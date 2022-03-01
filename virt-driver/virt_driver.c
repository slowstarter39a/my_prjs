#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/dev_printk.h>
#include <linux/cdev.h>

#define VIRT_DEV_COUNT 2
#define DEV_NAME "virt_dev"

#define virt_dev_err(fmt, ...) \
	pr_err("[%s]%s():" fmt, DEV_NAME, __func__, ##__VA_ARGS__)
#define virt_dev_info(fmt, ...) \
	pr_info("[%s]%s():" fmt, DEV_NAME, __func__, ##__VA_ARGS__)
#define virt_dev_debug(fmt, ...) \
	pr_debug("[%s]%s():" fmt, DEV_NAME, __func__, ##__VA_ARGS__)

static int major = 0;
static struct cdev virt_cdev;
static struct device *virt_device[VIRT_DEV_COUNT];
static struct class *virt_class;
static struct device *virt_device[VIRT_DEV_COUNT];

int virt_open(struct inode *inode, struct file *filp)
{
	int major = imajor(inode);
	int minor = iminor(inode);

	virt_dev_info("major = %d, minor = %d\n", major, minor);

	return 0;
}

ssize_t virt_read(struct file *filp, char __user *buf, size_t count,
		loff_t *f_pos)
{
	int major = imajor(file_inode(filp));
	int minor = iminor(file_inode(filp));
	int not_copied = 0;
	char local_buf[1000] = {0,};
	int local_buf_size = sizeof(local_buf);
	int size_to_copy = count > local_buf_size ? local_buf_size : count;

	snprintf(local_buf, local_buf_size, "string from kernel is \"%s\"\n",
			"data from kernel");

	not_copied = copy_to_user(buf, local_buf, size_to_copy);

	virt_dev_info("major = %d, minor = %d\n", major, minor);

	return (size_to_copy - not_copied);
}

ssize_t virt_write(struct file *filp, const char __user *buf, size_t count,
		loff_t *f_pos)
{
	int major = imajor(file_inode(filp));
	int minor = iminor(file_inode(filp));
	char local_buf[1000] = {0,};
	ssize_t written_count = 0;

	if (count > sizeof(local_buf)) {
		virt_dev_err(
		"The size of input data is too large! Can't write data\n");
		virt_dev_err("size to write is %ld, size of local buf is %lu\n",
				count, sizeof(local_buf));
		return -1;
	}

	written_count = copy_from_user(local_buf, buf, count);

	virt_dev_info("major = %d, minor = %d\n", major, minor);
	virt_dev_info("string from user is %s\n", local_buf);

	return count;
}

__poll_t virt_poll(struct file *filp, struct poll_table_struct *wait)
{
	__poll_t mask = 0;
	int major = imajor(file_inode(filp));
	int minor = iminor(file_inode(filp));

	virt_dev_info("major = %d, minor = %d\n", major, minor);

	return mask;
}

long virt_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
	int major = imajor(file_inode(filp));
	int minor = iminor(file_inode(filp));

	virt_dev_info("major = %d, minor = %d\n", major, minor);

	return 0;
}

int virt_fasync(int fd, struct file *filp, int on)
{
	int major = imajor(file_inode(filp));
	int minor = iminor(file_inode(filp));

	virt_dev_info("major = %d, minor = %d\n", major, minor);

	return 0;
}

int virt_close(struct inode *inode, struct file *filp)
{
	int major = imajor(inode);
	int minor = iminor(inode);

	virt_dev_info("major = %d, minor = %d\n", major, minor);

	return 0;
}

struct file_operations virt_fops = {
	.owner = THIS_MODULE,
	.open = virt_open,
	.read = virt_read,
	.write = virt_write,
	.poll = virt_poll,
	.unlocked_ioctl = virt_ioctl,
	.fasync = virt_fasync,
	.release = virt_close,
};

int init_virt_driver_module(void)
{
	dev_t dev_num = 0;
	int ret = 0;
	int i = 0;

	virt_dev_debug("\n");

	if (major == 0) {
		ret = alloc_chrdev_region(&dev_num, 0, VIRT_DEV_COUNT,
				DEV_NAME);
		major = MAJOR(dev_num);
	} else {
		ret = register_chrdev_region(major, VIRT_DEV_COUNT, DEV_NAME);
	}

	if (ret < 0) {
		virt_dev_err("register chrdev region failed\n");
		goto err_register_chrdev;
	}

	cdev_init(&virt_cdev,  &virt_fops);
	virt_cdev.owner = THIS_MODULE;
	ret = cdev_add(&virt_cdev, dev_num, VIRT_DEV_COUNT);

	if (ret < 0) {
		virt_dev_err("cdev_add failed\n");
		goto err_cdev_add;
	}

	virt_class = class_create(THIS_MODULE, "virt-drv");
	if (IS_ERR_OR_NULL(virt_class)) {
		ret = PTR_ERR(virt_class);
		goto err_class_create;
	}

	for (i = 0; i < VIRT_DEV_COUNT; i++) {
		virt_device[i] = device_create(virt_class, NULL, dev_num + i,
				NULL, "%s%d", DEV_NAME, i);
		if(IS_ERR_OR_NULL(virt_device[i])) {
			ret = PTR_ERR(virt_device[i]);
			goto err_device_create;
		}
	}

	return 0;

err_device_create:
	if (i != 0) {
		int j = 0;
		for (j = 0; j < i; j++) {
			device_destroy(virt_class, dev_num + j);
		}
	}
	class_destroy(virt_class);
err_class_create:
	cdev_del(&virt_cdev);
err_cdev_add:
	unregister_chrdev_region(dev_num, VIRT_DEV_COUNT);
err_register_chrdev:
	return ret;
}

void exit_virt_driver_module(void)
{
	int i = 0;
	dev_t dev_num = MKDEV(major, 0);

	pr_info("%s\n", __func__);

	for (i = 0; i < VIRT_DEV_COUNT; i++) {
		device_destroy(virt_class, dev_num + i);
	}
	class_destroy(virt_class);
	cdev_del(&virt_cdev);
	unregister_chrdev_region(dev_num, VIRT_DEV_COUNT);
}

module_init(init_virt_driver_module);
module_exit(exit_virt_driver_module);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Chulhyun");
MODULE_DESCRIPTION("A simple virtual driver module sample");

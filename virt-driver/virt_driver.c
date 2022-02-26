#include <linux/module.h>
#include <linux/kernel.h>

int init_virt_driver_module(void)
{
	pr_info("%s\n", __func__);

	return 0;
}

void exit_virt_driver_module(void)
{
	pr_info("%s\n", __func__);
}

module_init(init_virt_driver_module);
module_exit(exit_virt_driver_module);

MODULE_LICENSE("MIT");
MODULE_AUTHOR("Chulhyun");
MODULE_DESCRIPTION("virtual driver module");

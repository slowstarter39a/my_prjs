#include <linux/module.h>
#include <linux/kernel.h>

int init_module(void)
{
	pr_info("%s\n");

	return 0;
}

void exit_module(void)
{
	pr_info("%s\n");
}

module_init(init_module);
module_exit(exit_module);

MODULE

MODULE_LICENSE("MIT");
MODULE_AUTHOR("Chulhyun");
MODULE_DESCRIPTION("virtual driver module");

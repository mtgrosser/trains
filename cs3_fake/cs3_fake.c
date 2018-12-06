#include <linux/module.h>
#include <linux/init.h>
#include <linux/kobject.h>
#include <linux/sysfs.h>
#include <linux/string.h>
#include <linux/device.h>
#include <linux/err.h>
#include <linux/slab.h>
#include <linux/sys_soc.h>


static struct device *soc0_dev;
static struct device_attribute machine_attr;


ssize_t soc0_machine_read(struct device* dev, struct device_attribute* attr, char* buf)
{

	return scnprintf(buf, PAGE_SIZE, "%s", "Sontheim i.MX6 Solo SMARC Board\n");
}


static int __init cs3_init(void)
{
	soc0_dev = root_device_register("soc0");
	if (!soc0_dev)
		return - ENOMEM;

	machine_attr.attr.name = "machine";
	machine_attr.attr.mode = 0444;
	machine_attr.show = soc0_machine_read;
	machine_attr.store = NULL;

	if (PTR_ERR((const void *) sysfs_create_file(&soc0_dev->kobj, &machine_attr.attr)))
		goto unregister_dev;

	printk(KERN_INFO "cs3_fake: CS3 platform registered\n");

	return 0;

unregister_dev:
	root_device_unregister(soc0_dev);
	return - ENOMEM;
}


static void __exit cs3_exit(void)
{
	sysfs_remove_file(&soc0_dev->kobj, &machine_attr.attr);
	root_device_unregister(soc0_dev);
        printk(KERN_INFO "cs3_fake: CS3 platform unregistered\n");
}


module_init(cs3_init);
module_exit(cs3_exit);

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Author <anonymous@example.com>");

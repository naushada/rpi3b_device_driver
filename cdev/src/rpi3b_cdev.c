#ifndef __RPI3B_CDEV_C__
#define __RPI3B_CDEV_C__

#include "common.h"
#include "rpi3b_cdev.h"

static unsigned char *device_name[] = { "/uart/uart0" ,
                                        "/uart/uart1" ,
                                        "/spis/spi0"  ,
                                        "/spis/spi1"  ,
                                        "/spim/spi0"  ,
                                        "/i2c/i2c0"   ,
                                        "/i2c/i2c1"   ,
                                        NULL};

/*This holds the opened device major NUmber*/
static unsigned int device_major[32];
static struct cdev device_cdev[32];
static struct class *device_class[32];

static const struct file_operations fops = {
  .owner   = THIS_MODULE,
  .read    = rpi3b_read,
  .write   = rpi3b_write,
  .open    = rpi3b_open,
  .release = rpi3b_release,
};


ssize_t rpi3b_write(struct file *fp, 
                  const char *in_ptr, 
                  size_t in_len, 
                  loff_t *offset) {
#if 0
  if(in_len <= 0)
    return 0;

  /*copy user's buffer into kernel buffer*/
  if(copy_from_user(out_ptr, in_ptr, in_len))
    return -EFAULT;

  *offset += in_len;

  return(in_len);
#endif
  unsigned int idx;
  for(idx = 0; idx < in_len; idx++) {
    printk(KERN_INFO "%X \t", in_ptr[idx]);
  }

  return(in_len);
}/*rpi3b_write*/

/*https://linux-kernel-labs.github.io/master/labs/device_drivers.html*/
int rpi3b_open(struct inode *object, struct file *fp) {

 printk(KERN_INFO "f_mode %d f_pos %lld f_flags %d",
          fp->f_mode, fp->f_pos, fp->f_flags);

  return(0);
}/*rpi3b_open*/


int rpi3b_cdev_init(void) {
  unsigned int idx;
  unsigned char dev_name[64];

  memset((void *)dev_name, 0, sizeof(dev_name));

  for(idx = 0; device_name[idx]; idx++) {
    snprintf(dev_name, sizeof(dev_name), "%s/_proc",device_name[idx]);
    /* cat /proc/devices */
    if(alloc_chrdev_region(&device_major[idx], idx, 32, dev_name) < 0) {
      printk(KERN_INFO "alloc_chrdev_region failed device_major[%d] %d\n", idx, device_major[idx]);
      return(-1);
    }
    
    memset((void *)dev_name, 0, sizeof(dev_name));
    snprintf(dev_name, sizeof(dev_name), "%s/_sys",device_name[idx]);
    /* ls /sys/class */
    if((device_class[idx] = class_create(THIS_MODULE, dev_name)) == NULL) {
      printk(KERN_INFO "device_class failed for device_major[%d] %d\n", idx, device_major[idx]);
      return(-1);
    }

    /* ls /dev/ */
    if(device_create(device_class[idx], NULL, device_major[idx], NULL, device_name[idx]) == NULL) {
      printk(KERN_INFO "device_create failed for device_major[%d] %d\n", idx, device_major[idx]);
      return(-1);
    }

    cdev_init(&device_cdev[idx], &fops);
    if(cdev_add(&device_cdev[idx], device_major[idx], 1) == -1) {
      printk(KERN_INFO "cdev_add failed for device_major[%d] %d\n", idx, device_major[idx]);
      return(-1);
    }
  }

  /*Success*/
  return(0);
}/*rpi3b_cdev_init*/


int rpi3b_cdev_destroy(void) {
  unsigned int idx;

  for(idx = 0; device_name[idx]; idx++) {
    device_destroy(device_class[idx], device_major[idx]);
    cdev_del(&device_cdev[idx]);
    class_destroy(device_class[idx]);
    unregister_chrdev_region(device_major[idx], 1); 
  }

  /*Success*/
  return(0);
}/*rpi3b_cdev_destroy*/


int rpi3b_release(struct inode *object, struct file *fp) {

  return(0);
}/*rpi3b_release*/



ssize_t rpi3b_read(struct file *fp, 
                   char *in_ptr, 
                   size_t in_len, 
                   loff_t *offset) {

  return(in_len);
}/*rpi3b_read*/


MODULE_VERSION("2.1");
MODULE_AUTHOR("Mohammed Naushad Ahmed");
MODULE_DESCRIPTION("Raspberry Pi3B Peripheral");
MODULE_LICENSE("GPL");

#endif /* __RPI3B_CDEV_C__ */

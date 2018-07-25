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

  for(idx = 0; device_name[idx]; idx++) {
    /*device_major number will be allocated by kernel*/
    device_major[idx] = register_chrdev(0, device_name[idx], &fops);

    if(device_major[idx] < 0) {
      printk(KERN_INFO "Device [%s] registration failed\n", device_name[idx]);
      return(device_major[idx]);
    }
  }

  /*Success*/
  return(0);
}/*rpi3b_cdev_init*/




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

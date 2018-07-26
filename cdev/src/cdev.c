#ifndef __CDEV_C__
#define __CDEV_C__

#include "common.h"
#include "cdev.h"
#include "uart.h"

static cdev_ctx_t __g_cdev_ctx[32];

static unsigned char *device_name[] = { "/rpi3b/uart/uart0" ,
                                        "/rpi3b/uart/uart1" ,
                                        "/rpi3b/spis/spi0"  ,
                                        "/rpi3b/spis/spi1"  ,
                                        "/rpi3b/spim/spi0"  ,
                                        "/rpi3b/i2c/i2c0"   ,
                                        "/rpi3b/i2c/i2c1"   ,
                                        "/rpi3b/gpio"       ,
                                        NULL};


static const struct file_operations fops = {
  .owner   = THIS_MODULE,
  .read    = __cdev_read,
  .write   = __cdev_write,
  .open    = __cdev_open,
  .release = __cdev_release,
};


ssize_t __cdev_write(struct file *fp, 
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
    printk(KERN_INFO "%X", in_ptr[idx]);
    uart0_send_data(in_ptr[idx]);
  }

  /*To flush the last element*/
  printk(KERN_INFO "\n");

  return(in_len);
}/*__cdev_write*/

/*https://linux-kernel-labs.github.io/master/labs/device_drivers.html*/
int __cdev_open(struct inode *object, struct file *fp) {

  char fname[64];

  memset((void *)fname, 0, sizeof(fname));
  __cdev_get_fname(fp, fname);

  printk(KERN_INFO "fname is %s\n", fname);

  if(!strncmp(fname, "/dev/rpi3b/uart/uart0", sizeof(fname))) {
    uart0_main();  

  } else if(!strncmp(fname, "/dev/rpi3b/uart/uart1", sizeof(fname))) {
    uart0_main();  

  } else if(!strncmp(fname, "/dev/rpi3b/gpio", sizeof(fname))) {
    uart0_main();  

  } else if(!strncmp(fname, "/dev/rpi3b/spim/spi0", sizeof(fname))) {
    uart0_main();  

  } else if(!strncmp(fname, "/dev/rpi3b/spim/spi1", sizeof(fname))) {
    uart0_main();  

  } else if(!strncmp(fname, "/dev/rpi3b/spis/spi0", sizeof(fname))) {
    uart0_main();  

  } else if(!strncmp(fname, "/dev/rpi3b/spis/spi1", sizeof(fname))) {
    uart0_main();  

  } else {
    printk(KERN_INFO "Invalid device file name\n");
  }

  return(0);
}/*__cdev_open*/


int __cdev_init(void) {
  unsigned int idx;
  unsigned char dev_name[64];

  memset((void *)dev_name, 0, sizeof(dev_name));

  for(idx = 0; device_name[idx]; idx++) {
    snprintf(dev_name, sizeof(dev_name), "%s/_proc",device_name[idx]);
    /* cat /proc/devices */
    if(alloc_chrdev_region(&__g_cdev_ctx[idx].device_major, 
                           idx, 
                           32, 
                           dev_name) < 0) {
      printk(KERN_INFO "alloc_chrdev_region failed device_major[%d] %d\n", 
                        idx, 
                        __g_cdev_ctx[idx].device_major);
      return(-1);
    }
    
    memset((void *)dev_name, 0, sizeof(dev_name));
    snprintf(dev_name, sizeof(dev_name), "%s/_sys",device_name[idx]);
    /* ls /sys/class */
    if((__g_cdev_ctx[idx].device_class = class_create(THIS_MODULE, dev_name)) == NULL) {
      printk(KERN_INFO "device_class failed for device_major[%d] %d\n", 
                        idx, 
                        __g_cdev_ctx[idx].device_major);
      return(-1);
    }

    /* ls /dev/ */
    if(device_create(__g_cdev_ctx[idx].device_class, 
                     NULL, 
                     __g_cdev_ctx[idx].device_major, 
                     NULL, 
                     device_name[idx]) == NULL) {
      printk(KERN_INFO "device_create failed for device_major[%d] %d\n", 
                        idx, 
                        __g_cdev_ctx[idx].device_major);
      return(-1);
    }

    cdev_init(&__g_cdev_ctx[idx].device_cdev, &fops);
    if(cdev_add(&__g_cdev_ctx[idx].device_cdev, __g_cdev_ctx[idx].device_major, 1) == -1) {
      printk(KERN_INFO "cdev_add failed for device_major[%d] %d\n", 
                        idx, 
                        __g_cdev_ctx[idx].device_major);
      return(-1);
    }
  }

  /*Success*/
  return(0);
}/*__cdev_init*/

int __cdev_destroy(void) {
  unsigned int idx;

  for(idx = 0; device_name[idx]; idx++) {
    device_destroy(__g_cdev_ctx[idx].device_class, 
                   __g_cdev_ctx[idx].device_major);
    cdev_del(&__g_cdev_ctx[idx].device_cdev);
    class_destroy(__g_cdev_ctx[idx].device_class);
    unregister_chrdev_region(__g_cdev_ctx[idx].device_major, 1); 
  }

  /*Success*/
  return(0);
}/*__cdev_destroy*/

int __cdev_release(struct inode *object, struct file *fp) {
  char fname[64];
  
  memset((void *)fname, 0, sizeof(fname));
  __cdev_get_fname(fp, fname);
  printk(KERN_INFO "fname %s has been closed\n", fname);

  if(!strncmp(fname, "/dev/rpi3b/uart/uart0", sizeof(fname))) {
    uart0_flush_fifo();
    uart0_disable();  

  } else if(!strncmp(fname, "/dev/rpi3b/uart/uart1", sizeof(fname))) {

  } else if(!strncmp(fname, "/dev/rpi3b/gpio", sizeof(fname))) {

  } else if(!strncmp(fname, "/dev/rpi3b/spim/spi0", sizeof(fname))) {

  } else if(!strncmp(fname, "/dev/rpi3b/spim/spi1", sizeof(fname))) {

  } else if(!strncmp(fname, "/dev/rpi3b/spis/spi0", sizeof(fname))) {

  } else if(!strncmp(fname, "/dev/rpi3b/spis/spi1", sizeof(fname))) {

  } else {
    printk(KERN_INFO "Invalid device file name\n");
  }
  return(0);
}/*__cdev_release*/

ssize_t __cdev_read(struct file *fp, 
                    char *in_ptr, 
                    size_t in_len, 
                    loff_t *offset) {

  char fname[64];
  
  memset((void *)fname, 0, sizeof(fname));
  __cdev_get_fname(fp, fname);

  printk(KERN_INFO "Path %s has been READ\n", fname);
  strcpy(in_ptr, "From Kernel\n");
  
  return(12);
}/*__cdev_read*/

int __cdev_get_fname(struct file *fp, char *fname) {

  char *tmp;
  char *tmp_fname;

  printk(KERN_INFO "f_mode %d f_pos %lld f_flags %d",
           fp->f_mode, fp->f_pos, fp->f_flags);

  tmp = (char *)__get_free_page(GFP_KERNEL);

  if (!tmp) {
    printk(KERN_INFO "Memory Allocation Failed\n"); 
    return -ENOMEM;
  }
  
  /*Returns pointer into tmp*/
  tmp_fname = d_path(&fp->f_path, tmp, PAGE_SIZE);

  if(IS_ERR(tmp_fname)) {
    printk(KERN_INFO "d_path Failed\n"); 
    free_page((unsigned long)tmp);
    return PTR_ERR(tmp_fname);
  }

  memcpy((void *)fname, (const char *)tmp_fname, strlen(tmp_fname));
  free_page((unsigned long)tmp);

  return(0);
}/*__cdev_get_fname*/

MODULE_VERSION("2.1");
MODULE_AUTHOR("Mohammed Naushad Ahmed");
MODULE_DESCRIPTION("Raspberry Pi3B Peripheral");
MODULE_LICENSE("GPL");

#endif /* __CDEV_C__ */

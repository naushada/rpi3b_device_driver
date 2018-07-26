#ifndef __CDEV_H__
#define __CDEV_H__


typedef struct {
  
  /*This holds the opened device major NUmber*/
  unsigned int device_major;
  struct cdev  device_cdev;
  struct class *device_class;
}cdev_ctx_t;


int __cdev_open(struct inode *, struct file *);

int __cdev_release(struct inode *, struct file *);

ssize_t __cdev_read(struct file *, char *, size_t, loff_t *);

ssize_t __cdev_write(struct file *, const char *, size_t, loff_t *);

int __cdev_init(void);

int __cdev_destroy(void);

int __cdev_get_fname(struct file *fp, char *fname);

#endif /* __RPI3B_CDEV_H__ */

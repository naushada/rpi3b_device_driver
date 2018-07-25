#ifndef __RPI3B_CDEV_H__
#define __RPI3B_CDEV_H__


int rpi3b_open(struct inode *, struct file *);

int rpi3b_release(struct inode *, struct file *);

ssize_t rpi3b_read(struct file *, char *, size_t, loff_t *);

ssize_t rpi3b_write(struct file *, const char *, size_t, loff_t *);

int rpi3b_cdev_init(void);

#endif /* __RPI3B_CDEV_H__ */

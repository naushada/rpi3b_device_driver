#ifndef __RPI3B_CDEV_H__
#define __RPI3B_CDEV_H__


static int rpi_open(struct inode *, struct file *);

static int rpi_release(struct inode *, struct file *);

static ssize_t rpi_read(struct file *, char *, size_t, loff_t *);

static ssize_t rpi_write(struct file *, const char *, size_t, loff_t *);

int rpi3b_cdev_init(void);

#endif /* __RPI3B_CDEV_H__ */

#include "watchdog_runled.h"


int hito_sys_led_on(void)
{
    char tmp = '1';
    int fd;
    fd = open("/dev/debug_led",O_RDWR);
    if (fd < 0)
    {
        return -1;
    }
    tmp = IO_VAULE_H;
    ioctl(fd, tmp, 1);

    close(fd);
    return 0;
}

int hito_sys_led_off(void)
{
    char tmp = '1';
    int fd;
    fd = open("/dev/debug_led", O_RDWR);
    if (fd < 0)
    {
        return -1;
    }
    tmp = IO_VAULE_L;
    ioctl(fd, tmp, 1);

    close(fd);

    return 0;
}

int watchdog_fd = 0;

int hito_watchdog_init(int wdgtimeout)
{
    int ret_val, data;
    watchdog_fd = open("/dev/watchdog", O_WRONLY);
    if(watchdog_fd == -1)
    {
        perror("watchdog");
        return -1;
    }

    /* 获取第一次看门狗超时时间  */
    ret_val = ioctl (watchdog_fd, WDIOC_GETTIMEOUT, &data);
    if(ret_val)
    {
        printf("\nWatchdog Timer : WDIOC_GETTIMEOUT failed\n");
        return -1;
    }
    else
    {
        printf("\nCurrent timeout value is : %d seconds\n", data);
    }

    /* 设置自己的看门狗超时时间  */
    ret_val = ioctl (watchdog_fd, WDIOC_SETTIMEOUT, &wdgtimeout);
    if (ret_val)
    {
        printf ("Watchdog Timer : WDIOC_SETTIMEOUT failed\n");
        return -1;
    }
    else
    {
        printf ("\nNew timeout value is : %d seconds\n", wdgtimeout);
    }

    if (1 != write(watchdog_fd, "\0", 1))
    {
        printf("Write failed\n");
        return -1;
    }
    else
    {
        printf("Write succeeded\n");
        return 0;
    }

    return 0;
}

int hito_watchdog_keep_alive(void)
{
    if (1 != write(watchdog_fd, "\0", 1))
    {
        printf("Write failed\n");
        return -1;
    }
    else
    {
        printf("Write succeeded\n");
        return 0;
    }
}


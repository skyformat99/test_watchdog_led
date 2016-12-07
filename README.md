

库描述：
    这个库是针对Aplex SBC7109 led 灯以及看门狗测试的库。
    头文件：Libdev/watchdog_runled.h, 里面包含各个方法的大致说明
    例程： App/watchdog_test
    使用方法：
        将watchdog_test 拷入SBC_7109文件系统内。
        ./watchdog_test A  传入参数A 表示保持喂狗状态，不死。

        ./watchfog_test D  传入参数D 表示5秒后触发看门狗硬件重启。
    编译方法：
        cd App
        make all

    清理：
        make clean




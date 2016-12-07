


all:
	make -C  ../Libdev/
	arm-none-linux-gnueabi-gcc  *.c -o watchdog_test  -L ../Libdev -lwatchdog_runled

clean:
	rm watchdog_test
	make -C ../Libdev/  clean

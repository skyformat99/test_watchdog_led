
all:
	arm-none-linux-gnueabi-gcc -c watchdog_runled.c -o watchdog_runled.o -I .
	arm-none-linux-gnueabi-ar rcv libwatchdog_runled.a watchdog_runled.o


clean:
	rm *.o *.a


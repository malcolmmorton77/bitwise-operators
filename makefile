bitwisemenu.out: major1.o clz.o endian.o rotate.o parity.o
	gcc -o bitwisemenu major1.o clz.o endian.o rotate.o parity.o
major1.o: major1.h
	gcc -Wall -c major1.c
clz.o: major1.h
	gcc -Wall -c clz.c
endian.o: major1.h
	gcc -Wall -c endian.c
rotate.o: major1.h
	gcc -Wall -c rotate.c
parity.o: major1.h
	gcc -Wall -c parity.c
clean:
	rm *.o bitwisemenu
bitwisemenu:
	./bitwisemenu.out

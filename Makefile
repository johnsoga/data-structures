CC=gcc

objects = ds.o check_ds.o

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
	.DEFAULT_GOAL := build_macos
endif

.DELETE_ON_ERROR:

ds.o: ./src/ds.c
	$(CC) -c ./src/ds.c

check_ds.o: ./tests/check_ds.c
	$(CC) -I$$(brew --prefix check)/include -c ./tests/check_ds.c

build_macos: $(objects)
	$(CC) -L$$(brew --prefix check)/lib -g $(objects) -lcheck -lm -lpthread -o check_ds_tests.out
	./check_ds_tests.out

clean:
	rm -f $(objects)

cleanall: clean
	rm -f check_ds_tests.out
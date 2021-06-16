CFLAGS=-std=c99 -Wall -pedantic -g3
clean: 
	rm -f c1 c3 c7 c8 c9 c9ex test\
		c10 c10ex1 c10ex2 c11 c13 c14 c15\
		c15ex1 c16 c16ex c19 stack func_as_ptr\
		stack1 c_database_mng c23 duffs_dev grey_code str hj\
		$(-DNDEBUG c22_main.c c22.o -o c22_main)

str: strlib.o
	gcc $(CFLAGS) -o $@ $^

strlib.o: strlib.c

all: clean
	make c1 c3 c7 c8 c9 c9ex c10 c10ex1 c10ex2\
		c11 c13 c14 c15 c15ex1 c16	c16ex c19 stack\
		func_as_ptr stack1	c_database_mng c23 duffs_dev grey_code\
		$(-DNDEBUG c22_main.c c22.o -o c22_main)
help:
	egrep "^# target:" [Mm]akefile
MACRO = 54
NEW_MAC = $(MACRO) + $(MACRO)
hello: ; @echo $(MACRO)_"gfff"_$(NEW_MAC)_UTD_$@__$?

# Playing
hj: gsj.o
	gcc $(CFLAGS) -o $@ $^
	@echo "I just built $@"


gsj.o: gsj.c gsj.h


test: hj
	@./hj 45

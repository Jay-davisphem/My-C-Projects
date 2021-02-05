CFLAGS=-Wall -g

clean:
	rm -f c1 c3 c7 c8 c9 c9ex test c10 c10ex1 c10ex2 c11 c13 c14 c15 c15ex1 c16 c16ex c19 stack func_as_ptr stack1 c_database_mng $(-DNDEBUG c22_main.c c22.o -o c22_main)

all:
	make c1 c3 c7 c8 c9 c9ex c10 c10ex1 c10ex2 c11 c13 c14 c15 c15ex1	c16	c16ex c19 stack func_as_ptr stack1 c_database_mng $(-DNDEBUG c22_main.c c22.o -o c22_main)

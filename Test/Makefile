CC_FLG = $(CS_CC_FLG) $(CS_EXE_FLG) -lcsmap -lstdc++

all: test
	
test: test.c
	gcc $(CC_FLG) test.c ../Source/CS_rlsUpdt.c -o test

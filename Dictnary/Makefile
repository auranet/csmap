CC_FLG = $(CS_CC_FLG) $(CS_EXE_FLG) -lcsmap -lstdc++
CS_SRC = cs_comp.c

all: cs_comp cs_dictdiff

cs_comp: $(CS_SRC)
	gcc $(CC_FLG) $(CS_SRC) -o cs_comp

cs_dictdiff: $(CS_SRC)
	gcc $(CC_FLG) cs_dictdiff.c -o cs_dictdiff

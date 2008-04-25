CS_SRC = CS_COMP.C

ALL: CS_COMP.EXE CS_DictDiff.EXE

CS_COMP.EXE: $(CS_SRC)
	cl /MT /I..\include $(CS_SRC) /link ..\SOURCE\CSMAPMNT.LIB

CS_DictDiff.EXE: $(CS_SRC)
	cl /MT /I..\include CS_DictDiff.c /link ..\SOURCE\CSMAPMNT.LIB

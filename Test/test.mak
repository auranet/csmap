ALL: TEST.EXE mfcTest.exe
	
TEST.EXE: TEST.C
	cl /MT /O2 /I..\include TEST.C ..\Source\CS_rlsUpdt.c /link ..\SOURCE\CSMAPMNT.LIB
	
mfcTest.exe: mfcTest.cpp mfcTest.h
	rc /l 0x409 /fo"mfcTest.res" /i..\include /d"NDEBUG" ..\SOURCE\csmap.rc
	cl /MT /O2 /I..\include /D"__MFC__" mfcTest.cpp /link mfcTest.res ..\SOURCE\CSMAPMNT.LIB /subsystem:windows /machine:I386


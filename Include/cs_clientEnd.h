/******************************************************************************

	*********************************************************************
	*********************************************************************
	**                                                                 **
	**  It is the purpose of this file that it be replaced, as         **
	**  appropriate, by CS-MAP clients.  The intent is that clients    **
	**  use their own version of this file to define the macros which  **
	**	appear herein.  Thus, little or no tinkering with Mentor       **
	**	Software, Inc. source code is required to implement client     **
	**	variations indicated by the macros involved.                   **
	**                                                                 **
	*********************************************************************
	*********************************************************************

******************************************************************************/

/******************************************************************************

	A file with this name is included by "cs_map.h", the main header file
	for the CS-MAP library as the last thing it does.  Use this file to
	modify any of the standard settings used in CS-MAP.

	Below please find several macro definitions which are commented out.
	The definitions indicated are the default definitions used in the
	CS-MAP source code if these macros are left undefined.  If you need
	a definition which is different, please supply the definition in this
	file.

	It is intended that application developers simplay maintain their
	own version of this file, and ignore the distribution copy of this
	file.  In this manner, different environments can be supported without
	resorting to modification of CS-MAP distribution code.

	Macro definitions wehich can be replaced are:

#define _csMalloc(_n)         malloc(_n)
#define _csCalloc(_n,_s)      calloc(_n,_s)
#define _csRealloc(_m,_n)     realloc(_m,_n)
#define _csFree(_m)           {if (_m) {free(_m); _m = 0;}}
#define _csClose(_m)          {if (_m >= 0) {close(_m);}}

******************************************************************************/

/******************************************************************************

	*********************************************************************
	*********************************************************************
	**                                                                 **
	**          Copyright (c) 1997 Mentor Software, Inc.               **
	**                    All Rights Reserved                          **
	**                                                                 **
	** The software and information contained herein are proprietary   **
	** to, and comprise valuable trade secrets of, Mentor Software,    **
	** Inc., which intends to preserve as trade secrets such software  **
	** and information.  This software is furnished pursuant to a      **
	** written license agreement and may be used, copied, transmitted, **
	** and stored only in accordance with the terms of such license    **
	** and with the inclusion of the above copyright notice.  This     **
	** software and information or any other copies thereof may not    **
	** be provided or otherwise made available to any other person.    **
	** Failure to honor the terms of the written license agreement     **
	** could be cause for legal action against you and/or your         **
	** company.                                                         **
	**                                                                 **
	** Notwithstanding any other lease or license that may pertain to, **
	** or accompany the delivery of, this computer software and        **
	** information, the rights of the Government regarding its use,    **
	** reproduction and disclosure are as set forth in Section         **
	** 52.227-19 of the FARS Computer Software-Restricted Rights       **
	** clause.                                                         **
	**                                                                 **
	** Use, duplication, or disclosure by the Government is subject    **
	** to restrictions as set forth in subparagraph (c)(1)(ii) of the  **
	** Rights in Technical Data and Computer Software clause at DFARS  **
	** 252.227-7013. Contractor/Manufacturer is Mentor Software, Inc., **
	** 3907 East 120th Avenue, Suite 200, Thornton, CO  80233.         **
	**                                                                 **
	*********************************************************************  
	*********************************************************************  

			 File Name: $RCSfile: CS_general.c $
		   Description:
			   Purpose:

		Revision Level:	$Revision: #6 $
		 Check In Date:	$Date: 2006/12/01 $

		Last Revision:	$Log: CS_general.c $
		Last Revision:	Revision 11.1300  2005/05/25 23:27:12  nto
		Last Revision:	Official Release 11.13
		Last Revision:	Revision 11.1200  2005/01/15 18:27:12  nto
		Last Revision:	Official Release of CS-MAP 11.12, 11:26am 15 Jan 2005
		Last Revision:	Revision 11.1100  2004/11/01 18:53:09  nto
		Last Revision:	Official release 11.11
		Last Revision:	Revision 11.1001  2004/10/07 19:25:18  nto
		Last Revision:	Revision 11.900  2004/03/26 17:02:24  nto
		Last Revision:	Official release: 11.09 - 3/25/2003
		Last Revision:	Revision 11.800  2004/01/13 23:29:13  nto
		Last Revision:	Revision 11.700  2003/12/19 01:49:53  nto
		Last Revision:	Official release 11.07
		Last Revision:	Revision 11.600  2003/12/04 02:46:28  nto
		Last Revision:	Release 11.06.  Never shipped. Source captured in prep for C++ V7.
		Last Revision:	Revision 11.501  2003/08/22 21:12:55  nto
		Last Revision:	Official Release: 11.05
		Last Revision:	Revision 11.401  2003/05/01 23:06:22  nto
		Last Revision:	Revision 11.300  2003/02/25 04:29:16  nto
		Last Revision:	Official Release 11.03
		Last Revision:	Revision 11.100  2002/11/22 19:38:44  nto
		Last Revision:	Official release: 11.01
		Last Revision:	Revision 10.1504  2002/11/06 23:50:58  nto
		Last Revision:	Fixed a typo in code only compiled under UNIX.
		Last Revision:	Revision 10.1503  2002/10/13 00:27:18  nto
		Last Revision:	Now calls CS_getenv instead of plain 'getenv'.
		Last Revision:	Revision 10.1502  2002/10/06 22:24:07  nto
		Last Revision:	Fixed to compile under Windows CE ('time' function).
		Last Revision:	Revision 10.1501  2002/10/06 18:07:03  nto
		Last Revision:	Converted all direct references to 'access' to CS_access.
		Last Revision:	Revision 10.1500  2002/09/22 00:01:20  nto
		Last Revision:	Official Release:= 10.15
		Last Revision:	Revision 10.1400  2002/08/09 18:14:22  nto
		Last Revision:	Revision 10.1200  2002/07/14 03:26:16  nto
		Last Revision:	Revision 10.1100  2002/06/13 14:18:37  nto
		Last Revision:	Release 10.11 Official
		Last Revision:	Revision 10.1000  2002/02/23 21:18:26  nto
		Last Revision:	Official Release of 10.10, 2/22/02 - Norm Olsen
		Last Revision:	Revision 10.901  2001/11/09 22:31:02  nto
		Last Revision:	Fixed a bug where a name of 23 characters was considered an error.
		Last Revision:	Revision 10.900  2001/09/24 04:31:11  nto
		Last Revision:	Revision 10.703  2001/09/18 19:21:10  nto
		Last Revision:	Fixed CS_init so that it properly recognizes a UNC path as a valid
		Last Revision:	file/path name.
		Last Revision:	Revision 10.702  2001/05/01 16:47:00  nto
		Last Revision:	Correct possibility of character overflow on Unix systems where path names can get quite long.
		Last Revision:	Revision 10.701  2001/05/01 15:38:39  nto
		Last Revision:	Adjusted the sizeof the ctemp characterarray for Unix.
		Last Revision:	Revision 10.700  2001/01/25 04:13:48  nto
		Last Revision:	Revision 10.600  2000/12/11 06:39:43  nto
		Last Revision:	Release 10.06
		Last Revision:	Revision 10.501  2000/12/11 05:24:52  nto
		Last Revision:	Some tweaks for UNIX and the protections system.
		Last Revision:	Revision 10.500  2000/10/27 07:38:20  nto
		Last Revision:	Official Release 10.05
		Last Revision:	Revision 10.401  2000/10/27 03:55:44  nto
		Last Revision:	Removed the difference between Release and Evaluation.
		Last Revision:	Revision 10.400  2000/09/13 01:16:54  nto
		Last Revision:	Release 10.04
		Last Revision:	Revision 10.301  2000/09/12 20:39:34  nto
		Last Revision:	Fixed possible bug in CS_init.  DId not get a report on this one, just found it naturally.
		Last Revision:	Revision 10.300  2000/04/04 23:18:25  nto
		Last Revision:	Revision 10.200  2000/03/02 18:51:17  nto
		Last Revision:	Revision 10.4  2000/02/14 07:07:00  nto
		Last Revision:	Removed unused global variables.
		Last Revision:	Revision 10.3  2000/01/30 23:40:33  nto
		Last Revision:	Moved the CS_unitlu function out to its own file for easier modification by users.
		Last Revision:	Revision 10.2  1999/11/04 00:13:15  nto
		Last Revision:	Fixed a problem in CS_altdr when CS_altsr is called multiple times in the same process.
		Last Revision:	Revision 10.1  1999/10/16 18:48:26  nto
		Last Revision:	Modifications suggested by Gimpel PC-Lint.  Note, one potential
		Last Revision:	bug related to the undefined symbol rt_UNIX, was corrected.
		Last Revision:	Revision 10.0  1999/10/05 18:27:14  nto
		Last Revision:	Revision 9.99  1999/10/05 17:36:25  nto
		Last Revision:	Revision 1.2  1999/09/10 18:44:30  nto
		Last Revision:	This revision compiles, links, and generates a successful test program.

******************************************************************************/

#ifdef LABEL_MODULE
static char revlvl [] = {"$Id: //depot/Libraries/CsMap/current/src/CS_general.c#6 $"};
#endif

#include "cs_map.h"

/**********************************************************************
**	flag = CS_altdr (alt_dir);
**
**	char *alt_dir;				the alternate directory to use for mapping
**								stuff if viable.  NULL says use the environmental
**								variable named CS_MAP_DIR.  The null string says
**								check the current directory.
**	int flag;					returns TRUE if cs_Dir contains a valid
**								pointer to a directory containing a
**								COORDSYS file.
**
**	This module will alter the contents of cs_Dir and cs_DirP
**	if the proposed alternate directory is a viable directory
**	for mapping.  If the proposed directory is not viable,
**	we use the default standard defined in CSdata.c.
**
**	The return value simply indicates the presence of a file
**	with the appropriate name.  This function does not test
**	the magic number of the file.
**********************************************************************/

int EXP_LVL1 CS_altdr (Const char *alt_dir)
{
	extern char cs_DirK [];
	extern char cs_Dir [];
	extern char *cs_DirP;
	extern char cs_Csname [];
	extern char cs_Envvar [];
	extern char cs_DirsepC;

	int st;
	int flag;

	char *cp;

	char ctemp [MAXPATH];

	flag = FALSE;

	/* Deal with the possible NULL value of cs_DirP. */

	if (cs_Dir [0] == '\0')
	{
		cs_DirP = CS_stcpy (cs_Dir,cs_DirK);
	}
	if (cs_DirP == NULL)
	{
		cp = strrchr (cs_Dir,cs_DirsepC);
		if (cp != NULL) cs_DirP = cp + 1;
		else            cs_DirP = cs_Dir;
	}

	/* See if the Coordinate System Dictionary exists in the
	   proposed alternate directory. If alt_dir is the NULL
	   pointer, we use the value of the environmental variable
	   whose name is defined in the cs_Envvar global variabele.
	   
	   There is no "getenv" in the NS VC++ Version 8 embedded
	   environment. */
#if !defined (__WINCE__)
	if (alt_dir == NULL)
	{
		cp = CS_getenv (cs_Envvar);
		if (cp != NULL)
		{
			cp = CS_stncp (ctemp,cp,sizeof (ctemp));
			if (*(cp - 1) != cs_DirsepC)
			{
				*cp++ = cs_DirsepC;
				*cp = '\0';
			}
		}
		else
		{
			ctemp [0] = '\0';
			cp = ctemp;
		}
	}
	else if (*alt_dir != '\0')
	{
		/* If we have been given something, use it. Note,
		   we add a directory separator character if there
		   is not one already. */

		strcpy (ctemp,alt_dir);
		cp = ctemp + strlen (ctemp);
		if (*(cp - 1) != cs_DirsepC)
		{
			*cp++ = cs_DirsepC;
			*cp = '\0';							/*lint !e661 */
		}
	}
	else
	{
		/* All else has failed. However, we must initialize to
		   something rational. We'll use the current directory
		   of the current drive. */

		ctemp [0] = '.';
		ctemp [1] = cs_DirsepC;
		ctemp [2] = '\0';
		cp = &ctemp [2];
	}
#endif

	/* See if the coordinate system dictionary resides in the
	   desired location.  Note, we only use the name here, we
	   don't check the magic number.  Maybe we should. */

	strcpy (cp,cs_Csname);
	st = CS_access (ctemp,0);
	*cp = '\0';
	if (st == 0)
	{
		/* Here if a Coordinate System Dictionary exists
		   in the proposed alternate directory.  Therefore,
		   we use it. */

		cs_DirP = CS_stcpy (cs_Dir,ctemp);
		flag = TRUE;
	}
	return (flag ? 0 : -1);
}

/**********************************************************************
**	st = CS_nampp (name);
**
**	char *name;					the name to be processed and checked.
**	int st;						returns zero if the name is OK, else
**								returns -1.
**
**	Converts all lower case characters to upper case, and
**	trims leading and traling blanks.  Also trims default
**	wrapping characters from the name if present.
**********************************************************************/

int EXP_LVL5 CS_nampp (char *name)
{
	extern char csErrnam [];
	extern char cs_Nmchset [];
	extern char cs_Unique;

	int ok;
	size_t size;
	int alphaCount;
	int uniqueCount;

	cs_Register char *pp;
	cs_Register char *qq;

	cs_Register char cc;

	char ctemp [cs_KEYNM_DEF];

	/* Prepare for a possible error. */

	CS_stncp (csErrnam,name,MAXPATH);

	/* Capture the size of the original array.  If the name
	   is OK, we will be copying back into this array a string
	   which may be smaller, but certainly not larger than
	   the original. */

	size = strlen (name);						/*lint !e713 */

	/* Remove leading and trailing white space while copying
	   name to ctemp. */

	pp = name;
	while (*pp == ' ') pp += 1;
	qq = CS_stncp (ctemp,pp,sizeof (ctemp));
	if (ctemp [0] == '\0')
	{
		/* We were given all blanks. */

		CS_erpt (cs_INV_NAME);
		goto error;
	}

	/* We now know that there is at least one non-space
	   character in the string.  Thus the following does
	   not need a pointer comparison which we like to avoid. */

	while (*(qq - 1) == ' ') qq -= 1;
	*qq = '\0';

	/* If the name is surrounded by either set of default
	   characters, remove them. */

	pp = ctemp;
	qq = ctemp + strlen (pp) - 1;
	if ((*pp == cs_DFLT_IDNTBEG && *qq == cs_DFLT_IDNTEND) ||
		(*pp == cs_DFLT_REPLBEG && *qq == cs_DFLT_REPLEND)
	   )
	{
		*qq = '\0';			/* trims trailing */
		CS_stcpy (ctemp,&ctemp [1]);	/* trims leading */
	}

	/* Careful, ctemp could be the null string now if we were
	   given a set of empty default wrappers. */

	if (*pp == '\0')
	{
		/* We were given all blanks. */

		CS_erpt (cs_INV_NAME);
		goto error;
	}

	/* Make sure all characters are legal.  pp should still
	   point to ctemp, and there must be at least one character
	   in the array.
	   
	   Note, we no longer force the name to upper case. However,
	   all comparisions remain case insensitive. */

	uniqueCount = alphaCount = 0;
	while (*pp != '\0')
	{
		cc = *pp++;
		if (cc == cs_Unique)
		{
			uniqueCount += 1;	
			continue;
		}
		if (cc >= '0' && cc <= '9') continue;
		if ((cc >= 'A' && cc <= 'Z') || (cc >= 'a' && cc <= 'z'))
		{
			alphaCount += 1;
			continue;
		}
		if (strchr (cs_Nmchset,cc) == NULL)
		{
			CS_erpt (cs_INV_NAME);
			goto error;
		}

		/* if cc == ' ' and we are still here, then spaces are
		   allowed in key names (i.e. space is a member of the set
		   defined by cs_Nmchset).  Check for a double space in the
		   name, a condition which we don't allow in any case.  We
		   have a specific error message for that condition. */

		if (cc == ' ' && *pp == ' ')
		{
			CS_erpt (cs_DBL_SPACE);
			goto error;
		}
	}
	if (uniqueCount > 1)
	{
		/* If the cs_Unique feature is enabled, we only allow one
		   of them. */

		CS_erpt (cs_INV_NAME);
		goto error;
	}
	if (alphaCount == 0)
	{
		/* Must have at least on alphabetic in the name. */

		CS_erpt (cs_INV_NAME);
		goto error;
	}

	/* If the result is longer than cs_KEYNM_MAX characters we
	   have an illegal name. */

	size = strlen (ctemp);						/*lint !e713 */
	if (size > cs_KEYNM_MAX)
	{
		CS_erpt (cs_INV_NAME);
		goto error;
	}

	/* We use to require that a key name begin with an alphabetic (prior
	   to release 9.01).  We now allow key names to begin with numerics
	   providing that the first non-numeric character is indeed alphabetic.
	   For the purposes of this particular test, the underscore character
	   is considered alphabetic. */

	pp = ctemp;
	if (*pp == cs_Unique) pp += 1;
	while ((cc = *pp++) != '\0') if (cc < '0' || cc > '9') break;
	ok = (cc == '_')  || (cc == cs_Unique) || (cc >= 'A' && cc <= 'Z') || (cc >= 'a' && cc <= 'z');
	if (!ok)
	{
		CS_erpt (cs_INV_NAME);
		goto error;
	}

	/* OK, the name has been processed, and is OK. */

	CS_stncp (name,ctemp,(int)(size + 1));
	return (0);

error:
	/* Return error status without modifying name at all. */
	return (-1);
}

/**********************************************************************
**	scale = CS_un2c (name);
**
**	char *name;					the name of a unit of length as a null
**								terminated string.
**	double scale;				returns the scale required to convert a value
**								in the named unit to meters by multiplication,
**								else zero.
**
**	Previously, only length units were supported and this
**	function peformed the search of the single unit table,
**	cs_Unittab and returned the appropriate value.  Now,
**	multiple types of units are supported.  To remain
**	compatible with existing code, this function performs
**	a length unit look up.  New code should use the
**	CS_unitlu function.  Eventually, we would like to do
**	away with this function.
**********************************************************************/

double EXP_LVL9 CS_un2d (Const char *name)

{
	return (CS_unitlu (cs_UTYP_LEN,name));
}

/**********************************************************************
**	CS_init (keep_dflts);
**
**	int keep_dflts;				bitmap of flags indicating what is
**								to be kept fropm previous thread.
**
**	This function exists specifically for the multi-threaded
**	environment of Windows 32/95/NT.  Threads are quite different
**	from UNIX processes in that they share the same data address
**	space as the parent (and all colleague) threads.  Thus, in
**	a multi-threaded program using CS-MAP, two threads would
**	quite normally be modifying the same data.
**
**	Since each thread has it's own stack space all automatic
**	variables are safe.  We need only concern ourselves with the
**	static/global variables in use.  There are several of these
**	in CS-MAP.
**
**	This function is the result of our initial effort to make CS-MAP
**	thread safe.  We currently rely on the compiler's ability
**	(Microsoft and Borland provide this, not sure about Watcom)
**	to declare a variable as being thread local.  While the
**	documentation is rather obscure, we assume this means that
**	all variable declared as thread local are assign addresses in
**	a data segment for which a unique copy is generated for each
**	new thread.  It is not clear from the documentation, but we
**	also assume that each new thread will get an uninitialized
**	copy of whatever was present in the parent thread.
**
**	The primary purpose of this module is to initialize all variables
**	declared as thread local to appropriate start up values. The
**	one argument indicates if the default values for datums,
**	ellipsoids, and units are to be preserved from the parent
**	thread.
**
**	If all of our assumptions are correct, and we have properly
**	isolated all the appropriate variables, you should be able
**	to use CS-MAP safely in a multi-threaded environment by:
**
**	1) Recompiling CS-MAP assuring that the csThread define actually
**	   maps to the correct stuff for you compiler.
**	2) Calling this function in the new thread code, immedaitely
**	   after the new thread is created.
**
**	If there are problems with multi-threaded use, the problems
**	will be in one of two areas:
**
**	1) File names and the muliple use of the cs_Dir character array.
**	2) The use of the NAD27/83 and HPGN datum shift caches.  These
**	   are malloc'ed, but the pointer to same is in a global static
**	   variable.  Thus, it is possible for two different threads to
**	   be manipulating the same stack without knowledge of what
**	   the other is doing.
**
**	If any of this doesn't work, we'll have to do some major
**	surgery to several functions, and change the calling sequence
**	of some.  Stick to the higher level Application Program
**	Interfaces and you wll be insulated from these changes.
**********************************************************************/

void EXP_LVL1 CS_init (int keepers)
{
#if _FILE_SYSTEM == _fs_UNIX
	extern char cs_DirsepC;
#endif
	extern char cs_DirK [];
	extern csThread char cs_Dir [];
	extern csThread char *cs_DirP;

	extern csThread char cs_Csname [];
	extern csThread char cs_Dtname [];
	extern csThread char cs_Elname [];

	extern csThread char csDtDflt [];
	extern csThread char csElDflt [];
	extern csThread char csLuDflt [];
	extern csThread char csAuDflt [];

	extern csThread int cs_Sortbs;

	extern csThread int cs_Error;
	extern csThread int cs_Errno;
	extern csThread int csErrlng;
	extern csThread int csErrlat;
	extern csThread unsigned short cs_ErrSup;

	extern csThread char csErrnam [];
	extern csThread char csErrmsg [];

	extern csThread struct csCscach_ *csCscachP;
	extern csThread int csCscachI;
	extern csThread struct csDtcach_ *csDtcachP;
	extern csThread int csDtcachI;

	extern csThread char *cs_CsKeyNames;
	extern csThread char *cs_DtKeyNames;
	extern csThread char *cs_ElKeyNames;
 	extern csThread struct cs_Csgrplst_ *cs_CsGrpList;

	int status;

	char chr_tmp [MAXPATH];

	/* First, we attempt to preserve the location of the
	   data directory.  First we attempt to assure that
	   there is something valid there.  Depending on the
	   file system: */

#if _FILE_SYSTEM == _fs_UNIX
	if (cs_Dir [0] == cs_DirsepC)
#else
	if (cs_Dir [1] == ':' || (cs_Dir [0] == '\\' && cs_Dir [1] == '\\'))
#endif
	{
		/* cs_Dir contents appear to be valid. */

		*cs_DirP = '\0';
		CS_stncp (chr_tmp,cs_Dir,sizeof (chr_tmp));
		status = CS_altdr (chr_tmp);
	}
	else
	{
		/* cs_Dir contents appear to be invalid. */

		status = CS_altdr (NULL);
	}

	/* If we haven't located a valid directory, we establish
	   a default name.  While probably invalid, it is at least
	   it is the same value which was initially established
	   at compile time. */

	if (status != 0)
	{
		cs_DirP = CS_stcpy (cs_Dir,cs_DirK);
	}

	/* Initialize the dictionary file names. */

	CS_stcpy (cs_DirP,(char *)cs_Csname);
	if (CS_access (cs_Dir,0) || (keepers & cs_THRD_CSNAME) == 0)
	{
		CS_stcpy ((char *)cs_Csname,cs_CS_NAME);
	}
	CS_stcpy (cs_DirP,(char *)cs_Dtname);
	if (CS_access (cs_Dir,0) || (keepers & cs_THRD_DTNAME) == 0)
	{
		CS_stcpy ((char *)cs_Dtname,cs_DAT_NAME);
	}
	CS_stcpy (cs_DirP,(char *)cs_Elname);
	if (CS_access (cs_Dir,0) || (keepers & cs_THRD_ELNAME) == 0)
	{
		CS_stcpy ((char *)cs_Elname,cs_ELL_NAME);
	}

	/* Initialize the defaults. */

	if ((keepers & cs_THRD_DTDFLT) == 0) csDtDflt [0] = '\0';
	if ((keepers & cs_THRD_ELDFLT) == 0) csElDflt [0] = '\0';
	if ((keepers & cs_THRD_LUDFLT) == 0) csLuDflt [0] = '\0';
	if ((keepers & cs_THRD_AUDFLT) == 0) csAuDflt [0] = '\0';

	/* The remainder are always initialized.  Application programs
	   can re-initalize as they like when this function returns. */

#if _MEM_MODEL == _mm_VIRTUAL || _MEM_MODEL == _mm_FLAT
	cs_Sortbs = 128 * 1024;
#else
	cs_Sortbs = 24 * 1024;
#endif

	cs_Error = 0;
	cs_Errno = 0;
	csErrlng = 0;
	csErrlat = 0;
	cs_ErrSup = 0;

	csErrnam [0] = '\0';
	csErrmsg [0] = '\0';

	csCscachP = NULL;
	csCscachI = cs_CSCACH_MAX;
	csDtcachP = NULL;
	csDtcachI = cs_DTCACH_MAX;

	cs_CsKeyNames = NULL;
	cs_DtKeyNames = NULL;
	cs_ElKeyNames = NULL;
	cs_CsGrpList = NULL;

	return;
}

/**********************************************************************
**	CS_quadF (xy,xx,yy,x_off,y_off,quad);
**	CS_quadI (&xx,&yy,xy,x_off,y_off,quad);
**
**	double xy [2];				the user defined cartesian system XY coordinate.
**	double xx;					the X coordinate in the projection cartesian
**								system.
**	double yy;					the Y coordinate in the projection cartesian
**								system.
**	double x_off;				the X offset, aka False Easting, aka the X
**								coordinate of the False Origin.
**	double y_off;				the Y offset, aka False Northing, aka the Y
**								coordinate of the False Origin.
**	short quad;					a bit map of the operations to be performed.
**
**	The xx [] and the &xx,&yy arguments may point to the same
**	memory locations.
**
**	The quadF form is designed specifically for calling by the
**	forward projection functions; the quadI form for use by the
**	inverse projection functions.
**
**	QuadF returns its results in the xy array.  QuadI returns
**	its results in the xx and yy variables.  Thus, in the
**	quadI form, the xx and yy arguments must be pointers to
**	double.
**
**	The quad argument is a bit map of the functions to be
**	performed.  Zero produces the standard right handed result.
**	If quad is zero, these functions are an expensive way to deal
**	with the false origin.  For performance purposes, and since
**	non-standard cartesian systems are so rare, most all
**	projection functions deal with the false origin on their
**	own if quad is zero.
**
**	The bit map should be defined by oring one or more of the
**	following manifest constants:
**
**	cs_QUAD_SWAP:	swap the X and Y axis.
**	cs_QUAD_INVX:	invert X axis.
**	cs_QUAD_INVY:	invert Y axis.
**
**	In quadF, the axis inversion is applied first.  The false
**	origin is then applied.  Axis swapping is performed last.
**	Obviously, the order is reversed in quadI.
**
**********************************************************************/

void EXP_LVL9 CS_quadF (	double xy [2],
							double xx,
							double yy,
							double x_off,
							double y_off,
							short quad)
{
	if ((quad & cs_QUAD_SWAP) == 0)
	{
		xy [XX] = ((quad & cs_QUAD_INVX) != 0 ? -xx : xx) + x_off;
		xy [YY] = ((quad & cs_QUAD_INVY) != 0 ? -yy : yy) + y_off;
	}
	else
	{
		xy [YY] = ((quad & cs_QUAD_INVX) != 0 ? -xx : xx) + x_off;
		xy [XX] = ((quad & cs_QUAD_INVY) != 0 ? -yy : yy) + y_off;
	}
	return;
}

void EXP_LVL9 CS_quadI (double *xx,
						double *yy,
						Const double xy [2],
						double x_off,
						double y_off,
						short quad)
{
	double my_x;
	double my_y;

	if ((quad & cs_QUAD_INVX) != 0)
	{
		my_x = -(((quad & cs_QUAD_SWAP) == 0 ? xy [XX] : xy [YY]) - x_off);
	}
	else
	{
		my_x =   ((quad & cs_QUAD_SWAP) == 0 ? xy [XX] : xy [YY]) - x_off;
	}

	if ((quad & cs_QUAD_INVY) != 0)
	{
		my_y = -(((quad & cs_QUAD_SWAP) == 0 ? xy [YY] : xy [XX]) - y_off);
	}
	else
	{
		my_y =   ((quad & cs_QUAD_SWAP) == 0 ? xy [YY] : xy [XX]) - y_off;
	}
	*xx = my_x;
	*yy = my_y;
	return;
}

/*
	The following function is used to convert XY min/maxes as
	developed by the Setup functions and:

	1) Apply the approriate quad inversions.
	2) Add the false origin.
	3) Provide for the axis swap.
	4) Assure that the end result is a properly ordered
	   min/max.
*/

void EXP_LVL9 CS_quadMM (	double min_xy [2],
							double max_xy [2],
							double x_off,
							double y_off,
							short quad)
{
	double my_min [2];
	double my_max [2];

	CS_quadF (my_min,min_xy [XX],min_xy [YY],x_off,y_off,quad);
	CS_quadF (my_max,max_xy [XX],max_xy [YY],x_off,y_off,quad);

	min_xy [XX] = (my_min [XX] <= my_max [XX]) ? my_min [XX] : my_max [XX];
	min_xy [YY] = (my_min [YY] <= my_max [YY]) ? my_min [YY] : my_max [YY];

	max_xy [XX] = (my_max [XX] >= my_min [XX]) ? my_max [XX] : my_min [XX];
	max_xy [YY] = (my_max [YY] >= my_min [YY]) ? my_max [YY] : my_min [YY];
	return;
}


/**********************************************************************
**	protected = CS_prchk (prot_val);
**
**	short prot_val;				a protection value extracted from a dictionary
**								definition record.
**	int protected;				returns TRUE if the item would be considered
**								protected by the appropriate update function.
**								Else, returns FALSE.
**
**	In all probability it will never happen, but it is possible that
**	a clock tick between the time you call this function and the
**	time that you call the update function will change the protection
**	status of the dictionary item.  Note, the clock tick may not
**	necessarily be exactly at midnight.
**********************************************************************/

int EXP_LVL1 CS_prchk (short prot_val)
{
	extern short cs_Protect;

	short cs_time;		/* Number of days since Jan 1, 1990 */


	if (cs_Protect < 0) return (FALSE);
	if (prot_val == 1) return (TRUE);
	cs_time = (short)((CS_time ((cs_Time_ *)0) - 630720000L) / 86400L);
	return (prot_val < (cs_time - cs_Protect));
}

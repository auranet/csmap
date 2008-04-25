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
	** company.                                                        **
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

			 File Name: $RCSfile: CS_COMP.C $
		   Description:	Dictionary Compiler
			   Purpose:	Compiles a coordinate system dictionary from
						an ASCII source file.

	  Calling Sequence:	CSCOMP [-c] [-b] [-t] [source_path [result_path]]

		Revision Level:	$Revision: #3 $
		 Check In Date:	$Date: 2005/07/26 $

		Last Revision:	$Log: CS_COMP.C $
		Last Revision:	Revision 11.1300  2005/05/25 23:27:07  nto
		Last Revision:	Official Release 11.13
		Last Revision:	Revision 11.1200  2005/01/15 18:27:09  nto
		Last Revision:	Official Release of CS-MAP 11.12, 11:26am 15 Jan 2005
		Last Revision:	Revision 11.1100  2004/11/01 18:53:06  nto
		Last Revision:	Official release 11.11
		Last Revision:	Revision 11.1001  2004/10/07 19:25:15  nto
		Last Revision:	Revision 11.900  2004/03/26 17:02:22  nto
		Last Revision:	Official release: 11.09 - 3/25/2003
		Last Revision:	Revision 11.800  2004/01/13 23:29:11  nto
		Last Revision:	Revision 11.700  2003/12/19 01:49:51  nto
		Last Revision:	Official release 11.07
		Last Revision:	Revision 11.600  2003/12/04 02:46:26  nto
		Last Revision:	Release 11.06.  Never shipped. Source captured in prep for C++ V7.
		Last Revision:	Revision 11.501  2003/08/22 21:12:53  nto
		Last Revision:	Official Release: 11.05
		Last Revision:	Revision 11.401  2003/05/01 23:06:20  nto
		Last Revision:	Revision 11.300  2003/02/25 04:29:14  nto
		Last Revision:	Official Release 11.03
		Last Revision:	Revision 11.100  2002/11/22 19:38:42  nto
		Last Revision:	Official release: 11.01
		Last Revision:	Revision 10.1500  2002/09/22 00:01:18  nto
		Last Revision:	Official Release:= 10.15
		Last Revision:	Revision 10.1400  2002/08/09 18:14:20  nto
		Last Revision:	Revision 10.1200  2002/07/14 03:26:13  nto
		Last Revision:	Revision 10.1100  2002/06/13 14:18:35  nto
		Last Revision:	Release 10.11 Official
		Last Revision:	Revision 10.1000  2002/02/23 21:18:24  nto
		Last Revision:	Official Release of 10.10, 2/22/02 - Norm Olsen
		Last Revision:	Revision 10.900  2001/09/24 04:31:09  nto
		Last Revision:	Revision 10.701  2001/09/18 19:12:05  nto
		Last Revision:	Use MAXPATH (instead of 128) as the dimension of character
		Last Revision:	arrays used for path names.
		Last Revision:	Revision 10.700  2001/01/25 04:13:45  nto
		Last Revision:	Revision 10.600  2000/12/11 06:39:39  nto
		Last Revision:	Release 10.06
		Last Revision:	Revision 10.500  2000/10/27 07:38:17  nto
		Last Revision:	Official Release 10.05
		Last Revision:	Revision 10.400  2000/09/13 01:16:51  nto
		Last Revision:	Release 10.04
		Last Revision:	Revision 10.301  2000/09/12 21:51:33  nto
		Last Revision:	Take out the extent stuff.

		       * * * * R E M A R K S * * * *

	This program converts the ASCII COORDSYS.ASC, DATUNS.ASC, and
	ELIPSOID.ASC files into their binary form.  This serves two
	purposes:

	1) Allows all coordinate system definitions to be maintained
	   in ASCII and controlled by a source control mechanism.
	2) Enables production of COORDSYS files on various platforms
	   with various byte orderings.

	If the source path is not specified, the current directory
	is assumed.

	If the destination path argument is not given, the results
	are written to files in the directory encoded into the cs_Dir
	global variable at the time this module was last linked.

	The "c" option causes unencrypted files to be produced.
	The "t" option causes test components to be included.
	The "d" option causes demonstration magic numbers to be used.
	The "e" option supresses the automatic generation of extents.

	Mentor Software now ships all files encrypted. The /c option
	is provided for debugging and testing only. The data in these
	files is valuable and we don't believe it should be given away.

	Please excuse the rather crude natire of this program.  For the
	viability of the CS_MAP product, however, it must be able to run
	on just about any system which has a C compiler, and we cannot
	require the user to have a license to a LEX/YACC type product.

	Note, over time, this main line has become a simple interafce
	to the CScscomp, CSdtcomp, CSdtcomp, and CSmrcomp modules which
	are now maintained as part of the normal library.  Most all of
	the heavy lifting is done in these modules.

******************************************************************************/

#ifdef LABEL_MODULE
static char revlvl [] = {"$Id: //depot/Libraries/CsMap/current/src/CS_COMP.C#3 $"};
#endif

#include "cs_map.h"

#if _RUN_TIME < _rt_UNIXPCC
#	include <conio.h>		/* for acknowledgment */
#else
#       include <unistd.h>
#       include <ctype.h>
#       include <limits.h>  
#endif

#if defined (__TURBOC__) && defined (__MSDOS__)
unsigned _stklen = 16384;		/* was once required, probably not anymore  */
#endif 

void usage (void);
void acknowledge (void);
int err_disp (char *mesg);
int cs_Batch;

int main (int argc,char *argv [])
{
	extern char cs_Dir [];
	extern char *cs_DirP;
	extern char cs_Csname [];
	extern char cs_Dtname [];
	extern char cs_Elname [];
	extern char cs_OptchrC;
	extern char cs_DirsepC;
	extern int cs_Sortbs;
	extern union cs_Bswap_ cs_BswapU;

	int ii;
	int st;

	int batch;
	int crypt;
	int demo;
	int extents;
	int test;
	int warn;
	int flags;
	int err_cnt;

	char *cp;

	char src_dir [MAXPATH];
	char dst_dir [MAXPATH];
	char src_name [MAXPATH];
	char el_path [MAXPATH];
	char dt_path [MAXPATH];
	char cs_path [MAXPATH];
	char mr_path [MAXPATH];

#if _MEM_MODEL == _mm_VIRTUAL
	cs_Sortbs = (128 * 1024);
#endif

	/* The following is necessary to set up the target directory
	   of the results. A NULL argument says see if the
	   environmental variable is set. The null string says
	   check the current directory. In any case, if a COORDSYS
	   is not found, cs_Dir is initialized to the current
	   directory, even in the event of an error. */

	st = CS_altdr (NULL);
	if (st != 0) CS_altdr ("");

	/* Process the arguments on the command line. */
	crypt = TRUE;
	batch = FALSE;
	cs_Batch = FALSE;
	test = FALSE;
	demo = FALSE;
	extents = TRUE;			/* Extents are normally on, option turns
							   them off. */
	warn = FALSE;
	src_dir [0] = '\0';
	dst_dir [0] = '\0';
	for (ii = 1;ii < argc;ii++)
	{
		cp = argv [ii];
		if (*cp == cs_OptchrC)
		{
			/* Here if the current argument is an
			   option. */

			cp += 1;
			if (*cp == 'b' || *cp == 'B')
			{
				batch = TRUE;
				cs_Batch = TRUE;
			}
			else if (*cp == 'c' || *cp == 'C')
			{
				crypt = FALSE;
			}
			else if (*cp == 'd' || *cp == 'D')
			{
				demo = TRUE;
			}
			else if (*cp == 'e' || *cp == 'E')
			{
				extents = FALSE;
			}
			else if (*cp == 's' || *cp == 'S')
			{
				/* Force CS_bswap to think that it is running
				   on a big endian machine, thus causing
				   the results to be written in big
				   endian, regardless of the system
				   upon which this program was compiled. */

				cs_BswapU.cccc [0] = 0x03;
				cs_BswapU.cccc [1] = 0x02;
				cs_BswapU.cccc [2] = 0x01;
				cs_BswapU.cccc [3] = 0x00;
			}
			else if (*cp == 't' || *cp == 'T')
			{
				test = TRUE;
			}
			else if (*cp == 'w' || *cp == 'W')
			{
				warn = TRUE;
			}
			else
			{
				printf ("Unknown option: %c\n",*cp);
				usage ();
				if (!batch) acknowledge ();
				return (1);
			}
			continue;
		}

		/* If it isn't an option, it must be the next
		   positional argument. */
		if (src_dir [0] == '\0')
		{
			/* We haven't captured a source directory
			   argument yet, so this argument must be
			   the source file name. */
			CS_stncp (src_dir,cp,sizeof (src_dir));
		}
		else if (dst_dir [0] == '\0')
		{
			/* We've captured a source directory name, so this
			   positional argument must be the destination
			   directory. */
			(void)CS_stncp (dst_dir,cp,sizeof (dst_dir));
		}
		else
		{
			/* We've seen a source directory and a destination
			   directory name.  Don't know what this argument
			   would be. */
			printf ("Two many positional arguments (%-16.16s)\n",argv [ii]);
			usage ();
			if (!batch) acknowledge ();
			return (1);
		}
	}

	/* Adjust as necessary. */
	if (src_dir [0] != '\0')
	{
		cp = src_dir + strlen (src_dir);
		if (*(cp - 1) != cs_DirsepC)
		{
			*cp++ = cs_DirsepC;
			*cp = '\0';
		}
	}

	if (dst_dir [0] != '\0')
	{
		cp = CS_stcpy (cs_Dir,dst_dir);
		if (*(cp - 1) != cs_DirsepC)
		{
			*cp++ = cs_DirsepC;
			*cp = '\0';
		}
		cs_DirP = cp;
	}
	flags = 0;
	if (crypt)   flags |= cs_CMPLR_CRYPT;
	if (demo)    flags |= cs_CMPLR_DEMO;
	if (test)    flags |= cs_CMPLR_TEST;
	if (warn)    flags |= cs_CMPLR_WARN;
	if (extents) flags |= cs_CMPLR_EXTENTS;
	strcpy (cs_DirP,cs_Elname);
	strcpy (el_path,cs_Dir);
	strcpy (cs_DirP,cs_Dtname);
	strcpy (dt_path,cs_Dir);
	strcpy (cs_DirP,cs_Csname);
	strcpy (cs_path,cs_Dir);
	*cs_DirP = '\0';
	strcpy (mr_path,cs_Dir);

	/* Compile the Ellipsoid Dictionary. */
	strcpy (src_name,src_dir);
	strcat (src_name,"ELIPSOID.ASC");
	printf ("Compiling %s to %s.\n",src_name,el_path);
	err_cnt = CSelcomp (src_name,el_path,flags,err_disp);
	if (err_cnt != 0)
	{
		printf ("Compilation of %s failed, %s removed.\n",src_name,el_path);
		if (!batch) acknowledge ();
		return (1);
	}

	/* Compile the Datum Dictionary. */
	strcpy (src_name,src_dir);
	strcat (src_name,"DATUMS.ASC");
	printf ("Compiling %s to %s.\n",src_name,dt_path);
	err_cnt = CSdtcomp (src_name,dt_path,flags,el_path,err_disp);
	if (err_cnt != 0)
	{
		printf ("Compilation of %s failed, %s removed.\n",src_name,dt_path);
		if (!batch) acknowledge ();
		return (1);
	}

	/* Compile the Coordinate System Dictionary. */
	strcpy (src_name,src_dir);
	strcat (src_name,"COORDSYS.ASC");
	printf ("Compiling %s to %s.\n",src_name,cs_path);
	err_cnt = CScscomp (src_name,cs_path,flags,el_path,dt_path,err_disp);
	if (err_cnt != 0)
	{
		printf ("Compilation of %s failed, %s removed.\n",src_name,cs_path);
		if (!batch) acknowledge ();
		return (1);
	}
	
	/* Compile the Multiple Regression definition files. */
	strcpy (src_name,src_dir);
	strcat (src_name,"MREG.ASC");
	printf ("Compiling %s to the %s directory.\n",src_name,mr_path);
	err_cnt = CSmrcomp (src_name,mr_path,flags,dt_path,err_disp);
	if (err_cnt != 0)
	{
		printf ("%d errors detected in %s.\n",err_cnt,src_name);
		printf ("Multiple Regression compile to %s is not complete.\n",mr_path);
		if (!batch) acknowledge ();
		return (1);
	}

	/* We're done. */
	printf ("All dictionaries and multiple regressions compiled successfully.\n");
	if (!batch) acknowledge ();

	return (0);
}

int err_disp (char *mesg)
{
	extern int cs_Batch;

	int cc;

	cc = '\0';
	if (!CS_strnicmp (mesg,"Warning",7))
	{
		printf ("\r%s\n",mesg);
	}
	else
	{
		printf ("\rError: %s\n",mesg);
	}
	if (!cs_Batch)
	{
#if _RUN_TIME < _rt_UNIXPCC
		/* Use this if kbhit/getch are available. */
		printf ("Press C to cancel, any other key to continue: ");
		while (kbhit ()) getch ();
		while (!kbhit ());
		cc = getch ();
		printf ("\n");
#elif __cplusplus
		/* Use this if kbhit/getch not available and C++ */
		char strbuf [MAX_INPUT];
		cout << "Press any key to continue: " << flush;
		cin.getline(strbuf, MAX_INPUT, '\n');
		cout << "\n" << flush;
		cc = (int)(strbuf[0]);
#else
		/* Use this as last resort. Note, no flush!!! */
		printf ("Press C to cancel, any other key to continue: ");
		cc = getc (stdin);
		printf ("\n");
#endif
	}
	return (cc == 'C' || cc == 'c');
}

void acknowledge (void)
{
#if _RUN_TIME < _rt_UNIXPCC
	/* Use this if kbhit/getch are available. */
	printf ("Press any key to continue: ");
	while (kbhit ()) getch ();
	while (!kbhit ());
	getch ();
	printf ("\n");
#elif __cplusplus
	/* Use this if kbhit/getch not available and C++ */
	char strbuf [MAX_INPUT];
	cout << "Press any key to continue: " << flush;
	cin.getline(strbuf, MAX_INPUT, '\n');
	cout << "\n" << flush;
#else
	/* Use this as last resort. Note, no flush!!! */
	printf ("Press any key to continue: ");
	(void)getc (stdin);
	printf ("\n");
#endif
	return;
}

void usage (void)
{
	extern char cs_OptchrC;

	(void)printf ("Usage: CS_COMP [%cc] [%cb] [%cd] [%ct] [source_dir [result_dir]]\n",cs_OptchrC,cs_OptchrC,cs_OptchrC,cs_OptchrC);
	return;
}

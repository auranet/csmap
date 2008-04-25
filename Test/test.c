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

			 File Name: $RCSfile: CS_test.c $
		   Description:
			   Purpose:

		Revision Level:	$Revision: #14 $
		 Check In Date:	$Date: 2007/01/12 $

		Last Revision:	$Log: CS_test.c $
		Last Revision:	Revision 11.1300  2005/05/25 23:27:18  nto
		Last Revision:	Official Release 11.13
		Last Revision:	Revision 11.1200  2005/01/15 18:27:16  nto
		Last Revision:	Official Release of CS-MAP 11.12, 11:26am 15 Jan 2005
		Last Revision:	Revision 11.1100  2004/11/01 18:53:14  nto
		Last Revision:	Official release 11.11
		Last Revision:	Revision 11.1001  2004/10/07 19:25:22  nto
		Last Revision:	Revision 11.903  2004/10/07 02:37:50  nto
		Last Revision:	Removed table driven aspects of test J.
		Last Revision:	Revision 11.902  2004/08/07 20:55:00  nto
		Last Revision:	Added deferred close functionality.
		Last Revision:	Revision 11.901  2004/08/07 03:40:18  nto
		Last Revision:	Added the msi2epsg and CS_epsg2msi functions to test J.
		Last Revision:	Revision 11.900  2004/03/26 17:02:28  nto
		Last Revision:	Official release: 11.09 - 3/25/2003
		Last Revision:	Revision 11.801  2004/03/25 21:12:47  nto
		Last Revision:	Added Test J to check EPSG & WKT conversions.
		Last Revision:	Revision 11.800  2004/01/13 23:29:17  nto
		Last Revision:	Revision 11.701  2004/01/13 20:48:19  nto
		Last Revision:	Added test of the CSwktDictRpl function.
		Last Revision:	Revision 11.700  2003/12/19 01:49:57  nto
		Last Revision:	Official release 11.07
		Last Revision:	Revision 11.601  2003/12/19 01:10:38  nto
		Last Revision:	Added datum and ellipsoid comparison to test I (WKT).
		Last Revision:	Revision 11.600  2003/12/04 02:46:32  nto
		Last Revision:	Release 11.06.  Never shipped. Source captured in prep for C++ V7.
		Last Revision:	Revision 11.502  2003/11/24 19:00:29  nto
		Last Revision:	Added Test I for WKT stuff.
		Last Revision:	Revision 11.501  2003/08/22 21:12:59  nto
		Last Revision:	Official Release: 11.05
		Last Revision:	Revision 11.401  2003/05/01 23:06:26  nto
		Last Revision:	Revision 11.302  2003/04/29 02:32:25  nto
		Last Revision:	Commented out some stuff that does compile under Unix.
		Last Revision:	Revision 11.301  2003/04/28 22:49:02  nto
		Last Revision:	Added test of Geoid Height functions.
		Last Revision:	Revision 11.300  2003/02/25 04:29:20  nto
		Last Revision:	Official Release 11.03
		Last Revision:	Revision 11.102  2003/02/15 01:33:01  nto
		Last Revision:	Added some additional test to the dictionary test functions.
		Last Revision:	Revision 11.101  2002/12/17 04:09:33  nto
		Last Revision:	Added the check of RGF93 memory arrays.
		Last Revision:	Revision 11.100  2002/11/22 19:38:48  nto
		Last Revision:	Official release: 11.01
		Last Revision:	Revision 10.1504  2002/11/22 19:22:31  nto
		Last Revision:	Added some datum shift logging tests.
		Last Revision:	Revision 10.1503  2002/11/12 04:24:34  nto
		Last Revision:	Added a projection or two to the creep test.
		Last Revision:	Revision 10.1502  2002/11/08 06:16:34  nto
		Last Revision:	Updated the first and last names in the dictionary test lists.
		Last Revision:	Revision 10.1501  2002/10/03 00:02:36  nto
		Last Revision:	Removed UNIX I/O in favor of ANSI stream I/O.
		Last Revision:	Revision 10.1500  2002/09/22 00:01:24  nto
		Last Revision:	Official Release:= 10.15
		Last Revision:	Revision 10.1403  2002/09/21 23:20:33  nto
		Last Revision:	Disabled test B for the OSTN?? projection types.
		Last Revision:	Revision 10.1402  2002/09/20 22:48:54  nto
		Last Revision:	Took the new Danish stuff out of Test B
		Last Revision:	Revision 10.1401  2002/09/20 04:36:23  nto
		Last Revision:	Added close of Ostn??_ objects to fix file descriptor leak.  Also
		Last Revision:	corrected the reduced longitude range of testE.
		Last Revision:	Revision 10.1400  2002/08/09 18:14:26  nto
		Last Revision:	Revision 10.1200  2002/07/14 03:26:22  nto
		Last Revision:	Revision 10.1100  2002/06/13 14:18:41  nto
		Last Revision:	Release 10.11 Official
		Last Revision:	Revision 10.1000  2002/02/23 21:18:30  nto
		Last Revision:	Official Release of 10.10, 2/22/02 - Norm Olsen
		Last Revision:	Revision 10.901  2002/02/19 05:41:52  nto
		Last Revision:	Adjusted do that the Danish System 34 would not produce error
		Last Revision:	diagnostics.
		Last Revision:	Revision 10.900  2001/09/24 04:31:14  nto
		Last Revision:	Revision 10.701  2001/09/18 19:32:08  nto
		Last Revision:	Added fairly rigorous test of CS_ecvt.
		Last Revision:	Revision 10.700  2001/01/25 04:13:55  nto
		Last Revision:	Revision 10.600  2000/12/11 06:39:49  nto
		Last Revision:	Release 10.06
		Last Revision:	Revision 10.501  2000/12/11 06:33:12  nto
		Last Revision:	Revision 10.500  2000/10/27 07:38:26  nto
		Last Revision:	Official Release 10.05
		Last Revision:	Revision 10.401  2000/09/13 16:40:04  nto
		Last Revision:	Cleaned up the Krovak stuff a bit, pretty trivial.
		Last Revision:	Revision 10.400  2000/09/13 01:17:01  nto
		Last Revision:	Release 10.04
		Last Revision:	Revision 10.301  2000/09/12 21:53:34  nto
		Last Revision:	Added a test on the Military Grid Reference System.
		Last Revision:	Revision 10.300  2000/04/04 23:18:31  nto
		Last Revision:	Revision 10.201  2000/04/03 23:24:11  nto
		Last Revision:	Skip the scale test for the Krovak projection.
		Last Revision:	Revision 10.200  2000/03/02 18:51:22  nto
		Last Revision:	Revision 10.3  2000/02/14 07:59:13  nto
		Last Revision:	Fixed a bug in releasing datum conversion memory.
		Last Revision:	Revision 10.2  2000/02/14 07:27:02  nto
		Last Revision:	Removed the old datum stuff, added the new stuff.  Also, added
		Last Revision:	a test of the new hook functions.
		Last Revision:	Revision 10.1  1999/11/04 00:30:08  nto
		Last Revision:	Adjusted for three dimensions.
		Last Revision:	Revision 10.0  1999/10/05 18:27:19  nto
		Last Revision:	Revision 9.99  1999/10/05 17:36:29  nto
		Last Revision:	Revision 1.2  1999/09/07 14:25:44  nto
		Last Revision:	This revision compiles, links, and generates a successful test program.

******************************************************************************/

#include "cs_map.h"
#include "cs_wkt.h"
#include <ctype.h>
#include <time.h>

#if _RUN_TIME < _rt_UNIXPCC
#	include <crtdbg.h>
#	include <conio.h>
#endif

#ifndef CLK_TCK
#	define CLK_TCK CLOCKS_PER_SECOND
#endif

struct tst_lst_
{
	char name [24];
	struct cs_Csdef_ *cs_ptr;
	struct cs_Dtdef_ *dt_ptr;
	struct cs_Eldef_ *el_ptr;
};

#ifdef __HEAP__
	static unsigned long mem_used;
#	if defined (_MSC_VER)
#		if _MSC_VER >= 800 && _MSC_VER < 1300
#			define heapwalk _heapwalk
#		endif
#	endif
#	if defined (__WATCOMC__)
#		define heapwalk _heapwalk
#	endif
#endif

/*
	Make sure we operate on those included in Test 4
	to verify that we didn't alter the entries
	adversely.
*/

__ALIGNMENT__10				/* Required by some Sun compilers. */
static struct tst_lst_ el_tst [] =
{
	{     "APL4-5",NULL,NULL},	/* Try to keep set to the first one */
	{     "CLRK66",NULL,NULL},
	{    "T-BPCNC",NULL,NULL},
	{     "SPHERE",NULL,NULL},
	{   "CLRK-IGN",NULL,NULL},
	{      "INTNL",NULL,NULL},
	{      "UNITS",NULL,NULL},
	{     "CLRK80",NULL,NULL},
	{    "GRS1980",NULL,NULL},
	{      "UNITE",NULL,NULL},
	{      "WGS84",NULL,NULL},	/* Try to keep set to the last one */
	{           "",NULL,NULL}
};

__ALIGNMENT__11				/* Required by some Sun compilers. */
static struct tst_lst_ dt_tst [] =
{
	{   "ZANDERIJ",NULL,NULL},	/* last one */
	{      "NAD27",NULL,NULL},
	{      "NAD83",NULL,NULL},
	{   "WGS72-BW",NULL,NULL},
	{    "TEST-MO",NULL,NULL},
	{     "PSAD56",NULL,NULL},
	{      "OLDHI",NULL,NULL},
	{      "WGS72",NULL,NULL},
	{   "TIMBALAI",NULL,NULL},
	{    "ADINDAN",NULL,NULL},	/* first one */
	{           "",NULL,NULL}
};
__ALIGNMENT__12				/* Required by some Sun compilers. */
static struct tst_lst_ cs_tst [] =
{			    
	{          "UTM27-13",NULL,NULL},
	{        "10TM115-27",NULL,NULL},	/* First one */
	{              "AK-1",NULL,NULL},
	{             "WY-EC",NULL,NULL},
	{           "UTM-13N",NULL,NULL},
	{              "US48",NULL,NULL},
	{           "UTM-13S",NULL,NULL},
	{              "CO-N",NULL,NULL},
	{             "WY-WC",NULL,NULL},
	{                "LL",NULL,NULL},
	{            "T-SGSO",NULL,NULL},
	{          "TEST-OMB",NULL,NULL},
	{               "YAP",NULL,NULL},
	{"YellowMedicineMN-M",NULL,NULL},	/* Last one */
	{           "TEST-TE",NULL,NULL},
	{           "TEST-LE",NULL,NULL},
	{                  "",NULL,NULL}
};

extern int cs_Error;
extern int cs_Errno;
extern char cs_DirsepC;

void usage (int batch);
int CStest1 (int verbose,int crypt);
int CStest2 (int verbose,int crypt);
int CStest3 (int verbose,int crypt);
int CStest4 (int verbose,char *test_file);
int CStest5 (int verbose,long duration);
int CStest6 (int verbose,int crypt); 
int CStest7 (int verbose,int crypt); 
int CStest8 (int verbose,int crypt); 
int CStest9 (int verbose);
int CStestA (int verbose,char *test_file);
int CStestB (int verbose,long duration);
int CStestC (int verbose,long duration);
int CStestD (int verbose,long duration);
int CStestE (int verbose,long duration);
int CStestF (int verbose,long duration);
int CStestG (int verbose,long duration);
int CStestH (int verbose,long duration);
int CStestI (int verbose,long duration);
int CStestJ (int verbose,long duration);
int CStestS (int verbose);
double CStestRN (double low, double high);
double CStstsclk (struct cs_Csprm_ *csprm,double ll [2]);
double CStstsclh (struct cs_Csprm_ *csprm,double ll [2]);
double CStstcnvrg (struct cs_Csprm_ *csprm,double ll[2]);

int cs_MeFlag = 0;
char cs_MeKynm [128];
char cs_MeFunc [128];
double cs_Coords [3];
int cs_InitialRandomValue;
char test_file [MAXPATH];

/**********************************************************************
**	CS_Test [/p30] [/ddirectory] [/t12345] [test_file]
**
**	/t				use the t option to indicate the test
**					numbers, and the specific sequence
**					they are to be run.
**	/d				use the /d argument to indicate the directory
**					which is to be searched for the dictionary
**					and datum conversion files.
**	/v				use the v option to indicate that the
**					program is to produce verbose output
**					concerning what it is doing.
**	/p				use the p variable to extent or reduce the
**					number of iterations in a test.  The base
**					value is 30.
**	test_file		if present, the one positional argument
**					is the name of the test file which is
**					to be used for test number 4.
**
**	No arguments are required, but this module expects
**	the release supplied Coordinate System Dictionary
**	and Datum Dictionary to be in the location defined
**	in CSdata.c.
**
**	The heap checker built into this module is only
**	activated by having the -D__HEAP__ on the command
**	line when this module is compiled.  The heap calls
**	included are available in the Borland 4.5 library;
**	maybe some others.  In any case, the test always
**	fails the first time through.  I don't know why.
**	However, if you repeat whatever the first test
**	is, it passes just fine.  The run-time library
**	must be allocating memory somewhere, for some
**	reason, but I can't figure out what that reason
**	may be.
**
**	This test program assumes that there are at least
**	two entries in each of the dictionary files.
**
**********************************************************************/

int main (int argc,char *argv [])
{
	extern char cs_Dir [];
	extern char *cs_DirP;
	extern char cs_OptchrC;
	extern union cs_Bswap_ cs_BswapU;

	extern short cs_Protect;
	extern char cs_Unique;

	extern struct csNad27ToNad83_* csNad27ToNad83;
	extern struct csNad83ToHarn_* csNad83ToHarn;
	extern struct csAgd66ToGda94_* csAgd66ToGda94;
	extern struct csAgd84ToGda94_* csAgd84ToGda94;
	extern struct csNzgd49ToNzgd2K_* csNzgd49ToNzgd2K;

	extern struct csAts77ToCsrs_* csAts77ToCsrs;
	extern struct csNad83ToCsrs_* csNad83ToCsrs;
	extern struct csVertconUS_* csVertconUS;
	extern struct cs_Osgm91_ *cs_Osgm91Ptr;
	extern struct csTokyoToJgd2k_ *csTokyoToJgd2k;
	extern struct csRgf93ToNtf_* csRgf93ToNtf;

	extern struct cs_Ostn97_ *cs_Ostn97Ptr;
	extern struct cs_Ostn02_ *cs_Ostn02Ptr;

	short protectSave;
	char uniqueSave;

	int ii;
	int st;
	int ok_cnt;
	int bad_cnt;
	int crypt;
	int batch;
	int verbose;
	int test_st;
	int initial_fd;
	int final_fd;

	unsigned seed;

	long duration;

	char *cp;
	csFILE *chk_fs;
	csFILE *csStrm;

	char tests [128];
	char alt_dir [MAXPATH];

	/* Save the distribution values used to activate the dictionary
	   protection system.  We use these to restore the protection
	   mode back to normal after each test. */
	protectSave = cs_Protect;
	uniqueSave = cs_Unique;

	/* Set up the current directory as the possible source for
	   the dictionaries and other data files.  This only works
	   under MS-DOS unless they've changed UNIX since this
	   old fart last worked on a UNIX system.  The /d option
	   overrides this selection if present on the command
	   line. */

#if _OPR_SYSTEM != _os_UNIX
	strncpy (alt_dir,argv [0],sizeof (alt_dir));
	alt_dir [sizeof (alt_dir) - 1] = '\0';
	cp = strrchr (alt_dir,cs_DirsepC);
	if (cp != NULL)
	{
		*cp = '\0';
		CS_altdr (alt_dir);
	}
#endif

	/* Analyze the arguments and extract all options. */

	verbose = FALSE;
	batch = FALSE;
	crypt = FALSE;
	duration = 0L;
	seed = 0;
	tests [0] = '\0';
	alt_dir [0] = '\0';
	test_file [0] = '\0';
	cs_DirP = CS_stcpy (cs_Dir,"C:\\Program Files\\MentorSoftwareCO\\CS_MAP\\Dictnary\\");

	for (ii = 1;ii < argc;ii++)
	{
		/* Here once for each argument. */

		cp = argv [ii];
		if (*cp == cs_OptchrC)
		{
			cp += 1;
			switch (*cp) {

			case 'b':
			case 'B':
				batch = TRUE;
				break;

			case 'c':
			case 'C':
				crypt = TRUE;
				break;

			case 'd':
			case 'D':
				if (alt_dir [0] != '\0')
				{
					printf ("Multiple alternate directory options.\n");
					usage (batch);
				}
				cp += 1;
				if (*cp == '\0')
				{
					CS_stcpy (alt_dir,".");
				}
				else
				{
					CS_stncp (alt_dir,cp,sizeof (alt_dir));
				}
				break;

			case 'p':
			case 'P':

				if (duration != 0)
				{
					printf ("Multiple duration arguments.\n");
					usage (batch);
				}
				cp += 1;
				duration = atol (cp);
				break;

			case 'r':
			case 'R':
				cp += 1;
				seed = atoi (cp) & 0x3FFF;
				break;

			case 's':
			case 'S':
				/* Force CS_bswap to think that it is running on a big
				   endian machine. */

				cs_BswapU.cccc [0] = 0x03;
				cs_BswapU.cccc [1] = 0x02;
				cs_BswapU.cccc [2] = 0x01;
				cs_BswapU.cccc [3] = 0x00;
				break;

			case 't':
			case 'T':
				if (tests [0] != '\0')
				{
					printf ("Multiple test specifications.\n");
					usage (batch);
				}
				cp += 1;
				CS_stncp (tests,cp,sizeof (tests));
				break;

			case 'v':
			case 'V':
				verbose = TRUE;
				break;

			default:
				printf ("Unknown option letter - %c\n",*cp);
				usage (batch);
				break;
			}
		}
		else
		{
			/* It must be the file name. */

			if (test_file [0] != '\0')
			{
				printf ("Too many positional arguments.\n");
				usage (batch);
			}
			CS_stncp (test_file,cp,sizeof (test_file));
		}
	}

	/* Set up the defaults. */

	if (test_file [0] == '\0')
	{
		CS_stcpy (test_file,"TEST.DAT");
	}
	if (alt_dir [0] != '\0')
	{
		st = CS_altdr (alt_dir);
		if (st != 0)
		{
			printf ("CS_altdr did not succeed.  Either CS_altdr is broke, or\n");
			printf ("the path %s is not a valid data directory path.\n",alt_dir);
			usage (batch);
		}
	}
	if (tests [0] == '\0')
	{
		CS_stcpy (tests,"123456789ABCDEFGHIJIHGFEDCBA987654321");
	}
	if (duration <= 0L)
	{
		duration = 30L;
	}
	if (seed == 0)
	{
		seed = (unsigned)CS_time ((cs_Time_ *)0) & 0x3FFF;
	}
	*cs_DirP = '\0';
	printf ("Using data files in the %s directory.\n",cs_Dir);
	printf ("Random number seed = %d.\n",seed);
	srand (seed);
	cs_InitialRandomValue = rand ();

	/* Force test values to upper case. */
	for (cp = tests;*cp != '\0';cp += 1)
	{
		*cp = toupper (*cp);
	}

	/* Open a file with and save the file descriptor.
	   This is used to see if any of the modules in
	   CS_MAP leave a file descriptor open.  This is
	   admittedly a poor test, but it has found some
	   bugs, so we leave it in. */
	initial_fd = -1;
	csStrm = CS_csopn (_STRM_BINRD);
	if (csStrm != 0)
	{	
		initial_fd = _fileno (csStrm);
		CS_csDictCls (csStrm);
	}

	/* If the test sequence includes any of the tests which
	   use the test file, we make sure it exists before
	   plunging into the entire thing. */

	cp = strchr (tests,'4');
	if (cp == NULL) cp = strchr (tests,'A');
	if (cp == NULL) cp = strchr (tests,'a');
	if (cp != NULL)
	{
		chk_fs = fopen (test_file,_STRM_TXTRD);
		if (chk_fs != NULL)
		{
			fclose (chk_fs);
		}
		else
		{
			printf ("Can't open the test data file %s.\n",test_file);
			return (1);
		}
	}

	/* We connect to this and leave active throughout the test, as the
	   question has been raised as to if the heap memory arrays used by
	   this 'object' are being corrupted.  Thus, we leave this active
	   while all other tests are run, and we then check their integrity
	   before final exit. */
	CSrgf93Init ();

	/* If the heap check feature is activated, we walk the
	   current heap and accumulate the amount of heap memory
	   currently in use.  This is used later on to verify
	   that all heap memory used in any test has been
	   successfully returned.  This is conditionally compiled
	   as not all compilers support heap walking, nor is it
	   supported in a standard manner.
	   
	   This test usually fails for the first test.  I believe
	   this is due to the fact that whatever run time library is
	   in use malloc's some memory on the first call to some
	   function.  I feel confident about this as the failure
	   always happens with the first test, no matter which one
	   is chosen.  The specific test which fails always passes
	   on subsequent tries, and always passes if it is not the
	   first test.  So, don't get upset if this test fails
	   on the first test.  */

#ifdef __HEAP__

{	/* start a block so we can declare some automatics */

	int hi_st;
	_HEAPINFO hi;

	hi._pentry = NULL;
	mem_used = 0;
	while (TRUE)
	{
		hi_st = heapwalk (&hi);
		if (hi_st != _HEAPOK) break;
		if (hi._useflag == _USEDENTRY)
		{
			mem_used += hi._size;
		}
	}				 
	if (hi_st != _HEAPEND && hi_st != _HEAPEMPTY)
	{
		printf ("Initial heap is corrupt!!!\n");
		return (1);
	}
}
#endif

	/* OK, we now cycle through the list of tests we have been
	   given. */

	ok_cnt = 0;
	bad_cnt = 0;
	for (cp = tests;*cp != '\0';cp += 1)
	{
		/* Restart the entire sequence if we encounter a 'Z' */ 
		if (*cp == 'Z')
		{
			printf ("Recyling through test sequence.\n");
			seed = (unsigned)clock () & 0x3FFF;
			printf ("Random number seed = %d.\n",seed);
			srand (seed);
			cp = tests;
		}

		/* Turn on the dictionary protection system prior to each test.
		   We use the standard distribution values. */

		cs_Protect = protectSave;
		cs_Unique = uniqueSave;

		/* Do the current test. */

		switch (*cp) {

		case '1':

			/* Perform test 1.  This test checks the
			   set of functions which manipulate the
			   coordinate system dictionary. */

			test_st = CStest1 (verbose,crypt);
			break;

		case '2':

			/* Perform test 2.  This test checks the
			   set of functions which manipulate the
			   datum dictionary. */

			test_st = CStest2 (verbose,crypt);
			break;

		case '3':

			/* Perform test 3.  This test checks the
			   set of functions which manipulate the
			   datum dictionary. */

			test_st = CStest3 (verbose,crypt);
			break;

		case '4':

			/* Perform test 4.  This test processes all
			   conversions in the provided test file
			   and reports any discrepancies. */

			test_st = CStest4 (verbose,test_file);
			break;

		case '5':

			/* Performs a perfomance test on certain
			   conversions. */

			test_st = CStest5 (verbose,duration);
			break;

		case '6':

			/* Tests the sort and binary search functions
			   by reversing the order of the Coordinate
			   System Dictionary file. */

			test_st = CStest6 (verbose,crypt);
			break;

		case '7':

			/* Tests the group list function and actual
			   group data in the Coordinate System
			   Dictionary file. */

			test_st = CStest7 (verbose,crypt);
			break;

		case '8':

			/* Assures that every coordinate system
			   definition is exercised. */

			test_st = CStest8 (verbose,crypt);
			break;

		case '9':

			/* Excercises the auxilliary latitude
			   series functions, assuring correct
			   results and thath the inverse always
			   matches the forward. */

			test_st = CStest9 (verbose);
			break;

		case 'A':
		case 'a':

			/* Perform test A. Same as test 4 but uses
			   the single function interface. */

			test_st = CStestA (verbose,test_file);
			break;

		case 'B':
		case 'b':

			/* Perform test B. Checks grid scale and
			   convergence angle functions. */

			test_st = CStestB (verbose,duration);
			break;

		case 'C':
		case 'c':

			/* Perform test C. Tries to produce a
			   floating point exception error. */

			test_st = CStestC (verbose,duration);
			break;

		case 'D':
		case 'd':

			/* Perform test D. Test's each coordinate
			   system for reversibility. */

			test_st = CStestD (verbose,duration);
			break;

		case 'E':
		case 'e':

			/* Perform test E. Test's each coordinate
			   system for reversibility over a smaller
			   region, but with a smaller tolerance. */

			test_st = CStestE (verbose,duration);
			break;

		case 'F':
		case 'f':

			/* Perform test F. Exercises the CS_atof and
			   CS_ftoa functions, using one to test the
			   other. */

			test_st = CStestF (verbose,duration);
			break;

		case 'G':
		case 'g':

			/* Perform test G. Creep test on selected
			   projections. */

			test_st = CStestG (verbose,duration);
			break;

		case 'H':
		case 'h':

			/* Perform test H. Test miscellaneous functions. */

			test_st = CStestH (verbose,duration);
			break;

		case 'I':
		case 'i':

			/* Perform test I. Test WKT functions. */

			test_st = CStestI (verbose,duration);
			break;

		case 'J':
		case 'j':

			/* Perform test J. Test EPSG conversions. */

			test_st = CStestJ (verbose,duration);
			break;

		case 'S':
		case 's':

			/* Swaps the byte order of binary data files,
			   then adjusts CS_bswap appropriately.  Not
			   a test in itself, but sets up the system
			   for running all other tests in the swapped
			   environment. */

			test_st = CStestS (verbose);
			if (test_st != 0)
			{
				printf ("Swap operation failed; status of binary files questionable!!!\n");
			}
			break;

		case 'V':
			test_st = 0;
			verbose = ~verbose;
			break;
			 
		default:

			test_st = 1;
			printf ("Test case %c not known.\n",*cp);
			break;
		}

		/* If __HEAP__ is defined, we check the heap after
		   each test to make sure it has not been corrupted.
		   This applies only to certain compilers.  Therefore
		   this test is performed only if the -D__HEAP__
		   argument is used when this function is compiled. */

#ifdef __HEAP__
		{
			int hi_st;
			unsigned long mem_used_now;
			_HEAPINFO hi;

			hi._pentry = NULL;
			mem_used_now = 0;
			while (TRUE)
			{
				hi_st = heapwalk (&hi);
				if (hi_st != _HEAPOK) break;
				if (hi._useflag == _USEDENTRY)
				{
					mem_used_now += hi._size;
				}
			}
			if (hi_st != _HEAPEND && hi_st != _HEAPEMPTY)
			{
				printf ("Last test has corrupted the heap!!!\n");
			}
			if (mem_used_now != mem_used)
			{
				printf ("Last test failed to free memory it allocated!!!\n");
				mem_used = mem_used_now;
			}
		}
#endif

		if (test_st != 0)
		{
			if (*cp == 'S')
			{
				printf ("File swap failed!!!\n");
			}
			else
			{
				bad_cnt += 1;
				printf ("Test %c failed!!!\n",*cp);
			}
		}
		else if (*cp != 'S' && *cp != 'V')
		{
			ok_cnt += 1;
			if (verbose)
			{
				printf ("Test %c succeeded!!!\n",*cp);
			}
		}

		/* On to the next test. */

	}

	/* Delete any datum shift stuff which may be around.  Note that
	   CS_dtcls releases resources, but doesn't actually delete
	   the objects. */

	CS_recvr ();

	/* If CSrgf93Chk returns zero, the memory in the memory arrays
	   has not changed since the start of this program. */
	if (CSrgf93Chk ())
	{
		CS_errmsg (alt_dir,sizeof (alt_dir));
		printf ("Memory integrity violation: %s\n",alt_dir);
	}
	CSrgf93Cls ();

	CSdeleteNad27ToNad83 (csNad27ToNad83);
	CSdeleteNad83ToHarn (csNad83ToHarn);
	CSdeleteAgd66ToGda94 (csAgd66ToGda94);
	CSdeleteAgd84ToGda94 (csAgd84ToGda94);
	CSdeleteNzgd49ToNzgd2K (csNzgd49ToNzgd2K);
	CSdeleteAts77ToCsrs (csAts77ToCsrs);
	CSdeleteNad83ToCsrs (csNad83ToCsrs);
	CSdeleteVertconUS (csVertconUS);
	CSdeleteOsgm91 (cs_Osgm91Ptr);
	CSdeleteTokyoToJgd2k (csTokyoToJgd2k);
	CSdeleteRgf93ToNtf (csRgf93ToNtf);
	CSdeleteOstn97 (cs_Ostn97Ptr);
	CSdeleteOstn02 (cs_Ostn02Ptr);

	/* See if a file open doesn't produce the same file
	   descriptor that we got the first time we did this. */

	if (initial_fd >= 0)
	{
		csStrm = CS_csopn (_STRM_BINRD);
		final_fd = _fileno (csStrm);
		CS_csDictCls (csStrm);
		if (final_fd != initial_fd)
		{
			printf ("There's a file descriptor leak somewhere.\n");
		}
	}

	printf ("%d tests completed successfully.\n",ok_cnt);
	if (bad_cnt != 0)
	{
		printf ("%d tests failed!!!!\n",bad_cnt);
	}

	if (!batch)
	{
		printf ("\rPress any key to continue: ");
		getchar ();
		printf ("\n");
	}
	return (0);
}

int CStest1 (int verbose,int crypt)
{
	extern short cs_Protect;
	extern char cs_Unique;

	short protectSave;
	char uniqueSave;

	int st;
	int cnt;
	int my_crypt;

	csFILE *elStrm;
	struct tst_lst_ *tp;

	char last_name [48];

	__ALIGNMENT__1			/* Required by some Sun compilers. */
	struct cs_Eldef_ el_def;

	protectSave = cs_Protect;
	uniqueSave = cs_Unique;
	printf ("Testing Ellipsoid Dictionary functions.\n");

	/* Test the Ellipsoid Dictionary manipulation functions
	   by fetching, updating, deleteing, and updating again
	   all the ellipsoids in the test list structure for
	   ellipsoids.  These were all chosen as ellipsoids used
	   in the coordinate calculation test.  Thus, the validity
	   of the results can be tested by using test 4 after the
	   completion of this test. */

	tp = el_tst;
	while (tp->name [0] != '\0')
	{
		cs_Protect = protectSave;
		cs_Unique = uniqueSave;

		/* First we fetch the ellipsoid definition. */
		if (verbose)
		{
			printf ("Fetching %s ellipsoid definition.",tp->name);
		}
		tp->el_ptr = CS_eldef (tp->name);
		if (tp->el_ptr == NULL)
		{
			(void)printf ("CS_eldef failed on %s. [%d:%d]\n",tp->name,cs_Error,cs_Errno);
			return (1);
		}
		if (verbose) printf (" OK.\n");

		/* There are two tests.  One with protection on, one with it  off.
		   If this is not a TEST ellipsoid,  then we can only do an update
		   with ptotection off.  If it is a TEST ellipsoid, we can test
		   with protection on. */
		if (CS_stricmp (tp->el_ptr->group,"teSt"))
		{
			/* Now we put it back in, with protection off. */
			if (verbose)
			{
				printf ("Updating %s ellipsoid definition, protection off.",tp->name);
			}
			cs_Protect = -1;
			st = CS_elupd (tp->el_ptr,crypt);
			if (st != 1)
			{
				(void)printf ("\nCS_elupd failed on %s at line %d. [%d:%d]\n",tp->name,(__LINE__-3),cs_Error,cs_Errno);
				return (1);
			}
			if (verbose) printf (" OK.\n");

			/* Now we delete it. */
			if (verbose)
			{
				printf ("Deleting %s ellipsoid definition, protection off.",tp->name);
			}
			st = CS_eldel (tp->el_ptr);
			if (st != 0)
			{
				(void)printf ("\nCS_eldel failed on %s at line %d. [%d:%d]\n",tp->name,(__LINE__-3),cs_Error,cs_Errno);
				return (1);
			}
			if (verbose) printf (" OK.\n");
		}
		else
		{
			/* Now we put it back in, with protection on. */
			if (verbose)
			{
				printf ("Updating %s ellipsoid definition, protection on.",tp->name);
			}
			cs_Protect = 10000;						/* Sets protect date 27 years into the future. */
			st = CS_elupd (tp->el_ptr,crypt);
			if (st != 1)
			{
				(void)printf ("\nCS_elupd failed on %s at line %d. [%d:%d]\n",tp->name,(__LINE__-3),cs_Error,cs_Errno);
				return (1);
			}
			if (verbose) printf (" OK.\n");

			/* Now we delete it. */
			if (verbose)
			{
				printf ("Deleting %s ellipsoid definition, protection on.",tp->name);
			}
			st = CS_eldel (tp->el_ptr);
			if (st != 0)
			{
				(void)printf ("\nCS_eldel failed on %s at line %d. [%d:%d]\n",tp->name,(__LINE__-3),cs_Error,cs_Errno);
				return (1);
			}
			if (verbose) printf (" OK.\n");
		}
		tp++;
	}

	/* Now we put all the deleted ellipsoid definitions back in.
	   This is a test of the add case since they shouldn't be
	   there any more. */
	tp = el_tst;
	while (tp->name [0] != '\0')
	{
		cs_Protect = protectSave;
		cs_Unique = uniqueSave;
		if (verbose)
		{
			printf ("Putting %s ellipsoid definition back in.",tp->name);
		}

		/* I can't really do a prtected test without changeing the name of the
		   definition.  So, we're stuck with testing with protection off. */
		cs_Unique = '\0';
		st = CS_elupd (tp->el_ptr,crypt);
		if (st != 0)
		{
			(void)printf ("\nCS_elupd failed on %s at line %d. [%d:%d]\n",tp->name,(__LINE__-3),cs_Error,cs_Errno);
			return (st);
		}
		if (verbose) printf (" OK.\n");
		CS_free (tp->el_ptr);
		tp++;
	}

	/* Finally, we cruise through the ellipsoid file and verify
	   that all are in sorted order and that there are no
	   duplicates.  */
	if (verbose)
	{
		printf ("Checking order of Ellipsoid Dictionary.\n");
	}
	cnt = 0;
	elStrm = CS_elopn (_STRM_BINRD);
	st = CS_elrd (elStrm,&el_def,&my_crypt);
	CS_stncp (last_name,el_def.key_nm,sizeof (last_name));
	while (CS_elrd (elStrm,&el_def,&my_crypt))
	{
		cnt += 1;
		if (verbose && (cnt % 3) == 0) putchar ('.');
		st = CS_stricmp (last_name,el_def.key_nm);
		if (st > 0)
		{
			printf ("\nEllipsoid Dictionary no longer sorted!!!\n");
			CS_fclose (elStrm);
			return (1);
		}
		else if (st == 0)
		{
			printf ("\nDuplicate entries in Ellipsoid Dictionary!!!\n");
			CS_fclose (elStrm);
			return (1);
		}
	}
	CS_elDictCls (elStrm);
	if (verbose) printf (" OK.\n");
	return (0);
}

int CStest2 (int verbose,int crypt)
{
	extern short cs_Protect;
	extern char cs_Unique;

	short protectSave;
	char uniqueSave;

	int st;
	int cnt;
	int my_crypt;

	csFILE *dtStrm;
	struct tst_lst_ *tp;

	char last_name [48];

	__ALIGNMENT__1			/* Required by some Sun compilers. */
	struct cs_Dtdef_ dt_def;

	protectSave = cs_Protect;
	uniqueSave = cs_Unique;
	printf ("Testing Datum Dictionary functions.\n");

	/* We do the same thing now with datum definitions. */

	tp = dt_tst;
	while (tp->name [0] != '\0')
	{
		cs_Protect = protectSave;
		cs_Unique = uniqueSave;
		if (verbose)
		{
			printf ("Fetching %s datum definition.",tp->name);
		}
		tp->dt_ptr = CS_dtdef (tp->name);
		if (tp->dt_ptr == NULL)
		{
			(void)printf ("\nCS_dtdef failed on %s. [%d:%d]\n",
							tp->name,
							cs_Error,
							cs_Errno);
			return (1);
		}
		if (verbose) printf (" OK.\n");

		if (CS_stricmp (tp->dt_ptr->group,"tESt"))
		{
			if (verbose)
			{
				printf ("Updating %s datum definition, protection off.",tp->name);
			}
			cs_Protect = -1;
			st = CS_dtupd (tp->dt_ptr,crypt);
			if (st != 1)
			{
				(void)printf ("\nCS_dtupd failed on %s at line %d. [%d:%d]\n",tp->name,(__LINE__-3),cs_Error,cs_Errno);
				return (1);
			}
			if (verbose) printf (" OK.\n");
			if (verbose)
			{
				printf ("Deleting %s datum definition.",tp->name);
			}
			st = CS_dtdel (tp->dt_ptr);
			if (st != 0)
			{
				(void)printf ("CS_dtdel failed on %s at line %d. [%d:%d]\n",tp->name,(__LINE__-3),cs_Error,cs_Errno);
				return (1);
			}
			if (verbose) printf (" OK.\n");
		}
		else
		{
			if (verbose)
			{
				printf ("Updating %s datum definition, protection on.",tp->name);
			}
			cs_Protect = 10000;
			st = CS_dtupd (tp->dt_ptr,crypt);
			if (st != 1)
			{
				(void)printf ("\nCS_dtupd failed on %s at line %d. [%d:%d]\n",tp->name,(__LINE__-3),cs_Error,cs_Errno);
				return (1);
			}
			if (verbose) printf (" OK.\n");
			if (verbose)
			{
				printf ("Deleting %s datum definition.",tp->name);
			}
			st = CS_dtdel (tp->dt_ptr);
			if (st != 0)
			{
				(void)printf ("CS_dtdel failed on %s at line %d. [%d:%d]\n",tp->name,(__LINE__-3),cs_Error,cs_Errno);
				return (1);
			}
			if (verbose) printf (" OK.\n");
		}
		tp++;
	}
	tp = dt_tst;
	while (tp->name [0] != '\0')
	{
		cs_Protect = protectSave;
		cs_Unique = uniqueSave;
		if (verbose)
		{
			printf ("Putting %s datum definition back in.",tp->name);
		}
		cs_Unique = '\0';
		st = CS_dtupd (tp->dt_ptr,crypt);
		if (st != 0)
		{
			(void)printf ("\nCS_dtupd (2) failed on %s. [%d:%d]\n",
							tp->name,
							cs_Error,
							cs_Errno);
			return (1);
		}
		if (verbose) printf (" OK.\n");
		CS_free (tp->dt_ptr);
		tp++;
	}
	if (verbose)
	{
		printf ("Checking the order of the Datum Dictionary.\n");
	}
	cnt = 0;
	dtStrm = CS_dtopn (_STRM_BINRD);
	st = CS_dtrd (dtStrm,&dt_def,&my_crypt);
	CS_stncp (last_name,dt_def.key_nm,sizeof (last_name));
	while (CS_dtrd (dtStrm,&dt_def,&my_crypt))
	{
		cnt += 1;
		if (verbose && (cnt % 4) == 0) putchar ('.');
		st = CS_stricmp (last_name,dt_def.key_nm);
		if (st > 0)
		{
			printf ("\nDatum Dictionary no longer sorted!!!\n");
			CS_fclose (dtStrm);
			return (1);
		}
		else if (st == 0)
		{
			printf ("\nDuplicate entries in Datum Dictionary!!!\n");
			CS_fclose (dtStrm);
			return (1);
		}
	}
	if (verbose) printf (" OK.\n");
	CS_dtDictCls (dtStrm);
	return (0);
}

int CStest3 (int verbose,int crypt)
{
	extern short cs_Protect;
	extern char cs_Unique;

	short protectSave;
	char uniqueSave;

	int st;
	int cnt;
	int my_crypt;

	csFILE *csStrm;
	struct tst_lst_ *tp;

	char last_name [48];

	__ALIGNMENT__1			/* Required by some Sun compilers. */
	struct cs_Csdef_ cs_def;

	/* Preserve the original values of the dictionary protection system.
	   We will need to turn protection off and on to do this test
	   properly.  Upon entry, the protection system should be on. */
	protectSave = cs_Protect;
	uniqueSave = cs_Unique;

	printf ("Testing Coordinate System Dictionary functions.\n");

	tp = cs_tst;
	while (tp->name [0] != '\0')
	{
		/* Always restore protection to the distribution values. */
		cs_Protect = protectSave;
		cs_Unique = uniqueSave;
		if (verbose)
		{
			printf ("Fetching %s from the Coordinate System Dictionary.",tp->name);
		}

		tp->cs_ptr = CS_csdef (tp->name);
		if (tp->cs_ptr == NULL)
		{
			(void)printf ("\nCS_csdef failed on %s. [%d:%d]\n",
							tp->name,
							cs_Error,
							cs_Errno);
			return (1);
		}
		if (verbose) printf (" OK.\n");

		/* If this is not a TEST (i.e. group) coordinate system, we can't really test
		   it with protection on as the compiler will have marked it as a
		   distribution coordinate system.  Therefore, we have two tests,
		   one for the TEST group and one for other groups.  We can do the
		   TEST group with protection on. */
		if (CS_stricmp (tp->cs_ptr->group,"tEst"))
		{
			/* Its not a test definition, we have to test with protection off. */
			if (verbose)
			{
				printf ("Updating %s in the Coordinate System Dictionary with protection turned off.\n",tp->name);
			}

			cs_Protect = -1;
			cs_Unique = '\0';
			st = CS_csupd (tp->cs_ptr,crypt);
			/* Return value should be one since this should be an update. */
			if (st != 1)
			{
				(void)printf ("\nUnprotected CS_csupd failed failed on %s at line %d. [%d:%d]\n",
								tp->name,
								(__LINE__-6),
								cs_Error,
								cs_Errno);
				return (1);
			}
			st = CS_csdel (tp->cs_ptr);
			if (st != 0)
			{
				(void)printf ("\nUnprotected CS_csdel failed on %s at line %d. [%d:%d]\n",
								tp->name,
								(__LINE__-6),
								cs_Error,
								cs_Errno);
				return (1);
			}
		}
		else
		{
			if (verbose)
			{
				printf ("Updating %s in the Coordinate System Dictionary with protection on.",tp->name);
			}

			/* The TEST definitions are manufactured with a creation date of (aprrox) Jan 1, 2002.
			   We set cs_Protect to a large number to essentially enable this definition to
			   be updated in the normal fashion.  That's what we want to test here.  We
			   actually test protection system operation elsewhere. */
			cs_Protect = 10000;
			st = CS_csupd (tp->cs_ptr,crypt);	/* This should succeed. */
			if (st != 1)
			{
				(void)printf ("\nProtected CS_csupd failed on %s at line %d. [%d:%d]\n",
								tp->name,
								(__LINE__-6),
								cs_Error,
								cs_Errno);
				return (1);
			}
			if (verbose) printf (" OK.\n");
			if (verbose)
			{
				printf ("Deleting %s from the Coordinate System Dictionary (protected).",tp->name);
			}

			/* Test delete, and remove the entry with the bogus protect value in
			   same operation.  This delete should succeed. */
			st = CS_csdel (tp->cs_ptr);
			if (st != 0)
			{
				(void)printf ("\nProtected CS_csdel failed on %s at line %d. [%d:%d]\n",
								tp->name,
								(__LINE__-6),
								cs_Error,
								cs_Errno);
				return (1);
			}
			if (verbose) printf (" OK.\n");
		}
		tp++;
	}

	/* We go through the list again, adding each definition back into the deictionary.
	   Since each was deleted, they should all succeed.  However, we have to turn unique
	   off since these defintiions will have their distribution names. */
	tp = cs_tst;
	while (tp->name [0] != '\0')
	{
		cs_Protect = protectSave;
		cs_Unique = uniqueSave;
		if (verbose)
		{
			printf ("Putting %s back in the Coordinate System Dictionary.",tp->name);
		}
		cs_Unique = '\0';					/* This turns name protection off. */
		st = CS_csupd (tp->cs_ptr,crypt);	/* This should succeed. */
		if (st != 0)
		{
			(void)printf ("\nCS_csupd failed on %s at line %d. [%d:%d]\n",
								tp->name,
								(__LINE__-6),
								cs_Error,
								cs_Errno);
			return (1);
		}
		if (verbose) printf (" OK.\n");
		CS_free (tp->cs_ptr);
		tp++;
	}
	if (verbose)
	{
		printf ("Checking the sorted order of the Coordinate System Dictionary.\n");
	}

	/* Verify that we haven't screwed up the dictionary. */
	cnt = 0;
	csStrm = CS_csopn (_STRM_BINRD);
	st = CS_csrd (csStrm,&cs_def,&my_crypt);
	CS_stncp (last_name,cs_def.key_nm,sizeof (last_name));
	while (CS_csrd (csStrm,&cs_def,&my_crypt))
	{
		cnt += 1;
		if (verbose && (cnt % 14) == 0) putchar ('.');
		st = CS_stricmp (last_name,cs_def.key_nm);
		if (st > 0)
		{
			printf ("\nCoordinate System Dictionary no longer sorted!!!\n");
			CS_fclose (csStrm);
			return (1);
		}
		else if (st == 0)
		{
			printf ("\nDuplicate entries in Coordinate System Dictionary!!!\n");
			CS_fclose (csStrm);
			return (1);
		}
	}
	if (verbose) printf (" OK.\n");
	CS_csDictCls (csStrm);
	return (0);
}

int CStest4 (int verbose,char *test_file)

{
	extern struct csNad27ToNad83_* csNad27ToNad83;
	extern struct csNad83ToHarn_* csNad83ToHarn;
	extern struct csAgd66ToGda94_* csAgd66ToGda94;
	extern struct csAgd84ToGda94_* csAgd84ToGda94;
	extern struct csNzgd49ToNzgd2K_* csNzgd49ToNzgd2K;

	int stI;
	int stD;
	int stF;
	int line_nbr;
	int fail_cnt;

	long frmt_SX;
	long frmt_SY;
	long frmt_DX;
	long frmt_DY;

	char *cp;
	char *src_nm;
	char *src_x;
	char *src_y;
	char *dest_nm;
	char *dest_x;
	char *dest_y;
	char *tol_x;
	char *tol_y;
	FILE *fs_tst;
	struct cs_Csprm_ *src_cs;
	struct cs_Csprm_ *dest_cs;
	struct cs_Dtcprm_ *dtc_prm;

	double src_cc [3];
	double dest_cc [3];
	double rslt [3];
	double tol [3];
	double del [3];

	char last_src [32];
	char last_dest [32];
	char l_buf [256];
	char bufrX [32];
	char bufrY [32];
	char msgBufr [256];

	printf ("Checking all test cases in %s.\n",test_file);

	/* In this test, we read an ordinary text file and parse out
	   eight items.  The items are expected to be separated by
	   commas.  The eight items, in expected order, are:

	   1) Source coordinate system.
	   2) Source X coordinate.
	   3) Source Y coordinate.
	   4) Destination coordinate system.
	   5) Destination X coordinate.
	   6) Destination Y coordinate.
	   7) X Tolerance of the test.
	   8) Y Tolerance of the test.

	   All numbers are in simple decimal form.

	   Then, for each line, we convert the coordinate,
	   check the converted result against the supplied
	   value (using the tolerance figure). */

	fs_tst = fopen (test_file,_STRM_TXTRD);
	if (fs_tst == NULL)
	{
		(void)printf ("Couldn't open %s\n",test_file);
		return (1);
	}

	/* Initialize the loop so we don't call CS_csloc and
	   CS_dtcsu unless the coordinate systems have changed.
	   This just keeps this test from taking a long time. */

	last_src [0] = '\0';
	last_dest [0] = '\0';
	src_cs = NULL;
	dest_cs = NULL;
	dtc_prm = NULL;
	line_nbr = 0;

	/* OK, now we can loop and perform the coordinate calculation
	   tests. */

	fail_cnt = 0;
	while (fgets (l_buf,sizeof (l_buf),fs_tst) != NULL)
	{
		line_nbr += 1;

		/* Trim any leading and trailing white space. */

		CS_trim (l_buf);

		/* Here once for each line.  Skip a comment
		   line. */

		if (l_buf [0] == '#') continue;

		/* Skip any empty lines.  CS_trim considers the
		   trailing newline character to be white space. */

		if (l_buf [0] == '\0') continue;

		/* Parse the input.  This is a pretty hoeky
		   parser, but this is a test program.  We simply
		   locate all commas and replace same with a
		   null character, then save the pointer to the
		   next character. */

		cp = l_buf;
		src_nm = cp;
		cp = strchr (cp,',');
		if (cp == NULL) goto frmterr;
		*cp++ = '\0';
		src_x = cp;
		cp = strchr (cp,',');
		if (cp == NULL) goto frmterr;
		*cp++ = '\0';
		src_y = cp;
		cp = strchr (cp,',');
		if (cp == NULL) goto frmterr;
		*cp++ = '\0';
		dest_nm = cp;
		cp = strchr (cp,',');
		if (cp == NULL) goto frmterr;
		*cp++ = '\0';
		dest_x = cp;
		cp = strchr (cp,',');
		if (cp == NULL) goto frmterr;
		*cp++ = '\0';
		dest_y = cp;
		cp = strchr (cp,',');
		if (cp == NULL) goto frmterr;
		*cp++ = '\0';
		tol_x = cp;
		cp = strchr (cp,',');
		if (cp == NULL) goto frmterr;
		*cp++ = '\0';
		tol_y = cp;

		/* Get a coordinate system parameter structure for the
		   source system.  If the name is the same as the
		   last time, skip this to speed things up a little
		   bit. */

		if (CS_stricmp (src_nm,last_src))
		{
			if (src_cs != NULL)
			{
				CS_free (src_cs);
				src_cs = NULL;
			}
			src_cs = CS_csloc (src_nm);
			if (src_cs == NULL)
			{
				CS_errmsg (msgBufr,sizeof (msgBufr));
				printf ("%s\n",msgBufr);
				(void)printf ("CS_csloc failed on %s.\n",src_nm);
				fclose (fs_tst);
				return (1);
			}
			(void)strcpy (last_src,src_nm);

			/* Kludge to handle Alaska stuff, longitude = -189. */
			if (!CS_stricmp (src_nm,"LL27") || !CS_stricmp (src_nm,"LL83"))
			{
				src_cs->proj_prms.unity.usr_min = -270.0;
				src_cs->proj_prms.unity.usr_max = 270.0;
				src_cs->proj_prms.unity.usr_rng = 540.0;
			}

			/* Since the source coordinate system has changed,
			   we discard any datum conversion which was set
			   up based on it. */

			if (dtc_prm != NULL)
			{
				CS_dtcls (dtc_prm);
				dtc_prm = NULL;
			}
		}

		/* Similarly with the destination coordinate system. */

		if (CS_stricmp (dest_nm,last_dest))
		{
			if (dest_cs != NULL)
			{
				CS_free (dest_cs);
				dest_cs = NULL;
			}
			dest_cs = CS_csloc (dest_nm);
			if (dest_cs == NULL)
			{
				CS_errmsg (msgBufr,sizeof (msgBufr));
				printf ("%s\n",msgBufr);
				(void)printf ("CS_csloc failed on %s.\n",dest_nm);
				fclose (fs_tst);
				return (1);
			}

			/* Kludge to handle Alaska stuff, longitude = -189. */
			if (!CS_stricmp (dest_nm,"LL27") || !CS_stricmp (dest_nm,"LL83"))
			{
				dest_cs->proj_prms.unity.usr_min = -270.0;
				dest_cs->proj_prms.unity.usr_max = 270.0;
				dest_cs->proj_prms.unity.usr_rng = 540.0;
			}

			(void)strcpy (last_dest,dest_nm);
			if (dtc_prm != NULL)
			{
				CS_dtcls (dtc_prm);
				dtc_prm = NULL;
			}
		}

		/* Set up the datum conversion.  Again, we skip this
		   if the coordinate system names are the same.  Only
		   if both were the same (very unlikely) do we
		   reuse the datum setup. */

		if (dtc_prm == NULL)
		{
			dtc_prm = CS_dtcsu (src_cs,dest_cs,cs_DTCFLG_DAT_F,cs_DTCFLG_BLK_W);
			if (dtc_prm == NULL)
			{
				CS_errmsg (msgBufr,sizeof (msgBufr));
				printf ("%s\n",msgBufr);
				(void)printf ("CS_dtcsu failed on %s to %s.\n",src_nm,dest_nm);
				fclose (fs_tst);
				return (1);
			}
		}

		/* OK, now we can perform the conversion. */

		frmt_SX = CS_atof (&src_cc [0],src_x);
		frmt_SY = CS_atof (&src_cc [1],src_y);
		src_cc [2] = 0.0;
		frmt_DX = CS_atof (&dest_cc [0],dest_x);
		frmt_DY = CS_atof (&dest_cc [1],dest_y);
		dest_cc [2] = 0.0;
		CS_atof (&tol [0],tol_x);
		CS_atof (&tol [1],tol_y);

		stI = CS_cs2ll (src_cs,rslt,src_cc);
		stD = CS_dtcvt (dtc_prm,rslt,rslt);
		if (stD != 0)
		{
			CS_errmsg (msgBufr,sizeof (msgBufr));
			printf ("%s\n",msgBufr);
			if (stD < 0) (void)printf ("CS_dtcvt failed on %s to %s.\n",src_nm,dest_nm);
		}
		stF = CS_ll2cs (dest_cs,rslt,rslt);

		/* Evaluate the calculated result. */

		del [0] = fabs (rslt [0] - dest_cc [0]);
		del [1] = fabs (rslt [1] - dest_cc [1]);
		if (del [0] > tol [0] || del [1] > tol [1])
		{
			(void)printf ("Verification failure (line %d):\n",line_nbr);
			(void)printf ("\t%-23.23s %-16.16s %-16.16s\n",
							src_nm,src_x,src_y);
			(void)printf ("\t%-23.23s %-16.16s %-16.16s\n",
							dest_nm,dest_x,dest_y);
			CS_ftoa (bufrX,17,rslt [0],frmt_DX);
			CS_ftoa (bufrY,17,rslt [1],frmt_DY);
			(void)printf ("\t                   CALC %-16.16s %-16.16s\n",
								bufrX,bufrY);
			fail_cnt += 1;
		}
		else if (verbose)
		{
			(void)printf ("[%9.9s]%12.12s %12.12s ==> %12f %12f [%-9.9s]\n",
						src_nm,
						src_x,
						src_y,
						rslt [0],
						rslt [1],
						dest_nm);
		}
	}
	fclose (fs_tst);

	/* Clean up in preparation for exit. */

	if (src_cs != NULL) CS_free (src_cs);
	if (dest_cs != NULL) CS_free (dest_cs);
	if (dtc_prm != NULL) CS_dtcls (dtc_prm);

	/* Note, CS_dtcls does not normally free up the
	   NADCON file directory as it does not use up
	   much memory, and is rather expensive (time wise)
	   to build.  However, since we are checking
	   heap allocations in this program, we must
	   free it up ourselves. */

	CSdeleteNad27ToNad83 (csNad27ToNad83);
	csNad27ToNad83 = NULL;
	CSdeleteNad83ToHarn (csNad83ToHarn);
	csNad83ToHarn = NULL;
	CSdeleteAgd66ToGda94 (csAgd66ToGda94);
	csAgd66ToGda94 = NULL;
	CSdeleteAgd84ToGda94 (csAgd84ToGda94);
	csAgd84ToGda94 = NULL;
	CSdeleteNzgd49ToNzgd2K (csNzgd49ToNzgd2K);
	csNzgd49ToNzgd2K = NULL;

	return (fail_cnt);

frmterr:
	printf ("Test data file format error on line %d.\n",line_nbr);
	fclose (fs_tst);
	if (src_cs != NULL) CS_free (src_cs);
	if (dest_cs != NULL) CS_free (dest_cs);
	if (dtc_prm != NULL) CS_dtcls (dtc_prm);
	return (1);
}

#define cs_TEST_COORD_COUNT 10
static double csTestcoords [10][3] =
{
	{ 456661.0, 4316548.0, 0.0 },
	{ 462938.0, 4314975.0, 0.0 },
	{ 512384.0, 4419456.0, 0.0 },
	{ 417845.0, 4391564.0, 0.0 },
	{ 489263.0, 4346712.0, 0.0 },
	{ 612374.0, 4394561.0, 0.0 },
	{ 472384.0, 4314904.0, 0.0 },
	{ 498374.0, 4334978.0, 0.0 },
	{ 452894.0, 4401245.0, 0.0 },
	{ 413649.0, 4294561.0, 0.0 }
};

int CStest5 (int verbose,long duration)
{
	extern struct csNad27ToNad83_* csNad27ToNad83;

	int ii;

	long cvt_cnt;
	long rate;

	clock_t done;
	clock_t start;

	struct cs_Csprm_ *utm13;
	struct cs_Csprm_ *co83c;
	struct cs_Dtcprm_ *dtcptr;

	double elapsed;				/* In seconds. */
	double dbls [3];

	/* Here to perform a performance test.  For this
	   we will convert a series of coordinates from
	   UTM-13 to CO83-C */

	utm13 = CS_csloc ("UTM27-13");
	if (utm13 == NULL) return (1);
	co83c = CS_csloc ("CO83-C");
	if (co83c == NULL) return (1);
	dtcptr = CS_dtcsu (utm13,co83c,cs_DTCFLG_DAT_F,cs_DTCFLG_BLK_F);
	if (dtcptr == NULL) return (1);

	duration = duration * 10000;

	printf ("Measuring performance: %ld coordinates; UTM27-13 ==> CO83-C\n",duration);

	cvt_cnt = 0L;
	start = clock ();
	while (cvt_cnt < duration)
	{
		for (ii = 0;ii < 10;ii++)
		{
			CS_cs2ll (utm13,dbls,csTestcoords [ii]);
			CS_dtcvt (dtcptr,dbls,dbls);
			CS_ll2cs (co83c,dbls,dbls);
			cvt_cnt += 1L;
		}
	}
	done = clock ();
	CS_free (utm13);
	CS_free (co83c);
	CS_dtcls (dtcptr);
	CSdeleteNad27ToNad83 (csNad27ToNad83);
	csNad27ToNad83 = NULL;

	/* Report on the performance. */

	elapsed = (double)(done - start) / (double)CLOCKS_PER_SEC;
	if (elapsed > 0.00001)
	{
		rate = (cvt_cnt > 0) ? (long)((double)cvt_cnt / elapsed) : 0;
	}
	else
	{
		rate = 0;
	}
	printf ("Converted %ld coordinates from UTM27-13 to CO83C in %6.2lf seconds.\n",
					cvt_cnt,elapsed);
	printf ("Effective conversion rate = %ld conversions per second.\n",rate);

	return (0);
}

/*
	The following function simply inverts the result of
	CS_cscmp, thereby yeilding a sort in reverse order.
*/
int CStest6cmp (struct cs_Csdef_ *pp,struct cs_Csdef_ *qq)
{
	return (-CS_cscmp (pp,qq));
}

int CStest6 (int verbose,int crypt)
{
	int st;
	int cnt;
	int flag;
	int my_crypt;

	csFILE *csStrm;
	struct tst_lst_ *tp;

	char last_name [48];

	__ALIGNMENT__1			/* Required by some Sun compilers. */
	struct cs_Csdef_ cs_def;

	printf ("Testing sort and binary search functions.\n");

	/* This test sorts the Coordinate System Dictionary, the
	   largest of the three dictionaries, into reverse order.
	   Then does some CS_bins calls.  Then resorts back into
	   normal order.  This is a resaonable good exercise of
	   the sort function which normally sorts files with a
	   single entry out of order. */

	if (verbose)
	{
		printf ("Sorting Coordinate System Dictionary into reverse order.\n");
	}
	csStrm = CS_csopn (_STRM_BINUP);

	/* NOTE: CS_csopn leaves the file positioned after
	   the magic number.  CS_ips always starts sorting
	   at the current file position. */

	CS_ips (csStrm,sizeof (struct cs_Csdef_),-1L,(CMPFUNC_CAST)CStest6cmp);

	/* The dictionary should now be in reverse order.  We
	   check the order now.  CS_ips is supposed to return
	   with the file position where it was when we started. */

	if (verbose)
	{
		printf ("Checking reverse order of Coordinate System Dictionary.\n");
	}
	cnt = 0;
	st = CS_csrd (csStrm,&cs_def,&my_crypt);
	if (st == 0)
	{
		printf ("CS_ips hosed the Coordinate System Dictionary.\n");
		CS_fclose (csStrm);
		return (1);
	}
	CS_stncp (last_name,cs_def.key_nm,sizeof (last_name));
	while (CS_csrd (csStrm,&cs_def,&my_crypt))
	{
		cnt += 1;
		if (verbose && (cnt % 10) == 0) putchar ('.');
		st = CS_stricmp (last_name,cs_def.key_nm);
		if (st < 0)
		{
			printf ("\nSort did not sort entire file correctly!!!\n");
			CS_fclose (csStrm);
			return (1);
		}
		else if (st == 0)
		{
			printf ("\nSort left duplicate entries when sorting entire file!!!\n");
			CS_fclose (csStrm);
			return (1);
		}
	}
	if (verbose) printf (" OK.\n");

	/* If we are still here, the sort worked correctly.
	   Use the cs_tst list as a list of names to binary
	   search on.  It includes the normal first and last;
	   which should now be the last and the first. */

	tp = cs_tst;
	while (tp->name [0] != '\0')
	{
		if (verbose)
		{
			printf ("Searching for %s in reversed CS Dictionary.",tp->name);
		}
		CS_stncp (cs_def.key_nm,tp->name,sizeof (cs_def.key_nm));
		flag = CS_bins (csStrm,(long)sizeof (cs_magic_t),0L,sizeof (cs_def),
				(char *)&cs_def,(CMPFUNC_CAST)CStest6cmp);
		if (flag <= 0)
		{
			printf ("CS_bins failed on file in reverse order!!!\n");
			CS_fclose (csStrm);
			return (1);
		}
		if (verbose) printf (" OK.\n");
		tp += 1;
	}

	/* OK, return the file back to normal sorted order. */

	if (verbose)
	{
		printf ("Sorting Coordinate System Dictionary back to normal order.\n");
	}
	CS_fseek (csStrm,(long)sizeof (cs_magic_t),SEEK_SET);
	CS_ips (csStrm,sizeof (struct cs_Csdef_),-1L,(CMPFUNC_CAST)CS_cscmp);

	/* One more time, check that the order is correct. */

	if (verbose)
	{
		printf ("Checking Coordinate System Dictionary normal sorted order.\n");
	}
	cnt = 0;
	st = CS_csrd (csStrm,&cs_def,&my_crypt);
	if (st == 0)
	{
		printf ("CS_ips hosed the Coordinate System Dictionary.\n");
		CS_fclose (csStrm);
		return (1);
	}
	CS_stncp (last_name,cs_def.key_nm,sizeof (last_name));
	while (CS_csrd (csStrm,&cs_def,&my_crypt))
	{
		cnt += 1;
		if (verbose && (cnt % 10) == 0) putchar ('.');
		st = CS_stricmp (last_name,cs_def.key_nm);
		if (st > 0)
		{
			printf ("Sort did not sort entire file correctly!!!\n");
			CS_fclose (csStrm);
			return (1);
		}
		else if (st == 0)
		{
			printf ("Sort left duplicate entries when sorting entire file!!!\n");
			CS_fclose (csStrm);
			return (1);
		}
	}
	if (verbose) printf (" OK.\n");

	/* OK, if we are still here, we passed the test. */

	CS_csDictCls (csStrm);
	return (0);
}

/*
	Here we test the CS_grups function.
*/

int CStest7 (int verbose,int crypt)
{
	extern struct cs_Grptbl_ cs_CsGrptbl [];

	int cnt;
	int f_cnt;
	int cs_cnt;
	int grp_cnt;
	int err_cnt;
	int my_crypt;

	csFILE *csStrm;
	struct cs_Grptbl_ *tp;
	struct cs_Csgrplst_ *gp;
	struct cs_Csgrplst_ *grp_list;

	__ALIGNMENT__1			/* Required by some Sun compilers. */
	struct cs_Csdef_ cs_def;

	printf ("Testing Coordinate System Group functions.\n");

	/* Count the number of entries in the Coordinate System
	   Dictionary. */

	cs_cnt = 0;
	csStrm = CS_csopn (_STRM_BINRD);
	while (CS_csrd (csStrm,&cs_def,&my_crypt))
	{
		cs_cnt += 1;
	}
	CS_csDictCls (csStrm);

	/* Loop through the group table and fetch a linked list
	   for each group.  Count the number in the group and
	   add to the total in the group. */

	err_cnt = 0;
	grp_cnt = 0;
	for (tp = cs_CsGrptbl;tp->group [0] != '\0';tp += 1)
	{
		f_cnt = CS_csgrp (tp->group,&grp_list);
		cnt = 0;
		for (gp = grp_list;gp != NULL;gp = gp->next)
		{
			cnt += 1;
		}
		CS_csgrpf (grp_list);
		if (cnt != f_cnt)
		{
			printf ("CS_csgrp returned a bogus count/list for group %s\n",tp->group);
			err_cnt += 1;
		}
		if (verbose)
		{
			printf ("%d Coordinate Systems in %s group.\n",cnt,tp->group);
		}
		grp_cnt += cnt;
	}

	/* Grp_cnt should now equal cs_cnt. */

	if (cs_cnt != grp_cnt)
	{
		printf ("Group function failed to return all appropriate coordinate systems.\n");
		err_cnt += 1;
	}
	return (err_cnt);
}

void usage (int batch)
{
	extern char cs_OptchrC;

	printf ("Usage: TEST [%cb] [%cv] [%cp30] [%cddir] [%ct123] [test_file]\n",
		cs_OptchrC,cs_OptchrC,cs_OptchrC,cs_OptchrC,cs_OptchrC);
	printf ("\t       %cb  supresses acknowledgement before exit\n",cs_OptchrC);
	printf ("\t       %cd  specifies Dictionary directory\n",cs_OptchrC);
	printf ("\t       %cp  test duration parameter\n",cs_OptchrC);
	printf ("\t       %cr  specify random number seed value\n",cs_OptchrC);
	printf ("\t       %cs  indicates binary data files are swapped\n",cs_OptchrC);
	printf ("\t       %ct  specifies tests, and sequence\n",cs_OptchrC);
	printf ("\t       %cv  run in verbose mode\n",cs_OptchrC);
	printf ("\ttest_file  name of test data file\n\n");
	if (!batch)
	{
		printf ("Press any key to continue: ");
		fflush (stdout);
		getchar ();
		printf ("\n");
	}
	exit (1);
}

int CStest8 (int verbose,int crypt)

{
	extern struct cs_Grptbl_ cs_CsGrptbl [];
	extern int cs_Error;

	int err_cnt;

	struct cs_Grptbl_ *tp;
	struct cs_Csgrplst_ *gp;
	struct cs_Csgrplst_ *grp_list;
	struct cs_Csprm_ *csprm;

	double xy [3];
	double ll [3];

	printf ("Exercising each coordinate system definition at least once.\n");

	/* Loop through the group table and fetch a linked list
	   for each group.  Count the number in the group and
	   add to the total in the group. */

	err_cnt = 0;
	for (tp = cs_CsGrptbl;tp->group [0] != 0;tp += 1)
	{
		CS_csgrp (tp->group,&grp_list);
		for (gp = grp_list;gp != NULL;gp = gp->next)
		{
			/* Activate this coordinate system.  This
			   ensures that every coordinate system
			   is "set up" at least once in all of this. */

			if (verbose)
			{
				printf ("Exercising coordinate system named %s.\n",
							gp->key_nm);
			}
			csprm = CS_csloc (gp->key_nm);
			if (csprm == NULL)
			{
				printf ("Couldn't setup coordinate system named %s.\n",gp->key_nm);
				err_cnt += 1;
			}
			else
			{
				/* Convert a coordinate, the false origin should
				   be a safe one. */

				xy [0] = csprm->csdef.x_off;
				xy [1] = csprm->csdef.y_off;
				xy [2] = 0.0;
				cs_Error = 0;
				CS_cs2ll (csprm,ll,xy);
				CS_ll2cs (csprm,xy,ll);
				CS_csscl (csprm,ll);
				CS_cscnv (csprm,ll);
				if (cs_Error != 0)
				{
					printf ("Exercise of coordinate system %s failed.\n",
								csprm->csdef.key_nm);
					err_cnt += 1;
				}
				CS_free (csprm);
			}
		}
		CS_csgrpf (grp_list);
	}
	return (err_cnt);
}

struct cs_Test8_
{
	double geo;		/* degrees */
	double chi;		/* Delta, in seconds. */
	double beta;		/* Delta, in seconds. */
	double mu;		/* Delta, in seconds. Not used any more. */
	double centric;		/* Not used as yet. */
	double para;		/* Not used as yet. */
};

/* Values given are for the Clarke 1866 ellipsoid. Taken from
   Synder, Table 3 on page 18. */

__ALIGNMENT__13				/* Required by some Sun compilers. */
struct cs_Test8_ cs_Test8 [19] =
{/*        geo     chi    beta      mu centric    para   */
		{ 90.0,    0.0,    0.0,    0.0,    0.0,    0.0},
		{ 85.0, -121.9,  -81.2,  -91.4, -122.0,  -60.9},
		{ 80.0, -240.1, -160.0, -180.0, -240.3, -120.0},
		{ 75.0, -350.9, -233.9, -263.1, -351.3, -175.4},
		{ 70.0, -451.0, -300.6, -338.2, -451.4, -225.4},
		{ 65.0, -537.2, -358.2, -403.0, -537.7, -268.6},
		{ 60.0, -607.1, -404.8, -455.4, -607.6, -303.6},
		{ 55.0, -658.5, -439.1, -494.0, -658.9, -329.3},
		{ 50.0, -689.7, -460.1, -517.5, -690.2, -345.0},
		{ 45.0, -700.0, -467.0, -525.3, -700.5, -350.2},
		{ 40.0, -689.1, -459.8, -517.2, -689.4, -344.8},
		{ 35.0, -657.2, -438.6, -493.3, -657.4, -328.9},
		{ 30.0, -605.4, -404.1, -454.5, -605.6, -303.0},
		{ 25.0, -535.3, -357.3, -401.9, -535.4, -268.0},
		{ 20.0, -449.0, -299.7, -337.1, -449.1, -224.8},
		{ 15.0, -349.2, -233.1, -262.2, -349.2, -294.9},
		{ 10.0, -238.8, -159.4, -179.3, -238.8, -119.6},
		{  5.0, -121.2,  -80.9,  -91.0, -121.2,  -60.7},
		{  0.0,    0.0,    0.0,    0.0,    0.0,    0.0}
};

int CStest9 (int verbose)
{
	extern double cs_Zero;			/* 0.0 */
	extern double cs_Degree;		/* 1.0/57.29... */
	extern double cs_Sec2Rad;		/* Converts seconds to
						   radians. */
	int ii;
	int err_cnt;

	double ka;
	double e_sq;
	double lat;
	double lat_dd;
	double test;
	double test_val;
	double fwd;
	double inv;

	double mmi_sum;
	double chii_sum;
	double chif_sum;
	double bti_sum;
	double btf_sum;

	__ALIGNMENT__1			/* Required by some Sun compilers. */
	struct cs_MmcofF_  mmcofF;
	__ALIGNMENT__2			/* Required by some Sun compilers. */
	struct cs_MmcofI_  mmcofI;
	__ALIGNMENT__3			/* Required by some Sun compilers. */
	struct cs_ChicofF_ chicofF;
	__ALIGNMENT__4			/* Required by some Sun compilers. */
	struct cs_ChicofI_ chicofI;
	__ALIGNMENT__5			/* Required by some Sun compilers. */
	struct cs_BtcofF_  btcofF;
	__ALIGNMENT__6			/* Required by some Sun compilers. */
	struct cs_BtcofI_  btcofI;

	printf ("Checking ellipsoidal power series expansion functions.\n");

	err_cnt = 0;
	test_val = 2.424068406E-07;		/* 0.05 seconds of arc in
						   radians. */
	mmi_sum  = cs_Zero;
	chii_sum = cs_Zero;
	chif_sum = cs_Zero;
	bti_sum  = cs_Zero;
	btf_sum  = cs_Zero;

	/* For each value in the table, we compute the appropriate
	   value, compare with the value in the table, and then
	   compute the inverse, and compare with the original.
	   Again, we use the values for ka and e_sq provided by
	   Synder to be perfectly consistent on the test data.

	   Note, on the forward functions, the RMS value is what
	   some would call significant, however, it is well within
	   the significance of the prcision provided in the table.
	   Analysis of the RMS errors of the inverse are more
	   indicative of the accuracy of the series functions and
	   programming. */

	ka = 6378206.4;			/* Synder, Table 1, page 12. */
	e_sq = 0.006768658;		/* Synder, text, page 13. */

	CSmmFsu  (&mmcofF,ka,e_sq);
	CSmmIsu  (&mmcofI,ka,e_sq);
	CSchiFsu (&chicofF,e_sq);
	CSchiIsu (&chicofI,e_sq);
	CSbtFsu  (&btcofF,e_sq);
	CSbtIsu  (&btcofI,e_sq);

	/* We will use the forward function to generate a value which
	   is used to test the inverse function below.  However, we
	   have no specific table of data with which to comapre the
	   results of the forward function.  SYnder does provide, on
	   page 265 in Appendix A, a single test case which is used
	   here to perform a single test on the CSmmF??? functions.
	   Since this single test is at 40 degrees of latitude, the
	   check is special cased into the loop below. */


	for (ii = 0;ii < 19;ii++)
	{
		lat_dd = cs_Test8 [ii].geo;
		lat = lat_dd * cs_Degree;

		/* Test the meridonal distance functions. */

		fwd = CSmmFcal (&mmcofF,lat,sin (lat),cos (lat));
		if (lat_dd == 40.0)
		{
			/* See page 265 of Synder for this test. */
			test = fabs ((fwd / ka) - 0.6944458);
			if (test >= 0.00000005)
			{
				printf ("CSmmFcal failed on %4.1f degrees.\n",lat_dd);
				err_cnt += 1;
			}
		}

		inv = CSmmIcal (&mmcofI,fwd);
		test = fabs (inv - lat);
		if (test > test_val)
		{
			printf ("CSmmIcal failed on %4.1f degrees.\n",lat_dd);
			err_cnt += 1;
		}
		mmi_sum += test * test;

		/* Test the conformal latitude functions. */

		fwd = CSchiFcal (&chicofF,lat);
		test = fabs (fwd - (lat + (cs_Test8 [ii].chi * cs_Sec2Rad)));
		if (test > test_val)
		{
			printf ("CSchiFcal failed on %4.1f degrees.\n",lat_dd);
			err_cnt += 1;
		}
		chif_sum += test * test;

		inv = CSchiIcal (&chicofI,fwd);
		test = fabs (inv - lat);
		if (test > test_val)
		{
			printf ("CSchiIcal failed on %4.1f degrees.\n",lat_dd);
			err_cnt += 1;
		}
		chii_sum += test * test;

		/* Test the authalic latitude functions. */

		fwd = CSbtFcalPrec (&btcofF,lat);
		test = fabs (fwd - (lat + (cs_Test8 [ii].beta * cs_Sec2Rad)));
		if (test > test_val)
		{
			printf ("CSbtFcal failed on %4.1f degrees.\n",lat_dd);
			err_cnt += 1;
		}
		btf_sum += test * test;

		inv = CSbtIcalPrec (&btcofI,fwd);
		test = fabs (inv - lat);
		if (test > test_val)
		{
			printf ("CSbtIcal failed on %4.1f degrees.\n",lat_dd);
			err_cnt += 1;
		}
		bti_sum += test * test;
	}

	/* If verbose mode, print out the RMS errors for each item. */

	if (verbose)
	{
		printf (" Note that the forward results listed here are compared against\n");
		printf (" a published table which is limited in precision to 0.1 seconds\n");
		printf (" of arc. Thus, for the forward case, any RMS error less than 0.05\n");
		printf (" seconds of arc should be considered quite good. The inverse\n");
		printf (" error numebrs result from a comparison of the forward and inverse\n");
		printf (" calculations and are a true indication of the accuracy/precision\n");
		printf (" built into CS-MAP.\n\n");
		test = sqrt (mmi_sum / 18) / cs_Sec2Rad;
		printf (" Meridonal distance inverse error (RMS) = %12.8f seconds of arc.\n",
							test);
		test = sqrt (chif_sum / 18) / cs_Sec2Rad;
		printf (" Conformal latitude forward error (RMS) = %12.8f seconds of arc.\n",
							test);
		test = sqrt (chii_sum / 18) / cs_Sec2Rad;
		printf (" Conformal latitude inverse error (RMS) = %12.8f seconds of arc.\n",
							test);
		test = sqrt (btf_sum / 18) / cs_Sec2Rad;
		printf ("  Authalic latitude forward error (RMS) = %12.8f seconds of arc.\n",
							test);
		test = sqrt (bti_sum / 18) / cs_Sec2Rad;
		printf ("  Authalic latitude inverse error (RMS) = %12.8f seconds of arc.\n",
							test);
	}
	return (err_cnt);
}

int CStestA (int verbose,char *test_file)

{
	extern struct csNad27ToNad83_* csNad27ToNad83;
	extern struct csNad83ToHarn_* csNad83ToHarn;
	extern struct csAgd66ToGda94_* csAgd66ToGda94;
	extern struct csAgd84ToGda94_* csAgd84ToGda94;
	extern struct csNzgd49ToNzgd2K_* csNzgd49ToNzgd2K;

	int st;
	int line_nbr;
	int fail_cnt;

	long frmt_SX;
	long frmt_SY;
	long frmt_DX;
	long frmt_DY;

	char *cp;
	char *src_nm;
	char *src_x;
	char *src_y;
	char *dest_nm;
	char *dest_x;
	char *dest_y;
	char *tol_x;
	char *tol_y;
	FILE *fs_tst;

	double src_cc [3];
	double dest_cc [3];
	double rslt [3];
	double tol [2];
	double del [2];

	char l_buf [256];
	char errBufr [256];
	char bufrX [32];
	char bufrY [32];

	printf ("Using %s to test single function interface.\n",test_file);

	/* Same as Test 4, except we use the single function interface.
	   Therefore, we leave out the comments, and get right to it. */

	fs_tst = fopen (test_file,_STRM_TXTRD);
	if (fs_tst == NULL)
	{
		(void)printf ("Couldn't open %s\n",test_file);
		return (1);
	}

	line_nbr = 0;
	fail_cnt = 0;
	while (fgets (l_buf,sizeof (l_buf),fs_tst) != NULL)
	{
		line_nbr += 1;
		CS_trim (l_buf);
		if (l_buf [0] == '#') continue;
		if (l_buf [0] == '\0') continue;
		cp = l_buf;
		src_nm = cp;
		cp = strchr (cp,',');
		if (cp == NULL) goto frmterr;
		*cp++ = '\0';
		src_x = cp;
		cp = strchr (cp,',');
		if (cp == NULL) goto frmterr;
		*cp++ = '\0';
		src_y = cp;
		cp = strchr (cp,',');
		if (cp == NULL) goto frmterr;
		*cp++ = '\0';
		dest_nm = cp;
		cp = strchr (cp,',');
		if (cp == NULL) goto frmterr;
		*cp++ = '\0';
		dest_x = cp;
		cp = strchr (cp,',');
		if (cp == NULL) goto frmterr;
		*cp++ = '\0';
		dest_y = cp;
		cp = strchr (cp,',');
		if (cp == NULL) goto frmterr;
		*cp++ = '\0';
		tol_x = cp;
		cp = strchr (cp,',');
		if (cp == NULL) goto frmterr;
		*cp++ = '\0';
		tol_y = cp;

		/* OK, now we can perform the conversion. */

		frmt_SX = CS_atof (&src_cc [0],src_x);
		frmt_SY = CS_atof (&src_cc [1],src_y);
		src_cc [2] = 0.0;
		frmt_DX = CS_atof (&dest_cc [0],dest_x);
		frmt_DY = CS_atof (&dest_cc [1],dest_y);
		dest_cc [2] = 0.0;
		CS_atof (&tol [0],tol_x);
		CS_atof (&tol [1],tol_y);

		rslt [0] = src_cc [0];
		rslt [1] = src_cc [1];
		rslt [2] = 0.0;
		st = CS_cnvrt (src_nm,dest_nm,rslt);
		if (st < 0)
		{
			CS_errmsg (errBufr,sizeof (errBufr));
			printf ("%s\n",errBufr);
			fail_cnt += 1;
			continue;
		}
		if (st > 0)
		{
			printf ("Warning, range/domain error on %s ==> %s.\n",src_nm,dest_nm);
		}

		/* Evaluate the calculated result. */

		del [0] = fabs (rslt [0] - dest_cc [0]);
		del [1] = fabs (rslt [1] - dest_cc [1]);
		if (del [0] > tol [0] || del [1] > tol [1])
		{
			(void)printf ("Verification failure (line %d):\n",line_nbr);
			(void)printf ("\t%-23.23s %-16.16s %-16.16s\n",
							src_nm,src_x,src_y);
			(void)printf ("\t%-23.23s %-16.16s %-16.16s\n",
							dest_nm,dest_x,dest_y);
			CS_ftoa (bufrX,17,rslt [0],frmt_DX);
			CS_ftoa (bufrY,17,rslt [1],frmt_DY);
			(void)printf ("\t                   CALC %-16.16s %-16.16s\n",
								bufrX,bufrY);
			fail_cnt += 1;
		}
		else if (verbose)
		{
			(void)printf ("[%9.9s]%12.12s %12.12s ==> %12f %12f [%-9.9s]\n",
						src_nm,
						src_x,
						src_y,
						rslt [0],
						rslt [1],
						dest_nm);
		}
	}
	fclose (fs_tst);
	CS_recvr ();

	/* Note, CS_dtcls does not normally free up the
	   NADCON file directory as it does not use up
	   much memory, and is rather expensive (time wise)
	   to build.  However, since we are checking
	   heap allocations in this program, we must
	   free it up ourselves. */

	CSdeleteNad27ToNad83 (csNad27ToNad83);
	csNad27ToNad83 = NULL;
	CSdeleteNad83ToHarn (csNad83ToHarn);
	csNad83ToHarn = NULL;
	CSdeleteAgd66ToGda94 (csAgd66ToGda94);
	csAgd66ToGda94 = NULL;
	CSdeleteAgd84ToGda94 (csAgd84ToGda94);
	csAgd84ToGda94 = NULL;
	CSdeleteNzgd49ToNzgd2K (csNzgd49ToNzgd2K);
	csNzgd49ToNzgd2K = NULL;

	return (fail_cnt);

frmterr:
	printf ("Test data file format error on line %d.\n",line_nbr);
	fclose (fs_tst);
	CS_recvr ();

	CSdeleteNad27ToNad83 (csNad27ToNad83);
	csNad27ToNad83 = NULL;
	CSdeleteNad83ToHarn (csNad83ToHarn);
	csNad83ToHarn = NULL;
	CSdeleteAgd66ToGda94 (csAgd66ToGda94);
	csAgd66ToGda94 = NULL;
	CSdeleteAgd84ToGda94 (csAgd84ToGda94);
	csAgd84ToGda94 = NULL;
	CSdeleteNzgd49ToNzgd2K (csNzgd49ToNzgd2K);
	csNzgd49ToNzgd2K = NULL;

	return (1);
}

int CStestB (int verbose,long duration)

{
	extern struct cs_Grptbl_ cs_CsGrptbl [];
	extern double cs_Mone;   /* -1 */
	extern double cs_Km360;  /* -360 */
	extern double cs_SclInf; /* 9.9E+04 */

	int brk_flg;
	int err_cnt;
	int itr_cnt;

	long il;

	struct cs_Grptbl_ *tp;
	struct cs_Csgrplst_ *gp;
	struct cs_Csgrplst_ *grp_list;
	struct cs_Csprm_ *csprm;

	double del_lat;
	double tolerance;
	double test_val, csmap_val;

	double low_lat, hi_lat;
	double low_lng, hi_lng;
	double ll [2];

	printf ("Checking scale and convergence for non-azimuthal projections.\n");

	/* Loop through the group table and fetch a linked list
	   for each group.  Count the number in the group and
	   add to the total in the group. */

	err_cnt = 0;
	csprm = NULL;
	for (tp = cs_CsGrptbl;tp->group [0] != 0;tp += 1)
	{
		if (csprm != NULL)
		{
			CS_free (csprm);
			csprm = NULL;
		}
		CS_csgrp (tp->group,&grp_list);
		for (gp = grp_list;gp != NULL;gp = gp->next)
		{
			if (csprm != NULL)
			{
				CS_free (csprm);
				csprm = NULL;
			}

			/* Activate this coordinate system. */

			if (verbose)
			{
				printf ("Checking scale and convergence for %s.\n",
							gp->key_nm);
			}
			csprm = CS_csloc (gp->key_nm);
			if (csprm == NULL)
			{
				printf ("Couldn't setup coordinate system named %s.\n",gp->key_nm);
				err_cnt += 1;
				continue;
			}

			/* Skip over the LL projections.  They make no sense
			   here. */

			if (csprm->prj_code == cs_PRJCOD_UNITY)
			{
				continue;
			}

			/* We are testing the validity of the values here.
			   We test robustness elsewhere.

			   Generate a random coordinate now. */

			low_lng = csprm->cent_mer + csprm->min_ll [LNG] * 0.75;
			hi_lng =  csprm->cent_mer + csprm->max_ll [LNG] * 0.75;
			del_lat = csprm->max_ll [LAT] - csprm->min_ll [LAT];
			low_lat = csprm->min_ll [LAT] + 0.1 * del_lat;
			hi_lat  = csprm->max_ll [LAT] - 0.1 * del_lat;

			brk_flg = FALSE;
			for (il = 0;!brk_flg && il < duration;il += 1)
			{
				ll [LNG] = CStestRN (low_lng,hi_lng);
				ll [LNG] = CS_adj180 (ll [LNG]);
				itr_cnt = 0;
				do
				{
					if (itr_cnt++ > 5) break;
					ll [LAT] = CStestRN (low_lat,hi_lat);
				} while	(fabs (ll [LAT]) > 85.0);

				/* For Azimuthal projections, K and H
				   scale factors are often special, e.g.
				   normal to the radial from the origin
				   of the projection. In these cases,
				   the test functions in this module
				   are invalid.  Therefore, we have this
				   little kludge to skip the K and
				   H scale factor tests for certain
				   type projections.
				   
				   Similar considerations apply to the
				   Bipolar Oblique Conic. K and H are
				   relative to the oblique poles. Therefore,
				   our test functions will not generate
				   appropriate values. */

				if ((csprm->prj_flags & cs_PRJFLG_AZMTH) != 0 ||
					 csprm->prj_code == cs_PRJCOD_BPCNC)
				{
					goto skip_KH;
				}

				/* The special projection variations for WI
				   and MN won't work either as these systems
				   are elevated above the ellipsoid.
				   
				   OSTN02, OSTN97, and both Danish systems
				   include heavy duty non-analytical (i.e.
				   polynomials and/or grid file) techniques,
				   thus we have now way of generating a
				   reliabel test value. */

				if (csprm->prj_code == cs_PRJCOD_WCCST ||
					csprm->prj_code == cs_PRJCOD_WCCSL ||
					csprm->prj_code == cs_PRJCOD_MNDOTL ||
					csprm->prj_code == cs_PRJCOD_MNDOTT ||
					csprm->prj_code == cs_PRJCOD_OSTN97 ||
					csprm->prj_code == cs_PRJCOD_OSTN02 ||
					csprm->prj_code == cs_PRJCOD_SYS34 ||
					csprm->prj_code == cs_PRJCOD_SYS34_99
				   )
				{
					goto skip_KH;
				}

				/* The Krovak projection uses a strange radius as the base for
				   the calculations.  That is, rho0 (the radius of the standard
				   parallel) is calculated on the ellipsoid, but the actual
				   coordinate system is based on a sphere of a different
				   radius.  Thus, the test value generator, does not generate
				   appropriate values.  So, for now, we skip this test on
				   the Krovak. */

				if (csprm->prj_code == cs_PRJCOD_KROVAK || csprm->prj_code == cs_PRJCOD_KRVK95)
				{
					goto skip_KH;
				}

				/* Since we will be calculating our own
				   value, we can't use CS_csscl.
				   
				   Note, we could tighten up the tolerances, but
				   only if we limit the geographic extents of the
				   tests.  The values used are a compromise. */

				csmap_val = CS_cssck (csprm,ll);
				test_val  = CStstsclk (csprm,ll);
				if (test_val > cs_Mone && test_val < cs_SclInf)
				{
					tolerance = 0.00005 * fabs (test_val - 1.0);
					if (tolerance < 5.0E-06) tolerance = 5.0E-06;
					if (fabs (csmap_val - test_val) > tolerance)
					{
						printf ("K scale error, %s: lng = %11.6f, lat = %10.6f\n",
										csprm->csdef.key_nm,
										ll [LNG],
										ll [LAT]);
						err_cnt += 1;
						brk_flg = TRUE;

						/* Uncomment the following for
						   convenient debugging.
						*/

						csmap_val = CS_cssck (csprm,ll);
						test_val  = CStstsclk (csprm,ll);
					}
				}

				csmap_val = CS_cssch (csprm,ll);
				test_val  = CStstsclh (csprm,ll);
				if (test_val < cs_SclInf && test_val > cs_Mone)
				{
					tolerance = 0.00005 * fabs (test_val - 1.0);
					if (tolerance < 5.0E-06) tolerance = 5.0E-06;

					if (fabs (csmap_val - test_val) > tolerance)
					{
						printf ("H scale error, %s: lng = %11.6f, lat = %10.6f\n",
										csprm->csdef.key_nm,
										ll [LNG],
										ll [LAT]);
						err_cnt += 1;
						brk_flg = TRUE;

						/* Uncomment the following for
						   convenient debugging. */

						csmap_val = CS_cssch (csprm,ll);
						test_val  = CStstsclh (csprm,ll);
						/**/
					}
				}

skip_KH:
				/* We skip the coordinate systems which are
				   not rectified, i.e. Y is not necessarily
				   north. */

				if (csprm->prj_code == cs_PRJCOD_HOM1UV ||
					csprm->prj_code == cs_PRJCOD_HOM2UV)
				{
					continue;
				}

				csmap_val = CS_cscnv (csprm,ll);
				test_val  = CStstcnvrg (csprm,ll);
				if (test_val <= cs_Km360)
				{
					continue;
				}

				/* For the Transverse Mercator and similar projections, the
				   accuracy of the standard convergence angle calculation
				   deteriotates	rapidly as one moves away from the central
				   meridian.  So, we have this rather obnoxious kludge for
				   these projections.  Note, this value is in degrees,
				   therefore, a tolerance of 0.001 is pretty tight. */

				tolerance = 0.00001 * fabs (test_val);
				if (tolerance < 0.00001) tolerance = 0.00001;
				if (fabs (csmap_val - test_val) > tolerance)
				{
					printf ("Convergence error, %s: lng = %11.6f, lat = %10.6f\n",
									csprm->csdef.key_nm,
									ll [LNG],
									ll [LAT]);
					err_cnt += 1;
					brk_flg = TRUE;

					/* Uncomment the following for
					   convenient debugging.
					*/

					csmap_val = CS_cscnv (csprm,ll);
					test_val  = CStstcnvrg (csprm,ll);
				}
			}
			CS_free (csprm);
			csprm = NULL;
		}
		CS_csgrpf (grp_list);
	}
	return (err_cnt);
}

/*
	The following test exercises each coordinate system
	in the COORDSYS file, and exercises each attempting
	to produce a floating point exception.  We do this,
	using a random number generator, to throw all sorts
	of bogus numbers at each projection.
*/

int CStestC (int verbose,long duration)

{
	extern struct cs_Grptbl_ cs_CsGrptbl [];
	extern double cs_Zero;
	extern int cs_MeFlag;
	extern char cs_MeKynm [];
	extern char cs_MeFunc [];
	extern double cs_Coords [3];

	int err_cnt;

	long il;
	long ilng;
	long ilat;
	long ihgt;

	struct cs_Grptbl_ *tp;
	struct cs_Csgrplst_ *gp;
	struct cs_Csgrplst_ *grp_list;
	struct cs_Csprm_ *csprm;

	double hi_val;
	double lo_val;
	double adjust;

	double ll [3];
	double xy [3];
	double llAry [1][3];
	double xyAry [1][3];

	duration *= 10L;

	printf ("Trying very hard to produce a floating point exception.\n");

	/* Loop through the group table and fetch a linked list
	   for each group.  Count the number in the group and
	   add to the total in the group. */

	err_cnt = 0;
	csprm = NULL;
	for (tp = cs_CsGrptbl;tp->group [0] != 0;tp += 1)
	{
		if (csprm != NULL)
		{
			CS_free (csprm);
			csprm = NULL;
		}
		CS_csgrp (tp->group,&grp_list);
		for (gp = grp_list;gp != NULL;gp = gp->next)
		{
			if (csprm != NULL)
			{
				CS_free (csprm);
				csprm = NULL;
			}
			if (verbose)
			{
				printf ("Trying to cause a floating exception using %s.\n",
							gp->key_nm);
			}
			else
			{
				printf ("%s               \r",gp->key_nm);
			}

			csprm = CS_csloc (gp->key_nm);
			if (csprm == NULL)
			{
				printf ("Couldn't setup coordinate system named %s.\n",gp->key_nm);
				err_cnt += 1;
				strcpy (cs_MeKynm,"???");
				continue;
			}
			cs_MeFlag = 0;
			strcpy (cs_MeKynm,csprm->csdef.key_nm);
			for (ilng = -600;ilng <= 600;ilng += 15)
			{
				for (ilat = -600;ilat <= 600;ilat += 15)
				{
					ihgt = (ilat / 2) + (ilng / 2);
					cs_Coords [LNG] = (double)(ilng);
					cs_Coords [LAT] = (double)(ilat);
					cs_Coords [HGT] = (double)(ihgt);
					ll [LNG] = cs_Coords [LNG];
					ll [LAT] = cs_Coords [LAT];
					ll [HGT] = cs_Coords [HGT];
					if (verbose)
					{
						printf ("\tLNG = %4ld, LAT = %4ld, HGT = %4ld     \r",ilng,ilat,ihgt);
					}
					strcpy (cs_MeFunc,"CS_cssck");
					CS_cssck (csprm,ll);
					if (cs_MeFlag) break;
					strcpy (cs_MeFunc,"CS_cssch");
					CS_cssch (csprm,ll);
					if (cs_MeFlag) break;
					strcpy (cs_MeFunc,"CS_cscnv");
					CS_cscnv (csprm,ll);
					if (cs_MeFlag) break;
					strcpy (cs_MeFunc,"CS_ll2cs");
					CS_ll2cs (csprm,xy,ll);
					if (cs_MeFlag) break;

					llAry [0][0] = ll [0];		/* keep gcc compiler happy */
					llAry [0][1] = ll [1];
					llAry [0][2] = ll [2];
					strcpy (cs_MeFunc,"CS_llchk");
					CS_llchk (csprm,1,llAry);
					if (cs_MeFlag) break;
				}
				if (cs_MeFlag) break;
			}
			if (cs_MeFlag)
			{
				err_cnt += 1;
				continue;
			}
			hi_val = CStestRN (1.0E+10,2.0E+10);
			lo_val = -hi_val;
			adjust = exp (log (hi_val) / (double)duration);
			for (il = 0;il < duration;il += 1)
			{
				cs_Coords [LNG] = (double)(ilng);
				cs_Coords [LAT] = (double)(ilat);
				cs_Coords [HGT] = 0.0;

				ll [LNG] = cs_Coords [LNG];
				ll [LAT] = cs_Coords [LAT];
				ll [HGT] = 0.0;
				if (verbose)
				{
					printf ("\tLNG = %g, LAT = %g               \r",ll [LNG],ll [LAT]);
				}
				strcpy (cs_MeFunc,"CS_cssck");
				CS_cssck (csprm,ll);
				if (cs_MeFlag) break;
				strcpy (cs_MeFunc,"CS_cssch");
				CS_cssch (csprm,ll);
				if (cs_MeFlag) break;
				strcpy (cs_MeFunc,"CS_ccnvk");
				CS_cscnv (csprm,ll);
				if (cs_MeFlag) break;
				strcpy (cs_MeFunc,"CS_ll2cs");
				CS_ll2cs (csprm,xy,ll);
				if (cs_MeFlag) break;
				strcpy (cs_MeFunc,"CS_llchk");

				llAry [0][0] = ll [0];		/* keep gcc compiler happy */
				llAry [0][1] = ll [1];
				llAry [0][2] = ll [2];
				CS_llchk (csprm,1,llAry);
				if (cs_MeFlag) break;
				lo_val /= adjust;
				hi_val /= adjust;
			}
			if (cs_MeFlag)
			{
				err_cnt += 1;
				continue;
			}
			hi_val = CStestRN (1.0E+10,2.0E+10);
			lo_val = -hi_val;
			adjust = exp (log (hi_val) / (double)duration);
			for (il = 0;il < duration;il += 1)
			{
				xy [XX] = CStestRN (lo_val,hi_val);
				xy [YY] = CStestRN (lo_val,hi_val);
				xy [ZZ] = CStestRN (lo_val,hi_val);
				cs_Coords [XX] = xy [XX];
				cs_Coords [YY] = xy [YY];
				cs_Coords [ZZ] = xy [ZZ];
				if (verbose)
				{
					printf ("\tXX = %g, YY = %g, ZZ = %g          \r",xy [XX],xy [YY],xy [ZZ]);
				}
				strcpy (cs_MeFunc,"CS_cs2ll");
				CS_cs2ll (csprm,ll,xy);
				if (cs_MeFlag) break;
				strcpy (cs_MeFunc,"CS_llchk");
				xyAry [0][0] = xy [0];		/* keep gcc compiler happy */
				xyAry [0][1] = xy [1];
				xyAry [0][2] = xy [2];
				CS_xychk (csprm,1,xyAry);
				if (cs_MeFlag) break;
				lo_val /= adjust;
				hi_val /= adjust;
			}
			if (cs_MeFlag)
			{
				err_cnt += 1;
				continue;
			}

			/* Make sure we give the inverse function a
			   zero coordinate. */

			xy [XX] = cs_Zero;
			xy [YY] = cs_Zero;
			xy [ZZ] = cs_Zero;
			cs_Coords [XX] = xy [XX];
			cs_Coords [YY] = xy [YY];
			cs_Coords [ZZ] = xy [ZZ];
			if (verbose)
			{
				printf ("\tXX = %g, YY = %g             \r",xy [XX],xy [YY]);
			}
			strcpy (cs_MeFunc,"CS_cs2ll");
			CS_cs2ll (csprm,ll,xy);
			if (cs_MeFlag)
			{
				err_cnt += 1;
				continue;
			}

			if (verbose)
			{
				printf ("                                                \r");
			}
			CS_free (csprm);
			csprm = NULL;
		}
		CS_csgrpf (grp_list);
	}
	printf ("                                 \r");
	return (err_cnt);
}

/*
	The following test exercises each coordinate system
	in the COORDSYS file, and exercises each assuring
	that coordinates within the useful range of each
	projection are reversible within rather liberal
	limits.
*/

int CStestD (int verbose,long duration)

{
	extern struct cs_Grptbl_ cs_CsGrptbl [];

	int status;
	int err_cnt;

	long il;

	struct cs_Grptbl_ *tp;
	struct cs_Csgrplst_ *gp;
	struct cs_Csgrplst_ *grp_list;
	struct cs_Csprm_ *csprm;

	double ll  [3];
	double xy  [3];
	double ll1 [3];

	double low_lng;
	double low_lat;
	double hi_lng;
	double hi_lat;
	double ll_tol;
	double del_lng;
	double del_lat;

	duration *= 100L;

	printf ("Checking reversibility of all projections, large region/tolerance.\n");

	/* Loop through the group table and fetch a linked list
	   for each group.  Count the number in the group and
	   add to the total in the group. */

	err_cnt = 0;
	csprm = NULL;
	for (tp = cs_CsGrptbl;tp->group [0] != 0;tp += 1)
	{
		if (csprm != NULL)
		{
			CS_free (csprm);
			csprm = NULL;
		}
		CS_csgrp (tp->group,&grp_list);
		for (gp = grp_list;gp != NULL;gp = gp->next)
		{
			if (csprm != NULL)
			{
				CS_free (csprm);
				csprm = NULL;
			}
			if (verbose)
			{
				printf ("Testing %s for reversibility.\n",
							gp->key_nm);
			}
			else
			{
				printf ("%s               \r",gp->key_nm);
			}

			csprm = CS_csloc (gp->key_nm);
			if (csprm == NULL)
			{
				printf ("Couldn't setup coordinate system named %s.\n",gp->key_nm);
				err_cnt += 1;
				continue;
			}
			strcpy (cs_MeKynm,csprm->csdef.key_nm);

			low_lng = csprm->cent_mer + csprm->min_ll [LNG];
			hi_lng =  csprm->cent_mer + csprm->max_ll [LNG];
			low_lat = csprm->min_ll [LAT];
			hi_lat  = csprm->max_ll [LAT];
			for (il = 0;il < duration;il += 1)
			{
				ll [LNG] = CStestRN (low_lng,hi_lng);
				ll [LNG] = CS_adj180 (ll [LNG]);
				ll [LAT] = CStestRN (low_lat,hi_lat);

				/* We set the tolerance to what equals about one
				   a meter for this test.  A smaller tolerance is
				   possible, but only if we tighten up on the deviations
				   from the origin of the projection.  That is done, now,
				   int test E. */

				ll_tol = 1.0E-05;
				if (csprm->prj_code == cs_PRJCOD_SYS34 ||
				    csprm->prj_code == cs_PRJCOD_SYS34_99) ll_tol = 5.0E-05;

				/* Convert to X and Y, then back again. */

				strcpy (cs_MeFunc,"CS_ll2cs");
				status = CS_ll2cs (csprm,xy,ll);
				if (status != cs_CNVRT_NRML) continue;
				strcpy (cs_MeFunc,"CS_cs2ll");
				status = CS_cs2ll (csprm,ll1,xy);
				if (status != cs_CNVRT_NRML) continue;

				/* Conversions were OK, see if we
				   ended up with what we started
				   with. */

				del_lng = CS_adj180 (ll [0] - ll1 [0]);
				del_lat = ll [1] - ll1 [1];
				if (fabs (del_lng) > ll_tol ||
					fabs (del_lat) > ll_tol)
				{
					printf ("%s:: Couldn't reverse %f:%f.\n",csprm->csdef.key_nm,ll[0],ll[1]);
					printf ("\t\tdel_lng = %g,del_lat = %g.\n",del_lng,del_lat);
					err_cnt += 1;

					/* Uncomment the following for
					   easier debugging.

					status = CS_ll2cs (csprm,xy,ll);
				    status = CS_cs2ll (csprm,ll1,xy);
					ll1 [0] = CS_adj180 (ll1 [0]);
					*/
					break;
				}
			}

			CS_free (csprm);
			csprm = NULL;
		}
		CS_csgrpf (grp_list);
	}
	return (err_cnt);
}

/*
	The following test is a duplicate of the previous
	test.  However, in this case we restrict test
	coordinates to be more firmly rooted to the
	useful area of the projection, and therefore,
	can increase the tolerance level by an order
	of magnitude.
*/

int CStestE (int verbose,long duration)

{
	extern struct cs_Grptbl_ cs_CsGrptbl [];

	int status;
	int err_cnt;

	long il;

	struct cs_Grptbl_ *tp;
	struct cs_Csgrplst_ *gp;
	struct cs_Csgrplst_ *grp_list;
	struct cs_Csprm_ *csprm;

	double ll  [3];
	double xy  [3];
	double ll1 [3];

	double lat_del;
	double low_lng;
	double low_lat;
	double hi_lng;
	double hi_lat;
	double ll_tol;
	double del_lng;
	double del_lat;

	duration *= 100L;

	printf ("Checking reversibility of all projections, smaller region/tolerance.\n");

	/* Loop through the group table and fetch a linked list
	   for each group.  Count the number in the group and
	   add to the total in the group. */

	err_cnt = 0;
	csprm = NULL;
	for (tp = cs_CsGrptbl;tp->group [0] != 0;tp += 1)
	{
		if (csprm != NULL)
		{
			CS_free (csprm);
			csprm = NULL;
		}
		CS_csgrp (tp->group,&grp_list);
		for (gp = grp_list;gp != NULL;gp = gp->next)
		{
			if (csprm != NULL)
			{
				CS_free (csprm);
				csprm = NULL;
			}
			if (verbose)
			{
				printf ("Testing %s for reversibility.\n",
							gp->key_nm);
			}
			else
			{
				printf ("%s               \r",gp->key_nm);
			}

			csprm = CS_csloc (gp->key_nm);
			if (csprm == NULL)
			{
				printf ("Couldn't setup coordinate system named %s.\n",gp->key_nm);
				err_cnt += 1;
				continue;
			}
			strcpy (cs_MeKynm,csprm->csdef.key_nm);

			/* Get the useful range of the coordinate system and reduce it
			   by about one half. */

			low_lng = csprm->cent_mer + csprm->min_ll [LNG] + fabs (csprm->min_ll [LNG] * 0.5);
			hi_lng =  csprm->cent_mer + csprm->max_ll [LNG] - fabs (csprm->min_ll [LNG] * 0.5);
			lat_del = csprm->max_ll [LAT] - csprm->min_ll [LAT]; 
			low_lat = csprm->min_ll [LAT] + lat_del * 0.25;
			hi_lat  = csprm->max_ll [LAT] - lat_del * 0.25;
			for (il = 0;il < duration;il += 1)
			{
				ll [LNG] = CStestRN (low_lng,hi_lng);
				ll [LNG] = CS_adj180 (ll [LNG]);
				ll [LAT] = CStestRN (low_lat,hi_lat);

				/* For the two projections which account for 95% of
				   the mapping in the world, we use a very small
				   tolerance which approximates 5 millimeters on the
				   earth.  For the less important projections, we
				   use a tolerance which approximates 50 millimeters.

				   That is, for several projections, specifically the
				   whole world type, the mathemagics simply doesn't
				   produce the same level of accuracy as the two
				   biggies do.

				   As the Van der Grinten approaches the central
				   meridian, however, we need to relax the tolerance
				   to account for the mathematical discontinuity
				   encountered there. */

				if (csprm->prj_code == cs_PRJCOD_TRMER ||
				    csprm->prj_code == cs_PRJCOD_LM2SP)
				{
					ll_tol = 4.5E-08;
				}
				else if (csprm->prj_code == cs_PRJCOD_CSINI)
				{
					/* Cassini doesn't reverse very well.  Have investigated
					   several times, but cannot determine why this projection
					   is significanly worse than the others.  Current code
					   matches all test cases we have been able to find. */
					ll_tol = 2.5E-06;
				}
				else
				{
					ll_tol = 4.5E-07;
				}
				if (csprm->prj_code == cs_PRJCOD_VDGRN)
				{
					if (fabs (ll [0] - csprm->cent_mer) < 0.1) ll_tol = 1.0E-05;
				}

				/* Due to the polynomials, the Danish stuff does not invert well
				   when you're not within the real domain of the polynomial; i.e.
				   actually in the region being converted.  Thus, randomly generated
				   numbers like this do not invert well. */
				if (csprm->prj_code == cs_PRJCOD_SYS34 ||
				    csprm->prj_code == cs_PRJCOD_SYS34_99) ll_tol = 5.0E-05;

				/* Convert to X and Y, then back again. */

				strcpy (cs_MeFunc,"CS_ll2cs");
				status = CS_ll2cs (csprm,xy,ll);
				if (status != cs_CNVRT_NRML) continue;
				strcpy (cs_MeFunc,"CS_cs2ll");
				status = CS_cs2ll (csprm,ll1,xy);
				if (status != cs_CNVRT_NRML) continue;

				/* Conversions were OK, see if we
				   ended up with what we started
				   with. */

				del_lng = CS_adj180 (ll [0] - ll1 [0]);
				del_lat = ll [1] - ll1 [1];
				if (fabs (del_lng) > ll_tol ||
					fabs (del_lat) > ll_tol)
				{
					printf ("%s:: Couldn't reverse %f:%f.\n",csprm->csdef.key_nm,ll[0],ll[1]);
					printf ("\t\tdel_lng = %g,del_lat = %g.\n",del_lng,del_lat);
					err_cnt += 1;

					/* Uncomment the following for
					   easier debugging. */

					status = CS_ll2cs (csprm,xy,ll);
					status = CS_cs2ll (csprm,ll1,xy);
				}
			}

			CS_free (csprm);
			csprm = NULL;
		}
		CS_csgrpf (grp_list);
	}
	return (err_cnt);
}

#define XY_BASE (cs_ATOF_COMMA)
#define DMS_BASE (cs_ATOF_MINSEC | cs_ATOF_MINSEC0 | cs_ATOF_DIRCHR | cs_ATOF_XEAST)
struct _fTable
{
	long format;
	double tol;
	double min;
	double max;
};
double __dummy_21;			/* Required by some Sun compilers. */
struct _fTable fTable [] =
{
	{cs_ATOF_XXXDFLT,  0.01, -1E+08, 1E+08 },
	{cs_ATOF_YYYDFLT,  0.01, -1E+08, 1E+08 },
	{XY_BASE | 6,     1E-05, -1E+08, 1E+08 },
	{XY_BASE | 8,     1E-07, -1E+08, 1E+08 },
	{cs_ATOF_LNGDFLT, 3E-06, -180.0, 180.0 },
	{cs_ATOF_LATDFLT, 3E-06,  -90.0,  90.0 },
	{DMS_BASE | 6,    3E-09, -180.0, 180.0 }
};

int CStestF (int verbose,long duration)
{
	int err_cnt;
	int idx;
	int prec;

	long il;

	double dbl1, dbl2, tol;

	char bufr [32];

	duration *= 2000L;

	printf ("Using sprintf to check CS_atof (no DMS).\n");
	err_cnt = 0;
	for (il = 0;il < duration && err_cnt == 0;il += 1)
	{
		dbl1 = CStestRN (-1E+12,1E+12);
		if (fabs (dbl1) < 1E-23) continue;
		sprintf	(bufr,"%28.14f",dbl1);
		CS_atof (&dbl2,bufr);
		prec = (int)log10 (fabs (dbl1));
		prec = (int)log10 (fabs (dbl1)) - 14;
		tol = pow (10.0,(double)prec); 
		if (fabs (dbl1 -dbl2) > tol)
		{
			printf ("CS_atof produced %f from %s.\n",dbl2,bufr);
			err_cnt += 1;
		}
	}
	printf ("Using CS_atof to check CS_ftoa.\n");
	for (il = 0;il < duration && err_cnt < 4;il += 1)
	{
		idx = il % 7;
		dbl1 = CStestRN (fTable [idx].min,fTable [idx].max);
		CS_ftoa (bufr,sizeof (bufr),dbl1,fTable [idx].format);
		CS_atof (&dbl2,bufr);
		if (fabs (dbl1 - dbl2) > fTable [idx].tol)
		{
	    	printf ("CS_atof/ftoa failed: %f -> %s ->%f\n",dbl1,bufr,dbl2);
			err_cnt += 1;
		}
	}
	return (err_cnt);
}

/*
	Test G is the creep test. We start with a cartesian coordinate.
	We then repeatedly convert from cartesian to geographic and
	back to cartesian; about 1,000 times. We then measure the
	difference between what we started with and what we ended
	up with. Our tolerance here is 1 centimeter per 1000 conversions.
*/

struct _gTable
{
	char cs_name [32];
	char prjLabel [64];
	double point [2];
	double tol;
};
__ALIGNMENT__14				/* Required by some Sun compilers. */
struct _gTable gTable [] =
{
	{       "UTM27-13",     "Transverse Mercator", { 400000.0, 5000000.0},   5.000},
	{           "CO-C", "Lambert Conformal Conic", { 1500000.0, 250000.0},   5.000},
	{           "AK-1", "Hotine Oblique Mercator", { 2615716.0,1156768.0},   5.000},
	{           "US48",      "Alber's Equal Area", { 1000000.0,2000000.0},   5.000},
	{           "TRUK",    "Lambert Equi-Distant", {   75000.0,  60000.0},   5.000},
	{     "ArPoly-27F",      "American Polyconic", {  100000.0, 100000.0},   5.000},
	{     "CaspianSea",                "Mercator", {  100500.0,  95000.0},   5.000},
	{               "",                        "", {       0.0,      0.0},   0.000}
};

int CStestG (int verbose,long duration)
{
	int err_cnt;
	int idx;
	int ii;

	struct cs_Csprm_ *csPtr;

	double del_xx;
	double del_yy;
	double creep;

	double start [2];
	double xy [3];
	double ll [3];
	
	printf ("Performing creep test.\n");
	err_cnt = 0;
	for (idx = 0;gTable [idx].cs_name [0] != '\0' && err_cnt < 4;idx += 1)
	{
		start [0] = gTable [idx].point [0];
		start [1] = gTable [idx].point [1];
		xy [0] = start [0];
		xy [1] = start [1];
		csPtr = CS_csloc (gTable [idx].cs_name);
		if (csPtr == NULL)
		{
			return (1);
		}
		for (ii = 0;ii < 1000;ii += 1)
		{
			CS_cs2ll (csPtr,ll,xy);
			CS_ll2cs (csPtr,xy,ll);
		}
		del_xx = xy [0] - start [0];
		del_yy = xy [1] - start [1];
		creep = sqrt (del_xx * del_xx + del_yy * del_yy) * csPtr->csdef.unit_scl * 1000.0;
		if (creep > gTable [idx].tol)
		{
			printf ("Creep test on %s failed, (%f mm/1,000 conversions).\n",gTable [idx].cs_name,creep);
			err_cnt += 1;
		}
		else if (verbose)
		{
			printf ("%s creep is %f mm per %d conversions\n",gTable [idx].prjLabel,creep,ii);
		}
		CS_free (csPtr);
	}
	return (err_cnt);
}

struct _hTable1
{
	char str1 [32];
	char str2 [32];
	int cmpLength;
	int cmpValue;
};
__ALIGNMENT__15				/* Required by some Sun compilers. */
struct _hTable1 hTable1 [] =
{
	{ "abcdefg", "abcdefg", 0,  0},
	{ "ABCDEFG", "abcdefg", 0,  0},
	{ "abcdefg", "ABCDEFG", 0,  0},

	{ "abcdefg", "bcdefgh", 0, -1},
	{ "ABCDEFG", "bcdefgh", 0, -1},
	{ "abcdefg", "BCDEFGH", 0, -1},

	{ "bcdefgh", "abcdefg", 0,  1},
	{ "BCDEFGH", "abcdefg", 0,  1},
	{ "bcdefgh", "ABCDEFG", 0,  1},

	{ "abcd   ", "abcd$$$", 4,  0},
	{ "ABCD   ", "abcd$$$", 4,  0},
	{ "abcd   ", "ABCD$$$", 4,  0},

	{ "abcd   ", "bcde$$$", 4, -1},
	{ "ABCD   ", "bcde$$$", 4, -1},
	{ "abcd   ", "BCDE$$$", 4, -1},

	{ "bcde   ", "abcd!!!", 4,  1},
	{ "BCDE   ", "abcd!!!", 4,  1},
	{ "bcde   ", "ABCD!!!", 4,  1},

	{ "abcd!!!", "abcd   ", 4,  0},
	{ "ABCD!!!", "abcd   ", 4,  0},
	{ "abcd!!!", "ABCD   ", 4,  0},

	{ "abcd$$$", "bcde   ", 4, -1},
	{ "ABCD$$$", "bcde   ", 4, -1},
	{ "abcd$$$", "BCDE   ", 4, -1},

	{ "bcde$$$", "abcd   ", 4,  1},
	{ "BCDE$$$", "abcd   ", 4,  1},
	{ "bcde$$$", "ABCD   ", 4,  1},

	{ "ABC_EFG", "abc_efg", 0,  0},
	{ "ABC[EFG", "abc[efg", 0,  0},
	{ "ABC]EFG", "abc]efg", 0,  0},
	{ "ABC^EFG", "abc^efg", 0,  0},
	{ "ABC`EFG", "abc`efg", 0,  0},
	{ "ABC_EFG", "abc[efg", 0,  1},
	{ "ABC[EFG", "abc_efg", 0, -1},

	{ "",        "Abcdef",  0, -1},
	{ "Abcdef",  "",        0,  1},
	{ "AbcDefG", "aBcDefG", 0,  0},
	{ "",        "",       -1,  0}
};
struct _hTable2
{
	char str1 [32];
	char str2 [32];
	char str3 [32];
	int nullFlag;
};
__ALIGNMENT__16				/* Required by some Sun compilers. */
struct _hTable2 hTable2 [] =
{
	{ "AbCdEfGhIjKlMnO", "efg",            "EfG",            FALSE},
	{ "AbCdEfGhIjKlMnO", "EFG",            "EfG",            FALSE},
	{ "AbCdEfGhIjKlMnO", "EfG",            "EfG",            FALSE},
	{ "AbCdEfGhIjKlMnO", "eFg",            "EfG",            FALSE},

	{ "AbCdEfGhIjKlMnO", "eg",             "",                TRUE},
	{ "AbCdEfGhIjKlMnO", "",               "",                TRUE},
	{ "AbCdEfGhIjKlMnO", "EGF",            "",                TRUE},
	{ "AbCdEfGhIjKlMnO", "egf",            "",                TRUE},

	{ "AbCdEfGhIjKlMnO", "MNO",            "MnO",             FALSE},
	{ "AbCdEfGhIjKlMnO", "AbC",            "AbC",             FALSE},
	{ "AbCdEfGhIjKlMnO", "ABCDEFGHIJKLMNO","AbCdEfGhIjKlMnO", 0},

	{ "CONUS",           "HPGN",           "",                TRUE},
	{ "conus",           "HPGN",           "",                TRUE},
	{ "CONUS",           "hpgn",           "",                TRUE},
	{ "CoNuS",           "HpGn",           "",                TRUE},
	{ "COnuS",           "hPgN",           "",                TRUE},
	{ "COHPGN",          "HPGN",           "HPGN",            FALSE},
	{ "cohpgn",           "HPGN",          "hpgn",            FALSE},
	{ "CoHpgn",           "HPGN",          "Hpgn",            FALSE},
	{ "CoHpgn",           "HPGN",          "Hpgn",            FALSE},
	{ "CoHpGn",           "HPGN",          "HpGn",            FALSE},
	{ "CoHpGn",           "hpgn",          "HpGn",            FALSE},
	{ "CoHpGn.los",       "hpgn",          "HpGn",            FALSE},
	{ "CoHpGn.LAS",       "HPGN",          "HpGn",            FALSE},
	{ "CoHpGn.XXX",       "hpgn",          "HpGn",            FALSE},
	{ "CoHpGn.XXX",       "h",             "H",               FALSE},
	{ "CoHpGn.XXX",       "q",             "",                TRUE},
	{ "CoHpGn.XXX",       "",              "",                TRUE},
	{ "",                 "Q",             "",                TRUE},

	{ "",                "",                "",               -1}
};
int CSusrCsDef (struct cs_Csdef_ *csPtr,Const char *keyName)
{
	if (!strcmp (keyName,"XXX"))
	{
		strcpy (csPtr->desc_nm,"XXX");
		strcpy (csPtr->source,"Source");
		return 0;
	}
	else if (!strcmp (keyName,"YYY"))
	{
		CS_erpt (cs_NO_MEM);
		return -1;
	}
	return 1;
}
int CSusrDtDef (struct cs_Dtdef_ *dtPtr,Const char *keyName)
{
	if (!strcmp (keyName,"XXX"))
	{
		strcpy (dtPtr->name,"XXX");
		strcpy (dtPtr->source,"Source");
		return 0;
	}
	else if (!strcmp (keyName,"YYY"))
	{
		CS_erpt (cs_NO_MEM);
		return -1;
	}
	return 1;
}

int CSusrElDef (struct cs_Eldef_ *elPtr,Const char *keyName)
{
	if (!strcmp (keyName,"XXX"))
	{
		strcpy (elPtr->name,"XXX");
		strcpy (elPtr->source,"Source");
		return 0;
	}
	else if (!strcmp (keyName,"YYY"))
	{
		CS_erpt (cs_NO_MEM);
		return -1;
	}
	return 1;
}
double CSusrUnit (short type,Const char *unitName)
{
	if (!strcmp (unitName,"XXX"))
	{
		return 17.0;
	}
	if (!strcmp (unitName,"YYY"))
	{
		CS_erpt (cs_NO_MEM);
		return -1.0;
	}
	return 0.0;
}

struct _mgrsTable
{
	char mgrs [16];
	char lat  [16];
	char lng  [16];
};
__ALIGNMENT__16				/* Required by some Sun compilers. */
struct _mgrsTable mgrsTable [] =
{
	{ "11SMV3868748955", "35 40 57.34N","117 40 39.28W" },
	{ "19TDL2756711568", "45 15 13.96N","069 55 23.18W" },
	{ "32VLL1890944323", "58 59 59.96N","005 50 50.04E" },
	{ "33XWF2510946986", "77 00 00.01N","015 59 59.84E" },
	{ "35XMK2635439930", "80 30 00.00N","023 00 00.09E" },
	{ "37XCG8408563319", "77 59 59.99N","033 59 59.94E" },
	{ "41XMK4763094558", "81 00 00.00N","060 00 00.07E" },
	{ "24SWH8779806286", "38 00 00.00N","038 00 00.01W" },
	{ "19FDV3603304750", "55 00 00.01S","069 59 59.97W" },
	{ "56HKH2290933784", "34 00 00.01S","150 00 00.02E" },
	{ "27JWG9645080794", "29 59 59.99S","020 00 00.00W" },
	{ "17NRA2840700034", "00 00 01.11N","078 03 00.00W" },
	{ "04NAF6609900034", "00 00 01.11N","161 59 57.48W" },
	{ "04MHE3300000032", "00 54 11.49S","156 00 30.27W" },
	{ "15XWJ5956055217", "79 45 00.01N","090 00 01.79W" },
	{ "58CDS4043044783", "79 44 59.99S","162 00 00.00E" },
	{ "",                "",            ""              }
};

int CStestH (int verbose,long duration)
{
	extern double cs_Degree;
	extern double cs_ParmTest;		/* .1 seconds of arc in degrees. */

	extern int (*CS_usrCsDefPtr)(struct cs_Csdef_ *ptr,Const char *keyName);
	extern int (*CS_usrDtDefPtr)(struct cs_Dtdef_ *ptr,Const char *keyName);
	extern int (*CS_usrElDefPtr)(struct cs_Eldef_ *ptr,Const char *keyName);
	extern double (*CS_usrUnitPtr)(short type,Const char *unitName);

	int err_cnt;
	int idx;
	int status;
	int length;
	int iStat;
	int msDecPnt,csDecPnt;
	int msSign,csSign;
	size_t strLen;
	long lStat;

	Const char *ptr;
	Const char *csEcvtPtr;
	Const char *msEcvtPtr;
	struct cs_Csdef_ *csPtr;
	struct cs_Dtdef_ *dtPtr;
	struct cs_Eldef_ *elPtr;
	struct _mgrsTable *tblPtr;
	struct cs_Mgrs_ *mgrsPtr;
	
	double testValue;

	double testLatLng [2];
	double rsltLatLng [2];
	double delLatLng [2];
	char rsltMgrs [32];

	printf ("Testing miscellaneous functions\n");
	err_cnt = 0;
	duration *= 2000;

	/* The _ecvt test works fine in the Microsoft environment.  IN the Linux
	   environment, we get discrepancies in the least significant digit for
	   some reason.  Haven't yet figured out a way to verify results in the
	   Linux environment. */
#if _RUN_TIME < _rt_UNIXPCC
	/* The _ecvt function is not ANSI standard, so we had to write our own.
	   This gismo pretty rigorously test our version against the version
	   in the C run time library.  Your C run time library may not have
	   an _ecvt function, but mine does; so we use it to perform the test.
	   In this manner, we can geta very rigorous test with a minimal amount
	   of code. */
	for (idx = 0;idx < duration;idx += 1)
	{
		testValue = CStestRN (-9.999E+20,9.999E+20);
		for (length = 5;length < 18;length += 1)
		{
			msEcvtPtr = _ecvt (testValue,length,&msDecPnt,&msSign);
			csEcvtPtr = CS_ecvt (testValue,length,&csDecPnt,&csSign);
			if (csDecPnt != msDecPnt || csSign != msSign || strcmp (csEcvtPtr,msEcvtPtr))
			{
				err_cnt += 1;
				printf ("CS_ecvt failure on %18.4f, length = %d.\n",testValue,length);
				if (verbose)
				{
					printf ("                CS-MAP (%s :: %d)\n",csEcvtPtr,csDecPnt);
					printf ("                   CRT (%s :: %d)\n",msEcvtPtr,msDecPnt);
				}
			}
			if (err_cnt > 10) break;
		}
		/* Use this to test values less than one. */
		testValue = CStestRN (-1.0,1.0);
		for (length = 5;length < 18;length += 1)
		{
			msEcvtPtr = _ecvt (testValue,length,&msDecPnt,&msSign);
			csEcvtPtr = CS_ecvt (testValue,length,&csDecPnt,&csSign);
			if (csDecPnt != msDecPnt || csSign != msSign || strcmp (csEcvtPtr,msEcvtPtr))
			{
				err_cnt += 1;
				printf ("CS_ecvt failure on %18.4f, length = %d.\n",testValue,length);
				if (verbose)
				{
					printf ("                CS-MAP (%s :: %d)\n",csEcvtPtr,csDecPnt);
					printf ("                   CRT (%s :: %d)\n",msEcvtPtr,msDecPnt);
				}
			}
			if (err_cnt > 10) break;
		}
		if (err_cnt > 10) break;
	}
	/* Zero is a problematical case. */
	testValue = 0.0;
	for (length = 5;length < 18;length += 1)
	{
		msEcvtPtr = _ecvt (testValue,length,&msDecPnt,&msSign);
		csEcvtPtr = CS_ecvt (testValue,length,&csDecPnt,&csSign);
		if (csDecPnt != msDecPnt || csSign != msSign || strcmp (csEcvtPtr,msEcvtPtr))
		{
			err_cnt += 1;
			printf ("CS_ecvt failure on %18.4f, length = %d.\n",testValue,length);
			if (verbose)
			{
				printf ("                CS-MAP (%s :: %d)\n",csEcvtPtr,csDecPnt);
				printf ("                   CRT (%s :: %d)\n",msEcvtPtr,msDecPnt);
			}
		}
		if (err_cnt > 10) break;
	}
#endif

	/* Tests the CS_strnicmp function.  There is no strinicmp function in the
	   ANSI library, so we had to write our own. */
	for (idx = 0;hTable1 [idx].cmpLength >= 0 && err_cnt < 4;idx += 1)
	{
		if (hTable1 [idx].cmpLength > 0)
		{
			status = CS_strnicmp (hTable1 [idx].str1,hTable1 [idx].str2,hTable1 [idx].cmpLength);
		}
		else
		{
			status = CS_stricmp (hTable1 [idx].str1,hTable1 [idx].str2);
		}
		if (((hTable1 [idx].cmpValue <  0) && (status >= 0)) ||
			((hTable1 [idx].cmpValue == 0) && (status != 0)) ||
			((hTable1 [idx].cmpValue >  0) && (status <= 0))
		   )
		{
			printf ("Case insensitive functions failure, index = %d.\n",idx);
			err_cnt += 1;
		}
	}
	for (idx = 0;hTable2 [idx].nullFlag >= 0 && err_cnt < 5;idx += 1)
	{
		strLen = strlen (hTable2 [idx].str3);
		ptr = CS_stristr (hTable2 [idx].str1,hTable2 [idx].str2);
		if (( hTable2 [idx].nullFlag && ptr != NULL) ||
			(!hTable2 [idx].nullFlag && strncmp (ptr,hTable2 [idx].str3,strLen))
		   )
		{
			printf ("Case insensitive functions 2 failure, index = %d.\n",idx);
			err_cnt += 1;
		}
	}

	CS_usrCsDefPtr = CSusrCsDef;
	CS_usrDtDefPtr = CSusrDtDef;
	CS_usrElDefPtr = CSusrElDef;
	CS_usrUnitPtr = CSusrUnit;

	csPtr = CS_csdef ("XXX");
	if (csPtr == NULL || strcmp (csPtr->desc_nm,"XXX"))
	{
		printf ("CS_usrCsDefPtr function failure.\n");
		err_cnt += 1;
	}
	if (csPtr != NULL) CS_free (csPtr);

	csPtr = CS_csdef ("YYY");
	if (csPtr != NULL)
	{
		printf ("CS_usrCsDefPtr function failure.\n");
		err_cnt += 1;
	}
	if (csPtr != NULL) CS_free (csPtr);

	csPtr = CS_csdef ("LL");
	if (csPtr == NULL || strcmp (csPtr->key_nm,"LL"))
	{
		printf ("CS_usrCsDefPtr function failure.\n");
		err_cnt += 1;
	}
	if (csPtr != NULL) CS_free (csPtr);

	dtPtr = CS_dtdef ("XXX");
	if (dtPtr == NULL || strcmp (dtPtr->name,"XXX"))
	{
		printf ("CS_usrDtDefPtr function failure.\n");
		err_cnt += 1;
	}
	if (dtPtr != NULL) CS_free (dtPtr);

	dtPtr = CS_dtdef ("YYY");
	if (dtPtr != NULL)
	{
		printf ("CS_usrDtDefPtr function failure.\n");
		err_cnt += 1;
	}
	if (dtPtr != NULL) CS_free (dtPtr);

	dtPtr = CS_dtdef ("WGS84");
	if (dtPtr == NULL || strcmp (dtPtr->key_nm,"WGS84"))
	{
		printf ("CS_usrDtDefPtr function failure.\n");
		err_cnt += 1;
	}
	if (dtPtr != NULL) CS_free (dtPtr);

	elPtr = CS_eldef ("XXX");
	if (elPtr == NULL || strcmp (elPtr->name,"XXX"))
	{
		printf ("CS_usrElDefPtr function failure.\n");
		err_cnt += 1;
	}
	if (elPtr != NULL) CS_free (elPtr);

	elPtr = CS_eldef ("YYY");
	if (elPtr != NULL)
	{
		printf ("CS_usrElDefPtr function failure.\n");
		err_cnt += 1;
	}
	if (elPtr != NULL) CS_free (elPtr);

	elPtr = CS_eldef ("WGS84");
	if (elPtr == NULL || strcmp (elPtr->key_nm,"WGS84"))
	{
		printf ("CS_usrElDefPtr function failure.\n");
		err_cnt += 1;
	}
	if (elPtr != NULL) CS_free (elPtr);

	if (CS_unitlu (cs_UTYP_LEN,"XXX") != 17.0)
	{
		printf ("CS_usrUnitPtr function failure.\n");
		err_cnt += 1;
	}
	if (CS_unitlu (cs_UTYP_LEN,"YYY") != 0.0)
	{
		printf ("CS_usrUnitPtr function failure.\n");
		err_cnt += 1;
	}
	if (CS_unitlu (cs_UTYP_LEN,"METER") != 1.0)
	{
		printf ("CS_usrUnitPtr function failure.\n");
		err_cnt += 1;
	}

	CS_usrCsDefPtr = NULL;
	CS_usrDtDefPtr = NULL;
	CS_usrElDefPtr = NULL;
	CS_usrUnitPtr = NULL;

	/* Test the MGRS stuff.  We have a table which we got from an
	   external source.  We simply work through the table.  The
	   table is based on WGS84. */
	mgrsPtr = CSnewMgrs (6378137.0,0.00669438000426089,FALSE);
	if (mgrsPtr == NULL)
	{
		printf ("cs_Mgrs_ construction failure.\n");
		err_cnt += 1;
		return (err_cnt);
	}
	for (tblPtr = mgrsTable;tblPtr->mgrs [0] != '\0';tblPtr += 1)
	{
		lStat = CS_atof (&testLatLng [0],tblPtr->lng);
		if (lStat < 0L)
		{
			printf ("MGRS test table internal failure.\n");
			err_cnt += 1;
			continue;
		}
		lStat = CS_atof (&testLatLng [1],tblPtr->lat);
		if (lStat < 0L)
		{
			printf ("MGRS test table internal failure.\n");
			err_cnt += 1;
			continue;
		}

		/* We have a lat/long,  Convert the MGRS string to
		   lat/long, and compare the results. */
		iStat =  CScalcLlFromMgrs (mgrsPtr,rsltLatLng,tblPtr->mgrs);
		if (iStat < 0L)
		{
			printf ("CScalcLlFromMgrs failure.\n");
			err_cnt += 1;
			continue;
		}
		delLatLng [0] = fabs (testLatLng [0] - rsltLatLng [0]); 
		delLatLng [1] = fabs (testLatLng [1] - rsltLatLng [1]);
		testValue = cs_ParmTest / cos (testLatLng [1] * cs_Degree);
		if (delLatLng [0] > testValue || delLatLng [1] > testValue)
		{
			printf ("CScalcLlFromMgrs failure.\n");
			err_cnt += 1;
		}

		/* Convert the lat/long to MGRS and check the result. */
		iStat = CScalcMgrsFromLl (mgrsPtr,rsltMgrs,sizeof (rsltMgrs),testLatLng,5); 
		if (iStat < 0L)
		{
			printf ("CScalcMgrsFromLl failure.\n");
			err_cnt += 1;
			continue;
		}
		if (CS_stricmp (rsltMgrs,tblPtr->mgrs))
		{
			printf ("CScalcMgrsFromLl failure.\n");
			err_cnt += 1;
			continue;
		}
	}
	CS_free (mgrsPtr);

	/* Test the new logging functions. */
	CSnadInit ();
	testLatLng [0] = -105.0;
	testLatLng [1] =   35.0;
	ptr = CSnad27ToNad83Log (testLatLng);
	testLatLng [1] =   55.0;
	ptr = CSnad27ToNad83Log (testLatLng);
	testLatLng [0] = -150.0;
	testLatLng [1] =   65.0;
	ptr = CSnad27ToNad83Log (testLatLng);
	testLatLng [0] = -158.0;
	testLatLng [1] =   21.5;
	ptr = CSnad27ToNad83Log (testLatLng);
	testLatLng [0] =  -66.5;
	testLatLng [1] =   18.0;
	ptr = CSnad27ToNad83Log (testLatLng);
	CSnadCls ();

	CSagd66Init ();
	testLatLng [0] =  145.0;
	testLatLng [1] =  -35.0;
	ptr = CSagd66ToGda94Log (testLatLng);
	testLatLng [0] =  135.0;
	testLatLng [1] =  -20.0;
	ptr = CSagd66ToGda94Log (testLatLng);
	testLatLng [0] =  146.0;
	testLatLng [1] =  -41.0;
	ptr = CSagd66ToGda94Log (testLatLng);
	CSagd66Cls ();

	CSagd84Init ();
	testLatLng [0] =  145.0;
	testLatLng [1] =  -20.0;
	ptr = CSagd84ToGda94Log (testLatLng);
	testLatLng [0] =  125.0;
	testLatLng [1] =  -25.0;
	ptr = CSagd84ToGda94Log (testLatLng);
	CSagd84Cls ();

	/* Test the Geoid height functions. */
	testLatLng [0] = -105.123456789;
	testLatLng [1] = 39.123456789;
	status = CS_geoidHgt (testLatLng,&testValue);
	if (status < 0)
	{
		char errMsg [256];
		CS_errmsg (errMsg,sizeof (errMsg));
		printf ("CS_geoidHgt fatal error at %d. Reason: %s\n",__LINE__,errMsg);
		err_cnt += 1;
	}
	else if (status != 0)
	{
		printf ("CS_geoidHgt range error at %d.\n",__LINE__);
		err_cnt += 1;
	}
	else if (fabs (testValue + 14.795) > 0.0005)	/* Geoid99 numbers */
	{
		printf ("CS_geoidHgt calculation failure at %d (%f).\n",__LINE__,testValue);
		err_cnt += 1;
	}
	testLatLng [0] = -65.123456789;
	testLatLng [1] = 27.123456789;
	status = CS_geoidHgt (testLatLng,&testValue);
	if (status < 0)
	{
		char errMsg [256];
		CS_errmsg (errMsg,sizeof (errMsg));
		printf ("CS_geoidHgt fatal error at %d. Reason: %s\n",__LINE__,errMsg);
		err_cnt += 1;
	}
	else if (status != 0)
	{
		printf ("CS_geoidHgt range error at %d.\n",__LINE__);
		err_cnt += 1;
	}
	else if (fabs (testValue + 47.053) > 0.0005)	/* Geoid99 numbers */
	{
		printf ("CS_geoidHgt calculation failure at %d (%f).\n",__LINE__,testValue);
		err_cnt += 1;
	}
	CS_geoidCls ();

	return (err_cnt);
}
/*
	The following test exercises the WKT routines.  It simply converts
	a coordinate system definition to WKT and then back to our
	own binary interpretation.  We should have what we started with.
*/
int CStestI (int verbose,long duration)
{
	extern struct cs_Grptbl_ cs_CsGrptbl [];
	extern struct cs_Prjtab_ cs_Prjtab [];

	int err_cnt;

	int status;
	enum ErcWktFlavor flavor;

	struct cs_Grptbl_ *tp;
	struct cs_Csgrplst_ *gp;
	struct cs_Csgrplst_ *grp_list;
	struct cs_Prjtab_ *prjPtr;
	struct cs_Prjtab_ *rsltPrjPtr;
	struct cs_Csdef_ *csDefPtr;
	struct cs_Dtdef_ *dtDefPtr;
	struct cs_Eldef_ *elDefPtr;

	char msgBufr [256];
	char csWktBufr [2048];

	struct cs_Csdef_ csDefOriginal;
	struct cs_Csdef_ csDefImported;
	struct cs_Dtdef_ dtDefOriginal;
	struct cs_Dtdef_ dtDefImported;
	struct cs_Eldef_ elDefOriginal;
	struct cs_Eldef_ elDefImported;

	printf ("Using WKT import to check WKT export, flavor = ESRI\n");

	/* As of now, we only do one flavor.  We should loop and do all flavors. */
	flavor = wktFlvrEsri;

	/* Loop through the group table and fetch a linked list
	   for each group.  Count the number in the group and
	   add to the total in the group. */
	err_cnt = 0;
	for (tp = cs_CsGrptbl;tp->group [0] != 0;tp += 1)
	{
		if (err_cnt >= 40)
		{
			printf ("Abandoning test I due to numerous errors.\n");
			break;
		}

		/* We skip the test group, as the test contain some pretty
		   weird stuff. */
		if (!CS_stricmp (tp->group,"TEST")) continue;

		/* Loop through the definitions in this group. */
		CS_csgrp (tp->group,&grp_list);
		for (gp = grp_list;gp != NULL;gp = gp->next)
		{
			csDefPtr = CS_csdef (gp->key_nm);
			if (csDefPtr == NULL)
			{
				printf ("\rCouldn't obtain coordinate system definition for %s.\n",gp->key_nm);
				err_cnt += 1;
				continue;
			}
			memcpy (&csDefOriginal,csDefPtr,sizeof (csDefOriginal));
			CS_free (csDefPtr);
			strcpy (cs_MeKynm,csDefOriginal.key_nm);

			/* Locate the projection in the projection table.  We need this for access
			   to the flag word for this projection. */
			for (prjPtr = cs_Prjtab;prjPtr->code != cs_PRJCOD_END;prjPtr += 1)
			{
				if (!strcmp (csDefOriginal.prj_knm,prjPtr->key_nm)) break;
			}
			if (prjPtr->code == cs_PRJCOD_END) continue;

			/* We skip several projection types which are not generally supported by WKT. */
			if (prjPtr->code == cs_PRJCOD_MODPC ||
				prjPtr->code == cs_PRJCOD_MSTRO ||
				prjPtr->code == cs_PRJCOD_HMLSN ||
				prjPtr->code == cs_PRJCOD_NACYL ||
				prjPtr->code == cs_PRJCOD_TACYL ||
				prjPtr->code == cs_PRJCOD_BPCNC ||
				prjPtr->code == cs_PRJCOD_SSTRO ||
				prjPtr->code == cs_PRJCOD_LMBLG ||
				prjPtr->code == cs_PRJCOD_WCCSL ||
				prjPtr->code == cs_PRJCOD_WCCST ||
				prjPtr->code == cs_PRJCOD_MNDOTT ||
				prjPtr->code == cs_PRJCOD_MNDOTL ||
				prjPtr->code == cs_PRJCOD_SOTRM ||
				prjPtr->code == cs_PRJCOD_HOM2UV ||
				prjPtr->code == cs_PRJCOD_RSKEWO ||
				prjPtr->code == cs_PRJCOD_RSKEWC ||
				prjPtr->code == cs_PRJCOD_HOM1UV ||
				prjPtr->code == cs_PRJCOD_KROVAK ||
				prjPtr->code == cs_PRJCOD_KRVK95 ||
				prjPtr->code == cs_PRJCOD_KRVK951 ||
				prjPtr->code == cs_PRJCOD_MRCATK ||
				prjPtr->code == cs_PRJCOD_TRMERAF ||
				prjPtr->code == cs_PRJCOD_NERTH ||
				prjPtr->code == cs_PRJCOD_OBQCYL ||
				prjPtr->code == cs_PRJCOD_SYS34 ||
				prjPtr->code == cs_PRJCOD_OSTN97 ||
				prjPtr->code == cs_PRJCOD_AZEDE ||
				prjPtr->code == cs_PRJCOD_OSTN02 ||
				prjPtr->code == cs_PRJCOD_SYS34_99 ||
				prjPtr->code == cs_PRJCOD_TRMRKRG ||
				//prjPtr->code == cs_PRJCOD_WINKL ||
				prjPtr->code == cs_PRJCOD_NRTHSRT ||
				prjPtr->code == cs_PRJCOD_LMBRTAF
			   )
			{
				continue;
			}

			if (verbose)
			{
				printf ("Testing WKT import/export using %s.              \r",gp->key_nm);
			}

			/* We do not attempt to convert anything that is cartographically
			   referenced.  Since there is no real WKT specification, we don't
			   know how to encode a definition which is not referenced to a
			   datum. */
			if (csDefOriginal.dat_knm [0] == '\0') continue;

			/* Locate the associated datum and ellipsoid definitions. */
			dtDefPtr = CS_dtdef (csDefOriginal.dat_knm);
			if (dtDefPtr == NULL)
			{
				char errMsg [256];

				CS_errmsg (errMsg,sizeof (errMsg));
				printf ("\rCouldn't obtain datum definition for %s (Reason: %s).\n",csDefOriginal.dat_knm,errMsg);
				err_cnt += 1;
				continue;
			}
			memcpy (&dtDefOriginal,dtDefPtr,sizeof (dtDefOriginal));
			CS_free (dtDefPtr);

			elDefPtr = CS_eldef (dtDefOriginal.ell_knm);
			if (elDefPtr == NULL)
			{
				char errMsg [256];

				CS_errmsg (errMsg,sizeof (errMsg));
				printf ("\rCouldn't obtain ellipsoid definition for %s (Reason: %s).\n",dtDefOriginal.ell_knm,errMsg);
				err_cnt += 1;
				continue;
			}
			memcpy (&elDefOriginal,elDefPtr,sizeof (elDefOriginal));
			CS_free (elDefPtr);

			/* Convert this definition to WKT.  Please note that (currently)
			   we rely on the CScsToWkt function to access the ellipsoid and
			   datum dictionaries to get those eleements which are required. */
			status = CScs2Wkt (csWktBufr,sizeof (csWktBufr),flavor,&csDefOriginal,&dtDefOriginal,&elDefOriginal);
			if (status < 0)
			{
				char errMsg [256];

				err_cnt += 1;
				CS_errmsg (errMsg,sizeof (errMsg));
				printf ("\rCScsToWkt failed on %s; reason given: %s\n",csDefOriginal.key_nm,errMsg);
				continue;
			}

			/* Convert the WKT back to our internal binary form. */
			status = CS_wktToCs (&csDefImported,&dtDefImported,&elDefImported,flavor,csWktBufr);
			if (status < 0)
			{
				char errMsg [256];

				err_cnt += 1;
				CS_errmsg (errMsg,sizeof (errMsg));
				printf ("\rCS_wktToCs failed on %s; reason given: %s\n",csDefOriginal.key_nm,errMsg);
				continue;
			}

			/* We know that an LMTAN will be converted to LM1SP.  So we filter this
			   out here. */
			if (prjPtr->code == cs_PRJCOD_LMTAN)
			{
				for (rsltPrjPtr = cs_Prjtab;rsltPrjPtr->code != cs_PRJCOD_END;rsltPrjPtr += 1)
				{
					if (!strcmp (csDefImported.prj_knm,rsltPrjPtr->key_nm)) break;
				}
				if (rsltPrjPtr->code == cs_PRJCOD_LM1SP)
				{
					CS_stncp (csDefImported.prj_knm,"LMTAN",sizeof (csDefImported.prj_knm));
				}
			}

			/* See if they compare; if not report the error. */
			status = CS_csDefCmp (&csDefOriginal,&csDefImported,msgBufr,sizeof (msgBufr));
			if (status > 0)
			{
				printf ("\rImported version of coordinate system %s does not match original; %s\n",csDefOriginal.key_nm,msgBufr);
				err_cnt += 1;
			}
			status = CS_dtDefCmp (&dtDefOriginal,&dtDefImported,msgBufr,sizeof (msgBufr));
			if (status > 0)
			{
				printf ("\rImported version of datum %s does not match original; %s\n",dtDefOriginal.key_nm,msgBufr);
				err_cnt += 1;
			}
			status = CS_elDefCmp (&elDefOriginal,&elDefImported,msgBufr,sizeof (msgBufr));
			if (status > 0)
			{
				printf ("\rImported version of ellipsoid %s does not match original; %s\n",dtDefOriginal.key_nm,msgBufr);
				err_cnt += 1;
			}

			/* Test CS_wktDictRpl.  Note, all of these definitions came from the dictionary
			   originally, so they should all be replaced. */
			status = CS_wktDictRpl (0,0,0);
			if (status != 0)
			{
				printf ("\rCS_wktDictRpl failed: line %d, status = %d.\n",__LINE__,status);
				err_cnt += 1;
			}
			status = CS_wktDictRpl (&csDefImported,0,0);
			if (status != 4)
			{
				printf ("\rCS_wktDictRpl failed: line %d, status = %d.\n",__LINE__,status);
				err_cnt += 1;
			}
			status = CS_wktDictRpl (0,&dtDefImported,&elDefImported);
			if (status != 3)
			{
				printf ("\rCS_wktDictRpl failed: line %d, status = %d.\n",__LINE__,status);
				err_cnt += 1;
			}

			/* Let's bag it if we have more than 30 errors.  No sense beating a dead horse. */
			if (err_cnt >= 30) break;
		}
		CS_csgrpf (grp_list);
	}
	if (verbose)
	{
		printf ("\r                                                  \n");
	}
	return (err_cnt);
}
int CStestJ (int verbose,long duration)
{
	extern int (*CS_usrCsDefPtr)(struct cs_Csdef_ *ptr,Const char *keyName);
	extern int (*CS_usrDtDefPtr)(struct cs_Dtdef_ *ptr,Const char *keyName);
	extern int (*CS_usrElDefPtr)(struct cs_Eldef_ *ptr,Const char *keyName);

	short flags;
	int status;
	int err_cnt;
	int epsgIndex;
	long epsgCode;

	enum ErcWktFlavor flavor = wktFlvrGeoTiff;

	char *cp;
	const char *msiNamePtr;
	struct cs_Csprm_ *msiCS;
	struct cs_Csprm_ *epsgCS;
	struct cs_Csprm_ *wktCS;
	FILE* wktStream;

	long lineNbr;

	double deltaX;
	double deltaY;

	char csWktBufr [2048];
	char errMesg   [2048];

	double xyz [3];
	double llh [3];
	double msiLlh [3];
	double epsgLlh [3];
	double msiXyz [3];
	double epsgXyz [3];
	double testInput [3];
	double msiResult [3];
	double wktResult [3];

	struct cs_Csdef_ csDef;
	struct cs_Dtdef_ dtDef;
	struct cs_Eldef_ elDef;
	
	printf ("Checking Well Known Text conversions.\n");
	err_cnt = 0;

	epsgIndex = 0;
	while ((epsgCode = CSepsgByIdxCS (epsgIndex++)) > 0)
	{
		msiCS = epsgCS = NULL;
		if (err_cnt >= 40)
		{
			printf ("Abandoning test J due to numerous errors.\n");
			break;
		}

		msiNamePtr = CSepsg2msiCS (epsgCode,&flags);
		if (msiNamePtr == 0) continue;
		if ((flags & 1) != 1)
		{
			/* There was no MSI definition for this system prior to
			   the incorporation of EPSG; so we don't really have
			   anything to check against. */
			continue;
		}

		if (verbose)
		{
			printf ("Comparing %s with %ld.          \r",msiNamePtr,epsgCode);
		}

		/* Test the VB level first. EPSG::23700 projection is not supported by WKT. */
		epsgCode =	CS_msi2epsg (msiNamePtr);
		if (epsgCode == 23700)
		{
			continue;
		}

		status = CS_cs2Wkt (csWktBufr,sizeof (csWktBufr),msiNamePtr,flavor);
		if (status != 0)
		{
			err_cnt += 1;
			CS_errmsg (errMesg,sizeof (errMesg));
			printf ("\rHigh level conversion of %s to WKT failed.  Reason: %s\n",msiNamePtr,errMesg);
		}
		else
		{
			status = CS_wktToCs (&csDef,&dtDef,&elDef,flavor,csWktBufr);
			epsgCS = CScsloc1 (&csDef);
			if (epsgCS == 0)
			{
				err_cnt += 1;
				CS_errmsg (errMesg,sizeof (errMesg));
				printf ("\rCouldn't setup WKT coordinate system.  Reason: %s\n",errMesg);
				continue;
			}
		}
		if (status != 0) continue;

		msiCS = CS_csloc (msiNamePtr);
		if (msiCS == NULL)
		{
			err_cnt += 1;
			CS_free (epsgCS);
			CS_errmsg (errMesg,sizeof (errMesg));
			printf ("\rCouldn't setup coordinate system named %s. Reason: %s\n",msiNamePtr,errMesg);
			continue;
		}

		/* We use the useful range in the MSI definition to compute a suitable
		   pair of x and y coordinates for the test.  (EPSG definitions don't
		   have such information.) */
		llh [0] = msiCS->cent_mer + msiCS->min_ll [0] * 0.65;
		llh [1] = msiCS->min_ll [1] + (msiCS->max_ll [1] - msiCS->min_ll [1]) * 0.65;
		llh [2] = 0.0;
		status = CS_ll2cs (msiCS,xyz,llh);
		if (status != 0)
		{
			printf ("Test J algorithm failure at line %d, CS = %s.\n",__LINE__,msiNamePtr);
			err_cnt += 1;
			CS_free (msiCS);
			CS_free (epsgCS);
			continue;
		}
		
		/* OK, we can now perform the real test. */
		status = CS_cs2ll (msiCS,msiLlh,xyz);
		if (status != 0)
		{
			printf ("\rCouldn't convert %12.3f :: %12.3f to Lat?lng via %s.\n",xyz [0],xyz [1],msiNamePtr);
			err_cnt += 1;
			CS_free (msiCS);
			CS_free (epsgCS);
			continue;
		}
		status = CS_ll2cs (msiCS,msiXyz,msiLlh);
		if (status != 0)
		{
			printf ("\rCouldn't convert %12.6f :: %12.6f to X?Y?Z via %s.\n",llh [0],llh [1],msiNamePtr);
			err_cnt += 1;
			CS_free (msiCS);
			CS_free (epsgCS);
			continue;
		}

		status = CS_cs2ll (epsgCS,epsgLlh,xyz);
		if (status != 0)
		{
			printf ("\rCouldn't convert %12.3f :: %12.3f to Lat?lng via %s.\n",xyz [0],xyz [1],msiNamePtr);
			err_cnt += 1;
			CS_free (msiCS);
			CS_free (epsgCS);
			continue;
		}
		status = CS_ll2cs (epsgCS,epsgXyz,epsgLlh);
		if (status != 0)
		{
			printf ("\rCouldn't convert %12.6f :: %12.6f to X?Y?Z via %s.\n",llh [0],llh [1],msiNamePtr);
			err_cnt += 1;
			CS_free (msiCS);
			CS_free (epsgCS);
			continue;
		}

		/* How did we do? */
		if (fabs (msiXyz [0] - epsgXyz [0]) > 0.0003 ||
			fabs (msiXyz [1] - epsgXyz [1]) > 0.0003 ||
			fabs (msiLlh [0] - epsgLlh [0]) > 0.0000002 ||
			fabs (msiLlh [1] - epsgLlh [1]) > 0.0000002)
		{
			printf ("\rComparison of pre/post WKT of %s failed.\n",msiNamePtr);
			err_cnt += 1;
			continue;
		}
		CS_free (msiCS);	msiCS = NULL;
		CS_free (epsgCS);	epsgCS = NULL;
	}
	
	/* If a file named WktTestFile.wkt exists, we open it and for each entry in
	   the file, we perform the following test:
	   1> Read a WKT definition from the file.
	   2> Parse the WKT definition.
	   3> Extract the WKT (in this case ESRI) name
	   4> Map the ESRI name to an MSI name.
	   5> Get a cs_Csprm_ structure using the MSI name.
	   6> Get a cs_Csprm_ structure from the WKT string.
	   7> Determine a coordinate in the useful range of the definition.
	   8> Convert the point using both definitions.
	   9> Compare the results of the conversion.
	*/
	wktStream = fopen ("WktTest.txt","rt");
	if (wktStream == 0)
	{
		CS_stncp (csWktBufr,test_file,sizeof (csWktBufr));
		cp = strrchr (csWktBufr,'\\');
		if (cp == 0)
		{
			cp = strrchr (csWktBufr,'/');
		}
		if (cp != 0)
		{
			cp += 1;
			strcpy (cp,"WktTest.txt");
			wktStream = fopen (csWktBufr,"rt");
		}
	}
	if (wktStream != 0)
	{

#ifdef __WKT_REPORTS__
		FILE* parseReport = fopen ("ParseReport.txt","wt");
		FILE* mapReport = fopen ("MapReport.txt","wt");
		FILE* msiReport = fopen ("MsiFailures.txt","wt");
		FILE* cmpReport = fopen ("CmpReport.txt","wt");
#endif
		/* Activate the WKT capability for CS_csloc () */
		CS_usrCsDefPtr = CS_wktCsDefFunc;
		CS_usrDtDefPtr = CS_wktDtDefFunc;
		CS_usrElDefPtr = CS_wktElDefFunc;

		/* Read each of the WKT definitions in the test file. */
		wktCS = 0;
		msiCS = 0;
		lineNbr = 0;
		while (fgets (csWktBufr,sizeof (csWktBufr),wktStream) != NULL)
		{
			if (err_cnt >= 100)
			{
				printf ("Abandoning test J at line %ld due to numerous errors.\n",lineNbr);
				break;
			}
			lineNbr += 1;

			/* Convert the WKT string to a coordinate conversion. */
			wktCS = CS_csloc (csWktBufr);
			if (wktCS == 0)
			{
				/* Here if the WKT parse and conversion failed.  If due to a
				   datum mapping failure or an unsupported projection we do not
				   report it at the current time.  This is a test of WKT. */
				if (cs_Error != cs_WKT_DTMAP && cs_Error != cs_WKT_INVPROJ)
				{
#ifdef __WKT_REPORTS__
					CS_errmsg (errMesg,sizeof (errMesg));
					fprintf (parseReport,"WKT parse failed (%ld): %s\n",lineNbr,errMesg);
#endif
					printf ("Parsing WKT definition failed. (WKT = %.48s)\n",csWktBufr);
					CS_errmsg (errMesg,sizeof (errMesg));
					printf ("\tReason: %s\n",errMesg);
					err_cnt += 1;
				}
			}
			else
			{
				/* Map the ESRI name to a Mentor Name. */
				msiNamePtr = CS_esriName2Msi (wktCS->csdef.desc_nm,&flags);
				if (msiNamePtr == 0)
				{
					/* We disable this error at the current time, as it is not
					   a WKT error, but simply means that there are WKT
					   definitions in the test file which we don't have, or
					   which are not being properly mapped by the mapping
					   tables.  The latter case produces most of the
					   instances of the condition being reported here. */
#ifdef __WKT_REPORTS__
					fprintf (mapReport,"Line %ld: Mapping of WKT name '%s' to CS-MAP failed.\n",lineNbr,wktCS->csdef.desc_nm);
#endif
					if (verbose)
					{
						printf ("Mapping of WKT name '%s' to MSI failed.\n",wktCS->csdef.desc_nm);
					}
					CS_free (wktCS);
				}
				else
				{
					msiCS = CS_csloc (msiNamePtr);
					if (msiCS == 0)
					{
#ifdef __WKT_REPORTS__
						fprintf (msiReport,"Line %ld: Name '%s' mapped to CS-MAP name '%s', but %s such did not exist.\n",lineNbr,wktCS->csdef.desc_nm,msiNamePtr,msiNamePtr);
#endif
						printf ("WKT name '%s' mapped to MSI name '%s', but an MSI definition with that name did not exist.\n",wktCS->csdef.desc_nm,msiNamePtr);
						err_cnt += 1;
						CS_free (wktCS);
					}
					else
					{
						/* We have two coordinate systems which are supposed to be
						   the same.  We construct a coordinate that is known to be
						   in the useful range, convert it using both conversions
						   and verify that the two results are the same. */
						testInput [0] = msiCS->cent_mer + msiCS->min_ll [0] * 0.5;
						testInput [1] = msiCS->min_ll [1] + (msiCS->max_ll [1] - msiCS->min_ll [1]) * 0.25;
						testInput [2] = 0.0;
						CS_ll2cs (msiCS,msiResult,testInput);
						CS_ll2cs (wktCS,wktResult,testInput);
						deltaX = fabs (msiResult [0] - wktResult [0]);
						deltaY = fabs (msiResult [1] - wktResult [1]);
						/* Orindarily, I'd use 0.001 (1mm) as the tolerance.
						   However, WKT uses the flattening and EPSG truncates
						   the flattening of the Clarke 1880 (IGN) ellipsoid
						   to the point where is produces an error of about 1.8mm.
						   So, to keep the test from failing due to this, we
						   use a tolerance of 2mm. */
						if (deltaX > 0.002 || deltaY > 0.002)
						{
#ifdef __WKT_REPORTS__
							fprintf (cmpReport,"Line %ld: Comparision of WKT '%s' and CS-MAP '%s' failed.\n",lineNbr,wktCS->csdef.desc_nm,msiNamePtr);
#endif
							printf ("Comparision of WKT '%s' and MSI '%s' failed.\n",wktCS->csdef.desc_nm,msiNamePtr);
							err_cnt += 1;

							// For debugging convenience.
							CS_ll2cs (msiCS,msiResult,testInput);
							CS_ll2cs (wktCS,wktResult,testInput);
						}
						CS_free (wktCS);
						CS_free (msiCS);
					}
				}
			}
		}
		fclose (wktStream);
		CS_usrCsDefPtr = 0;
		CS_usrDtDefPtr = 0;
		CS_usrElDefPtr = 0;
	}
	return err_cnt;
}
void CStestSa (const char *swp_name)
{
	printf ("Swapping contents of %s now.\n",swp_name);
	return;
}
int CStestS (int verbose)
{
	extern char cs_Dir [];
	extern char *cs_DirP;
	extern char cs_Csname [];
	extern union cs_Bswap_ cs_BswapU;

	int st;
	size_t rdCnt;

	csFILE *strm;

	char magic [sizeof (cs_magic_t)];
	
	printf ("Switching byte order in all files for subsequent tests.\n");

	/* Now we force CS_swap into swap mode. */
	cs_BswapU.llll = 0x010203L;

	st = 0;	
#if _RUN_TIME < _rt_UNIXPCC
	/* It appears that there are problems with the directory tree scan stuff
	   under UNIX.  Mentor hasn't had a UNIX box since my Unix PC died.
	   So, we simply comment this out for now. */
	/* Swap all the files. */
	if (verbose)
	{
		st = CS_swpal (CStestSa);
	}
	else
	{
		st = CS_swpal (NULL);
	}
#endif
	
	/* Now we set CS_bswap to operate correctly with the results;
	   regardless of what type of machine we are on. In order to do
	   this, we determine the current state of the binary files.
	   This may be the same as before if CS_swpal had some sort of
	   problem. */
	(void)strcpy (cs_DirP,cs_Csname);
	strm = CS_fopen (cs_Dir,_STRM_BINRD);
	if (strm == NULL)
	{
		st = cs_CSDICT;
	}
	else
	{
		rdCnt = CS_fread (&magic,1,sizeof (magic),strm);
		CS_fclose (strm);
		if (rdCnt != sizeof (magic))
		{
			st = CS_ferror (strm) ? cs_IOERR : cs_INV_FILE;
		}
		else
		{
			if (magic [0] != '\200')
			{
				/* Little endian order. */
				cs_BswapU.cccc [0] = 0x00;
				cs_BswapU.cccc [1] = 0x01;
				cs_BswapU.cccc [2] = 0x02;
				cs_BswapU.cccc [3] = 0x03;
			}
			else
			{
				/* Little endian order. */
				cs_BswapU.cccc [0] = 0x03;
				cs_BswapU.cccc [1] = 0x02;
				cs_BswapU.cccc [2] = 0x01;
				cs_BswapU.cccc [3] = 0x00;
			}
		}
	}
	return (st);
}

double CStestRN (double low, double high)

{
	unsigned irand;

	double rrand;

	irand = rand ();
	rrand = low + (high - low) * ((double)irand / (double)RAND_MAX);
	return (rrand);
}

/*
	The following function calculates the K scale factor, i.e.
	grid scale along a parallels. For the algorithm in use, see
	Synder/Bugayevskiy, page 18. They call it "n".
*/

double CStstsclk (struct cs_Csprm_ *csprm,double ll [2])

{
	extern double cs_One;
	extern double cs_Mone;
	extern double cs_Degree;
	extern double cs_MaxLatFz;

	int status;

	double N;
	double kk;
	double lat;
	double tmp;
	double delta;
	double cos_lat;
	double del_xx;
	double del_yy;
	double e_rad;
	double ecent;

	double xy1 [3];
	double xy2 [3];
	double my_ll [3];

	/* K is not defined at the poles. */

	if (fabs (ll [LAT]) >= cs_MaxLatFz)
	{
		return (cs_Mone);
	}

	my_ll [LNG] = ll [LNG];
	my_ll [LAT] = ll [LAT];

	lat = my_ll [LAT] * cs_Degree;
	cos_lat = cos (lat);

	/* Since the actual magnitude of longitude varies with
	   latitude, we adjust the "infinitesimal" delta which
	   we use to simulate the partial deriviative by the
	   cosine of the latitude. */

	delta = 0.00005 / cos_lat;

	my_ll [LNG] -= delta;
	status = CS_ll2cs (csprm,xy1,my_ll);
	if (status != cs_CNVRT_NRML)
	{
		return (cs_Mone);
	}
	my_ll [LNG] += (delta + delta);
	status = CS_ll2cs (csprm,xy2,my_ll);
	if (status != cs_CNVRT_NRML)
	{
		return (cs_Mone);
	}
	del_xx = (xy2 [XX] - xy1 [XX]);
	del_yy = (xy2 [YY] - xy1 [YY]);

	/* e_rad is the equatorial radius in system units. */

	e_rad = csprm->datum.e_rad * csprm->csdef.scale;
	ecent = csprm->datum.ecent;

	if (ecent == 0.0 || (csprm->prj_flags & cs_PRJFLG_ELLIPS) == 0)
	{
		/* Here if the reference ellipsoid is actually a
		   sphere, or the projection is defined for the
		   sphere only. */

		N = e_rad;
	}
	else
	{
		/* Need to take the ellipsoid into account. */

		tmp = ecent * sin (lat);
		N = e_rad / sqrt (cs_One - tmp * tmp);
	}
	N *= 2.0 * delta * cs_Degree;

	kk = sqrt (del_xx * del_xx + del_yy * del_yy) / (N * cos_lat);
	return (kk);
}

/*
	The following function calculates the H scale factor, i.e.
	grid scale along a meridian.  See Synder/Bugayevskiy, page 17.
	They call it "m".
*/

double CStstsclh (struct cs_Csprm_ *csprm,double ll [2])

{
	extern double cs_One;
	extern double cs_Mone;
	extern double cs_Degree;

	int status;

	double M;
	double hh;
	double lat;
	double tmp;
	double del_xx;
	double del_yy;
	double e_rad;
	double ecent;

	double xy1 [3];
	double xy2 [3];
	double my_ll [3];

	my_ll [LNG] = ll [LNG];
	my_ll [LAT] = ll [LAT];

	lat = my_ll [LAT] * cs_Degree;

	my_ll [LAT] -= 0.00005;
	status = CS_ll2cs (csprm,xy1,my_ll);
	if (status != cs_CNVRT_NRML)
	{
		return (cs_Mone);
	}
	my_ll [LAT] += 0.0001;
	status = CS_ll2cs (csprm,xy2,my_ll);
	if (status != cs_CNVRT_NRML)
	{
		return (cs_Mone);
	}
	del_xx = (xy2 [XX] - xy1 [XX]);
	del_yy = (xy2 [YY] - xy1 [YY]);

	/* e_rad is the equatorial radius in system units. */

	e_rad = csprm->datum.e_rad * csprm->csdef.scale;
	ecent = csprm->datum.ecent;

	if (ecent == 0.0 || (csprm->prj_flags & cs_PRJFLG_ELLIPS) == 0)
	{
		/* Here if the reference ellipsoid is actually a
		   sphere, or the projection is defined for the
		   sphere only. */

		M = e_rad;
	}
	else
	{
		/* Need to take the ellipsoid into account. */

		tmp = ecent * sin (lat);
		tmp = cs_One - tmp * tmp;
		M = e_rad * (cs_One - (ecent * ecent)) / (tmp * sqrt (tmp));
	}
	M *= 0.0001 * cs_Degree;

	hh = sqrt (del_xx * del_xx + del_yy * del_yy) / M;
	return (hh);
}

double CStstcnvrg (struct cs_Csprm_ *csprm,double ll [2])

{
	extern double cs_Km360;
	extern double cs_Radian;

	int status;

	double del_xx;
	double del_yy;
	double gamma;

	double xy1 [3];
	double xy2 [3];
	double my_ll [3];

	my_ll [LNG] = ll [LNG];
	my_ll [LAT] = ll [LAT];

	my_ll [LAT] -= 0.00005;
	status = CS_ll2cs (csprm,xy1,my_ll);
	if (status != cs_CNVRT_NRML)
	{
		return (cs_Km360);
	}
	ll [LAT] += 0.0001;
	status = CS_ll2cs (csprm,xy2,my_ll);
	if (status != cs_CNVRT_NRML)
	{
		return (cs_Km360);
	}

	del_xx = xy2 [0] - xy1 [0];
	del_yy = xy2 [1] - xy1 [1];
	if ((fabs (del_xx) + fabs (del_yy)) > 0.0)
	{
		gamma = -atan2 (del_xx,del_yy) * cs_Radian;
	}
	else
	{
		gamma = cs_Km360;
	}
	return (gamma);
}

/* I thought matherrr was ANSI standard.  Maybe it isn't, as the code below
   does not appear to compile in all Unix environments. */
#if _RUN_TIME < _rt_UNIXPCC
#	if defined (_MSC_VER)
		int matherr (struct _exception *except)
#	else
		int matherr (struct exception *except)
#	endif
{
	extern int cs_MeFlag;
	extern char cs_MeKynm [];
	extern char cs_MeFunc [];
	extern double cs_Coords [3];

	char *type;

	cs_MeFlag = 1;
	switch (except->type) {
	case DOMAIN:
		type = "Domain";
		break;
	case SING:
		type = "Singularity";
		break;
	case OVERFLOW:
		type = "Overflow";
		break;
	case PLOSS:
		type = "Precision loss";
		break;
	case TLOSS:
		type = "Precision loss";
		break;
	case UNDERFLOW:
		type = "Underflow";
		break;
	default:
		type = "Unknown";
		break;
	}
	printf ("Math Error produced by %s :: %s %s(%g) [%s(%g:%g:%g)].\n",
				cs_MeKynm,
				type,
				except->name,
				except->arg1,
				cs_MeFunc,
				cs_Coords [0],
				cs_Coords [1],
				cs_Coords [2]);
	return (1);
}
#endif

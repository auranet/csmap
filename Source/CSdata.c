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

			 File Name: $RCSfile: CSdata.c $
		   Description:
			   Purpose:

		Revision Level:	$Revision: #7 $
		 Check In Date:	$Date: 2007/01/15 $

		Last Revision:	$Log: CSdata.c $
		Last Revision:	Revision 11.1300  2005/05/25 23:27:03  nto
		Last Revision:	Official Release 11.13
		Last Revision:	Revision 11.1201  2005/05/25 00:36:32  nto
		Last Revision:	Added cs_Diagnostic variable.
		Last Revision:	Revision 11.1200  2005/01/15 18:27:07  nto
		Last Revision:	Official Release of CS-MAP 11.12, 11:26am 15 Jan 2005
		Last Revision:	Revision 11.1101  2005/01/15 07:09:23  nto
		Last Revision:	Revision 11.1100  2004/11/01 18:53:04  nto
		Last Revision:	Official release 11.11
		Last Revision:	Revision 11.1001  2004/10/07 19:25:13  nto
		Last Revision:	Revision 11.902  2004/08/27 04:47:09  nto
		Last Revision:	Added four new groups for the EPSG stuff
		Last Revision:	Revision 11.901  2004/08/07 20:51:14  nto
		Last Revision:	Added global variables for the dictionary deferred close feature.
		Last Revision:	Revision 11.900  2004/03/26 17:02:20  nto
		Last Revision:	Official release: 11.09 - 3/25/2003
		Last Revision:	Revision 11.800  2004/01/13 23:29:08  nto
		Last Revision:	Revision 11.702  2004/01/13 20:39:43  nto
		Last Revision:	Update to 11.08 revision level.
		Last Revision:	Revision 11.701  2003/12/19 02:10:18  nto
		Last Revision:	Opps!! Forgot to change the release level.
		Last Revision:	Revision 11.700  2003/12/19 01:49:48  nto
		Last Revision:	Official release 11.07
		Last Revision:	Revision 11.600  2003/12/04 02:46:23  nto
		Last Revision:	Release 11.06.  Never shipped. Source captured in prep for C++ V7.
		Last Revision:	Revision 11.502  2003/11/07 03:58:28  nto
		Last Revision:	Added some groups for WKT and EPSG.
		Last Revision:	Revision 11.501  2003/08/22 21:12:51  nto
		Last Revision:	Official Release: 11.05
		Last Revision:	Revision 11.402  2003/08/22 20:54:44  nto
		Last Revision:	Added the new CS-csRangeEnum feature.
		Last Revision:	Revision 11.401  2003/05/01 23:06:18  nto
		Last Revision:	Revision 11.303  2003/04/29 00:22:33  nto
		Last Revision:	Updated release number.
		Last Revision:	Revision 11.302  2003/04/28 22:41:30  nto
		Last Revision:	Adjusted the GDC table to allow a .gdc file in the Nad27ToCsrs file.
		Last Revision:	Revision 11.301  2003/03/23 23:45:18  nto
		Last Revision:	Added the French thing to the GDC table, and fixed the VertCon entry.
		Last Revision:	Revision 11.300  2003/02/25 04:29:12  nto
		Last Revision:	Official Release 11.03
		Last Revision:	Revision 11.102  2003/02/22 00:08:51  nto
		Last Revision:	Update to release 11.03
		Last Revision:	Revision 11.101  2002/12/17 04:08:22  nto
		Last Revision:	Update release level to 11.02.
		Last Revision:	Revision 11.100  2002/11/22 19:38:39  nto
		Last Revision:	Official release: 11.01
		Last Revision:	Revision 10.1503  2002/11/08 20:21:30  nto
		Last Revision:	Revision 10.1502  2002/11/06 23:56:28  nto
		Last Revision:	Added support for the gdcEditor, and some changes to support UNIX compilation.
		Last Revision:	Revision 10.1501  2002/10/23 22:54:54  nto
		Last Revision:	Moved the cs_Safe to this module.
		Last Revision:	Revision 10.1500  2002/09/22 00:01:15  nto
		Last Revision:	Official Release:= 10.15
		Last Revision:	Revision 10.1402  2002/09/17 23:27:48  nto
		Last Revision:	Added the name for the Nad27ToAts77.gdc file.
		Last Revision:	Revision 10.1401  2002/09/15 21:22:20  nto
		Last Revision:	Added .gdc file names for NAD27<-->CSRS and ED50<-->ETRF89
		Last Revision:	Revision 10.1400  2002/08/09 18:14:18  nto
		Last Revision:	Revision 10.1201  2002/07/23 04:49:51  nto
		Last Revision:	Release 10.13
		Last Revision:	Revision 10.1200  2002/07/14 03:26:10  nto
		Last Revision:	Revision 10.1101  2002/06/20 17:58:31  nto
		Last Revision:	New release level (10.12)
		Last Revision:	Revision 10.1100  2002/06/13 14:18:32  nto
		Last Revision:	Release 10.11 Official
		Last Revision:	Revision 10.1001  2002/04/18 21:06:14  nto
		Last Revision:	Added the elevated ellipsoid parameter limits.
		Last Revision:	Revision 10.1000  2002/02/23 21:18:23  nto
		Last Revision:	Official Release of 10.10, 2/22/02 - Norm Olsen
		Last Revision:	Revision 10.901  2002/02/19 05:35:55  nto
		Last Revision:	Added a name for the JGD2k Datum Catalog.
		Last Revision:	Revision 10.900  2001/09/24 04:31:07  nto
		Last Revision:	Revision 10.701  2001/09/18 19:01:08  nto
		Last Revision:	Changed the Molodensky/7 Parameter mmaximum values
		Last Revision:	to accomodate the Swedish test case.
		Last Revision:	Revision 10.700  2001/01/25 04:13:41  nto
		Last Revision:	Revision 10.601  2001/01/25 04:05:47  nto
		Last Revision:	Some minot changes to support the new MSI protection scheme.
		Last Revision:	Revision 10.600  2000/12/11 06:39:35  nto
		Last Revision:	Release 10.06
		Last Revision:	Revision 10.501  2000/12/11 05:34:29  nto
		Last Revision:	Added the cs_Wgs84Ptr stuff.
		Last Revision:	Revision 10.500  2000/10/27 07:38:13  nto
		Last Revision:	Official Release 10.05
		Last Revision:	Revision 10.401  2000/10/27 03:47:57  nto
		Last Revision:	Removed attempt to export the hook function pointers.  Didn't
		Last Revision:	seem to work.  Also added support for the high level geocentric
		Last Revision:	and MGRS facilities.
		Last Revision:	Revision 10.400  2000/09/13 01:16:47  nto
		Last Revision:	Release 10.04
		Last Revision:	Revision 10.301  2000/09/12 21:20:49  nto
		Last Revision:	Changed cs_RotMax to 120, and added data catalog file name for CSRS.
		Last Revision:	Revision 10.300  2000/04/04 23:18:18  nto
		Last Revision:	Revision 10.201  2000/04/03 21:44:19  nto
		Last Revision:	Added the LEGACY coordinate system group.
		Last Revision:	Revision 10.200  2000/03/02 18:51:11  nto
		Last Revision:	Revision 10.3  2000/02/11 06:18:56  nto
		Last Revision:	Added the slash to the allowable characters in key names.  Added the names of the new Geodetic Data Catalogs.
		Last Revision:	Revision 10.2  2000/01/31 00:15:25  nto
		Last Revision:	Added hook function definitions.  Changed type of cs_Doserr to unsigned long.  Added coordinate system group named Canada, changed release level in copyright statement. 
		Last Revision:	Revision 10.1  1999/11/03 23:41:08  nto
		Last Revision:	Results of datum conversion rewrite.
		Last Revision:	Revision 10.0  1999/10/05 18:27:10  nto
		Last Revision:	Revision 9.99  1999/10/05 17:36:21  nto
		Last Revision:	Revision 1.2  1999/09/10 18:12:10  nto
		Last Revision:	This revision compiles, links, and generates a successful test program.

******************************************************************************/

#ifdef LABEL_MODULE
static char revlvl [] = {"$Id: //depot/Libraries/CsMap/current/src/CSdata.c#7 $"};
#endif

#include "cs_map.h"

/*
	The following defines and declarations are used to
	access the various data files required by CS_MAP.

	NOTE:  cs_DirP MUST point to the terminating null
	character of the string contained in the cs_Dir
	array.  cs_Dir MUST end with a directory separation
	character.  If you modify the initialization of
	cs_Dir, YOU MUST ALSO MODIFY THE INITIALIZATION OF
	cs_DirP.
*/

#if _RUN_TIME < _rt_UNIXPCC
char cs_DirK [260] = "C:\\MAPPING\\";
csThread char cs_Dir [260] = "";
csThread char *cs_DirP = NULL;
char cs_DirsepC = '\\';
char cs_ExtsepC = '.';
char cs_OptchrC = '/';
#else
char cs_DirK [512] = "/usr/mapping/data/";
char cs_Dir [512] = "/usr/mapping/data/";
char *cs_DirP = cs_Dir + 18;
char cs_DirsepC = '/';
char cs_ExtsepC = '.';
char cs_OptchrC = '-';
#endif

/*
	The following are used in CS_atof and CS_ftoa for the
	conversion of numbers to/from ASCII.  Modify as appropriate
	for the current locale.
*/

char cs_DecpntC = '.';
char cs_DigsepC = ',';
char cs_RatioC  = ':';
char cs_LngDir [6] = "EeWw";
char cs_LatDir [6] = "NnSs";

/*
	The following array contains the set of characters which
	are considered valid for coordinate system, datum, and
	ellipsoid key names. The test occurs in the CS_nampp function.

	Note, as of Release 8, we allow a space character. The
	name preprocessor, CS_nampp, will flag a double space as
	an error, however. Also, as of release 8, we no longer
	convert key names to upper case. However, all comparisions
	remain case Insensitive.

	As of Release 9, all alpha numeric characters are tested by
	hard code in the CS_nampp module.  This string now only
	contains the special characters (i.e. non-alphanumeric)
	which are allowed.  Note that cs_Unique need not be included
	in this string. Include a space in this string if you want to
	support spaces in key names.  CS_nampp will enforce a
	restriction which does not allow two consectuive spaces.
	If the underscore is included in this list, it will be
	considered acceptable as the first alphanumeric in a key name.
*/

Const char cs_Nmchset [32] = " _-$:.;~/";

/*
	As of release 5.0, the names of the Coordinate System, Datums,
	and Elipsoid dictionaries are maintained here. Should your
	application desire to use names other than the standard names
	which all Mentor products use, you may change them here and
	recompile or use the CS_csnam, CS_dtnam, or CS_elnam functions.
	Of course, you could just copy to these global variables, but
	the function interface provides a bit more insulation from
	future changes in the system.
*/

csThread char cs_Csname  [cs_FNM_MAXLEN]      = cs_CS_NAME;
csThread char cs_Dtname  [cs_FNM_MAXLEN]      = cs_DAT_NAME;
csThread char cs_Elname  [cs_FNM_MAXLEN]      = cs_ELL_NAME;
csThread char cs_Envvar  [cs_FNM_MAXLEN]      = cs_ENV_VAR;

csThread char cs_NadName     [cs_FNM_MAXLEN]  = cs_NAD_NAME;
csThread char cs_HarnName    [cs_FNM_MAXLEN]  = cs_HARN_NAME;
csThread char cs_GeoidName   [cs_FNM_MAXLEN]  = cs_GEOID_NAME;
csThread char cs_VertconName [cs_FNM_MAXLEN]  = cs_VERTCON_NAME;
csThread char cs_Agd66Name   [cs_FNM_MAXLEN]  = cs_AGD66_NAME;
csThread char cs_Agd84Name   [cs_FNM_MAXLEN]  = cs_AGD84_NAME;
csThread char cs_Nzgd49Name  [cs_FNM_MAXLEN]  = cs_NZGD49_NAME;
csThread char cs_Ats77Name   [cs_FNM_MAXLEN]  = cs_ATS77_NAME;
csThread char cs_CsrsName    [cs_FNM_MAXLEN]  = cs_CSRS_NAME;
csThread char cs_Csrs27Name  [cs_FNM_MAXLEN]  = cs_CSRS27_NAME;
csThread char cs_Jgd2kName   [cs_FNM_MAXLEN]  = cs_JGD2K_NAME;
csThread char cs_Ed50Name    [cs_FNM_MAXLEN]  = cs_ED50_NAME;
csThread char cs_DhdnName    [cs_FNM_MAXLEN]  = cs_DHDN_NAME;
csThread char cs_N27A77Name  [cs_FNM_MAXLEN]  = cs_N27A77_NAME;
csThread char cs_Rgf93Name   [cs_FNM_MAXLEN]  = cs_RGF93_NAME;

/*
	The following array supports the enumerator for GDC file
	names.  This is used in the GDC file editor.  Adding a new
	file to this array will, essentially, add it to the
	GDC File Editor.

	This array is also used for the functions which enable
	applications to change the default names.  While
	applications can modify the global variables directly,
	this is no longer recommended.  When connvenient,
	change your application to use the new name change
	functions.

	Note, that gdcFileNone marks the end of the table.
*/
struct cs_GdcCatalogTable_ cs_GdcCatalogTable [] =
{
	{  gdcFileNad27ToNad83, cs_NadName    ,	gdcTypeHorizontal,    0UL, ".las.los.gsb.dac","NADCON files (*.l?s)|*.l?s|Canadian Ntv2 (*.gsb)|*.gsb|Canadian Ntv1 (*.dac)|*.dac||"},
	{   gdcFileNad83ToHarn, cs_HarnName   ,	gdcTypeHorizontal,    0UL, ".las.los"        ,"NADCON files (*.l?s)|*.l?s||"              },
	{  gdcFileAgd66ToGda94, cs_Agd66Name  ,	gdcTypeHorizontal,    0UL, ".gsb"            ,"Canadian Ntv2 format (*.gsb)|*.gsb||"      },
	{  gdcFileAgd84ToGda94, cs_Agd84Name  ,	gdcTypeHorizontal,    0UL, ".gsb"            ,"Canadian Ntv2 format (*.gsb)|*.gsb||"      },
	{gdcFileNzgd49ToNzgd2K, cs_Nzgd49Name ,	gdcTypeHorizontal,    0UL, ".gsb"            ,"Canadian Ntv2 format (*.gsb)|*.gsb||"      },
	{   gdcFileAts77ToCsrs, cs_Ats77Name  ,	gdcTypeHorizontal,    0UL, ".gsb"            ,"Canadian Ntv2 format (*.gsb)|*.gsb||"      },
	{   gdcFileNad83ToCsrs, cs_CsrsName   ,	gdcTypeHorizontal,    0UL, ".gsb"            ,"Canadian Ntv2 format (*.gsb)|*.gsb||"      },
	{  gdcFileTokyoToJgd2k, cs_Jgd2kName  ,	gdcTypeHorizontal,    0UL, ".gsb"            ,"Japanese Grid format (*.par)|*.par||"      },
	{   gdcFileNad27ToCsrs, cs_Csrs27Name ,	gdcTypeHorizontal,    0UL, ".gsb.gdc"        ,"Canadian Ntv2 format (*.gsb)|*.gsb|Ats77 Geodetic Data Catalog (*.gdc)|*.gdc||"},
	{  gdcFileEd50ToEtrf89, cs_Ed50Name   ,	gdcTypeHorizontal,    0UL, ".gsb"            ,"Canadian Ntv2 format (*.gsb)|*.gsb||"      },
	{  gdcFileDhdnToEtrf89, cs_DhdnName   ,	gdcTypeHorizontal,    0UL, ".gsb"            ,"Canadian Ntv2 format (*.gsb)|*.gsb||"      },
	{  gdcFileNad27ToAts77, cs_N27A77Name ,	gdcTypeHorizontal,    0UL, ".gsb"            ,"ATS77 Transform files (*.DAT)|*.DAT"       },
	{   gdcFileGeoidHeight, cs_GeoidName  ,	gdcTypeSeparation,    0UL, ".geo.bin.byn.txt","Geoid96 (*.geo)|*.geo|Geoid99 (*.bin)|*.bin|Canadian (*.byn)|*.byn|UK OSGM91 (*.txt)|*.txt||"},
	{       gdcFileVertcon, cs_VertconName,	gdcTypeVertical,      0UL, ".94"             ,"Vertcon files (*.94)|*.94||"               },
	{    gdcFileNtfToRgf93, cs_Rgf93Name  ,	gdcTypeHorizontal,    0UL, ".txt"             ,"French IGN Datum Shift Files (*.txt)|*.txt|All Files (*.*)|*.*||"},
	{          gdcFileNone, 0             ,	gdcTypeNone,          0UL, ""                ,""                                          }
};

/*
	The following arrays are used to process default values
	for datums, ellipsoids, and units.  The value assigned,
	the null string, says that the specific feature is
	inactive.
*/
csThread char csDtDflt [32] = "";	/* The current default datum. */
csThread char csElDflt [32] = "";	/* The current default ellipsoid. */
csThread char csLuDflt [32] = "";	/* The current default linear unit. */
csThread char csAuDflt [32] = "";	/* The current default angular unit. */

/*
	The following are used to control the dictionary protection
	scheme. cs_Unique is a character which must appear in a
	user defined dictionary key name, one which the system
	manufacturer (i.e. Mentor and/or you) will never use.  Disable
	this feature by setiing cs_Unique to '\0'.

	cs_Protect controls the protection of distribution coordinate
	systems and user defined systems.  Set cs_Protect to -1 to
	disable all protection. Set cs_Protect to 0 to enable
	distribution protection, but disable user coordinate system
	protection.  If cs_Protect is positive and non-zero, it is
	taken to mean that user coordinate systems are protected
	after remaining unaltered for that number of days.

	In the standard distribution, all protection is enabled.
*/

char cs_Unique = ':';
short cs_Protect = 60;
int cs_Safe = 1;

/*
	The following variables are used to keep the three dictionary files open
	during normal operation.  It has been found that certain virus checking
	programs incur a substantial performance penalty for each file open.
	Thus, the policy of opening, and then closing, teh dictionary files on
	each access caused a dreadful situation.
	
	The opening and closing business has been in CS-MAP since its inception,
	this being when on both MNS-DOS and UNIX the number of files which could
	be open simultaneously was severly limited (i.e. like 8 on MS-DOS and 20
	for a UNIX process, and 100 for an entire UNIX system).
	
	Now, a dictionary search will cause the dictionary file to be opened,
	and it will be left open until an update, or delete, operation is
	requested.  After such an operation, the next search will cause the
	file to be open (and left open) again.
	
	For each stream, there is a flag.  The above described operation is
	suppressed if the flag is TRUE, which is the initial state.
*/
csThread short cs_CsStrmFlg = FALSE;
csThread short cs_DtStrmFlg = FALSE;
csThread short cs_ElStrmFlg = FALSE;

csThread csFILE* cs_CsStream = 0;
csThread csFILE* cs_DtStream = 0;
csThread csFILE* cs_ElStream = 0;

/*
	The following are used to communicate certain information
	between modules without overloading the calling sequence
	of the functions involved.
*/

#if _MEM_MODEL == _mm_VIRTUAL || _MEM_MODEL == _mm_FLAT
csThread int cs_Sortbs = 128 * 1024;
#else
csThread int cs_Sortbs = 24 * 1024;
#endif
csThread int cs_Error = 0;
csThread int cs_Errno = 0;
csThread int csErrlng = 0;
csThread int csErrlat = 0;
csThread unsigned short cs_ErrSup = 0;
#if _RUN_TIME <= _rt_UNIXPCC
csThread unsigned long cs_Doserr = 0;
#endif

/* The following should be left assigned to zero.  When this variable is
   non-zero, it is assumed to point to a a valid stream, and diagnostic
   information is written to the stream.
*/
csFILE* csDiagnostic = 0;

/*
	The following points are used in the High Performance
	Interface. We define them here, so that CS_init can
	initialize them, without forcing the code of the
	High Performance Interface.
*/

csThread struct csCscach_ *csCscachP = NULL;
csThread int csCscachI = cs_CSCACH_MAX;
csThread struct csDtcach_ *csDtcachP = NULL;
csThread int csDtcachI = cs_DTCACH_MAX;

csThread char *cs_CsKeyNames = NULL;
csThread char *cs_DtKeyNames = NULL;
csThread char *cs_ElKeyNames = NULL;
csThread char *cs_CsLlEnum = NULL;
csThread struct cs_Csgrplst_ *cs_CsGrpList = NULL;

/* Used for high level MGRS access. */
csThread struct cs_Mgrs_ *cs_MgrsPtr = NULL;

/* Used for geocentric coordinate calculations. */
csThread double csGeoCtrErad = 0.0;
csThread double csGeoCtrEsq = 0.0;

/* Note: several functions assume that csErrnam is dimensioned
   at MAXPATH (i.e. a minimum value). */
   
csThread char csErrnam [MAXPATH] = "???";
csThread char csErrmsg [256] = "???";

/**********************************************************************
	Hook function pointers.  Set to NULL to deativate.
**********************************************************************/

/*
	The following group of hook functions are called prior to actual
	fetching of the related definition from the dictionaries/tables.
	They have been implemented to support dynamically created (temporary)
	definitions.
*/
int (*CS_usrCsDefPtr)(struct cs_Csdef_ *csDef,Const char *keyName) = NULL;
int (*CS_usrDtDefPtr)(struct cs_Dtdef_ *dtDef,Const char *keyName) = NULL;
int (*CS_usrElDefPtr)(struct cs_Eldef_ *elDef,Const char *keyName) = NULL;
double (*CS_usrUnitPtr)(short type,Const char *unitName) = NULL;
/*
	The following hook functions are called after the definition has been read,
	but before any default processing.
*/
int (*cs_CsHook)(struct cs_Csdef_ *csdef,unsigned short prj_code,unsigned long prj_flags) = NULL;
int (*cs_DtHook)(struct cs_Dtdef_ *dtdef) = NULL;

/*
	The following constants are used throughout CS_MAP.
	They are declared here, once, to reduce data space
	requirements of the package.  Variables, rather
	than literals, are used to reduce code space and
	improve performance.
*/

Const double cs_Pi       = PI;			/*  3.14159..... */
Const double cs_Mpi      = -PI;			/* -3.14159..... */
Const double cs_Two_pi   = (2.0 * PI);		/*  6.28218..... */
Const double cs_Three_pi = (3.0 * PI);		/*  9.424777.... */
Const double cs_3Pi_o_2  = (3.0 * PI / 2.0);	/*  3 pi over 2  */
Const double cs_Pi_o_2   = PI_OVR_2;		/*  PI / 2.0     */
Const double cs_Mpi_o_2  = -PI_OVR_2;		/*  -PI / 2.0    */
Const double cs_Pi_o_3   = (PI / 3.0);		/*  PI / 3.0     */
Const double cs_Pi_o_4   = PI_OVR_4;		/*  PI / 4.0     */
Const double cs_Mpi_o_4  = -PI_OVR_4;		/*  PI / 4.0     */
Const double cs_Radian   = RADIAN;		/* 57.29577..... */
Const double cs_Degree   = ONE_DEGREE;		/* 1.0 / RADIAN  */
Const double cs_Mone     =  -1.0;			/* -1.0 */
Const double cs_Zero     =   0.0;
Const double cs_Fifth    =   (1.0 / 5.0);
Const double cs_Fourth   =   (1.0 / 4.0);
Const double cs_Third    =   (1.0 / 3.0);
Const double cs_Half     =   0.5;
Const double cs_One      =   1.0;
Const double cs_Two      =   2.0;
Const double cs_Three    =   3.0;
Const double cs_Four     =   4.0;
Const double cs_Mfour    =  -4.0;
Const double cs_Five     =   5.0;
Const double cs_Six      =   6.0;
Const double cs_Seven    =   7.0;
Const double cs_Eight    =   8.0;
Const double cs_Nine     =   9.0;
Const double cs_Ten      =  10.0;
Const double cs_K15      =  15.0;
Const double cs_K30      =  30.0;
Const double cs_K45      =  45.0;
Const double cs_Km45     = -45.0;
Const double cs_K60      =  60.0;
Const double cs_K75      =  75.0;
Const double cs_K540     = 540.0;
Const double cs_K360     = 360.0;
Const double cs_K270     = 270.0;
Const double cs_K180     = 180.0;
Const double cs_K90      =  90.0;
Const double cs_K89      =  89.0;
Const double cs_Km360    = -360.0;
Const double cs_Km270    = -270.0;
Const double cs_Km180    = -180.0;
Const double cs_Km90     = -90.0;
Const double cs_Km89     = -89.0;
Const double cs_SclInf   = 9999.99;		/* The value we return for
										   a scale factor when the
										   result actually approaches
										   infinity. */

	/*  The value of INFINITY has been carefully selected to
	    be very large, but not so large as it cannot be used.
	    Thus, for tan (PI/2), we often use this value and then
	    proceed to square it, multiply by it, divide by it,
	    etc.  Thus, don't make this value too small, but don't
	    make it too big either.  Its possible that this value
	    will be used in cases where floats are used, so we
	    like to keep it around 1.0E+32. */

Const double cs_Zero1  = 0.0;
#if _RUN_TIME == _rt_HPUX
	/* It appears that HP UNIX has it's own idea about INFINITY.  I guess I should
	   have used the name cs_INFINITY. */
	Const double cs_Huge   = 1.0E+32;	/* Value often returned when
										   the real result would be
										   infinite. */
	Const double cs_Mhuge  = -1.0E+32;	/* Negative infinity. */
#else
	Const double cs_Huge   = INFINITY;	/* Value often returned when
										   the real result would be
										   infinite. */
	Const double cs_Mhuge  = -INFINITY;	/* Negative infinity. */
#endif

	/* The following constants are used to check the validity of
	   a definitions following acquisition from disk.

	   Change them here or at run time.  Note, we allow a
	   radius as small as 1.0 to handle the test cases.  Also,
	   some folks use this stuff to map planets and the moon. So,
	   the following numbers are pretty liberal.  You may want
	   to be more conservative. */

double cs_ERadMax = 1.0E+08;
double cs_PRadMax = 1.0E+08;
double cs_ERadMin = 1.0;
double cs_PRadMin = .75;
double cs_EccentMax = 0.2;

double cs_DelMax = 50000.0;
double cs_RotMax = 50000.0;
double cs_SclMax = 2000.0;

double cs_SclRedMin = 0.5;
double cs_SclRedMax = 1.5;

double cs_ElevElMin = -25000.0;
double cs_ElevElMax =  50000.0;

	/* The following value is used to test angles for being equal
	   to a specific value, usually 0.0 or 90 degrees.  The value
	   is in radians an corresponds to .001 seconds of arc.  This
	   equates to about 30 centimeters on the earth.  See Synder,
	   page 71.  He suggests 1.E-07.  I feel that 4.85E-08 is
	   close enough to his value, works fine, and is a bit easier
	   to document.
	   
	   This value was established here in release 6.05.  The replacement
	   of the several different literal constants currently used will
	   take place over the next few releases. */
   
Const double cs_AnglTest  = 4.85E-08;
Const double cs_AnglTest1 = (1.0 - 4.85E-08);

	/* cs_ParmTest is similar to cs_AnglTest, but it:
	   1) is in units of degrees;
	   2) is used when checking user entered parameters;
	   3) is a bit larger, representing .1 seconds of arc, about
	      3 meters on the surface of the earth (at the equator).
	      
	   This is the value used to, for example, see if the two
	   standard parallels of a conic are the same.
	*/

Const double cs_ParmTest = 2.78E-05;

/*
	The following values are used to test for proximity to
	the north and south poles, and 90 degrees east and west
	of the central merdian for many projections.  Essentially,
	these values represent +- 90 degrees of latitude, less the
	cs_AnglTest value, in radians.  These constants are designed
	to be consistent with cs_AnglTest, but make checking more
	efficient.
*/

Const double cs_NPTest = ( PI_OVR_2 - 4.85E-08);	/* North Pole TEST value. */
Const double cs_SPTest = (-PI_OVR_2 + 4.85E-08);	/* South Pole TEST value. */
Const double cs_EETest = ( PI_OVR_2 - 4.85E-08);	/* East Extent TEST value. */
Const double cs_WETest = (-PI_OVR_2 + 4.85E-08);	/* West Extent TEST value. */

/*
	The following are used where appropriate to filter out noise
	in the low order bits of double precision latitude and
	longitude numbers.
*/

Const double cs_Micron  = 1.0E-06;
Const double cs_LlNoise = 1.0E-12;


/*
	The following values, all in degrees, are used to test
	coordinate system definition parameters.
*/

Const double cs_MinLng    = -180.00;
Const double cs_MaxLng    =  180.00;
Const double cs_MinLat    = -90.00;
Const double cs_MaxLat    =  90.00;
Const double cs_MinLngFz  = -179.9997222;	/* 1 second greater than -180. */
Const double cs_MaxLngFz  =  179.9997222;	/* 1 second less than 180. */
Const double cs_MinLatFz  = -89.9997222;	/* 1 second less than 90. */
Const double cs_MaxLatFz  =  89.9997222;	/* 1 second greater than -90. */
  
Const double cs_Deg2Sec = 3600.0;			/* Converts degrees to
											   arc seconds. */
Const double cs_Sec2Deg = (1.0 / 3600.0);	/* Converts arc seconds to
											   degrees. */
Const double cs_Min2Deg = (1.0 / 60.0);		/* Converts arc minutes to
											   degrees. */
Const double cs_HlfSecDeg = (0.5 / 3600.0);	/* One half second of arc
											   in degrees. */
Const double cs_Sec2Rad = (1.0 / 3600.0 / RADIAN);/* Converts arc seconds to
												   radians. */
Const double cs_Sin1Sec  = 0.00000484813681107636782;
											/* Sine of one second of arc,
											   also can be used as one
											   arc second in radians. */
Const double cs_NPSecs = (90.0 * 3600.0);	/* Latitude of the north
											   pole in arc seconds. */

Const double cs_Wgs84_aa = 6378137.000;			/* WGS-84 major radius. */
Const double cs_Wgs84_ff = 1.0 / 298.257223563;	/* WGS-84 flattening */
Const double cs_Wgs84_esq = 0.00669437999013;	/* WGS-84 eccentricity
												   squared */
Const double cs_Wgs84_1esq = 0.99330562000987;	/* WGS-84 1.0 - e_sq */

/* Formatting variables used by the CScs2src, CScs2xml, and similar
   functions. */
long csLatFrmt = 16L;
long csLngFrmt = 16L;
long csAnglFrmt = 16L;
long csXyFrmt = 5L;
long csZzFrmt = 5L;
long csRedFrmt = 0L;
long csSclFrmt = 0L;
long csCoefFrmt = 11L;

/* The following definition is used in fallback cases only.  That is, where
   extraordinary calculations are being performed.  In all "normal"
   situations, the definition fetched from the dictionary(s) is/are used. */
struct cs_Datum_ cs_Wgs84Def =
{
	"WGS84",				/* datum key name */
	"WGS84",				/* ellipsoid key name */
	6378137.000,			/* equatorial radius */
	6356752.3142,			/* polar radius */
	1.0 / 298.257223563,	/* flattening */
	0.0818191908426,		/* eccentricity */
	0.0,					/* Delta X */
	0.0,					/* Delta Y */
	0.0,					/* Delta Z */
	0.0,					/* Rot X */
	0.0,					/* Rot Y */
	0.0,					/* Rot Z */
	0.0,					/* Scale */
	cs_DTCTYP_WGS84,		/* to84_via */
	"World Geodetic System of 1984",
	"World Geodetic System of 1984"
};
#if !defined(__SUNPRO_C)
	struct cs_Datum_ *cs_Wgs84Ptr = &cs_Wgs84Def;
#endif

/*
	The following are global constants used to define the
	operation of the non-standard cartesian system
	feature of CS_MAP.

	cs_QuadMin & cs_QuadMax are used in the CS_cschk function
	to determine validity of the user supplied value.
	cs_QuadMap is used in the projection setup functions
	to convert the user supplied value to the bit map
	value expected by CS_quadF and cs_quadI.

	Note, the projection setup functions use

	trmer->quad = cs_QuadMap [csprm->csdef.quad - cs_QuadMin];

	to convert from user specified code to internal code.
*/

Const short cs_QuadMax =  4;
Const short cs_QuadMin = -4;
Const short cs_QuadMap [] =
{
		cs_QUAD_SWAP | cs_QUAD_INVY,				/* -4 */
		cs_QUAD_SWAP | cs_QUAD_INVX | cs_QUAD_INVY,	/* -3 */
		cs_QUAD_SWAP | cs_QUAD_INVX,				/* -2 */
		cs_QUAD_SWAP,								/* -1 */
		0,											/*  0 */
		0,											/*  1 */
		cs_QUAD_INVX,								/*  2 */
		cs_QUAD_INVX | cs_QUAD_INVY,				/*  3 */
		cs_QUAD_INVY								/*  4 */
};
/*
	A quad map for use with south oriented coordinate systems.
*/	
Const short cs_QuadMapSO [] =
{
		cs_QUAD_SWAP | cs_QUAD_INVX,				/* -4 */
		cs_QUAD_SWAP,								/* -3 */
		cs_QUAD_SWAP | cs_QUAD_INVY,				/* -2 */
		cs_QUAD_SWAP | cs_QUAD_INVX | cs_QUAD_INVY,	/* -1 */
		cs_QUAD_INVX | cs_QUAD_INVY,				/*  0 */
		cs_QUAD_INVX | cs_QUAD_INVY,				/*  1 */
		cs_QUAD_INVY,								/*  2 */
		0,											/*  3 */
		cs_QUAD_INVX								/*  4 */
};

/*
	The following table defines the list of currently supported
	Coordinate System groups.  It is suggested that application
	developers resist the temptation to add new groups.  If there
	are too many groups, with too few members, the whole group
	concept loses its effectiveness.  Applications developers
	may, need however, to translate the table to a different
	language.
*/

Const struct cs_Grptbl_ cs_CsGrptbl [] =
{
	{  "SPCS27","State Planes, NAD27 Based, US Foot"          ,cs_GRPTBL_ACTIVE},
	{  "SPCS83","State Planes, NAD83 Based, Meters"           ,cs_GRPTBL_ACTIVE},
	{ "SPCS83F","State Planes, NAD83 Based, US Foot"          ,cs_GRPTBL_ACTIVE},
	{ "SPCS83I","State Planes, NAD83 Based, Intn'l Foot"      ,cs_GRPTBL_ACTIVE},
	{  "SPCSHP","State Planes, HARN (HPGN) Based, Meters"     ,cs_GRPTBL_ACTIVE},
	{ "SPCSHPF","State Planes, HARN (HPGN) Based, US Foot"    ,cs_GRPTBL_ACTIVE},
	{ "SPCSHPI","State Planes, HARN (HPGN) Based, Intn'l Foot",cs_GRPTBL_ACTIVE},
	{      "LL","Latitude/Longitude"                          ,cs_GRPTBL_ACTIVE},
	{   "UTM27","UTM Zones, NAD27 Based, Meters"              ,cs_GRPTBL_ACTIVE},
	{  "UTM27F","UTM Zones, NAD27 Based, US Foot"             ,cs_GRPTBL_ACTIVE},
	{  "UTM27I","UTM Zones, NAD27 Based, Intn'l Foot"         ,cs_GRPTBL_ACTIVE},
	{   "UTM83","UTM Zones, NAD83 Based, Meters"              ,cs_GRPTBL_ACTIVE},
	{  "UTM83F","UTM Zones, NAD83 Based, US Foot"             ,cs_GRPTBL_ACTIVE},
	{  "UTM83I","UTM Zones, NAD83 Based, Intn'l Foot"         ,cs_GRPTBL_ACTIVE},
	{   "UTMHP","UTM Zones, HARN (HPGN) Based, Meters"        ,cs_GRPTBL_ACTIVE},
	{  "UTMHPF","UTM Zones, HARN (HPGN) Based, US Foot"       ,cs_GRPTBL_ACTIVE},
	{  "UTMHPI","UTM Zones, HARN (HPGN) Based, Intn'l Foot"   ,cs_GRPTBL_ACTIVE},
	{ "OTHR-US","Other US Coordinate Systems"                 ,cs_GRPTBL_ACTIVE},
	{  "CANADA","Canadian Coordinate Systems"                 ,cs_GRPTBL_ACTIVE},
	{ "OTHR-NA","Other North American Coordinate Systems"     ,cs_GRPTBL_ACTIVE},
	{    "UTMN","UTM Zones, Northern Hemisphere, Meters"      ,cs_GRPTBL_ACTIVE},
	{    "UTMS","UTM Zones, Southern Hemisphere, Meters"      ,cs_GRPTBL_ACTIVE},
	{   "WORLD","World/Continent Coordinate Systems"          ,cs_GRPTBL_ACTIVE},
	{  "EUROPE","European Coordinate Systems"                 ,cs_GRPTBL_ACTIVE},
	{   "AUSNZ","Australia/New Zealand Coordinate Systems"    ,cs_GRPTBL_ACTIVE},
	{   "SAMER","South American Coordinate Systems"           ,cs_GRPTBL_ACTIVE},
	{   "CAMER","Central American Coordinate Systems"         ,cs_GRPTBL_ACTIVE},
	{  "AFRICA","African Coordinate Systems"                  ,cs_GRPTBL_ACTIVE},
	{    "ASIA","Asian Coordinate Systems"                    ,cs_GRPTBL_ACTIVE},
	{ "PACIFIC","Other Pacific Coordinate Systems"            ,cs_GRPTBL_ACTIVE},
	{"ATLANTIC","Other Atlantic Coordinate Systems"           ,cs_GRPTBL_ACTIVE},
	{   "POLAR","Polar Coordinate Systems"                    ,cs_GRPTBL_ACTIVE},
	{ "EPSGPRJ","Projected defs from EPSG, area undetermined" ,cs_GRPTBL_ACTIVE},
	{  "EPSGLL","Geographic defs from EPSG, area undetermined",cs_GRPTBL_ACTIVE},
	{    "TEST","Test Coordinate Systems"                     ,cs_GRPTBL_ACTIVE},
	{    "USER","User Defined Coordinate Systems"             ,cs_GRPTBL_ACTIVE},
	{"WKTSUPPT","Well Known Text Support"                     ,cs_GRPTBL_ACTIVE},
	{   "CARIB","Caribean/Gulf of Mexico and Vicinity"        ,cs_GRPTBL_ACTIVE},
	{ "MIDEAST","Mideast/Holy Land"                           ,cs_GRPTBL_ACTIVE},
	{  "INDIAN","Indian Ocean"                                ,cs_GRPTBL_ACTIVE},
	{    "NONE","No group specified in definition"            ,cs_GRPTBL_ACTIVE},
	{  "LEGACY","Obsolete/Incorrect; for legacy use only"     ,cs_GRPTBL_ACTIVE},
	{        "",""                                            ,cs_GRPTBL_END}
};


/*
	Provisions of the licensing agreement prohibit the
	removal of the following decalaration; or the
	modification of any other code for the purpose of
	eliminating the existence of this string in executable
	modules.
*/

Const csThread char cs_Mentor [] = "Coordinate System Mapping Package Copyright (c) 1988-2003 Mentor Software, Inc.\tAll Rights Reserved\tRelease 11.15\n";
Const csThread char cs_SrlNbr [] = "Serial Number: 70371\n";
Const csThread char cs_LicTo [] = "Licensed To: The WhiteStar Corporation\n";

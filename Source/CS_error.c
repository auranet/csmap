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

			 File Name: $RCSfile: CS_error.c $
		   Description:
			   Purpose:

		Revision Level:	$Revision: #10 $
		 Check In Date:	$Date: 2007/01/12 $

		Last Revision:	$Log: CS_error.c $
		Last Revision:	Revision 11.1300  2005/05/25 23:27:11  nto
		Last Revision:	Official Release 11.13
		Last Revision:	Revision 11.1201  2005/05/25 23:15:17  nto
		Last Revision:	Added message for Kruger Formulation quality check.
		Last Revision:	Revision 11.1200  2005/01/15 18:27:11  nto
		Last Revision:	Official Release of CS-MAP 11.12, 11:26am 15 Jan 2005
		Last Revision:	Revision 11.1100  2004/11/01 18:53:09  nto
		Last Revision:	Official release 11.11
		Last Revision:	Revision 11.1001  2004/10/07 19:25:17  nto
		Last Revision:	Revision 11.901  2004/08/07 03:36:55  nto
		Last Revision:	Added cs_WKT_NODTREF message for high level WKT functions.
		Last Revision:	Revision 11.900  2004/03/26 17:02:24  nto
		Last Revision:	Official release: 11.09 - 3/25/2003
		Last Revision:	Revision 11.800  2004/01/13 23:29:12  nto
		Last Revision:	Revision 11.701  2004/01/13 20:43:05  nto
		Last Revision:	Added a message for "no base geographic" system.
		Last Revision:	Revision 11.700  2003/12/19 01:49:53  nto
		Last Revision:	Official release 11.07
		Last Revision:	Revision 11.601  2003/12/19 01:04:24  nto
		Last Revision:	Added missing message, and added two more related to WKT.
		Last Revision:	Revision 11.600  2003/12/04 02:46:27  nto
		Last Revision:	Release 11.06.  Never shipped. Source captured in prep for C++ V7.
		Last Revision:	Revision 11.503  2003/11/24 01:12:55  nto
		Last Revision:	Added some messages for WKT export.
		Last Revision:	Revision 11.502  2003/10/01 22:04:49  nto
		Last Revision:	Added messages for WKT
		Last Revision:	Revision 11.501  2003/08/22 21:12:55  nto
		Last Revision:	Official Release: 11.05
		Last Revision:	Revision 11.402  2003/08/22 20:45:30  nto
		Last Revision:	Error messages for new Useful Range feature
		Last Revision:	Revision 11.401  2003/05/01 23:06:21  nto
		Last Revision:	Revision 11.302  2003/04/29 01:43:16  nto
		Last Revision:	Removed a reference to cs_Doserr when compiling for Unix.
		Last Revision:	Revision 11.301  2003/04/28 22:46:55  nto
		Last Revision:	Added message for an invalid density value in a GDC file.
		Last Revision:	Revision 11.300  2003/02/25 04:29:16  nto
		Last Revision:	Official Release 11.03
		Last Revision:	Revision 11.101  2003/02/15 01:27:43  nto
		Last Revision:	Added message for missing OSTN02.txt file.
		Last Revision:	Revision 11.100  2002/11/22 19:38:43  nto
		Last Revision:	Official release: 11.01
		Last Revision:	Revision 10.1502  2002/11/06 23:48:13  nto
		Last Revision:	Fixed to compile under various flavors of UNIX.
		Last Revision:	Revision 10.1501  2002/10/13 00:23:42  nto
		Last Revision:	Dealt with errno and _doserror with respect to ANSI and Windows CE.
		Last Revision:	Revision 10.1500  2002/09/22 00:01:19  nto
		Last Revision:	Official Release:= 10.15
		Last Revision:	Revision 10.1402  2002/09/17 23:25:27  nto
		Last Revision:	Added messages for Nad27<->Ats77.
		Last Revision:	Revision 10.1401  2002/09/15 21:17:01  nto
		Last Revision:	Added messages for Units Add, and ED50<-->ETRF89
		Last Revision:	Revision 10.1400  2002/08/09 18:14:22  nto
		Last Revision:	Revision 10.1200  2002/07/14 03:26:15  nto
		Last Revision:	Revision 10.1100  2002/06/13 14:18:37  nto
		Last Revision:	Release 10.11 Official
		Last Revision:	Revision 10.1002  2002/06/13 13:32:44  nto
		Last Revision:	Added messages for RGF93.
		Last Revision:	Revision 10.1001  2002/04/18 21:04:39  nto
		Last Revision:	Message for elevated ellipsoid.
		Last Revision:	Revision 10.1000  2002/02/23 21:18:26  nto
		Last Revision:	Official Release of 10.10, 2/22/02 - Norm Olsen
		Last Revision:	Revision 10.901  2002/02/19 05:19:25  nto
		Last Revision:	New messages for the JGD2K datum, OSTN97 Transofrmation, Geoid99, OSGM91 geoid, and the Danish coordinate systems.
		Last Revision:	Revision 10.900  2001/09/24 04:31:10  nto
		Last Revision:	Revision 10.701  2001/09/18 19:19:37  nto
		Last Revision:	Fixed the conditional compile code for referencing cs_DosError.
		Last Revision:	Revision 10.700  2001/01/25 04:13:48  nto
		Last Revision:	Revision 10.601  2001/01/25 04:04:04  nto
		Last Revision:	Added message for the 10 and ignore soft datum error processing.
		Last Revision:	Revision 10.600  2000/12/11 06:39:42  nto
		Last Revision:	Release 10.06
		Last Revision:	Revision 10.501  2000/12/11 05:23:38  nto
		Last Revision:	Added some messages related to the Multiple Regression error handling.
		Last Revision:	Revision 10.500  2000/10/27 07:38:20  nto
		Last Revision:	Official Release 10.05
		Last Revision:	Revision 10.401  2000/10/27 03:51:41  nto
		Last Revision:	Added messages for many things, primarily the new datum fallback
		Last Revision:	feature.  ALso added the NERTH message.
		Last Revision:	Revision 10.400  2000/09/13 01:16:54  nto
		Last Revision:	Release 10.04
		Last Revision:	Revision 10.302  2000/09/13 01:02:21  nto
		Last Revision:	Added message for affine denominator of zero.
		Last Revision:	Revision 10.301  2000/09/12 20:37:30  nto
		Last Revision:	Added new MGRS message.
		Last Revision:	Revision 10.300  2000/04/04 23:18:25  nto
		Last Revision:	Revision 10.201  2000/04/03 21:37:16  nto
		Last Revision:	Changed the single message about invalid string to nine more descriptive messages.
		Last Revision:	Revision 10.200  2000/03/02 18:51:16  nto
		Last Revision:	Revision 10.4  2000/02/11 06:08:13  nto
		Last Revision:	Added several new messages for the new datum conversions AGD66, AGD84, et. al.
		Last Revision:	Revision 10.3  2000/01/31 00:29:27  nto
		Last Revision:	COrrected problem in the case of ltoa overflow.
		Last Revision:	Revision 10.2  2000/01/30 23:38:01  nto
		Last Revision:	Moved the CS_erpt function out to its own file for easier modification by user.  Also some PCLint cleanup.
		Last Revision:	Revision 10.1  1999/11/04 00:12:41  nto
		Last Revision:	New messages resulting from datum conversion rewrite.
		Last Revision:	Revision 10.0  1999/10/05 18:27:13  nto
		Last Revision:	Revision 9.99  1999/10/05 17:36:24  nto
		Last Revision:	Revision 1.2  1999/09/06 20:32:16  nto
		Last Revision:	This revision compiles, links, and generates a successful test program.

******************************************************************************/

#ifdef LABEL_MODULE
static char revlvl [] = {"$Id: //depot/Libraries/CsMap/current/src/CS_error.c#10 $"};
#endif

#include "cs_map.h"

/**********************************************************************
	The following function is used to return a text string which
	describes thelast error condition encounered.
**********************************************************************/

void EXP_LVL1 CS_errmsg (char *user_bufr,int bfr_size)
{
	extern char csErrmsg [256];
	
	strncpy (user_bufr,csErrmsg,(unsigned)bfr_size);
	user_bufr [bfr_size - 1] = '\0';
	return;
}

/**********************************************************************
**    Calling Sequence:	CSerpt (mesg,size,err_num);
**
**	char *mesg;					pointer to the character array which is to
**								recieve the error message text.
**	int size;					the size of the character array pointed to
**								by the mesg argument.
**	int err_num;				number of the error condition being
**								reported.
**
**	This module is written as it is to isolate the code which
**	generates the message from the code which presents it to
**	the user.  Printf's are bad news in many environments.
**	However, we don't want to duplicate this code if possible.
**********************************************************************/

#if _RUN_TIME >= _rt_UNIXPCC
#	include <errno.h>
#endif

#define csET_NM  1
#define csET_LOC 2

/*
	In the table below, type is used to select an appropriate
	sprintf type sequence for placing inserts, such as file
	names, into the error message.
	
	Group is a bit map which classifies (can't use class, it is
	resevered word in C++) an error condition as a member of one
	or more of the following classes.  The cs_ErrSup global
	variable is used to supress errors of specific classes at
	specific times.
	
	For example, when one desires to use CS_dtdef to determine if
	a name is valid, one wishes to disable the error condition for
	name not found, but leave such messages as "Couldn't open Datum
	Dictionary" active.  Thus, we have invented this group bit map.
	Normally, we run with cs_ErrSup set to zero.  Setting a specific
	bit in this word causes that specific group to be suppressed.
	
	The error groups are:
	
	Bit | Define Name     |  Description
	-------------------------------------------------------------------
	  1 | cs_ERSUP_SOFT   | Software problems; problems which are not
	    |                 | supposed to happen if all is working per
	    |                 | design.
	  2 | cs_ERSUP_SYS    | System problems, e.g. malloc failed,
	    |                 | I/O error, disk full.
	  4 | cs_ERSUP_CONFIG | Installation, configuration, manufacturing
	    |                 | problems; e.g. couln't open COORDSYS
	  8 | cs_ERSUP_OPR    | Operational problems; e.g. invalid name,
	    |                 | bogus coordinate system name.  Conditions
	    |                 | a user might cause.
	 16 | cs_ERSUP_DATA   | A problem with supplied data; i.e. convergence
	    |                 | failures, etc.
	 32 | cs_ERSUP_RNG    | Converting data out of normal range, e.g.
	    |                 | converting a European lat/long to NAD27.
	    
	 If you want to invent your own, work your way down from the
	 most significant bit.  We'll add from 32 on up.
	    
*/

struct csErrtab_
{
	short code;		/* Numeric code assigned to this error
				   condition. */
	short type;		/* Type of message, i.e. what data gets
				   inserted into the message. */
	unsigned short sup_grp;	/* Group bit map to which message belongs,
				   used for optional suppression. */
	char *msg;		/* The actual message to be reported. */
};

struct csErrtab_ csErrtab [] =
{
 {      cs_CSDICT,       0,cs_ERSUP_CONFIG,
						   "The Coordinate System Dictionary open failed."},
 {  cs_CS_NOT_FND, csET_NM,cs_ERSUP_OPR,
						   "Coordinate system named %s does not exist."},
 {      cs_NO_MEM,       0,cs_ERSUP_SYS,
						   "Insufficient memory available."},
 {  cs_UNKWN_PROJ, csET_NM,cs_ERSUP_SOFT,
						   "%s is not a supported projection."},
 {cs_CS_BAD_MAGIC, csET_NM,cs_ERSUP_CONFIG,
						   "%s is not a Coodinate System Dictionary."},
 {       cs_IOERR,       0,cs_ERSUP_CONFIG,
						   "Physical I/O error detected."},
 {      cs_DTDICT,       0,cs_ERSUP_SYS,
						   "The Datum Dictionary open failed."},
 {cs_DT_BAD_MAGIC, csET_NM,cs_ERSUP_CONFIG,
						   "%s is not a Datum Dictionary."},
 {  cs_DT_NOT_FND, csET_NM,cs_ERSUP_OPR,
						   "Datum definition %s does not exist."},
 {      cs_ELDICT,       0,cs_ERSUP_CONFIG,
						   "The Ellipsoid Dictionary open failed."},
 {cs_EL_BAD_MAGIC, csET_NM,cs_ERSUP_CONFIG,
						   "%s is not a Ellipsoid Dictionary."},
 {  cs_EL_NOT_FND, csET_NM,cs_ERSUP_OPR,
						   "Ellipsoid definition %s does not exist."},
 {    cs_INV_FILE,       0,cs_ERSUP_SYS,
						   "Corrupted CS_MAP data file encountered."},
 {     cs_TMP_CRT,       0,cs_ERSUP_SYS,
						   "Creation of a temporary file failed."},
 {   cs_DISK_FULL,       0,cs_ERSUP_SYS,
						   "Insufficient disk space available."},
 {      cs_UNLINK, csET_NM,cs_ERSUP_SYS,
						   "Deletion of %s failed."},
 {      cs_RENAME, csET_NM,cs_ERSUP_SYS,
						   "Rename of temporary file to %s failed."},
 {    cs_INV_NAME, csET_NM,cs_ERSUP_OPR,
						   "%s is not a valid key name."},
 {    cs_INV_UNIT, csET_NM,cs_ERSUP_SOFT,
						   "Unknown unit name (%s) detected."},
 { cs_NAD_NO_DATA,       0,cs_ERSUP_CONFIG,
						   "WARNING: NADCON data files could not be found."},
 {   cs_DTC_DAT_W,       0,cs_ERSUP_SOFT,
						   "WARNING: Optional software would produce better results."},
 {   cs_DTC_DAT_F,       0,cs_ERSUP_SOFT,
						   "Requested datum conversion unsupported."},
 {   cs_DTC_BLK_W,csET_LOC,cs_ERSUP_RNG,
						   "WARNING: NADCON data for %s is not available."},
 {   cs_DTC_BLK_F,csET_LOC,cs_ERSUP_RNG,
						   "NADCON data for %s is not available."},
 {   cs_DTC_BLK_Q,       0,cs_ERSUP_RNG,
						   "Further NADCON data availability messages suppressed."},
 {cs_DTC_NO_SETUP,       0,cs_ERSUP_SOFT,
						   "Datum shift calculations not initialized."},
 { cs_NADCON_ICNT,       0,cs_ERSUP_DATA,
						   "Grid datum inverse calculation failed to converge."},
 { cs_NADCON_CONS,       0,cs_ERSUP_DATA,
						   "NADCON database files inconsistent."},
 {    cs_DTC_FILE, csET_NM,cs_ERSUP_CONFIG,
						   "Open of datum shift data file (%s) failed."},
 {   cs_WGS_CNVRG,       0,cs_ERSUP_DATA,
						   "Iterative conversion failed to converge."},
 {        cs_ISER, csET_NM,cs_ERSUP_SOFT,
						   "Internal software error detected in module %s."},
 {   cs_HPGN_ICNT,       0,cs_ERSUP_DATA,
						   "HPGN 91 to 83 iteration count insufficient."},
 {   cs_HPGN_CONS,       0,cs_ERSUP_DATA,
						   "HPGN database files inconsistent."},
 { cs_HPG_NO_DATA,       0,cs_ERSUP_CONFIG,
						   "WARNING: HPGN data files could not be found."},
 {   cs_HPG_BLK_W,csET_LOC,cs_ERSUP_RNG,
						   "WARNING: HPGN data for %s is not available."},
 {   cs_HPG_BLK_F,csET_LOC,cs_ERSUP_RNG,
						   "HPGN data for %s is not available."},
 {   cs_HPG_BLK_Q,       0,cs_ERSUP_RNG,
						   "Further HPGN data availability messages suppressed."},
 {  cs_MREG_RANGE,       0,cs_ERSUP_RNG,
						   "Conversion outside of usable range of Multiple Regression definition; using fallback definition."},
 { cs_MREG_BADMAG, csET_NM,cs_ERSUP_DATA,
						   "Multiple Regression file %s corrupt."},
 {   cs_NWDT_READ,       0,cs_ERSUP_SYS,
						   "Error reading old datum dictionary file."},
 {   cs_NWDT_WRIT,       0,cs_ERSUP_SYS,
						   "Error writing/creating new datum dictionary file."},
 { cs_TMPFN_MAXED,       0,cs_ERSUP_SYS,
						   "Temporary file name algorithm max'ed out."},
 {  cs_BSWP_UNKWN,       0,cs_ERSUP_CONFIG,
						   "This machine has unsupported byte ordering."},
 {   cs_NWCS_READ,       0,cs_ERSUP_SYS,
						   "Error reading old coordinate system dictionary file."},
 {   cs_NWCS_WRIT,       0,cs_ERSUP_SYS,
						   "Error writing/creating new coordinate system dictionary file."},
 {   cs_NWEL_READ,       0,cs_ERSUP_SYS,
						   "Error reading old ellipsoid dictionary file."},
 {   cs_NWEL_WRIT,       0,cs_ERSUP_SYS,
						   "Error writing/creating new ellipsoid dictionary file."},
 { cs_NO_REFERNCE, csET_NM,cs_ERSUP_SOFT,
						   "System %s has neither a datum or ellipsoid reference."},
 {cs_CSGRP_INVKEY, csET_NM,cs_ERSUP_SOFT,
						   "%s is not a valid coordinate system group key."},
 {cs_DLM_CSIDX_FULL,     0,cs_ERSUP_SYS,
						   "Coordinate System index resource is exhausted."},
 {cs_DLM_DTIDX_FULL,     0,cs_ERSUP_SYS,
						   "Datum Conversion index resource is exhausted."},
 {     cs_FL_OPEN, csET_NM,cs_ERSUP_CONFIG,
						   "Couldn't open file named %s."},
 {    cs_SWP_TYPE, csET_NM,cs_ERSUP_SOFT,
						   "Don't know how to swap bytes in %s."},
 {   cs_ELDEF_INV, csET_NM,cs_ERSUP_OPR,
						   "Ellipsoid definition with key name %s is invalid."},
 {   cs_DTDEF_INV, csET_NM,cs_ERSUP_OPR,
						   "Datum definition with key name %s is invalid."},
 {  cs_RGN_PNTCNT,       0,cs_ERSUP_SOFT,
						   "Region definition must have at least 4 points."},
 {  cs_CNTV2_MULT, csET_NM,cs_ERSUP_OPR,
						   "Multiple CNT V2 data files detected, using %s."},
 {     cs_CS_PROT, csET_NM,cs_ERSUP_OPR,
						   "%s is a distribution coordinate system and is protected."},
 {     cs_DT_PROT, csET_NM,cs_ERSUP_OPR,
						   "%s is a distribution datum and is protected."},
 {     cs_EL_PROT, csET_NM,cs_ERSUP_OPR,
						   "%s is a distribution ellipsoid and is protected."},
 {    cs_CS_UPROT, csET_NM,cs_ERSUP_OPR,
						   "User defined coordinate system %s is now protected."},
 {    cs_DT_UPROT, csET_NM,cs_ERSUP_OPR,
						   "User defined datum %s is now protected."},
 {    cs_EL_UPROT, csET_NM,cs_ERSUP_OPR,
						   "User defined ellipsoid %s is now protected."},
 {      cs_UNIQUE, csET_NM,cs_ERSUP_OPR,
						   "User defined dictionary items require %s in name."},
 {  cs_A2F_MLTSGN,       0,cs_ERSUP_OPR,
						   "Multiple sign indications encountered."},
 {  cs_A2F_ERRCMA,       0,cs_ERSUP_OPR,
						   "Use of thousands separator is inconsistent."},
 {  cs_A2F_MLTPNT,       0,cs_ERSUP_OPR,
						   "Multiple decimal point indications encountered."},
 {  cs_A2F_SECS60,       0,cs_ERSUP_OPR,
						   "Got a value of 60 or greater where seconds were expected."},
 {  cs_A2F_MINS60,       0,cs_ERSUP_OPR,
						   "Got a value of 60 or greater where minutes were expected."},
 {  cs_A2F_FMTERR,       0,cs_ERSUP_OPR,
						   "Numeric formatting error; too many spaces?."},
 {  cs_INV_INDX,         0,cs_ERSUP_SOFT,
						   "Invalid enumeration index."},
 {  cs_INV_ARG1,   csET_NM,cs_ERSUP_SOFT,
						   "Argument 1 of %s is not a valid memory address/pointer."},
 {  cs_INV_ARG2,   csET_NM,cs_ERSUP_SOFT,
						   "Argument 2 of %s is not a valid memory address/pointer."},
 {  cs_INV_ARG3,   csET_NM,cs_ERSUP_SOFT,
						   "Argument 3 of %s is not a valid memory address/pointer."},
 {  cs_INV_ARG4,   csET_NM,cs_ERSUP_SOFT,
						   "Argument 4 of %s is not a valid memory address/pointer."},
 {  cs_INV_ARG5,   csET_NM,cs_ERSUP_SOFT,
						   "Argument 5 of %s is not a valid memory address/pointer."},
 {  cs_INV_UTYP,         0,cs_ERSUP_SOFT,
						   "Invalid unit type specified."},
 {cs_GEOID_NO_DATA,      0,cs_ERSUP_CONFIG,
						   "WARNING: No geoid height data files were found."},
 {cs_GEOID_FILE,         0,cs_ERSUP_CONFIG,
						   "Open of geoid height data file failed."},
 {cs_GEOID_NO_SETUP,     0,cs_ERSUP_SOFT,
						   "Geoid height calculations not initialized."},
 {    cs_MIF_UNIT, csET_NM,cs_ERSUP_OPR,
						   "Coordinate system %s is based on a unit not supported by MapInfo."},
 {   cs_MIF_ELREF,       0,cs_ERSUP_OPR,
						   "MapInfo doesn't support direct references to an ellipsoid."},
 {   cs_MIF_DATUM, csET_NM,cs_ERSUP_OPR,
						   "MapInfo doesn't support datum named %s."},
 {   cs_MIF_FEATR, csET_NM,cs_ERSUP_OPR,
						   "Coordinate system %s uses a feature not supported by MapInfo."},
 {    cs_MIF_PROJ, csET_NM,cs_ERSUP_OPR,
						   "Coordinate system %s is based on a projection not supported by MapInfo."},
 {   cs_DBL_SPACE, csET_NM,cs_ERSUP_OPR,
						   "Key name %s contains a double space; contrary to system requirements."},
 {   cs_MRT_NTFND, csET_NM,cs_ERSUP_OPR,
						   "Multiple Regression file named %s not found in data directory."},
 {   cs_DTC_FIL_F, csET_NM,cs_ERSUP_CONFIG,
						   "Datum shift data file(s) named %s are not available in approriate directory."},
 {   cs_DTC_FIL_W, csET_NM,cs_ERSUP_CONFIG,
						   "WARNING: Datum shift data file(s) named %s not available; using approximation."},
 {   cs_DTC_RNG_F,csET_LOC,cs_ERSUP_RNG,
						   "Encountered data at %s which is outside NAD27/83 conversion extents."},
 {   cs_DTC_RNG_W,csET_LOC,cs_ERSUP_RNG,
						   "WARNING: Data in range %s is outside NAD27/83 extents; no datum shift has been applied."},
 { cs_SPZ_INVALID,csET_NM,cs_ERSUP_RNG,
						   "%s is not a valid state plane zone code number."},
 {   cs_A2F_RATIO,       0,cs_ERSUP_OPR,
						   "Characters entered included ratio character, but not in valid ratio format."},
 { cs_AGD66_RNG_F,csET_LOC,cs_ERSUP_RNG,
						   "Encountered data at %s which is outside AGD66<->GDA94 conversion extents."},
 { cs_AGD66_RNG_W,csET_LOC,cs_ERSUP_RNG,
						   "WARNING: Data in range %s is outside AGD66<->GDA94 data file coverage; conversion results are unshifted."},
 {    cs_XYZ_ITR,        0,cs_ERSUP_SOFT,
						   "Geocentric inverse calculation failed to converge."},
 {   cs_MO_CNVRG,        0,cs_ERSUP_SOFT,
						   "Molodensky 2D inverse failed to converge."},
 {   cs_BW_CNVRG,        0,cs_ERSUP_SOFT,
						   "Bursa/Wolf 2D inverse failed to converge."},
 {   cs_7P_CNVRG,        0,cs_ERSUP_SOFT,
						   "Seven parameter 2D inverse failed to converge."},
 {   cs_3P_CNVRG,        0,cs_ERSUP_SOFT,
						   "Three parameter 2D inverse failed to converge."},
 {   cs_6P_CNVRG,        0,cs_ERSUP_SOFT,
						   "Six parameter 2D inverse failed to converge."},
 {   cs_4P_CNVRG,        0,cs_ERSUP_SOFT,
						   "Four parameter 2D inverse failed to converge."},
 {   cs_DTC_PATH,  csET_NM,cs_ERSUP_CONFIG,
						   "Path (%s) in datum catalog update is not formatted correctly."},
 {   cs_NAD_HPGN,        0,cs_ERSUP_CONFIG,
						   "Reference to HPGN file detected in North American datum catalog."},
 {    cs_NAD_EXT,  csET_NM,cs_ERSUP_CONFIG,
						   "Invalid extension, or missing extension, encountered in NAD datum shift catalog (%s)."},
 {   cs_NAD_LAS,         0,cs_ERSUP_CONFIG,
						   "LAS extension encountered in NAD datum shift catalog; use \"L?S\"."},
 {   cs_NAD_LOS,         0,cs_ERSUP_CONFIG,
						   "LOS extension encountered in NAD datum shift catalog; use \"L?S\"."},
 {  cs_HPGN_NAD,         0,cs_ERSUP_CONFIG,
						   "Reference to NAD shift file detected in HARN datum catalog."},
 { cs_HPGN_EXTA,         0,cs_ERSUP_CONFIG,
						   "LAS extension encountered in HARN datum shift catalog; use \"L?S\"."},
 { cs_HPGN_EXTO,         0,cs_ERSUP_CONFIG,
						   "LOS extension encountered in HARN datum shift catalog; use \"L?S\"."},
 { cs_HPGN_EXTX,         0,cs_ERSUP_CONFIG,
						   "Invalid, or missing, extension encountered in the HARN datum shift catalog."},
 {  cs_GHGT_GEO,         0,cs_ERSUP_CONFIG,
						   "Geoid height data catalog file contains reference to file without the .geo extension."},
 {  cs_GHGT_EXT,         0,cs_ERSUP_CONFIG,
						   "Invalid, or missing, extension encountered in the Geoid height data catalog."},
 {   cs_VCON_94,         0,cs_ERSUP_CONFIG,
						   "VERTCON data catalog file contains reference to file without the .94 extension."},
 {  cs_VCON_EXT,         0,cs_ERSUP_CONFIG,
						   "Invalid, or missing, extension encountered in the VERTCON data catalog."},
 {cs_DTC_CATFILE,  csET_NM,cs_ERSUP_SOFT,
						   "Open of data catalog file %s failed; does it exist?"},
 {    cs_DTC_EXT,        0,cs_ERSUP_CONFIG,
						   "File name in data catalog does not contain an extension or directory specification."},
 {cs_AGD84_RNG_F, csET_LOC,cs_ERSUP_RNG,
						   "Encountered data at %s which is outside AGD84<->GDA94 conversion extents."},
 {cs_AGD84_RNG_W, csET_LOC,cs_ERSUP_RNG,
						   "WARNING: Data in range %s is outside AGD84<->GDA94 data file coverage; converted results are unshifted."},
 {cs_NZGD49_RNG_F,csET_LOC,cs_ERSUP_RNG,
						   "Encountered data at %s which is outside NZGD49<->NZGD2K conversion extents."},
 {cs_NZGD49_RNG_W,csET_LOC,cs_ERSUP_RNG,
						   "WARNING: Data in range %s is outside NZGD49<->NZGD2K data file coverage; conversion results are unshifted."},
 {cs_ATS77_RNG_F, csET_LOC,cs_ERSUP_RNG,
						   "Encountered data at %s which is outside ATS77<->CSRS conversion extents."},
 {cs_ATS77_RNG_W, csET_LOC,cs_ERSUP_RNG,
						   "WARNING: Data in range %s is outside ATS77<->CSRS data file coverage; conversion results are unshifted."},
 { cs_NAD_RNG_F,  csET_LOC,cs_ERSUP_RNG,
						   "Encountered data at %s which is outside NAD27<->NAD83 conversion extents."},
 { cs_NAD_RNG_W,  csET_LOC,cs_ERSUP_RNG,
						   "WARNING: Data in range %s is outside NAD27<->NAD83 NADCON data file coverage; conversion results are unshifted."},
 {cs_HARN_RNG_F,csET_LOC,cs_ERSUP_RNG,
						   "Encountered data at %s which is outside NAD83<->HARN conversion extents."},
 {cs_HARN_RNG_W,csET_LOC,cs_ERSUP_RNG,
						   "WARNING: Data in range %s is outside NAD83<->HARN NADCON data file coverage; conversion results are unshifted."},

 {   cs_CSQ_AZM,   csET_NM,cs_ERSUP_OPR,
						   "%s :: Y axis azimuth specification is invalid." },
 { cs_CSQ_AZMTH,   csET_NM,cs_ERSUP_OPR,
						   "%s :: Great circle azimuth value is invalid." },
 {   cs_CSQ_LAT,   csET_NM,cs_ERSUP_OPR,
						   "%s :: Invalid latitude detected in definition." },
 {cs_CSQ_LATEQU,   csET_NM,cs_ERSUP_OPR,
						   "%s :: Latitudes of defining points are equal." },
 { cs_CSQ_LLRNG,   csET_NM,cs_ERSUP_OPR,
						   "%s :: Longitude range is too small." },
 {   cs_CSQ_LNG,   csET_NM,cs_ERSUP_OPR,
						   "%s :: Invalid longitude detected in definition." },
 {cs_CSQ_LNGEQU,   csET_NM,cs_ERSUP_OPR,
						   "%s :: First defining point may not be on the equator." },
 {cs_CSQ_MAPSCL,   csET_NM,cs_ERSUP_OPR,
						   "%s :: Invalid map scale value detected." },
 {cs_CSQ_MEREQU,   csET_NM,cs_ERSUP_OPR,
						   "%s :: Standard meridians are the same." },
 { cs_CSQ_MRCAT,   csET_NM,cs_ERSUP_OPR,
						   "%s :: Defining great circle is a parallel, try Mercator." },
 {cs_CSQ_MSCOEF,   csET_NM,cs_ERSUP_OPR,
						   "%s :: Invalid coefficient value specified." },
 { cs_CSQ_NOREF,   csET_NM,cs_ERSUP_OPR,
						   "%s :: System must be referenced to a datum or an ellipsoid." },
 {cs_CSQ_NOTNRTH,  csET_NM,cs_ERSUP_OPR,
						   "%s :: Standard paralells are not ordered correctly." },
 {cs_CSQ_NRTHLAT,  csET_NM,cs_ERSUP_OPR,
						   "%s :: Standard parallells are not ordered correctly." },
 { cs_CSQ_NRTHPNT, csET_NM,cs_ERSUP_OPR,
						   "%s :: Point defining Y axis direction incorrectly specified." },
 {  cs_CSQ_ORGLAT, csET_NM,cs_ERSUP_OPR,
						   "%s :: Invalid latitude value given for projection origin." },
 {  cs_CSQ_ORGLNG, csET_NM,cs_ERSUP_OPR,
						   "%s :: Invalid longitude value given for projection origin." },
 {   cs_CSQ_PLL90, csET_NM,cs_ERSUP_OPR,
						   "%s :: Standard parallel location exceeds 90 degrees." },
 {  cs_CSQ_PLLEQU, csET_NM,cs_ERSUP_OPR,
						   "%s :: Standard parallel locations are the same." },
 {  cs_CSQ_PLLLRG, csET_NM,cs_ERSUP_OPR,
						   "%s :: Standard parallel locations not inbetween poles." },
 {  cs_CSQ_PLLREV, csET_NM,cs_ERSUP_OPR,
						   "%s :: Order of standard parallels incorrect." },
 { cs_CSQ_PLLZERO, csET_NM,cs_ERSUP_OPR,
						   "%s :: Standard parallel location is zero." },
 {   cs_CSQ_POLDD, csET_NM,cs_ERSUP_OPR,
						   "%s :: Poles are too far apart." },
 {  cs_CSQ_POLDUP, csET_NM,cs_ERSUP_OPR,
						   "%s :: Poles are not sufficiently separated." },
 {  cs_CSQ_POLLAT, csET_NM,cs_ERSUP_OPR,
						   "%s :: Latitude of pole incorrectly specified." },
 {  cs_CSQ_POLLNG, csET_NM,cs_ERSUP_OPR,
						   "%s :: Longitude of pole incorrectly specified." },
 {    cs_CSQ_QUAD, csET_NM,cs_ERSUP_OPR,
						   "%s :: Invalid quad specification detected." },
 {  cs_CSQ_RNGORD, csET_NM,cs_ERSUP_OPR,
						   "%s :: Longitude range values out of order." },
 {  cs_CSQ_SCLRED, csET_NM,cs_ERSUP_OPR,
						   "%s :: Invalid scale reduction value encountered." },
 { cs_CSQ_SOTHLAT, csET_NM,cs_ERSUP_OPR,
						   "%s :: Standard parallels are not ordered correctly." },
 {  cs_CSQ_STDLAT, csET_NM,cs_ERSUP_OPR,
						   "%s :: Standard parallel is incorrectly specified." },
 {  cs_CSQ_STDLNG, csET_NM,cs_ERSUP_OPR,
						   "%s :: Standard meridian specification is invalid." },
 {  cs_CSQ_STDPLL, csET_NM,cs_ERSUP_OPR,
						   "%s :: Standard parallel specifications are invalid." },
 {  cs_CSQ_STDSOU, csET_NM,cs_ERSUP_OPR,
						   "%s :: Southern parallel is equal to or north of northern." },
 { cs_CSQ_STDWEST, csET_NM,cs_ERSUP_OPR,
						   "%s :: Standard meridian must be east of the central meridian." },
 {    cs_CSQ_UNIT, csET_NM,cs_ERSUP_OPR,
						   "%s :: Invalid unit specification detected." },
 {  cs_CSQ_INVPRJ, csET_NM,cs_ERSUP_OPR,
						   "%s :: Invalid projection key name detected." },
 {  cs_CSQ_INVDTM, csET_NM,cs_ERSUP_OPR,
						   "%s :: Invalid datum name specification detected." },
 {  cs_CSQ_INVELP, csET_NM,cs_ERSUP_OPR,
						   "%s :: Invalid ellipsoid name specification detected." },
 {   cs_CSQ_LLRNG, csET_NM,cs_ERSUP_OPR,
						   "%s :: Invalid Lat/Long range specification detected." },
 {  cs_CSQ_RNGORD, csET_NM,cs_ERSUP_OPR,
						   "%s :: Order of Lat/Long range specification is improper." },
 { cs_CSQ_INVQUAD,csET_NM,cs_ERSUP_OPR,
						   "%s :: Invalid quadrant specification given." },
 {   cs_CSQ_GEOMM,csET_NM,cs_ERSUP_OPR,
						   "%s :: Invalid invalid geographic useful range detected." },
 {   cs_CSQ_CRTMM,csET_NM,cs_ERSUP_OPR,
						   "%s :: Invalid invalid cartesian useful range detected." },
 {   cs_CSQ_PLLED, csET_NM,cs_ERSUP_OPR,
						   "%s :: Standard parallels must be equidistant from poles." },
 {  cs_CSQ_PLRLAT, csET_NM,cs_ERSUP_OPR,
						   "%s :: Origin latitude is not polar; use oblique form of projection." },
 {  cs_CSQ_USEPLR, csET_NM,cs_ERSUP_OPR,
						   "%s :: Origin latitude is polar; use polar form of projection." },
 {  cs_CSQ_UTMZON, csET_NM,cs_ERSUP_OPR,
						   "%s :: Invalid value given for UTM zone number." },
 { cs_CSQ_HMISPHR, csET_NM,cs_ERSUP_OPR,
						   "%s :: Invalid hemisphere specification (+1 == north, -1 == south)." },
 {   cs_CSQ_USESW, csET_NM,cs_ERSUP_OPR,
						   "%s :: Central azimuth is 90, use the Swiss Oblique Mercator." },
 {   cs_CSQ_MAX15, csET_NM,cs_ERSUP_OPR,
						   "%s :: Eastern meridian is more than 15 degrees from the central meridian." },
 {cs_CSQ_OBLQPOLE, csET_NM,cs_ERSUP_OPR,
						   "%s :: Invalid oblique pole specification." },
 { cs_CSQ_AFFZERO, csET_NM,cs_ERSUP_OPR,
						   "%s :: Affine coefficients produced an inverse denominator of zero." },
 { cs_CSQ_NRDATUM, csET_NM,cs_ERSUP_OPR,
						   "%s :: Non-georeferenced system may not be referenced to a datum, use an ellipsoid instead." },
 {  cs_CSQ_OSTN97, csET_NM,cs_ERSUP_OPR,
						   "%s :: OSTN97.TXT grid shift file could not be located or opened with read access." },
 {  cs_CSQ_DENRGN, csET_NM,cs_ERSUP_OPR,
						   "%s :: Invalid region code specified for Danish System 34/45 (1=J, 2=S, 3=B)." },
 {  cs_CSQ_ELEVEL, csET_NM,cs_ERSUP_OPR,
						   "%s :: Value supplied for elevated ellipsoid is outside acceptable range." },
 {  cs_CSQ_OSTN02, csET_NM,cs_ERSUP_OPR,
						   "%s :: OSTN02.TXT grid shift file could not be located or opened with read access." },
 {  cs_CSQ_TMKRG0, csET_NM,cs_ERSUP_OPR,
						   "%s :: Transverse Mercator Kruger formulation requested with non-zero origin latitude." },
 {     cs_MGRS_LL,csET_LOC,cs_ERSUP_OPR,
						   "Invalid Lat/Long (%s) presented for MGRS conversion." },
 {   cs_MGRS_ZONE,       0,cs_ERSUP_SOFT,
						   "Invalid zone number presented for UTM/UPS to Lat/Long conversion." },
 {    cs_MGRS_UTM,       0,cs_ERSUP_SOFT,
						   "Invalid UTM or UPS coordinate presented for UTM/UPS to Lat/Long conversion." },
 {     cs_MGRS_XY,       0,cs_ERSUP_SOFT,
						   "Invalid UTM or UPS coordinate presented for conversion to MGRS." },
 {   cs_MGRS_STR1, csET_NM,cs_ERSUP_OPR,
						   "MGRS string invalid: '%s' contains an invalid polar 100K quad identifier." },
 {   cs_MGRS_STR2, csET_NM,cs_ERSUP_OPR,
						   "MGRS string invalid: '%s' contains an odd number of trailing digits." },
 {   cs_MGRS_STR3, csET_NM,cs_ERSUP_OPR,
						   "MGRS string invalid: '%s' contains too many trailing digits (10 max)." },
 {   cs_MGRS_STR4, csET_NM,cs_ERSUP_OPR,
						   "MGRS string invalid: '%s' contains a non-digit where a digit was expected." },
 {   cs_MGRS_STR5, csET_NM,cs_ERSUP_OPR,
						   "MGRS string invalid: '%s' references a non-existant zone." },
 {   cs_MGRS_STR6, csET_NM,cs_ERSUP_OPR,
						   "MGRS string invalid: the 8 degree latitude zone designation in '%s' is invalid." },
 {   cs_MGRS_STR7, csET_NM,cs_ERSUP_OPR,
						   "MGRS string invalid: the easting portion of the 100K meter quad designation in '%s' is not valid." },
 {   cs_MGRS_STR8, csET_NM,cs_ERSUP_OPR,
						   "MGRS string invalid: the northing portion of the 100K meter quad designation in '%s' is not valid." },
 {   cs_MGRS_STR9, csET_NM,cs_ERSUP_OPR,
						   "MGRS string invalid: the 8 degree latitude zone and the 100K meter quad designations in '%s' are inconsistent." },
 {   cs_MGRS_STRA, csET_NM,cs_ERSUP_OPR,
						   "MGRS string invalid: processing of '%s' produced a range/domain error on conversion to geogrpahic form." },
 {   cs_MGRS_STRB, csET_NM,cs_ERSUP_OPR,
						   "MGRS string invalid: '%s' contains an invalid UTM zone number or UPS zone designator." },
 {   cs_MGRS_STRC,       0,cs_ERSUP_OPR,
						   "MGRS string may be invalid; resulting longitude is actually in a different zone." },
 {  cs_MGRS_NOSET,       0,cs_ERSUP_OPR,
						   "High level interface MGRS functions have not been initialized with cs_mgrsSetUp." },
 {  cs_FLBK_NOSET, csET_NM,cs_ERSUP_OPR,
						   "No fallback datum specified in geodetic data catalog file named %s." },
 {  cs_FLBK_NTFND, csET_NM,cs_ERSUP_OPR,
						   "Fallback datum specified in geodetic data catalog file named %s does not exist." },
 {  cs_FLBK_WRNGT, csET_NM,cs_ERSUP_OPR,
						   "Fallback datum specified in geodetic data catalog file named %s is of the wrong type." },
 {   cs_NOT_NERTH,       0,cs_ERSUP_OPR,
						   "Conversion from a NERTH type definition to anyother type is not supported." },
 {   cs_NAD_RNG_A,csET_LOC,cs_ERSUP_OPR,
						   "WARNING: Data in range %s is outside NAD27<->NAD83 NADCON coverage; using fallback approximation." },
 { cs_AGD66_RNG_A,csET_LOC,cs_ERSUP_OPR,
						   "WARNING: Data in range %s is outside AGD66<->GDA94 data file coverage; using fallback approximation." },
 { cs_AGD84_RNG_A,csET_LOC,cs_ERSUP_OPR,
						   "WARNING: Data in range %s is outside AGD84<->GDA94 data file coverage; using fallback approximation." },
 {cs_NZGD49_RNG_A,csET_LOC,cs_ERSUP_OPR,
						   "WARNING: Data in range %s is outside NZGD49<->NZGD2K data file coverage; using fallback approximation." },
 { cs_ATS77_RNG_A,csET_LOC,cs_ERSUP_OPR,
						   "WARNING: Data in range %s is outside ATS77<->CSRS data file coverage; using fallback approximation." },
 {  cs_HARN_RNG_A,csET_LOC,cs_ERSUP_OPR,
						   "WARNING: Data in range %s is outside NAD83<->HARN/HPGN NADCON data file coverage; using fallback approximation." },
 {  cs_CSRS_RNG_F,csET_LOC,cs_ERSUP_RNG,
						   "Encountered data at %s which is outside NAD83<->CSRS data file coverage."},
 {  cs_CSRS_RNG_W,csET_LOC,cs_ERSUP_RNG,
						   "WARNING: Data in range %s is outside NAD83<->CSRS data file coverage; conversion results are unshifted."},
 {  cs_CSRS_RNG_A,csET_LOC,cs_ERSUP_OPR,
						   "WARNING: Data in range %s is outside NAD83<->CSRS data file coverage; using fallback approximation." },
 { cs_DTC_SOFTMAX, csET_NM,cs_ERSUP_OPR,
						   "Datum shift calculations for the datum named %s have produced the tenth (or more data) file coverage error. This is considered to be a hard error." },
 { cs_MREG_RANGEF, csET_NM,cs_ERSUP_OPR,
						   "Data to be converted was outside the usable range of the multiple regression formula, and fallback data is not supplied in definition." },
 {  cs_MREG_CNVRG, csET_NM,cs_ERSUP_OPR,
						   "Multiple regression 2D inverse calculation failed to converge." },
 {cs_DTC_SOFTIGNR, csET_NM,cs_ERSUP_OPR,
						   "Ten datum shift data availablity errors have been reported; reporting of additional such situations is being suppressed." },
 {  cs_GEOID_INIT,       0,cs_ERSUP_CONFIG,
						   "Geiod height calculation sub-system was not initialized properly." },
 {  cs_TOKYO_ICNT,       0,cs_ERSUP_RNG,
						   "Inverse Japanese Geodetic Datum of 2000 calculation failed to converge." },
 { cs_TOKYO_RNG_F,csET_LOC,cs_ERSUP_RNG,
						   "Encountered data at %s which is outside Tokyo<->Jgd2k data file coverage."},
 { cs_TOKYO_RNG_W,csET_LOC,cs_ERSUP_RNG,
						   "WARNING: Data in range %s is outside Tokyo<->Jgd2k data file coverage; conversion results are unshifted."},
 { cs_TOKYO_RNG_A,csET_LOC,cs_ERSUP_OPR,
						   "WARNING: Data in range %s is outside Tokyo<->Jgd2k data file coverage; using fallback approximation." },
 {   cs_TOKYO_EXT,       0,cs_ERSUP_CONFIG,
						   "Invalid extension, or missing extension, encountered in JGD2K datum shift catalog."},
 {  cs_RGF93_ICNT,       0,cs_ERSUP_RNG,
						   "Inverse RGF93 calculation failed to converge." },
 { cs_RGF93_RNG_F,csET_LOC,cs_ERSUP_RNG,
						   "Encountered data at %s which is outside RGF93<->NTF data file coverage."},
 { cs_RGF93_RNG_W,csET_LOC,cs_ERSUP_RNG,
						   "WARNING: Data in range %s is outside RGF93<->NTF data file coverage; conversion results are unshifted."},
 { cs_RGF93_RNG_A,csET_LOC,cs_ERSUP_OPR,
						   "WARNING: Data in range %s is outside RGF93<->NTF data file coverage; using fallback approximation." },
 {cs_CSRS27_RNG_F,csET_LOC,cs_ERSUP_RNG,
						   "Encountered data at %s which is outside NAD27<->CSRS data file coverage."},
 {cs_CSRS27_RNG_W,csET_LOC,cs_ERSUP_RNG,
						   "WARNING: Data in range %s is outside NAD27<->CSRS data file coverage; conversion results are unshifted."},
 {cs_CSRS27_RNG_A,csET_LOC,cs_ERSUP_OPR,
						   "WARNING: Data in range %s is outside NAD27<->CSRS data file coverage; using fallback approximation." },
 {  cs_ED50_RNG_F,csET_LOC,cs_ERSUP_RNG,
						   "Encountered data at %s which is outside ED50<->ETRF89 data file coverage."},
 {  cs_ED50_RNG_W,csET_LOC,cs_ERSUP_RNG,
						   "WARNING: Data in range %s is outside ED50<->ETRF89 data file coverage; conversion results are unshifted."},
 {  cs_ED50_RNG_A,csET_LOC,cs_ERSUP_OPR,
						   "WARNING: Data in range %s is outside ED50<->ETRF89 data file coverage; using fallback approximation." },
 {   cs_UADD_TYPE, csET_NM,cs_ERSUP_SOFT,
						   "Attempt to add unit named %s failed.  Invalid unit type specification given." },
 {    cs_UADD_DUP, csET_NM,cs_ERSUP_SOFT,
						   "Attempt to add unit named %s failed.  A unit specification with that name already exists." },
 {   cs_UADD_FULL, csET_NM,cs_ERSUP_SOFT,
						   "Attempt to add unit named %s failed.  All available slots in the unit table are already being used." },
 {   cs_UDEL_NONE, csET_NM,cs_ERSUP_SOFT,
						   "Attempt to deactivate unit named %s failed.  A unit with that name (and type) does not exist." },
 {cs_N27A77_RNG_F,csET_LOC,cs_ERSUP_RNG,
						   "Encountered data at %s which is outside NAD27<->ATS77 data file coverage."},
 {cs_N27A77_RNG_W,csET_LOC,cs_ERSUP_RNG,
						   "WARNING: Data in range %s is outside NAD27<->ATS77 data file coverage; conversion results are unshifted."},
 {cs_N27A77_RNG_A,csET_LOC,cs_ERSUP_OPR,
						   "WARNING: Data in range %s is outside NAD27<->ATS77 data file coverage; using fallback approximation." },
 { cs_GDC_DENSITY, csET_NM,cs_ERSUP_OPR,
						   "Invalid density value detected in geodetic data catalog file named %s." },
 { cs_LLENUM_NOSU,       0,cs_ERSUP_SOFT,
						   "Setup was not called successfully prior to a useful range coordinate system enumeration attempt." },
 { cs_WKT_WRNGTYP,       0,cs_ERSUP_SOFT,
						   "The text presented as a WKT definition for conversion to native form was of the wrong type." },
 { cs_WKT_NOELLIP,       0,cs_ERSUP_DATA,
						   "The text presented as a WKT definition for conversion did not contain a SPHEROID definition as is required." },
 { cs_WKT_NODATUM,       0,cs_ERSUP_DATA,
						   "The text presented as a WKT definition for conversion did not contain a DATUM specification as is required." },
 {  cs_WKT_NOUNIT,       0,cs_ERSUP_DATA,
						   "The text presented as a WKT definition for conversion did not contain a UNIT definition as is required." },
 { cs_WKT_INVUNIT, csET_NM,cs_ERSUP_DATA,
						   "The text presented as a WKT definition for conversion contained a UNIT definition (%s) which is not supported." },
 { cs_WKT_NOGEOCS,       0,cs_ERSUP_DATA,
						    "The text presented as a WKT definition for conversion did not contain a GEOGCS definition as is required." },
 { cs_WKT_NOGUNIT,       0,cs_ERSUP_DATA,
						    "The GEOGCS definition contained within the text presented as a WKT definition did not contain a UNIT specification." },
 {cs_WKT_INVGUNIT, csET_NM,cs_ERSUP_DATA,
						    "The UNIT specification within the GEOGCS definition contained within the text presented as a WKT definition, contained an unrecognized unit name (%s)." },
 {  cs_WKT_NOPROJ,       0,cs_ERSUP_DATA,
						    "The text presented as a WKT definition for conversion did not contain a PROJECTION specification as is required." },
 { cs_WKT_INVPROJ, csET_NM,cs_ERSUP_DATA,
						    "The PROJECTION specification contained within the text presented as a WKT definition specified an unsupported projection (%s)." },
 { cs_WKT_GEOGCNT, csET_NM,cs_ERSUP_DATA,
						    "Could not locate two GEOGCS objects in the GEOGTRAN object named %s.  Exactly two are required." },
 { cs_WKT_NOSRCDT, csET_NM,cs_ERSUP_DATA,
						    "Could not locate a DATUM object in the first of the two GEOGCS objects in the GEOGTRAN object named %s." },
 { cs_WKT_NOMETH,  csET_NM,cs_ERSUP_DATA,
						    "Could not locate a METHOD object in the GEOGTRAN object named %s." },
 { cs_WKT_MTHERR,  csET_NM,cs_ERSUP_DATA,
						    "The parameters provided and the METHOD specified for GEOGTRAN named %s are inconsistent." },
 { cs_WKT_UKMETH,  csET_NM,cs_ERSUP_DATA,
						    "The GEOGTRAN object named %s contains a METHOD specification which is not recognized." },
 { cs_WKT_WRNGTRG, csET_NM,cs_ERSUP_DATA,
						    "The GEOGTRAN object named %s does not have \"WGS_1984\" as the target datum.  GEOGTRANS must produce WGS84 to be converted." },
 {cs_WKT_PRMSUPRT, csET_NM,cs_ERSUP_DATA,
						    "WKT system named %s uses a parameter arrangement unsupported by CS-MAP." },
 {cs_WKT_UNITMAP,  csET_NM,cs_ERSUP_DATA,
						    "WKT conversion failed; the WKT equivalent for the %s unit is unknown." },
 {cs_WKT_PRJSUPRT, csET_NM,cs_ERSUP_DATA,
						    "The WKT equivalent for the %s projection is either non-existent or incompatible.  WKT conversion failed." },
 {cs_WKT_NODTMNM,        0,cs_ERSUP_DATA,
						    "The WKT definition contained an unnamed DATUM specification in addition to not having a TOWGS84 specification." },
 {cs_WKT_NODTMSPC, csET_NM,cs_ERSUP_DATA,
						    "The WKT definition did not contan a TOWGS84 specification and a datum with the name given, %s, could not be found in the dictionary." },
 {cs_WKT_NOLLBASE, csET_NM,cs_ERSUP_DATA,
						    "The datum reference of the coordinate system named %s could not be converted to a valid geographic system reference." },
 { cs_WKT_NODTREF, csET_NM,cs_ERSUP_DATA,
						    "%s is cartographically referenced.  WKT does not support this, conversion to WKT failed." },
 {   cs_WLD_NOSOL,       0,cs_ERSUP_DATA,
						    "The control points provided to the .WLD file calculator failed to produce a unique solution." },
 {cs_WKT_BADFORM,  csET_NM,cs_ERSUP_DATA,
						    "WKT string provided is incorrectly formed and cannot be parsed.  The invalid string begins with: %s" },
 {cs_WKT_DTMAP,    csET_NM,cs_ERSUP_DATA,
						    "WKT string referenced datum named '%s'.  This datum name could not be mapped to a dictionary definition" },
 {cs_WKT_FLAVOR,   csET_NM,cs_ERSUP_DATA,
						    "Flavor of WKT string named '%s' could not be determined." },
 {cs_WKT_INCNSIST,       0,cs_ERSUP_DATA,
						    "Information provided to the WKT formatting functions is inconsistent." },
 {  cs_DHDN_RNG_F,csET_LOC,cs_ERSUP_RNG,
						   "Encountered data at %s which is outside DHDN<->ETRF89 data file coverage."},
 {  cs_DHDN_RNG_W,csET_LOC,cs_ERSUP_RNG,
						   "WARNING: Data in range %s is outside DHDN<->ETRF89 data file coverage; conversion results are unshifted."},
 {  cs_DHDN_RNG_A,csET_LOC,cs_ERSUP_OPR,
						   "WARNING: Data in range %s is outside DHDN<->ETRF89 data file coverage; using fallback approximation." },
 {              0,       0,0,""}
};

void EXP_LVL9 CSsprntf (char *dst,int size,char *frmt,char *insert);
void EXP_LVL9 CSreltoa (char *rslt,int size,long value);

unsigned short EXP_LVL7 CSerpt (char *mesg,int size,int err_num)

{
	extern char csErrnam [];
	extern int csErrlng;
	extern int csErrlat;
	extern int cs_Error;
	extern int cs_Errno;
#if _RUN_TIME < _rt_UNIXPCC
	extern unsigned long cs_Doserr;
#endif

	char dir_cc;

	long ltemp;

  	char *cp;
	struct csErrtab_ *err_ptr;

	char ctemp [32];
	char insert [32];

#if _RUN_TIME == _rt_WINCE
	cs_Errno = GetLastError ();
	cs_Doserr = cs_Errno;
#elif _RUN_TIME < _rt_UNIXPCC
	cs_Errno = errno;
	cs_Doserr = _doserrno;
#else
	cs_Errno = errno;
#endif

	cs_Error = err_num;

	/* Locate the appropriate message. */

	for (err_ptr = csErrtab;err_ptr->code != 0;err_ptr++)
	{
		if (err_ptr->code == err_num)
		{
			switch (err_ptr->type) {

			case csET_NM:
				CSsprntf (mesg,size,err_ptr->msg,csErrnam);
				break;

			case csET_LOC:
				/* Build a string which defines the
				   location.  We desire to do this
				   re-entrantly. */
				ltemp = -csErrlng;
				dir_cc = 'W';
				if (csErrlng >= 0)
				{
					ltemp = csErrlng;
					dir_cc = 'E';
				}
				CSreltoa (ctemp,sizeof (ctemp),ltemp);
				cp = CS_stcpy (insert,ctemp);
				*cp++ = dir_cc;
				*cp++ = ':';
				
				ltemp = csErrlat;
				dir_cc = 'N';
				if (csErrlat < 0)
				{
					ltemp = -csErrlat;
					dir_cc = 'S';
				}
				CSreltoa (ctemp,sizeof (ctemp),ltemp);
				cp = CS_stcpy (cp,ctemp);
				*cp++ = dir_cc;
				*cp++ = '\0';

				CSsprntf (mesg,size,err_ptr->msg,insert);
				break;
				
			default:
				CS_stncp (mesg,err_ptr->msg,size);
				break;
			}

			/* Break out of the search loop. */
			break;
		}
	}

	/* In code we didn't find the message in the table, a
	   software bug. */
	if (err_ptr->code == 0)
	{
		CSreltoa (ctemp,sizeof (ctemp),(long)err_num);
		CSsprntf (mesg,size,"Error condition #%s encountered; no message in table.",ctemp);
	}

	/* Return to the calling module for cleanup. */
	return (err_ptr->sup_grp);
}

/*
	A reentrant means of doing ltoa.  It will not exceed
	the size of the provided destination array.
*/

void EXP_LVL9 CSreltoa (char *rslt,int size,long value)

{
	int minus;

	char *cp;

	char my_val [12];

	minus = FALSE;
	if (value < 0L)
	{
		minus = TRUE;
		value = -value;
	}
	cp = &my_val [11];
	*cp = '\0';
	if (value == 0L) *--cp = '0';
	while (value > 0)
	{
		*--cp = (char)((value % 10) | '0');
		value /= 10;
	}
	if (minus) *--cp = '-';

	/* Copy the result back, left justified. */
	size -= 1;
	while (*cp != '\0' && size >= 0)
	{
		if (size == 1 && *(cp + 1) != '\0')			/*lint !e796 */
		{
			*rslt = '*';
		}
		else
		{
			*rslt++ =*cp++;
		}
		size -= 1;
	}
	*rslt = '\0';
	return;
}

/*
	The following does a very simple sprintf, but will
	not attempt to exceed the size of the destination
	array.

	NOTE: by simple sprintf, we mean it recognizes a
	single %s soecification in the format string.  This
	reference is replaced with the string given by
	the insert argument.
*/

void EXP_LVL9 CSsprntf (char *dst,int size,char *frmt,char *insert)

{
	size -= 1;
	while (*frmt != '\0' && size > 0)
	{
		if (*frmt == '%' &&
		    *(frmt + 1) == 's')
		{
			while (*insert != '\0' && size > 0)
			{
				*dst++ = *insert++;
				size -= 1;
			}
			frmt += 2;
			continue;
		}
		*dst++ = *frmt++;
		size -= 1;
	}
	*dst = '\0';
	return;
}

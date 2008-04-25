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

			 File Name: $RCSfile: CS_japan.c $
		   Description:
			   Purpose:

		Revision Level:	$Revision: #6 $
		 Check In Date:	$Date: 2006/11/27 $

		Last Revision:	$Log: CS_japan.c $
		Last Revision:	Revision 11.1300  2005/05/25 23:27:13  nto
		Last Revision:	Official Release 11.13
		Last Revision:	Revision 11.1200  2005/01/15 18:27:13  nto
		Last Revision:	Official Release of CS-MAP 11.12, 11:26am 15 Jan 2005
		Last Revision:	Revision 11.1100  2004/11/01 18:53:10  nto
		Last Revision:	Official release 11.11
		Last Revision:	Revision 11.1001  2004/10/07 19:25:18  nto
		Last Revision:	Revision 11.900  2004/03/26 17:02:25  nto
		Last Revision:	Official release: 11.09 - 3/25/2003
		Last Revision:	Revision 11.800  2004/01/13 23:29:14  nto
		Last Revision:	Revision 11.700  2003/12/19 01:49:54  nto
		Last Revision:	Official release 11.07
		Last Revision:	Revision 11.600  2003/12/04 02:46:29  nto
		Last Revision:	Release 11.06.  Never shipped. Source captured in prep for C++ V7.
		Last Revision:	Revision 11.502  2003/11/24 01:12:08  nto
		Last Revision:	Correct very remote possibility of addressing fault when errors occur.
		Last Revision:	Revision 11.501  2003/08/22 21:12:56  nto
		Last Revision:	Official Release: 11.05
		Last Revision:	Revision 11.401  2003/05/01 23:06:23  nto
		Last Revision:	Revision 11.300  2003/02/25 04:29:17  nto
		Last Revision:	Official Release 11.03
		Last Revision:	Revision 11.100  2002/11/22 19:38:45  nto
		Last Revision:	Official release: 11.01
		Last Revision:	Revision 10.1504  2002/11/13 23:06:17  nto
		Last Revision:	The name of a GridCell element got changed somewhere along the line.
		Last Revision:	Revision 10.1503  2002/10/13 00:28:41  nto
		Last Revision:	Removed references to the stat: function, header, and structure.
		Last Revision:	Revision 10.1502  2002/10/06 17:51:52  nto
		Last Revision:	Adjusted the open mode of the binary file when created so it could be sorted.
		Last Revision:	Revision 10.1501  2002/10/03 00:00:10  nto
		Last Revision:	Removed UNIX I/O in favor of ANSI stream I/O.
		Last Revision:	Revision 10.1500  2002/09/22 00:01:21  nto
		Last Revision:	Official Release:= 10.15
		Last Revision:	Revision 10.1400  2002/08/09 18:14:23  nto
		Last Revision:	Revision 10.1200  2002/07/14 03:26:17  nto
		Last Revision:	Revision 10.1100  2002/06/13 14:18:38  nto
		Last Revision:	Release 10.11 Official
		Last Revision:	Revision 10.1000  2002/02/23 21:18:27  nto
		Last Revision:	Official Release of 10.10, 2/22/02 - Norm Olsen
		Last Revision:	Revision 1.1  2002/02/19 05:44:00  nto
		Last Revision:	Initial Revision

******************************************************************************/

#ifdef LABEL_MODULE
static char revlvl [] = {"$Id"};
#endif

#include "cs_map.h"

/******************************************************************************
	The following is used to maintain the status of the Tokyo<-->Jgd2k
	conversion system.  Namely, if its already opened, we don't have to
	open it again.  Upon close, we release resources, but don't actually
	destruct.  The counter keeps track of the number of opens.
*/
struct csTokyoToJgd2k_ *csTokyoToJgd2k = NULL;
int csTokyoToJgd2kCnt = 0;
/******************************************************************************
	Initialize the Tokyo <--> Jgd2k conversion system.  The catalog file is
	expected to	reside in the basic data directory.  The name of the file is
	taken from the cs_Jgd2kName global variable.
*/
int EXP_LVL7 CSjgd2kInit ()
{
	extern char cs_Dir [];
	extern char* cs_DirP;
	extern char cs_Jgd2kName [];

	char catalog [MAXPATH];

	if (csTokyoToJgd2k == NULL)
	{
		/* Set up the catalog file name. */
		CS_stcpy (cs_DirP,cs_Jgd2kName);
		CS_stncp (catalog,cs_Dir,sizeof (catalog));

		/* USe this catalog to build a list of the files we are to use. */
		csTokyoToJgd2k = CSnewTokyoToJgd2k (catalog);
		if (csTokyoToJgd2k == NULL) goto error;
	}
	csTokyoToJgd2kCnt += 1;
	return 0;
error:
	if (csTokyoToJgd2k != NULL)
	{
		CSdeleteTokyoToJgd2k (csTokyoToJgd2k);
		csTokyoToJgd2k = NULL;
		csTokyoToJgd2kCnt = 0;
	}
	return -1;
}
/******************************************************************************
	Close the Tokyo <--> Jgd2k conversion system.  Note, this only does a
	release, not a full delete.  This is for performance reasons.  During
	test, you may get a "memory leak message" because of this.  If this is
	undesirable, then change the 'release' function to the 'delete' function.
*/
void EXP_LVL7 CSjgd2kCls ()
{
	csTokyoToJgd2kCnt -= 1;
	if (csTokyoToJgd2kCnt <= 0)
	{
		if (csTokyoToJgd2k != NULL)
		{
			CSdeleteTokyoToJgd2k (csTokyoToJgd2k);
			csTokyoToJgd2k = NULL;
		}
		csTokyoToJgd2kCnt = 0;
	}
	return;
}
/**********************************************************************
	Convert from the older Tokyo datum to the newer JGD2000
*/
int EXP_LVL7 CStokyoToJgd2k (double llJgd2k [3],Const double llTokyo [3])
{
	int status;
	double lclJgd2k [3];

	/* Set the default return values.  We need this to allow both input
	   arrays to be the same physical memory. */
	lclJgd2k [LNG] = llTokyo [LNG];
	lclJgd2k [LAT] = llTokyo [LAT];

	/* Make sure we have been initialized. */
	if (csTokyoToJgd2k == NULL)
	{
		CS_erpt (cs_DTC_NO_SETUP);
		status = -1;
	}
	else
	{
		status = CScalcTokyoToJgd2k (csTokyoToJgd2k,lclJgd2k,llTokyo);
	}

	/* Return the results. */
	if (status >= 0)
	{
		llJgd2k [LNG] = lclJgd2k [LNG];
		llJgd2k [LAT] = lclJgd2k [LAT];
	}
	return status;
}
/**********************************************************************
	The inverse calcultaion.
*/
int EXP_LVL7 CSjgd2kToTokyo (double llTokyo [3],Const double llJgd2k [3])
{
	int status;
	double lclTokyo [3];

	/* Set the default return values.  We need this to allow both input
	   arrays to be the same physical memory. */
	lclTokyo [LNG] = llJgd2k [LNG];
	lclTokyo [LAT] = llJgd2k [LAT];

	/* Make sure we have been initialized. */
	if (csTokyoToJgd2k == NULL)
	{
		CS_erpt (cs_DTC_NO_SETUP);
		status = -1;
	}
	else
	{
		status = CSinverseTokyoToJgd2k (csTokyoToJgd2k,lclTokyo,llJgd2k);
	}

	/* Return the results. */
	if (status >= 0)
	{
		llTokyo [LNG] = lclTokyo [LNG];
		llTokyo [LAT] = lclTokyo [LAT];
	}
	return status;
}
/******************************************************************************
	The following function returns the mesh code appropriate for the given
	geographic coordinates provided.  Note, it is expected that the calling
	module deals with the rounding to the appropriate grid point.

	This function returns a zero to indicate an error.  Zero is not, under
	any circumstances, a valid mesh code.
*/
unsigned long EXP_LVL9 CSjpnLlToMeshCode (const double ll [2])
{
	extern char csErrnam [];

	unsigned long mesh;
	unsigned long iLat, iLng;

	/* Verify that we are in the proper range.  This prevents many nasty
	   situations such as overflow. */
	if (ll [0] < 120.0 || ll [0] > 160.0 || ll [1] <  20.0 || ll [1] >  60.0)
	{
		CS_stncp (csErrnam,"CS_jpnMeshCode:1",MAXPATH);
		CS_erpt (cs_ISER);
		return 0;
	}

	/* Compute the mesh numbers for each value. */
	iLat = ((unsigned long)CS_degToSec (ll [1])) / 30;
	iLng = ((unsigned long)CS_degToSec (ll [0] - 100.0)) / 45;

	/* We do the last two digits; these range from 0 thru 9.  Each increment in
	   longitude represents 45 seconds of longitude.  Each increment in
	   latitude represents 30 seconds of latitude. */
	mesh  =  iLng % 10;
	mesh += (iLat % 10) * 10;

	/* Next two digits, range from 0 thru 7.  Each increment of longitude represents
	   7.5 minutes (450 seconds).  Each increment of latitude represents 5 minutes
	   (300 seconds). */
	mesh += ((iLng / 10) % 8) * 100;
	mesh += ((iLat / 10) % 8) * 1000;

	/* Now for the last set of four digits.  Each increment of latitude represents
	   40 minutes (2400 sceonds) and each increment of longitude repsents 12 degree
	   (3600 seconds) of longitude.  Note that we biased the longitude by 100 degrees
	   above. */
	mesh += ((iLng / 80) % 100) *   10000;
	mesh += ((iLat / 80) % 100) * 1000000;
	return mesh;
}
void EXP_LVL9 CSjpnMeshCodeToLl (double ll [2],unsigned long meshCode)
{
	extern double cs_Sec2Deg;		/* 1.0 / 3600.00 */

	unsigned long iLat, iLng;		/* in seconds, lng - 100. */

	iLng = ((meshCode /        1) % 10) * 45;
	iLat = ((meshCode /       10) % 10) * 30;

	iLng += ((meshCode /     100) % 10) * 450;
	iLat += ((meshCode /    1000) % 10) * 300;

	iLng += ((meshCode /   10000) % 100) * 3600;
	iLat += ((meshCode / 1000000) % 100) * 2400;

	ll [0] = (double)iLng * cs_Sec2Deg + 100.0;
	ll [1] = (double)iLat * cs_Sec2Deg;

	return;
}
int EXP_LVL9 CScompareJgd2kGridRecord (const struct csJgd2kGridRecord_ *elem1,const struct csJgd2kGridRecord_ *elem2)
{
	int rtnVal = 0;

	if (elem1->meshCode < elem2->meshCode) rtnVal = -1;
	else if (elem1->meshCode > elem2->meshCode) rtnVal = 1;
	return rtnVal;
}
struct csJgd2kGridFile_* EXP_LVL7 CSnewJgd2kGridFile (Const char *path,long bufferSize,unsigned long flags,double density)
{
	extern char cs_DirsepC;
	extern char csErrnam [];

	int st;
	char *cp;
	struct csJgd2kGridFile_ *__This = NULL;

	char lineBufr [MAXPATH];

	/* Allocate the object structure. */
	__This = CS_malc (sizeof (struct csJgd2kGridFile_));
	if (__This == NULL)
	{
		CS_erpt (cs_NO_MEM);
		goto error;
	}

	/* Initialize. */
	__This->ewDelta = ( 45.0 / 3600.0);
	__This->nsDelta = ( 30.0 / 3600.0);
	__This->strm = NULL;
	__This->bufferSize = 64 * sizeof (struct csJgd2kGridRecord_);
	if (bufferSize > 0) __This->bufferSize = bufferSize;
	__This->dataBuffer = NULL;
	CSinitGridCell (&__This->lngCell);
	CSinitGridCell (&__This->latCell);
	__This->lngCell.deltaLng = __This->ewDelta;
	__This->lngCell.deltaLat = __This->nsDelta;
	__This->latCell.deltaLng = __This->ewDelta;
	__This->latCell.deltaLat = __This->nsDelta;
	__This->filePath [0] = '\0';
	__This->fileName [0] = '\0';

	/* Capture the file name, etc. */
	CS_stncp (__This->filePath,path,sizeof (__This->filePath));
	CS_stncp (lineBufr,path,sizeof (__This->filePath));
	cp = strrchr (lineBufr,cs_DirsepC);
	if (cp != NULL) CS_stncp (__This->fileName,(cp + 1),sizeof (__This->fileName));
	else CS_stncp (__This->fileName,lineBufr,sizeof (__This->fileName));

	/* Save the name for error message, audit trail purposes. */
	CS_stncp (__This->lngCell.sourceId,__This->fileName,sizeof (__This->lngCell.sourceId));
	CS_stncp (__This->latCell.sourceId,__This->fileName,sizeof (__This->latCell.sourceId));

	/* Make a binary file which we can use.  Note this verifies the existence
	   of the file. */
	st = CSmkBinaryJgd2k (__This);
	if (st != 0)
	{
		CS_stncp (csErrnam,__This->filePath,MAXPATH);
		CS_erpt (cs_DTC_FILE);
		goto error;
	}

	/* No need to open the file until such time as the datum calculation
	   needs to be performed. */
	return __This;
error:
	if (__This != NULL)
	{
		if (__This->strm != NULL)
		{
			CS_fclose (__This->strm);
			__This->strm = NULL;
		}
		if (__This->dataBuffer != NULL)
		{
			CS_free (__This->dataBuffer);
			__This->dataBuffer = NULL;
		}
		CS_free (__This);
	}
	return NULL;
}
/*
	The equivalent of a destructor follows.
*/
void CSdeleteJgd2kGridFile (struct csJgd2kGridFile_ *__This)
{
	if (__This != NULL)
	{
		if (__This->strm != NULL)
		{
			CS_fclose (__This->strm);
			__This->strm = NULL;
		}
		if (__This->dataBuffer != NULL)
		{
			CS_free (__This->dataBuffer);
			__This->dataBuffer = NULL;
		}
		CS_free (__This);
	}
	return;
}
/*
	The equivalent of a destructor follows.
*/
void CSreleaseJgd2kGridFile (struct csJgd2kGridFile_ *__This)
{
	if (__This != NULL)
	{
		if (__This->strm != NULL)
		{
			CS_fclose (__This->strm);
			__This->strm = NULL;
		}
		if (__This->dataBuffer != NULL)
		{
			CS_free (__This->dataBuffer);
			__This->dataBuffer = NULL;
		}
	}
	return;
}
/*
	Given a lat/long, we extract the grid cell which covers the point.
*/
int CSextractJgd2kGridFile (struct csJgd2kGridFile_ *__This,Const double* sourceLL)
{
	extern char csErrnam [];
	extern double cs_Sec2Deg;

	int flag;
	size_t rdCnt;

	unsigned long meshCode;
	unsigned long iLng, iLat;
	struct csJgd2kGridRecord_ swRec, seRec, neRec, nwRec;

	double swLL [2], seLL [2], neLL [2], nwLL [2];

	struct csJgd2kGridRecord_ srchKey;

	if (sourceLL [0] < 120.0 || sourceLL [0] > 160.0 ||
		sourceLL [1] <  20.0 || sourceLL [1] >  60.0)
	{
		/* Out of range.  This check eliminates lots of error checking
		   below */
		return 1;
	}

	/* Open the file if is isn't open already. */
	if (__This->strm == NULL)
	{
		/* Open the binary file, since it isn't open already. */
		__This->strm = CS_fopen (__This->filePath,_STRM_BINRD);
		if (__This->strm == NULL)
		{
			CS_stncp (csErrnam,__This->filePath,MAXPATH);
			CS_erpt (cs_DTC_FILE);
			return -1;
		} 
	}

	/* Note, we don't use a buffer (anymore, we used to). */

	/* Locate and read the four corners.  This is quite brutal, but
	   this is the only general way since in this module we know
	   nothing of the structure of a mesh code.
	   
	   The rather strange nature of this code is the result of our
	   desire to keep all information about the nature of the 'mesh'
	   in the two functions defined above. */
	meshCode = CSjpnLlToMeshCode (sourceLL);
	if (meshCode == 0UL) return -1;
	CSjpnMeshCodeToLl (swLL,meshCode);
	iLng = (unsigned long)CS_degToSec (swLL [0]);
	iLat = (unsigned long)CS_degToSec (swLL [1]);

	srchKey.meshCode = meshCode;
	flag = CS_bins (__This->strm,0L,-1L,sizeof (struct csJgd2kGridRecord_),&srchKey,(CMPFUNC_CAST)CScompareJgd2kGridRecord);
	if (flag < 0) return -1;
	if (!flag) return 1;
	rdCnt = CS_fread (&swRec,1,sizeof (swRec),__This->strm);
	if (rdCnt != sizeof (swRec))
	{
		CS_erpt (cs_IOERR);
		return -1;
	}

	iLng += 45;
	seLL [0] = (double)iLng * cs_Sec2Deg;
	seLL [1] = (double)iLat * cs_Sec2Deg;
	meshCode = CSjpnLlToMeshCode (seLL);
	if (meshCode == 0UL) return -1;
	srchKey.meshCode = meshCode;
	flag = CS_bins (__This->strm,0L,-1L,sizeof (struct csJgd2kGridRecord_),&srchKey,(CMPFUNC_CAST)CScompareJgd2kGridRecord);
	if (flag < 0) return -1;
	if (!flag) return 1;
	rdCnt = CS_fread (&seRec,1,sizeof (seRec),__This->strm);
	if (rdCnt != sizeof (seRec))
	{
		CS_erpt (cs_IOERR);
		return -1;
	}

	iLat += 30;
	neLL [0] = (double)iLng * cs_Sec2Deg;
	neLL [1] = (double)iLat * cs_Sec2Deg;
	meshCode = CSjpnLlToMeshCode (neLL);
	if (meshCode == 0UL) return -1;
	srchKey.meshCode = meshCode;
	flag = CS_bins (__This->strm,0L,-1L,sizeof (struct csJgd2kGridRecord_),&srchKey,(CMPFUNC_CAST)CScompareJgd2kGridRecord);
	if (flag < 0) return -1;
	if (!flag) return 1;
	rdCnt = CS_fread (&neRec,1,sizeof (neRec),__This->strm);
	if (rdCnt != sizeof (neRec))
	{
		CS_erpt (cs_IOERR);
		return -1;
	}

	iLng -= 45;
	nwLL [0] = (double)iLng * cs_Sec2Deg;
	nwLL [1] = (double)iLat * cs_Sec2Deg;
	meshCode = CSjpnLlToMeshCode (nwLL);
	if (meshCode == 0UL) return -1;
	srchKey.meshCode = meshCode;
	flag = CS_bins (__This->strm,0L,-1L,sizeof (struct csJgd2kGridRecord_),&srchKey,(CMPFUNC_CAST)CScompareJgd2kGridRecord);
	if (flag < 0) return -1;
	if (!flag) return 1;
	rdCnt = CS_fread (&nwRec,1,sizeof (nwRec),__This->strm);
	if (rdCnt != sizeof (nwRec))
	{
		CS_erpt (cs_IOERR);
		return -1;
	}

	/* Populate the two cell structures involved. */
	CSsetCoverage (&__This->lngCell.coverage,swLL,neLL);
	__This->lngCell.currentAA = (double)swRec.deltaLng / 100000.0;
	__This->lngCell.currentBB = (double)(seRec.deltaLng - swRec.deltaLng) / 100000.0;
	__This->lngCell.currentCC = (double)(nwRec.deltaLng - swRec.deltaLng) / 100000.0;
	__This->lngCell.currentDD = (double)(swRec.deltaLng - seRec.deltaLng - nwRec.deltaLng + neRec.deltaLng) / 100000.0;

	CSsetCoverage (&__This->latCell.coverage,swLL,neLL);
	__This->latCell.currentAA = (double)swRec.deltaLat / 100000.0;
	__This->latCell.currentBB = (double)(seRec.deltaLat - swRec.deltaLat) / 100000.0;
	__This->latCell.currentCC = (double)(nwRec.deltaLat - swRec.deltaLat) / 100000.0;
	__This->latCell.currentDD = (double)(swRec.deltaLat - seRec.deltaLat - nwRec.deltaLat + neRec.deltaLat) / 100000.0;

	/* Identify the source of data for the grid cell. */
	CS_stncp (__This->lngCell.sourceId,__This->fileName,sizeof (__This->lngCell.sourceId));
	CS_stncp (__This->latCell.sourceId,__This->fileName,sizeof (__This->lngCell.sourceId));

	/* We're done, some one else does the actual calculation. */
	return 0;
}
/*
	Calculate the specific value indicated.  The return values are in seconds.
*/
int CScalcJgd2kGridFile (struct csJgd2kGridFile_* __This,double result [2],Const double* sourceLL)
{
	extern double cs_Sec2Deg;				/* 1.0 / 3600.0 */

	double deltaLng;
	double deltaLat;

	/* Retuns the grid data values obtained from the grid file after appropriate
	   bilinear interpolation.  The return values are in seconds of longitude and
	   latitude respectively. */

	int cellStatus;

	if (CStestCoverageUS (&__This->lngCell.coverage,sourceLL) != 0.0)
	{
		cellStatus = 0;
	}
	else
	{
		cellStatus = CSextractJgd2kGridFile (__This,sourceLL);
	}
	if (cellStatus == 0)
	{
		deltaLng = CScalcGridCellUS (&__This->lngCell,sourceLL);
		deltaLat = CScalcGridCellUS (&__This->latCell,sourceLL);

		result [LNG] = sourceLL [LNG] + deltaLng * cs_Sec2Deg;
		result [LAT] = sourceLL [LAT] + deltaLat * cs_Sec2Deg;
	}
	else
	{
		result [LNG] = sourceLL [LNG];
		result [LAT] = sourceLL [LAT];
	}
	return cellStatus;
}
/* This function creates a binary version of the Jgd2k file if it doesn't
   exist, or if the date on the binary file is older than or equal to
   that of the primary text file.  Note, that this function uses the path name
   in the provided object, and modifies it to point to the binary file which
   is then created if necessary.
   
   This function is implemented as records in the ASCII text file may not be
   of fixed length, there can be a million of them, and there is no guarantee
   that the records in the text file will be properly soprted.  The binary
   file enables random access to the data file for decent performance without
   eating up 12MB of RAM. */
int CSmkBinaryJgd2k (struct csJgd2kGridFile_* __This)
{
	extern char cs_ExtsepC;
	extern char csErrnam [];

	int st;
	cs_Time_ aTime, bTime;

	char *dummy;
	char *cp1, *cp2;
	csFILE *aStrm, *bStrm;

	unsigned long meshCode;

	double lngTmp, latTmp;

	char lineBufr [128];
	char binaryPath [MAXPATH];

	struct csJgd2kGridRecord_ gridRec;

	/* Prepare for an error of some sort. */
	aStrm = bStrm = NULL;

	/* Manufacture the name of the binary file. */
	CS_stncp (binaryPath,__This->filePath,sizeof (binaryPath));
	cp1 = strrchr (binaryPath,cs_ExtsepC);
	if (cp1 == NULL) 
	{
		CS_stncp (csErrnam,__This->filePath,MAXPATH);
		CS_erpt (cs_DTC_FILE);
		goto error;
	}
	CS_stcpy ((cp1 + 1),"_jg");

	/* Determine the last modification time for the two files.  Zero time value
	   means the file does not exist. */
	aTime = CS_fileModTime (__This->filePath);
	if (aTime == 0)
	{
		CS_stncp (csErrnam,__This->filePath,MAXPATH);
		CS_erpt (cs_DTC_FILE);
		goto error;
	}
	bTime = CS_fileModTime (binaryPath);

	/* Build a new binary file if appropriate. */
	if (bTime == 0 || bTime <= aTime)
	{
		/* Here to create a, possibly new, binary version of the "Jgd2k".txt
		   file.  In this case, there can be several files, and there is no
		   fixed name for the file.  We write one csJgd2kGridRecord structure
		   for each line of text that we read.   Of course, we need to skip
		   the first two lines (usually) in the file. */
		aStrm = CS_fopen (__This->filePath,_STRM_TXTRD);
		if (aStrm == NULL)
		{
			CS_stncp (csErrnam,__This->filePath,MAXPATH);
			CS_erpt (cs_DTC_FILE);
			goto error;
		}
		/* The mode of the following open will truncate any existing file, and
		   create a new file if necessary. */
		bStrm = CS_fopen (binaryPath,_STRM_BINWR);
		if (bStrm == NULL)
		{
			CS_stncp (csErrnam,__This->filePath,MAXPATH);
			CS_erpt (cs_FL_OPEN);
			goto error;
		}

		/* If we're still here, we can copy the file, converting it to binary
		   form as we do. */
		while (CS_fgets (lineBufr,sizeof (lineBufr),aStrm) != NULL)
		{
			/* Parse the information is in a record. */
			meshCode = CS_strtoul (lineBufr,&cp1,10);
			if (meshCode == 0 || meshCode == ULONG_MAX) continue;
			latTmp = CS_strtod (cp1,&cp2);
			lngTmp = CS_strtod (cp2,&dummy);

			/* Build a new record in the array. */
			gridRec.meshCode = meshCode;
			gridRec.deltaLat = (long)(latTmp * 100000.0);
			gridRec.deltaLng = (long)(lngTmp * 100000.0);
			CS_fwrite (&gridRec,sizeof (gridRec),1,bStrm);
		}
		CS_fclose (aStrm);
		aStrm = NULL;
		st = CS_fclose (bStrm);
		bStrm = NULL;

		bStrm = CS_fopen (binaryPath,_STRM_BINUP);
		if (bStrm == NULL)
		{
			CS_stncp (csErrnam,binaryPath,MAXPATH);
			CS_erpt (cs_FL_OPEN);
			goto error;
		}
		st = CS_ips (bStrm,sizeof (gridRec),0L,(CMPFUNC_CAST)CScompareJgd2kGridRecord);
		CS_fclose (bStrm);
		if (st < 0) goto error;
		if (st == 1) st = 0;			/* CS_ips returns 1 for success, for historical reasons. */

		/* OK, now we're done. */
		if (st != 0)
		{
			CS_erpt (cs_INV_FILE);
			goto error;
		}
	}

	/* If all that was done successfully, we change the name of
	   the file and return success. */
	CS_stncp (__This->filePath,binaryPath,sizeof (__This->filePath));
	return 0;
error:
	if (aStrm != NULL) CS_fclose (aStrm);
	if (bStrm != NULL) CS_fclose (bStrm);						/*lint !e644 */
	return -1;
}
/**********************************************************************
**	CS_Jgd2kName (new_name);
**
**	char *new_name;				the name of the Jgd2kToNzgd2K catalog
**								file.
**
**	This function specifies the name only.  The directory,
**	and possibly drive, are specified using CS_altdr.
**********************************************************************/
void EXP_LVL1 CS_jgd2kName (Const char *newName)
{
	extern char cs_Jgd2kName [];

	CS_stncp (cs_Jgd2kName,newName,cs_FNM_MAXLEN);
	return;
}

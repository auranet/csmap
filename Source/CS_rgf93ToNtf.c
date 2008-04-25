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

			 File Name: $Source: C:/Development/NewCsMap/rcs/CS_rgf93ToNtf.c $
			 Full Name:	
		   Description:
			   Purpose:	

		Revision Level:	$Revision: #6 $
				  Date:	$Date: 2006/11/25 $

		 Last Revision:	$Log: CS_rgf93ToNtf.c $
		 Last Revision:	Revision 11.1300  2005/05/25 23:27:17  nto
		 Last Revision:	Official Release 11.13
		 Last Revision:	Revision 11.1200  2005/01/15 18:27:15  nto
		 Last Revision:	Official Release of CS-MAP 11.12, 11:26am 15 Jan 2005
		 Last Revision:	Revision 11.1100  2004/11/01 18:53:13  nto
		 Last Revision:	Official release 11.11
		 Last Revision:	Revision 11.1001  2004/10/07 19:25:21  nto
		 Last Revision:	Revision 11.900  2004/03/26 17:02:27  nto
		 Last Revision:	Official release: 11.09 - 3/25/2003
		 Last Revision:	Revision 11.800  2004/01/13 23:29:16  nto
		 Last Revision:	Revision 11.700  2003/12/19 01:49:56  nto
		 Last Revision:	Official release 11.07
		 Last Revision:	Revision 11.600  2003/12/04 02:46:31  nto
		 Last Revision:	Release 11.06.  Never shipped. Source captured in prep for C++ V7.
		 Last Revision:	Revision 11.502  2003/11/24 01:12:09  nto
		 Last Revision:	Correct very remote possibility of addressing fault when errors occur.
		 Last Revision:	Revision 11.501  2003/08/22 21:12:58  nto
		 Last Revision:	Official Release: 11.05
		 Last Revision:	Revision 11.401  2003/05/01 23:06:25  nto
		 Last Revision:	Revision 11.300  2003/02/25 04:29:19  nto
		 Last Revision:	Official Release 11.03
		 Last Revision:	Revision 11.101  2002/12/17 04:07:30  nto
		 Last Revision:	Added test functions to verify intergity of the data file, and integrity of the memory arrays.
		 Last Revision:	Revision 11.100  2002/11/22 19:38:47  nto
		 Last Revision:	Official release: 11.01
		 Last Revision:	Revision 10.1503  2002/11/21 21:08:23  nto
		 Last Revision:	Lint cleanup.
		 Last Revision:	Revision 10.1502  2002/11/06 23:52:27  nto
		 Last Revision:	Adjusted the calculation of the grid size, to accomodate round off on some platforms.
		 Last Revision:	Revision 10.1501  2002/10/13 00:30:22  nto
		 Last Revision:	Fixed a couple of strnicmps, they are not ANSI.
		 Last Revision:	Revision 10.1500  2002/09/22 00:01:23  nto
		 Last Revision:	Official Release:= 10.15
		 Last Revision:	Revision 10.1401  2002/09/20 04:27:24  nto
		 Last Revision:	Oops!!!  Forgot to close the file during construction.
		 Last Revision:	Revision 10.1400  2002/08/09 18:14:25  nto
		 Last Revision:	Revision 10.1200  2002/07/14 03:26:20  nto
		 Last Revision:	Revision 10.1101  2002/06/20 17:45:34  nto
		 Last Revision:	Rewrite ti account for new inverse algorithm, and fixed an algebra error.
		 Last Revision:	Revision 10.1100  2002/06/13 14:18:40  nto
		 Last Revision:	Release 10.11 Official
		 Last Revision:	Revision 1.1  2002/06/13 13:33:42  nto
		 Last Revision:	Initial Revision

		       * * * * R E M A R K S * * * *

*****************************************************************************/

#include "cs_map.h"
#include <ctype.h>

#ifdef LABEL_MODULE
static char revlvl [] = {"%W"};
#endif

/*lint -esym(644,sw,ne,__This->deltaLng,__This->deltaLat) */
/*lint -esym(732,sw,ne,__This->lngCount,__This->latCount) */
/*lint -esym(732,sw,ne,lngIsx,latIdx,swIdx, nwIdx, neIdx, seIdx) */

int CScalcNtfToRfg93Deltas (struct csRgf93ToNtf_ *__This,Const double ll_rgf93 [3],double *deltaX,double *deltaY,double *deltaZ);
unsigned short EXP_LVL9 CS_crc16 (unsigned short crc16,unsigned char *cp,int count);

struct csRgf93ToNtf_* csRgf93ToNtf = NULL;
int csRgf93ToNtfCnt = 0;

int EXP_LVL7 CSrgf93Init (void)
{
	extern char cs_Dir [];
	extern char* cs_DirP;

	char gridFile [MAXPATH];

	if (csRgf93ToNtf == NULL)
	{
		CS_stcpy (cs_DirP,"gr3df97a.txt");
		CS_stncp (gridFile,cs_Dir,sizeof (gridFile));
		csRgf93ToNtf = CSnewRgf93ToNtf (gridFile);
		if (csRgf93ToNtf == NULL) goto error;
	}
	csRgf93ToNtfCnt += 1;
	return 0;

error:
	if (csRgf93ToNtf != NULL)
	{
		CSdeleteRgf93ToNtf (csRgf93ToNtf);
		csRgf93ToNtf = NULL;
		csRgf93ToNtfCnt = 0;
	}
	return -1;
}
void EXP_LVL7 CSrgf93Cls (void)
{
	csRgf93ToNtfCnt -= 1;
	if (csRgf93ToNtfCnt <= 0)
	{
		if (csRgf93ToNtf != NULL)
		{
			CSdeleteRgf93ToNtf (csRgf93ToNtf);
			csRgf93ToNtf = NULL;
		}
		csRgf93ToNtfCnt = 0;
	}
	return;
}
int EXP_LVL7 CSrgf93Chk (void)
{
	extern char csErrnam [];

	unsigned short crcX;
	unsigned short crcY;
	unsigned short crcZ;
	int status;
	size_t malcSize;
	struct csRgf93ToNtf_ *__This;

	status = 0;
	__This = csRgf93ToNtf;
	if (__This != NULL)
	{
		/* Before we delete, we check the status of the heap memory arrays. */
		malcSize = (size_t)(__This->lngCount * __This->latCount) * sizeof (long);
		crcX = CS_crc16 (0X0101,(unsigned char *)__This->deltaX,(int)malcSize);
		crcY = CS_crc16 (0X0202,(unsigned char *)__This->deltaY,(int)malcSize);
		crcZ = CS_crc16 (0X0404,(unsigned char *)__This->deltaZ,(int)malcSize);
		if (crcX != __This->crcX || crcY != __This->crcY || crcZ != __This->crcZ)
		{
			CS_stncp (csErrnam,"CS_rgf93ToNtf.c:1",MAXPATH);
			CS_erpt (cs_ISER);
			status = -1;
		}
	}
	return status;
}
int EXP_LVL7 CSrgf93ToNtf (double ll_ntf [3],Const double ll_rgf93 [3])
{
	int status;
	double my_ntf [3];

	/* We always do the null conversion. */
	my_ntf [LNG] = ll_rgf93 [LNG];
	my_ntf [LAT] = ll_rgf93 [LAT];
	my_ntf [HGT] = ll_rgf93 [HGT];

	/* Do the real conversion, if possible. */
	if (csRgf93ToNtf == NULL)
	{
		CS_erpt (cs_DTC_NO_SETUP);
		status = -1;
	}
	else
	{
		status = CScalcRgf93ToNtf (csRgf93ToNtf,my_ntf,ll_rgf93);
	}
	ll_ntf [LNG] = my_ntf [LNG];
	ll_ntf [LAT] = my_ntf [LAT];
	ll_ntf [HGT] = my_ntf [HGT];
	return status;
}
int EXP_LVL7 CSntfToRgf93 (double ll_rgf93 [3],Const double ll_ntf [3])
{
	int status;
	double my_rgf93 [3];

	/* We always do the null conversion. */
	my_rgf93 [LNG] = ll_ntf [LNG];
	my_rgf93 [LAT] = ll_ntf [LAT];
	my_rgf93 [HGT] = ll_ntf [HGT];

	/* Do the real conversion, if possible. */
	if (csRgf93ToNtf == NULL)
	{
		CS_erpt (cs_DTC_NO_SETUP);
		status = -1;
	}
	else
	{
		status = CSinverseRgf93ToNtf (csRgf93ToNtf,my_rgf93,ll_ntf);
	}
	ll_rgf93 [LNG] = my_rgf93 [LNG];
	ll_rgf93 [LAT] = my_rgf93 [LAT];
	ll_rgf93 [HGT] = my_rgf93 [HGT];
	return status;
}
/*
	The following object is used to convert geographic coordinates from the
	New Triangulation (actually, quite old now) to the newer RGF (don't
	know what RGF stands for) 1993 datum.

	Essentially, the grid shift file is read into memory when this thing
	is constructued.  The file is then closed.  The size of the grids is
	about 200KB, small potatoes by today's standards.

	Note that this is a bit of a deviation from the way this problem has
	been approached by others.  This grid defines the transformation from
	RGF93 to NTF.  Most algorithms go the other way.  Therefore, we are
	doiong the inverse where most algorithms are doing the forward.

	To conserve RAM, we keep the shift values as millimeters in longs.
	This reduces, by half, the amount of memory required.
*/
struct csRgf93ToNtf_ *CSnewRgf93ToNtf (const char *filePath)
{
	extern char cs_DirsepC;
	extern char cs_ExtsepC;
	extern char csErrnam [];

	int hdrFlag = 0;

	long lngIdx, latIdx;
	unsigned arrayIdx;
	unsigned tknCount;
	size_t malcSize;

	char *cpV;
	csFILE *fstrm;
	struct cs_Eldef_ *elPtr;
	struct csRgf93ToNtf_ *__This;
	double lng, lat;
	double deltaX, deltaY, deltaZ;

	double sw [3], ne [2];
	char *ptrs [20];

	char lineBuffer [256];

	/* Prepare for an error. */
	fstrm = NULL;
	__This = NULL;
	elPtr = NULL;

	/* Allocate the initial chunk of memory for this thing. */
	__This = CS_malc (sizeof (struct csRgf93ToNtf_));
	__This->deltaX = NULL;
	__This->deltaY = NULL;
	__This->deltaZ = NULL;

	/* Capture the full path to the file and the file name. */
	CS_stncp (__This->filePath,filePath,sizeof (__This->filePath));
	cpV = strrchr (__This->filePath,cs_DirsepC);
	if (cpV == NULL) cpV = __This->filePath;
	CS_stncp (__This->fileName,cpV,sizeof (__This->fileName));
	cpV = strrchr (__This->fileName,cs_ExtsepC);
	if (cpV != NULL) *cpV = '\0';

	/* OK, open the file, and extra the parameters.  There are
	   two types of files.  We handle either kind (since we can do it
	   all in this module).  Get the first line and determine which
	   type of file we have. */
	fstrm = CS_fopen (filePath,_STRM_TXTRD);
	if (fstrm == NULL)
	{
		CS_stncp (csErrnam,__This->filePath,MAXPATH);
		CS_erpt (cs_DTC_FILE);
		goto error;
	}
	if (CS_fgets (lineBuffer,sizeof (lineBuffer),fstrm) == NULL)
	{
		CS_erpt (cs_IOERR);
		goto error;
	}
	tknCount = CS_spaceParse (lineBuffer,ptrs,20);

	/* Decide which file type we have. */
	if (!CS_stricmp (ptrs [0],"GR3D"))
	{
		/* Here for the verbose format. */
		while (CS_fgets (lineBuffer,sizeof (lineBuffer),fstrm) != NULL)
		{
			tknCount = CS_spaceParse (lineBuffer,ptrs,20);
			if (!CS_stricmp (ptrs [0],"GR3D3")) break;
			if (!CS_stricmp (ptrs [0],"GR3D1") && tknCount == 7)
			{
				hdrFlag = 1;
				sw [0] = atof (ptrs [1]);
				ne [0] = atof (ptrs [2]);
				sw [1] = atof (ptrs [3]);
				ne [1] = atof (ptrs [4]);
				__This->deltaLng = atof (ptrs [5]);
				__This->deltaLat = atof (ptrs [6]);
			}
		}
		if (hdrFlag == 0)
		{
			/* If we didn't see the expected header record, we have
			   a big problem. */
			CS_stncp (csErrnam,__This->filePath,MAXPATH);
			CS_erpt (cs_INV_FILE);
			goto error;
		}

		/* Capture the coverage area. */
		__This->coverage.southWest [LNG] = sw [0];
		__This->coverage.southWest [LAT] = sw [1];
		__This->coverage.northEast [LNG] = ne [0];
		__This->coverage.northEast [LAT] = ne [1];
		__This->coverage.density = __This->deltaLat;

		/* Compute the size of the grid.  We need to add the extra 0.1
		   to account for round off errors on certain compilers/platforms. */
		__This->lngCount = (long)(((ne [0] - sw [0]) / __This->deltaLng) + 0.1) + 1;
		__This->latCount = (long)(((ne [1] - sw [1]) / __This->deltaLat) + 0.1) + 1;

		/* Now we can allocate the arrays. */
		malcSize = (size_t)(__This->lngCount * __This->latCount) * sizeof (long);
		__This->deltaX = CS_malc (malcSize);
		if (__This->deltaX == NULL)
		{
			CS_erpt (cs_NO_MEM);
			goto error;
		}
		__This->deltaY = CS_malc (malcSize);
		if (__This->deltaY == NULL)
		{
			CS_erpt (cs_NO_MEM);
			goto error;
		}
		__This->deltaZ = CS_malc (malcSize);
		if (__This->deltaZ == NULL)
		{
			CS_erpt (cs_NO_MEM);
			goto error;
		}
		for (lngIdx = 0;lngIdx < __This->lngCount;lngIdx += 1)
		{
			for (latIdx = 0;latIdx < __This->latCount;latIdx += 1)
			{
				arrayIdx = (unsigned)((latIdx * __This->lngCount) + lngIdx);
				*(__This->deltaX + arrayIdx) = 0L;
				*(__This->deltaY + arrayIdx) = 0L;
				*(__This->deltaZ + arrayIdx) = 0L;
			}
		}

		/* Fill in the ellipsoid numbers.  Pretty hokey, but it will work
		   for now. */
		elPtr = CS_eldef ("GRS1980");
		if (elPtr == NULL) goto error;
		__This->rgf93ERad = elPtr->e_rad;
		__This->rgf93ESq = elPtr->ecent * elPtr->ecent;
		CS_free (elPtr);
		elPtr = NULL;
		elPtr = CS_eldef ("CLRK-IGN");
		if (elPtr == NULL) goto error;
		__This->ntfERad = elPtr->e_rad;
		__This->ntfESq = elPtr->ecent * elPtr->ecent;
		CS_free (elPtr);
		elPtr = NULL;

		/* Process the rest of the file. Note, that the first
		   node record should already be in lineBuffer, and it
		   should already be parsed. */
		while (CS_fgets (lineBuffer,sizeof (lineBuffer),fstrm) != NULL)
		{
			tknCount = CS_spaceParse (lineBuffer,ptrs,20);
			if (tknCount == 8)
			{
				/* Determine the location of the node in the grid. */
				lng = atof (ptrs [1]);
				lat = atof (ptrs [2]);
				deltaX = atof (ptrs [3]);
				deltaY = atof (ptrs [4]);
				deltaZ = atof (ptrs [5]);

				lngIdx = (long)(((lng - sw [0]) / __This->deltaLng) + 1.0E-10);
				latIdx = (long)(((lat - sw [1]) / __This->deltaLat) + 1.0E-10);
				if (lngIdx < 0 || lngIdx >= __This->lngCount ||
					latIdx < 0 || latIdx >= __This->latCount)
				{
					/* This should never happen with a good data file. */
					CS_erpt (cs_INV_FILE);
					goto error;
				}
				
				/* Adjust for possible orund down; required for LInux, perhaps
				   others as well. */
				deltaX += (deltaX < 0.0) ? -0.0002 : 0.0002;
				deltaY += (deltaY < 0.0) ? -0.0002 : 0.0002;
				deltaZ += (deltaZ < 0.0) ? -0.0002 : 0.0002;

				/* Stuff extracted values in the local arrays. */
				arrayIdx = (unsigned)((latIdx * __This->lngCount) + lngIdx);
				*(__This->deltaX + arrayIdx) = (long)(deltaX * 1000.0);
				*(__This->deltaY + arrayIdx) = (long)(deltaY * 1000.0);
				*(__This->deltaZ + arrayIdx) = (long)(deltaZ * 1000.0);
			}
		}
	}
	else
	{
		/* We don't support the abbreviated file.  There is little reason to do so
		   as we pre-process the file and, therefore, there is little in the way of
		   efficiency to be obtained.  The verbose file is only 1.2 megabytes;
		   trivial by today's standards.  If you are in a real crunch (a pocket
		   PC for example) generate the binary file on a real computer, and install
		   both the binary version and an empty text file.  Just make sure the
		   time stamp on the empty text file is older than the binary file. */
		CS_erpt (cs_INV_FILE);
		goto error;
	}

	/* For testing purposes, we generate the check-sum of the three memory
	   arrays allocated above.  The CSrgf93Chk function verifies that the
	   memory in these arrays has not changed since they were allocated. */
	__This->crcX = CS_crc16 (0X0101,(unsigned char *)__This->deltaX,(int)malcSize);
	__This->crcY = CS_crc16 (0X0202,(unsigned char *)__This->deltaY,(int)malcSize);
	__This->crcZ = CS_crc16 (0X0404,(unsigned char *)__This->deltaZ,(int)malcSize);

	/* OK, we're outa here. */
	CS_fclose (fstrm);
	fstrm = NULL;
	return __This;

error:
	if (elPtr != NULL)
	{
		CS_free (elPtr);
		elPtr = NULL;
	}
	if (fstrm != NULL)
	{
		CS_fclose (fstrm);
		fstrm = NULL;
	}
	CSdeleteRgf93ToNtf (__This);
	return NULL;
}
void CSdeleteRgf93ToNtf (struct csRgf93ToNtf_ *__This)
{
	if (__This != NULL)
	{
		if (__This->deltaX != NULL)
		{
			CS_free (__This->deltaX);
			__This->deltaX = NULL;
		}
		if (__This->deltaY != NULL)
		{
			CS_free (__This->deltaY);
			__This->deltaY = NULL;
		}
		if (__This->deltaZ != NULL)
		{
			CS_free (__This->deltaZ);
			__This->deltaZ = NULL;
		}
		CS_free (__This);
	}
}
// The forward function will convert an RFG93 geographic coordinate to
// NTF coordinate.  This is the opposite of the normal case.
int CScalcRgf93ToNtf (struct csRgf93ToNtf_ *__This,double ll_ntf [3],Const double ll_rgf93 [3])
{
	int rtnVal, xyzSt;

	double deltaX, deltaY, deltaZ;

	double xyz [3];

	rtnVal = 0;

	/* Prepare for an out of range condition. */
	ll_ntf [LNG] = ll_rgf93 [LNG];
	ll_ntf [LAT] = ll_rgf93 [LAT];
	ll_ntf [HGT] = ll_rgf93 [HGT];

	/* Determine the delta shift values. */
	rtnVal = CScalcNtfToRfg93Deltas (__This,ll_rgf93,&deltaX,&deltaY,&deltaZ);
	/* A status value of +1 says that the given point is not covered by the grid file.
	   However, in this case, CScalcNtfToRfg93Deltas returns delta X, Y, & Z set
	   to average values.  Thus, we do the following regardless of the value
	   of rtnVal. */
	if (rtnVal >= 0)
	{
		/* OK, we have the appropriate delta values.  We need to do a three parameter
		   transformation using these values.  Before we can do this, we need to convert
		   the source geographic coordinates to geocentric form. */
		CS_llhToXyz (xyz,ll_rgf93,__This->rgf93ERad,__This->rgf93ESq);
		xyz [0] -= deltaX;
		xyz [1] -= deltaY;
		xyz [2] -= deltaZ;
		xyzSt = CS_xyzToLlh (ll_ntf,xyz,__This->ntfERad,__This->ntfESq);
		if (xyzSt != 0)
		{
			CS_erpt ( cs_XYZ_ITR);
			rtnVal = -1;
		}
	}
	return rtnVal;
}
/* The following version of the inverse calculation is commented out.  This
   version will produce the exact inverse of the forward within the
   tolerances programmed (i.e. 1.0E-09 degrees, about .1 millimeters.

   The reference document uses the alternative inverse which appears below.
   It will not produce the exact inverse, but is very very close, and is a
   lot faster.  Since this is what the French use, we use it as well.
*/
#if defined (__SKIP__)
/* Since the following code has beenb tested, we leave it in here.  Easier to
   delete than it is to create. */
int CSinverseRgf93ToNtf (struct csRgf93ToNtf_ *__This,double ll_rgf93 [3],Const double ll_ntf [3])
{
	static int maxIteration = 20;
	static double smallValue  = 1.0E-09;		/* equates to =~ .1 millimeters */
	static double smallValue2 = 1.0E-06;		/* equates to =~ 100 millimeters */

	int ii;
	int lngOk;
	int latOk;
	int rtnVal;

	double guess [3];
	double newLl [3];
	double epsilon [3];

	/* Assume everything goes OK until we know different. */
	rtnVal = 0;

	/* First, we copy the source lat/longs to the local array.
	   This is the default result which the user may want in
	   the event of an error.  Note, we assume such has been
	   done below, even if there has not been an error. */
	ll_rgf93 [LNG] = guess [LNG] = ll_ntf [LNG];
	ll_rgf93 [LAT] = guess [LAT] = ll_ntf [LAT];
	ll_rgf93 [HGT] = guess [HGT] = ll_ntf [HGT];

	/* Start a loop which will iterate as many as maxIteration times. */
	for (ii = 0;ii < maxIteration;ii++)
	{
		/* Assume we are done until we know different. */
		lngOk = latOk = TRUE;

		/* Compute the WGS-84 lat/long for our current guess. */
		rtnVal = CScalcRgf93ToNtf (__This,newLl,guess);
		if (rtnVal != 0)
		{
			/* Oopps!! We must have been given some pretty strange
			   coordinate values. */
			break;
		}

		/* See how far we are off. */
		epsilon [LNG] = ll_ntf [LNG] - newLl [LNG];
		epsilon [LAT] = ll_ntf [LAT] - newLl [LAT];

		/* If our guess at the longitude is off by more than
		   small, we adjust our guess by the amount we are off. */
		if (fabs (epsilon [LNG]) > smallValue)
		{
			lngOk = FALSE;
			guess [LNG] += epsilon [LNG];
		}
		/* If our guess longitude is off by more than
		   small, we adjust our guess by the amount we are off. */
		if (fabs (epsilon [LAT]) > smallValue)
		{
			latOk = FALSE;
			guess [LAT] += epsilon [LAT];
		}

		/* If our current guess produces a newLl that is within
		   samllValue of srcLl, we are done. */
		if (lngOk && latOk) break;
	}

	/* If we didn't resolve in maxIteration tries, we issue a warning
	   message.  Usually, three or four iterations does the trick. */
	if (ii >= maxIteration )
	{
		CS_erpt (cs_RGF93_ICNT);

		/* Issue a warning if we're close, a fatal if we are still way off.
		   In any case, we return the last computed value.  We could have
		   gotten very fancy with this stuff, but it would have had serious
		   affects on the performance.  So we just check epsilon here as
		   we know we have an error and this doesn't happen very often. */
		rtnVal = 1;
		if (fabs (epsilon [LNG]) > smallValue2 ||
		    fabs (epsilon [LAT]) > smallValue2)
		{
			rtnVal = -1;
		}
	}

	/* Return the resuls if everything converged. */
	if (rtnVal >= 0)
	{
		ll_rgf93 [LNG] = guess [LNG];
		ll_rgf93 [LAT] = guess [LAT];
	}
	return rtnVal;
}
#else
int CSinverseRgf93ToNtf (struct csRgf93ToNtf_ *__This,double ll_rgf93 [3],Const double ll_ntf [3])
{
	int rtnVal = 0;

	double deltaX, deltaY, deltaZ;

	double xyz [3];

	/* We start with the basic, default, average, values. */
	deltaX = -168.0;
	deltaY =  -60.0;
	deltaZ =  320.0;

	/* The grid file is indexed by RGF93 lat/longs, even though the delta values
	   in the grid file are the values which convert from NTF to RGF93.  We only
	   have ntf lat/longs.  So, first thing we do is to do an approximate
	   calculation, converting the provided NTF lat/longs to RGF93 lat/longs using
	   standard, average, delta X, Y, & Z values.  Note that in the event
	   of an error below, these approximate results are allowed to remain in
	   the target array. */
	CS_llhToXyz (xyz,ll_ntf,__This->ntfERad,__This->ntfESq);
	xyz [0] += deltaX;
	xyz [1] += deltaY;
	xyz [2] += deltaZ;
	rtnVal = CS_xyzToLlh (ll_rgf93,xyz,__This->rgf93ERad,__This->rgf93ESq);
	if (rtnVal != 0)
	{
		CS_erpt ( cs_XYZ_ITR);
	}
	else
	{
		/* Now we use this approximate RGF93 lat/long to access the grid file to get
		   the Delta X, Y, & Z.  Obviously, not perfectly exact, but very close. */
		rtnVal = CScalcNtfToRfg93Deltas (__This,ll_rgf93,&deltaX,&deltaY,&deltaZ);

		/* A status value of +1 says that the given point is not covered by the grid file.
		   In this case, since we have already calculated an approximation, we are done. */
		if (rtnVal == 0)
		{
			CS_llhToXyz (xyz,ll_ntf,__This->ntfERad,__This->ntfESq);
			xyz [0] += deltaX;
			xyz [1] += deltaY;
			xyz [2] += deltaZ;
			rtnVal = CS_xyzToLlh (ll_rgf93,xyz,__This->rgf93ERad,__This->rgf93ESq);
			if (rtnVal != 0)
			{
				CS_erpt ( cs_XYZ_ITR);
			}
		}
	}
	return rtnVal;
}
#endif
// Given a RGF93 lat/long in degreess relative to Greenwich, this function
// extracts the appropaite delta X, Y, and Z from the rid file.  Returns
// +1 if the provided lat/long are not covered by the grid file.
int CScalcNtfToRfg93Deltas (struct csRgf93ToNtf_ *__This,Const double ll_rgf93 [3],double *deltaX,double *deltaY,double *deltaZ)
{
	short westEdg, northEdg, eastEdg, southEdg;

	int rtnVal;

	unsigned swIdx, nwIdx, neIdx, seIdx;

	long lngIdx, latIdx;

	double density;
	double cellLng, cellLat;
	double x1, x2, x3, x4;
	double y1, y2, y3, y4;										/*lint !e578 */
	double z1, z2, z3, z4;

	double sw [3];

	rtnVal = 0;

	/* In the case of a +1 return, we return the standrd values. */
	*deltaX = -168.0;
	*deltaY =  -60.0;
	*deltaZ =  320.0;

	/* Check and make sure we have proper coverage. */
	density = CStestCoverageUS (&__This->coverage,ll_rgf93);
	if (density == 0.0) return 1;

	/* Here if we have coverage.  Calculate the indices to the appropriate cell. */
	lngIdx = (long)((ll_rgf93 [0] - __This->coverage.southWest [0]) / __This->deltaLng);
	latIdx = (long)((ll_rgf93 [1] - __This->coverage.southWest [1]) / __This->deltaLat);

	/* The coverage test should have caught any coordinate which would cause
	   us a problem.  But to be extra safe: */
	westEdg  = (lngIdx < 0);
	northEdg = (latIdx >= __This->latCount);
	eastEdg  = (lngIdx >= __This->lngCount);
	southEdg = (latIdx < 0);
	if (westEdg || northEdg || eastEdg || southEdg) return 1;

	/* We calculate the geographic coordinates of the southwest corner of the
	   appropriate grid cell. */
	sw [0] = __This->coverage.southWest [0] + (lngIdx * __This->deltaLng);
	sw [1] = __This->coverage.southWest [1] + (latIdx * __This->deltaLat);

	/* Now, deltaLng and deltaLat are the normalized distances into the
	   grid cell of the provided point. */
	cellLng = (ll_rgf93 [0] - sw [0]) / __This->deltaLng;
	cellLat = (ll_rgf93 [1] - sw [1]) / __This->deltaLat;

	/* Compute the indices into the delta arrays.  Due to the above checking,
	   these indices should be safe to use for memory access. */
	swIdx = ( latIdx      * __This->lngCount) + lngIdx;
	nwIdx = ((latIdx + 1) * __This->lngCount) + lngIdx;
	neIdx = ((latIdx + 1) * __This->lngCount) + lngIdx + 1;
	seIdx = ( latIdx      * __This->lngCount) + lngIdx + 1;

	/* Now we can do the bilinear calculation.  The nomenclature here jives
	   with the reference document. */
	x1 = (double)(*(__This->deltaX + swIdx)) * 0.001;
	x2 = (double)(*(__This->deltaX + nwIdx)) * 0.001;
	x3 = (double)(*(__This->deltaX + seIdx)) * 0.001;
	x4 = (double)(*(__This->deltaX + neIdx)) * 0.001;

	y1 = (double)(*(__This->deltaY + swIdx)) * 0.001;
	y2 = (double)(*(__This->deltaY + nwIdx)) * 0.001;
	y3 = (double)(*(__This->deltaY + seIdx)) * 0.001;
	y4 = (double)(*(__This->deltaY + neIdx)) * 0.001;

	z1 = (double)(*(__This->deltaZ + swIdx)) * 0.001;
	z2 = (double)(*(__This->deltaZ + nwIdx)) * 0.001;
	z3 = (double)(*(__This->deltaZ + seIdx)) * 0.001;
	z4 = (double)(*(__This->deltaZ + neIdx)) * 0.001;

	*deltaX = x1 + (x3 - x1) * cellLng + (x2 - x1) * cellLat +
				   (x1 - x2 - x3 + x4) * cellLng * cellLat;
	*deltaY = y1 + (y3 - y1) * cellLng + (y2 - y1) * cellLat +
				   (y1 - y2 - y3 + y4) * cellLng * cellLat;
	*deltaZ = z1 + (z3 - z1) * cellLng + (z2 - z1) * cellLat +
				   (z1 - z2 - z3 + z4) * cellLng * cellLat;

	/* If we are still here, the return value is zero. */
	return rtnVal;
}
// The following parses a line of text into space separated tokens.  Note
// this function is destructive to the "lineBuffer: argument.
unsigned CS_spaceParse (char *lineBuffer,char *ptrs [],unsigned maxPtrs)
{
	unsigned index = 0;
	char *cp, *cp1;

	if (maxPtrs == 0) return index;
	CS_removeRedundantWhiteSpace (lineBuffer);
	if (lineBuffer [0] == '\0') return index;
	cp = lineBuffer;
	do
	{
		ptrs [index++] = cp;
		cp1 = strchr (cp,' ');
		if (cp1 == 0) break;
		*cp1++ = '\0';
		cp = cp1;
	} while (index < maxPtrs);
	return index;
}
// The following does itsmagic inplace; how nice.
void CS_removeRedundantWhiteSpace (char *string)
{
	char cc;
	char* fromPtr;

	/* Skip over any initial whitespace. */
	fromPtr = string;
	while (isspace (*fromPtr++));						  /*lint !e722 !e666 */
	if (*fromPtr == '\0')
	{
		*string = '\0';
		return;
	}
	fromPtr -= 1;

	// Copy the string into itself, replacing a consecutive white space
	// characters with a single space character. Note, iswspace defines
	// what white space is.
	while ((cc = *fromPtr++) != '\0')
	{
		if (!isspace (cc)) *string++ = cc;
		else
		{
			while (isspace (*fromPtr++));				  /*lint !e722 !e666 */
			fromPtr -= 1;
			if (*fromPtr != '\0') *string++ = ' ';
		}
	}
	*string = '\0';
	return;
}

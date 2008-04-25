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

			 File Name: $RCSfile: CS_ostn02.c $
		   Description:
			   Purpose:

		Revision Level:	$Revision: #6 $
		 Check In Date:	$Date: 2006/11/25 $

		Last Revision:	$Log: CS_ostn02.c $
		Last Revision:	Revision 11.1300  2005/05/25 23:27:16  nto
		Last Revision:	Official Release 11.13
		Last Revision:	Revision 11.1200  2005/01/15 18:27:15  nto
		Last Revision:	Official Release of CS-MAP 11.12, 11:26am 15 Jan 2005
		Last Revision:	Revision 11.1100  2004/11/01 18:53:12  nto
		Last Revision:	Official release 11.11
		Last Revision:	Revision 11.1001  2004/10/07 19:25:20  nto
		Last Revision:	Revision 11.900  2004/03/26 17:02:27  nto
		Last Revision:	Official release: 11.09 - 3/25/2003
		Last Revision:	Revision 11.800  2004/01/13 23:29:16  nto
		Last Revision:	Revision 11.700  2003/12/19 01:49:56  nto
		Last Revision:	Official release 11.07
		Last Revision:	Revision 11.600  2003/12/04 02:46:31  nto
		Last Revision:	Release 11.06.  Never shipped. Source captured in prep for C++ V7.
		Last Revision:	Revision 11.501  2003/08/22 21:12:58  nto
		Last Revision:	Official Release: 11.05
		Last Revision:	Revision 11.401  2003/05/01 23:06:24  nto
		Last Revision:	Revision 11.300  2003/02/25 04:29:19  nto
		Last Revision:	Official Release 11.03
		Last Revision:	Revision 11.100  2002/11/22 19:38:46  nto
		Last Revision:	Official release: 11.01
		Last Revision:	Revision 10.1501  2002/10/13 00:28:42  nto
		Last Revision:	Removed references to the stat: function, header, and structure.
		Last Revision:	Revision 10.1500  2002/09/22 00:01:23  nto
		Last Revision:	Official Release:= 10.15
		Last Revision:	Revision 1.2  2002/09/20 22:47:15  nto
		Last Revision:	Change atol to atof in two places to fix accuracy of conversion.
		Last Revision:	Revision 1.1  2002/09/15 21:18:45  nto
		Last Revision:	Initial Revision

		*  *  *  *  R E M A R K S *  *  *  *  *

	Virtually identical to CS_ostn97.c  Only difference is in the conversion
	of the text form to the binary form.  Since the binary form of the file
	remains the same, the remainder of the code is pretty much the same.

******************************************************************************/

#ifdef LABEL_MODULE
static char revlvl [] = {"$Id: //depot/Libraries/CsMap/current/src/CS_ostn02.c#6 $"};
#endif

#include "cs_map.h"

/*
	This file contains the implementation of the Ostn02 object.

	Ostn02 is based on a text file with some 876,951 records, i.e.
	lines of text.  Each line contains the translation in cartesian
	form from the normal computed values using ETRS89 coordinates
	to the OSGB36 National Coordinate System.  That is, the data file
	represents a 700 x 1250 grid whose density is one kilometer.

	Please note the following:

	1> Each record also carries a Geoid Height value and a
	integer which indicates which vertical datum was used to
	determine the Geoid Height.

	2> This makes for yet additional problem.  In order to obtain a
	Geoid Height, therefore, one must first obtain ETRF89 X & Y
	coordinates for the point.  This is in contrast to the normal
	situation where Geoid Heights can be determined directly
	from latitude and longitude.  Painful.

	3> In addition to a construction/destruction this module provides
	both a forward anda n inverse function which will provide the
	approriate translations.  Note that these functions are expected
	to be used in conjunction with the normal Transverse Mercator
	functions which would normally implement OSGB36 and OSTN02.

	4> Some of the stuff in the ogject may look strnage in this
	implementation.  This is due to the fact that the code is constructed
	with an eye to a future C++ implementation.  The C++ object will be
	derived from certain base classes and certain virtual functions will
	need to be supported.  Thus, there is some stuff here that looks
	redundant and unnecessary.

	5> The following pointer is used to maintain a single cs_Ostn02_ object.
	It is "created" by the first function that needs it.  It is only
	detroyed explicitly by an application call:
		
		CSdeleteOstn02 (cs_Ostn02Ptr);
		cs_Ostn0297Ptr = NULL;

	or by calling the CS_recvr () function.  That is, once one of these
	is actually constructed, we keep it around in case we need it
	again.  This is for performance purposes.

	6> The shifts in the data file are the shifts from ETRF89 to OSGB36
	coordinates.  The shifts are in the ofrm of cartesian coordinates,
	i.e. delta X and delta Y in meters.

	7> Thus the shifts extracted from this file must be applied to
	projected coordinates (not the latitude and longitude).

	8> The shifts are from ETRF89 to OSGB36.  This is opposite of what
	most similar data files generate.

	FUN!!!   FUN!!!   FUN!!!
*/ 

struct csThread cs_Ostn02_ *cs_Ostn02Ptr = NULL;

/* The file path here is a path to the ASCII text file which carries
   all the shift data.  For example, "OSTN02_OSGM02_GB.txt" */
struct cs_Ostn02_ *CSnewOstn02 (const char *filePath)
{
	extern char cs_DirsepC;
	extern char cs_ExtsepC;

	int st;

	char *cp;
	struct cs_Ostn02_ *__This = NULL;

	/* Allocate and initialize the object. */
	__This = CS_malc (sizeof (struct cs_Ostn02_));
	if (__This == NULL)
	{
		CS_erpt (cs_NO_MEM);
		goto error;
	}

	/* Populate the structure.  Most of this stuff is fixed, there
	   is no header on the front of this file. */
	__This->coverage.southWest [LNG] = -7.555903649568;		/*  7 33 21.253138W */
	__This->coverage.southWest [LAT] = 49.766132660352;		/* 49 45 58.077577N */
	__This->coverage.northEast [LNG] =  3.554379009129;		/*  3 33 15.764433E */
	__This->coverage.northEast [LAT] = 61.017343337548;		/* 61 01 2.4360125N */
	__This->coverage.density = 0.009009009;
	__This->elementCount = 701;
	__This->recordCount = 1251;
	__This->elementSize = 2 * sizeof (float);
	__This->recordSize = __This->elementCount * __This->elementSize;

	__This->strm = NULL;
	__This->dataBuffer = NULL;
	__This->bufferSize = 4 * __This->recordSize;
	__This->bufferBeginPosition = -1L;
	__This->bufferEndPosition = -2L;

	CS_stncp (__This->filePath,filePath,sizeof (__This->filePath));
	cp = strrchr (filePath,cs_DirsepC);							 /*lint !e605*/
	if (cp != NULL)
	{
		CS_stncp (__This->fileName,(cp + 1),sizeof (__This->fileName));
		cp = strrchr (__This->fileName,cs_ExtsepC);
		if (cp != NULL) *cp = '\0';
	}
	
	/* Create a binary file if one does not exist already. */
	st = CSmkBinaryOstn02 (__This);
	if (st != 0) goto error;

	/* That's that. */
	return __This;
error:
	if (__This != NULL) CS_free (__This);
	return NULL;
}
void CSdeleteOstn02 (struct cs_Ostn02_ *__This)
{
	if (__This != NULL)
	{
		CSreleaseOstn02 (__This);
		CS_free (__This);
	}
	return;
}
void CSreleaseOstn02 (struct cs_Ostn02_ *__This)
{
	if (__This != NULL)
	{
		/* Close the file if opened. */
		if (__This->strm != NULL)
		{
			CS_fclose (__This->strm);
			__This->strm = NULL;
		}

		/* Delete the buffer is allocated. */
		if (__This->dataBuffer != NULL)
		{
			CS_free (__This->dataBuffer);
			__This->dataBuffer = NULL;
		}
		__This->bufferBeginPosition = -1L;
		__This->bufferEndPosition = -2L;
	}
	return;
}
/* Note, the following function is also called by the CSinverseOstn02 function. */
int CSprivateOstn02 (struct cs_Ostn02_ *__This,double result [2],const double etrs89 [2])
{
	extern double cs_Mhuge;
	extern char csErrnam [];
	extern double cs_Zero;

	long readCount;
	long checkCount;

	long lngTmp;
	long checkSeek;
	long recNbr, eleNbr;
	long recFirst, recLast;
	long fposBegin, fposEnd;

	char *chrPtr;
	float *fltPtr; 

	double tt, uu;

	float southWest [2], southEast [2];
	float northWest [2], northEast [2];

	/* Given the ETRS89 OSGB coordinates, return the translation values necessary to
	   produce official OSGB36 coordinates.  Returns zero on normal completion, +1 if
	   ETRS89 coordinates are out of range, -1 for any other error (i.e. call
	   CS_errmsg for a textual description of the error). */;

	/* Return now if the input numbers are ridculous.  This protects much of the
	   code below from domain errors, overflows, etc.		
	if (etrs89 [0] < -10.0 || etrs89 [0] > 40.0 || etrs89 [1] < 0.0 || etrs89 [1] > 60.0)
	{
		result [0] = result [1] = cs_Zero;
		return 1;
	} */

	/* Compute the indices of the grid cells involved. */
	recNbr = (long)etrs89 [1] / 1000;
	eleNbr = (long)etrs89 [0] / 1000;

	/* Return now if out of range. */
	if (recNbr < 0 || recNbr >= (__This->recordCount  - 1) ||
	    eleNbr < 0 || eleNbr >= (__This->elementCount - 1)
	   )
	{
		result [0] = result [1] = cs_Zero;
		return 1;
	}

	/* Do we have a buffer?  Could have been released.  Maybe this is the
	   first access. */
	if (__This->dataBuffer == NULL)
	{
		__This->dataBuffer = CS_malc ((size_t)__This->bufferSize);
		if (__This->dataBuffer == NULL)
		{
			CS_erpt (cs_NO_MEM);
			goto error;
		}

		/* Make sure the rest of this stuff knows the buffer is empty.  These values
		   will fail to match any specific file position. */
		__This->bufferBeginPosition = -1L;
		__This->bufferEndPosition = -2L;
	}

	/* Is the necessary data in the buffer already? */
	fposBegin = recNbr * __This->recordSize + eleNbr * __This->elementSize;
	fposEnd   = fposBegin + __This->recordSize + __This->elementSize;
	if (fposBegin < __This->bufferBeginPosition || fposBegin > __This->bufferEndPosition ||
		fposEnd   < __This->bufferBeginPosition || fposEnd   > __This->bufferEndPosition)
	{
		/* The data we need is not in the buffer.  If the file has been released,
		   open it again now. */
		if (__This->strm == NULL)
		{
			__This->strm = CS_fopen (__This->filePath,_STRM_BINRD);
			if (__This->strm == NULL)
			{
				CS_stncp (csErrnam,__This->filePath,MAXPATH);
				CS_erpt (cs_DTC_FILE);
				goto error;
			}
			/* We do our own buffering, turn stream buffering off. */
			setvbuf (__This->strm,NULL,_IONBF,0);
		}

		/* Fill the buffer with data, including the specific data that we need.
		   When we go to the "well", we always fetch a minimum of two "records"
		   of water. */
		recFirst = recNbr;
		recLast = recFirst + 1;
		lngTmp = __This->bufferSize / __This->recordSize;
		if (lngTmp > 3)
		{
			recFirst = recNbr - (lngTmp / 2);
			recLast = recFirst + (lngTmp - 1);
			while (recFirst < 0)
			{
				recFirst += 1;
				recLast += 1;
			}
		}
		while (recLast > 1401)
		{
			recFirst -= 1;
			recLast -= 1;
		}
		readCount = (recLast - recFirst + 1) * __This->recordSize;
		if (readCount != (size_t)__This->bufferSize)
		{
			CS_stncp (csErrnam,"CS_ostn02:2",MAXPATH);
			CS_erpt (cs_ISER);
			goto error;
		}
		__This->bufferBeginPosition = recFirst * __This->recordSize;
		__This->bufferEndPosition = __This->bufferBeginPosition + readCount;

		/* OK, read in the data. */
		checkSeek = CS_fseek (__This->strm,__This->bufferBeginPosition,SEEK_SET);
		if (checkSeek < 0L)
		{
			CS_stncp (csErrnam,__This->filePath,MAXPATH);
			CS_erpt (cs_IOERR);
			goto error;
		}
		checkCount = (long)CS_fread (__This->dataBuffer,1,(size_t)readCount,__This->strm);
		if (checkCount != readCount)
		{
			CS_stncp (csErrnam,__This->filePath,MAXPATH);
			CS_erpt (cs_INV_FILE);
			goto error;
		}
		if (CS_ferror (__This->strm))
		{
			CS_stncp (csErrnam,__This->filePath,MAXPATH);
			CS_erpt (cs_IOERR);
			goto error;
		}
		/* We assume that the binary file is manufactured on the system which is
		   using it.  Therefore, byte swapping is not an issue. */
	}

	/* Extract the grid cell. */
	chrPtr = (char *)__This->dataBuffer + (fposBegin - __This->bufferBeginPosition);
	fltPtr = (float *)(chrPtr);									 /*lint !e826*/
	southWest [XX] = *fltPtr;
	southWest [YY] = *(fltPtr + 1);
	southEast [XX] = *(fltPtr + 2);
	southEast [YY] = *(fltPtr + 3);
	chrPtr += __This->recordSize;
	fltPtr = (float *)(chrPtr);									 /*lint !e826*/
	northWest [XX] = *fltPtr;
	northWest [YY] = *(fltPtr + 1);
	northEast [XX] = *(fltPtr + 2);
	northEast [YY] = *(fltPtr + 3);

	/* Perform the bi-linear calculation. */
	tt = fmod (etrs89 [0],1000.0) / 1000.0;
	uu = fmod (etrs89 [1],1000.0) / 1000.0;

	result [0] = southWest [0] +
				 tt * (southEast [0] - southWest [0]) +
				 uu * (northWest [0] - southWest [0]) +
				 tt * uu * (southWest [0] - southEast [0] - northWest [0] + northEast [0]);
	result [1] = southWest [1] +
				 tt * (southEast [1] - southWest [1]) +
				 uu * (northWest [1] - southWest [1]) +
				 tt * uu * (southWest [1] - southEast [1] - northWest [1] + northEast [1]);

	/* We're done. */
	return 0;

error:
	CSreleaseOstn02 (__This);

	/* We do the following to make sure that no application uses an error
	   without some one noticing it. */
	result [0] = result [1] = cs_Mhuge;

	return -1;
}
int CSforwardOstn02 (struct cs_Ostn02_ *__This,double osgb36 [2],const double etrs89 [2])
{
	int st;

	double delta [2];

	st = CSprivateOstn02 (__This,delta,etrs89);
	if (st == 0)
	{
		osgb36 [0] = etrs89 [0] + delta [0];
		osgb36 [1] = etrs89 [1] + delta [1];
	}
	else
	{
		osgb36 [0] = etrs89 [0];
		osgb36 [1] = etrs89 [1];
	}
	return st;
}
int CSinverseOstn02 (struct cs_Ostn02_ *__This,double etrs89 [2],const double osgb36 [2])
{
	extern char csErrnam [];
	extern double cs_Zero;

	int st;
	int itrCount;

	double delta, deltaX, deltaY;

	double fwdDelta [2];
	double myOsgb36 [2];
	double myEtrs89 [2];

	/* The default answer. */
	etrs89 [0] = osgb36 [0];	
	etrs89 [1] = osgb36 [1];

	/* Compute our first guess. */
	st = CSprivateOstn02 (__This,fwdDelta,osgb36);
	if (st > 0) return st;	

	/* Compute our first guess. */
	myEtrs89 [0] = osgb36 [0] - fwdDelta [0];
	myEtrs89 [1] = osgb36 [1] - fwdDelta [1];

	/* Loop until the change is less than 0.0001 */
	itrCount = 10;
	deltaX = deltaY = cs_Zero;
	do
	{
		/* Try to handle the unpredictable. */
		itrCount -= 1;
		if (itrCount < 0)
		{
			CS_stncp (csErrnam,"CS_geoid99:2",MAXPATH);
			CS_erpt (cs_ISER);
			st = -1;
			break;
		}

		/* Calculate a new guess. */
		myEtrs89 [0] -= deltaX;
		myEtrs89 [1] -= deltaY;
		st = CSprivateOstn02 (__This,fwdDelta,myEtrs89);
		if (st != 0) break;
		myOsgb36 [0] = myEtrs89 [0] + fwdDelta [0];
		myOsgb36 [1] = myEtrs89 [1] + fwdDelta [1];
		deltaX = myOsgb36 [0] - osgb36 [0];
		deltaY = myOsgb36 [1] - osgb36 [1];
		delta = (fabs (deltaX) > fabs (deltaY)) ? deltaX : deltaY;
	} while (fabs (delta) > 0.0001);

	if (st == 0)
	{
		etrs89 [0] = myEtrs89 [0];
		etrs89 [1] = myEtrs89 [1];
	}
	return st;
}
/* This function creates a binary version of the Ostn02 file if it doesn't
   exist, or if the date on the binary file is older than that of the
   text file.  Note, that this function uses the path name in the
   provided object, and modifies it to point to the binary file which
   is created.
   
   This function is required as records in the ASCII text file are not
   of fixed length, and there are a million of them.  The binary file
   enables random access to the data file for decent performance without
   eating up 25MB of RAM, virtual or otherwise.

   Also note that this function writes a header to the front of the
   binary file.   This header is used to populate the information
   in the provided object (*__This).  This enables support of
   several different files, which we think may be necessary in
   future (I.e. Republic of Ireland and Northern Ireland).
*/
int CSmkBinaryOstn02 (struct cs_Ostn02_ *__This)
{
	extern char cs_ExtsepC;
	extern char csErrnam [];

	int st;
	int idx;

	long eleCount;
	long recCount;
	long lineCnt;
	long lineNbr;
	long geoFlag;
	long crnrXY [2];

	cs_Time_ aTime, bTime;

	float deltaX;
	float deltaY;
	float deltaZ;

	char *cp;
	char *cpn;
	csFILE *aStrm;
	csFILE *bStrm;

	char lineBufr [256];
	char binaryPath [MAXPATH];

	aStrm = NULL;
	bStrm = NULL;

	CS_stncp (binaryPath,__This->filePath,sizeof (binaryPath));
	cp = strrchr (binaryPath,cs_ExtsepC);
	if (cp == NULL) 
	{
		CS_stncp (csErrnam,__This->filePath,MAXPATH);
		CS_erpt (cs_DTC_FILE);
		goto error;
	}
	CS_stcpy ((cp + 1),"_02");

	aTime = CS_fileModTime (__This->filePath);
	if (aTime == 0)
	{
		CS_stncp (csErrnam,__This->filePath,MAXPATH);
		CS_erpt (cs_DTC_FILE);
		goto error;
	}

	bTime = CS_fileModTime (binaryPath);
	if (bTime == 0 || bTime <= aTime)
	{
		/* Here to create a, possibly new, binary version of the
		   OSTN02??.txt file.  We write a file which has two longs
		   for each line of text that we read. */
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

		/* If we're still here, we can copy the file, converting it to
		   binary form as we do. */

		recCount = 1L;
		eleCount = 0L;
		lineCnt = 0L;
		while (CS_fgets (lineBufr,sizeof (lineBufr),aStrm) != NULL)
		{
			lineCnt += 1;
			lineNbr = -1L;
			crnrXY [0] = 0L;
			crnrXY [1] = 0L;
			deltaX = 0.0;
			deltaY = 0.0;
			deltaZ = 0.0;
			geoFlag = 0L;

			/* Parse the line of text.  The items are separated by
			   commas.  We extract the first three fields for
			   quality control.  */
			for (cp = lineBufr,idx = 0; idx < 7;idx += 1)
			{
				if (idx < 6) cpn = strchr (cp,',');
				else         cpn = strchr (cp,'\n');
				if (cpn == NULL) break;

				*cpn++ = '\0';
				switch (idx) {
				case 0:
					lineNbr = atol (cp);
					break;
				case 1:
					crnrXY [0] = atol (cp);
					break;
				case 2:
					crnrXY [1] = atol (cp);
					break;
				case 3:
					deltaX = (float)atof (cp);
					break;
				case 4:
					deltaY = (float)atof (cp);
					break;
				case 5:
					deltaZ = (float)atof (cp);
					break;
				case 6:
					geoFlag = atol (cp);
					break;
				default:
					CS_stncp (csErrnam,"CS_ostn02:3",MAXPATH);
					CS_erpt (cs_ISER);
					goto error;
				}
				cp = cpn;
			}

			/* Apply a fairly rigorous quality control check. */
			if (idx != 7 || lineNbr != lineCnt)
			{
				CS_erpt (cs_INV_FILE);
				goto error;
			}
			if (geoFlag == 0L && (deltaX != 0L ||
								  deltaY != 0L ||
								  deltaZ != 0L))
			{
				CS_erpt (cs_INV_FILE);
				goto error;
			}
			if (geoFlag != 0L && (deltaX == 0L ||
								  deltaY == 0L ||
								  deltaZ == 0L))
			{
				CS_erpt (cs_INV_FILE);
				goto error;
			}
			if (geoFlag < 0 || geoFlag > 14)
			{
				CS_erpt (cs_INV_FILE);
				goto error;
			}

			/* If this is not the first line, and delatX == 0L, we have completed a
			   band in the file.  That is, we should now know the element count. */
			if (lineNbr != 1 && crnrXY [0] == 0L)
			{
				if (eleCount != __This->elementCount)
				{
					CS_erpt (cs_INV_FILE);
					goto error;
				}
				eleCount = 1L;
				recCount += 1;
			}
			else
			{
				eleCount += 1;
			}

			/* Write a record out to the binary file. */
			CS_fwrite (&deltaX,sizeof (float),1,bStrm);
			CS_fwrite (&deltaY,sizeof (float),1,bStrm);
		}
		if (recCount != __This->recordCount)
		{
			CS_erpt (cs_INV_FILE);
			goto error;
		}
		CS_fclose (aStrm);
		st = CS_fclose (bStrm);

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
	if (aStrm != NULL) CS_fclose (aStrm);						 /*lint !e449*/
	if (bStrm != NULL)											 /*lint !e449*/
	{
		CS_fclose (bStrm);
		CS_remove (binaryPath);									/*lint !e534*/
	}
	return -1;
}
#ifdef _DEBUG
double CStestOstn02 (struct cs_Ostn02_ *__This)
{
	double deltaX, deltaY;
	double knownEtrs89 [2];
	double calcEtrs89 [2];
	double calcOsgb36 [2];
	double knownOsgb36 [2];

	knownEtrs89 [0] = 651307.003;
	knownEtrs89 [1] = 313255.686;
	knownOsgb36 [0] = 651409.903;
	knownOsgb36 [1] = 313177.270;

	CSforwardOstn02 (__This,calcOsgb36,knownEtrs89);
	deltaX = knownOsgb36 [0] - calcOsgb36 [0];
	deltaY = knownOsgb36 [1] - calcOsgb36 [1];
	CSinverseOstn02 (__This,calcEtrs89,calcOsgb36);
	deltaX += knownEtrs89 [0] - calcEtrs89 [0];
	deltaY += knownEtrs89 [1] - calcEtrs89 [1];
	return sqrt (deltaX * deltaX + deltaY * deltaY);
}
#endif

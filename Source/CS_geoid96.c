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

			 File Name: $RCSfile: CS_geoid96.c $
		   Description:
			   Purpose:

		Revision Level:	$Revision: #4 $
		 Check In Date:	$Date: 2006/11/16 $

		Last Revision:	$Log: CS_geoid96.c $
		Last Revision:	Revision 11.1300  2005/05/25 23:27:12  nto
		Last Revision:	Official Release 11.13
		Last Revision:	Revision 11.1200  2005/01/15 18:27:12  nto
		Last Revision:	Official Release of CS-MAP 11.12, 11:26am 15 Jan 2005
		Last Revision:	Revision 11.1100  2004/11/01 18:53:09  nto
		Last Revision:	Official release 11.11
		Last Revision:	Revision 11.1001  2004/10/07 19:25:18  nto
		Last Revision:	Revision 11.901  2004/08/07 03:37:44  nto
		Last Revision:	Fixed calculation of deltaLng, caused errors up to 20cm.
		Last Revision:	Revision 11.900  2004/03/26 17:02:24  nto
		Last Revision:	Official release: 11.09 - 3/25/2003
		Last Revision:	Revision 11.800  2004/01/13 23:29:13  nto
		Last Revision:	Revision 11.700  2003/12/19 01:49:53  nto
		Last Revision:	Official release 11.07
		Last Revision:	Revision 11.600  2003/12/04 02:46:28  nto
		Last Revision:	Release 11.06.  Never shipped. Source captured in prep for C++ V7.
		Last Revision:	Revision 11.502  2003/11/24 01:12:07  nto
		Last Revision:	Correct very remote possibility of addressing fault when errors occur.
		Last Revision:	Revision 11.501  2003/08/22 21:12:56  nto
		Last Revision:	Official Release: 11.05
		Last Revision:	Revision 11.401  2003/05/01 23:06:22  nto
		Last Revision:	Revision 11.300  2003/02/25 04:29:17  nto
		Last Revision:	Official Release 11.03
		Last Revision:	Revision 11.100  2002/11/22 19:38:44  nto
		Last Revision:	Official release: 11.01
		Last Revision:	Revision 10.1501  2002/11/21 20:33:30  nto
		Last Revision:	Lint cleanup.
		Last Revision:	Revision 10.1500  2002/09/22 00:01:20  nto
		Last Revision:	Official Release:= 10.15
		Last Revision:	Revision 10.1400  2002/08/09 18:14:22  nto
		Last Revision:	Revision 10.1200  2002/07/14 03:26:16  nto
		Last Revision:	Revision 10.1100  2002/06/13 14:18:37  nto
		Last Revision:	Release 10.11 Official
		Last Revision:	Revision 10.1000  2002/02/23 21:18:26  nto
		Last Revision:	Official Release of 10.10, 2/22/02 - Norm Olsen
		Last Revision:	Revision 1.2  2002/01/30 00:56:05  nto
		Last Revision:	Geoid 96 and 99 now work, and have been superficially tested.
		Last Revision:	Revision 1.1  2002/01/30 00:55:12  nto
		Last Revision:	Initial Revision

******************************************************************************/

#ifdef LABEL_MODULE
static char revlvl [] = {"$Id: //depot/Libraries/CsMap/current/src/CS_geoid96.c#4 $"};
#endif

#include "cs_map.h"

/*
	This file contains the implementation of the Geoi96 object.
	Geoid96 is a slight variation of the NADCON Grid thing.  The
	primary difference is the way the interpolation within the
	grid cell is performed.  To implement this without creating
	a ton of spaghetti, we end up duplicating a lot of code.

	"You pays your money, and you takes your choice."

	A lot of this duplicates code in csGridFileUS.c, and the rest
	of it is code duplicated in CS_geoid99.c
*/

extern char csErrnam [MAXPATH];

/*****************************************************************************
	'Private' support function
*/
void CSinitGeoid96 (struct csGeoid96GridFile_ *__This)
{
	CSinitCoverage (&__This->coverage);
	__This->elementCount = 0;
	__This->recordCount = 0;
	__This->recordSize = 0;
	__This->deltaLng = 0.0;
	__This->deltaLat = 0.0;
	__This->strm = NULL;
	__This->bufferSize = 0L;
	__This->bufferBeginPosition = 0;
	__This->bufferEndPosition = 0;
	__This->dataBuffer = NULL;
	__This->filePath [0] = '\0';
	__This->fileName [0] = '\0';
}

/*****************************************************************************
	Constructor
*/
struct csGeoid96GridFile_* CSnewGeoid96GridFile (Const char *path,long bufferSize,unsigned long flags,double density)
{
	extern char cs_DirsepC;
	extern char cs_ExtsepC;
	extern char csErrnam [];

	size_t readCount;
	long lngTmp;
	char *cp1, *cp2;
	csFILE *fstr;
	struct csGeoid96GridFile_* __This;
	char cTemp [MAXPATH];
	struct csGridHdrUS_ geoid96Hdr;

	/* Prepare for an error. */
	__This = NULL;
	fstr = NULL;

	/* Malloc and initialize */
	__This = CS_malc (sizeof (struct csGeoid96GridFile_));
	if (__This == NULL)
	{
		CS_erpt (cs_NO_MEM);
		goto error;
	}
	CSinitGeoid96 (__This);

	/* Set default values for all members. */
	__This->bufferSize = bufferSize;
	if (__This->bufferSize < 0) __This->bufferSize = 0;

	/* Save file path/name. */
	CS_stncp (__This->filePath,path,sizeof (__This->filePath));
	CS_stncp (cTemp,path,sizeof (cTemp));

	/* Set up the type of file.  Get cp1 to point at the file
	   name, and cp2 to point at the extension.  We consider it
	   an error if we are not given a full path name.  Note,
	   we care not about the format of the drive specification.
	   But there must be at least one directory and there must
	   be an extension. */
	cp1 = strrchr (cTemp,cs_DirsepC);
	if (cp1 == NULL)
	{
		CS_stncp (csErrnam,__This->filePath,MAXPATH);
		CS_erpt (cs_INV_FILE);
		goto error;
	}
	cp1 += 1;
	cp2 = strchr (cp1,cs_ExtsepC);
	if (cp2 == NULL)
	{
		CS_stncp (csErrnam,__This->filePath,MAXPATH);
		CS_erpt (cs_INV_FILE);
		goto error;
	}
	*cp2++ = '\0';
	CS_stncp (__This->fileName,cp1,sizeof (__This->fileName));

	/* The thing should have a .geo extension to be processed by us. */
	if (CS_stricmp (cp2,"geo"))
	{
		CS_stncp (csErrnam,__This->filePath,MAXPATH);
		CS_erpt (cs_INV_FILE);
		goto error;
	}

	/* Get the file information header. */
	fstr = CS_fopen (__This->filePath,_STRM_BINRD);
	if (fstr == NULL)
	{
		CS_stncp (csErrnam,__This->filePath,MAXPATH);
		CS_erpt (cs_DTC_FILE);
		goto error;
	}
	readCount = CS_fread (&geoid96Hdr,1,sizeof (geoid96Hdr),fstr);
	if (readCount != sizeof (geoid96Hdr))
	{
		CS_stncp (csErrnam,__This->filePath,MAXPATH);
		CS_erpt (cs_INV_FILE);
		goto error;
	}
	if (CS_ferror (fstr))
	{
		CS_stncp (csErrnam,__This->filePath,MAXPATH);
		CS_erpt (cs_IOERR);
		goto error;
	}

	/* Determine the size of the file. */
	if (CS_fseek (fstr,0L,SEEK_END))
	{
		CS_stncp (csErrnam,__This->filePath,MAXPATH);
		CS_erpt (cs_IOERR);
		goto error;
	}
	__This->fileSize = CS_ftell (fstr);
	if (__This->fileSize < 0L)
	{
		CS_stncp (csErrnam,__This->filePath,MAXPATH);
		CS_erpt (cs_IOERR);
		goto error;
	}

	/* This constructor doesn't need the file any more. */
	CS_fclose (fstr);
	fstr = NULL;

	/* Swap the bytes if necessary. */
	CS_bswap (&geoid96Hdr,cs_BSWP_GridFileHdrUS);

	/* The extra stuff here is required as conversions of floats to doubles
	   does not always provide precise results.  To get the precise results we
	   require, we assume that the value (which is in degrees) is an intergal
	   number of seconds. */
	lngTmp = (long)(((double)geoid96Hdr.del_lng * 3600.0) + 0.4);
	__This->deltaLng = ((double)lngTmp / 3600.0);
	lngTmp = (long)(((double)geoid96Hdr.del_lat * 3600.0) + 0.4);
	__This->deltaLat = ((double)lngTmp / 3600.0);

	/* Now we can do the rest of this stuff. */
	__This->coverage.southWest [LNG] = geoid96Hdr.min_lng;
	__This->coverage.southWest [LAT] = geoid96Hdr.min_lat;
	__This->coverage.northEast [LNG] = geoid96Hdr.min_lng + (__This->deltaLng * (geoid96Hdr.ele_cnt - 1));
	__This->coverage.northEast [LAT] = geoid96Hdr.min_lat + (__This->deltaLat * (geoid96Hdr.rec_cnt - 1));
	__This->coverage.density = (__This->deltaLng < __This->deltaLat) ? __This->deltaLng : __This->deltaLat;
	if (density != 0.0) __This->coverage.density = density;
	__This->elementCount = geoid96Hdr.ele_cnt;
	__This->recordCount = geoid96Hdr.rec_cnt;
	__This->recordSize = geoid96Hdr.ele_cnt * (int)sizeof (float) + (int)sizeof (long);

	/* Verify the integrity of the file. */
	lngTmp = (__This->recordCount + 1) * __This->recordSize;
	if (lngTmp != __This->fileSize)
	{
		CS_stncp (csErrnam,__This->filePath,MAXPATH);
		CS_erpt (cs_INV_FILE);
		goto error;
	}

	/* Now that we know recordSize, we can adjust the bufferSize for maximum
	   efficiency. */
	if (__This->bufferSize > __This->fileSize)
	{
		__This->bufferSize = __This->fileSize;
	}
	else
	{
		if (__This->bufferSize > (3 * __This->recordSize))
		{
			/* Maximum efficiency is obtained with a buffer size whch is
			   a multiple of the record size. */
			__This->bufferSize = (__This->bufferSize / __This->recordSize) * __This->recordSize;
		}
		else
		{
			/* We require a minimum buffer size of 3 records. */
			__This->bufferSize = 3 * __This->recordSize;
		}
	}

	return (__This);
error:
	CSdeleteGeoid96GridFile (__This);
	return NULL;
}
/*****************************************************************************
	Destructor
*/
void CSdeleteGeoid96GridFile (struct csGeoid96GridFile_* __This)
{
	if (__This != NULL)
	{
		if (__This->strm != NULL) CS_fclose (__This->strm);
		if (__This->dataBuffer != NULL)	CS_free (__This->dataBuffer);
		CS_free (__This);
	}
}
/*****************************************************************************
	Release resources
*/
void CSreleaseGeoid96GridFile (struct csGeoid96GridFile_* __This)
{
	if (__This != NULL)
	{
		/* Close the file and release the buffer.  Leave the file size,
		   buffer size, coverage information, and other stuff intact.
		   The only purpose here is to release allocated resources. */

		/* Free and invalidate the buffer, if there is one. */
		if (__This->dataBuffer != NULL)
		{
			CS_free (__This->dataBuffer);
		}
		__This->dataBuffer = NULL;
		__This->bufferBeginPosition = -1L;
		__This->bufferEndPosition = -2L;

		/* Close the file (if open). */
		if (__This->strm != NULL)
		{
			CS_fclose (__This->strm);
		}
		__This->strm = NULL;
	}
	return;
}

/*****************************************************************************
	Coverage Test
*/
double CStestGeoid96GridFile (struct csGeoid96GridFile_* __This,Const double *sourceLL)
{
	/* Returns zero if not covered, file density if covered. */
	return CStestCoverageUS (&(__This->coverage),sourceLL);
}

/*****************************************************************************
	This function would be a private function in C++.
	This function sets the currentCell member to the cell which covers the
	provided geographic coordinate.  Returns 0 on success or a negative value
	for a system error of some sort (i.e. file I/O).  Per the design of this
	object, this function is not to be called unless the provided source
	coordinate is within the coverage of the object.
*/
int CScalcGeoid96GridFile (struct csGeoid96GridFile_* __This,double* result,Const double* sourceLL)
{
	extern double cs_One;

	int eleNbr;
	int recNbr;
	int readCount;
	int checkCount;

	long lngTmp;
	long checkSeek;
	long fpos;
	long fposBegin;
	long fposEnd;

	char* chrPtr;
	float* fltPtr;

	double centerLL [2];
	double deltaLL [2];

	/* Float array carries the 3x3 array as follows:
		         North

		W       0  1  2      E
		e       3  4  5      a
		s       6  7  8      s
		t                    t 
			     South          */
	float array [9];

	enum edgeEffects {	edgeNone = 0,
						edgeSouthwest,
						edgeSouth,
						edgeSoutheast,
						edgeEast,
						edgeNortheast,
						edgeNorth,
						edgeNorthwest,
						edgeWest
					 } edge;
	edge = edgeNone;

	/* We are not supposed to get here unless the sourceLL is within the coverage of the
	   file object.  We make sure of that now.  This makes life much easier below.  Use the
	   CStestGeoid96GridFile function to select the proper csGeoid96GridFile object. */
	if (sourceLL [LNG] < __This->coverage.southWest [LNG] || sourceLL [LNG] > __This->coverage.northEast [LNG] ||
	    sourceLL [LAT] < __This->coverage.southWest [LAT] || sourceLL [LAT] > __This->coverage.northEast [LAT])
	{
		CS_stncp (csErrnam,"CS_geoid96:1",MAXPATH);
		CS_erpt  (cs_ISER);
		goto error;
	}
	   
	/* Compute the basic indices to the cell in the data file.  We're supposed to come up
	   with a reference to the closest point.  Since we know the source coordinate is within
	   range, dealing with the edges is rather easy. */
	eleNbr = (long)(((sourceLL [LNG] - __This->coverage.southWest [LNG]) / __This->deltaLng) + 0.5);
	recNbr = (long)(((sourceLL [LAT] - __This->coverage.southWest [LAT]) / __This->deltaLat) + 0.5);

	/* Determine the if an edge effect applies. */
	if (recNbr < 1)
	{
		recNbr = 1;
		if (eleNbr < 1)
		{
			eleNbr = 1;
			edge = edgeSouthwest;
		}
		else if (eleNbr >= __This->elementCount - 1)
		{
			eleNbr = __This->elementCount - 2;
			edge = edgeSoutheast;
		}
		else
		{
			edge = edgeSouth;
		}
	}
	else if (recNbr >= __This->recordCount - 1)
	{
		if (eleNbr < 1)
		{
			eleNbr = 1;
			edge = edgeNorthwest;
		}
		else if (eleNbr >= __This->elementCount - 1)
		{
			eleNbr = __This->elementCount - 2;
			edge = edgeNortheast;
		}
		else
		{
			edge = edgeNorth;
		}
	}
	else
	{
		if (eleNbr < 1)
		{
			eleNbr = 1;
			edge = edgeWest;
		}
		else if (eleNbr > __This->elementCount -1)
		{
			eleNbr = __This->elementCount - 2;
			edge = edgeEast;
		}
		else
		{
			edge = edgeNone;
		}
	}

	/* Compute the minimal region of the file which we need to read.  Note that
	   the header in a US grid file is always one recordSize in length. */
	fposBegin = __This->recordSize + (recNbr - 1) * __This->recordSize;
	fposEnd = fposBegin + (__This->recordSize * 3);
	if (fposEnd > __This->fileSize) fposEnd = __This->fileSize;
	
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

	/* See if the stuff we want is in the buffer.  Careful here, all of the intended
	   range must be in the buffer, not just a portion of it. */
	if (fposBegin < __This->bufferBeginPosition || fposBegin > __This->bufferEndPosition ||
		fposEnd   < __This->bufferBeginPosition || fposEnd   > __This->bufferEndPosition)
	{
		/* The data we need is not there; we need to read it in.  Is the file open? */
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

		/* Compute the starting position of the actual read. */
		if (__This->bufferSize >= __This->fileSize)
		{
			__This->bufferBeginPosition = 0L;
			__This->bufferEndPosition = __This->fileSize;
			readCount = __This->fileSize;
		}
		else
		{
			/* We need to do a partial read, the normal case.  Initialize for the
			   minimal case computed above, then expand as is possible.  Note, we
			   get here only when a read has to be done. */
			__This->bufferBeginPosition = fposBegin;
			__This->bufferEndPosition = fposEnd;
			readCount = __This->bufferEndPosition - __This->bufferBeginPosition;

			/* In this section, lngTmp is the number of additional records
			   which can fit in the buffer. */
			lngTmp = (__This->bufferSize - readCount) / __This->recordSize;
			if (lngTmp > 3L)
			{
				/* Move the beginning of the read up by one half of the
				   amount of extra space in the buffer; but never past the
				   beginning of record number 1. */
				lngTmp = lngTmp / 2;
				__This->bufferBeginPosition -= __This->recordSize * lngTmp;
				if (__This->bufferBeginPosition < __This->recordSize)
				{
					__This->bufferBeginPosition = __This->recordSize;
				}
				readCount = __This->bufferEndPosition - __This->bufferBeginPosition;
			}

			lngTmp = (__This->bufferSize - readCount) / __This->recordSize;
			if (lngTmp > 3L)
			{
				/* Move the end of the read back by the amount of extra
				   space in the buffer, but never past the end of the file. */
				__This->bufferEndPosition += __This->recordSize * lngTmp;
				if (__This->bufferEndPosition > __This->fileSize)
				{
					__This->bufferEndPosition = __This->fileSize;
				}
				readCount = __This->bufferEndPosition - __This->bufferBeginPosition;
			}

			lngTmp = (__This->bufferSize - readCount) / __This->recordSize;
			if (lngTmp > 0L)
			{
				/* In case the expanded end of read exceeded the end of the
				   file, we can move the beginning of the read up some more,
				   However, never more than the beginning of the first
				   data record. */
				__This->bufferBeginPosition -= __This->recordSize * lngTmp;
				if (__This->bufferBeginPosition < __This->recordSize)
				{
					__This->bufferBeginPosition = __This->recordSize;
				}
				readCount = __This->bufferEndPosition - __This->bufferBeginPosition;
			}

			/* Defensive programming. */
			if (readCount != __This->bufferSize)
			{
				CS_stncp (csErrnam,"CS_geoid96:2",MAXPATH);
				CS_erpt (cs_ISER);
				goto error;
			}
		}

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
		/* Note, we swap the individual cells as we need them.  Perhaps we should
		   swap the whole buffer now, but we don't.  We do each data item as
		   it is required. */

		/* We have the desired data in the buffer.  If we read in the whole file,
		   we close the stream now.  No need to have the file descriptor open. */
		if (__This->bufferSize == __This->fileSize)
		{
			CS_fclose (__This->strm);
			__This->strm = NULL;
		}
	}

	/* Compute the delta into the grid cell we will contruct below.  Note, we are using adjusted
	   recNbr and eleNbr variables here. */
	centerLL [LNG] = __This->coverage.southWest [LNG] + __This->deltaLng * (double)eleNbr;
	centerLL [LAT] = __This->coverage.southWest [LAT] + __This->deltaLat * (double)recNbr;
	deltaLL [LNG] = ((sourceLL [LNG] - centerLL [LNG]) / __This->deltaLng) + cs_One;
	deltaLL [LAT] = ((centerLL [LAT] - sourceLL [LAT]) / __This->deltaLat) + cs_One;

	/* OK, the necessary stuff should be in the buffer.  We do what is necessary to
	   populate the array.  Notice, we populate the array in a way that the edge
	   effects come out correct using a standard algorithm below. */
	switch (edge) {
	case edgeNone:
		fpos = __This->recordSize + (recNbr * __This->recordSize) + sizeof (long) + (eleNbr * sizeof (float));

		chrPtr = (char *)(__This->dataBuffer) + (fpos - __This->bufferBeginPosition);
		chrPtr += __This->recordSize;
		fltPtr = (float *)(chrPtr);
		array [0] = *(fltPtr - 1);
		array [1] = *fltPtr;
		array [2] = *(fltPtr + 1);

		chrPtr = (char *)(__This->dataBuffer) + (fpos - __This->bufferBeginPosition);
		fltPtr = (float *)(chrPtr);
		array [3] = *(fltPtr - 1);
		array [4] = *fltPtr;
		array [5] = *(fltPtr + 1);

		chrPtr = (char *)(__This->dataBuffer) + (fpos - __This->bufferBeginPosition);
		chrPtr -= __This->recordSize;
		fltPtr = (float *)(chrPtr);
		array [6] = *(fltPtr - 1);
		array [7] = *fltPtr;
		array [8] = *(fltPtr + 1);
		break;

	case edgeSouthwest:
		fpos = __This->recordSize + sizeof (long);
		chrPtr = (char *)(__This->dataBuffer) + (fpos - __This->bufferBeginPosition);
		fltPtr = (float *)(chrPtr);

		array [0] = array [1] = array [2] = *fltPtr;
		array [3] = array [4] = array [5] = *fltPtr;
		array [6] = array [7] = array [8] = *fltPtr;

		deltaLL [LNG] = deltaLL [LAT] = cs_One;
		break;

	case edgeSouth:
		fpos = __This->recordSize + sizeof (long) + eleNbr * sizeof (float);
		chrPtr = (char *)(__This->dataBuffer) + (fpos - __This->bufferBeginPosition);
		fltPtr = (float *)(chrPtr);

		array [0] = array [3] = array [6] = *(fltPtr - 1);
		array [1] = array [4] = array [7] = *fltPtr;
		array [2] = array [5] = array [8] = *(fltPtr + 1);

		deltaLL [LAT] = cs_One;
		break;

	case edgeSoutheast:
		fpos = __This->recordSize + sizeof (long) + (__This->elementCount - 1) * sizeof (float);
		chrPtr = (char *)(__This->dataBuffer) + (fpos - __This->bufferBeginPosition);
		fltPtr = (float *)(chrPtr);

		array [0] = array [1] = array [2] = *fltPtr;
		array [3] = array [4] = array [5] = *fltPtr;
		array [6] = array [7] = array [8] = *fltPtr;

		deltaLL [LNG] = deltaLL [LAT] = cs_One;
		break;

	case edgeEast:
		fpos = __This->recordSize + recNbr * __This->recordSize + sizeof (long) + (__This->elementCount - 1) * sizeof (float);
		chrPtr = (char *)(__This->dataBuffer) + (fpos - __This->bufferBeginPosition);
		chrPtr += __This->recordSize;
		fltPtr = (float *)(chrPtr);

		array [0] = array [1] = array [2] = *fltPtr;

		chrPtr = (char *)(__This->dataBuffer) + (fpos - __This->bufferBeginPosition);
		fltPtr = (float *)(chrPtr);
		array [3] = array [4] = array [5] = *fltPtr;

		chrPtr = (char *)(__This->dataBuffer) + (fpos - __This->bufferBeginPosition);
		chrPtr -= __This->recordSize;
		fltPtr = (float *)(chrPtr);
		array [6] = array [7] = array [8] = *fltPtr;

		deltaLL [LNG] = cs_One;
		break;

	case edgeNortheast:
		fpos = __This->recordSize + (__This->recordCount - 1) * __This->recordSize + sizeof (long) + (__This->elementCount - 1) * sizeof (float);
		chrPtr = (char *)(__This->dataBuffer) + (fpos - __This->bufferBeginPosition);
		fltPtr = (float *)(chrPtr);

		array [0] = array [1] = array [2] = *fltPtr;
		array [3] = array [4] = array [5] = *fltPtr;
		array [6] = array [7] = array [8] = *fltPtr;

		deltaLL [LNG] = deltaLL [LAT] = cs_One;
		break;

	case edgeNorth:
		fpos = __This->recordSize + (__This->recordCount - 1) * __This->recordSize + sizeof (long) + eleNbr * sizeof (float);
		chrPtr = (char *)(__This->dataBuffer) + (fpos - __This->bufferBeginPosition);
		fltPtr = (float *)(chrPtr);

		array [0] = array [3] = array [6] = *(fltPtr - 1);
		array [1] = array [4] = array [7] = *fltPtr;
		array [2] = array [5] = array [8] = *(fltPtr + 1);

		deltaLL [LAT] = cs_One;
		break;

	case edgeNorthwest:
		fpos = __This->recordSize + (__This->recordCount - 1) * __This->recordSize + sizeof (long);
		chrPtr = (char *)(__This->dataBuffer) + (fpos - __This->bufferBeginPosition);
		fltPtr = (float *)(chrPtr);

		array [0] = array [1] = array [2] = *fltPtr;
		array [3] = array [4] = array [5] = *fltPtr;
		array [6] = array [7] = array [8] = *fltPtr;

		deltaLL [LNG] = deltaLL [LAT] = cs_One;
		break;

	case edgeWest:
		fpos = __This->recordSize + recNbr * __This->recordSize + sizeof (long);
		chrPtr = (char *)(__This->dataBuffer) + (fpos - __This->bufferBeginPosition);
		chrPtr += __This->recordSize;
		fltPtr = (float *)(chrPtr);
		array [0] = array [1] = array [2] = *fltPtr;

		chrPtr = (char *)(__This->dataBuffer) + (fpos - __This->bufferBeginPosition);
		fltPtr = (float *)(chrPtr);
		array [3] = array [4] = array [5] = *fltPtr;

		chrPtr = (char *)(__This->dataBuffer) + (fpos - __This->bufferBeginPosition);
		chrPtr -= __This->recordSize;
		fltPtr = (float *)(chrPtr);
		array [6] = array [7] = array [8] = *fltPtr;

		deltaLL [LNG] = cs_One;
		break;
	}

	/* Swap bytes as appropriate. */
	CS_bswap (array,"fffffffff");

	/* Do the calculations. */
	*result = CSgeoidQterp (deltaLL,array);
	return 0;

error:
	/* Release the resources allocated to this object.  The next call to this
	   object would then require a refresh. */
	CSreleaseGeoid96GridFile (__This);

	/* Negative return indicates a system error of sorts. */
	return -1;
}

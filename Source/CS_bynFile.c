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

			 File Name: $RCSfile: CS_bynFile.c $
		   Description:
			   Purpose:

		Revision Level:	$Revision: #4 $
		 Check In Date:	$Date: 2006/11/16 $

		Last Revision:	$Log: CS_bynFile.c $
		Last Revision:	Revision 11.1300  2005/05/25 23:27:07  nto
		Last Revision:	Official Release 11.13
		Last Revision:	Revision 11.1200  2005/01/15 18:27:09  nto
		Last Revision:	Official Release of CS-MAP 11.12, 11:26am 15 Jan 2005
		Last Revision:	Revision 11.1100  2004/11/01 18:53:06  nto
		Last Revision:	Official release 11.11
		Last Revision:	Revision 11.1001  2004/10/07 19:25:15  nto
		Last Revision:	Revision 11.900  2004/03/26 17:02:22  nto
		Last Revision:	Official release: 11.09 - 3/25/2003
		Last Revision:	Revision 11.800  2004/01/13 23:29:10  nto
		Last Revision:	Revision 11.700  2003/12/19 01:49:50  nto
		Last Revision:	Official release 11.07
		Last Revision:	Revision 11.600  2003/12/04 02:46:25  nto
		Last Revision:	Release 11.06.  Never shipped. Source captured in prep for C++ V7.
		Last Revision:	Revision 11.502  2003/11/24 01:12:03  nto
		Last Revision:	Correct very remote possibility of addressing fault when errors occur.
		Last Revision:	Revision 11.501  2003/08/22 21:12:53  nto
		Last Revision:	Official Release: 11.05
		Last Revision:	Revision 11.401  2003/05/01 23:06:19  nto
		Last Revision:	Revision 11.300  2003/02/25 04:29:14  nto
		Last Revision:	Official Release 11.03
		Last Revision:	Revision 11.100  2002/11/22 19:38:41  nto
		Last Revision:	Official release: 11.01
		Last Revision:	Revision 10.1501  2002/11/21 20:17:56  nto
		Last Revision:	Lint clean up, removeed some unused stuff.
		Last Revision:	Revision 10.1500  2002/09/22 00:01:17  nto
		Last Revision:	Official Release:= 10.15
		Last Revision:	Revision 10.1400  2002/08/09 18:14:20  nto
		Last Revision:	Revision 1.2  2002/07/23 04:06:53  nto
		Last Revision:	Original check in, this version appears to work reliably.
		Last Revision:	Revision 1.1  2002/07/23 04:06:24  nto
		Last Revision:	Initial Revision

******************************************************************************/

#ifdef LABEL_MODULE
static char revlvl [] = {"$Id: //depot/Libraries/CsMap/current/src/CS_bynFile.c#4 $"};
#endif

#include "cs_map.h"

/*
	This file contains the implementation of the BynFile object.
	BynFile's are very similar to Geoid99 type files and are
	also used for data sets other than geoid heights.

	Anywho, the implementation, use, and purpose are different
	enough to warrant a separate set of implementation code.
*/

extern char csErrnam [MAXPATH];

short CSswapShort (short source,int swapEm);
long  CSswapLong  (long source,int swapEm);
double EXP_LVL9 CSbynGridFileQterp (double sourceDelta [2],double array [9]);
double EXP_LVL9 CSbynGridFileQterp1 (double delta,double f0,double f1,double f2);

/*****************************************************************************
	'Private' support function
*/
void CSinitBynGridFile (struct csBynGridFile_ *__This)
{
	CSinitCoverage (&__This->coverage);
	__This->elementCount = 0;
	__This->recordCount = 0;
	__This->recordSize = 0;
	__This->deltaLng = 0.0;
	__This->deltaLat = 0.0;
	__This->dataFactor = 1.0;
	__This->fileSize = 0L;
	__This->strm = NULL;
	__This->bufferSize = 0L;
	__This->bufferBeginPosition = 0;
	__This->bufferEndPosition = 0;
	__This->dataBuffer = NULL;
	__This->fileType = 0;
	__This->elementSize = 0;
	__This->byteOrder = 1;
	__This->swapFlag = 0;
	__This->filePath [0] = '\0';
	__This->fileName [0] = '\0';
}

/*****************************************************************************
	Constructor
*/
struct csBynGridFile_* CSnewBynGridFile (Const char *path,long bufferSize,unsigned long flags,double density)
{
	extern double cs_Sec2Deg;
	extern double cs_One;

	extern char cs_DirsepC;
	extern char cs_ExtsepC;
	extern char csErrnam [];

	size_t readCount;
	long lngTmp;
	char *cp1, *cp2;
	csFILE *fstr;
	struct csBynGridFile_* __This;
	char cTemp [MAXPATH];
	struct csBynGridFileHdr_ bynFileHdr;

	/* Prepare for an error. */
	__This = NULL;
	fstr = NULL;

	/* Malloc and initialize */
	__This = CS_malc (sizeof (struct csBynGridFile_));
	if (__This == NULL)
	{
		CS_erpt (cs_NO_MEM);
		goto error;
	}
	CSinitBynGridFile (__This);

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

	/* The thing should have a .bin extension to be processed by us. */
	if (CS_stricmp (cp2,"byn"))
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
	readCount = CS_fread (&bynFileHdr,1,sizeof (bynFileHdr),fstr);
	if (readCount != sizeof (bynFileHdr))
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

	/* Swap the bytes if necessary.  Note that this implementation
	   assumes that the file is in little endian order. */
	CS_bswap (&bynFileHdr,cs_BSWP_BynFileHDR);

	/* Extract the important stuff from the header. */
	__This->coverage.southWest [LNG] = (double)bynFileHdr.westBoundary  * cs_Sec2Deg;
	__This->coverage.southWest [LAT] = (double)bynFileHdr.southBoundary * cs_Sec2Deg;
	__This->coverage.northEast [LNG] = (double)bynFileHdr.eastBoundary * cs_Sec2Deg;
	__This->coverage.northEast [LAT] = (double)bynFileHdr.northBoundary * cs_Sec2Deg;
	__This->deltaLng = (double)bynFileHdr.ewSpacing * cs_Sec2Deg;
	__This->deltaLat = (double)bynFileHdr.nsSpacing * cs_Sec2Deg;
	__This->coverage.density = (__This->deltaLng < __This->deltaLat) ? __This->deltaLng : __This->deltaLat;
	if (density != 0.0) __This->coverage.density = density;
	__This->elementCount = ((bynFileHdr.eastBoundary - bynFileHdr.westBoundary) / bynFileHdr.ewSpacing) + 1L;
	__This->recordCount = ((bynFileHdr.northBoundary - bynFileHdr.southBoundary) / bynFileHdr.nsSpacing) + 1L;
	__This->recordSize = __This->elementCount * bynFileHdr.sizeOfData;

	/* Verify the integrity of the file. */
	lngTmp = __This->recordCount * __This->recordSize + sizeof (bynFileHdr);
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

	/* Finish up with some simple stuff.  We inverse factor as
	   multiples are faster than divides, and we will probably
	   be doing a lot of them. */
	__This->dataFactor = cs_One / bynFileHdr.factor;
	__This->fileType = bynFileHdr.dataType;
	__This->elementSize = bynFileHdr.sizeOfData;
	__This->byteOrder = bynFileHdr.byteOrder;
	__This->swapFlag = ((__This->byteOrder == 0) ^ CS_isBigEndian ());	/*lint !e514 */

	return (__This);

error:
	CSdeleteBynGridFile (__This);
	return NULL;
}
/*****************************************************************************
	Destructor
*/
void CSdeleteBynGridFile (struct csBynGridFile_* __This)
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
void CSreleaseBynGridFile (struct csBynGridFile_* __This)
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
double CStestBynGridFile (struct csBynGridFile_* __This,Const double *sourceLL)
{
	extern double cs_Zero;

	int st;
	double geoidHgt;
	double density;

	density = CStestCoverageUS (&(__This->coverage),sourceLL);
	if (density > 0.0)
	{
		/* Need to do this extra check, which can be painful, as there are
		   regions in the .byn file which carry values which indicate
		   no coverage.  Note, if we get a minus 1 back from the calc
		   function, we still return the current density.  This will
		   tend to force a calc function call be the user, and the proper
		   error reporting performed at that time. */
		st = CScalcBynGridFile (__This,&geoidHgt,sourceLL);
		density = (st > 0) ? cs_Zero : __This->coverage.density;
	}
	return density;
}

/*****************************************************************************
	This function would be a private function in C++.
	This function sets the currentCell member to the cell which covers the
	provided geographic coordinate.  Returns 0 on success or a negative value
	for a system error of some sort (i.e. file I/O).  Per the design of this
	object, this function is not to be called unless the provided source
	coordinate is within the coverage of the object.
*/
int CScalcBynGridFile (struct csBynGridFile_* __This,double* result,Const double* sourceLL)
{
	extern double cs_One;

	int idx;
	int rtnVal;
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
	short *shrtPtr;
	long *lngPtr;

	double centerLL [2];
	double deltaLL [2];

	/* The arrays carry the 3x3 array as follows:
		         North

		W       6  7  8      E
		e       3  4  5      a
		s       0  1  2      s
		t                    t 
			     South          */

	short shrtArray [9];
	long lngArray [9];
	double dblArray [9];

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
	   CStestBynGridFile function to select the proper csBynGridFile object. */
	if (sourceLL [LNG] < __This->coverage.southWest [LNG] || sourceLL [LNG] > __This->coverage.northEast [LNG] ||
	    sourceLL [LAT] < __This->coverage.southWest [LAT] || sourceLL [LAT] > __This->coverage.northEast [LAT])
	{
		CS_stncp (csErrnam,"CSbynGridFile:1",MAXPATH);
		CS_erpt  (cs_ISER);
		goto error;
	}
	   
	/* Compute the basic indices to the cell in the data file.  We're supposed to come up
	   with a reference to the closest point.  Since we know the source coordinate is within
	   range, dealing with the edges is rather easy.  Note, this file goes from north to south,
	   unlike most all other files of this type.  Thus, a record number of 1 means the northern
	   edge of the data. */
	eleNbr = (long)(((sourceLL [LNG] - __This->coverage.southWest [LNG]) / __This->deltaLng) + 0.5);
	recNbr = (long)(((__This->coverage.northEast [LAT] - sourceLL [LAT]) / __This->deltaLat) + 0.5);

	/* Determine the if an edge effect applies. */
	if (recNbr < 1)
	{
		recNbr = 1;
		if (eleNbr < 1)
		{
			eleNbr = 1;
			edge = edgeNorthwest;
		}
		else if (eleNbr >= (__This->elementCount - 1))
		{
			eleNbr = __This->elementCount - 2;
			edge = edgeNortheast;
		}
		else
		{
			edge = edgeNorth;
		}
	}
	else if (recNbr >= (__This->recordCount - 1))
	{
		if (eleNbr < 1)
		{
			eleNbr = 1;
			edge = edgeSouthwest;
		}
		else if (eleNbr >= (__This->elementCount - 1))
		{
			eleNbr = __This->elementCount - 2;
			edge = edgeSoutheast;
		}
		else
		{
			edge = edgeSouth;
		}
	}
	else
	{
		if (eleNbr < 1)
		{
			eleNbr = 1;
			edge = edgeWest;
		}
		else if (eleNbr > (__This->elementCount -1))
		{
			eleNbr = __This->elementCount - 2;
			edge = edgeEast;
		}
		else
		{
			edge = edgeNone;
		}
	}

	/* Compute the minimal region of the file which we need to read. */
	fposBegin = sizeof (struct csBynGridFileHdr_) + (recNbr - 1) * __This->recordSize;
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
				if (__This->bufferBeginPosition < sizeof (struct csBynGridFileHdr_))	/*lint !e574 */
				{
					__This->bufferBeginPosition = sizeof (struct csBynGridFileHdr_);
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
				if (__This->bufferBeginPosition < sizeof (struct csBynGridFileHdr_))	/*lint !e574 */
				{
					__This->bufferBeginPosition = sizeof (struct csBynGridFileHdr_);
				}
				readCount = __This->bufferEndPosition - __This->bufferBeginPosition;
			}

			/* Defensive programming. */
			if (readCount != __This->bufferSize)
			{
				CS_stncp (csErrnam,"CSbynGridFIle:2",MAXPATH);
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
	   recNbr and eleNbr variables here.  Center is the southwest corner of the cell in the
	   center of the minigrid we will deal with. */
	centerLL [LNG] = __This->coverage.southWest [LNG] + __This->deltaLng * (double)eleNbr;
	centerLL [LAT] = __This->coverage.northEast [LAT] - __This->deltaLat * (double)recNbr;
	deltaLL [LNG] = ((sourceLL [LNG] - centerLL [LNG]) / __This->deltaLng) + cs_One;
	deltaLL [LAT] = ((sourceLL [LAT] - centerLL [LAT]) / __This->deltaLat) + cs_One;

	/* OK, the necessary stuff should be in the buffer.  We do what is necessary to
	   populate the array.  Notice, we populate the array in a way that the edge
	   effects come out correct using a standard algorithm below.  Actually, I
	   think all this edge stuff is superfluous, as the cells onthe edges are
	   probaly marked as "999" anyway.  (9999 means no data available.) */
	if (__This->elementSize == 2)
	{
		switch (edge) {
		case edgeNone:
			fpos = sizeof (struct csBynGridFileHdr_) + (recNbr * __This->recordSize) + (eleNbr * __This->elementSize);

			chrPtr = (char *)(__This->dataBuffer) + (fpos - __This->bufferBeginPosition);
			chrPtr -= __This->recordSize;
			shrtPtr = (short *)(chrPtr);
			shrtArray [6] = CSswapShort (*(shrtPtr - 1),__This->swapFlag);
			shrtArray [7] = CSswapShort (*shrtPtr,__This->swapFlag);
			shrtArray [8] = CSswapShort (*(shrtPtr + 1),__This->swapFlag);

			chrPtr = (char *)(__This->dataBuffer) + (fpos - __This->bufferBeginPosition);
			shrtPtr = (short *)(chrPtr);
			shrtArray [3] = CSswapShort (*(shrtPtr - 1),__This->swapFlag);
			shrtArray [4] = CSswapShort (*shrtPtr,__This->swapFlag);
			shrtArray [5] = CSswapShort (*(shrtPtr + 1),__This->swapFlag);

			chrPtr = (char *)(__This->dataBuffer) + (fpos - __This->bufferBeginPosition);
			chrPtr += __This->recordSize;
			shrtPtr = (short *)(chrPtr);
			shrtArray [0] = CSswapShort (*(shrtPtr - 1),__This->swapFlag);
			shrtArray [1] = CSswapShort (*shrtPtr,__This->swapFlag);
			shrtArray [2] = CSswapShort (*(shrtPtr + 1),__This->swapFlag);
			break;

		case edgeSouthwest:
			fpos = sizeof (struct csBynGridFileHdr_) + (__This->recordCount - 1) * __This->recordSize;
			chrPtr = (char *)(__This->dataBuffer) + (fpos - __This->bufferBeginPosition);
			shrtPtr = (short *)(chrPtr);

			shrtArray [6] = shrtArray [7] = shrtArray [8] = CSswapShort (*shrtPtr,__This->swapFlag);
			shrtArray [3] = shrtArray [4] = shrtArray [5] = CSswapShort (*shrtPtr,__This->swapFlag);
			shrtArray [0] = shrtArray [1] = shrtArray [2] = CSswapShort (*shrtPtr,__This->swapFlag);

			deltaLL [LNG] = deltaLL [LAT] = cs_One;
			break;

		case edgeSouth:
			fpos = sizeof (struct csBynGridFileHdr_) + (__This->recordCount - 1) * __This->recordSize + eleNbr * __This->elementSize;
			chrPtr = (char *)(__This->dataBuffer) + (fpos - __This->bufferBeginPosition);
			shrtPtr = (short *)(chrPtr);

			shrtArray [6] = shrtArray [3] = shrtArray [0] = CSswapShort (*(shrtPtr - 1),__This->swapFlag);
			shrtArray [7] = shrtArray [4] = shrtArray [1] = CSswapShort (*shrtPtr,__This->swapFlag);
			shrtArray [8] = shrtArray [5] = shrtArray [2] = CSswapShort (*(shrtPtr + 1),__This->swapFlag);

			deltaLL [LAT] = cs_One;
			break;

		case edgeSoutheast:
			fpos = sizeof (struct csBynGridFileHdr_) + (__This->recordCount - 1) * __This->recordSize + (__This->elementCount - 1) * __This->elementSize;
			chrPtr = (char *)(__This->dataBuffer) + (fpos - __This->bufferBeginPosition);
			shrtPtr = (short *)(chrPtr);

			shrtArray [6] = shrtArray [7] = shrtArray [8] = CSswapShort (*shrtPtr,__This->swapFlag);
			shrtArray [3] = shrtArray [4] = shrtArray [5] = CSswapShort (*shrtPtr,__This->swapFlag);
			shrtArray [0] = shrtArray [1] = shrtArray [2] = CSswapShort (*shrtPtr,__This->swapFlag);

			deltaLL [LNG] = deltaLL [LAT] = cs_One;
			break;

		case edgeEast:
			fpos = sizeof (struct csBynGridFileHdr_) + (recNbr * __This->recordSize) + (__This->elementCount - 1) * __This->elementSize;
			chrPtr = (char *)(__This->dataBuffer) + (fpos - __This->bufferBeginPosition);
			chrPtr -= __This->recordSize;
			shrtPtr = (short *)(chrPtr);

			shrtArray [6] = shrtArray [7] = shrtArray [8] = CSswapShort (*shrtPtr,__This->swapFlag);

			chrPtr = (char *)(__This->dataBuffer) + (fpos - __This->bufferBeginPosition);
			shrtPtr = (short *)(chrPtr);
			shrtArray [3] = shrtArray [4] = shrtArray [5] = CSswapShort (*shrtPtr,__This->swapFlag);

			chrPtr = (char *)(__This->dataBuffer) + (fpos - __This->bufferBeginPosition);
			chrPtr += __This->recordSize;
			shrtPtr = (short *)(chrPtr);
			shrtArray [0] = shrtArray [1] = shrtArray [2] = CSswapShort (*shrtPtr,__This->swapFlag);

			deltaLL [LNG] = cs_One;
			break;

		case edgeNortheast:
			fpos = sizeof (struct csBynGridFileHdr_) + (__This->elementCount - 1) * __This->elementSize;
			chrPtr = (char *)(__This->dataBuffer) + (fpos - __This->bufferBeginPosition);
			shrtPtr = (short *)(chrPtr);

			shrtArray [6] = shrtArray [7] = shrtArray [8] = CSswapShort (*shrtPtr,__This->swapFlag);
			shrtArray [3] = shrtArray [4] = shrtArray [5] = CSswapShort (*shrtPtr,__This->swapFlag);
			shrtArray [0] = shrtArray [1] = shrtArray [2] = CSswapShort (*shrtPtr,__This->swapFlag);

			deltaLL [LNG] = deltaLL [LAT] = cs_One;
			break;

		case edgeNorth:
			fpos = sizeof (struct csBynGridFileHdr_) + eleNbr * __This->elementSize;
			chrPtr = (char *)(__This->dataBuffer) + (fpos - __This->bufferBeginPosition);
			shrtPtr = (short *)(chrPtr);

			shrtArray [6] = shrtArray [3] = shrtArray [0] = CSswapShort (*(shrtPtr - 1),__This->swapFlag);
			shrtArray [7] = shrtArray [4] = shrtArray [1] = CSswapShort (*shrtPtr,__This->swapFlag);
			shrtArray [8] = shrtArray [5] = shrtArray [2] = CSswapShort (*(shrtPtr + 1),__This->swapFlag);

			deltaLL [LAT] = cs_One;
			break;

		case edgeNorthwest:
			fpos = sizeof (struct csBynGridFileHdr_);
			chrPtr = (char *)(__This->dataBuffer) + (fpos - __This->bufferBeginPosition);
			shrtPtr = (short *)(chrPtr);

			shrtArray [6] = shrtArray [7] = shrtArray [8] = CSswapShort (*shrtPtr,__This->swapFlag);
			shrtArray [3] = shrtArray [4] = shrtArray [5] = CSswapShort (*shrtPtr,__This->swapFlag);
			shrtArray [0] = shrtArray [1] = shrtArray [2] = CSswapShort (*shrtPtr,__This->swapFlag);

			deltaLL [LNG] = deltaLL [LAT] = cs_One;
			break;

		case edgeWest:
			fpos = sizeof (struct csBynGridFileHdr_) + recNbr * __This->recordSize;
			chrPtr = (char *)(__This->dataBuffer) + (fpos - __This->bufferBeginPosition);
			chrPtr -= __This->recordSize;
			shrtPtr = (short *)(chrPtr);
			shrtArray [6] = shrtArray [7] = shrtArray [8] = CSswapShort (*shrtPtr,__This->swapFlag);

			chrPtr = (char *)(__This->dataBuffer) + (fpos - __This->bufferBeginPosition);
			shrtPtr = (short *)(chrPtr);
			shrtArray [3] = shrtArray [4] = shrtArray [5] = CSswapShort (*shrtPtr,__This->swapFlag);

			chrPtr = (char *)(__This->dataBuffer) + (fpos - __This->bufferBeginPosition);
			chrPtr += __This->recordSize;
			shrtPtr = (short *)(chrPtr);
			shrtArray [0] = shrtArray [1] = shrtArray [2] = CSswapShort (*shrtPtr,__This->swapFlag);

			deltaLL [LNG] = cs_One;
			break;
		}
		
		/* Transfer to dblArray. */
		for (idx = 0;idx < 9;idx += 1)
		{
			if (shrtArray [idx] == 32767) dblArray [idx] = 9999.0;		/*lint !e644 */
			else
			{
				dblArray [idx] = shrtArray [idx] * __This->dataFactor;
			}
		}
	}
	else if (__This->elementSize == 4)
	{
		switch (edge) {
		case edgeNone:
			fpos = sizeof (struct csBynGridFileHdr_) + (recNbr * __This->recordSize) + (eleNbr * __This->elementSize);

			chrPtr = (char *)(__This->dataBuffer) + (fpos - __This->bufferBeginPosition);
			chrPtr -= __This->recordSize;
			lngPtr = (long *)(chrPtr);
			lngArray [6] = CSswapLong (*(lngPtr - 1),__This->swapFlag);
			lngArray [7] = CSswapLong (*lngPtr,__This->swapFlag);
			lngArray [8] = CSswapLong (*(lngPtr + 1),__This->swapFlag);

			chrPtr = (char *)(__This->dataBuffer) + (fpos - __This->bufferBeginPosition);
			lngPtr = (long *)(chrPtr);
			lngArray [3] = CSswapLong (*(lngPtr - 1),__This->swapFlag);
			lngArray [4] = CSswapLong (*lngPtr,__This->swapFlag);
			lngArray [5] = CSswapLong (*(lngPtr + 1),__This->swapFlag);

			chrPtr = (char *)(__This->dataBuffer) + (fpos - __This->bufferBeginPosition);
			chrPtr += __This->recordSize;
			lngPtr = (long *)(chrPtr);
			lngArray [0] = CSswapLong (*(lngPtr - 1),__This->swapFlag);
			lngArray [1] = CSswapLong (*lngPtr,__This->swapFlag);
			lngArray [2] = CSswapLong (*(lngPtr + 1),__This->swapFlag);
			break;

		case edgeSouthwest:
			fpos = sizeof (struct csBynGridFileHdr_) + (__This->recordCount - 1) * __This->recordSize;
			chrPtr = (char *)(__This->dataBuffer) + (fpos - __This->bufferBeginPosition);
			lngPtr = (long *)(chrPtr);

			lngArray [6] = lngArray [7] = lngArray [8] = CSswapLong (*lngPtr,__This->swapFlag);
			lngArray [3] = lngArray [4] = lngArray [5] = CSswapLong (*lngPtr,__This->swapFlag);
			lngArray [0] = lngArray [1] = lngArray [2] = CSswapLong (*lngPtr,__This->swapFlag);

			deltaLL [LNG] = deltaLL [LAT] = cs_One;
			break;

		case edgeSouth:
			fpos = sizeof (struct csBynGridFileHdr_) + (__This->recordCount - 1) * __This->recordSize + eleNbr * __This->elementSize;
			chrPtr = (char *)(__This->dataBuffer) + (fpos - __This->bufferBeginPosition);
			lngPtr = (long *)(chrPtr);

			lngArray [6] = lngArray [3] = lngArray [0] = CSswapLong (*(lngPtr - 1),__This->swapFlag);
			lngArray [7] = lngArray [4] = lngArray [1] = CSswapLong (*lngPtr,__This->swapFlag);
			lngArray [8] = lngArray [5] = lngArray [2] = CSswapLong (*(lngPtr + 1),__This->swapFlag);

			deltaLL [LAT] = cs_One;
			break;

		case edgeSoutheast:
			fpos = sizeof (struct csBynGridFileHdr_) + (__This->recordCount - 1) * __This->recordSize + (__This->elementCount - 1) * __This->elementSize;
			chrPtr = (char *)(__This->dataBuffer) + (fpos - __This->bufferBeginPosition);
			lngPtr = (long *)(chrPtr);

			lngArray [6] = lngArray [7] = lngArray [8] = CSswapLong (*lngPtr,__This->swapFlag);
			lngArray [3] = lngArray [4] = lngArray [5] = CSswapLong (*lngPtr,__This->swapFlag);
			lngArray [0] = lngArray [1] = lngArray [2] = CSswapLong (*lngPtr,__This->swapFlag);

			deltaLL [LNG] = deltaLL [LAT] = cs_One;
			break;

		case edgeEast:
			fpos = sizeof (struct csBynGridFileHdr_) + recNbr * __This->recordSize + (__This->elementCount - 1) * __This->elementSize;
			chrPtr = (char *)(__This->dataBuffer) + (fpos - __This->bufferBeginPosition);
			chrPtr -= __This->recordSize;
			lngPtr = (long *)(chrPtr);

			lngArray [6] = lngArray [7] = lngArray [8] = CSswapLong (*lngPtr,__This->swapFlag);

			chrPtr = (char *)(__This->dataBuffer) + (fpos - __This->bufferBeginPosition);
			lngPtr = (long *)(chrPtr);
			lngArray [3] = lngArray [4] = lngArray [5] = CSswapLong (*lngPtr,__This->swapFlag);

			chrPtr = (char *)(__This->dataBuffer) + (fpos - __This->bufferBeginPosition);
			chrPtr += __This->recordSize;
			lngPtr = (long *)(chrPtr);
			lngArray [0] = lngArray [1] = lngArray [2] = CSswapLong (*lngPtr,__This->swapFlag);

			deltaLL [LNG] = cs_One;
			break;

		case edgeNortheast:
			fpos = sizeof (struct csBynGridFileHdr_) + (__This->elementCount - 1) * __This->elementSize;
			chrPtr = (char *)(__This->dataBuffer) + (fpos - __This->bufferBeginPosition);
			lngPtr = (long *)(chrPtr);

			lngArray [6] = lngArray [7] = lngArray [8] = CSswapLong (*lngPtr,__This->swapFlag);
			lngArray [3] = lngArray [4] = lngArray [5] = CSswapLong (*lngPtr,__This->swapFlag);
			lngArray [0] = lngArray [1] = lngArray [2] = CSswapLong (*lngPtr,__This->swapFlag);

			deltaLL [LNG] = deltaLL [LAT] = cs_One;
			break;

		case edgeNorth:
			fpos = sizeof (struct csBynGridFileHdr_) + (__This->elementCount - 1) * __This->elementSize;
			chrPtr = (char *)(__This->dataBuffer) + (fpos - __This->bufferBeginPosition);
			lngPtr = (long *)(chrPtr);

			lngArray [6] = lngArray [3] = lngArray [0] = CSswapLong (*(lngPtr - 1),__This->swapFlag);
			lngArray [7] = lngArray [4] = lngArray [1] = CSswapLong (*lngPtr,__This->swapFlag);
			lngArray [8] = lngArray [5] = lngArray [2] = CSswapLong (*(lngPtr + 1),__This->swapFlag);

			deltaLL [LAT] = cs_One;
			break;

		case edgeNorthwest:
			fpos = sizeof (struct csBynGridFileHdr_);
			chrPtr = (char *)(__This->dataBuffer) + (fpos - __This->bufferBeginPosition);
			lngPtr = (long *)(chrPtr);

			lngArray [6] = lngArray [7] = lngArray [8] = CSswapLong (*lngPtr,__This->swapFlag);
			lngArray [3] = lngArray [4] = lngArray [5] = CSswapLong (*lngPtr,__This->swapFlag);
			lngArray [0] = lngArray [1] = lngArray [2] = CSswapLong (*lngPtr,__This->swapFlag);

			deltaLL [LNG] = deltaLL [LAT] = cs_One;
			break;

		case edgeWest:
			fpos = sizeof (struct csBynGridFileHdr_) + recNbr * __This->recordSize;
			chrPtr = (char *)(__This->dataBuffer) + (fpos - __This->bufferBeginPosition);
			chrPtr -= __This->recordSize;
			lngPtr = (long *)(chrPtr);
			lngArray [6] = lngArray [7] = lngArray [8] = CSswapLong (*lngPtr,__This->swapFlag);

			chrPtr = (char *)(__This->dataBuffer) + (fpos - __This->bufferBeginPosition);
			lngPtr = (long *)(chrPtr);
			lngArray [3] = lngArray [4] = lngArray [5] = CSswapLong (*lngPtr,__This->swapFlag);

			chrPtr = (char *)(__This->dataBuffer) + (fpos - __This->bufferBeginPosition);
			chrPtr += __This->recordSize;
			lngPtr = (long *)(chrPtr);
			lngArray [0] = lngArray [1] = lngArray [2] = CSswapLong (*lngPtr,__This->swapFlag);

			deltaLL [LNG] = cs_One;
			break;
		}

		/* Transfer to dblArray. */
		for (idx = 0;idx < 9;idx += 1)
		{
			dblArray [idx] = lngArray [idx] * __This->dataFactor;	/*lint !e644 */	
		}
	}
	else
	{
		CS_stncp (csErrnam,"CSbynGridFile:3",MAXPATH);
		CS_erpt (cs_ISER);
		goto error;
	}

	/* Do the calculations. */
	rtnVal = 0;
	for (idx = 0;idx < 9;idx += 1)
	{
		if (dblArray [idx] >= 9999.0) rtnVal = 1;
	}
	if (rtnVal == 0)
	{
		*result = CSbynGridFileQterp (deltaLL,dblArray);
	}
	else
	{
		*result = 9999.0;
	}
	return rtnVal;

error:
	/* Release the resources allocated to this object.  The next call to this
	   object would then require a refresh. */
	CSreleaseBynGridFile (__This);

	/* Negative return indicates a system error of sorts. */
	return -1;
}
double EXP_LVL9 CSbynGridFileQterp (double sourceDelta [2],double array [9])
{
	double result;
	double f0, f1, f2;

	f0 = CSgeoidQterp1 (sourceDelta [0],array [0],array [1],array [2]);
	f1 = CSgeoidQterp1 (sourceDelta [0],array [3],array [4],array [5]);
	f2 = CSgeoidQterp1 (sourceDelta [0],array [6],array [7],array [8]);
	result = CSbynGridFileQterp1 (sourceDelta [1],f0,f1,f2);
	return result;
}
double EXP_LVL9 CSbynGridFileQterp1 (double delta,double f0,double f1,double f2)
{
	extern double cs_One;
	extern double cs_Half;

	double tmp;
	double df0;			/* first delta */
	double df1;			/* second delta */
	double d2f0;		/* second order delta */
	double result;

	df0  = f1 - f0;
	df1  = f2 - f1;
	d2f0 = df1  - df0;
	tmp = cs_Half * delta * (delta - cs_One);
	result = f0 + delta * df0 + tmp * d2f0;
	return result;
}
short CSswapShort (short source,int swapEm)
{
	union
	{
		unsigned char bytes [2];
		short result;
	} value;
	cs_Register unsigned char *ptr;

	if (swapEm == 0) return source;

	ptr = (unsigned char *)(&source);
	value.bytes [1] = *ptr++;
	value.bytes [0] = *ptr;
	return value.result;
}
long CSswapLong (long source,int swapEm)
{
	union
	{
		unsigned char bytes [4];
		long result;
	} value;
	cs_Register unsigned char *ptr;

	if (swapEm == 0) return source;

	ptr = (unsigned char *)(&source);
	value.bytes [3] = *ptr++;
	value.bytes [2] = *ptr++;
	value.bytes [1] = *ptr++;
	value.bytes [0] = *ptr;
	return value.result;
}

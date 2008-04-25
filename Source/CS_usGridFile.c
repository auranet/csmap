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

			 File Name: $Source: C:/Development/NewCsMap/rcs/CS_usGridFile.c $
			 Full Name:	US Grid File Object
		   Description:
			   Purpose:	Encapsulates the access to a US Grid File,
						ala NADCON, VERTCON, and GEOID97.

		Revision Level:	$Revision: #4 $
				  Date:	$Date: 2006/11/16 $

		 Last Revision:	$Log: CS_usGridFile.c $
		 Last Revision:	Revision 11.1300  2005/05/25 23:27:19  nto
		 Last Revision:	Official Release 11.13
		 Last Revision:	Revision 11.1200  2005/01/15 18:27:17  nto
		 Last Revision:	Official Release of CS-MAP 11.12, 11:26am 15 Jan 2005
		 Last Revision:	Revision 11.1100  2004/11/01 18:53:15  nto
		 Last Revision:	Official release 11.11
		 Last Revision:	Revision 11.1001  2004/10/07 19:25:22  nto
		 Last Revision:	Revision 11.900  2004/03/26 17:02:29  nto
		 Last Revision:	Official release: 11.09 - 3/25/2003
		 Last Revision:	Revision 11.800  2004/01/13 23:29:18  nto
		 Last Revision:	Revision 11.700  2003/12/19 01:49:58  nto
		 Last Revision:	Official release 11.07
		 Last Revision:	Revision 11.600  2003/12/04 02:46:33  nto
		 Last Revision:	Release 11.06.  Never shipped. Source captured in prep for C++ V7.
		 Last Revision:	Revision 11.502  2003/11/24 01:12:09  nto
		 Last Revision:	Correct very remote possibility of addressing fault when errors occur.
		 Last Revision:	Revision 11.501  2003/08/22 21:13:00  nto
		 Last Revision:	Official Release: 11.05
		 Last Revision:	Revision 11.401  2003/05/01 23:06:26  nto
		 Last Revision:	Revision 11.300  2003/02/25 04:29:21  nto
		 Last Revision:	Official Release 11.03
		 Last Revision:	Revision 11.100  2002/11/22 19:38:48  nto
		 Last Revision:	Official release: 11.01
		 Last Revision:	Revision 10.1501  2002/11/13 23:05:36  nto
		 Last Revision:	Added grid data file logging for Nad27ToNad83.
		 Last Revision:	Revision 10.1500  2002/09/22 00:01:25  nto
		 Last Revision:	Official Release:= 10.15
		 Last Revision:	Revision 10.1400  2002/08/09 18:14:26  nto
		 Last Revision:	Revision 10.1200  2002/06/20 18:00:31  nto
		 Last Revision:	Official release: 10.12
		 Last Revision:	Revision 10.1100  2002/06/13 14:18:44  nto
		 Last Revision:	Release 10.11 Official
		 Last Revision:	Revision 10.1002  2002/06/13 13:35:22  nto
		 Last Revision:	Some minor changes in preparation for the datum source file feature.
		 Last Revision:	Revision 10.1001  2002/04/18 21:05:36  nto
		 Last Revision:	Added the capture of the file name in the control block.
		 Last Revision:	Revision 10.1000  2002/02/23 21:18:30  nto
		 Last Revision:	Official Release of 10.10, 2/22/02 - Norm Olsen
		 Last Revision:	Revision 10.901  2002/01/30 00:59:01  nto
		 Last Revision:	Name used to reference goid96 changed.
		 Last Revision:	Revision 10.900  2001/09/24 04:31:14  nto
		 Last Revision:	Revision 10.700  2001/01/25 04:13:56  nto
		 Last Revision:	Revision 10.600  2000/12/11 06:39:50  nto
		 Last Revision:	Release 10.06
		 Last Revision:	Revision 10.500  2000/10/27 07:38:32  nto
		 Last Revision:	Official Release 10.05
		 Last Revision:	Revision 10.400  2000/09/13 01:17:02  nto
		 Last Revision:	Release 10.04
		 Last Revision:	Revision 10.300  2000/04/04 23:18:33  nto
		 Last Revision:	Revision 10.200  2000/03/02 18:51:23  nto
		 Last Revision:	Revision 1.3  2000/01/31 00:08:37  nto
		 Last Revision:	Replaced stricmp with CS_stricmp.
		 Last Revision:	Revision 1.2  1999/11/03 23:41:08  nto
		 Last Revision:	Results of datum conversion rewrite.

		       * * * * R E M A R K S * * * *

	Once properly constructed, this object returns the indicated
	datum from the grid file, properly interpolated.  This
	capability is suitable for use in NADCON, VERTCON, and
	GEOID97 emulations.

	To construct one of these things, you must provide a complete
	path to the file name.

******************************************************************************/

#include "cs_map.h"

#ifdef LABEL_MODULE
static char revlvl [] = {"%W"};
#endif

/*
	US geodetic calculations typically use a grid file structure.  This
	same structure is used in several applications.  Contrary to previous
	releases, we now use common code for all of these applications.

	Note, we use US in most of the symbology.  There are similar constructs
	in use in Canada.  In future, perhaps there will be others.
*/

extern char csErrnam [MAXPATH];

/*****************************************************************************
	'Private' support function
*/
void CSinitGridFileUS (struct csGridFileUS_ *__This)
{
	__This->type = usGridTypeNoneYet;
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
	CSinitGridCell (&__This->currentCell);
	__This->filePath [0] = '\0';
}

/*****************************************************************************
	Constructor
*/
struct csGridFileUS_* CSnewGridFileUS (Const char *path,long bufferSize,unsigned long flags,double density)
{
	extern char cs_DirsepC;
	extern char cs_ExtsepC;
	extern char csErrnam [];

	int hpgn;
	size_t readCount;
	long lngTmp;
	const char *cpK;
	char *cp1, *cp2;
	csFILE *fstr;
	struct csGridFileUS_* __This;
	struct csGridHdrUS_ usGridHdr;

	/* Prepare for an error. */
	__This = NULL;
	fstr = NULL;

	/* Malloc and initialize */
	__This = CS_malc (sizeof (struct csGridFileUS_));
	if (__This == NULL)
	{
		CS_erpt (cs_NO_MEM);
		goto error;
	}
	CSinitGridFileUS (__This);

	/* Set default values for all members. */
	__This->bufferSize = bufferSize;
	if (__This->bufferSize < 0) __This->bufferSize = 0;

	/* Save file path/name. */
	CS_stncp (__This->filePath,path,sizeof (__This->filePath));
	cpK = strrchr (path,cs_DirsepC);
	if (cpK != NULL) cpK += 1;
	else             cpK = path;
	CS_stncp (__This->FileName,cpK,sizeof (__This->FileName));
	cp1 = strrchr (__This->FileName,cs_ExtsepC);
	if (cp1 != NULL) *cp1 = '\0';

	/* Set up the type of file.  Get cp1 to point at the file
	   name, and cp2 to point at the extension.  We consider it
	   an error if we are not given a full path name.  Note,
	   we care not about the format of the drive specification.
	   But there must be at least on directory and there must
	   be an extension. */
	cp1 = strrchr (__This->filePath,cs_DirsepC);
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
	cp2 += 1;

	/* Is it an HPGN file? */
	hpgn = !CS_stristr (cp1,"hpgn");
	if (!CS_stricmp (cp2,"LAS"))
	{
		if (hpgn) __This->type = usGridTypeHarnLAS;
		else      __This->type = usGridTypeNad27LAS;
	}
	else if (!CS_stricmp (cp2,"LOS"))
	{
		if (hpgn) __This->type = usGridTypeHarnLOS;
		else      __This->type = usGridTypeNad27LOS;
	}
	else if (!CS_stricmp (cp2,"geo"))
	{
		__This->type = usGridTypeGeoid96;
	}
	else if (!CS_stricmp (cp2,"94"))
	{
		__This->type = usGridTypeVertCon;
	}
	else
	{
		__This->type = usGridTypeUnknown;
	}

	/* Get the file information header. */
	fstr = CS_fopen (__This->filePath,_STRM_BINRD);
	if (fstr == NULL)
	{
		CS_stncp (csErrnam,__This->filePath,MAXPATH);
		CS_erpt (cs_DTC_FILE);
		goto error;
	}
	readCount = CS_fread (&usGridHdr,1,sizeof (usGridHdr),fstr);
	if (readCount != sizeof (usGridHdr))
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
	CS_bswap (&usGridHdr,cs_BSWP_GridFileHdrUS);

	/* The extra stuff here is required as conversions of floats to doubles
	   does not always provide precise results.  To get the precise results we
	   require, we assume that the value (which is in degrees) is an intergal
	   number of seconds.
	   
	   You can reproduce NADCON results precisely by replacing this stuff with
	   the following:

			__This->deltaLng = usGridHdr.del_lng;
			__This->deltaLat = usGridHdr.del_lat;

		However, you'll run into problems in the inverse, noticeable
		in Hawaii and Puerto Rico where the grid density is an awkward
		number, but especially on the island of St. George.  Note that
		the compiler that I'm using as I write, converts a "float" of
		0.0166667 (1 minute) to 0.0166699 something. */

	lngTmp = (long)(((double)usGridHdr.del_lng * 3600.0) + 0.4);
	__This->deltaLng = ((double)lngTmp / 3600.0);
	lngTmp = (long)(((double)usGridHdr.del_lat * 3600.0) + 0.4);
	__This->deltaLat = ((double)lngTmp / 3600.0);

	/* Now we can do the rest of this stuff. */
	__This->coverage.southWest [LNG] = usGridHdr.min_lng;
	__This->coverage.southWest [LAT] = usGridHdr.min_lat;
	__This->coverage.northEast [LNG] = usGridHdr.min_lng + (__This->deltaLng * (usGridHdr.ele_cnt - 1));
	__This->coverage.northEast [LAT] = usGridHdr.min_lat + (__This->deltaLat * (usGridHdr.rec_cnt - 1));
	__This->coverage.density = (__This->deltaLng < __This->deltaLat) ? __This->deltaLng : __This->deltaLat;
	if (density != 0.0) __This->coverage.density = density;
	__This->elementCount = usGridHdr.ele_cnt;
	__This->recordCount = usGridHdr.rec_cnt;
	__This->recordSize = usGridHdr.ele_cnt * (int)sizeof (float) + (int)sizeof (long);

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
		if (__This->bufferSize > (2 * __This->recordSize))
		{
			/* Maximum efficiency is obtained with a buffer size whch is
			   a multiple of the record size. */
			__This->bufferSize = (__This->bufferSize / __This->recordSize) * __This->recordSize;
		}
		else
		{
			/* We require a minimum buffer size of 2 records. */
			__This->bufferSize = 2 * __This->recordSize;
		}
	}

	return (__This);
error:
	CSdeleteGridFileUS (__This);
	return NULL;
}											/*lint !e715 flags */

/*****************************************************************************
	Destructor
*/
void CSdeleteGridFileUS (struct csGridFileUS_* __This)
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
void CSreleaseGridFileUS (struct csGridFileUS_* __This)
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

		/* Initialize the grid cell so it doesn't match anything. */
		CSinitGridCell (&__This->currentCell);

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
double CStestGridFileUS (struct csGridFileUS_* __This,Const double *sourceLL)
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
	coordinate is iwthin the coverage of the object.
*/
int CSextractGridCellUS (struct csGridFileUS_* __This,Const double* sourceLL)
{
	extern double cs_LlNoise;			/* 1.0E-12 */

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

	float south [2];
	float north [2];

	/* Compute the basic indices to the cell in the data file. Use of cs_LlNoise
	   is to force a result, such as, 0.99999999999998 to be a 1.0. */
	eleNbr = (long)((sourceLL [LNG] - __This->coverage.southWest [LNG] + cs_LlNoise) / __This->deltaLng);
	recNbr = (long)((sourceLL [LAT] - __This->coverage.southWest [LAT] + cs_LlNoise) / __This->deltaLat);
	if (eleNbr > __This->elementCount || recNbr > __This->recordCount)
	{
		/* This is not supposed to happen.  This is a "private" function and
		   only called when it is known that the provided coordinate is within
		   the coverage of the file. */
		CS_stncp (csErrnam,"CS_usGridFile:1",MAXPATH);
		CS_erpt  (cs_ISER);
		goto error;
	}

	/* Compute the latitude and longitude of the southwest corner of the grid cell. */
	__This->currentCell.coverage.southWest [LNG] = __This->coverage.southWest [LNG] + __This->deltaLng * (double)eleNbr;
	__This->currentCell.coverage.southWest [LAT] = __This->coverage.southWest [LAT] + __This->deltaLat * (double)recNbr;

	/* The northeast corner of the grid cell. */
	__This->currentCell.coverage.northEast [LNG] = __This->currentCell.coverage.southWest [LNG] + __This->deltaLng;
	__This->currentCell.coverage.northEast [LAT] = __This->currentCell.coverage.southWest [LAT] + __This->deltaLat;

	/* Transfer the grid cell size. */
	__This->currentCell.deltaLng = __This->deltaLng;
	__This->currentCell.deltaLat = __This->deltaLat;

	/* Compute the position in the file of the data of interest.  Note, a
	   header occupies the first record.  Therefore, the +1 on the record
	   number.  Each record has a 32 bit record number as the first element,
	   thus the +1 on the element number. */
	fpos = (recNbr + 1) * __This->recordSize + (eleNbr + 1) * (int)sizeof (float);

	/* Adjust the beginning and the end to record boundaires.  We do I/O on
	   a record number basis; and we always require a minimum of two records. */
	fposBegin = (fpos / __This->recordSize) * __This->recordSize;
	fposEnd = fposBegin + __This->recordSize + __This->recordSize;

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
			__This->bufferBeginPosition = fposBegin;
			__This->bufferEndPosition = fposEnd;
			readCount = __This->bufferEndPosition - __This->bufferBeginPosition;

			/* In this section, lngTmp is the number of additional records
			   which can fit in the buffer. */
			lngTmp = (__This->bufferSize - readCount) / __This->recordSize;
			if (lngTmp > 2L)
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
			if (lngTmp > 2L)
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
				CS_stncp (csErrnam,"CS_usGridFile:2",MAXPATH);
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

		/* We have the desired data in the buffer.  Extract what we need from it.
		   If we read in the whole file, we close the stream now.  No need to
		   have the file descriptor open. */
		if (__This->bufferSize == __This->fileSize)
		{
			CS_fclose (__This->strm);
			__This->strm = NULL;
		}
	}

	/* Extract from the buffer the four floats which we need. */
	chrPtr = (char *)(__This->dataBuffer) + (fpos - __This->bufferBeginPosition);
	fltPtr = (float *)(chrPtr);
	south [0] = *fltPtr;
	south [1] = *(fltPtr + 1);
	chrPtr += __This->recordSize;
	fltPtr = (float *)(chrPtr);
	north [0] = *fltPtr;
	north [1] = *(fltPtr + 1);

	/* Swap bytes as appropriate. */
	CS_bswap (south,"ff");
	CS_bswap (north,"ff");

	/* Do the calculations.  We do these here once and save the results in the
	   current cell.  Note, an ANSI 'C' compiler should do the calculation as
	   a double. */
	__This->currentCell.currentAA = (double)(south [0]);
	__This->currentCell.currentBB = (double)(south [1] - south [0]);
	__This->currentCell.currentCC = (double)(north [0] - south [0]);
	__This->currentCell.currentDD = (double)(north [1] - south [1] - north [0] + south [0]);
	strncpy (__This->currentCell.sourceId,__This->FileName,sizeof (__This->currentCell.sourceId));

	return 0;

error:
	/* Disable the current grid cell to indicate that it is invalid. */
	__This->currentCell.coverage.southWest [LNG] = 1.0;
	__This->currentCell.coverage.southWest [LAT] = 1.0;
	__This->currentCell.coverage.northEast [LNG] = -1.0;
	__This->currentCell.coverage.northEast [LAT] = -1.0;
	__This->currentCell.sourceId [0] = '\0';

	/* Release the resources allocated to this object.  The next call to this
	   object would then require a refresh. */
	CSreleaseGridFileUS (__This);

	/* Negative return indicates a system error of sorts. */
	return -1;
}

/*****************************************************************************
	Calculate the specific value indicated.  Note, this returns whatever data
	is in the grid file.  Thus, in some cases its a datum shift, some cases a
	geoid height, etc.
*/
int CScalcGridFileUS (struct csGridFileUS_* __This,double* result,Const double* sourceLL)
{
	/* Retuns the grid data value obtained from the grid file after appropriate
	   bilinear interpolation.  Note, this value means different things in
	   different applications.  Its calculation is the same for all applications. */

	int cellStatus;

	/* In the case of the US data files, all overlapping coverage is boundary
	   consistent.  That is, if the current cell coverage includes the provided point,
	   than we can rely on that cell as being the best data available regardless
	   of overlap.  So, for performance purposes: */
	if (CStestCoverageUS (&__This->currentCell.coverage,sourceLL) != 0.0)
	{
		cellStatus = 0;
	}
	else
	{
		/* Need to get the approriate data for the cell from the file/buffer. */
		cellStatus = CSextractGridCellUS (__This,sourceLL);
	}
	if (cellStatus == 0)
	{
		*result = CScalcGridCellUS (&__This->currentCell,sourceLL);
	}
	else
	{
		*result = 0.0;
	}
	return cellStatus;
}
Const char *CSsourceGridFileUS (struct csGridFileUS_* __This,Const double* llSource)
{
	Const char *cp;

	cp = NULL;
	if (CStestGridFileUS (__This,llSource) != 0.0)
	{
		cp = __This->FileName;
	}
	return cp;
}

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

			 File Name: $RCSfile: CSgridCellCache.c $
		   Description:
			   Purpose:

		Revision Level:	$Revision: #4 $
		 Check In Date:	$Date: 2006/11/16 $

		Last Revision:	$Log: CSgridCellCache.c $
		Last Revision:	Revision 11.1300  2005/05/25 23:27:04  nto
		Last Revision:	Official Release 11.13
		Last Revision:	Revision 11.1200  2005/01/15 18:27:07  nto
		Last Revision:	Official Release of CS-MAP 11.12, 11:26am 15 Jan 2005
		Last Revision:	Revision 11.1100  2004/11/01 18:53:04  nto
		Last Revision:	Official release 11.11
		Last Revision:	Revision 11.1001  2004/10/07 19:25:13  nto
		Last Revision:	Revision 11.900  2004/03/26 17:02:20  nto
		Last Revision:	Official release: 11.09 - 3/25/2003
		Last Revision:	Revision 11.800  2004/01/13 23:29:09  nto
		Last Revision:	Revision 11.700  2003/12/19 01:49:49  nto
		Last Revision:	Official release 11.07
		Last Revision:	Revision 11.600  2003/12/04 02:46:24  nto
		Last Revision:	Release 11.06.  Never shipped. Source captured in prep for C++ V7.
		Last Revision:	Revision 11.501  2003/08/22 21:12:52  nto
		Last Revision:	Official Release: 11.05
		Last Revision:	Revision 11.401  2003/05/01 23:06:18  nto
		Last Revision:	Revision 11.300  2003/02/25 04:29:13  nto
		Last Revision:	Official Release 11.03
		Last Revision:	Revision 11.100  2002/11/22 19:38:40  nto
		Last Revision:	Official release: 11.01
		Last Revision:	Revision 10.1502  2002/11/21 21:08:26  nto
		Last Revision:	Lint cleanup.
		Last Revision:	Revision 10.1501  2002/11/13 23:05:37  nto
		Last Revision:	Added grid data file logging for Nad27ToNad83.
		Last Revision:	Revision 10.1500  2002/09/22 00:01:16  nto
		Last Revision:	Official Release:= 10.15
		Last Revision:	Revision 10.1400  2002/08/09 18:14:19  nto
		Last Revision:	Revision 10.1201  2002/08/06 21:47:53  nto
		Last Revision:	Fixed a circular list problem.
		Last Revision:	Revision 10.1200  2002/07/14 03:26:11  nto
		Last Revision:	Revision 10.1100  2002/06/13 14:18:33  nto
		Last Revision:	Release 10.11 Official
		Last Revision:	Revision 10.1001  2002/06/13 13:37:20  nto
		Last Revision:	Copied the source file into the cache.
		Last Revision:	Revision 10.1000  2002/02/23 21:18:23  nto
		Last Revision:	Official Release of 10.10, 2/22/02 - Norm Olsen
		Last Revision:	Revision 10.901  2002/01/30 01:02:09  nto
		Last Revision:	Fixed a spelling error in a comment.
		Last Revision:	Revision 10.900  2001/09/24 04:31:08  nto
		Last Revision:	Revision 10.700  2001/01/25 04:13:42  nto
		Last Revision:	Revision 10.600  2000/12/11 06:39:37  nto
		Last Revision:	Release 10.06
		Last Revision:	Revision 10.500  2000/10/27 07:38:14  nto
		Last Revision:	Official Release 10.05
		Last Revision:	Revision 10.400  2000/09/13 01:16:49  nto
		Last Revision:	Release 10.04
		Last Revision:	Revision 10.300  2000/04/04 23:18:19  nto
		Last Revision:	Revision 10.200  2000/03/02 18:51:12  nto
		Last Revision:	Revision 1.3  2000/01/31 00:23:09  nto
		Last Revision:	Properly defined argument as const.
		Last Revision:	Revision 1.2  1999/11/03 23:41:09  nto
		Last Revision:	Results of datum conversion rewrite.

******************************************************************************/

#ifdef LABEL_MODULE
static char revlvl [] = {"$Id"};
#endif

#include "cs_map.h"

struct csLLGridCellCache_* CSnewLLGridCellCache (int cellCount)
{
	struct csLLGridCellCache_* cachePtr;

	if (cellCount < 2)
	{
		CS_erpt (cs_ISER);
		return NULL;
	}
	cachePtr = (struct csLLGridCellCache_ *)CS_malc (sizeof (struct csLLGridCellCache_));
	if (cachePtr == NULL)
	{
		CS_erpt (cs_NO_MEM);
		return cachePtr;
	}
	cachePtr->maxCount = cellCount;
	cachePtr->usedCount = 0;
	cachePtr->listHead = NULL;
	return cachePtr;
}
void CSdeleteLLGridCellCache (struct csLLGridCellCache_* __This)
{
	if (__This != NULL)
	{
		CSreleaseLLGridCellCache (__This);
		free( (struct csLLGridCellCache_*) __This);
		//CS_free (__This);
	}
}
void CSreleaseLLGridCellCache (struct csLLGridCellCache_* __This)
{
	struct csLLGridCell_* cellPtr;
	struct csLLGridCell_* tmpPtr;

	if (__This != NULL)
	{
		cellPtr = __This->listHead;
		while (cellPtr != NULL)
		{
			tmpPtr = cellPtr;
			cellPtr = cellPtr->next;
			free((struct csLLGridCell_ *) tmpPtr);		
			//CS_free (tmpPtr);
		}
		__This->listHead = NULL;
		__This->usedCount = 0;
	}
	return;
}
int CSaddLLGridCellCache (struct csLLGridCellCache_* __This,enum csDtCvtType cellType,
															struct csGridCell_* lngCell,
															struct csGridCell_* latCell)
{
	extern char csErrnam [];

	struct csLLGridCell_ *cellPtr, *prvCellPtr;

	/* Adjust the cache so that the first entry is suitable for the
	   new addition. */
	if (__This->usedCount < __This->maxCount)
	{
		/* Here to add a complete new cell to the cache. */
		cellPtr = (struct csLLGridCell_*)CS_malc (sizeof (struct csLLGridCell_));
		if (cellPtr == NULL)
		{
			CS_erpt (cs_NO_MEM);
			return -1;
		}
		if (__This->listHead == NULL) cellPtr->next = NULL;
		else cellPtr->next = __This->listHead;
		__This->listHead = cellPtr;
		__This->usedCount += 1;
	}
	else
	{
		/* Here to reuse an existing grid cell. Move the last one in the
		   cache up to the front, then use it. */
		cellPtr = __This->listHead;
		prvCellPtr = NULL;
		while (cellPtr->next != NULL)
		{
			prvCellPtr = cellPtr;
			cellPtr = cellPtr->next;
		}
		if (prvCellPtr == NULL)
		{
			CS_stncp (csErrnam,"CSgridCellCache:1",MAXPATH);
			CS_erpt (cs_ISER);
			return -1;
		}
		prvCellPtr->next = NULL;
		cellPtr->next = __This->listHead;
		__This->listHead = cellPtr;
	}

	/* Cell pointer points to the first cell in the list; which
	   is also the target of the add. */
	cellPtr->type = cellType;
	cellPtr->southWest [LNG] = lngCell->coverage.southWest [LNG];
	cellPtr->southWest [LAT] = lngCell->coverage.southWest [LAT];
	cellPtr->northEast [LNG] = lngCell->coverage.northEast [LNG];
	cellPtr->northEast [LAT] = lngCell->coverage.northEast [LAT];

	cellPtr->deltaLng = lngCell->deltaLng;
	cellPtr->deltaLat = latCell->deltaLat;

	cellPtr->AA [0] = lngCell->currentAA;
	cellPtr->BB [0] = lngCell->currentBB;
	cellPtr->CC [0] = lngCell->currentCC;
	cellPtr->DD [0] = lngCell->currentDD;

	cellPtr->AA [1] = latCell->currentAA;
	cellPtr->BB [1] = latCell->currentBB;
	cellPtr->CC [1] = latCell->currentCC;
	cellPtr->DD [1] = latCell->currentDD;

	CS_stncp (cellPtr->sourceId,lngCell->sourceId,sizeof (cellPtr->sourceId));
	return 0;
}
void CSfirstLLGridCellCache (struct csLLGridCellCache_* __This,struct csLLGridCell_* cellPtr)
{
	struct csLLGridCell_ *srchPtr;

	/* This is tsurctured so that if cellPtr is the same as listHead,
	   nothing happens. */
	srchPtr = __This->listHead;
	while (srchPtr != NULL)
	{
		if (srchPtr->next == cellPtr)
		{
			/* We have found the cell. */
			srchPtr->next = srchPtr->next->next;
			cellPtr->next = __This->listHead;
			__This->listHead = cellPtr;
			break;
		}
		srchPtr = srchPtr->next;
	}
	return;
}

int CScalcLLGridCellCache (struct csLLGridCellCache_* __This,double trgLL [2],Const double srcLL [2])
{
	extern double cs_Sec2Deg;			/* 1.0 / 3600.0 */
	extern double cs_K360;

	int status;
	int alaskaFlag;
	struct csLLGridCell_* cellPtr;
	double gridDeltaLng, gridDeltaLat;
	double deltaLng, deltaLat;

	double lclLL [2];

	status = 1;
	alaskaFlag = FALSE;

	/* Search the cache. */
	cellPtr = __This->listHead;
	while (cellPtr != NULL)
	{
		/* For now, we can accomodate all four cases rather
		   easily. */
		switch (cellPtr->type) {
		case dtcTypeUS:
		case dtcTypeHarn:
			lclLL [LNG] = srcLL [LNG];
			lclLL [LAT] = srcLL [LAT];

			/* Need to play a game to properly convert Alaska longitude.
			   The grid cell may be set up with a longitude < -180. */
			if (lclLL [LNG] > 0.0)
			{
				lclLL [LNG] -= cs_K360;
				alaskaFlag = TRUE;
			}

			/* See if this cell covers the coordinate we're converting. */
			if (lclLL [LNG] >= cellPtr->southWest [LNG] &&
				lclLL [LAT] >= cellPtr->southWest [LAT] &&
				lclLL [LNG] <  cellPtr->northEast [LNG] &&
				lclLL [LAT] <  cellPtr->northEast [LAT])
			{
				/* Do the calculation. */
				gridDeltaLng = (lclLL [LNG] - cellPtr->southWest [LNG]) / cellPtr->deltaLng;
				gridDeltaLat = (lclLL [LAT] - cellPtr->southWest [LAT]) / cellPtr->deltaLat;
				deltaLng = cellPtr->AA [0] +
						   cellPtr->BB [0] * gridDeltaLng +
						   cellPtr->CC [0] * gridDeltaLat +
						   cellPtr->DD [0] * gridDeltaLng * gridDeltaLat;
				deltaLat = cellPtr->AA [1] +
						   cellPtr->BB [1] * gridDeltaLng +
						   cellPtr->CC [1] * gridDeltaLat +
						   cellPtr->DD [1] * gridDeltaLng * gridDeltaLat;
				trgLL [LNG] = lclLL [LNG] - deltaLng * cs_Sec2Deg;
				trgLL [LAT] = lclLL [LAT] + deltaLat * cs_Sec2Deg;

				/* Undo the Alaska thing. */
				if (alaskaFlag)
				{
					trgLL [LNG] += cs_K360;
				}

				/* Signal conversion successfully performed. */
				status = 0;
			}
			break;

		case dtcTypeAustralian:
		case dtcTypeCanadian1:
		case dtcTypeCanadian2:
			/* Similar, but different stuff for these guys.  In this case,
			   longitude is west positive, even for the Australians.  Thus,
			   the longitude code will seem strange.  Think of Canada being
			   in Russia, and Australia being in South America to keep your
			   mind straight. */
			lclLL [LNG] = -srcLL [LNG];
			lclLL [LAT] = srcLL [LAT];
			if (lclLL [LNG] >= cellPtr->southWest [LNG] &&
				lclLL [LAT] >= cellPtr->southWest [LAT] &&
				lclLL [LNG] <  cellPtr->northEast [LNG] &&
				lclLL [LAT] <  cellPtr->northEast [LAT])
			{
				/* Do the calculation. */
				gridDeltaLng = (lclLL [LNG] - cellPtr->southWest [LNG]) / cellPtr->deltaLng;
				gridDeltaLat = (lclLL [LAT] - cellPtr->southWest [LAT]) / cellPtr->deltaLat;
				deltaLng = cellPtr->AA [0] +
						   cellPtr->BB [0] * gridDeltaLng +
						   cellPtr->CC [0] * gridDeltaLat +
						   cellPtr->DD [0] * gridDeltaLng * gridDeltaLat;
				deltaLat = cellPtr->AA [1] +
						   cellPtr->BB [1] * gridDeltaLng +
						   cellPtr->CC [1] * gridDeltaLat +
						   cellPtr->DD [1] * gridDeltaLng * gridDeltaLat;
				trgLL [LNG] = srcLL [LNG] - deltaLng * cs_Sec2Deg;
				trgLL [LAT] = srcLL [LAT] + deltaLat * cs_Sec2Deg;

				/* Signal conversion successfully performed. */
				status = 0;
			}
			break;

		default:
			/* Just in case. */
			CS_erpt (cs_ISER);
			status = -1;
			break;
		}									/*lint !e788 */

		/* If we did the calculation, we're outa here. */
		if (status > 0)
		{
			cellPtr = cellPtr->next;
		}
		else
		{
			if (status == 0 && cellPtr != __This->listHead)
			{
				/* Make this the first cell. */
				CSfirstLLGridCellCache (__This,cellPtr);
			}
			break;
		}
	}
	return status;
}
Const char *CSsourceLLGridCellCache (struct csLLGridCellCache_* __This,Const double srcLL [2])
{
	extern double cs_K360;

	int status;
	int alaskaFlag;

	Const char *cp;
	struct csLLGridCell_* cellPtr;

	double lclLL [2];

	status = 1;
	cp = NULL;
	alaskaFlag = FALSE;

	/* Search the cache. */
	cellPtr = __This->listHead;
	while (cellPtr != NULL)
	{
		/* For now, we can accomodate all four cases rather
		   easily. */
		switch (cellPtr->type) {
		case dtcTypeUS:
		case dtcTypeHarn:
			lclLL [LNG] = srcLL [LNG];
			lclLL [LAT] = srcLL [LAT];

			/* Need to play a game to properly convert Alaska longitude.
			   The grid cell may be set up with a longitude < -180. */
			if (lclLL [LNG] > 0.0)
			{
				lclLL [LNG] -= cs_K360;
				alaskaFlag = TRUE;
			}

			/* See if this cell covers the coordinate we're converting. */
			if (lclLL [LNG] >= cellPtr->southWest [LNG] &&
				lclLL [LAT] >= cellPtr->southWest [LAT] &&
				lclLL [LNG] <  cellPtr->northEast [LNG] &&
				lclLL [LAT] <  cellPtr->northEast [LAT])
			{
				cp = cellPtr->sourceId;
				status = 0;
			}
			break;

		case dtcTypeAustralian:
		case dtcTypeCanadian1:
		case dtcTypeCanadian2:
			/* Similar, but different stuff for these guys.  In this case,
			   longitude is west positive, even for the Australians.  Thus,
			   the longitude code will seem strange.  Think of Canada being
			   in Russia, and Australia being in South America to keep your
			   mind straight. */
			lclLL [LNG] = -srcLL [LNG];
			lclLL [LAT] = srcLL [LAT];
			if (lclLL [LNG] >= cellPtr->southWest [LNG] &&
				lclLL [LAT] >= cellPtr->southWest [LAT] &&
				lclLL [LNG] <  cellPtr->northEast [LNG] &&
				lclLL [LAT] <  cellPtr->northEast [LAT])
			{
				cp = cellPtr->sourceId;
				status = 0;
			}
			break;

		default:
			/* Just in case. */
			CS_erpt (cs_ISER);
			status = -1;
			break;
		}									/*lint !e788 */

		/* If we did the calculation, we're outa here. */
		if (status > 0)
		{
			cellPtr = cellPtr->next;
		}
		else
		{
			break;
		}
	}
	return cp;
}																/*lint !e550 */

/******************************************************************************
	Single dimension grid cell cache.
*/
struct csZGridCellCache_* CSnewZGridCellCache (int cellCount)
{
	struct csZGridCellCache_* cachePtr;

	if (cellCount < 2)
	{
		CS_erpt (cs_ISER);
		return NULL;
	}
	cachePtr = (struct csZGridCellCache_ *)CS_malc (sizeof (struct csZGridCellCache_));
	if (cachePtr == NULL)
	{
		CS_erpt (cs_NO_MEM);
		return cachePtr;
	}
	cachePtr->maxCount = cellCount;
	cachePtr->usedCount = 0;
	cachePtr->listHead = NULL;
	return cachePtr;
}
void CSdeleteZGridCellCache (struct csZGridCellCache_* __This)
{
	if (__This != NULL)
	{
		CSreleaseZGridCellCache (__This);
		CS_free (__This);
	}
}
void CSreleaseZGridCellCache (struct csZGridCellCache_* __This)
{
	struct csZGridCell_* cellPtr;
	struct csZGridCell_* tmpPtr;

	if (__This != NULL)
	{
		cellPtr = __This->listHead;
		while (cellPtr != NULL)
		{
			tmpPtr = cellPtr;
			cellPtr = cellPtr->next;
			CS_free (tmpPtr);
		}
		__This->usedCount = 0;
	}
	return;
}

int CSaddZGridCellCache (struct csZGridCellCache_* __This,enum csDtCvtType cellType,
														  struct csGridCell_* zzzCell)
{
	extern char csErrnam [];

	struct csZGridCell_ *cellPtr, *prvCellPtr;

	/* Adjust the cache so that the first entry is suitable for the
	   new addition. */
	if (__This->usedCount < __This->maxCount)
	{
		/* Here to add a complete new cell to the cache. */
		cellPtr = (struct csZGridCell_*)CS_malc (sizeof (struct csZGridCell_));
		if (cellPtr == NULL)
		{
			CS_erpt (cs_NO_MEM);
			return -1;
		}
		if (__This->listHead == NULL) cellPtr->next = NULL;
		else cellPtr->next = __This->listHead;
		__This->listHead = cellPtr;
		__This->usedCount += 1;
	}
	else
	{
		/* Here to reuse an existing grid cell. */
		cellPtr = __This->listHead;
		prvCellPtr = NULL;
		while (cellPtr->next != NULL)
		{
			prvCellPtr = cellPtr;
			cellPtr = cellPtr->next;
		}
		if (prvCellPtr == NULL)
		{
			CS_stncp (csErrnam,"CSgridCellCache:2",MAXPATH);
			CS_erpt (cs_ISER);
			return -1;
		}
		prvCellPtr->next = NULL;
		cellPtr->next = __This->listHead;
		__This->listHead = cellPtr;
	}

	/* Cell pointer points to the first cell in the list; which
	   is also the target of the add. */
	cellPtr->type = cellType;
	cellPtr->southWest [LNG] = zzzCell->coverage.southWest [LNG];
	cellPtr->southWest [LAT] = zzzCell->coverage.southWest [LAT];
	cellPtr->northEast [LNG] = zzzCell->coverage.northEast [LNG];
	cellPtr->northEast [LAT] = zzzCell->coverage.northEast [LAT];

	cellPtr->deltaLng = zzzCell->deltaLng;
	cellPtr->deltaLat = zzzCell->deltaLat;

	cellPtr->AA = zzzCell->currentAA;
	cellPtr->BB = zzzCell->currentBB;
	cellPtr->CC = zzzCell->currentCC;
	cellPtr->DD = zzzCell->currentDD;
	return 0;
}
void CSfirstZGridCellCache (struct csZGridCellCache_* __This,struct csZGridCell_* cellPtr)
{
	struct csZGridCell_ *srchPtr;

	/* This is structured so that if cellPtr is the same as listHead,
	   nothing happens. */
	srchPtr = __This->listHead;
	while (srchPtr != NULL)
	{
		if (srchPtr->next == cellPtr)
		{
			/* We have found the cell. */
			srchPtr->next = srchPtr->next->next;
			cellPtr->next = __This->listHead;
			__This->listHead = cellPtr;
			break;
		}
		srchPtr = srchPtr->next;
	}
	return;
}

int CScalcZGridCellCache (struct csZGridCellCache_* __This,double* target,Const double srcLL [2])
{
	extern double cs_K360;

	int status;
	struct csZGridCell_* cellPtr;
	double gridDeltaLng, gridDeltaLat;

	double lclLL [2];

	status = 1;

	/* Search the cache. */
	cellPtr = __This->listHead;
	while (cellPtr != NULL)
	{
		/* For now, we can accomodate all four cases rather
		   easily. */
		switch (cellPtr->type) {
		case dtcTypeGeoid96:
		case dtcTypeUSVertcon:
			lclLL [LNG] = srcLL [LNG];
			lclLL [LAT] = srcLL [LAT];

			/* Need to play a game to properly convert Alaska longitude.
			   The grid cell may be set up with a longitude < -180. */
			if (lclLL [LNG] > 0.0)
			{
				lclLL [LNG] -= cs_K360;
			}

			/* See if this cell covers the coordinate we're converting. */
			if (lclLL [LNG] >= cellPtr->southWest [LNG] &&
				lclLL [LAT] >= cellPtr->southWest [LAT] &&
				lclLL [LNG] <  cellPtr->northEast [LNG] &&
				lclLL [LAT] <  cellPtr->northEast [LAT])
			{
				/* Do the calculation. */
				gridDeltaLng = (lclLL [LNG] - cellPtr->southWest [LNG]) / cellPtr->deltaLng;
				gridDeltaLat = (lclLL [LAT] - cellPtr->southWest [LAT]) / cellPtr->deltaLat;
				*target = cellPtr->AA +
						  cellPtr->BB * gridDeltaLng +
						  cellPtr->CC * gridDeltaLat +
						  cellPtr->DD * gridDeltaLng * gridDeltaLat;

				/* Signal conversion successfully performed. */
				status = 0;
			}
			break;

		default:
			/* Just in case. */
			CS_erpt (cs_ISER);
			status = -1;
			break;
		}								/*lint !e788 */

		/* If we did the calculation, we're outa here. */
		if (status > 0)
		{
			cellPtr = cellPtr->next;
		}
		else
		{
			if (status == 0 && cellPtr != __This->listHead)
			{
				/* Make this the first cell. */
				CSfirstZGridCellCache (__This,cellPtr);
			}
			break;
		}
	}
	return status;
}

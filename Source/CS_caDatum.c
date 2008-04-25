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

			 File Name: $Source: C:/Development/NewCsMap/rcs/CS_caDatum.c $
			 Full Name:	CA Datum Shift Objects, 1 and 2
		   Description:
			   Purpose:	Implements the Canadian versions of datum
						shifts.

		Revision Level:	$Revision: #3 $
				  Date:	$Date: 2005/07/26 $

		 Last Revision:	$Log: CS_caDatum.c $
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
		 Last Revision:	Revision 11.501  2003/08/22 21:12:53  nto
		 Last Revision:	Official Release: 11.05
		 Last Revision:	Revision 11.401  2003/05/01 23:06:19  nto
		 Last Revision:	Revision 11.300  2003/02/25 04:29:14  nto
		 Last Revision:	Official Release 11.03
		 Last Revision:	Revision 11.100  2002/11/22 19:38:41  nto
		 Last Revision:	Official release: 11.01
		 Last Revision:	Revision 10.1501  2002/11/13 23:05:33  nto
		 Last Revision:	Added grid data file logging for Nad27ToNad83.
		 Last Revision:	Revision 10.1500  2002/09/22 00:01:17  nto
		 Last Revision:	Official Release:= 10.15
		 Last Revision:	Revision 10.1400  2002/08/09 18:14:20  nto
		 Last Revision:	Revision 10.1200  2002/07/14 03:26:12  nto
		 Last Revision:	Revision 10.1100  2002/06/13 14:18:34  nto
		 Last Revision:	Release 10.11 Official
		 Last Revision:	Revision 10.1000  2002/02/23 21:18:24  nto
		 Last Revision:	Official Release of 10.10, 2/22/02 - Norm Olsen
		 Last Revision:	Revision 10.900  2001/09/24 04:31:09  nto
		 Last Revision:	Revision 10.700  2001/01/25 04:13:44  nto
		 Last Revision:	Revision 10.600  2000/12/11 06:39:39  nto
		 Last Revision:	Release 10.06
		 Last Revision:	Revision 10.500  2000/10/27 07:38:16  nto
		 Last Revision:	Official Release 10.05
		 Last Revision:	Revision 10.400  2000/09/13 01:16:51  nto
		 Last Revision:	Release 10.04
		 Last Revision:	Revision 10.300  2000/04/04 23:18:21  nto
		 Last Revision:	Revision 10.200  2000/03/02 18:51:13  nto
		 Last Revision:	Revision 10.1  1999/11/03 23:41:03  nto
		 Last Revision:	Results of datum conversion rewrite.

		       * * * * R E M A R K S * * * *
	The US datum shift requires two grid files; thus a US datum
	shift object was required.  These objects are very simple
	and exist largely to be consistent with the US
	implementation.  Who knows, maybe some day there will be
	a need to do something special at this level.

******************************************************************************/

#include "cs_map.h"

#ifdef LABEL_MODULE
static char revlvl [] = {"%W"};
#endif

/******************************************************************************
Constructor */
struct csDatumShiftCa2_* CSnewDatumShiftCa2 (enum csDtCvtType type,Const char *path,long bufferSize,unsigned long flags,double density)
{
	struct csDatumShiftCa2_ *__This = NULL;

	__This = (struct csDatumShiftCa2_ *)CS_malc (sizeof (struct csDatumShiftCa2_));
	if (__This == NULL)
	{
		CS_erpt (cs_NO_MEM);
		goto error;
	}
	__This->gridPtr = NULL;

	__This->gridPtr = CSnewGridFileCa2 (type,path,bufferSize,flags,density);
	if (__This->gridPtr == NULL) goto error;
	return __This;
error:
	if (__This != NULL)
	{
		if (__This->gridPtr != NULL) CSdeleteGridFileCa2 (__This->gridPtr);
		CS_free (__This);
	}
	return NULL;
}
/* Destructor */
void CSdeleteDatumShiftCa2 (struct csDatumShiftCa2_* __This)
{
	if (__This != NULL)
	{
		if (__This->gridPtr != NULL) CSdeleteGridFileCa2 (__This->gridPtr);
		CS_free (__This);
	}
}
void CSreleaseDatumShiftCa2 (struct csDatumShiftCa2_* __This)
{
	if (__This != NULL)
	{
		if (__This->gridPtr != NULL) CSreleaseGridFileCa2 (__This->gridPtr);
	}
}
double CStestDatumShiftCa2 (struct csDatumShiftCa2_* __This,Const double *coord)
{
	if (__This->gridPtr == NULL) return 0.0;
	return CStestGridFileCa2 (__This->gridPtr,coord);
}
int CScalcDatumShiftCa2 (struct csDatumShiftCa2_* __This,double* result,Const double* source,struct csLLGridCellCache_ *cachePtr)
{
	extern double cs_Sec2Deg;		/* 1/3600 */
	int status;
	double deltaLL [2];

	/* Here we simply shift the longitude using lngShift, and the latitude
	   using latShift. */
	status = CScalcGridFileCa2 (__This->gridPtr,deltaLL,source);
	if (status == 0)
	{
		result [LNG] = source [LNG] - deltaLL [LNG] * cs_Sec2Deg;
		result [LAT] = source [LAT] + deltaLL [LAT] * cs_Sec2Deg;
		if (cachePtr != NULL && __This->gridPtr->CellIsValid)
		{
			CSaddLLGridCellCache (cachePtr,dtcTypeCanadian2,&__This->gridPtr->longitudeCell,
															&__This->gridPtr->latitudeCell);
		}
	}
	else if (status > 0)
	{
		result [LNG] = source [LNG];
		result [LAT] = source [LAT];
	}
	return status;
}
Const char *CSsourceDatumShiftCa2 (struct csDatumShiftCa2_* __This,Const double llSource [2])
{
	Const char *cp;

	cp = CSsourceGridFileCa2 (__This->gridPtr,llSource);	
	return cp;
}

/******************************************************************************
Constructor */
struct csDatumShiftCa1_* CSnewDatumShiftCa1 (Const char *path,long bufferSize,unsigned long flags,double density)
{
	struct csDatumShiftCa1_ *__This = NULL;

	__This = (struct csDatumShiftCa1_ *)CS_malc (sizeof (struct csDatumShiftCa1_));
	if (__This == NULL)
	{
		CS_erpt (cs_NO_MEM);
		goto error;
	}
	__This->gridPtr = NULL;

	__This->gridPtr = CSnewGridFileCa1 (path,bufferSize,flags,density);
	if (__This->gridPtr == NULL) goto error;
	return __This;
error:
	if (__This != NULL)
	{
		if (__This->gridPtr != NULL) CSdeleteGridFileCa1 (__This->gridPtr);
		CS_free (__This);
	}
	return NULL;
}
/* Destructor */
void CSdeleteDatumShiftCa1 (struct csDatumShiftCa1_* __This)
{
	if (__This != NULL)
	{
		if (__This->gridPtr != NULL) CSdeleteGridFileCa1 (__This->gridPtr);
		CS_free (__This);
	}
}
void CSreleaseDatumShiftCa1 (struct csDatumShiftCa1_* __This)
{
	if (__This != NULL)
	{
		if (__This->gridPtr != NULL) CSreleaseGridFileCa1 (__This->gridPtr);
	}
}
double CStestDatumShiftCa1 (struct csDatumShiftCa1_* __This,Const double *coord)
{
	if (__This->gridPtr == NULL) return 0.0;
	return CStestGridFileCa1 (__This->gridPtr,coord);
}
int CScalcDatumShiftCa1 (struct csDatumShiftCa1_* __This,double* result,Const double* source,struct csLLGridCellCache_ *cachePtr)
{
	extern double cs_Sec2Deg;		/* 1/3600 */

	int status;
	double deltaLL [2];

	/* Here we simply shift the longitude using lngShift, and the latitude
	   using latShift. */
	status = CScalcGridFileCa1 (__This->gridPtr,deltaLL,source);
	if (status == 0)
	{
		result [LNG] = source [LNG] - deltaLL [LNG] * cs_Sec2Deg;
		result [LAT] = source [LAT] + deltaLL [LAT] * cs_Sec2Deg;
		if (cachePtr != NULL && __This->gridPtr->CellIsValid)
		{
			CSaddLLGridCellCache (cachePtr,dtcTypeCanadian1,&__This->gridPtr->longitudeCell,
															&__This->gridPtr->latitudeCell);
		}
	}
	else if (status > 0)
	{
		result [LNG] = source [LNG];
		result [LAT] = source [LAT];
	}
	return status;
}
Const char *CSsourceDatumShiftCa1 (struct csDatumShiftCa1_* __This,Const double* source)
{
	Const char *cp;

	cp = CSsourceGridFileCa1 (__This->gridPtr,source);
	return cp;
}


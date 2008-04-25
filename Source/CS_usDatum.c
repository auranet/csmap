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

			 File Name: $Source: C:/Development/NewCsMap/rcs/CS_usDatum.c $
			 Full Name:	US Datum Shift Object
		   Description:	
			   Purpose:	Combines two csGridFileUS objects into a
						single object which can perform the datum
						shift operation.

		Revision Level:	$Revision: #4 $
				  Date:	$Date: 2006/11/16 $

		 Last Revision:	$Log: CS_usDatum.c $
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
		 Last Revision:	Revision 11.501  2003/08/22 21:13:00  nto
		 Last Revision:	Official Release: 11.05
		 Last Revision:	Revision 11.401  2003/05/01 23:06:26  nto
		 Last Revision:	Revision 11.300  2003/02/25 04:29:21  nto
		 Last Revision:	Official Release 11.03
		 Last Revision:	Revision 11.100  2002/11/22 19:38:48  nto
		 Last Revision:	Official release: 11.01
		 Last Revision:	Revision 10.1501  2002/11/13 23:05:35  nto
		 Last Revision:	Added grid data file logging for Nad27ToNad83.
		 Last Revision:	Revision 10.1500  2002/09/22 00:01:25  nto
		 Last Revision:	Official Release:= 10.15
		 Last Revision:	Revision 10.1400  2002/08/09 18:14:26  nto
		 Last Revision:	Revision 10.1200  2002/06/20 18:00:31  nto
		 Last Revision:	Official release: 10.12
		 Last Revision:	Revision 10.1100  2002/06/13 14:18:44  nto
		 Last Revision:	Release 10.11 Official
		 Last Revision:	Revision 10.1000  2002/02/23 21:18:30  nto
		 Last Revision:	Official Release of 10.10, 2/22/02 - Norm Olsen
		 Last Revision:	Revision 10.900  2001/09/24 04:31:14  nto
		 Last Revision:	Revision 10.701  2001/05/01 16:47:01  nto
		 Last Revision:	Correct possibility of character overflow on Unix systems where path names can get quite long.
		 Last Revision:	Revision 10.700  2001/01/25 04:13:56  nto
		 Last Revision:	Revision 10.600  2000/12/11 06:39:50  nto
		 Last Revision:	Release 10.06
		 Last Revision:	Revision 10.500  2000/10/27 07:38:31  nto
		 Last Revision:	Official Release 10.05
		 Last Revision:	Revision 10.400  2000/09/13 01:17:02  nto
		 Last Revision:	Release 10.04
		 Last Revision:	Revision 10.300  2000/04/04 23:18:33  nto
		 Last Revision:	Revision 10.200  2000/03/02 18:51:23  nto
		 Last Revision:	Revision 1.2  1999/11/03 23:41:08  nto
		 Last Revision:	Results of datum conversion rewrite.

		       * * * * R E M A R K S * * * *

	US datum shift calculations, i.e. NAD27 <--> NAD83 and
	NAD83 <--> HPGN, require a system of two US grid files.
	The object defined and implemented here combines two
	csGridFileUS_ structures into a single object, and
	implements a datum shift conversion.  Such objects are
	used to perform these datum shifts.

******************************************************************************/

#include "cs_map.h"

#ifdef LABEL_MODULE
static char revlvl [] = {"%W"};
#endif

/******************************************************************************
	Constructor
*/
struct csDatumShiftUS_* CSnewDatumShiftUS (enum csDtCvtType type,Const char *path,long bufferSize,unsigned long flags,double density)
{
	extern char cs_DirsepC;
	extern char cs_ExtsepC;

	/* Do the .LAS, then the .LOS.  Note, this is a datum shift object,
	   so there will always be two of these. */

	char *cpFront;
	char *cpBack;
	struct csDatumShiftUS_ *__This = NULL;
	char ctemp [MAXPATH];

	__This = (struct csDatumShiftUS_ *)CS_malc (sizeof (struct csDatumShiftUS_));
	if (__This == NULL)
	{
		CS_erpt (cs_NO_MEM);
		goto error;
	}
	__This->lngShift = NULL;
	__This->latShift = NULL;
	__This->type = type;

	CS_stncp (ctemp,path,sizeof (ctemp));
	cpFront = strrchr (ctemp,cs_DirsepC);
	if (cpFront == NULL) cpFront = ctemp;
	else cpFront += 1;

	/* Do the .LOS file */
	cpBack = strrchr (cpFront,cs_ExtsepC);
	if (cpBack == NULL) cpBack = cpFront + strlen (cpFront);
	*cpBack++ = cs_ExtsepC;
	*cpBack = '\0';													/*lint !e661 */
	strcat (ctemp,cs_NADCON_LOS);
	__This->lngShift = CSnewGridFileUS (ctemp,bufferSize,flags,density);
	if (__This->lngShift == NULL) goto error;

	/* Do the .LAS file */
	cpBack = strrchr (cpFront,cs_ExtsepC);
	if (cpBack == NULL) cpBack = cpFront + strlen (cpFront);
	*cpBack++ = cs_ExtsepC;
	*cpBack = '\0';													/*lint !e661 */
	strcat (ctemp,cs_NADCON_LAS);
	__This->latShift = CSnewGridFileUS (ctemp,bufferSize,flags,density);
	if (__This->latShift == NULL) goto error;

	/* Verify that the two files are consistent. */
	if (__This->lngShift->coverage.southWest [0] != __This->latShift->coverage.southWest [0] ||		/*lint !e777 */
		__This->lngShift->coverage.southWest [1] != __This->latShift->coverage.southWest [1] ||		/*lint !e777 */
		__This->lngShift->coverage.northEast [0] != __This->latShift->coverage.northEast [0] ||		/*lint !e777 */
		__This->lngShift->coverage.northEast [1] != __This->latShift->coverage.northEast [1] ||		/*lint !e777 */
		__This->lngShift->elementCount           != __This->latShift->elementCount ||
		__This->lngShift->recordCount            != __This->latShift->recordCount ||
		__This->lngShift->deltaLng               != __This->latShift->deltaLng ||					/*lint !e777 */
		__This->lngShift->deltaLat               != __This->latShift->deltaLat)						/*lint !e777 */
	{
		CS_erpt (cs_NADCON_CONS);
		goto error;
	}
		
	return __This;
error:
	if (__This != NULL)
	{
		if (__This->lngShift != NULL) CSdeleteGridFileUS (__This->lngShift);
		if (__This->latShift != NULL) CSdeleteGridFileUS (__This->latShift);
		CS_free (__This);
	}
	return NULL;
}

/******************************************************************************
	Destructor
*/
void CSdeleteDatumShiftUS (struct csDatumShiftUS_* __This)
{
	if (__This != NULL)
	{
		if (__This->lngShift != NULL) CSdeleteGridFileUS (__This->lngShift);
		if (__This->latShift != NULL) CSdeleteGridFileUS (__This->latShift);
		CS_free (__This);
	}
}

/******************************************************************************
	Release resource
*/
void CSreleaseDatumShiftUS (struct csDatumShiftUS_* __This)
{
	if (__This != NULL)
	{
		if (__This->lngShift != NULL) CSreleaseGridFileUS (__This->lngShift);
		if (__This->latShift != NULL) CSreleaseGridFileUS (__This->latShift);
	}
}

/******************************************************************************
	Select a specific "Entry" from the linked list of "Entry" objects.
*/
double CStestDatumShiftUS (struct csDatumShiftUS_* __This,Const double *coord)
{
	if (__This->lngShift == NULL) return 0.0;
	return CStestGridFileUS (__This->lngShift,coord);
}

/******************************************************************************
	Calculate the shift.
*/
int CScalcDatumShiftUS (struct csDatumShiftUS_* __This,double* result,Const double* source,struct csLLGridCellCache_ *cachePtr)
{
	extern double cs_Sec2Deg;			/* 1.0 / 3600.0 */

	int status;
	double deltaLng;
	double deltaLat;

	/* Here we simply shift the longitude using lngShift, and the latitude
	   using latShift. */
	status = CScalcGridFileUS (__This->lngShift,&deltaLng,source);
	if (status == 0)
	{
		status = CScalcGridFileUS (__This->latShift,&deltaLat,source);
		if (status == 0)
		{
			result [LNG] = source [LNG] - deltaLng * cs_Sec2Deg;
			result [LAT] = source [LAT] + deltaLat * cs_Sec2Deg;

			/* If cachePtr is not NULL, we add the current cell to the
			   cache.  If we find situations where cacheing a cell is
			   inappropriate, add that code here. */
			if (cachePtr != NULL)
			{
				CSaddLLGridCellCache (cachePtr,__This->type,&__This->lngShift->currentCell,&__This->latShift->currentCell);
			}
		}
	}
	if (status > 0)
	{
		result [LNG] = source [LNG];
		result [LAT] = source [LAT];
	}
	return status;
}
Const char *CSsourceDatumShiftUS (struct csDatumShiftUS_* __This,Const double llSource [2])
{
	Const char *cp;

	cp = CSsourceGridFileUS (__This->lngShift,llSource);
	return cp;
}

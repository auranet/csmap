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

			 File Name: $RCSfile: CS_ats77Transform.c $
		   Description:
			   Purpose:

		Revision Level:	$Revision: #5 $
		 Check In Date:	$Date: 2006/11/27 $

		Last Revision:	$Log: CS_ats77Transform.c $
		Last Revision:	Revision 11.1300  2005/05/25 23:27:06  nto
		Last Revision:	Official Release 11.13
		Last Revision:	Revision 11.1200  2005/01/15 18:27:08  nto
		Last Revision:	Official Release of CS-MAP 11.12, 11:26am 15 Jan 2005
		Last Revision:	Revision 11.1100  2004/11/01 18:53:05  nto
		Last Revision:	Official release 11.11
		Last Revision:	Revision 11.1001  2004/10/07 19:25:14  nto
		Last Revision:	Revision 11.900  2004/03/26 17:02:21  nto
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
		Last Revision:	Revision 10.1503  2002/11/21 00:41:40  nto
		Last Revision:	Added the log/source functions for reporting which file got used in datum conversions.
		Last Revision:	Revision 10.1502  2002/10/06 17:49:07  nto
		Last Revision:	Fixed a 'const' ambiguity.
		Last Revision:	Revision 10.1501  2002/09/29 21:21:21  nto
		Last Revision:	Changed references to strnicmp to CS_strincmp.
		Last Revision:	Revision 10.1500  2002/09/22 00:01:17  nto
		Last Revision:	Official Release:= 10.15
		Last Revision:	Revision 1.2  2002/09/17 23:23:14  nto
		Last Revision:	Added the coverage test function, and had to rename the debug test function.
		Last Revision:	Revision 1.1  2002/09/15 21:12:38  nto
		Last Revision:	Initial Revision

		*  *  *  *  R E M A R K S *  *  *  *  *

	This object implements the functionality of the ATS77 TRANSFORM
	program as used by the Maritime Provinces of Canada.  This
	algorithm is used to convert directly between ATS77 <--> NAD27.

	There are six data files possible.  For each conversion direction
	there is one file for each of the three provinces involved.

******************************************************************************/

#ifdef LABEL_MODULE
static char revlvl [] = {"$Id: //depot/Libraries/CsMap/current/src/CS_ats77Transform.c#5 $"};
#endif

#include "cs_map.h"

struct cs_Ats77Xfrm_ *CSnewAts77Xfrm (Const char *filePath,unsigned long flags,double density)
{
	extern char csErrnam [];
	extern char cs_DirsepC;
	extern char cs_ExtsepC;

	extern double cs_Huge;
	extern double cs_Mhuge;
	extern double cs_Zero;
	extern double cs_One;

	int idx;
	size_t rdCnt;

	long np;
	long n4;
	long n5;
	long tmpLong;

	double tmpDbl;
	double c1;
	double c2;

	char *cp;
	csFILE *strm = NULL;
	struct cs_Ats77Xfrm_ *__This = NULL;

	/* Allocate and initialize the object. */
	__This = CS_malc (sizeof (struct cs_Ats77Xfrm_));
	if (__This == NULL)
	{
		CS_erpt (cs_NO_MEM);
		goto error;
	}
	__This->coeffs = NULL;

	/* Initialize the structure; mostly just to be safe. */
	__This->coverage.southWest [LNG] = cs_Huge;
	__This->coverage.southWest [LAT] = cs_Huge;
	__This->coverage.northEast [LNG] = cs_Mhuge;
	__This->coverage.northEast [LAT] = cs_Mhuge;
	__This->coverage.density = cs_Zero;
	__This->province = ats77PrvNone;
	__This->direction = ats77DirNone;
	__This->iMax = 0L;
	__This->jMax = 0L;
	__This->polynomialDegree = 0L;
	__This->controlStations  = 0L;
	__This->rui2 = 0.0;
	__This->localOrigin [0] = cs_Zero;
	__This->localOrigin [0] = cs_Zero;
	__This->localOrigin [1] = cs_Zero;
	__This->dataScale [0] = cs_One;
	__This->dataScale [1] = cs_One;
	__This->UO = cs_Zero;
	__This->UO = cs_Zero;
	__This->SU = cs_Zero;
	__This->SV = cs_Zero;
	__This->filePath [0] = '\0';
	__This->fileName [0] = '\0';
	for (idx = 0;idx < 10;idx++)
	{
		CS_iicrt (&__This->ccc [idx],cs_Zero,cs_Zero);
	}

	/* Save the file path we will be reading (hopefully).  Also, extract
	   the name only portion for error reporting purposes. */
	CS_stncp (__This->filePath,filePath,sizeof (__This->filePath));
	cp = strrchr (filePath,cs_DirsepC);
	if (cp != NULL)
	{
		CS_stncp (__This->fileName,(cp + 1),sizeof (__This->fileName));
		cp = strrchr (__This->fileName,cs_ExtsepC);
		if (cp != NULL) *cp = '\0';
	}

	/* Doing this after every read is rather boring.  We'll do it
	   here once and get it done with. */
	CS_stncp (csErrnam,__This->filePath,MAXPATH);

	/* OK, open up the file and read in the important stuff.  Note, we leave
	   all this stuff in memeory, so we don't keep the file open. */
	strm = CS_fopen (__This->filePath,_STRM_BINRD);
	if (strm == NULL)
	{
		CS_erpt (cs_DTC_FILE);
		goto error;
	}

	/* The third and fourth letters indicate the province. */
	if (!CS_strnicmp (&__This->fileName [2],"nb",2))
	{
		/* NB for New Brunswick. */
		__This->province = ats77PrvNB;
		__This->iMax = 76086L;
	}
	else if (!CS_strnicmp (&__This->fileName [2],"ns",2))
	{
		/* NS for Nova Scotia. */
		__This->province = ats77PrvNS;
		__This->iMax = 86141;
	}
	else if (!CS_strnicmp (&__This->fileName [2],"pe",2))
	{
		/* PE for Prince Edward island. */
		__This->province = ats77PrvPE;
		__This->iMax = 18856L;
	}
	else
	{
		CS_erpt (cs_INV_FILE);
		goto error;
	}

	/* Read in the various header stuff, do header calculations, and
	   remember to do the byte swapping as is appropriate.
	   
	   The first thing in the file is junk.  Perhaps something to do
	   with how FORTRAN I/O works. */
	rdCnt = CS_fread (&tmpLong,sizeof (tmpLong),1,strm);
	if (rdCnt != 1)
	{
		CS_erpt (cs_IOERR);
		goto error;
	}

	/* Polynomial degree. */
	rdCnt = CS_fread (&tmpLong,sizeof (tmpLong),1,strm);
	if (rdCnt != 1)
	{
		CS_erpt (cs_IOERR);
		goto error;
	}
	CS_bswap (&tmpLong,"l");
	__This->polynomialDegree = tmpLong;
	__This->nf = __This->polynomialDegree + 1;

	/* Control Stations. */
	rdCnt = CS_fread (&tmpLong,sizeof (tmpLong),1,strm);
	if (rdCnt != 1)
	{
		CS_erpt (cs_IOERR);
		goto error;
	}
	CS_bswap (&tmpLong,"l");
	np = __This->controlStations = tmpLong;

	/* Direction indicator. */
	rdCnt = CS_fread (&tmpLong,sizeof (tmpLong),1,strm);
	if (rdCnt != 1)
	{
		CS_erpt (cs_IOERR);
		goto error;
	}
	CS_bswap (&tmpLong,"l");
	if (tmpLong == 1L)	__This->direction = ats77DirToAts77;
	else if (tmpLong == 2L) __This->direction = ats77DirToNad27;
	else
	{
		CS_erpt (cs_INV_FILE);
		goto error;
	}

	/* RUI, whatever that is. */
	rdCnt = CS_fread (&tmpDbl,sizeof (tmpDbl),1,strm);
	if (rdCnt != 1)
	{
		CS_erpt (cs_IOERR);
		goto error;
	}
	CS_bswap (&tmpDbl,"d");
	__This->rui2 = tmpDbl * tmpDbl;
	__This->oprue = cs_One + 0.250;

	/* Local Origin. */
	rdCnt = CS_fread (&tmpDbl,sizeof (tmpDbl),1,strm);
	if (rdCnt != 1)
	{
		CS_erpt (cs_IOERR);
		goto error;
	}
	CS_bswap (&tmpDbl,"d");
	__This->localOrigin [1] = tmpDbl;
	rdCnt = CS_fread (&tmpDbl,sizeof (tmpDbl),1,strm);
	if (rdCnt != 1)
	{
		CS_erpt (cs_IOERR);
		goto error;
	}
	CS_bswap (&tmpDbl,"d");
	__This->localOrigin [0] = tmpDbl;

	/* UO & VO, whatever they are. */
	rdCnt = CS_fread (&tmpDbl,sizeof (tmpDbl),1,strm);
	if (rdCnt != 1)
	{
		CS_erpt (cs_IOERR);
		goto error;
	}
	CS_bswap (&tmpDbl,"d");
	__This->UO = tmpDbl;
	rdCnt = CS_fread (&tmpDbl,sizeof (tmpDbl),1,strm);
	if (rdCnt != 1)
	{
		CS_erpt (cs_IOERR);
		goto error;
	}
	CS_bswap (&tmpDbl,"d");
	__This->VO = tmpDbl;

	/* Data Scale. */
	rdCnt = CS_fread (&tmpDbl,sizeof (tmpDbl),1,strm);
	if (rdCnt != 1)
	{
		CS_erpt (cs_IOERR);
		goto error;
	}
	CS_bswap (&tmpDbl,"d");
	__This->dataScale [1] = tmpDbl;
	rdCnt = CS_fread (&tmpDbl,sizeof (tmpDbl),1,strm);
	if (rdCnt != 1)
	{
		CS_erpt (cs_IOERR);
		goto error;
	}
	CS_bswap (&tmpDbl,"d");
	__This->dataScale [0] = tmpDbl;

	/* SU & SV whatever they are. */
	rdCnt = CS_fread (&tmpDbl,sizeof (tmpDbl),1,strm);
	if (rdCnt != 1)
	{
		CS_erpt (cs_IOERR);
		goto error;
	}
	CS_bswap (&tmpDbl,"d");
	__This->SU = tmpDbl;
	rdCnt = CS_fread (&tmpDbl,sizeof (tmpDbl),1,strm);
	if (rdCnt != 1)
	{
		CS_erpt (cs_IOERR);
		goto error;
	}
	CS_bswap (&tmpDbl,"d");
	__This->SV = tmpDbl;

	/* Skip FORTRAN structure packing stuff. */
	rdCnt = CS_fread (&tmpLong,sizeof (tmpLong),1,strm);
	if (rdCnt != 1)
	{
		CS_erpt (cs_IOERR);
		goto error;
	}
	CS_bswap (&tmpLong,"l");
	rdCnt = CS_fread (&tmpLong,sizeof (tmpLong),1,strm);
	if (rdCnt != 1)
	{
		CS_erpt (cs_IOERR);
		goto error;
	}
	CS_bswap (&tmpLong,"l");

	/* Determine the size of the complex coefficient array, allocate it,
	   and then read in the data.  While the first several thousand of
	   these things are actual complec number pairs, the last thousand
	   or so are straight doubles.  So, we use the brute force approach. */
	n4 = (5 * np) + 1;
	n5 = n4 + (2 * __This->nf);
	__This->jMax = 5 * (np + __This->nf) + (__This->nf * __This->nf);
	__This->coeffs = CS_malc (n5 * sizeof (double));
	if (__This->coeffs == NULL)
	{
		CS_erpt (cs_NO_MEM);
		goto error;
	}
	for (idx = 0;idx < n5;idx += 1)
	{
		rdCnt = CS_fread (&tmpDbl,sizeof (tmpDbl),1,strm);
		if (rdCnt != 1)
		{
			CS_erpt (cs_IOERR);
			goto error;
		}
		CS_bswap (&tmpDbl,"d");
		*(__This->coeffs + idx) = tmpDbl;
	}

	/* We don't need the file anymore. */
	CS_fclose (strm);
	strm = NULL;

	/* Need to calculate the base coefficients. */
	for (idx = 0;idx < __This->nf;idx += 1)
	{
		c1 = __This->coeffs [(n4 - 1) + (2 * idx)];
		c2 = __This->coeffs [(n4 - 1) + (2 * idx) + 1];
		CS_iicrt (&__This->ccc [idx],c1,c2);
	}

	/* Now we can compute the coverage of this object. */
	__This->coverage.southWest [LNG] = -__This->localOrigin [0] - (__This->oprue / __This->dataScale [0]);
	__This->coverage.southWest [LAT] =  __This->localOrigin [1] - (__This->oprue / __This->dataScale [1]);
	__This->coverage.northEast [LNG] = -__This->localOrigin [0] + (__This->oprue / __This->dataScale [0]);
	__This->coverage.northEast [LAT] =  __This->localOrigin [1] + (__This->oprue / __This->dataScale [1]);
	__This->coverage.density = 0.1;
	if (density > 0.0) __This->coverage.density = density;

	/* That's that. */
	return __This;
error:
	if (strm != NULL)
	{
		CS_fclose (strm);
		strm = NULL;
	}
	CSdeleteAts77Xfrm (__This);
	return NULL;
}
void CSdeleteAts77Xfrm (struct cs_Ats77Xfrm_ *__This)
{
	if (__This != NULL)
	{
		if (__This->coeffs != NULL)
		{
			CS_free (__This->coeffs);
			__This->coeffs = NULL;
		}
		CS_free (__This);
	}
	return;
}
void CSreleaseAts77Xfrm (struct cs_Ats77Xfrm_ *__This)
{
	/* For this type of object, release does nothing. */
	return;
}
enum cs_Ats77Dir_ CSdirectionAts77Xfrm (Const struct cs_Ats77Xfrm_ *__This)
{
	return __This->direction;
}
double CStestAts77Xfrm (Const struct cs_Ats77Xfrm_ *__This,enum cs_Ats77Dir_ direction,Const double point [2])
{
	double returnValue = 0.0;
	if (CSdirectionAts77Xfrm (__This) == direction)
	{
		if (point [LNG] >= __This->coverage.southWest [LNG] &&
			point [LAT] >= __This->coverage.southWest [LAT] &&
			point [LNG] <  __This->coverage.northEast [LNG] &&
			point [LAT] <  __This->coverage.northEast [LAT])
		{
			returnValue = __This->coverage.density;
		}
	}
	return returnValue;
}
/*
	Calculate the offset for a given geographic position.  The direction is built
	into the object.
*/
int CScalcAts77Xfrm (Const struct cs_Ats77Xfrm_ *__This,double ll_out [2],Const double ll_in [2])
{
	extern double cs_Zero;
	extern double cs_One;

	static const double clrk66Rad = 6378206.400;
	static const double clrk66Esq = 0.00676865799729122;

	static const double ats77Rad = 6378135.000;
	static const double ats77Esq = 0.00669438497508474;

	static const double ats77DeltaX = -15.0;
	static const double ats77DeltaY = 165.0;
	static const double ats77DeltaZ = 175.0;

	int st;
	int idx;
	int status;
	int idxNp1;
	int idxNp3;
	int idxNp5;

	double dd;
	double gu;
	double gv;
	double fu;
	double fv;
	double qq;
	double qw;
	double llDd;
	double expdd;

	double deltaLng;
	double deltaLat;

	double llh [3];
	double xyz [3];

	struct cs_Cmplx_ cz;
	struct cs_Cmplx_ cf;
	struct cs_Cmplx_ zz;
	struct cs_Cmplx_ czz;
	struct cs_Cmplx_ cTmp;
	struct cs_Cmplx_ cTmp1;

	status = 0;

	/* There are 5 sets of doubles in the A array (among other things).
	   The following are set up as the 'C' index to the first element
	   in each group.  Note, that the first two groups are actually
	   complex numbers, two doubles per index.  The last group
	   is a single set of doubles.  We use this scheme to preserve
	   our sanity as we convert some complicated indexing from
	   FORTRAN where the first element is index 1, and do loops start
	   index 1. */
	idxNp1 = 0;
	idxNp3 = 2 * __This->controlStations;
	idxNp5 = 4 * __This->controlStations;

	/* Convert to the correcdt ellipsoid using a Three Parameter Transformation. */
	llh [0] = ll_in [0];
	llh [1] = ll_in [1];
	llh [2] = cs_Zero;
	if (__This->direction == ats77DirToAts77)
	{
		CS_llhToXyz (xyz,llh,clrk66Rad,clrk66Esq);
		xyz [0] += ats77DeltaX;
		xyz [1] += ats77DeltaY;
		xyz [2] += ats77DeltaZ;
		st = CS_xyzToLlh (llh,xyz,ats77Rad,ats77Esq);
		if (st != 0) status = 1;
	}
	else if (__This->direction == ats77DirToNad27)
	{
		CS_llhToXyz (xyz,llh,ats77Rad,ats77Esq);
		xyz [0] -= ats77DeltaX;
		xyz [1] -= ats77DeltaY;
		xyz [2] -= ats77DeltaZ;
		st = CS_xyzToLlh (llh,xyz,clrk66Rad,clrk66Esq);
		if (st != 0) status = 1;
	}

	/* The rest of this stuff expects longitude to be positive west. */
	llh [0] = -llh [0];

	/* Now for the hard stuff.  We apply the complex coefficients.  We
	   work with the results of above, i.e. llh. */
	deltaLng = __This->dataScale [0] * (llh [0] - __This->localOrigin [0]);
	deltaLat = __This->dataScale [1] * (llh [1] - __This->localOrigin [1]);
	llDd = sqrt (deltaLng * deltaLng + deltaLat * deltaLat);
	if (llDd <= __This->oprue)
	{
		/* Appears to be in range.  Compute the result of applying the base
		   polynomial to the input values. */
		CS_iicrt (&cz,deltaLat,deltaLng);
		CS_iicpy (&__This->ccc [0],&cf);
		CS_iicrt (&czz,cs_One,cs_Zero);
		for (idx = 1;idx < __This->nf;idx += 1)
		{
			CS_iimul (&czz,&cz,&czz);
			CS_iimul (&czz,&__This->ccc [idx],&cTmp);
			CS_iiadd (&cf,&cTmp,&cf);
		}
		qq = cs_Zero;
		CS_iicrt (&czz,cs_Zero,cs_Zero);
		if (__This->rui2 != 0.0)
		{
			for (idx = 0;idx < __This->controlStations;idx += 1)
			{
				CS_iicrt (&zz,__This->coeffs [idxNp1 + (2 * idx)],__This->coeffs [idxNp1 + (2 * idx) + 1]);
				CS_iisub (&cz,&zz,&cTmp);
				dd = (cTmp.real * cTmp.real + cTmp.img * cTmp.img) / __This->rui2;
				expdd = cs_Zero;
				if (dd < 172.00) expdd = exp (-dd);
				qw = __This->coeffs [idxNp5 + idx] * expdd;
				if (fabs (qq + qw) >= 1.0E-75)
				{
					CS_iicrt (&cTmp,__This->coeffs [idxNp3 + (2 * idx)],__This->coeffs [idxNp3 + (2 * idx) + 1]);
					CS_iikmul (&cTmp,qw,&cTmp);
					CS_iikmul (&czz,qq,&cTmp1);
					CS_iiadd (&cTmp1,&cTmp,&cTmp);
					CS_iikmul (&cTmp,(1.0 / (qq + qw)),&czz);
				}
				qq += qw;
			}
			fu = cf.real  / __This->SU + __This->UO;
			fv = cf.img   / __This->SV + __This->VO;
			gu = czz.real / __This->SU;
			gv = czz.img  / __This->SV;

			ll_out [0] = -((llh [0] * 3600.00) - fv - gv) / 3600.00;
			ll_out [1] =  ((llh [1] * 3600.00) - fu - gu) / 3600.00;
		}
	}
	else
	{
		status = 1;
	}
	return status;
}
Const char *CSsourceAts77Xfrm (Const struct cs_Ats77Xfrm_ *__This)
{
	return __This->fileName;
}

#ifdef _DEBUG
double CS_Ats77XfrmTestFunction ()
{
	extern char cs_Dir [];
	extern char *cs_DirP;
	extern char csErrnam [];
	extern char cs_DirsepC;
	extern char cs_ExtsepC;

	/* These test values were obtained from execution of the TRANSFORM
	   program itself.  Obviously, the results were transcribed by
	   Mentor Software.  Thus, there may be an error in the
	   transcription. */
	static const double ll_in [7][2] =
	{
		{-59.8827587  ,46.12309425 },
		{-64.015471706,45.023685822},
		{-60.993470508,45.336660964},
		{-63.940173583,45.888912733},
		{-60.477884683,46.8888983  },
		{-66.132080328,43.951812075},
		{-60.534750144,47.026871825}
	};
	static const double ll_test [7][2] =
	{
		{-59.883498633,46.123061128},
		{-64.016066744,45.023638556},
		{-60.994167014,45.336616058},
		{-63.940773869,45.888867769},
		{-60.478607592,46.888862417},
		{-66.132609239,43.951761983},
		{-60.535471706,47.535471706}
	};

	int idx;
	int stat;

	struct cs_Ats77Xfrm_ *__This;

	double deltaX;
	double deltaY;
	double errorSum = 0.0;
	
	double ll_out [2];

	/* We only test one province, in one direction, but the code is
	   virtually the same. */
	CS_stcpy (cs_DirP,"TRNS7727.dat");
	__This = CSnewAts77Xfrm (cs_Dir,0,0.1);
	if (__This != NULL)
	{
		for (idx = 0;idx < 7;idx += 1)
		{
			stat = CScalcAts77Xfrm (__This,ll_out,ll_in [idx]);
			if (stat == 0)
			{
				deltaX = ll_out [0] - ll_test [idx][0];
				deltaY = ll_out [1] - ll_test [idx][1];
				errorSum += sqrt (deltaX * deltaX + deltaY * deltaY); 
			}
			else
			{
				CS_erpt (cs_ISER);
			}
		}
	}
	CSdeleteAts77Xfrm (__This);

	return (errorSum / 7.0);
}
#endif

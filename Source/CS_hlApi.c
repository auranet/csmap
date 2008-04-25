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

			 File Name: $RCSfile: CS_hlApi.c $
		   Description:
			   Purpose:

		Revision Level:	$Revision: #6 $
		 Check In Date:	$Date: 2006/11/25 $

		Last Revision:	$Log: CS_hlApi.c $
		Last Revision:	Revision 11.1300  2005/05/25 23:27:13  nto
		Last Revision:	Official Release 11.13
		Last Revision:	Revision 11.1201  2005/05/25 00:40:36  nto
		Last Revision:	Add cs_Diagnostic implementation.
		Last Revision:	Revision 11.1200  2005/01/15 18:27:12  nto
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
		Last Revision:	Revision 11.501  2003/08/22 21:12:56  nto
		Last Revision:	Official Release: 11.05
		Last Revision:	Revision 11.402  2003/08/22 20:54:41  nto
		Last Revision:	Added the new CS-csRangeEnum feature.
		Last Revision:	Revision 11.401  2003/05/01 23:06:22  nto
		Last Revision:	Revision 11.300  2003/02/25 04:29:17  nto
		Last Revision:	Official Release 11.03
		Last Revision:	Revision 11.101  2003/02/15 01:28:42  nto
		Last Revision:	Added two functions for production of diagnostic displays.
		Last Revision:	Revision 11.100  2002/11/22 19:38:44  nto
		Last Revision:	Official release: 11.01
		Last Revision:	Revision 10.1501  2002/10/23 22:52:49  nto
		Last Revision:	Redid the way the check argument feature is coded; to facilitate Windows CE which does not support IsBadWritePtr (et al).
		Last Revision:	Revision 10.1500  2002/09/22 00:01:20  nto
		Last Revision:	Official Release:= 10.15
		Last Revision:	Revision 10.1401  2002/09/15 21:18:38  nto
		Last Revision:	Added resource recovery for OSTN02.
		Last Revision:	Revision 10.1400  2002/08/09 18:14:23  nto
		Last Revision:	Revision 10.1200  2002/07/14 03:26:17  nto
		Last Revision:	Revision 10.1100  2002/06/13 14:18:38  nto
		Last Revision:	Release 10.11 Official
		Last Revision:	Revision 10.1000  2002/02/23 21:18:27  nto
		Last Revision:	Official Release of 10.10, 2/22/02 - Norm Olsen
		Last Revision:	Revision 10.901  2002/02/19 05:34:05  nto
		Last Revision:	Added the OSTN97 object to the CS_recvr function.
		Last Revision:	Revision 10.900  2001/09/24 04:31:11  nto
		Last Revision:	Revision 10.701  2001/04/16 03:26:03  nto
		Last Revision:	Fixed a problem where the status was not demo when it should have been.
		Last Revision:	Revision 10.700  2001/01/25 04:13:49  nto
		Last Revision:	Revision 10.600  2000/12/11 06:39:44  nto
		Last Revision:	Release 10.06
		Last Revision:	Revision 10.501  2000/12/11 05:25:37  nto
		Last Revision:	Fixed a bug that only shows up when a datum initialization fails.
		Last Revision:	Revision 10.500  2000/10/27 07:38:21  nto
		Last Revision:	Official Release 10.05
		Last Revision:	Revision 10.401  2000/10/27 03:41:17  nto
		Last Revision:	Added the datum fallback feature to all datums which
		Last Revision:	rely on grid data files
		Last Revision:	Revision 10.400  2000/09/13 01:16:55  nto
		Last Revision:	Release 10.04
		Last Revision:	Revision 10.300  2000/04/04 23:18:26  nto
		Last Revision:	Revision 10.200  2000/03/02 18:51:18  nto
		Last Revision:	Revision 10.2  2000/01/30 23:45:48  nto
		Last Revision:	PCLint clean up.
		Last Revision:	Revision 10.1  1999/11/03 23:41:06  nto
		Last Revision:	Results of datum conversion rewrite.
		Last Revision:	Revision 10.0  1999/10/05 18:27:15  nto
		Last Revision:	Revision 9.99  1999/10/05 17:36:26  nto
		Last Revision:	Revision 1.2  1999/09/06 18:27:12  nto
		Last Revision:	This revision compiles, links, and generates a successful test program.

******************************************************************************/

#ifdef LABEL_MODULE
static char revlvl [] = {"$Id: //depot/Libraries/CsMap/current/src/CS_hlApi.c#6 $"};
#endif

#include "cs_map.h"



void EXP_LVL1 CS_fast (int mode)
{
	extern int cs_Safe;

	cs_Safe = (mode == 0);
	return;
}

/**********************************************************************
**	st = CS_cnvrt (src_cs,dst_cs,coord);
**	alpha = CS_cnvrg (cs_nam,ll);
**	kk = CS_scale (cs_nam,ll);
**	kk = CS_scalk (cs_nam,ll);
**	hh = CS_scalh (cs_nam,ll);
**
**	char *src_cs;				name of the source coordinate system.
**	char *dst_cs;				name of the destination coordinate system.
**	char *cs_nam;				name of the subject coordinate system.
**	double coord [3];			an array of double in which the coordinate
**			to be converted is supplied, and the
**			converted result is returned.
**	double ll [2];				latitude and longitude of the location at which
**			the convergence or grid scale is to be
**			determined.
**	double alpha;				the convergence angle in degrees east of north.
**	double kk;					the grid scale factor along a parallel.
**	double hh;					the grid scale factor along a meridian.
**
**	The functions in this module rely on a cache of
**	previously initialized coordinate system definitions and
**	datum conversions.  These caches are searched for each
**	conversion.
**********************************************************************/

int EXP_LVL1 CS_cnvrt (Const char *src_cs,Const char *dst_cs,double coord [3])

{
	extern int cs_Error;
	extern csFILE* csDiagnostic;

	static char modl_name [] = "CS_cnvrt";

	struct cs_Csprm_ *src_ptr;
	struct cs_Csprm_ *dst_ptr;
	struct cs_Dtcprm_ *dtc_ptr;

	int st;
	int status;
	int dt_st;

	double my_ll [3];

	status = 0;


	/* Get a pointer to the two coordinate systems involved. */
if (csDiagnostic != 0) fprintf (csDiagnostic,"%s[%d] %s->%s\n",modl_name,__LINE__,src_cs,dst_cs);
	src_ptr = CSbcclu (src_cs);
	if (src_ptr == NULL) goto error;
	dst_ptr = CSbcclu (dst_cs);
	if (dst_ptr == NULL) goto error;
if (csDiagnostic != 0) fprintf (csDiagnostic,"%s[%d] %p & %p\n",modl_name,__LINE__,src_ptr,dst_ptr);

	/* Get a pointer to the datum conversion required. */
	dtc_ptr = CSbdclu (src_ptr,dst_ptr,cs_DTCFLG_DAT_F,cs_DTCFLG_BLK_W);
	if (dtc_ptr == NULL) goto error;
if (csDiagnostic != 0) fprintf (csDiagnostic,"%s[%d] %p\n",modl_name,__LINE__,dtc_ptr);

	/* Convert the coordinate and return the result to the
	   user. */
	st = CS_cs2ll (src_ptr,my_ll,coord);
if (csDiagnostic != 0) fprintf (csDiagnostic,"%s[%d] %d\n",modl_name,__LINE__,st);
	if (st != cs_CNVRT_NRML)
	{
		status |= cs_BASIC_SRCRNG;
	}
	dt_st = CS_dtcvt (dtc_ptr,my_ll,my_ll);
if (csDiagnostic != 0) fprintf (csDiagnostic,"%s[%d] %d\n",modl_name,__LINE__,dt_st);
	if (dt_st != 0)
	{
		if (dt_st < 0) goto error;
		status |= cs_BASIC_DTCWRN;
	}
	st = CS_ll2cs (dst_ptr,coord,my_ll);
if (csDiagnostic != 0) fprintf (csDiagnostic,"%s[%d] %d\n",modl_name,__LINE__,st);
	if (st != cs_CNVRT_NRML)
	{
		status |= cs_BASIC_DSTRNG;
	}

	/* That's it. */
if (csDiagnostic != 0) fprintf (csDiagnostic,"%s[%d] %d\n",modl_name,__LINE__,status);
	return (status);

error:
	return (-cs_Error);
}

/**********************************************************************
**	st = CS_cnvrt3D (src_cs,dst_cs,coord);
**
**	char *src_cs;				name of the source coordinate system.
**	char *dst_cs;				name of the destination coordinate system.
**	double coord [3];			an array of double in which the coordinate
**			to be converted is supplied, and the
**			converted result is returned.
**
**	The functions in this module rely on a cache of previously
**	initialized coordinate system definitions and datum conversions.
**	These caches are searched for each conversion.
**********************************************************************/
int EXP_LVL1 CS_cnvrt3D (Const char *src_cs,Const char *dst_cs,double coord [3])
{
	extern int cs_Error;
	extern csFILE* csDiagnostic;

	static char modl_name [] = "CS_cnvrt3D";

	struct cs_Csprm_ *src_ptr;
	struct cs_Csprm_ *dst_ptr;
	struct cs_Dtcprm_ *dtc_ptr;

	int st;
	int status;
	int dt_st;

	double my_ll [3];

	status = 0;


	/* Get a pointer to the two coordinate systems involved. */
if (csDiagnostic != 0) fprintf (csDiagnostic,"%s[%d] %s->%s\n",modl_name,__LINE__,src_cs,dst_cs);
	src_ptr = CSbcclu (src_cs);
	if (src_ptr == NULL) goto error;
	dst_ptr = CSbcclu (dst_cs);
	if (dst_ptr == NULL) goto error;
if (csDiagnostic != 0) fprintf (csDiagnostic,"%s[%d] %p & %p\n",modl_name,__LINE__,src_ptr,dst_ptr);

	/* Get a pointer to the datum conversion required. */
	dtc_ptr = CSbdclu (src_ptr,dst_ptr,cs_DTCFLG_DAT_F,cs_DTCFLG_BLK_W);
if (csDiagnostic != 0) fprintf (csDiagnostic,"%s[%d] %p\n",modl_name,__LINE__,dtc_ptr);
	if (dtc_ptr == NULL) goto error;

	/* Convert the coordinate and return the result to the user. */
	st = CS_cs3ll (src_ptr,my_ll,coord);
if (csDiagnostic != 0) fprintf (csDiagnostic,"%s[%d] %d\n",modl_name,__LINE__,st);
	if (st != cs_CNVRT_NRML)
	{
		status |= cs_BASIC_SRCRNG;
	}
	dt_st = CS_dtcvt3D (dtc_ptr,my_ll,my_ll);
if (csDiagnostic != 0) fprintf (csDiagnostic,"%s[%d] %d\n",modl_name,__LINE__,dt_st);
	if (dt_st != 0)
	{
		if (dt_st < 0) goto error;
		status |= cs_BASIC_DTCWRN;
	}
	st = CS_ll3cs (dst_ptr,coord,my_ll);
if (csDiagnostic != 0) fprintf (csDiagnostic,"%s[%d] %d\n",modl_name,__LINE__,st);
	if (st != cs_CNVRT_NRML)
	{
		status |= cs_BASIC_DSTRNG;
	}

	/* That's it. */
if (csDiagnostic != 0) fprintf (csDiagnostic,"%s[%d] %d\n",modl_name,__LINE__,status);
	return (status);

error:
	return (-cs_Error);
}

/**********************************************************************
	The following function maintains the coordinate system
	cache.  This is nothing more than a linked list of
	coordinate system names and pointers.  If the name is
	on the list, the pointer is returned.  If the name
	is not on the list, a new list entry is created and
	the coordinate system definition is fetched.

	The doubly linked list nature of this list is used
	to always maintain the last referenced coordinate
	system at the top of the list.  The least recently
	accessed coordinate system is always at the bottom
	of the list.  Thus, search time is kept to a
	minimum.

	The list is of a fixed size, to prevent all of memory
	from being hogged by coordinate system definitions.
	You may change the size of the list from the
	default value of 8 by setting the global variable
	csCscachI to a different value before calling
	CScnvrt for the first time. 2 is the minimum
	acceptable value for this variable.
**********************************************************************/

struct cs_Csprm_ * EXP_LVL9 CSbcclu (Const char *cs_name)
{
	extern csThread struct csCscach_ *csCscachP;
	extern csThread int csCscachI;

	cs_Register struct csCscach_ *ch_ptr;

	int ii;

	struct csCscach_ *tmp_ptr;
	struct csCscach_ *last_chp;
	struct cs_Csprm_ *cs_ptr;

	char kyTemp [cs_KEYNM_DEF + 2];

	CS_stncp (kyTemp,cs_name,sizeof (kyTemp));
	if (CS_nampp (kyTemp) != 0) return ((struct cs_Csprm_ *)0);

	if (csCscachP == NULL)
	{
		/* Here to allocate the cache. */

		if (csCscachI <= 1) csCscachI = 2;
		last_chp = NULL;
		for (ii = 0;ii < csCscachI;ii++)
		{
			ch_ptr = (struct csCscach_ *)CS_malc (sizeof (struct csCscach_));
			if (ch_ptr == NULL)
			{
				CS_erpt (cs_NO_MEM);
				ch_ptr = csCscachP;
				while (ch_ptr != NULL)
				{
					tmp_ptr = ch_ptr->next;
					CS_free (ch_ptr);
					ch_ptr = tmp_ptr;
				}
				csCscachP = NULL;
				goto error;
			}
			if (ii == 0)
			{
				csCscachP = ch_ptr;
			}
			else
			{
				last_chp->next = ch_ptr;		/*lint !e613 */
			}
			ch_ptr->prev = last_chp;
			ch_ptr->next = NULL;
			ch_ptr->cs_ptr = NULL;
			ch_ptr->cs_nam [0] = '\0';
			last_chp = ch_ptr;
		}
	}

	/* At this point, we have a cache.  It may be empty, but
	   it exists and has more than one entry. */

	cs_ptr = NULL;
	ch_ptr = csCscachP;
	last_chp = NULL;
	while (ch_ptr != NULL)
	{
		if (ch_ptr->cs_ptr == NULL) break;
		if (!CS_stricmp (ch_ptr->cs_nam,kyTemp))
		{
			cs_ptr = ch_ptr->cs_ptr;
			break;
		}

		last_chp = ch_ptr;
		ch_ptr = ch_ptr->next;
	}

	/* If cs_ptr is NULL, we havn't found the one we are looking
	   for.  We must add it to the cache. */

	if (cs_ptr == NULL)
	{
		/* If ch_ptr is not NULL, it must point to the
		   first element in the linked list which is
		   unused.  We simply use this entry. */

		if (ch_ptr != NULL)
		{
			ch_ptr->cs_ptr = CS_csloc (kyTemp);
			if (ch_ptr->cs_ptr == NULL)
			{
				goto error;
			}
			(void)CS_stncp (ch_ptr->cs_nam,kyTemp,sizeof (ch_ptr->cs_nam));
			cs_ptr = ch_ptr->cs_ptr;
		}
		else
		{
			/* We need to reuse an existing entry.  We always
			   reuse that the last entry in the linked list
			   as it should be the least recently accessed
			   entry in the list. */

			ch_ptr = last_chp;
			CS_free (ch_ptr->cs_ptr);
			ch_ptr->cs_nam [0] = '\0';
			ch_ptr->cs_ptr = CS_csloc (kyTemp);
			(void)CS_stncp (ch_ptr->cs_nam,kyTemp,sizeof (ch_ptr->cs_nam));
			cs_ptr = ch_ptr->cs_ptr;
		}
	}

	/* OK, we should now have a coordinate system pointer.  All we
	   need to do is make this one first on the list as an indication
	   that it was the most recently accessed.  Of course, if it
	   is already the first on the list, we do not need to do
	   anything.  The following code assumes that the entry being
	   processed is not the first on the list (i.e. ch_ptr->prev
	   is not NULL). */

	if (ch_ptr != csCscachP)
	{
		/* Remove the current entry from the list. */

		ch_ptr->prev->next = ch_ptr->next;				/*lint !e613 */
		if (ch_ptr->next != NULL)						/*lint !e613 */
		{
			ch_ptr->next->prev = ch_ptr->prev;			/*lint !e613 */
		}

		/* Now we insert it at the top of the list. */

		ch_ptr->prev = NULL;							/*lint !e613 */
		ch_ptr->next = csCscachP;						/*lint !e613 */
		csCscachP->prev = ch_ptr;
		csCscachP = ch_ptr;
	}

	/* Return a pointer to the located coordinate system. */

	return (cs_ptr);

error:
	return ((struct cs_Csprm_ *)0);
}
/**********************************************************************
  The following function returns a list of the coordinate systems
  in the cache.
**********************************************************************/
void EXP_LVL1 CSbccDbg (char *results,int rsltSz)
{
	extern csThread struct csCscach_ *csCscachP;

	int need;
	char *cp;
	char *rsltPtr = results;
	cs_Register struct csCscach_ *ch_ptr;
	char myName [32];

	*results = '\0';
	if (csCscachP == NULL)
	{
		CS_stncp (results,"<none>",rsltSz);
	}
	else
	{
		rsltSz -= 1;
		for (ch_ptr = csCscachP;ch_ptr != NULL;ch_ptr = ch_ptr->next)
		{
			if (rsltSz > 0)
			{
				cp = myName;
				if (*results != '\0') *cp++ = ',';

				if (ch_ptr->cs_nam [0] == '\0')
				{
					cp = CS_stcpy (cp,"<none>");
				}
				else if (ch_ptr->cs_ptr != NULL)
				{
					cp = CS_stncp (cp,ch_ptr->cs_nam,sizeof (myName) - 1);
				}
				else
				{
					cp = CS_stcpy (cp,"<none>");
				}
				need = (int)strlen (myName);
				if (need > rsltSz) need = rsltSz;
				rsltPtr = CS_stncp (rsltPtr,myName,need + 1);
				rsltSz -= need;
			}
		}
	}
	return;
}
/**********************************************************************
	The following function caches datum conversions.

	This is the same as above, except two names are
	involved, and the name of the global variable is
	csDtcachI.
**********************************************************************/

struct cs_Dtcprm_ * EXP_LVL9 CSbdclu (	Const struct cs_Csprm_ *src_cs,
										Const struct cs_Csprm_ *dst_cs,
										int dat_err,
										int blk_err)
{
	extern csThread struct csDtcach_ *csDtcachP;
	extern csThread int csDtcachI;

	unsigned short srcPrjCode;
	unsigned short dstPrjCode;
	int ii;
	

	struct cs_Dtcprm_ *dtc_ptr;
	struct csDtcach_ *ch_ptr;
	struct csDtcach_ *tmp_ptr;
	struct csDtcach_ *last_chp;

	/* Make sure we're not converting between non-georeferenced and georeferenced. */
	srcPrjCode = src_cs->prj_code;
	dstPrjCode = dst_cs->prj_code;

	if (srcPrjCode == cs_PRJCOD_NRTHSRT) srcPrjCode = cs_PRJCOD_NERTH;
	if (dstPrjCode == cs_PRJCOD_NRTHSRT) dstPrjCode = cs_PRJCOD_NERTH;
	
	if ((srcPrjCode == cs_PRJCOD_NERTH) ^ (dstPrjCode == cs_PRJCOD_NERTH))	/*lint !e514 */
	{
		CS_erpt (cs_NOT_NERTH);
		goto error;
	}

	/* If we have not done so already, allocate the cache now. */
	if (csDtcachP == NULL)
	{
		if (csDtcachI <= 1) csDtcachI = 2;
		last_chp = NULL;
		for (ii = 0;ii < csDtcachI;ii++)
		{
			ch_ptr = (struct csDtcach_ *)CS_malc (sizeof (struct csDtcach_));
			if (ch_ptr == NULL)
			{
				CS_erpt (cs_NO_MEM);
				ch_ptr = csDtcachP;
				while (ch_ptr != NULL)
				{
					tmp_ptr = ch_ptr->next;
					CS_free (ch_ptr);
					ch_ptr = tmp_ptr;
				}
				csDtcachP = NULL;
				goto error;
			}
			if (ii == 0)
			{
				csDtcachP = ch_ptr;
			}
			else
			{
				last_chp->next = ch_ptr;				/*lint !e613 */
			}
			ch_ptr->prev = last_chp;
			ch_ptr->next = NULL;
			ch_ptr->dtc_ptr = NULL;
			last_chp = ch_ptr;
		}
	}

	/* Search the existing cache entries for the desired
	   datum combination.  While doing so, we maintain
	   last_chp as a pointer to the last cache entry
	   examined.  We will use this to add a new entry to
	   the cache if we don't find the one we are looking for. */

	dtc_ptr = NULL;
	ch_ptr = csDtcachP;
	last_chp = NULL;
	while (ch_ptr != NULL)
	{
		if (ch_ptr->dtc_ptr == NULL) break;
		if (!CS_stricmp (ch_ptr->dtc_ptr->srcKeyName,src_cs->csdef.dat_knm) &&
		    !CS_stricmp (ch_ptr->dtc_ptr->trgKeyName,dst_cs->csdef.dat_knm))
		{
			dtc_ptr = ch_ptr->dtc_ptr;
			break;
		}
		last_chp = ch_ptr;
		ch_ptr = ch_ptr->next;
	}

	if (dtc_ptr == NULL)
	{
		/* Didn't find one. */
		if (ch_ptr != NULL)
		{
			/* ch_ptr is pointing to an unused entry. */
			dtc_ptr = CS_dtcsu (src_cs,dst_cs,dat_err,blk_err);
			if (dtc_ptr == NULL) goto error;
			ch_ptr->dtc_ptr = dtc_ptr;
		}
		else
		{
			/* All entries in the cache are used. Last_chp
			   points to the last entry in the cache, which is
			   also the least recently used entry. */
			ch_ptr = last_chp;
			CS_dtcls (ch_ptr->dtc_ptr);
			dtc_ptr = ch_ptr->dtc_ptr = CS_dtcsu (src_cs,dst_cs,dat_err,blk_err);
			if (dtc_ptr == NULL) goto error;
		}
	}
	else
	{
		dtc_ptr->block_err = (short)blk_err;
	}

	if (ch_ptr != csDtcachP)
	{
		/* Push this cache entry to the top of the list. */
		ch_ptr->prev->next = ch_ptr->next;			/*lint !e613 */
		if (ch_ptr->next != NULL)					/*lint !e613 */
		{
			ch_ptr->next->prev = ch_ptr->prev;		/*lint !e613 */
		}
		ch_ptr->prev = NULL;						/*lint !e613 */
		ch_ptr->next = csDtcachP;					/*lint !e613 */
		csDtcachP->prev = ch_ptr;
		csDtcachP = ch_ptr;
	}
	return (dtc_ptr);

error:
	return (NULL);
}
/**********************************************************************
  The following function returns a list of the coordinate systems
  in the cache.
**********************************************************************/
void EXP_LVL1 CSbdcDbg (char *results,int rsltSz)
{
	extern csThread struct csDtcach_ *csDtcachP;

	int need;
	char *cp;
	char *rsltPtr = results;
	cs_Register struct csDtcach_ *ch_ptr;
	char myName [64];

	*results = '\0';
	if (csDtcachP == NULL)
	{
		CS_stncp (results,"<none>",rsltSz);
	}
	else
	{
		rsltSz -= 1;
		for (ch_ptr = csDtcachP;ch_ptr != NULL;ch_ptr = ch_ptr->next)
		{
			if (rsltSz > 0)
			{
				cp = myName;
				if (*results != '\0') *cp++ = ';';
				if (ch_ptr->dtc_ptr == NULL)
				{
					cp = CS_stcpy (cp,"<none>");
				}
				else
				{
					*cp++ = '<';
					cp = CS_stncp (cp,ch_ptr->dtc_ptr->srcKeyName,28);
					*cp++ = ':';
					*cp++ = ':';
					cp = CS_stncp (cp,ch_ptr->dtc_ptr->trgKeyName,28);
					*cp++ = '>';
					*cp = '\0';
				}
				need = (int)strlen (myName);
				if (need > rsltSz) need = rsltSz;
				rsltPtr = CS_stncp (rsltPtr,myName,need + 1);
				rsltSz -= need;
			}
		}
	}
	return;
}
/**********************************************************************
	The following functions complete the BASIC interface, providing
	access to the convergence, sacel, scaleK and scaleH functions
	providing a coordinate system name rather than a coordinate
	system definition pointer.
**********************************************************************/

double EXP_LVL1 CS_cnvrg (Const char *cs_nam,Const double ll [2])
{

	struct cs_Csprm_ *cs_ptr;

	double alpha;


	/* Perform the calculation. */

	cs_ptr = CSbcclu (cs_nam);
	if (cs_ptr != NULL) alpha = CS_cscnv (cs_ptr,ll);
	else		    alpha = -360.0;
	return (alpha);
}

double EXP_LVL1 CS_scale (Const char *cs_nam,double ll [2])
{
	extern double cs_Mone;		/* -1.0 */
	
	struct cs_Csprm_ *cs_ptr;

	double kk;

	cs_ptr = CSbcclu (cs_nam);
	if (cs_ptr != NULL) kk = CS_csscl (cs_ptr,ll);
	else				kk = cs_Mone;
	return (kk);
}

double EXP_LVL1 CS_scalk (Const char *cs_nam,double ll [2])
{
	extern double cs_Mone;		/* -1.0 */

	struct cs_Csprm_ *cs_ptr;

	double kk;

	cs_ptr = CSbcclu (cs_nam);
	if (cs_ptr != NULL) kk = CS_cssck (cs_ptr,ll);
	else		    kk = cs_Mone;
	return (kk);
}

double EXP_LVL1 CS_scalh (Const char *cs_nam,double ll [2])
{
	extern double cs_Mone;		/* -1.0 */
	
	struct cs_Csprm_ *cs_ptr;

	double hh;

	cs_ptr = CSbcclu (cs_nam);
	if (cs_ptr != NULL) hh = CS_cssch (cs_ptr,ll);
	else		    hh = cs_Mone;
	return (hh);
}

/**********************************************************************
	The following function releases all resources acquired by the
	functions defined in this module.
**********************************************************************/

void EXP_LVL1 CS_recvr (void)
{
	extern csThread struct cs_Ostn97_ *cs_Ostn97Ptr;
	extern csThread struct cs_Ostn02_ *cs_Ostn02Ptr;

	extern csThread struct csCscach_ *csCscachP;
	extern csThread struct csDtcach_ *csDtcachP;

	extern csThread char *cs_CsKeyNames;
	extern csThread char *cs_DtKeyNames;
	extern csThread char *cs_ElKeyNames;
	extern csThread char *cs_CsLlEnum;
	extern csThread struct cs_Csgrplst_ *cs_CsGrpList;
	extern csThread struct cs_Mgrs_ *cs_MgrsPtr;

	struct csDtcach_ *dtch_ptr;
	struct csDtcach_ *dtch_tmp;

	struct csCscach_ *csch_ptr;
	struct csCscach_ *csch_tmp;

	/* Kludge time.  Delete any cs_Ostn97_ object which may currently exist. */
	if (cs_Ostn97Ptr != NULL)
	{
		CSdeleteOstn97 (cs_Ostn97Ptr);
		cs_Ostn97Ptr = NULL;
	}
	if (cs_Ostn02Ptr != NULL)
	{
		CSdeleteOstn02 (cs_Ostn02Ptr);
		cs_Ostn02Ptr = NULL;
	}

	/* Loop through the datum conversion cache. */

	dtch_ptr = csDtcachP;
	while (dtch_ptr != NULL)
	{
		/* If this entry has a datum conversion, close it. */

		if (dtch_ptr->dtc_ptr != NULL)
		{
			CS_dtcls (dtch_ptr->dtc_ptr);
			dtch_ptr->dtc_ptr = NULL;
		}

		/* Unlink this entry from the list.  We try to keep the list
		   intact in case of an error. */

		dtch_tmp = dtch_ptr;
		dtch_ptr = dtch_ptr->next;
		csDtcachP = dtch_ptr;
		if (dtch_ptr != NULL)
		{
			dtch_ptr->prev = NULL;
		}

		/* Free the cache entry. */

		CS_free (dtch_tmp);
	}

	/* Same with the coordinate systems. */

	csch_ptr = csCscachP;
	while (csch_ptr != NULL)
	{
		if (csch_ptr->cs_ptr != NULL)
		{
			CS_free (csch_ptr->cs_ptr);
			csch_ptr->cs_ptr = NULL;
		}
		csch_tmp = csch_ptr;
		csch_ptr = csch_ptr->next;
		csCscachP = csch_ptr;
		if (csch_ptr != NULL)
		{
			csch_ptr->prev = NULL;
		}
		CS_free (csch_tmp);
	}

	/* Free up any name lists which may be present. */

	if (cs_CsKeyNames != NULL)
	{
		CS_free (cs_CsKeyNames);
		cs_CsKeyNames = NULL;
	}
	if (cs_DtKeyNames != NULL)
	{
		CS_free (cs_DtKeyNames);
		cs_DtKeyNames = NULL;
	}
	if (cs_ElKeyNames != NULL)
	{
		CS_free (cs_ElKeyNames);
		cs_ElKeyNames = NULL;
	}
	if (cs_CsLlEnum != NULL)
	{
		CS_free (cs_CsLlEnum);
		cs_CsLlEnum = NULL;
	}
	if (cs_CsGrpList != NULL)
	{
		CS_csgrpf (cs_CsGrpList);
		cs_CsGrpList = NULL;
	};

	/* Do the high level MGRS stuff. */
	if (cs_MgrsPtr != NULL)
	{
		CS_free (cs_MgrsPtr);
		cs_MgrsPtr = NULL;
	}

	return;
}

/**********************************************************************
	The following function releases all resources acquired by the
	functions defined in this module.
**********************************************************************/
int EXP_LVL1 CS_mgrsSetUp (const char* ellipsoid,short bessel)
{
	extern struct cs_Mgrs_ *cs_MgrsPtr;


	if (cs_MgrsPtr != NULL)
	{
		CS_free (cs_MgrsPtr);
		cs_MgrsPtr = NULL;
	}


	cs_MgrsPtr = CSnewMgrsE (ellipsoid,bessel);
	return (cs_MgrsPtr == NULL) ? -1 : 0;
}
int EXP_LVL1 CS_mgrsFromLl (char* result,double latLng [2],int prec)
{
	extern struct cs_Mgrs_ *cs_MgrsPtr;

	int size;
	int status;

	size = 6 + prec + prec;


	if (cs_MgrsPtr == NULL)
	{
		CS_erpt (cs_MGRS_NOSET);
		status = -1;
	}
	else
	{
		size = 6 + prec + prec;
		status = CScalcMgrsFromLl (cs_MgrsPtr,result,size,latLng,prec);
	}
	return status;
}
int EXP_LVL1 CS_llFromMgrs (double latLng [2],const char* mgrsString)
{
	extern struct cs_Mgrs_ *cs_MgrsPtr;


	int status;


	if (cs_MgrsPtr == NULL)
	{
		CS_erpt (cs_MGRS_NOSET);
		status = -1;
	}
	else
	{
		status = CScalcLlFromMgrs (cs_MgrsPtr,latLng,mgrsString);
	}
	return status;
}
int EXP_LVL1 CS_geoctrSetUp (const char* ellipsoid)
{
	extern double csGeoCtrErad;
	extern double csGeoCtrEsq;
	extern double cs_Zero;


	int status;	
	struct cs_Eldef_ *elPtr;


	elPtr = CS_eldef (ellipsoid);
	if (elPtr != NULL)
	{
		csGeoCtrErad = elPtr->e_rad;
		csGeoCtrEsq  = elPtr->ecent * elPtr->ecent;
		status = 0;
	}
	else
	{
		csGeoCtrErad = cs_Zero;
		csGeoCtrEsq  = cs_Zero;
		status = -1;
	}
	return status;
}
int EXP_LVL1 CS_geoctrGetXyz (double xyz [3],double llh [3])
{
	extern double csGeoCtrErad;
	extern double csGeoCtrEsq;
	

	CS_llhToXyz (xyz,llh,csGeoCtrErad,csGeoCtrEsq);
	return 0;
}
int EXP_LVL1 CS_geoctrGetLlh (double llh [3],double xyz [3])
{
	extern double csGeoCtrErad;
	extern double csGeoCtrEsq;


	return CS_xyzToLlh (llh,xyz,csGeoCtrErad,csGeoCtrEsq);
}

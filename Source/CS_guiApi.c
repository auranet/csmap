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

			 File Name: $RCSfile: CS_guiApi.c $
		   Description:
			   Purpose:

		Revision Level:	$Revision: #7 $
		 Check In Date:	$Date: 2007/01/12 $

		Last Revision:	$Log: CS_guiApi.c $
		Last Revision:	Revision 11.1300  2005/05/25 23:27:13  nto
		Last Revision:	Official Release 11.13
		Last Revision:	Revision 11.1201  2005/05/25 23:15:47  nto
		Last Revision:	Added fill-in for the Kruger Formulation variety.
		Last Revision:	Revision 11.1200  2005/01/15 18:27:12  nto
		Last Revision:	Official Release of CS-MAP 11.12, 11:26am 15 Jan 2005
		Last Revision:	Revision 11.1100  2004/11/01 18:53:10  nto
		Last Revision:	Official release 11.11
		Last Revision:	Revision 11.1001  2004/10/07 19:25:18  nto
		Last Revision:	Revision 11.901  2004/08/07 20:53:47  nto
		Last Revision:	Added the dictionary deferred close feature.
		Last Revision:	Revision 11.900  2004/03/26 17:02:25  nto
		Last Revision:	Official release: 11.09 - 3/25/2003
		Last Revision:	Revision 11.800  2004/01/13 23:29:14  nto
		Last Revision:	Revision 11.700  2003/12/19 01:49:54  nto
		Last Revision:	Official release 11.07
		Last Revision:	Revision 11.600  2003/12/04 02:46:28  nto
		Last Revision:	Release 11.06.  Never shipped. Source captured in prep for C++ V7.
		Last Revision:	Revision 11.501  2003/08/22 21:12:56  nto
		Last Revision:	Official Release: 11.05
		Last Revision:	Revision 11.402  2003/08/22 20:54:38  nto
		Last Revision:	Added the new CS-csRangeEnum feature.
		Last Revision:	Revision 11.401  2003/05/01 23:06:22  nto
		Last Revision:	Revision 11.301  2003/04/04 00:38:59  nto
		Last Revision:	Fixed the parameter check on the third parameter to CS_csEnumByGroup.
		Last Revision:	Revision 11.300  2003/02/25 04:29:17  nto
		Last Revision:	Official Release 11.03
		Last Revision:	Revision 11.100  2002/11/22 19:38:44  nto
		Last Revision:	Official release: 11.01
		Last Revision:	Revision 10.1503  2002/10/23 22:52:49  nto
		Last Revision:	Redid the way the check argument feature is coded; to facilitate Windows CE which does not support IsBadWritePtr (et al).
		Last Revision:	Revision 10.1502  2002/10/06 18:07:03  nto
		Last Revision:	Converted all direct references to 'access' to CS_access.
		Last Revision:	Revision 10.1501  2002/10/03 00:00:09  nto
		Last Revision:	Removed UNIX I/O in favor of ANSI stream I/O.
		Last Revision:	Revision 10.1500  2002/09/22 00:01:20  nto
		Last Revision:	Official Release:= 10.15
		Last Revision:	Revision 10.1403  2002/09/21 23:18:51  nto
		Last Revision:	Updated the "FillIn" function for OSTN02 and SYSTM34-99.
		Last Revision:	Revision 10.1402  2002/09/20 04:26:45  nto
		Last Revision:	Added two new datum shift tecnniques to the technique enumerator.
		Last Revision:	Revision 10.1401  2002/09/15 21:17:50  nto
		Last Revision:	Added Plural Unit name and Unit system enumerator functions.
		Last Revision:	Revision 10.1400  2002/08/09 18:14:23  nto
		Last Revision:	Revision 10.1200  2002/07/14 03:26:17  nto
		Last Revision:	Revision 10.1100  2002/06/13 14:18:38  nto
		Last Revision:	Release 10.11 Official
		Last Revision:	Revision 10.1001  2002/06/13 13:33:21  nto
		Last Revision:	Added RGF93.
		Last Revision:	Revision 10.1000  2002/02/23 21:18:27  nto
		Last Revision:	Official Release of 10.10, 2/22/02 - Norm Olsen
		Last Revision:	Revision 10.902  2002/02/19 05:33:23  nto
		Last Revision:	Various accomodations for JGD2K datum and the OSTN97, SYSTEM34, and Oblique Cylindrical projections.
		Last Revision:	Revision 10.901  2002/01/30 00:57:07  nto
		Last Revision:	Added the CS_getElValues function.
		Last Revision:	Revision 10.900  2001/09/24 04:31:11  nto
		Last Revision:	Revision 10.702  2001/09/18 19:23:01  nto
		Last Revision:	Added the coordinate system hook function to the CS_csIsValid logic.
		Last Revision:	Also for CS_dtIsValid and CS_elIsValid.
		Last Revision:	Revision 10.701  2001/04/16 03:25:04  nto
		Last Revision:	Added new functions for geting units, datum, etc for a specified 
		Last Revision:	coordinate system.  Useful for GUI type stuff.
		Last Revision:	Revision 10.700  2001/01/25 04:13:49  nto
		Last Revision:	Revision 10.600  2000/12/11 06:39:43  nto
		Last Revision:	Release 10.06
		Last Revision:	Revision 10.500  2000/10/27 07:38:21  nto
		Last Revision:	Official Release 10.05
		Last Revision:	Revision 10.400  2000/09/13 01:16:55  nto
		Last Revision:	Release 10.04
		Last Revision:	Revision 10.301  2000/09/12 20:40:53  nto
		Last Revision:	Adjusted the to84Via enumerator to include proper labels for CSRS and ATS77.
		Last Revision:	Revision 10.300  2000/04/04 23:18:26  nto
		Last Revision:	Revision 10.201  2000/04/03 21:40:30  nto
		Last Revision:	Added the NZGD2000, ATS77, & CSRS methods to the datum conversion file.
		Last Revision:	Revision 10.200  2000/03/02 18:51:18  nto
		Last Revision:	Revision 10.4  2000/02/11 06:09:15  nto
		Last Revision:	Added the datum conversion techniques: AGD66, AGD84, NZGD49, etc.
		Last Revision:	Revision 10.3  2000/01/30 23:45:09  nto
		Last Revision:	PCLint clean up.  Added some 3D datum conversion support.
		Last Revision:	Revision 10.2  1999/11/03 23:41:05  nto
		Last Revision:	Results of datum conversion rewrite.
		Last Revision:	Revision 10.1  1999/10/16 18:51:44  nto
		Last Revision:	Modifications suggested by Gimpel PC-Lint.  Note, the type of argument
		Last Revision:	2 to the CS_prjprm function was changed.
		Last Revision:	Revision 10.0  1999/10/05 18:27:14  nto
		Last Revision:	Revision 9.99  1999/10/05 17:36:26  nto
		Last Revision:	Revision 1.2  1999/09/12 02:07:20  nto
		Last Revision:	This revision compiles, links, and generates a successful test program.

******************************************************************************/

#ifdef LABEL_MODULE
static char revlvl [] = {"$Id: //depot/Libraries/CsMap/current/src/CS_guiApi.c#7 $"};
#endif

#include "cs_map.h"



extern int (*CS_usrCsDefPtr)(struct cs_Csdef_ *ptr,Const char *keyName);
extern int (*CS_usrDtDefPtr)(struct cs_Dtdef_ *ptr,Const char *keyName);
extern int (*CS_usrElDefPtr)(struct cs_Eldef_ *ptr,Const char *keyName);
extern double (*CS_usrUnitPtr)(short type,Const char *unitName);


int EXP_LVL1 CS_getcs (Const char *cs_name,struct cs_Csdef_ *bufr)
{
	extern int cs_Error;

	int status;

	struct cs_Csdef_ *cs_ptr;

	status = 0;
	cs_ptr = CS_csdef (cs_name);
	if (cs_ptr == NULL)
	{
		status = -cs_Error;
	}
	else
	{
		memcpy (bufr,cs_ptr,sizeof (struct cs_Csdef_));
		CS_free (cs_ptr);
	}
	return (status);
}

int EXP_LVL1 CS_getdt (	Const char *dt_name,
			struct cs_Dtdef_ *bufr)
{
	extern int cs_Error;

	int status;

	struct cs_Dtdef_ *dt_ptr;

	status = 0;
	dt_ptr = CS_dtdef (dt_name);
	if (dt_ptr == NULL)
	{
		status = -cs_Error;
	}
	else
	{
		memcpy (bufr,dt_ptr,sizeof (struct cs_Dtdef_));
		CS_free (dt_ptr);
	}
	return (status);
}

int EXP_LVL1 CS_getel (	Const char *el_name,
			struct cs_Eldef_ *bufr)
{
	extern int cs_Error;

	int status;

	struct cs_Eldef_ *el_ptr;

	status = 0;
	el_ptr = CS_eldef (el_name);
	if (el_ptr == NULL)
	{
		status = -cs_Error;
	}
	else
	{
		memcpy (bufr,el_ptr,sizeof (struct cs_Eldef_));
		CS_free (el_ptr);
	}
	return (status);
}

int EXP_LVL1 CS_getElValues (Const char *el_name,double *radius,double *e_Sq)
{
	extern int cs_Error;

	int status;

	struct cs_Eldef_ *el_ptr;

	status = 0;
	el_ptr = CS_eldef (el_name);
	if (el_ptr == NULL)
	{
		status = -cs_Error;
	}
	else
	{
		*radius = el_ptr->e_rad;
		*e_Sq = el_ptr->ecent * el_ptr->ecent;
		CS_free (el_ptr);
	}
	return (status);
}

int EXP_LVL1 CS_isgeo (Const char *cs_nam)
{
	extern int cs_Error;

	int rtn_val;

	struct cs_Csprm_ *cs_ptr;

	cs_ptr = CSbcclu (cs_nam);
	if (cs_ptr != NULL)
	{
		rtn_val = (cs_ptr->prj_flags & cs_PRJFLG_GEOGR) != 0;
	}
	else
	{
		rtn_val = -cs_Error;
	}
	return (rtn_val);
}

int EXP_LVL1 CS_putcs (	Const struct cs_Csdef_ *cs_def,int crypt)
{

	int status;

	__ALIGNMENT__1		/* Required by some Sun compilers. */
	struct cs_Csdef_ my_csdef;

	memcpy (&my_csdef,cs_def,sizeof (my_csdef));
	status = CS_csupd (&my_csdef,crypt);
	if (status >= 0) CS_recvr ();
	return (status);
}

int EXP_LVL1 CS_putdt (	Const struct cs_Dtdef_ *dt_def,int crypt)
{

	int status;

 	__ALIGNMENT__1		/* Required by some Sun compilers. */
	struct cs_Dtdef_ my_dtdef;

	memcpy (&my_dtdef,dt_def,sizeof (my_dtdef));
	status = CS_dtupd (&my_dtdef,crypt);
	if (status >= 0) CS_recvr ();
	return (status);
}

int EXP_LVL1 CS_putel (	Const struct cs_Eldef_ *el_def,int crypt)
{

	int status;

 	__ALIGNMENT__1		/* Required by some Sun compilers. */
	struct cs_Eldef_ my_eldef;


	memcpy (&my_eldef,el_def,sizeof (my_eldef));
	status = CS_elupd (&my_eldef,crypt);
	if (status >= 0) CS_recvr ();
	return (status);
}

int EXP_LVL1 CS_csEnum (int index,char *key_name,int size)
{
	extern int cs_Error;

	cs_Register char *cp;

	int ii;

	*key_name = '\0';

	if (index < 0)
	{
		CS_erpt (cs_INV_INDX);
		return (-1);
	}

	/* Get a pointer to the Coordinate System Names enumeration. */

	cp = CScsKeyNames ();
	if (cp == NULL) return (-cs_Error);

	/* Locate the index'th entry in the enumeration. */

	for (ii = 0;ii < index;ii++)
	{
		while (*cp++ != '\0');						/*lint !e722 */
		if (*cp == '\0') break;
	}

	/* Return the located result, even if it is the null string. */

	CS_stncp (key_name,cp,size);

	/* Return zero (FALSE) if index is past the end of the list,
	   otherwise return 1 (TRUE) */

	return (*cp != '\0');
}

int EXP_LVL1 CS_csIsValid (Const char *key_name)
{

	int st;
	char kyTemp [cs_KEYNM_DEF + 2];
	cs_Register char *cp;
	struct cs_Csdef_ csdef;

	/* Since we invented the "temporary definition hook functions", we must give
	   them first shot at the definition with the provided name. */
	if (CS_usrCsDefPtr != NULL)
	{
		st = (*CS_usrCsDefPtr)(&csdef,key_name);
		if (st < 0)
		{
			/* This value actually means some sort of error. */
			 return (-1);
		}
		if (st == 0)
		{
			/* This value means there is some sort of definition out there. */
			return 1;
		}

		/* Otherwise, we simply defer to the dictionary for the status of this
		   key name. */
	}

	/* Get a pointer to the Coordinate System Names enumeration. */

	cp = CScsKeyNames ();
	if (cp == NULL) return (-1);

	/* If the name we've been given is in the list. */

	CS_stncp (kyTemp,key_name,sizeof (kyTemp));
	if (CS_nampp (kyTemp) == 0)
	{
		while (*cp != '\0')
		{
			if (!CS_stricmp (kyTemp,cp)) return (1);
			while (*cp++ != '\0');						/*lint !e722 */
		}
	}

	/* Guess there was none; return something that looks like false. */
	return (0);
}

int EXP_LVL1 CS_dtEnum (int index,char *key_name,int size)
{
	extern int cs_Error;

	cs_Register char *cp;

	int ii;

	*key_name = '\0';

	if (index < 0)
	{
		CS_erpt (cs_INV_INDX);
		return (-cs_Error);
	}

	cp = CSdtKeyNames ();
	if (cp == NULL)	return (-1);
	for (ii = 0;ii < index;ii++)
	{
		while (*cp++ != '\0');						/*lint !e722 */
		if (*cp == '\0') break;
	}
	CS_stncp (key_name,cp,size);
	return (*cp != '\0');
}

int EXP_LVL1 CS_dtIsValid (Const char *key_name)
{
	extern int cs_Error;

	char kyTemp [cs_KEYNM_DEF + 2];
	cs_Register char *cp;

	cp = CSdtKeyNames ();
	if (cp == NULL) return (-cs_Error);
	CS_stncp (kyTemp,key_name,sizeof (kyTemp));
	if (CS_nampp (kyTemp) == 0)
	{
		while (*cp != '\0')
		{
			if (!CS_stricmp (kyTemp,cp)) return (1);
			while (*cp++ != '\0');						/*lint !e722 */
		}
	}
	return (0);
}

int EXP_LVL1 CS_elEnum (int index,char *key_name,int size)
{
	extern int cs_Error;

	cs_Register char *cp;

	int ii;

	*key_name = '\0';

	if (index < 0)
	{
		CS_erpt (cs_INV_INDX);
		return (-cs_Error);
	}

	cp = CSelKeyNames ();
	if (cp == NULL) return (-1);
	for (ii = 0;ii < index;ii++)
	{
		while (*cp++ != '\0');						/*lint !e722 */
		if (*cp == '\0') break;
	}
	CS_stncp (key_name,cp,size);
	return (*cp != '\0');
}

int EXP_LVL1 CS_elIsValid (Const char *key_name)
{
	extern int cs_Error;

	char kyTemp [cs_KEYNM_DEF + 2];
	cs_Register char *cp;

	cp = CSelKeyNames ();
	if (cp == NULL) return (-cs_Error);
	CS_stncp (kyTemp,key_name,sizeof (kyTemp));
	if (CS_nampp (kyTemp) == 0)
	{
		while (*cp != '\0')
		{
			if (!CS_stricmp (kyTemp,cp)) return (1);
			while (*cp++ != '\0');						/*lint !e722 */
		}
	}
	return (0);
}

int EXP_LVL1 CS_csEnumByGroup (int index,Const char *grp_name,struct cs_Csgrplst_ *cs_descr)
{
	extern int cs_Error;
	extern csThread struct cs_Csgrplst_ *cs_CsGrpList;

	static char cur_group [24] = "!!!";

	int ii;
	
	struct cs_Csgrplst_ *ptr;

	if (index < 0)
	{
		CS_erpt (cs_INV_INDX);
		return (-cs_Error);
	}

	if (cs_CsGrpList == NULL || CS_stricmp (grp_name,cur_group))
	{
		if (cs_CsGrpList != NULL)
		{
			CS_csgrpf (cs_CsGrpList);
			cs_CsGrpList = NULL;
		}
		CS_stncp (cur_group,grp_name,sizeof (cur_group));
		CS_csgrp (cur_group,&cs_CsGrpList);					/*lint !e534 */
	}
	if (cs_CsGrpList == NULL) return (-1);

	ptr = cs_CsGrpList;
	for (ii = 0;ii < index && ptr != NULL;ii++) ptr = ptr->next;
	if (ptr != NULL)
	{
		memcpy (cs_descr,ptr,sizeof (*cs_descr));
		cs_descr->next = NULL;
	}
	return (ptr != NULL);
}

int EXP_LVL1 CS_csGrpEnum (int index,char *grp_name,int name_sz,char *grp_dscr,int dscr_sz)
{
	extern int cs_Error;
	extern struct cs_Grptbl_ cs_CsGrptbl [];

	int ii;
	int my_idx;	/* Index into table of index'th active entry. */
	int count;	/* Number of active entries in the table. */

	if (index < 0)
	{
		CS_erpt (cs_INV_INDX);
		return (-cs_Error);
	}

	/* Count the active entries, capturing the table index of the
	   index'th active entry. */

	count = 0;
	my_idx = -1;
	for (ii = 0;(cs_CsGrptbl [ii].flags & cs_GRPTBL_END) == 0;ii += 1)
	{
		if ((cs_CsGrptbl [ii].flags & cs_GRPTBL_ACTIVE) == 0) continue;
		if (index == count) my_idx = ii;
		count += 1;
	}
	if (my_idx < 0) my_idx = ii;

	if (grp_name != NULL) CS_stncp (grp_name,cs_CsGrptbl [my_idx].group,name_sz);
	if (grp_dscr != NULL) CS_stncp (grp_dscr,cs_CsGrptbl [my_idx].descr,dscr_sz);
	return (index < count);
}

char * EXP_LVL9 CScsKeyNames (void)
{
	extern csThread char *cs_CsKeyNames;

	int st;
	int crypt;

	size_t len;
	size_t malc_size;
	size_t used_size;

	char *cp;
	char *new_ptr;
	char *tmp_ptr;
	csFILE *strm;

 	__ALIGNMENT__1		/* Required by some Sun compilers. */
	struct cs_Csdef_ cs_def;

	/* If cs_CsKeyNames is not NULL, we already have a list, simply return it. */

	if (cs_CsKeyNames == NULL)
	{
		malc_size = 8196;
		used_size = 0;
		new_ptr = (char *)CS_malc (malc_size);
		if (new_ptr == NULL)
		{
			CS_erpt (cs_NO_MEM);
		}
		else
		{
			strm = CS_csopn (_STRM_BINRD);
			if (strm != NULL)
			{
				while ((st = CS_csrd (strm,&cs_def,&crypt)) > 0)
				{
					/* Make sure we have enough room for the new
					   entry, its terminating null character, AND
					   the extra null which terminates the whole list. */

					len = strlen (cs_def.key_nm);
					if ((used_size + len + 2) >= malc_size)
					{
						malc_size += 2048;
						tmp_ptr = (char *)CS_ralc (new_ptr,malc_size);
						if (tmp_ptr == NULL)
						{
							CS_erpt (cs_NO_MEM);
							CS_free (new_ptr);
							new_ptr = NULL;
							break;
						}
						new_ptr = tmp_ptr;
					}

					/* Add the new item to the list. Must recalculate cp
					   in case the realloc has moved the list to new memory. */

					cp = new_ptr + used_size;
					cp = CS_stcpy (cp,cs_def.key_nm);
					used_size += len + 1;
				}
				CS_csDictCls (strm);
				if (st != 0)
				{
					/* Here if the above loop terminated due to an
					   error, rather than a simple EOF. */

					CS_free (new_ptr);
					new_ptr = NULL;
				}
			}
			else
			{
				CS_free (new_ptr);
				new_ptr = NULL;
			}
		}

		if (new_ptr != NULL)
		{
			/* List generated without an error. Make sure the whole list
			   is properly terminated, and resize down to the minimum
			   amount of memory necessary. */

			*(new_ptr + used_size) = '\0';
			used_size += 1;
			cs_CsKeyNames = (char *)CS_ralc (new_ptr,used_size);
			if (cs_CsKeyNames == NULL) CS_free (new_ptr);
		}
	}

	/* If anything in the list generation failed, cs_CsKeyNames will
	   still be NULL. In any case, it represents the desired return
	   value. */

	return (cs_CsKeyNames);
}

char * EXP_LVL9 CSdtKeyNames (void)
{
	extern csThread char *cs_DtKeyNames;

	int st;
	int crypt;

	size_t len;
	size_t malc_size;
	size_t used_size;

	char *cp;
	char *new_ptr;
	char *tmp_ptr;
	csFILE *strm;

 	__ALIGNMENT__1		/* Required by some Sun compilers. */
	struct cs_Dtdef_ dt_def;

	/* See CScsKeyNames for commentary. */

	if (cs_DtKeyNames == NULL)
	{
		malc_size = 2048;
		used_size = 0;
		new_ptr = (char *)CS_malc (malc_size);
		if (new_ptr == NULL)
		{
			CS_erpt (cs_NO_MEM);
		}
		else
		{
			strm = CS_dtopn (_STRM_BINRD);
			if (strm != NULL)
			{
				while ((st = CS_dtrd (strm,&dt_def,&crypt)) > 0)
				{
					len = strlen (dt_def.key_nm);
					if ((used_size + len + 2) >= malc_size)
					{
						malc_size += 1024;
						tmp_ptr = (char *)CS_ralc (new_ptr,malc_size);
						if (tmp_ptr == NULL)
						{
							CS_erpt (cs_NO_MEM);
							CS_free (new_ptr);
							new_ptr = NULL;
							break;
						}
						new_ptr = tmp_ptr;
					}
					cp = new_ptr + used_size;
					cp = CS_stcpy (cp,dt_def.key_nm);
					used_size += len + 1;
				}
				CS_dtDictCls (strm);
				if (st != 0)
				{
					CS_free (new_ptr);
					new_ptr = NULL;
				}
			}
			else
			{
				CS_free (new_ptr);
				new_ptr = NULL;
			}
		}
		if (new_ptr != NULL)
		{
			*(new_ptr + used_size) = '\0';
			used_size += 1;
			cs_DtKeyNames = (char *)CS_ralc (new_ptr,used_size);
			if (cs_DtKeyNames == NULL) CS_free (new_ptr);
		}
	}
	return (cs_DtKeyNames);
}

char * EXP_LVL9 CSelKeyNames (void)
{
	extern csThread char *cs_ElKeyNames;

	int st;
	int crypt;

	size_t len;
	size_t malc_size;
	size_t used_size;

	char *cp;
	char *new_ptr;
	char *tmp_ptr;
	csFILE *strm;

 	__ALIGNMENT__1		/* Required by some Sun compilers. */
	struct cs_Eldef_ el_def;

	/* See CScsKeyNames for commentary. */

	if (cs_ElKeyNames == NULL)
	{
		malc_size = 1024;
		used_size = 0;
		new_ptr = (char *)CS_malc (malc_size);
		if (new_ptr == NULL)
		{
			CS_erpt (cs_NO_MEM);
		}
		else
		{
			strm = CS_elopn (_STRM_BINRD);
			if (strm != NULL)
			{
				while ((st = CS_elrd (strm,&el_def,&crypt)) > 0)
				{
					len = strlen (el_def.key_nm);
					if ((used_size + len + 2) >= malc_size)
					{
						malc_size += 512;
						tmp_ptr = (char *)CS_ralc (new_ptr,malc_size);
						if (tmp_ptr == NULL)
						{
							CS_erpt (cs_NO_MEM);
							CS_free (new_ptr);
							new_ptr = NULL;
							break;
						}
						new_ptr = tmp_ptr;
					}
					cp = new_ptr + used_size;
					cp = CS_stcpy (cp,el_def.key_nm);
					used_size += len + 1;
				}
				CS_elDictCls (strm);
				if (st != 0)
				{
					CS_free (new_ptr);
					new_ptr = NULL;
				}
			}
			else
			{
				CS_free (new_ptr);
				new_ptr = NULL;
			}
		}
		if (new_ptr != NULL)
		{
			*(new_ptr + used_size) = '\0';
			used_size += 1;
			cs_ElKeyNames = (char *)CS_ralc (new_ptr,used_size);
			if (cs_ElKeyNames == NULL) CS_free (new_ptr);
		}
	}
	return (cs_ElKeyNames);
}

int EXP_LVL1 CS_prjEnum (int index,unsigned long *prj_flags,char *prj_keynm,int keynm_sz,char *prj_descr,int descr_sz)
{
	extern int cs_Error;
	extern struct cs_Prjtab_ cs_Prjtab [];

	int ii;
	int count;
	int my_idx;

	if (index < 0)
	{
		CS_erpt (cs_INV_INDX);
		return (-cs_Error);
	}

	my_idx = -1;
	count = 0;
	for (ii = 0;cs_Prjtab [ii].code != cs_PRJCOD_END;ii++)
	{
		if (count == index)
		{
			my_idx = count;
			break;
		}
		count += 1;
	}
	if (my_idx < 0)
	{
		if (prj_flags != NULL) *prj_flags = 0L;
		if (prj_keynm != NULL) *prj_keynm = '\0';
		if (prj_descr != NULL) *prj_descr = '\0';
		return (0);
	}
	if (prj_flags != NULL) *prj_flags = cs_Prjtab [my_idx].flags;
	if (prj_keynm != NULL) CS_stncp (prj_keynm,cs_Prjtab [my_idx].key_nm,keynm_sz);
	if (prj_descr != NULL) CS_stncp (prj_descr,cs_Prjtab [my_idx].descr,descr_sz);
	return (cs_Prjtab [ii].code);
}

int EXP_LVL1 CS_unEnum (int index,int type,char *un_name,int un_size)
{
	extern int cs_Error;
	extern struct cs_Unittab_ cs_Unittab [];
	extern char csErrnam [];

	static char modl_name [] = "CS_unEnum";

	int ii;
	int my_idx;
	int count;

	if (type != cs_UTYP_LEN && type != cs_UTYP_ANG)
	{
		CS_stcpy (csErrnam,modl_name);
		CS_erpt (cs_INV_UTYP);
		return (-cs_Error);
	}

	if (index < 0)
	{
		CS_erpt (cs_INV_INDX);
		return (-cs_Error);
	}

	/* Scan the table for the index'th entry with the same type as
	   requested. Note, we do not "count" entries with other types. */

	count = 0;
	my_idx = -1;
	for (ii = 0;cs_Unittab [ii].type != cs_UTYP_END;ii++)
	{
		if (cs_Unittab [ii].type != type) continue;
		if (count == index)
		{
			my_idx = ii;
			break;
		}
		count += 1;
	}
	if (my_idx < 0)
	{
		*un_name = '\0';
		return (0);
	}
	CS_stncp (un_name,cs_Unittab [my_idx].name,un_size);
	return (1);
}

int EXP_LVL1 CS_unEnumPlural (int index,int type,char *un_name,int un_size)
{
	extern int cs_Error;
	extern struct cs_Unittab_ cs_Unittab [];
	extern char csErrnam [];

	static char modl_name [] = "CS_unEnumPlural";

	int ii;
	int my_idx;
	int count;

	if (type != cs_UTYP_LEN && type != cs_UTYP_ANG)
	{
		CS_stcpy (csErrnam,modl_name);
		CS_erpt (cs_INV_UTYP);
		return (-cs_Error);
	}

	if (index < 0)
	{
		CS_erpt (cs_INV_INDX);
		return (-cs_Error);
	}

	/* Scan the table for the index'th entry with the same type as
	   requested. Note, we do not "count" entries with other types. */

	count = 0;
	my_idx = -1;
	for (ii = 0;cs_Unittab [ii].type != cs_UTYP_END;ii++)
	{
		if (cs_Unittab [ii].type != type) continue;
		if (count == index)
		{
			my_idx = ii;
			break;
		}
		count += 1;
	}
	if (my_idx < 0)
	{
		*un_name = '\0';
		return (0);
	}
	CS_stncp (un_name,cs_Unittab [my_idx].pluralName,un_size);
	return (1);
}

int EXP_LVL1 CS_unEnumSystem (int index,int type)
{
	extern int cs_Error;
	extern struct cs_Unittab_ cs_Unittab [];

	int ii;
	int my_idx;
	int count;
	int rtnValue;

	if (type != cs_UTYP_LEN && type != cs_UTYP_ANG)
	{
		CS_erpt (cs_INV_UTYP);
		rtnValue = -cs_Error;
	}
	else
	{
		if (index < 0)
		{
			CS_erpt (cs_INV_INDX);
			rtnValue = -cs_Error;
		}
		else
		{
			/* Scan the table for the index'th entry with the same type as
			   requested. Note, we do not "count" entries with other types. */
			rtnValue = count = 0;
			my_idx = -1;
			for (ii = 0;cs_Unittab [ii].type != cs_UTYP_END;ii++)
			{
				if (cs_Unittab [ii].type != type) continue;
				if (count == index)
				{
					my_idx = ii;
					break;
				}
				count += 1;
			}
			if (my_idx >= 0)
			{
				rtnValue = cs_Unittab [my_idx].system;
			}
		}
	}
	return rtnValue;
}

int EXP_LVL1 CS_getDataDirectory (char *data_dir,int dir_sz)
{
	extern char cs_Dir [];
	extern char *cs_DirP;
	extern char cs_Csname [];

	int st;
	int len;

	if (dir_sz <= 0) return (-1);

	*cs_DirP = '\0';
	len = (int)strlen (cs_Dir);
	if (len > dir_sz) len = dir_sz;
	CS_stncp (data_dir,cs_Dir,len);
	strcpy (cs_DirP,cs_Csname);
	st = CS_access (cs_Dir,0);
	return (st == 0);
}
/*
	The following table and function associates an 8-bit ASCII
	label for the supported quad codes.  For use in user
	interfaces.
*/
static struct quadTable_
{
	short ident;
	char descr [58];
} quadTable [] =
{
/*                       1         2         3         4         5        
	        1234567890123456789012345678901234567890123456789012345678*/
	{   1, "X/Lng increases to the east, Y/Lat increases to the north" },
	{   2, "X/Lng increases to the west, Y/Lat increases to the north" },
	{   3, "X/Lng increases to the west, Y/Lat increases to the south" },
	{   4, "X/Lng increases to the east, Y/Lat increases to the south" },
	{  -1, "Y increases to the east, X increases to the north" },
	{  -2, "Y increases to the west, X increases to the north" },
	{  -3, "Y increases to the west, X increases to the south" },
	{  -4, "Y increases to the east, X increases to the south" }
};
int EXP_LVL1 CS_quadEnum (int index,char *descr,int size,int *ident)
{
	if (index < 0)
	{
		CS_erpt (cs_INV_INDX);
		return (-1);
	}
	if (index >= (int)(sizeof (quadTable) / sizeof (struct quadTable_)))
	{
		return (0);
	}
	CS_stncp (descr,quadTable [index].descr,size);
	*ident = quadTable [index].ident;
	return 1;
}
/*
	The following table and function associates an 8-bit ASCII
	label for the supported to84_via codes.  For use in user
	interfaces.
*/
static struct viaTable_
{
	short ident;
	char descr [32];
} viaTable [] =
{
/*								   1        2         3
					      12345678901234567890123456789012 */
	{    cs_DTCTYP_MOLO, "DMA Molodensky Transformation" },
	{    cs_DTCTYP_MREG, "DMA Multiple Regression" },
	{   cs_DTCTYP_NAD27, "NAD27<->NAD83 via NADCON/NTv2" },
	{   cs_DTCTYP_NAD83, "Is NAD83, no shift required." },
	{   cs_DTCTYP_WGS84, "Is WGS84, no shift required." },
	{   cs_DTCTYP_GDA94, "Is GDA94, no shift required." },
	{  cs_DTCTYP_NZGD2K, "Is NZGD2000, no shift required." },
	{  cs_DTCTYP_ETRF89, "Is ETRF89, no shift required." },
	{    cs_DTCTYP_CSRS, "NAD83<->CSRS Via Grid Files." },
	{   cs_DTCTYP_WGS72, "WGS72<->WGS84 Via DMA formula." },
	{    cs_DTCTYP_HPGN, "HARN<->NAD83 via NADCON" },
	{   cs_DTCTYP_AGD66, "AGD66<->GDA94 via Grid Files" },
	{   cs_DTCTYP_AGD84, "AGD84<->GDA94 via Grid Files" },
	{    cs_DTCTYP_ED50, "ED50<->ETRF89 via Grid Files" },
	{    cs_DTCTYP_DHDN, "DHDN<->ETRF89 via Grid Files" },
	{  cs_DTCTYP_NZGD49, "NZGD49<->NZGD2K via Grid File" },
	{   cs_DTCTYP_ATS77, "ATS77<->NAD83 via Grid Files" },
	{   cs_DTCTYP_TOKYO, "TOKYO<->JGD2k via Grid Files" },
	{   cs_DTCTYP_RGF93, "NTF<->RGF93 via Grid File" },
	{   cs_DTCTYP_3PARM, "Three Parameter Transformation" },
	{    cs_DTCTYP_BURS, "Bursa/Wolf Transformation" },
	{  cs_DTCTYP_ETRF89, "Is ETRF89, no shift required." },
	{   cs_DTCTYP_6PARM, "Six Parameter Transformation" },
	{   cs_DTCTYP_7PARM, "Seven Parameter Transformation" },
	{   cs_DTCTYP_4PARM, "Four Parameter Transformation" }
};
int EXP_LVL1 CS_viaEnum (int index,char *descr,int size,int *ident)
{
	if (index < 0)
	{
		CS_erpt (cs_INV_INDX);
		return (-1);
	}
	if (index >= (int)(sizeof (viaTable) / sizeof (struct viaTable_)))
	{
		return (0);
	}
	CS_stncp (descr,viaTable [index].descr,size);
	*ident = viaTable [index].ident;
	return 1;
}

int EXP_LVL1 CS_getUnitsOf (Const char *csKeyName,char *unitName,int size)
{
	int rtnValue = -1;
	struct cs_Csdef_ *csDefPtr;

	csDefPtr = CS_csdef (csKeyName);
	if (csDefPtr != NULL)
	{
		CS_stncp (unitName,csDefPtr->unit,size);
		CS_free (csDefPtr);
		rtnValue = 0;
	}
	return rtnValue;
}
int EXP_LVL1 CS_getDatumOf (Const char *csKeyName,char *datumName,int size)
{
	int rtnValue = -1;
	struct cs_Csdef_ *csDefPtr;

	csDefPtr = CS_csdef (csKeyName);
	if (csDefPtr != NULL)
	{
		CS_stncp (datumName,csDefPtr->dat_knm,size);
		CS_free (csDefPtr);
		rtnValue = 0;
	}
	return rtnValue;
}
int EXP_LVL1 CS_getEllipsoidOf (Const char *csKeyName,char *ellipsoidName,int size)
{
	int rtnValue = -1;
	struct cs_Csdef_ *csDefPtr;
	struct cs_Dtdef_ *dtDef;

	csDefPtr = CS_csdef (csKeyName);
	if (csDefPtr != NULL)
	{
		if (csDefPtr->dat_knm [0] != '\0')
		{
			/* Coordinate system is referenced to a datum.  Need to get the
			   datum definition in order to determine the ellipsoid. */

			dtDef = CS_dtdef (csDefPtr->dat_knm);
			if (dtDef != NULL)
			{
				CS_stncp (ellipsoidName,dtDef->ell_knm,size);
				CS_free (dtDef);
			}
		}
		else
		{
			CS_stncp (ellipsoidName,csDefPtr->elp_knm,size);
		}
		CS_free (csDefPtr);
		rtnValue = 0;
	}
	return rtnValue;
}
int EXP_LVL1 CS_getReferenceOf (Const char *csKeyName,char *reference,int size)
{
	int rtnValue = -1;
	char *cp;
	struct cs_Csdef_ *csDefPtr;
	char myReference [256];

	csDefPtr = CS_csdef (csKeyName);
	if (csDefPtr != NULL)
	{
		if (csDefPtr->dat_knm [0] != '\0')
		{
			cp = CS_stcpy (myReference,"Datum: ");
			CS_stncp (cp,csDefPtr->dat_knm,sizeof (myReference) - 16);
		}
		else
		{
			cp = CS_stcpy (myReference,"Ellipsoid: ");
			CS_stncp (cp,csDefPtr->elp_knm,sizeof (myReference) - 16);
		}
		CS_free (csDefPtr);
		CS_stncp (reference,myReference,size);
		rtnValue = 0;
	}
	return rtnValue;
}
int EXP_LVL1 CS_getDescriptionOf (Const char *csKeyName,char *description,int size)
{
	int rtnValue = -1;
	struct cs_Csdef_ *csDefPtr;

	csDefPtr = CS_csdef (csKeyName);
	if (csDefPtr != NULL)
	{
		CS_stncp (description,csDefPtr->desc_nm,size);
		CS_free (csDefPtr);
		rtnValue = 0;
	}
	return rtnValue;
}
int EXP_LVL1 CS_getSourceOf (Const char *csKeyName,char *source,int size)
{
	int rtnValue = -1;
	struct cs_Csdef_ *csDefPtr;

	csDefPtr = CS_csdef (csKeyName);
	if (csDefPtr != NULL)
	{
		CS_stncp (source,csDefPtr->source,size);
		CS_free (csDefPtr);
		rtnValue = 0;
	}
	return rtnValue;
}
double EXP_LVL1 CS_getCurvatureAt (Const char *csKeyName,double lat)
{
	extern double cs_Zero;			/* 0.0 */
	extern double cs_One;			/* 1.0 */
	extern double cs_Degree;		/* 1.0 / 57.29577.... */

	int st;
	double mm;
	double nn;
	double e_sq;
	double sinLat;
	double dblTmp;
	double curvature;
	char ellipsoidName [32];
	struct cs_Eldef_* elDefPtr;

	curvature = cs_Zero;
	st = CS_getEllipsoidOf (csKeyName,ellipsoidName,sizeof (ellipsoidName));
	if (st == 0)
	{
		elDefPtr = CS_eldef (ellipsoidName);
		if (elDefPtr != 0)
		{
			sinLat = sin (lat * cs_Degree);
			e_sq = elDefPtr->ecent * elDefPtr->ecent;
			dblTmp = cs_One - (e_sq * sinLat * sinLat);

			/* mm is the radius of curvature of the ellipsoid along the
			   meridian at the specified latitude.

			   nn is the radius of curvature of the ellipsoid in a plane
			   orthogonal to the meridian at the specified latitude. */
			nn = elDefPtr->e_rad / sqrt (dblTmp);
			mm = elDefPtr->e_rad * (cs_One - e_sq) / (dblTmp * sqrt (dblTmp));

			/* curvature is calculated as the geometric mean of the two
			   radii of curvature, also known as the Gauss curvature. */
			curvature = sqrt (mm * nn);
			CS_free (elDefPtr);
		}
	}
	return curvature;
}
/**********************************************************************
**	id = CS_prjprm (result,prj_cod,parm_nbr);
**
**	struct cs_Prjprm_ *result;	information concerning the requested parameter
**								is returned here. May be NULL.
**	short prj_cod;				the numeric projection code assigned to the
**								specific projection in use.
**	int parm_nbr;				the number of the parameter, zero based (i.e.
**								0 through 23).
**	int status;					returns +1 for a valid parameter; returns zero
**								if the requested parameter number is not used
**								for the indicated projection.  Returns -1 if
**								prj_cod or parm_nbr are bogus.
**
**	The result parameter may be the NULL pointer.  In this case
**	this function simply returns an indication of the status
**	of a particular parameter.
**
**	This function is designed for use in programming a dialog
**	box type of coordinate system editor.  For any given projection,
**	and any given parameter number, it returns a proper description
**	and information useful in formatting the numbers and checking
**	for valid ranges.
**
**	Given the tables provided in CSdataPJ, it would be relatively
**	easy for the application programmer to fetch her/his own
**	information.  This is not recommended.  Use this function and
**	provide yourself with some (repeat some) insulation from
**	changes in the future.
**********************************************************************/

int EXP_LVL3  CS_prjprm (struct cs_Prjprm_ *result,unsigned short prj_code,int parm_nbr)
{
	extern struct cs_Prjprm_ csPrjprm [];
	extern struct cs_PrjprmMap_ cs_PrjprmMap [];

	int parm_idx;

	struct cs_Prjprm_ *pp;
	struct cs_PrjprmMap_ *mp;

	char my_temp [256];

	for (mp = cs_PrjprmMap;mp->prj_code != cs_PRJCOD_END;mp += 1)
	{
		if (mp->prj_code == prj_code) break;
	}
	if (mp->prj_code == cs_PRJCOD_END || parm_nbr < 0 || parm_nbr > 23)
	{
		return (-1);
	}
	parm_idx = mp->prm_types [parm_nbr];
	if (parm_idx <= 0)
	{
		return (0);
	}
	pp = &csPrjprm [parm_idx];

	/* OK, we have a pointer to the appropriate parameter type
	   structure.  We return to the application programmer the
	   appropriate values. This insulates the application
	   programmer from the tables, so we can change them in the
	   future. */

	if (result != NULL)
	{
		result->min_val   = pp->min_val;
		result->max_val   = pp->max_val;
		result->deflt     = pp->deflt;
		result->format    = pp->format;
		result->help_id   = pp->help_id;
		result->labl_id   = pp->labl_id;
		result->phys_type = pp->phys_type;
		result->log_type  = pp->log_type;
		result->prj_code  = pp->prj_code;
		result->parm_nbr  = (short)parm_nbr;
		result->sprf_type = pp->sprf_type;

		/* Deal with the label here.  Another reason to uses
		   this function rather then mess with the tables
		   themselves. */

		switch (pp->sprf_type) {

		case 1:

			parm_idx = (parm_nbr) / 2 + 1;
			sprintf (my_temp,pp->label,parm_idx);
			CS_stncp (result->label,my_temp,sizeof (result->label));
			break;

		default:
			CS_stncp (result->label,pp->label,sizeof (result->label));
			break;
		}
	}
	return (1);
}

/**********************************************************************
**	CS_fillIn (csPtr);
**
**	struct cs_Csdef_ *csPtr;	structure to be "filled in".
**
**	This function will fill in the implied values for items in
**	the cs_Csdef_ structure whose value is not used, i.e. implied,
**	by the referenced projection.
**
**	This function is used in the Coordinate System compiler, and
**	is also used in coordinate system editor functions to update
**	a definition as specific items (i.e. projection, unit,
**	zone number, etc.) change.
**
**	There should be no errors if the provided definition is
**	legitimate.  If it isn't, this function does nothing
**	silently.
**********************************************************************/

void EXP_LVL3 CS_fillIn (struct cs_Csdef_ *csPtr)
{
	extern double cs_Degree;
	extern double cs_Radian;
	extern double cs_Mone;
	extern double cs_Zero;
	extern double cs_Half;
	extern double cs_One;
	extern double cs_Two;
	extern double cs_Nine;
	extern double cs_K15;
	extern double cs_ParmTest;

	extern struct cs_Prjtab_ cs_Prjtab [];

	int zoneNbr;
	struct cs_Prjtab_ *prjPtr;
	double lng_A, lat_A, lng_B, lat_B;
	double sin_lat_A, cos_lat_A, sin_lat_B, cos_lat_B;
	double sp_1, sp_2, pole_dd;
	double sin_dd, cos_dd;
	double nn, T, Az_AB, z_c;
	double cos_Az_AB, sin_Az_AB;
	double tmp1, tmp2, tmp3, tmp4, tmp5;
	double unit_scl;

	/* Essentially, we have a big switch based on projection
	   code.  Therefore, must first determine the projection
	   code from the projection key name. */

	for (prjPtr = cs_Prjtab;prjPtr->key_nm [0] != '\0';prjPtr += 1)
	{
		if (!strcmp (csPtr->prj_knm,prjPtr->key_nm)) break;
	}
	if (prjPtr->key_nm [0] == '\0') return;

	/* There are some things we do in general. */

	if ((prjPtr->flags & cs_PRJFLG_SCLRED) == 0) csPtr->scl_red = 1.0;
	if ((prjPtr->flags & cs_PRJFLG_ORGLAT) == 1) csPtr->org_lat = 0.0;

	switch (prjPtr->code) {
	default:
		break;
	case cs_PRJCOD_UNITY:
		csPtr->x_off = 0.0;
		csPtr->y_off = 0.0;
		break;
	case cs_PRJCOD_TRMER:
		csPtr->org_lng = csPtr->prj_prm1;
		break;
	case cs_PRJCOD_ALBER:
		break;
	case cs_PRJCOD_OBLQM:
		/* This is a historical artifact; see HOM1UV et. al. below */ 
		break;
	case cs_PRJCOD_MRCAT:
		csPtr->org_lng = csPtr->prj_prm1;
		break;
	case cs_PRJCOD_AZMED:
		break;
	case cs_PRJCOD_LMTAN:
		break;
	case cs_PRJCOD_PLYCN:
		csPtr->org_lng = csPtr->prj_prm1;
		break;
	case cs_PRJCOD_MODPC:
		csPtr->org_lng = csPtr->prj_prm1;
		csPtr->org_lat = csPtr->prj_prm4;
		break;
	case cs_PRJCOD_AZMEA:
		break;
	case cs_PRJCOD_EDCNC:
		break;
	case cs_PRJCOD_MILLR:
		break;
	case cs_PRJCOD_MSTRO:
		break;
	case cs_PRJCOD_NZLND:
		break;
	case cs_PRJCOD_SINUS:
		break;
	case cs_PRJCOD_ORTHO:
		break;
	case cs_PRJCOD_GNOMC:
		break;
	case cs_PRJCOD_EDCYL:
		break;
	case cs_PRJCOD_VDGRN:
		break;
	case cs_PRJCOD_CSINI:
		csPtr->org_lng = csPtr->prj_prm1;
		break;
	case cs_PRJCOD_ROBIN:
		break;
	case cs_PRJCOD_BONNE:
		break;
	case cs_PRJCOD_EKRT4:
		break;
	case cs_PRJCOD_EKRT6:
		break;
	case cs_PRJCOD_MOLWD:
		break;
	case cs_PRJCOD_HMLSN:
		break;
	case cs_PRJCOD_NACYL:
		break;
	case cs_PRJCOD_TACYL:
		break;
	case cs_PRJCOD_BPCNC:
		/* Compute the actual origin of this thing. */
		lng_A = csPtr->prj_prm1 * cs_Degree;
		lat_A = csPtr->prj_prm2 * cs_Degree;
		lng_B = csPtr->prj_prm3 * cs_Degree;
		lat_B = csPtr->prj_prm4 * cs_Degree;
		pole_dd = csPtr->prj_prm5 * cs_Degree;
		sp_1 = csPtr->prj_prm6 * cs_Degree;
		sp_2 = csPtr->prj_prm7 * cs_Degree;
		sin_lat_A = sin (lat_A);
		cos_lat_A = cos (lat_A);
		sin_lat_B = sin (lat_B);
		cos_lat_B = cos (lat_B);
		if (pole_dd <= cs_Zero)
		{
			tmp1 = cos (lng_B - lng_A);
			cos_dd = (sin_lat_A * sin_lat_B) - (cos_lat_B * cos_lat_A * tmp1);
			pole_dd = acos (cos_dd);
			sin_dd = sin (pole_dd);
		}
		else
		{
			sin_dd = sin (pole_dd);
			cos_dd = cos (pole_dd);
			tmp1 = cos_lat_A * cos_lat_B;
			tmp1 = (cos_dd - sin_lat_A * sin_lat_B) / tmp1;
			lng_B = lng_A + acos (tmp1);
		}
		if (fabs (sp_1 - sp_2) > 1.0E-06)
		{
			tmp1 = tan (sp_1 * cs_Half);
			tmp2 = tan (sp_2 * cs_Half);
			tmp3 = log (tmp1) - log (tmp2);
			tmp4 = sin (sp_1);
			tmp5 = sin (sp_2);
			nn = (log (tmp4) - log (tmp5)) / tmp3;
			T = pow (tmp1,nn) + pow (tmp2,nn);
		}
		else
		{
			nn = sin (sp_1);
			T = cs_One;
		}
		tmp1 = pow (T * cs_Half,cs_One / nn);
		z_c = cs_Two * atan (tmp1);
		tmp1 = cos (lng_B - lng_A);
		tmp2 = cos_lat_A * sin_lat_B - sin_lat_A * cos_lat_B * tmp1;
		Az_AB = acos (tmp2 / sin_dd);
		sin_Az_AB = sin (Az_AB);
		cos_Az_AB = cos (Az_AB);

		tmp1 = sin_lat_A * cos (z_c) + cos_lat_A * sin (z_c) * cos_Az_AB;
		if (tmp1 < cs_Mone) tmp1 = cs_Mone;
		if (tmp1 > cs_One) tmp1 = cs_One;
		tmp1 = asin (tmp1);
		csPtr->org_lat = tmp1 * cs_Radian;
		tmp2 = sin (z_c) * sin_Az_AB / cos (tmp1);
		if (tmp2 < cs_Mone) tmp2 = cs_Mone;
		if (tmp2 > cs_One) tmp2 = cs_One;
		csPtr->org_lng = asin (tmp2) * cs_Radian + csPtr->prj_prm1;
		break;
	case cs_PRJCOD_SWISS:
		break;
	case cs_PRJCOD_PSTRO:
		break;
	case cs_PRJCOD_OSTRO:
		break;
	case cs_PRJCOD_SSTRO:
		break;
	case cs_PRJCOD_LM1SP:
		break;
	case cs_PRJCOD_LM2SP:
		break;
	case cs_PRJCOD_LMBLG:
		break;
	case cs_PRJCOD_WCCSL:
		break;
	case cs_PRJCOD_WCCST:
		csPtr->org_lng = csPtr->prj_prm1;
		break;
	case cs_PRJCOD_MNDOTL:
		break;		
	case cs_PRJCOD_MNDOTT:
		csPtr->org_lng = csPtr->prj_prm1;
		break;
	case cs_PRJCOD_SOTRM:
		csPtr->org_lng = csPtr->prj_prm1;
		break;
	case cs_PRJCOD_UTM:
		zoneNbr = (int)csPtr->prj_prm1;
		csPtr->org_lng = (double)(-183 + (6 * zoneNbr));	/*lint !e790 */
		csPtr->org_lat = cs_Zero;
		unit_scl = CS_unitlu (cs_UTYP_LEN,csPtr->unit);
		csPtr->x_off = 500000.0 / unit_scl;
		if (csPtr->prj_prm2 >= 0.0) csPtr->y_off = cs_Zero;
		else csPtr->y_off = 10000000.0 / unit_scl;
		csPtr->scl_red = 0.9996;
		break;
	case cs_PRJCOD_TRMRS:
		csPtr->org_lng = csPtr->prj_prm1;
		break;
	case cs_PRJCOD_GAUSSK:
		csPtr->org_lng = csPtr->prj_prm1;
		csPtr->scl_red = cs_One;
		break;		
	case cs_PRJCOD_KROVAK:
		break;
	case cs_PRJCOD_KRVK95:
		break;
	case cs_PRJCOD_PSTROSL:
		break;
	case cs_PRJCOD_TRMERAF:
		csPtr->org_lng = csPtr->prj_prm1;
		break;
	case cs_PRJCOD_NERTH:
		break;
	case cs_PRJCOD_OBQCYL:
		break;
	case cs_PRJCOD_SYS34:
		if      ((int)(csPtr->prj_prm1 + cs_ParmTest) == 1) csPtr->org_lng = cs_Nine;
		else if ((int)(csPtr->prj_prm1 + cs_ParmTest) == 2) csPtr->org_lng = cs_Nine;
		else if ((int)(csPtr->prj_prm1 + cs_ParmTest) == 3) csPtr->org_lng = cs_K15;
		else csPtr->org_lng = cs_Zero;
		break;
	case cs_PRJCOD_OSTN97:
		csPtr->org_lng = -2.0;
		csPtr->org_lat = 49.0;
		unit_scl = CS_unitlu (cs_UTYP_LEN,csPtr->unit);
		csPtr->x_off = 400000.0 / unit_scl;
		csPtr->y_off = -100000.0 / unit_scl;
		csPtr->scl_red = 0.9996012717;
		break;
	case cs_PRJCOD_AZEDE:
		break;
	case cs_PRJCOD_OSTN02:
		csPtr->org_lng = -2.0;
		csPtr->org_lat = 49.0;
		unit_scl = CS_unitlu (cs_UTYP_LEN,csPtr->unit);
		csPtr->x_off = 400000.0 / unit_scl;
		csPtr->y_off = -100000.0 / unit_scl;
		csPtr->scl_red = 0.9996012717;
		break;
	case cs_PRJCOD_SYS34_99:
		if      ((int)(csPtr->prj_prm1 + cs_ParmTest) == 1) csPtr->org_lng = cs_Nine;
		else if ((int)(csPtr->prj_prm1 + cs_ParmTest) == 2) csPtr->org_lng = cs_Nine;
		else if ((int)(csPtr->prj_prm1 + cs_ParmTest) == 3) csPtr->org_lng = cs_K15;
		else csPtr->org_lng = cs_Zero;
		break;
	case cs_PRJCOD_HOM1UV:
		csPtr->org_lng = csPtr->prj_prm1;
		csPtr->org_lat = csPtr->prj_prm2;
		break;
	case cs_PRJCOD_HOM1XY:
		csPtr->org_lng = csPtr->prj_prm1;
		csPtr->org_lat = csPtr->prj_prm2;
		break;
	case cs_PRJCOD_HOM2UV:
		csPtr->org_lng = 0.0;
		break;
	case cs_PRJCOD_HOM2XY:
		csPtr->org_lng = 0.0;
		break;
	case cs_PRJCOD_RSKEW:
		csPtr->org_lng = csPtr->prj_prm1;
		csPtr->org_lat = csPtr->prj_prm2;
		break;
	case cs_PRJCOD_RSKEWC:
		break;
	case cs_PRJCOD_TRMRKRG:
		csPtr->org_lng = csPtr->prj_prm1;
		break;
	case cs_PRJCOD_WINKL:
		break;
	case cs_PRJCOD_NRTHSRT:
		break;
	}
	return;
}

int EXP_LVL1 CS_csRangeEnumSetup (double longitude,double latitude)
{
	extern char *cs_CsLlEnum;

	int st;
	int result;
	int count;
	int crypt;

	size_t len;
	size_t malc_size;
	size_t used_size;

	char *cp;
	char *new_ptr;
	char *tmp_ptr;
	csFILE *strm;

 	__ALIGNMENT__1				/* Required by some Sun compilers. */
	struct cs_Csdef_ cs_def;

	/* We assume we failed until we know different. */
	result = -1;
	count = 0;
	if (cs_CsLlEnum != NULL)
	{
		CS_free (cs_CsLlEnum);
		cs_CsLlEnum = NULL;
	}
	malc_size = 8196;
	used_size = 0;
	new_ptr = (char *)CS_malc (malc_size);
	if (new_ptr == NULL)
	{
		CS_erpt (cs_NO_MEM);
	}
	else
	{
		/* Open the coordinate system dictionary, we're going to look at each definition. */
		strm = CS_csopn (_STRM_BINRD);
		if (strm != NULL)
		{
			while ((st = CS_csrd (strm,&cs_def,&crypt)) > 0)
			{
				/* See if the current entry meets the indeicated criteria. */
				if (longitude >= cs_def.ll_min [0] && latitude >= cs_def.ll_min [1] &&
					longitude <= cs_def.ll_max [0] && latitude <= cs_def.ll_max [1])
				{
					/* Add the keyname to the list. */
					len = strlen (cs_def.key_nm);
					if ((used_size + len + 2) >= malc_size)
					{
						malc_size += 2048;
						tmp_ptr = (char *)CS_ralc (new_ptr,malc_size);
						if (tmp_ptr == NULL)
						{
							st = -1;
							CS_erpt (cs_NO_MEM);
							CS_free (new_ptr);
							new_ptr = NULL;
							break;
						}
						new_ptr = tmp_ptr;
					}

					/* Add the new item to the list. Must recalculate cp
					   in case the realloc has moved the list to new memory. */
					cp = new_ptr + used_size;
					cp = CS_stcpy (cp,cs_def.key_nm);
					used_size += len + 1;

					/* Count it. */
					count += 1;
				}
			}
			CS_csDictCls (strm);
			if (st >= 0)
			{
				if (new_ptr != NULL)
				{
					/* List generated without an error. Make sure the whole list
					   is properly terminated, and resize down to the minimum
					   amount of memory necessary. */

					*(new_ptr + used_size) = '\0';
					used_size += 1;
					cs_CsLlEnum = (char *)CS_ralc (new_ptr,used_size);
					if (cs_CsLlEnum != NULL)
					{
						/* Success */
						new_ptr = NULL;
						result = count;
					}
					else
					{
						/* Failure */
						CS_erpt (cs_NO_MEM);
					}
				}
			}
		}
		if (new_ptr != NULL)
		{
			CS_free (new_ptr);
		}
	}
	return result;
}

int EXP_LVL1 CS_csRangeEnum (int index,char *key_name,int size)
{
	extern char *cs_CsLlEnum;

	cs_Register char *cp;

	int ii;

	*key_name = '\0';
	if (index < 0)
	{
		CS_erpt (cs_INV_INDX);
		return (-1);
	}

	/* Get a pointer to the Coordinate System Names enumeration. */
	cp = cs_CsLlEnum;
	if (cp == NULL)
	{
		CS_erpt (cs_LLENUM_NOSU);
		return (-1);
	}

	/* Locate the index'th entry in the enumeration. */
	for (ii = 0;ii < index;ii++)
	{
		while (*cp++ != '\0');						/*lint !e722 */
		if (*cp == '\0') break;
	}

	/* Return the located result, even if it is the null string. */
	CS_stncp (key_name,cp,size);

	/* Return zero (FALSE) if index is past the end of the list,
	   otherwise return 1 (TRUE) */
	return (*cp != '\0');
}

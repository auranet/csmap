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

			 File Name: $RCSfile: CS_csprm.c $
		   Description:
			   Purpose:

		Revision Level:	$Revision: #3 $
		 Check In Date:	$Date: 2005/07/26 $

		Last Revision:	$Log: CS_csprm.c $
		Last Revision:	Revision 11.1300  2005/05/25 23:27:08  nto
		Last Revision:	Official Release 11.13
		Last Revision:	Revision 11.1200  2005/01/15 18:27:09  nto
		Last Revision:	Official Release of CS-MAP 11.12, 11:26am 15 Jan 2005
		Last Revision:	Revision 11.1100  2004/11/01 18:53:06  nto
		Last Revision:	Official release 11.11
		Last Revision:	Revision 11.1001  2004/10/07 19:25:15  nto
		Last Revision:	Revision 11.901  2004/10/07 02:35:55  nto
		Last Revision:	Added new function: CSllCsFromDt
		Last Revision:	Revision 11.900  2004/03/26 17:02:22  nto
		Last Revision:	Official release: 11.09 - 3/25/2003
		Last Revision:	Revision 11.800  2004/01/13 23:29:11  nto
		Last Revision:	Revision 11.700  2003/12/19 01:49:51  nto
		Last Revision:	Official release 11.07
		Last Revision:	Revision 11.600  2003/12/04 02:46:26  nto
		Last Revision:	Release 11.06.  Never shipped. Source captured in prep for C++ V7.
		Last Revision:	Revision 11.501  2003/08/22 21:12:54  nto
		Last Revision:	Official Release: 11.05
		Last Revision:	Revision 11.401  2003/05/01 23:06:20  nto
		Last Revision:	Revision 11.300  2003/02/25 04:29:14  nto
		Last Revision:	Official Release 11.03
		Last Revision:	Revision 11.100  2002/11/22 19:38:42  nto
		Last Revision:	Official release: 11.01
		Last Revision:	Revision 10.1501  2002/11/06 23:45:17  nto
		Last Revision:	Fixed the declaration of the Hook function.
		Last Revision:	Revision 10.1500  2002/09/22 00:01:18  nto
		Last Revision:	Official Release:= 10.15
		Last Revision:	Revision 10.1400  2002/08/09 18:14:20  nto
		Last Revision:	Revision 10.1200  2002/07/14 03:26:13  nto
		Last Revision:	Revision 10.1100  2002/06/13 14:18:36  nto
		Last Revision:	Release 10.11 Official
		Last Revision:	Revision 10.1000  2002/02/23 21:18:25  nto
		Last Revision:	Official Release of 10.10, 2/22/02 - Norm Olsen
		Last Revision:	Revision 10.900  2001/09/24 04:31:09  nto
		Last Revision:	Revision 10.700  2001/01/25 04:13:45  nto
		Last Revision:	Revision 10.600  2000/12/11 06:39:39  nto
		Last Revision:	Release 10.06
		Last Revision:	Revision 10.500  2000/10/27 07:38:17  nto
		Last Revision:	Official Release 10.05
		Last Revision:	Revision 10.401  2000/10/27 03:51:08  nto
		Last Revision:	Removed the attempt to export the hook function pointers.
		Last Revision:	Revision 10.400  2000/09/13 01:16:51  nto
		Last Revision:	Release 10.04
		Last Revision:	Revision 10.300  2000/04/04 23:18:22  nto
		Last Revision:	Revision 10.200  2000/03/02 18:51:14  nto
		Last Revision:	Revision 10.3  2000/01/30 23:26:36  nto
		Last Revision:	Moved the definition of the hook function pointers to the CSdata.c module.
		Last Revision:	Revision 10.2  1999/10/16 18:44:11  nto
		Last Revision:	Modifications suggested by Gimpel PC-Lint.
		Last Revision:	Revision 10.1  1999/10/09 00:18:34  nto
		Last Revision:	FIxed some minor bugs reported by Autodesk, Inc.
		Last Revision:	Revision 10.0  1999/10/05 18:27:12  nto
		Last Revision:	Revision 9.99  1999/10/05 17:36:23  nto
		Last Revision:	Revision 1.2  1999/09/06 17:26:36  nto
		Last Revision:	This revision compiles, links, and generates a successful test program.

******************************************************************************/

#ifdef LABEL_MODULE
static char revlvl [] = {"$Id: //depot/Libraries/CsMap/current/src/CS_csprm.c#3 $"};
#endif

#include "cs_map.h"

/**********************************************************************
	The function pointed to by the following variable is called after the
	definition has been read, but before any default processing.
***********************************************************************/

extern int (*cs_CsHook)(struct cs_Csdef_ *csdef,unsigned short prj_code,unsigned long prj_flags);

/**********************************************************************
**	csprm = CS_csloc (cs_nam);
**
**	char *cs_nam;				key name of the coordinate system to be
**								located.
**	struct cs_Csprm_ *csprm;	returns a pointer to a malloc'ed and initialized
**								coordinate system parameter structure.  Returns
**								NULL on error.
**********************************************************************/

struct cs_Csprm_ * EXP_LVL3 CS_csloc (Const char *cs_nam)
{
	extern char csErrnam [];
	extern struct cs_Prjtab_ cs_Prjtab [];

	int status;

	struct cs_Csprm_ *csprm;
	struct cs_Csdef_ *cs_ptr;
	struct cs_Prjtab_ *pp;

	/* Prepare for an error condition. */

	csprm = NULL;
	cs_ptr = NULL;

	/* Get the coordinate system definition from the dictionary. */

	cs_ptr = CS_csdef (cs_nam);
	if (cs_ptr == NULL) goto error;

	/* We need a pointer to the projection table entry before
	   we proceed much further.  This is somewhat redundant,
	   as CS_cschk will do the same thing, but it isn't that
	   expensive. */

	for (pp = cs_Prjtab;*pp->key_nm != '\0';pp++)
	{
		if (!CS_stricmp (pp->key_nm,cs_ptr->prj_knm)) break;
	}
	if (*pp->key_nm == '\0' || pp->setup == NULL)
	{
		CS_stncp (csErrnam,cs_ptr->prj_knm,MAXPATH);
		CS_erpt (cs_UNKWN_PROJ);
		goto error;
	}

	/* Give the application programmer a chance to do something
	   special. */

	if (cs_CsHook != NULL)
	{
		status = (*cs_CsHook)(cs_ptr,pp->code,pp->flags);
		if (status != 0)
		{
			CS_stncp (csErrnam,cs_ptr->key_nm,MAXPATH);
			if (status > 0) CS_erpt (status);
			goto error;
		}
	}

	/* Construct the coordinate system.  CScsloc1 will cause, eventually,
	   the definition structure to be checked for validity. */

	csprm = CScsloc1 (cs_ptr);
	if (csprm == NULL) goto error;

	CS_free (cs_ptr);
	cs_ptr = NULL;
	return (csprm);

error:
	if (cs_ptr != NULL) CS_free (cs_ptr);
	if (csprm != NULL) CS_free (csprm);
	return (NULL);
}

/**********************************************************************
**	Equivalent to the above, but the definition was, perhaps, obtained
**	or constructed by some means other than CS_csdef ().
**********************************************************************/

struct cs_Csprm_ * EXP_LVL3 CScsloc1 (struct cs_Csdef_ *cs_ptr)
{
	extern char csErrnam [];
	extern struct cs_Prjtab_ cs_Prjtab [];

	struct cs_Csprm_ *csprm;
	struct cs_Datum_ *dt_ptr;
	struct cs_Eldef_ *el_ptr;
	struct cs_Prjtab_ *pp;
	struct cs_Csdef_ lclCsDef;

	csprm = NULL;
	dt_ptr = NULL;
	el_ptr = NULL;

	/* We need a pointer to the projection table entry before
	   we proceed much further.  This is somewhat redundant,
	   as CS_cschk (called from CScsloc) will do the same thing,
	   but if we don't have a valid projection, things get ugly. */

	for (pp = cs_Prjtab;*pp->key_nm != '\0';pp++)
	{
		if (!CS_stricmp (pp->key_nm,cs_ptr->prj_knm)) break;
	}
	if (*pp->key_nm == '\0' || pp->setup == NULL)
	{
		CS_stncp (csErrnam,cs_ptr->prj_knm,MAXPATH);
		CS_erpt (cs_UNKWN_PROJ);
		goto error;
	}

	/* Perform any default replacements before we do any further
	   checks.  We need a copy of the definition which we can modify.
	   Note, that in this process, the validity of the datum or
	   ellipsoid key names is established. */

	memcpy (&lclCsDef,cs_ptr,sizeof (lclCsDef));
	if (lclCsDef.dat_knm [0] != '\0')
	{
		CSdfltpro (cs_DFLTSW_DT,lclCsDef.dat_knm,sizeof (lclCsDef.dat_knm));
		dt_ptr = CS_dtloc (lclCsDef.dat_knm);
		if (dt_ptr == NULL) goto error;
	}
	else if (cs_ptr->elp_knm [0] != '\0')
	{
		CSdfltpro (cs_DFLTSW_EL,lclCsDef.elp_knm,sizeof (lclCsDef.elp_knm));
		el_ptr = CS_eldef (lclCsDef.elp_knm);
		if (el_ptr == NULL) goto error;
		dt_ptr = CSdtloc2 (NULL,el_ptr);
		if (dt_ptr == NULL) goto error;
		CS_free (el_ptr);
		el_ptr = NULL;
	}
	if (pp->code != cs_PRJCOD_UNITY)
	{
		CSdfltpro (cs_DFLTSW_LU,lclCsDef.unit,sizeof (lclCsDef.unit));
	}
	else
	{
		CSdfltpro (cs_DFLTSW_AU,lclCsDef.unit,sizeof (lclCsDef.unit));
	}

	/* Construct the coordinate system definition. */

	csprm = CScsloc (&lclCsDef,dt_ptr);
	if (csprm == NULL) goto error;
	
	/* We've succeeded. */

	CS_free (dt_ptr);
	return (csprm);
error:
	/* We've failed. */

	if (dt_ptr != NULL) CS_free (dt_ptr);
	if (el_ptr != NULL) CS_free (el_ptr);
	if (csprm != NULL)
	{
		CS_free (csprm);
		csprm = NULL;
	}
	return (csprm);
}

/**********************************************************************
**	Equivalent to the above, but all three components were obtained or
**	constructed by the calling module.
**********************************************************************/

struct cs_Csprm_ * EXP_LVL3 CScsloc2 (	struct cs_Csdef_ *cs_ptr,
										struct cs_Dtdef_ *dt_ptr,
										struct cs_Eldef_ *el_ptr)
{
	struct cs_Csprm_ *csprm;
	struct cs_Datum_ *datum;

	/* Prepare for possible error. */

	csprm = NULL;

	/* Construct a cs_Datum_ structure from the information
	   provided.  The cs_Csdef_ structure is checked by CScsloc
	   which is called below.  Since all datum and ellipsoid
	   data is provided, there is no need to check the
	   key names which are/may be in cs_Csdef_. */

	datum = CSdtloc2 (dt_ptr,el_ptr);
	if (datum == NULL) goto error;

	/* Construct the coordinate system definition. */
	
	csprm = CScsloc (cs_ptr,datum);
	if (csprm == NULL) goto error;

	/* If we still here, all is fine. */

	return (csprm);

error:
	/* Free up definitions we've caused to be malloc'ed. */
	if (datum != NULL) CS_free (datum);
	if (csprm != NULL)							/*lint !e774 pcLint bug */
	{
		CS_free (csprm);
		csprm = NULL;
	}
	return (csprm);
}

/**********************************************************************
	The is the main function that does most all the work.
	Note that all defaults must be properly processed before
	this function is called.
**********************************************************************/

struct cs_Csprm_ * EXP_LVL3 CScsloc (	struct cs_Csdef_ *cs_ptr,
										struct cs_Datum_ *dt_ptr)
{
	extern char csErrnam [];
	extern struct cs_Prjtab_ cs_Prjtab [];

	extern double cs_One;					/* 1.0 */
	extern double cs_Two_pi;				/* 6.28..... */

	int list_sz;

	struct cs_Csprm_ *csprm;
	struct cs_Prjtab_ *pp;

	int err_list [4];

	/* Prepare for an error condition. */

	csprm = NULL;

	/* We need a pointer to the projection table entry before
	   we proceed much further.  This is somewhat redundant,
	   as CS_cschk (below) will do the same thing, but if we
	   don't have a valid projection, things get ugly. */

	for (pp = cs_Prjtab;*pp->key_nm != '\0';pp++)
	{
		if (!CS_stricmp (pp->key_nm,cs_ptr->prj_knm)) break;
	}
	if (*pp->key_nm == '\0' || pp->setup == NULL)
	{
		CS_stncp (csErrnam,cs_ptr->prj_knm,MAXPATH);
		CS_erpt (cs_UNKWN_PROJ);
		goto error;
	}

	/* Check the definition before we proceed any further.  Since we've
	   been given a pointer to the datum structure, we instruct the checker
	   to skip the datum/ellipsoid key name check.  They may not have
	   come from the dictionary.  The calling module must have gotten
	   them from somewhere.  Note, this check still requires that a
	   key name (either datum or ellipsoid) be present. */

	list_sz = sizeof (err_list) / sizeof (int);
	if (CS_cschk (cs_ptr,cs_CSCHK_REPORT,err_list,list_sz) != 0)
	{
		goto error;
	}

	/* If we're still here, the coordinate system existed.  So
	   we malloc a structure for the parameters. */

	csprm = (struct cs_Csprm_ *)CS_malc (sizeof (struct cs_Csprm_));
	if (csprm == NULL)
	{
		CS_erpt (cs_NO_MEM);
		goto error;
	}

	/* Move the definition. */

	memcpy (&csprm->csdef,cs_ptr,sizeof (*cs_ptr));

	/* Copy the elements of the datum sturcture. */

	memcpy (&csprm->datum,dt_ptr,sizeof (*dt_ptr));

	/* Now we must set up the units.  The scale element of the
	   cs_Csdef_ structure is used to convert the equatorial
	   radius of the ellipsoid to system units; the definition
	   of ellipsoids now required to be in units of meters.
	   (In previous releases, ellipsoid definitions had a unit
	   specification of their own.  This has been eliminated but
	   the existence of the scale variable has survived.)  Thus,
	   all cartographic calculations are performed in the
	   coordinate system unit.  The unit_scl element is used to
	   convert scalars, such as text height, from the system unit
	   to meters by multiplication.  We recompute these scale
	   values every time the definition is fetched as a means
	   of making sure the database remains consistent. */

	if (pp->code == cs_PRJCOD_UNITY)
	{
		/* Here if we have a lat/long coordinate
		   system.  The unit_scl element is computed
		   to be the distance, in meters, of whatever
		   the angular unit of this coordinate system
		   is.  For example, if the unit is degrees,
		   we compute the length, in meters, of one
		   degree of longitude at the equator.  If the
		   unit is seconds, we compute the length, in
		   meters, of one second of longitude at the
		   equator.  This varies slightly from one ellipsoid
		   to the next. */

		csprm->csdef.unit_scl = CS_unitlu (cs_UTYP_ANG,csprm->csdef.unit);
		if (csprm->csdef.unit_scl == 0.0) goto error;

		/* Now we can compute the two different scale factors.  In
		   the lat/long case (remember that this is not really
		   a projection) we simply store the factor which, by
		   multiplication, will convert degrees to the system
		   unit (i.e. seconds, radians, greads, whatever). */

		csprm->csdef.scale = csprm->csdef.unit_scl;
		csprm->csdef.scale = cs_One / csprm->csdef.scale;

		/* The unit scale factor is used to convert text height,
		   line widths, etc.  Therefore, we need to store a
		   value which will convert the degrees/seconds/grads/whatever
		   to meters.  This is a function of the ellipsoid in use. */

		csprm->csdef.unit_scl *= cs_Two_pi * csprm->datum.e_rad / 360.0;
	}
	else
	{
		/* Here for all cartesian cases. */

		csprm->csdef.unit_scl = CS_unitlu (cs_UTYP_LEN,csprm->csdef.unit);
		if (csprm->csdef.unit_scl == 0.0) goto error;


		csprm->csdef.scale = cs_One / (csprm->csdef.unit_scl *
									   csprm->csdef.map_scl);
	}

	/* Copy the prrojection code and flags for use by projection
	   independent code. */

	csprm->prj_code = pp->code;
	csprm->prj_flags = pp->flags;

	/* Call the Set up routine.  We wouldn't be here if pp wasn't
	   valid. */

	(*pp->setup)(csprm);

	/* That's it. Csprm is already to go. */

	return (csprm);

error:
	if (csprm != NULL) CS_free (csprm);
	return (NULL);
}

/**********************************************************************
**	The function pointed to by the following variable is called
**	after the definition has been obtained, but before any default
**	processing takes palce.
**********************************************************************/
extern int (*cs_DtHook)(struct cs_Dtdef_ *dtdef);

/**********************************************************************
**	datum = CS_dtloc (dat_key);
**
**	char dat_key;				the key name of the datum to be located.
**								I.e. "NAD27" for the North American Datum
**								of 1927.
**	struct m_Datum_ *datum;		returns a pointer to a malloc'ed structure.
**								Will return a NULL pointer in the event of
**								an error of some sort.
**
**	This function accesses both the Datum Dictionary and
**	the Ellipsoid Dictionary to compose a complete
**	m_Datum_ structure.
**
**	The returned pointer points to a malloc'ed area of
**	memory and can be "free'ed" by CS_free when no longer
**	required.
**********************************************************************/

struct cs_Datum_ * EXP_LVL5 CS_dtloc (Const char *dat_nam)

{
	extern char csErrnam [];

	int status;

	struct cs_Dtdef_ *dtdef_p;
	struct cs_Datum_ *datum;

	/* Prepare for any type of error. */

	datum = NULL;

	/* Get the datum definition. */

	dtdef_p = CS_dtdef (dat_nam);
	if (dtdef_p == NULL) goto error;

	/* Before we doing anything else, we give application
	   programmers a chance to do their thing. */

	if (cs_DtHook != NULL)
	{
		status = (*cs_DtHook)(dtdef_p);
		if (status != 0)
		{
			CS_stncp (csErrnam,dat_nam,MAXPATH);
			if (status > 0) CS_erpt (status);
			goto error;
		}
	}

	/* Given the definition, construct a cs_Datum_ structure which
	   includes ellipsoid information. */

	datum = CSdtloc1 (dtdef_p);
	if (datum == NULL) goto error;

	/* Free up the datum definition structure. */

	CS_free (dtdef_p);
	dtdef_p = NULL;

	/* Return the initialized datum structure to the user. */

	return (datum);
error:
	if (dtdef_p != NULL) CS_free (dtdef_p);
	if (datum != NULL)							/*lint !e774 pcLint bug */
	{
		CS_free (datum);
		datum = NULL;
	}
	return (datum);
}

struct cs_Datum_ * EXP_LVL5 CSdtloc1 (Const struct cs_Dtdef_ *dtdef_p)
{
	struct cs_Eldef_ *eldef_p;
	struct cs_Datum_ *datum;

	struct cs_Dtdef_ lclDtDef;

	eldef_p = NULL;				/* In case of error. */
	datum = NULL;

	/* To handle defaults correctly, we need a copy of the cs_Dtdef_
	   structure which we can modify. */

	memcpy (&lclDtDef,dtdef_p,sizeof (lclDtDef));

	/* Get the ellipsoid definition. This may have a default
	   reference. */

	CSdfltpro (cs_DFLTSW_EL,lclDtDef.ell_knm,sizeof (lclDtDef.ell_knm));
	eldef_p = CS_eldef (lclDtDef.ell_knm);
	if (eldef_p == NULL) goto error;

	/* Use CSdtloc2 to actually build the cs_Datum_ structure, thus
	   eliminate duplicate code. */

	datum = CSdtloc2 (&lclDtDef,eldef_p);
	if (datum == NULL) goto error;
	CS_free (eldef_p);

	/* Return the initialized datum structure to the user. */

	return (datum);

error:
	if (eldef_p != NULL) CS_free (eldef_p);
	if (datum != NULL)							/*lint !e774 pcLint bug */
	{
		CS_free (datum);
		datum = NULL;
	}
	return (datum);
}

/**********************************************************************
	All default processing must be completed before
	calling this function.  In this form, the datum
	pointer is optional (i.e. can be NULL) but the
	ellipsoid pointer is always required.
**********************************************************************/

struct cs_Datum_ * EXP_LVL5 CSdtloc2 (Const struct cs_Dtdef_ *dtdef_p,Const struct cs_Eldef_ *eldef_p)
{
	struct cs_Datum_ *datum;

	datum = (struct cs_Datum_ *)CS_malc (sizeof (*datum));
	if (datum == NULL)
	{
		CS_erpt (cs_NO_MEM);
		goto error;
	}

	/* Populate the malloc'ed structure with the proper values. */

	datum->e_rad = eldef_p->e_rad;
	datum->p_rad = eldef_p->p_rad;
	datum->flat  = eldef_p->flat;
	datum->ecent = eldef_p->ecent;
	CS_stncp (datum->el_name,eldef_p->name,sizeof (datum->el_name));
	if (dtdef_p != NULL)
	{
		CS_stncp (datum->key_nm,dtdef_p->key_nm,sizeof (datum->key_nm));
		CS_stncp (datum->ell_knm,dtdef_p->ell_knm,sizeof (datum->ell_knm));
		CS_stncp (datum->dt_name,dtdef_p->name,sizeof (datum->dt_name));
		datum->delta_X = dtdef_p->delta_X;
		datum->delta_Y = dtdef_p->delta_Y;
		datum->delta_Z = dtdef_p->delta_Z;
		datum->rot_X = dtdef_p->rot_X;
		datum->rot_Y = dtdef_p->rot_Y;
		datum->rot_Z = dtdef_p->rot_Z;
		datum->bwscale = dtdef_p->bwscale;
		datum->to84_via = dtdef_p->to84_via;
	}
	else
	{
		datum->key_nm [0] = '\0';
		CS_stncp (datum->ell_knm,eldef_p->key_nm,sizeof (datum->ell_knm));
		CS_stncp (datum->dt_name,"No Datum, cartographically referenced directly to an ellipsoid.",sizeof (datum->dt_name));
		datum->delta_X = 0.0;
		datum->delta_Y = 0.0;
		datum->delta_Z = 0.0;
		datum->rot_X   = 0.0;
		datum->rot_Y   = 0.0;
		datum->rot_Z   = 0.0;
		datum->bwscale = 0.0;
		datum->to84_via = cs_DTCTYP_NONE;
	}
	return (datum);
error:
	if (datum != NULL)							/*lint !e774 pcLint bug */
	{
		CS_free (datum);
		datum = NULL;
	}
	return (datum);
}

int EXP_LVL9 CSllCsFromDt (char* csKeyName,int csKeySize,Const char* dtKeyName)
{
	extern struct cs_Prjtab_ cs_Prjtab [];

	int st;
	int crypt;

	csFILE *strm;
	struct cs_Prjtab_ *pp;

 	__ALIGNMENT__1		/* Required by some Sun compilers. */
	struct cs_Csdef_ cs_def;

	st = -1;
	csKeyName [0] = '\0';
	strm = CS_csopn (_STRM_BINRD);
	if (strm != NULL)
	{
		while ((st = CS_csrd (strm,&cs_def,&crypt)) > 0)
		{
			if (cs_def.dat_knm [0] == '\0')
			{
				/* Cartographically referenced, can't be used. */
				continue;
			}
			if (CS_stricmp (cs_def.dat_knm,dtKeyName))
			{
				/* Referenced to another datum, can't be used. */
				continue;
			}
			/* Determine the projection code. */
			for (pp = cs_Prjtab;*pp->key_nm != '\0';pp++)
			{
				if (!CS_stricmp (pp->key_nm,cs_def.prj_knm)) break;
			}
			if (*pp->key_nm == '\0' || pp->setup == NULL)
			{
				/* Couldn't find a projection code, shouldn't happen. */
				continue;
			}
			if (pp->code != cs_PRJCOD_UNITY)
			{
				/* It is not a geographic definition, can't use it. */
				continue;
			}
			if (cs_def.org_lng != 0.0 || CS_stricmp (cs_def.unit,"DEGREE"))
			{
				/* Not sure we need this test. */
				/* Not referenced to Greenwich, or unit not degree.  Can't use it. */
				continue;
			}
			
			/* If we're still here, we have located what we are looking for. */
			CS_stncp (csKeyName,cs_def.key_nm,csKeySize);
			st = 0;
			break;
		}
		CS_csDictCls (strm);
	}
	return st;
}

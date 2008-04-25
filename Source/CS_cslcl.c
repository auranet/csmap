/**********************************************************************
**
**      ***************************************************************
**      ***************************************************************
**	**                                                           **
**      **         Copyright (C) 1988 Mentor Software, Inc.          **
**      **                   All Rights Reserved                     **
**	**                                                           **
**      ** Access to this material is provided  under the terms of a **
**      ** licenseing and non-disclosure agreement.  It is not to be **
**      ** copied or its content disclosed to others without the     **
**      ** permission of Mentor Software, Inc.  Your compliance with **
**      ** this agreement will enable me provide for my kids'        **
**      ** education.   Linda and Eric thank you for your integrity. **
**      ***************************************************************
**      ***************************************************************
**
**	   Module Name:	%M%
**    Descriptive Name:	Coordinate System; LoCaL
**	   Module Type: %Y%
**
**	Revision Level: %I%
**     Last Delta Date: %E% %U%
**
**	      Get Date: %H% %T%
**
**	  Make Control: %Z%%Y%%Z%%Q%%Z%
**
**	Module Purpose:	Given a min/max window in lat/longs,
**			returns a custom coordinatate system
**			tailored for the specific area.
**
**    Calling Sequence:	csprm = CS_cslcl (min_ll,max_ll,units,datum,map_scl);
**
**	double min_ll [2];
**			the southwestern corner, (lng,lat in degrees)
**			of the region to be mapped.
**	double max_ll [2];
**			the northeastern corner, (lng,lat in degrees)
**			of the region to be mapped.
**	char *units;	the name of the units to be used in the
**			coordinate system.
**	struct cs_Datum_ *datum;
**			the datum to be used in the mapping process.
**	double map_scl;	the mappping scale to use.
**	struct cs_Csprm_ *csprm;
**			returns a pointer to a malloc'ed coordinate
**			system definition.  Use CS_free when you don't
**			need it anymore.
**
**		*  *  *  *  *  *  *
**
**		External References
**
**		  Error Conditions
**
**		      Remarks
**
**	Returns a Transverse Mercator coordinate system with the
**	following parameters:
**
**	1) Central meridian bisects the region to be mapped.
**	2) Latitude origin in the latitude minimum.
**	3) Scale reduction optimized for the specific region.
**	4) Datum as specified.
**	5) Units as specified.
**	6) False northing set to zero (i.e. a Y coordinate of
** 	   zero maps to the minimum latitude).
**	7) False easting set to map minimum longitude to
**	   an X coordinate value of zero.
**
**	The returned argument is suitable for use with the
**	CS_cs2ll, CS_ll2cs, and CS_csscl functions.  This function
**	is designed specifically for converting lat/long coordinates
**	of a small region to a Cartesian form for calculation
**	and/or plotting purposes.
**
**********************************************************************/

#include "cs_map.h"

#ifdef LABEL_MODULE
static char revlvl [] = {"%W%"};
#endif

struct cs_Csprm_ * EXP_LVL3 CS_cslcl (	Const double min_ll [2],
					Const double max_ll [2],
					Const char *units,
					Const struct cs_Datum_ *datum,
					double map_scl)

{
	struct cs_Csprm_ *csprm;

	double del_lng;

	double xy [2];

	/* Prepare for a possible error of some sort. */

	csprm = NULL;

	/* Allocate the coordinate system parameter structure. */

	csprm = (struct cs_Csprm_ *)CS_malc (sizeof (struct cs_Csprm_));
	if (csprm == NULL)
	{
		CS_erpt (cs_NO_MEM);
		goto error;
	}
	
	/* KLW/ASAP: Original code forgot to initialize allocated memory that is assumed to be so in called functions. */
	memset(csprm, 0, sizeof(struct cs_Csprm_));

	/* Insert the appropriate function pointers. */

	csprm->ll2cs = (cs_LL2CS_CAST)CStrmerF;
	csprm->cs2ll = (cs_CS2LL_CAST)CStrmerI;
	csprm->cs_scale = (cs_SCALE_CAST)CStrmerK;
	csprm->cs_sclk = (cs_SCALK_CAST)CStrmerK;
	csprm->cs_sclh = (cs_SCALH_CAST)CStrmerK;
	csprm->cs_scale = (cs_CNVRG_CAST)CStrmerC;

	/* Copy the datum definition. */

	memcpy ((char *)&csprm->datum,(char *)datum,sizeof (struct cs_Datum_));

	/* Calculate the projection parameters, optimized for this
	   specific region. */

	csprm->csdef.prj_prm1 = (min_ll [0] + max_ll [0]) * 0.5;
	del_lng = fabs (max_ll [0] - min_ll [0]);
	csprm->csdef.scl_red = cos (del_lng * (0.25 * ONE_DEGREE));
	csprm->csdef.org_lat = min_ll [1];
	csprm->csdef.x_off = 0.0;
	csprm->csdef.y_off = 0.0;

	/* Insert the appropriate units factor. */

	csprm->csdef.unit_scl = CS_unitlu (cs_UTYP_LEN,units);

	/* Insert the mapping scale. */

	csprm->csdef.map_scl = map_scl;

	/* Calculate the final scale factor. */

	csprm->csdef.scale = 1.0 / (csprm->csdef.unit_scl * csprm->csdef.map_scl);

	/* Perform the initial setup of the coordinate system. */
	/*csprm->prj_code = 0;
	csprm->csdef.ll_min[0] = 0.0;
	csprm->csdef.ll_min[1] = 0.0;
	csprm->csdef.ll_max[0] = 0.0;
	csprm->csdef.ll_max[1] = 0.0;*/
	CStrmerS (csprm);

	/* Map the minimum point through the conversion and set the
	   false easting and northing accordingly.  These can be set
	   after the coordinate conversion is setup. */

	CStrmerF (&csprm->proj_prms.trmer,xy,min_ll);
	csprm->proj_prms.trmer.x_off = -xy [0];
	csprm->proj_prms.trmer.y_off = -xy [1];

	/* Return the coordinate system to the user. */

	return (csprm);

error:
	if (csprm != NULL) CS_free (csprm);
	return (NULL);
}

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

			 File Name: $RCSfile: CSel2wkt.c $
		   Description:
			   Purpose:	Converts the supplied ellipsoid dictionary
						entry to a WKT ASCII representation suitable for
						use as a Well Known Text string; writing the
						resulting ASCII definition to the provided
						stream.

		Revision Level:	$Revision: #2 $
		 Check In Date:	$Date: 2006/11/25 $

		Last Revision:	$Log: CSel2wkt.c $
		Last Revision:	Revision 11.1300  2005/05/25 23:27:04  nto
		Last Revision:	Official Release 11.13
		Last Revision:	Revision 11.1200  2005/01/15 18:27:07  nto
		Last Revision:	Official Release of CS-MAP 11.12, 11:26am 15 Jan 2005
		Last Revision:	Revision 11.1100  2004/11/01 18:53:04  nto
		Last Revision:	Official release 11.11
		Last Revision:	Revision 11.1001  2004/10/07 19:25:13  nto
		Last Revision:	Revision 11.901  2004/08/07 03:35:49  nto
		Last Revision:	Added CS_el2Wkt, a high level version of CSel2Wkt
		Last Revision:	Revision 11.900  2004/03/26 17:02:20  nto
		Last Revision:	Official release: 11.09 - 3/25/2003
		Last Revision:	Revision 11.800  2004/01/13 23:29:09  nto
		Last Revision:	Revision 11.700  2003/12/19 01:49:49  nto
		Last Revision:	Official release 11.07
		Last Revision:	Revision 11.600  2003/12/04 02:46:24  nto
		Last Revision:	Release 11.06.  Never shipped. Source captured in prep for C++ V7.
		Last Revision:	Revision 1.3  2003/11/24 01:14:23  nto
		Last Revision:	Major modifications to fix several problems.
		Last Revision:	Revision 1.2  2003/11/07 03:57:07  nto
		Last Revision:	Modified major portions to add the flavor capability to WKT outout.
		Last Revision:	Revision 1.1  2003/10/01 22:09:59  nto
		Last Revision:	Initial Revision

	 Calling Sequence:	st = CSel2Xml (cs_def,fstr_out);
	struct cs_Eldef_ *el_def;
						the definition which os to be converted to XML
						form.
	FILE *fstr_out;		the stream to which the converted result is to
						be written.
	int st;				returns zero on success, -1 on I/O error on the
						stream.

******************************************************************************/

#ifdef LABEL_MODULE
static char revlvl [] = {"$Id: //depot/Libraries/CsMap/current/src/CSel2Wkt.c#2 $"};
#endif

#include "cs_map.h"
#include "cs_wkt.h"

int EXP_LVL1 CS_el2WktEx (char *bufr,size_t bufrSize,const char *elKeyName,int flavor,unsigned short flags)
{
	int rtnValue = -1;
	struct cs_Eldef_ *elDefPtr = 0;

	if (bufrSize > 0)
	{
		*bufr = '\0';
		elDefPtr = CS_eldef (elKeyName);
		if (elDefPtr != 0)
		{
			rtnValue = CSel2WktEx (bufr,bufrSize,flavor,elDefPtr,flags);
			CS_free (elDefPtr);
			elDefPtr = 0;
		}
	}
	return rtnValue;
}

int EXP_LVL1 CS_el2Wkt (char *bufr,size_t bufrSize,const char *elKeyName,int flavor)
{
	int rtnValue = -1;
	struct cs_Eldef_ *elDefPtr = 0;

	if (bufrSize > 0)
	{
		*bufr = '\0';
		elDefPtr = CS_eldef (elKeyName);
		if (elDefPtr != 0)
		{
			rtnValue = CSel2Wkt (bufr,bufrSize,flavor,elDefPtr);
			CS_free (elDefPtr);
			elDefPtr = 0;
		}
	}
	return rtnValue;
}

int EXP_LVL3 CSel2Wkt (char *bufr,size_t bufrSize,enum ErcWktFlavor flavor,const struct cs_Eldef_ *el_def)
{
	int st;
	
	st = CSel2WktEx (bufr,bufrSize,flavor,el_def,0);
	return st;
}
int EXP_LVL3 CSel2WktEx (char *bufr,size_t bufrSize,enum ErcWktFlavor flavor,const struct cs_Eldef_ *el_def,unsigned short flags)
{
	extern double cs_One;

	/* The real value is infinity, but that this a rather awkward number to deal with.
	   So, we use zero to indicate a sphere.  Quite frankly, the specification
	   (if there reallyis one) for WKT does not handle spheres at all.  We should
	   probably just bag anything references to a spehere. */
	Const char* kCp;
	double rcpFlattening = 0.0;
	
	char wktEllipsoidName [96];
	char cTemp [1024];

	if (el_def->flat != 0.0)
	{
		rcpFlattening = cs_One / el_def->flat;
	}
	
	if (bufrSize >= 1)
	{
		CS_stncp (wktEllipsoidName,el_def->key_nm,sizeof (wktEllipsoidName));
		if ((flags & cs_WKTFLG_MAPNAMES) != 0)
		{
			if (flavor == wktFlvrEsri)
			{
				kCp = CS_msiElpName2Esri (el_def->key_nm);
				if (kCp != 0)
				{
					CS_stncp (wktEllipsoidName,kCp,sizeof (wktEllipsoidName));
				}
			}
			else if (flavor == wktFlvrOracle)
			{
				kCp = CS_msiElpName2Oracle (el_def->key_nm);
				if (kCp != 0)
				{
					CS_stncp (wktEllipsoidName,kCp,sizeof (wktEllipsoidName));
				}
			}
		}
		sprintf (cTemp,"SPHEROID[\"%s\",%.3f,%.8f]",wktEllipsoidName,el_def->e_rad,rcpFlattening);
		CS_stncp (bufr,cTemp,(int)bufrSize);
	}
	return 0;
}

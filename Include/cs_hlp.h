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

			 File Name: $RCSfile: cs_hlp.h $
		   Description:
			   Purpose:

		Revision Level:	$Revision: #3 $
		 Check In Date:	$Date: 2005/07/26 $

		Last Revision:	$Log: cs_hlp.h $
		Last Revision:	Revision 11.1300  2005/05/25 23:27:13  nto
		Last Revision:	Official Release 11.13
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
		Last Revision:	Revision 11.401  2003/05/01 23:06:22  nto
		Last Revision:	Revision 11.300  2003/02/25 04:29:17  nto
		Last Revision:	Official Release 11.03
		Last Revision:	Revision 11.100  2002/11/22 19:38:44  nto
		Last Revision:	Official release: 11.01
		Last Revision:	Revision 10.1501  2002/11/21 00:43:16  nto
		Last Revision:	Added help functionality to the gdcEdit feature.
		Last Revision:	Revision 10.1500  2002/09/22 00:01:21  nto
		Last Revision:	Official Release:= 10.15
		Last Revision:	Revision 10.1400  2002/08/09 18:14:23  nto
		Last Revision:	Revision 10.1200  2002/07/14 03:26:17  nto
		Last Revision:	Revision 10.1100  2002/06/13 14:18:38  nto
		Last Revision:	Release 10.11 Official
		Last Revision:	Revision 10.1000  2002/02/23 21:18:27  nto
		Last Revision:	Official Release of 10.10, 2/22/02 - Norm Olsen
		Last Revision:	Revision 10.900  2001/09/24 04:31:11  nto
		Last Revision:	Revision 10.700  2001/01/25 04:13:49  nto
		Last Revision:	Revision 10.601  2001/01/25 04:07:57  nto
		Last Revision:	Added topic ID's for the new datum algorithm descriptions.
		Last Revision:	Revision 10.600  2000/12/11 06:39:44  nto
		Last Revision:	Release 10.06
		Last Revision:	Revision 10.500  2000/10/27 07:38:21  nto
		Last Revision:	Official Release 10.05
		Last Revision:	Revision 10.400  2000/09/13 01:16:55  nto
		Last Revision:	Release 10.04
		Last Revision:	Revision 10.300  2000/04/04 23:18:26  nto
		Last Revision:	Revision 10.201  2000/04/03 23:07:38  nto
		Last Revision:	Added the MGRS help id's.
		Last Revision:	Revision 10.200  2000/03/02 18:51:18  nto
		Last Revision:	Revision 10.0  1999/10/05 18:27:15  nto
		Last Revision:	Revision 9.99  1999/10/05 17:36:26  nto
		Last Revision:	Revision 1.2  1999/09/12 02:44:32  nto
		Last Revision:	This revision compiles, links, and generates a successful test program.

******************************************************************************/

#ifdef LABEL_MODULE
static char revlvl [] = {"$Id: //depot/Libraries/CsMap/current/inc/cs_hlp.h#3 $"};
#endif

/**********************************************************************
**	Establishes the help context id's of the Windows MFC dialog boxes.
**********************************************************************/

/*	Have we been here before? */

#ifndef __CS_HLPH__
#define __CS_HLPH__

#define csHLPID_CSED_IDENT     199012
#define csHLPID_CSED_GENRL     199013
#define csHLPID_CSED_ORGNS     199014
#define csHLPID_CSED_EXTNT     199015
#define csHLPID_CSED_PARMS     199016
#define csHLPID_CSTEST         199017
#define csHLPID_COORDSY_REF    199018
#define csHLPID_CSATOF         199019
#define csHLPID_CSBROWSER      199020
#define csHLPID_CSED_OVRVW     199021
#define csHLPID_CSMAP          0
#define csHLPID_CSREF_CARTOG   199023
#define csHLPID_CSREF_GEODETIC 199024
#define csHLPID_DATADIR_DLG    199025
#define csHLPID_DEFAULTS       199026
#define csHLPID_DIALOG_SUPPORT 199027
#define csHLPID_DICT_PROT      199028
#define csHLPID_DISTPROT       199029
#define csHLPID_DTEDIT         199030
#define csHLPID_DTSELECTOR     199031
#define csHLPID_ELEDIT         199032
#define csHLPID_ELSELECTOR     199033
#define csHLPID_GEOCSTRICK     199035
#define csHLPID_GEOCS_CONV     199036
#define csHLPID_KEYNAM_REQ     199038
#define csHLPID_KYNAM_CONV     199039
#define csHLPID_LL_COORDSYS    199040
#define csHLPID_NAMEDUP        199041
#define csHLPID_NEWKEYNM       199042
#define csHLPID_OVERVIEW       199043
#define csHLPID_PROVINFO       199044
#define csHLPID_SPCS_CONV      199045
#define csHLPID_STEPONE        199046
#define csHLPID_STEPTHREE      199047
#define csHLPID_STEPTWO        199048
#define csHLPID_USER_DIALOGS   199049
#define csHLPID_USRPROT        199050
#define csHLPID_UTMREF_ZONE    199051
#define csHLPID_UTM_CONV       199052
#define csHLPID_MGRS_TEST      199053

#define csHLPID_GDC_FALLBACK   199054
#define csHLPID_GEOREF         199055
#define csHLPID_GREF_7PARM     199056
#define csHLPID_GREF_BURSA     199057
#define csHLPID_GREF_3PARM     199058
#define csHLPID_GREF_MOLO      199059
#define csHLPID_GREF_MREG      199060
#define csHLPID_GREF_NAD27     199061
#define csHLPID_GREF_HARN      199062
#define csHLPID_GREF_CSRS      199063
#define csHLPID_GREF_NAD83     199064
#define csHLPID_GREF_GDA94     199065
#define csHLPID_GREF_NZGD2K    199066
#define csHLPID_GREF_WGS84     199067
#define csHLPID_GREF_WGS72     199068
#define csHLPID_GREF_6PARM     199069
#define csHLPID_GREF_4PARM     199070
#define csHLPID_GREF_AGD66     199071
#define csHLPID_GREF_AGD84     199072
#define csHLPID_GREF_NZGD49    199073
#define csHLPID_GREF_ATS77     199074
#define csHLPID_GDCCONTENT     199075
#define csHLPID_GDC            199076
#define csHLPID_GDE            199077

#endif

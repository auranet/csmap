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

			 File Name: $RCSfile: CS_erpt.c $
		   Description:
			   Purpose:

		Revision Level:	$Revision: #3 $
		 Check In Date:	$Date: 2005/07/26 $

		Last Revision:	$Log: CS_erpt.c $
		Last Revision:	Revision 11.1300  2005/05/25 23:27:11  nto
		Last Revision:	Official Release 11.13
		Last Revision:	Revision 11.1200  2005/01/15 18:27:11  nto
		Last Revision:	Official Release of CS-MAP 11.12, 11:26am 15 Jan 2005
		Last Revision:	Revision 11.1100  2004/11/01 18:53:09  nto
		Last Revision:	Official release 11.11
		Last Revision:	Revision 11.1001  2004/10/07 19:25:17  nto
		Last Revision:	Revision 11.900  2004/03/26 17:02:24  nto
		Last Revision:	Official release: 11.09 - 3/25/2003
		Last Revision:	Revision 11.800  2004/01/13 23:29:12  nto
		Last Revision:	Revision 11.700  2003/12/19 01:49:52  nto
		Last Revision:	Official release 11.07
		Last Revision:	Revision 11.600  2003/12/04 02:46:27  nto
		Last Revision:	Release 11.06.  Never shipped. Source captured in prep for C++ V7.
		Last Revision:	Revision 11.501  2003/08/22 21:12:55  nto
		Last Revision:	Official Release: 11.05
		Last Revision:	Revision 11.401  2003/05/01 23:06:21  nto
		Last Revision:	Revision 11.300  2003/02/25 04:29:16  nto
		Last Revision:	Official Release 11.03
		Last Revision:	Revision 11.100  2002/11/22 19:38:43  nto
		Last Revision:	Official release: 11.01
		Last Revision:	Revision 10.1500  2002/09/22 00:01:19  nto
		Last Revision:	Official Release:= 10.15
		Last Revision:	Revision 10.1400  2002/08/09 18:14:22  nto
		Last Revision:	Revision 10.1200  2002/07/14 03:26:15  nto
		Last Revision:	Revision 10.1100  2002/06/13 14:18:37  nto
		Last Revision:	Release 10.11 Official
		Last Revision:	Revision 10.1000  2002/02/23 21:18:26  nto
		Last Revision:	Official Release of 10.10, 2/22/02 - Norm Olsen
		Last Revision:	Revision 10.900  2001/09/24 04:31:10  nto
		Last Revision:	Revision 10.700  2001/01/25 04:13:48  nto
		Last Revision:	Revision 10.600  2000/12/11 06:39:42  nto
		Last Revision:	Release 10.06
		Last Revision:	Revision 10.500  2000/10/27 07:38:19  nto
		Last Revision:	Official Release 10.05
		Last Revision:	Revision 10.400  2000/09/13 01:16:54  nto
		Last Revision:	Release 10.04
		Last Revision:	Revision 10.300  2000/04/04 23:18:25  nto
		Last Revision:	Revision 10.200  2000/03/02 18:51:16  nto
		Last Revision:	Revision 1.2  2000/01/30 23:36:34  nto
		Last Revision:	PCLint clean up.
		Last Revision:	Revision 1.1  2000/01/28 02:21:34  nto
		Last Revision:	Initial Revision

******************************************************************************/

#ifdef LABEL_MODULE
static char revlvl [] = {"$Id: //depot/Libraries/CsMap/current/src/CS_erpt.c#3 $"};
#endif

#include "cs_map.h"

/**********************************************************************
**	void CS_erpt (err_num);
**
**	int err_num;	number of the error condition being reported.
**
**	Designed to be modified to meet user requirements.
**********************************************************************/

void EXP_LVL3 CS_erpt (int err_num)

{
	extern char csErrmsg [cs_ERRMSG_SIZE];
	
#ifdef PRINTF
	extern unsigned short cs_ErrSup;

	short sup_bm;

	sup_bm = CSerpt (csErrmsg,sizeof (csErrmsg),err_num);

	if ((sup_bm & cs_ErrSup) == 0)
	{
		fprintf (stderr,"%s\n",csErrmsg);
	}
#else
	CSerpt (csErrmsg,sizeof (csErrmsg),err_num);		/*lint !e534 */
#endif

	/* Return to the calling module for cleanup. */

	return;
}

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

			 File Name: $RCSfile: CSwinHlp.cpp $
		   Description:
			   Purpose:

		Revision Level:	$Revision: #3 $
		 Check In Date:	$Date: 2005/07/26 $

		Last Revision:	$Log: CSwinHlp.cpp $
		Last Revision:	Revision 11.1300  2005/05/25 23:27:05  nto
		Last Revision:	Official Release 11.13
		Last Revision:	Revision 11.1200  2005/01/15 18:27:08  nto
		Last Revision:	Official Release of CS-MAP 11.12, 11:26am 15 Jan 2005
		Last Revision:	Revision 11.1100  2004/11/01 18:53:05  nto
		Last Revision:	Official release 11.11
		Last Revision:	Revision 11.1001  2004/10/07 19:25:14  nto
		Last Revision:	Revision 11.900  2004/03/26 17:02:21  nto
		Last Revision:	Official release: 11.09 - 3/25/2003
		Last Revision:	Revision 11.800  2004/01/13 23:29:09  nto
		Last Revision:	Revision 11.700  2003/12/19 01:49:50  nto
		Last Revision:	Official release 11.07
		Last Revision:	Revision 11.600  2003/12/04 02:46:25  nto
		Last Revision:	Release 11.06.  Never shipped. Source captured in prep for C++ V7.
		Last Revision:	Revision 11.501  2003/08/22 21:12:52  nto
		Last Revision:	Official Release: 11.05
		Last Revision:	Revision 11.401  2003/05/01 23:06:19  nto
		Last Revision:	Revision 11.300  2003/02/25 04:29:13  nto
		Last Revision:	Official Release 11.03
		Last Revision:	Revision 11.100  2002/11/22 19:38:40  nto
		Last Revision:	Official release: 11.01
		Last Revision:	Revision 10.1501  2002/10/06 18:07:05  nto
		Last Revision:	Converted all direct references to 'access' to CS_access.
		Last Revision:	Revision 10.1500  2002/09/22 00:01:16  nto
		Last Revision:	Official Release:= 10.15
		Last Revision:	Revision 10.1400  2002/08/09 18:14:19  nto
		Last Revision:	Revision 10.1200  2002/07/14 03:26:11  nto
		Last Revision:	Revision 10.1100  2002/06/13 14:18:34  nto
		Last Revision:	Release 10.11 Official
		Last Revision:	Revision 10.1000  2002/02/23 21:18:24  nto
		Last Revision:	Official Release of 10.10, 2/22/02 - Norm Olsen
		Last Revision:	Revision 10.900  2001/09/24 04:31:08  nto
		Last Revision:	Revision 10.700  2001/01/25 04:13:43  nto
		Last Revision:	Revision 10.600  2000/12/11 06:39:37  nto
		Last Revision:	Release 10.06
		Last Revision:	Revision 10.500  2000/10/27 07:38:15  nto
		Last Revision:	Official Release 10.05
		Last Revision:	Revision 10.400  2000/09/13 01:16:49  nto
		Last Revision:	Release 10.04
		Last Revision:	Revision 10.300  2000/04/04 23:18:20  nto
		Last Revision:	Revision 10.201  2000/04/03 21:52:19  nto
		Last Revision:	Adjusted to enable setting of help file name even if it doesn't exist.  This is to prevent looking for the default when a non-existent file name is presented.
		Last Revision:	Revision 10.200  2000/03/02 18:51:12  nto
		Last Revision:	Revision 10.1  2000/01/31 00:24:35  nto
		Last Revision:	PCLint clean up.
		Last Revision:	Revision 10.0  1999/10/05 18:27:11  nto
		Last Revision:	Revision 9.99  1999/10/05 17:36:22  nto
		Last Revision:	Revision 1.2  1999/09/12 02:50:32  nto
		Last Revision:	This revision compiles, links, and generates a successful test program.

******************************************************************************/

#ifdef LABEL_MODULE
static char revlvl [] = {"$Id: //depot/Libraries/CsMap/current/src/CSwinHlp.cpp#3 $"};
#endif

#if defined (__MFC__)

#include "cs_map.h"
#include "cs_mfc.h"
#include "cs_hlp.h"

static char csHelpFile [260] = "";
static int csHlpIsAvail = 0;

extern "C" char cs_Dir [];
extern "C" char *cs_DirP;

/**********************************************************************
**	status = CSwinhlp (wHndl,context);
**
**	HWND wHndl;					handle to the window which is requesting
**								help. Passed as first argument to WinHelp ().
**	int context;				context index for the specific item for which
**								help is requested.
**********************************************************************/

int EXP_LVL1 CS_setHelpPath (const char *path)
{
	CS_stncp (csHelpFile,path,sizeof (csHelpFile));
	if (CS_access (path,4) != 0) return FALSE;
	csHlpIsAvail = 1;
	return TRUE;
}
int EXP_LVL1 CS_isHlpAvailable ()
{
	if (csHlpIsAvail == 0)
	{
		if (csHelpFile [0] == '\0')
		{
			if (cs_DirP != NULL)
			{
				CS_stcpy (cs_DirP,"CS-MAP.hlp");
				if (CS_access (cs_Dir,4) == 0)
				{
					csHlpIsAvail = 1;
					CS_stcpy (csHelpFile,cs_Dir);
				}
			}
			else
			{
				csHlpIsAvail = -1;
			}
		}
		else if (CS_access (csHelpFile,4) == 0)
		{
			csHlpIsAvail = 1;
		}
		else
		{
			csHlpIsAvail = -1;
		}
	}
	return (csHlpIsAvail > 0);
}
int EXP_LVL3 CSwinhlp (void* hWnd,unsigned long context)
{
	int rtnValue;

	rtnValue = 0;
	if (CS_isHlpAvailable ())
	{
		rtnValue = (int)::WinHelp ((HWND)hWnd,csHelpFile,HELP_CONTEXT,(DWORD)context);
	}
	return rtnValue;
}
#endif

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

			 File Name: $RCSfile: mfcTest.h $
		   Description:
			   Purpose:

		Revision Level:	$Revision: #4 $
		 Check In Date:	$Date: 2007/01/16 $

		Last Revision:	$Log: mfcTest.h $
		Last Revision:	Revision 11.1300  2005/05/25 23:27:22  nto
		Last Revision:	Official Release 11.13
		Last Revision:	Revision 11.1200  2005/01/15 18:27:18  nto
		Last Revision:	Official Release of CS-MAP 11.12, 11:26am 15 Jan 2005
		Last Revision:	Revision 11.1100  2004/11/01 18:53:17  nto
		Last Revision:	Official release 11.11
		Last Revision:	Revision 11.1001  2004/10/07 19:25:24  nto
		Last Revision:	Revision 11.900  2004/03/26 17:02:30  nto
		Last Revision:	Official release: 11.09 - 3/25/2003
		Last Revision:	Revision 11.800  2004/01/13 23:29:19  nto
		Last Revision:	Revision 11.700  2003/12/19 01:49:59  nto
		Last Revision:	Official release 11.07
		Last Revision:	Revision 11.600  2003/12/04 02:46:34  nto
		Last Revision:	Release 11.06.  Never shipped. Source captured in prep for C++ V7.
		Last Revision:	Revision 11.502  2003/10/01 22:12:40  nto
		Last Revision:	Revision 11.501  2003/08/22 21:13:01  nto
		Last Revision:	Official Release: 11.05
		Last Revision:	Revision 11.401  2003/05/01 23:06:27  nto
		Last Revision:	Revision 11.301  2003/04/28 22:53:41  nto
		Last Revision:	Revision 11.300  2003/02/25 04:29:22  nto
		Last Revision:	Official Release 11.03
		Last Revision:	Revision 11.100  2002/11/22 19:38:49  nto
		Last Revision:	Official release: 11.01
		Last Revision:	Revision 10.1501  2002/11/08 06:17:02  nto
		Last Revision:	Added the GDC file editor.
		Last Revision:	Revision 10.1500  2002/09/22 00:01:26  nto
		Last Revision:	Official Release:= 10.15
		Last Revision:	Revision 10.1400  2002/08/09 18:14:27  nto
		Last Revision:	Revision 10.1200  2002/06/20 18:00:32  nto
		Last Revision:	Official release: 10.12
		Last Revision:	Revision 10.1100  2002/06/13 14:18:49  nto
		Last Revision:	Release 10.11 Official
		Last Revision:	Revision 10.1000  2002/02/23 21:18:31  nto
		Last Revision:	Official Release of 10.10, 2/22/02 - Norm Olsen
		Last Revision:	Revision 10.900  2001/09/24 04:31:15  nto
		Last Revision:	Revision 10.700  2001/01/25 04:13:58  nto
		Last Revision:	Revision 10.601  2001/01/25 04:11:58  nto
		Last Revision:	Added the recover operation.
		Last Revision:	Revision 10.600  2000/12/11 06:39:53  nto
		Last Revision:	Release 10.06
		Last Revision:	Revision 10.500  2000/10/27 07:38:39  nto
		Last Revision:	Official Release 10.05
		Last Revision:	Revision 10.400  2000/09/13 01:17:04  nto
		Last Revision:	Release 10.04
		Last Revision:	Revision 10.301  2000/09/12 21:56:51  nto
		Last Revision:	Added codes for Sual Browser test.
		Last Revision:	Revision 10.300  2000/04/04 23:18:41  nto
		Last Revision:	Revision 10.201  2000/04/03 23:26:41  nto
		Last Revision:	Added the MGRS test option.
		Last Revision:	Revision 10.200  2000/03/02 18:51:25  nto
		Last Revision:	Revision 10.0  1999/10/05 18:27:20  nto
		Last Revision:	Revision 9.99  1999/10/05 17:36:31  nto
		Last Revision:	Revision 1.2  1999/09/12 04:27:00  nto
		Last Revision:	This revision compiles, links, and generates a successful test program.

******************************************************************************/

#ifdef LABEL_MODULE
static char revlvl [] = {"$Id: //depot/Libraries/CsMap/current/inc/mfcTest.h#4 $"};
#endif

/**********************************************************************
**	Defines MFC classes for the MFS Test Module.
**********************************************************************/

// Codes for the menu options.  The values are arbitrary, but unique.

#define IDM_DIRECTORIES  11
#define IDM_ED_COORDSYS  12
#define IDM_ED_DATUMS    13
#define IDM_ED_ELIPSOID  14
#define IDM_ED_GDC       15
#define IDM_TEST_CS      16
#define IDM_EXIT         17
#define IDM_CS_BROWSE    18
#define IDM_TEST_MG      19
#define IDM_CS_BROWSE2   20
#define IDM_RECOVER      21
#define IDM_TESTFUNC     23

class CmfcTest: public CWinApp
{
public:
	CmfcTest (void);
	BOOL InitInstance (void);
	int ExitInstance (void);

	HINSTANCE m_Instance;
	bool m_IsWindowsNT;
	char m_FullPath [260];
	char m_Directory [260];
	char m_FileName [260];
	CFrameWnd *m_MainFrame;
};
class CmfcTestWnd : public CFrameWnd
{
public:
	CmfcTestWnd ();
protected:
	afx_msg void OnDirectories ();
	afx_msg void OnCsEdit ();
	afx_msg void OnDtEdit ();
	afx_msg void OnElEdit ();
	afx_msg void OnGdcEdit ();
	afx_msg void OnCsTest ();
	afx_msg void OnMgTest ();
	afx_msg void OnExit   ();
	afx_msg void OnBrowse ();
	afx_msg void OnDualBrowse ();
	afx_msg void OnRecover ();
	afx_msg void OnTestFunc ();

	DECLARE_MESSAGE_MAP ();

private:
	char m_CsKeyName [24];
	char m_DtKeyName [24];
	char m_ElKeyName [24];
	char m_SrcSystem [24];
	char m_TrgSystem [24];
	double m_SrcXYZ [3];
	char m_BrowseKeyNm [24];
	char m_MgrsEllipsoid [24];
	char m_SrcKeyName [24];
	char m_TrgKeyName [24];
	char m_GdcName [64];
	long m_FtoaFrmt;
};


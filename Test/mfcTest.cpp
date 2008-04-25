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

			 File Name: $RCSfile: mfcTest.cpp $
		   Description:
			   Purpose:

		Revision Level:	$Revision: #7 $
		 Check In Date:	$Date: 2007/01/16 $

		Last Revision:	$Log: mfcTest.cpp $
		Last Revision:	Revision 11.1300  2005/05/25 23:27:22  nto
		Last Revision:	Official Release 11.13
		Last Revision:	Revision 11.1200  2005/01/15 18:27:18  nto
		Last Revision:	Official Release of CS-MAP 11.12, 11:26am 15 Jan 2005
		Last Revision:	Revision 11.1101  2005/01/15 06:02:55  nto
		Last Revision:	Cleaned-up test function remnants, write an Orcale WKT tester.
		Last Revision:	Revision 11.1100  2004/11/01 18:53:17  nto
		Last Revision:	Official release 11.11
		Last Revision:	Revision 11.1001  2004/10/07 19:25:24  nto
		Last Revision:	Revision 11.901  2004/10/07 02:41:30  nto
		Last Revision:	Added a version of TestFunction for WKT development.
		Last Revision:	Revision 11.900  2004/03/26 17:02:30  nto
		Last Revision:	Official release: 11.09 - 3/25/2003
		Last Revision:	Revision 11.800  2004/01/13 23:29:19  nto
		Last Revision:	Revision 11.700  2003/12/19 01:49:59  nto
		Last Revision:	Official release 11.07
		Last Revision:	Revision 11.601  2003/12/19 01:13:48  nto
		Last Revision:	Converted to the new ANSI C++ standard form of STL.
		Last Revision:	Revision 11.600  2003/12/04 02:46:34  nto
		Last Revision:	Release 11.06.  Never shipped. Source captured in prep for C++ V7.
		Last Revision:	Revision 11.505  2003/11/07 04:51:12  nto
		Last Revision:	Added some code to the test function which generates WKT datums.
		Last Revision:	Revision 11.504  2003/10/02 04:58:51  nto
		Last Revision:	Revision 11.503  2003/10/01 22:39:05  nto
		Last Revision:	Caused all test functions to be skipped.
		Last Revision:	Revision 11.502  2003/10/01 22:12:38  nto
		Last Revision:	Added WKT stesting stuff.
		Last Revision:	Revision 11.501  2003/08/22 21:13:01  nto
		Last Revision:	Official Release: 11.05
		Last Revision:	Revision 11.402  2003/08/22 21:10:58  nto
		Last Revision:	Cleaned up some bogus testing code that got left in.
		Last Revision:	Revision 11.401  2003/05/01 23:06:27  nto
		Last Revision:	Revision 11.302  2003/04/29 23:35:03  nto
		Last Revision:	Take out the FTOA dialog ofr release 11.04
		Last Revision:	Revision 11.301  2003/04/28 22:53:32  nto
		Last Revision:	Added the Nad27ToCsrs datum object to the recover function.
		Last Revision:	Also, added the number formatting dialog.
		Last Revision:	Revision 11.300  2003/02/25 04:29:22  nto
		Last Revision:	Official Release 11.03
		Last Revision:	Revision 11.100  2002/11/22 19:38:49  nto
		Last Revision:	Official release: 11.01
		Last Revision:	Revision 10.1501  2002/11/08 06:17:02  nto
		Last Revision:	Added the GDC file editor.
		Last Revision:	Revision 10.1500  2002/09/22 00:01:26  nto
		Last Revision:	Official Release:= 10.15
		Last Revision:	Revision 10.1401  2002/09/20 04:31:34  nto
		Last Revision:	Added close of cs_Ostn02_ object before exit.
		Last Revision:	Revision 10.1400  2002/08/09 18:14:27  nto
		Last Revision:	Revision 10.1200  2002/06/20 18:00:32  nto
		Last Revision:	Official release: 10.12
		Last Revision:	Revision 10.1100  2002/06/13 14:18:49  nto
		Last Revision:	Release 10.11 Official
		Last Revision:	Revision 10.1000  2002/02/23 21:18:31  nto
		Last Revision:	Official Release of 10.10, 2/22/02 - Norm Olsen
		Last Revision:	Revision 10.901  2002/02/19 05:43:22  nto
		Last Revision:	Added code to releasse the new objects for OSTN97, OSGM91, and JGD2K
		Last Revision:	Revision 10.900  2001/09/24 04:31:15  nto
		Last Revision:	Revision 10.701  2001/09/18 19:37:29  nto
		Last Revision:	Set the cs_Unique character to colon and the default.
		Last Revision:	Revision 10.700  2001/01/25 04:13:58  nto
		Last Revision:	Revision 10.601  2001/01/25 04:11:41  nto
		Last Revision:	Added the recover operation.
		Last Revision:	Revision 10.600  2000/12/11 06:39:52  nto
		Last Revision:	Release 10.06
		Last Revision:	Revision 10.500  2000/10/27 07:38:39  nto
		Last Revision:	Official Release 10.05
		Last Revision:	Revision 10.400  2000/09/13 01:17:04  nto
		Last Revision:	Release 10.04
		Last Revision:	Revision 10.301  2000/09/12 21:56:31  nto
		Last Revision:	Added test for Dual Browser.
		Last Revision:	Revision 10.300  2000/04/04 23:18:41  nto
		Last Revision:	Revision 10.201  2000/04/03 23:26:14  nto
		Last Revision:	Improved data directory detection, added the MGRS test option.
		Last Revision:	Revision 10.200  2000/03/02 18:51:25  nto
		Last Revision:	Revision 10.1  2000/02/14 07:27:51  nto
		Last Revision:	Added the new 3D test option.  Removed the old datum stuff.
		Last Revision:	Added the new datum stuff.
		Last Revision:	Revision 10.0  1999/10/05 18:27:20  nto
		Last Revision:	Revision 9.99  1999/10/05 17:36:31  nto
		Last Revision:	Revision 1.2  1999/09/12 04:25:24  nto
		Last Revision:	This revision compiles, links, and generates a successful test program.

******************************************************************************/

#ifdef LABEL_MODULE
static char revlvl [] = {"$Id: //depot/Libraries/CsMap/current/src/mfcTest.cpp#7 $"};
#endif

/**********************************************************************
**    Calling Sequence:	mfcTest	data_directory
**********************************************************************/

#include <afxwin.h>
#include "mfcTest.h"
#include "cs_map.h"

#if defined (__CPP__)
#include <string>
#include <fstream>
using std::iostream;
using std::ifstream;
using std::ofstream;
using std::ios_base;
using std::istream;
using std::ostream;
using std::wistream;
using std::wostream;
using std::wifstream;
using std::wofstream;
using std::endl;
using std::ends;
using std::flush;
#include "rcWellKnownText.hpp"
#include "CS_wkt.h"
#endif

extern "C" short cs_Protect;
extern "C" char cs_Unique;

///////////////////////////////////////////////////////////////////////////////
// Application class implementation.
CmfcTest::CmfcTest()
{
	// We don't really need to do much here. The CWinApp constructor
	// does most everything.
	m_Instance = 0;
	m_IsWindowsNT = false;
	m_FullPath [0] = '\0';
	m_Directory [0] = '\0';
	m_FileName [0] = '\0';
}
BOOL CmfcTest::InitInstance ()
{
	int st;
	char *cp;
	OSVERSIONINFO version;
	char ctemp [1024];

	cs_Protect = -1;
	cs_Unique = '\0';

	// Here we simply capture some of the environment.  We do, however,
	// create our own menu. This enables us to have a menu without
	// having to have a resource file, and a class wizard file, and
	// all of that crap.

	m_Instance = AfxGetInstanceHandle ();

	// Get a full path name to the EXE file we came from.
	if (GetModuleFileName (m_Instance,ctemp,sizeof (ctemp)) < 0) return (FALSE);
	strncpy (m_FullPath,ctemp,sizeof (m_FullPath));
	m_FullPath [sizeof (m_FullPath) - 1] = '\0';

	// Extract the directory portion only.
	cp = strrchr (ctemp,'\\');
	if (cp == NULL) return (FALSE);
	*cp++ = '\0';
	strncpy (m_Directory,ctemp,sizeof (m_Directory));
	m_Directory [sizeof (m_Directory) - 1] = '\0';

	// Capture the file name.
	strncpy (m_FileName,cp,sizeof (m_FileName));
	m_FileName [sizeof (m_FileName) - 1] = '\0';

	// See if the directory whence we came has the mapping data.
	st = CS_altdr (m_Directory);
	if (st != 0)
	{
		// Nope, try another location.
		strcpy (ctemp,m_Directory);
		strcat (ctemp,"\\DATA");
		st = CS_altdr (ctemp);
	}
	if (st != 0)
	{
		// Still no luck, try a sub-directory of the whence we came.
		strcpy (ctemp,m_Directory);
		strcat (ctemp,"\\dictnary");
		st = CS_altdr (ctemp);
	}
	if (st != 0)
	{
		// Still no luck, try yet another place.
		strcpy (ctemp,m_Directory);
		strcat (ctemp,"\\..\\dictnary");
		st = CS_altdr (ctemp);
	}
	if (st != 0)
	{
		// Still no luck, see if there is an environmental variable.
		st = CS_altdr (NULL);
	}
	if (st != 0)
	{
		// Still no luck, try the current working directory.
		st = CS_altdr ("");
	}
	if (st != 0)
	{
		// Still no luck, try the developement system case.
#ifdef _DEBUG
		strcpy (ctemp,"C:\\dev\\bin\\NewCsMap\\Data\\Test");
#else
		strcpy (ctemp,"C:\\dev\\bin\\NewCsMap\\Data\\Release");
#endif
		st = CS_altdr (ctemp);
	}

	if (st != 0)
	{
		// No luck at all, issue a message box warning.  We do not
		// exit as this thing provides a directory dialog which can
		// be used to fix the problem.
		MessageBox (0,"Could not locate the mapping data directory.","Mapping Data Error",MB_OK | MB_ICONINFORMATION);
	}

	// Determine the opperating system in use.
	version.dwOSVersionInfoSize = sizeof (version);
	if (GetVersionEx (&version))
	{
		m_IsWindowsNT = (version.dwPlatformId == VER_PLATFORM_WIN32_NT);
	}

	// Make the main window, such as it is, visible.
	m_pMainWnd = new CmfcTestWnd;
	m_pMainWnd->ShowWindow (m_nCmdShow);
	m_pMainWnd->UpdateWindow ();

	// Build a menu programmatically.  This way, we don't need a silly
	// resource file, for the menu anyway.
	CMenu mainMenu;
	CMenu popMenu;
	popMenu.CreatePopupMenu ();
	popMenu.AppendMenu (MF_STRING,IDM_DIRECTORIES,"Directories");
	popMenu.AppendMenu (MF_STRING,IDM_CS_BROWSE,"csBrowser");
	popMenu.AppendMenu (MF_STRING,IDM_CS_BROWSE2,"csDualBrowser");
	popMenu.AppendMenu (MF_STRING,IDM_ED_COORDSYS,"csEdit");
	popMenu.AppendMenu (MF_STRING,IDM_ED_DATUMS,"dtEdit");
	popMenu.AppendMenu (MF_STRING,IDM_ED_ELIPSOID,"elEdit");
	popMenu.AppendMenu (MF_STRING,IDM_ED_GDC,"gdcEdit");
	popMenu.AppendMenu (MF_STRING,IDM_TEST_CS,"csTest");
	popMenu.AppendMenu (MF_STRING,IDM_TEST_MG,"mgTest");
//	popMenu.AppendMenu (MF_STRING,IDM_FTOA_FRMT,"Ftoa Format");
	popMenu.AppendMenu (MF_STRING,IDM_RECOVER,"Recover");
	popMenu.AppendMenu (MF_STRING,IDM_TESTFUNC,"Test Function");
	popMenu.AppendMenu (MF_STRING,IDM_EXIT,"E&xit");
	mainMenu.CreateMenu ();
	mainMenu.AppendMenu (MF_POPUP,(UINT)popMenu.Detach (),"Test");
	m_pMainWnd->SetMenu (&mainMenu);
	mainMenu.Detach ();

	return TRUE;
}

extern "C" struct csNad27ToNad83_* csNad27ToNad83;
extern "C" struct csNad83ToHarn_* csNad83ToHarn;
extern "C" struct csAgd66ToGda94_* csAgd66ToGda94;
extern "C" struct csAgd84ToGda94_* csAgd84ToGda94;
extern "C" struct csNzgd49ToNzgd2K_* csNzgd49ToNzgd2K;
extern "C" struct csAts77ToCsrs_* csAts77ToCsrs;
extern "C" struct csNad83ToCsrs_* csNad83ToCsrs;
extern "C" struct csVertconUS_* csVertconUS;
extern "C" struct cs_Ostn97_ *cs_Ostn97Ptr;
extern "C" struct cs_Osgm91_ *cs_Osgm91Ptr;
extern "C" struct cs_Ostn02_ *cs_Ostn02Ptr;
extern "C" struct csTokyoToJgd2k_ *csTokyoToJgd2k;
extern "C" struct csNad27ToAts77_ *csNad27ToAts77;
extern "C" struct csNad27ToCsrs_* csNad27ToCsrs;

extern "C" int csNad27ToNad83Cnt;
extern "C" int csNad83ToHarnCnt;
extern "C" int csAgd66ToGda94Cnt;
extern "C" int csAgd84ToGda94Cnt;
extern "C" int csNzgd49ToNzgd2KCnt;
extern "C" int csAts77ToCsrsCnt;
extern "C" int csNad83ToCsrsCnt;
extern "C" int csVertconUSCnt;
extern "C" int csTokyoToJgd2kCnt;
extern "C" int csNad27ToAts77Cnt;
extern "C" int csNad27ToCsrsCnt;

int CmfcTest::ExitInstance ()
{
	// Clean up before exit.
	CS_recvr ();

	CSdeleteNad27ToNad83 (csNad27ToNad83);
	CSdeleteNad83ToHarn (csNad83ToHarn);
	CSdeleteAgd66ToGda94 (csAgd66ToGda94);
	CSdeleteAgd84ToGda94 (csAgd84ToGda94);
	CSdeleteNzgd49ToNzgd2K (csNzgd49ToNzgd2K);
	CSdeleteVertconUS (csVertconUS);
	return 0;
}
///////////////////////////////////////////////////////////////////////////////
// Main Window class implementation.
BEGIN_MESSAGE_MAP (CmfcTestWnd,CFrameWnd)
	ON_COMMAND (IDM_DIRECTORIES,OnDirectories)
	ON_COMMAND (IDM_CS_BROWSE  ,OnBrowse)
	ON_COMMAND (IDM_CS_BROWSE2 ,OnDualBrowse)
	ON_COMMAND (IDM_ED_COORDSYS,OnCsEdit)
	ON_COMMAND (IDM_ED_DATUMS,  OnDtEdit)
	ON_COMMAND (IDM_ED_ELIPSOID,OnElEdit)
	ON_COMMAND (IDM_ED_GDC,     OnGdcEdit)
	ON_COMMAND (IDM_TEST_CS,    OnCsTest)
	ON_COMMAND (IDM_TEST_MG,    OnMgTest)
	ON_COMMAND (IDM_RECOVER,    OnRecover)
	ON_COMMAND (IDM_TESTFUNC,   OnTestFunc)
	ON_COMMAND (IDM_EXIT,       OnExit)
END_MESSAGE_MAP ()


extern "C" struct cs_Ostn97_ *CSnewOstn97 (const char *filePath);
extern "C" double CStestOstn97 (struct cs_Ostn97_ *__This);

CmfcTestWnd::CmfcTestWnd ()
{
	Create (NULL,"CS-MAP MFC Test Application",
			WS_OVERLAPPEDWINDOW,
			CRect (20,20,320,240));	
	strcpy (m_CsKeyName,"US48");
	strcpy (m_DtKeyName,"WGS84");
	strcpy (m_ElKeyName,"WGS84");
	strcpy (m_SrcSystem,"UTM27-13");
	strcpy (m_TrgSystem,"LL83");
	m_SrcXYZ [0] = 500000.0;
	m_SrcXYZ [1] = 3900000.0;
	m_SrcXYZ [2] = 0.0;
	strcpy (m_MgrsEllipsoid,"WGS84");
	strcpy (m_BrowseKeyNm,"LL");
	strcpy (m_SrcKeyName,"UTM27-13");
	strcpy (m_TrgKeyName,"LL83");
	strcpy (m_GdcName,"Nad27ToNad83.gdc");
	m_FtoaFrmt = cs_ATOF_LNGDFLT;
}
void CmfcTestWnd::OnDirectories ()
{
	// Non-sense stuff is for testing/debugging.
	int status;
	status = CS_csDataDir (0);
	return;
}
void CmfcTestWnd::OnBrowse ()
{
	CS_csBrowser (m_BrowseKeyNm);
}
void CmfcTestWnd::OnDualBrowse ()
{
	CS_csDualBrowser (m_SrcKeyName,m_TrgKeyName);
}
void CmfcTestWnd::OnCsEdit ()
{
	CS_csEditor (m_CsKeyName);
}
void CmfcTestWnd::OnDtEdit ()
{
	CS_dtEditor (m_DtKeyName);
}
void CmfcTestWnd::OnElEdit ()
{
	CS_elEditor (m_ElKeyName);
}
void CmfcTestWnd::OnGdcEdit ()
{
	CS_gdcEditor (m_GdcName);
}
void CmfcTestWnd::OnCsTest ()
{
	CS_csTest (m_SrcSystem,m_TrgSystem,m_SrcXYZ);
}
int CS_geoCtrDlg (char *elKeyName,double geographic [3],double geoCtr [3]);
void CmfcTestWnd::OnMgTest ()
{
	CS_mgTest (m_MgrsEllipsoid);
}

void CmfcTestWnd::OnRecover ()
{
	CS_recvr ();

	CSdeleteNad27ToNad83 (csNad27ToNad83);
	csNad27ToNad83 = NULL;
	csNad27ToNad83Cnt = 0;
	CSdeleteNad83ToHarn (csNad83ToHarn);
	csNad83ToHarn = NULL;
	csNad83ToHarnCnt = 0;
	CSdeleteAgd66ToGda94 (csAgd66ToGda94);
	csAgd66ToGda94 = NULL;
	csAgd66ToGda94Cnt = 0;
	CSdeleteAgd84ToGda94 (csAgd84ToGda94);
	csAgd84ToGda94 = NULL;
	csAgd84ToGda94Cnt = 0;
	CSdeleteNzgd49ToNzgd2K (csNzgd49ToNzgd2K);
	csNzgd49ToNzgd2K = NULL;
	csNzgd49ToNzgd2KCnt = 0;
	CSdeleteAts77ToCsrs (csAts77ToCsrs);
	csAts77ToCsrs = NULL;
	csAts77ToCsrsCnt = 0;
	CSdeleteNad83ToCsrs (csNad83ToCsrs);
	csNad83ToCsrs = NULL;
	csNad83ToCsrsCnt = 0;
	CSdeleteVertconUS (csVertconUS);
	csVertconUS = NULL;
	csVertconUSCnt = 0;
	CSdeleteOstn97 (cs_Ostn97Ptr);
	cs_Ostn97Ptr = NULL;
	CSdeleteOsgm91 (cs_Osgm91Ptr);
	cs_Ostn97Ptr = NULL;
	CSdeleteOstn02 (cs_Ostn02Ptr);
	cs_Ostn02Ptr = NULL;
	csTokyoToJgd2kCnt = 1;
	CSdeleteTokyoToJgd2k (csTokyoToJgd2k);
	csTokyoToJgd2k = NULL;
	CSdeleteNad27ToAts77 (csNad27ToAts77);
	csNad27ToAts77 = NULL;
	csNad27ToAts77Cnt = 0;
	CSdeleteNad27ToCsrs (csNad27ToCsrs);
	csNad27ToCsrs = NULL;
	csNad27ToCsrsCnt = 0;
}
void CmfcTestWnd::OnTestFunc ()
{
}
void CmfcTestWnd::OnExit ()
{
	SendMessage (WM_CLOSE,0,0);
}
//////////////////////////////////////////////////////////////////////////////
// Declare the single instance of the application object.
CmfcTest mfcTest;

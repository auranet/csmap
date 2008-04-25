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

			 File Name: $RCSfile: CS_system.c $
		   Description:
			   Purpose:

		Revision Level:	$Revision: #4 $
		 Check In Date:	$Date: 2006/11/16 $

		Last Revision:	$Log: CS_system.c $
		Last Revision:	Revision 11.1300  2005/05/25 23:27:18  nto
		Last Revision:	Official Release 11.13
		Last Revision:	Revision 11.1200  2005/01/15 18:27:16  nto
		Last Revision:	Official Release of CS-MAP 11.12, 11:26am 15 Jan 2005
		Last Revision:	Revision 11.1100  2004/11/01 18:53:14  nto
		Last Revision:	Official release 11.11
		Last Revision:	Revision 11.1001  2004/10/07 19:25:21  nto
		Last Revision:	Revision 11.901  2004/08/07 03:39:48  nto
		Last Revision:	Added CS_protect and CS_unique functions.
		Last Revision:	Revision 11.900  2004/03/26 17:02:28  nto
		Last Revision:	Official release: 11.09 - 3/25/2003
		Last Revision:	Revision 11.800  2004/01/13 23:29:17  nto
		Last Revision:	Revision 11.700  2003/12/19 01:49:57  nto
		Last Revision:	Official release 11.07
		Last Revision:	Revision 11.600  2003/12/04 02:46:32  nto
		Last Revision:	Release 11.06.  Never shipped. Source captured in prep for C++ V7.
		Last Revision:	Revision 11.501  2003/08/22 21:12:59  nto
		Last Revision:	Official Release: 11.05
		Last Revision:	Revision 11.401  2003/05/01 23:06:25  nto
		Last Revision:	Revision 11.300  2003/02/25 04:29:20  nto
		Last Revision:	Official Release 11.03
		Last Revision:	Revision 11.100  2002/11/22 19:38:48  nto
		Last Revision:	Official release: 11.01
		Last Revision:	Revision 10.1502  2002/11/06 23:54:47  nto
		Last Revision:	Added two functions for use on a UNIX platform: CS_fopen & CS_ftw.
		Last Revision:	Revision 10.1501  2002/10/13 00:32:46  nto
		Last Revision:	Removed the CS_calc and CS_fdcls functions.
		Last Revision:	Revision 10.1500  2002/09/22 00:01:24  nto
		Last Revision:	Official Release:= 10.15
		Last Revision:	Revision 10.1400  2002/08/09 18:14:25  nto
		Last Revision:	Revision 10.1200  2002/07/14 03:26:22  nto
		Last Revision:	Revision 10.1100  2002/06/13 14:18:41  nto
		Last Revision:	Release 10.11 Official
		Last Revision:	Revision 10.1000  2002/02/23 21:18:30  nto
		Last Revision:	Official Release of 10.10, 2/22/02 - Norm Olsen
		Last Revision:	Revision 1.1  2002/02/22 22:04:15  nto
		Last Revision:	Initial Revision

                       R E M A R K S 

	This module carries several stub functions which are used to
	insulate CS-MAP from system dependencies.

******************************************************************************/

#ifdef LABEL_MODULE
static char revlvl [] = {"$Id: //depot/Libraries/CsMap/current/src/CS_system.c#4 $"};
#endif

#include "cs_map.h"

int EXP_LVL1 CS_protect (int newValue)
{
	extern short cs_Protect;

	int rtnValue;
	
	rtnValue = cs_Protect;
	cs_Protect = newValue;
	return rtnValue;
}
int EXP_LVL1 CS_unique (int newValue)
{
	extern char cs_Unique;

	int rtnValue;
	
	rtnValue = cs_Unique;
	cs_Unique = newValue;
	return rtnValue;
}

/* Establish definitions for all functions which the application programmer
   did not provide.  Application programmers are expected to make their
   own definitions in the "cs_ClientBeg.h" or "cs_ClientEnd.h" header
   files. */

void * EXP_LVL1 CS_malc (size_t blk_size)
{
#ifndef _csMalloc
#	define _csMalloc(_n) malloc(_n)
#endif
	return (_csMalloc (blk_size));
}

void * EXP_LVL1 CS_ralc (void *ptr,size_t new_size)
{
#ifndef _csRealloc
#	define _csRealloc(_m,_n) realloc(_m,_n)
#endif
	return (_csRealloc (ptr,new_size));
}

#if _RUN_TIME != _rt_WINCE
void * EXP_LVL1 CS_calc (size_t blk_count,size_t blk_size)
{
#ifndef _csCalloc
#	define _csCalloc(_n,_s) calloc(_n,_s)
#endif
	return (_csCalloc (blk_count,blk_size));
}
#endif

void EXP_LVL1 CS_free (void *ptr)
{
#ifndef _csFree
#	define _csFree(_m) {if (_m) {free(_m); _m = 0;} }
#endif

	void *lclPtr;

	lclPtr = ptr;
	_csFree (lclPtr);
	return;
}

/******************************************************************************
	The following function is, essentially, a case insensitive file
	open function.  It was written by a Mentor client who distributes
	product on a wide variety of platforms, specifically several
	different flavors of UNIX.  Thus, a case insensitive file open
	is very useful.

	NOTE   NOTE   NOTE   NOTE   NOTE   NOTE   NOTE   NOTE   NOTE

	Mentor Software has no way of testing this function or verifying
	its veracity.  Use this function at your own risk.
******************************************************************************/

#if _FILE_SYSTEM == _fs_UNIX
#include <dirent.h>
csFILE *CS_fopen(const char *filename, const char *mode)
{
	extern char cs_DirsepC;
	struct stat statbuf;
	csFILE *result = NULL;
	char *fixed_filename = (char*) filename;

	/* If we are attempting to read from the file, and the file passed
	 * in does not exist, look for a different file in the same directory
	 * that has the same filename with a different case.
	 */

	if ( (*mode == *_STRM_TXTRD) && stat(filename,&statbuf) )
	{
		/* Make a copy of the filename passed in, and separate it into
		 * directory and path components.
		 */

		char *last_path_sep;

		fixed_filename = (char*) malloc(strlen(filename)+1);
		strcpy(fixed_filename,filename);
		last_path_sep = strrchr(fixed_filename,cs_DirsepC);
		if ( last_path_sep )
		{
			/* Unless the directory is the current directory, we'd
			 * better make sure that at least the directory exists!
			 */
			char *filename_part = last_path_sep + 1;
			*last_path_sep = '\0';
			if ( ! stat(fixed_filename,&statbuf) )
			{
				/* Search the contents of the directory for a file which
				 * matches the one passed in, allowing for different
				 * case.
				 */
#if 1
				DIR *directory = opendir(fixed_filename);
				if ( directory )
				{
					struct dirent *entry;
					while ( (entry = readdir(directory)) != 0 )
					{
						if ( ! CS_stricmp(entry->d_name,filename_part) )
						{
							 /* We have a match!  It should be safe to assume that
							  * their lengths are the same, so we'll just copy it
							  * in-place.
							  */
							strcpy(filename_part,entry->d_name);
							break;
						}
					}
					closedir(directory);
				}
#else
				struct dirent *name_list = NULL;
				int num_matches = scandir( fixed_filename, name_list, NULL, NULL);
				if (num_matches > 0)
				{
					int ii;
					for (ii=0;ii < num_matches;ii++ )
					{
						if (!CS_stricmp (name_list[ii].d_name,filename_part))
						{
							 /* We have a match!  It should be safe to assume that
							  * their lengths are the same, so we'll just copy it
							  * in-place.
							  */
							strcpy (filename_part,name_list[ii].d_name);
							break;
						}
					}
					free (name_list);
				}
#endif
				/* Replace the directory/path separator */
				*last_path_sep = cs_DirsepC;
			}
		}
	}
	result = (csFILE*) fopen(fixed_filename,mode);
	if ( filename != fixed_filename )
	{
		free(fixed_filename);
	}
	return result;
}
#endif

#if _RUN_TIME == _rt_MOSXUNIX
/******************************************************************************
	Apple doesn't support findfirst or ftw.  So, the following function
	has been written to support use of CS-MAP on the Apple.  It should be
	noted, that the ftw functionality is no longer a part of the standard
	library.  As of this writing (11/6/02), there are only two functions
	in the library which use this functionality: CS_gdcGenerator & CS_rlsUpdt.
	
	Neither function is a part of the normal coordinate conversion library,
	CS_gdcGenerator was written to support the automatic generation of .gdc
	files and should no longer be needed.  CS_rlsUpdt is used to update
	older dictionary files to a newer format.  Since the dictionary files
	have not changed in many years, it's use is rather limited also.

	NOTE   NOTE   NOTE   NOTE   NOTE   NOTE   NOTE   NOTE   NOTE

	Mentor Software has no way of testing this function or verifying
	its veracity.  Use this function at your own risk.
*****************************************************************************/

int CS_ftw (const char *path,int (*fn)(const char*,const struct stat*,int),int depth)
{
		/* Apple doesn't include an "ftw" implementation, and the
		 * only one I could find is subject to the GNU license,
		 * so we'll go for a different implementation. [GEH 2000/11/30]
		 * 
		 * This is a bit of a farce, really; the "depth" parameter is completely
		 * ignored.  It would take very little work to make it call CS_ftw()
		 * recursively.
		 */
	extern char cs_DirsepC;
	extern char *cs_DirP;
	extern char cs_ExtsepC;

	char *cp;
	char ctemp[MAXPATH];
	DIR *directory = NULL;
	int st = 0;

	cp = CS_stcpy(ctemp,path);

	directory = opendir(ctemp);
	if ( directory )
	{
		struct dirent *entry;
		*(cp - 1) = cs_DirsepC;
		while ( entry = readdir(directory) )
		{
			struct stat stat_buf; 
			CS_stcpy(cp,entry->d_name);

			st = stat (ctemp,&stat_buf);
			if (st == 0)
			{
				if ( S_ISDIR(stat_buf.st_mode) )  /* Should really be smarter here */
				{
					st = (*fn) (ctemp,&stat_buf,FTW_D);
				}
				else
				{
					st = (*fn) (ctemp,&stat_buf,FTW_F);
				}
				if (st != 0)
				{
					break;
				}
			}
		}
		closedir(directory);
	}
	return st;
}
#endif

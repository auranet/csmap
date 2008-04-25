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

			 File Name: $RCSfile: CSelcomp.c $
		   Description:
			   Purpose:

		Revision Level:	$Revision: #6 $
		 Check In Date:	$Date: 2007/01/05 $

		Last Revision:	$Log: CSelcomp.c $
		Last Revision:	Revision 11.1300  2005/05/25 23:27:04  nto
		Last Revision:	Official Release 11.13
		Last Revision:	Revision 11.1200  2005/01/15 18:27:07  nto
		Last Revision:	Official Release of CS-MAP 11.12, 11:26am 15 Jan 2005
		Last Revision:	Revision 11.1100  2004/11/01 18:53:04  nto
		Last Revision:	Official release 11.11
		Last Revision:	Revision 11.1001  2004/10/07 19:25:13  nto
		Last Revision:	Revision 11.900  2004/03/26 17:02:20  nto
		Last Revision:	Official release: 11.09 - 3/25/2003
		Last Revision:	Revision 11.800  2004/01/13 23:29:09  nto
		Last Revision:	Revision 11.700  2003/12/19 01:49:49  nto
		Last Revision:	Official release 11.07
		Last Revision:	Revision 11.600  2003/12/04 02:46:24  nto
		Last Revision:	Release 11.06.  Never shipped. Source captured in prep for C++ V7.
		Last Revision:	Revision 11.501  2003/08/22 21:12:52  nto
		Last Revision:	Official Release: 11.05
		Last Revision:	Revision 11.401  2003/05/01 23:06:18  nto
		Last Revision:	Revision 11.300  2003/02/25 04:29:13  nto
		Last Revision:	Official Release 11.03
		Last Revision:	Revision 11.101  2003/02/15 01:30:38  nto
		Last Revision:	Made definitions in the TEST group "user protected" for testing purposes.
		Last Revision:	Revision 11.100  2002/11/22 19:38:40  nto
		Last Revision:	Official release: 11.01
		Last Revision:	Revision 10.1504  2002/11/21 21:08:25  nto
		Last Revision:	Lint cleanup.
		Last Revision:	Revision 10.1503  2002/10/06 22:26:34  nto
		Last Revision:	Changed 'unlink' to 'CS_remove'.
		Last Revision:	Revision 10.1502  2002/10/06 17:53:36  nto
		Last Revision:	Adjusted the mode of the output file open, so the file could be sorted.
		Last Revision:	Revision 10.1501  2002/10/03 00:00:11  nto
		Last Revision:	Removed UNIX I/O in favor of ANSI stream I/O.
		Last Revision:	Revision 10.1500  2002/09/22 00:01:16  nto
		Last Revision:	Official Release:= 10.15
		Last Revision:	Revision 10.1400  2002/08/09 18:14:19  nto
		Last Revision:	Revision 10.1200  2002/07/14 03:26:11  nto
		Last Revision:	Revision 10.1100  2002/06/13 14:18:33  nto
		Last Revision:	Release 10.11 Official
		Last Revision:	Revision 10.1000  2002/02/23 21:18:23  nto
		Last Revision:	Official Release of 10.10, 2/22/02 - Norm Olsen
		Last Revision:	Revision 10.900  2001/09/24 04:31:08  nto
		Last Revision:	Revision 10.700  2001/01/25 04:13:42  nto
		Last Revision:	Revision 10.600  2000/12/11 06:39:37  nto
		Last Revision:	Release 10.06
		Last Revision:	Revision 10.500  2000/10/27 07:38:14  nto
		Last Revision:	Official Release 10.05
		Last Revision:	Revision 10.400  2000/09/13 01:16:49  nto
		Last Revision:	Release 10.04
		Last Revision:	Revision 10.300  2000/04/04 23:18:19  nto
		Last Revision:	Revision 10.200  2000/03/02 18:51:12  nto
		Last Revision:	Revision 10.0  1999/10/05 18:27:11  nto
		Last Revision:	Revision 9.99  1999/10/05 17:36:22  nto
		Last Revision:	Revision 1.2  1999/09/12 05:14:16  nto
		Last Revision:	This revision compiles, links, and generates a successful test program.

******************************************************************************/

#ifdef LABEL_MODULE
static char revlvl [] = {"$Id: //depot/Libraries/CsMap/current/src/CSelcomp.c#6 $"};
#endif

#include "cs_map.h"

/* Entire module skipped if this is an Embedded compile for project management
   convenience.  Don't think it likely that we'll need to compile dictionaries
   in the Embedded environment. */
#if !defined (__WINCE__)

#define EL_NAME 1
#define DESC_NM 2
#define E_RAD   3
#define P_RAD   4
#define FLAT    5
#define ECENT   6
#define GROUP   7
#define SOURCE  8
#define EPSG_NBR 9

struct cs_ElcmpT_
{
	char label [10];
	int type;
};

__ALIGNMENT__1		/* For some versions of Sun compiler. */
static struct cs_ElcmpT_ cs_ElcmpT [] =
{
	{"\010EL_NAME:"  ,EL_NAME},
	{"\010DESC_NM:"  ,DESC_NM},
	{"\007SOURCE:"   ,SOURCE},
	{"\006E_RAD:"    ,E_RAD},
	{"\006P_RAD:"    ,P_RAD},
	{"\006ECENT:"    ,ECENT},
	{"\006GROUP:"    ,GROUP},
	{"\005FLAT:"     ,FLAT},
	{"\005EPSG:"     ,EPSG_NBR},
	{""              ,0}
};

int CSeldefwr (	csFILE *outStrm,
				struct cs_Eldef_ *eldef,
				int crypt,
				int warn,
				int (*err_func)(char *mesg)
			  );

/**********************************************************************
**	err_cnt = CSelcomp (inpt,outp,flags,err_func);
**
**	char *inpt;					full pathe name to the ASCII source file.
**	char *outp;					full path name to the target file.
**	int flags;					bitmat of options, see REMARKS below.
**	int (*err_func)(char *mesg);function called top present error messages
**								to the user.
**	int err_cnt;				returns the number of errors reported.
**
**	The flags argument is a bit map of the following options:
**
**	cs_CMPLR_CRYPT -- produce an encrypted output file.
**	cs_CMPLR_DEMO  -- use DEMO magic numbers.
**	cs_CMPLR_TEST  -- include test elements in outut.  Normally,
**					  these are suppressed.
**
**	Please excuse the rather crude nature of this program.  However,
**	it is necessary for this program to be compiled, linked, and
**	run in just about any environment, without requiring users
**	to license LEX/YACC.
**********************************************************************/


int EXP_LVL9 CSelcomp (	Const char *inpt,
						Const char *outp,
						int flags,
						int (*err_func)(char *mesg)
					  )

{
	int st;
	int demo;
	int test;
	int warn;
	int dummy;
	int cancel;
	int crypt;
	int line_nbr;
	int err_cnt;
	size_t wrCnt;

	char *cp;
	csFILE *inStrm;
	csFILE *outStrm;
	struct cs_ElcmpT_ *tp;

	cs_magic_t magic;

	char err_seg [18];
	char buff [128];
	char err_msg [128];
	char last_name [48];

	__ALIGNMENT__2		/* For some versions of Sun compiler. */
	struct cs_Eldef_ eldef;

	/* Process the arguments on the command line. */
	crypt = ((flags & cs_CMPLR_CRYPT) != 0);
	demo = ((flags & cs_CMPLR_DEMO) != 0);
	test = ((flags & cs_CMPLR_TEST) != 0);
	warn = ((flags & cs_CMPLR_WARN) != 0);

	/* OK, lets do it.  Open the source file. */
	inStrm = CS_fopen (inpt,_STRM_TXTRD);
	if (inStrm == NULL)
	{
		sprintf (err_msg,"Couldn't open %s for input.",inpt);
		cancel = (*err_func)(err_msg);
		return (1);
	}

	/* Open the output file and write the magic number.  BINRW creats a
	   new file (truncates if necessary) with read write access.  We
	   need read/write as we will be dorting below. */
	outStrm = CS_fopen (outp,_STRM_BINRW);
	if (outStrm == NULL)
	{
		sprintf (err_msg,"Couln't open %s for output.",outp);
		cancel = (*err_func)(err_msg);
		CS_fclose (inStrm);
		return (1);
	}

	if (demo) magic = cs_ELDEF_MAGIC;
	else      magic = cs_ELDEF_MAGIC;
	CS_bswap (&magic,"l");
	wrCnt = CS_fwrite (&magic,1,sizeof (magic),outStrm);
	if (wrCnt != sizeof (magic))
	{
		sprintf (err_msg,"Write failure on %s.",outp);
		cancel = (*err_func)(err_msg);
		CS_fclose (inStrm);
		CS_fclose (outStrm);
		CS_remove (outp);										/*lint !e534 */
		return (1);
	}

	/* Process each line in the source file. */
	err_cnt = 0;
	cancel = FALSE;
	line_nbr = 0;
	memset (&eldef,'\0',sizeof (eldef));
	eldef.e_rad = 0.0;
	eldef.p_rad = 0.0;
	while (CS_fgets (buff,sizeof (buff),inStrm) != NULL)
	{
		if (cancel)
		{
			CS_fclose (outStrm);
			CS_remove (outp);										/*lint !e534 */
			CS_fclose (inStrm);
			return (err_cnt);
		}
		line_nbr += 1;

		/* Ignore comments and blank lines. */
		(void)CS_trim (buff);
		if (buff [0] == '#' || buff [0] == '\0')
		{
			continue;
		}
		cp = buff;
		while ((cp = strchr (cp,'#')) != NULL)
		{
			if (*(cp + 1) != '#' &&
				*(cp - 1) != '\\')
			{
				*cp = '\0';
				break;
			}
		}

		/* Run the line through the table parser.  WWe
		   see what type of line we have. */
		cp = buff;
		tp = (struct cs_ElcmpT_ *)CS_tpars (&cp,(char *)cs_ElcmpT,sizeof (struct cs_ElcmpT_));
		if (tp == NULL)
		{
			CS_stncp (err_seg,buff,sizeof (err_seg));
			sprintf (err_msg,"Invalid line label (%s) at line %d.",err_seg,line_nbr);
			cancel = (*err_func)(err_msg);
			eldef.key_nm [0] = '\0';
			continue;
		}

		/* Here when we have a valid line. Cp points to the first
		   character after the colon. */
		(void)CS_trim (cp);
		switch (tp->type) {

		case EL_NAME:
			/* Here each time we encounter a new ellipsoid
			   name.  We see if there is an existing
			   ellipsoid which must be written. */

			if (eldef.key_nm [0] != '\0' &&
				(test || CS_stricmp (eldef.group,"TEST")))
			{
				
				st = CSeldefwr (outStrm,&eldef,crypt,warn,err_func);
				if (st >= 0) err_cnt += st;
				else
				{
					err_cnt += -st;
					cancel = TRUE;
				}
			}
		
			/* Prepare for the next ellipsoid definition. */
			(void)memset ((char *)&eldef,'\0',sizeof (eldef));
			(void)CS_stncp (eldef.key_nm,cp,sizeof (eldef.key_nm));
			st = CS_nampp (eldef.key_nm);
			if (st != 0)
			{
				sprintf (err_msg,"%s is not a valid ellipsoid key name; line %d.",cp,line_nbr);
				cancel = (*err_func)(err_msg);
				err_cnt += 1;
			}
			break;

		case DESC_NM:
			(void)CS_stncp (eldef.name,cp,sizeof (eldef.name));
			break;

		case E_RAD:
			eldef.e_rad = atof (cp);
			break;

		case P_RAD:
			eldef.p_rad = atof (cp);
			break;

		case FLAT:
			eldef.flat = atof (cp);
			break;

		case ECENT:
			eldef.ecent = atof (cp);
			break;

		case SOURCE:
			CS_stncp (eldef.source,cp,sizeof (eldef.source));
			break;

		case GROUP:
			CS_stncp (eldef.group,cp,sizeof (eldef.group));
			break;
		
		case EPSG_NBR:
			eldef.epsgNbr = atoi (cp);
			break;

		default:
			sprintf (err_msg,"Software Problem at line %d in module %s.",__LINE__,__FILE__);
			break;
		}
		/* On to the next input line. */
	}
	CS_fclose (inStrm);

	/* Write out the last coordinate system if not in error. */
	if (eldef.key_nm [0] != '\0')
	{
		st = CSeldefwr (outStrm,&eldef,crypt,warn,err_func);
		if (st >= 0) err_cnt += st;
		else
		{
			err_cnt += -st;
			cancel = TRUE;
		}
	}
	if (cancel)
	{
		CS_fclose (outStrm);
		CS_remove (outp);										/*lint !e534 */
		return (err_cnt);
	}

	/* Sort the output file. */
	CS_fseek (outStrm,(long)sizeof (magic),SEEK_SET);
	CS_ips (outStrm,sizeof (eldef),0L,(CMPFUNC_CAST)CS_elcmp);		/*lint !e534 */

	/* Check for duplicate names. */
	CS_fseek (outStrm,(long)sizeof (magic),SEEK_SET);
	CS_elrd (outStrm,&eldef,&dummy);								/*lint !e534 */
	CS_stncp (last_name,eldef.key_nm,sizeof (last_name));
	while (!cancel && CS_elrd (outStrm,&eldef,&dummy))
	{
		if (!CS_stricmp (last_name,eldef.key_nm))
		{
			sprintf (err_msg,"Ellipsoid named %s appears more than once.",last_name);
			cancel = (*err_func)(err_msg);
			err_cnt += 1;
		}
		CS_stncp (last_name,eldef.key_nm,sizeof (last_name));
	}
	CS_fclose (outStrm);
	
	/* If there were any errors, delete the output file and
	   exit now. */
	if (err_cnt > 0)
	{
		CS_remove (outp);										/*lint !e534 */
	}

	/* That's it. */
	return (err_cnt);
}

int CSeldefwr (	csFILE *outStrm,
				struct cs_Eldef_ *eldef,
				int crypt,
				int warn,
				int (*err_func)(char *mesg)
			  )
{
	int err_cnt;
	int cancel;

	char err_msg [128];

	err_cnt = 0;
	cancel = FALSE;

	if (eldef->e_rad == 0.0)
	{
		sprintf (err_msg,"No equatorial radius specified for %s.          \n",eldef->key_nm);
		cancel = (*err_func)(err_msg);
		err_cnt += 1;
	}
	else if (eldef->p_rad == 0.0)
	{
		sprintf (err_msg,"No polar radius specified for %s.",eldef->key_nm);
		cancel = (*err_func)(err_msg);
		err_cnt += 1;
	}
	else if (warn && ((eldef->e_rad < 6000000.0) || (eldef->e_rad > 7000000.0)))
	{
		sprintf (err_msg,"Warning: Equatorial raidus of ellipsoid named %s is suspicious.",eldef->key_nm);
		cancel = (*err_func)(err_msg);
	}
	if (err_cnt == 0)
	{
		eldef->protect = TRUE;
		/* The following sets the "creation date" to Jan 1, 2002 (approx) for
		   all test coordinate systems.  This enables the protection system to
		   be tested.  Normally, distribution definitions are protected from
		   any kind of change. */
		if (!CS_stricmp (eldef->group,"TEST")) eldef->protect = 4383;
		eldef->fill [0] = '\0';
		eldef->fill [1] = '\0';

		/* Compute the flattening and eccentricity. */
		eldef->flat = 1.0 - (eldef->p_rad / eldef->e_rad);
		eldef->ecent = sqrt ((2.0 * eldef->flat) - (eldef->flat * eldef->flat));
		if (warn &&
			eldef->p_rad != eldef->e_rad &&
			((eldef->flat > 0.0040) ||
			 (eldef->flat < 0.0032)))
		{
			sprintf (err_msg,"Warning: Polar radius of ellipsoid named %s is suspicious.",eldef->key_nm);
			cancel = (*err_func)(err_msg);
		}
		CS_elwr (outStrm,eldef,crypt);								/*lint !e534 */
	}
	if (warn && eldef->name [0] == '\0')
	{
		sprintf (err_msg,"No description for ellipsoid named %s.",eldef->key_nm);
		cancel = (*err_func)(err_msg);
	} 
	if (warn && eldef->source [0] == '\0')
	{
		sprintf (err_msg,"No source for ellipsoid named %s.",eldef->key_nm);
		cancel = (*err_func)(err_msg);
	}
	if (cancel && err_cnt == 0) err_cnt = 1;
	return (cancel ? -err_cnt : err_cnt);
}
#endif

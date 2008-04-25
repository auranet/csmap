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

			 File Name: $RCSfile: CS_units.c $
		   Description:
			   Purpose:

		Revision Level:	$Revision: #5 $
		 Check In Date:	$Date: 2006/06/23 $

		Last Revision:	$Log: CS_units.c $
		Last Revision:	Revision 11.1300  2005/05/25 23:27:19  nto
		Last Revision:	Official Release 11.13
		Last Revision:	Revision 11.1200  2005/01/15 18:27:16  nto
		Last Revision:	Official Release of CS-MAP 11.12, 11:26am 15 Jan 2005
		Last Revision:	Revision 11.1100  2004/11/01 18:53:15  nto
		Last Revision:	Official release 11.11
		Last Revision:	Revision 11.1001  2004/10/07 19:25:22  nto
		Last Revision:	Revision 11.900  2004/03/26 17:02:29  nto
		Last Revision:	Official release: 11.09 - 3/25/2003
		Last Revision:	Revision 11.800  2004/01/13 23:29:18  nto
		Last Revision:	Revision 11.700  2003/12/19 01:49:58  nto
		Last Revision:	Official release 11.07
		Last Revision:	Revision 11.600  2003/12/04 02:46:32  nto
		Last Revision:	Release 11.06.  Never shipped. Source captured in prep for C++ V7.
		Last Revision:	Revision 11.501  2003/08/22 21:13:00  nto
		Last Revision:	Official Release: 11.05
		Last Revision:	Revision 11.401  2003/05/01 23:06:26  nto
		Last Revision:	Revision 11.300  2003/02/25 04:29:21  nto
		Last Revision:	Official Release 11.03
		Last Revision:	Revision 11.100  2002/11/22 19:38:48  nto
		Last Revision:	Official release: 11.01
		Last Revision:	Revision 10.1500  2002/09/22 00:01:25  nto
		Last Revision:	Official Release:= 10.15
		Last Revision:	Revision 10.1401  2002/09/15 21:21:20  nto
		Last Revision:	Added the unitAdd abd unitDel functions.
		Last Revision:	Revision 10.1400  2002/08/09 18:14:26  nto
		Last Revision:	Revision 10.1200  2002/06/20 18:00:31  nto
		Last Revision:	Official release: 10.12
		Last Revision:	Revision 10.1100  2002/06/13 14:18:44  nto
		Last Revision:	Release 10.11 Official
		Last Revision:	Revision 10.1000  2002/02/23 21:18:30  nto
		Last Revision:	Official Release of 10.10, 2/22/02 - Norm Olsen
		Last Revision:	Revision 10.900  2001/09/24 04:31:14  nto
		Last Revision:	Revision 10.700  2001/01/25 04:13:55  nto
		Last Revision:	Revision 10.600  2000/12/11 06:39:50  nto
		Last Revision:	Release 10.06
		Last Revision:	Revision 10.500  2000/10/27 07:38:31  nto
		Last Revision:	Official Release 10.05
		Last Revision:	Revision 10.401  2000/10/27 03:58:18  nto
		Last Revision:	Removed attempt to export the hook function pointer variables.
		Last Revision:	Revision 10.400  2000/09/13 01:17:02  nto
		Last Revision:	Release 10.04
		Last Revision:	Revision 10.300  2000/04/04 23:18:32  nto
		Last Revision:	Revision 10.200  2000/03/02 18:51:23  nto
		Last Revision:	Revision 1.2  2000/01/31 00:07:29  nto
		Last Revision:	Added hook function for user defined units. Also some PCLint clean up.
		Last Revision:	Revision 1.1  2000/01/28 02:27:55  nto
		Last Revision:	Initial Revision

******************************************************************************/

#ifdef LABEL_MODULE
static char revlvl [] = {"$Id: //depot/Libraries/CsMap/current/src/CS_units.c#5 $"};
#endif

#include "cs_map.h"

/**********************************************************************
 Hook function to support the use of user defined units table.

 To activate, set the global CS_usrUnitPtr variable to point to your
 function.  To deactivate, set CS_usrUnitPtr to NULL.
 
 CS_unitlu calls the (*CS_usrUnitPtr) function after it checks the type
 argument for validitiy, but before it does anything else.  Thus, user
 defined unit names need not adhere to any CS-MAP convention regarding
 names and user defined units can be used to override names used by Mentor.

 (*CS_usrUnitsPtr) should return:
 < 0.0 (any negative value) to indicate an error of sorts, in which case
       the error condition must have already been reported to CS_erpt.
   0.0 to indicate that normal CS_unitlu processing is to be performed.
 > 0.0 the actual value which is to be returned by CS_unitlu to its
       calling function.
**********************************************************************/
extern double (*CS_usrUnitPtr) (short type,Const char *unitName);

/**********************************************************************
**	value = CS_unitlu (type,name);
**
**	short type;					code value indicating the type of unit being
**								searched for.
**	char *name;					the name of the unit as a null terminated string.
**	double value;				returns the value associated with that specific
**								unit, else zero.
**
**	This function returns the value necessary to convert
**	various external units to standard internal units.
**	For example, the standard internal unit of length is
**	the meter.  Therefore, when called with the name "FOOT",
**	this, function will return "0.3048006..." which is the
**	value you must multiply feet by to get meters.  Using this
**	function, you can convert from any supported unit of
**	length to any other.
**
**	Formerly, the unit table supported only units of length.
**	Currently, the unit table supports any number of unit
**	types, length and angular measure being implemented.
**	The first argument to this function indicates the type
**	unit to be searched for.
**
**	Please use this function for all unit look ups.  The
**	structure of the table and the search technique is
**	subject to change as the size of the table grows.
**
**********************************************************************/

double EXP_LVL1 CS_unitlu (short type,Const char *name)
{
	extern double cs_Zero;
	extern int cs_Error;
	extern char csErrnam [];
	extern struct cs_Unittab_ cs_Unittab [];

	cs_Register struct cs_Unittab_ Huge *tp;

	Const char *ccp;
	char *cp;
	double usrValue;

	char my_name [cs_KEYNM_DEF];

	/* Check the unit type provided. */

	if (type != cs_UTYP_LEN && type != cs_UTYP_ANG)
	{
		CS_erpt (cs_INV_UTYP);
		return (-cs_Error);
	}

	/* Give the application a chance to do its own thing. */
	if (CS_usrUnitPtr != NULL)
	{
		usrValue = (*CS_usrUnitPtr)(type,name);
		if (usrValue < 0.0) return cs_Zero;
		if (usrValue > 0.0) return usrValue;
	}

	/* Get a copy of the name which I can modify.  We strip
	   leading and trailing blanks, and also any default
	   wrapping characters. */

	ccp = name;
	while (*ccp == ' ') ccp += 1;
	cp = CS_stncp (my_name,ccp,sizeof (my_name));
	if (my_name [0] == '\0') goto error;
	while (*(cp - 1) == ' ') cp -= 1;
	*cp = '\0';
	cp -= 1;

	if ((*my_name == cs_DFLT_IDNTBEG && *cp == cs_DFLT_IDNTEND) ||
		(*my_name == cs_DFLT_REPLBEG && *cp == cs_DFLT_REPLEND))
	{
		*cp = '\0';
		CS_stcpy (my_name,&my_name [1]);
	}

	/* Look for a match in the type and complete name portion
	   of the table. */

	for (tp = cs_Unittab;tp->type != cs_UTYP_END;tp++)
	{
		if (tp->type == type &&
			!CS_stricmp (my_name,tp->name))
		{
			return (tp->factor);
		}
	}

	/* If we're still here, we didn't find it.  Look for the
	   abbreviation. */

	for (tp = cs_Unittab;tp->type != cs_UTYP_END;tp++)
	{
		if (tp->type == type &&
		    !CS_stricmp (my_name,tp->abrv))
		{
			return (tp->factor);
		}
	}

	/* It's just not there.  Must have an invalid name. */

error:
	(void)strcpy (csErrnam,name);
	CS_erpt (cs_INV_UNIT);
	return (cs_Zero);
}
int EXP_LVL3 CS_unitAdd (struct cs_Unittab_ *unitPtr)
{
	extern char csErrnam [];
	extern struct cs_Unittab_ cs_Unittab [];

	int status = 0;
	struct cs_Unittab_ *tabPtr;

	/* Prepare for possible error. */
	CS_stncp (csErrnam,unitPtr->name,MAXPATH);

	/* Verify the validity of the provided structure. */
	if (unitPtr->type != cs_UTYP_LEN && unitPtr->type != cs_UTYP_ANG)
	{
		CS_erpt (cs_UADD_TYPE);
		status = -1;
	}
	else
	{
		/* Verify that a unit with this name does not alreay exist. */
		for (tabPtr = cs_Unittab;tabPtr->type != cs_UTYP_END;tabPtr++)
		{
			if (tabPtr->type == unitPtr->type && !CS_stricmp (unitPtr->name,tabPtr->name))
			{
				break;
			}
		}
		if (tabPtr->type != cs_UTYP_END)
		{
			CS_erpt (cs_UADD_DUP);
			status = -1;
		}
		else
		{
			/* Locate the first unused unit slot in the table. */
			for (tabPtr = cs_Unittab;tabPtr->type != cs_UTYP_END;tabPtr++)
			{
				if (tabPtr->type == cs_UTYP_OFF) break;
			}
			if (tabPtr->type != cs_UTYP_OFF)
			{
				CS_erpt (cs_UADD_FULL);
				status = -1;
			}
			else
			{
				/* Copy the new definition into the static table. */
				tabPtr->type = unitPtr->type;
				CS_stncp (tabPtr->name,unitPtr->name,sizeof (tabPtr->name));
				CS_stncp (tabPtr->pluralName,unitPtr->pluralName,sizeof (tabPtr->pluralName));
				CS_stncp (tabPtr->abrv,unitPtr->abrv,sizeof (tabPtr->abrv));
				tabPtr->system = unitPtr->system;
				tabPtr->factor = unitPtr->factor;
			}
		}
	}
	return status;
}
int EXP_LVL3 CS_unitDel (short type,Const char *name)
{
	extern char csErrnam [];
	extern struct cs_Unittab_ cs_Unittab [];

	int status = 0;
	struct cs_Unittab_ *tabPtr;

	/* Prepare for possible error. */
	CS_stncp (csErrnam,name,MAXPATH);

	/* Locate the name provided. */
	for (tabPtr = cs_Unittab;tabPtr->type != cs_UTYP_END;tabPtr++)
	{
		if (tabPtr->type == type && !CS_stricmp (tabPtr->name,name))
		{
			break;
		}
	}
	if (tabPtr->type == cs_UTYP_END)
	{
		CS_erpt (cs_UDEL_NONE);
		status = -1;
	}
	else
	{
		/* Mark it as available.  This, essentially, also deletes it. */
		tabPtr->type = cs_UTYP_OFF;
	}
	return status;
}
Const char* EXP_LVL3 CS_unitluByFactor (short type,double factor)
{
	extern struct cs_Unittab_ cs_Unittab [];

	int equal;
	Const char* unitNamePtr = 0;
	struct cs_Unittab_ *tabPtr;

	for (tabPtr = cs_Unittab;tabPtr->type != cs_UTYP_END;tabPtr++)
	{
		if (tabPtr->type == type)
		{
			 equal = CS_cmpDbls (tabPtr->factor,factor);
			 if (equal != 0)
			 {
				unitNamePtr = tabPtr->name;
				break;
			}
		}
	}
	return unitNamePtr;
}

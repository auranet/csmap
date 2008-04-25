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

			 File Name: $RCSfile$
		   Description:
			   Purpose:

		Revision Level:	$Revision: #9 $
		 Check In Date:	$Date: 2007/01/12 $

		Last Revision:	$Log$

******************************************************************************/

#ifdef LABEL_MODULE
static char revlvl [] = {"$Id"};
#endif

#include "cs_map.h"

struct csEsriNbrMap_
{
	long esriNbr;
	long epsgNbr;
	char msiName [24];
	char esriName [96];
	unsigned short flags;		/* currently unused */
};
struct csEsriNbrMap_ csEsriNbrMap [] =
{
	{   4121L,  4121L, "GGRS87.LL",                  "GCS_GGRS_1987",                                                    0 },	// GGRS87
	{   4122L,  4122L, "LL77",                       "GCS_ATS_1977",                                                     1 },	// ATS77
	{   4123L,  4123L, "KKJ.LL",                     "GCS_KKJ",                                                          0 },	// KKJ
	{   4124L,  4124L, "LL-RT90",                    "GCS_RT_1990",                                                      1 },	// RT90
	{   4125L,  4125L, "Samboja.LL",                 "GCS_Samboja",                                                      2 },	// Samboja
	{   4126L,  4126L, "Lithuania94.LL",             "GCS_LKS_1994",                                                     2 },	// LKS94 (ETRS89)
	{   4127L,  4127L, "Tete.LL",                    "GCS_Tete",                                                         0 },	// Tete
	{   4130L,  4130L, "Moznet.LL",                  "GCS_Moznet",                                                       0 },	// Moznet
	{   4131L,  4131L, "Indian60.LL",                "GCS_Indian_1960",                                                  0 },	// Indian 1960
	{   4132L,  4132L, "Final58.LL",                 "GCS_FD_1958",                                                      0 },	// FD58
	{   4133L,  4133L, "Estonia92",                  "GCS_Estonia_1992",                                                 0 },	// EST92
	{   4134L,  4134L, "PDOSurvey93.LL",             "GCS_PDO_1993",                                                     0 },	// PDO Survey Datum 1993
	{   4135L,  4135L, "LL-OLDHI",                   "GCS_Old_Hawaiian",                                                 1 },	// Old Hawaiian
	{   4139L,  4139L, "PRVI.LL",                    "GCS_Puerto_Rico",                                                  0 },	// Puerto Rico
	{   4140L,  4140L, "LLCSRS",                     "GCS_North_American_1983_CSRS98",                                   3 },	// NAD83(CSRS98)
	{   4141L,  4141L, "Israel.LL",                  "GCS_Israel",                                                       0 },	// Israel
	{   4142L,  4142L, "Locodjo65.LL",               "GCS_Locodjo_1965",                                                 0 },	// Locodjo 1965
	{   4143L,  4143L, "Abidjan87.LL",               "GCS_Abidjan_1987",                                                 0 },	// Abidjan 1987
	{   4144L,  4144L, "Kalianpur37.LL",             "GCS_Kalianpur_1937",                                               0 },	// Kalianpur 1937
	{   4145L,  4145L, "Kalianpur62.LL",             "GCS_Kalianpur_1962",                                               0 },	// Kalianpur 1962
	{   4146L,  4146L, "Kalianpur75.LL",             "GCS_Kalianpur_1975",                                               0 },	// Kalianpur 1975
	{   4147L,  4147L, "Hanoi72.LL",                 "GCS_Hanoi_1972",                                                   0 },	// Hanoi 1972
	{   4148L,  4148L, "Hartebeesthoek94.LL",        "GCS_Hartebeesthoek_1994",                                          0 },	// Hartebeesthoek94
	{   4149L,  4149L, "LLCH1903",                   "GCS_CH1903",                                                       1 },	// CH1903
	{   4150L,  4150L, "CH1903Plus.LL",              "GCS_CH1903+",                                                      0 },	// CH1903+
	{   4151L,  4151L, "CHTRF95.LL",                 "GCS_Swiss_TRF_1995",                                               0 },	// CHTRF95
	{   4152L,  4152L, "LL-HPGN",                    "GCS_North_American_1983_HARN",                                     1 },	// NAD83(HARN)
	{   4153L,  4153L, "Rassadiran.LL",              "GCS_Rassadiran",                                                   0 },	// Rassadiran
	{   4154L,  4154L, "Europ50/77.LL",              "GCS_European_1950_ED77",                                           0 },	// ED50(ED77)
	{   4155L,  4155L, "Dabola81.LL",                "GCS_Dabola_1981",                                                  0 },	// Dabola 1981
	{   4156L,  4156L, "S-JTSK.LL",                  "GCS_S_JTSK",                                                       1 },	// S-JTSK
	{   4161L,  4161L, "Castillo.LL",                "GCS_Pampa_del_Castillo",                                           0 },	// Pampa del Castillo
	{   4163L,  4163L, "YemenNtl96.LL",              "GCS_Yemen_NGN_1996",                                               0 },	// Yemen NGN96
	{   4164L,  4164L, "SouthYemen.LL",              "GCS_South_Yemen",                                                  0 },	// South Yemen
	{   4165L,  4165L, "Bissau.LL",                  "GCS_Bissau",                                                       0 },	// Bissau
	{   4166L,  4166L, "Korean95.LL",                "GCS_Korean_Datum_1995",                                            0 },	// Korean 1995
	{   4167L,  4167L, "NZGD2000.LL",                "GCS_NZGD_2000",                                                    0 },	// NZGD2000
	{   4168L,  4168L, "Accra.LL",                   "GCS_Accra",                                                        0 },	// Accra
	{  37252L,  4169L, "AmSamoa62.LL",               "GCS_American_Samoa_1962",                                          0 },	// American Samoa 1962
	{   4170L,  4170L, "GRSSA.LL",                   "GCS_SIRGAS",                                                       0 },	// SIRGAS
	{   4171L,  4171L, "LL-RGF93",                   "GCS_RGF_1993",                                                     1 },	// RGF93
	{   4173L,  4173L, "IRENET95.LL",                "GCS_IRENET95",                                                     0 },	// IRENET95
	{   4175L,  4175L, "SierraLeone68.LL",           "GCS_Sierra_Leone_1968",                                            0 },	// Sierra Leone 1968
	{   4176L,  4176L, "Antarctic98.LL",             "GCS_Australian_Antarctic_1998",                                    0 },	// Australian Antarctic
	{   4178L,  4178L, "Pulkovo42/83.LL",            "GCS_Pulkovo_1942_Adj_1983",                                        0 },	// Pulkovo 1942(83)
	{   4179L,  4179L, "Pulkovo42/58.LL",            "GCS_Pulkovo_1942_Adj_1958",                                        0 },	// Pulkovo 1942(58)
	{   4180L,  4180L, "Estonia97.LL",               "GCS_Estonia_1997",                                                 0 },	// EST97
	{   4181L,  4181L, "Luxembourg30.LL",            "GCS_Luxembourg_1930",                                              0 },	// Luxembourg 1930
	{   4182L,  4182L, "OBSRV66.LL",                 "GCS_Azores_Occidental_1939",                                       1 },	// Azores Occidental 1939
	{   4183L,  4183L, "AZORES.LL",                  "GCS_Azores_Central_1948",                                          0 },	// Azores Central 1948
	{   4184L,  4184L, "SAOBRAZ.LL",                 "GCS_Azores_Oriental_1940",                                         0 },	// Azores Oriental 1940
	{   4188L,  4188L, "OSNI52.LL",                  "GCS_OSNI_1952",                                                    0 },	// OSNI 1952
	{ 104110L,  4189L, "REGVEN.LL",                  "GCS_REGVEN",                                                       0 },	// REGVEN
	{   4190L,  4190L, "PGA98.LL",                   "GCS_POSGAR_1998",                                                  0 },	// POSGAR 98
	{   4192L,  4192L, "Douala48.LL",                "GCS_Douala_1948",                                                  0 },	// Douala 1948
	{   4193L,  4193L, "Manoca62.LL",                "GCS_Manoca_1962",                                                  0 },	// Manoca 1962
	{   4194L,  4194L, "Qornoq27.LL",                "GCS_Qornoq_1927",                                                  0 },	// Qornoq 1927
	{   4195L,  4195L, "Scoresbysund52.LL",          "GCS_Scoresbysund_1952",                                            0 },	// Scoresbysund 1952
	{   4196L,  4196L, "Ammassalik58.LL",            "GCS_Ammassalik_1958",                                              0 },	// Ammassalik 1958
	{   4201L,  4201L, "Adindan.LL",                 "GCS_Adindan",                                                      0 },	// Adindan
	{   4202L,  4202L, "LL-AGD66",                   "GCS_Australian_1966",                                              1 },	// AGD66
	{   4203L,  4203L, "LL-AGD84",                   "GCS_Australian_1984",                                              1 },	// AGD84
	{   4204L,  4204L, "AinElAbd.LL",                "GCS_Ain_el_Abd_1970",                                              0 },	// Ain el Abd
	{   4205L,  4205L, "Afgooye.LL",                 "GCS_Afgooye",                                                      0 },	// Afgooye
	{   4207L,  4207L, "Lisbon37.LL",                "GCS_Lisbon",                                                       0 },	// Lisbon
	{   4208L,  4208L, "Aratu.LL",                   "GCS_Aratu",                                                        0 },	// Aratu
	{   4209L,  4209L, "Arc1950.LL",                 "GCS_Arc_1950",                                                     0 },	// Arc 1950
	{   4210L,  4210L, "Arc1960.LL",                 "GCS_Arc_1960",                                                     0 },	// Arc 1960
	{   4211L,  4211L, "DJAKRTA.LL",                 "GCS_Batavia",                                                      1 },	// Batavia
	{   4212L,  4212L, "Barbados38.LL",              "GCS_Barbados_1938",                                                0 },	// Barbados 1938
	{   4214L,  4214L, "Beijing54.LL",               "GCS_Beijing_1954",                                                 0 },	// Beijing 1954
	{   4216L,  4216L, "Bermuda.LL",                 "GCS_Bermuda_1957",                                                 0 },	// Bermuda 1957
	{   4218L,  4218L, "Bogota.LL",                  "GCS_Bogota",                                                       0 },	// Bogota 1975
	{   4219L,  4219L, "BukitRimpah.LL",             "GCS_Bukit_Rimpah",                                                 0 },	// Bukit Rimpah
	{   4220L,  4220L, "Camacupa.LL",                "GCS_Camacupa",                                                     0 },	// Camacupa
	{   4221L,  4221L, "Campo.LL",                   "GCS_Campo_Inchauspe",                                              0 },	// Campo Inchauspe
	{   4222L,  4222L, "Cape-1.LL",                  "GCS_Cape",                                                         0 },	// Cape
	{   4223L,  4223L, "Carthage.LL",                "GCS_Carthage",                                                     0 },	// Carthage
	{   4224L,  4224L, "Chua.LL",                    "GCS_Chua",                                                         0 },	// Chua
	{   4225L,  4225L, "Corrego.LL",                 "GCS_Corrego_Alegre",                                               0 },	// Corrego Alegre
	{   4227L,  4227L, "DeirEzZor.LL",               "GCS_Deir_ez_Zor",                                                  0 },	// Deir ez Zor
	{   4229L,  4229L, "Old-Egyp.LL",                "GCS_Egypt_1907",                                                   0 },	// Egypt 1907
	{   4230L,  4230L, "LL-ERP50",                   "GCS_European_1950",                                                1 },	// ED50
	{   4231L,  4231L, "Europ87.LL",                 "GCS_European_1987",                                                0 },	// ED87
	{   4232L,  4232L, "OMAN.LL",                    "GCS_Fahud",                                                        1 },	// Fahud
	{   4233L,  4233L, "Gandajika.LL",               "GCS_Gandajika_1970",                                               2 },	// Gandajika 1970
	{   4236L,  4236L, "HuTzuShan.LL",               "GCS_Hu_Tzu_Shan",                                                  0 },	// Hu Tzu Shan
	{   4237L,  4237L, "HUN72.LL",                   "GCS_Hungarian_1972",                                               0 },	// HD72
	{   4238L,  4238L, "Indonesian74.LL",            "GCS_Indonesian_1974",                                              0 },	// ID74
	{   4239L,  4239L, "Indian54.LL",                "GCS_Indian_1954",                                                  0 },	// Indian 1954
	{   4240L,  4240L, "Indian75.LL",                "GCS_Indian_1975",                                                  0 },	// Indian 1975
	{   4242L,  4242L, "Jamaica69.LL",               "GCS_Jamaica_1969",                                                 0 },	// JAD69
	{   4244L,  4244L, "Kandawala.LL",               "GCS_Kandawala",                                                    0 },	// Kandawala
	{   4245L,  4245L, "Kertau48.LL",                "GCS_Kertau",                                                       0 },	// Kertau 1968
	{   4246L,  4246L, "KuwaitOilCo.LL",             "GCS_Kuwait_Oil_Company",                                           0 },	// KOC
	{   4247L,  4247L, "LaCanoa.LL",                 "GCS_La_Canoa",                                                     0 },	// La Canoa
	{   4248L,  4248L, "LLPSAD56",                   "GCS_Provisional_S_American_1956",                                  1 },	// PSAD56
	{   4250L,  4250L, "Leigon.LL",                  "GCS_Leigon",                                                       0 },	// Leigon
	{   4251L,  4251L, "Liberia.LL",                 "GCS_Liberia_1964",                                                 0 },	// Liberia 1964
	{   4253L,  4253L, "Luzon.LL",                   "GCS_Luzon_1911",                                                   0 },	// Luzon 1911
	{   4254L,  4254L, "HitoXVIII63.LL",             "GCS_Hito_XVIII_1963",                                              0 },	// Hito XVIII 1963
	{   4255L,  4255L, "HeratNorth.LL",              "GCS_Herat_North",                                                  0 },	// Herat North
	{   4256L,  4256L, "Mahe1971.LL",                "GCS_Mahe_1971",                                                    0 },	// Mahe 1971
	{   4257L,  4257L, "Makassar.LL",                "GCS_Makassar",                                                     0 },	// Makassar
	{   4258L,  4258L, "LL-ETRF89",                  "GCS_ETRS_1989",                                                    1 },	// ETRS89
	{   4259L,  4259L, "Malongo87.LL",               "GCS_Malongo_1987",                                                 0 },	// Malongo 1987
	{   4260L,  4260L, "Manoca.LL",                  "GCS_Manoca",                                                       2 },	// Manoca
	{   4261L,  4261L, "Merchich",                   "GCS_Merchich",                                                     0 },	// Merchich
	{   4262L,  4262L, "Massawa.LL",                 "GCS_Massawa",                                                      0 },	// Massawa
	{   4263L,  4263L, "Minna.LL",                   "GCS_Minna",                                                        0 },	// Minna
	{   4264L,  4264L, "Mhast.LL",                   "GCS_Mhast",                                                        2 },	// Mhast
	{   4265L,  4265L, "ROME1940.LL",                "GCS_Monte_Mario",                                                  1 },	// Monte Mario
	{   4266L,  4266L, "Mporaloko.LL",               "GCS_Mporaloko",                                                    0 },	// M'poraloko
	{   4267L,  4267L, "LL27",                       "GCS_North_American_1927",                                          1 },	// NAD27
	{   4268L,  4268L, "MICHIGAN.LL",                "GCS_North_American_Michigan",                                      1 },	// NAD27 Michigan
	{   4269L,  4269L, "LL83",                       "GCS_North_American_1983",                                          1 },	// NAD83
	{   4270L,  4270L, "NHRWN-O.LL",                 "GCS_Nahrwan_1967",                                                 0 },	// Nahrwan 1967
	{   4271L,  4271L, "Naparima72.LL",              "GCS_Naparima_1972",                                                0 },	// Naparima 1972
	{   4272L,  4272L, "LL-NZGD49",                  "GCS_New_Zealand_1949",                                             1 },	// NZGD49
	{   4273L,  4273L, "NGO48.LL",                   "GCS_NGO_1948",                                                     0 },	// NGO 1948
	{   4274L,  4274L, "Datum73.LL",                 "GCS_Datum_73",                                                     0 },	// Datum 73
	{   4275L,  4275L, "NTF.LL",                     "GCS_NTF",                                                          1 },	// NTF
	{   4277L,  4277L, "OSGB.LL",                    "GCS_OSGB_1936",                                                    1 },	// OSGB 1936
	{   4281L,  4281L, "Palestine23.LL",             "GCS_Palestine_1923",                                               0 },	// Palestine 1923
	{   4282L,  4282L, "PointeNoire.LL",             "GCS_Pointe_Noire",                                                 0 },	// Pointe Noire
	{   4283L,  4283L, "LL-GDA94",                   "GCS_GDA_1994",                                                     1 },	// GDA94
	{   4284L,  4284L, "Pulkovo42.LL",               "GCS_Pulkovo_1942",                                                 0 },	// Pulkovo 1942
	{   4285L,  4285L, "Qatar74.LL",                 "GCS_Qatar_1974",                                                   0 },	// Qatar 1974
	{   4286L,  4286L, "Qatar.LL",                   "GCS_Qatar_1948",                                                   0 },	// Qatar 1948
	{   4287L,  4287L, "Qornoq.LL",                  "GCS_Qornoq",                                                       2 },	// Qornoq
	{   4289L,  4289L, "Amersfoort.LL",              "GCS_Amersfoort",                                                   1 },	// Amersfoort
	{   4291L,  4291L, "SAD69.LL",                   "GCS_South_American_1969",                                          2 },	// SAD69
	{   4292L,  4292L, "Sapper.LL",                  "GCS_Sapper_Hill_1943",                                             0 },	// Sapper Hill 1943
	{   4293L,  4293L, "Schwarzk.LL",                "GCS_Schwarzeck",                                                   0 },	// Schwarzeck
	{   4294L,  4294L, "Segora.LL",                  "GCS_Segora",                                                       2 },	// Segora
	{   4297L,  4297L, "Tananarive25.LL",            "GCS_Tananarive_1925",                                              0 },	// Tananarive
	{   4298L,  4298L, "TIMBALAI.LL",                "GCS_Timbalai_1948",                                                1 },	// Timbalai 1948
	{   4299L,  4299L, "TM65.LL",                    "GCS_TM65",                                                         0 },	// TM65
	{   4301L,  4301L, "Tokyo",                      "GCS_Tokyo",                                                        0 },	// Tokyo
	{   4302L,  4302L, "Trinidad03.LL",              "GCS_Trinidad_1903",                                                0 },	// Trinidad 1903
	{   4304L,  4304L, "Voirol1875.LL",              "GCS_Voirol_1875",                                                  0 },	// Voirol 1875
	{   4307L,  4307L, "NordSahara59.LL",            "GCS_Nord_Sahara_1959",                                             0 },	// Nord Sahara 1959
	{   4309L,  4309L, "Yacare.LL",                  "GCS_Yacare",                                                       0 },	// Yacare
	{   4311L,  4311L, "Zanderij.LL",                "GCS_Zanderij",                                                     0 },	// Zanderij
	{   4312L,  4312L, "MGI.LL",                     "GCS_MGI",                                                          0 },	// MGI
	{   4313L,  4313L, "Belge72.LL",                 "GCS_Belge_1972",                                                   0 },	// Belge 1972
	{   4314L,  4314L, "DHDN.LL",                    "GCS_Deutsches_Hauptdreiecksnetz",                                  0 },	// DHDN
	{   4315L,  4315L, "Conakry05.LL",               "GCS_Conakry_1905",                                                 0 },	// Conakry 1905
	{   4316L,  4316L, "DealulPiscului33.LL",        "GCS_Dealul_Piscului_1933",                                         0 },	// Dealul Piscului 1933
	{   4317L,  4317L, "DealulPiscului70.LL",        "GCS_Dealul_Piscului_1970",                                         0 },	// Dealul Piscului 1970
	{   4318L,  4318L, "NtlGeodeticNet.LL",          "GCS_NGN",                                                          0 },	// NGN
	{   4319L,  4319L, "KuwaitUtility.LL",           "GCS_KUDAMS",                                                       0 },	// KUDAMS
	{   4322L,  4322L, "LL72",                       "GCS_WGS_1972",                                                     1 },	// WGS 72
	{   4324L,  4324L, "WGS72-TBE.LL",               "GCS_WGS_1972_BE",                                                  0 },	// WGS 72BE
	{   4326L,  4326L, "LL84",                       "GCS_WGS_1984",                                                     1 },	// WGS 84
	{   4601L,  4601L, "Antigua43.LL",               "GCS_Antigua_1943",                                                 0 },	// Antigua 1943
	{   4602L,  4602L, "Dominica45.LL",              "GCS_Dominica_1945",                                                0 },	// Dominica 1945
	{   4603L,  4603L, "Grenada53.LL",               "GCS_Grenada_1953",                                                 0 },	// Grenada 1953
	{   4404L,  4604L, "Montserrat58.LL",            "GCS_Montserrat_1958",                                              0 },	// Montserrat 1958
	{   4605L,  4605L, "StKitts55.LL",               "GCS_St_Kitts_1955",                                                0 },	// St. Kitts 1955
	{   4606L,  4606L, "StLucia55.LL",               "GCS_St_Lucia_1955",                                                0 },	// St. Lucia 1955
	{   4607L,  4607L, "StVincent45.LL",             "GCS_St_Vincent_1945",                                              0 },	// St. Vincent 1945
	{   4610L,  4610L, "Xian80.LL",                  "GCS_Xian_1980",                                                    0 },	// Xian 1980
	{ 104104L,  4611L, "HongKong80.LL",              "GCS_Hong_Kong_1980",                                               0 },	// Hong Kong 1980
	{   4612L,  4612L, "JGD2000.LL",                 "GCS_JGD_2000",                                                     0 },	// JGD2000
	{   4613L,  4613L, "Segara.LL",                  "GCS_Gunung_Segara",                                                0 },	// Segara
	{   4614L,  4614L, "QatarNtl95.LL",              "GCS_QND_1995",                                                     0 },	// QND95
	{   4615L,  4615L, "MADEIRA.LL",                 "GCS_Porto_Santo_1936",                                             1 },	// Porto Santo
	{   4619L,  4619L, "SWEREF99.LL",                "GCS_SWEREF99",                                                     0 },	// SWEREF99
	{  37211L,  4620L, "Point58.LL",                 "GCS_Point_58",                                                     0 },	// Point 58
	{   4621L,  4621L, "FortMarigot.LL",             "GCS_Fort_Marigot",                                                 0 },	// Fort Marigot
	{   4622L,  4622L, "StAnne.LL",                  "GCS_Sainte_Anne",                                                  0 },	// Guadeloupe 1948
	{   4623L,  4623L, "CSG67.LL",                   "GCS_CSG_1967",                                                     0 },	// CSG67
	{   4624L,  4624L, "Guyane95.LL",                "GCS_RGFG_1995",                                                    0 },	// RGFG95
	{   4625L,  4625L, "FortDesaix.LL",              "GCS_Fort_Desaix",                                                  0 },	// Martinique 1938
	{   4626L,  4626L, "REUNION.LL",                 "GCS_Piton_des_Neiges",                                             0 },	// Reunion 1947
	{   4627L,  4627L, "Reunion92.LL",               "GCS_RGR_1992",                                                     0 },	// RGR92
	{   4628L,  4628L, "Tahiti.LL",                  "GCS_Tahiti",                                                       0 },	// Tahiti 52
	{   4629L,  4629L, "Tahaa.LL",                   "GCS_Tahaa",                                                        0 },	// Tahaa 54
	{   4630L,  4630L, "IGN72NukuHiva.LL",           "GCS_IGN72_Nuku_Hiva",                                              0 },	// IGN72 Nuku Hiva
	{   4631L,  4631L, "K01949.LL",                  "GCS_K0_1949",                                                      2 },	// K0 1949
	{   4632L,  4632L, "Combani50.LL",               "GCS_Combani_1950",                                                 0 },	// Combani 1950
	{   4633L,  4633L, "IGN56Lifou.LL",              "GCS_IGN56_Lifou",                                                  0 },	// IGN56 Lifou
	{   4635L,  4635L, "ST87Ouvea.LL",               "GCS_ST87_Ouvea",                                                   2 },	// ST87 Ouvea
	{   4636L,  4636L, "Petrels72.LL",               "GCS_Petrels_1972",                                                 0 },	// Petrels 1972
	{   4637L,  4637L, "Perroud50.LL",               "GCS_Pointe_Geologie_Perroud_1950",                                 0 },	// Perroud 1950
	{   4638L,  4638L, "Miquelon50.LL",              "GCS_Saint_Pierre_et_Miquelon_1950",                                0 },	// Saint Pierre et Miquelon 1950
	{   4639L,  4639L, "MOP78.LL",                   "GCS_MOP78",                                                        0 },	// MOP78
	{   4640L,  4640L, "Antilles91.LL",              "GCS_RRAF_1991",                                                    0 },	// RRAF 1991
	{   4641L,  4641L, "IGN53/Mare.LL",              "GCS_IGN53_Mare",                                                   0 },	// IGN53 Mare
	{   4642L,  4642L, "ST84IleDesPins.LL",          "GCS_ST84_Ile_des_Pins",                                            0 },	// ST84 Ile des Pins
	{   4643L,  4643L, "ST71Belep.LL",               "GCS_ST71_Belep",                                                   0 },	// ST71 Belep
	{   4644L,  4644L, "NEA74Noumea.LL",             "GCS_NEA74_Noumea",                                                 0 },	// NEA74 Noumea
	{   4645L,  4645L, "Caledonie91.LL",             "GCS_RGNC_1991",                                                    2 },	// RGNC 1991
	{   4657L,  4657L, "Reykjavik.LL",               "GCS_Reykjavik_1900",                                               0 },	// Reykjavik 1900
	{  37204L,  4658L, "HJORSEY.LL",                 "GCS_Hjorsey_1955",                                                 1 },	// Hjorsey 1955
	{   4659L,  4659L, "IslandsNet1993.LL",          "GCS_ISN_1993",                                                     0 },	// ISN93
	{   4660L,  4660L, "Helle1954.LL",               "GCS_Helle_1954",                                                   0 },	// Helle 1954
	{   4661L,  4661L, "Latvia1992.LL",              "GCS_LKS_1992",                                                     0 },	// LKS92
	{   4662L,  4662L, "IGN72GrandeTerre.LL",        "GCS_IGN72_Grande_Terre",                                           0 },	// IGN72 Grande Terre
	{   4663L,  4663L, "PortoSanto1995.LL",          "GCS_Porto_Santo_1995",                                             0 },	// Porto Santo 1995
	{   4664L,  4664L, "AzoresOriental1995.LL",      "GCS_Azores_Oriental_1995",                                         0 },	// Azores Oriental 1995
	{   4665L,  4665L, "AzoresCentral1995.LL",       "GCS_Azores_Central_1995",                                          0 },	// Azores Central 1995
	{   4666L,  4666L, "Lisbon1890.LL",              "GCS_Lisbon_1890",                                                  0 },	// Lisbon 1890
	{   4667L,  4667L, "IraqKuwait1992.LL",          "GCS_IKBD_1992",                                                    0 },	// IKBD-92
	{   4668L,  4668L, "EUROP79.LL",                 "GCS_European_1979",                                                1 },	// ED79
	{   4669L,  4669L, "Lithuania94.LL",             "GCS_LKS_1994",                                                     0 },	// LKS94
	{   4670L,  4670L, "IGM1995.LL",                 "GCS_IGM_1995",                                                     0 },	// IGM95
	{   4672L,  4672L, "CHATHAM.LL",                 "GCS_Chatham_Island_1971",                                          1 },	// CI1971
	{   4673L,  4673L, "Chatham1979.LL",             "GCS_Chatham_Islands_1979",                                         0 },	// CI1979
	{   4674L,  4674L, "SRG-SA/2000.LL",             "GCS_SIRGAS_2000",                                                  0 },	// SIRGAS 2000
	{  37220L,  4675L, "GUAM63.LL",                  "GCS_Guam_1963",                                                    1 },	// Guam 1963
	{   4678L,  4678L, "Lao1997.LL",                 "GCS_Lao_1997",                                                     0 },	// Lao 1997
	{   4679L,  4679L, "Jouik1961.LL",               "GCS_Jouik_1961",                                                   0 },	// Jouik 1961
	{   4680L,  4680L, "Nouakchott1965.LL",          "GCS_Nouakchott_1965",                                              0 },	// Nouakchott 1965
	{   4682L,  4682L, "Gulshan-303.LL",             "GCS_Gulshan_303",                                                  0 },	// Gulshan 303
	{  37232L,  4684L, "Gan1970.LL",                 "GCS_Gan_1970",                                                     0 },	// Gan 1970
	{  37213L,  4707L, "Tern1961.LL",                "GCS_Tern_Island_1961",                                             0 },	// Tern Island 1961
	{  37237L,  4712L, "ASCENSN.LL",                 "GCS_Ascension_Island_1958",                                        1 },	// Ascension Island 1958
	{  37239L,  4717L, "CANAVRL.LL",                 "GCS_Cape_Canaveral",                                               1 },	// Cape Canaveral
	{  37219L,  4719L, "EASTER.LL",                  "GCS_Easter_Island_1967",                                           1 },	// Easter Island 1967
	{  37222L,  4725L, "JHNSTN.LL",                  "GCS_Johnston_Island_1961",                                         1 },	// Johnston Island 1961
	{  37224L,  4727L, "MIDWAY.LL",                  "GCS_Midway_1961",                                                  1 },	// Midway 1961
	{  37226L,  4729L, "PITCAIRN.LL",                "GCS_Pitcairn_1967",                                                1 },	// Pitcairn 1967
	{  37228L,  4731L, "VITI.LL",                    "GCS_Viti_Levu_1916",                                               3 },	// Viti Levu 1916
	{  37230L,  4733L, "Wake1952.LL",                "GCS_Wake_Island_1952",                                             0 },	// Wake Island 1952
	{  37251L,  4734L, "TRISTAN.LL",                 "GCS_Tristan_1968",                                                 1 },	// Tristan 1968
	{  37259L,  4735L, "Kusaie1951.LL",              "GCS_Kusaie_1951",                                                  0 },	// Kusaie 1951
	{  37254L,  4736L, "DeceptionIsland.LL",         "GCS_Deception_Island",                                             0 },	// Deception Island
	{  37205L,  4738L, "HONGKONG.LL",                "GCS_Hong_Kong_1963",                                               1 },	// Hong Kong 1963
	{   2001L,  2001L, "Antigua43.BWIgrid",          "Antigua_1943_British_West_Indies_Grid",                            0 },	// Antigua 1943 / British West Indies Grid
	{   2002L,  2002L, "Dominica45.BWIgrid",         "Dominica_1945_British_West_Indies_Grid",                           0 },	// Dominica 1945 / British West Indies Grid
	{   2003L,  2003L, "Grenada53.BWIgrid",          "Grenada_1953_British_West_Indies_Grid",                            0 },	// Grenada 1953 / British West Indies Grid
	{   2004L,  2004L, "Montserrat58.BWIgrid",       "Montserrat_1958_British_West_Indies_Grid",                         0 },	// Montserrat 1958 / British West Indies Grid
	{   2005L,  2005L, "StKitts55.BWIgrid",          "St_Kitts_1955_British_West_Indies_Grid",                           0 },	// St. Kitts 1955 / British West Indies Grid
	{   2006L,  2006L, "StLucia55.BWIgrid",          "St_Lucia_1955_British_West_Indies_Grid",                           0 },	// St. Lucia 1955 / British West Indies Grid
	{   2007L,  2007L, "StVincent45.BWIgrid",        "St_Vincent_1945_British_West_Indies_Grid",                         0 },	// St. Vincent 45 / British West Indies Grid
	{   2036L,  2036L, "NewBrunswickCSRS",           "NAD_1983_CSRS98_New_Brunswick_Stereographic",                      3 },	// NAD83(CSRS98) / New Brunswick Stereo
	{   2037L,  2037L, "NAD83/98.UTM-19N",           "NAD_1983_CSRS98_UTM_Zone_19N",                                     2 },	// NAD83(CSRS98) / UTM zone 19N
	{   2038L,  2038L, "NAD83/98.UTM-20N",           "NAD_1983_CSRS98_UTM_Zone_20N",                                     2 },	// NAD83(CSRS98) / UTM zone 20N
	{   2039L,  2039L, "Israel.IsraeliGrid",         "Israel_TM_Grid",                                                   0 },	// Israel / Israeli TM Grid
	{   2040L,  2040L, "Locodjo65.UTM-30N",          "Locodjo_1965_UTM_Zone_30N",                                        0 },	// Locodjo 1965 / UTM zone 30N
	{   2041L,  2041L, "Abidjan87.UTM-30N",          "Abidjan_1987_UTM_Zone_30N",                                        0 },	// Abidjan 1987 / UTM zone 30N
	{   2042L,  2042L, "Locodjo65.UTM-29N",          "Locodjo_1965_UTM_Zone_29N",                                        0 },	// Locodjo 1965 / UTM zone 29N
	{   2043L,  2043L, "Abidjan87.UTM-29N",          "Abidjan_1987_UTM_Zone_29N",                                        0 },	// Abidjan 1987 / UTM zone 29N
	{   2044L,  2044L, "Hanoi72.GK-18",              "Hanoi_1972_GK_Zone_18",                                            0 },	// Hanoi 1972 / Gauss-Kruger zone 18
	{   2045L,  2045L, "Hanoi72.GK-19",              "Hanoi_1972_GK_Zone_19",                                            0 },	// Hanoi 1972 / Gauss-Kruger zone 19
	{   2056L,  2056L, "CH1903Plus.LV95",            "CH1903+_LV95",                                                     0 },	// CH1903+ / LV95
	{   2057L,  2057L, "Rassadiran.NakhlTaqi",       "Rassadiran_Nakhl_e_Taqi",                                          0 },	// Rassadiran / Nakhl e Taqi
	{   2058L,  2058L, "ED50/77.UTM-38N",            "ED_1950_ED77_UTM_Zone_38N",                                        0 },	// ED50(ED77) / UTM zone 38N
	{   2059L,  2059L, "ED50/77.UTM-39N",            "ED_1950_ED77_UTM_Zone_39N",                                        0 },	// ED50(ED77) / UTM zone 39N
	{   2060L,  2060L, "ED50/77.UTM-40N",            "ED_1950_ED77_UTM_Zone_40N",                                        0 },	// ED50(ED77) / UTM zone 40N
	{   2061L,  2061L, "ED50/77.UTM-41N",            "ED_1950_ED77_UTM_Zone_41N",                                        0 },	// ED50(ED77) / UTM zone 41N
	{   2063L,  2063L, "Dabola81.UTM-28N",           "Dabola_UTM_Zone_28N",                                              0 },	// Dabola 1981 / UTM zone 28N
	{   2064L,  2064L, "Dabola81.UTM-29N",           "Dabola_UTM_Zone_29N",                                              0 },	// Dabola 1981 / UTM zone 29N
	{   2065L,  2065L, "Krovak S-JTSK",              "S-JTSK_Ferro_Krovak",                                              1 },	// S-JTSK (Ferro) / Krovak
	{   2067L,  2067L, "Naparima55.UTM-20N",         "Naparima_1955_UTM_Zone_20N",                                       0 },	// Naparima 1955 / UTM zone 20N
	{   2068L,  2068L, "ELD79.Libya-5",              "ELD_1979_Libya_5",                                                 0 },	// ELD79 / Libya zone 5
	{   2069L,  2069L, "ELD79.Libya-6",              "ELD_1979_Libya_6",                                                 0 },	// ELD79 / Libya zone 6
	{   2070L,  2070L, "ELD79.Libya-7",              "ELD_1979_Libya_7",                                                 0 },	// ELD79 / Libya zone 7
	{   2071L,  2071L, "ELD79.Libya-8",              "ELD_1979_Libya_8",                                                 0 },	// ELD79 / Libya zone 8
	{   2072L,  2072L, "ELD79.Libya-9",              "ELD_1979_Libya_9",                                                 0 },	// ELD79 / Libya zone 9
	{   2073L,  2073L, "ELD79.Libya-10",             "ELD_1979_Libya_10",                                                0 },	// ELD79 / Libya zone 10
	{   2074L,  2074L, "ELD79.Libya-11",             "ELD_1979_Libya_11",                                                0 },	// ELD79 / Libya zone 11
	{   2075L,  2075L, "ELD79.Libya-12",             "ELD_1979_Libya_12",                                                0 },	// ELD79 / Libya zone 12
	{   2076L,  2076L, "ELD79.Libya-13",             "ELD_1979_Libya_13",                                                0 },	// ELD79 / Libya zone 13
	{   2077L,  2077L, "ELD79.UTM-32N",              "ELD_1979_UTM_Zone_32N",                                            0 },	// ELD79 / UTM zone 32N
	{   2078L,  2078L, "ELD79.UTM-33N",              "ELD_1979_UTM_Zone_33N",                                            0 },	// ELD79 / UTM zone 33N
	{   2079L,  2079L, "ELD79.UTM-34N",              "ELD_1979_UTM_Zone_34N",                                            0 },	// ELD79 / UTM zone 34N
	{   2080L,  2080L, "ELD79.UTM-35N",              "ELD_1979_UTM_Zone_35N",                                            0 },	// ELD79 / UTM zone 35N
	{   2082L,  2082L, "Castillo.Argentina-2",       "Pampa_del_Castillo_Argentina_2",                                   0 },	// Pampa del Castillo / Argentina zone 2
	{   2083L,  2083L, "Hito63.Argentina-2",         "Hito_XVIII_1963_Argentina_2",                                      0 },	// Hito XVIII 1963 / Argentina zone 2
	{   2084L,  2084L, "Hito63.UTM-19S",             "Hito_XVIII_1963_UTM_19S",                                          0 },	// Hito XVIII 1963 / UTM zone 19S
	{   2085L,  2085L, "NAD27.CubaNorte",            "NAD_1927_Cuba_Norte",                                              0 },	// NAD27 / Cuba Norte
	{   2086L,  2086L, "NAD27.CubaSur",              "NAD_1927_Cuba_Sur",                                                0 },	// NAD27 / Cuba Sur
	{   2087L,  2087L, "ELD79.TM-12NE",              "ELD_1979_TM_12_NE",                                                0 },	// ELD79 / TM 12 NE
	{   2088L,  2088L, "Carthage.TM-11NE",           "Carthage_TM_11_NE",                                                0 },	// Carthage / TM 11 NE
	{   2089L,  2089L, "Yemen96.UTM-38N",            "Yemen_NGN_1996_UTM_Zone_38N",                                      0 },	// Yemen NGN96 / UTM zone 38N
	{   2090L,  2090L, "Yemen96.UTM-39N",            "Yemen_NGN_1996_UTM_Zone_39N",                                      0 },	// Yemen NGN96 / UTM zone 39N
	{   2091L,  2091L, "SouthYemen.GK-8",            "South_Yemen_GK_Zone_8",                                            2 },	// South Yemen / Gauss Kruger zone 8
	{   2092L,  2092L, "SouthYemen.GK-9",            "South_Yemen_GK_Zone_9",                                            2 },	// South Yemen / Gauss Kruger zone 9
	{   2093L,  2093L, "Hanoi72.GK-106NE",           "Hanoi_1972_GK_106_NE",                                             0 },	// Hanoi 1972 / GK 106 NE
	{   2094L,  2094L, "WGS72be.TM-106NE",           "WGS_1972_BE_TM_106_NE",                                            0 },	// WGS 72BE / TM 106 NE
	{   2095L,  2095L, "Bissau.UTM-28N",             "Bissau_UTM_Zone_28N",                                              0 },	// Bissau / UTM zone 28N
	{   2099L,  2099L, "Qatar48.Qatar Grid",         "Qatar_1948_Qatar_Grid",                                            0 },	// Qatar 1948 / Qatar Grid
	{   2100L,  2100L, "GreekGRS87.GreekGrid",       "Greek_Grid",                                                       0 },	// GGRS87 / Greek Grid
	{   2105L,  2105L, "NZGD2K.MountEden",           "NZGD_2000_Mount_Eden_Circuit",                                     0 },	// NZGD2000 / Mount Eden Circuit 2000
	{   2106L,  2106L, "NZGD2K.BayofPlenty",         "NZGD_2000_Bay_of_Plenty_Circuit",                                  0 },	// NZGD2000 / Bay of Plenty Circuit 2000
	{   2107L,  2107L, "NZGD2K.PovertyBay",          "NZGD_2000_Poverty_Bay_Circuit",                                    0 },	// NZGD2000 / Poverty Bay Circuit 2000
	{   2108L,  2108L, "NZGD2K.HawkesBay",           "NZGD_2000_Hawkes_Bay_Circuit",                                     0 },	// NZGD2000 / Hawkes Bay Circuit 2000
	{   2109L,  2109L, "NZGD2K.Taranaki",            "NZGD_2000_Taranaki_Circuit",                                       0 },	// NZGD2000 / Taranaki Circuit 2000
	{   2110L,  2110L, "NZGD2K.Tuhirangi",           "NZGD_2000_Tuhirangi_Circuit",                                      0 },	// NZGD2000 / Tuhirangi Circuit 2000
	{   2111L,  2111L, "NZGD2K.Wanganui",            "NZGD_2000_Wanganui_Circuit",                                       0 },	// NZGD2000 / Wanganui Circuit 2000
	{   2112L,  2112L, "NZGD2K.Wairarapa",           "NZGD_2000_Wairarapa_Circuit",                                      0 },	// NZGD2000 / Wairarapa Circuit 2000
	{   2113L,  2113L, "NZGD2K.Wellington",          "NZGD_2000_Wellington_Circuit",                                     0 },	// NZGD2000 / Wellington Circuit 2000
	{   2114L,  2114L, "NZGD2K.Collingwood",         "NZGD_2000_Collingwood_Circuit",                                    0 },	// NZGD2000 / Collingwood Circuit 2000
	{   2115L,  2115L, "NZGD2K.Nelson",              "NZGD_2000_Nelson_Circuit",                                         0 },	// NZGD2000 / Nelson Circuit 2000
	{   2116L,  2116L, "NZGD2K.Karamea",             "NZGD_2000_Karamea_Circuit",                                        0 },	// NZGD2000 / Karamea Circuit 2000
	{   2117L,  2117L, "NZGD2K.Buller",              "NZGD_2000_Buller_Circuit",                                         0 },	// NZGD2000 / Buller Circuit 2000
	{   2118L,  2118L, "NZGD2K.Grey",                "NZGD_2000_Grey_Circuit",                                           0 },	// NZGD2000 / Grey Circuit 2000
	{   2119L,  2119L, "NZGD2K.Amuri",               "NZGD_2000_Amuri_Circuit",                                          0 },	// NZGD2000 / Amuri Circuit 2000
	{   2120L,  2120L, "NZGD2K.Marlborough",         "NZGD_2000_Marlborough_Circuit",                                    0 },	// NZGD2000 / Marlborough Circuit 2000
	{   2121L,  2121L, "NZGD2K.Hokitika",            "NZGD_2000_Hokitika_Circuit",                                       0 },	// NZGD2000 / Hokitika Circuit 2000
	{   2122L,  2122L, "NZGD2K.Okarito",             "NZGD_2000_Okarito_Circuit",                                        0 },	// NZGD2000 / Okarito Circuit 2000
	{   2123L,  2123L, "NZGD2K.JacksonsBay",         "NZGD_2000_Jacksons_Bay_Circuit",                                   0 },	// NZGD2000 / Jacksons Bay Circuit 2000
	{   2124L,  2124L, "NZGD2K.MountPleasant",       "NZGD_2000_Mount_Pleasant_Circuit",                                 0 },	// NZGD2000 / Mount Pleasant Circuit 2000
	{   2125L,  2125L, "NZGD2K.Gawler",              "NZGD_2000_Gawler_Circuit",                                         0 },	// NZGD2000 / Gawler Circuit 2000
	{   2126L,  2126L, "NZGD2K.Timaru",              "NZGD_2000_Timaru_Circuit",                                         0 },	// NZGD2000 / Timaru Circuit 2000
	{   2127L,  2127L, "NZGD2K.LindisPeak",          "NZGD_2000_Lindis_Peak_Circuit",                                    0 },	// NZGD2000 / Lindis Peak Circuit 2000
	{   2128L,  2128L, "NZGD2K.MountNicholas",       "NZGD_2000_Mount_Nicholas_Circuit",                                 0 },	// NZGD2000 / Mount Nicholas Circuit 2000
	{   2129L,  2129L, "NZGD2K.MountYork",           "NZGD_2000_Mount_York_Circuit",                                     0 },	// NZGD2000 / Mount York Circuit 2000
	{   2130L,  2130L, "NZGD2K.ObservationPnt",      "NZGD_2000_Observation_Point_Circuit",                              0 },	// NZGD2000 / Observation Point Circuit 2000
	{   2131L,  2131L, "NZGD2K.NorthTaieri",         "NZGD_2000_North_Taieri_Circuit",                                   0 },	// NZGD2000 / North Taieri Circuit 2000
	{   2132L,  2132L, "NZGD2K.Bluff",               "NZGD_2000_Bluff_Circuit",                                          0 },	// NZGD2000 / Bluff Circuit 2000
	{   2133L,  2133L, "NZGD2K.UTM-58S",             "NZGD_2000_UTM_Zone_58S",                                           0 },	// NZGD2000 / UTM zone 58S
	{   2134L,  2134L, "NZGD2K.UTM-59S",             "NZGD_2000_UTM_Zone_59S",                                           0 },	// NZGD2000 / UTM zone 59S
	{   2135L,  2135L, "NZGD2K.UTM-60S",             "NZGD_2000_UTM_Zone_60S",                                           0 },	// NZGD2000 / UTM zone 60S
	{   2136L,  2136L, "Accra.GhanaNational",        "Accra_Ghana_Grid",                                                 0 },	// Accra / Ghana National Grid
	{   2137L,  2137L, "Accra.TM-1NW",               "Accra_TM_1_NW",                                                    0 },	// Accra / TM 1 NW
	{   2139L,  2139L, "NAD83/98.SCoPQ-2",           "NAD_1983_CSRS98_MTM_2_SCoPQ",                                      2 },	// NAD83(CSRS98) / SCoPQ zone 2
	{   2140L,  2140L, "NAD83/98.MTM-3",             "NAD_1983_CRS98_MTM_3",                                             2 },	// NAD83(CSRS98) / MTM zone 3
	{   2141L,  2141L, "NAD83/98.MTM-4",             "NAD_1983_CRS98_MTM_4",                                             2 },	// NAD83(CSRS98) / MTM zone 4
	{   2142L,  2142L, "NAD83/98.MTM-5",             "NAD_1983_CRS98_MTM_5",                                             2 },	// NAD83(CSRS98) / MTM zone 5
	{   2143L,  2143L, "NAD83/98.MTM-6",             "NAD_1983_CRS98_MTM_6",                                             2 },	// NAD83(CSRS98) / MTM zone 6
	{   2144L,  2144L, "NAD83/98.MTM-7",             "NAD_1983_CRS98_MTM_7",                                             2 },	// NAD83(CSRS98) / MTM zone 7
	{   2145L,  2145L, "NAD83/98.MTM-8",             "NAD_1983_CRS98_MTM_8",                                             2 },	// NAD83(CSRS98) / MTM zone 8
	{   2146L,  2146L, "NAD83/98.MTM-9",             "NAD_1983_CRS98_MTM_9",                                             2 },	// NAD83(CSRS98) / MTM zone 9
	{   2147L,  2147L, "NAD83/98.MTM-10",            "NAD_1983_CRS98_MTM_10",                                            2 },	// NAD83(CSRS98) / MTM zone 10
	{   2148L,  2148L, "NAD83/98.UTM-21N",           "NAD_1983_CSRS98_UTM_Zone_21N",                                     2 },	// NAD83(CSRS98) / UTM zone 21N
	{   2149L,  2149L, "NAD83/98.UTM-18N",           "NAD_1983_CSRS98_UTM_Zone_18N",                                     2 },	// NAD83(CSRS98) / UTM zone 18N
	{   2150L,  2150L, "NAD83/98.UTM-17N",           "NAD_1983_CSRS98_UTM_Zone_17N",                                     2 },	// NAD83(CSRS98) / UTM zone 17N
	{   2151L,  2151L, "NAD83/98.UTM-13N",           "NAD_1983_CSRS98_UTM_Zone_13N",                                     2 },	// NAD83(CSRS98) / UTM zone 13N
	{   2152L,  2152L, "NAD83/98.UTM-12N",           "NAD_1983_CSRS98_UTM_Zone_12N",                                     2 },	// NAD83(CSRS98) / UTM zone 12N
	{   2153L,  2153L, "NAD83/98.UTM-11N",           "NAD_1983_CSRS98_UTM_Zone_11N",                                     2 },	// NAD83(CSRS98) / UTM zone 11N
	{   2154L,  2154L, "IGN-RGF93",                  "RGF_1993_Lambert_93",                                              1 },	// RGF93 / Lambert-93
	{   2155L,  2155L, "AmSamoa62.Lambert",          "Samoa_1962_Samoa_Lambert",                                         2 },	// American Samoa 1962 / American Samoa Lambert
	{   2157L,  2157L, "IRENET95.IrishTM",           "IRENET95_Irish_Transverse_Mercator",                               0 },	// IRENET95 / Irish Transverse Mercator
	{   2158L,  2158L, "IRENET95.UTM-29N",           "IRENET95_UTM_Zone_29N",                                            0 },	// IRENET95 / UTM zone 29N
	{   2161L,  2161L, "SierraLeone68.UTM-28N",      "Sierra_Leone_1968_UTM_Zone_28N",                                   0 },	// Sierra Leone 1968 / UTM zone 28N
	{   2162L,  2162L, "SierraLeone68.UTM-29N",      "Sierra_Leone_1968_UTM_Zone_29N",                                   0 },	// Sierra Leone 1968 / UTM zone 29N
	{   2164L,  2164L, "Locodjo65.TM-5NW",           "Locodjo_1965_TM_5_NW",                                             0 },	// Locodjo 1965 / TM 5 NW
	{   2165L,  2165L, "Abidjan87.TM-5NW",           "Abidjan_1987_TM_5_NW",                                             0 },	// Abidjan 1987 / TM 5 NW
	{   2166L,  2166L, "Pulkovo/83.GK-3",            "Pulkovo_1942_Adj_1983_3_Degree_GK_Zone_3",                         2 },	// Pulkovo 1942(83) / Gauss Kruger zone 3
	{   2167L,  2167L, "Pulkovo/83.GK-4",            "Pulkovo_1942_Adj_1983_3_Degree_GK_Zone_4",                         2 },	// Pulkovo 1942(83) / Gauss Kruger zone 4
	{   2168L,  2168L, "Pulkovo/83.GK-5",            "Pulkovo_1942_Adj_1983_3_Degree_GK_Zone_5",                         2 },	// Pulkovo 1942(83) / Gauss Kruger zone 5
	{   2169L,  2169L, "Luxembourg30.Gauss",         "Luxembourg_1930_Gauss",                                            0 },	// Luxembourg 1930 / Gauss
	{   2170L,  2170L, "MGI.Slovenia",               "MGI_Slovenia_Grid",                                                0 },	// MGI / Slovenia Grid
	{   2176L,  2176L, "ETRS89.PolandCS2K-5",        "ETRS_1989_Poland_CS2000_Zone_5",                                   0 },	// ETRS89 / Poland CS2000 zone 5
	{   2177L,  2177L, "ETRS89.PolandCS2K-6",        "ETRS_1989_Poland_CS2000_Zone_6",                                   0 },	// ETRS89 / Poland CS2000 zone 6
	{   2178L,  2178L, "ETRS89.PolandCS2K-7",        "ETRS_1989_Poland_CS2000_Zone_7",                                   0 },	// ETRS89 / Poland CS2000 zone 7
	{   2179L,  2179L, "ETRS89.PolandCS2K-8",        "ETRS_1989_Poland_CS2000_Zone_8",                                   0 },	// ETRS89 / Poland CS2000 zone 8
	{   2180L,  2180L, "ETRS89.PolandCS92",          "ETRS_1989_Poland_CS92",                                            0 },	// ETRS89 / Poland CS92
	{   2192L,  2192L, "ED50.EuroLambert",           "ED_1950_France_EuroLambert",                                       0 },	// ED50 / France EuroLambert
	{   2193L,  2193L, "NZTM",                       "NZGD_2000_New_Zealand_Transverse_Mercator",                        1 },	// NZGD2000 / New Zealand Transverse Mercator
	{   2195L,  2195L, "HARN.UTM-2S",                "NAD_1983_HARN_UTM_Zone_2S",                                        0 },	// NAD83(HARN) / UTM zone 2S
	{   2196L,  2196L, "ETRS89.Kp2K-Jutland",        "ETRS_1989_Kp2000_Jutland",                                         0 },	// ETRS89 / Kp2000 Jutland
	{   2197L,  2197L, "ETRS89.Kp2K-Zealand",        "ETRS_1989_Kp2000_Zealand",                                         0 },	// ETRS89 / Kp2000 Zealand
	{   2198L,  2198L, "ETRS89.Kp2K-Bornholm",       "ETRS_1989_Kp2000_Bornholm",                                        0 },	// ETRS89 / Kp2000 Bornholm
	{   2200L,  2200L, "NewBrunswick77",             "ATS_1977_New_Brunswick_Stereographic",                             1 },	// ATS77 / New Brunswick Stereographic (ATS77)
	{   2201L,  2201L, "REGVEN.UTM-18N",             "REGVEN_UTM_Zone_18N",                                              0 },	// REGVEN / UTM zone 18N
	{   2202L,  2202L, "REGVEN.UTM-19N",             "REGVEN_UTM_Zone_19N",                                              0 },	// REGVEN / UTM zone 19N
	{   2203L,  2203L, "REGVEN.UTM-20N",             "REGVEN_UTM_Zone_20N",                                              0 },	// REGVEN / UTM zone 20N
	{  32036L,  2204L, "TN",                         "NAD_1927_StatePlane_Tennessee_FIPS_4100",                          1 },	// NAD27 / Tennessee
	{  26979L, 26979L, "KY83-N",                     "NAD_1983_StatePlane_Kentucky_North_FIPS_1601",                     3 },	// NAD83 / Kentucky North
	{   2206L,  2206L, "ED50.GK3d-9",                "ED_1950_3_Degree_GK_Zone_9",                                       0 },	// ED50 / 3-degree Gauss-Kruger zone 9
	{   2207L,  2207L, "ED50.GK3d-10",               "ED_1950_3_Degree_GK_Zone_10",                                      0 },	// ED50 / 3-degree Gauss-Kruger zone 10
	{   2208L,  2208L, "ED50.GK3d-11",               "ED_1950_3_Degree_GK_Zone_11",                                      0 },	// ED50 / 3-degree Gauss-Kruger zone 11
	{   2209L,  2209L, "ED50.GK3d-12",               "ED_1950_3_Degree_GK_Zone_12",                                      0 },	// ED50 / 3-degree Gauss-Kruger zone 12
	{   2210L,  2210L, "ED50.GK3d-13",               "ED_1950_3_Degree_GK_Zone_13",                                      0 },	// ED50 / 3-degree Gauss-Kruger zone 13
	{   2211L,  2211L, "ED50.GK3d-14",               "ED_1950_3_Degree_GK_Zone_14",                                      0 },	// ED50 / 3-degree Gauss-Kruger zone 14
	{   2212L,  2212L, "ED50.GK3d-15",               "ED_1950_3_Degree_GK_Zone_15",                                      0 },	// ED50 / 3-degree Gauss-Kruger zone 15
	{   2213L,  2213L, "ETRS89.TM-30NE",             "ETRS_1989_TM_30_NE",                                               0 },	// ETRS89 / TM 30 NE
	{   2215L,  2215L, "Manoca62.UTM-32N",           "Manoca_1962_UTM_Zone_32N",                                         0 },	// Manoca 1962 / UTM zone 32N
	{   2216L,  2216L, "Qornoq27.UTM-22N",           "Qornoq_1927_UTM_Zone_22N",                                         0 },	// Qornoq 1927 / UTM zone 22N
	{   2217L,  2217L, "Qornoq27.UTM-23N",           "Qornoq_1927_UTM_Zone_23N",                                         0 },	// Qornoq 1927 / UTM zone 23N
	{   2219L,  2219L, "ATS77.UTM-19N",              "ATS_1977_UTM_Zone_19N",                                            0 },	// ATS77 / UTM zone 19N
	{   2220L,  2220L, "ATS77.UTM-20N",              "ATS_1977_UTM_Zone_20N",                                            0 },	// ATS77 / UTM zone 20N
	{   2222L,  2222L, "AZ83-EIF",                   "NAD_1983_StatePlane_Arizona_East_FIPS_0201_Feet_Intl",             1 },	// NAD83 / Arizona East (ft)
	{   2223L,  2223L, "AZ83-CIF",                   "NAD_1983_StatePlane_Arizona_Central_FIPS_0202_Feet_Intl",          1 },	// NAD83 / Arizona Central (ft)
	{   2224L,  2224L, "AZ83-WIF",                   "NAD_1983_StatePlane_Arizona_West_FIPS_0203_Feet_Intl",             1 },	// NAD83 / Arizona West (ft)
	{   2225L,  2225L, "CA83-IF",                    "NAD_1983_StatePlane_California_I_FIPS_0401_Feet",                  1 },	// NAD83 / California zone 1 (ftUS)
	{   2226L,  2226L, "CA83-IIF",                   "NAD_1983_StatePlane_California_II_FIPS_0402_Feet",                 1 },	// NAD83 / California zone 2 (ftUS)
	{   2227L,  2227L, "CA83IIIF",                   "NAD_1983_StatePlane_California_III_FIPS_0403_Feet",                1 },	// NAD83 / California zone 3 (ftUS)
	{   2228L,  2228L, "CA83-IVF",                   "NAD_1983_StatePlane_California_IV_FIPS_0404_Feet",                 1 },	// NAD83 / California zone 4 (ftUS)
	{   2229L,  2229L, "CA83-VF",                    "NAD_1983_StatePlane_California_V_FIPS_0405_Feet",                  1 },	// NAD83 / California zone 5 (ftUS)
	{   2230L,  2230L, "CA83-VIF",                   "NAD_1983_StatePlane_California_VI_FIPS_0406_Feet",                 1 },	// NAD83 / California zone 6 (ftUS)
	{   2231L,  2231L, "CO83-NF",                    "NAD_1983_StatePlane_Colorado_North_FIPS_0501_Feet",                1 },	// NAD83 / Colorado North (ftUS)
	{   2232L,  2232L, "CO83-CF",                    "NAD_1983_StatePlane_Colorado_Central_FIPS_0502_Feet",              1 },	// NAD83 / Colorado Central (ftUS)
	{   2233L,  2233L, "CO83-SF",                    "NAD_1983_StatePlane_Colorado_South_FIPS_0503_Feet",                1 },	// NAD83 / Colorado South (ftUS)
	{   2234L,  2234L, "CT83F",                      "NAD_1983_StatePlane_Connecticut_FIPS_0600_Feet",                   1 },	// NAD83 / Connecticut (ftUS)
	{   2235L,  2235L, "DE83F",                      "NAD_1983_StatePlane_Delaware_FIPS_0700_Feet",                      1 },	// NAD83 / Delaware (ftUS)
	{   2236L,  2236L, "FL83-EF",                    "NAD_1983_StatePlane_Florida_East_FIPS_0901_Feet",                  1 },	// NAD83 / Florida East (ftUS)
	{   2237L,  2237L, "FL83-WF",                    "NAD_1983_StatePlane_Florida_West_FIPS_0902_Feet",                  1 },	// NAD83 / Florida West (ftUS)
	{   2238L,  2238L, "FL83-NF",                    "NAD_1983_StatePlane_Florida_North_FIPS_0903_Feet",                 1 },	// NAD83 / Florida North (ftUS)
	{   2239L,  2239L, "GA83-EF",                    "NAD_1983_StatePlane_Georgia_East_FIPS_1001_Feet",                  1 },	// NAD83 / Georgia East (ftUS)
	{   2240L,  2240L, "GA83-WF",                    "NAD_1983_StatePlane_Georgia_West_FIPS_1002_Feet",                  1 },	// NAD83 / Georgia West (ftUS)
	{   2241L,  2241L, "ID83-EF",                    "NAD_1983_StatePlane_Idaho_East_FIPS_1101_Feet",                    1 },	// NAD83 / Idaho East (ftUS)
	{   2242L,  2242L, "ID83-CF",                    "NAD_1983_StatePlane_Idaho_Central_FIPS_1102_Feet",                 1 },	// NAD83 / Idaho Central (ftUS)
	{   2243L,  2243L, "ID83-WF",                    "NAD_1983_StatePlane_Idaho_West_FIPS_1103_Feet",                    1 },	// NAD83 / Idaho West (ftUS)
	{   2965L,  2244L, "IN83-EF",                    "NAD_1983_StatePlane_Indiana_East_FIPS_1301_Feet",                  3 },	// NAD83 / Indiana East (ftUS)
	{   2966L,  2245L, "IN83-WF",                    "NAD_1983_StatePlane_Indiana_West_FIPS_1302_Feet",                  3 },	// NAD83 / Indiana West (ftUS)
	{   2246L,  2246L, "KY83-NF",                    "NAD_1983_StatePlane_Kentucky_North_FIPS_1601_Feet",                1 },	// NAD83 / Kentucky North (ftUS)
	{   2247L,  2247L, "KY83-SF",                    "NAD_1983_StatePlane_Kentucky_South_FIPS_1602_Feet",                1 },	// NAD83 / Kentucky South (ftUS)
	{   2248L,  2248L, "MD83F",                      "NAD_1983_StatePlane_Maryland_FIPS_1900_Feet",                      1 },	// NAD83 / Maryland (ftUS)
	{   2249L,  2249L, "MA83F",                      "NAD_1983_StatePlane_Massachusetts_Mainland_FIPS_2001_Feet",        1 },	// NAD83 / Massachusetts Mainland (ftUS)
	{   2250L,  2250L, "MA83-ISF",                   "NAD_1983_StatePlane_Massachusetts_Island_FIPS_2002_Feet",          1 },	// NAD83 / Massachusetts Island (ftUS)
	{   2251L,  2251L, "MI83-NIF",                   "NAD_1983_StatePlane_Michigan_North_FIPS_2111_Feet_Intl",           1 },	// NAD83 / Michigan North (ft)
	{   2252L,  2252L, "MI83-CIF",                   "NAD_1983_StatePlane_Michigan_Central_FIPS_2112_Feet_Intl",         1 },	// NAD83 / Michigan Central (ft)
	{   2253L,  2253L, "MI83-SIF",                   "NAD_1983_StatePlane_Michigan_South_FIPS_2113_Feet_Intl",           1 },	// NAD83 / Michigan South (ft)
	{   2254L,  2254L, "MS83-EF",                    "NAD_1983_StatePlane_Mississippi_East_FIPS_2301_Feet",              1 },	// NAD83 / Mississippi East (ftUS)
	{   2255L,  2255L, "MS83-WF",                    "NAD_1983_StatePlane_Mississippi_West_FIPS_2302_Feet",              1 },	// NAD83 / Mississippi West (ftUS)
	{   2256L,  2256L, "MT83IF",                     "NAD_1983_StatePlane_Montana_FIPS_2500_Feet_Intl",                  1 },	// NAD83 / Montana (ft)
	{   2257L,  2257L, "NM83-EF",                    "NAD_1983_StatePlane_New_Mexico_East_FIPS_3001_Feet",               1 },	// NAD83 / New Mexico East (ftUS)
	{   2258L,  2258L, "NM83-CF",                    "NAD_1983_StatePlane_New_Mexico_Central_FIPS_3002_Feet",            1 },	// NAD83 / New Mexico Central (ftUS)
	{   2259L,  2259L, "NM83-WF",                    "NAD_1983_StatePlane_New_Mexico_West_FIPS_3003_Feet",               1 },	// NAD83 / New Mexico West (ftUS)
	{   2260L,  2260L, "NY83-EF",                    "NAD_1983_StatePlane_New_York_East_FIPS_3101_Feet",                 1 },	// NAD83 / New York East (ftUS)
	{   2261L,  2261L, "NY83-CF",                    "NAD_1983_StatePlane_New_York_Central_FIPS_3102_Feet",              1 },	// NAD83 / New York Central (ftUS)
	{   2262L,  2262L, "NY83-WF",                    "NAD_1983_StatePlane_New_York_West_FIPS_3103_Feet",                 1 },	// NAD83 / New York West (ftUS)
	{   2263L,  2263L, "NY83-LIF",                   "NAD_1983_StatePlane_New_York_Long_Island_FIPS_3104_Feet",          1 },	// NAD83 / New York Long Island (ftUS)
	{   2264L,  2264L, "NC83F",                      "NAD_1983_StatePlane_North_Carolina_FIPS_3200_Feet",                1 },	// NAD83 / North Carolina (ftUS)
	{   2265L,  2265L, "NAD83.ND-Nft",               "NAD_1983_StatePlane_North_Dakota_North_FIPS_3301_Feet_Intl",       0 },	// NAD83 / North Dakota North (ft)
	{   2266L,  2266L, "NAD83.ND-Sft",               "NAD_1983_StatePlane_North_Dakota_South_FIPS_3302_Feet_Intl",       0 },	// NAD83 / North Dakota South (ft)
	{   2267L,  2267L, "OK83-NF",                    "NAD_1983_StatePlane_Oklahoma_North_FIPS_3501_Feet",                1 },	// NAD83 / Oklahoma North (ftUS)
	{   2268L,  2268L, "OK83-SF",                    "NAD_1983_StatePlane_Oklahoma_South_FIPS_3502_Feet",                1 },	// NAD83 / Oklahoma South (ftUS)
	{   2269L,  2269L, "OR83-NIF",                   "NAD_1983_StatePlane_Oregon_North_FIPS_3601_Feet_Intl",             1 },	// NAD83 / Oregon North (ft)
	{   2270L,  2270L, "OR83-SIF",                   "NAD_1983_StatePlane_Oregon_South_FIPS_3602_Feet_Intl",             1 },	// NAD83 / Oregon South (ft)
	{   2271L,  2271L, "PA83-NF",                    "NAD_1983_StatePlane_Pennsylvania_North_FIPS_3701_Feet",            1 },	// NAD83 / Pennsylvania North (ftUS)
	{   2272L,  2272L, "PA83-SF",                    "NAD_1983_StatePlane_Pennsylvania_South_FIPS_3702_Feet",            1 },	// NAD83 / Pennsylvania South (ftUS)
	{   2273L,  2273L, "SC83IF",                     "NAD_1983_StatePlane_South_Carolina_FIPS_3900_Feet_Intl",           1 },	// NAD83 / South Carolina (ft)
	{   2274L,  2274L, "TN83F",                      "NAD_1983_StatePlane_Tennessee_FIPS_4100_Feet",                     1 },	// NAD83 / Tennessee (ftUS)
	{   2275L,  2275L, "TX83-NF",                    "NAD_1983_StatePlane_Texas_North_FIPS_4201_Feet",                   1 },	// NAD83 / Texas North (ftUS)
	{   2276L,  2276L, "TX83-NCF",                   "NAD_1983_StatePlane_Texas_North_Central_FIPS_4202_Feet",           1 },	// NAD83 / Texas North Central (ftUS)
	{   2277L,  2277L, "TX83-CF",                    "NAD_1983_StatePlane_Texas_Central_FIPS_4203_Feet",                 1 },	// NAD83 / Texas Central (ftUS)
	{   2278L,  2278L, "TX83-SCF",                   "NAD_1983_StatePlane_Texas_South_Central_FIPS_4204_Feet",           1 },	// NAD83 / Texas South Central (ftUS)
	{   2279L,  2279L, "TX83-SF",                    "NAD_1983_StatePlane_Texas_South_FIPS_4205_Feet",                   1 },	// NAD83 / Texas South (ftUS)
	{   2280L,  2280L, "UT83-NIF",                   "NAD_1983_StatePlane_Utah_North_FIPS_4301_Feet_Intl",               1 },	// NAD83 / Utah North (ft)
	{   2281L,  2281L, "UT83-CIF",                   "NAD_1983_StatePlane_Utah_Central_FIPS_4302_Feet_Intl",             1 },	// NAD83 / Utah Central (ft)
	{   2282L,  2282L, "UT83-SIF",                   "NAD_1983_StatePlane_Utah_South_FIPS_4303_Feet_Intl",               1 },	// NAD83 / Utah South (ft)
	{   2283L,  2283L, "VA83-NF",                    "NAD_1983_StatePlane_Virginia_North_FIPS_4501_Feet",                1 },	// NAD83 / Virginia North (ftUS)
	{   2284L,  2284L, "VA83-SF",                    "NAD_1983_StatePlane_Virginia_South_FIPS_4502_Feet",                1 },	// NAD83 / Virginia South (ftUS)
	{   2285L,  2285L, "WA83-NF",                    "NAD_1983_StatePlane_Washington_North_FIPS_4601_Feet",              1 },	// NAD83 / Washington North (ftUS)
	{   2286L,  2286L, "WA83-SF",                    "NAD_1983_StatePlane_Washington_South_FIPS_4602_Feet",              1 },	// NAD83 / Washington South (ftUS)
	{   2287L,  2287L, "WI83-NF",                    "NAD_1983_StatePlane_Wisconsin_North_FIPS_4801_Feet",               1 },	// NAD83 / Wisconsin North (ftUS)
	{   2288L,  2288L, "WI83-CF",                    "NAD_1983_StatePlane_Wisconsin_Central_FIPS_4802_Feet",             1 },	// NAD83 / Wisconsin Central (ftUS)
	{   2289L,  2289L, "WI83-SF",                    "NAD_1983_StatePlane_Wisconsin_South_FIPS_4803_Feet",               1 },	// NAD83 / Wisconsin South (ftUS)
	{   2290L,  2290L, "PrinceEdwardIsland77",       "Prince_Edward_Island_Stereographic",                               1 },	// ATS77 / Prince Edward Isl. Stereographic (ATS77)
	{   2291L,  2291L, "PrinceEdwardIslandCSRS",     "NAD_1983_CSRS98_Prince_Edward_Island",                             3 },	// NAD83(CSRS98) / Prince Edward Isl. Stereographic (NAD83)
	{   2294L,  2294L, "NovaScotia77-4",             "ATS_1977_MTM_4_Nova_Scotia",                                       1 },	// ATS77 / MTM Nova Scotia zone 4
	{   2295L,  2295L, "NovaScotia77-5",             "ATS_1977_MTM_5_Nova_Scotia",                                       1 },	// ATS77 / MTM Nova Scotia zone 5
	{   2308L,  2308L, "Batavia.TM-109SE",           "Batavia_TM_109_SE",                                                0 },	// Batavia / TM 109 SE
	{   2309L,  2309L, "WGS84.TM-116SE",             "WGS_1984_TM_116_SE",                                               0 },	// WGS 84 / TM 116 SE
	{   2310L,  2310L, "WGS84.TM-132SE",             "WGS_1984_TM_132_SE",                                               0 },	// WGS 84 / TM 132 SE
	{   2311L,  2311L, "WGS84.TM-6NE",               "WGS_1984_TM_6_NE",                                                 0 },	// WGS 84 / TM 6 NE
	{   2314L,  2314L, "Trinidad03.TrinidadGrid",    "Trinidad_1903_Trinidad_Grid_Feet_Clarke",                          0 },	// Trinidad 1903 / Trinidad Grid (ftCla)
	{   2315L,  2315L, "CampoInchauspe.UTM-19S",     "Campo_Inchauspe_UTM_19S",                                          0 },	// Campo Inchauspe / UTM zone 19S
	{   2316L,  2316L, "CampoInchauspe.UTM-20S",     "Campo_Inchauspe_UTM_20S",                                          0 },	// Campo Inchauspe / UTM zone 20S
	{   2317L,  2317L, "PSAD56.IcnRegional",         "PSAD_1956_ICN_Regional",                                           0 },	// PSAD56 / ICN Regional
	{   2318L,  2318L, "AINELABD.AramcoLambert",     "Ain_el_Abd_Aramco_Lambert",                                        0 },	// Ain el Abd / Aramco Lambert
	{   2319L,  2319L, "ED50.TM27",                  "ED_1950_TM27",                                                     0 },	// ED50 / TM27
	{   2320L,  2320L, "ED50.TM30",                  "ED_1950_TM30",                                                     0 },	// ED50 / TM30
	{   2321L,  2321L, "ED50.TM33",                  "ED_1950_TM33",                                                     0 },	// ED50 / TM33
	{   2322L,  2322L, "ED50.TM36",                  "ED_1950_TM36",                                                     0 },	// ED50 / TM36
	{   2323L,  2323L, "ED50.TM39",                  "ED_1950_TM39",                                                     0 },	// ED50 / TM39
	{   2324L,  2324L, "ED50.TM42",                  "ED_1950_TM42",                                                     0 },	// ED50 / TM42
	{   2325L,  2325L, "ED50.TM45",                  "ED_1950_TM45",                                                     0 },	// ED50 / TM45
	{   2326L,  2326L, "HongKong80.GridSystem",      "Hong_Kong_1980_Grid",                                              0 },	// Hong Kong 1980 Grid System
	{   2327L,  2327L, "Xian80.GK-13",               "Xian_1980_GK_Zone_13",                                             0 },	// Xian 1980 / Gauss-Kruger zone 13
	{   2328L,  2328L, "Xian80.GK-14",               "Xian_1980_GK_Zone_14",                                             0 },	// Xian 1980 / Gauss-Kruger zone 14
	{   2329L,  2329L, "Xian80.GK-15",               "Xian_1980_GK_Zone_15",                                             0 },	// Xian 1980 / Gauss-Kruger zone 15
	{   2330L,  2330L, "Xian80.GK-16",               "Xian_1980_GK_Zone_16",                                             0 },	// Xian 1980 / Gauss-Kruger zone 16
	{   2331L,  2331L, "Xian80.GK-17",               "Xian_1980_GK_Zone_17",                                             0 },	// Xian 1980 / Gauss-Kruger zone 17
	{   2332L,  2332L, "Xian80.GK-18",               "Xian_1980_GK_Zone_18",                                             0 },	// Xian 1980 / Gauss-Kruger zone 18
	{   2333L,  2333L, "Xian80.GK-19",               "Xian_1980_GK_Zone_19",                                             0 },	// Xian 1980 / Gauss-Kruger zone 19
	{   2334L,  2334L, "Xian80.GK-20",               "Xian_1980_GK_Zone_20",                                             0 },	// Xian 1980 / Gauss-Kruger zone 20
	{   2335L,  2335L, "Xian80.GK-21",               "Xian_1980_GK_Zone_21",                                             0 },	// Xian 1980 / Gauss-Kruger zone 21
	{   2336L,  2336L, "Xian80.GK-22",               "Xian_1980_GK_Zone_22",                                             0 },	// Xian 1980 / Gauss-Kruger zone 22
	{   2337L,  2337L, "Xian80.GK-23",               "Xian_1980_GK_Zone_23",                                             0 },	// Xian 1980 / Gauss-Kruger zone 23
	{   2338L,  2338L, "Xian80.GK/CM-75E",           "Xian_1980_GK_CM_75E",                                              0 },	// Xian 1980 / Gauss-Kruger CM 75E
	{   2339L,  2339L, "Xian80.GK/CM-81E",           "Xian_1980_GK_CM_81E",                                              0 },	// Xian 1980 / Gauss-Kruger CM 81E
	{   2340L,  2340L, "Xian80.GK/CM-87E",           "Xian_1980_GK_CM_87E",                                              0 },	// Xian 1980 / Gauss-Kruger CM 87E
	{   2341L,  2341L, "Xian80.GK/CM-93E",           "Xian_1980_GK_CM_93E",                                              0 },	// Xian 1980 / Gauss-Kruger CM 93E
	{   2342L,  2342L, "Xian80.GK/CM-99E",           "Xian_1980_GK_CM_99E",                                              0 },	// Xian 1980 / Gauss-Kruger CM 99E
	{   2343L,  2343L, "Xian80.GK/CM-105E",          "Xian_1980_GK_CM_105E",                                             0 },	// Xian 1980 / Gauss-Kruger CM 105E
	{   2344L,  2344L, "Xian80.GK/CM-111E",          "Xian_1980_GK_CM_111E",                                             0 },	// Xian 1980 / Gauss-Kruger CM 111E
	{   2345L,  2345L, "Xian80.GK/CM-117E",          "Xian_1980_GK_CM_117E",                                             0 },	// Xian 1980 / Gauss-Kruger CM 117E
	{   2346L,  2346L, "Xian80.GK/CM-123E",          "Xian_1980_GK_CM_123E",                                             0 },	// Xian 1980 / Gauss-Kruger CM 123E
	{   2347L,  2347L, "Xian80.GK/CM-129E",          "Xian_1980_GK_CM_129E",                                             0 },	// Xian 1980 / Gauss-Kruger CM 129E
	{   2348L,  2348L, "Xian80.GK/CM-135E",          "Xian_1980_GK_CM_135E",                                             0 },	// Xian 1980 / Gauss-Kruger CM 135E
	{   2349L,  2349L, "Xian80.GK3d-25",             "Xian_1980_3_Degree_GK_Zone_25",                                    0 },	// Xian 1980 / 3-degree Gauss-Kruger zone 25
	{   2350L,  2350L, "Xian80.GK3d-26",             "Xian_1980_3_Degree_GK_Zone_26",                                    0 },	// Xian 1980 / 3-degree Gauss-Kruger zone 26
	{   2351L,  2351L, "Xian80.GK3d-27",             "Xian_1980_3_Degree_GK_Zone_27",                                    0 },	// Xian 1980 / 3-degree Gauss-Kruger zone 27
	{   2352L,  2352L, "Xian80.GK3d-28",             "Xian_1980_3_Degree_GK_Zone_28",                                    0 },	// Xian 1980 / 3-degree Gauss-Kruger zone 28
	{   2353L,  2353L, "Xian80.GK3d-29",             "Xian_1980_3_Degree_GK_Zone_29",                                    0 },	// Xian 1980 / 3-degree Gauss-Kruger zone 29
	{   2354L,  2354L, "Xian80.GK3d-30",             "Xian_1980_3_Degree_GK_Zone_30",                                    0 },	// Xian 1980 / 3-degree Gauss-Kruger zone 30
	{   2355L,  2355L, "Xian80.GK3d-31",             "Xian_1980_3_Degree_GK_Zone_31",                                    0 },	// Xian 1980 / 3-degree Gauss-Kruger zone 31
	{   2356L,  2356L, "Xian80.GK3d-32",             "Xian_1980_3_Degree_GK_Zone_32",                                    0 },	// Xian 1980 / 3-degree Gauss-Kruger zone 32
	{   2357L,  2357L, "Xian80.GK3d-33",             "Xian_1980_3_Degree_GK_Zone_33",                                    0 },	// Xian 1980 / 3-degree Gauss-Kruger zone 33
	{   2358L,  2358L, "Xian80.GK3d-34",             "Xian_1980_3_Degree_GK_Zone_34",                                    0 },	// Xian 1980 / 3-degree Gauss-Kruger zone 34
	{   2359L,  2359L, "Xian80.GK3d-35",             "Xian_1980_3_Degree_GK_Zone_35",                                    0 },	// Xian 1980 / 3-degree Gauss-Kruger zone 35
	{   2360L,  2360L, "Xian80.GK3d-36",             "Xian_1980_3_Degree_GK_Zone_36",                                    0 },	// Xian 1980 / 3-degree Gauss-Kruger zone 36
	{   2361L,  2361L, "Xian80.GK3d-37",             "Xian_1980_3_Degree_GK_Zone_37",                                    0 },	// Xian 1980 / 3-degree Gauss-Kruger zone 37
	{   2362L,  2362L, "Xian80.GK3d-38",             "Xian_1980_3_Degree_GK_Zone_38",                                    0 },	// Xian 1980 / 3-degree Gauss-Kruger zone 38
	{   2363L,  2363L, "Xian80.GK3d-39",             "Xian_1980_3_Degree_GK_Zone_39",                                    0 },	// Xian 1980 / 3-degree Gauss-Kruger zone 39
	{   2364L,  2364L, "Xian80.GK3d-40",             "Xian_1980_3_Degree_GK_Zone_40",                                    0 },	// Xian 1980 / 3-degree Gauss-Kruger zone 40
	{   2365L,  2365L, "Xian80.GK3d-41",             "Xian_1980_3_Degree_GK_Zone_41",                                    0 },	// Xian 1980 / 3-degree Gauss-Kruger zone 41
	{   2366L,  2366L, "Xian80.GK3d-42",             "Xian_1980_3_Degree_GK_Zone_42",                                    0 },	// Xian 1980 / 3-degree Gauss-Kruger zone 42
	{   2367L,  2367L, "Xian80.GK3d-43",             "Xian_1980_3_Degree_GK_Zone_43",                                    0 },	// Xian 1980 / 3-degree Gauss-Kruger zone 43
	{   2368L,  2368L, "Xian80.GK3d-44",             "Xian_1980_3_Degree_GK_Zone_44",                                    0 },	// Xian 1980 / 3-degree Gauss-Kruger zone 44
	{   2369L,  2369L, "Xian80.GK3d-45",             "Xian_1980_3_Degree_GK_Zone_45",                                    0 },	// Xian 1980 / 3-degree Gauss-Kruger zone 45
	{   2370L,  2370L, "Xian80.GK3d/CM-75E",         "Xian_1980_3_Degree_GK_CM_75E",                                     0 },	// Xian 1980 / 3-degree Gauss-Kruger CM 75E
	{   2371L,  2371L, "Xian80.GK3d/CM-78E",         "Xian_1980_3_Degree_GK_CM_78E",                                     0 },	// Xian 1980 / 3-degree Gauss-Kruger CM 78E
	{   2372L,  2372L, "Xian80.GK3d/CM-81E",         "Xian_1980_3_Degree_GK_CM_81E",                                     0 },	// Xian 1980 / 3-degree Gauss-Kruger CM 81E
	{   2373L,  2373L, "Xian80.GK3d/CM-84E",         "Xian_1980_3_Degree_GK_CM_84E",                                     0 },	// Xian 1980 / 3-degree Gauss-Kruger CM 84E
	{   2374L,  2374L, "Xian80.GK3d/CM-87E",         "Xian_1980_3_Degree_GK_CM_87E",                                     0 },	// Xian 1980 / 3-degree Gauss-Kruger CM 87E
	{   2375L,  2375L, "Xian80.GK3d/CM-90E",         "Xian_1980_3_Degree_GK_CM_90E",                                     0 },	// Xian 1980 / 3-degree Gauss-Kruger CM 90E
	{   2376L,  2376L, "Xian80.GK3d/CM-93E",         "Xian_1980_3_Degree_GK_CM_93E",                                     0 },	// Xian 1980 / 3-degree Gauss-Kruger CM 93E
	{   2377L,  2377L, "Xian80.GK3d/CM-96E",         "Xian_1980_3_Degree_GK_CM_96E",                                     0 },	// Xian 1980 / 3-degree Gauss-Kruger CM 96E
	{   2378L,  2378L, "Xian80.GK3d/CM-99E",         "Xian_1980_3_Degree_GK_CM_99E",                                     0 },	// Xian 1980 / 3-degree Gauss-Kruger CM 99E
	{   2379L,  2379L, "Xian80.GK3d/CM-102E",        "Xian_1980_3_Degree_GK_CM_102E",                                    0 },	// Xian 1980 / 3-degree Gauss-Kruger CM 102E
	{   2380L,  2380L, "Xian80.GK3d/CM-105E",        "Xian_1980_3_Degree_GK_CM_105E",                                    0 },	// Xian 1980 / 3-degree Gauss-Kruger CM 105E
	{   2381L,  2381L, "Xian80.GK3d/CM-108E",        "Xian_1980_3_Degree_GK_CM_108E",                                    0 },	// Xian 1980 / 3-degree Gauss-Kruger CM 108E
	{   2382L,  2382L, "Xian80.GK3d/CM-111E",        "Xian_1980_3_Degree_GK_CM_111E",                                    0 },	// Xian 1980 / 3-degree Gauss-Kruger CM 111E
	{   2383L,  2383L, "Xian80.GK3d/CM-114E",        "Xian_1980_3_Degree_GK_CM_114E",                                    0 },	// Xian 1980 / 3-degree Gauss-Kruger CM 114E
	{   2384L,  2384L, "Xian80.GK3d/CM-117E",        "Xian_1980_3_Degree_GK_CM_117E",                                    0 },	// Xian 1980 / 3-degree Gauss-Kruger CM 117E
	{   2385L,  2385L, "Xian80.GK3d/CM-120E",        "Xian_1980_3_Degree_GK_CM_120E",                                    0 },	// Xian 1980 / 3-degree Gauss-Kruger CM 120E
	{   2386L,  2386L, "Xian80.GK3d/CM-123E",        "Xian_1980_3_Degree_GK_CM_123E",                                    0 },	// Xian 1980 / 3-degree Gauss-Kruger CM 123E
	{   2387L,  2387L, "Xian80.GK3d/CM-126E",        "Xian_1980_3_Degree_GK_CM_126E",                                    0 },	// Xian 1980 / 3-degree Gauss-Kruger CM 126E
	{   2388L,  2388L, "Xian80.GK3d/CM-129E",        "Xian_1980_3_Degree_GK_CM_129E",                                    0 },	// Xian 1980 / 3-degree Gauss-Kruger CM 129E
	{   2389L,  2389L, "Xian80.GK3d/CM-132E",        "Xian_1980_3_Degree_GK_CM_132E",                                    0 },	// Xian 1980 / 3-degree Gauss-Kruger CM 132E
	{   2390L,  2390L, "Xian80.GK3d/CM-135E",        "Xian_1980_3_Degree_GK_CM_135E",                                    0 },	// Xian 1980 / 3-degree Gauss-Kruger CM 135E
	{   2391L,  2391L, "KKJ.Finland-1",              "Finland_Zone_1",                                                   0 },	// KKJ / Finland zone 1
	{   2392L,  2392L, "KKJ.Finland-2",              "Finland_Zone_2",                                                   0 },	// KKJ / Finland zone 2
	{   2393L,  2393L, "KKJ.Finland-UCS",            "Finland_Zone_3",                                                   0 },	// KKJ / Finland Uniform Coordinate System
	{   2394L,  2394L, "KKJ.Finland-4",              "Finland_Zone_4",                                                   0 },	// KKJ / Finland zone 4
	{   3021L,  2400L, "RT90-2.5V",                  "RT90_25_gon_V",                                                    3 },	// RT90 2.5 gon W
	{   2401L,  2401L, "Beijing54.GK3d-25",          "Beijing_1954_3_Degree_GK_Zone_25",                                 0 },	// Beijing 1954 / 3-degree Gauss-Kruger zone 25
	{   2402L,  2402L, "Beijing54.GK3d-26",          "Beijing_1954_3_Degree_GK_Zone_26",                                 0 },	// Beijing 1954 / 3-degree Gauss-Kruger zone 26
	{   2403L,  2403L, "Beijing54.GK3d-27",          "Beijing_1954_3_Degree_GK_Zone_27",                                 0 },	// Beijing 1954 / 3-degree Gauss-Kruger zone 27
	{   2404L,  2404L, "Beijing54.GK3d-28",          "Beijing_1954_3_Degree_GK_Zone_28",                                 0 },	// Beijing 1954 / 3-degree Gauss-Kruger zone 28
	{   2405L,  2405L, "Beijing54.GK3d-29",          "Beijing_1954_3_Degree_GK_Zone_29",                                 0 },	// Beijing 1954 / 3-degree Gauss-Kruger zone 29
	{   2406L,  2406L, "Beijing54.GK3d-30",          "Beijing_1954_3_Degree_GK_Zone_30",                                 0 },	// Beijing 1954 / 3-degree Gauss-Kruger zone 30
	{   2407L,  2407L, "Beijing54.GK3d-31",          "Beijing_1954_3_Degree_GK_Zone_31",                                 0 },	// Beijing 1954 / 3-degree Gauss-Kruger zone 31
	{   2408L,  2408L, "Beijing54.GK3d-32",          "Beijing_1954_3_Degree_GK_Zone_32",                                 0 },	// Beijing 1954 / 3-degree Gauss-Kruger zone 32
	{   2409L,  2409L, "Beijing54.GK3d-33",          "Beijing_1954_3_Degree_GK_Zone_33",                                 0 },	// Beijing 1954 / 3-degree Gauss-Kruger zone 33
	{   2410L,  2410L, "Beijing54.GK3d-34",          "Beijing_1954_3_Degree_GK_Zone_34",                                 0 },	// Beijing 1954 / 3-degree Gauss-Kruger zone 34
	{   2411L,  2411L, "Beijing54.GK3d-35",          "Beijing_1954_3_Degree_GK_Zone_35",                                 0 },	// Beijing 1954 / 3-degree Gauss-Kruger zone 35
	{   2412L,  2412L, "Beijing54.GK3d-36",          "Beijing_1954_3_Degree_GK_Zone_36",                                 0 },	// Beijing 1954 / 3-degree Gauss-Kruger zone 36
	{   2413L,  2413L, "Beijing54.GK3d-37",          "Beijing_1954_3_Degree_GK_Zone_37",                                 0 },	// Beijing 1954 / 3-degree Gauss-Kruger zone 37
	{   2414L,  2414L, "Beijing54.GK3d-38",          "Beijing_1954_3_Degree_GK_Zone_38",                                 0 },	// Beijing 1954 / 3-degree Gauss-Kruger zone 38
	{   2415L,  2415L, "Beijing54.GK3d-39",          "Beijing_1954_3_Degree_GK_Zone_39",                                 0 },	// Beijing 1954 / 3-degree Gauss-Kruger zone 39
	{   2416L,  2416L, "Beijing54.GK3d-40",          "Beijing_1954_3_Degree_GK_Zone_40",                                 0 },	// Beijing 1954 / 3-degree Gauss-Kruger zone 40
	{   2417L,  2417L, "Beijing54.GK3d-41",          "Beijing_1954_3_Degree_GK_Zone_41",                                 0 },	// Beijing 1954 / 3-degree Gauss-Kruger zone 41
	{   2418L,  2418L, "Beijing54.GK3d-42",          "Beijing_1954_3_Degree_GK_Zone_42",                                 0 },	// Beijing 1954 / 3-degree Gauss-Kruger zone 42
	{   2419L,  2419L, "Beijing54.GK3d-43",          "Beijing_1954_3_Degree_GK_Zone_43",                                 0 },	// Beijing 1954 / 3-degree Gauss-Kruger zone 43
	{   2420L,  2420L, "Beijing54.GK3d-44",          "Beijing_1954_3_Degree_GK_Zone_44",                                 0 },	// Beijing 1954 / 3-degree Gauss-Kruger zone 44
	{   2421L,  2421L, "Beijing54.GK3d-45",          "Beijing_1954_3_Degree_GK_Zone_45",                                 0 },	// Beijing 1954 / 3-degree Gauss-Kruger zone 45
	{   2422L,  2422L, "Beijing54.GK3d/CM-75E",      "Beijing_1954_3_Degree_GK_CM_75E",                                  0 },	// Beijing 1954 / 3-degree Gauss-Kruger CM 75E
	{   2423L,  2423L, "Beijing54.GK3d/CM-78E",      "Beijing_1954_3_Degree_GK_CM_78E",                                  0 },	// Beijing 1954 / 3-degree Gauss-Kruger CM 78E
	{   2424L,  2424L, "Beijing54.GK3d/CM-81E",      "Beijing_1954_3_Degree_GK_CM_81E",                                  0 },	// Beijing 1954 / 3-degree Gauss-Kruger CM 81E
	{   2425L,  2425L, "Beijing54.GK3d/CM-84E",      "Beijing_1954_3_Degree_GK_CM_84E",                                  0 },	// Beijing 1954 / 3-degree Gauss-Kruger CM 84E
	{   2426L,  2426L, "Beijing54.GK3d/CM-87E",      "Beijing_1954_3_Degree_GK_CM_87E",                                  0 },	// Beijing 1954 / 3-degree Gauss-Kruger CM 87E
	{   2427L,  2427L, "Beijing54.GK3d/CM-90E",      "Beijing_1954_3_Degree_GK_CM_90E",                                  0 },	// Beijing 1954 / 3-degree Gauss-Kruger CM 90E
	{   2428L,  2428L, "Beijing54.GK3d/CM-93E",      "Beijing_1954_3_Degree_GK_CM_93E",                                  0 },	// Beijing 1954 / 3-degree Gauss-Kruger CM 93E
	{   2429L,  2429L, "Beijing54.GK3d/CM-96E",      "Beijing_1954_3_Degree_GK_CM_96E",                                  0 },	// Beijing 1954 / 3-degree Gauss-Kruger CM 96E
	{   2430L,  2430L, "Beijing54.GK3d/CM-99E",      "Beijing_1954_3_Degree_GK_CM_99E",                                  0 },	// Beijing 1954 / 3-degree Gauss-Kruger CM 99E
	{   2431L,  2431L, "Beijing54.GK3d/CM-102E",     "Beijing_1954_3_Degree_GK_CM_102E",                                 0 },	// Beijing 1954 / 3-degree Gauss-Kruger CM 102E
	{   2432L,  2432L, "Beijing54.GK3d/CM-105E",     "Beijing_1954_3_Degree_GK_CM_105E",                                 0 },	// Beijing 1954 / 3-degree Gauss-Kruger CM 105E
	{   2433L,  2433L, "Beijing54.GK3d/CM-108E",     "Beijing_1954_3_Degree_GK_CM_108E",                                 0 },	// Beijing 1954 / 3-degree Gauss-Kruger CM 108E
	{   2434L,  2434L, "Beijing54.GK3d/CM-111E",     "Beijing_1954_3_Degree_GK_CM_111E",                                 0 },	// Beijing 1954 / 3-degree Gauss-Kruger CM 111E
	{   2435L,  2435L, "Beijing54.GK3d/CM-114E",     "Beijing_1954_3_Degree_GK_CM_114E",                                 0 },	// Beijing 1954 / 3-degree Gauss-Kruger CM 114E
	{   2436L,  2436L, "Beijing54.GK3d/CM-117E",     "Beijing_1954_3_Degree_GK_CM_117E",                                 0 },	// Beijing 1954 / 3-degree Gauss-Kruger CM 117E
	{   2437L,  2437L, "Beijing54.GK3d/CM-120E",     "Beijing_1954_3_Degree_GK_CM_120E",                                 0 },	// Beijing 1954 / 3-degree Gauss-Kruger CM 120E
	{   2438L,  2438L, "Beijing54.GK3d/CM-123E",     "Beijing_1954_3_Degree_GK_CM_123E",                                 0 },	// Beijing 1954 / 3-degree Gauss-Kruger CM 123E
	{   2439L,  2439L, "Beijing54.GK3d/CM-126E",     "Beijing_1954_3_Degree_GK_CM_126E",                                 0 },	// Beijing 1954 / 3-degree Gauss-Kruger CM 126E
	{   2440L,  2440L, "Beijing54.GK3d/CM-129E",     "Beijing_1954_3_Degree_GK_CM_129E",                                 0 },	// Beijing 1954 / 3-degree Gauss-Kruger CM 129E
	{   2441L,  2441L, "Beijing54.GK3d/CM-132E",     "Beijing_1954_3_Degree_GK_CM_132E",                                 0 },	// Beijing 1954 / 3-degree Gauss-Kruger CM 132E
	{   2442L,  2442L, "Beijing54.GK3d/CM-135E",     "Beijing_1954_3_Degree_GK_CM_135E",                                 0 },	// Beijing 1954 / 3-degree Gauss-Kruger CM 135E
	{   2443L,  2443L, "JGD2K.CS-I",                 "JGD_2000_Japan_Zone_1",                                            0 },	// JGD2000 / Japan Plane Rectangular CS I
	{   2444L,  2444L, "JGD2K.CS-II",                "JGD_2000_Japan_Zone_2",                                            0 },	// JGD2000 / Japan Plane Rectangular CS II
	{   2445L,  2445L, "JGD2K.CS-III",               "JGD_2000_Japan_Zone_3",                                            0 },	// JGD2000 / Japan Plane Rectangular CS III
	{   2446L,  2446L, "JGD2K.CS-IV",                "JGD_2000_Japan_Zone_4",                                            0 },	// JGD2000 / Japan Plane Rectangular CS IV
	{   2447L,  2447L, "JGD2K.CS-V",                 "JGD_2000_Japan_Zone_5",                                            0 },	// JGD2000 / Japan Plane Rectangular CS V
	{   2448L,  2448L, "JGD2K.CS-VI",                "JGD_2000_Japan_Zone_6",                                            0 },	// JGD2000 / Japan Plane Rectangular CS VI
	{   2449L,  2449L, "JGD2K.CS-VII",               "JGD_2000_Japan_Zone_7",                                            0 },	// JGD2000 / Japan Plane Rectangular CS VII
	{   2450L,  2450L, "JGD2K.CS-VIII",              "JGD_2000_Japan_Zone_8",                                            0 },	// JGD2000 / Japan Plane Rectangular CS VIII
	{   2451L,  2451L, "JGD2K.CS-IX",                "JGD_2000_Japan_Zone_9",                                            0 },	// JGD2000 / Japan Plane Rectangular CS IX
	{   2452L,  2452L, "JGD2K.CS-X",                 "JGD_2000_Japan_Zone_10",                                           0 },	// JGD2000 / Japan Plane Rectangular CS X
	{   2453L,  2453L, "JGD2K.CS-XI",                "JGD_2000_Japan_Zone_11",                                           0 },	// JGD2000 / Japan Plane Rectangular CS XI
	{   2454L,  2454L, "JGD2K.CS-XII",               "JGD_2000_Japan_Zone_12",                                           0 },	// JGD2000 / Japan Plane Rectangular CS XII
	{   2455L,  2455L, "JGD2K.CS-XIII",              "JGD_2000_Japan_Zone_13",                                           0 },	// JGD2000 / Japan Plane Rectangular CS XIII
	{   2456L,  2456L, "JGD2K.CS-XIV",               "JGD_2000_Japan_Zone_14",                                           0 },	// JGD2000 / Japan Plane Rectangular CS XIV
	{   2457L,  2457L, "JGD2K.CS-XV",                "JGD_2000_Japan_Zone_15",                                           0 },	// JGD2000 / Japan Plane Rectangular CS XV
	{   2458L,  2458L, "JGD2K.CS-XVI",               "JGD_2000_Japan_Zone_16",                                           0 },	// JGD2000 / Japan Plane Rectangular CS XVI
	{   2459L,  2459L, "JGD2K.CS-XVII",              "JGD_2000_Japan_Zone_17",                                           0 },	// JGD2000 / Japan Plane Rectangular CS XVII
	{   2460L,  2460L, "JGD2K.CS-XVIII",             "JGD_2000_Japan_Zone_18",                                           0 },	// JGD2000 / Japan Plane Rectangular CS XVIII
	{   2461L,  2461L, "JGD2K.CS-XIX",               "JGD_2000_Japan_Zone_19",                                           0 },	// JGD2000 / Japan Plane Rectangular CS XIX
	{   2523L,  2523L, "Pulkovo42.GK3d-7",           "Pulkovo_1942_3_Degree_GK_Zone_7",                                  0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger zone 7
	{   2524L,  2524L, "Pulkovo42.GK3d-8",           "Pulkovo_1942_3_Degree_GK_Zone_8",                                  0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger zone 8
	{   2525L,  2525L, "Pulkovo42.GK3d-9",           "Pulkovo_1942_3_Degree_GK_Zone_9",                                  0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger zone 9
	{   2526L,  2526L, "Pulkovo42.GK3d-10",          "Pulkovo_1942_3_Degree_GK_Zone_10",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger zone 10
	{   2527L,  2527L, "Pulkovo42.GK3d-11",          "Pulkovo_1942_3_Degree_GK_Zone_11",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger zone 11
	{   2528L,  2528L, "Pulkovo42.GK3d-12",          "Pulkovo_1942_3_Degree_GK_Zone_12",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger zone 12
	{   2529L,  2529L, "Pulkovo42.GK3d-13",          "Pulkovo_1942_3_Degree_GK_Zone_13",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger zone 13
	{   2530L,  2530L, "Pulkovo42.GK3d-14",          "Pulkovo_1942_3_Degree_GK_Zone_14",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger zone 14
	{   2531L,  2531L, "Pulkovo42.GK3d-15",          "Pulkovo_1942_3_Degree_GK_Zone_15",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger zone 15
	{   2532L,  2532L, "Pulkovo42.GK3d-16",          "Pulkovo_1942_3_Degree_GK_Zone_16",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger zone 16
	{   2533L,  2533L, "Pulkovo42.GK3d-17",          "Pulkovo_1942_3_Degree_GK_Zone_17",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger zone 17
	{   2534L,  2534L, "Pulkovo42.GK3d-18",          "Pulkovo_1942_3_Degree_GK_Zone_18",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger zone 18
	{   2535L,  2535L, "Pulkovo42.GK3d-19",          "Pulkovo_1942_3_Degree_GK_Zone_19",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger zone 19
	{   2536L,  2536L, "Pulkovo42.GK3d-20",          "Pulkovo_1942_3_Degree_GK_Zone_20",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger zone 20
	{   2537L,  2537L, "Pulkovo42.GK3d-21",          "Pulkovo_1942_3_Degree_GK_Zone_21",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger zone 21
	{   2538L,  2538L, "Pulkovo42.GK3d-22",          "Pulkovo_1942_3_Degree_GK_Zone_22",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger zone 22
	{   2539L,  2539L, "Pulkovo42.GK3d-23",          "Pulkovo_1942_3_Degree_GK_Zone_23",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger zone 23
	{   2540L,  2540L, "Pulkovo42.GK3d-24",          "Pulkovo_1942_3_Degree_GK_Zone_24",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger zone 24
	{   2541L,  2541L, "Pulkovo42.GK3d-25",          "Pulkovo_1942_3_Degree_GK_Zone_25",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger zone 25
	{   2542L,  2542L, "Pulkovo42.GK3d-26",          "Pulkovo_1942_3_Degree_GK_Zone_26",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger zone 26
	{   2543L,  2543L, "Pulkovo42.GK3d-27",          "Pulkovo_1942_3_Degree_GK_Zone_27",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger zone 27
	{   2544L,  2544L, "Pulkovo42.GK3d-28",          "Pulkovo_1942_3_Degree_GK_Zone_28",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger zone 28
	{   2545L,  2545L, "Pulkovo42.GK3d-29",          "Pulkovo_1942_3_Degree_GK_Zone_29",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger zone 29
	{   2546L,  2546L, "Pulkovo42.GK3d-30",          "Pulkovo_1942_3_Degree_GK_Zone_30",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger zone 30
	{   2547L,  2547L, "Pulkovo42.GK3d-31",          "Pulkovo_1942_3_Degree_GK_Zone_31",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger zone 31
	{   2548L,  2548L, "Pulkovo42.GK3d-32",          "Pulkovo_1942_3_Degree_GK_Zone_32",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger zone 32
	{   2549L,  2549L, "Pulkovo42.GK3d-33",          "Pulkovo_1942_3_Degree_GK_Zone_33",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger zone 33
	{   2550L,  2550L, "Samboja.UTM-50S",            "Samboja_UTM_Zone_50S",                                             2 },	// Samboja / UTM zone 50S
	{   2551L,  2551L, "Pulkovo42.GK3d-34",          "Pulkovo_1942_3_Degree_GK_Zone_34",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger zone 34
	{   2552L,  2552L, "Pulkovo42.GK3d-35",          "Pulkovo_1942_3_Degree_GK_Zone_35",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger zone 35
	{   2553L,  2553L, "Pulkovo42.GK3d-36",          "Pulkovo_1942_3_Degree_GK_Zone_36",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger zone 36
	{   2554L,  2554L, "Pulkovo42.GK3d-37",          "Pulkovo_1942_3_Degree_GK_Zone_37",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger zone 37
	{   2555L,  2555L, "Pulkovo42.GK3d-38",          "Pulkovo_1942_3_Degree_GK_Zone_38",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger zone 38
	{   2556L,  2556L, "Pulkovo42.GK3d-39",          "Pulkovo_1942_3_Degree_GK_Zone_39",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger zone 39
	{   2557L,  2557L, "Pulkovo42.GK3d-40",          "Pulkovo_1942_3_Degree_GK_Zone_40",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger zone 40
	{   2558L,  2558L, "Pulkovo42.GK3d-41",          "Pulkovo_1942_3_Degree_GK_Zone_41",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger zone 41
	{   2559L,  2559L, "Pulkovo42.GK3d-42",          "Pulkovo_1942_3_Degree_GK_Zone_42",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger zone 42
	{   2560L,  2560L, "Pulkovo42.GK3d-43",          "Pulkovo_1942_3_Degree_GK_Zone_43",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger zone 43
	{   2561L,  2561L, "Pulkovo42.GK3d-44",          "Pulkovo_1942_3_Degree_GK_Zone_44",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger zone 44
	{   2562L,  2562L, "Pulkovo42.GK3d-45",          "Pulkovo_1942_3_Degree_GK_Zone_45",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger zone 45
	{   2563L,  2563L, "Pulkovo42.GK3d-46",          "Pulkovo_1942_3_Degree_GK_Zone_46",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger zone 46
	{   2564L,  2564L, "Pulkovo42.GK3d-47",          "Pulkovo_1942_3_Degree_GK_Zone_47",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger zone 47
	{   2565L,  2565L, "Pulkovo42.GK3d-48",          "Pulkovo_1942_3_Degree_GK_Zone_48",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger zone 48
	{   2566L,  2566L, "Pulkovo42.GK3d-49",          "Pulkovo_1942_3_Degree_GK_Zone_49",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger zone 49
	{   2567L,  2567L, "Pulkovo42.GK3d-50",          "Pulkovo_1942_3_Degree_GK_Zone_50",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger zone 50
	{   2568L,  2568L, "Pulkovo42.GK3d-51",          "Pulkovo_1942_3_Degree_GK_Zone_51",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger zone 51
	{   2569L,  2569L, "Pulkovo42.GK3d-52",          "Pulkovo_1942_3_Degree_GK_Zone_52",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger zone 52
	{   2570L,  2570L, "Pulkovo42.GK3d-53",          "Pulkovo_1942_3_Degree_GK_Zone_53",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger zone 53
	{   2571L,  2571L, "Pulkovo42.GK3d-54",          "Pulkovo_1942_3_Degree_GK_Zone_54",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger zone 54
	{   2572L,  2572L, "Pulkovo42.GK3d-55",          "Pulkovo_1942_3_Degree_GK_Zone_55",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger zone 55
	{   2573L,  2573L, "Pulkovo42.GK3d-56",          "Pulkovo_1942_3_Degree_GK_Zone_56",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger zone 56
	{   2574L,  2574L, "Pulkovo42.GK3d-57",          "Pulkovo_1942_3_Degree_GK_Zone_57",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger zone 57
	{   2575L,  2575L, "Pulkovo42.GK3d-58",          "Pulkovo_1942_3_Degree_GK_Zone_58",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger zone 58
	{   2576L,  2576L, "Pulkovo42.GK3d-59",          "Pulkovo_1942_3_Degree_GK_Zone_59",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger zone 59
	{   2577L,  2577L, "Pulkovo42.GK3d-60",          "Pulkovo_1942_3_Degree_GK_Zone_60",                                 2 },	// Pulkovo 1942 / 3-degree Gauss-Kruger zone 60
	{   2578L,  2578L, "Pulkovo42.GK3d-61",          "Pulkovo_1942_3_Degree_GK_Zone_61",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger zone 61
	{   2579L,  2579L, "Pulkovo42.GK3d-62",          "Pulkovo_1942_3_Degree_GK_Zone_62",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger zone 62
	{   2580L,  2580L, "Pulkovo42.GK3d-63",          "Pulkovo_1942_3_Degree_GK_Zone_63",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger zone 63
	{   2581L,  2581L, "Pulkovo42.GK3d-64",          "Pulkovo_1942_3_Degree_GK_Zone_64",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger zone 64
	{   2582L,  2582L, "Pulkovo42.GK3d/CM-21E",      "Pulkovo_1942_3_Degree_GK_CM_21E",                                  0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger CM 21E
	{   2583L,  2583L, "Pulkovo42.GK3d/CM-24E",      "Pulkovo_1942_3_Degree_GK_CM_24E",                                  0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger CM 24E
	{   2584L,  2584L, "Pulkovo42.GK3d/CM-27E",      "Pulkovo_1942_3_Degree_GK_CM_27E",                                  0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger CM 27E
	{   2585L,  2585L, "Pulkovo42.GK3d/CM-30E",      "Pulkovo_1942_3_Degree_GK_CM_30E",                                  0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger CM 30E
	{   2586L,  2586L, "Pulkovo42.GK3d/CM-33E",      "Pulkovo_1942_3_Degree_GK_CM_33E",                                  0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger CM 33E
	{   2587L,  2587L, "Pulkovo42.GK3d/CM-36E",      "Pulkovo_1942_3_Degree_GK_CM_36E",                                  0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger CM 36E
	{   2588L,  2588L, "Pulkovo42.GK3d/CM-39E",      "Pulkovo_1942_3_Degree_GK_CM_39E",                                  0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger CM 39E
	{   2589L,  2589L, "Pulkovo42.GK3d/CM-42E",      "Pulkovo_1942_3_Degree_GK_CM_42E",                                  0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger CM 42E
	{   2590L,  2590L, "Pulkovo42.GK3d/CM-45E",      "Pulkovo_1942_3_Degree_GK_CM_45E",                                  0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger CM 45E
	{   2591L,  2591L, "Pulkovo42.GK3d/CM-48E",      "Pulkovo_1942_3_Degree_GK_CM_48E",                                  0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger CM 48E
	{   2592L,  2592L, "Pulkovo42.GK3d/CM-51E",      "Pulkovo_1942_3_Degree_GK_CM_51E",                                  0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger CM 51E
	{   2593L,  2593L, "Pulkovo42.GK3d/CM-54E",      "Pulkovo_1942_3_Degree_GK_CM_54E",                                  0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger CM 54E
	{   2594L,  2594L, "Pulkovo42.GK3d/CM-57E",      "Pulkovo_1942_3_Degree_GK_CM_57E",                                  0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger CM 57E
	{   2595L,  2595L, "Pulkovo42.GK3d/CM-60E",      "Pulkovo_1942_3_Degree_GK_CM_60E",                                  0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger CM 60E
	{   2596L,  2596L, "Pulkovo42.GK3d/CM-63E",      "Pulkovo_1942_3_Degree_GK_CM_63E",                                  0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger CM 63E
	{   2597L,  2597L, "Pulkovo42.GK3d/CM-66E",      "Pulkovo_1942_3_Degree_GK_CM_66E",                                  0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger CM 66E
	{   2598L,  2598L, "Pulkovo42.GK3d/CM-69E",      "Pulkovo_1942_3_Degree_GK_CM_69E",                                  0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger CM 69E
	{   2599L,  2599L, "Pulkovo42.GK3d/CM-72E",      "Pulkovo_1942_3_Degree_GK_CM_72E",                                  0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger CM 72E
	{   2600L,  2600L, "Lietuvos1994",               "Lietuvos_Koordinaciu_Sistema",                                     2 },	// Lietuvos Koordinoei Sistema 1994
	{   2601L,  2601L, "Pulkovo42.GK3d/CM-75E",      "Pulkovo_1942_3_Degree_GK_CM_75E",                                  0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger CM 75E
	{   2602L,  2602L, "Pulkovo42.GK3d/CM-78E",      "Pulkovo_1942_3_Degree_GK_CM_78E",                                  0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger CM 78E
	{   2603L,  2603L, "Pulkovo42.GK3d/CM-81E",      "Pulkovo_1942_3_Degree_GK_CM_81E",                                  0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger CM 81E
	{   2604L,  2604L, "Pulkovo42.GK3d/CM-84E",      "Pulkovo_1942_3_Degree_GK_CM_84E",                                  0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger CM 84E
	{   2605L,  2605L, "Pulkovo42.GK3d/CM-87E",      "Pulkovo_1942_3_Degree_GK_CM_87E",                                  0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger CM 87E
	{   2606L,  2606L, "Pulkovo42.GK3d/CM-90E",      "Pulkovo_1942_3_Degree_GK_CM_90E",                                  0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger CM 90E
	{   2607L,  2607L, "Pulkovo42.GK3d/CM-93E",      "Pulkovo_1942_3_Degree_GK_CM_93E",                                  0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger CM 93E
	{   2608L,  2608L, "Pulkovo42.GK3d/CM-96E",      "Pulkovo_1942_3_Degree_GK_CM_96E",                                  0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger CM 96E
	{   2609L,  2609L, "Pulkovo42.GK3d/CM-99E",      "Pulkovo_1942_3_Degree_GK_CM_99E",                                  0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger CM 99E
	{   2610L,  2610L, "Pulkovo42.GK3d/CM-102E",     "Pulkovo_1942_3_Degree_GK_CM_102E",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger CM 102E
	{   2611L,  2611L, "Pulkovo42.GK3d/CM-105E",     "Pulkovo_1942_3_Degree_GK_CM_105E",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger CM 105E
	{   2612L,  2612L, "Pulkovo42.GK3d/CM-108E",     "Pulkovo_1942_3_Degree_GK_CM_108E",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger CM 108E
	{   2613L,  2613L, "Pulkovo42.GK3d/CM-111E",     "Pulkovo_1942_3_Degree_GK_CM_111E",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger CM 111E
	{   2614L,  2614L, "Pulkovo42.GK3d/CM-114E",     "Pulkovo_1942_3_Degree_GK_CM_114E",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger CM 114E
	{   2615L,  2615L, "Pulkovo42.GK3d/CM-117E",     "Pulkovo_1942_3_Degree_GK_CM_117E",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger CM 117E
	{   2616L,  2616L, "Pulkovo42.GK3d/CM-120E",     "Pulkovo_1942_3_Degree_GK_CM_120E",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger CM 120E
	{   2617L,  2617L, "Pulkovo42.GK3d/CM-123E",     "Pulkovo_1942_3_Degree_GK_CM_123E",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger CM 123E
	{   2618L,  2618L, "Pulkovo42.GK3d/CM-126E",     "Pulkovo_1942_3_Degree_GK_CM_126E",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger CM 126E
	{   2619L,  2619L, "Pulkovo42.GK3d/CM-129E",     "Pulkovo_1942_3_Degree_GK_CM_129E",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger CM 129E
	{   2620L,  2620L, "Pulkovo42.GK3d/CM-132E",     "Pulkovo_1942_3_Degree_GK_CM_132E",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger CM 132E
	{   2621L,  2621L, "Pulkovo42.GK3d/CM-135E",     "Pulkovo_1942_3_Degree_GK_CM_135E",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger CM 135E
	{   2622L,  2622L, "Pulkovo42.GK3d/CM-138E",     "Pulkovo_1942_3_Degree_GK_CM_138E",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger CM 138E
	{   2623L,  2623L, "Pulkovo42.GK3d/CM-141E",     "Pulkovo_1942_3_Degree_GK_CM_141E",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger CM 141E
	{   2624L,  2624L, "Pulkovo42.GK3d/CM-144E",     "Pulkovo_1942_3_Degree_GK_CM_144E",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger CM 144E
	{   2625L,  2625L, "Pulkovo42.GK3d/CM-147E",     "Pulkovo_1942_3_Degree_GK_CM_147E",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger CM 147E
	{   2626L,  2626L, "Pulkovo42.GK3d/CM-150E",     "Pulkovo_1942_3_Degree_GK_CM_150E",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger CM 150E
	{   2627L,  2627L, "Pulkovo42.GK3d/CM-153E",     "Pulkovo_1942_3_Degree_GK_CM_153E",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger CM 153E
	{   2628L,  2628L, "Pulkovo42.GK3d/CM-156E",     "Pulkovo_1942_3_Degree_GK_CM_156E",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger CM 156E
	{   2629L,  2629L, "Pulkovo42.GK3d/CM-159E",     "Pulkovo_1942_3_Degree_GK_CM_159E",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger CM 159E
	{   2630L,  2630L, "Pulkovo42.GK3d/CM-162E",     "Pulkovo_1942_3_Degree_GK_CM_162E",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger CM 162E
	{   2631L,  2631L, "Pulkovo42.GK3d/CM-165E",     "Pulkovo_1942_3_Degree_GK_CM_165E",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger CM 165E
	{   2632L,  2632L, "Pulkovo42.GK3d/CM-168E",     "Pulkovo_1942_3_Degree_GK_CM_168E",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger CM 168E
	{   2633L,  2633L, "Pulkovo42.GK3d/CM-171E",     "Pulkovo_1942_3_Degree_GK_CM_171E",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger CM 171E
	{   2634L,  2634L, "Pulkovo42.GK3d/CM-174E",     "Pulkovo_1942_3_Degree_GK_CM_174E",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger CM 174E
	{   2635L,  2635L, "Pulkovo42.GK3d/CM-177E",     "Pulkovo_1942_3_Degree_GK_CM_177E",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger CM 177E
	{   2636L,  2636L, "Pulkovo42.GK3d/CM-180E",     "Pulkovo_1942_3_Degree_GK_CM_180E",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger CM 180E
	{   2637L,  2637L, "Pulkovo42.GK3d/CM-177W",     "Pulkovo_1942_3_Degree_GK_CM_177W",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger CM 177W
	{   2638L,  2638L, "Pulkovo42.GK3d/CM-174W",     "Pulkovo_1942_3_Degree_GK_CM_174W",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger CM 174W
	{   2639L,  2639L, "Pulkovo42.GK3d/CM-171W",     "Pulkovo_1942_3_Degree_GK_CM_171W",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger CM 171W
	{   2640L,  2640L, "Pulkovo42.GK3d/CM-168W",     "Pulkovo_1942_3_Degree_GK_CM_168W",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger CM 168W
	{   2641L,  2641L, "Pulkovo95.GK3d-7",           "Pulkovo_1995_3_Degree_GK_Zone_7",                                  0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger zone 7
	{   2642L,  2642L, "Pulkovo95.GK3d-8",           "Pulkovo_1995_3_Degree_GK_Zone_8",                                  0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger zone 8
	{   2643L,  2643L, "Pulkovo95.GK3d-9",           "Pulkovo_1995_3_Degree_GK_Zone_9",                                  0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger zone 9
	{   2644L,  2644L, "Pulkovo95.GK3d-10",          "Pulkovo_1995_3_Degree_GK_Zone_10",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger zone 10
	{   2645L,  2645L, "Pulkovo95.GK3d-11",          "Pulkovo_1995_3_Degree_GK_Zone_11",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger zone 11
	{   2646L,  2646L, "Pulkovo95.GK3d-12",          "Pulkovo_1995_3_Degree_GK_Zone_12",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger zone 12
	{   2647L,  2647L, "Pulkovo95.GK3d-13",          "Pulkovo_1995_3_Degree_GK_Zone_13",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger zone 13
	{   2648L,  2648L, "Pulkovo95.GK3d-14",          "Pulkovo_1995_3_Degree_GK_Zone_14",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger zone 14
	{   2649L,  2649L, "Pulkovo95.GK3d-15",          "Pulkovo_1995_3_Degree_GK_Zone_15",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger zone 15
	{   2650L,  2650L, "Pulkovo95.GK3d-16",          "Pulkovo_1995_3_Degree_GK_Zone_16",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger zone 16
	{   2651L,  2651L, "Pulkovo95.GK3d-17",          "Pulkovo_1995_3_Degree_GK_Zone_17",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger zone 17
	{   2652L,  2652L, "Pulkovo95.GK3d-18",          "Pulkovo_1995_3_Degree_GK_Zone_18",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger zone 18
	{   2653L,  2653L, "Pulkovo95.GK3d-19",          "Pulkovo_1995_3_Degree_GK_Zone_19",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger zone 19
	{   2654L,  2654L, "Pulkovo95.GK3d-20",          "Pulkovo_1995_3_Degree_GK_Zone_20",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger zone 20
	{   2655L,  2655L, "Pulkovo95.GK3d-21",          "Pulkovo_1995_3_Degree_GK_Zone_21",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger zone 21
	{   2656L,  2656L, "Pulkovo95.GK3d-22",          "Pulkovo_1995_3_Degree_GK_Zone_22",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger zone 22
	{   2657L,  2657L, "Pulkovo95.GK3d-23",          "Pulkovo_1995_3_Degree_GK_Zone_23",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger zone 23
	{   2658L,  2658L, "Pulkovo95.GK3d-24",          "Pulkovo_1995_3_Degree_GK_Zone_24",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger zone 24
	{   2659L,  2659L, "Pulkovo95.GK3d-25",          "Pulkovo_1995_3_Degree_GK_Zone_25",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger zone 25
	{   2660L,  2660L, "Pulkovo95.GK3d-26",          "Pulkovo_1995_3_Degree_GK_Zone_26",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger zone 26
	{   2661L,  2661L, "Pulkovo95.GK3d-27",          "Pulkovo_1995_3_Degree_GK_Zone_27",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger zone 27
	{   2662L,  2662L, "Pulkovo95.GK3d-28",          "Pulkovo_1995_3_Degree_GK_Zone_28",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger zone 28
	{   2663L,  2663L, "Pulkovo95.GK3d-29",          "Pulkovo_1995_3_Degree_GK_Zone_29",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger zone 29
	{   2664L,  2664L, "Pulkovo95.GK3d-30",          "Pulkovo_1995_3_Degree_GK_Zone_30",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger zone 30
	{   2665L,  2665L, "Pulkovo95.GK3d-31",          "Pulkovo_1995_3_Degree_GK_Zone_31",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger zone 31
	{   2666L,  2666L, "Pulkovo95.GK3d-32",          "Pulkovo_1995_3_Degree_GK_Zone_32",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger zone 32
	{   2667L,  2667L, "Pulkovo95.GK3d-33",          "Pulkovo_1995_3_Degree_GK_Zone_33",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger zone 33
	{   2668L,  2668L, "Pulkovo95.GK3d-34",          "Pulkovo_1995_3_Degree_GK_Zone_34",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger zone 34
	{   2669L,  2669L, "Pulkovo95.GK3d-35",          "Pulkovo_1995_3_Degree_GK_Zone_35",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger zone 35
	{   2670L,  2670L, "Pulkovo95.GK3d-36",          "Pulkovo_1995_3_Degree_GK_Zone_36",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger zone 36
	{   2671L,  2671L, "Pulkovo95.GK3d-37",          "Pulkovo_1995_3_Degree_GK_Zone_37",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger zone 37
	{   2672L,  2672L, "Pulkovo95.GK3d-38",          "Pulkovo_1995_3_Degree_GK_Zone_38",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger zone 38
	{   2673L,  2673L, "Pulkovo95.GK3d-39",          "Pulkovo_1995_3_Degree_GK_Zone_39",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger zone 39
	{   2674L,  2674L, "Pulkovo95.GK3d-40",          "Pulkovo_1995_3_Degree_GK_Zone_40",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger zone 40
	{   2675L,  2675L, "Pulkovo95.GK3d-41",          "Pulkovo_1995_3_Degree_GK_Zone_41",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger zone 41
	{   2676L,  2676L, "Pulkovo95.GK3d-42",          "Pulkovo_1995_3_Degree_GK_Zone_42",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger zone 42
	{   2677L,  2677L, "Pulkovo95.GK3d-43",          "Pulkovo_1995_3_Degree_GK_Zone_43",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger zone 43
	{   2678L,  2678L, "Pulkovo95.GK3d-44",          "Pulkovo_1995_3_Degree_GK_Zone_44",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger zone 44
	{   2679L,  2679L, "Pulkovo95.GK3d-45",          "Pulkovo_1995_3_Degree_GK_Zone_45",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger zone 45
	{   2680L,  2680L, "Pulkovo95.GK3d-46",          "Pulkovo_1995_3_Degree_GK_Zone_46",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger zone 46
	{   2681L,  2681L, "Pulkovo95.GK3d-47",          "Pulkovo_1995_3_Degree_GK_Zone_47",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger zone 47
	{   2682L,  2682L, "Pulkovo95.GK3d-48",          "Pulkovo_1995_3_Degree_GK_Zone_48",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger zone 48
	{   2683L,  2683L, "Pulkovo95.GK3d-49",          "Pulkovo_1995_3_Degree_GK_Zone_49",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger zone 49
	{   2684L,  2684L, "Pulkovo95.GK3d-50",          "Pulkovo_1995_3_Degree_GK_Zone_50",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger zone 50
	{   2685L,  2685L, "Pulkovo95.GK3d-51",          "Pulkovo_1995_3_Degree_GK_Zone_51",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger zone 51
	{   2686L,  2686L, "Pulkovo95.GK3d-52",          "Pulkovo_1995_3_Degree_GK_Zone_52",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger zone 52
	{   2687L,  2687L, "Pulkovo95.GK3d-53",          "Pulkovo_1995_3_Degree_GK_Zone_53",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger zone 53
	{   2688L,  2688L, "Pulkovo95.GK3d-54",          "Pulkovo_1995_3_Degree_GK_Zone_54",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger zone 54
	{   2689L,  2689L, "Pulkovo95.GK3d-55",          "Pulkovo_1995_3_Degree_GK_Zone_55",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger zone 55
	{   2690L,  2690L, "Pulkovo95.GK3d-56",          "Pulkovo_1995_3_Degree_GK_Zone_56",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger zone 56
	{   2691L,  2691L, "Pulkovo95.GK3d-57",          "Pulkovo_1995_3_Degree_GK_Zone_57",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger zone 57
	{   2692L,  2692L, "Pulkovo95.GK3d-58",          "Pulkovo_1995_3_Degree_GK_Zone_58",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger zone 58
	{   2693L,  2693L, "Pulkovo95.GK3d-59",          "Pulkovo_1995_3_Degree_GK_Zone_59",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger zone 59
	{   2694L,  2694L, "Pulkovo95.GK3d-60",          "Pulkovo_1995_3_Degree_GK_Zone_60",                                 2 },	// Pulkovo 1995 / 3-degree Gauss-Kruger zone 60
	{   2695L,  2695L, "Pulkovo95.GK3d-61",          "Pulkovo_1995_3_Degree_GK_Zone_61",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger zone 61
	{   2696L,  2696L, "Pulkovo95.GK3d-62",          "Pulkovo_1995_3_Degree_GK_Zone_62",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger zone 62
	{   2697L,  2697L, "Pulkovo95.GK3d-63",          "Pulkovo_1995_3_Degree_GK_Zone_63",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger zone 63
	{   2698L,  2698L, "Pulkovo95.GK3d-64",          "Pulkovo_1995_3_Degree_GK_Zone_64",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger zone 64
	{   2699L,  2699L, "Pulkovo95.GK3d/CM-21E",      "Pulkovo_1995_3_Degree_GK_CM_21E",                                  0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger CM 21E
	{   2700L,  2700L, "Pulkovo95.GK3d/CM-24E",      "Pulkovo_1995_3_Degree_GK_CM_24E",                                  0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger CM 24E
	{   2701L,  2701L, "Pulkovo95.GK3d/CM-27E",      "Pulkovo_1995_3_Degree_GK_CM_27E",                                  0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger CM 27E
	{   2702L,  2702L, "Pulkovo95.GK3d/CM-30E",      "Pulkovo_1995_3_Degree_GK_CM_30E",                                  0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger CM 30E
	{   2703L,  2703L, "Pulkovo95.GK3d/CM-33E",      "Pulkovo_1995_3_Degree_GK_CM_33E",                                  0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger CM 33E
	{   2704L,  2704L, "Pulkovo95.GK3d/CM-36E",      "Pulkovo_1995_3_Degree_GK_CM_36E",                                  0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger CM 36E
	{   2705L,  2705L, "Pulkovo95.GK3d/CM-39E",      "Pulkovo_1995_3_Degree_GK_CM_39E",                                  0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger CM 39E
	{   2706L,  2706L, "Pulkovo95.GK3d/CM-42E",      "Pulkovo_1995_3_Degree_GK_CM_42E",                                  0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger CM 42E
	{   2707L,  2707L, "Pulkovo95.GK3d/CM-45E",      "Pulkovo_1995_3_Degree_GK_CM_45E",                                  0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger CM 45E
	{   2708L,  2708L, "Pulkovo95.GK3d/CM-48E",      "Pulkovo_1995_3_Degree_GK_CM_48E",                                  0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger CM 48E
	{   2709L,  2709L, "Pulkovo95.GK3d/CM-51E",      "Pulkovo_1995_3_Degree_GK_CM_51E",                                  0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger CM 51E
	{   2710L,  2710L, "Pulkovo95.GK3d/CM-54E",      "Pulkovo_1995_3_Degree_GK_CM_54E",                                  0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger CM 54E
	{   2711L,  2711L, "Pulkovo95.GK3d/CM-57E",      "Pulkovo_1995_3_Degree_GK_CM_57E",                                  0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger CM 57E
	{   2712L,  2712L, "Pulkovo95.GK3d/CM-60E",      "Pulkovo_1995_3_Degree_GK_CM_60E",                                  0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger CM 60E
	{   2713L,  2713L, "Pulkovo95.GK3d/CM-63E",      "Pulkovo_1995_3_Degree_GK_CM_63E",                                  0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger CM 63E
	{   2714L,  2714L, "Pulkovo95.GK3d/CM-66E",      "Pulkovo_1995_3_Degree_GK_CM_66E",                                  0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger CM 66E
	{   2715L,  2715L, "Pulkovo95.GK3d/CM-69E",      "Pulkovo_1995_3_Degree_GK_CM_69E",                                  0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger CM 69E
	{   2716L,  2716L, "Pulkovo95.GK3d/CM-72E",      "Pulkovo_1995_3_Degree_GK_CM_72E",                                  0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger CM 72E
	{   2717L,  2717L, "Pulkovo95.GK3d/CM-75E",      "Pulkovo_1995_3_Degree_GK_CM_75E",                                  0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger CM 75E
	{   2718L,  2718L, "Pulkovo95.GK3d/CM-78E",      "Pulkovo_1995_3_Degree_GK_CM_78E",                                  0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger CM 78E
	{   2719L,  2719L, "Pulkovo95.GK3d/CM-81E",      "Pulkovo_1995_3_Degree_GK_CM_81E",                                  0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger CM 81E
	{   2720L,  2720L, "Pulkovo95.GK3d/CM-84E",      "Pulkovo_1995_3_Degree_GK_CM_84E",                                  0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger CM 84E
	{   2721L,  2721L, "Pulkovo95.GK3d/CM-87E",      "Pulkovo_1995_3_Degree_GK_CM_87E",                                  0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger CM 87E
	{   2722L,  2722L, "Pulkovo95.GK3d/CM-90E",      "Pulkovo_1995_3_Degree_GK_CM_90E",                                  0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger CM 90E
	{   2723L,  2723L, "Pulkovo95.GK3d/CM-93E",      "Pulkovo_1995_3_Degree_GK_CM_93E",                                  0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger CM 93E
	{   2724L,  2724L, "Pulkovo95.GK3d/CM-96E",      "Pulkovo_1995_3_Degree_GK_CM_96E",                                  0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger CM 96E
	{   2725L,  2725L, "Pulkovo95.GK3d/CM-99E",      "Pulkovo_1995_3_Degree_GK_CM_99E",                                  0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger CM 99E
	{   2726L,  2726L, "Pulkovo95.GK3d/CM-102E",     "Pulkovo_1995_3_Degree_GK_CM_102E",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger CM 102E
	{   2727L,  2727L, "Pulkovo95.GK3d/CM-105E",     "Pulkovo_1995_3_Degree_GK_CM_105E",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger CM 105E
	{   2728L,  2728L, "Pulkovo95.GK3d/CM-108E",     "Pulkovo_1995_3_Degree_GK_CM_108E",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger CM 108E
	{   2729L,  2729L, "Pulkovo95.GK3d/CM-111E",     "Pulkovo_1995_3_Degree_GK_CM_111E",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger CM 111E
	{   2730L,  2730L, "Pulkovo95.GK3d/CM-114E",     "Pulkovo_1995_3_Degree_GK_CM_114E",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger CM 114E
	{   2731L,  2731L, "Pulkovo95.GK3d/CM-117E",     "Pulkovo_1995_3_Degree_GK_CM_117E",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger CM 117E
	{   2732L,  2732L, "Pulkovo95.GK3d/CM-120E",     "Pulkovo_1995_3_Degree_GK_CM_120E",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger CM 120E
	{   2733L,  2733L, "Pulkovo95.GK3d/CM-123E",     "Pulkovo_1995_3_Degree_GK_CM_123E",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger CM 123E
	{   2734L,  2734L, "Pulkovo95.GK3d/CM-126E",     "Pulkovo_1995_3_Degree_GK_CM_126E",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger CM 126E
	{   2735L,  2735L, "Pulkovo95.GK3d/CM-129E",     "Pulkovo_1995_3_Degree_GK_CM_129E",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger CM 129E
	{   2736L,  2736L, "Tete.UTM-36S",               "Tete_UTM_Zone_36S",                                                0 },	// Tete / UTM zone 36S
	{   2737L,  2737L, "Tete.UTM-37S",               "Tete_UTM_Zone_37S",                                                0 },	// Tete / UTM zone 37S
	{   2738L,  2738L, "Pulkovo95.GK3d/CM-132E",     "Pulkovo_1995_3_Degree_GK_CM_132E",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger CM 132E
	{   2739L,  2739L, "Pulkovo95.GK3d/CM-135E",     "Pulkovo_1995_3_Degree_GK_CM_135E",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger CM 135E
	{   2740L,  2740L, "Pulkovo95.GK3d/CM-138E",     "Pulkovo_1995_3_Degree_GK_CM_138E",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger CM 138E
	{   2741L,  2741L, "Pulkovo95.GK3d/CM-141E",     "Pulkovo_1995_3_Degree_GK_CM_141E",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger CM 141E
	{   2742L,  2742L, "Pulkovo95.GK3d/CM-144E",     "Pulkovo_1995_3_Degree_GK_CM_144E",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger CM 144E
	{   2743L,  2743L, "Pulkovo95.GK3d/CM-147E",     "Pulkovo_1995_3_Degree_GK_CM_147E",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger CM 147E
	{   2744L,  2744L, "Pulkovo95.GK3d/CM-150E",     "Pulkovo_1995_3_Degree_GK_CM_150E",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger CM 150E
	{   2745L,  2745L, "Pulkovo95.GK3d/CM-153E",     "Pulkovo_1995_3_Degree_GK_CM_153E",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger CM 153E
	{   2746L,  2746L, "Pulkovo95.GK3d/CM-156E",     "Pulkovo_1995_3_Degree_GK_CM_156E",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger CM 156E
	{   2747L,  2747L, "Pulkovo95.GK3d/CM-159E",     "Pulkovo_1995_3_Degree_GK_CM_159E",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger CM 159E
	{   2748L,  2748L, "Pulkovo95.GK3d/CM-162E",     "Pulkovo_1995_3_Degree_GK_CM_162E",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger CM 162E
	{   2749L,  2749L, "Pulkovo95.GK3d/CM-165E",     "Pulkovo_1995_3_Degree_GK_CM_165E",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger CM 165E
	{   2750L,  2750L, "Pulkovo95.GK3d/CM-168E",     "Pulkovo_1995_3_Degree_GK_CM_168E",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger CM 168E
	{   2751L,  2751L, "Pulkovo95.GK3d/CM-171E",     "Pulkovo_1995_3_Degree_GK_CM_171E",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger CM 171E
	{   2752L,  2752L, "Pulkovo95.GK3d/CM-174E",     "Pulkovo_1995_3_Degree_GK_CM_174E",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger CM 174E
	{   2753L,  2753L, "Pulkovo95.GK3d/CM-177E",     "Pulkovo_1995_3_Degree_GK_CM_177E",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger CM 177E
	{   2754L,  2754L, "Pulkovo95.GK3d/CM-180E",     "Pulkovo_1995_3_Degree_GK_CM_180E",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger CM 180E
	{   2755L,  2755L, "Pulkovo95.GK3d/CM-177W",     "Pulkovo_1995_3_Degree_GK_CM_177W",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger CM 177W
	{   2756L,  2756L, "Pulkovo95.GK3d/CM-174W",     "Pulkovo_1995_3_Degree_GK_CM_174W",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger CM 174W
	{   2757L,  2757L, "Pulkovo95.GK3d/CM-171W",     "Pulkovo_1995_3_Degree_GK_CM_171W",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger CM 171W
	{   2758L,  2758L, "Pulkovo95.GK3d/CM-168W",     "Pulkovo_1995_3_Degree_GK_CM_168W",                                 0 },	// Pulkovo 1995 / 3-degree Gauss-Kruger CM 168W
	{   2759L,  2759L, "ALHP-E",                     "NAD_1983_HARN_StatePlane_Alabama_East_FIPS_0101",                  1 },	// NAD83(HARN) / Alabama East
	{   2760L,  2760L, "ALHP-W",                     "NAD_1983_HARN_StatePlane_Alabama_West_FIPS_0102",                  1 },	// NAD83(HARN) / Alabama West
	{   2761L,  2761L, "AZHP-E",                     "NAD_1983_HARN_StatePlane_Arizona_East_FIPS_0201",                  1 },	// NAD83(HARN) / Arizona East
	{   2762L,  2762L, "AZHP-C",                     "NAD_1983_HARN_StatePlane_Arizona_Central_FIPS_0202",               1 },	// NAD83(HARN) / Arizona Central
	{   2763L,  2763L, "AZHP-W",                     "NAD_1983_HARN_StatePlane_Arizona_West_FIPS_0203",                  1 },	// NAD83(HARN) / Arizona West
	{   2764L,  2764L, "ARHP-N",                     "NAD_1983_HARN_StatePlane_Arkansas_North_FIPS_0301",                1 },	// NAD83(HARN) / Arkansas North
	{   2765L,  2765L, "ARHP-S",                     "NAD_1983_HARN_StatePlane_Arkansas_South_FIPS_0302",                1 },	// NAD83(HARN) / Arkansas South
	{   2766L,  2766L, "CAHP-I",                     "NAD_1983_HARN_StatePlane_California_I_FIPS_0401",                  1 },	// NAD83(HARN) / California zone 1
	{   2767L,  2767L, "CAHP-II",                    "NAD_1983_HARN_StatePlane_California_II_FIPS_0402",                 1 },	// NAD83(HARN) / California zone 2
	{   2768L,  2768L, "CAHP-III",                   "NAD_1983_HARN_StatePlane_California_III_FIPS_0403",                1 },	// NAD83(HARN) / California zone 3
	{   2769L,  2769L, "CAHP-IV",                    "NAD_1983_HARN_StatePlane_California_IV_FIPS_0404",                 1 },	// NAD83(HARN) / California zone 4
	{   2770L,  2770L, "CAHP-V",                     "NAD_1983_HARN_StatePlane_California_V_FIPS_0405",                  1 },	// NAD83(HARN) / California zone 5
	{   2771L,  2771L, "CAHP-VI",                    "NAD_1983_HARN_StatePlane_California_VI_FIPS_0406",                 1 },	// NAD83(HARN) / California zone 6
	{   2772L,  2772L, "COHP-N",                     "NAD_1983_HARN_StatePlane_Colorado_North_FIPS_0501",                1 },	// NAD83(HARN) / Colorado North
	{   2773L,  2773L, "COHP-C",                     "NAD_1983_HARN_StatePlane_Colorado_Central_FIPS_0502",              1 },	// NAD83(HARN) / Colorado Central
	{   2774L,  2774L, "COHP-S",                     "NAD_1983_HARN_StatePlane_Colorado_South_FIPS_0503",                1 },	// NAD83(HARN) / Colorado South
	{   2775L,  2775L, "CTHP",                       "NAD_1983_HARN_StatePlane_Connecticut_FIPS_0600",                   1 },	// NAD83(HARN) / Connecticut
	{   2776L,  2776L, "DEHP",                       "NAD_1983_HARN_StatePlane_Delaware_FIPS_0700",                      1 },	// NAD83(HARN) / Delaware
	{   2777L,  2777L, "FLHP-E",                     "NAD_1983_HARN_StatePlane_Florida_East_FIPS_0901",                  1 },	// NAD83(HARN) / Florida East
	{   2778L,  2778L, "FLHP-W",                     "NAD_1983_HARN_StatePlane_Florida_West_FIPS_0902",                  1 },	// NAD83(HARN) / Florida West
	{   2779L,  2779L, "FLHP-N",                     "NAD_1983_HARN_StatePlane_Florida_North_FIPS_0903",                 1 },	// NAD83(HARN) / Florida North
	{   2780L,  2780L, "GAHP-E",                     "NAD_1983_HARN_StatePlane_Georgia_East_FIPS_1001",                  1 },	// NAD83(HARN) / Georgia East
	{   2781L,  2781L, "GAHP-W",                     "NAD_1983_HARN_StatePlane_Georgia_West_FIPS_1002",                  1 },	// NAD83(HARN) / Georgia West
	{   2782L,  2782L, "HIHP-1",                     "NAD_1983_HARN_StatePlane_Hawaii_1_FIPS_5101",                      0 },	// NAD83(HARN) / Hawaii zone 1
	{   2783L,  2783L, "HIHP-2",                     "NAD_1983_HARN_StatePlane_Hawaii_2_FIPS_5102",                      0 },	// NAD83(HARN) / Hawaii zone 2
	{   2784L,  2784L, "HIHP-3",                     "NAD_1983_HARN_StatePlane_Hawaii_3_FIPS_5103",                      0 },	// NAD83(HARN) / Hawaii zone 3
	{   2785L,  2785L, "HIHP-4",                     "NAD_1983_HARN_StatePlane_Hawaii_4_FIPS_5104",                      0 },	// NAD83(HARN) / Hawaii zone 4
	{   2786L,  2786L, "HIHP-5",                     "NAD_1983_HARN_StatePlane_Hawaii_5_FIPS_5105",                      0 },	// NAD83(HARN) / Hawaii zone 5
	{   2787L,  2787L, "IDHP-E",                     "NAD_1983_HARN_StatePlane_Idaho_East_FIPS_1101",                    1 },	// NAD83(HARN) / Idaho East
	{   2788L,  2788L, "IDHP-C",                     "NAD_1983_HARN_StatePlane_Idaho_Central_FIPS_1102",                 1 },	// NAD83(HARN) / Idaho Central
	{   2789L,  2789L, "IDHP-W",                     "NAD_1983_HARN_StatePlane_Idaho_West_FIPS_1103",                    1 },	// NAD83(HARN) / Idaho West
	{   2790L,  2790L, "ILHP-E",                     "NAD_1983_HARN_StatePlane_Illinois_East_FIPS_1201",                 1 },	// NAD83(HARN) / Illinois East
	{   2791L,  2791L, "ILHP-W",                     "NAD_1983_HARN_StatePlane_Illinois_West_FIPS_1202",                 1 },	// NAD83(HARN) / Illinois West
	{   2792L,  2792L, "INHP-E",                     "NAD_1983_HARN_StatePlane_Indiana_East_FIPS_1301",                  1 },	// NAD83(HARN) / Indiana East
	{   2793L,  2793L, "INHP-W",                     "NAD_1983_HARN_StatePlane_Indiana_West_FIPS_1302",                  1 },	// NAD83(HARN) / Indiana West
	{   2794L,  2794L, "IAHP-N",                     "NAD_1983_HARN_StatePlane_Iowa_North_FIPS_1401",                    1 },	// NAD83(HARN) / Iowa North
	{   2795L,  2795L, "IAHP-S",                     "NAD_1983_HARN_StatePlane_Iowa_South_FIPS_1402",                    1 },	// NAD83(HARN) / Iowa South
	{   2796L,  2796L, "KSHP-N",                     "NAD_1983_HARN_StatePlane_Kansas_North_FIPS_1501",                  1 },	// NAD83(HARN) / Kansas North
	{   2797L,  2797L, "KSHP-S",                     "NAD_1983_HARN_StatePlane_Kansas_South_FIPS_1502",                  1 },	// NAD83(HARN) / Kansas South
	{   2798L,  2798L, "KYHP-N",                     "NAD_1983_HARN_StatePlane_Kentucky_North_FIPS_1601",                1 },	// NAD83(HARN) / Kentucky North
	{   2799L,  2799L, "KYHP-S",                     "NAD_1983_HARN_StatePlane_Kentucky_South_FIPS_1602",                1 },	// NAD83(HARN) / Kentucky South
	{   2800L,  2800L, "LAHP-N",                     "NAD_1983_HARN_StatePlane_Louisiana_North_FIPS_1701",               1 },	// NAD83(HARN) / Louisiana North
	{   2801L,  2801L, "LAHP-S",                     "NAD_1983_HARN_StatePlane_Louisiana_South_FIPS_1702",               1 },	// NAD83(HARN) / Louisiana South
	{   2802L,  2802L, "MEHP-E",                     "NAD_1983_HARN_StatePlane_Maine_East_FIPS_1801",                    1 },	// NAD83(HARN) / Maine East
	{   2803L,  2803L, "MEHP-W",                     "NAD_1983_HARN_StatePlane_Maine_West_FIPS_1802",                    1 },	// NAD83(HARN) / Maine West
	{   2804L,  2804L, "MDHP",                       "NAD_1983_HARN_StatePlane_Maryland_FIPS_1900",                      1 },	// NAD83(HARN) / Maryland
	{   2805L,  2805L, "MAHP",                       "NAD_1983_HARN_StatePlane_Massachusetts_Mainland_FIPS_2001",        1 },	// NAD83(HARN) / Massachusetts Mainland
	{   2806L,  2806L, "MAHP-IS",                    "NAD_1983_HARN_StatePlane_Massachusetts_Island_FIPS_2002",          1 },	// NAD83(HARN) / Massachusetts Island
	{   2807L,  2807L, "MIHP-N",                     "NAD_1983_HARN_StatePlane_Michigan_North_FIPS_2111",                1 },	// NAD83(HARN) / Michigan North
	{   2808L,  2808L, "MIHP-C",                     "NAD_1983_HARN_StatePlane_Michigan_Central_FIPS_2112",              1 },	// NAD83(HARN) / Michigan Central
	{   2809L,  2809L, "MIHP-S",                     "NAD_1983_HARN_StatePlane_Michigan_South_FIPS_2113",                1 },	// NAD83(HARN) / Michigan South
	{   2810L,  2810L, "MNHP-N",                     "NAD_1983_HARN_StatePlane_Minnesota_North_FIPS_2201",               1 },	// NAD83(HARN) / Minnesota North
	{   2811L,  2811L, "MNHP-C",                     "NAD_1983_HARN_StatePlane_Minnesota_Central_FIPS_2202",             1 },	// NAD83(HARN) / Minnesota Central
	{   2812L,  2812L, "MNHP-S",                     "NAD_1983_HARN_StatePlane_Minnesota_South_FIPS_2203",               1 },	// NAD83(HARN) / Minnesota South
	{   2813L,  2813L, "MSHP-E",                     "NAD_1983_HARN_StatePlane_Mississippi_East_FIPS_2301",              1 },	// NAD83(HARN) / Mississippi East
	{   2814L,  2814L, "MSHP-W",                     "NAD_1983_HARN_StatePlane_Mississippi_West_FIPS_2302",              1 },	// NAD83(HARN) / Mississippi West
	{   2815L,  2815L, "MOHP-E",                     "NAD_1983_HARN_StatePlane_Missouri_East_FIPS_2401",                 1 },	// NAD83(HARN) / Missouri East
	{   2816L,  2816L, "MOHP-C",                     "NAD_1983_HARN_StatePlane_Missouri_Central_FIPS_2402",              1 },	// NAD83(HARN) / Missouri Central
	{   2817L,  2817L, "MOHP-W",                     "NAD_1983_HARN_StatePlane_Missouri_West_FIPS_2403",                 1 },	// NAD83(HARN) / Missouri West
	{   2818L,  2818L, "MTHP",                       "NAD_1983_HARN_StatePlane_Montana_FIPS_2500",                       1 },	// NAD83(HARN) / Montana
	{   2819L,  2819L, "NBHP",                       "NAD_1983_HARN_StatePlane_Nebraska_FIPS_2600",                      1 },	// NAD83(HARN) / Nebraska
	{   2820L,  2820L, "NVHP-E",                     "NAD_1983_HARN_StatePlane_Nevada_East_FIPS_2701",                   1 },	// NAD83(HARN) / Nevada East
	{   2821L,  2821L, "NVHP-C",                     "NAD_1983_HARN_StatePlane_Nevada_Central_FIPS_2702",                1 },	// NAD83(HARN) / Nevada Central
	{   2822L,  2822L, "NVHP-W",                     "NAD_1983_HARN_StatePlane_Nevada_West_FIPS_2703",                   1 },	// NAD83(HARN) / Nevada West
	{   2823L,  2823L, "NHHP",                       "NAD_1983_HARN_StatePlane_New_Hampshire_FIPS_2800",                 1 },	// NAD83(HARN) / New Hampshire
	{   2824L,  2824L, "NJHP",                       "NAD_1983_HARN_StatePlane_New_Jersey_FIPS_2900",                    1 },	// NAD83(HARN) / New Jersey
	{   2825L,  2825L, "NMHP-E",                     "NAD_1983_HARN_StatePlane_New_Mexico_East_FIPS_3001",               1 },	// NAD83(HARN) / New Mexico East
	{   2826L,  2826L, "NMHP-C",                     "NAD_1983_HARN_StatePlane_New_Mexico_Central_FIPS_3002",            1 },	// NAD83(HARN) / New Mexico Central
	{   2827L,  2827L, "NMHP-W",                     "NAD_1983_HARN_StatePlane_New_Mexico_West_FIPS_3003",               1 },	// NAD83(HARN) / New Mexico West
	{   2828L,  2828L, "NYHP-E",                     "NAD_1983_HARN_StatePlane_New_York_East_FIPS_3101",                 1 },	// NAD83(HARN) / New York East
	{   2829L,  2829L, "NYHP-C",                     "NAD_1983_HARN_StatePlane_New_York_Central_FIPS_3102",              1 },	// NAD83(HARN) / New York Central
	{   2830L,  2830L, "NYHP-W",                     "NAD_1983_HARN_StatePlane_New_York_West_FIPS_3103",                 1 },	// NAD83(HARN) / New York West
	{   2831L,  2831L, "NYHP-LI",                    "NAD_1983_HARN_StatePlane_New_York_Long_Island_FIPS_3104",          1 },	// NAD83(HARN) / New York Long Island
	{   2832L,  2832L, "NDHP-N",                     "NAD_1983_HARN_StatePlane_North_Dakota_North_FIPS_3301",            1 },	// NAD83(HARN) / North Dakota North
	{   2833L,  2833L, "NDHP-S",                     "NAD_1983_HARN_StatePlane_North_Dakota_South_FIPS_3302",            1 },	// NAD83(HARN) / North Dakota South
	{   2834L,  2834L, "OHHP-N",                     "NAD_1983_HARN_StatePlane_Ohio_North_FIPS_3401",                    1 },	// NAD83(HARN) / Ohio North
	{   2835L,  2835L, "OHHP-S",                     "NAD_1983_HARN_StatePlane_Ohio_South_FIPS_3402",                    1 },	// NAD83(HARN) / Ohio South
	{   2836L,  2836L, "OKHP-N",                     "NAD_1983_HARN_StatePlane_Oklahoma_North_FIPS_3501",                1 },	// NAD83(HARN) / Oklahoma North
	{   2837L,  2837L, "OKHP-S",                     "NAD_1983_HARN_StatePlane_Oklahoma_South_FIPS_3502",                1 },	// NAD83(HARN) / Oklahoma South
	{   2838L,  2838L, "ORHP-N",                     "NAD_1983_HARN_StatePlane_Oregon_North_FIPS_3601",                  1 },	// NAD83(HARN) / Oregon North
	{   2839L,  2839L, "ORHP-S",                     "NAD_1983_HARN_StatePlane_Oregon_South_FIPS_3602",                  1 },	// NAD83(HARN) / Oregon South
	{   2840L,  2840L, "RIHP",                       "NAD_1983_HARN_StatePlane_Rhode_Island_FIPS_3800",                  1 },	// NAD83(HARN) / Rhode Island
	{   2841L,  2841L, "SDHP-N",                     "NAD_1983_HARN_StatePlane_South_Dakota_North_FIPS_4001",            1 },	// NAD83(HARN) / South Dakota North
	{   2842L,  2842L, "SDHP-S",                     "NAD_1983_HARN_StatePlane_South_Dakota_South_FIPS_4002",            1 },	// NAD83(HARN) / South Dakota South
	{   2843L,  2843L, "TNHP",                       "NAD_1983_HARN_StatePlane_Tennessee_FIPS_4100",                     1 },	// NAD83(HARN) / Tennessee
	{   2844L,  2844L, "TXHP-N",                     "NAD_1983_HARN_StatePlane_Texas_North_FIPS_4201",                   1 },	// NAD83(HARN) / Texas North
	{   2845L,  2845L, "TXHP-NC",                    "NAD_1983_HARN_StatePlane_Texas_North_Central_FIPS_4202",           1 },	// NAD83(HARN) / Texas North Central
	{   2846L,  2846L, "TXHP-C",                     "NAD_1983_HARN_StatePlane_Texas_Central_FIPS_4203",                 1 },	// NAD83(HARN) / Texas Central
	{   2847L,  2847L, "TXHP-SC",                    "NAD_1983_HARN_StatePlane_Texas_South_Central_FIPS_4204",           1 },	// NAD83(HARN) / Texas South Central
	{   2848L,  2848L, "TXHP-S",                     "NAD_1983_HARN_StatePlane_Texas_South_FIPS_4205",                   1 },	// NAD83(HARN) / Texas South
	{   2849L,  2849L, "UTHP-N",                     "NAD_1983_HARN_StatePlane_Utah_North_FIPS_4301",                    1 },	// NAD83(HARN) / Utah North
	{   2850L,  2850L, "UTHP-C",                     "NAD_1983_HARN_StatePlane_Utah_Central_FIPS_4302",                  1 },	// NAD83(HARN) / Utah Central
	{   2851L,  2851L, "UTHP-S",                     "NAD_1983_HARN_StatePlane_Utah_South_FIPS_4303",                    1 },	// NAD83(HARN) / Utah South
	{   2852L,  2852L, "VTHP",                       "NAD_1983_HARN_StatePlane_Vermont_FIPS_4400",                       1 },	// NAD83(HARN) / Vermont
	{   2853L,  2853L, "VAHP-N",                     "NAD_1983_HARN_StatePlane_Virginia_North_FIPS_4501",                1 },	// NAD83(HARN) / Virginia North
	{   2854L,  2854L, "VAHP-S",                     "NAD_1983_HARN_StatePlane_Virginia_South_FIPS_4502",                1 },	// NAD83(HARN) / Virginia South
	{   2855L,  2855L, "WAHP-N",                     "NAD_1983_HARN_StatePlane_Washington_North_FIPS_4601",              1 },	// NAD83(HARN) / Washington North
	{   2856L,  2856L, "WAHP-S",                     "NAD_1983_HARN_StatePlane_Washington_South_FIPS_4602",              1 },	// NAD83(HARN) / Washington South
	{   2857L,  2857L, "WVHP-N",                     "NAD_1983_HARN_StatePlane_West_Virginia_North_FIPS_4701",           1 },	// NAD83(HARN) / West Virginia North
	{   2858L,  2858L, "WVHP-S",                     "NAD_1983_HARN_StatePlane_West_Virginia_South_FIPS_4702",           1 },	// NAD83(HARN) / West Virginia South
	{   2859L,  2859L, "WIHP-N",                     "NAD_1983_HARN_StatePlane_Wisconsin_North_FIPS_4801",               1 },	// NAD83(HARN) / Wisconsin North
	{   2860L,  2860L, "WIHP-C",                     "NAD_1983_HARN_StatePlane_Wisconsin_Central_FIPS_4802",             1 },	// NAD83(HARN) / Wisconsin Central
	{   2861L,  2861L, "WIHP-S",                     "NAD_1983_HARN_StatePlane_Wisconsin_South_FIPS_4803",               1 },	// NAD83(HARN) / Wisconsin South
	{   2862L,  2862L, "WYHP-E",                     "NAD_1983_HARN_StatePlane_Wyoming_East_FIPS_4901",                  1 },	// NAD83(HARN) / Wyoming East
	{   2863L,  2863L, "WYHP-EC",                    "NAD_1983_HARN_StatePlane_Wyoming_East_Central_FIPS_4902",          1 },	// NAD83(HARN) / Wyoming East Central
	{   2864L,  2864L, "WYHP-WC",                    "NAD_1983_HARN_StatePlane_Wyoming_West_Central_FIPS_4903",          1 },	// NAD83(HARN) / Wyoming West Central
	{   2865L,  2865L, "WYHP-W",                     "NAD_1983_HARN_StatePlane_Wyoming_West_FIPS_4904",                  1 },	// NAD83(HARN) / Wyoming West
	{   2866L,  2866L, "PRHP",                       "NAD_1983_HARN_StatePlane_Puerto_Rico_Virgin_Islands_FIPS_5200",    1 },	// NAD83(HARN) / Puerto Rico & Virgin Is.
	{   2867L,  2867L, "AZHP-EIF",                   "NAD_1983_HARN_StatePlane_Arizona_East_FIPS_0201_Feet_Intl",        1 },	// NAD83(HARN) / Arizona East (ft)
	{   2868L,  2868L, "AZHP-CIF",                   "NAD_1983_HARN_StatePlane_Arizona_Central_FIPS_0202_Feet_Intl",     1 },	// NAD83(HARN) / Arizona Central (ft)
	{   2869L,  2869L, "AZHP-WIF",                   "NAD_1983_HARN_StatePlane_Arizona_West_FIPS_0203_Feet_Intl",        1 },	// NAD83(HARN) / Arizona West (ft)
	{   2870L,  2870L, "CAHP-IF",                    "NAD_1983_HARN_StatePlane_California_I_FIPS_0401_Feet",             1 },	// NAD83(HARN) / California zone 1 (ftUS)
	{   2871L,  2871L, "CAHP-IIF",                   "NAD_1983_HARN_StatePlane_California_II_FIPS_0402_Feet",            1 },	// NAD83(HARN) / California zone 2 (ftUS)
	{   2872L,  2872L, "CAHPIIIF",                   "NAD_1983_HARN_StatePlane_California_III_FIPS_0403_Feet",           1 },	// NAD83(HARN) / California zone 3 (ftUS)
	{   2873L,  2873L, "CAHP-IVF",                   "NAD_1983_HARN_StatePlane_California_IV_FIPS_0404_Feet",            1 },	// NAD83(HARN) / California zone 4 (ftUS)
	{   2874L,  2874L, "CAHP-VF",                    "NAD_1983_HARN_StatePlane_California_V_FIPS_0405_Feet",             1 },	// NAD83(HARN) / California zone 5 (ftUS)
	{   2875L,  2875L, "CAHP-VIF",                   "NAD_1983_HARN_StatePlane_California_VI_FIPS_0406_Feet",            1 },	// NAD83(HARN) / California zone 6 (ftUS)
	{   2876L,  2876L, "COHP-NF",                    "NAD_1983_HARN_StatePlane_Colorado_North_FIPS_0501_Feet",           1 },	// NAD83(HARN) / Colorado North (ftUS)
	{   2877L,  2877L, "COHP-CF",                    "NAD_1983_HARN_StatePlane_Colorado_Central_FIPS_0502_Feet",         1 },	// NAD83(HARN) / Colorado Central (ftUS)
	{   2878L,  2878L, "COHP-SF",                    "NAD_1983_HARN_StatePlane_Colorado_South_FIPS_0503_Feet",           1 },	// NAD83(HARN) / Colorado South (ftUS)
	{   2879L,  2879L, "CTHPF",                      "NAD_1983_HARN_StatePlane_Connecticut_FIPS_0600_Feet",              1 },	// NAD83(HARN) / Connecticut (ftUS)
	{   2880L,  2880L, "DEHPF",                      "NAD_1983_HARN_StatePlane_Delaware_FIPS_0700_Feet",                 1 },	// NAD83(HARN) / Delaware (ftUS)
	{   2881L,  2881L, "FLHP-EF",                    "NAD_1983_HARN_StatePlane_Florida_East_FIPS_0901_Feet",             1 },	// NAD83(HARN) / Florida East (ftUS)
	{   2882L,  2882L, "FLHP-WF",                    "NAD_1983_HARN_StatePlane_Florida_West_FIPS_0902_Feet",             1 },	// NAD83(HARN) / Florida West (ftUS)
	{   2883L,  2883L, "FLHP-NF",                    "NAD_1983_HARN_StatePlane_Florida_North_FIPS_0903_Feet",            1 },	// NAD83(HARN) / Florida North (ftUS)
	{   2884L,  2884L, "GAHP-EF",                    "NAD_1983_HARN_StatePlane_Georgia_East_FIPS_1001_Feet",             1 },	// NAD83(HARN) / Georgia East (ftUS)
	{   2885L,  2885L, "GAHP-WF",                    "NAD_1983_HARN_StatePlane_Georgia_West_FIPS_1002_Feet",             1 },	// NAD83(HARN) / Georgia West (ftUS)
	{   2886L,  2886L, "IDHP-EF",                    "NAD_1983_HARN_StatePlane_Idaho_East_FIPS_1101_Feet",               1 },	// NAD83(HARN) / Idaho East (ftUS)
	{   2887L,  2887L, "IDHP-CF",                    "NAD_1983_HARN_StatePlane_Idaho_Central_FIPS_1102_Feet",            1 },	// NAD83(HARN) / Idaho Central (ftUS)
	{   2888L,  2888L, "IDHP-WF",                    "NAD_1983_HARN_StatePlane_Idaho_West_FIPS_1103_Feet",               1 },	// NAD83(HARN) / Idaho West (ftUS)
	{   2967L,  2889L, "INHP-EF",                    "NAD_1983_HARN_StatePlane_Indiana_East_FIPS_1301_Feet",             3 },	// NAD83(HARN) / Indiana East (ftUS)
	{   2968L,  2890L, "INHP-WF",                    "NAD_1983_HARN_StatePlane_Indiana_West_FIPS_1302_Feet",             3 },	// NAD83(HARN) / Indiana West (ftUS)
	{   2891L,  2891L, "KYHP-NF",                    "NAD_1983_HARN_StatePlane_Kentucky_North_FIPS_1601_Feet",           1 },	// NAD83(HARN) / Kentucky North (ftUS)
	{   2892L,  2892L, "KYHP-SF",                    "NAD_1983_HARN_StatePlane_Kentucky_South_FIPS_1602_Feet",           1 },	// NAD83(HARN) / Kentucky South (ftUS)
	{   2893L,  2893L, "MDHPF",                      "NAD_1983_HARN_StatePlane_Maryland_FIPS_1900_Feet",                 1 },	// NAD83(HARN) / Maryland (ftUS)
	{   2894L,  2894L, "MAHPF",                      "NAD_1983_HARN_StatePlane_Massachusetts_Mainland_FIPS_2001_Feet",   1 },	// NAD83(HARN) / Massachusetts Mainland (ftUS)
	{   2895L,  2895L, "MAHP-ISF",                   "NAD_1983_HARN_StatePlane_Massachusetts_Island_FIPS_2002_Feet",     1 },	// NAD83(HARN) / Massachusetts Island (ftUS)
	{   2896L,  2896L, "MIHP-NIF",                   "NAD_1983_HARN_StatePlane_Michigan_North_FIPS_2111_Feet_Intl",      1 },	// NAD83(HARN) / Michigan North (ft)
	{   2897L,  2897L, "MIHP-CIF",                   "NAD_1983_HARN_StatePlane_Michigan_Central_FIPS_2112_Feet_Intl",    1 },	// NAD83(HARN) / Michigan Central (ft)
	{   2898L,  2898L, "MIHP-SIF",                   "NAD_1983_HARN_StatePlane_Michigan_South_FIPS_2113_Feet_Intl",      1 },	// NAD83(HARN) / Michigan South (ft)
	{   2899L,  2899L, "MSHP-EF",                    "NAD_1983_HARN_StatePlane_Mississippi_East_FIPS_2301_Feet",         1 },	// NAD83(HARN) / Mississippi East (ftUS)
	{   2900L,  2900L, "MSHP-WF",                    "NAD_1983_HARN_StatePlane_Mississippi_West_FIPS_2302_Feet",         1 },	// NAD83(HARN) / Mississippi West (ftUS)
	{   2901L,  2901L, "MTHPIF",                     "NAD_1983_HARN_StatePlane_Montana_FIPS_2500_Feet_Intl",             1 },	// NAD83(HARN) / Montana (ft)
	{   2902L,  2902L, "NMHP-EF",                    "NAD_1983_HARN_StatePlane_New_Mexico_East_FIPS_3001_Feet",          1 },	// NAD83(HARN) / New Mexico East (ftUS)
	{   2903L,  2903L, "NMHP-CF",                    "NAD_1983_HARN_StatePlane_New_Mexico_Central_FIPS_3002_Feet",       1 },	// NAD83(HARN) / New Mexico Central (ftUS)
	{   2904L,  2904L, "NMHP-WF",                    "NAD_1983_HARN_StatePlane_New_Mexico_West_FIPS_3003_Feet",          1 },	// NAD83(HARN) / New Mexico West (ftUS)
	{   2905L,  2905L, "NYHP-EF",                    "NAD_1983_HARN_StatePlane_New_York_East_FIPS_3101_Feet",            1 },	// NAD83(HARN) / New York East (ftUS)
	{   2906L,  2906L, "NYHP-CF",                    "NAD_1983_HARN_StatePlane_New_York_Central_FIPS_3102_Feet",         1 },	// NAD83(HARN) / New York Central (ftUS)
	{   2907L,  2907L, "NYHP-WF",                    "NAD_1983_HARN_StatePlane_New_York_West_FIPS_3103_Feet",            1 },	// NAD83(HARN) / New York West (ftUS)
	{   2908L,  2908L, "NYHP-LIF",                   "NAD_1983_HARN_StatePlane_New_York_Long_Island_FIPS_3104_Feet",     1 },	// NAD83(HARN) / New York Long Island (ftUS)
	{   2909L,  2909L, "NDHP-NIF",                   "NAD_1983_HARN_StatePlane_North_Dakota_North_FIPS_3301_Feet_Intl",  0 },	// NAD83(HARN) / North Dakota North (ft)
	{   2910L,  2910L, "NDHP-SIF",                   "NAD_1983_HARN_StatePlane_North_Dakota_South_FIPS_3302_Feet_Intl",  0 },	// NAD83(HARN) / North Dakota South (ft)
	{   2911L,  2911L, "OKHP-NF",                    "NAD_1983_HARN_StatePlane_Oklahoma_North_FIPS_3501_Feet",           1 },	// NAD83(HARN) / Oklahoma North (ftUS)
	{   2912L,  2912L, "OKHP-SF",                    "NAD_1983_HARN_StatePlane_Oklahoma_South_FIPS_3502_Feet",           1 },	// NAD83(HARN) / Oklahoma South (ftUS)
	{   2913L,  2913L, "ORHP-NIF",                   "NAD_1983_HARN_StatePlane_Oregon_North_FIPS_3601_Feet_Intl",        1 },	// NAD83(HARN) / Oregon North (ft)
	{   2914L,  2914L, "ORHP-SIF",                   "NAD_1983_HARN_StatePlane_Oregon_South_FIPS_3602_Feet_Intl",        1 },	// NAD83(HARN) / Oregon South (ft)
	{   2915L,  2915L, "TNHPF",                      "NAD_1983_HARN_StatePlane_Tennessee_FIPS_4100_Feet",                1 },	// NAD83(HARN) / Tennessee (ftUS)
	{   2916L,  2916L, "TXHP-NF",                    "NAD_1983_HARN_StatePlane_Texas_North_FIPS_4201_Feet",              1 },	// NAD83(HARN) / Texas North (ftUS)
	{   2917L,  2917L, "TXHP-NCF",                   "NAD_1983_HARN_StatePlane_Texas_North_Central_FIPS_4202_Feet",      1 },	// NAD83(HARN) / Texas North Central (ftUS)
	{   2918L,  2918L, "TXHP-CF",                    "NAD_1983_HARN_StatePlane_Texas_Central_FIPS_4203_Feet",            1 },	// NAD83(HARN) / Texas Central (ftUS)
	{   2919L,  2919L, "TXHP-SCF",                   "NAD_1983_HARN_StatePlane_Texas_South_Central_FIPS_4204_Feet",      1 },	// NAD83(HARN) / Texas South Central (ftUS)
	{   2920L,  2920L, "TXHP-SF",                    "NAD_1983_HARN_StatePlane_Texas_South_FIPS_4205_Feet",              1 },	// NAD83(HARN) / Texas South (ftUS)
	{   2921L,  2921L, "UTHP-NIF",                   "NAD_1983_HARN_StatePlane_Utah_North_FIPS_4301_Feet_Intl",          1 },	// NAD83(HARN) / Utah North (ft)
	{   2922L,  2922L, "UTHP-CIF",                   "NAD_1983_HARN_StatePlane_Utah_Central_FIPS_4302_Feet_Intl",        1 },	// NAD83(HARN) / Utah Central (ft)
	{   2923L,  2923L, "UTHP-SIF",                   "NAD_1983_HARN_StatePlane_Utah_South_FIPS_4303_Feet_Intl",          1 },	// NAD83(HARN) / Utah South (ft)
	{   2924L,  2924L, "VAHP-NF",                    "NAD_1983_HARN_StatePlane_Virginia_North_FIPS_4501_Feet",           1 },	// NAD83(HARN) / Virginia North (ftUS)
	{   2925L,  2925L, "VAHP-SF",                    "NAD_1983_HARN_StatePlane_Virginia_South_FIPS_4502_Feet",           1 },	// NAD83(HARN) / Virginia South (ftUS)
	{   2926L,  2926L, "WAHP-NF",                    "NAD_1983_HARN_StatePlane_Washington_North_FIPS_4601_Feet",         1 },	// NAD83(HARN) / Washington North (ftUS)
	{   2927L,  2927L, "WAHP-SF",                    "NAD_1983_HARN_StatePlane_Washington_South_FIPS_4602_Feet",         1 },	// NAD83(HARN) / Washington South (ftUS)
	{   2928L,  2928L, "WIHP-NF",                    "NAD_1983_HARN_StatePlane_Wisconsin_North_FIPS_4801_Feet",          1 },	// NAD83(HARN) / Wisconsin North (ftUS)
	{   2929L,  2929L, "WIHP-CF",                    "NAD_1983_HARN_StatePlane_Wisconsin_Central_FIPS_4802_Feet",        1 },	// NAD83(HARN) / Wisconsin Central (ftUS)
	{   2930L,  2930L, "WIHP-SF",                    "NAD_1983_HARN_StatePlane_Wisconsin_South_FIPS_4803_Feet",          1 },	// NAD83(HARN) / Wisconsin South (ftUS)
	{   2935L,  2935L, "Pulkovo42.CS63-A1",          "Pulkovo_1942_CS63_Zone_A1",                                        0 },	// Pulkovo 1942 / CS63 zone A1
	{   2936L,  2936L, "Pulkovo42.CS63-A2",          "Pulkovo_1942_CS63_Zone_A2",                                        0 },	// Pulkovo 1942 / CS63 zone A2
	{   2937L,  2937L, "Pulkovo42.CS63-A3",          "Pulkovo_1942_CS63_Zone_A3",                                        0 },	// Pulkovo 1942 / CS63 zone A3
	{   2938L,  2938L, "Pulkovo42.CS63-A4",          "Pulkovo_1942_CS63_Zone_A4",                                        0 },	// Pulkovo 1942 / CS63 zone A4
	{   2939L,  2939L, "Pulkovo42.CS63-K2",          "Pulkovo_1942_CS63_Zone_K2",                                        0 },	// Pulkovo 1942 / CS63 zone K2
	{   2940L,  2940L, "Pulkovo42.CS63-K3",          "Pulkovo_1942_CS63_Zone_K3",                                        0 },	// Pulkovo 1942 / CS63 zone K3
	{   2941L,  2941L, "Pulkovo42.CS63-K4",          "Pulkovo_1942_CS63_Zone_K4",                                        0 },	// Pulkovo 1942 / CS63 zone K4
	{   2942L,  2942L, "PortoSanto.UTM-28N",         "Porto_Santo_1936_UTM_Zone_28N",                                    0 },	// Porto Santo / UTM zone 28N
	{   2965L,  2965L, "IN83-EF",                    "NAD_1983_StatePlane_Indiana_East_FIPS_1301_Feet",                  1 },	// NAD83 / Indiana East (ftUS)
	{   2966L,  2966L, "IN83-WF",                    "NAD_1983_StatePlane_Indiana_West_FIPS_1302_Feet",                  1 },	// NAD83 / Indiana West (ftUS)
	{   2967L,  2967L, "INHP-EF",                    "NAD_1983_HARN_StatePlane_Indiana_East_FIPS_1301_Feet",             1 },	// NAD83(HARN) / Indiana East (ftUS)
	{   2968L,  2968L, "INHP-WF",                    "NAD_1983_HARN_StatePlane_Indiana_West_FIPS_1302_Feet",             1 },	// NAD83(HARN) / Indiana West (ftUS)
	{   2969L,  2969L, "FortMarigot.UTM-20N",        "Fort_Marigot_UTM_20N",                                             0 },	// Fort Marigot / UTM zone 20N
	{   2970L,  2970L, "SainteAnne.UTM-20N",         "Sainte_Anne_UTM_20N",                                              0 },	// Guadeloupe 1948 / UTM zone 20N
	{   2971L,  2971L, "CSG67.UTM-22N",              "CSG_1967_UTM_22N",                                                 0 },	// CSG67 / UTM zone 22N
	{   2972L,  2972L, "RGFG95.UTM-22N",             "RGFG_1995_UTM_22N",                                                0 },	// RGFG95 / UTM zone 22N
	{   2973L,  2973L, "FortDesaix.UTM-20N",         "Fort_Desaix_UTM_20N",                                              0 },	// Martinique 1938 / UTM zone 20N
	{   2975L,  2975L, "RGR92.UTM-40S",              "RGR_1992_UTM_40S",                                                 0 },	// RGR92 / UTM zone 40S
	{   2976L,  2976L, "Tahiti.UTM-6S",              "Tahiti_UTM_6S",                                                    0 },	// Tahiti 52 / UTM zone 6S
	{   2977L,  2977L, "Tahaa.UTM-5S",               "Tahaa_UTM_5S",                                                     0 },	// Tahaa 54 / UTM zone 5S
	{   2978L,  2978L, "IGN72NukuHiva.UTM-7S",       "IGN72_Nuku_Hiva_UTM_7S",                                           0 },	// IGN72 Nuku Hiva / UTM zone 7S
	{   2979L,  2979L, "K01949.UTM-42S",             "K0_1949_UTM_42S",                                                  2 },	// K0 1949 / UTM zone 42S
	{   2980L,  2980L, "Combani50.UTM-38S",          "Combani_1950_UTM_38S",                                             0 },	// Combani 1950 / UTM zone 38S
	{   2981L,  2981L, "IGN56Lifou.UTM-58S",         "IGN56_Lifou_UTM_58S",                                              0 },	// IGN56 Lifou / UTM zone 58S
	{   2982L,  2982L, "IGN72GrandTerre.UTM-58S",    "IGN72_Grande_Terre_UTM_58S",                                       2 },	// IGN72 Grand Terre / UTM zone 58S
	{   2983L,  2983L, "ST87Ouvea.UTM-58S",          "ST87_Ouvea_UTM_58S",                                               2 },	// ST87 Ouvea / UTM zone 58S
	{   2984L,  2984L, "RGNC91.Lambert",             "RGNC_1991_Lambert_New_Caledonia",                                  2 },	// RGNC 1991 / Lambert New Caledonia
	{   2987L,  2987L, "Miquelon50.UTM-21N",         "Saint_Pierre_et_Miquelon_1950_UTM_21N",                            0 },	// Saint Pierre et Miquelon 1950 / UTM zone 21N
	{   2988L,  2988L, "MOP78.UTM-1S",               "MOP78_UTM_1S",                                                     0 },	// MOP78 / UTM zone 1S
	{   2989L,  2989L, "RRAF91.UTM-20N",             "RRAF_1991_UTM_20N",                                                0 },	// RRAF 1991 / UTM zone 20N
	{   2990L,  2990L, "REUNION.TmReunion",          "Piton_des_Neiges_TM_Reunion",                                      0 },	// Reunion 1947 / TM Reunion
	{   2991L,  2991L, "NAD83.OregonLambert",        "NAD_1983_Oregon_Statewide_Lambert",                                0 },	// NAD83 / Oregon Lambert
	{   2992L,  2992L, "OR83-SSCGIS",                "NAD_1983_Oregon_Statewide_Lambert_Feet_Intl",                      1 },	// NAD83 / Oregon Lambert (ft)
	{   2993L,  2993L, "HARN.OregonLambert",         "NAD_1983_HARN_Oregon_Statewide_Lambert",                           0 },	// NAD83(HARN) / Oregon Lambert
	{   2994L,  2994L, "HARN.OregonLambert.ft",      "NAD_1983_HARN_Oregon_Statewide_Lambert_Feet_Intl",                 0 },	// NAD83(HARN) / Oregon Lambert (ft)
	{   2995L,  2995L, "IGN53/Mare.UTM-58S",         "IGN53_Mare_UTM_58S",                                               0 },	// IGN53 Mare / UTM zone 58S
	{   2996L,  2996L, "ST84IledesPins.UTM-58S",     "ST84_Ile_des_Pins_UTM_58S",                                        0 },	// ST84 Ile des Pins / UTM zone 58S
	{   2997L,  2997L, "ST71Belep.UTM-58S",          "ST71_Belep_UTM_58S",                                               0 },	// ST71 Belep / UTM zone 58S
	{   2998L,  2998L, "NEA74Noumea.UTM-58S",        "NEA74_Noumea_UTM_58S",                                             0 },	// NEA74 Noumea / UTM zone 58S
	{   3000L,  3000L, "Segara.NEIEZ",               "Gunung_Segara_NEIEZ",                                              0 },	// Segara / NEIEZ
	{   3001L,  3001L, "Batavia.NEIEZ",              "Batavia_NEIEZ",                                                    0 },	// Batavia / NEIEZ
	{   3002L,  3002L, "Makassar.NEIEZ",             "Makassar_NEIEZ",                                                   0 },	// Makassar / NEIEZ
	{   3003L,  3003L, "MonteMario.Italy-1",         "Monte_Mario_Italy_1",                                              0 },	// Monte Mario / Italy zone 1
	{   3004L,  3004L, "MonteMario.Italy-2",         "Monte_Mario_Italy_2",                                              0 },	// Monte Mario / Italy zone 2
	{   3005L,  3005L, "NAD83.BC/Abers",             "NAD_1983_BC_Environment_Albers",                                   0 },	// NAD83 / BC Albers
	{   3006L,  3006L, "SWEREF 99 TM",               "SWEREF99_TM",                                                      1 },	// SWEREF99 TM
	{   3007L,  3007L, "SWEREF 99 12 00",            "SWEREF99_12_00",                                                   1 },	// SWEREF99 12 00
	{   3008L,  3008L, "SWEREF 99 13 30",            "SWEREF99_13_30",                                                   1 },	// SWEREF99 13 30
	{   3009L,  3009L, "SWEREF 99 15 00",            "SWEREF99_15_00",                                                   1 },	// SWEREF99 15 00
	{   3010L,  3010L, "SWEREF 99 16 30",            "SWEREF99_16_30",                                                   1 },	// SWEREF99 16 30
	{   3011L,  3011L, "SWEREF 99 18 00",            "SWEREF99_18_00",                                                   1 },	// SWEREF99 18 00
	{   3012L,  3012L, "SWEREF 99 14 15",            "SWEREF99_14_15",                                                   1 },	// SWEREF99 14 15
	{   3013L,  3013L, "SWEREF 99 15 45",            "SWEREF99_15_45",                                                   1 },	// SWEREF99 15 45
	{   3014L,  3014L, "SWEREF 99 17 15",            "SWEREF99_17_15",                                                   1 },	// SWEREF99 17 15
	{   3015L,  3015L, "SWEREF 99 18 45",            "SWEREF99_18_45",                                                   1 },	// SWEREF99 18 45
	{   3016L,  3016L, "SWEREF 99 20 15",            "SWEREF99_20_15",                                                   1 },	// SWEREF99 20 15
	{   3017L,  3017L, "SWEREF 99 21 45",            "SWEREF99_21_45",                                                   1 },	// SWEREF99 21 45
	{   3018L,  3018L, "SWEREF 99 23 15",            "SWEREF99_23_15",                                                   1 },	// SWEREF99 23 15
	{   3019L,  3019L, "RT90-7.5V",                  "RT90_75_gon_V",                                                    1 },	// RT90 7.5 gon V
	{   3020L,  3020L, "RT90-5V",                    "RT90_5_gon_V",                                                     1 },	// RT90 5 gon V
	{   3021L,  3021L, "RT90-2.5V",                  "RT90_25_gon_V",                                                    1 },	// RT90 2.5 gon V
	{   3022L,  3022L, "RT90-0",                     "RT90_0_gon",                                                       1 },	// RT90 0 gon
	{   3023L,  3023L, "RT90-2.5O",                  "RT90_25_gon_O",                                                    1 },	// RT90 2.5 gon O
	{   3024L,  3024L, "RT90-5O",                    "RT90_5_gon_O",                                                     1 },	// RT90 5 gon O
	{   3033L,  3033L, "WGS84.AusAntarctic/LM",      "WGS_1984_Australian_Antarctic_Lambert",                            0 },	// WGS 84 / Australian Antarctic Lambert
	{   3034L,  3034L, "ETRF89.Europe/Lambert",      "ETRS_1989_LCC",                                                    0 },	// ETRS89 / ETRS-LCC
	{   3035L,  3035L, "ETRF89.Europe/EqArea",       "ETRS_1989_LAEA",                                                   0 },	// ETRS89 / ETRS-LAEA
	{   3036L,  3036L, "Moznet.UTM-36S",             "Moznet_UTM_Zone_36S",                                              0 },	// Moznet / UTM zone 36S
	{   3037L,  3037L, "Moznet.UTM-37S",             "Moznet_UTM_Zone_37S",                                              0 },	// Moznet / UTM zone 37S
	{   3054L,  3054L, "Hjorsey.UTM-26N",            "Hjorsey_1955_UTM_Zone_26N",                                        0 },	// Hjorsey 1955 / UTM zone 26N
	{   3055L,  3055L, "Hjorsey.UTM-27N",            "Hjorsey_1955_UTM_Zone_27N",                                        0 },	// Hjorsey 1955 / UTM zone 27N
	{   3056L,  3056L, "Hjorsey.UTM-28N",            "Hjorsey_1955_UTM_Zone_28N",                                        0 },	// Hjorsey 1955 / UTM zone 28N
	{   3057L,  3057L, "ISN93.IcelandGrid",          "ISN_1993_Lambert_1993",                                            1 },	// ISN93 / Lambert 1993
	{   3058L,  3058L, "Helle1954.JanMayen",         "Helle_1954_Jan_Mayen_Grid",                                        0 },	// Helle 1954 / Jan Mayen Grid
	{   3059L,  3059L, "Latvia1992.TM",              "LKS_1992_Latvia_TM",                                               0 },	// LKS92 / Latvia TM
	{   3061L,  3061L, "MADEIRA.UTM-28N",            "Porto_Santo_1995_UTM_Zone_28N",                                    0 },	// Porto Santo 1995 / UTM zone 28N
	{   3062L,  3062L, "AzoresEast95.UTM-26N",       "Azores_Oriental_1995_UTM_Zone_26N",                                0 },	// Azores Oriental 1995 / UTM zone 26N
	{   3063L,  3063L, "AzoresCntrl95.UTM-26N",      "Azores_Central_1995_UTM_Zone_26N",                                 0 },	// Azores Central 1995 / UTM zone 26N
	{   3064L,  3064L, "IGM1995.UTM-32N",            "IGM_1995_UTM_Zone_32N",                                            0 },	// IGM95 / UTM zone 32N
	{   3065L,  3065L, "IGM1995.UTM-33N",            "IGM_1995_UTM_Zone_33N",                                            0 },	// IGM95 / UTM zone 33N
	{   3066L,  3066L, "ED50.Jordan/TM",             "ED_1950_Jordan_TM",                                                0 },	// ED50 / Jordan TM
	{   3067L,  3067L, "ETRF89.TM-35/Fin",           "EUREF_FIN_TM35FIN",                                                0 },	// ETRS89 / ETRS-TM35FIN
	{   3068L,  3068L, "DHDN.Berlin/Cassini",        "DHDN_Soldner_Berlin",                                              0 },	// DHDN / Soldner Berlin
	{   3069L,  3069L, "WisconsinTM-27",             "NAD_1927_Wisconsin_TM",                                            1 },	// NAD27 / Wisconsin Transverse Mercator
	{   3070L,  3070L, "WisconsinTM-83",             "NAD_1983_Wisconsin_TM",                                            1 },	// NAD83 / Wisconsin Transverse Mercator
	{   3071L,  3071L, "WisconsinTM-HP",             "NAD_1983_HARN_Wisconsin_TM",                                       0 },	// NAD83(HARN) / Wisconsin Transverse Mercator
	{   3072L,  3072L, "ME2K-E",                     "NAD_1983_Maine_2000_East_Zone",                                    1 },	// NAD83 / Maine CS2000 East
	{   3073L,  3073L, "ME2K-C",                     "NAD_1983_Maine_2000_Central_Zone",                                 1 },	// NAD83 / Maine CS2000 Central
	{   3074L,  3074L, "ME2K-W",                     "NAD_1983_Maine_2000_West_Zone",                                    1 },	// NAD83 / Maine CS2000 West
	{   3075L,  3075L, "HARN.ME2K-E",                "NAD_1983_HARN_Maine_2000_East_Zone",                               0 },	// NAD83(HARN) / Maine CS2000 East
	{   3076L,  3076L, "HARN.ME2K-C",                "NAD_1983_HARN_Maine_2000_Central_Zone",                            0 },	// NAD83(HARN) / Maine CS2000 Central
	{   3077L,  3077L, "HARN.ME2K-W",                "NAD_1983_HARN_Maine_2000_West_Zone",                               0 },	// NAD83(HARN) / Maine CS2000 West
	{   3078L,  3078L, "MichiganGeoRef83",           "NAD_1983_Michigan_GeoRef_Meters",                                  1 },	// NAD83 / Michigan Oblique Mercator
	{   3079L,  3079L, "MichiganGeoRefHP",           "NAD_1983_HARN_Michigan_GeoRef_Meters",                             0 },	// NAD83(HARN) / Michigan Oblique Mercator
	{   3080L,  3080L, "TX27-DOT",                   "NAD_1927_Texas_Statewide_Mapping_System",                          1 },	// NAD27 / Shackleford
	{   3081L,  3081L, "TX83-DOT",                   "NAD_1983_Texas_Statewide_Mapping_System",                          1 },	// NAD83 / Texas State Mapping System
	{   3082L,  3082L, "NAD83.Texas/Lambert",        "NAD_1983_Texas_Centric_Mapping_System_Lambert",                    0 },	// NAD83 / Texas Centric Lambert Conformal
	{   3083L,  3083L, "NAD83.Texas/EqArea",         "NAD_1983_Texas_Centric_Mapping_System_Albers",                     0 },	// NAD83 / Texas Centric Albers Equal Area
	{   3084L,  3084L, "HARN.Texas/Lambert",         "NAD_1983_HARN_Texas_Centric_Mapping_System_Lambert",               0 },	// NAD83(HARN) / Texas Centric Lambert Conformal
	{   3085L,  3085L, "HARN.Texas/Albers",          "NAD_1983_HARN_Texas_Centric_Mapping_System_Albers",                0 },	// NAD83(HARN) / Texas Centric Albers Equal Area
	{   3086L,  3086L, "NAD83.FloridaGDL/Albers",    "NAD_1983_Florida_GDL_Albers",                                      0 },	// NAD83 / Florida GDL Albers
	{   3087L,  3087L, "HARN.FloridaGDL/Albers",     "NAD_1983_HARN_Florida_GDL_Albers",                                 0 },	// NAD83(HARN) / Florida GDL Albers
	{   3088L,  3088L, "KY83",                       "NAD_1983_StatePlane_Kentucky_FIPS_1600",                           1 },	// NAD83 / Kentucky Single Zone
	{   3089L,  3089L, "KY83F",                      "NAD_1983_StatePlane_Kentucky_FIPS_1600_Feet",                      1 },	// NAD83 / Kentucky Single Zone (ftUS)
	{   3090L,  3090L, "KYHP",                       "NAD_1983_HARN_StatePlane_Kentucky_FIPS_1600",                      0 },	// NAD83(HARN) / Kentucky Single Zone
	{   3091L,  3091L, "KYHPF",                      "NAD_1983_HARN_StatePlane_Kentucky_FIPS_1600_Feet",                 0 },	// NAD83(HARN) / Kentucky Single Zone (ftUS)
	{   3092L,  3092L, "TOKYO.UTM-51N",              "Tokyo_UTM_Zone_51N",                                               0 },	// Tokyo / UTM zone 51N
	{   3093L,  3093L, "TOKYO.UTM-52N",              "Tokyo_UTM_Zone_52N",                                               0 },	// Tokyo / UTM zone 52N
	{   3094L,  3094L, "TOKYO.UTM-53N",              "Tokyo_UTM_Zone_53N",                                               0 },	// Tokyo / UTM zone 53N
	{   3095L,  3095L, "TOKYO.UTM-54N",              "Tokyo_UTM_Zone_54N",                                               0 },	// Tokyo / UTM zone 54N
	{   3096L,  3096L, "TOKYO.UTM-55N",              "Tokyo_UTM_Zone_55N",                                               0 },	// Tokyo / UTM zone 55N
	{   3097L,  3097L, "JGD2000.UTM-51N",            "JGD_2000_UTM_Zone_51N",                                            0 },	// JGD2000 / UTM zone 51N
	{   3098L,  3098L, "JGD2000.UTM-52N",            "JGD_2000_UTM_Zone_52N",                                            0 },	// JGD2000 / UTM zone 52N
	{   3099L,  3099L, "JGD2000.UTM-53N",            "JGD_2000_UTM_Zone_53N",                                            0 },	// JGD2000 / UTM zone 53N
	{   3100L,  3100L, "JGD2000.UTM-54N",            "JGD_2000_UTM_Zone_54N",                                            0 },	// JGD2000 / UTM zone 54N
	{   3101L,  3101L, "JGD2000.UTM-55N",            "JGD_2000_UTM_Zone_55N",                                            0 },	// JGD2000 / UTM zone 55N
	{   3106L,  3106L, "Gulshan.Bangladesh/TM",      "Gulshan_303_Bangladesh_TM",                                        0 },	// Gulshan 303 / Bangladesh Transverse Mercator
	{   3107L,  3107L, "GDA94.SA/Lambert",           "GDA_1994_South_Australia_Lambert",                                 0 },	// GDA94 / SA Lambert
	{ 102170L,  3110L, "VictoriaGrid",               "AGD_1966_VICGRID",                                                 1 },	// AGD66 / Vicgrid66
	{ 102171L,  3111L, "GDA94.VictoriaGrid",         "GDA_1994_VICGRID94",                                               0 },	// GDA94 / Vicgrid94
	{   3148L,  3148L, "Indian1960.UTM-48N",         "Indian_1960_UTM_Zone_48N",                                         0 },	// Indian 1960 / UTM zone 48N
	{   3149L,  3149L, "Indian1960.UTM-49N",         "Indian_1960_UTM_Zone_49N",                                         0 },	// Indian 1960 / UTM zone 49N
	{   3176L,  3176L, "Indian1960.TM-106NE",        "Indian_1960_TM_106NE",                                             0 },	// Indian 1960 / TM 106 NE
	{   3200L,  3200L, "Final58.Iraq",               "FD_1958_Iraq",                                                     0 },	// FD58 / Iraq zone
	{   3300L,  3300L, "Estonia92.Estonia",          "Estonian_Coordinate_System_of_1992",                               0 },	// Estonian Coordinate System of 1992
	{   3301L,  3301L, "Estonia97.Estonia",          "Estonia_1997_Estonia_National_Grid",                               0 },	// Estonian Coordinate System of 1997
	{   2577L,  3389L, "Pulkovo42.GK3d-60/1",        "Pulkovo_1942_3_Degree_GK_Zone_60",                                 0 },	// Pulkovo 1942 / 3-degree Gauss-Kruger zone 60
	{   3439L,  3439L, "PSD93.UTM-39N",              "PDO_1993_UTM_Zone_39N",                                            0 },	// PSD93 / UTM zone 39N
	{   3440L,  3440L, "PSD93.UTM-40N",              "PDO_1993_UTM_Zone_40N",                                            0 },	// PSD93 / UTM zone 40N
	{   3561L,  3561L, "OLDHI.Hawaii-1",             "Old_Hawaiian_StatePlane_Hawaii_1_FIPS_5101",                       0 },	// Old Hawaiian / Hawaii zone 1
	{   3562L,  3562L, "OLDHI.Hawaii-2",             "Old_Hawaiian_StatePlane_Hawaii_2_FIPS_5102",                       0 },	// Old Hawaiian / Hawaii zone 2
	{   3563L,  3563L, "OLDHI.Hawaii-3",             "Old_Hawaiian_StatePlane_Hawaii_3_FIPS_5103",                       0 },	// Old Hawaiian / Hawaii zone 3
	{   3564L,  3564L, "OLDHI.Hawaii-4",             "Old_Hawaiian_StatePlane_Hawaii_4_FIPS_5104",                       0 },	// Old Hawaiian / Hawaii zone 4
	{   3565L,  3565L, "OLDHI.Hawaii-5",             "Old_Hawaiian_StatePlane_Hawaii_5_FIPS_5105",                       0 },	// Old Hawaiian / Hawaii zone 5
	{   3920L,  3920L, "PRVI.UTM-20N",               "Puerto_Rico_UTM_Zone_20N",                                         0 },	// Puerto Rico / UTM zone 20N
	{   3991L,  3991L, "PRVI.PR-1",                  "Puerto_Rico_StatePlane_Puerto_Rico_FIPS_5201",                     0 },	// Puerto Rico State Plane CS of 1927
	{   3992L,  3992L, "PRVI.PR-2",                  "Puerto_Rico_StatePlane_Virgin_Islands_St_Croix_FIPS_5202",         0 },	// Puerto Rico / St. Croix
	{  20137L, 20137L, "Adindan.UTM-37N",            "Adindan_UTM_Zone_37N",                                             0 },	// Adindan / UTM zone 37N
	{  20138L, 20138L, "Adindan.UTM-38N",            "Adindan_UTM_Zone_38N",                                             0 },	// Adindan / UTM zone 38N
	{  20248L, 20248L, "AMG66-48",                   "AGD_1966_AMG_Zone_48",                                             1 },	// AGD66 / AMG zone 48
	{  20249L, 20249L, "AMG66-49",                   "AGD_1966_AMG_Zone_49",                                             1 },	// AGD66 / AMG zone 49
	{  20250L, 20250L, "AMG66-50",                   "AGD_1966_AMG_Zone_50",                                             1 },	// AGD66 / AMG zone 50
	{  20251L, 20251L, "AMG66-51",                   "AGD_1966_AMG_Zone_51",                                             1 },	// AGD66 / AMG zone 51
	{  20252L, 20252L, "AMG66-52",                   "AGD_1966_AMG_Zone_52",                                             1 },	// AGD66 / AMG zone 52
	{  20253L, 20253L, "AMG66-53",                   "AGD_1966_AMG_Zone_53",                                             1 },	// AGD66 / AMG zone 53
	{  20254L, 20254L, "AMG66-54",                   "AGD_1966_AMG_Zone_54",                                             1 },	// AGD66 / AMG zone 54
	{  20255L, 20255L, "AMG66-55",                   "AGD_1966_AMG_Zone_55",                                             1 },	// AGD66 / AMG zone 55
	{  20256L, 20256L, "AMG66-56",                   "AGD_1966_AMG_Zone_56",                                             1 },	// AGD66 / AMG zone 56
	{  20257L, 20257L, "AMG66-57",                   "AGD_1966_AMG_Zone_57",                                             1 },	// AGD66 / AMG zone 57
	{  20258L, 20258L, "AMG66-58",                   "AGD_1966_AMG_Zone_58",                                             1 },	// AGD66 / AMG zone 58
	{  20348L, 20348L, "AMG84-48",                   "AGD_1984_AMG_Zone_48",                                             1 },	// AGD84 / AMG zone 48
	{  20349L, 20349L, "AMG84-49",                   "AGD_1984_AMG_Zone_49",                                             1 },	// AGD84 / AMG zone 49
	{  20350L, 20350L, "AMG84-50",                   "AGD_1984_AMG_Zone_50",                                             1 },	// AGD84 / AMG zone 50
	{  20351L, 20351L, "AMG84-51",                   "AGD_1984_AMG_Zone_51",                                             1 },	// AGD84 / AMG zone 51
	{  20352L, 20352L, "AMG84-52",                   "AGD_1984_AMG_Zone_52",                                             1 },	// AGD84 / AMG zone 52
	{  20353L, 20353L, "AMG84-53",                   "AGD_1984_AMG_Zone_53",                                             1 },	// AGD84 / AMG zone 53
	{  20354L, 20354L, "AMG84-54",                   "AGD_1984_AMG_Zone_54",                                             1 },	// AGD84 / AMG zone 54
	{  20355L, 20355L, "AMG84-55",                   "AGD_1984_AMG_Zone_55",                                             1 },	// AGD84 / AMG zone 55
	{  20356L, 20356L, "AMG84-56",                   "AGD_1984_AMG_Zone_56",                                             1 },	// AGD84 / AMG zone 56
	{  20357L, 20357L, "AMG84-57",                   "AGD_1984_AMG_Zone_57",                                             1 },	// AGD84 / AMG zone 57
	{  20358L, 20358L, "AMG84-58",                   "AGD_1984_AMG_Zone_58",                                             1 },	// AGD84 / AMG zone 58
	{  20437L, 20437L, "AinElAbd.UTM-37N",           "Ain_el_Abd_UTM_Zone_37N",                                          0 },	// Ain el Abd / UTM zone 37N
	{  20438L, 20438L, "AinElAbd.UTM-38N",           "Ain_el_Abd_UTM_Zone_38N",                                          0 },	// Ain el Abd / UTM zone 38N
	{  20439L, 20439L, "AinElAbd.UTM-39N",           "Ain_el_Abd_UTM_Zone_39N",                                          0 },	// Ain el Abd / UTM zone 39N
	{  20499L, 20499L, "AinElAbd.BahrainGrid",       "Bahrain_State_Grid",                                               0 },	// Ain el Abd / Bahrain Grid
	{  20538L, 20538L, "Afgooye.UTM-38N",            "Afgooye_UTM_Zone_38N",                                             0 },	// Afgooye / UTM zone 38N
	{  20539L, 20539L, "Afgooye.UTM-39N",            "Afgooye_UTM_Zone_39N",                                             0 },	// Afgooye / UTM zone 39N
	{  20822L, 20822L, "Aratu.UTM-22S",              "Aratu_UTM_Zone_22S",                                               0 },	// Aratu / UTM zone 22S
	{  20823L, 20823L, "Aratu.UTM-23S",              "Aratu_UTM_Zone_23S",                                               0 },	// Aratu / UTM zone 23S
	{  20824L, 20824L, "Aratu.UTM-24S",              "Aratu_UTM_Zone_24S",                                               0 },	// Aratu / UTM zone 24S
	{  20934L, 20934L, "ARC1950.UTM-34S",            "Arc_1950_UTM_Zone_34S",                                            0 },	// Arc 1950 / UTM zone 34S
	{  20935L, 20935L, "ARC1950.UTM-35S",            "Arc_1950_UTM_Zone_35S",                                            0 },	// Arc 1950 / UTM zone 35S
	{  20936L, 20936L, "ARC1950.UTM-36S",            "Arc_1950_UTM_Zone_36S",                                            0 },	// Arc 1950 / UTM zone 36S
	{  21035L, 21035L, "ARC1960.UTM-35S",            "Arc_1960_UTM_Zone_35S",                                            0 },	// Arc 1960 / UTM zone 35S
	{  21036L, 21036L, "ARC1960.UTM-36S",            "Arc_1960_UTM_Zone_36S",                                            0 },	// Arc 1960 / UTM zone 36S
	{  21037L, 21037L, "ARC1960.UTM-37S",            "Arc_1960_UTM_Zone_37S",                                            0 },	// Arc 1960 / UTM zone 37S
	{  21095L, 21095L, "ARC1960.UTM-35N",            "Arc_1960_UTM_Zone_35N",                                            0 },	// Arc 1960 / UTM zone 35N
	{  21096L, 21096L, "ARC1960.UTM-36N",            "Arc_1960_UTM_Zone_36N",                                            0 },	// Arc 1960 / UTM zone 36N
	{  21097L, 21097L, "ARC1960.UTM-37N",            "Arc_1960_UTM_Zone_37N",                                            0 },	// Arc 1960 / UTM zone 37N
	{  21148L, 21148L, "Batavia.UTM-48S",            "Batavia_UTM_Zone_48S",                                             0 },	// Batavia / UTM zone 48S
	{  21149L, 21149L, "Batavia.UTM-49S",            "Batavia_UTM_Zone_49S",                                             0 },	// Batavia / UTM zone 49S
	{  21150L, 21150L, "Batavia.UTM-50S",            "Batavia_UTM_Zone_50S",                                             0 },	// Batavia / UTM zone 50S
	{  21291L, 21291L, "Barbados38.BWIgrid",         "Barbados_1938_British_West_Indies_Grid",                           0 },	// Barbados 1938 / British West Indies Grid
	{  21292L, 21292L, "Barbados38.NtlGrid",         "Barbados_1938_Barbados_Grid",                                      0 },	// Barbados 1938 / Barbados National Grid
	{  21413L, 21413L, "Beijing54.GK-13",            "Beijing_1954_GK_Zone_13",                                          0 },	// Beijing 1954 / Gauss-Kruger zone 13
	{  21414L, 21414L, "Beijing54.GK-14",            "Beijing_1954_GK_Zone_14",                                          0 },	// Beijing 1954 / Gauss-Kruger zone 14
	{  21415L, 21415L, "Beijing54.GK-15",            "Beijing_1954_GK_Zone_15",                                          0 },	// Beijing 1954 / Gauss-Kruger zone 15
	{  21416L, 21416L, "Beijing54.GK-16",            "Beijing_1954_GK_Zone_16",                                          0 },	// Beijing 1954 / Gauss-Kruger zone 16
	{  21417L, 21417L, "Beijing54.GK-17",            "Beijing_1954_GK_Zone_17",                                          0 },	// Beijing 1954 / Gauss-Kruger zone 17
	{  21418L, 21418L, "Beijing54.GK-18",            "Beijing_1954_GK_Zone_18",                                          0 },	// Beijing 1954 / Gauss-Kruger zone 18
	{  21419L, 21419L, "Beijing54.GK-19",            "Beijing_1954_GK_Zone_19",                                          0 },	// Beijing 1954 / Gauss-Kruger zone 19
	{  21420L, 21420L, "Beijing54.GK-20",            "Beijing_1954_GK_Zone_20",                                          0 },	// Beijing 1954 / Gauss-Kruger zone 20
	{  21421L, 21421L, "Beijing54.GK-21",            "Beijing_1954_GK_Zone_21",                                          0 },	// Beijing 1954 / Gauss-Kruger zone 21
	{  21422L, 21422L, "Beijing54.GK-22",            "Beijing_1954_GK_Zone_22",                                          0 },	// Beijing 1954 / Gauss-Kruger zone 22
	{  21423L, 21423L, "Beijing54.GK-23",            "Beijing_1954_GK_Zone_23",                                          0 },	// Beijing 1954 / Gauss-Kruger zone 23
	{  21473L, 21473L, "Beijing54.GK-13N",           "Beijing_1954_GK_Zone_13N",                                         2 },	// Beijing 1954 / Gauss-Kruger 13N
	{  21474L, 21474L, "Beijing54.GK-14N",           "Beijing_1954_GK_Zone_14N",                                         2 },	// Beijing 1954 / Gauss-Kruger 14N
	{  21475L, 21475L, "Beijing54.GK-15N",           "Beijing_1954_GK_Zone_15N",                                         2 },	// Beijing 1954 / Gauss-Kruger 15N
	{  21476L, 21476L, "Beijing54.GK-16N",           "Beijing_1954_GK_Zone_16N",                                         2 },	// Beijing 1954 / Gauss-Kruger 16N
	{  21477L, 21477L, "Beijing54.GK-17N",           "Beijing_1954_GK_Zone_17N",                                         2 },	// Beijing 1954 / Gauss-Kruger 17N
	{  21478L, 21478L, "Beijing54.GK-18N",           "Beijing_1954_GK_Zone_18N",                                         2 },	// Beijing 1954 / Gauss-Kruger 18N
	{  21479L, 21479L, "Beijing54.GK-19N",           "Beijing_1954_GK_Zone_19N",                                         2 },	// Beijing 1954 / Gauss-Kruger 19N
	{  21480L, 21480L, "Beijing54.GK-20N",           "Beijing_1954_GK_Zone_20N",                                         2 },	// Beijing 1954 / Gauss-Kruger 20N
	{  21481L, 21481L, "Beijing54.GK-21N",           "Beijing_1954_GK_Zone_21N",                                         2 },	// Beijing 1954 / Gauss-Kruger 21N
	{  21482L, 21482L, "Beijing54.GK-22N",           "Beijing_1954_GK_Zone_22N",                                         2 },	// Beijing 1954 / Gauss-Kruger 22N
	{  21483L, 21483L, "Beijing54.GK-23N",           "Beijing_1954_GK_Zone_23N",                                         2 },	// Beijing 1954 / Gauss-Kruger 23N
	{  21781L, 21781L, "CH1903.LV03",                "CH1903_LV03",                                                      0 },	// CH1903 / LV03
	{  21817L, 21817L, "BOGOTA.UTM-17N",             "Bogota_UTM_Zone_17N",                                              2 },	// Bogota 1975 / UTM zone 17N
	{  21818L, 21818L, "BOGOTA.UTM-18N",             "Bogota_UTM_Zone_18N",                                              0 },	// Bogota 1975 / UTM zone 18N
	{  22032L, 22032L, "Camacupa.UTM-32S",           "Camacupa_UTM_Zone_32S",                                            0 },	// Camacupa / UTM zone 32S
	{  22033L, 22033L, "Camacupa.UTM-33S",           "Camacupa_UTM_Zone_33S",                                            0 },	// Camacupa / UTM zone 33S
	{  22091L, 22091L, "Camacupa.TM-1130SE",         "Camacupa_TM_11_30_SE",                                             0 },	// Camacupa / TM 11.30 SE
	{  22092L, 22092L, "Camacupa.TM-12SE",           "Camacupa_TM_12_SE",                                                0 },	// Camacupa / TM 12 SE
	{  22191L, 22191L, "Campo.Argentina 1",          "Argentina_Zone_1",                                                 0 },	// Campo Inchauspe / Argentina 1
	{  22192L, 22192L, "Campo.Argentina 2",          "Argentina_Zone_2",                                                 0 },	// Campo Inchauspe / Argentina 2
	{  22193L, 22193L, "Campo.Argentina 3",          "Argentina_Zone_3",                                                 0 },	// Campo Inchauspe / Argentina 3
	{  22194L, 22194L, "Campo.Argentina 4",          "Argentina_Zone_4",                                                 0 },	// Campo Inchauspe / Argentina 4
	{  22195L, 22195L, "Campo.Argentina 5",          "Argentina_Zone_5",                                                 0 },	// Campo Inchauspe / Argentina 5
	{  22196L, 22196L, "Campo.Argentina 6",          "Argentina_Zone_6",                                                 0 },	// Campo Inchauspe / Argentina 6
	{  22197L, 22197L, "Campo.Argentina 7",          "Argentina_Zone_7",                                                 0 },	// Campo Inchauspe / Argentina 7
	{  22234L, 22234L, "Cape-1.UTM-34S",             "Cape_UTM_Zone_34S",                                                0 },	// Cape / UTM zone 34S
	{  22235L, 22235L, "Cape-1.UTM-35S",             "Cape_UTM_Zone_35S",                                                0 },	// Cape / UTM zone 35S
	{  22236L, 22236L, "Cape-1.UTM-36S",             "Cape_UTM_Zone_36S",                                                0 },	// Cape / UTM zone 36S
	{  22332L, 22332L, "Carthage.UTM-32N",           "Carthage_UTM_Zone_32N",                                            0 },	// Carthage / UTM zone 32N
	{  22391L, 22391L, "Carthage.NordTunisie",       "Nord_Tunisie",                                                     0 },	// Carthage / Nord Tunisie
	{  22392L, 22392L, "Carthage.SudTunisie",        "Sud_Tunisie",                                                      0 },	// Carthage / Sud Tunisie
	{  22523L, 22523L, "Corrego.UTM-23S",            "Corrego_Alegre_UTM_Zone_23S",                                      0 },	// Corrego Alegre / UTM zone 23S
	{  22524L, 22524L, "Corrego.UTM-24S",            "Corrego_Alegre_UTM_Zone_24S",                                      0 },	// Corrego Alegre / UTM zone 24S
	{  22700L, 22700L, "DeirEzZor.Levant",           "Deir_ez_Zor_Levant_Zone",                                          0 },	// Deir ez Zor / Levant Zone
	{  22770L, 22770L, "DeirEzZor.Syria",            "Deir_ez_Zor_Syria_Lambert",                                        0 },	// Deir ez Zor / Syria Lambert
	{  22780L, 22780L, "DeirEzZor.Levant",           "Deir_ez_Zor_Levant_Stereographic",                                 0 },	// Deir ez Zor / Levant Stereographic
	{  22991L, 22991L, "Old-Egyp.Blue",              "Egypt_Blue_Belt",                                                  0 },	// Egypt 1907 / Blue Belt
	{  22992L, 22992L, "Old-Egyp.Red",               "Egypt_Red_Belt",                                                   0 },	// Egypt 1907 / Red Belt
	{  22993L, 22993L, "Old-Egyp.Purple",            "Egypt_Purple_Belt",                                                0 },	// Egypt 1907 / Purple Belt
	{  22994L, 22994L, "Old-Egyp.ExPurple",          "Egypt_Extended_Purple_Belt",                                       0 },	// Egypt 1907 / Extended Purple Belt
	{  23028L, 23028L, "ED50-UTM28",                 "ED_1950_UTM_Zone_28N",                                             1 },	// ED50 / UTM zone 28N
	{  23029L, 23029L, "ED50-UTM29",                 "ED_1950_UTM_Zone_29N",                                             1 },	// ED50 / UTM zone 29N
	{  23030L, 23030L, "ED50-UTM30",                 "ED_1950_UTM_Zone_30N",                                             1 },	// ED50 / UTM zone 30N
	{  23031L, 23031L, "ED50-UTM31",                 "ED_1950_UTM_Zone_31N",                                             1 },	// ED50 / UTM zone 31N
	{  23032L, 23032L, "ED50-UTM32",                 "ED_1950_UTM_Zone_32N",                                             1 },	// ED50 / UTM zone 32N
	{  23033L, 23033L, "ED50-UTM33",                 "ED_1950_UTM_Zone_33N",                                             1 },	// ED50 / UTM zone 33N
	{  23034L, 23034L, "ED50-UTM34",                 "ED_1950_UTM_Zone_34N",                                             1 },	// ED50 / UTM zone 34N
	{  23035L, 23035L, "ED50-UTM35",                 "ED_1950_UTM_Zone_35N",                                             1 },	// ED50 / UTM zone 35N
	{  23036L, 23036L, "ED50-UTM36",                 "ED_1950_UTM_Zone_36N",                                             1 },	// ED50 / UTM zone 36N
	{  23037L, 23037L, "ED50-UTM37",                 "ED_1950_UTM_Zone_37N",                                             1 },	// ED50 / UTM zone 37N
	{  23038L, 23038L, "ED50-UTM38",                 "ED_1950_UTM_Zone_38N",                                             1 },	// ED50 / UTM zone 38N
	{  23090L, 23090L, "Europ50.TM-0N",              "ED_1950_TM_0_N",                                                   0 },	// ED50 / TM 0 N
	{  23095L, 23095L, "Europ50.TM-5NE",             "ED_1950_TM_5_NE",                                                  0 },	// ED50 / TM 5 NE
	{  23239L, 23239L, "Fahud.UTM-39N",              "Fahud_UTM_Zone_39N",                                               0 },	// Fahud / UTM zone 39N
	{  23240L, 23240L, "Fahud.UTM-40N",              "Fahud_UTM_Zone_40N",                                               0 },	// Fahud / UTM zone 40N
	{  23700L, 23700L, "HU-EOV72",                   "Hungarian_1972_Egyseges_Orszagos_Vetuleti",                        1 },	// HD72 / EOV
	{  23846L, 23846L, "Indonesian74.UTM-46N",       "Indonesian_1974_UTM_Zone_46N",                                     0 },	// ID74 / UTM zone 46N
	{  23847L, 23847L, "Indonesian74.UTM-47N",       "Indonesian_1974_UTM_Zone_47N",                                     0 },	// ID74 / UTM zone 47N
	{  23848L, 23848L, "Indonesian74.UTM-48N",       "Indonesian_1974_UTM_Zone_48N",                                     0 },	// ID74 / UTM zone 48N
	{  23849L, 23849L, "Indonesian74.UTM-49N",       "Indonesian_1974_UTM_Zone_49N",                                     0 },	// ID74 / UTM zone 49N
	{  23850L, 23850L, "Indonesian74.UTM-50N",       "Indonesian_1974_UTM_Zone_50N",                                     0 },	// ID74 / UTM zone 50N
	{  23851L, 23851L, "Indonesian74.UTM-51N",       "Indonesian_1974_UTM_Zone_51N",                                     0 },	// ID74 / UTM zone 51N
	{  23852L, 23852L, "Indonesian74.UTM-52N",       "Indonesian_1974_UTM_Zone_52N",                                     0 },	// ID74 / UTM zone 52N
	{  23853L, 23853L, "Indonesian74.UTM-53N",       "Indonesian_1974_UTM_Zone_53N",                                     2 },	// ID74 / UTM zone 53N
	{  23886L, 23886L, "Indonesian74.UTM-46S",       "Indonesian_1974_UTM_Zone_46S",                                     2 },	// ID74 / UTM zone 46S
	{  23887L, 23887L, "Indonesian74.UTM-47S",       "Indonesian_1974_UTM_Zone_47S",                                     0 },	// ID74 / UTM zone 47S
	{  23888L, 23888L, "Indonesian74.UTM-48S",       "Indonesian_1974_UTM_Zone_48S",                                     0 },	// ID74 / UTM zone 48S
	{  23889L, 23889L, "Indonesian74.UTM-49S",       "Indonesian_1974_UTM_Zone_49S",                                     0 },	// ID74 / UTM zone 49S
	{  23890L, 23890L, "Indonesian74.UTM-50S",       "Indonesian_1974_UTM_Zone_50S",                                     0 },	// ID74 / UTM zone 50S
	{  23891L, 23891L, "Indonesian74.UTM-51S",       "Indonesian_1974_UTM_Zone_51S",                                     0 },	// ID74 / UTM zone 51S
	{  23892L, 23892L, "Indonesian74.UTM-52S",       "Indonesian_1974_UTM_Zone_52S",                                     0 },	// ID74 / UTM zone 52S
	{  23893L, 23893L, "Indonesian74.UTM-53S",       "Indonesian_1974_UTM_Zone_53S",                                     0 },	// ID74 / UTM zone 53S
	{  23894L, 23894L, "Indonesian74.UTM-54S",       "Indonesian_1974_UTM_Zone_54S",                                     0 },	// ID74 / UTM zone 54S
	{  23946L, 23946L, "Indian54.UTM-46N",           "Indian_1954_UTM_Zone_46N",                                         0 },	// Indian 1954 / UTM zone 46N
	{  23947L, 23947L, "Indian54.UTM-47N",           "Indian_1954_UTM_Zone_47N",                                         0 },	// Indian 1954 / UTM zone 47N
	{  23948L, 23948L, "Indian54.UTM-48N",           "Indian_1954_UTM_Zone_48N",                                         0 },	// Indian 1954 / UTM zone 48N
	{  24047L, 24047L, "Indian75.UTM-47N",           "Indian_1975_UTM_Zone_47N",                                         0 },	// Indian 1975 / UTM zone 47N
	{  24048L, 24048L, "Indian75.UTM-48N",           "Indian_1975_UTM_Zone_48N",                                         0 },	// Indian 1975 / UTM zone 48N
	{  24200L, 24200L, "Jamaica69.NtlGrid",          "Jamaica_Grid",                                                     0 },	// JAD69 / Jamaica National Grid
	{  24305L, 24305L, "Kalianpur37.UTM-45N",        "Kalianpur_1937_UTM_Zone_45N",                                      0 },	// Kalianpur 1937 / UTM zone 45N
	{  24306L, 24306L, "Kalianpur37.UTM-46N",        "Kalianpur_1937_UTM_Zone_46N",                                      0 },	// Kalianpur 1937 / UTM zone 46N
	{  24311L, 24311L, "Kalianpur62.UTM-41N",        "Kalianpur_1962_UTM_Zone_41N",                                      0 },	// Kalianpur 1962 / UTM zone 41N
	{  24312L, 24312L, "Kalianpur62.UTM-42N",        "Kalianpur_1962_UTM_Zone_42N",                                      0 },	// Kalianpur 1962 / UTM zone 42N
	{  24313L, 24313L, "Kalianpur62.UTM-43N",        "Kalianpur_1962_UTM_Zone_43N",                                      0 },	// Kalianpur 1962 / UTM zone 43N
	{  24342L, 24342L, "Kalianpur75.UTM-42N",        "Kalianpur_1975_UTM_Zone_42N",                                      0 },	// Kalianpur 1975 / UTM zone 42N
	{  24343L, 24343L, "Kalianpur75.UTM-43N",        "Kalianpur_1975_UTM_Zone_43N",                                      0 },	// Kalianpur 1975 / UTM zone 43N
	{  24344L, 24344L, "Kalianpur75.UTM-44N",        "Kalianpur_1975_UTM_Zone_44N",                                      0 },	// Kalianpur 1975 / UTM zone 44N
	{  24345L, 24345L, "Kalianpur75.UTM-45N",        "Kalianpur_1975_UTM_Zone_45N",                                      0 },	// Kalianpur 1975 / UTM zone 45N
	{  24346L, 24346L, "Kalianpur75.UTM-46N",        "Kalianpur_1975_UTM_Zone_46N",                                      0 },	// Kalianpur 1975 / UTM zone 46N
	{  24347L, 24347L, "Kalianpur75.UTM-47N",        "Kalianpur_1975_UTM_Zone_47N",                                      0 },	// Kalianpur 1975 / UTM zone 47N
	{  24375L, 24375L, "Kalianpur37.India-IIb",      "Kalianpur_1937_India_Zone_IIb",                                    0 },	// Kalianpur 1937 / India zone IIb
	{  24376L, 24376L, "Kalianpur62.India-I",        "Kalianpur_1962_India_Zone_I",                                      0 },	// Kalianpur 1962 / India zone I
	{  24377L, 24377L, "Kalianpur62.India-IIa",      "Kalianpur_1962_India_Zone_IIa",                                    0 },	// Kalianpur 1962 / India zone IIa
	{  24378L, 24378L, "Kalianpur75.India-I",        "Kalianpur_1975_India_Zone_I",                                      0 },	// Kalianpur 1975 / India zone I
	{  24379L, 24379L, "Kalianpur75.India-IIa",      "Kalianpur_1975_India_Zone_IIa",                                    0 },	// Kalianpur 1975 / India zone IIa
	{  24380L, 24380L, "Kalianpur75.India-IIb",      "Kalianpur_1975_India_Zone_IIb",                                    0 },	// Kalianpur 1975 / India zone IIb
	{  24381L, 24381L, "Kalianpur75.India-III",      "Kalianpur_1975_India_Zone_III",                                    0 },	// Kalianpur 1975 / India zone III
	{  24383L, 24383L, "Kalianpur75.India-IV",       "Kalianpur_1975_India_Zone_IV",                                     0 },	// Kalianpur 1975 / India zone IV
	{  24500L, 24500L, "Kertau.SingaporeGrid",       "Kertau_Singapore_Grid",                                            0 },	// Kertau 1968 / Singapore Grid
	{  24547L, 24547L, "Kertau.UTM-47N",             "Kertau_UTM_Zone_47N",                                              0 },	// Kertau 1968 / UTM zone 47N
	{  24548L, 24548L, "Kertau.UTM-48N",             "Kertau_UTM_Zone_48N",                                              0 },	// Kertau 1968 / UTM zone 48N
	{  24571L, 24571L, "Kertau.MalayaRSO",           "Kertau_RSO_Malaya_Chains",                                         2 },	// Kertau / R.S.O. Malaya (ch)
	{  24600L, 24600L, "KuwaitOilCo.Lambert",        "KOC_Lambert",                                                      0 },	// KOC Lambert
	{  24718L, 24718L, "LaCanoa.UTM-18N",            "La_Canoa_UTM_Zone_18N",                                            0 },	// La Canoa / UTM zone 18N
	{  24719L, 24719L, "LaCanoa.UTM-19N",            "La_Canoa_UTM_Zone_19N",                                            0 },	// La Canoa / UTM zone 19N
	{  24720L, 24720L, "LaCanoa.UTM-20N",            "La_Canoa_UTM_Zone_20N",                                            0 },	// La Canoa / UTM zone 20N
	{  24818L, 24818L, "UTM56-18N",                  "PSAD_1956_UTM_Zone_18N",                                           1 },	// PSAD56 / UTM zone 18N
	{  24819L, 24819L, "UTM56-19N",                  "PSAD_1956_UTM_Zone_19N",                                           1 },	// PSAD56 / UTM zone 19N
	{  24820L, 24820L, "UTM56-20N",                  "PSAD_1956_UTM_Zone_20N",                                           1 },	// PSAD56 / UTM zone 20N
	{  24821L, 24821L, "UTM56-21N",                  "PSAD_1956_UTM_Zone_21N",                                           1 },	// PSAD56 / UTM zone 21N
	{  24877L, 24877L, "UTM56-17S",                  "PSAD_1956_UTM_Zone_17S",                                           1 },	// PSAD56 / UTM zone 17S
	{  24878L, 24878L, "UTM56-18S",                  "PSAD_1956_UTM_Zone_18S",                                           1 },	// PSAD56 / UTM zone 18S
	{  24879L, 24879L, "UTM56-19S",                  "PSAD_1956_UTM_Zone_19S",                                           1 },	// PSAD56 / UTM zone 19S
	{  24880L, 24880L, "UTM56-20S",                  "PSAD_1956_UTM_Zone_20S",                                           1 },	// PSAD56 / UTM zone 20S
	{  24882L, 24882L, "UTM56-22S",                  "PSAD_1956_UTM_Zone_22S",                                           1 },	// PSAD56 / UTM zone 22S
	{  24891L, 24891L, "PSAD56.PeruWest",            "Peru_West_Zone",                                                   0 },	// PSAD56 / Peru west zone
	{  24892L, 24892L, "PSAD56.PeruCentral",         "Peru_Central_Zone",                                                0 },	// PSAD56 / Peru central zone
	{  24893L, 24893L, "PSAD56.PeruEast",            "Peru_East_Zone",                                                   0 },	// PSAD56 / Peru east zone
	{  25000L, 25000L, "Leigon.GhanaMetreGrid",      "Ghana_Metre_Grid",                                                 0 },	// Leigon / Ghana Metre Grid
	{  25391L, 25391L, "Luzon.Philippines-I",        "Philippines_Zone_I",                                               0 },	// Luzon 1911 / Philippines zone I
	{  25392L, 25392L, "Luzon.Philippines-II",       "Philippines_Zone_II",                                              0 },	// Luzon 1911 / Philippines zone II
	{  25393L, 25393L, "Luzon.Philippines-III",      "Philippines_Zone_III",                                             0 },	// Luzon 1911 / Philippines zone III
	{  25394L, 25394L, "Luzon.Philippines-IV",       "Philippines_Zone_IV",                                              0 },	// Luzon 1911 / Philippines zone IV
	{  25395L, 25395L, "Luzon.Philippines-V",        "Philippines_Zone_V",                                               0 },	// Luzon 1911 / Philippines zone V
	{  25828L, 25828L, "ETRS89.UTM-28N",             "ETRS_1989_UTM_Zone_28N",                                           0 },	// ETRS89 / UTM zone 28N
	{  25829L, 25829L, "ETRS89.UTM-29N",             "ETRS_1989_UTM_Zone_29N",                                           0 },	// ETRS89 / UTM zone 29N
	{  25830L, 25830L, "ETRS89.UTM-30N",             "ETRS_1989_UTM_Zone_30N",                                           0 },	// ETRS89 / UTM zone 30N
	{  25831L, 25831L, "ETRS89.UTM-31N",             "ETRS_1989_UTM_Zone_31N",                                           0 },	// ETRS89 / UTM zone 31N
	{  25832L, 25832L, "ETRS89.UTM-32N",             "ETRS_1989_UTM_Zone_32N",                                           0 },	// ETRS89 / UTM zone 32N
	{  25833L, 25833L, "ETRS89.UTM-33N",             "ETRS_1989_UTM_Zone_33N",                                           0 },	// ETRS89 / UTM zone 33N
	{  25834L, 25834L, "ETRS89.UTM-34N",             "ETRS_1989_UTM_Zone_34N",                                           0 },	// ETRS89 / UTM zone 34N
	{  25835L, 25835L, "ETRS89.UTM-35N",             "ETRS_1989_UTM_Zone_35N",                                           0 },	// ETRS89 / UTM zone 35N
	{  25836L, 25836L, "ETRS89.UTM-36N",             "ETRS_1989_UTM_Zone_36N",                                           0 },	// ETRS89 / UTM zone 36N
	{  25837L, 25837L, "ETRS89.UTM-37N",             "ETRS_1989_UTM_Zone_37N",                                           0 },	// ETRS89 / UTM zone 37N
	{  25838L, 25838L, "ETRS89.UTM-38N",             "ETRS_1989_UTM_Zone_38N",                                           0 },	// ETRS89 / UTM zone 38N
	{  25884L, 25884L, "ETRS89.TM-Baltic",           "ETRS_1989_TM_Baltic_1993",                                         0 },	// ETRS89 / TM Baltic93
	{  25932L, 25932L, "Malongo87.UTM-32S",          "Malongo_1987_UTM_Zone_32S",                                        0 },	// Malongo 1987 / UTM zone 32S
	{  26191L, 26191L, "Merchich.NordMaroc",         "Nord_Maroc",                                                       0 },	// Merchich / Nord Maroc
	{  26192L, 26192L, "Merchich.SudMaroc",          "Sud_Maroc",                                                        0 },	// Merchich / Sud Maroc
	{  26193L, 26193L, "Merchich.Sahara",            "Sahara",                                                           2 },	// Merchich / Sahara
	{  26237L, 26237L, "Massawa.UTM-37N",            "Massawa_UTM_Zone_37N",                                             0 },	// Massawa / UTM zone 37N
	{  26331L, 26331L, "Minna.UTM-31N",              "Minna_UTM_Zone_31N",                                               0 },	// Minna / UTM zone 31N
	{  26332L, 26332L, "Minna.UTM-32N",              "Minna_UTM_Zone_32N",                                               0 },	// Minna / UTM zone 32N
	{  26391L, 26391L, "Minna.NigeriaWest",          "Nigeria_West_Belt",                                                0 },	// Minna / Nigeria West Belt
	{  26392L, 26392L, "Minna.NigeriaMid",           "Nigeria_Mid_Belt",                                                 0 },	// Minna / Nigeria Mid Belt
	{  26393L, 26393L, "Minna.NigeriaEast",          "Nigeria_East_Belt",                                                0 },	// Minna / Nigeria East Belt
	{  26432L, 26432L, "Mhast.UTM-32S",              "Mhast_UTM_Zone_32S",                                               2 },	// Mhast / UTM zone 32S
	{  26591L, 26591L, "MonteMario.Italy-1",         "Monte_Mario_Rome_Italy_1",                                         2 },	// Monte Mario (Rome) / Italy zone 1
	{  26592L, 26592L, "MonteMario.Italy-2",         "Monte_Mario_Rome_Italy_2",                                         2 },	// Monte Mario (Rome) / Italy zone 2
	{  26632L, 26632L, "Mporaloko.UTM-32N",          "Mporaloko_UTM_Zone_32N",                                           0 },	// M'poraloko / UTM zone 32N
	{  26692L, 26692L, "Mporaloko.UTM-32S",          "Mporaloko_UTM_Zone_32S",                                           0 },	// M'poraloko / UTM zone 32S
	{ 102124L, 26701L, "UTM27-1N",                   "NAD_1927_UTM_Zone_1N",                                             0 },	// NAD27 / UTM zone 1N
	{ 102125L, 26702L, "UTM27-2N",                   "NAD_1927_UTM_Zone_2N",                                             0 },	// NAD27 / UTM zone 2N
	{  26703L, 26703L, "UTM27-3",                    "NAD_1927_UTM_Zone_3N",                                             1 },	// NAD27 / UTM zone 3N
	{  26704L, 26704L, "UTM27-4",                    "NAD_1927_UTM_Zone_4N",                                             1 },	// NAD27 / UTM zone 4N
	{  26705L, 26705L, "UTM27-5",                    "NAD_1927_UTM_Zone_5N",                                             1 },	// NAD27 / UTM zone 5N
	{  26706L, 26706L, "UTM27-6",                    "NAD_1927_UTM_Zone_6N",                                             1 },	// NAD27 / UTM zone 6N
	{  26707L, 26707L, "UTM27-7",                    "NAD_1927_UTM_Zone_7N",                                             1 },	// NAD27 / UTM zone 7N
	{  26708L, 26708L, "UTM27-8",                    "NAD_1927_UTM_Zone_8N",                                             1 },	// NAD27 / UTM zone 8N
	{  26709L, 26709L, "UTM27-9",                    "NAD_1927_UTM_Zone_9N",                                             1 },	// NAD27 / UTM zone 9N
	{  26710L, 26710L, "UTM27-10",                   "NAD_1927_UTM_Zone_10N",                                            1 },	// NAD27 / UTM zone 10N
	{  26711L, 26711L, "UTM27-11",                   "NAD_1927_UTM_Zone_11N",                                            1 },	// NAD27 / UTM zone 11N
	{  26712L, 26712L, "UTM27-12",                   "NAD_1927_UTM_Zone_12N",                                            1 },	// NAD27 / UTM zone 12N
	{  26713L, 26713L, "UTM27-13",                   "NAD_1927_UTM_Zone_13N",                                            1 },	// NAD27 / UTM zone 13N
	{  26714L, 26714L, "UTM27-14",                   "NAD_1927_UTM_Zone_14N",                                            1 },	// NAD27 / UTM zone 14N
	{  26715L, 26715L, "UTM27-15",                   "NAD_1927_UTM_Zone_15N",                                            1 },	// NAD27 / UTM zone 15N
	{  26716L, 26716L, "UTM27-16",                   "NAD_1927_UTM_Zone_16N",                                            1 },	// NAD27 / UTM zone 16N
	{  26717L, 26717L, "UTM27-17",                   "NAD_1927_UTM_Zone_17N",                                            1 },	// NAD27 / UTM zone 17N
	{  26718L, 26718L, "UTM27-18",                   "NAD_1927_UTM_Zone_18N",                                            1 },	// NAD27 / UTM zone 18N
	{  26719L, 26719L, "UTM27-19",                   "NAD_1927_UTM_Zone_19N",                                            1 },	// NAD27 / UTM zone 19N
	{  26720L, 26720L, "UTM27-20",                   "NAD_1927_UTM_Zone_20N",                                            1 },	// NAD27 / UTM zone 20N
	{  26721L, 26721L, "UTM27-21",                   "NAD_1927_UTM_Zone_21N",                                            1 },	// NAD27 / UTM zone 21N
	{  26722L, 26722L, "UTM27-22",                   "NAD_1927_UTM_Zone_22N",                                            1 },	// NAD27 / UTM zone 22N
	{  26729L, 26729L, "AL-E",                       "NAD_1927_StatePlane_Alabama_East_FIPS_0101",                       1 },	// NAD27 / Alabama East
	{  26730L, 26730L, "AL-W",                       "NAD_1927_StatePlane_Alabama_West_FIPS_0102",                       1 },	// NAD27 / Alabama West
	{  26731L, 26731L, "AK-1",                       "NAD_1927_StatePlane_Alaska_1_FIPS_5001",                           1 },	// NAD27 / Alaska zone 1
	{  26732L, 26732L, "AK-2",                       "NAD_1927_StatePlane_Alaska_2_FIPS_5002",                           1 },	// NAD27 / Alaska zone 2
	{  26733L, 26733L, "AK-3",                       "NAD_1927_StatePlane_Alaska_3_FIPS_5003",                           1 },	// NAD27 / Alaska zone 3
	{  26734L, 26734L, "AK-4",                       "NAD_1927_StatePlane_Alaska_4_FIPS_5004",                           1 },	// NAD27 / Alaska zone 4
	{  26735L, 26735L, "AK-5",                       "NAD_1927_StatePlane_Alaska_5_FIPS_5005",                           1 },	// NAD27 / Alaska zone 5
	{  26736L, 26736L, "AK-6",                       "NAD_1927_StatePlane_Alaska_6_FIPS_5006",                           1 },	// NAD27 / Alaska zone 6
	{  26737L, 26737L, "AK-7",                       "NAD_1927_StatePlane_Alaska_7_FIPS_5007",                           1 },	// NAD27 / Alaska zone 7
	{  26738L, 26738L, "AK-8",                       "NAD_1927_StatePlane_Alaska_8_FIPS_5008",                           1 },	// NAD27 / Alaska zone 8
	{  26739L, 26739L, "AK-9",                       "NAD_1927_StatePlane_Alaska_9_FIPS_5009",                           1 },	// NAD27 / Alaska zone 9
	{  26740L, 26740L, "AK-10",                      "NAD_1927_StatePlane_Alaska_10_FIPS_5010",                          1 },	// NAD27 / Alaska zone 10
	{  26741L, 26741L, "CA-I",                       "NAD_1927_StatePlane_California_I_FIPS_0401",                       1 },	// NAD27 / California zone I
	{  26742L, 26742L, "CA-II",                      "NAD_1927_StatePlane_California_II_FIPS_0402",                      1 },	// NAD27 / California zone II
	{  26743L, 26743L, "CA-III",                     "NAD_1927_StatePlane_California_III_FIPS_0403",                     1 },	// NAD27 / California zone III
	{  26744L, 26744L, "CA-IV",                      "NAD_1927_StatePlane_California_IV_FIPS_0404",                      1 },	// NAD27 / California zone IV
	{  26745L, 26745L, "CA-V",                       "NAD_1927_StatePlane_California_V_FIPS_0405",                       1 },	// NAD27 / California zone V
	{  26746L, 26746L, "CA-VI",                      "NAD_1927_StatePlane_California_VI_FIPS_0406",                      1 },	// NAD27 / California zone VI
	{  26747L, 26747L, "CA-VII",                     "NAD_1927_StatePlane_California_VII_FIPS_0407",                     3 },	// NAD27 / California zone VII
	{  26748L, 26748L, "AZ-E",                       "NAD_1927_StatePlane_Arizona_East_FIPS_0201",                       1 },	// NAD27 / Arizona East
	{  26749L, 26749L, "AZ-C",                       "NAD_1927_StatePlane_Arizona_Central_FIPS_0202",                    1 },	// NAD27 / Arizona Central
	{  26750L, 26750L, "AZ-W",                       "NAD_1927_StatePlane_Arizona_West_FIPS_0203",                       1 },	// NAD27 / Arizona West
	{  26751L, 26751L, "AR-N",                       "NAD_1927_StatePlane_Arkansas_North_FIPS_0301",                     1 },	// NAD27 / Arkansas North
	{  26752L, 26752L, "AR-S",                       "NAD_1927_StatePlane_Arkansas_South_FIPS_0302",                     1 },	// NAD27 / Arkansas South
	{  26753L, 26753L, "CO-N",                       "NAD_1927_StatePlane_Colorado_North_FIPS_0501",                     1 },	// NAD27 / Colorado North
	{  26754L, 26754L, "CO-C",                       "NAD_1927_StatePlane_Colorado_Central_FIPS_0502",                   1 },	// NAD27 / Colorado Central
	{  26755L, 26755L, "CO-S",                       "NAD_1927_StatePlane_Colorado_South_FIPS_0503",                     1 },	// NAD27 / Colorado South
	{  26756L, 26756L, "CT",                         "NAD_1927_StatePlane_Connecticut_FIPS_0600",                        1 },	// NAD27 / Connecticut
	{  26757L, 26757L, "DE",                         "NAD_1927_StatePlane_Delaware_FIPS_0700",                           1 },	// NAD27 / Delaware
	{  26758L, 26758L, "FL-E",                       "NAD_1927_StatePlane_Florida_East_FIPS_0901",                       1 },	// NAD27 / Florida East
	{  26759L, 26759L, "FL-W",                       "NAD_1927_StatePlane_Florida_West_FIPS_0902",                       1 },	// NAD27 / Florida West
	{  26760L, 26760L, "FL-N",                       "NAD_1927_StatePlane_Florida_North_FIPS_0903",                      1 },	// NAD27 / Florida North
	{  26766L, 26766L, "GA-E",                       "NAD_1927_StatePlane_Georgia_East_FIPS_1001",                       1 },	// NAD27 / Georgia East
	{  26767L, 26767L, "GA-W",                       "NAD_1927_StatePlane_Georgia_West_FIPS_1002",                       1 },	// NAD27 / Georgia West
	{  26768L, 26768L, "ID-E",                       "NAD_1927_StatePlane_Idaho_East_FIPS_1101",                         1 },	// NAD27 / Idaho East
	{  26769L, 26769L, "ID-C",                       "NAD_1927_StatePlane_Idaho_Central_FIPS_1102",                      1 },	// NAD27 / Idaho Central
	{  26770L, 26770L, "ID-W",                       "NAD_1927_StatePlane_Idaho_West_FIPS_1103",                         1 },	// NAD27 / Idaho West
	{  26771L, 26771L, "IL-E",                       "NAD_1927_StatePlane_Illinois_East_FIPS_1201",                      1 },	// NAD27 / Illinois East
	{  26772L, 26772L, "IL-W",                       "NAD_1927_StatePlane_Illinois_West_FIPS_1202",                      1 },	// NAD27 / Illinois West
	{  26773L, 26773L, "IN-E",                       "NAD_1927_StatePlane_Indiana_East_FIPS_1301",                       1 },	// NAD27 / Indiana East
	{  26774L, 26774L, "IN-W",                       "NAD_1927_StatePlane_Indiana_West_FIPS_1302",                       1 },	// NAD27 / Indiana West
	{  26775L, 26775L, "IA-N",                       "NAD_1927_StatePlane_Iowa_North_FIPS_1401",                         1 },	// NAD27 / Iowa North
	{  26776L, 26776L, "IA-S",                       "NAD_1927_StatePlane_Iowa_South_FIPS_1402",                         1 },	// NAD27 / Iowa South
	{  26777L, 26777L, "KS-N",                       "NAD_1927_StatePlane_Kansas_North_FIPS_1501",                       1 },	// NAD27 / Kansas North
	{  26778L, 26778L, "KS-S",                       "NAD_1927_StatePlane_Kansas_South_FIPS_1502",                       1 },	// NAD27 / Kansas South
	{  26779L, 26779L, "KY-N",                       "NAD_1927_StatePlane_Kentucky_North_FIPS_1601",                     1 },	// NAD27 / Kentucky North
	{  26780L, 26780L, "KY-S",                       "NAD_1927_StatePlane_Kentucky_South_FIPS_1602",                     1 },	// NAD27 / Kentucky South
	{  26781L, 26781L, "LA-N",                       "NAD_1927_StatePlane_Louisiana_North_FIPS_1701",                    1 },	// NAD27 / Louisiana North
	{  26782L, 26782L, "LA-S",                       "NAD_1927_StatePlane_Louisiana_South_FIPS_1702",                    1 },	// NAD27 / Louisiana South
	{  26783L, 26783L, "ME-E",                       "NAD_1927_StatePlane_Maine_East_FIPS_1801",                         1 },	// NAD27 / Maine East
	{  26784L, 26784L, "ME-W",                       "NAD_1927_StatePlane_Maine_West_FIPS_1802",                         1 },	// NAD27 / Maine West
	{  26785L, 26785L, "MD",                         "NAD_1927_StatePlane_Maryland_FIPS_1900",                           1 },	// NAD27 / Maryland
	{  26786L, 26786L, "MA",                         "NAD_1927_StatePlane_Massachusetts_Mainland_FIPS_2001",             1 },	// NAD27 / Massachusetts Mainland
	{  26787L, 26787L, "MA27-IS",                    "NAD_1927_StatePlane_Massachusetts_Island_FIPS_2002",               1 },	// NAD27 / Massachusetts Island
	{  26791L, 26791L, "MN-N",                       "NAD_1927_StatePlane_Minnesota_North_FIPS_2201",                    1 },	// NAD27 / Minnesota North
	{  26792L, 26792L, "MN-C",                       "NAD_1927_StatePlane_Minnesota_Central_FIPS_2202",                  1 },	// NAD27 / Minnesota Central
	{  26793L, 26793L, "MN-S",                       "NAD_1927_StatePlane_Minnesota_South_FIPS_2203",                    1 },	// NAD27 / Minnesota South
	{  26794L, 26794L, "MS-E",                       "NAD_1927_StatePlane_Mississippi_East_FIPS_2301",                   1 },	// NAD27 / Mississippi East
	{  26795L, 26795L, "MS-W",                       "NAD_1927_StatePlane_Mississippi_West_FIPS_2302",                   1 },	// NAD27 / Mississippi West
	{  26796L, 26796L, "MO-E",                       "NAD_1927_StatePlane_Missouri_East_FIPS_2401",                      1 },	// NAD27 / Missouri East
	{  26797L, 26797L, "MO-C",                       "NAD_1927_StatePlane_Missouri_Central_FIPS_2402",                   1 },	// NAD27 / Missouri Central
	{  26798L, 26798L, "MO-W",                       "NAD_1927_StatePlane_Missouri_West_FIPS_2403",                      1 },	// NAD27 / Missouri West
	{  26747L, 26799L, "CA-VII",                     "NAD_1927_StatePlane_California_VII_FIPS_0407",                     1 },	// NAD27 / California zone VII
	{  26801L, 26801L, "MICHIGAN.East",              "NAD_Michigan_StatePlane_Michigan_East_Old_FIPS_2101",              0 },	// NAD Michigan / Michigan East
	{  26802L, 26802L, "MICHIGAN.OldCentral",        "NAD_Michigan_StatePlane_Michigan_Central_Old_FIPS_2102",           0 },	// NAD Michigan / Michigan Old Central
	{  26803L, 26803L, "MICHIGAN.West",              "NAD_Michigan_StatePlane_Michigan_West_Old_FIPS_2103",              0 },	// NAD Michigan / Michigan West
	{  26811L, 26811L, "MI27-N",                     "NAD_Michigan_StatePlane_Michigan_North_FIPS_2111",                 1 },	// NAD Michigan / Michigan North
	{  26812L, 26812L, "MI27-C",                     "NAD_Michigan_StatePlane_Michigan_Central_FIPS_2112",               1 },	// NAD Michigan / Michigan Central
	{  26813L, 26813L, "MI27-S",                     "NAD_Michigan_StatePlane_Michigan_South_FIPS_2113",                 1 },	// NAD Michigan / Michigan South
	{ 102128L, 26901L, "UTM83-1",                    "NAD_1983_UTM_Zone_1N",                                             1 },	// NAD83 / UTM zone 1N
	{ 102129L, 26902L, "UTM83-2",                    "NAD_1983_UTM_Zone_2N",                                             1 },	// NAD83 / UTM zone 2N
	{  26903L, 26903L, "UTM83-3",                    "NAD_1983_UTM_Zone_3N",                                             1 },	// NAD83 / UTM zone 3N
	{  26904L, 26904L, "UTM83-4",                    "NAD_1983_UTM_Zone_4N",                                             1 },	// NAD83 / UTM zone 4N
	{  26905L, 26905L, "UTM83-5",                    "NAD_1983_UTM_Zone_5N",                                             1 },	// NAD83 / UTM zone 5N
	{  26906L, 26906L, "UTM83-6",                    "NAD_1983_UTM_Zone_6N",                                             1 },	// NAD83 / UTM zone 6N
	{  26907L, 26907L, "UTM83-7",                    "NAD_1983_UTM_Zone_7N",                                             1 },	// NAD83 / UTM zone 7N
	{  26908L, 26908L, "UTM83-8",                    "NAD_1983_UTM_Zone_8N",                                             1 },	// NAD83 / UTM zone 8N
	{  26909L, 26909L, "UTM83-9",                    "NAD_1983_UTM_Zone_9N",                                             1 },	// NAD83 / UTM zone 9N
	{  26910L, 26910L, "UTM83-10",                   "NAD_1983_UTM_Zone_10N",                                            1 },	// NAD83 / UTM zone 10N
	{  26911L, 26911L, "UTM83-11",                   "NAD_1983_UTM_Zone_11N",                                            1 },	// NAD83 / UTM zone 11N
	{  26912L, 26912L, "UTM83-12",                   "NAD_1983_UTM_Zone_12N",                                            1 },	// NAD83 / UTM zone 12N
	{  26913L, 26913L, "UTM83-13",                   "NAD_1983_UTM_Zone_13N",                                            1 },	// NAD83 / UTM zone 13N
	{  26914L, 26914L, "UTM83-14",                   "NAD_1983_UTM_Zone_14N",                                            1 },	// NAD83 / UTM zone 14N
	{  26915L, 26915L, "UTM83-15",                   "NAD_1983_UTM_Zone_15N",                                            1 },	// NAD83 / UTM zone 15N
	{  26916L, 26916L, "UTM83-16",                   "NAD_1983_UTM_Zone_16N",                                            1 },	// NAD83 / UTM zone 16N
	{  26917L, 26917L, "UTM83-17",                   "NAD_1983_UTM_Zone_17N",                                            1 },	// NAD83 / UTM zone 17N
	{  26918L, 26918L, "UTM83-18",                   "NAD_1983_UTM_Zone_18N",                                            1 },	// NAD83 / UTM zone 18N
	{  26919L, 26919L, "UTM83-19",                   "NAD_1983_UTM_Zone_19N",                                            1 },	// NAD83 / UTM zone 19N
	{  26920L, 26920L, "UTM83-20",                   "NAD_1983_UTM_Zone_20N",                                            1 },	// NAD83 / UTM zone 20N
	{  26921L, 26921L, "UTM83-21",                   "NAD_1983_UTM_Zone_21N",                                            1 },	// NAD83 / UTM zone 21N
	{  26922L, 26922L, "UTM83-22",                   "NAD_1983_UTM_Zone_22N",                                            1 },	// NAD83 / UTM zone 22N
	{  26923L, 26923L, "NAD83.UTM-23N",              "NAD_1983_UTM_Zone_23N",                                            0 },	// NAD83 / UTM zone 23N
	{  26929L, 26929L, "AL83-E",                     "NAD_1983_StatePlane_Alabama_East_FIPS_0101",                       1 },	// NAD83 / Alabama East
	{  26930L, 26930L, "AL83-W",                     "NAD_1983_StatePlane_Alabama_West_FIPS_0102",                       1 },	// NAD83 / Alabama West
	{  26931L, 26931L, "AK83-1",                     "NAD_1983_StatePlane_Alaska_1_FIPS_5001",                           1 },	// NAD83 / Alaska zone 1
	{  26932L, 26932L, "AK83-2",                     "NAD_1983_StatePlane_Alaska_2_FIPS_5002",                           1 },	// NAD83 / Alaska zone 2
	{  26933L, 26933L, "AK83-3",                     "NAD_1983_StatePlane_Alaska_3_FIPS_5003",                           1 },	// NAD83 / Alaska zone 3
	{  26934L, 26934L, "AK83-4",                     "NAD_1983_StatePlane_Alaska_4_FIPS_5004",                           1 },	// NAD83 / Alaska zone 4
	{  26935L, 26935L, "AK83-5",                     "NAD_1983_StatePlane_Alaska_5_FIPS_5005",                           1 },	// NAD83 / Alaska zone 5
	{  26936L, 26936L, "AK83-6",                     "NAD_1983_StatePlane_Alaska_6_FIPS_5006",                           1 },	// NAD83 / Alaska zone 6
	{  26937L, 26937L, "AK83-7",                     "NAD_1983_StatePlane_Alaska_7_FIPS_5007",                           1 },	// NAD83 / Alaska zone 7
	{  26938L, 26938L, "AK83-8",                     "NAD_1983_StatePlane_Alaska_8_FIPS_5008",                           1 },	// NAD83 / Alaska zone 8
	{  26939L, 26939L, "AK83-9",                     "NAD_1983_StatePlane_Alaska_9_FIPS_5009",                           1 },	// NAD83 / Alaska zone 9
	{  26940L, 26940L, "AK83-10",                    "NAD_1983_StatePlane_Alaska_10_FIPS_5010",                          1 },	// NAD83 / Alaska zone 10
	{  26941L, 26941L, "CA83-I",                     "NAD_1983_StatePlane_California_I_FIPS_0401",                       1 },	// NAD83 / California zone 1
	{  26942L, 26942L, "CA83-II",                    "NAD_1983_StatePlane_California_II_FIPS_0402",                      1 },	// NAD83 / California zone 2
	{  26943L, 26943L, "CA83-III",                   "NAD_1983_StatePlane_California_III_FIPS_0403",                     1 },	// NAD83 / California zone 3
	{  26944L, 26944L, "CA83-IV",                    "NAD_1983_StatePlane_California_IV_FIPS_0404",                      1 },	// NAD83 / California zone 4
	{  26945L, 26945L, "CA83-V",                     "NAD_1983_StatePlane_California_V_FIPS_0405",                       1 },	// NAD83 / California zone 5
	{  26946L, 26946L, "CA83-VI",                    "NAD_1983_StatePlane_California_VI_FIPS_0406",                      1 },	// NAD83 / California zone 6
	{  26948L, 26948L, "AZ83-E",                     "NAD_1983_StatePlane_Arizona_East_FIPS_0201",                       1 },	// NAD83 / Arizona East
	{  26949L, 26949L, "AZ83-C",                     "NAD_1983_StatePlane_Arizona_Central_FIPS_0202",                    1 },	// NAD83 / Arizona Central
	{  26950L, 26950L, "AZ83-W",                     "NAD_1983_StatePlane_Arizona_West_FIPS_0203",                       1 },	// NAD83 / Arizona West
	{  26951L, 26951L, "AR83-N",                     "NAD_1983_StatePlane_Arkansas_North_FIPS_0301",                     1 },	// NAD83 / Arkansas North
	{  26952L, 26952L, "AR83-S",                     "NAD_1983_StatePlane_Arkansas_South_FIPS_0302",                     1 },	// NAD83 / Arkansas South
	{  26953L, 26953L, "CO83-N",                     "NAD_1983_StatePlane_Colorado_North_FIPS_0501",                     1 },	// NAD83 / Colorado North
	{  26954L, 26954L, "CO83-C",                     "NAD_1983_StatePlane_Colorado_Central_FIPS_0502",                   1 },	// NAD83 / Colorado Central
	{  26955L, 26955L, "CO83-S",                     "NAD_1983_StatePlane_Colorado_South_FIPS_0503",                     1 },	// NAD83 / Colorado South
	{  26956L, 26956L, "CT83",                       "NAD_1983_StatePlane_Connecticut_FIPS_0600",                        1 },	// NAD83 / Connecticut
	{  26957L, 26957L, "DE83",                       "NAD_1983_StatePlane_Delaware_FIPS_0700",                           1 },	// NAD83 / Delaware
	{  26958L, 26958L, "FL83-E",                     "NAD_1983_StatePlane_Florida_East_FIPS_0901",                       1 },	// NAD83 / Florida East
	{  26959L, 26959L, "FL83-W",                     "NAD_1983_StatePlane_Florida_West_FIPS_0902",                       1 },	// NAD83 / Florida West
	{  26960L, 26960L, "FL83-N",                     "NAD_1983_StatePlane_Florida_North_FIPS_0903",                      1 },	// NAD83 / Florida North
	{  26961L, 26961L, "HI83-1",                     "NAD_1983_StatePlane_Hawaii_1_FIPS_5101",                           1 },	// NAD83 / Hawaii zone 1
	{  26962L, 26962L, "HI83-2",                     "NAD_1983_StatePlane_Hawaii_2_FIPS_5102",                           1 },	// NAD83 / Hawaii zone 2
	{  26963L, 26963L, "HI83-3",                     "NAD_1983_StatePlane_Hawaii_3_FIPS_5103",                           1 },	// NAD83 / Hawaii zone 3
	{  26964L, 26964L, "HI83-4",                     "NAD_1983_StatePlane_Hawaii_4_FIPS_5104",                           1 },	// NAD83 / Hawaii zone 4
	{  26965L, 26965L, "HI83-5",                     "NAD_1983_StatePlane_Hawaii_5_FIPS_5105",                           1 },	// NAD83 / Hawaii zone 5
	{  26966L, 26966L, "GA83-E",                     "NAD_1983_StatePlane_Georgia_East_FIPS_1001",                       1 },	// NAD83 / Georgia East
	{  26967L, 26967L, "GA83-W",                     "NAD_1983_StatePlane_Georgia_West_FIPS_1002",                       1 },	// NAD83 / Georgia West
	{  26968L, 26968L, "ID83-E",                     "NAD_1983_StatePlane_Idaho_East_FIPS_1101",                         1 },	// NAD83 / Idaho East
	{  26969L, 26969L, "ID83-C",                     "NAD_1983_StatePlane_Idaho_Central_FIPS_1102",                      1 },	// NAD83 / Idaho Central
	{  26970L, 26970L, "ID83-W",                     "NAD_1983_StatePlane_Idaho_West_FIPS_1103",                         1 },	// NAD83 / Idaho West
	{  26971L, 26971L, "IL83-E",                     "NAD_1983_StatePlane_Illinois_East_FIPS_1201",                      1 },	// NAD83 / Illinois East
	{  26972L, 26972L, "IL83-W",                     "NAD_1983_StatePlane_Illinois_West_FIPS_1202",                      1 },	// NAD83 / Illinois West
	{  26973L, 26973L, "IN83-E",                     "NAD_1983_StatePlane_Indiana_East_FIPS_1301",                       1 },	// NAD83 / Indiana East
	{  26974L, 26974L, "IN83-W",                     "NAD_1983_StatePlane_Indiana_West_FIPS_1302",                       1 },	// NAD83 / Indiana West
	{  26975L, 26975L, "IA83-N",                     "NAD_1983_StatePlane_Iowa_North_FIPS_1401",                         1 },	// NAD83 / Iowa North
	{  26976L, 26976L, "IA83-S",                     "NAD_1983_StatePlane_Iowa_South_FIPS_1402",                         1 },	// NAD83 / Iowa South
	{  26977L, 26977L, "KS83-N",                     "NAD_1983_StatePlane_Kansas_North_FIPS_1501",                       1 },	// NAD83 / Kansas North
	{  26978L, 26978L, "KS83-S",                     "NAD_1983_StatePlane_Kansas_South_FIPS_1502",                       1 },	// NAD83 / Kansas South
	{  26979L, 26979L, "KY83-N",                     "NAD_1983_StatePlane_Kentucky_North_FIPS_1601",                     3 },	// NAD83 / Kentucky North
	{  26980L, 26980L, "KY83-S",                     "NAD_1983_StatePlane_Kentucky_South_FIPS_1602",                     1 },	// NAD83 / Kentucky South
	{  26981L, 26981L, "LA83-N",                     "NAD_1983_StatePlane_Louisiana_North_FIPS_1701",                    1 },	// NAD83 / Louisiana North
	{  26982L, 26982L, "LA83-S",                     "NAD_1983_StatePlane_Louisiana_South_FIPS_1702",                    1 },	// NAD83 / Louisiana South
	{  26983L, 26983L, "ME83-E",                     "NAD_1983_StatePlane_Maine_East_FIPS_1801",                         1 },	// NAD83 / Maine East
	{  26984L, 26984L, "ME83-W",                     "NAD_1983_StatePlane_Maine_West_FIPS_1802",                         1 },	// NAD83 / Maine West
	{  26985L, 26985L, "MD83",                       "NAD_1983_StatePlane_Maryland_FIPS_1900",                           1 },	// NAD83 / Maryland
	{  26986L, 26986L, "MA83",                       "NAD_1983_StatePlane_Massachusetts_Mainland_FIPS_2001",             1 },	// NAD83 / Massachusetts Mainland
	{  26987L, 26987L, "MA83-IS",                    "NAD_1983_StatePlane_Massachusetts_Island_FIPS_2002",               1 },	// NAD83 / Massachusetts Island
	{  26988L, 26988L, "MI83-N",                     "NAD_1983_StatePlane_Michigan_North_FIPS_2111",                     1 },	// NAD83 / Michigan North
	{  26989L, 26989L, "MI83-C",                     "NAD_1983_StatePlane_Michigan_Central_FIPS_2112",                   1 },	// NAD83 / Michigan Central
	{  26990L, 26990L, "MI83-S",                     "NAD_1983_StatePlane_Michigan_South_FIPS_2113",                     1 },	// NAD83 / Michigan South
	{  26991L, 26991L, "MN83-N",                     "NAD_1983_StatePlane_Minnesota_North_FIPS_2201",                    1 },	// NAD83 / Minnesota North
	{  26992L, 26992L, "MN83-C",                     "NAD_1983_StatePlane_Minnesota_Central_FIPS_2202",                  1 },	// NAD83 / Minnesota Central
	{  26993L, 26993L, "MN83-S",                     "NAD_1983_StatePlane_Minnesota_South_FIPS_2203",                    1 },	// NAD83 / Minnesota South
	{  26994L, 26994L, "MS83-E",                     "NAD_1983_StatePlane_Mississippi_East_FIPS_2301",                   1 },	// NAD83 / Mississippi East
	{  26995L, 26995L, "MS83-W",                     "NAD_1983_StatePlane_Mississippi_West_FIPS_2302",                   1 },	// NAD83 / Mississippi West
	{  26996L, 26996L, "MO83-E",                     "NAD_1983_StatePlane_Missouri_East_FIPS_2401",                      1 },	// NAD83 / Missouri East
	{  26997L, 26997L, "MO83-C",                     "NAD_1983_StatePlane_Missouri_Central_FIPS_2402",                   1 },	// NAD83 / Missouri Central
	{  26998L, 26998L, "MO83-W",                     "NAD_1983_StatePlane_Missouri_West_FIPS_2403",                      1 },	// NAD83 / Missouri West
	{  27038L, 27038L, "Nahrwan67.UTM-38N",          "Nahrwan_1967_UTM_Zone_38N",                                        0 },	// Nahrwan 1967 / UTM zone 38N
	{  27039L, 27039L, "Nahrwan67.UTM-39N",          "Nahrwan_1967_UTM_Zone_39N",                                        0 },	// Nahrwan 1967 / UTM zone 39N
	{  27040L, 27040L, "Nahrwan67.UTM-40N",          "Nahrwan_1967_UTM_Zone_40N",                                        0 },	// Nahrwan 1967 / UTM zone 40N
	{  27120L, 27120L, "Naparima72.UTM-20N",         "Naparima_1972_UTM_Zone_20N",                                       0 },	// Naparima 1972 / UTM zone 20N
	{  27200L, 27200L, "NZGD49.NewZealandGrid",      "GD_1949_New_Zealand_Map_Grid",                                     1 },	// NZGD49 / New Zealand Map Grid
	{  27205L, 27205L, "NZGD49.MountEden",           "NZGD_1949_Mount_Eden_Circuit",                                     0 },	// NZGD49 / Mount Eden Circuit
	{  27206L, 27206L, "NZGD49.BayOfPlenty",         "NZGD_1949_Bay_of_Plenty_Circuit",                                  0 },	// NZGD49 / Bay of Plenty Circuit
	{  27207L, 27207L, "NZGD49.PovertyBay",          "NZGD_1949_Poverty_Bay_Circuit",                                    0 },	// NZGD49 / Poverty Bay Circuit
	{  27208L, 27208L, "NZGD49.HawkesBay",           "NZGD_1949_Hawkes_Bay_Circuit",                                     0 },	// NZGD49 / Hawkes Bay Circuit
	{  27209L, 27209L, "NZGD49.Taranaki",            "NZGD_1949_Taranaki_Circuit",                                       0 },	// NZGD49 / Taranaki Circuit
	{  27210L, 27210L, "NZGD49.Tuhirangi",           "NZGD_1949_Tuhirangi_Circuit",                                      0 },	// NZGD49 / Tuhirangi Circuit
	{  27211L, 27211L, "NZGD49.Wanganui",            "NZGD_1949_Wanganui_Circuit",                                       0 },	// NZGD49 / Wanganui Circuit
	{  27212L, 27212L, "NZGD49.Wairarapa",           "NZGD_1949_Wairarapa_Circuit",                                      0 },	// NZGD49 / Wairarapa Circuit
	{  27213L, 27213L, "NZGD49.Wellington",          "NZGD_1949_Wellington_Circuit",                                     0 },	// NZGD49 / Wellington Circuit
	{  27214L, 27214L, "NZGD49.Collingwood",         "NZGD_1949_Collingwood_Circuit",                                    0 },	// NZGD49 / Collingwood Circuit
	{  27215L, 27215L, "NZGD49.Nelson",              "NZGD_1949_Nelson_Circuit",                                         0 },	// NZGD49 / Nelson Circuit
	{  27216L, 27216L, "NZGD49.Karamea",             "NZGD_1949_Karamea_Circuit",                                        0 },	// NZGD49 / Karamea Circuit
	{  27217L, 27217L, "NZGD49.Buller",              "NZGD_1949_Buller_Circuit",                                         0 },	// NZGD49 / Buller Circuit
	{  27218L, 27218L, "NZGD49.Grey",                "NZGD_1949_Grey_Circuit",                                           0 },	// NZGD49 / Grey Circuit
	{  27219L, 27219L, "NZGD49.Amuri",               "NZGD_1949_Amuri_Circuit",                                          0 },	// NZGD49 / Amuri Circuit
	{  27220L, 27220L, "NZGD49.Marlborough",         "NZGD_1949_Marlborough_Circuit",                                    0 },	// NZGD49 / Marlborough Circuit
	{  27221L, 27221L, "NZGD49.Hokitika",            "NZGD_1949_Hokitika_Circuit",                                       0 },	// NZGD49 / Hokitika Circuit
	{  27222L, 27222L, "NZGD49.Okarito",             "NZGD_1949_Okarito_Circuit",                                        0 },	// NZGD49 / Okarito Circuit
	{  27223L, 27223L, "NZGD49.JacksonsBay",         "NZGD_1949_Jacksons_Bay_Circuit",                                   0 },	// NZGD49 / Jacksons Bay Circuit
	{  27224L, 27224L, "NZGD49.MountPleasant",       "NZGD_1949_Mount_Pleasant_Circuit",                                 0 },	// NZGD49 / Mount Pleasant Circuit
	{  27225L, 27225L, "NZGD49.Gawler",              "NZGD_1949_Gawler_Circuit",                                         0 },	// NZGD49 / Gawler Circuit
	{  27226L, 27226L, "NZGD49.Timaru",              "NZGD_1949_Timaru_Circuit",                                         0 },	// NZGD49 / Timaru Circuit
	{  27227L, 27227L, "NZGD49.LindisPeak",          "NZGD_1949_Lindis_Peak_Circuit",                                    0 },	// NZGD49 / Lindis Peak Circuit
	{  27228L, 27228L, "NZGD49.MountNicholas",       "NZGD_1949_Mount_Nicholas_Circuit",                                 0 },	// NZGD49 / Mount Nicholas Circuit
	{  27229L, 27229L, "NZGD49.MountYork",           "NZGD_1949_Mount_York_Circuit",                                     0 },	// NZGD49 / Mount York Circuit
	{  27230L, 27230L, "NZGD49.ObservationPnt",      "NZGD_1949_Observation_Point_Circuit",                              0 },	// NZGD49 / Observation Point Circuit
	{  27231L, 27231L, "NZGD49.NorthTaieri",         "NZGD_1949_North_Taieri_Circuit",                                   0 },	// NZGD49 / North Taieri Circuit
	{  27232L, 27232L, "NZGD49.Bluff",               "NZGD_1949_Bluff_Circuit",                                          0 },	// NZGD49 / Bluff Circuit
	{  27258L, 27258L, "NZGD49.UTM-58S",             "NZGD_1949_UTM_Zone_58S",                                           0 },	// NZGD49 / UTM zone 58S
	{  27259L, 27259L, "NZGD49.UTM-59S",             "NZGD_1949_UTM_Zone_59S",                                           0 },	// NZGD49 / UTM zone 59S
	{  27260L, 27260L, "NZGD49.UTM-60S",             "NZGD_1949_UTM_Zone_60S",                                           0 },	// NZGD49 / UTM zone 60S
	{  27291L, 27291L, "NZGD49.NorthIslandGrid",     "New_Zealand_North_Island",                                         0 },	// NZGD49 / North Island Grid
	{  27292L, 27292L, "NZGD49.SouthIslandGrid",     "New_Zealand_South_Island",                                         0 },	// NZGD49 / South Island Grid
	{  27429L, 27429L, "Datum73.UTM-29N",            "Datum_73_UTM_Zone_29N",                                            0 },	// Datum 73 / UTM zone 29N
	{  27700L, 27700L, "BritishNatGrid",             "British_National_Grid",                                            1 },	// OSGB 1936 / British National Grid
	{  28191L, 28191L, "Palestine23.Grid",           "Palestine_1923_Palestine_Grid",                                    0 },	// Palestine 1923 / Palestine Grid
	{  28192L, 28192L, "Palestine23.Belt",           "Palestine_1923_Palestine_Belt",                                    0 },	// Palestine 1923 / Palestine Belt
	{  28193L, 28193L, "Palestine23.IsraeliGrd",     "Palestine_1923_Israel_CS_Grid",                                    0 },	// Palestine 1923 / Israeli CS Grid
	{  28232L, 28232L, "PointeNoire.UTM-32S",        "Pointe_Noire_UTM_Zone_32S",                                        0 },	// Pointe Noire / UTM zone 32S
	{  28348L, 28348L, "MGA94-48",                   "GDA_1994_MGA_Zone_48",                                             1 },	// GDA94 / MGA zone 48
	{  28349L, 28349L, "MGA94-49",                   "GDA_1994_MGA_Zone_49",                                             1 },	// GDA94 / MGA zone 49
	{  28350L, 28350L, "MGA94-50",                   "GDA_1994_MGA_Zone_50",                                             1 },	// GDA94 / MGA zone 50
	{  28351L, 28351L, "MGA94-51",                   "GDA_1994_MGA_Zone_51",                                             1 },	// GDA94 / MGA zone 51
	{  28352L, 28352L, "MGA94-52",                   "GDA_1994_MGA_Zone_52",                                             1 },	// GDA94 / MGA zone 52
	{  28353L, 28353L, "MGA94-53",                   "GDA_1994_MGA_Zone_53",                                             1 },	// GDA94 / MGA zone 53
	{  28354L, 28354L, "MGA94-54",                   "GDA_1994_MGA_Zone_54",                                             1 },	// GDA94 / MGA zone 54
	{  28355L, 28355L, "MGA94-55",                   "GDA_1994_MGA_Zone_55",                                             1 },	// GDA94 / MGA zone 55
	{  28356L, 28356L, "MGA94-56",                   "GDA_1994_MGA_Zone_56",                                             1 },	// GDA94 / MGA zone 56
	{  28357L, 28357L, "MGA94-57",                   "GDA_1994_MGA_Zone_57",                                             1 },	// GDA94 / MGA zone 57
	{  28358L, 28358L, "MGA94-58",                   "GDA_1994_MGA_Zone_58",                                             1 },	// GDA94 / MGA zone 58
	{  28402L, 28402L, "Pulkovo42.GK-2",             "Pulkovo_1942_GK_Zone_2",                                           0 },	// Pulkovo 1942 / Gauss-Kruger zone 2
	{  28403L, 28403L, "Pulkovo42.GK-3",             "Pulkovo_1942_GK_Zone_3",                                           0 },	// Pulkovo 1942 / Gauss-Kruger zone 3
	{  28404L, 28404L, "GK42-4",                     "Pulkovo_1942_GK_Zone_4",                                           1 },	// Pulkovo 1942 / Gauss-Kruger zone 4
	{  28405L, 28405L, "GK42-5",                     "Pulkovo_1942_GK_Zone_5",                                           1 },	// Pulkovo 1942 / Gauss-Kruger zone 5
	{  28406L, 28406L, "GK42-6",                     "Pulkovo_1942_GK_Zone_6",                                           1 },	// Pulkovo 1942 / Gauss-Kruger zone 6
	{  28407L, 28407L, "GK42-7",                     "Pulkovo_1942_GK_Zone_7",                                           1 },	// Pulkovo 1942 / Gauss-Kruger zone 7
	{  28408L, 28408L, "GK42-8",                     "Pulkovo_1942_GK_Zone_8",                                           1 },	// Pulkovo 1942 / Gauss-Kruger zone 8
	{  28409L, 28409L, "GK42-9",                     "Pulkovo_1942_GK_Zone_9",                                           1 },	// Pulkovo 1942 / Gauss-Kruger zone 9
	{  28410L, 28410L, "GK42-10",                    "Pulkovo_1942_GK_Zone_10",                                          1 },	// Pulkovo 1942 / Gauss-Kruger zone 10
	{  28411L, 28411L, "GK42-11",                    "Pulkovo_1942_GK_Zone_11",                                          1 },	// Pulkovo 1942 / Gauss-Kruger zone 11
	{  28412L, 28412L, "GK42-12",                    "Pulkovo_1942_GK_Zone_12",                                          1 },	// Pulkovo 1942 / Gauss-Kruger zone 12
	{  28413L, 28413L, "GK42-13",                    "Pulkovo_1942_GK_Zone_13",                                          1 },	// Pulkovo 1942 / Gauss-Kruger zone 13
	{  28414L, 28414L, "GK42-14",                    "Pulkovo_1942_GK_Zone_14",                                          1 },	// Pulkovo 1942 / Gauss-Kruger zone 14
	{  28415L, 28415L, "GK42-15",                    "Pulkovo_1942_GK_Zone_15",                                          1 },	// Pulkovo 1942 / Gauss-Kruger zone 15
	{  28416L, 28416L, "GK42-16",                    "Pulkovo_1942_GK_Zone_16",                                          1 },	// Pulkovo 1942 / Gauss-Kruger zone 16
	{  28417L, 28417L, "GK42-17",                    "Pulkovo_1942_GK_Zone_17",                                          1 },	// Pulkovo 1942 / Gauss-Kruger zone 17
	{  28418L, 28418L, "GK42-18",                    "Pulkovo_1942_GK_Zone_18",                                          1 },	// Pulkovo 1942 / Gauss-Kruger zone 18
	{  28419L, 28419L, "GK42-19",                    "Pulkovo_1942_GK_Zone_19",                                          1 },	// Pulkovo 1942 / Gauss-Kruger zone 19
	{  28420L, 28420L, "GK42-20",                    "Pulkovo_1942_GK_Zone_20",                                          1 },	// Pulkovo 1942 / Gauss-Kruger zone 20
	{  28421L, 28421L, "GK42-21",                    "Pulkovo_1942_GK_Zone_21",                                          1 },	// Pulkovo 1942 / Gauss-Kruger zone 21
	{  28422L, 28422L, "GK42-22",                    "Pulkovo_1942_GK_Zone_22",                                          1 },	// Pulkovo 1942 / Gauss-Kruger zone 22
	{  28423L, 28423L, "GK42-23",                    "Pulkovo_1942_GK_Zone_23",                                          1 },	// Pulkovo 1942 / Gauss-Kruger zone 23
	{  28424L, 28424L, "GK42-24",                    "Pulkovo_1942_GK_Zone_24",                                          1 },	// Pulkovo 1942 / Gauss-Kruger zone 24
	{  28425L, 28425L, "GK42-25",                    "Pulkovo_1942_GK_Zone_25",                                          1 },	// Pulkovo 1942 / Gauss-Kruger zone 25
	{  28426L, 28426L, "GK42-26",                    "Pulkovo_1942_GK_Zone_26",                                          1 },	// Pulkovo 1942 / Gauss-Kruger zone 26
	{  28427L, 28427L, "GK42-27",                    "Pulkovo_1942_GK_Zone_27",                                          1 },	// Pulkovo 1942 / Gauss-Kruger zone 27
	{  28428L, 28428L, "GK42-28",                    "Pulkovo_1942_GK_Zone_28",                                          1 },	// Pulkovo 1942 / Gauss-Kruger zone 28
	{  28429L, 28429L, "GK42-29",                    "Pulkovo_1942_GK_Zone_29",                                          1 },	// Pulkovo 1942 / Gauss-Kruger zone 29
	{  28430L, 28430L, "GK42-30",                    "Pulkovo_1942_GK_Zone_30",                                          1 },	// Pulkovo 1942 / Gauss-Kruger zone 30
	{  28431L, 28431L, "GK42-31",                    "Pulkovo_1942_GK_Zone_31",                                          1 },	// Pulkovo 1942 / Gauss-Kruger zone 31
	{  28432L, 28432L, "GK42-32",                    "Pulkovo_1942_GK_Zone_32",                                          1 },	// Pulkovo 1942 / Gauss-Kruger zone 32
	{  28462L, 28462L, "Pulkovo42.GK-2N",            "Pulkovo_1942_GK_Zone_2N",                                          2 },	// Pulkovo 1942 / Gauss-Kruger 2N
	{  28463L, 28463L, "Pulkovo42.GK-3N",            "Pulkovo_1942_GK_Zone_3N",                                          2 },	// Pulkovo 1942 / Gauss-Kruger 3N
	{  28464L, 28464L, "GK42-4N",                    "Pulkovo_1942_GK_Zone_4N",                                          3 },	// Pulkovo 1942 / Gauss-Kruger 4N
	{  28465L, 28465L, "GK42-5N",                    "Pulkovo_1942_GK_Zone_5N",                                          3 },	// Pulkovo 1942 / Gauss-Kruger 5N
	{  28466L, 28466L, "GK42-6N",                    "Pulkovo_1942_GK_Zone_6N",                                          3 },	// Pulkovo 1942 / Gauss-Kruger 6N
	{  28467L, 28467L, "GK42-7N",                    "Pulkovo_1942_GK_Zone_7N",                                          3 },	// Pulkovo 1942 / Gauss-Kruger 7N
	{  28468L, 28468L, "GK42-8N",                    "Pulkovo_1942_GK_Zone_8N",                                          3 },	// Pulkovo 1942 / Gauss-Kruger 8N
	{  28469L, 28469L, "GK42-9N",                    "Pulkovo_1942_GK_Zone_9N",                                          3 },	// Pulkovo 1942 / Gauss-Kruger 9N
	{  28470L, 28470L, "GK42-10N",                   "Pulkovo_1942_GK_Zone_10N",                                         3 },	// Pulkovo 1942 / Gauss-Kruger 10N
	{  28471L, 28471L, "GK42-11N",                   "Pulkovo_1942_GK_Zone_11N",                                         3 },	// Pulkovo 1942 / Gauss-Kruger 11N
	{  28472L, 28472L, "GK42-12N",                   "Pulkovo_1942_GK_Zone_12N",                                         3 },	// Pulkovo 1942 / Gauss-Kruger 12N
	{  28473L, 28473L, "GK42-13N",                   "Pulkovo_1942_GK_Zone_13N",                                         3 },	// Pulkovo 1942 / Gauss-Kruger 13N
	{  28474L, 28474L, "GK42-14N",                   "Pulkovo_1942_GK_Zone_14N",                                         3 },	// Pulkovo 1942 / Gauss-Kruger 14N
	{  28475L, 28475L, "GK42-15N",                   "Pulkovo_1942_GK_Zone_15N",                                         3 },	// Pulkovo 1942 / Gauss-Kruger 15N
	{  28476L, 28476L, "GK42-16N",                   "Pulkovo_1942_GK_Zone_16N",                                         3 },	// Pulkovo 1942 / Gauss-Kruger 16N
	{  28477L, 28477L, "GK42-17N",                   "Pulkovo_1942_GK_Zone_17N",                                         3 },	// Pulkovo 1942 / Gauss-Kruger 17N
	{  28478L, 28478L, "GK42-18N",                   "Pulkovo_1942_GK_Zone_18N",                                         3 },	// Pulkovo 1942 / Gauss-Kruger 18N
	{  28479L, 28479L, "GK42-19N",                   "Pulkovo_1942_GK_Zone_19N",                                         3 },	// Pulkovo 1942 / Gauss-Kruger 19N
	{  28480L, 28480L, "GK42-20N",                   "Pulkovo_1942_GK_Zone_20N",                                         3 },	// Pulkovo 1942 / Gauss-Kruger 20N
	{  28481L, 28481L, "GK42-21N",                   "Pulkovo_1942_GK_Zone_21N",                                         3 },	// Pulkovo 1942 / Gauss-Kruger 21N
	{  28482L, 28482L, "GK42-22N",                   "Pulkovo_1942_GK_Zone_22N",                                         3 },	// Pulkovo 1942 / Gauss-Kruger 22N
	{  28483L, 28483L, "GK42-23N",                   "Pulkovo_1942_GK_Zone_23N",                                         3 },	// Pulkovo 1942 / Gauss-Kruger 23N
	{  28484L, 28484L, "GK42-24N",                   "Pulkovo_1942_GK_Zone_24N",                                         3 },	// Pulkovo 1942 / Gauss-Kruger 24N
	{  28485L, 28485L, "GK42-25N",                   "Pulkovo_1942_GK_Zone_25N",                                         3 },	// Pulkovo 1942 / Gauss-Kruger 25N
	{  28486L, 28486L, "GK42-26N",                   "Pulkovo_1942_GK_Zone_26N",                                         3 },	// Pulkovo 1942 / Gauss-Kruger 26N
	{  28487L, 28487L, "GK42-27N",                   "Pulkovo_1942_GK_Zone_27N",                                         3 },	// Pulkovo 1942 / Gauss-Kruger 27N
	{  28488L, 28488L, "GK42-28N",                   "Pulkovo_1942_GK_Zone_28N",                                         3 },	// Pulkovo 1942 / Gauss-Kruger 28N
	{  28489L, 28489L, "GK42-29N",                   "Pulkovo_1942_GK_Zone_29N",                                         3 },	// Pulkovo 1942 / Gauss-Kruger 29N
	{  28490L, 28490L, "GK42-30N",                   "Pulkovo_1942_GK_Zone_30N",                                         3 },	// Pulkovo 1942 / Gauss-Kruger 30N
	{  28491L, 28491L, "GK42-31N",                   "Pulkovo_1942_GK_Zone_31N",                                         3 },	// Pulkovo 1942 / Gauss-Kruger 31N
	{  28492L, 28492L, "GK42-32N",                   "Pulkovo_1942_GK_Zone_32N",                                         3 },	// Pulkovo 1942 / Gauss-Kruger 32N
	{  28600L, 28600L, "Qatar74.NationalGrid",       "Qatar_National_Grid",                                              0 },	// Qatar 1974 / Qatar National Grid
	{  28991L, 28991L, "Netherlands-RD-Old",         "RD_Old",                                                           1 },	// Amersfoort / RD Old
	{  28992L, 28992L, "Netherlands-RD-New",         "RD_New",                                                           1 },	// Amersfoort / RD New
	{  29100L, 29101L, "SAD69.BzPolyconic",          "SAD_1969_Brazil_Polyconic",                                        0 },	// SAD69 / Brazil Polyconic
	{  29118L, 29168L, "SAD69.UTM-18N",              "SAD_1969_UTM_Zone_18N",                                            0 },	// SAD69 / UTM zone 18N
	{  29119L, 29169L, "SAD69.UTM-19N",              "SAD_1969_UTM_Zone_19N",                                            0 },	// SAD69 / UTM zone 19N
	{  29120L, 29170L, "SAD69.UTM-20N",              "SAD_1969_UTM_Zone_20N",                                            0 },	// SAD69 / UTM zone 20N
	{  29121L, 29171L, "SAD69.UTM-21N",              "SAD_1969_UTM_Zone_21N",                                            0 },	// SAD69 / UTM zone 21N
	{  29122L, 29172L, "SAD69.UTM-22N",              "SAD_1969_UTM_Zone_22N",                                            0 },	// SAD69 / UTM zone 22N
	{  29177L, 29187L, "SAD69.UTM-17S",              "SAD_1969_UTM_Zone_17S",                                            0 },	// SAD69 / UTM zone 17S
	{  29178L, 29188L, "SAD69.UTM-18S",              "SAD_1969_UTM_Zone_18S",                                            0 },	// SAD69 / UTM zone 18S
	{  29179L, 29189L, "SAD69.UTM-19S",              "SAD_1969_UTM_Zone_19S",                                            0 },	// SAD69 / UTM zone 19S
	{  29180L, 29190L, "SAD69.UTM-20S",              "SAD_1969_UTM_Zone_20S",                                            0 },	// SAD69 / UTM zone 20S
	{  29181L, 29191L, "SAD69.UTM-21S",              "SAD_1969_UTM_Zone_21S",                                            0 },	// SAD69 / UTM zone 21S
	{  29182L, 29192L, "SAD69.UTM-22S",              "SAD_1969_UTM_Zone_22S",                                            0 },	// SAD69 / UTM zone 22S
	{  29183L, 29193L, "SAD69.UTM-23S",              "SAD_1969_UTM_Zone_23S",                                            0 },	// SAD69 / UTM zone 23S
	{  29184L, 29194L, "SAD69.UTM-24S",              "SAD_1969_UTM_Zone_24S",                                            0 },	// SAD69 / UTM zone 24S
	{  29185L, 29195L, "SAD69.UTM-25S",              "SAD_1969_UTM_Zone_25S",                                            0 },	// SAD69 / UTM zone 25S
	{  29220L, 29220L, "Sapper.UTM-20S",             "Sapper_Hill_1943_UTM_Zone_20S",                                    0 },	// Sapper Hill 1943 / UTM zone 20S
	{  29221L, 29221L, "Sapper.UTM-21S",             "Sapper_Hill_1943_UTM_Zone_21S",                                    0 },	// Sapper Hill 1943 / UTM zone 21S
	{  29333L, 29333L, "Schwarzk.UTM-33S",           "Schwarzeck_UTM_Zone_33S",                                          0 },	// Schwarzeck / UTM zone 33S
	{  29738L, 29738L, "Tananarive.UTM-38S",         "Tananarive_1925_UTM_Zone_38S",                                     0 },	// Tananarive / UTM zone 38S
	{  29739L, 29739L, "Tananarive.UTM-39S",         "Tananarive_1925_UTM_Zone_39S",                                     0 },	// Tananarive / UTM zone 39S
	{  29849L, 29849L, "TMBLI-B.UTM-49N",            "Timbalai_1948_UTM_Zone_49N",                                       0 },	// Timbalai 1948 / UTM zone 49N
	{  29850L, 29850L, "TMBLI-B.UTM-50N",            "Timbalai_1948_UTM_Zone_50N",                                       0 },	// Timbalai 1948 / UTM zone 50N
	{  29871L, 29871L, "TMBLI-B.RSOBorneo.ch",       "Timbalai_1948_RSO_Borneo_Chains",                                  0 },	// Timbalai 1948 / RSO Borneo (ch)
	{  29872L, 29872L, "TMBLI-B.RSOBorneo.ft",       "Timbalai_1948_RSO_Borneo_Feet",                                    0 },	// Timbalai 1948 / RSO Borneo (ft)
	{  29873L, 29873L, "TMBLI-B.RSOBorneo.m",        "Timbalai_1948_RSO_Borneo_Meters",                                  0 },	// Timbalai 1948 / RSO Borneo (m)
	{  29900L, 29900L, "TM65.IrishNationalGrid",     "Irish_National_Grid",                                              2 },	// TM65 / Irish National Grid
	{  29901L, 29901L, "OSNI52.IrishNtlGrid",        "OSNI_1952_Irish_National_Grid",                                    0 },	// OSNI 1952 / Irish National Grid
	{  30161L, 30161L, "Tokyo.PlnRctCS-I",           "Japan_Zone_1",                                                     0 },	// Tokyo / Japan Plane Rectangular CS I
	{  30162L, 30162L, "Tokyo.PlnRctCS-II",          "Japan_Zone_2",                                                     0 },	// Tokyo / Japan Plane Rectangular CS II
	{  30163L, 30163L, "Tokyo.PlnRctCS-III",         "Japan_Zone_3",                                                     0 },	// Tokyo / Japan Plane Rectangular CS III
	{  30164L, 30164L, "Tokyo.PlnRctCS-IV",          "Japan_Zone_4",                                                     0 },	// Tokyo / Japan Plane Rectangular CS IV
	{  30165L, 30165L, "Tokyo.PlnRctCS-V",           "Japan_Zone_5",                                                     0 },	// Tokyo / Japan Plane Rectangular CS V
	{  30166L, 30166L, "Tokyo.PlnRctCS-VI",          "Japan_Zone_6",                                                     0 },	// Tokyo / Japan Plane Rectangular CS VI
	{  30167L, 30167L, "Tokyo.PlnRctCS-VII",         "Japan_Zone_7",                                                     0 },	// Tokyo / Japan Plane Rectangular CS VII
	{  30168L, 30168L, "Tokyo.PlnRctCS-VIII",        "Japan_Zone_8",                                                     0 },	// Tokyo / Japan Plane Rectangular CS VIII
	{  30169L, 30169L, "Tokyo.PlnRctCS-IX",          "Japan_Zone_9",                                                     0 },	// Tokyo / Japan Plane Rectangular CS IX
	{  30170L, 30170L, "Tokyo.PlnRctCS-X",           "Japan_Zone_10",                                                    0 },	// Tokyo / Japan Plane Rectangular CS X
	{  30171L, 30171L, "Tokyo.PlnRctCS-XI",          "Japan_Zone_11",                                                    0 },	// Tokyo / Japan Plane Rectangular CS XI
	{  30172L, 30172L, "Tokyo.PlnRctCS-XII",         "Japan_Zone_12",                                                    0 },	// Tokyo / Japan Plane Rectangular CS XII
	{  30173L, 30173L, "Tokyo.PlnRctCS-XIII",        "Japan_Zone_13",                                                    0 },	// Tokyo / Japan Plane Rectangular CS XIII
	{  30174L, 30174L, "Tokyo.PlnRctCS-XIV",         "Japan_Zone_14",                                                    0 },	// Tokyo / Japan Plane Rectangular CS XIV
	{  30175L, 30175L, "Tokyo.PlnRctCS-XV",          "Japan_Zone_15",                                                    0 },	// Tokyo / Japan Plane Rectangular CS XV
	{  30176L, 30176L, "Tokyo.PlnRctCS-XVI",         "Japan_Zone_16",                                                    0 },	// Tokyo / Japan Plane Rectangular CS XVI
	{  30177L, 30177L, "Tokyo.PlnRctCS-XVII",        "Japan_Zone_17",                                                    0 },	// Tokyo / Japan Plane Rectangular CS XVII
	{  30178L, 30178L, "Tokyo.PlnRctCS-XVIII",       "Japan_Zone_18",                                                    0 },	// Tokyo / Japan Plane Rectangular CS XVIII
	{  30179L, 30179L, "Tokyo.PlnRctCS-XIX",         "Japan_Zone_19",                                                    0 },	// Tokyo / Japan Plane Rectangular CS XIX
	{  30200L, 30200L, "Trinidad03.Trinidad",        "Trinidad_1903_Trinidad_Grid",                                      0 },	// Trinidad 1903 / Trinidad Grid
	{  30491L, 30491L, "Voirol1875.NordAlgerie",     "Nord_Algerie_Ancienne",                                            0 },	// Voirol 1875 / Nord Algerie (ancienne)
	{  30492L, 30492L, "Voirol1875.Sud Algerie",     "Sud_Algerie_Ancienne",                                             0 },	// Voirol 1875 / Sud Algerie (ancienne)
	{  30494L, 30494L, "Voirol1875.NordAlgerie",     "Voirol_1879_Sud_Algerie_Ancienne",                                 0 },	// Voirol 1879 / Sud Algerie (ancienne)
	{  30729L, 30729L, "NordSahara59.UTM-29N",       "Nord_Sahara_1959_UTM_Zone_29N",                                    0 },	// Nord Sahara 1959 / UTM zone 29N
	{  30730L, 30730L, "NordSahara59.UTM-30N",       "Nord_Sahara_1959_UTM_Zone_30N",                                    0 },	// Nord Sahara 1959 / UTM zone 30N
	{  30731L, 30731L, "NordSahara59.UTM-31N",       "Nord_Sahara_1959_UTM_Zone_31N",                                    0 },	// Nord Sahara 1959 / UTM zone 31N
	{  30732L, 30732L, "NordSahara59.UTM-32N",       "Nord_Sahara_1959_UTM_Zone_32N",                                    0 },	// Nord Sahara 1959 / UTM zone 32N
	{  31121L, 31121L, "Zanderij.UTM-21N",           "Zanderij_1972_UTM_Zone_21N",                                       0 },	// Zanderij / UTM zone 21N
	{  31154L, 31154L, "Zanderij.TM-54NW",           "Zanderij_TM_54_NW",                                                0 },	// Zanderij / TM 54 NW
	{  31170L, 31170L, "Zanderij.SurinameTMOld",     "Zanderij_Suriname_Old_TM",                                         0 },	// Zanderij / Suriname Old TM
	{  31171L, 31171L, "Zanderij.SurinameTM",        "Zanderij_Suriname_TM",                                             0 },	// Zanderij / Suriname TM
	{  31265L, 31265L, "MGI.Gauss3d-5",              "MGI_3_Degree_Gauss_Zone_5",                                        2 },	// MGI / 3-degree Gauss zone 5
	{  31266L, 31266L, "MGI.Gauss3d-6",              "MGI_3_Degree_Gauss_Zone_6",                                        2 },	// MGI / 3-degree Gauss zone 6
	{  31267L, 31267L, "MGI.Gauss3d-7",              "MGI_3_Degree_Gauss_Zone_7",                                        2 },	// MGI / 3-degree Gauss zone 7
	{  31268L, 31268L, "MGI.Gauss3d-8",              "MGI_3_Degree_Gauss_Zone_8",                                        2 },	// MGI / 3-degree Gauss zone 8
	{  31275L, 31275L, "MGI.Balkans-5",              "MGI_Balkans_5",                                                    0 },	// MGI / Balkans zone 5
	{  31276L, 31276L, "MGI.Balkans-6",              "MGI_Balkans_6",                                                    0 },	// MGI / Balkans zone 6
	{  31277L, 31277L, "MGI.Balkans-7",              "MGI_Balkans_7",                                                    0 },	// MGI / Balkans zone 7
	{  31278L, 31278L, "MGI.Balkans-8",              "MGI_Balkans_8",                                                    2 },	// MGI / Balkans zone 8
	{  31284L, 31284L, "MGI.M28",                    "MGI_M28",                                                          0 },	// MGI / M28
	{  31285L, 31285L, "MGI.M31",                    "MGI_M31",                                                          0 },	// MGI / M31
	{  31286L, 31286L, "MGI.M34",                    "MGI_M34",                                                          0 },	// MGI / M34
	{  31287L, 31287L, "MGI.Austria",                "MGI_Austria_Lambert",                                              0 },	// MGI / Austria Lambert
	{  31294L, 31294L, "MGI.M28",                    "MGI_M28",                                                          2 },	// MGI / M28
	{  31295L, 31295L, "MGI.M31",                    "MGI_M31",                                                          2 },	// MGI / M31
	{  31296L, 31296L, "MGI.M34",                    "MGI_M34",                                                          2 },	// MGI / M34
	{  31297L, 31297L, "MGI.AustriaLambert",         "MGI_Austria_Lambert",                                              2 },	// MGI / Austria Lambert
	{  31370L, 31370L, "Belge72.Lambert72A",         "Belge_Lambert_1972",                                               0 },	// Belge 1972 / Belgian Lambert 72
	{  31466L, 31466L, "DHDN.Gauss3d-2",             "DHDN_3_Degree_Gauss_Zone_2",                                       0 },	// DHDN / Gauss-Kruger zone 2
	{  31467L, 31467L, "DHDN.Gauss3d-3",             "DHDN_3_Degree_Gauss_Zone_3",                                       0 },	// DHDN / Gauss-Kruger zone 3
	{  31468L, 31468L, "DHDN.Gauss3d-4",             "DHDN_3_Degree_Gauss_Zone_4",                                       0 },	// DHDN / Gauss-Kruger zone 4
	{  31469L, 31469L, "DHDN.Gauss3d-5",             "DHDN_3_Degree_Gauss_Zone_5",                                       0 },	// DHDN / Gauss-Kruger zone 5
	{  31528L, 31528L, "Conakry05.UTM-28N",          "Conakry_1905_UTM_Zone_28N",                                        0 },	// Conakry 1905 / UTM zone 28N
	{  31529L, 31529L, "Conakry05.UTM-29N",          "Conakry_1905_UTM_Zone_29N",                                        0 },	// Conakry 1905 / UTM zone 29N
	{  31600L, 31600L, "DealulPiscului33.Stero",     "Stereo_33",                                                        0 },	// Dealul Piscului 1933/ Stereo 33
	{  31700L, 31700L, "DealulPiscului70.Stero",     "Stereo_70",                                                        0 },	// Dealul Piscului 1970/ Stereo 70
	{  31838L, 31838L, "NGN.UTM-38N",                "NGN_UTM_Zone_38N",                                                 0 },	// NGN / UTM zone 38N
	{  31839L, 31839L, "NGN.UTM-39N",                "NGN_UTM_Zone_39N",                                                 0 },	// NGN / UTM zone 39N
	{  31901L, 31901L, "KuwaitUtility.KTM",          "KUDAMS_KTM",                                                       0 },	// KUDAMS / KTM
	{  31977L, 31977L, "SIRGAS2000.UTM-17S",         "SIRGAS_UTM_Zone_17S",                                              0 },	// SIRGAS 2000 / UTM zone 17S
	{  31978L, 31978L, "SIRGAS2000.UTM-18S",         "SIRGAS_UTM_Zone_18S",                                              0 },	// SIRGAS 2000 / UTM zone 18S
	{  31979L, 31979L, "SIRGAS2000.UTM-19S",         "SIRGAS_UTM_Zone_19S",                                              0 },	// SIRGAS 2000 / UTM zone 19S
	{  31980L, 31980L, "SIRGAS2000.UTM-20S",         "SIRGAS_UTM_Zone_20S",                                              0 },	// SIRGAS 2000 / UTM zone 20S
	{  31981L, 31981L, "SIRGAS2000.UTM-21S",         "SIRGAS_UTM_Zone_21S",                                              0 },	// SIRGAS 2000 / UTM zone 21S
	{  31982L, 31982L, "SIRGAS2000.UTM-22S",         "SIRGAS_UTM_Zone_22S",                                              0 },	// SIRGAS 2000 / UTM zone 22S
	{  31983L, 31983L, "SIRGAS2000.UTM-23S",         "SIRGAS_UTM_Zone_23S",                                              0 },	// SIRGAS 2000 / UTM zone 23S
	{  31984L, 31984L, "SIRGAS2000.UTM-24S",         "SIRGAS_UTM_Zone_24S",                                              0 },	// SIRGAS 2000 / UTM zone 24S
	{  31985L, 31985L, "SIRGAS2000.UTM-25S",         "SIRGAS_UTM_Zone_25S",                                              0 },	// SIRGAS 2000 / UTM zone 25S
	{  31917L, 31986L, "GRSSA.UTM-17N",              "SIRGAS_UTM_Zone_17N",                                              0 },	// SIRGAS / UTM zone 17N
	{  31918L, 31987L, "GRSSA.UTM-18N",              "SIRGAS_UTM_Zone_18N",                                              0 },	// SIRGAS / UTM zone 18N
	{  31919L, 31988L, "GRSSA.UTM-19N",              "SIRGAS_UTM_Zone_19N",                                              0 },	// SIRGAS / UTM zone 19N
	{  31920L, 31989L, "GRSSA.UTM-20N",              "SIRGAS_UTM_Zone_20N",                                              0 },	// SIRGAS / UTM zone 20N
	{  31921L, 31990L, "GRSSA.UTM-21N",              "SIRGAS_UTM_Zone_21N",                                              0 },	// SIRGAS / UTM zone 21N
	{  31922L, 31991L, "GRSSA.UTM-22N",              "SIRGAS_UTM_Zone_22N",                                              0 },	// SIRGAS / UTM zone 22N
	{  32001L, 32001L, "MT-N",                       "NAD_1927_StatePlane_Montana_North_FIPS_2501",                      1 },	// NAD27 / Montana North
	{  32002L, 32002L, "MT-C",                       "NAD_1927_StatePlane_Montana_Central_FIPS_2502",                    1 },	// NAD27 / Montana Central
	{  32003L, 32003L, "MT-S",                       "NAD_1927_StatePlane_Montana_South_FIPS_2503",                      1 },	// NAD27 / Montana South
	{  32005L, 32005L, "NB-N",                       "NAD_1927_StatePlane_Nebraska_North_FIPS_2601",                     1 },	// NAD27 / Nebraska North
	{  32006L, 32006L, "NB-S",                       "NAD_1927_StatePlane_Nebraska_South_FIPS_2602",                     1 },	// NAD27 / Nebraska South
	{  32007L, 32007L, "NV-E",                       "NAD_1927_StatePlane_Nevada_East_FIPS_2701",                        1 },	// NAD27 / Nevada East
	{  32008L, 32008L, "NV-C",                       "NAD_1927_StatePlane_Nevada_Central_FIPS_2702",                     1 },	// NAD27 / Nevada Central
	{  32009L, 32009L, "NV-W",                       "NAD_1927_StatePlane_Nevada_West_FIPS_2703",                        1 },	// NAD27 / Nevada West
	{  32010L, 32010L, "NH",                         "NAD_1927_StatePlane_New_Hampshire_FIPS_2800",                      1 },	// NAD27 / New Hampshire
	{  32011L, 32011L, "NJ",                         "NAD_1927_StatePlane_New_Jersey_FIPS_2900",                         1 },	// NAD27 / New Jersey
	{  32012L, 32012L, "NM-E",                       "NAD_1927_StatePlane_New_Mexico_East_FIPS_3001",                    1 },	// NAD27 / New Mexico East
	{  32013L, 32013L, "NM-C",                       "NAD_1927_StatePlane_New_Mexico_Central_FIPS_3002",                 1 },	// NAD27 / New Mexico Central
	{  32014L, 32014L, "NM-W",                       "NAD_1927_StatePlane_New_Mexico_West_FIPS_3003",                    1 },	// NAD27 / New Mexico West
	{  32015L, 32015L, "NY-E",                       "NAD_1927_StatePlane_New_York_East_FIPS_3101",                      1 },	// NAD27 / New York East
	{  32016L, 32016L, "NY-C",                       "NAD_1927_StatePlane_New_York_Central_FIPS_3102",                   1 },	// NAD27 / New York Central
	{  32017L, 32017L, "NY-W",                       "NAD_1927_StatePlane_New_York_West_FIPS_3103",                      1 },	// NAD27 / New York West
	{  32018L, 32018L, "NY-LI",                      "NAD_1927_StatePlane_New_York_Long_Island_FIPS_3104",               1 },	// NAD27 / New York Long Island
	{  32019L, 32019L, "NC",                         "NAD_1927_StatePlane_North_Carolina_FIPS_3200",                     1 },	// NAD27 / North Carolina
	{  32020L, 32020L, "ND-N",                       "NAD_1927_StatePlane_North_Dakota_North_FIPS_3301",                 1 },	// NAD27 / North Dakota North
	{  32021L, 32021L, "ND-S",                       "NAD_1927_StatePlane_North_Dakota_South_FIPS_3302",                 1 },	// NAD27 / North Dakota South
	{  32022L, 32022L, "OH-N",                       "NAD_1927_StatePlane_Ohio_North_FIPS_3401",                         1 },	// NAD27 / Ohio North
	{  32023L, 32023L, "OH-S",                       "NAD_1927_StatePlane_Ohio_South_FIPS_3402",                         1 },	// NAD27 / Ohio South
	{  32024L, 32024L, "OK-N",                       "NAD_1927_StatePlane_Oklahoma_North_FIPS_3501",                     1 },	// NAD27 / Oklahoma North
	{  32025L, 32025L, "OK-S",                       "NAD_1927_StatePlane_Oklahoma_South_FIPS_3502",                     1 },	// NAD27 / Oklahoma South
	{  32026L, 32026L, "OR-N",                       "NAD_1927_StatePlane_Oregon_North_FIPS_3601",                       1 },	// NAD27 / Oregon North
	{  32027L, 32027L, "OR-S",                       "NAD_1927_StatePlane_Oregon_South_FIPS_3602",                       1 },	// NAD27 / Oregon South
	{  32028L, 32028L, "PA-N",                       "NAD_1927_StatePlane_Pennsylvania_North_FIPS_3701",                 1 },	// NAD27 / Pennsylvania North
	{  32029L, 32029L, "PA-S",                       "NAD_1927_StatePlane_Pennsylvania_South_FIPS_3702",                 1 },	// NAD27 / Pennsylvania South
	{  32030L, 32030L, "RI",                         "NAD_1927_StatePlane_Rhode_Island_FIPS_3800",                       1 },	// NAD27 / Rhode Island
	{  32031L, 32031L, "SC-N",                       "NAD_1927_StatePlane_South_Carolina_North_FIPS_3901",               1 },	// NAD27 / South Carolina North
	{  32033L, 32033L, "SC-S",                       "NAD_1927_StatePlane_South_Carolina_South_FIPS_3902",               1 },	// NAD27 / South Carolina South
	{  32034L, 32034L, "SD-N",                       "NAD_1927_StatePlane_South_Dakota_North_FIPS_4001",                 1 },	// NAD27 / South Dakota North
	{  32035L, 32035L, "SD-S",                       "NAD_1927_StatePlane_South_Dakota_South_FIPS_4002",                 1 },	// NAD27 / South Dakota South
	{  32037L, 32037L, "TX-N",                       "NAD_1927_StatePlane_Texas_North_FIPS_4201",                        1 },	// NAD27 / Texas North
	{  32038L, 32038L, "TX-NC",                      "NAD_1927_StatePlane_Texas_North_Central_FIPS_4202",                1 },	// NAD27 / Texas North Central
	{  32039L, 32039L, "TX-C",                       "NAD_1927_StatePlane_Texas_Central_FIPS_4203",                      1 },	// NAD27 / Texas Central
	{  32040L, 32040L, "TX-SC",                      "NAD_1927_StatePlane_Texas_South_Central_FIPS_4204",                1 },	// NAD27 / Texas South Central
	{  32041L, 32041L, "TX-S",                       "NAD_1927_StatePlane_Texas_South_FIPS_4205",                        1 },	// NAD27 / Texas South
	{  32042L, 32042L, "UT-N",                       "NAD_1927_StatePlane_Utah_North_FIPS_4301",                         1 },	// NAD27 / Utah North
	{  32043L, 32043L, "UT-C",                       "NAD_1927_StatePlane_Utah_Central_FIPS_4302",                       1 },	// NAD27 / Utah Central
	{  32044L, 32044L, "UT-S",                       "NAD_1927_StatePlane_Utah_South_FIPS_4303",                         1 },	// NAD27 / Utah South
	{  32045L, 32045L, "VT",                         "NAD_1927_StatePlane_Vermont_FIPS_3400",                            1 },	// NAD27 / Vermont
	{  32046L, 32046L, "VA-N",                       "NAD_1927_StatePlane_Virginia_North_FIPS_4501",                     1 },	// NAD27 / Virginia North
	{  32047L, 32047L, "VA-S",                       "NAD_1927_StatePlane_Virginia_South_FIPS_4502",                     1 },	// NAD27 / Virginia South
	{  32048L, 32048L, "WA-N",                       "NAD_1927_StatePlane_Washington_North_FIPS_4601",                   1 },	// NAD27 / Washington North
	{  32049L, 32049L, "WA-S",                       "NAD_1927_StatePlane_Washington_South_FIPS_4602",                   1 },	// NAD27 / Washington South
	{  32050L, 32050L, "WV-N",                       "NAD_1927_StatePlane_West_Virginia_North_FIPS_4701",                1 },	// NAD27 / West Virginia North
	{  32051L, 32051L, "WV-S",                       "NAD_1927_StatePlane_West_Virginia_South_FIPS_4702",                1 },	// NAD27 / West Virginia South
	{  32052L, 32052L, "WI-N",                       "NAD_1927_StatePlane_Wisconsin_North_FIPS_4801",                    1 },	// NAD27 / Wisconsin North
	{  32053L, 32053L, "WI-C",                       "NAD_1927_StatePlane_Wisconsin_Central_FIPS_4802",                  1 },	// NAD27 / Wisconsin Central
	{  32054L, 32054L, "WI-S",                       "NAD_1927_StatePlane_Wisconsin_South_FIPS_4803",                    1 },	// NAD27 / Wisconsin South
	{  32055L, 32055L, "WY-E",                       "NAD_1927_StatePlane_Wyoming_East_FIPS_4901",                       1 },	// NAD27 / Wyoming East
	{  32056L, 32056L, "WY-EC",                      "NAD_1927_StatePlane_Wyoming_East_Central_FIPS_4902",               1 },	// NAD27 / Wyoming East Central
	{  32057L, 32057L, "WY-WC",                      "NAD_1927_StatePlane_Wyoming_West_Central_FIPS_4903",               1 },	// NAD27 / Wyoming West Central
	{  32058L, 32058L, "WY-W",                       "NAD_1927_StatePlane_Wyoming_West_FIPS_4904",                       1 },	// NAD27 / Wyoming West
	{  32061L, 32061L, "NAD27.GuatemalaN",           "NAD_1927_Guatemala_Norte",                                         0 },	// NAD27 / Guatemala Norte
	{  32062L, 32062L, "NAD27.GuatemalaS",           "NAD_1927_Guatemala_Sur",                                           0 },	// NAD27 / Guatemala Sur
	{  32074L, 32074L, "NAD27.BLM-14N.Ift",          "NAD_1927_BLM_Zone_14N",                                            2 },	// NAD27 / BLM 14N (feet)
	{  32075L, 32075L, "NAD27.BLM-15N.Ift",          "NAD_1927_BLM_Zone_15N",                                            2 },	// NAD27 / BLM 15N (feet)
	{  32076L, 32076L, "NAD27.BLM-16N.Ift",          "NAD_1927_BLM_Zone_16N",                                            2 },	// NAD27 / BLM 16N (feet)
	{  32077L, 32077L, "NAD27.BLM-17N.Ift",          "NAD_1927_BLM_Zone_17N",                                            2 },	// NAD27 / BLM 17N (feet)
	{  32081L, 32081L, "NAD27.MTM-1",                "NAD_1927_MTM_1",                                                   0 },	// NAD27 / MTM zone 1
	{  32082L, 32082L, "NAD27.MTM-2",                "NAD_1927_MTM_2",                                                   0 },	// NAD27 / MTM zone 2
	{  32083L, 32083L, "MTM27-3",                    "NAD_1927_MTM_3",                                                   1 },	// NAD27 / MTM zone 3
	{  32084L, 32084L, "MTM27-4",                    "NAD_1927_MTM_4",                                                   1 },	// NAD27 / MTM zone 4
	{  32085L, 32085L, "MTM27-5",                    "NAD_1927_MTM_5",                                                   1 },	// NAD27 / MTM zone 5
	{  32086L, 32086L, "MTM27-6",                    "NAD_1927_MTM_6",                                                   1 },	// NAD27 / MTM zone 6
	{  32098L, 32098L, "NAD27.QuebecLambert",        "NAD_1927_Quebec_Lambert",                                          0 },	// NAD27 / Quebec Lambert
	{  32100L, 32100L, "MT83",                       "NAD_1983_StatePlane_Montana_FIPS_2500",                            1 },	// NAD83 / Montana
	{  32104L, 32104L, "NB83",                       "NAD_1983_StatePlane_Nebraska_FIPS_2600",                           1 },	// NAD83 / Nebraska
	{  32107L, 32107L, "NV83-E",                     "NAD_1983_StatePlane_Nevada_East_FIPS_2701",                        1 },	// NAD83 / Nevada East
	{  32108L, 32108L, "NV83-C",                     "NAD_1983_StatePlane_Nevada_Central_FIPS_2702",                     1 },	// NAD83 / Nevada Central
	{  32109L, 32109L, "NV83-W",                     "NAD_1983_StatePlane_Nevada_West_FIPS_2703",                        1 },	// NAD83 / Nevada West
	{  32110L, 32110L, "NH83",                       "NAD_1983_StatePlane_New_Hampshire_FIPS_2800",                      1 },	// NAD83 / New Hampshire
	{  32111L, 32111L, "NJ83",                       "NAD_1983_StatePlane_New_Jersey_FIPS_2900",                         1 },	// NAD83 / New Jersey
	{  32112L, 32112L, "NM83-E",                     "NAD_1983_StatePlane_New_Mexico_East_FIPS_3001",                    1 },	// NAD83 / New Mexico East
	{  32113L, 32113L, "NM83-C",                     "NAD_1983_StatePlane_New_Mexico_Central_FIPS_3002",                 1 },	// NAD83 / New Mexico Central
	{  32114L, 32114L, "NM83-W",                     "NAD_1983_StatePlane_New_Mexico_West_FIPS_3003",                    1 },	// NAD83 / New Mexico West
	{  32115L, 32115L, "NY83-E",                     "NAD_1983_StatePlane_New_York_East_FIPS_3101",                      1 },	// NAD83 / New York East
	{  32116L, 32116L, "NY83-C",                     "NAD_1983_StatePlane_New_York_Central_FIPS_3102",                   1 },	// NAD83 / New York Central
	{  32117L, 32117L, "NY83-W",                     "NAD_1983_StatePlane_New_York_West_FIPS_3103",                      1 },	// NAD83 / New York West
	{  32118L, 32118L, "NY83-LI",                    "NAD_1983_StatePlane_New_York_Long_Island_FIPS_3104",               1 },	// NAD83 / New York Long Island
	{  32119L, 32119L, "NC83",                       "NAD_1983_StatePlane_North_Carolina_FIPS_3200",                     1 },	// NAD83 / North Carolina
	{  32120L, 32120L, "ND83-N",                     "NAD_1983_StatePlane_North_Dakota_North_FIPS_3301",                 1 },	// NAD83 / North Dakota North
	{  32121L, 32121L, "ND83-S",                     "NAD_1983_StatePlane_North_Dakota_South_FIPS_3302",                 1 },	// NAD83 / North Dakota South
	{  32122L, 32122L, "OH83-N",                     "NAD_1983_StatePlane_Ohio_North_FIPS_3401",                         1 },	// NAD83 / Ohio North
	{  32123L, 32123L, "OH83-S",                     "NAD_1983_StatePlane_Ohio_South_FIPS_3402",                         1 },	// NAD83 / Ohio South
	{  32124L, 32124L, "OK83-N",                     "NAD_1983_StatePlane_Oklahoma_North_FIPS_3501",                     1 },	// NAD83 / Oklahoma North
	{  32125L, 32125L, "OK83-S",                     "NAD_1983_StatePlane_Oklahoma_South_FIPS_3502",                     1 },	// NAD83 / Oklahoma South
	{  32126L, 32126L, "OR83-N",                     "NAD_1983_StatePlane_Oregon_North_FIPS_3601",                       1 },	// NAD83 / Oregon North
	{  32127L, 32127L, "OR83-S",                     "NAD_1983_StatePlane_Oregon_South_FIPS_3602",                       1 },	// NAD83 / Oregon South
	{  32128L, 32128L, "PA83-N",                     "NAD_1983_StatePlane_Pennsylvania_North_FIPS_3701",                 1 },	// NAD83 / Pennsylvania North
	{  32129L, 32129L, "PA83-S",                     "NAD_1983_StatePlane_Pennsylvania_South_FIPS_3702",                 1 },	// NAD83 / Pennsylvania South
	{  32130L, 32130L, "RI83",                       "NAD_1983_StatePlane_Rhode_Island_FIPS_3800",                       1 },	// NAD83 / Rhode Island
	{  32133L, 32133L, "SC83",                       "NAD_1983_StatePlane_South_Carolina_FIPS_3900",                     1 },	// NAD83 / South Carolina
	{  32134L, 32134L, "SD83-N",                     "NAD_1983_StatePlane_South_Dakota_North_FIPS_4001",                 1 },	// NAD83 / South Dakota North
	{  32135L, 32135L, "SD83-S",                     "NAD_1983_StatePlane_South_Dakota_South_FIPS_4002",                 1 },	// NAD83 / South Dakota South
	{  32136L, 32136L, "TN83",                       "NAD_1983_StatePlane_Tennessee_FIPS_4100",                          1 },	// NAD83 / Tennessee
	{  32137L, 32137L, "TX83-N",                     "NAD_1983_StatePlane_Texas_North_FIPS_4201",                        1 },	// NAD83 / Texas North
	{  32138L, 32138L, "TX83-NC",                    "NAD_1983_StatePlane_Texas_North_Central_FIPS_4202",                1 },	// NAD83 / Texas North Central
	{  32139L, 32139L, "TX83-C",                     "NAD_1983_StatePlane_Texas_Central_FIPS_4203",                      1 },	// NAD83 / Texas Central
	{  32140L, 32140L, "TX83-SC",                    "NAD_1983_StatePlane_Texas_South_Central_FIPS_4204",                1 },	// NAD83 / Texas South Central
	{  32141L, 32141L, "TX83-S",                     "NAD_1983_StatePlane_Texas_South_FIPS_4205",                        1 },	// NAD83 / Texas South
	{  32142L, 32142L, "UT83-N",                     "NAD_1983_StatePlane_Utah_North_FIPS_4301",                         1 },	// NAD83 / Utah North
	{  32143L, 32143L, "UT83-C",                     "NAD_1983_StatePlane_Utah_Central_FIPS_4302",                       1 },	// NAD83 / Utah Central
	{  32144L, 32144L, "UT83-S",                     "NAD_1983_StatePlane_Utah_South_FIPS_4303",                         1 },	// NAD83 / Utah South
	{  32145L, 32145L, "VT83",                       "NAD_1983_StatePlane_Vermont_FIPS_4400",                            1 },	// NAD83 / Vermont
	{  32146L, 32146L, "VA83-N",                     "NAD_1983_StatePlane_Virginia_North_FIPS_4501",                     1 },	// NAD83 / Virginia North
	{  32147L, 32147L, "VA83-S",                     "NAD_1983_StatePlane_Virginia_South_FIPS_4502",                     1 },	// NAD83 / Virginia South
	{  32148L, 32148L, "WA83-N",                     "NAD_1983_StatePlane_Washington_North_FIPS_4601",                   1 },	// NAD83 / Washington North
	{  32149L, 32149L, "WA83-S",                     "NAD_1983_StatePlane_Washington_South_FIPS_4602",                   1 },	// NAD83 / Washington South
	{  32150L, 32150L, "WV83-N",                     "NAD_1983_StatePlane_West_Virginia_North_FIPS_4701",                1 },	// NAD83 / West Virginia North
	{  32151L, 32151L, "WV83-S",                     "NAD_1983_StatePlane_West_Virginia_South_FIPS_4702",                1 },	// NAD83 / West Virginia South
	{  32152L, 32152L, "WI83-N",                     "NAD_1983_StatePlane_Wisconsin_North_FIPS_4801",                    1 },	// NAD83 / Wisconsin North
	{  32153L, 32153L, "WI83-C",                     "NAD_1983_StatePlane_Wisconsin_Central_FIPS_4802",                  1 },	// NAD83 / Wisconsin Central
	{  32154L, 32154L, "WI83-S",                     "NAD_1983_StatePlane_Wisconsin_South_FIPS_4803",                    1 },	// NAD83 / Wisconsin South
	{  32155L, 32155L, "WY83-E",                     "NAD_1983_StatePlane_Wyoming_East_FIPS_4901",                       1 },	// NAD83 / Wyoming East
	{  32156L, 32156L, "WY83-EC",                    "NAD_1983_StatePlane_Wyoming_East_Central_FIPS_4902",               1 },	// NAD83 / Wyoming East Central
	{  32157L, 32157L, "WY83-WC",                    "NAD_1983_StatePlane_Wyoming_West_Central_FIPS_4903",               1 },	// NAD83 / Wyoming West Central
	{  32158L, 32158L, "WY83-W",                     "NAD_1983_StatePlane_Wyoming_West_FIPS_4904",                       1 },	// NAD83 / Wyoming West
	{  32161L, 32161L, "PR83",                       "NAD_1983_StatePlane_Puerto_Rico_Virgin_Islands_FIPS_5200",         1 },	// NAD83 / Puerto Rico & Virgin Is.
	{  32180L, 32180L, "NAD83.SCoPQ-2",              "NAD_1983_MTM_2_SCoPQ",                                             0 },	// NAD83 / SCoPQ zone 2
	{  32181L, 32181L, "MTM83-1",                    "NAD_1983_MTM_1",                                                   1 },	// NAD83 / MTM zone 1
	{  32182L, 32182L, "MTM83-2",                    "NAD_1983_MTM_2",                                                   1 },	// NAD83 / MTM zone 2
	{  32183L, 32183L, "MTM83-3",                    "NAD_1983_MTM_3",                                                   1 },	// NAD83 / MTM zone 3
	{  32184L, 32184L, "MTM83-4",                    "NAD_1983_MTM_4",                                                   1 },	// NAD83 / MTM zone 4
	{  32185L, 32185L, "MTM83-5",                    "NAD_1983_MTM_5",                                                   1 },	// NAD83 / MTM zone 5
	{  32186L, 32186L, "MTM83-6",                    "NAD_1983_MTM_6",                                                   1 },	// NAD83 / MTM zone 6
	{  32187L, 32187L, "MTM83-7",                    "NAD_1983_MTM_7",                                                   1 },	// NAD83 / MTM zone 7
	{  32188L, 32188L, "MTM83-8",                    "NAD_1983_MTM_8",                                                   1 },	// NAD83 / MTM zone 8
	{  32189L, 32189L, "MTM83-9",                    "NAD_1983_MTM_9",                                                   1 },	// NAD83 / MTM zone 9
	{  32190L, 32190L, "MTM83-10",                   "NAD_1983_MTM_10",                                                  1 },	// NAD83 / MTM zone 10
	{  32191L, 32191L, "MTM83-11",                   "NAD_1983_MTM_11",                                                  1 },	// NAD83 / MTM zone 11
	{  32192L, 32192L, "MTM83-12",                   "NAD_1983_MTM_12",                                                  1 },	// NAD83 / MTM zone 12
	{  32193L, 32193L, "MTM83-13",                   "NAD_1983_MTM_13",                                                  1 },	// NAD83 / MTM zone 13
	{  32194L, 32194L, "MTM83-14",                   "NAD_1983_MTM_14",                                                  1 },	// NAD83 / MTM zone 14
	{  32195L, 32195L, "MTM83-15",                   "NAD_1983_MTM_15",                                                  1 },	// NAD83 / MTM zone 15
	{  32196L, 32196L, "MTM83-16",                   "NAD_1983_MTM_16",                                                  1 },	// NAD83 / MTM zone 16
	{  32197L, 32197L, "MTM83-17",                   "NAD_1983_MTM_17",                                                  1 },	// NAD83 / MTM zone 17
	{  32198L, 32198L, "NAD83.QuebecLambert",        "NAD_1983_Quebec_Lambert",                                          0 },	// NAD83 / Quebec Lambert
	{  32201L, 32201L, "WGS72.UTM-1N",               "WGS_1972_UTM_Zone_1N",                                             0 },	// WGS 72 / UTM zone 1N
	{  32202L, 32202L, "WGS72.UTM-2N",               "WGS_1972_UTM_Zone_2N",                                             0 },	// WGS 72 / UTM zone 2N
	{  32203L, 32203L, "WGS72.UTM-3N",               "WGS_1972_UTM_Zone_3N",                                             0 },	// WGS 72 / UTM zone 3N
	{  32204L, 32204L, "WGS72.UTM-4N",               "WGS_1972_UTM_Zone_4N",                                             0 },	// WGS 72 / UTM zone 4N
	{  32205L, 32205L, "WGS72.UTM-5N",               "WGS_1972_UTM_Zone_5N",                                             0 },	// WGS 72 / UTM zone 5N
	{  32206L, 32206L, "WGS72.UTM-6N",               "WGS_1972_UTM_Zone_6N",                                             0 },	// WGS 72 / UTM zone 6N
	{  32207L, 32207L, "WGS72.UTM-7N",               "WGS_1972_UTM_Zone_7N",                                             0 },	// WGS 72 / UTM zone 7N
	{  32208L, 32208L, "WGS72.UTM-8N",               "WGS_1972_UTM_Zone_8N",                                             0 },	// WGS 72 / UTM zone 8N
	{  32209L, 32209L, "WGS72.UTM-9N",               "WGS_1972_UTM_Zone_9N",                                             0 },	// WGS 72 / UTM zone 9N
	{  32210L, 32210L, "WGS72.UTM-10N",              "WGS_1972_UTM_Zone_10N",                                            0 },	// WGS 72 / UTM zone 10N
	{  32211L, 32211L, "WGS72.UTM-11N",              "WGS_1972_UTM_Zone_11N",                                            0 },	// WGS 72 / UTM zone 11N
	{  32212L, 32212L, "WGS72.UTM-12N",              "WGS_1972_UTM_Zone_12N",                                            0 },	// WGS 72 / UTM zone 12N
	{  32213L, 32213L, "WGS72.UTM-13N",              "WGS_1972_UTM_Zone_13N",                                            0 },	// WGS 72 / UTM zone 13N
	{  32214L, 32214L, "WGS72.UTM-14N",              "WGS_1972_UTM_Zone_14N",                                            0 },	// WGS 72 / UTM zone 14N
	{  32215L, 32215L, "WGS72.UTM-15N",              "WGS_1972_UTM_Zone_15N",                                            0 },	// WGS 72 / UTM zone 15N
	{  32216L, 32216L, "WGS72.UTM-16N",              "WGS_1972_UTM_Zone_16N",                                            0 },	// WGS 72 / UTM zone 16N
	{  32217L, 32217L, "WGS72.UTM-17N",              "WGS_1972_UTM_Zone_17N",                                            0 },	// WGS 72 / UTM zone 17N
	{  32218L, 32218L, "WGS72.UTM-18N",              "WGS_1972_UTM_Zone_18N",                                            0 },	// WGS 72 / UTM zone 18N
	{  32219L, 32219L, "WGS72.UTM-19N",              "WGS_1972_UTM_Zone_19N",                                            0 },	// WGS 72 / UTM zone 19N
	{  32220L, 32220L, "WGS72.UTM-20N",              "WGS_1972_UTM_Zone_20N",                                            0 },	// WGS 72 / UTM zone 20N
	{  32221L, 32221L, "WGS72.UTM-21N",              "WGS_1972_UTM_Zone_21N",                                            0 },	// WGS 72 / UTM zone 21N
	{  32222L, 32222L, "WGS72.UTM-22N",              "WGS_1972_UTM_Zone_22N",                                            0 },	// WGS 72 / UTM zone 22N
	{  32223L, 32223L, "WGS72.UTM-23N",              "WGS_1972_UTM_Zone_23N",                                            0 },	// WGS 72 / UTM zone 23N
	{  32224L, 32224L, "WGS72.UTM-24N",              "WGS_1972_UTM_Zone_24N",                                            0 },	// WGS 72 / UTM zone 24N
	{  32225L, 32225L, "WGS72.UTM-25N",              "WGS_1972_UTM_Zone_25N",                                            0 },	// WGS 72 / UTM zone 25N
	{  32226L, 32226L, "WGS72.UTM-26N",              "WGS_1972_UTM_Zone_26N",                                            0 },	// WGS 72 / UTM zone 26N
	{  32227L, 32227L, "WGS72.UTM-27N",              "WGS_1972_UTM_Zone_27N",                                            0 },	// WGS 72 / UTM zone 27N
	{  32228L, 32228L, "WGS72.UTM-28N",              "WGS_1972_UTM_Zone_28N",                                            0 },	// WGS 72 / UTM zone 28N
	{  32229L, 32229L, "WGS72.UTM-29N",              "WGS_1972_UTM_Zone_29N",                                            0 },	// WGS 72 / UTM zone 29N
	{  32230L, 32230L, "WGS72.UTM-30N",              "WGS_1972_UTM_Zone_30N",                                            0 },	// WGS 72 / UTM zone 30N
	{  32231L, 32231L, "WGS72.UTM-31N",              "WGS_1972_UTM_Zone_31N",                                            0 },	// WGS 72 / UTM zone 31N
	{  32232L, 32232L, "WGS72.UTM-32N",              "WGS_1972_UTM_Zone_32N",                                            0 },	// WGS 72 / UTM zone 32N
	{  32233L, 32233L, "WGS72.UTM-33N",              "WGS_1972_UTM_Zone_33N",                                            0 },	// WGS 72 / UTM zone 33N
	{  32234L, 32234L, "WGS72.UTM-34N",              "WGS_1972_UTM_Zone_34N",                                            0 },	// WGS 72 / UTM zone 34N
	{  32235L, 32235L, "WGS72.UTM-35N",              "WGS_1972_UTM_Zone_35N",                                            0 },	// WGS 72 / UTM zone 35N
	{  32236L, 32236L, "WGS72.UTM-36N",              "WGS_1972_UTM_Zone_36N",                                            0 },	// WGS 72 / UTM zone 36N
	{  32237L, 32237L, "WGS72.UTM-37N",              "WGS_1972_UTM_Zone_37N",                                            0 },	// WGS 72 / UTM zone 37N
	{  32238L, 32238L, "WGS72.UTM-38N",              "WGS_1972_UTM_Zone_38N",                                            0 },	// WGS 72 / UTM zone 38N
	{  32239L, 32239L, "WGS72.UTM-39N",              "WGS_1972_UTM_Zone_39N",                                            0 },	// WGS 72 / UTM zone 39N
	{  32240L, 32240L, "WGS72.UTM-40N",              "WGS_1972_UTM_Zone_40N",                                            0 },	// WGS 72 / UTM zone 40N
	{  32241L, 32241L, "WGS72.UTM-41N",              "WGS_1972_UTM_Zone_41N",                                            0 },	// WGS 72 / UTM zone 41N
	{  32242L, 32242L, "WGS72.UTM-42N",              "WGS_1972_UTM_Zone_42N",                                            0 },	// WGS 72 / UTM zone 42N
	{  32243L, 32243L, "WGS72.UTM-43N",              "WGS_1972_UTM_Zone_43N",                                            0 },	// WGS 72 / UTM zone 43N
	{  32244L, 32244L, "WGS72.UTM-44N",              "WGS_1972_UTM_Zone_44N",                                            0 },	// WGS 72 / UTM zone 44N
	{  32245L, 32245L, "WGS72.UTM-45N",              "WGS_1972_UTM_Zone_45N",                                            0 },	// WGS 72 / UTM zone 45N
	{  32246L, 32246L, "WGS72.UTM-46N",              "WGS_1972_UTM_Zone_46N",                                            0 },	// WGS 72 / UTM zone 46N
	{  32247L, 32247L, "WGS72.UTM-47N",              "WGS_1972_UTM_Zone_47N",                                            0 },	// WGS 72 / UTM zone 47N
	{  32248L, 32248L, "WGS72.UTM-48N",              "WGS_1972_UTM_Zone_48N",                                            0 },	// WGS 72 / UTM zone 48N
	{  32249L, 32249L, "WGS72.UTM-49N",              "WGS_1972_UTM_Zone_49N",                                            0 },	// WGS 72 / UTM zone 49N
	{  32250L, 32250L, "WGS72.UTM-50N",              "WGS_1972_UTM_Zone_50N",                                            0 },	// WGS 72 / UTM zone 50N
	{  32251L, 32251L, "WGS72.UTM-51N",              "WGS_1972_UTM_Zone_51N",                                            0 },	// WGS 72 / UTM zone 51N
	{  32252L, 32252L, "WGS72.UTM-52N",              "WGS_1972_UTM_Zone_52N",                                            0 },	// WGS 72 / UTM zone 52N
	{  32253L, 32253L, "WGS72.UTM-53N",              "WGS_1972_UTM_Zone_53N",                                            0 },	// WGS 72 / UTM zone 53N
	{  32254L, 32254L, "WGS72.UTM-54N",              "WGS_1972_UTM_Zone_54N",                                            0 },	// WGS 72 / UTM zone 54N
	{  32255L, 32255L, "WGS72.UTM-55N",              "WGS_1972_UTM_Zone_55N",                                            0 },	// WGS 72 / UTM zone 55N
	{  32256L, 32256L, "WGS72.UTM-56N",              "WGS_1972_UTM_Zone_56N",                                            0 },	// WGS 72 / UTM zone 56N
	{  32257L, 32257L, "WGS72.UTM-57N",              "WGS_1972_UTM_Zone_57N",                                            0 },	// WGS 72 / UTM zone 57N
	{  32258L, 32258L, "WGS72.UTM-58N",              "WGS_1972_UTM_Zone_58N",                                            0 },	// WGS 72 / UTM zone 58N
	{  32259L, 32259L, "WGS72.UTM-59N",              "WGS_1972_UTM_Zone_59N",                                            0 },	// WGS 72 / UTM zone 59N
	{  32260L, 32260L, "WGS72.UTM-60N",              "WGS_1972_UTM_Zone_60N",                                            0 },	// WGS 72 / UTM zone 60N
	{  32301L, 32301L, "WGS72.UTM-1S",               "WGS_1972_UTM_Zone_1S",                                             0 },	// WGS 72 / UTM zone 1S
	{  32302L, 32302L, "WGS72.UTM-2S",               "WGS_1972_UTM_Zone_2S",                                             0 },	// WGS 72 / UTM zone 2S
	{  32303L, 32303L, "WGS72.UTM-3S",               "WGS_1972_UTM_Zone_3S",                                             0 },	// WGS 72 / UTM zone 3S
	{  32304L, 32304L, "WGS72.UTM-4S",               "WGS_1972_UTM_Zone_4S",                                             0 },	// WGS 72 / UTM zone 4S
	{  32305L, 32305L, "WGS72.UTM-5S",               "WGS_1972_UTM_Zone_5S",                                             0 },	// WGS 72 / UTM zone 5S
	{  32306L, 32306L, "WGS72.UTM-6S",               "WGS_1972_UTM_Zone_6S",                                             0 },	// WGS 72 / UTM zone 6S
	{  32307L, 32307L, "WGS72.UTM-7S",               "WGS_1972_UTM_Zone_7S",                                             0 },	// WGS 72 / UTM zone 7S
	{  32308L, 32308L, "WGS72.UTM-8S",               "WGS_1972_UTM_Zone_8S",                                             0 },	// WGS 72 / UTM zone 8S
	{  32309L, 32309L, "WGS72.UTM-9S",               "WGS_1972_UTM_Zone_9S",                                             0 },	// WGS 72 / UTM zone 9S
	{  32310L, 32310L, "WGS72.UTM-10S",              "WGS_1972_UTM_Zone_10S",                                            0 },	// WGS 72 / UTM zone 10S
	{  32311L, 32311L, "WGS72.UTM-11S",              "WGS_1972_UTM_Zone_11S",                                            0 },	// WGS 72 / UTM zone 11S
	{  32312L, 32312L, "WGS72.UTM-12S",              "WGS_1972_UTM_Zone_12S",                                            0 },	// WGS 72 / UTM zone 12S
	{  32313L, 32313L, "WGS72.UTM-13S",              "WGS_1972_UTM_Zone_13S",                                            0 },	// WGS 72 / UTM zone 13S
	{  32314L, 32314L, "WGS72.UTM-14S",              "WGS_1972_UTM_Zone_14S",                                            0 },	// WGS 72 / UTM zone 14S
	{  32315L, 32315L, "WGS72.UTM-15S",              "WGS_1972_UTM_Zone_15S",                                            0 },	// WGS 72 / UTM zone 15S
	{  32316L, 32316L, "WGS72.UTM-16S",              "WGS_1972_UTM_Zone_16S",                                            0 },	// WGS 72 / UTM zone 16S
	{  32317L, 32317L, "WGS72.UTM-17S",              "WGS_1972_UTM_Zone_17S",                                            0 },	// WGS 72 / UTM zone 17S
	{  32318L, 32318L, "WGS72.UTM-18S",              "WGS_1972_UTM_Zone_18S",                                            0 },	// WGS 72 / UTM zone 18S
	{  32319L, 32319L, "WGS72.UTM-19S",              "WGS_1972_UTM_Zone_19S",                                            0 },	// WGS 72 / UTM zone 19S
	{  32320L, 32320L, "WGS72.UTM-20S",              "WGS_1972_UTM_Zone_20S",                                            0 },	// WGS 72 / UTM zone 20S
	{  32321L, 32321L, "WGS72.UTM-21S",              "WGS_1972_UTM_Zone_21S",                                            0 },	// WGS 72 / UTM zone 21S
	{  32322L, 32322L, "WGS72.UTM-22S",              "WGS_1972_UTM_Zone_22S",                                            0 },	// WGS 72 / UTM zone 22S
	{  32323L, 32323L, "WGS72.UTM-23S",              "WGS_1972_UTM_Zone_23S",                                            0 },	// WGS 72 / UTM zone 23S
	{  32324L, 32324L, "WGS72.UTM-24S",              "WGS_1972_UTM_Zone_24S",                                            0 },	// WGS 72 / UTM zone 24S
	{  32325L, 32325L, "WGS72.UTM-25S",              "WGS_1972_UTM_Zone_25S",                                            0 },	// WGS 72 / UTM zone 25S
	{  32326L, 32326L, "WGS72.UTM-26S",              "WGS_1972_UTM_Zone_26S",                                            0 },	// WGS 72 / UTM zone 26S
	{  32327L, 32327L, "WGS72.UTM-27S",              "WGS_1972_UTM_Zone_27S",                                            0 },	// WGS 72 / UTM zone 27S
	{  32328L, 32328L, "WGS72.UTM-28S",              "WGS_1972_UTM_Zone_28S",                                            0 },	// WGS 72 / UTM zone 28S
	{  32329L, 32329L, "WGS72.UTM-29S",              "WGS_1972_UTM_Zone_29S",                                            0 },	// WGS 72 / UTM zone 29S
	{  32330L, 32330L, "WGS72.UTM-30S",              "WGS_1972_UTM_Zone_30S",                                            0 },	// WGS 72 / UTM zone 30S
	{  32331L, 32331L, "WGS72.UTM-31S",              "WGS_1972_UTM_Zone_31S",                                            0 },	// WGS 72 / UTM zone 31S
	{  32332L, 32332L, "WGS72.UTM-32S",              "WGS_1972_UTM_Zone_32S",                                            0 },	// WGS 72 / UTM zone 32S
	{  32333L, 32333L, "WGS72.UTM-33S",              "WGS_1972_UTM_Zone_33S",                                            0 },	// WGS 72 / UTM zone 33S
	{  32334L, 32334L, "WGS72.UTM-34S",              "WGS_1972_UTM_Zone_34S",                                            0 },	// WGS 72 / UTM zone 34S
	{  32335L, 32335L, "WGS72.UTM-35S",              "WGS_1972_UTM_Zone_35S",                                            0 },	// WGS 72 / UTM zone 35S
	{  32336L, 32336L, "WGS72.UTM-36S",              "WGS_1972_UTM_Zone_36S",                                            0 },	// WGS 72 / UTM zone 36S
	{  32337L, 32337L, "WGS72.UTM-37S",              "WGS_1972_UTM_Zone_37S",                                            0 },	// WGS 72 / UTM zone 37S
	{  32338L, 32338L, "WGS72.UTM-38S",              "WGS_1972_UTM_Zone_38S",                                            0 },	// WGS 72 / UTM zone 38S
	{  32339L, 32339L, "WGS72.UTM-39S",              "WGS_1972_UTM_Zone_39S",                                            0 },	// WGS 72 / UTM zone 39S
	{  32340L, 32340L, "WGS72.UTM-40S",              "WGS_1972_UTM_Zone_40S",                                            0 },	// WGS 72 / UTM zone 40S
	{  32341L, 32341L, "WGS72.UTM-41S",              "WGS_1972_UTM_Zone_41S",                                            0 },	// WGS 72 / UTM zone 41S
	{  32342L, 32342L, "WGS72.UTM-42S",              "WGS_1972_UTM_Zone_42S",                                            0 },	// WGS 72 / UTM zone 42S
	{  32343L, 32343L, "WGS72.UTM-43S",              "WGS_1972_UTM_Zone_43S",                                            0 },	// WGS 72 / UTM zone 43S
	{  32344L, 32344L, "WGS72.UTM-44S",              "WGS_1972_UTM_Zone_44S",                                            0 },	// WGS 72 / UTM zone 44S
	{  32345L, 32345L, "WGS72.UTM-45S",              "WGS_1972_UTM_Zone_45S",                                            0 },	// WGS 72 / UTM zone 45S
	{  32346L, 32346L, "WGS72.UTM-46S",              "WGS_1972_UTM_Zone_46S",                                            0 },	// WGS 72 / UTM zone 46S
	{  32347L, 32347L, "WGS72.UTM-47S",              "WGS_1972_UTM_Zone_47S",                                            0 },	// WGS 72 / UTM zone 47S
	{  32348L, 32348L, "WGS72.UTM-48S",              "WGS_1972_UTM_Zone_48S",                                            0 },	// WGS 72 / UTM zone 48S
	{  32349L, 32349L, "WGS72.UTM-49S",              "WGS_1972_UTM_Zone_49S",                                            0 },	// WGS 72 / UTM zone 49S
	{  32350L, 32350L, "WGS72.UTM-50S",              "WGS_1972_UTM_Zone_50S",                                            0 },	// WGS 72 / UTM zone 50S
	{  32351L, 32351L, "WGS72.UTM-51S",              "WGS_1972_UTM_Zone_51S",                                            0 },	// WGS 72 / UTM zone 51S
	{  32352L, 32352L, "WGS72.UTM-52S",              "WGS_1972_UTM_Zone_52S",                                            0 },	// WGS 72 / UTM zone 52S
	{  32353L, 32353L, "WGS72.UTM-53S",              "WGS_1972_UTM_Zone_53S",                                            0 },	// WGS 72 / UTM zone 53S
	{  32354L, 32354L, "WGS72.UTM-54S",              "WGS_1972_UTM_Zone_54S",                                            0 },	// WGS 72 / UTM zone 54S
	{  32355L, 32355L, "WGS72.UTM-55S",              "WGS_1972_UTM_Zone_55S",                                            0 },	// WGS 72 / UTM zone 55S
	{  32356L, 32356L, "WGS72.UTM-56S",              "WGS_1972_UTM_Zone_56S",                                            0 },	// WGS 72 / UTM zone 56S
	{  32357L, 32357L, "WGS72.UTM-57S",              "WGS_1972_UTM_Zone_57S",                                            0 },	// WGS 72 / UTM zone 57S
	{  32358L, 32358L, "WGS72.UTM-58S",              "WGS_1972_UTM_Zone_58S",                                            0 },	// WGS 72 / UTM zone 58S
	{  32359L, 32359L, "WGS72.UTM-59S",              "WGS_1972_UTM_Zone_59S",                                            0 },	// WGS 72 / UTM zone 59S
	{  32360L, 32360L, "WGS72.UTM-60S",              "WGS_1972_UTM_Zone_60S",                                            0 },	// WGS 72 / UTM zone 60S
	{  32601L, 32601L, "UTM84-1N",                   "WGS_1984_UTM_Zone_1N",                                             1 },	// WGS 84 / UTM zone 1N
	{  32602L, 32602L, "UTM84-2N",                   "WGS_1984_UTM_Zone_2N",                                             1 },	// WGS 84 / UTM zone 2N
	{  32603L, 32603L, "UTM84-3N",                   "WGS_1984_UTM_Zone_3N",                                             1 },	// WGS 84 / UTM zone 3N
	{  32604L, 32604L, "UTM84-4N",                   "WGS_1984_UTM_Zone_4N",                                             1 },	// WGS 84 / UTM zone 4N
	{  32605L, 32605L, "UTM84-5N",                   "WGS_1984_UTM_Zone_5N",                                             1 },	// WGS 84 / UTM zone 5N
	{  32606L, 32606L, "UTM84-6N",                   "WGS_1984_UTM_Zone_6N",                                             1 },	// WGS 84 / UTM zone 6N
	{  32607L, 32607L, "UTM84-7N",                   "WGS_1984_UTM_Zone_7N",                                             1 },	// WGS 84 / UTM zone 7N
	{  32608L, 32608L, "UTM84-8N",                   "WGS_1984_UTM_Zone_8N",                                             1 },	// WGS 84 / UTM zone 8N
	{  32609L, 32609L, "UTM84-9N",                   "WGS_1984_UTM_Zone_9N",                                             1 },	// WGS 84 / UTM zone 9N
	{  32610L, 32610L, "UTM84-10N",                  "WGS_1984_UTM_Zone_10N",                                            1 },	// WGS 84 / UTM zone 10N
	{  32611L, 32611L, "UTM84-11N",                  "WGS_1984_UTM_Zone_11N",                                            1 },	// WGS 84 / UTM zone 11N
	{  32612L, 32612L, "UTM84-12N",                  "WGS_1984_UTM_Zone_12N",                                            1 },	// WGS 84 / UTM zone 12N
	{  32613L, 32613L, "UTM84-13N",                  "WGS_1984_UTM_Zone_13N",                                            1 },	// WGS 84 / UTM zone 13N
	{  32614L, 32614L, "UTM84-14N",                  "WGS_1984_UTM_Zone_14N",                                            1 },	// WGS 84 / UTM zone 14N
	{  32615L, 32615L, "UTM84-15N",                  "WGS_1984_UTM_Zone_15N",                                            1 },	// WGS 84 / UTM zone 15N
	{  32616L, 32616L, "UTM84-16N",                  "WGS_1984_UTM_Zone_16N",                                            1 },	// WGS 84 / UTM zone 16N
	{  32617L, 32617L, "UTM84-17N",                  "WGS_1984_UTM_Zone_17N",                                            1 },	// WGS 84 / UTM zone 17N
	{  32618L, 32618L, "UTM84-18N",                  "WGS_1984_UTM_Zone_18N",                                            1 },	// WGS 84 / UTM zone 18N
	{  32619L, 32619L, "UTM84-19N",                  "WGS_1984_UTM_Zone_19N",                                            1 },	// WGS 84 / UTM zone 19N
	{  32620L, 32620L, "UTM84-20N",                  "WGS_1984_UTM_Zone_20N",                                            1 },	// WGS 84 / UTM zone 20N
	{  32621L, 32621L, "UTM84-21N",                  "WGS_1984_UTM_Zone_21N",                                            1 },	// WGS 84 / UTM zone 21N
	{  32622L, 32622L, "UTM84-22N",                  "WGS_1984_UTM_Zone_22N",                                            1 },	// WGS 84 / UTM zone 22N
	{  32623L, 32623L, "UTM84-23N",                  "WGS_1984_UTM_Zone_23N",                                            1 },	// WGS 84 / UTM zone 23N
	{  32624L, 32624L, "UTM84-24N",                  "WGS_1984_UTM_Zone_24N",                                            1 },	// WGS 84 / UTM zone 24N
	{  32625L, 32625L, "UTM84-25N",                  "WGS_1984_UTM_Zone_25N",                                            1 },	// WGS 84 / UTM zone 25N
	{  32626L, 32626L, "UTM84-26N",                  "WGS_1984_UTM_Zone_26N",                                            1 },	// WGS 84 / UTM zone 26N
	{  32627L, 32627L, "UTM84-27N",                  "WGS_1984_UTM_Zone_27N",                                            1 },	// WGS 84 / UTM zone 27N
	{  32628L, 32628L, "UTM84-28N",                  "WGS_1984_UTM_Zone_28N",                                            1 },	// WGS 84 / UTM zone 28N
	{  32629L, 32629L, "UTM84-29N",                  "WGS_1984_UTM_Zone_29N",                                            1 },	// WGS 84 / UTM zone 29N
	{  32630L, 32630L, "UTM84-30N",                  "WGS_1984_UTM_Zone_30N",                                            1 },	// WGS 84 / UTM zone 30N
	{  32631L, 32631L, "UTM84-31N",                  "WGS_1984_UTM_Zone_31N",                                            1 },	// WGS 84 / UTM zone 31N
	{  32632L, 32632L, "UTM84-32N",                  "WGS_1984_UTM_Zone_32N",                                            1 },	// WGS 84 / UTM zone 32N
	{  32633L, 32633L, "UTM84-33N",                  "WGS_1984_UTM_Zone_33N",                                            1 },	// WGS 84 / UTM zone 33N
	{  32634L, 32634L, "UTM84-34N",                  "WGS_1984_UTM_Zone_34N",                                            1 },	// WGS 84 / UTM zone 34N
	{  32635L, 32635L, "UTM84-35N",                  "WGS_1984_UTM_Zone_35N",                                            1 },	// WGS 84 / UTM zone 35N
	{  32636L, 32636L, "UTM84-36N",                  "WGS_1984_UTM_Zone_36N",                                            1 },	// WGS 84 / UTM zone 36N
	{  32637L, 32637L, "UTM84-37N",                  "WGS_1984_UTM_Zone_37N",                                            1 },	// WGS 84 / UTM zone 37N
	{  32638L, 32638L, "UTM84-38N",                  "WGS_1984_UTM_Zone_38N",                                            1 },	// WGS 84 / UTM zone 38N
	{  32639L, 32639L, "UTM84-39N",                  "WGS_1984_UTM_Zone_39N",                                            1 },	// WGS 84 / UTM zone 39N
	{  32640L, 32640L, "UTM84-40N",                  "WGS_1984_UTM_Zone_40N",                                            1 },	// WGS 84 / UTM zone 40N
	{  32641L, 32641L, "UTM84-41N",                  "WGS_1984_UTM_Zone_41N",                                            1 },	// WGS 84 / UTM zone 41N
	{  32642L, 32642L, "UTM84-42N",                  "WGS_1984_UTM_Zone_42N",                                            1 },	// WGS 84 / UTM zone 42N
	{  32643L, 32643L, "UTM84-43N",                  "WGS_1984_UTM_Zone_43N",                                            1 },	// WGS 84 / UTM zone 43N
	{  32644L, 32644L, "UTM84-44N",                  "WGS_1984_UTM_Zone_44N",                                            1 },	// WGS 84 / UTM zone 44N
	{  32645L, 32645L, "UTM84-45N",                  "WGS_1984_UTM_Zone_45N",                                            1 },	// WGS 84 / UTM zone 45N
	{  32646L, 32646L, "UTM84-46N",                  "WGS_1984_UTM_Zone_46N",                                            1 },	// WGS 84 / UTM zone 46N
	{  32647L, 32647L, "UTM84-47N",                  "WGS_1984_UTM_Zone_47N",                                            1 },	// WGS 84 / UTM zone 47N
	{  32648L, 32648L, "UTM84-48N",                  "WGS_1984_UTM_Zone_48N",                                            1 },	// WGS 84 / UTM zone 48N
	{  32649L, 32649L, "UTM84-49N",                  "WGS_1984_UTM_Zone_49N",                                            1 },	// WGS 84 / UTM zone 49N
	{  32650L, 32650L, "UTM84-50N",                  "WGS_1984_UTM_Zone_50N",                                            1 },	// WGS 84 / UTM zone 50N
	{  32651L, 32651L, "UTM84-51N",                  "WGS_1984_UTM_Zone_51N",                                            1 },	// WGS 84 / UTM zone 51N
	{  32652L, 32652L, "UTM84-52N",                  "WGS_1984_UTM_Zone_52N",                                            1 },	// WGS 84 / UTM zone 52N
	{  32653L, 32653L, "UTM84-53N",                  "WGS_1984_UTM_Zone_53N",                                            1 },	// WGS 84 / UTM zone 53N
	{  32654L, 32654L, "UTM84-54N",                  "WGS_1984_UTM_Zone_54N",                                            1 },	// WGS 84 / UTM zone 54N
	{  32655L, 32655L, "UTM84-55N",                  "WGS_1984_UTM_Zone_55N",                                            1 },	// WGS 84 / UTM zone 55N
	{  32656L, 32656L, "UTM84-56N",                  "WGS_1984_UTM_Zone_56N",                                            1 },	// WGS 84 / UTM zone 56N
	{  32657L, 32657L, "UTM84-57N",                  "WGS_1984_UTM_Zone_57N",                                            1 },	// WGS 84 / UTM zone 57N
	{  32658L, 32658L, "UTM84-58N",                  "WGS_1984_UTM_Zone_58N",                                            1 },	// WGS 84 / UTM zone 58N
	{  32659L, 32659L, "UTM84-59N",                  "WGS_1984_UTM_Zone_59N",                                            1 },	// WGS 84 / UTM zone 59N
	{  32660L, 32660L, "UTM84-60N",                  "WGS_1984_UTM_Zone_60N",                                            1 },	// WGS 84 / UTM zone 60N
	{  32661L, 32661L, "WGS84.UPSNorth",             "UPS_North",                                                        0 },	// WGS 84 / UPS North
	{  32701L, 32701L, "UTM84-1S",                   "WGS_1984_UTM_Zone_1S",                                             1 },	// WGS 84 / UTM zone 1S
	{  32702L, 32702L, "UTM84-2S",                   "WGS_1984_UTM_Zone_2S",                                             1 },	// WGS 84 / UTM zone 2S
	{  32703L, 32703L, "UTM84-3S",                   "WGS_1984_UTM_Zone_3S",                                             1 },	// WGS 84 / UTM zone 3S
	{  32704L, 32704L, "UTM84-4S",                   "WGS_1984_UTM_Zone_4S",                                             1 },	// WGS 84 / UTM zone 4S
	{  32705L, 32705L, "UTM84-5S",                   "WGS_1984_UTM_Zone_5S",                                             1 },	// WGS 84 / UTM zone 5S
	{  32706L, 32706L, "UTM84-6S",                   "WGS_1984_UTM_Zone_6S",                                             1 },	// WGS 84 / UTM zone 6S
	{  32707L, 32707L, "UTM84-7S",                   "WGS_1984_UTM_Zone_7S",                                             1 },	// WGS 84 / UTM zone 7S
	{  32708L, 32708L, "UTM84-8S",                   "WGS_1984_UTM_Zone_8S",                                             1 },	// WGS 84 / UTM zone 8S
	{  32709L, 32709L, "UTM84-9S",                   "WGS_1984_UTM_Zone_9S",                                             1 },	// WGS 84 / UTM zone 9S
	{  32710L, 32710L, "UTM84-10S",                  "WGS_1984_UTM_Zone_10S",                                            1 },	// WGS 84 / UTM zone 10S
	{  32711L, 32711L, "UTM84-11S",                  "WGS_1984_UTM_Zone_11S",                                            1 },	// WGS 84 / UTM zone 11S
	{  32712L, 32712L, "UTM84-12S",                  "WGS_1984_UTM_Zone_12S",                                            1 },	// WGS 84 / UTM zone 12S
	{  32713L, 32713L, "UTM84-13S",                  "WGS_1984_UTM_Zone_13S",                                            1 },	// WGS 84 / UTM zone 13S
	{  32714L, 32714L, "UTM84-14S",                  "WGS_1984_UTM_Zone_14S",                                            1 },	// WGS 84 / UTM zone 14S
	{  32715L, 32715L, "UTM84-15S",                  "WGS_1984_UTM_Zone_15S",                                            1 },	// WGS 84 / UTM zone 15S
	{  32716L, 32716L, "UTM84-16S",                  "WGS_1984_UTM_Zone_16S",                                            1 },	// WGS 84 / UTM zone 16S
	{  32717L, 32717L, "UTM84-17S",                  "WGS_1984_UTM_Zone_17S",                                            1 },	// WGS 84 / UTM zone 17S
	{  32718L, 32718L, "UTM84-18S",                  "WGS_1984_UTM_Zone_18S",                                            1 },	// WGS 84 / UTM zone 18S
	{  32719L, 32719L, "UTM84-19S",                  "WGS_1984_UTM_Zone_19S",                                            1 },	// WGS 84 / UTM zone 19S
	{  32720L, 32720L, "UTM84-20S",                  "WGS_1984_UTM_Zone_20S",                                            1 },	// WGS 84 / UTM zone 20S
	{  32721L, 32721L, "UTM84-21S",                  "WGS_1984_UTM_Zone_21S",                                            1 },	// WGS 84 / UTM zone 21S
	{  32722L, 32722L, "UTM84-22S",                  "WGS_1984_UTM_Zone_22S",                                            1 },	// WGS 84 / UTM zone 22S
	{  32723L, 32723L, "UTM84-23S",                  "WGS_1984_UTM_Zone_23S",                                            1 },	// WGS 84 / UTM zone 23S
	{  32724L, 32724L, "UTM84-24S",                  "WGS_1984_UTM_Zone_24S",                                            1 },	// WGS 84 / UTM zone 24S
	{  32725L, 32725L, "UTM84-25S",                  "WGS_1984_UTM_Zone_25S",                                            1 },	// WGS 84 / UTM zone 25S
	{  32726L, 32726L, "UTM84-26S",                  "WGS_1984_UTM_Zone_26S",                                            1 },	// WGS 84 / UTM zone 26S
	{  32727L, 32727L, "UTM84-27S",                  "WGS_1984_UTM_Zone_27S",                                            1 },	// WGS 84 / UTM zone 27S
	{  32728L, 32728L, "UTM84-28S",                  "WGS_1984_UTM_Zone_28S",                                            1 },	// WGS 84 / UTM zone 28S
	{  32729L, 32729L, "UTM84-29S",                  "WGS_1984_UTM_Zone_29S",                                            1 },	// WGS 84 / UTM zone 29S
	{  32730L, 32730L, "UTM84-30S",                  "WGS_1984_UTM_Zone_30S",                                            1 },	// WGS 84 / UTM zone 30S
	{  32731L, 32731L, "UTM84-31S",                  "WGS_1984_UTM_Zone_31S",                                            1 },	// WGS 84 / UTM zone 31S
	{  32732L, 32732L, "UTM84-32S",                  "WGS_1984_UTM_Zone_32S",                                            1 },	// WGS 84 / UTM zone 32S
	{  32733L, 32733L, "UTM84-33S",                  "WGS_1984_UTM_Zone_33S",                                            1 },	// WGS 84 / UTM zone 33S
	{  32734L, 32734L, "UTM84-34S",                  "WGS_1984_UTM_Zone_34S",                                            1 },	// WGS 84 / UTM zone 34S
	{  32735L, 32735L, "UTM84-35S",                  "WGS_1984_UTM_Zone_35S",                                            1 },	// WGS 84 / UTM zone 35S
	{  32736L, 32736L, "UTM84-36S",                  "WGS_1984_UTM_Zone_36S",                                            1 },	// WGS 84 / UTM zone 36S
	{  32737L, 32737L, "UTM84-37S",                  "WGS_1984_UTM_Zone_37S",                                            1 },	// WGS 84 / UTM zone 37S
	{  32738L, 32738L, "UTM84-38S",                  "WGS_1984_UTM_Zone_38S",                                            1 },	// WGS 84 / UTM zone 38S
	{  32739L, 32739L, "UTM84-39S",                  "WGS_1984_UTM_Zone_39S",                                            1 },	// WGS 84 / UTM zone 39S
	{  32740L, 32740L, "UTM84-40S",                  "WGS_1984_UTM_Zone_40S",                                            1 },	// WGS 84 / UTM zone 40S
	{  32741L, 32741L, "UTM84-41S",                  "WGS_1984_UTM_Zone_41S",                                            1 },	// WGS 84 / UTM zone 41S
	{  32742L, 32742L, "UTM84-42S",                  "WGS_1984_UTM_Zone_42S",                                            1 },	// WGS 84 / UTM zone 42S
	{  32743L, 32743L, "UTM84-43S",                  "WGS_1984_UTM_Zone_43S",                                            1 },	// WGS 84 / UTM zone 43S
	{  32744L, 32744L, "UTM84-44S",                  "WGS_1984_UTM_Zone_44S",                                            1 },	// WGS 84 / UTM zone 44S
	{  32745L, 32745L, "UTM84-45S",                  "WGS_1984_UTM_Zone_45S",                                            1 },	// WGS 84 / UTM zone 45S
	{  32746L, 32746L, "UTM84-46S",                  "WGS_1984_UTM_Zone_46S",                                            1 },	// WGS 84 / UTM zone 46S
	{  32747L, 32747L, "UTM84-47S",                  "WGS_1984_UTM_Zone_47S",                                            1 },	// WGS 84 / UTM zone 47S
	{  32748L, 32748L, "UTM84-48S",                  "WGS_1984_UTM_Zone_48S",                                            1 },	// WGS 84 / UTM zone 48S
	{  32749L, 32749L, "UTM84-49S",                  "WGS_1984_UTM_Zone_49S",                                            1 },	// WGS 84 / UTM zone 49S
	{  32750L, 32750L, "UTM84-50S",                  "WGS_1984_UTM_Zone_50S",                                            1 },	// WGS 84 / UTM zone 50S
	{  32751L, 32751L, "UTM84-51S",                  "WGS_1984_UTM_Zone_51S",                                            1 },	// WGS 84 / UTM zone 51S
	{  32752L, 32752L, "UTM84-52S",                  "WGS_1984_UTM_Zone_52S",                                            1 },	// WGS 84 / UTM zone 52S
	{  32753L, 32753L, "UTM84-53S",                  "WGS_1984_UTM_Zone_53S",                                            1 },	// WGS 84 / UTM zone 53S
	{  32754L, 32754L, "UTM84-54S",                  "WGS_1984_UTM_Zone_54S",                                            1 },	// WGS 84 / UTM zone 54S
	{  32755L, 32755L, "UTM84-55S",                  "WGS_1984_UTM_Zone_55S",                                            1 },	// WGS 84 / UTM zone 55S
	{  32756L, 32756L, "UTM84-56S",                  "WGS_1984_UTM_Zone_56S",                                            1 },	// WGS 84 / UTM zone 56S
	{  32757L, 32757L, "UTM84-57S",                  "WGS_1984_UTM_Zone_57S",                                            1 },	// WGS 84 / UTM zone 57S
	{  32758L, 32758L, "UTM84-58S",                  "WGS_1984_UTM_Zone_58S",                                            1 },	// WGS 84 / UTM zone 58S
	{  32759L, 32759L, "UTM84-59S",                  "WGS_1984_UTM_Zone_59S",                                            1 },	// WGS 84 / UTM zone 59S
	{  32760L, 32760L, "UTM84-60S",                  "WGS_1984_UTM_Zone_60S",                                            1 },	// WGS 84 / UTM zone 60S
	{  32761L, 32761L, "WGS84.UPSSouth",             "UPS_South",                                                        0 },	// WGS 84 / UPS South
	{  32766L, 32766L, "WGS84.TM-36SE",              "WGS_1984_TM_36_SE",                                                0 },	// WGS 84 / TM 36 SE
	{      0L,     0L, "",                           "",                                                                 0 },	// End of table marker
};
struct csEsriDtmMap_
{
	long epsgNbr;
	char msiName [24];
	char esriName [96];
	unsigned short flags;		/* currently unused */
};
struct csEsriDtmMap_ csEsriDtmMap [] =
{
	{   6121L,  "Greek-GRS87",              "D_GGRS_1987",                            0 },	// Greek Geodetic Reference System 1987
	{   6122L,  "ATS77",                    "D_ATS_1977",                             1 },	// Average Terrestrial System 1977
	{   6123L,  "Kartasto66",               "D_KKJ",                                  0 },	// Kartastokoordinaattijarjestelma (1966)
	{   6124L,  "RT90",                     "D_RT_1990",                              1 },	// Rikets koordinatsystem 1990
	{   6125L,  "Samboja",                  "D_Samboja",                              2 },	// Samboja
	{   6126L,  "Lithuania94",              "D_Lithuania_1994",                       0 },	// Lithuania 1994 (ETRS89)
	{   6127L,  "Tete",                     "D_Tete",                                 0 },	// Tete
	{   6130L,  "Moznet",                   "D_Moznet",                               0 },	// Moznet (ITRF94)
	{   6131L,  "Indian60",                 "D_Indian_1960",                          0 },	// Indian 1960
	{   6132L,  "Final58",                  "D_FD_1958",                              0 },	// Final Datum 1958
	{   6133L,  "Estonia92",                "D_Estonia_1992",                         0 },	// Estonia 1992
	{   6134L,  "PDOSurvey93",              "D_PDO_1993",                             0 },	// PDO Survey Datum 1993
	{   6135L,  "OLDHI",                    "D_Old_Hawaiian",                         1 },	// Old Hawaiian
	{   6139L,  "PRVI",                     "D_Puerto_Rico",                          1 },	// Puerto Rico
	{   6140L,  "CSRS",                     "D_North_American_1983_CSRS98",           1 },	// NAD83 Canadian Spatial Reference System
	{   6141L,  "Israel",                   "D_Israel",                               0 },	// Israel
	{   6142L,  "Locodjo65",                "D_Locodjo_1965",                         0 },	// Locodjo 1965
	{   6143L,  "Abidjan87",                "D_Abidjan_1987",                         0 },	// Abidjan 1987
	{   6144L,  "Kalianpur37",              "D_Kalianpur_1937",                       0 },	// Kalianpur 1937
	{   6145L,  "Kalianpur62",              "D_Kalianpur_1962",                       0 },	// Kalianpur 1962
	{   6146L,  "Kalianpur75",              "D_Kalianpur_1975",                       0 },	// Kalianpur 1975
	{   6147L,  "Hanoi72",                  "D_Hanoi_1972",                           0 },	// Hanoi 1972
	{   6148L,  "Hartebeesthoek94",         "D_Hartebeesthoek_1994",                  0 },	// Hartebeesthoek94
	{   6149L,  "CH1903",                   "D_CH1903",                               0 },	// CH1903
	{   6150L,  "CH1903Plus",               "D_CH1903+",                              0 },	// CH1903+
	{   6151L,  "CHTRF95",                  "D_Swiss_TRF_1995",                       0 },	// Swiss Terrestrial Reference Frame 1995
	{   6152L,  "HPGN",                     "D_North_American_1983_HARN",             0 },	// NAD83 (High Accuracy Regional Network)
	{   6153L,  "Rassadiran",               "D_Rassadiran",                           0 },	// Rassadiran
	{   6154L,  "Europ50/77",               "D_European_1950_ED77",                   0 },	// European Datum 1950(1977)
	{   6155L,  "Dabola81",                 "D_Dabola",                               0 },	// Dabola 1981
	{   6156L,  "S-JTSK",                   "D_S_JTSK",                               1 },	// Jednotne Trigonometricke Site Katastralni
	{   6158L,  "NAPARIMA",                 "D_Naparima_1955",                        1 },	// Naparima 1955
	{   6159L,  "EuropLibyan79",            "D_European_Libyan_1979",                 0 },	// European Libyan Datum 1979
	{   6161L,  "Castillo",                 "D_Pampa_del_Castillo",                   0 },	// Pampa del Castillo
	{   6163L,  "YemenNtl96",               "D_Yemen_NGN_1996",                       0 },	// Yemen National Geodetic Network 1996
	{   6164L,  "SouthYemen",               "D_South_Yemen",                          0 },	// South Yemen
	{   6165L,  "Bissau",                   "D_Bissau",                               0 },	// Bissau
	{   6166L,  "Korean95",                 "D_Korean_Datum_1995",                    0 },	// Korean Datum 1995
	{   6167L,  "NZGD2000",                 "D_NZGD_2000",                            1 },	// New Zealand Geodetic Datum 2000
	{   6168L,  "Accra",                    "D_Accra",                                0 },	// Accra
	{   6169L,  "AmSamoa62",                "D_American_Samoa_1962",                  0 },	// American Samoa 1962
	{   6170L,  "GRSSA",                    "D_SIRGAS",                               0 },	// Sistema de Referencia Geocentrico para America del Sur 1995
	{   6171L,  "RGF93",                    "D_RGF_1993",                             1 },	// Reseau Geodesique Francais 1993
	{   6172L,  "PosGAr",                   "D_POSGAR",                               2 },	// Posiciones Geodesicas Argentinas
	{   6173L,  "IRENET95",                 "D_IRENET95",                             0 },	// IRENET95
	{   6175L,  "SierraLeone68",            "D_Sierra_Leone_1968",                    0 },	// Sierra Leone 1968
	{   6176L,  "Antarctic98",              "D_Australian_Antarctic_1998",            0 },	// Australian Antarctic Datum 1998
	{   6180L,  "Estonia97",                "D_Estonia_1997",                         0 },	// Estonia 1997
	{   6181L,  "Luxembourg30",             "D_Luxembourg_1930",                      0 },	// Luxembourg 1930
	{   6182L,  "OBSRV66",                  "D_Observ_Meteorologico_1939",            1 },	// Azores Occidental Islands 1939
	{   6183L,  "AZORES",                   "D_Graciosa_Base_SW_1948",                1 },	// Azores Central Islands 1948
	{   6184L,  "SAOBRAZ",                  "D_Sao_Braz",                             1 },	// Azores Oriental Islands 1940
	{   6188L,  "OSNI52",                   "D_OSNI_1952",                            0 },	// OSNI 1952
	{   6189L,  "REGVEN",                   "D_REGVEN",                               0 },	// Red Geodesica Venezolana
	{   6190L,  "PGA98",                    "D_POSGAR_1998",                          0 },	// Posiciones Geodesicas Argentinas 1998
	{   6192L,  "Douala48",                 "D_Douala_1948",                          0 },	// Douala 1948
	{   6193L,  "Manoca62",                 "D_Manoca_1962",                          0 },	// Manoca 1962
	{   6194L,  "Qornoq27",                 "D_Qornoq",                               0 },	// Qornoq 1927
	{   6195L,  "Scoresbysund52",           "D_Scoresbysund_1952",                    0 },	// Scoresbysund 1952
	{   6196L,  "Ammassalik58",             "D_Ammassalik_1958",                      0 },	// Ammassalik 1958
	{   6201L,  "ADINDAN",                  "D_Adindan",                              1 },	// Adindan
	{   6202L,  "AGD66",                    "D_Australian_1966",                      1 },	// Australian Geodetic Datum 1966
	{   6203L,  "AGD84",                    "D_Australian_1984",                      1 },	// Australian Geodetic Datum 1984
	{   6204L,  "AINELABD",                 "D_Ain_el_Abd_1970",                      1 },	// Ain el Abd 1970
	{   6205L,  "AFGOOYE",                  "D_Afgooye",                              1 },	// Afgooye
	{   6207L,  "Lisbon37",                 "D_Lisbon",                               0 },	// Lisbon 1937
	{   6208L,  "Aratu",                    "D_Aratu",                                0 },	// Aratu
	{   6209L,  "ARC1950",                  "D_Arc_1950",                             1 },	// Arc 1950
	{   6210L,  "ARC1960",                  "D_Arc_1960",                             1 },	// Arc 1960
	{   6211L,  "DJAKRTA",                  "D_Batavia",                              1 },	// Batavia
	{   6212L,  "Barbados38",               "D_Barbados_1938",                        0 },	// Barbados 1938
	{   6214L,  "Beijing54",                "D_Beijing_1954",                         1 },	// Beijing 1954
	{   6216L,  "BERMUDA",                  "D_Bermuda_1957",                         1 },	// Bermuda 1957
	{   6218L,  "BOGOTA",                   "D_Bogota",                               1 },	// Bogota 1975
	{   6219L,  "BukitRimpah",              "D_Bukit_Rimpah",                         0 },	// Bukit Rimpah
	{   6220L,  "Camacupa",                 "D_Camacupa",                             0 },	// Camacupa
	{   6221L,  "CAMPO",                    "D_Campo_Inchauspe",                      1 },	// Campo Inchauspe
	{   6222L,  "CAPE-1",                   "D_Cape",                                 1 },	// Cape
	{   6223L,  "CARTHAGE",                 "D_Carthage",                             1 },	// Carthage
	{   6224L,  "CHAU",                     "D_Chua",                                 1 },	// Chua
	{   6225L,  "CORREGO",                  "D_Corrego_Alegre",                       1 },	// Corrego Alegre
	{   6227L,  "DeirEzZor",                "D_Deir_ez_Zor",                          0 },	// Deir ez Zor
	{   6229L,  "OLD-EGYP",                 "D_Egypt_1907",                           1 },	// Egypt 1907
	{   6230L,  "ED50",                     "D_European_1950",                        1 },	// European Datum 1950
	{   6231L,  "Europ87",                  "D_European_1987",                        0 },	// European Datum 1987
	{   6232L,  "OMAN",                     "D_Fahud",                                1 },	// Fahud
	{   6233L,  "GNDAJIKA",                 "D_Gandajika_1970",                       3 },	// Gandajika 1970
	{   6236L,  "HuTzuShan",                "D_Hu_Tzu_Shan",                          0 },	// Hu Tzu Shan
	{   6237L,  "HD-72",                    "D_Hungarian_1972",                       1 },	// Hungarian Datum 1972
	{   6238L,  "Indonesian74",             "D_Indonesian_1974",                      0 },	// Indonesian Datum 1974
	{   6239L,  "Indian54",                 "D_Indian_1954",                          0 },	// Indian 1954
	{   6240L,  "Indian75",                 "D_Indian_1975",                          0 },	// Indian 1975
	{   6242L,  "Jamaica69",                "D_Jamaica_1969",                         0 },	// Jamaica 1969
	{   6244L,  "KANDWALA",                 "D_Kandawala",                            1 },	// Kandawala
	{   6245L,  "KERTAU48",                 "D_Kertau",                               1 },	// Kertau 1968
	{   6246L,  "KuwaitOilCo",              "D_Kuwait_Oil_Company",                   0 },	// Kuwait Oil Company
	{   6247L,  "LaCanoa",                  "D_La_Canoa",                             0 },	// La Canoa
	{   6248L,  "PSAD56",                   "D_Provisional_S_American_1956",          1 },	// Provisional South American Datum 1956
	{   6250L,  "Leigon",                   "D_Leigon",                               0 },	// Leigon
	{   6251L,  "LIBERIA",                  "D_Liberia_1964",                         1 },	// Liberia 1964
	{   6253L,  "LUZON",                    "D_Luzon_1911",                           1 },	// Luzon 1911
	{   6254L,  "HitoXVIII63",              "D_Hito_XVIII_1963",                      0 },	// Hito XVIII 1963
	{   6255L,  "HeratNorth",               "D_Herat_North",                          0 },	// Herat North
	{   6256L,  "MAHE1971",                 "D_Mahe_1971",                            1 },	// Mahe 1971
	{   6257L,  "Makassar",                 "D_Makassar",                             0 },	// Makassar
	{   6258L,  "ETRF89",                   "D_ETRF_1989",                            1 },	// European Terrestrial Reference System 1989
	{   6259L,  "Malongo87",                "D_Malongo_1987",                         0 },	// Malongo 1987
	{   6260L,  "Manoca",                   "D_Manoca",                               2 },	// Manoca
	{   6261L,  "MERCHICH",                 "D_Merchich",                             1 },	// Merchich
	{   6262L,  "MASSAWA",                  "D_Massawa",                              1 },	// Massawa
	{   6263L,  "MINNA",                    "D_Minna",                                1 },	// Minna
	{   6264L,  "Mhast",                    "D_Mhast",                                2 },	// Mhast
	{   6265L,  "ROME1940",                 "D_Monte_Mario",                          1 },	// Monte Mario
	{   6266L,  "Mporaloko",                "D_Mporaloko",                            0 },	// M'poraloko
	{   6267L,  "NAD27",                    "D_North_American_1927",                  1 },	// North American Datum 1927
	{   6268L,  "MICHIGAN",                 "D_North_American_Michigan",              1 },	// NAD Michigan
	{   6269L,  "NAD83",                    "D_North_American_1983",                  1 },	// North American Datum 1983
	{   6270L,  "NHRWN-O",                  "D_Nahrwan_1967",                         1 },	// Nahrwan 1967
	{   6271L,  "Naparima72",               "D_Naparima_1972",                        0 },	// Naparima 1972
	{   6272L,  "NZGD49",                   "D_New_Zealand_1949",                     1 },	// New Zealand Geodetic Datum 1949
	{   6273L,  "NGO48",                    "D_NGO_1948",                             0 },	// NGO 1948
	{   6274L,  "Datum73",                  "D_Datum_73",                             0 },	// Datum 73
	{   6275L,  "NTF",                      "D_NTF",                                  1 },	// Nouvelle Triangulation Francaise
	{   6277L,  "OSGB",                     "D_OSGB_1936",                            1 },	// OSGB 1936
	{   6281L,  "Palestine23",              "D_Palestine_1923",                       0 },	// Palestine 1923
	{   6282L,  "PointeNoire",              "D_Pointe_Noire",                         0 },	// Congo 1960 Pointe Noire
	{   6283L,  "GDA94",                    "D_GDA_1994",                             1 },	// Geocentric Datum of Australia 1994
	{   6284L,  "Pulkovo1942",              "D_Pulkovo_1942",                         1 },	// Pulkovo 1942
	{   6285L,  "Qatar74",                  "D_Qatar",                                0 },	// Qatar 1974
	{   6286L,  "QATAR",                    "D_Qatar_1948",                           1 },	// Qatar 1948
	{   6287L,  "QORNOQ",                   "D_Qornoq",                               3 },	// Qornoq
	{   6289L,  "Amersfoort",               "D_Amersfoort",                           1 },	// Amersfoort
	{   6291L,  "SAD69",                    "D_South_American_1969",                  2 },	// South American Datum 1969
	{   6292L,  "SAPPER",                   "D_Sapper_Hill_1943",                     1 },	// Sapper Hill 1943
	{   6293L,  "SCHWARZK",                 "D_Schwarzeck",                           1 },	// Schwarzeck
	{   6294L,  "Segora",                   "D_Segora",                               2 },	// Segora
	{   6297L,  "Tananarive25",             "D_Tananarive_1925",                      0 },	// Tananarive 1925
	{   6298L,  "TMBLI-B",                  "D_Timbalai_1948",                        1 },	// Timbalai 1948
	{   6299L,  "TM65",                     "D_TM65",                                 0 },	// TM65
	{   6301L,  "TOKYO",                    "D_Tokyo",                                1 },	// Tokyo
	{   6302L,  "Trinidad03",               "D_Trinidad_1903",                        0 },	// Trinidad 1903
	{   6304L,  "Voirol1875",               "D_Voirol_1875",                          0 },	// Voirol 1875
	{   6307L,  "NordSahara59",             "D_Nord_Sahara_1959",                     0 },	// Nord Sahara 1959
	{   6309L,  "Yacare",                   "D_Yacare",                               0 },	// Yacare
	{   6311L,  "ZANDERIJ",                 "D_Zanderij",                             1 },	// Zanderij
	{   6312L,  "MGI",                      "D_MGI",                                  0 },	// Militar-Geographische Institut
	{   6313L,  "Belge72",                  "D_Belge_1972",                           0 },	// Reseau National Belge 1972
	{   6314L,  "DHDN",                     "D_Deutsche_Hauptdreiecksnetz",           0 },	// Deutsches Hauptdreiecksnetz
	{   6315L,  "Conakry05",                "D_Conakry_1905",                         0 },	// Conakry 1905
	{   6316L,  "DealulPiscului33",         "D_Dealul_Piscului_1933",                 0 },	// Dealul Piscului 1933
	{   6317L,  "DealulPiscului70",         "D_Dealul_Piscului_1970",                 0 },	// Dealul Piscului 1970
	{   6318L,  "NtlGeodeticNet",           "D_NGN",                                  0 },	// National Geodetic Network
	{   6319L,  "KuwaitUtility",            "D_Kuwait_Utility",                       0 },	// Kuwait Utility
	{   6322L,  "WGS72",                    "D_WGS_1972",                             1 },	// World Geodetic System 1972
	{   6324L,  "WGS72-TBE",                "D_WGS_1972_BE",                          0 },	// WGS 72 Transit Broadcast Ephemeris
	{   6326L,  "WGS84",                    "D_WGS_1984",                             1 },	// World Geodetic System 1984
	{   6601L,  "Antigua43",                "D_Antigua_1943",                         0 },	// Antigua 1943
	{   6602L,  "Dominica45",               "D_Dominica_1945",                        0 },	// Dominica 1945
	{   6603L,  "Grenada53",                "D_Grenada_1953",                         0 },	// Grenada 1953
	{   6604L,  "Montserrat58",             "D_Montserrat_1958",                      0 },	// Montserrat 1958
	{   6605L,  "StKitts55",                "D_St_Kitts_1955",                        0 },	// St. Kitts 1955
	{   6606L,  "StLucia55",                "D_St_Lucia_1955",                        0 },	// St. Lucia 1955
	{   6607L,  "StVincent45",              "D_St_Vincent_1945",                      0 },	// St. Vincent 1945
	{   6610L,  "Xian80",                   "D_Xian_1980",                            1 },	// Xian 1980
	{   6611L,  "HongKong80",               "D_Hong_Kong_1980",                       0 },	// Hong Kong 1980
	{   6612L,  "JGD2000",                  "D_JGD_2000",                             0 },	// Japanese Geodetic Datum 2000
	{   6613L,  "Segara",                   "D_Gunung_Segara",                        0 },	// Gunung Segara
	{   6614L,  "QatarNtl95",               "D_QND_1995",                             0 },	// Qatar National Datum 1995
	{   6615L,  "MADEIRA",                  "D_Porto_Santo_1936",                     1 },	// Porto Santo 1936
	{   6616L,  "SelvagemGrande",           "D_Selvagem_Grande_1938",                 0 },	// Selvagem Grande
	{   6618L,  "SA1969",                   "D_South_American_1969",                  1 },	// South American Datum 1969
	{   6619L,  "SWEREF99",                 "D_SWEREF99",                             0 },	// SWEREF99
	{   6620L,  "Point58",                  "D_Point_58",                             0 },	// Point 58
	{   6621L,  "FortMarigot",              "D_Fort_Marigot",                         0 },	// Fort Marigot
	{   6622L,  "StAnne",                   "D_Sainte_Anne",                          0 },	// Guadeloupe 1948
	{   6623L,  "CSG67",                    "D_CSG_1967",                             0 },	// Centre Spatial Guyanais 1967
	{   6624L,  "Guyane95",                 "D_RGFG_1995",                            0 },	// Reseau Geodesique Francais Guyane 1995
	{   6625L,  "FortDesaix",               "D_Fort_Desaix",                          0 },	// Martinique 1938
	{   6626L,  "REUNION",                  "D_Reunion",                              1 },	// Reunion 1947
	{   6627L,  "Reunion92",                "D_RGR_1992",                             0 },	// Reseau Geodesique de la Reunion 1992
	{   6628L,  "Tahiti",                   "D_Tahiti",                               0 },	// Tahiti 52
	{   6629L,  "Tahaa",                    "D_Tahaa",                                0 },	// Tahaa 54
	{   6630L,  "IGN72/NH",                 "D_IGN72_Nuku_Hiva",                      0 },	// IGN72 Nuku Hiva
	{   6631L,  "K01949",                   "D_K0_1949",                              2 },	// K0 1949
	{   6632L,  "Combani50",                "D_Combani_1950",                         0 },	// Combani 1950
	{   6633L,  "IGN56Lifou",               "D_IGN56_Lifou",                          0 },	// IGN56 Lifou
	{   6634L,  "IGN72GrandeTerre",         "D_IGN72_Grande_Terre",                   0 },	// IGN72 Grande Terre
	{   6635L,  "ST87Ouvea",                "D_ST87_Ouvea",                           2 },	// ST87 Ouvea
	{   6636L,  "Petrels72",                "D_Petrels_1972",                         0 },	// Petrels 1972
	{   6637L,  "Perroud50",                "D_Pointe_Geologie_Perroud_1950",         0 },	// Pointe Geologie Perroud 1950
	{   6638L,  "Miquelon50",               "D_Saint_Pierre_et_Miquelon_1950",        0 },	// Saint Pierre et Miquelon 1950
	{   6639L,  "MOP78",                    "D_MOP78",                                0 },	// MOP78
	{   6640L,  "Antilles91",               "D_RRAF_1991",                            0 },	// Reseau de Reference des Antilles Francaises 1991
	{   6641L,  "IGN53/Mare",               "D_IGN53_Mare",                           0 },	// IGN53 Mare
	{   6642L,  "ST84IleDesPins",           "D_ST84_Ile_des_Pins",                    0 },	// ST84 Ile des Pins
	{   6643L,  "ST71Belep",                "D_ST71_Belep",                           0 },	// ST71 Belep
	{   6644L,  "NEA74Noumea",              "D_NEA74_Noumea",                         0 },	// NEA74 Noumea
	{   6645L,  "Caledonie91",              "D_RGNC_1991",                            2 },	// Reseau Geodesique Nouvelle Caledonie 1991
	{   6657L,  "Reykjavik",                "D_Reykjavik_1900",                       1 },	// Reykjavik 1900
	{   6658L,  "HJORSEY",                  "D_Hjorsey_1955",                         1 },	// Hjorsey 1955
	{   6659L,  "ISN93",                    "D_Islands_Network_1993",                 1 },	// Islands Network 1993
	{   6660L,  "Helle1954",                "D_Helle_1954",                           0 },	// Helle 1954
	{   6661L,  "Latvia1992",               "D_Latvia_1992",                          0 },	// Latvia 1992
	{   6663L,  "PortoSanto1995",           "D_Porto_Santo_1995",                     0 },	// Porto Santo 1995
	{   6664L,  "AzoresEast95",             "D_Azores_Oriental_Islands_1995",         0 },	// Azores Oriental Islands 1995
	{   6665L,  "AzoresCntrl95",            "D_Azores_Central_Islands_1995",          0 },	// Azores Central Islands 1995
	{   6666L,  "Lisbon1890",               "D_Lisbon_1890",                          0 },	// Lisbon 1890
	{   6667L,  "IraqKuwait1992",           "D_Iraq_Kuwait_Boundary_1992",            0 },	// Iraq-Kuwait Boundary Datum 1992
	{   6668L,  "EUROP79",                  "D_European_1979",                        1 },	// European Datum 1979
	{   6670L,  "IGM1995",                  "D_IGM_1995",                             0 },	// Istituto Geografico Militaire 1995
	{   6672L,  "CHATHAM",                  "D_Chatham_Island_1971",                  1 },	// Chatham Islands Datum 1971
	{   6673L,  "Chatham1979",              "D_Chatham_Islands_1979",                 0 },	// Chatham Islands Datum 1979
	{   6674L,  "SIRGAS2000",               "D_SIRGAS_2000",                          0 },	// Sistema de Referencia Geocentrico para America del Sur 2000
	{   6675L,  "GUAM63",                   "D_Guam_1963",                            1 },	// Guam 1963
	{   6678L,  "Lao1997",                  "D_Lao_National_Datum_1997",              0 },	// Lao National Datum 1997
	{   6679L,  "Jouik1961",                "D_Jouik_1961",                           0 },	// Jouik 1961
	{   6680L,  "Nouakchott1965",           "D_Nouakchott_1965",                      0 },	// Nouakchott 1965
	{   6682L,  "Gulshan",                  "D_Gulshan_303",                          0 },	// Gulshan 303
	{   6684L,  "Gan1970",                  "D_Gan_1970",                             0 },	// Gan 1970
	{   6686L,  "MAGNA",                    "D_MAGNA",                                0 },	// Marco Geocentrico Nacional de Referencia
	{   6698L,  "KERGUELN",                 "D_Kerguelen_Island_1949",                1 },	// IGN 1962 Kerguelen
	{   6707L,  "Tern1961",                 "D_Tern_Island_1961",                     0 },	// Tern Island 1961
	{   6712L,  "ASCENSN",                  "D_Ascension_Island_1958",                1 },	// Ascension Island 1958
	{   6713L,  "Ayabelle",                 "D_Ayabelle",                             0 },	// Ayabelle Lighthouse
	{   6714L,  "BELLEVUE",                 "D_Bellevue_IGN",                         1 },	// Bellevue
	{   6715L,  "CampAreaAstro",            "D_Camp_Area",                            0 },	// Camp Area Astro
	{   6717L,  "CANAVRL",                  "D_Cape_Canaveral",                       1 },	// Cape Canaveral
	{   6719L,  "EASTER",                   "D_Easter_Island_1967",                   1 },	// Easter Island 1967
	{   6725L,  "JHNSTN",                   "D_Johnston_Island_1961",                 1 },	// Johnston Island 1961
	{   6727L,  "MIDWAY",                   "D_Midway_1961",                          1 },	// Midway 1961
	{   6728L,  "CANARY",                   "D_Pico_de_Las_Nieves",                   1 },	// Pico de la Nieves
	{   6729L,  "PITCAIRN",                 "D_Pitcairn_1967",                        1 },	// Pitcairn 1967
	{   6731L,  "VITI",                     "D_Viti_Levu_1916",                       3 },	// Viti Levu 1916
	{   6733L,  "Wake1952",                 "D_Wake_Island_1952",                     0 },	// Wake Island 1952
	{   6734L,  "TRISTAN",                  "D_Tristan_1968",                         1 },	// Tristan 1968
	{   6735L,  "Kusaie1951",               "D_Kusaie_1951",                          0 },	// Kusaie 1951
	{   6736L,  "DeceptionIsland",          "D_Deception_Island",                     0 },	// Deception Island
	{   6738L,  "HONGKONG",                 "D_Hong_Kong_1963",                       1 },	// Hong Kong 1963
	{      0L,  "",                         "",                                       0 },	// End of table marker
};
struct csEsriElpMap_
{
	long epsgNbr;
	char msiName [24];
	char esriName [96];
};
struct csEsriElpMap_ csEsriElpMap [] =
{
	{   7001L,  "AIRY30",                 "Airy_1830"                      },	// Airy 1830
	{   7002L,  "AIRY-MOD",               "Airy_Modified"                  },	// Airy Modified 1849
	{   7003L,  "ANS66",                  "Australian"                     },	// Australian National Spheroid
	{   7004L,  "BESSEL",                 "Bessel_1841"                    },	// Bessel 1841
	{   7005L,  "BESL-MOD",               "Bessel_Modified"                },	// Bessel Modified
	{   7006L,  "BESL-NMB",               "Bessel_Namibia"                 },	// Bessel Namibia
	{   7007L,  "CLRK58",                 "Clarke_1858"                    },	// Clarke 1858
	{   7008L,  "CLRK66",                 "Clarke_1866"                    },	// Clarke 1866
	{   7009L,  "MICHIGAN",               "Clarke_1866_Michigan"           },	// Clarke 1866 Michigan
	{   7010L,  "CLRK-PAL",               "Clarke_1880_Benoit"             },	// Clarke 1880 (Benoit)
	{   7011L,  "CLRK-IGN",               "Clarke_1880_IGN"                },	// Clarke 1880 (IGN)
	{   7012L,  "CLRK-RGS",               "Clarke_1880_RGS"                },	// Clarke 1880 (RGS)
	{   7013L,  "CLRK-ARC",               "Clarke_1880_Arc"                },	// Clarke 1880 (Arc)
	{   7014L,  "CLRK22",                 "Clarke_1880_SGA"                },	// Clarke 1880 (SGA 1922)
	{   7015L,  "EVEREST",                "Everest_Adjustment_1937"        },	// Everest 1830 (1937 Adjustment)
	{   7016L,  "Everest1830/67",         "Everest_Definition_1967"        },	// Everest 1830 (1967 Definition)
	{   7018L,  "EVRST-MD",               "Everest_1830_Modified"          },	// Everest 1830 Modified
	{   7019L,  "GRS1980",                "GRS_1980"                       },	// GRS 1980
	{   7020L,  "HLMRT06",                "Helmert_1906"                   },	// Helmert 1906
	{   7021L,  "IndonesianNtl",          "Indonesian"                     },	// Indonesian National Spheroid
	{   7022L,  "INTNL",                  "International_1924"             },	// International 1924
	{   7024L,  "KRASOV",                 "Krasovsky_1940"                 },	// Krassowsky 1940
	{   7025L,  "NWL-9D",                 "NWL_9D"                         },	// NWL 9D
	{   7027L,  "PLESSIS",                "Plessis_1817"                   },	// Plessis 1817
	{   7028L,  "STRU1860",               "Struve_1860"                    },	// Struve 1860
	{   7029L,  "WAR-OFC",                "War_Office"                     },	// War Office
	{   7030L,  "WGS84",                  "WGS_1984"                       },	// WGS 84
	{   7031L,  "GEM-10C",                "GEM_10C"                        },	// GEM 10C
	{   7032L,  "OSU86F",                 "OSU_86F"                        },	// OSU86F
	{   7033L,  "OSU91A",                 "OSU_91A"                        },	// OSU91A
	{   7034L,  "Clrk80-Strasser",        "Clarke_1880"                    },	// Clarke 1880
	{   7035L,  "SPHERE-1",               "Sphere"                         },	// Sphere
	{   7036L,  "GRS1967",                "GRS_1967"                       },	// GRS 1967
	{   7041L,  "ATS77",                  "ATS_1977"                       },	// Average Terrestrial System 1977
	{   7042L,  "Everest1830",            "Everest_1830"                   },	// Everest (1830 Definition)
	{   7043L,  "WGS72",                  "WGS_1972"                       },	// WGS 72
	{   7044L,  "Everest1830Def62",       "Everest_Definition_1962"        },	// Everest 1830 (1962 Definition)
	{   7045L,  "Everest1830Def75",       "Everest_Definition_1975"        },	// Everest 1830 (1975 Definition)
	{   7046L,  "BeslNmb-GLM",            "Bessel_Namibia"                 },	// Bessel Namibia (GLM)
	{   7049L,  "Xian80",                 "Xian_1980"                      },	// Xian 1980
	{   7050L,  "SA1969",                 "GRS_1967_Truncated"             },	// GRS 1967 (SAD69)
	{   7051L,  "DANEMARK",               "Danish_1876"                    },	// Danish 1876
	{   7052L,  "Clarke66AuthalicSphere", "Sphere_Clarke_1866_Authalic"    },	// Clarke 1866 Authalic Sphere
	{   7053L,  "HOUGH",                  "Hough_1960"                     },	// Hough 1960
	{   7056L,  "Everest1969/RSO",        "Everest_Modified_1969"          },	// Everest 1830 (RSO 1969)
	{      0L,  "",                       ""                               },	// End of table marker
};
Const char* EXP_LVL1 CS_esriName2Msi (Const char* esriName,unsigned short* flags)
{
	Const char* msiNamePtr = 0;
	struct csEsriNbrMap_ *tblPtr;

	if (flags != 0) *flags = 0;
	for (tblPtr = csEsriNbrMap;tblPtr->esriName [0] != '\0';tblPtr += 1)
	{
		if (!CS_stricmp (tblPtr->esriName,esriName))
		{
			msiNamePtr = tblPtr->msiName;
			if (flags != 0)
			{
				*flags = tblPtr->flags;
			}
			break;
		}
	}
	return msiNamePtr;
}
Const char* EXP_LVL1 CS_msiName2Esri (Const char* msiName)
{
	Const char* esriNamePtr = 0; 
	struct csEsriNbrMap_ *tblPtr;

	for (tblPtr = csEsriNbrMap;tblPtr->esriName [0] != '\0';tblPtr += 1)
	{
		if (!CS_stricmp (tblPtr->msiName,msiName))
		{
			esriNamePtr = tblPtr->esriName;
			break;
		}
	}
	return esriNamePtr;
}
long EXP_LVL1 CS_esriName2EpsgNbr (Const char* esriName)
{
	long epsgNbr = -1;
	const struct csEsriNbrMap_ *tblPtr;

	for (tblPtr = csEsriNbrMap;tblPtr->esriName [0] != '\0';tblPtr += 1)
	{
		if (!CS_stricmp (tblPtr->esriName,esriName))
		{
			epsgNbr = tblPtr->epsgNbr;
			break;
		}
	}
	return epsgNbr;
}
long EXP_LVL1 CS_esriNbr2Epsg (long esriNbr,unsigned short* flags)
{
	long epsgNbr = -1;
	const struct csEsriNbrMap_ *tblPtr;
	
	if (flags != 0) *flags = 0;
	for (tblPtr = csEsriNbrMap;tblPtr->esriNbr != 0;tblPtr += 1)
	{
		if (tblPtr->esriNbr == esriNbr)
		{
			epsgNbr = tblPtr->epsgNbr;
			if (flags != 0) *flags = tblPtr->flags;
			break;
		}
	}
	return epsgNbr;
}
long EXP_LVL1 CS_epsgNbr2Esri (long epsgNbr,unsigned short* flags)
{
	long esriNbr = 0;
	const struct csEsriNbrMap_ *tblPtr;

	if (flags != 0) *flags = 0;
	for (tblPtr = csEsriNbrMap;tblPtr->esriNbr != 0;tblPtr += 1)
	{
		if (tblPtr->epsgNbr == epsgNbr)
		{
			esriNbr = tblPtr->esriNbr;
			if (flags != 0) *flags = tblPtr->flags;
			break;
		}
	}
	return esriNbr;
}
Const char* EXP_LVL1 CS_epsgNbr2EsriName (long epsgNbr)
{
	Const char* esriNamePtr = 0;
	const struct csEsriNbrMap_ *tblPtr;

	for (tblPtr = csEsriNbrMap;tblPtr->esriNbr != 0;tblPtr += 1)
	{
		if (tblPtr->epsgNbr == epsgNbr)
		{
			esriNamePtr = tblPtr->esriName;
			break;
		}
	}
	return esriNamePtr;
}
Const char* EXP_LVL1 CS_esriNbr2Name (long esriNbr)
{
	Const char* esriNamePtr = 0;
	const struct csEsriNbrMap_ *tblPtr;

	for (tblPtr = csEsriNbrMap;tblPtr->esriNbr != 0;tblPtr += 1)
	{
		if (tblPtr->esriNbr == esriNbr)
		{
			esriNamePtr = tblPtr->esriName;
		}
	}
	return esriNamePtr;
}
long EXP_LVL1 CS_esriName2Nbr (Const char* esriName)
{
	long esriNbr = -1;
	const struct csEsriNbrMap_ *tblPtr;

	for (tblPtr = csEsriNbrMap;tblPtr->esriNbr != 0;tblPtr += 1)
	{
		if (!CS_stricmp (tblPtr->esriName,esriName))
		{
			esriNbr = tblPtr->esriNbr;
			break;
		}
	}
	return esriNbr;
}
Const char* EXP_LVL1 CS_esriNameByIdx (unsigned short index,unsigned short* flags)
{
	Const char* esriName = 0;
	const unsigned short idxMax = sizeof (csEsriNbrMap) / sizeof (struct csEsriNbrMap_);

	if (flags != 0) *flags = 0;
	if (index < idxMax)
	{
		esriName = csEsriNbrMap [index].esriName;
		if (flags != 0) *flags = csEsriNbrMap [index].flags;
	}
	return esriName;
}
long EXP_LVL1 CS_esriNbrByIdx (unsigned short index,unsigned short* flags)
{
	long esriNbr = 0;
	const unsigned short idxMax = sizeof (csEsriNbrMap) / sizeof (struct csEsriNbrMap_);

	if (flags != 0) *flags = 0;
	if (index < idxMax)
	{
		esriNbr = csEsriNbrMap [index].esriNbr;
		if (flags != 0) *flags = csEsriNbrMap [index].flags;
	}
	return esriNbr;
}
long EXP_LVL1 CS_esriDtmName2EpsgNbr (Const char* esriName,unsigned short* flags)
{
	long epsgNbr = -1;
	Const char* esriNmPtr;
	const struct csEsriDtmMap_ *tblPtr;

	if (flags != 0) *flags = 0;
	esriNmPtr = esriName;
	for (tblPtr = csEsriDtmMap;tblPtr->esriName [0] != '\0';tblPtr += 1)
	{
		if (!CS_stricmp (tblPtr->esriName,esriNmPtr))
		{
			epsgNbr = tblPtr->epsgNbr;
			if (flags != 0) *flags = tblPtr->flags;
			break;
		}
	}
	return epsgNbr;
}
Const char* EXP_LVL1 CS_epsgDtmNbr2EsriName (long epsgNbr,unsigned short* flags)
{
	Const char* esriName = 0;
	const struct csEsriDtmMap_ *tblPtr;

	if (flags != 0) *flags = 0;
	if (epsgNbr != 0)
	{
		for (tblPtr = csEsriDtmMap;tblPtr->esriName [0] != '\0';tblPtr += 1)
		{
			if (tblPtr->epsgNbr == epsgNbr)
			{
				esriName = tblPtr->esriName;
				if (flags != 0) *flags = tblPtr->flags;
				break;
			}
		}
	}
	return esriName;
}
Const char* EXP_LVL1 CS_esriDtmName2Msi (Const char* esriName,unsigned short* flags)
{
	Const char* msiName = 0;
	Const char* esriNmPtr;
	const struct csEsriDtmMap_ *tblPtr;

	if (flags != 0) *flags = 0;
	esriNmPtr = esriName;
	for (tblPtr = csEsriDtmMap;tblPtr->esriName [0] != '\0';tblPtr += 1)
	{
		if (!CS_stricmp (tblPtr->esriName,esriNmPtr))
		{
			msiName = tblPtr->msiName;
			if (flags != 0) *flags = tblPtr->flags;
			break;
		}
	}
	return msiName;
}
Const char* EXP_LVL1 CS_msiDtmName2Esri (Const char* msiName,unsigned short* flags)
{
	Const char* esriName = 0;
	const struct csEsriDtmMap_ *tblPtr;

	if (flags != 0) *flags = 0;
	for (tblPtr = csEsriDtmMap;tblPtr->esriName [0] != '\0';tblPtr += 1)
	{
		if (!CS_stricmp (tblPtr->msiName,msiName))
		{
			esriName = tblPtr->esriName;
			if (flags != 0) *flags = tblPtr->flags;
			break;
		}
	}
	return esriName;
}
Const char* EXP_LVL1 CS_esriDtmNameByIdx (unsigned short index,unsigned short* flags)
{
	Const char* esriDtmName = 0;
	const unsigned short idxMax = sizeof (csEsriDtmMap) / sizeof (struct csEsriDtmMap_);

	if (flags != 0) *flags = 0;
	if (index < idxMax)
	{
		esriDtmName = csEsriDtmMap [index].esriName;
		if (flags != 0) *flags = csEsriDtmMap [index].flags;
	}
	return esriDtmName;
}
Const char* EXP_LVL1 CS_esriElpName2Msi (Const char* esriName)
{
	const char* msiNamePtr = 0;
	const struct csEsriElpMap_ *tblPtr;

	for (tblPtr = csEsriElpMap;tblPtr->esriName [0] != '\0';tblPtr += 1)
	{
		if (!CS_stricmp (tblPtr->esriName,esriName))
		{
			msiNamePtr = tblPtr->msiName;
			break;
		}
	}
	return msiNamePtr;
}
long EXP_LVL1 CS_esriElpName2EpsgNbr (Const char* esriName)
{
	long epsgNbr = -1;
	const struct csEsriElpMap_ *tblPtr;

	for (tblPtr = csEsriElpMap;tblPtr->esriName [0] != '\0';tblPtr += 1)
	{
		if (!CS_stricmp (tblPtr->esriName,esriName))
		{
			epsgNbr = tblPtr->epsgNbr;
			break;
		}
	}
	return epsgNbr;
}
Const char* EXP_LVL1 CS_msiElpName2Esri (Const char* msiName)
{
	const char* esriNamePtr = 0;
	const struct csEsriElpMap_ *tblPtr;

	for (tblPtr = csEsriElpMap;tblPtr->esriName [0] != '\0';tblPtr += 1)
	{
		if (!CS_stricmp (tblPtr->msiName,msiName))
		{
			esriNamePtr = tblPtr->esriName;
			break;
		}
	}
	return esriNamePtr;
}
/******************************************************************************
** The following implements a rather rudimentary matrix object, just enough
** to implement a world file (i.e. of the .wld variety) calculator.
******************************************************************************/
struct mtx_t_
{
	unsigned short rows;		
	unsigned short cols;
	unsigned short status;
	unsigned long size;
	double det;
	double mtx [1];
};
typedef struct mtx_t_ mtx_t;
/* The following macro is used to access the individual elements of a matrix. */
#define MTX0(mtx_ptr,row,col) *(mtx_ptr->mtx + ((unsigned long)row * (unsigned long)mtx_ptr->cols) + (unsigned long)col)
/* View the following as sort of a matrix constructor. */
mtx_t *mxalo (int rows,int cols)
{
	extern double cs_Zero;

	int mal_size;
	int ele_cnt;

	double *dp;
	double *dpe;
	mtx_t *matrix;

	ele_cnt = rows * cols;
	mal_size = ((ele_cnt) - 1) * sizeof (double) + sizeof (mtx_t);
	matrix = (mtx_t *)malloc (mal_size);
	if (matrix == NULL) return (NULL);

	matrix->size = mal_size;
	matrix->rows = (unsigned short)rows;
	matrix->cols = (unsigned short)cols;
	matrix->status = 0;
	matrix->det = cs_Zero;

	dp = matrix->mtx;
	dpe = dp + ele_cnt;
	while (dp < dpe) *dp++ = cs_Zero;
	return (matrix);
}
/* Given two matrices, this functions a Gauss-Jordan reduction to calculate,
   what is typically, the solution to a system os simultaeous equations. */
double gauss (mtx_t *aa,mtx_t *bb)
{
	unsigned short cc;
	unsigned short dd;
	unsigned short rr;
	unsigned short bst_rr;

	double det;
	double tmp;
	double tst_val;

	if (aa->rows != aa->cols) return (0.0);
	if (bb->rows != aa->rows) return (0.0);
	if (bb->cols != 1) return (0.0);
	det = 1.0;
	for (dd = 0;dd < aa->rows;dd++)
	{
		bst_rr = dd;
		tst_val = fabs (MTX0(aa,dd,dd));
		for (rr = (unsigned short)(dd + 1);rr < aa->rows;rr++)
		{
			tmp = fabs (MTX0(aa,rr,dd));
			if (tmp > tst_val)
			{
				bst_rr = rr;
				tst_val = tmp;
			}
		}
		if (bst_rr != dd)
		{
			for (cc = dd;cc < aa->cols;cc++)
			{
				tmp = MTX0(aa,dd,cc);
				MTX0(aa,dd,cc) = MTX0(aa,bst_rr,cc);
				MTX0(aa,bst_rr,cc) = tmp;
			}
			tmp = MTX0(bb,dd,0);
			MTX0(bb,dd,0) = MTX0(bb,bst_rr,0);
			MTX0(bb,bst_rr,0) = tmp;
		}
		tmp = MTX0(aa,dd,dd);
		det *= tmp;
		if (det == 0.0) return (det);
		tmp = 1.0 / tmp;
		MTX0(aa,dd,dd) = 1.0;
		for (cc = (unsigned short)(dd + 1);cc < aa->cols;cc++)
		{
			MTX0(aa,dd,cc) *= tmp;
		}
		MTX0(bb,dd,0) *= tmp;
		for (rr = 0;rr < aa->rows;rr++)
		{
			if (rr == dd) continue;
			tmp = MTX0(aa,rr,dd);
			MTX0(aa,rr,dd) = 0.0;
			for (cc = (unsigned short)(dd + 1);cc < aa->cols;cc++)
			{
				MTX0(aa,rr,cc) -= tmp * MTX0(aa,dd,cc);
			}
			MTX0(bb,rr,0) -= tmp * MTX0(bb,dd,0);
		}
	}
	return (det);
}
/******************************************************************************
** With the above matrix tools available, we can do a .wld calculator pretty
** easily.  We only do the two point form.  The single point form is trivial.
**
** The return value AA, BB, CC, DD are calculated so that the following code:
**
**	to [0] = AA + CC * from[0] + DD * from[1];
**	to [1] = BB - DD * from[0] + CC * from[1];
**
** is valid for each of the provided two points.  AA and BB are translation
** values.  Read CC as being k * cos (theta) and DD as being k * sin (theta)
** where k is the uniform (same for X and Y axes) scale factor and theta
** is the rotation angle.  Rotation is about the origin.
**
******************************************************************************/
int EXP_LVL1 CS_wldCalc (double* AA, double* BB, double* CC, double* DD,double from1 [2],double to1 [2],double from2 [2],double to2 [2])
{
	extern double cs_One;
	extern double cs_Zero;

	double det;
	mtx_t *mtx_A = 0;
	mtx_t *mtx_B = 0;

	mtx_A = mxalo (4,4);
	if (mtx_A == NULL)
	{
		CS_erpt (cs_NO_MEM);
		goto error;		
	};
	mtx_B = mxalo (4,1);
	if (mtx_B == NULL)
	{
		CS_erpt (cs_NO_MEM);
		goto error;		
	};

	/* Populate the matrices. */
	MTX0 (mtx_A,0,0) = cs_One;
	MTX0 (mtx_A,0,1) = cs_Zero;
	MTX0 (mtx_A,0,2) = from1 [XX];
	MTX0 (mtx_A,0,3) = from1 [YY];
	MTX0 (mtx_B,0,0) = to1 [XX];
	
	MTX0 (mtx_A,1,0) = cs_Zero;
	MTX0 (mtx_A,1,1) = cs_One;
	MTX0 (mtx_A,1,2) = from1 [YY];
	MTX0 (mtx_A,1,3) = -from1 [XX];
	MTX0 (mtx_B,1,0) = to1 [YY];
	
	MTX0 (mtx_A,2,0) = cs_One;
	MTX0 (mtx_A,2,1) = cs_Zero;
	MTX0 (mtx_A,2,2) = from2 [XX];
	MTX0 (mtx_A,2,3) = from2 [YY];
	MTX0 (mtx_B,2,0) = to2 [XX];
	
	MTX0 (mtx_A,3,0) = cs_Zero;
	MTX0 (mtx_A,3,1) = cs_One;
	MTX0 (mtx_A,3,2) = from2 [YY];
	MTX0 (mtx_A,3,3) = -from2 [XX];
	MTX0 (mtx_B,3,0) = to2 [YY];

	det = gauss (mtx_A,mtx_B);
	free (mtx_A);
	mtx_A = NULL;

	/* If the determinate was zero, there is something very
	   wrong.  For the two point case, the points must been
	   very very close to each other. */
	if (fabs (det) < 1.0E-38)
	{
		free (mtx_B);
		mtx_B = NULL;
		CS_erpt (cs_WLD_NOSOL);
		goto error;
	}

	/* The determinate was not zero, the desired results are in mtx_B */
	*AA = MTX0 (mtx_B,0,0);
	*BB = MTX0 (mtx_B,1,0);
	*CC = MTX0 (mtx_B,2,0);
	*DD = MTX0 (mtx_B,3,0);
	free (mtx_B);
	mtx_B = NULL;
	return 0;

error:
	if (mtx_A != NULL)
	{
		free (mtx_A);
	}
	if (mtx_B != NULL)
	{
		free (mtx_B);
	}
	return -1;
}

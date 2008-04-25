CC_FLG= /I..\include /MT /O2 /W3 /GX /D"WIN32" /D"NDEBUG" /D"_WINDOWS"

CPP_FLG= /I..\include /MT /O2 /W3 /GX /D"WIN32" /D"NDEBUG" /D"_WINDOWS" /D"__MFC__" /D"__CPP__"

.C.OBJ:
	cl /c $(CC_FLG) /Fp"cs_map.pch" /YX"cs_map.h" $<

.CPP.OBJ:
	cl /c $(CPP_FLG) /Fp"cs_map.pch" /YX"cs_map.h" $<

CS_SRC=	CS_agd66.c          CS_agd84.c            CS_alber.c             CS_angle.c \
	CS_ansi.c \
	CS_ats77.c          CS_ats77Transform.c   CS_azmea.c             CS_azmed.c \
	CS_bonne.c \
	CS_bpcnc.c          CS_bynFile.c          CS_caDatum.c           CS_caV1GridFile.c \
	CS_caV2GridFile.c \
	CS_csini.c          CS_csio.c             CS_csprm.c             CS_csrs.c \
	CS_csWktLoc.c       CS_datum.c \
	CS_defaults.c       CS_defCmp.c           CS_dhdn.c \
	CS_dtAgd66ToGda94.c CS_dtAgd84ToGda94.c \
	CS_dtAts77ToNad83.c CS_dtCalc.c           CS_dtDhdnToEtrf89.c    CS_dtEd50ToEtrf89.c \
	CS_dtio.c \
	CS_dtNad27ToAts77.c CS_dtNad27ToNad83.c \
	CS_dtNad83ToHarn.c  CS_dtNzdg49ToNzgd2K.c CS_dtTokyoToJgd2k.c    CS_ed50 \
	CS_edcnc.c          CS_edcyl.c \
	CS_ekrt4.c          CS_ekrt6.c            CS_elCalc.c            CS_elio.c \
	CS_epsg.c \
	CS_erpt.c           CS_error.c            CS_esri.c              CS_fips.c \
	CS_general.c        CS_geoid96.c          CS_geoid99.c           CS_geoidHeight.c \
	CS_gissupprt.c \
	CS_gnomc.c          CS_groups.c           CS_guiApi.c            CS_hlApi.c \
	CS_hmlsn.c          CS_hpApi.c            CS_hpgn.c              CS_japan.c \
	CS_krovk.c \
	CS_lmbrt.c          CS_lmtan.c            CS_mgrs.c              CS_millr.c \
	CS_modpc.c \
	CS_molwd.c          CS_mrcat.c            CS_mstro.c             CS_nacyl.c \
	CS_nad27.c          CS_nerth.c \
	CS_nzgd49.c         CS_nzlnd.c            CS_oblqm.c \
	CS_optional.c       CS_ortho.c            CS_oracle.c            CS_osgm91.c \
	CS_ostn97.c \
	CS_ostn02.c         CS_ostro.c            CS_plycn.c \
	CS_pstro.c          CS_rgf93ToNtf.c       CS_robin.c \
	CS_sinus.c \
	CS_sstro.c          CS_supprt.c           CS_swiss.c             CS_sys34.c \
	CS_system.c         CS_tacyl.c \
	CS_trmer.c          CS_trmrs.c            CS_units.c             CS_unity.c \
	CS_usDatum.c        CS_usGridFile.c       CS_vdgrn.c             CS_VertconUS.c \
	CS_vrtcon.c         CS_wellKnownText.cpp  CS_winkelTripel.c      CS_zones.c \
	CScscomp.c          CScs2Wkt.c             CSdata.c \
	CSdataPJ.c          CSdataU.c             CSdatumCatalog.c       CSdatumSupport.c \
	CSdictDiff.c        CSdt2Wkt.c            CSdtcomp.c             CSel2Wkt.c \
	CSelcomp.c \
	CSgridCellCache.c   CSmrcomp.c            CSnad83ToCsrs.c        CSnad27ToCsrs.c \
	csBrowser.cpp       csDataDir.cpp         csDualBrowse.cpp \
	csEdit.cpp          csKeyNm.cpp           csTest.cpp             CSwinHlp.cpp \
	CSwktFlavors.c \
	dtEdit.cpp          dtSelect.cpp          elEdit.cpp             elSelect.cpp \
	mgTest.cpp          gdcEdit.cpp           rcWellKnownText.cpp    rcWktKonstants.cpp

CS_OBJ= CS_agd66.obj          CS_agd84.obj            CS_alber.obj             CS_angle.obj \
	CS_ansi.obj \
	CS_ats77.obj          CS_ats77Transform.obj   CS_azmea.obj             CS_azmed.obj \
	CS_bonne.obj \
	CS_bpcnc.obj          CS_bynFile.obj          CS_caDatum.obj           CS_caV1GridFile.obj \
	CS_caV2GridFile.obj \
	CS_csini.obj          CS_csio.obj             CS_csprm.obj             CS_csrs.obj \
	CS_csWktLoc.obj       CS_datum.obj          CS_defCmp.obj           CS_dhdn.obj \
	CS_defaults.obj       CS_dtAgd66ToGda94.obj   CS_dtAgd84ToGda94.obj \
	CS_dtAts77ToNad83.obj CS_dtCalc.obj           CS_dtDhdnToEtrf89.obj    CS_dtEd50ToEtrf89.obj \
	CS_dtio.obj \
	CS_dtNad27ToAts77.obj CS_dtNad27ToNad83.obj \
	CS_dtNad83ToHarn.obj  CS_dtNzdg49ToNzgd2K.obj CS_dtTokyoToJgd2k.obj    CS_ed50.obj \
	CS_edcnc.obj \
	CS_edcyl.obj          CS_ekrt4.obj            CS_ekrt6.obj             CS_elCalc.obj \
	CS_elio.obj           CS_epsg.obj             CS_erpt.obj              CS_error.obj  \
	CS_esri.obj           CS_fips.obj \
	CS_general.obj        CS_geoid96.obj          CS_geoid99.obj \
	CS_geoidHeight.obj    CS_gissupprt.obj \
	CS_gnomc.obj          CS_groups.obj           CS_guiApi.obj            CS_hlApi.obj \
	CS_hmlsn.obj          CS_hpApi.obj            CS_hpgn.obj              CS_japan.obj \
	CS_krovk.obj          CS_lmbrt.obj            CS_lmtan.obj             CS_mgrs.obj \
	CS_millr.obj          CS_modpc.obj \
	CS_molwd.obj          CS_mrcat.obj            CS_mstro.obj             CS_nacyl.obj \
	CS_nad27.obj          CS_nerth.obj \
	CS_nzgd49.obj         CS_nzlnd.obj            CS_oblqm.obj \
	CS_optional.obj       CS_oracle.obj           CS_ortho.obj            CS_osgm91.obj \
	CS_ostn97.obj \
	CS_ostn02.obj         CS_ostro.obj            CS_plycn.obj \
	CS_pstro.obj          CS_rgf93ToNtf.obj       CS_robin.obj \
	CS_sinus.obj \
	CS_sstro.obj          CS_supprt.obj           CS_swiss.obj             CS_sys34.obj \
	CS_system.obj         CS_tacyl.obj \
	CS_trmer.obj          CS_trmrs.obj            CS_units.obj             CS_unity.obj \
	CS_usDatum.obj        CS_usGridFile.obj       CS_vdgrn.obj             CS_VertconUS.obj \
	CS_vrtcon.obj         CS_wellKnownText.obj    CS_winkelTripel.obj      CS_zones.obj \
	CScscomp.obj          CScs2Wkt.obj             CSdata.obj \
	CSdataPJ.obj          CSdataU.obj             CSdatumCatalog.obj       CSdatumSupport.obj \
	CSdictDiff.obj        CSdt2Wkt.obj            CSdtcomp.obj             CSel2Wkt.obj \
	CSelcomp.obj \
	CSgridCellCache.obj   CSmrcomp.obj            CSnad27ToCsrs.obj        CSnad83ToCsrs.obj \
	csBrowser.obj \
	csDataDir.obj         csDualBrowse.obj \
	csEdit.obj            csKeyNm.obj             csTest.obj               CSwinHlp.obj \
	CSwktFlavors.obj \
	dtEdit.obj            dtSelect.obj            elEdit.obj               elSelect.obj \
	mgTest.obj            gdcEdit.obj             rcWellKnownText.obj      rcWktKonstants.obj

CSMAPMNT.LIB : $(CS_OBJ)
	lib /out:"CSMAPMNT.LIB" $(CS_OBJ)

CC_FLG = $(CS_CC_FLG)
CPP_FLG = $(CS_CPP_FLG)

.c.o:
	gcc -c $(CC_FLG) $<

.cpp.o:
	gcc -c $(CPP_FLG) $<

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
	CS_cslcl.c \
	csBrowser.cpp       csDataDir.cpp         csDualBrowse.cpp \
	csEdit.cpp          csKeyNm.cpp           csTest.cpp             CSwinHlp.cpp \
	CSwktFlavors.c \
	dtEdit.cpp          dtSelect.cpp          elEdit.cpp             elSelect.cpp \
	mgTest.cpp          gdcEdit.cpp           rcWellKnownText.cpp    rcWktKonstants.cpp

CS_OBJ= CS_agd66.o          CS_agd84.o            CS_alber.o             CS_angle.o \
	CS_ansi.o \
	CS_ats77.o          CS_ats77Transform.o   CS_azmea.o             CS_azmed.o \
	CS_bonne.o \
	CS_bpcnc.o          CS_bynFile.o          CS_caDatum.o           CS_caV1GridFile.o \
	CS_caV2GridFile.o \
	CS_csini.o          CS_csio.o             CS_csprm.o             CS_csrs.o \
	CS_csWktLoc.o       CS_datum.o          CS_defCmp.o           CS_dhdn.o \
	CS_defaults.o       CS_dtAgd66ToGda94.o   CS_dtAgd84ToGda94.o \
	CS_dtAts77ToNad83.o CS_dtCalc.o           CS_dtDhdnToEtrf89.o    CS_dtEd50ToEtrf89.o \
	CS_dtio.o \
	CS_dtNad27ToAts77.o CS_dtNad27ToNad83.o \
	CS_dtNad83ToHarn.o  CS_dtNzdg49ToNzgd2K.o CS_dtTokyoToJgd2k.o    CS_ed50.o \
	CS_edcnc.o \
	CS_edcyl.o          CS_ekrt4.o            CS_ekrt6.o             CS_elCalc.o \
	CS_elio.o           CS_epsg.o             CS_erpt.o              CS_error.o  \
	CS_esri.o           CS_fips.o \
	CS_general.o        CS_geoid96.o          CS_geoid99.o \
	CS_geoidHeight.o    CS_gissupprt.o \
	CS_gnomc.o          CS_groups.o           CS_guiApi.o            CS_hlApi.o \
	CS_hmlsn.o          CS_hpApi.o            CS_hpgn.o              CS_japan.o \
	CS_krovk.o          CS_lmbrt.o            CS_lmtan.o             CS_mgrs.o \
	CS_millr.o          CS_modpc.o \
	CS_molwd.o          CS_mrcat.o            CS_mstro.o             CS_nacyl.o \
	CS_nad27.o          CS_nerth.o \
	CS_nzgd49.o         CS_nzlnd.o            CS_oblqm.o \
	CS_optional.o       CS_oracle.o           CS_ortho.o            CS_osgm91.o \
	CS_ostn97.o \
	CS_ostn02.o         CS_ostro.o            CS_plycn.o \
	CS_pstro.o          CS_rgf93ToNtf.o       CS_robin.o \
	CS_sinus.o \
	CS_sstro.o          CS_supprt.o           CS_swiss.o             CS_sys34.o \
	CS_system.o         CS_tacyl.o \
	CS_trmer.o          CS_trmrs.o            CS_units.o             CS_unity.o \
	CS_usDatum.o        CS_usGridFile.o       CS_vdgrn.o             CS_VertconUS.o \
	CS_vrtcon.o         CS_wellKnownText.o    CS_winkelTripel.o      CS_zones.o \
	CScscomp.o          CScs2Wkt.o             CSdata.o \
	CSdataPJ.o          CSdataU.o             CSdatumCatalog.o       CSdatumSupport.o \
	CSdictDiff.o        CSdt2Wkt.o            CSdtcomp.o             CSel2Wkt.o \
	CSelcomp.o \
	CSgridCellCache.o   CSmrcomp.o            CSnad27ToCsrs.o        CSnad83ToCsrs.o \
	CS_cslcl.o \
	csBrowser.o \
	csDataDir.o         csDualBrowse.o \
	csEdit.o            csKeyNm.o             csTest.o               CSwinHlp.o \
	CSwktFlavors.o \
	dtEdit.o            dtSelect.o            elEdit.o               elSelect.o \
	mgTest.o            gdcEdit.o             rcWellKnownText.o      rcWktKonstants.o

$(CS_LIB_PATH)/libcsmap.$(CS_LIB_SUFFIX) : $(CS_OBJ)
	gcc $(CS_LIB_FLG) $(CS_NAMES) -o libcsmap.1.15.1.$(CS_LIB_SUFFIX) $(CS_OBJ)
	sudo mv libcsmap.1.15.1.$(CS_LIB_SUFFIX) $(CS_LIB_PATH)
	sudo ln -fs $(CS_LIB_PATH)/libcsmap.1.15.1.$(CS_LIB_SUFFIX) $(CS_LIB_PATH)/libcsmap.1.$(CS_LIB_SUFFIX)
	sudo ln -fs $(CS_LIB_PATH)/libcsmap.1.15.1.$(CS_LIB_SUFFIX) $(CS_LIB_PATH)/libcsmap.$(CS_LIB_SUFFIX)

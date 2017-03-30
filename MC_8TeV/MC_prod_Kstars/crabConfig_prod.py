from WMCore.Configuration import Configuration
config = Configuration()
config.section_('General')
config.General.transferOutputs = True

config.General.requestName = 'Bd_JpsiKpi_PHSP_lxplus-fnal'

config.General.transferLogs = True
config.section_('JobType')

config.JobType.psetName = 'PYTHIA6_Bd2JpsiKpi_PHSP_TuneZ2star_8TeV_noPtEtaCuts_cff_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO.py'
config.JobType.pluginName = 'PrivateMC'

config.section_('Data')

config.Data.splitting = 'EventBased'
config.Data.unitsPerJob = 100 #20 earlier
NJOBS = 5000  # This is not a configuration parameter, but an auxiliary variable that we use in the next line.
config.Data.totalUnits = config.Data.unitsPerJob * NJOBS

config.Data.publication = False
config.Data.outputDatasetTag = 'Bd_JpsiKpi_PHSP_MC_Gen'
config.Data.ignoreLocality = False
config.section_('User')
config.section_('Site')

config.Data.outLFNDirBase = '/store/user/nsur/'

config.Site.blacklist = ['T1*']
#config.Site.storageSite = 'T2_IT_Bari' 
config.Site.storageSite = 'T3_US_FNALLPC'

from WMCore.Configuration import Configuration
config = Configuration()
config.section_('General')
config.General.transferOutputs = True

# Data
#config.General.requestName = 'psi1Sand2S_MuOnia2012B_AOD_lxplus-fnal'
#config.General.requestName = 'psi1S_MuOnia2012B_AOD_lxplus-fnal'
#config.General.requestName = 'psi1S_MuOnia2012C_AOD_lxplus-fnal'
#config.General.requestName = 'psi1S_MuOnia2012D_AOD_lxplus-fnal'
config.General.requestName = 'psi1S_MuOnia2012A_AOD_lxplus-fnal'

config.General.transferLogs = True
config.section_('JobType')

config.JobType.psetName = 'runMuMuPiKPAT_dataOrMC_09Apr.py'
config.JobType.pluginName = 'Analysis'
config.section_('Data')
#config.Data.inputDataset = '/MuOnia/Run2012B-22Jan2013-v1/AOD'
#config.Data.inputDataset = '/MuOnia/Run2012C-22Jan2013-v1/AOD'
#config.Data.inputDataset = '/MuOnia/Run2012D-22Jan2013-v1/AOD'
config.Data.inputDataset = '/MuOnia/Run2012A-22Jan2013-v1/AOD'

# Data
config.Data.splitting = 'LumiBased'
config.Data.unitsPerJob = 20 #20 earlier 

config.Data.totalUnits = -1 #-1
config.Data.lumiMask = 'Cert_190456-208686_8TeV_22Jan2013ReReco_Collisions12_JSON_MuonPhys.txt'
#config.Data.lumiMask = 'crab_dataset_C/results/missingLumiSummary.json' # for resubmission
config.Data.publication = False

config.Data.ignoreLocality = False
config.section_('User')
config.section_('Site')

config.Data.outLFNDirBase = '/store/user/nsur/'

config.Site.blacklist = ['T1*']
#config.Site.storageSite = 'T2_IT_Bari' 
config.Site.storageSite = 'T3_US_FNALLPC'

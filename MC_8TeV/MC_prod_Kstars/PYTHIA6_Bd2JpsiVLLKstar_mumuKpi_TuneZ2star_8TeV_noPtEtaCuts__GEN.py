# Auto generated configuration file
# using: 
# Revision: 1.381.2.28 
# Source: /local/reps/CMSSW/CMSSW/Configuration/PyReleaseValidation/python/ConfigBuilder.py,v 
# with command line options: Configuration/GenProduction/python/PYTHIA6_Bd2JpsiVLLKstar_mumuKpi_TuneZ2star_8TeV_noPtEtaCuts_cff.py --step GEN --beamspot Realistic8TeVCollision --conditions START53_V19F::All --pileup NoPileUp --datamix NODATAMIXER --eventcontent RAWSIM --datatier GEN --no_exec -n 10000 --python_filename=PYTHIA6_Bd2JpsiVLLKstar_mumuKpi_TuneZ2star_8TeV_noPtEtaCuts__GEN.py --fileout=PYTHIA6_Bd2JpsiVLLKstar_mumuKpi_TuneZ2star_8TeV_noPtEtaCuts__GEN.root
import FWCore.ParameterSet.Config as cms

process = cms.Process('GEN')

# import of standard configurations
process.load('Configuration.StandardSequences.Services_cff')
process.load('SimGeneral.HepPDTESSource.pythiapdt_cfi')
process.load('FWCore.MessageService.MessageLogger_cfi')
process.load('Configuration.EventContent.EventContent_cff')
process.load('SimGeneral.MixingModule.mixNoPU_cfi')
process.load('Configuration.StandardSequences.GeometryRecoDB_cff')
process.load('Configuration.StandardSequences.MagneticField_38T_cff')
process.load('Configuration.StandardSequences.Generator_cff')
process.load('IOMC.EventVertexGenerators.VtxSmearedRealistic8TeVCollision_cfi')
process.load('GeneratorInterface.Core.genFilterSummary_cff')
process.load('Configuration.StandardSequences.EndOfProcess_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(100)   #100000
)
 
# Input source
process.source = cms.Source("EmptySource")

process.options = cms.untracked.PSet(

)

# Production Info
process.configurationMetadata = cms.untracked.PSet(
    version = cms.untracked.string('$Revision: 1.1 $'),
    annotation = cms.untracked.string('B0 -> J/psiK* -> mumuK+pi- at 8TeV'),
    name = cms.untracked.string('$Source: /afs/cern.ch/user/l/lecriste/sanjay_code/CMSSW_5_3_22/src/Configuration/GenProduction/python/PYTHIA6_Bd2JpsiVLLKstar_mumuKpi_TuneZ2star_8TeV_noPtEtaCuts_cff.py,v $')
)

# Output definition

process.RAWSIMoutput = cms.OutputModule("PoolOutputModule",
    splitLevel = cms.untracked.int32(0),
    eventAutoFlushCompressedSize = cms.untracked.int32(5242880),
    outputCommands = process.RAWSIMEventContent.outputCommands,
    fileName = cms.untracked.string('PYTHIA6_Bd2JpsiVLLKstar_mumuKpi_TuneZ2star_8TeV_noPtEtaCuts__GEN.root'),
    dataset = cms.untracked.PSet(
        filterName = cms.untracked.string(''),
        dataTier = cms.untracked.string('GEN')
    ),
    SelectEvents = cms.untracked.PSet(
        SelectEvents = cms.vstring('generation_step')
    )
)

# Additional output definition

# Other statements
process.genstepfilter.triggerConditions=cms.vstring("generation_step")
from Configuration.AlCa.GlobalTag import GlobalTag
process.GlobalTag = GlobalTag(process.GlobalTag, 'START53_V19F::All', '')

process.psifilter = cms.EDFilter("PythiaDauVFilter",
    MotherID = cms.untracked.int32(511),
    MinPt = cms.untracked.vdouble(-1.0, -1.0),
    ParticleID = cms.untracked.int32(443),
    MaxEta = cms.untracked.vdouble(9999, 9999),
    MinEta = cms.untracked.vdouble(-9999, -9999),
    DaughterIDs = cms.untracked.vint32(13, -13),
    NumberDaughters = cms.untracked.int32(2),
    verbose = cms.untracked.int32(0)
)


process.decayfilter = cms.EDFilter("PythiaDauVFilter",
    MinPt = cms.untracked.vdouble(-1.0, -1.0),
    ParticleID = cms.untracked.int32(511),
    MaxEta = cms.untracked.vdouble(9999.0, 9999.0),
    MinEta = cms.untracked.vdouble(-9999.0, -9999.0),
    DaughterIDs = cms.untracked.vint32(443, 313),
    NumberDaughters = cms.untracked.int32(2),
    verbose = cms.untracked.int32(0)
)


process.bfilter = cms.EDFilter("PythiaFilter",
    MaxEta = cms.untracked.double(9999.0),
    MinEta = cms.untracked.double(-9999.0),
    ParticleID = cms.untracked.int32(511)
)


process.generator = cms.EDFilter("Pythia6GeneratorFilter",
    ExternalDecays = cms.PSet(
        EvtGen = cms.untracked.PSet(
            use_default_decay = cms.untracked.bool(False),
            decay_table = cms.FileInPath('GeneratorInterface/ExternalDecays/data/DECAY_NOLONGLIFE.DEC'),
            #particle_property_file = cms.FileInPath('GeneratorInterface/ExternalDecays/data/myevt.pdl'),
            particle_property_file = cms.FileInPath('GeneratorInterface/ExternalDecays/data/evt.pdl'),
            user_decay_file = cms.FileInPath('GeneratorInterface/ExternalDecays/data/Bd_JpsiKstar_mumuKpi.dec'),
            list_forced_decays = cms.vstring('MyB0', 
                'Myanti-B0'),
            #operates_on_particles = cms.vint32(0)
 	    operates_on_particles = cms.vint32(511, -511)
       ),
        parameterSets = cms.vstring('EvtGen')
    ),
    pythiaPylistVerbosity = cms.untracked.int32(0),
    filterEfficiency = cms.untracked.double(1.0),
    pythiaHepMCVerbosity = cms.untracked.bool(False),
    comEnergy = cms.double(8000.0),
    crossSection = cms.untracked.double(0.0),
    maxEventsToPrint = cms.untracked.int32(0),
    PythiaParameters = cms.PSet(
        pythiaUESettings = cms.vstring('MSTU(21)=1     ! Check on possible errors during program execution', 
            'MSTJ(22)=2     ! Decay those unstable particles', 
            'PARJ(71)=10 .  ! for which ctau  10 mm', 
            'MSTP(33)=0     ! no K factors in hard cross sections', 
            'MSTP(2)=1      ! which order running alphaS', 
            'MSTP(51)=10042 ! structure function chosen (external PDF CTEQ6L1)', 
            'MSTP(52)=2     ! work with LHAPDF', 
            'PARP(82)=1.921 ! pt cutoff for multiparton interactions', 
            'PARP(89)=1800. ! sqrts for which PARP82 is set', 
            'PARP(90)=0.227 ! Multiple interactions: rescaling power', 
            'MSTP(95)=6     ! CR (color reconnection parameters)', 
            'PARP(77)=1.016 ! CR', 
            'PARP(78)=0.538 ! CR', 
            'PARP(80)=0.1   ! Prob. colored parton from BBR', 
            'PARP(83)=0.356 ! Multiple interactions: matter distribution parameter', 
            'PARP(84)=0.651 ! Multiple interactions: matter distribution parameter', 
            'PARP(62)=1.025 ! ISR cutoff', 
            'MSTP(91)=1     ! Gaussian primordial kT', 
            'PARP(93)=10.0  ! primordial kT-max', 
            'MSTP(81)=21    ! multiple parton interactions 1 is Pythia default', 
            'MSTP(82)=4     ! Defines the multi-parton model'),
        bbbarSettings = cms.vstring('MSEL=5'),
        parameterSets = cms.vstring('pythiaUESettings', 
            'bbbarSettings')
    )
)


process.ProductionFilterSequence = cms.Sequence(process.generator+process.bfilter+process.decayfilter+process.psifilter)

# Path and EndPath definitions
process.generation_step = cms.Path(process.pgen)
process.genfiltersummary_step = cms.EndPath(process.genFilterSummary)
process.endjob_step = cms.EndPath(process.endOfProcess)
process.RAWSIMoutput_step = cms.EndPath(process.RAWSIMoutput)

# Schedule definition
process.schedule = cms.Schedule(process.generation_step,process.genfiltersummary_step,process.endjob_step,process.RAWSIMoutput_step)
# filter all path with the production filter sequence
for path in process.paths:
	getattr(process,path)._seq = process.ProductionFilterSequence * getattr(process,path)._seq 


import re
for x in range(1, 3):
    with open("runMuMuPiKPAT_MC_29Jan.py", "r") as old_file, open("runMuMuPiKPAT_MC_29Jan_60000_{0}.py".format(x * 10), "w") as new_file:
        for line in old_file:
            # This will match if this pattern is anywhere in the line
            if re.search("                        mylist = FileUtils.loadListFromFile ('filenames_official_formatted_60000.txt')", line) is not None:
                line = "                        mylist = FileUtils.loadListFromFile ('filenames_official_formatted_60000_{0}.txt')".format(x * 10)
        #new_file.write(line)
            # This will match if this pattern is anywhere in the line
            if re.search("                    process.TFileService.fileName = cms.string('/lustre/cms/store/user/nsur/Jpsi_8TeV_OfficialMC_small_ntuples/officialBdToJpsiKpi_MuMuPiKPAT_60000_small_ntpls.root')", line) is not None:
                line2 = "                    process.TFileService.fileName = cms.string('/lustre/cms/store/user/nsur/Jpsi_8TeV_OfficialMC_small_ntuples/officialBdToJpsiKpi_MuMuPiKPAT_60000_{0}_small_ntpls.root')".format(x * 10)
            new_file.write(line)
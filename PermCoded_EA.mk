##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=PermCoded_EA
ConfigurationName      :=Debug
WorkspacePath          := "E:\CodeLite\Workspace\BDMST"
ProjectPath            := "E:\CodeLite\Workspace\BDMST\PermCoded_EA"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Bishwas
Date                   :=30/03/2016
CodeLitePath           :="C:\Program Files\CodeLite"
LinkerName             :=C:/TDM-GCC-64/bin/g++.exe
SharedObjectLinkerName :=C:/TDM-GCC-64/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="PermCoded_EA.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/TDM-GCC-64/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/TDM-GCC-64/bin/ar.exe rcu
CXX      := C:/TDM-GCC-64/bin/g++.exe
CC       := C:/TDM-GCC-64/bin/gcc.exe
CXXFLAGS :=  -g -O3 -Wall $(Preprocessors)
CFLAGS   :=  -std=c++14 -std=c++11 -std=c99 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/TDM-GCC-64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IntermediateDirectory)/XOver.c$(ObjectSuffix) $(IntermediateDirectory)/mutation.c$(ObjectSuffix) $(IntermediateDirectory)/utility.c$(ObjectSuffix) $(IntermediateDirectory)/readBDMST.c$(ObjectSuffix) $(IntermediateDirectory)/calculateFitness.c$(ObjectSuffix) $(IntermediateDirectory)/selection.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.c$(ObjectSuffix): main.c $(IntermediateDirectory)/main.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/CodeLite/Workspace/BDMST/PermCoded_EA/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.c$(DependSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.c$(ObjectSuffix) -MF$(IntermediateDirectory)/main.c$(DependSuffix) -MM "main.c"

$(IntermediateDirectory)/main.c$(PreprocessSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.c$(PreprocessSuffix) "main.c"

$(IntermediateDirectory)/XOver.c$(ObjectSuffix): XOver.c $(IntermediateDirectory)/XOver.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/CodeLite/Workspace/BDMST/PermCoded_EA/XOver.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/XOver.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/XOver.c$(DependSuffix): XOver.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/XOver.c$(ObjectSuffix) -MF$(IntermediateDirectory)/XOver.c$(DependSuffix) -MM "XOver.c"

$(IntermediateDirectory)/XOver.c$(PreprocessSuffix): XOver.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/XOver.c$(PreprocessSuffix) "XOver.c"

$(IntermediateDirectory)/mutation.c$(ObjectSuffix): mutation.c $(IntermediateDirectory)/mutation.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/CodeLite/Workspace/BDMST/PermCoded_EA/mutation.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/mutation.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/mutation.c$(DependSuffix): mutation.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/mutation.c$(ObjectSuffix) -MF$(IntermediateDirectory)/mutation.c$(DependSuffix) -MM "mutation.c"

$(IntermediateDirectory)/mutation.c$(PreprocessSuffix): mutation.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/mutation.c$(PreprocessSuffix) "mutation.c"

$(IntermediateDirectory)/utility.c$(ObjectSuffix): utility.c $(IntermediateDirectory)/utility.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/CodeLite/Workspace/BDMST/PermCoded_EA/utility.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/utility.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/utility.c$(DependSuffix): utility.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/utility.c$(ObjectSuffix) -MF$(IntermediateDirectory)/utility.c$(DependSuffix) -MM "utility.c"

$(IntermediateDirectory)/utility.c$(PreprocessSuffix): utility.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/utility.c$(PreprocessSuffix) "utility.c"

$(IntermediateDirectory)/readBDMST.c$(ObjectSuffix): readBDMST.c $(IntermediateDirectory)/readBDMST.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/CodeLite/Workspace/BDMST/PermCoded_EA/readBDMST.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/readBDMST.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/readBDMST.c$(DependSuffix): readBDMST.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/readBDMST.c$(ObjectSuffix) -MF$(IntermediateDirectory)/readBDMST.c$(DependSuffix) -MM "readBDMST.c"

$(IntermediateDirectory)/readBDMST.c$(PreprocessSuffix): readBDMST.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/readBDMST.c$(PreprocessSuffix) "readBDMST.c"

$(IntermediateDirectory)/calculateFitness.c$(ObjectSuffix): calculateFitness.c $(IntermediateDirectory)/calculateFitness.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/CodeLite/Workspace/BDMST/PermCoded_EA/calculateFitness.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/calculateFitness.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/calculateFitness.c$(DependSuffix): calculateFitness.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/calculateFitness.c$(ObjectSuffix) -MF$(IntermediateDirectory)/calculateFitness.c$(DependSuffix) -MM "calculateFitness.c"

$(IntermediateDirectory)/calculateFitness.c$(PreprocessSuffix): calculateFitness.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/calculateFitness.c$(PreprocessSuffix) "calculateFitness.c"

$(IntermediateDirectory)/selection.c$(ObjectSuffix): selection.c $(IntermediateDirectory)/selection.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/CodeLite/Workspace/BDMST/PermCoded_EA/selection.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/selection.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/selection.c$(DependSuffix): selection.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/selection.c$(ObjectSuffix) -MF$(IntermediateDirectory)/selection.c$(DependSuffix) -MM "selection.c"

$(IntermediateDirectory)/selection.c$(PreprocessSuffix): selection.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/selection.c$(PreprocessSuffix) "selection.c"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/



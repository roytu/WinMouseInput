# Compiler flags...
CPP_COMPILER = g++
C_COMPILER = gcc

# Include paths...
Debug_Include_Path=-I"include"
Release_Include_Path=-I"include"

# Library paths...
Debug_Library_Path=
Release_Library_Path=-L"gcclibs" 

# Additional libraries...
Debug_Libraries=-Wl,--start-group -lGazeApiLib  -Wl,--end-group
Release_Libraries=-Wl,--start-group -lGazeApiLib -llibboost_system-vc100-mt-s-1_56 -llibboost_thread-vc100-mt-s-1_56 -llibboost_date_time-vc100-mt-s-1_56 -llibboost_regex-vc100-mt-s-1_56 -llibboost_chrono-vc100-mt-s-1_56  -Wl,--end-group

# Preprocessor definitions...
Debug_Preprocessor_Definitions=-D GCC_BUILD 
Release_Preprocessor_Definitions=-D GCC_BUILD 

# Implictly linked object files...
Debug_Implicitly_Linked_Objects=
Release_Implicitly_Linked_Objects=

# Compiler flags...
Debug_Compiler_Flags=-O0 -g 
Release_Compiler_Flags=-O2 -g 

# Builds all configurations for this project...
.PHONY: build_all_configurations
build_all_configurations: Debug Release 

# Builds the Debug configuration...
.PHONY: Debug
Debug: create_folders gccDebug/main.o gccDebug/src/MouseInput.o 
	g++ gccDebug/main.o gccDebug/src/MouseInput.o  $(Debug_Library_Path) $(Debug_Libraries) -Wl,-rpath,./ -o ../gccDebug/EyeTracker2.exe

# Compiles file main.cpp for the Debug configuration...
-include gccDebug/main.d
gccDebug/main.o: main.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c main.cpp $(Debug_Include_Path) -o gccDebug/main.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM main.cpp $(Debug_Include_Path) > gccDebug/main.d

# Compiles file src/MouseInput.cpp for the Debug configuration...
-include gccDebug/src/MouseInput.d
gccDebug/src/MouseInput.o: src/MouseInput.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c src/MouseInput.cpp $(Debug_Include_Path) -o gccDebug/src/MouseInput.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM src/MouseInput.cpp $(Debug_Include_Path) > gccDebug/src/MouseInput.d

# Builds the Release configuration...
.PHONY: Release
Release: create_folders gccRelease/main.o gccRelease/src/MouseInput.o 
	g++ gccRelease/main.o gccRelease/src/MouseInput.o  $(Release_Library_Path) $(Release_Libraries) -Wl,-rpath,./ -o ../gccRelease/EyeTracker2.exe

# Compiles file main.cpp for the Release configuration...
-include gccRelease/main.d
gccRelease/main.o: main.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c main.cpp $(Release_Include_Path) -o gccRelease/main.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM main.cpp $(Release_Include_Path) > gccRelease/main.d

# Compiles file src/MouseInput.cpp for the Release configuration...
-include gccRelease/src/MouseInput.d
gccRelease/src/MouseInput.o: src/MouseInput.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c src/MouseInput.cpp $(Release_Include_Path) -o gccRelease/src/MouseInput.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM src/MouseInput.cpp $(Release_Include_Path) > gccRelease/src/MouseInput.d

# Creates the intermediate and output folders for each configuration...
.PHONY: create_folders
create_folders:
	mkdir -p gccDebug/source
	mkdir -p ../gccDebug
	mkdir -p gccRelease/source
	mkdir -p ../gccRelease

# Cleans intermediate and output files (objects, libraries, executables)...
.PHONY: clean
clean:
	rm -f gccDebug/*.o
	rm -f gccDebug/*.d
	rm -f ../gccDebug/*.a
	rm -f ../gccDebug/*.so
	rm -f ../gccDebug/*.dll
	rm -f ../gccDebug/*.exe
	rm -f gccRelease/*.o
	rm -f gccRelease/*.d
	rm -f ../gccRelease/*.a
	rm -f ../gccRelease/*.so
	rm -f ../gccRelease/*.dll
	rm -f ../gccRelease/*.exe


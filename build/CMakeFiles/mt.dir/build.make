# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = "C:/Program Files/CMake/bin/cmake.exe"

# The command to remove a file.
RM = "C:/Program Files/CMake/bin/cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:/Users/pedro/Downloads/TrabFinal

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:/Users/pedro/Downloads/TrabFinal/build

# Include any dependencies generated for this target.
include CMakeFiles/mt.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/mt.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/mt.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mt.dir/flags.make

CMakeFiles/mt.dir/src/data_gen/mtwister/mtwister.c.obj: CMakeFiles/mt.dir/flags.make
CMakeFiles/mt.dir/src/data_gen/mtwister/mtwister.c.obj: ../src/data_gen/mtwister/mtwister.c
CMakeFiles/mt.dir/src/data_gen/mtwister/mtwister.c.obj: CMakeFiles/mt.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:/Users/pedro/Downloads/TrabFinal/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/mt.dir/src/data_gen/mtwister/mtwister.c.obj"
	C:/msys64/mingw64/bin/x86_64-w64-mingw32-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/mt.dir/src/data_gen/mtwister/mtwister.c.obj -MF CMakeFiles/mt.dir/src/data_gen/mtwister/mtwister.c.obj.d -o CMakeFiles/mt.dir/src/data_gen/mtwister/mtwister.c.obj -c C:/Users/pedro/Downloads/TrabFinal/src/data_gen/mtwister/mtwister.c

CMakeFiles/mt.dir/src/data_gen/mtwister/mtwister.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mt.dir/src/data_gen/mtwister/mtwister.c.i"
	C:/msys64/mingw64/bin/x86_64-w64-mingw32-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:/Users/pedro/Downloads/TrabFinal/src/data_gen/mtwister/mtwister.c > CMakeFiles/mt.dir/src/data_gen/mtwister/mtwister.c.i

CMakeFiles/mt.dir/src/data_gen/mtwister/mtwister.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mt.dir/src/data_gen/mtwister/mtwister.c.s"
	C:/msys64/mingw64/bin/x86_64-w64-mingw32-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:/Users/pedro/Downloads/TrabFinal/src/data_gen/mtwister/mtwister.c -o CMakeFiles/mt.dir/src/data_gen/mtwister/mtwister.c.s

# Object files for target mt
mt_OBJECTS = \
"CMakeFiles/mt.dir/src/data_gen/mtwister/mtwister.c.obj"

# External object files for target mt
mt_EXTERNAL_OBJECTS =

libmt.a: CMakeFiles/mt.dir/src/data_gen/mtwister/mtwister.c.obj
libmt.a: CMakeFiles/mt.dir/build.make
libmt.a: CMakeFiles/mt.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:/Users/pedro/Downloads/TrabFinal/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libmt.a"
	$(CMAKE_COMMAND) -P CMakeFiles/mt.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mt.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mt.dir/build: libmt.a
.PHONY : CMakeFiles/mt.dir/build

CMakeFiles/mt.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mt.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mt.dir/clean

CMakeFiles/mt.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" C:/Users/pedro/Downloads/TrabFinal C:/Users/pedro/Downloads/TrabFinal C:/Users/pedro/Downloads/TrabFinal/build C:/Users/pedro/Downloads/TrabFinal/build C:/Users/pedro/Downloads/TrabFinal/build/CMakeFiles/mt.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mt.dir/depend

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

# Produce verbose output by default.
VERBOSE = 1

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
include CMakeFiles/trabFinal.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/trabFinal.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/trabFinal.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/trabFinal.dir/flags.make

CMakeFiles/trabFinal.dir/src/main.c.obj: CMakeFiles/trabFinal.dir/flags.make
CMakeFiles/trabFinal.dir/src/main.c.obj: ../src/main.c
CMakeFiles/trabFinal.dir/src/main.c.obj: CMakeFiles/trabFinal.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:/Users/pedro/Downloads/TrabFinal/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/trabFinal.dir/src/main.c.obj"
	C:/msys64/mingw64/bin/x86_64-w64-mingw32-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/trabFinal.dir/src/main.c.obj -MF CMakeFiles/trabFinal.dir/src/main.c.obj.d -o CMakeFiles/trabFinal.dir/src/main.c.obj -c C:/Users/pedro/Downloads/TrabFinal/src/main.c

CMakeFiles/trabFinal.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/trabFinal.dir/src/main.c.i"
	C:/msys64/mingw64/bin/x86_64-w64-mingw32-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:/Users/pedro/Downloads/TrabFinal/src/main.c > CMakeFiles/trabFinal.dir/src/main.c.i

CMakeFiles/trabFinal.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/trabFinal.dir/src/main.c.s"
	C:/msys64/mingw64/bin/x86_64-w64-mingw32-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:/Users/pedro/Downloads/TrabFinal/src/main.c -o CMakeFiles/trabFinal.dir/src/main.c.s

# Object files for target trabFinal
trabFinal_OBJECTS = \
"CMakeFiles/trabFinal.dir/src/main.c.obj"

# External object files for target trabFinal
trabFinal_EXTERNAL_OBJECTS =

trabFinal.exe: CMakeFiles/trabFinal.dir/src/main.c.obj
trabFinal.exe: CMakeFiles/trabFinal.dir/build.make
trabFinal.exe: libdata_gen.a
trabFinal.exe: liblog.a
trabFinal.exe: liblse.a
trabFinal.exe: libabp.a
trabFinal.exe: librandom.a
trabFinal.exe: liblog.a
trabFinal.exe: CMakeFiles/trabFinal.dir/linklibs.rsp
trabFinal.exe: CMakeFiles/trabFinal.dir/objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:/Users/pedro/Downloads/TrabFinal/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable trabFinal.exe"
	"C:/Program Files/CMake/bin/cmake.exe" -E rm -f CMakeFiles/trabFinal.dir/objects.a
	C:/msys64/mingw64/bin/ar.exe cr CMakeFiles/trabFinal.dir/objects.a @CMakeFiles/trabFinal.dir/objects1.rsp
	C:/msys64/mingw64/bin/x86_64-w64-mingw32-gcc.exe -g -Wl,--whole-archive CMakeFiles/trabFinal.dir/objects.a -Wl,--no-whole-archive -o trabFinal.exe -Wl,--out-implib,libtrabFinal.dll.a -Wl,--major-image-version,0,--minor-image-version,0 @CMakeFiles/trabFinal.dir/linklibs.rsp

# Rule to build all files generated by this target.
CMakeFiles/trabFinal.dir/build: trabFinal.exe
.PHONY : CMakeFiles/trabFinal.dir/build

CMakeFiles/trabFinal.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/trabFinal.dir/cmake_clean.cmake
.PHONY : CMakeFiles/trabFinal.dir/clean

CMakeFiles/trabFinal.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" C:/Users/pedro/Downloads/TrabFinal C:/Users/pedro/Downloads/TrabFinal C:/Users/pedro/Downloads/TrabFinal/build C:/Users/pedro/Downloads/TrabFinal/build C:/Users/pedro/Downloads/TrabFinal/build/CMakeFiles/trabFinal.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/trabFinal.dir/depend


# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.6

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files (x86)\JetBrains\CLion 2016.3.4\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files (x86)\JetBrains\CLion 2016.3.4\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Admin\CLionProjects\mycp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Admin\CLionProjects\mycp\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/mycp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/mycp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mycp.dir/flags.make

CMakeFiles/mycp.dir/main.cpp.obj: CMakeFiles/mycp.dir/flags.make
CMakeFiles/mycp.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Admin\CLionProjects\mycp\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mycp.dir/main.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-6~1.0-P\mingw32\bin\G__~1.EXE   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\mycp.dir\main.cpp.obj -c C:\Users\Admin\CLionProjects\mycp\main.cpp

CMakeFiles/mycp.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mycp.dir/main.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-6~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Admin\CLionProjects\mycp\main.cpp > CMakeFiles\mycp.dir\main.cpp.i

CMakeFiles/mycp.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mycp.dir/main.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-6~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Admin\CLionProjects\mycp\main.cpp -o CMakeFiles\mycp.dir\main.cpp.s

CMakeFiles/mycp.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/mycp.dir/main.cpp.obj.requires

CMakeFiles/mycp.dir/main.cpp.obj.provides: CMakeFiles/mycp.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\mycp.dir\build.make CMakeFiles/mycp.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/mycp.dir/main.cpp.obj.provides

CMakeFiles/mycp.dir/main.cpp.obj.provides.build: CMakeFiles/mycp.dir/main.cpp.obj


# Object files for target mycp
mycp_OBJECTS = \
"CMakeFiles/mycp.dir/main.cpp.obj"

# External object files for target mycp
mycp_EXTERNAL_OBJECTS =

mycp.exe: CMakeFiles/mycp.dir/main.cpp.obj
mycp.exe: CMakeFiles/mycp.dir/build.make
mycp.exe: CMakeFiles/mycp.dir/linklibs.rsp
mycp.exe: CMakeFiles/mycp.dir/objects1.rsp
mycp.exe: CMakeFiles/mycp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Admin\CLionProjects\mycp\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable mycp.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\mycp.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mycp.dir/build: mycp.exe

.PHONY : CMakeFiles/mycp.dir/build

CMakeFiles/mycp.dir/requires: CMakeFiles/mycp.dir/main.cpp.obj.requires

.PHONY : CMakeFiles/mycp.dir/requires

CMakeFiles/mycp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\mycp.dir\cmake_clean.cmake
.PHONY : CMakeFiles/mycp.dir/clean

CMakeFiles/mycp.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Admin\CLionProjects\mycp C:\Users\Admin\CLionProjects\mycp C:\Users\Admin\CLionProjects\mycp\cmake-build-debug C:\Users\Admin\CLionProjects\mycp\cmake-build-debug C:\Users\Admin\CLionProjects\mycp\cmake-build-debug\CMakeFiles\mycp.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mycp.dir/depend


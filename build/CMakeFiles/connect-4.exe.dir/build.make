# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/serwer39/program/connect-4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/serwer39/program/connect-4/build

# Include any dependencies generated for this target.
include CMakeFiles/connect-4.exe.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/connect-4.exe.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/connect-4.exe.dir/flags.make

CMakeFiles/connect-4.exe.dir/main.cpp.o: CMakeFiles/connect-4.exe.dir/flags.make
CMakeFiles/connect-4.exe.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/serwer39/program/connect-4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/connect-4.exe.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/connect-4.exe.dir/main.cpp.o -c /home/serwer39/program/connect-4/main.cpp

CMakeFiles/connect-4.exe.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/connect-4.exe.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/serwer39/program/connect-4/main.cpp > CMakeFiles/connect-4.exe.dir/main.cpp.i

CMakeFiles/connect-4.exe.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/connect-4.exe.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/serwer39/program/connect-4/main.cpp -o CMakeFiles/connect-4.exe.dir/main.cpp.s

CMakeFiles/connect-4.exe.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/connect-4.exe.dir/main.cpp.o.requires

CMakeFiles/connect-4.exe.dir/main.cpp.o.provides: CMakeFiles/connect-4.exe.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/connect-4.exe.dir/build.make CMakeFiles/connect-4.exe.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/connect-4.exe.dir/main.cpp.o.provides

CMakeFiles/connect-4.exe.dir/main.cpp.o.provides.build: CMakeFiles/connect-4.exe.dir/main.cpp.o


# Object files for target connect-4.exe
connect__4_exe_OBJECTS = \
"CMakeFiles/connect-4.exe.dir/main.cpp.o"

# External object files for target connect-4.exe
connect__4_exe_EXTERNAL_OBJECTS =

connect-4.exe: CMakeFiles/connect-4.exe.dir/main.cpp.o
connect-4.exe: CMakeFiles/connect-4.exe.dir/build.make
connect-4.exe: CMakeFiles/connect-4.exe.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/serwer39/program/connect-4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable connect-4.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/connect-4.exe.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/connect-4.exe.dir/build: connect-4.exe

.PHONY : CMakeFiles/connect-4.exe.dir/build

CMakeFiles/connect-4.exe.dir/requires: CMakeFiles/connect-4.exe.dir/main.cpp.o.requires

.PHONY : CMakeFiles/connect-4.exe.dir/requires

CMakeFiles/connect-4.exe.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/connect-4.exe.dir/cmake_clean.cmake
.PHONY : CMakeFiles/connect-4.exe.dir/clean

CMakeFiles/connect-4.exe.dir/depend:
	cd /home/serwer39/program/connect-4/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/serwer39/program/connect-4 /home/serwer39/program/connect-4 /home/serwer39/program/connect-4/build /home/serwer39/program/connect-4/build /home/serwer39/program/connect-4/build/CMakeFiles/connect-4.exe.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/connect-4.exe.dir/depend


# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /cygdrive/c/Users/Sereg/.CLion2019.2/system/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/Sereg/.CLion2019.2/system/cygwin_cmake/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/c/Users/Sereg/CLionProjects/Lab1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/Users/Sereg/CLionProjects/Lab1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Lab1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Lab1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Lab1.dir/flags.make

CMakeFiles/Lab1.dir/main.cpp.o: CMakeFiles/Lab1.dir/flags.make
CMakeFiles/Lab1.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/Sereg/CLionProjects/Lab1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Lab1.dir/main.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Lab1.dir/main.cpp.o -c /cygdrive/c/Users/Sereg/CLionProjects/Lab1/main.cpp

CMakeFiles/Lab1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab1.dir/main.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/Sereg/CLionProjects/Lab1/main.cpp > CMakeFiles/Lab1.dir/main.cpp.i

CMakeFiles/Lab1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab1.dir/main.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/Sereg/CLionProjects/Lab1/main.cpp -o CMakeFiles/Lab1.dir/main.cpp.s

# Object files for target Lab1
Lab1_OBJECTS = \
"CMakeFiles/Lab1.dir/main.cpp.o"

# External object files for target Lab1
Lab1_EXTERNAL_OBJECTS =

Lab1.exe: CMakeFiles/Lab1.dir/main.cpp.o
Lab1.exe: CMakeFiles/Lab1.dir/build.make
Lab1.exe: CMakeFiles/Lab1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/Users/Sereg/CLionProjects/Lab1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Lab1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Lab1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Lab1.dir/build: Lab1.exe

.PHONY : CMakeFiles/Lab1.dir/build

CMakeFiles/Lab1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Lab1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Lab1.dir/clean

CMakeFiles/Lab1.dir/depend:
	cd /cygdrive/c/Users/Sereg/CLionProjects/Lab1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/Sereg/CLionProjects/Lab1 /cygdrive/c/Users/Sereg/CLionProjects/Lab1 /cygdrive/c/Users/Sereg/CLionProjects/Lab1/cmake-build-debug /cygdrive/c/Users/Sereg/CLionProjects/Lab1/cmake-build-debug /cygdrive/c/Users/Sereg/CLionProjects/Lab1/cmake-build-debug/CMakeFiles/Lab1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Lab1.dir/depend


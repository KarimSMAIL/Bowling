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
CMAKE_SOURCE_DIR = /home/karim/Bureau/Bowling

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/karim/Bureau/Bowling

# Include any dependencies generated for this target.
include include/googletest/CMakeFiles/gtest.dir/depend.make

# Include the progress variables for this target.
include include/googletest/CMakeFiles/gtest.dir/progress.make

# Include the compile flags for this target's objects.
include include/googletest/CMakeFiles/gtest.dir/flags.make

include/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o: include/googletest/CMakeFiles/gtest.dir/flags.make
include/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o: include/googletest/src/gtest-all.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/karim/Bureau/Bowling/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object include/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o"
	cd /home/karim/Bureau/Bowling/include/googletest && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gtest.dir/src/gtest-all.cc.o -c /home/karim/Bureau/Bowling/include/googletest/src/gtest-all.cc

include/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest.dir/src/gtest-all.cc.i"
	cd /home/karim/Bureau/Bowling/include/googletest && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/karim/Bureau/Bowling/include/googletest/src/gtest-all.cc > CMakeFiles/gtest.dir/src/gtest-all.cc.i

include/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest.dir/src/gtest-all.cc.s"
	cd /home/karim/Bureau/Bowling/include/googletest && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/karim/Bureau/Bowling/include/googletest/src/gtest-all.cc -o CMakeFiles/gtest.dir/src/gtest-all.cc.s

include/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.requires:

.PHONY : include/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.requires

include/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.provides: include/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.requires
	$(MAKE) -f include/googletest/CMakeFiles/gtest.dir/build.make include/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.provides.build
.PHONY : include/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.provides

include/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.provides.build: include/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o


# Object files for target gtest
gtest_OBJECTS = \
"CMakeFiles/gtest.dir/src/gtest-all.cc.o"

# External object files for target gtest
gtest_EXTERNAL_OBJECTS =

include/googletest/libgtest.a: include/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o
include/googletest/libgtest.a: include/googletest/CMakeFiles/gtest.dir/build.make
include/googletest/libgtest.a: include/googletest/CMakeFiles/gtest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/karim/Bureau/Bowling/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libgtest.a"
	cd /home/karim/Bureau/Bowling/include/googletest && $(CMAKE_COMMAND) -P CMakeFiles/gtest.dir/cmake_clean_target.cmake
	cd /home/karim/Bureau/Bowling/include/googletest && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gtest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
include/googletest/CMakeFiles/gtest.dir/build: include/googletest/libgtest.a

.PHONY : include/googletest/CMakeFiles/gtest.dir/build

include/googletest/CMakeFiles/gtest.dir/requires: include/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.requires

.PHONY : include/googletest/CMakeFiles/gtest.dir/requires

include/googletest/CMakeFiles/gtest.dir/clean:
	cd /home/karim/Bureau/Bowling/include/googletest && $(CMAKE_COMMAND) -P CMakeFiles/gtest.dir/cmake_clean.cmake
.PHONY : include/googletest/CMakeFiles/gtest.dir/clean

include/googletest/CMakeFiles/gtest.dir/depend:
	cd /home/karim/Bureau/Bowling && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/karim/Bureau/Bowling /home/karim/Bureau/Bowling/include/googletest /home/karim/Bureau/Bowling /home/karim/Bureau/Bowling/include/googletest /home/karim/Bureau/Bowling/include/googletest/CMakeFiles/gtest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : include/googletest/CMakeFiles/gtest.dir/depend


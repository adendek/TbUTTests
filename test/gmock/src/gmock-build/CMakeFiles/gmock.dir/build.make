# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.4

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
CMAKE_COMMAND = /home/ja/Documents/lhcb/TbUTTests/cmake-3.4.0-rc3-Linux-x86_64/bin/cmake

# The command to remove a file.
RM = /home/ja/Documents/lhcb/TbUTTests/cmake-3.4.0-rc3-Linux-x86_64/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ja/Documents/lhcb/TbUTTests/test/gmock/src/gmock

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ja/Documents/lhcb/TbUTTests/test/gmock/src/gmock-build

# Include any dependencies generated for this target.
include CMakeFiles/gmock.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/gmock.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/gmock.dir/flags.make

CMakeFiles/gmock.dir/gtest/src/gtest-all.cc.o: CMakeFiles/gmock.dir/flags.make
CMakeFiles/gmock.dir/gtest/src/gtest-all.cc.o: /home/ja/Documents/lhcb/TbUTTests/test/gmock/src/gmock/gtest/src/gtest-all.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ja/Documents/lhcb/TbUTTests/test/gmock/src/gmock-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/gmock.dir/gtest/src/gtest-all.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gmock.dir/gtest/src/gtest-all.cc.o -c /home/ja/Documents/lhcb/TbUTTests/test/gmock/src/gmock/gtest/src/gtest-all.cc

CMakeFiles/gmock.dir/gtest/src/gtest-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gmock.dir/gtest/src/gtest-all.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ja/Documents/lhcb/TbUTTests/test/gmock/src/gmock/gtest/src/gtest-all.cc > CMakeFiles/gmock.dir/gtest/src/gtest-all.cc.i

CMakeFiles/gmock.dir/gtest/src/gtest-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gmock.dir/gtest/src/gtest-all.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ja/Documents/lhcb/TbUTTests/test/gmock/src/gmock/gtest/src/gtest-all.cc -o CMakeFiles/gmock.dir/gtest/src/gtest-all.cc.s

CMakeFiles/gmock.dir/gtest/src/gtest-all.cc.o.requires:

.PHONY : CMakeFiles/gmock.dir/gtest/src/gtest-all.cc.o.requires

CMakeFiles/gmock.dir/gtest/src/gtest-all.cc.o.provides: CMakeFiles/gmock.dir/gtest/src/gtest-all.cc.o.requires
	$(MAKE) -f CMakeFiles/gmock.dir/build.make CMakeFiles/gmock.dir/gtest/src/gtest-all.cc.o.provides.build
.PHONY : CMakeFiles/gmock.dir/gtest/src/gtest-all.cc.o.provides

CMakeFiles/gmock.dir/gtest/src/gtest-all.cc.o.provides.build: CMakeFiles/gmock.dir/gtest/src/gtest-all.cc.o


CMakeFiles/gmock.dir/src/gmock-all.cc.o: CMakeFiles/gmock.dir/flags.make
CMakeFiles/gmock.dir/src/gmock-all.cc.o: /home/ja/Documents/lhcb/TbUTTests/test/gmock/src/gmock/src/gmock-all.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ja/Documents/lhcb/TbUTTests/test/gmock/src/gmock-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/gmock.dir/src/gmock-all.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gmock.dir/src/gmock-all.cc.o -c /home/ja/Documents/lhcb/TbUTTests/test/gmock/src/gmock/src/gmock-all.cc

CMakeFiles/gmock.dir/src/gmock-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gmock.dir/src/gmock-all.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ja/Documents/lhcb/TbUTTests/test/gmock/src/gmock/src/gmock-all.cc > CMakeFiles/gmock.dir/src/gmock-all.cc.i

CMakeFiles/gmock.dir/src/gmock-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gmock.dir/src/gmock-all.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ja/Documents/lhcb/TbUTTests/test/gmock/src/gmock/src/gmock-all.cc -o CMakeFiles/gmock.dir/src/gmock-all.cc.s

CMakeFiles/gmock.dir/src/gmock-all.cc.o.requires:

.PHONY : CMakeFiles/gmock.dir/src/gmock-all.cc.o.requires

CMakeFiles/gmock.dir/src/gmock-all.cc.o.provides: CMakeFiles/gmock.dir/src/gmock-all.cc.o.requires
	$(MAKE) -f CMakeFiles/gmock.dir/build.make CMakeFiles/gmock.dir/src/gmock-all.cc.o.provides.build
.PHONY : CMakeFiles/gmock.dir/src/gmock-all.cc.o.provides

CMakeFiles/gmock.dir/src/gmock-all.cc.o.provides.build: CMakeFiles/gmock.dir/src/gmock-all.cc.o


# Object files for target gmock
gmock_OBJECTS = \
"CMakeFiles/gmock.dir/gtest/src/gtest-all.cc.o" \
"CMakeFiles/gmock.dir/src/gmock-all.cc.o"

# External object files for target gmock
gmock_EXTERNAL_OBJECTS =

libgmock.a: CMakeFiles/gmock.dir/gtest/src/gtest-all.cc.o
libgmock.a: CMakeFiles/gmock.dir/src/gmock-all.cc.o
libgmock.a: CMakeFiles/gmock.dir/build.make
libgmock.a: CMakeFiles/gmock.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ja/Documents/lhcb/TbUTTests/test/gmock/src/gmock-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libgmock.a"
	$(CMAKE_COMMAND) -P CMakeFiles/gmock.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gmock.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/gmock.dir/build: libgmock.a

.PHONY : CMakeFiles/gmock.dir/build

CMakeFiles/gmock.dir/requires: CMakeFiles/gmock.dir/gtest/src/gtest-all.cc.o.requires
CMakeFiles/gmock.dir/requires: CMakeFiles/gmock.dir/src/gmock-all.cc.o.requires

.PHONY : CMakeFiles/gmock.dir/requires

CMakeFiles/gmock.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/gmock.dir/cmake_clean.cmake
.PHONY : CMakeFiles/gmock.dir/clean

CMakeFiles/gmock.dir/depend:
	cd /home/ja/Documents/lhcb/TbUTTests/test/gmock/src/gmock-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ja/Documents/lhcb/TbUTTests/test/gmock/src/gmock /home/ja/Documents/lhcb/TbUTTests/test/gmock/src/gmock /home/ja/Documents/lhcb/TbUTTests/test/gmock/src/gmock-build /home/ja/Documents/lhcb/TbUTTests/test/gmock/src/gmock-build /home/ja/Documents/lhcb/TbUTTests/test/gmock/src/gmock-build/CMakeFiles/gmock.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/gmock.dir/depend


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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/lucille/Works/algo/4181_convex_hull

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/lucille/Works/algo/4181_convex_hull/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/4181_convex_hull.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/4181_convex_hull.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/4181_convex_hull.dir/flags.make

CMakeFiles/4181_convex_hull.dir/main.cpp.o: CMakeFiles/4181_convex_hull.dir/flags.make
CMakeFiles/4181_convex_hull.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lucille/Works/algo/4181_convex_hull/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/4181_convex_hull.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/4181_convex_hull.dir/main.cpp.o -c /Users/lucille/Works/algo/4181_convex_hull/main.cpp

CMakeFiles/4181_convex_hull.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/4181_convex_hull.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lucille/Works/algo/4181_convex_hull/main.cpp > CMakeFiles/4181_convex_hull.dir/main.cpp.i

CMakeFiles/4181_convex_hull.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/4181_convex_hull.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lucille/Works/algo/4181_convex_hull/main.cpp -o CMakeFiles/4181_convex_hull.dir/main.cpp.s

# Object files for target 4181_convex_hull
4181_convex_hull_OBJECTS = \
"CMakeFiles/4181_convex_hull.dir/main.cpp.o"

# External object files for target 4181_convex_hull
4181_convex_hull_EXTERNAL_OBJECTS =

4181_convex_hull: CMakeFiles/4181_convex_hull.dir/main.cpp.o
4181_convex_hull: CMakeFiles/4181_convex_hull.dir/build.make
4181_convex_hull: CMakeFiles/4181_convex_hull.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/lucille/Works/algo/4181_convex_hull/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 4181_convex_hull"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/4181_convex_hull.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/4181_convex_hull.dir/build: 4181_convex_hull

.PHONY : CMakeFiles/4181_convex_hull.dir/build

CMakeFiles/4181_convex_hull.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/4181_convex_hull.dir/cmake_clean.cmake
.PHONY : CMakeFiles/4181_convex_hull.dir/clean

CMakeFiles/4181_convex_hull.dir/depend:
	cd /Users/lucille/Works/algo/4181_convex_hull/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/lucille/Works/algo/4181_convex_hull /Users/lucille/Works/algo/4181_convex_hull /Users/lucille/Works/algo/4181_convex_hull/cmake-build-debug /Users/lucille/Works/algo/4181_convex_hull/cmake-build-debug /Users/lucille/Works/algo/4181_convex_hull/cmake-build-debug/CMakeFiles/4181_convex_hull.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/4181_convex_hull.dir/depend

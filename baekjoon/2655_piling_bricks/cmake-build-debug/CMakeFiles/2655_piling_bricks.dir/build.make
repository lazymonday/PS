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
CMAKE_SOURCE_DIR = /Users/lucille/Works/algo/2655_piling_bricks

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/lucille/Works/algo/2655_piling_bricks/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/2655_piling_bricks.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/2655_piling_bricks.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/2655_piling_bricks.dir/flags.make

CMakeFiles/2655_piling_bricks.dir/main.cpp.o: CMakeFiles/2655_piling_bricks.dir/flags.make
CMakeFiles/2655_piling_bricks.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lucille/Works/algo/2655_piling_bricks/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/2655_piling_bricks.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/2655_piling_bricks.dir/main.cpp.o -c /Users/lucille/Works/algo/2655_piling_bricks/main.cpp

CMakeFiles/2655_piling_bricks.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/2655_piling_bricks.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lucille/Works/algo/2655_piling_bricks/main.cpp > CMakeFiles/2655_piling_bricks.dir/main.cpp.i

CMakeFiles/2655_piling_bricks.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/2655_piling_bricks.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lucille/Works/algo/2655_piling_bricks/main.cpp -o CMakeFiles/2655_piling_bricks.dir/main.cpp.s

# Object files for target 2655_piling_bricks
2655_piling_bricks_OBJECTS = \
"CMakeFiles/2655_piling_bricks.dir/main.cpp.o"

# External object files for target 2655_piling_bricks
2655_piling_bricks_EXTERNAL_OBJECTS =

2655_piling_bricks: CMakeFiles/2655_piling_bricks.dir/main.cpp.o
2655_piling_bricks: CMakeFiles/2655_piling_bricks.dir/build.make
2655_piling_bricks: CMakeFiles/2655_piling_bricks.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/lucille/Works/algo/2655_piling_bricks/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 2655_piling_bricks"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/2655_piling_bricks.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/2655_piling_bricks.dir/build: 2655_piling_bricks

.PHONY : CMakeFiles/2655_piling_bricks.dir/build

CMakeFiles/2655_piling_bricks.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/2655_piling_bricks.dir/cmake_clean.cmake
.PHONY : CMakeFiles/2655_piling_bricks.dir/clean

CMakeFiles/2655_piling_bricks.dir/depend:
	cd /Users/lucille/Works/algo/2655_piling_bricks/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/lucille/Works/algo/2655_piling_bricks /Users/lucille/Works/algo/2655_piling_bricks /Users/lucille/Works/algo/2655_piling_bricks/cmake-build-debug /Users/lucille/Works/algo/2655_piling_bricks/cmake-build-debug /Users/lucille/Works/algo/2655_piling_bricks/cmake-build-debug/CMakeFiles/2655_piling_bricks.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/2655_piling_bricks.dir/depend

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
CMAKE_SOURCE_DIR = /Users/lucille/Works/algo/2912_snow_white

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/lucille/Works/algo/2912_snow_white/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/2912_snow_white.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/2912_snow_white.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/2912_snow_white.dir/flags.make

CMakeFiles/2912_snow_white.dir/main.cpp.o: CMakeFiles/2912_snow_white.dir/flags.make
CMakeFiles/2912_snow_white.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lucille/Works/algo/2912_snow_white/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/2912_snow_white.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/2912_snow_white.dir/main.cpp.o -c /Users/lucille/Works/algo/2912_snow_white/main.cpp

CMakeFiles/2912_snow_white.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/2912_snow_white.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lucille/Works/algo/2912_snow_white/main.cpp > CMakeFiles/2912_snow_white.dir/main.cpp.i

CMakeFiles/2912_snow_white.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/2912_snow_white.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lucille/Works/algo/2912_snow_white/main.cpp -o CMakeFiles/2912_snow_white.dir/main.cpp.s

# Object files for target 2912_snow_white
2912_snow_white_OBJECTS = \
"CMakeFiles/2912_snow_white.dir/main.cpp.o"

# External object files for target 2912_snow_white
2912_snow_white_EXTERNAL_OBJECTS =

2912_snow_white: CMakeFiles/2912_snow_white.dir/main.cpp.o
2912_snow_white: CMakeFiles/2912_snow_white.dir/build.make
2912_snow_white: CMakeFiles/2912_snow_white.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/lucille/Works/algo/2912_snow_white/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 2912_snow_white"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/2912_snow_white.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/2912_snow_white.dir/build: 2912_snow_white

.PHONY : CMakeFiles/2912_snow_white.dir/build

CMakeFiles/2912_snow_white.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/2912_snow_white.dir/cmake_clean.cmake
.PHONY : CMakeFiles/2912_snow_white.dir/clean

CMakeFiles/2912_snow_white.dir/depend:
	cd /Users/lucille/Works/algo/2912_snow_white/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/lucille/Works/algo/2912_snow_white /Users/lucille/Works/algo/2912_snow_white /Users/lucille/Works/algo/2912_snow_white/cmake-build-debug /Users/lucille/Works/algo/2912_snow_white/cmake-build-debug /Users/lucille/Works/algo/2912_snow_white/cmake-build-debug/CMakeFiles/2912_snow_white.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/2912_snow_white.dir/depend


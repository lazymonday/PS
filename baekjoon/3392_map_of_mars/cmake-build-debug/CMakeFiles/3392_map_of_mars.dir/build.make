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
CMAKE_SOURCE_DIR = /Users/lucille/Works/algo/3392_map_of_mars

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/lucille/Works/algo/3392_map_of_mars/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/3392_map_of_mars.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/3392_map_of_mars.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/3392_map_of_mars.dir/flags.make

CMakeFiles/3392_map_of_mars.dir/main.cpp.o: CMakeFiles/3392_map_of_mars.dir/flags.make
CMakeFiles/3392_map_of_mars.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lucille/Works/algo/3392_map_of_mars/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/3392_map_of_mars.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/3392_map_of_mars.dir/main.cpp.o -c /Users/lucille/Works/algo/3392_map_of_mars/main.cpp

CMakeFiles/3392_map_of_mars.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/3392_map_of_mars.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lucille/Works/algo/3392_map_of_mars/main.cpp > CMakeFiles/3392_map_of_mars.dir/main.cpp.i

CMakeFiles/3392_map_of_mars.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/3392_map_of_mars.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lucille/Works/algo/3392_map_of_mars/main.cpp -o CMakeFiles/3392_map_of_mars.dir/main.cpp.s

# Object files for target 3392_map_of_mars
3392_map_of_mars_OBJECTS = \
"CMakeFiles/3392_map_of_mars.dir/main.cpp.o"

# External object files for target 3392_map_of_mars
3392_map_of_mars_EXTERNAL_OBJECTS =

3392_map_of_mars: CMakeFiles/3392_map_of_mars.dir/main.cpp.o
3392_map_of_mars: CMakeFiles/3392_map_of_mars.dir/build.make
3392_map_of_mars: CMakeFiles/3392_map_of_mars.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/lucille/Works/algo/3392_map_of_mars/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 3392_map_of_mars"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/3392_map_of_mars.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/3392_map_of_mars.dir/build: 3392_map_of_mars

.PHONY : CMakeFiles/3392_map_of_mars.dir/build

CMakeFiles/3392_map_of_mars.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/3392_map_of_mars.dir/cmake_clean.cmake
.PHONY : CMakeFiles/3392_map_of_mars.dir/clean

CMakeFiles/3392_map_of_mars.dir/depend:
	cd /Users/lucille/Works/algo/3392_map_of_mars/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/lucille/Works/algo/3392_map_of_mars /Users/lucille/Works/algo/3392_map_of_mars /Users/lucille/Works/algo/3392_map_of_mars/cmake-build-debug /Users/lucille/Works/algo/3392_map_of_mars/cmake-build-debug /Users/lucille/Works/algo/3392_map_of_mars/cmake-build-debug/CMakeFiles/3392_map_of_mars.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/3392_map_of_mars.dir/depend

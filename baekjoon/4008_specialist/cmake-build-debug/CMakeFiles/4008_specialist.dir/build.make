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
CMAKE_SOURCE_DIR = /Users/lucille/Works/algo/4008_specialist

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/lucille/Works/algo/4008_specialist/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/4008_specialist.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/4008_specialist.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/4008_specialist.dir/flags.make

CMakeFiles/4008_specialist.dir/main.cpp.o: CMakeFiles/4008_specialist.dir/flags.make
CMakeFiles/4008_specialist.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lucille/Works/algo/4008_specialist/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/4008_specialist.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/4008_specialist.dir/main.cpp.o -c /Users/lucille/Works/algo/4008_specialist/main.cpp

CMakeFiles/4008_specialist.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/4008_specialist.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lucille/Works/algo/4008_specialist/main.cpp > CMakeFiles/4008_specialist.dir/main.cpp.i

CMakeFiles/4008_specialist.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/4008_specialist.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lucille/Works/algo/4008_specialist/main.cpp -o CMakeFiles/4008_specialist.dir/main.cpp.s

# Object files for target 4008_specialist
4008_specialist_OBJECTS = \
"CMakeFiles/4008_specialist.dir/main.cpp.o"

# External object files for target 4008_specialist
4008_specialist_EXTERNAL_OBJECTS =

4008_specialist: CMakeFiles/4008_specialist.dir/main.cpp.o
4008_specialist: CMakeFiles/4008_specialist.dir/build.make
4008_specialist: CMakeFiles/4008_specialist.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/lucille/Works/algo/4008_specialist/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 4008_specialist"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/4008_specialist.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/4008_specialist.dir/build: 4008_specialist

.PHONY : CMakeFiles/4008_specialist.dir/build

CMakeFiles/4008_specialist.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/4008_specialist.dir/cmake_clean.cmake
.PHONY : CMakeFiles/4008_specialist.dir/clean

CMakeFiles/4008_specialist.dir/depend:
	cd /Users/lucille/Works/algo/4008_specialist/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/lucille/Works/algo/4008_specialist /Users/lucille/Works/algo/4008_specialist /Users/lucille/Works/algo/4008_specialist/cmake-build-debug /Users/lucille/Works/algo/4008_specialist/cmake-build-debug /Users/lucille/Works/algo/4008_specialist/cmake-build-debug/CMakeFiles/4008_specialist.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/4008_specialist.dir/depend


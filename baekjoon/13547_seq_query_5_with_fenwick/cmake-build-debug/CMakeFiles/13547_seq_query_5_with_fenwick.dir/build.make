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
CMAKE_SOURCE_DIR = /Users/lucille/Works/algo/13547_seq_query_5_with_fenwick

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/lucille/Works/algo/13547_seq_query_5_with_fenwick/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/13547_seq_query_5_with_fenwick.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/13547_seq_query_5_with_fenwick.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/13547_seq_query_5_with_fenwick.dir/flags.make

CMakeFiles/13547_seq_query_5_with_fenwick.dir/main.cpp.o: CMakeFiles/13547_seq_query_5_with_fenwick.dir/flags.make
CMakeFiles/13547_seq_query_5_with_fenwick.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lucille/Works/algo/13547_seq_query_5_with_fenwick/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/13547_seq_query_5_with_fenwick.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/13547_seq_query_5_with_fenwick.dir/main.cpp.o -c /Users/lucille/Works/algo/13547_seq_query_5_with_fenwick/main.cpp

CMakeFiles/13547_seq_query_5_with_fenwick.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/13547_seq_query_5_with_fenwick.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lucille/Works/algo/13547_seq_query_5_with_fenwick/main.cpp > CMakeFiles/13547_seq_query_5_with_fenwick.dir/main.cpp.i

CMakeFiles/13547_seq_query_5_with_fenwick.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/13547_seq_query_5_with_fenwick.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lucille/Works/algo/13547_seq_query_5_with_fenwick/main.cpp -o CMakeFiles/13547_seq_query_5_with_fenwick.dir/main.cpp.s

# Object files for target 13547_seq_query_5_with_fenwick
13547_seq_query_5_with_fenwick_OBJECTS = \
"CMakeFiles/13547_seq_query_5_with_fenwick.dir/main.cpp.o"

# External object files for target 13547_seq_query_5_with_fenwick
13547_seq_query_5_with_fenwick_EXTERNAL_OBJECTS =

13547_seq_query_5_with_fenwick: CMakeFiles/13547_seq_query_5_with_fenwick.dir/main.cpp.o
13547_seq_query_5_with_fenwick: CMakeFiles/13547_seq_query_5_with_fenwick.dir/build.make
13547_seq_query_5_with_fenwick: CMakeFiles/13547_seq_query_5_with_fenwick.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/lucille/Works/algo/13547_seq_query_5_with_fenwick/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 13547_seq_query_5_with_fenwick"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/13547_seq_query_5_with_fenwick.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/13547_seq_query_5_with_fenwick.dir/build: 13547_seq_query_5_with_fenwick

.PHONY : CMakeFiles/13547_seq_query_5_with_fenwick.dir/build

CMakeFiles/13547_seq_query_5_with_fenwick.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/13547_seq_query_5_with_fenwick.dir/cmake_clean.cmake
.PHONY : CMakeFiles/13547_seq_query_5_with_fenwick.dir/clean

CMakeFiles/13547_seq_query_5_with_fenwick.dir/depend:
	cd /Users/lucille/Works/algo/13547_seq_query_5_with_fenwick/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/lucille/Works/algo/13547_seq_query_5_with_fenwick /Users/lucille/Works/algo/13547_seq_query_5_with_fenwick /Users/lucille/Works/algo/13547_seq_query_5_with_fenwick/cmake-build-debug /Users/lucille/Works/algo/13547_seq_query_5_with_fenwick/cmake-build-debug /Users/lucille/Works/algo/13547_seq_query_5_with_fenwick/cmake-build-debug/CMakeFiles/13547_seq_query_5_with_fenwick.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/13547_seq_query_5_with_fenwick.dir/depend


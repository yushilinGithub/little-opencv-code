# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/yushilin/workspace/myCode/imageStitch/video_stitch/mining_hole

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/yushilin/workspace/myCode/imageStitch/video_stitch/mining_hole/build

# Include any dependencies generated for this target.
include src/CMakeFiles/util.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/util.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/util.dir/flags.make

src/CMakeFiles/util.dir/util/util.cpp.o: src/CMakeFiles/util.dir/flags.make
src/CMakeFiles/util.dir/util/util.cpp.o: ../src/util/util.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yushilin/workspace/myCode/imageStitch/video_stitch/mining_hole/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/util.dir/util/util.cpp.o"
	cd /home/yushilin/workspace/myCode/imageStitch/video_stitch/mining_hole/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/util.dir/util/util.cpp.o -c /home/yushilin/workspace/myCode/imageStitch/video_stitch/mining_hole/src/util/util.cpp

src/CMakeFiles/util.dir/util/util.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/util.dir/util/util.cpp.i"
	cd /home/yushilin/workspace/myCode/imageStitch/video_stitch/mining_hole/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yushilin/workspace/myCode/imageStitch/video_stitch/mining_hole/src/util/util.cpp > CMakeFiles/util.dir/util/util.cpp.i

src/CMakeFiles/util.dir/util/util.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/util.dir/util/util.cpp.s"
	cd /home/yushilin/workspace/myCode/imageStitch/video_stitch/mining_hole/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yushilin/workspace/myCode/imageStitch/video_stitch/mining_hole/src/util/util.cpp -o CMakeFiles/util.dir/util/util.cpp.s

src/CMakeFiles/util.dir/util/proc.cpp.o: src/CMakeFiles/util.dir/flags.make
src/CMakeFiles/util.dir/util/proc.cpp.o: ../src/util/proc.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yushilin/workspace/myCode/imageStitch/video_stitch/mining_hole/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/util.dir/util/proc.cpp.o"
	cd /home/yushilin/workspace/myCode/imageStitch/video_stitch/mining_hole/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/util.dir/util/proc.cpp.o -c /home/yushilin/workspace/myCode/imageStitch/video_stitch/mining_hole/src/util/proc.cpp

src/CMakeFiles/util.dir/util/proc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/util.dir/util/proc.cpp.i"
	cd /home/yushilin/workspace/myCode/imageStitch/video_stitch/mining_hole/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yushilin/workspace/myCode/imageStitch/video_stitch/mining_hole/src/util/proc.cpp > CMakeFiles/util.dir/util/proc.cpp.i

src/CMakeFiles/util.dir/util/proc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/util.dir/util/proc.cpp.s"
	cd /home/yushilin/workspace/myCode/imageStitch/video_stitch/mining_hole/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yushilin/workspace/myCode/imageStitch/video_stitch/mining_hole/src/util/proc.cpp -o CMakeFiles/util.dir/util/proc.cpp.s

# Object files for target util
util_OBJECTS = \
"CMakeFiles/util.dir/util/util.cpp.o" \
"CMakeFiles/util.dir/util/proc.cpp.o"

# External object files for target util
util_EXTERNAL_OBJECTS =

src/libutil.a: src/CMakeFiles/util.dir/util/util.cpp.o
src/libutil.a: src/CMakeFiles/util.dir/util/proc.cpp.o
src/libutil.a: src/CMakeFiles/util.dir/build.make
src/libutil.a: src/CMakeFiles/util.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/yushilin/workspace/myCode/imageStitch/video_stitch/mining_hole/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libutil.a"
	cd /home/yushilin/workspace/myCode/imageStitch/video_stitch/mining_hole/build/src && $(CMAKE_COMMAND) -P CMakeFiles/util.dir/cmake_clean_target.cmake
	cd /home/yushilin/workspace/myCode/imageStitch/video_stitch/mining_hole/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/util.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/util.dir/build: src/libutil.a

.PHONY : src/CMakeFiles/util.dir/build

src/CMakeFiles/util.dir/clean:
	cd /home/yushilin/workspace/myCode/imageStitch/video_stitch/mining_hole/build/src && $(CMAKE_COMMAND) -P CMakeFiles/util.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/util.dir/clean

src/CMakeFiles/util.dir/depend:
	cd /home/yushilin/workspace/myCode/imageStitch/video_stitch/mining_hole/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yushilin/workspace/myCode/imageStitch/video_stitch/mining_hole /home/yushilin/workspace/myCode/imageStitch/video_stitch/mining_hole/src /home/yushilin/workspace/myCode/imageStitch/video_stitch/mining_hole/build /home/yushilin/workspace/myCode/imageStitch/video_stitch/mining_hole/build/src /home/yushilin/workspace/myCode/imageStitch/video_stitch/mining_hole/build/src/CMakeFiles/util.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/util.dir/depend


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
CMAKE_SOURCE_DIR = /home/gwen/Documents/courses/cmake/demo3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/gwen/Documents/courses/cmake/demo3/build

# Include any dependencies generated for this target.
include CMakeFiles/greet.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/greet.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/greet.dir/flags.make

CMakeFiles/greet.dir/src/greet.cpp.o: CMakeFiles/greet.dir/flags.make
CMakeFiles/greet.dir/src/greet.cpp.o: ../src/greet.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gwen/Documents/courses/cmake/demo3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/greet.dir/src/greet.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/greet.dir/src/greet.cpp.o -c /home/gwen/Documents/courses/cmake/demo3/src/greet.cpp

CMakeFiles/greet.dir/src/greet.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/greet.dir/src/greet.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gwen/Documents/courses/cmake/demo3/src/greet.cpp > CMakeFiles/greet.dir/src/greet.cpp.i

CMakeFiles/greet.dir/src/greet.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/greet.dir/src/greet.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gwen/Documents/courses/cmake/demo3/src/greet.cpp -o CMakeFiles/greet.dir/src/greet.cpp.s

# Object files for target greet
greet_OBJECTS = \
"CMakeFiles/greet.dir/src/greet.cpp.o"

# External object files for target greet
greet_EXTERNAL_OBJECTS =

libgreet.a: CMakeFiles/greet.dir/src/greet.cpp.o
libgreet.a: CMakeFiles/greet.dir/build.make
libgreet.a: CMakeFiles/greet.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/gwen/Documents/courses/cmake/demo3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libgreet.a"
	$(CMAKE_COMMAND) -P CMakeFiles/greet.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/greet.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/greet.dir/build: libgreet.a

.PHONY : CMakeFiles/greet.dir/build

CMakeFiles/greet.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/greet.dir/cmake_clean.cmake
.PHONY : CMakeFiles/greet.dir/clean

CMakeFiles/greet.dir/depend:
	cd /home/gwen/Documents/courses/cmake/demo3/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gwen/Documents/courses/cmake/demo3 /home/gwen/Documents/courses/cmake/demo3 /home/gwen/Documents/courses/cmake/demo3/build /home/gwen/Documents/courses/cmake/demo3/build /home/gwen/Documents/courses/cmake/demo3/build/CMakeFiles/greet.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/greet.dir/depend


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
CMAKE_COMMAND = "/Users/sunyuchuan/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/201.7846.88/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/sunyuchuan/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/201.7846.88/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/sunyuchuan/go/src/github.com/sonnary/apue

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/sunyuchuan/go/src/github.com/sonnary/apue/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/mainp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/mainp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mainp.dir/flags.make

CMakeFiles/mainp.dir/y/p5-fopen.c.o: CMakeFiles/mainp.dir/flags.make
CMakeFiles/mainp.dir/y/p5-fopen.c.o: ../y/p5-fopen.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sunyuchuan/go/src/github.com/sonnary/apue/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/mainp.dir/y/p5-fopen.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/mainp.dir/y/p5-fopen.c.o   -c /Users/sunyuchuan/go/src/github.com/sonnary/apue/y/p5-fopen.c

CMakeFiles/mainp.dir/y/p5-fopen.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mainp.dir/y/p5-fopen.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/sunyuchuan/go/src/github.com/sonnary/apue/y/p5-fopen.c > CMakeFiles/mainp.dir/y/p5-fopen.c.i

CMakeFiles/mainp.dir/y/p5-fopen.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mainp.dir/y/p5-fopen.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/sunyuchuan/go/src/github.com/sonnary/apue/y/p5-fopen.c -o CMakeFiles/mainp.dir/y/p5-fopen.c.s

# Object files for target mainp
mainp_OBJECTS = \
"CMakeFiles/mainp.dir/y/p5-fopen.c.o"

# External object files for target mainp
mainp_EXTERNAL_OBJECTS =

mainp: CMakeFiles/mainp.dir/y/p5-fopen.c.o
mainp: CMakeFiles/mainp.dir/build.make
mainp: CMakeFiles/mainp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/sunyuchuan/go/src/github.com/sonnary/apue/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable mainp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mainp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mainp.dir/build: mainp

.PHONY : CMakeFiles/mainp.dir/build

CMakeFiles/mainp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mainp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mainp.dir/clean

CMakeFiles/mainp.dir/depend:
	cd /Users/sunyuchuan/go/src/github.com/sonnary/apue/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/sunyuchuan/go/src/github.com/sonnary/apue /Users/sunyuchuan/go/src/github.com/sonnary/apue /Users/sunyuchuan/go/src/github.com/sonnary/apue/cmake-build-debug /Users/sunyuchuan/go/src/github.com/sonnary/apue/cmake-build-debug /Users/sunyuchuan/go/src/github.com/sonnary/apue/cmake-build-debug/CMakeFiles/mainp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mainp.dir/depend


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
include CMakeFiles/main154.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/main154.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main154.dir/flags.make

CMakeFiles/main154.dir/Chapter-01/1.5.4.c.o: CMakeFiles/main154.dir/flags.make
CMakeFiles/main154.dir/Chapter-01/1.5.4.c.o: ../Chapter-01/1.5.4.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sunyuchuan/go/src/github.com/sonnary/apue/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/main154.dir/Chapter-01/1.5.4.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/main154.dir/Chapter-01/1.5.4.c.o   -c /Users/sunyuchuan/go/src/github.com/sonnary/apue/Chapter-01/1.5.4.c

CMakeFiles/main154.dir/Chapter-01/1.5.4.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main154.dir/Chapter-01/1.5.4.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/sunyuchuan/go/src/github.com/sonnary/apue/Chapter-01/1.5.4.c > CMakeFiles/main154.dir/Chapter-01/1.5.4.c.i

CMakeFiles/main154.dir/Chapter-01/1.5.4.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main154.dir/Chapter-01/1.5.4.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/sunyuchuan/go/src/github.com/sonnary/apue/Chapter-01/1.5.4.c -o CMakeFiles/main154.dir/Chapter-01/1.5.4.c.s

# Object files for target main154
main154_OBJECTS = \
"CMakeFiles/main154.dir/Chapter-01/1.5.4.c.o"

# External object files for target main154
main154_EXTERNAL_OBJECTS =

main154: CMakeFiles/main154.dir/Chapter-01/1.5.4.c.o
main154: CMakeFiles/main154.dir/build.make
main154: CMakeFiles/main154.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/sunyuchuan/go/src/github.com/sonnary/apue/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable main154"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main154.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main154.dir/build: main154

.PHONY : CMakeFiles/main154.dir/build

CMakeFiles/main154.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main154.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main154.dir/clean

CMakeFiles/main154.dir/depend:
	cd /Users/sunyuchuan/go/src/github.com/sonnary/apue/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/sunyuchuan/go/src/github.com/sonnary/apue /Users/sunyuchuan/go/src/github.com/sonnary/apue /Users/sunyuchuan/go/src/github.com/sonnary/apue/cmake-build-debug /Users/sunyuchuan/go/src/github.com/sonnary/apue/cmake-build-debug /Users/sunyuchuan/go/src/github.com/sonnary/apue/cmake-build-debug/CMakeFiles/main154.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main154.dir/depend

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
include CMakeFiles/main162.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/main162.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main162.dir/flags.make

CMakeFiles/main162.dir/Chapter-01/1.6.2.c.o: CMakeFiles/main162.dir/flags.make
CMakeFiles/main162.dir/Chapter-01/1.6.2.c.o: ../Chapter-01/1.6.2.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sunyuchuan/go/src/github.com/sonnary/apue/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/main162.dir/Chapter-01/1.6.2.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/main162.dir/Chapter-01/1.6.2.c.o   -c /Users/sunyuchuan/go/src/github.com/sonnary/apue/Chapter-01/1.6.2.c

CMakeFiles/main162.dir/Chapter-01/1.6.2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main162.dir/Chapter-01/1.6.2.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/sunyuchuan/go/src/github.com/sonnary/apue/Chapter-01/1.6.2.c > CMakeFiles/main162.dir/Chapter-01/1.6.2.c.i

CMakeFiles/main162.dir/Chapter-01/1.6.2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main162.dir/Chapter-01/1.6.2.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/sunyuchuan/go/src/github.com/sonnary/apue/Chapter-01/1.6.2.c -o CMakeFiles/main162.dir/Chapter-01/1.6.2.c.s

# Object files for target main162
main162_OBJECTS = \
"CMakeFiles/main162.dir/Chapter-01/1.6.2.c.o"

# External object files for target main162
main162_EXTERNAL_OBJECTS =

main162: CMakeFiles/main162.dir/Chapter-01/1.6.2.c.o
main162: CMakeFiles/main162.dir/build.make
main162: CMakeFiles/main162.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/sunyuchuan/go/src/github.com/sonnary/apue/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable main162"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main162.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main162.dir/build: main162

.PHONY : CMakeFiles/main162.dir/build

CMakeFiles/main162.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main162.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main162.dir/clean

CMakeFiles/main162.dir/depend:
	cd /Users/sunyuchuan/go/src/github.com/sonnary/apue/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/sunyuchuan/go/src/github.com/sonnary/apue /Users/sunyuchuan/go/src/github.com/sonnary/apue /Users/sunyuchuan/go/src/github.com/sonnary/apue/cmake-build-debug /Users/sunyuchuan/go/src/github.com/sonnary/apue/cmake-build-debug /Users/sunyuchuan/go/src/github.com/sonnary/apue/cmake-build-debug/CMakeFiles/main162.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main162.dir/depend

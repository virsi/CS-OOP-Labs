# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.30.3/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.30.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/EV/Desktop/BMSTU/Программирование/Lab1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/EV/Desktop/BMSTU/Программирование/Lab1

# Include any dependencies generated for this target.
include CMakeFiles/lab1.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/lab1.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/lab1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab1.dir/flags.make

CMakeFiles/lab1.dir/main.cpp.o: CMakeFiles/lab1.dir/flags.make
CMakeFiles/lab1.dir/main.cpp.o: main.cpp
CMakeFiles/lab1.dir/main.cpp.o: CMakeFiles/lab1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/EV/Desktop/BMSTU/Программирование/Lab1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lab1.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab1.dir/main.cpp.o -MF CMakeFiles/lab1.dir/main.cpp.o.d -o CMakeFiles/lab1.dir/main.cpp.o -c /Users/EV/Desktop/BMSTU/Программирование/Lab1/main.cpp

CMakeFiles/lab1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/lab1.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/EV/Desktop/BMSTU/Программирование/Lab1/main.cpp > CMakeFiles/lab1.dir/main.cpp.i

CMakeFiles/lab1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/lab1.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/EV/Desktop/BMSTU/Программирование/Lab1/main.cpp -o CMakeFiles/lab1.dir/main.cpp.s

# Object files for target lab1
lab1_OBJECTS = \
"CMakeFiles/lab1.dir/main.cpp.o"

# External object files for target lab1
lab1_EXTERNAL_OBJECTS =

lab1: CMakeFiles/lab1.dir/main.cpp.o
lab1: CMakeFiles/lab1.dir/build.make
lab1: mymath/libmymath.a
lab1: myoutput/libmyoutput.a
lab1: CMakeFiles/lab1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/EV/Desktop/BMSTU/Программирование/Lab1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable lab1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab1.dir/build: lab1
.PHONY : CMakeFiles/lab1.dir/build

CMakeFiles/lab1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lab1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lab1.dir/clean

CMakeFiles/lab1.dir/depend:
	cd /Users/EV/Desktop/BMSTU/Программирование/Lab1 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/EV/Desktop/BMSTU/Программирование/Lab1 /Users/EV/Desktop/BMSTU/Программирование/Lab1 /Users/EV/Desktop/BMSTU/Программирование/Lab1 /Users/EV/Desktop/BMSTU/Программирование/Lab1 /Users/EV/Desktop/BMSTU/Программирование/Lab1/CMakeFiles/lab1.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/lab1.dir/depend


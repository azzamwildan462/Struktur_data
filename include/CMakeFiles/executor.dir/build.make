# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/wildan/proyek/Struktur_data

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wildan/proyek/Struktur_data

# Include any dependencies generated for this target.
include include/CMakeFiles/executor.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include include/CMakeFiles/executor.dir/compiler_depend.make

# Include the progress variables for this target.
include include/CMakeFiles/executor.dir/progress.make

# Include the compile flags for this target's objects.
include include/CMakeFiles/executor.dir/flags.make

include/CMakeFiles/executor.dir/__/src/executor.cpp.o: include/CMakeFiles/executor.dir/flags.make
include/CMakeFiles/executor.dir/__/src/executor.cpp.o: src/executor.cpp
include/CMakeFiles/executor.dir/__/src/executor.cpp.o: include/CMakeFiles/executor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wildan/proyek/Struktur_data/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object include/CMakeFiles/executor.dir/__/src/executor.cpp.o"
	cd /home/wildan/proyek/Struktur_data/include && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT include/CMakeFiles/executor.dir/__/src/executor.cpp.o -MF CMakeFiles/executor.dir/__/src/executor.cpp.o.d -o CMakeFiles/executor.dir/__/src/executor.cpp.o -c /home/wildan/proyek/Struktur_data/src/executor.cpp

include/CMakeFiles/executor.dir/__/src/executor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/executor.dir/__/src/executor.cpp.i"
	cd /home/wildan/proyek/Struktur_data/include && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wildan/proyek/Struktur_data/src/executor.cpp > CMakeFiles/executor.dir/__/src/executor.cpp.i

include/CMakeFiles/executor.dir/__/src/executor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/executor.dir/__/src/executor.cpp.s"
	cd /home/wildan/proyek/Struktur_data/include && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wildan/proyek/Struktur_data/src/executor.cpp -o CMakeFiles/executor.dir/__/src/executor.cpp.s

# Object files for target executor
executor_OBJECTS = \
"CMakeFiles/executor.dir/__/src/executor.cpp.o"

# External object files for target executor
executor_EXTERNAL_OBJECTS =

include/libexecutor.a: include/CMakeFiles/executor.dir/__/src/executor.cpp.o
include/libexecutor.a: include/CMakeFiles/executor.dir/build.make
include/libexecutor.a: include/CMakeFiles/executor.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wildan/proyek/Struktur_data/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libexecutor.a"
	cd /home/wildan/proyek/Struktur_data/include && $(CMAKE_COMMAND) -P CMakeFiles/executor.dir/cmake_clean_target.cmake
	cd /home/wildan/proyek/Struktur_data/include && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/executor.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
include/CMakeFiles/executor.dir/build: include/libexecutor.a
.PHONY : include/CMakeFiles/executor.dir/build

include/CMakeFiles/executor.dir/clean:
	cd /home/wildan/proyek/Struktur_data/include && $(CMAKE_COMMAND) -P CMakeFiles/executor.dir/cmake_clean.cmake
.PHONY : include/CMakeFiles/executor.dir/clean

include/CMakeFiles/executor.dir/depend:
	cd /home/wildan/proyek/Struktur_data && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wildan/proyek/Struktur_data /home/wildan/proyek/Struktur_data/include /home/wildan/proyek/Struktur_data /home/wildan/proyek/Struktur_data/include /home/wildan/proyek/Struktur_data/include/CMakeFiles/executor.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : include/CMakeFiles/executor.dir/depend


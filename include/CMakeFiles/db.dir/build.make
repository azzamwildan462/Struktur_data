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
include include/CMakeFiles/db.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include include/CMakeFiles/db.dir/compiler_depend.make

# Include the progress variables for this target.
include include/CMakeFiles/db.dir/progress.make

# Include the compile flags for this target's objects.
include include/CMakeFiles/db.dir/flags.make

include/CMakeFiles/db.dir/__/src/db.cpp.o: include/CMakeFiles/db.dir/flags.make
include/CMakeFiles/db.dir/__/src/db.cpp.o: src/db.cpp
include/CMakeFiles/db.dir/__/src/db.cpp.o: include/CMakeFiles/db.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wildan/proyek/Struktur_data/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object include/CMakeFiles/db.dir/__/src/db.cpp.o"
	cd /home/wildan/proyek/Struktur_data/include && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT include/CMakeFiles/db.dir/__/src/db.cpp.o -MF CMakeFiles/db.dir/__/src/db.cpp.o.d -o CMakeFiles/db.dir/__/src/db.cpp.o -c /home/wildan/proyek/Struktur_data/src/db.cpp

include/CMakeFiles/db.dir/__/src/db.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/db.dir/__/src/db.cpp.i"
	cd /home/wildan/proyek/Struktur_data/include && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wildan/proyek/Struktur_data/src/db.cpp > CMakeFiles/db.dir/__/src/db.cpp.i

include/CMakeFiles/db.dir/__/src/db.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/db.dir/__/src/db.cpp.s"
	cd /home/wildan/proyek/Struktur_data/include && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wildan/proyek/Struktur_data/src/db.cpp -o CMakeFiles/db.dir/__/src/db.cpp.s

# Object files for target db
db_OBJECTS = \
"CMakeFiles/db.dir/__/src/db.cpp.o"

# External object files for target db
db_EXTERNAL_OBJECTS =

include/libdb.a: include/CMakeFiles/db.dir/__/src/db.cpp.o
include/libdb.a: include/CMakeFiles/db.dir/build.make
include/libdb.a: include/CMakeFiles/db.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wildan/proyek/Struktur_data/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libdb.a"
	cd /home/wildan/proyek/Struktur_data/include && $(CMAKE_COMMAND) -P CMakeFiles/db.dir/cmake_clean_target.cmake
	cd /home/wildan/proyek/Struktur_data/include && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/db.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
include/CMakeFiles/db.dir/build: include/libdb.a
.PHONY : include/CMakeFiles/db.dir/build

include/CMakeFiles/db.dir/clean:
	cd /home/wildan/proyek/Struktur_data/include && $(CMAKE_COMMAND) -P CMakeFiles/db.dir/cmake_clean.cmake
.PHONY : include/CMakeFiles/db.dir/clean

include/CMakeFiles/db.dir/depend:
	cd /home/wildan/proyek/Struktur_data && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wildan/proyek/Struktur_data /home/wildan/proyek/Struktur_data/include /home/wildan/proyek/Struktur_data /home/wildan/proyek/Struktur_data/include /home/wildan/proyek/Struktur_data/include/CMakeFiles/db.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : include/CMakeFiles/db.dir/depend


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
include include/CMakeFiles/ui.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include include/CMakeFiles/ui.dir/compiler_depend.make

# Include the progress variables for this target.
include include/CMakeFiles/ui.dir/progress.make

# Include the compile flags for this target's objects.
include include/CMakeFiles/ui.dir/flags.make

include/CMakeFiles/ui.dir/__/src/ui.cpp.o: include/CMakeFiles/ui.dir/flags.make
include/CMakeFiles/ui.dir/__/src/ui.cpp.o: src/ui.cpp
include/CMakeFiles/ui.dir/__/src/ui.cpp.o: include/CMakeFiles/ui.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wildan/proyek/Struktur_data/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object include/CMakeFiles/ui.dir/__/src/ui.cpp.o"
	cd /home/wildan/proyek/Struktur_data/include && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT include/CMakeFiles/ui.dir/__/src/ui.cpp.o -MF CMakeFiles/ui.dir/__/src/ui.cpp.o.d -o CMakeFiles/ui.dir/__/src/ui.cpp.o -c /home/wildan/proyek/Struktur_data/src/ui.cpp

include/CMakeFiles/ui.dir/__/src/ui.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ui.dir/__/src/ui.cpp.i"
	cd /home/wildan/proyek/Struktur_data/include && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wildan/proyek/Struktur_data/src/ui.cpp > CMakeFiles/ui.dir/__/src/ui.cpp.i

include/CMakeFiles/ui.dir/__/src/ui.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ui.dir/__/src/ui.cpp.s"
	cd /home/wildan/proyek/Struktur_data/include && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wildan/proyek/Struktur_data/src/ui.cpp -o CMakeFiles/ui.dir/__/src/ui.cpp.s

# Object files for target ui
ui_OBJECTS = \
"CMakeFiles/ui.dir/__/src/ui.cpp.o"

# External object files for target ui
ui_EXTERNAL_OBJECTS =

include/libui.a: include/CMakeFiles/ui.dir/__/src/ui.cpp.o
include/libui.a: include/CMakeFiles/ui.dir/build.make
include/libui.a: include/CMakeFiles/ui.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wildan/proyek/Struktur_data/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libui.a"
	cd /home/wildan/proyek/Struktur_data/include && $(CMAKE_COMMAND) -P CMakeFiles/ui.dir/cmake_clean_target.cmake
	cd /home/wildan/proyek/Struktur_data/include && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ui.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
include/CMakeFiles/ui.dir/build: include/libui.a
.PHONY : include/CMakeFiles/ui.dir/build

include/CMakeFiles/ui.dir/clean:
	cd /home/wildan/proyek/Struktur_data/include && $(CMAKE_COMMAND) -P CMakeFiles/ui.dir/cmake_clean.cmake
.PHONY : include/CMakeFiles/ui.dir/clean

include/CMakeFiles/ui.dir/depend:
	cd /home/wildan/proyek/Struktur_data && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wildan/proyek/Struktur_data /home/wildan/proyek/Struktur_data/include /home/wildan/proyek/Struktur_data /home/wildan/proyek/Struktur_data/include /home/wildan/proyek/Struktur_data/include/CMakeFiles/ui.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : include/CMakeFiles/ui.dir/depend


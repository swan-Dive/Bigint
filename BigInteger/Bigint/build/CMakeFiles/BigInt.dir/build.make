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
CMAKE_SOURCE_DIR = /home/nikita/Документы/informatics/c_homework/Bigint

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nikita/Документы/informatics/c_homework/Bigint/build

# Include any dependencies generated for this target.
include CMakeFiles/BigInt.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/BigInt.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/BigInt.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BigInt.dir/flags.make

CMakeFiles/BigInt.dir/main.cpp.o: CMakeFiles/BigInt.dir/flags.make
CMakeFiles/BigInt.dir/main.cpp.o: ../main.cpp
CMakeFiles/BigInt.dir/main.cpp.o: CMakeFiles/BigInt.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nikita/Документы/informatics/c_homework/Bigint/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/BigInt.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/BigInt.dir/main.cpp.o -MF CMakeFiles/BigInt.dir/main.cpp.o.d -o CMakeFiles/BigInt.dir/main.cpp.o -c /home/nikita/Документы/informatics/c_homework/Bigint/main.cpp

CMakeFiles/BigInt.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BigInt.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nikita/Документы/informatics/c_homework/Bigint/main.cpp > CMakeFiles/BigInt.dir/main.cpp.i

CMakeFiles/BigInt.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BigInt.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nikita/Документы/informatics/c_homework/Bigint/main.cpp -o CMakeFiles/BigInt.dir/main.cpp.s

# Object files for target BigInt
BigInt_OBJECTS = \
"CMakeFiles/BigInt.dir/main.cpp.o"

# External object files for target BigInt
BigInt_EXTERNAL_OBJECTS =

BigInt: CMakeFiles/BigInt.dir/main.cpp.o
BigInt: CMakeFiles/BigInt.dir/build.make
BigInt: header_folder/libBigInteger.a
BigInt: CMakeFiles/BigInt.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nikita/Документы/informatics/c_homework/Bigint/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable BigInt"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/BigInt.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BigInt.dir/build: BigInt
.PHONY : CMakeFiles/BigInt.dir/build

CMakeFiles/BigInt.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/BigInt.dir/cmake_clean.cmake
.PHONY : CMakeFiles/BigInt.dir/clean

CMakeFiles/BigInt.dir/depend:
	cd /home/nikita/Документы/informatics/c_homework/Bigint/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nikita/Документы/informatics/c_homework/Bigint /home/nikita/Документы/informatics/c_homework/Bigint /home/nikita/Документы/informatics/c_homework/Bigint/build /home/nikita/Документы/informatics/c_homework/Bigint/build /home/nikita/Документы/informatics/c_homework/Bigint/build/CMakeFiles/BigInt.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BigInt.dir/depend


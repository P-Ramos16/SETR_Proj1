# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = /home/rafa/Secretária/SETR/SETR_Proj1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rafa/Secretária/SETR/SETR_Proj1/build

# Include any dependencies generated for this target.
include CMakeFiles/mydll.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/mydll.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/mydll.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mydll.dir/flags.make

CMakeFiles/mydll.dir/src/main.c.o: CMakeFiles/mydll.dir/flags.make
CMakeFiles/mydll.dir/src/main.c.o: /home/rafa/Secretária/SETR/SETR_Proj1/src/main.c
CMakeFiles/mydll.dir/src/main.c.o: CMakeFiles/mydll.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/rafa/Secretária/SETR/SETR_Proj1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/mydll.dir/src/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/mydll.dir/src/main.c.o -MF CMakeFiles/mydll.dir/src/main.c.o.d -o CMakeFiles/mydll.dir/src/main.c.o -c /home/rafa/Secretária/SETR/SETR_Proj1/src/main.c

CMakeFiles/mydll.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/mydll.dir/src/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/rafa/Secretária/SETR/SETR_Proj1/src/main.c > CMakeFiles/mydll.dir/src/main.c.i

CMakeFiles/mydll.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/mydll.dir/src/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/rafa/Secretária/SETR/SETR_Proj1/src/main.c -o CMakeFiles/mydll.dir/src/main.c.s

CMakeFiles/mydll.dir/src/module/MyDLL.c.o: CMakeFiles/mydll.dir/flags.make
CMakeFiles/mydll.dir/src/module/MyDLL.c.o: /home/rafa/Secretária/SETR/SETR_Proj1/src/module/MyDLL.c
CMakeFiles/mydll.dir/src/module/MyDLL.c.o: CMakeFiles/mydll.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/rafa/Secretária/SETR/SETR_Proj1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/mydll.dir/src/module/MyDLL.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/mydll.dir/src/module/MyDLL.c.o -MF CMakeFiles/mydll.dir/src/module/MyDLL.c.o.d -o CMakeFiles/mydll.dir/src/module/MyDLL.c.o -c /home/rafa/Secretária/SETR/SETR_Proj1/src/module/MyDLL.c

CMakeFiles/mydll.dir/src/module/MyDLL.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/mydll.dir/src/module/MyDLL.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/rafa/Secretária/SETR/SETR_Proj1/src/module/MyDLL.c > CMakeFiles/mydll.dir/src/module/MyDLL.c.i

CMakeFiles/mydll.dir/src/module/MyDLL.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/mydll.dir/src/module/MyDLL.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/rafa/Secretária/SETR/SETR_Proj1/src/module/MyDLL.c -o CMakeFiles/mydll.dir/src/module/MyDLL.c.s

# Object files for target mydll
mydll_OBJECTS = \
"CMakeFiles/mydll.dir/src/main.c.o" \
"CMakeFiles/mydll.dir/src/module/MyDLL.c.o"

# External object files for target mydll
mydll_EXTERNAL_OBJECTS =

mydll: CMakeFiles/mydll.dir/src/main.c.o
mydll: CMakeFiles/mydll.dir/src/module/MyDLL.c.o
mydll: CMakeFiles/mydll.dir/build.make
mydll: CMakeFiles/mydll.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/rafa/Secretária/SETR/SETR_Proj1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable mydll"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mydll.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mydll.dir/build: mydll
.PHONY : CMakeFiles/mydll.dir/build

CMakeFiles/mydll.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mydll.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mydll.dir/clean

CMakeFiles/mydll.dir/depend:
	cd /home/rafa/Secretária/SETR/SETR_Proj1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rafa/Secretária/SETR/SETR_Proj1 /home/rafa/Secretária/SETR/SETR_Proj1 /home/rafa/Secretária/SETR/SETR_Proj1/build /home/rafa/Secretária/SETR/SETR_Proj1/build /home/rafa/Secretária/SETR/SETR_Proj1/build/CMakeFiles/mydll.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/mydll.dir/depend


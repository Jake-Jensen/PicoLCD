# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.19

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


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

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = G:\PicoTools\S_PicoKit\S_PicoKit

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = G:\PicoTools\S_PicoKit\S_PicoKit\build

# Utility rule file for bs2_default_bin.

# Include the progress variables for this target.
include pico-sdk\src\rp2_common\boot_stage2\CMakeFiles\bs2_default_bin.dir\progress.make

pico-sdk\src\rp2_common\boot_stage2\CMakeFiles\bs2_default_bin: pico-sdk\src\rp2_common\boot_stage2\bs2_default.bin
	cd G:\PicoTools\S_PicoKit\S_PicoKit\build\pico-sdk\src\rp2_common\boot_stage2
	cd G:\PicoTools\S_PicoKit\S_PicoKit\build

pico-sdk\src\rp2_common\boot_stage2\bs2_default.bin: pico-sdk\src\rp2_common\boot_stage2\bs2_default.elf
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=G:\PicoTools\S_PicoKit\S_PicoKit\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating bs2_default.bin"
	cd G:\PicoTools\S_PicoKit\S_PicoKit\build\pico-sdk\src\rp2_common\boot_stage2
	echo >nul && "C:\Program Files (x86)\GNU Arm Embedded Toolchain\10 2020-q4-major\bin\arm-none-eabi-objcopy.exe" -Obinary G:/PicoTools/S_PicoKit/S_PicoKit/build/pico-sdk/src/rp2_common/boot_stage2/bs2_default.elf G:/PicoTools/S_PicoKit/S_PicoKit/build/pico-sdk/src/rp2_common/boot_stage2/bs2_default.bin
	cd G:\PicoTools\S_PicoKit\S_PicoKit\build

bs2_default_bin: pico-sdk\src\rp2_common\boot_stage2\CMakeFiles\bs2_default_bin
bs2_default_bin: pico-sdk\src\rp2_common\boot_stage2\bs2_default.bin
bs2_default_bin: pico-sdk\src\rp2_common\boot_stage2\CMakeFiles\bs2_default_bin.dir\build.make

.PHONY : bs2_default_bin

# Rule to build all files generated by this target.
pico-sdk\src\rp2_common\boot_stage2\CMakeFiles\bs2_default_bin.dir\build: bs2_default_bin

.PHONY : pico-sdk\src\rp2_common\boot_stage2\CMakeFiles\bs2_default_bin.dir\build

pico-sdk\src\rp2_common\boot_stage2\CMakeFiles\bs2_default_bin.dir\clean:
	cd G:\PicoTools\S_PicoKit\S_PicoKit\build\pico-sdk\src\rp2_common\boot_stage2
	$(CMAKE_COMMAND) -P CMakeFiles\bs2_default_bin.dir\cmake_clean.cmake
	cd G:\PicoTools\S_PicoKit\S_PicoKit\build
.PHONY : pico-sdk\src\rp2_common\boot_stage2\CMakeFiles\bs2_default_bin.dir\clean

pico-sdk\src\rp2_common\boot_stage2\CMakeFiles\bs2_default_bin.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" G:\PicoTools\S_PicoKit\S_PicoKit G:\PicoTools\Pico\pico-sdk\src\rp2_common\boot_stage2 G:\PicoTools\S_PicoKit\S_PicoKit\build G:\PicoTools\S_PicoKit\S_PicoKit\build\pico-sdk\src\rp2_common\boot_stage2 G:\PicoTools\S_PicoKit\S_PicoKit\build\pico-sdk\src\rp2_common\boot_stage2\CMakeFiles\bs2_default_bin.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : pico-sdk\src\rp2_common\boot_stage2\CMakeFiles\bs2_default_bin.dir\depend


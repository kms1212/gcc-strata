/* Configuration common to all targets running foliOS.
   Copyright (C) 2000-2025 Free Software Foundation, Inc.

   This file is part of GCC.

   GCC is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published
   by the Free Software Foundation; either version 3, or (at your
   option) any later version.

   GCC is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
   License for more details.

   Under Section 7 of GPL version 3, you are granted additional
   permissions described in the GCC Runtime Library Exception, version
   3.1, as published by the Free Software Foundation.

   You should have received a copy of the GNU General Public License and
   a copy of the GCC Runtime Library Exception along with this program;
   see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
   <http://www.gnu.org/licenses/>.  */

#define STRATA_CPP_BUILTINS() \
  do { \
    builtin_define("__folios__"); \
    builtin_define("__FOLIOS__"); \
    builtin_assert("system=folios"); \
  } while (0)

#define STRATA_DYNAMIC_LINKER "/System/Processes/Current/RuntimeLinker.app"
#define STRATA_EXTRA_ASM_SPEC "--noexecstack"
#define STRATA_EXTRA_LINK_SPEC "-m elf_x86_64_folios %{!r:--gc-sections} -z noexecstack"
#define STRATA_EXTRA_CC1_SPEC "%{!fno-function-sections:-ffunction-sections} %{!fno-data-sections:-fdata-sections}"

#undef TARGET_ASM_FILE_END
#define TARGET_ASM_FILE_END file_end_indicate_exec_stack

#undef TARGET_EXECUTABLE_SUFFIX
#define TARGET_EXECUTABLE_SUFFIX ".app"

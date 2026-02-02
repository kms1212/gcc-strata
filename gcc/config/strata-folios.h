/* Configuration common to all targets running Strata.
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

#undef TARGET_STRATA
#define TARGET_STRATA 1

#undef TARGET_OS_CPP_BUILTINS
#define TARGET_OS_CPP_BUILTINS() \
  do { \
    builtin_define("__strata__"); \
    builtin_define("__STRATA__"); \
    builtin_assert("system=strata"); \
    \
    builtin_define("__folios__"); \
    builtin_define("__FOLIOS__"); \
    builtin_assert("system=folios"); \
    \
    builtin_define("__unix__"); \
    builtin_define("__unix"); \
    builtin_assert("system=unix"); \
    builtin_assert("system=posix"); \
    \
    builtin_define("__ELF__"); \
    \
    builtin_define("_REENTRANT"); \
  } while (0);

#undef STARTFILE_SPEC
#define STARTFILE_SPEC "%{!shared:crt0%O%s} crti%O%s crtbegin%O%s"

#undef ENDFILE_SPEC
#define ENDFILE_SPEC "crtend%O%s crtn%O%s"

#undef CC1_SPEC
#define CC1_SPEC  \
    "%{!fno-pic:%{!fno-PIC:%{!fpic:%{!fPIC:" \
        "%{!fno-pie:%{!fno-PIE:%{!fpie:%{!fPIE: -fPIE}}}}" \
    "}}}}"

#undef LIB_SPEC
#define LIB_SPEC "-lc"

#undef LINK_SPEC
#define LINK_SPEC \
    "%{shared:-shared} %{static:-static}" \
    "%{!shared: %{!static: %{rdynamic:-export-dynamic}}}" \
    "%{!shared:%{!static:%{!dynamic-linker:-dynamic-linker=" \
        "/Packages/folisdk/Current/lib/ld-musl-x86_64.so.1" \
    "}}}"

#undef GTHREAD_USE_WEAK
#define GTHREAD_USE_WEAK 0

# =============================================================================
# Copyright (C) 2016-2019 Blue Brain Project
#
# See top-level LICENSE file for details.
# =============================================================================

# Findnmodl
# -------------
#
# Find nmodl
#
# Find the nmodl Blue Brain HPC utils library
#
# Using nmodl:
#
# ::
#   set(CORENRN_NMODL_ROOT "" CACHE PATH "Path nmodl source-to-source compiler root")
#   find_package(nmodl REQUIRED)
#   include_directories(${nmodl_INCLUDE_DIRS})
#   target_link_libraries(foo ${nmodl_LIBRARIES})
#
# This module sets the following variables:
#
# ::
#
#   nmodl_FOUND   - set to true if the library is found
#   nmodl_INCLUDE - list of required include directories
#   nmodl_BINARY  - the nmodl binary


# UNIX paths are standard, no need to write.
find_program(nmodl_BINARY NAMES nmodl
        HINTS "${CORENRN_NMODL_ROOT}/bin" QUIET)

find_path(nmodl_INCLUDE "nmodl/fast_math.ispc" HINTS "${CORENRN_NMODL_ROOT}/include")
find_path(nmodl_PYTHONPATH "nmodl/__init__.py" HINTS "${CORENRN_NMODL_ROOT}/lib/python")

# Checks 'REQUIRED', 'QUIET' and versions.
include(FindPackageHandleStandardArgs)

find_package_handle_standard_args(nmodl
  FOUND_VAR nmodl_FOUND
  REQUIRED_VARS nmodl_BINARY nmodl_INCLUDE nmodl_PYTHONPATH)
  

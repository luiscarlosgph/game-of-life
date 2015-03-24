#/*============================================================================
#
#  research-computing-with-cpp-demo: CMake based demo code. 
#
#  Copyright (c) University College London (UCL). All rights reserved.
#
#  This software is distributed WITHOUT ANY WARRANTY; without even
#  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
#  PURPOSE.
#
#  See LICENSE.txt in the top level directory for details.
#
#============================================================================*/

# Sanity checks
if(DEFINED Eigen_DIR AND NOT EXISTS ${Eigen_DIR})
  message(FATAL_ERROR "Eigen_DIR variable is defined but corresponds to non-existing directory \"${Eigen_ROOT}\".")
endif()

set(version "3.2.2.1")
set(location "${PROJECT_SOURCE_DIR}/libs/eigen/cmake/src/eigen-eigen-${version}.tar.bz2")

if(NOT DEFINED Eigen_DIR)
  set(Eigen_DIR ${PROJECT_SOURCE_DIR}/libs/eigen/src)
  set(Eigen_ROOT ${Eigen_DIR})
  set(Eigen_INCLUDE_DIR ${Eigen_DIR})
else(NOT DEFINED Eigen_DIR)
  message(FATAL_ERROR "Eigen could not be loaded.")
endif(NOT DEFINED Eigen_DIR)

# Install script for directory: /Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/src/Eigen2Support/Geometry

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/src/Eigen2Support/Geometry/AlignedBox.h;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/src/Eigen2Support/Geometry/All.h;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/src/Eigen2Support/Geometry/AngleAxis.h;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/src/Eigen2Support/Geometry/Hyperplane.h;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/src/Eigen2Support/Geometry/ParametrizedLine.h;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/src/Eigen2Support/Geometry/Quaternion.h;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/src/Eigen2Support/Geometry/Rotation2D.h;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/src/Eigen2Support/Geometry/RotationBase.h;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/src/Eigen2Support/Geometry/Scaling.h;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/src/Eigen2Support/Geometry/Transform.h;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/src/Eigen2Support/Geometry/Translation.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/src/Eigen2Support/Geometry" TYPE FILE FILES
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/src/Eigen2Support/Geometry/AlignedBox.h"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/src/Eigen2Support/Geometry/All.h"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/src/Eigen2Support/Geometry/AngleAxis.h"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/src/Eigen2Support/Geometry/Hyperplane.h"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/src/Eigen2Support/Geometry/ParametrizedLine.h"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/src/Eigen2Support/Geometry/Quaternion.h"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/src/Eigen2Support/Geometry/Rotation2D.h"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/src/Eigen2Support/Geometry/RotationBase.h"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/src/Eigen2Support/Geometry/Scaling.h"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/src/Eigen2Support/Geometry/Transform.h"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/src/Eigen2Support/Geometry/Translation.h"
    )
endif()


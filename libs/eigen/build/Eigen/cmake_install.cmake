# Install script for directory: /Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen

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

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Devel")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/Array;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/Cholesky;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/CholmodSupport;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/Core;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/Dense;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/Eigen;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/Eigen2Support;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/Eigenvalues;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/Geometry;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/Householder;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/IterativeLinearSolvers;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/Jacobi;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/LeastSquares;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/LU;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/MetisSupport;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/OrderingMethods;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/PardisoSupport;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/PaStiXSupport;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/QR;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/QtAlignedMalloc;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/Sparse;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/SparseCholesky;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/SparseCore;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/SparseLU;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/SparseQR;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/SPQRSupport;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/StdDeque;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/StdList;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/StdVector;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/SuperLUSupport;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/SVD;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/UmfPackSupport")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen" TYPE FILE FILES
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/Array"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/Cholesky"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/CholmodSupport"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/Core"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/Dense"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/Eigen"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/Eigen2Support"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/Eigenvalues"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/Geometry"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/Householder"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/IterativeLinearSolvers"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/Jacobi"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/LeastSquares"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/LU"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/MetisSupport"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/OrderingMethods"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/PardisoSupport"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/PaStiXSupport"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/QR"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/QtAlignedMalloc"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/Sparse"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/SparseCholesky"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/SparseCore"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/SparseLU"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/SparseQR"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/SPQRSupport"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/StdDeque"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/StdList"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/StdVector"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/SuperLUSupport"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/SVD"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/UmfPackSupport"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/build/Eigen/src/cmake_install.cmake")

endif()


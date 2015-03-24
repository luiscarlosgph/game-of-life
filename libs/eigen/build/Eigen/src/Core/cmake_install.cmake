# Install script for directory: /Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/src/Core

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
   "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/src/Core/Array.h;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/src/Core/ArrayBase.h;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/src/Core/ArrayWrapper.h;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/src/Core/Assign.h;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/src/Core/Assign_MKL.h;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/src/Core/BandMatrix.h;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/src/Core/Block.h;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/src/Core/BooleanRedux.h;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/src/Core/CommaInitializer.h;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/src/Core/CoreIterators.h;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/src/Core/CwiseBinaryOp.h;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/src/Core/CwiseNullaryOp.h;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/src/Core/CwiseUnaryOp.h;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/src/Core/CwiseUnaryView.h;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/src/Core/DenseBase.h;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/src/Core/DenseCoeffsBase.h;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/src/Core/DenseStorage.h;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/src/Core/Diagonal.h;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/src/Core/DiagonalMatrix.h;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/src/Core/DiagonalProduct.h;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/src/Core/Dot.h;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/src/Core/EigenBase.h;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/src/Core/Flagged.h;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/src/Core/ForceAlignedAccess.h;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/src/Core/Functors.h;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/src/Core/Fuzzy.h;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/src/Core/GeneralProduct.h;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/src/Core/GenericPacketMath.h;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/src/Core/GlobalFunctions.h;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/src/Core/IO.h;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/src/Core/Map.h;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/src/Core/MapBase.h;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/src/Core/MathFunctions.h;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/src/Core/Matrix.h;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/src/Core/MatrixBase.h;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/src/Core/NestByValue.h;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/src/Core/NoAlias.h;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/src/Core/NumTraits.h;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/src/Core/PermutationMatrix.h;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/src/Core/PlainObjectBase.h;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/src/Core/ProductBase.h;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/src/Core/Random.h;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/src/Core/Redux.h;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/src/Core/Ref.h;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/src/Core/Replicate.h;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/src/Core/ReturnByValue.h;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/src/Core/Reverse.h;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/src/Core/Select.h;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/src/Core/SelfAdjointView.h;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/src/Core/SelfCwiseBinaryOp.h;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/src/Core/SolveTriangular.h;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/src/Core/StableNorm.h;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/src/Core/Stride.h;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/src/Core/Swap.h;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/src/Core/Transpose.h;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/src/Core/Transpositions.h;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/src/Core/TriangularMatrix.h;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/src/Core/VectorBlock.h;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/src/Core/VectorwiseOp.h;/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/src/Core/Visitor.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/install/include/eigen3/Eigen/src/Core" TYPE FILE FILES
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/src/Core/Array.h"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/src/Core/ArrayBase.h"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/src/Core/ArrayWrapper.h"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/src/Core/Assign.h"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/src/Core/Assign_MKL.h"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/src/Core/BandMatrix.h"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/src/Core/Block.h"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/src/Core/BooleanRedux.h"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/src/Core/CommaInitializer.h"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/src/Core/CoreIterators.h"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/src/Core/CwiseBinaryOp.h"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/src/Core/CwiseNullaryOp.h"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/src/Core/CwiseUnaryOp.h"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/src/Core/CwiseUnaryView.h"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/src/Core/DenseBase.h"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/src/Core/DenseCoeffsBase.h"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/src/Core/DenseStorage.h"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/src/Core/Diagonal.h"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/src/Core/DiagonalMatrix.h"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/src/Core/DiagonalProduct.h"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/src/Core/Dot.h"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/src/Core/EigenBase.h"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/src/Core/Flagged.h"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/src/Core/ForceAlignedAccess.h"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/src/Core/Functors.h"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/src/Core/Fuzzy.h"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/src/Core/GeneralProduct.h"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/src/Core/GenericPacketMath.h"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/src/Core/GlobalFunctions.h"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/src/Core/IO.h"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/src/Core/Map.h"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/src/Core/MapBase.h"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/src/Core/MathFunctions.h"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/src/Core/Matrix.h"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/src/Core/MatrixBase.h"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/src/Core/NestByValue.h"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/src/Core/NoAlias.h"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/src/Core/NumTraits.h"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/src/Core/PermutationMatrix.h"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/src/Core/PlainObjectBase.h"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/src/Core/ProductBase.h"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/src/Core/Random.h"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/src/Core/Redux.h"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/src/Core/Ref.h"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/src/Core/Replicate.h"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/src/Core/ReturnByValue.h"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/src/Core/Reverse.h"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/src/Core/Select.h"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/src/Core/SelfAdjointView.h"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/src/Core/SelfCwiseBinaryOp.h"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/src/Core/SolveTriangular.h"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/src/Core/StableNorm.h"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/src/Core/Stride.h"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/src/Core/Swap.h"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/src/Core/Transpose.h"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/src/Core/Transpositions.h"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/src/Core/TriangularMatrix.h"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/src/Core/VectorBlock.h"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/src/Core/VectorwiseOp.h"
    "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/src/Eigen/src/Core/Visitor.h"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/build/Eigen/src/Core/products/cmake_install.cmake")
  include("/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/build/Eigen/src/Core/util/cmake_install.cmake")
  include("/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/build/Eigen/src/Core/arch/cmake_install.cmake")

endif()


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

add_executable(GameOfLife main.cpp gameoflife.cpp board.cpp cell.cpp commandlinereader.cpp)
target_link_libraries(GameOfLife ${Eigen_LIBRARIES} ${Boost_LIBRARIES})

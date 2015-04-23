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

add_executable(GameOfLifeTest test.cpp ${PROJECT_SOURCE_DIR}/src/gameoflife.cpp ${PROJECT_SOURCE_DIR}/src/board.cpp ${PROJECT_SOURCE_DIR}/src/cell.cpp)
target_link_libraries(GameOfLifeTest ${Eigen_LIBRARIES} ${Boost_LIBRARIES})

set(file "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/cmake/src/eigen-eigen-3.2.2.1.tar.bz2")
message(STATUS "verifying file...
     file='${file}'")
set(expect_value "7eb340dd70daa019fcb5dc179f795600")
set(attempt 0)
set(succeeded 0)
while(${attempt} LESS 3 OR ${attempt} EQUAL 3 AND NOT ${succeeded})
  file(MD5 "${file}" actual_value)
  if("${actual_value}" STREQUAL "${expect_value}")
    set(succeeded 1)
  elseif(${attempt} LESS 3)
    message(STATUS "MD5 hash of ${file}
does not match expected value
  expected: ${expect_value}
    actual: ${actual_value}
Retrying download.
")
    file(REMOVE "${file}")
    execute_process(COMMAND ${CMAKE_COMMAND} -P "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/cmake/src/Eigen-stamp/download-Eigen.cmake")
  endif()
  math(EXPR attempt "${attempt} + 1")
endwhile()

if(${succeeded})
  message(STATUS "verifying file... done")
else()
  message(FATAL_ERROR "error: MD5 hash of
  ${file}
does not match expected value
  expected: ${expect_value}
    actual: ${actual_value}
")
endif()

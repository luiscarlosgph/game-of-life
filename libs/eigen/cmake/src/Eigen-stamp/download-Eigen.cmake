message(STATUS "downloading...
     src='http://cmic.cs.ucl.ac.uk/platform/dependencies/eigen-eigen-3.2.2.1.tar.bz2'
     dst='/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/cmake/src/eigen-eigen-3.2.2.1.tar.bz2'
     timeout='none'")




file(DOWNLOAD
  "http://cmic.cs.ucl.ac.uk/platform/dependencies/eigen-eigen-3.2.2.1.tar.bz2"
  "/Volumes/DATA/coursework1/research-computing-with-cpp-demo-build/Eigen/ab1a5/cmake/src/eigen-eigen-3.2.2.1.tar.bz2"
  SHOW_PROGRESS
  EXPECTED_HASH;MD5=7eb340dd70daa019fcb5dc179f795600
  # no TIMEOUT
  STATUS status
  LOG log)

list(GET status 0 status_code)
list(GET status 1 status_string)

if(NOT status_code EQUAL 0)
  message(FATAL_ERROR "error: downloading 'http://cmic.cs.ucl.ac.uk/platform/dependencies/eigen-eigen-3.2.2.1.tar.bz2' failed
  status_code: ${status_code}
  status_string: ${status_string}
  log: ${log}
")
endif()

message(STATUS "downloading... done")

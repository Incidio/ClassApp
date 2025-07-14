# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "3rdparty\\duckx\\CMakeFiles\\duckx_autogen.dir\\AutogenUsed.txt"
  "3rdparty\\duckx\\CMakeFiles\\duckx_autogen.dir\\ParseCache.txt"
  "3rdparty\\duckx\\duckx_autogen"
  "CMakeFiles\\ClassApp_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\ClassApp_autogen.dir\\ParseCache.txt"
  "ClassApp_autogen"
  )
endif()

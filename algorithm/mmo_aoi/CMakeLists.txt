CMAKE_MINIMUM_REQUIRED( VERSION 3.16 )

PROJECT( MMO_Aoi CXX )

ADD_COMPILE_OPTIONS ( -std=c++17 )

SET ( PROJECT_VERSION_MAJOR 1 )
SET ( PROJECT_VERSION_MINOR 0 )

SET ( CMAKE_CXX_FLAGS "-g -Wunused-result" )

SET ( INCLUDE_ROOT "src" )
SET ( SRC_ROOT "src" )

INCLUDE_DIRECTORIES( ${INCLUDE_ROOT} )

function(SEARCH_FILE RETURN_VAR ROOT_DIR)
  set(SEARCH_RESULT "")

  foreach(SUFFIX ${ARGN})
    file(
      GLOB_RECURSE RESULT
      LIST_DIRECTORIES false
      ${ROOT_DIR}/*.${SUFFIX}
    )
    list(APPEND SEARCH_RESULT ${RESULT})
  endforeach()

  set(${RETURN_VAR} ${SEARCH_RESULT} PARENT_SCOPE)
endfunction()

#search source file
SEARCH_FILE( SRC_FILES ${SRC_ROOT} cpp cc cxx c )
#search source file
SEARCH_FILE( HEAD_FILES ${INCLUDE_ROOT} hpp h )

message( "Head file : ${HEAD_FILES}" )
message( "Src file : ${SRC_FILES}" )

ADD_EXECUTABLE(Demo.out ${SRC_FILES})

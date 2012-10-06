
project("broadway" C)

cmake_minimum_required(VERSION 2.8)

SET( WISPER_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/../../include )

find_library( LIB_MICROHTTPD microhttpd )
find_library( LIB_PTHREAD pthread )

ADD_SUBDIRECTORY(src)

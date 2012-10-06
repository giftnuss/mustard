
include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${WISPER_INCLUDE_DIR}    
)

add_executable(
    ../broadway
    main.c
)

target_link_libraries(
    ../broadway   
    ${LIB_MICROHTTPD}
    ${LIB_PTHREAD}
)

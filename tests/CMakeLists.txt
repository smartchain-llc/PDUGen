configure_file(
    framework/PDUGenTest.h
    ${CMAKE_BINARY_DIR}/framework/PDUGenTest.h
)

# file(GLOB test_dirs ./pdus DIRECTORIES TRUE)

# message("[PDUGEN] -- ${dir}")
# foreach(dir ${test_dirs})
#     add_subdirectory(${dir})
# endforeach()
add_subdirectory(pdus)
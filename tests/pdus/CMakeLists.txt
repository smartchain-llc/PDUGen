add_executable(
    TEST_Header
    Header/HeaderTests.cxx
)
target_link_libraries(
    TEST_Header
    pdugen
)
message("[PDUGEN] -- Test Utils Include: ${pdg_test_h}")
target_include_directories(TEST_Header PUBLIC ${CMAKE_BINARY_DIR}/framework)
add_test(NAME HeaderTests COMMAND TEST_Header)
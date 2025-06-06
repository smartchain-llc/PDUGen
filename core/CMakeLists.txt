
file(GLOB_RECURSE pdu_srcs ./pdus/*.cxx)

add_library(
    pdugen
    SHARED ${pdu_srcs}
)
target_include_directories(
    pdugen
    INTERFACE ./pdus/
)
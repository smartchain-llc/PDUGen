find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)

set(RESC_DIR ${CMAKE_CURRENT_BINARY_DIR})
configure_file(resources/resources.h.in resources.h)
configure_file(resources/main/pdugen-glade.glade pdugen-glade.glade)
add_executable(
    pdugenUI
    main.cxx
)
message("COMMON INC DIR: ${COMMON_INC_DIR}")
target_include_directories(
    pdugenUI
    PRIVATE ${GTKMM_INCLUDE_DIRS}
    PRIVATE ${CMAKE_CURRENT_BINARY_DIR}
    PUBLIC ${COMMON_INC_DIR}
)
target_link_libraries(
    pdugenUI 
      pthread
      pdugen
      ${GTKMM_LIBRARIES}
)
target_compile_options(
    pdugenUI
    PRIVATE ${GTKMM_CFLAGS_OTHER}
)
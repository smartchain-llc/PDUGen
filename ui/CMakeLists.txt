find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED gtkmm-4.0)

add_executable(
    pdugenUI
    main.cxx
)
target_include_directories(
    pdugenUI
    PRIVATE ${GTKMM_INCLUDE_DIRS}
)
target_link_libraries(
    pdugenUI 
      pthread
      ${GTKMM_LIBRARIES}
)
target_compile_options(
    pdugenUI
    PRIVATE ${GTKMM_CFLAGS_OTHER}
)
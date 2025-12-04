file(GLOB SRC_FILES CONFIGURE_DEPENDS "*.cpp")
add_executable(25_5_2 ${SRC_FILES})
target_include_directories(25_5_2 PUBLIC ${PROJECT_SOURCE_DIR}/include)
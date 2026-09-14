add_executable(randomx-dataset_tests test_core.cpp)
target_link_libraries(randomx-dataset_tests PRIVATE work)
target_include_directories(randomx-dataset_tests PRIVATE ${CMAKE_SOURCE_DIR}/include)
add_test(NAME core COMMAND randomx-dataset_tests)

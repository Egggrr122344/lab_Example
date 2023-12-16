cmake_minimum_required(VERSION 3.10)
project(LAB6)
set(CMAKE_CXX_STANDARD 20)

# Подключение Google Test
add_subdirectory(lib/googletest)

# Определение директорий с исходными файлами и заголовочными файлами
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/lab0)

# Собираем список всех исходных файлов и заголовочных файлов
file(GLOB SOURCES ${SOURCE_DIR}/*.cpp)
file(GLOB HEADERS ${INCLUDE_DIR}/*.hpp)

# Создание основного исполняемого файла из main.cpp
add_executable(${PROJECT_NAME} main.cpp ${SOURCES} ${HEADERS})
target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE_DIR} ${gtest_SOURCE_DIR}/include)

# Включение тестирования
enable_testing()

# Создание тестовых исполняемых файлов для каждого теста
set(TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/test)

# Factory Test
add_executable(test_factory ${TEST_DIR}/test_factory.cpp ${HEADERS} ${SOURCES})
target_link_libraries(test_factory gtest gtest_main)

# Knight Test
add_executable(test_knight ${TEST_DIR}/test_knight.cpp ${HEADERS} ${SOURCES})
target_link_libraries(test_knight gtest gtest_main)

# Squirrel Test
add_executable(test_squirrel ${TEST_DIR}/test_squirrel.cpp ${HEADERS} ${SOURCES})
target_link_libraries(test_squirrel gtest gtest_main)

# Merchant Test
add_executable(test_merchant ${TEST_DIR}/test_merchant.cpp ${HEADERS} ${SOURCES})
target_link_libraries(test_merchant gtest gtest_main)

add_executable(test_fight ${TEST_DIR}/test_fight.cpp ${HEADERS} ${SOURCES})
target_link_libraries(test_fight gtest gtest_main)
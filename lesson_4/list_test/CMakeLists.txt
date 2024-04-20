#минимальная версия cmake
cmake_minimum_required(VERSION 3.10)
#имя проекта
project(testList)
find_package(Catch2 CONFIG REQUIRED)
#добавляем цель - приложение, у которого исходник с единственным приложением
add_executable(${PROJECT_NAME} list_test.cpp)
#линкуемся к catch2, в котором уже есть main
target_link_libraries(${PROJECT_NAME} PRIVATE Catch2::Catch2 Catch2::Catch2WithMain)
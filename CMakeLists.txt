cmake_minimum_required(VERSION 3.10)

project(MyProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(USE_ADDRESS_SANITIZER "Enable AddressSanitizer" OFF)
option(USE_THREAD_SANITIZER "Enable ThreadSanitizer" OFF)

if(USE_ADDRESS_SANITIZER AND USE_THREAD_SANITIZER)
    message(FATAL_ERROR "AddressSanitizer and ThreadSanitizer cannot be used together.")
elseif(USE_ADDRESS_SANITIZER)
    set(SANITIZER_FLAGS "-fsanitize=address")
elseif(USE_THREAD_SANITIZER)
    set(SANITIZER_FLAGS "-fsanitize=thread")
else()
    set(SANITIZER_FLAGS "")
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${SANITIZER_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${SANITIZER_FLAGS}")

# Основные исходники
# general/src/utils.cpp
set(SRCS
    main.cpp
    Task_1/src/task1.cpp
    Task_1/src/funcs.cpp
    Task_2/src/task2.cpp
    Task_2/src/funcs.cpp
    Task_3/src/task3.cpp
    Task_3/src/funcs.cpp
    general/src/funcs.cpp
)

# Зависимости для тестов
set(TESTS1_NECESSITY
    Task_1/src/funcs.cpp
    general/src/funcs.cpp
)

set(TESTS2_NECESSITY
    Task_2/src/funcs.cpp
    general/src/funcs.cpp
)

set(TESTS3_NECESSITY
    Task_3/src/funcs.cpp
    general/src/funcs.cpp
)

# Исходники тестов
set(TEST_SRCS1
    Task_1/tests/tests.cpp
)

set(TEST_SRCS2
    Task_2/tests/tests.cpp
)

set(TEST_SRCS3
    Task_3/tests/tests.cpp
)

# Подключаем GTest
find_package(GTest REQUIRED)

# Основной исполняемый файл
add_executable(app ${SRCS})
target_link_libraries(app PRIVATE pthread)

# Создаем тестовые исполняемые файлы
add_executable(tests1 ${TEST_SRCS1} ${TESTS1_NECESSITY})
target_link_libraries(tests1 PRIVATE GTest::GTest GTest::Main pthread)

add_executable(tests2 ${TEST_SRCS2} ${TESTS2_NECESSITY})
target_link_libraries(tests2 PRIVATE GTest::GTest GTest::Main pthread)

add_executable(tests3 ${TEST_SRCS3} ${TESTS3_NECESSITY})
target_link_libraries(tests3 PRIVATE GTest::GTest GTest::Main pthread)

# Установка зависимостей сборки (по желанию)
add_dependencies(tests1 app)
add_dependencies(tests2 app)
add_dependencies(tests3 app)

# Регистрация тестов
add_test(NAME task1tests COMMAND tests1)
add_test(NAME task2tests COMMAND tests2)
add_test(NAME task3tests COMMAND tests3)

# Настройка свойств сборки
set_target_properties(app tests1 tests2 tests3 PROPERTIES CLEAN_DIRECTORIES "YES")

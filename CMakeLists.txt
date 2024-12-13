# CMake minimum version
cmake_minimum_required(VERSION 3.29)
project(RestaurantManagement VERSION 1.0 LANGUAGES CXX)

# Global project settings
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# SFML: Include directories and link libraries
set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR "C:/SFML-2.5.1/lib/cmake/SFML")
include_directories("C:/SFML-2.5.1/include")
link_directories("C:/SFML-2.5.1/lib")

# PostgreSQL: Include directories and link libraries
include_directories("C:/Program Files/PostgreSQL/16/include")
link_directories("C:/Program Files/PostgreSQL/16/lib")

# Qt6: Required components
find_package(Qt6 COMPONENTS Core Gui Widgets Test REQUIRED)

# Source and header files for the main application
set(SOURCES
        main.cpp
        Model/PostgreSQLConnection.cpp
        Controller/ControleurService.cpp
        View/InterfaceAcceuil.cpp
        View/MainWindow.cpp
        View/formulaire.cpp
        Model/ClassDefinition/Position.cpp
        View/RestaurantDashboard.cpp
        Controller/Factory.cpp
        Model/ClassDefinition/Table.cpp
        View/MenuWindows.cpp
        Controller/ThreadPool.cpp
        Controller/TaskManager.cpp
)

set(HEADERS
        Model/PostgreSQLConnection.h
        Controller/ControleurService.h
        View/InterfaceAcceuil.h
        View/MainWindow.h
        View/formulaire.h
        Model/ClassDeclaration/Chef_de_rang.h
        View/RestaurantDashboard.h
        Controller/Factory.h
        Model/ClassDeclaration/Table.h
        View/MenuWindows.h
        Controller/ThreadPool.h
        Controller/TaskManager.h
)

# Add main executable
add_executable(RestaurantManagement ${SOURCES} ${HEADERS})

# Link libraries to the main executable
target_link_libraries(RestaurantManagement
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
        pq
        sfml-graphics
        sfml-window
        sfml-system
)

# Google Test: Include and configure testing
add_subdirectory(googletest)
enable_testing()

# Test sources
set(TEST_SOURCES
        tests/main_test.cpp
        tests/TestSample.cpp
        tests/FormulaireTest.cpp
        tests/RestaurantDashBoard_test.cpp
        tests/MenuWindowTest.cpp
        tests/PlatTest.cpp
        tests/FactoryTest.cpp
        tests/MainWindowTest.cpp
)

# Add test executable
add_executable(tests ${TEST_SOURCES})

# Link libraries and sources to the tests executable
target_link_libraries(tests
        gtest
        gtest_main
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
        Qt6::Test
        pq
        sfml-graphics
        sfml-window
        sfml-system
)

# Include only necessary test sources (including main sources)
target_sources(tests PRIVATE ${SOURCES})

# Add each test separately for isolation
foreach(TEST_FILE ${TEST_SOURCES})
    get_filename_component(TEST_NAME ${TEST_FILE} NAME_WE)
    add_test(NAME ${TEST_NAME} COMMAND tests ${TEST_FILE})
endforeach()

# Windows-specific actions
if (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()

    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()

    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET RestaurantManagement POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:RestaurantManagement>/plugins/platforms/")
        add_custom_command(TARGET RestaurantManagement POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:RestaurantManagement>/plugins/platforms/")
    endif ()

    foreach (QT_LIB Core Gui Widgets Test)
        add_custom_command(TARGET RestaurantManagement POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:RestaurantManagement>")
    endforeach ()
endif ()

cmake_minimum_required(VERSION 3.29)
project(RestaurantManagement)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML-2.5.1/lib/cmake/SFML)

# PostgreSQL
include_directories("C:/Program Files/PostgreSQL/16/include")
link_directories("C:/Program Files/PostgreSQL/16/lib")

# SFML
include_directories("C:/SFML-2.6.2/include")
link_directories("C:/SFML-2.6.2/lib")

# Find Qt
find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED
)


# Add executable
add_executable(RestaurantManagement main.cpp
        Model/PostgreSQLConnection.cpp
        Model/PostgreSQLConnection.h
        Controller/ControleurService.cpp
        Controller/ControleurService.h
        View/InterfaceAcceuil.cpp
        View/InterfaceAcceuil.h
        View/MainWindow.cpp
        View/MainWindow.h
        View/formulaire.cpp
        View/formulaire.h
        Model/classDeclaration/Chef_de_rang.h
        Model/ClassDefinition/Position.cpp
        View/RestaurantDashboard.cpp
        View/RestaurantDashboard.h
)

# Link libraries
target_link_libraries(RestaurantManagement
        Qt::Core
        Qt::Gui
        Qt::Widgets
        pq
        sfml-graphics
        sfml-window
        sfml-system
)

# Windows-specific post-build actions
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
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()

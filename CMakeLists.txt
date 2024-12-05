cmake_minimum_required(VERSION 3.29)
project(untitled7)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(untitled7 main.cpp
        mainwindow.cpp
        mainwindow.cpp
        ModelClass/ClassDeclaration/Personne.h
        ModelClass/ClassDeclaration/Plat.h
        ModelClass/ClassDeclaration/Maitre_d_hotel.h
        ModelClass/ClassDeclaration/Commande.h
        ModelClass/ClassDeclaration/Client.h
        ModelClass/ClassDeclaration/Serveur.h
        ModelClass/ClassDefinition/Chef_de_rang.cpp
        ModelClass/ClassDefinition/Commis_de_salle.cpp
        ModelClass/ClassDefinition/Client.cpp
        ModelClass/ClassDeclaration/Chef_de_cuisine.h
        ModelClass/ClassDefinition/Chef_de_cuisine.cpp
        ModelClass/ClassDeclaration/Ingredients.h
        ModelClass/ClassDefinition/Ingredients.cpp
        ModelClass/ClassDeclaration/Menu.h
        ModelClass/ClassDefinition/Menu.cpp
        ModelClass/ClassDeclaration/Rang.h
        ModelClass/ClassDefinition/Rang.cpp)
target_link_libraries(untitled7
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

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

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
        ModelClass/ClassDefinition/ChefDeRang.cpp
        ModelClass/ClassDefinition/CommisDeSalle.cpp
        ModelClass/ClassDefinition/Client.cpp
        ModelClass/ClassDefinition/Chef_de_cuisine.cpp
        ModelClass/ClassDefinition/Ingredients.cpp
        ModelClass/ClassDefinition/Menu.cpp
        ModelClass/ClassDefinition/Rang.cpp
        ModelClass/ClassDefinition/LaveVaisselle.cpp
        ModelClass/ClassDefinition/UstensileDeCuisine.cpp
        ModelClass/ClassDefinition/Chef_dePartie.cpp
        ModelClass/ClassDefinition/Commis_deCuisine.cpp
        ModelClass/ClassDefinition/Plongeur.cpp
        ModelClass/ClassDefinition/Carree.cpp
        ModelClass/ClassDefinition/Table.cpp
        ModelClass/ClassDefinition/Serveur.cpp
        ModelClass/ClassDefinition/Plat.cpp
        ModelClass/ClassDefinition/Position.cpp
        ModelClass/ClassDefinition/Personne.cpp
        ModelClass/ClassDefinition/Maitre_d_hotel.cpp
        ModelClass/ClassDefinition/Commande.cpp
        View/MainWindow.cpp)
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

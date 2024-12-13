# Activer la prise en charge des tests
enable_testing()

# Activer l'automatisation de Qt (MOC, UIC, RCC)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Définir le projet et le standard C++
project(RestaurantManagement VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Trouver les bibliothèques
find_package(Qt6 6.0 REQUIRED COMPONENTS Core Gui Widgets Test)

# PostgreSQL : Inclure les répertoires et lier la bibliothèque
find_library(PostgreSQL_LIBRARIES pq PATHS "C:/Program Files/PostgreSQL/16/lib")
include_directories("C:/Program Files/PostgreSQL/16/include")

# Ajouter l'exécutable pour les tests
add_executable(tests
        tests/main_test.cpp
        tests/TestSample.cpp
        tests/FormulaireTest.cpp
        tests/RestaurantDashBoard_test.cpp
        tests/MenuWindowTest.cpp
        tests/PlatTest.cpp
        tests/FactoryTest.cpp
)

# Inclure les fichiers sources nécessaires (ajusté pour être relatif au dossier racine)
target_sources(tests PRIVATE
        ${CMAKE_SOURCE_DIR}/View/MainWindow.cpp
        ${CMAKE_SOURCE_DIR}/View/Formulaire.cpp
        ${CMAKE_SOURCE_DIR}/View/RestaurantDashboard.cpp
        ${CMAKE_SOURCE_DIR}/Model/ClassDefinition/Plat.cpp
        ${CMAKE_SOURCE_DIR}/Controller/Factory.cpp
)

# Inclure les fichiers d'en-tête et répertoires
target_include_directories(tests PRIVATE
        ${CMAKE_SOURCE_DIR}/View
        ${CMAKE_SOURCE_DIR}/Model/ClassDeclaration
        ${CMAKE_SOURCE_DIR}/Model/ClassDefinition
        ${CMAKE_SOURCE_DIR}/Controller
)

# Lier les bibliothèques au projet de test
target_link_libraries(tests PRIVATE
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

# Configurer GoogleTest et augmenter le timeout
include(GoogleTest)
gtest_discover_tests(tests DISCOVERY_TIMEOUT 60)

# Propriétés de compilation
set_target_properties(tests PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS OFF
)

# Ajouter un test pour exécuter l'exécutable
add_test(NAME RunTests COMMAND $<TARGET_FILE:tests>)

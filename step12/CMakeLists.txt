cmake_minimum_required(VERSION 3.10)

# Nom du projet
project(ApplicHoraire)

# Spécifier le standard C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Trouver les modules Qt nécessaires
find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)

# Include répertoire sources
include_directories(includes sources)

# Ajouter les fichiers sources et ipp automatiquement
file(GLOB SOURCES "sources/*.cpp")
file(GLOB IPP_FILES "sources/*.ipp")

# Ajouter l'exécutable
add_executable(${PROJECT_NAME} ${SOURCES} ${IPP_FILES})

# Lier les bibliothèques Qt nécessaires
target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Gui Qt5::Widgets)

cmake_minimum_required(VERSION 3.17)
project(lab_3)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab_3 main.cpp algorithm/KirkpatrickSeidelAlgorithm.cpp algorithm/KirkpatrickSeidelAlgorithm.h geo/Point.cpp geo/Point.h gui/Button.cpp gui/Button.h gui/window/MenuWindow.cpp gui/window/MenuWindow.h gui/InfoArea.cpp gui/InfoArea.h gui/SelectionMenu.cpp gui/SelectionMenu.h gui/RadioButton.cpp gui/RadioButton.h gui/window/HullWindow.cpp gui/window/HullWindow.h gui/animation/AnimationArea.cpp gui/animation/AnimationArea.h gui/animation/AnimationController.cpp gui/animation/AnimationController.h algorithm/JarvisAndrewAlgorithm.cpp algorithm/JarvisAndrewAlgorithm.h algorithm/GrahamScan.cpp algorithm/GrahamScan.h algorithm/RecursiveAlgorithm.cpp algorithm/RecursiveAlgorithm.h)


set(SFML_DIR "~/Downloads/SFML-2.5.1/lib/cmake/SFML/")
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

target_link_libraries(lab_3 sfml-graphics)
cmake_minimum_required(VERSION 3.17)
project(Project)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_PREFIX_PATH "D:/QT/5.15.2/mingw81_64")
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(QT_VERSION 5)
set(REQUIRED_LIBS Core Gui Widgets)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Gui Qt5::Widgets)

include_directories(src)
include_directories(src/Game)
include_directories(dependencies/openAL/include)

add_subdirectory(dependencies/openAL)

add_executable(
        ${PROJECT_NAME}
        src/main.cpp
        src/Menu.cpp
        src/Menu.h
        src/Window.cpp
        src/Window.h
        src/Util.cpp
        src/Util.h
        src/Tutorial.cpp
        src/Tutorial.h
        src/Settings.cpp
        src/Settings.h
        src/Popup.cpp
        src/Popup.h
        src/Inbox.cpp
        src/Inbox.h
        src/Shop.cpp
        src/Shop.h
        src/CurrentSettings.cpp
        src/CurrentSettings.h
        src/Game/Score.cpp
        src/Game/Score.h
        src/Friends.cpp
        src/Friends.h
        src/Game/Game.cpp
        src/Game/Game.h
        src/Game/Board.cpp
        src/Game/Board.h
        src/Game/Square.cpp
        src/Game/Square.h
        src/Game/SquareTexture.cpp
        src/Game/SquareTexture.h
        src/Game/Figure.cpp
        src/Game/Figure.h
        src/Game/FigureL.h
        src/Game/FigureSquare.cpp
        src/Game/FigureSquare.h
        src/Game/FigureI.cpp
        src/Game/FigureI.h
        src/Game/FigureT.cpp
        src/Game/FigureT.h
        src/Game/FigureReversedL.cpp
        src/Game/FigureReversedL.h
        src/Game/FigureZ.cpp
        src/Game/FigureZ.h
        src/Game/FigureReversedZ.cpp
        src/Game/FigureReversedZ.h
        src/Game/Queue.cpp src/Game/Queue.h)


if (NOT CMAKE_PREFIX_PATH)
    message(WARNING "CMAKE_PREFIX_PATH is not defined, you may need to set it "
            "(-DCMAKE_PREFIX_PATH=\"path/to/Qt/lib/cmake\" or -DCMAKE_PREFIX_PATH=/usr/include/{host}/qt{version}/ on Ubuntu)")
endif ()

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})

if (WIN32)
    set(DEBUG_SUFFIX)
    if (CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "")
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
    foreach (QT_LIB ${REQUIRED_LIBS})
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt${QT_VERSION}${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()

add_executable(audioTest src/mainAudio.cpp)
target_link_libraries(audioTest openal)
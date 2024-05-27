cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(wxWidgets_USE_STATIC 1)
set(wxBUILD_SHARED OFF)

project(sudoku)

include(FetchContent)

FetchContent_Declare(
    wxWidgets
    URL https://github.com/wxWidgets/wxWidgets/releases/download/v3.2.4/wxWidgets-3.2.4.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
FetchContent_MakeAvailable(wxWidgets)
FetchContent_GetProperties(wxWidgets)
if(NOT wxWidgets_POPULATED)
    if(NOT EXISTS ${wxWidgets_SOURCE_DIR})
        FetchContent_Populate(wxWidgets)
        add_subdirectory(${wxWidgets_SOURCE_DIR} ${wxWidgets_BINARY_DIR})
    endif()
endif()

add_executable(sudoku 
    src/app/app.cpp
    src/config/config.cpp
    src/game/game.cpp
    src/view/main_frame.cpp
    src/view/draw_board/draw_board.cpp
    src/view/menu/main_menu.cpp
    src/view/input_number_popup.cpp
    src/game/generator/generator.cpp
)

target_include_directories(sudoku PRIVATE ${wxWidgets_SOURCE_DIR}/include)
target_link_libraries(sudoku PRIVATE wx::core wx::base)
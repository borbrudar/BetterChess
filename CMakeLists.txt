cmake_minimum_required(VERSION 3.0.0)
project(BetterChess VERSION 0.1.0)

include(CTest)
enable_testing()

find_package(SFML 2.5.1
  COMPONENTS 
    system window graphics network audio REQUIRED)

set(SOURCES 
   Bishop.cpp
   Board.cpp 
   BoardV.cpp 
   Chessboard.cpp 
   Game.cpp 
   King.cpp 
   Knight.cpp 
   Main.cpp 
   Pawn.cpp 
   Piece.cpp 
   PromotionMenu.cpp 
   Queen.cpp
   Rook.cpp 
)

list(TRANSFORM SOURCES PREPEND "src/")

set(HEADERS 
    Bishop.h
    Board.h 
    BoardV.h 
    Chessboard.h 
    consts.h
    Game.h
    King.h 
    Knight.h 
    Pawn.h 
    Piece.h 
    PromotionMenu.h 
    Queen.h
    Rook.h
)

list(TRANSFORM HEADERS PREPEND "include/")


add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_link_libraries(BetterChess sfml-graphics)
target_include_directories(BetterChess PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_include_directories(BetterChess PRIVATE ${PROJECT_SOURCE_DIR}/res)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

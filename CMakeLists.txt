cmake_minimum_required(VERSION 3.27.0)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "" FORCE)

project(Snake_Game)

file(GLOB_RECURSE SRC_FILES "${CMAKE_SOURCE_DIR}/Snake_Game/*.cpp")

add_executable(Snake_Game ${SRC_FILES})

add_custom_command(TARGET Snake_Game POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_SOURCE_DIR}/Map.txt" $<TARGET_FILE_DIR:Snake_Game>
  COMMAND_EXPAND_LISTS
  )
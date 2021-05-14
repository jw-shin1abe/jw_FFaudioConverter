cmake_minimum_required(VERSION 3.5)

project(FFaudioConverter LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC_SEARCH_PATHS src)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets LinguistTools REQUIRED)

set(TS_FILES
  translations/de.ts
  translations/fr.ts
  translations/tr.ts
)

file(GLOB SRC_FILES
  "src/main.cpp"
  "src/*.cpp"
  "src/*.h"
  "src/*.ui"
)

add_definitions( -DVERSIONSTR="0.29.1" )

if(EXISTS "/.flatpak-info")
  add_definitions( -DDEFAULT_FFMPEG_BINARY="/app/bin/ffmpeg" )
else()
  if(WIN32)
    add_definitions( -DDEFAULT_FFMPEG_BINARY="ffmpeg/bin/ffmpeg.exe" )
  else()
    add_definitions( -DDEFAULT_FFMPEG_BINARY="/usr/bin/ffmpeg" )
  endif()
endif()

# qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})

if(WIN32)
  set(TARGET FFaudioConverter)
else()
  set(TARGET ffaudioconverter)
endif()

add_executable(
  ${TARGET}
  ${SRC_FILES}
  ${TS_FILES}
)

target_link_libraries(
  ${TARGET}
  PRIVATE Qt5::Widgets
)

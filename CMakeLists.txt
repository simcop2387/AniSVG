# Project Needs a name ofcourse
project(plasma-anisvg)
 
# Find the required Libaries
find_package(KDE4 REQUIRED)
include(KDE4Defaults)

find_package( Qt4 REQUIRED )
set( QT_USE_QTGUI TRUE )
set( QT_USE_QTOPENGL TRUE )
set( QT_USE_QTCORE TRUE )
include(${QT_USE_FILE})

IF (QT_QTOPENGL_FOUND)
  Message("Found QTOPENGL")
ELSE (QT_QTOPENGL_FOUND)
  MESSAGE("Didn't find QTOPENGL")
ENDIF(QT_QTOPENGL_FOUND)

add_definitions ( ${KDE4_DEFINITIONS})
include_directories(
   ${CMAKE_SOURCE_DIR}
   ${CMAKE_BINARY_DIR}
   ${KDE4_INCLUDES}
   )
 
# We add our source code here
set(anisvg_SRCS anisvg.cpp)
 
# Now make sure all files get to the right place
kde4_add_plugin(plasma_wallpaper_anisvg ${anisvg_SRCS})
target_link_libraries(plasma_wallpaper_anisvg 
                      ${KDE4_PLASMA_LIBS} ${KDE4_KDEUI_LIBS} ${QT_LIBRARIES})
 
install(TARGETS plasma_wallpaper_anisvg
        DESTINATION ${PLUGIN_INSTALL_DIR})
 
install(FILES plasma-wallpaper-anisvg.desktop
        DESTINATION ${SERVICES_INSTALL_DIR})

CMAKE_MINIMUM_REQUIRED(VERSION 3.0.0)
PROJECT(gesture-parser VERSION 0.1.0)

SET(PARSER_SOURCES
        src/parser_main.cpp
        src/Leap.i
        src/gesture_parser.cpp
        src/gesture_visualizer.cpp
        src/gestures.cpp
        src/data_history.cpp
        src/g_bus_helper.cpp
        src/custom_listener.cpp
        )

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/include)

SET(PREFIX ${CMAKE_INSTALL_PREFIX})
SET(PACKAGE ${PROJECT_NAME})
SET(BINDIR "${PREFIX}/bin")
SET(LIBDIR "${PREFIX}/lib")
SET(INCLUDEDIR "${PREFIX}/include")

FIND_PACKAGE(Threads)
SET(PKG_MODULES
        glib-2.0
        gio-unix-2.0
        )

FIND_PACKAGE(PkgConfig REQUIRED)
pkg_check_modules(PKGS REQUIRED ${PKG_MODULES})

SET(CODEGEN_PREFIX
        gesture_gdbus_codegen
        )

SET(CODEGEN_COMMAND
        gdbus-codegen
        --interface-prefix com.thelvm.touchless.
        --generate-c-code ${CODEGEN_PREFIX}
        --c-generate-object-manager
        --c-namespace touchless
        ${CMAKE_CURRENT_SOURCE_DIR}/xml/gesture.xml
        )

ADD_CUSTOM_COMMAND(
        COMMAND rm -f ${CMAKE_CURRENT_SOURCE_DIR}/src/${CODEGEN_PREFIX}.c
        COMMAND rm -f ${CMAKE_CURRENT_SOURCE_DIR}/include/${CODEGEN_PREFIX}.h
        OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/src/${CODEGEN_PREFIX}.c
        OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/include/${CODEGEN_PREFIX}.h
        COMMAND ${CODEGEN_COMMAND}
        COMMAND mv -f ${CODEGEN_PREFIX}.c ${CMAKE_CURRENT_SOURCE_DIR}/src/
        COMMAND mv -f ${CODEGEN_PREFIX}.h ${CMAKE_CURRENT_SOURCE_DIR}/include/
)

SET(PARSER_SOURCES
        ${PARSER_SOURCES}
        ${CMAKE_CURRENT_SOURCE_DIR}/src/${CODEGEN_PREFIX}.c
        )

ADD_EXECUTABLE(gesture-parser ${PARSER_SOURCES})

TARGET_LINK_LIBRARIES(gesture-parser libLeap.so ${CMAKE_THREAD_LIBS_INIT} ${PKGS_LIBRARIES})
TARGET_INCLUDE_DIRECTORIES(gesture-parser PUBLIC ${PKGS_INCLUDE_DIRS})
TARGET_COMPILE_OPTIONS(gesture-parser PUBLIC ${PKGS_CFLAGS_OTHERS})

SET(VIEWER_SOURCES
        src/viewer_main.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/${CODEGEN_PREFIX}.c
        )

ADD_EXECUTABLE(gesture-viewer ${VIEWER_SOURCES})
TARGET_LINK_LIBRARIES(gesture-viewer libLeap.so ${CMAKE_THREAD_LIBS_INIT} ${PKGS_LIBRARIES})
TARGET_INCLUDE_DIRECTORIES(gesture-viewer PUBLIC ${PKGS_INCLUDE_DIRS})
TARGET_COMPILE_OPTIONS(gesture-viewer PUBLIC ${PKGS_CFLAGS_OTHERS})


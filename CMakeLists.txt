CMAKE_MINIMUM_REQUIRED(VERSION 3.0.0)
PROJECT(touchless-daemon)

FIND_PACKAGE(Threads)
SET(PKG_MODULES
        glib-2.0
        gio-unix-2.0
        )

FIND_PACKAGE(PkgConfig REQUIRED)
pkg_check_modules(PKGS REQUIRED ${PKG_MODULES})

SET(LEAP_SDK_DIR /home/lucas/leapSDK/2.3.1)
SET(TOUCHLESS_API_DIR /home/lucas/Documents/software_project/Code/touchless-api)

SET(SOURCES
        src/daemon.cpp
        src/DaemonGestureParserListener.cpp
        )

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/include)


ADD_EXECUTABLE(daemon ${SOURCES})

TARGET_LINK_LIBRARIES(daemon
        ${TOUCHLESS_API_DIR}/lib/libtouchless.a
        ${LEAP_SDK_DIR}/lib/x64/libLeap.so
        ${CMAKE_THREAD_LIBS_INIT}
        ${PKGS_LIBRARIES}
        )

TARGET_INCLUDE_DIRECTORIES(daemon PUBLIC
        "${LEAP_SDK_DIR}/include"
        "${CMAKE_CURRENT_SOURCE_DIR}/include"
        "${TOUCHLESS_API_DIR}/dbus"
        "${TOUCHLESS_API_DIR}/include"
        "${PKGS_INCLUDE_DIRS}"
        )

TARGET_COMPILE_OPTIONS(daemon PUBLIC ${PKGS_CFLAGS_OTHERS})

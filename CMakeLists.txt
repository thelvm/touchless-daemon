cmake_minimum_required(VERSION 3.0.0)
project(gesture-parser VERSION 0.1.0)

set(SOURCES main.cpp Leap.i gesture_parser.cpp gesture_visualizer.cpp gestures.cpp data_history.cpp data_history.h)
set(INCLUDE Leap.h getsures.h gesture_visualizer.h gesture_parser.h LeapMath.h)
link_libraries(libLeap.so)

add_executable(gesture-parser ${SOURCES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

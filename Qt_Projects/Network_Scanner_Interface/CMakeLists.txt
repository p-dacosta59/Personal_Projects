cmake_minimum_required(VERSION 3.5)

project(networkInterface)
set(EXECUTABLE_NAME "networkInterface")

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.


find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

find_package(Poco REQUIRED COMPONENTS Foundation Net)
include_directories(${POCO_INCLUDE_DIR}})

find_package(SFML 2.5.1 COMPONENTS network system REQUIRED)
include_directories(${SFML_INCLUDE_DIR})
link_directories(${SFML_LIB_DIR})

include_directories("/usr/local/Cellar/pcapplusplus/20.08/include/")
link_directories("/usr/local/Cellar/pcapplusplus/20.08/lib/")


if(ANDROID)
  add_library(${EXECUTABLE_NAME} SHARED
    main.cpp
  )
else()
  add_executable(${EXECUTABLE_NAME}
    main.cpp
    Scan.cpp
    Scan.h
    Scan.ui
    DetailsUser.cpp
    DetailsUser.h
    DetailsUser.ui
    ScanNetwork.h
    ScanNetwork.cpp
    UserNetwork.h
    UserNetwork.cpp
    utils.h
    utils.cpp
  )
endif()

target_link_libraries(${EXECUTABLE_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets ${Poco_LIBRARIES} sfml-system sfml-network ${THREADS_LIBRARY} Pcap++ Packet++ Common++ pcap pthread "-framework SystemConfiguration" "-framework CoreFoundation")

liri_add_executable("AnWaTool"
    SOURCES
        main.cpp
        qmlcpp.h qmlcpp.cpp
    RESOURCES
        qml.qrc
    LIBRARIES
        Qt5::Core
        Qt5::Gui
        Qt5::QuickControls2
)
if(${CMAKE_CXX_COMPILER} MATCHES ".*/(g\\+\\+)(\\..*)")
    set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS_DEBUG "-mwindows")
elseif(${CMAKE_CXX_COMPILER} MATCHES ".*/(cl)(\\..*)")
    set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS_DEBUG "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
endif()
set(CMAKE_CXX_STANDARD 17)
liri_finalize_executable("AnWaTool")

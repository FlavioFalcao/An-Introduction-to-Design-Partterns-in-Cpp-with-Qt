template = app
CONFIG += qt

QT += gui
QT += core
QT += widgets

SOURCES += \
    main.cpp \
    puzzlemodel.cpp \
    tile.cpp \
    puzzlewindow.cpp

message("CONDITION:")
win32-msvc2010 {
    message("Compiling as condition 'win32-msvc2010'")
    # Enable Level 4 compiler warning
    QMAKE_CXXFLAGS_WARN_ON -= -W3
    QMAKE_CXXFLAGS_WARN_ON += -W4
    # Treat warnings as errors
    QMAKE_CXXFLAGS_WARN_ON += -WX
    # Enable static (no DLL requirement)	# causes crashing
    #QMAKE_CXXFLAGS_RELEASE -= -MD
    #QMAKE_CXXFLAGS_RELEASE += -MT
    # Hush common known Qt warning
    # reference: http://qt-project.org/forums/viewthread/10527
    QMAKE_CXXFLAGS += -wd4127 -wd4512 -wd4189
} macx {
    message("Compile condition: macx")
    # work around to the "'initializer_list' file not found bug"
    QMAKE_CXXFLAGS = -mmacosx-version-min=10.7 -std=gnu0x -stdlib=libc++
    # enable all warnings
    QMAKE_CXXFLAGS_WARN_ON += -Wall
    # classify warning as errors
    QMAKE_CXXFLAGS += -Werror
    # pedantic
    QMAKE_CXXFLAGS += -pedantic
    # enable C++11
    QMAKE_CXXFLAGS += -std=c++11   # does not work due to 'initializer_list' file not found bug
} mingw {
    message("mingw condition...")
    # enable all warnings
    QMAKE_CXXFLAGS_WARN_ON += -Wall
    # classify warning as errors
    QMAKE_CXXFLAGS += -Werror
    # pedantic
    QMAKE_CXXFLAGS += -pedantic
    # enable C++11
    QMAKE_CXXFLAGS += -std=c++11
} else {
    message("Default condition...")
    #this condition will always be satisfied on Win7 machine for unknown reason.
}

HEADERS += \
    puzzlemodel.h \
    tile.h \
    puzzlewindow.h

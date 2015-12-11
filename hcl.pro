# Qt configuration
QT += dbus
TARGET = hcl
TEMPLATE = lib
CONFIG += dynamiclib

QMAKE_CXXFLAGS += -std=c++14

SOURCES += \
    src/DaemonWorker.cpp \
    src/DaemonManager.cpp \
    src/Exception.cpp \
    src/Hash.cpp \
    \
    include/HCL/Factory.tpp \
    src/Vector3.cpp \
    src/Operators.cpp \
    src/Locker2.cpp

HEADERS += \
    include/HCL/DaemonManager.hpp \
    include/HCL/DaemonWorker.hpp \
    include/HCL/Defs.hpp \
    include/HCL/Exception.hpp \
    include/HCL/Factory.hpp \
    include/HCL/Hash.hpp \
    include/HCL/DaemonMode.hpp \
    include/HCL/Vector3.hpp \
    include/HCL/Operators.hpp \
    include/HCL/Locker2.hpp

unix
{
    target.path = /usr/lib
    INSTALLS += target
}

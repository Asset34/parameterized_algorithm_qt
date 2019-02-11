QT += core gui widgets

INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD

SOURCES += \
    $$PWD/core/parameters/flagparameter.cpp \
    $$PWD/core/parameters/intparameter.cpp \
    $$PWD/core/parameters/parameter.cpp \
    $$PWD/core/parameters/realparameter.cpp \
    $$PWD/widgets/algorithmselector.cpp \
    $$PWD/widgets/algorithmwidget.cpp \
    $$PWD/widgets/guicreatingvisitor.cpp \
    $$PWD/widgets/parameterlistwidget.cpp \
    $$PWD/core/parameters/compositeparameter.cpp

HEADERS += \
    $$PWD/core/parameters/flagparameter.hpp \
    $$PWD/core/parameters/intparameter.hpp \
    $$PWD/core/parameters/parameter.hpp \
    $$PWD/core/parameters/realparameter.hpp \
    $$PWD/core/algorithm.hpp \
    $$PWD/core/parametervisitor.hpp \
    $$PWD/widgets/algorithmselector.hpp \
    $$PWD/widgets/algorithmwidget.hpp \
    $$PWD/widgets/guicreatingvisitor.hpp \
    $$PWD/widgets/parameterlistwidget.hpp \
    $$PWD/core/parameters/compositeparameter.hpp

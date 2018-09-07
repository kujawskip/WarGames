QT += widgets

HEADERS       = mainwindow.h \
    mainwindow.h \
    starttab.h \
    parameterstab.h \
    squadtab.h \
    maptab.h \
    placementtab.h \
    parameters.h \
    labeledslider.h \
    helper.h
SOURCES       = main.cpp \
                mainwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    starttab.cpp \
    parameterstab.cpp \
    squadtab.cpp \
    maptab.cpp \
    placementtab.cpp \
    labeledslider.cpp \
    simulatedparameters.cpp \
    helper.cpp
#! [0]
RESOURCES     = application.qrc \
    application.qrc
#! [0]

# install
target.path = ./
INSTALLS += target

DISTFILES += \
    application.pro.user

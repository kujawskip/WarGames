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
    area.h \
    army.h \
    simulationdata.h \
    placement.h \
    vector_from_array.h \
    jsonwrapper.h \
    unit.h \
    armygroup.h \
    ability.h \
    attack.h \
    simulatedunit.h \
    point.h \
    squad.h \
    labeledlineedit.h
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
    simulationdata.cpp \
    parameters.cpp \
    vector_from_array.cpp \
    jsonwrapper.cpp \
    point.cpp \
    labeledlinedit.cpp
#! [0]
RESOURCES     = application.qrc \
    application.qrc
#! [0]

# install
target.path = ./
INSTALLS += target

DISTFILES += \
    application.pro.user

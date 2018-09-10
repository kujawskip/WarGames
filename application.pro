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
    labeledlineedit.h \
    unitprovider.h \
    armyunitlabel.h \
    armyunitlabels.h \
    unitdetails.h \
    labeledlabel.h \
    groupunitlabel.h \
    maphelper.h \
    mapprovider.h \
    jsonmap.h \
    base64.h \
    arearenderer.h \
    maplist.h
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
    labeledlinedit.cpp \
    unitprovider.cpp \
    unit.cpp \
    armyunitlabel.cpp \
    armyunitlabels.cpp \
    ability.cpp \
    unitdetails.cpp \
    labeledlabel.cpp \
    armygroup.cpp \
    groupunitlabel.cpp \
    army.cpp \
    area.cpp \
    mapprovider.cpp \
    jsonmap.cpp \
    base64.cpp \
    arearenderer.cpp \
    maplist.cpp
#! [0]
RESOURCES     = application.qrc \
    application.qrc \
    resources.qrc
#! [0]

# install
target.path = ./
INSTALLS += target

DISTFILES += \
    application.pro.user \
    units.json \
    maps.json

INCLUDEPATH += "C:/Program Files (x86)/Windows Kits/10/Include/10.0.10240.0/ucrt"
LIBS += -L"C:/Program Files (x86)/Windows Kits/10/Lib/10.0.10240.0/ucrt/x64"

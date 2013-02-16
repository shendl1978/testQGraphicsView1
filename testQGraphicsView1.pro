QT += core gui widgets
SOURCES += \
    main.cpp \
    goelement.cpp \
    chessmapitem.cpp \
    fivechess.cpp \
    fivechesselement.cpp \
    fiveChessType.cpp \
    startdialog.cpp \
    fivechessform.cpp

HEADERS += \
    goelement.h \
    chessmapitem.h \
    fivechess.h \
    fivechesselement.h \
    fiveChessType.h \
    startdialog.h \
    fivechessform.h

FORMS += \
    startdialog.ui \
    fivechessform.ui

RESOURCES += \
    icons/icons.qrc

OTHER_FILES += \
    icons/download_manager.ico
TRANSLATIONS = fiveChess_zh_CN.ts

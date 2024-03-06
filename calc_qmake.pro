QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    math/executerpn.cpp \
    math/rpn.cpp \
    token/token.cpp \
    token/tokenizer.cpp \
    token/types/closeparenthesis.cpp \
    token/types/function.cpp \
    token/types/functionfabric.cpp \
    token/types/functions/abs.cpp \
    token/types/functions/cos.cpp \
    token/types/functions/sin.cpp \
    token/types/functions/sqrt.cpp \
    token/types/functions/tan.cpp \
    token/types/number.cpp \
    token/types/openparenthesis.cpp \
    token/types/operation.cpp

HEADERS += \
    mainwindow.h \
    math/executerpn.h \
    math/rpn.h \
    token/token.h \
    token/tokenizer.h \
    token/types/closeparenthesis.h \
    token/types/function.h \
    token/types/functionfabric.h \
    token/types/functions/abs.h \
    token/types/functions/cos.h \
    token/types/functions/sin.h \
    token/types/functions/sqrt.h \
    token/types/functions/tan.h \
    token/types/number.h \
    token/types/openparenthesis.h \
    token/types/operation.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

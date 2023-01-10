QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

#LIBS += -LC:\Program Files (x86)\taglib\lib\libtag_c.a
#INCLUDEPATH += C:\Program Files (x86)\taglib\include\taglib
#PRE_TARGETDEPS += C:\Program Files (x86)\taglib\lib\libtag.a

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
DEFINES += QT_DEPRECATED_WARNINGS


SOURCES += \
    main.cpp \
    mainwindow.cpp \
    music.cpp \
    weekday.cpp


HEADERS += \
    mainwindow.h \
    music.h \
    weekday.h






#INCLUDEPATH += C:\Program Files (x86)\taglib\include

#LIBS += C:\Program Files (x86)\taglib\lib\libtag.a
#LIBS += C:\Program Files (x86)\taglib\lib\libtag_c.a
#LIBS += C:\Program Files (x86)\taglib\lib\pkgconfig\taglib.pc
#LIBS += C:\Program Files (x86)\taglib\lib\pkgconfig\taglib_c.pc

#DEFINES += TAGLIB_STATIC


#INCLUDEPATH += E:\openCV\opencv\build\include
#LIBS += E:\openCV\opencv\build\bin\libopencv_core460.dll
#LIBS += E:\openCV\opencv\build\bin\libopencv_calib3d460.dll
#LIBS += E:\openCV\opencv\build\bin\libopencv_dnn460.dll
#LIBS += E:\openCV\opencv\build\bin\libopencv_features2d460.dll
#LIBS += E:\openCV\opencv\build\bin\libopencv_flann460.dll
#LIBS += E:\openCV\opencv\build\bin\libopencv_gapi460.dll

#LIBS += E:\openCV\opencv\build\bin\libopencv_highgui460.dll
#LIBS += E:\openCV\opencv\build\bin\libopencv_imgcodecs460.dll
#LIBS += E:\openCV\opencv\build\bin\libopencv_imgproc460.dll

#LIBS += E:\openCV\opencv\build\bin\libopencv_ml460.dll
#LIBS += E:\openCV\opencv\build\bin\libopencv_objdetect460.dll

#LIBS += E:\openCV\opencv\build\bin\libopencv_photo460.dll
#LIBS += E:\openCV\opencv\build\bin\libopencv_stitching460.dll

#LIBS += E:\openCV\opencv\build\bin\libopencv_video460.dll
#LIBS += E:\openCV\opencv\build\bin\libopencv_videoio460.dll
#LIBS += E:\openCV\opencv\build\bin\opencv_videoio_ffmpeg460_64.dll


#LIBS += -L$$(OPENCV_SDK_DIR)/x86/mingw/lib \


FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    first_en_US.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target







#win32:CONFIG(release, debug|release): LIBS += -LE:/opencv/build/lib/ -llibopencv_calib3d460.dll
#win32:CONFIG(release, debug|release): LIBS += -LE:/opencv/build/lib/ -libopencv_core460.dll
#win32:CONFIG(release, debug|release): LIBS += -LE:/opencv/build/lib/ -libopencv_dnn460.dll
#win32:CONFIG(release, debug|release): LIBS += -LE:/opencv/build/lib/ -libopencv-features2d460.dll
#win32:CONFIG(release, debug|release): LIBS += -LE:/opencv/build/lib/ -libopencv_flann460.dll
#win32:CONFIG(release, debug|release): LIBS += -LE:/opencv/build/lib/ -libopencv_gapi460.dll
#win32:CONFIG(release, debug|release): LIBS += -LE:/opencv/build/lib/ -libopencv_highgui460.dll
#win32:CONFIG(release, debug|release): LIBS += -LE:/opencv/build/lib/ -libopencv_imgcodecs460.dll
#win32:CONFIG(release, debug|release): LIBS += -LE:/opencv/build/lib/ -libopencv_imgproc460.dll
#win32:CONFIG(release, debug|release): LIBS += -LE:/opencv/build/lib/ -libopencv_ml460.dll
#win32:CONFIG(release, debug|release): LIBS += -LE:/opencv/build/lib/ -libopencv_objdetect460.dll
#win32:CONFIG(release, debug|release): LIBS += -LE:/opencv/build/lib/ -libopencv_photo460.dll
#win32:CONFIG(release, debug|release): LIBS += -LE:/opencv/build/lib/ -libopencv_stitching460.dll
#win32:CONFIG(release, debug|release): LIBS += -LE:/opencv/build/lib/ -libopencv_video460.dll
#win32:CONFIG(release, debug|release): LIBS += -LE:/opencv/build/lib/ -libopencv_videoio460.dll
#win32:CONFIG(release, debug|release): LIBS += -LE:/opencv/build/lib/ -opencv_videoio_ffmpeg460_64.dll



#INCLUDEPATH += E:/opencv/build/include
#DEPENDPATH += E:/opencv/build/include




#win32:CONFIG(release, debug|release): LIBS += -LE:/opencv/build/x64/vc15/lib/ -lopencv_world460
#else:win32:CONFIG(debug, debug|release): LIBS += -LE:/opencv/build/x64/vc15/lib/ -lopencv_world460d

#INCLUDEPATH += E:/opencv/build/x64/vc15
#DEPENDPATH += E:/opencv/build/x64/vc15


#win32:CONFIG(release, debug|release): LIBS += -LE:/opencv/build/x64/vc14/lib/ -lopencv_world460
#else:win32:CONFIG(debug, debug|release): LIBS += -LE:/opencv/build/x64/vc14/lib/ -lopencv_world460d

#INCLUDEPATH += E:/opencv/build/x64/vc14
#DEPENDPATH += E:/opencv/build/x64/vc14


#win32:CONFIG(release, debug|release): LIBS += -LE:/opencv/build/install/x64/mingw/lib/ -llibopencv_calib3d460.dll

#INCLUDEPATH += E:/opencv/build/install/x64/mingw
#DEPENDPATH += E:/opencv/build/install/x64/mingw



INCLUDEPATH += E:\code\c++\mp3\libmp3-master


HEADERS += E:\code\c++\mp3\libmp3-master\mp3.h
HEADERS += E:\code\c++\mp3\libmp3-master\mp3frame.h



SOURCES += E:\code\c++\mp3\libmp3-master\mp3.cpp
SOURCES += E:\code\c++\mp3\libmp3-master\mp3frame.cpp

LIBS += -LE:\code\c++\mp3\libmp3-master\ -llibmp3
LIBS += -LC:\Users\Mahdi\Desktop\MinGW\lib\ -lwinmm


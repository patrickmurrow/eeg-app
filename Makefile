#############################################################################
# Makefile for building: build/eeg-gui
# Generated by qmake (2.01a) (Qt 4.8.6) on: Tue Mar 1 13:43:19 2016
# Project:  eeg-gui.pro
# Template: app
# Command: /usr/lib/x86_64-linux-gnu/qt4/bin/qmake -o Makefile eeg-gui.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -m64 -pipe -g -lbluetooth -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++-64 -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I. -Isrc/interface -Isrc/eeg/brainlink -Ibuild -Ibuild
LINK          = g++
LFLAGS        = -m64 -Wl,-O1
LIBS          = $(SUBLIBS)  -L/usr/lib/x86_64-linux-gnu -lbluetooth -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/lib/x86_64-linux-gnu/qt4/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = build/

####### Files

SOURCES       = src/interface/bluetoothManager.cpp \
		src/interface/bluetoothConnectThread.cpp \
		src/interface/bluetoothSearchThread.cpp \
		src/interface/bluetoothItem.cpp \
		src/interface/main.cpp \
		src/eeg/eegHeadset.cpp \
		src/eeg/brainlink/brainlinkParser.cpp \
		src/eeg/brainlink/brainlinkHS.cpp \
		src/eeg/dummy/dummyHS.cpp \
		src/eeg/dummy/dummyGenerator.cpp \
		src/util/eeg/eegData.cpp \
		src/util/eeg/eegManager.cpp \
		src/util/eeg/headsetManager.cpp \
		src/interface/eeg-app/eegappmenu.cpp \
		src/interface/eeg-app/calibratewindow.cpp \
		src/interface/eeg-app/applicationwindow.cpp \
		src/interface/eeg-app/settingswindow.cpp \
		src/interface/eeg-app/calibrationthread.cpp \
		src/interface/eeg-app/device.cpp \
		src/interface/eeg-app/eegdisplaywindow.cpp \
		src/interface/eeg-app/qcustomplot.cpp \
		src/eeg/muse/museSerial.cpp \
		src/eeg/muse/museParser.cpp \
		src/eeg/muse/museHS.cpp \
		src/eeg/openBCI/openBCIHS.cpp \
		src/interface/eeg-app/eegdisplaydialog.cpp \
		src/eeg/openBCI/openBCIGenerator.cpp \
		src/fft/serial.c \
		src/fft/parser.c \
		src/fft/new_s.c \
		src/fft/fft.c \
		src/fft/drone.c \
		src/fft/dft.c \
		src/fft/fftCalc.cpp \
		src/eeg/openBCI/openBCISerial.cpp \
		src/eeg/openBCI/openBCIParser.cpp build/moc_bluetoothManager.cpp \
		build/moc_bluetoothConnectThread.cpp \
		build/moc_bluetoothSearchThread.cpp \
		build/moc_bluetoothItem.cpp \
		build/moc_dummyGenerator.cpp \
		build/moc_eegData.cpp \
		build/moc_eegManager.cpp \
		build/moc_eegappmenu.cpp \
		build/moc_calibratewindow.cpp \
		build/moc_applicationwindow.cpp \
		build/moc_settingswindow.cpp \
		build/moc_calibrationthread.cpp \
		build/moc_device.cpp \
		build/moc_eegdisplaywindow.cpp \
		build/moc_qcustomplot.cpp \
		build/moc_openBCIHS.cpp \
		build/moc_eegdisplaydialog.cpp \
		build/moc_openBCIGenerator.cpp \
		build/moc_fftCalc.cpp \
		build/qrc_ImageResources.cpp
OBJECTS       = build/bluetoothManager.o \
		build/bluetoothConnectThread.o \
		build/bluetoothSearchThread.o \
		build/bluetoothItem.o \
		build/main.o \
		build/eegHeadset.o \
		build/brainlinkParser.o \
		build/brainlinkHS.o \
		build/dummyHS.o \
		build/dummyGenerator.o \
		build/eegData.o \
		build/eegManager.o \
		build/headsetManager.o \
		build/eegappmenu.o \
		build/calibratewindow.o \
		build/applicationwindow.o \
		build/settingswindow.o \
		build/calibrationthread.o \
		build/device.o \
		build/eegdisplaywindow.o \
		build/qcustomplot.o \
		build/museSerial.o \
		build/museParser.o \
		build/museHS.o \
		build/openBCIHS.o \
		build/eegdisplaydialog.o \
		build/openBCIGenerator.o \
		build/serial.o \
		build/parser.o \
		build/new_s.o \
		build/fft.o \
		build/drone.o \
		build/dft.o \
		build/fftCalc.o \
		build/openBCISerial.o \
		build/openBCIParser.o \
		build/moc_bluetoothManager.o \
		build/moc_bluetoothConnectThread.o \
		build/moc_bluetoothSearchThread.o \
		build/moc_bluetoothItem.o \
		build/moc_dummyGenerator.o \
		build/moc_eegData.o \
		build/moc_eegManager.o \
		build/moc_eegappmenu.o \
		build/moc_calibratewindow.o \
		build/moc_applicationwindow.o \
		build/moc_settingswindow.o \
		build/moc_calibrationthread.o \
		build/moc_device.o \
		build/moc_eegdisplaywindow.o \
		build/moc_qcustomplot.o \
		build/moc_openBCIHS.o \
		build/moc_eegdisplaydialog.o \
		build/moc_openBCIGenerator.o \
		build/moc_fftCalc.o \
		build/qrc_ImageResources.o
DIST          = /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/shared.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		eeg-gui.pro
QMAKE_TARGET  = eeg-gui
DESTDIR       = build/
TARGET        = build/eeg-gui

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): build/ui_fatigueapp.h build/ui_eegappmenu.h build/ui_calibratewindow.h build/ui_applicationwindow.h build/ui_settingswindow.h build/ui_eegdisplaywindow.h build/ui_eegdisplaydialog.h $(OBJECTS)  
	@$(CHK_DIR_EXISTS) build/ || $(MKDIR) build/ 
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: eeg-gui.pro  /usr/share/qt4/mkspecs/linux-g++-64/qmake.conf /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/shared.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/lib/x86_64-linux-gnu/libQtGui.prl \
		/usr/lib/x86_64-linux-gnu/libQtCore.prl
	$(QMAKE) -o Makefile eeg-gui.pro
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/common/gcc-base.conf:
/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt4/mkspecs/common/g++-base.conf:
/usr/share/qt4/mkspecs/common/g++-unix.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/shared.prf:
/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/lib/x86_64-linux-gnu/libQtGui.prl:
/usr/lib/x86_64-linux-gnu/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -o Makefile eeg-gui.pro

dist: 
	@$(CHK_DIR_EXISTS) build/eeg-gui1.0.0 || $(MKDIR) build/eeg-gui1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) build/eeg-gui1.0.0/ && $(COPY_FILE) --parents src/interface/bluetoothManager.hpp src/interface/bluetoothConnectThread.hpp src/interface/bluetoothSearchThread.hpp src/interface/bluetoothDIsplayWidget.hpp src/interface/bluetoothItem.hpp src/eeg/eegHeadset.hpp src/eeg/brainlink/eeg.h src/eeg/brainlink/brainlinkParser.h src/eeg/brainlink/brainlinkSerial.h src/eeg/brainlink/brainlinkHS.hpp src/eeg/dummy/dummyGenerator.hpp src/eeg/dummy/dummyHS.hpp src/util/eeg/eegData.hpp src/util/eeg/eegManager.hpp src/util/eeg/headsetManager.hpp src/interface/eeg-app/eegappmenu.h src/interface/eeg-app/calibratewindow.h src/interface/eeg-app/applicationwindow.h src/interface/eeg-app/settingswindow.h src/interface/eeg-app/calibrationthread.hpp src/interface/eeg-app/device.h src/interface/eeg-app/eegdisplaywindow.h src/interface/eeg-app/qcustomplot.h src/eeg/muse/museSerial.h src/eeg/muse/museParser.h src/eeg/muse/museHS.hpp src/eeg/muse/eeg.h src/eeg/openBCI/openBCIHS.hpp src/interface/eeg-app/eegdisplaydialog.h src/eeg/openBCI/openBCIGenerator.hpp src/fft/eeg.h src/fft/drone.h src/fft/fftCalc.hpp src/eeg/openBCI/openBCISerial.h src/eeg/openBCI/openBCIParser.h src/eeg/openBCI/eeg.h build/eeg-gui1.0.0/ && $(COPY_FILE) --parents assets/ImageResources.qrc build/eeg-gui1.0.0/ && $(COPY_FILE) --parents src/interface/bluetoothManager.cpp src/interface/bluetoothConnectThread.cpp src/interface/bluetoothSearchThread.cpp src/interface/bluetoothItem.cpp src/interface/main.cpp src/eeg/eegHeadset.cpp src/eeg/brainlink/brainlinkParser.cpp src/eeg/brainlink/brainlinkHS.cpp src/eeg/dummy/dummyHS.cpp src/eeg/dummy/dummyGenerator.cpp src/util/eeg/eegData.cpp src/util/eeg/eegManager.cpp src/util/eeg/headsetManager.cpp src/interface/eeg-app/eegappmenu.cpp src/interface/eeg-app/calibratewindow.cpp src/interface/eeg-app/applicationwindow.cpp src/interface/eeg-app/settingswindow.cpp src/interface/eeg-app/calibrationthread.cpp src/interface/eeg-app/device.cpp src/interface/eeg-app/eegdisplaywindow.cpp src/interface/eeg-app/qcustomplot.cpp src/eeg/muse/museSerial.cpp src/eeg/muse/museParser.cpp src/eeg/muse/museHS.cpp src/eeg/openBCI/openBCIHS.cpp src/interface/eeg-app/eegdisplaydialog.cpp src/eeg/openBCI/openBCIGenerator.cpp src/fft/serial.c src/fft/parser.c src/fft/new_s.c src/fft/fft.c src/fft/drone.c src/fft/dft.c src/fft/fftCalc.cpp src/eeg/openBCI/openBCISerial.cpp src/eeg/openBCI/openBCIParser.cpp build/eeg-gui1.0.0/ && $(COPY_FILE) --parents src/interface/fatigue/fatigueapp.ui src/interface/eeg-app/eegappmenu.ui src/interface/eeg-app/calibratewindow.ui src/interface/eeg-app/applicationwindow.ui src/interface/eeg-app/settingswindow.ui src/interface/eeg-app/eegdisplaywindow.ui src/interface/eeg-app/eegdisplaydialog.ui build/eeg-gui1.0.0/ && (cd `dirname build/eeg-gui1.0.0` && $(TAR) eeg-gui1.0.0.tar eeg-gui1.0.0 && $(COMPRESS) eeg-gui1.0.0.tar) && $(MOVE) `dirname build/eeg-gui1.0.0`/eeg-gui1.0.0.tar.gz . && $(DEL_FILE) -r build/eeg-gui1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: build/moc_bluetoothManager.cpp build/moc_bluetoothConnectThread.cpp build/moc_bluetoothSearchThread.cpp build/moc_bluetoothItem.cpp build/moc_dummyGenerator.cpp build/moc_eegData.cpp build/moc_eegManager.cpp build/moc_eegappmenu.cpp build/moc_calibratewindow.cpp build/moc_applicationwindow.cpp build/moc_settingswindow.cpp build/moc_calibrationthread.cpp build/moc_device.cpp build/moc_eegdisplaywindow.cpp build/moc_qcustomplot.cpp build/moc_openBCIHS.cpp build/moc_eegdisplaydialog.cpp build/moc_openBCIGenerator.cpp build/moc_fftCalc.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) build/moc_bluetoothManager.cpp build/moc_bluetoothConnectThread.cpp build/moc_bluetoothSearchThread.cpp build/moc_bluetoothItem.cpp build/moc_dummyGenerator.cpp build/moc_eegData.cpp build/moc_eegManager.cpp build/moc_eegappmenu.cpp build/moc_calibratewindow.cpp build/moc_applicationwindow.cpp build/moc_settingswindow.cpp build/moc_calibrationthread.cpp build/moc_device.cpp build/moc_eegdisplaywindow.cpp build/moc_qcustomplot.cpp build/moc_openBCIHS.cpp build/moc_eegdisplaydialog.cpp build/moc_openBCIGenerator.cpp build/moc_fftCalc.cpp
build/moc_bluetoothManager.cpp: src/interface/bluetoothConnectThread.hpp \
		src/interface/bluetoothManager.hpp
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) src/interface/bluetoothManager.hpp -o build/moc_bluetoothManager.cpp

build/moc_bluetoothConnectThread.cpp: src/interface/bluetoothConnectThread.hpp
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) src/interface/bluetoothConnectThread.hpp -o build/moc_bluetoothConnectThread.cpp

build/moc_bluetoothSearchThread.cpp: src/interface/bluetoothSearchThread.hpp
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) src/interface/bluetoothSearchThread.hpp -o build/moc_bluetoothSearchThread.cpp

build/moc_bluetoothItem.cpp: src/interface/bluetoothItem.hpp
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) src/interface/bluetoothItem.hpp -o build/moc_bluetoothItem.cpp

build/moc_dummyGenerator.cpp: src/eeg/dummy/dummyGenerator.hpp
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) src/eeg/dummy/dummyGenerator.hpp -o build/moc_dummyGenerator.cpp

build/moc_eegData.cpp: src/util/eeg/eegData.hpp
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) src/util/eeg/eegData.hpp -o build/moc_eegData.cpp

build/moc_eegManager.cpp: src/util/eeg/eegData.hpp \
		src/eeg/eegHeadset.hpp \
		src/util/eeg/eegManager.hpp
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) src/util/eeg/eegManager.hpp -o build/moc_eegManager.cpp

build/moc_eegappmenu.cpp: src/interface/eeg-app/eegappmenu.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) src/interface/eeg-app/eegappmenu.h -o build/moc_eegappmenu.cpp

build/moc_calibratewindow.cpp: src/util/eeg/eegData.hpp \
		src/interface/eeg-app/calibratewindow.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) src/interface/eeg-app/calibratewindow.h -o build/moc_calibratewindow.cpp

build/moc_applicationwindow.cpp: src/interface/eeg-app/applicationwindow.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) src/interface/eeg-app/applicationwindow.h -o build/moc_applicationwindow.cpp

build/moc_settingswindow.cpp: src/interface/eeg-app/settingswindow.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) src/interface/eeg-app/settingswindow.h -o build/moc_settingswindow.cpp

build/moc_calibrationthread.cpp: src/interface/eeg-app/calibrationthread.hpp
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) src/interface/eeg-app/calibrationthread.hpp -o build/moc_calibrationthread.cpp

build/moc_device.cpp: src/interface/eeg-app/device.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) src/interface/eeg-app/device.h -o build/moc_device.cpp

build/moc_eegdisplaywindow.cpp: src/interface/eeg-app/eegdisplaywindow.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) src/interface/eeg-app/eegdisplaywindow.h -o build/moc_eegdisplaywindow.cpp

build/moc_qcustomplot.cpp: src/interface/eeg-app/qcustomplot.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) src/interface/eeg-app/qcustomplot.h -o build/moc_qcustomplot.cpp

build/moc_openBCIHS.cpp: src/eeg/openBCI/openBCISerial.h \
		src/eeg/openBCI/openBCIParser.h \
		src/util/eeg/headsetManager.hpp \
		src/util/eeg/eegManager.hpp \
		src/util/eeg/eegData.hpp \
		src/eeg/eegHeadset.hpp \
		src/eeg/openBCI/openBCIGenerator.hpp \
		src/eeg/openBCI/openBCIHS.hpp
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) src/eeg/openBCI/openBCIHS.hpp -o build/moc_openBCIHS.cpp

build/moc_eegdisplaydialog.cpp: src/util/eeg/eegManager.hpp \
		src/util/eeg/eegData.hpp \
		src/eeg/eegHeadset.hpp \
		src/interface/eeg-app/eegdisplaydialog.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) src/interface/eeg-app/eegdisplaydialog.h -o build/moc_eegdisplaydialog.cpp

build/moc_openBCIGenerator.cpp: src/eeg/eegHeadset.hpp \
		src/util/eeg/headsetManager.hpp \
		src/util/eeg/eegManager.hpp \
		src/util/eeg/eegData.hpp \
		src/eeg/openBCI/openBCIGenerator.hpp
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) src/eeg/openBCI/openBCIGenerator.hpp -o build/moc_openBCIGenerator.cpp

build/moc_fftCalc.cpp: src/eeg/eegHeadset.hpp \
		src/eeg/dummy/dummyHS.hpp \
		src/eeg/dummy/dummyGenerator.hpp \
		src/eeg/muse/museHS.hpp \
		src/eeg/openBCI/openBCIHS.hpp \
		src/eeg/openBCI/openBCISerial.h \
		src/eeg/openBCI/openBCIParser.h \
		src/util/eeg/headsetManager.hpp \
		src/util/eeg/eegManager.hpp \
		src/util/eeg/eegData.hpp \
		src/eeg/openBCI/openBCIGenerator.hpp \
		src/fft/fftCalc.hpp
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) src/fft/fftCalc.hpp -o build/moc_fftCalc.cpp

compiler_rcc_make_all: build/qrc_ImageResources.cpp
compiler_rcc_clean:
	-$(DEL_FILE) build/qrc_ImageResources.cpp
build/qrc_ImageResources.cpp: assets/ImageResources.qrc \
		assets/btnApplications.png \
		assets/btnBegin.png \
		assets/btnBack.png \
		assets/btnDrone.png \
		assets/btnSettings.png \
		assets/btnCancel.png \
		assets/loading.gif \
		assets/btnFatigue.png \
		assets/white-arrow-down.png \
		assets/btnCalibration.png \
		assets/btnSearch.png \
		assets/tick.png \
		assets/btnConnect.png \
		assets/btnDepression.png
	/usr/lib/x86_64-linux-gnu/qt4/bin/rcc -name ImageResources assets/ImageResources.qrc -o build/qrc_ImageResources.cpp

compiler_image_collection_make_all: build/qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) build/qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: build/ui_fatigueapp.h build/ui_eegappmenu.h build/ui_calibratewindow.h build/ui_applicationwindow.h build/ui_settingswindow.h build/ui_eegdisplaywindow.h build/ui_eegdisplaydialog.h
compiler_uic_clean:
	-$(DEL_FILE) build/ui_fatigueapp.h build/ui_eegappmenu.h build/ui_calibratewindow.h build/ui_applicationwindow.h build/ui_settingswindow.h build/ui_eegdisplaywindow.h build/ui_eegdisplaydialog.h
build/ui_fatigueapp.h: src/interface/fatigue/fatigueapp.ui
	/usr/lib/x86_64-linux-gnu/qt4/bin/uic src/interface/fatigue/fatigueapp.ui -o build/ui_fatigueapp.h

build/ui_eegappmenu.h: src/interface/eeg-app/eegappmenu.ui
	/usr/lib/x86_64-linux-gnu/qt4/bin/uic src/interface/eeg-app/eegappmenu.ui -o build/ui_eegappmenu.h

build/ui_calibratewindow.h: src/interface/eeg-app/calibratewindow.ui
	/usr/lib/x86_64-linux-gnu/qt4/bin/uic src/interface/eeg-app/calibratewindow.ui -o build/ui_calibratewindow.h

build/ui_applicationwindow.h: src/interface/eeg-app/applicationwindow.ui
	/usr/lib/x86_64-linux-gnu/qt4/bin/uic src/interface/eeg-app/applicationwindow.ui -o build/ui_applicationwindow.h

build/ui_settingswindow.h: src/interface/eeg-app/settingswindow.ui
	/usr/lib/x86_64-linux-gnu/qt4/bin/uic src/interface/eeg-app/settingswindow.ui -o build/ui_settingswindow.h

build/ui_eegdisplaywindow.h: src/interface/eeg-app/eegdisplaywindow.ui
	/usr/lib/x86_64-linux-gnu/qt4/bin/uic src/interface/eeg-app/eegdisplaywindow.ui -o build/ui_eegdisplaywindow.h

build/ui_eegdisplaydialog.h: src/interface/eeg-app/eegdisplaydialog.ui
	/usr/lib/x86_64-linux-gnu/qt4/bin/uic src/interface/eeg-app/eegdisplaydialog.ui -o build/ui_eegdisplaydialog.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_rcc_clean compiler_uic_clean 

####### Compile

build/bluetoothManager.o: src/interface/bluetoothManager.cpp src/interface/bluetoothManager.hpp \
		src/interface/bluetoothConnectThread.hpp \
		src/interface/bluetoothSearchThread.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/bluetoothManager.o src/interface/bluetoothManager.cpp

build/bluetoothConnectThread.o: src/interface/bluetoothConnectThread.cpp src/interface/bluetoothConnectThread.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/bluetoothConnectThread.o src/interface/bluetoothConnectThread.cpp

build/bluetoothSearchThread.o: src/interface/bluetoothSearchThread.cpp src/interface/bluetoothSearchThread.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/bluetoothSearchThread.o src/interface/bluetoothSearchThread.cpp

build/bluetoothItem.o: src/interface/bluetoothItem.cpp src/interface/bluetoothItem.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/bluetoothItem.o src/interface/bluetoothItem.cpp

build/main.o: src/interface/main.cpp src/eeg/dummy/dummyHS.hpp \
		src/eeg/eegHeadset.hpp \
		src/eeg/dummy/dummyGenerator.hpp \
		src/eeg/brainlink/brainlinkHS.hpp \
		src/eeg/openBCI/openBCIHS.hpp \
		src/eeg/openBCI/openBCISerial.h \
		src/eeg/openBCI/openBCIParser.h \
		src/util/eeg/headsetManager.hpp \
		src/util/eeg/eegManager.hpp \
		src/util/eeg/eegData.hpp \
		src/eeg/openBCI/openBCIGenerator.hpp \
		src/interface/eeg-app/eegappmenu.h \
		src/interface/bluetoothConnectThread.hpp \
		src/fft/fftCalc.hpp \
		src/eeg/muse/museHS.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/main.o src/interface/main.cpp

build/eegHeadset.o: src/eeg/eegHeadset.cpp src/eeg/eegHeadset.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/eegHeadset.o src/eeg/eegHeadset.cpp

build/brainlinkParser.o: src/eeg/brainlink/brainlinkParser.cpp src/util/eeg/headsetManager.hpp \
		src/util/eeg/eegManager.hpp \
		src/util/eeg/eegData.hpp \
		src/eeg/eegHeadset.hpp \
		src/eeg/brainlink/eeg.h \
		src/eeg/brainlink/brainlinkParser.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/brainlinkParser.o src/eeg/brainlink/brainlinkParser.cpp

build/brainlinkHS.o: src/eeg/brainlink/brainlinkHS.cpp src/eeg/brainlink/brainlinkHS.hpp \
		src/eeg/eegHeadset.hpp \
		src/eeg/brainlink/brainlinkSerial.cpp \
		src/eeg/brainlink/eeg.h \
		src/eeg/brainlink/brainlinkSerial.h \
		src/eeg/brainlink/brainlinkParser.h \
		src/util/eeg/headsetManager.hpp \
		src/util/eeg/eegManager.hpp \
		src/util/eeg/eegData.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/brainlinkHS.o src/eeg/brainlink/brainlinkHS.cpp

build/dummyHS.o: src/eeg/dummy/dummyHS.cpp src/eeg/dummy/dummyHS.hpp \
		src/eeg/eegHeadset.hpp \
		src/eeg/dummy/dummyGenerator.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/dummyHS.o src/eeg/dummy/dummyHS.cpp

build/dummyGenerator.o: src/eeg/dummy/dummyGenerator.cpp src/eeg/dummy/dummyGenerator.hpp \
		src/util/eeg/headsetManager.hpp \
		src/util/eeg/eegManager.hpp \
		src/util/eeg/eegData.hpp \
		src/eeg/eegHeadset.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/dummyGenerator.o src/eeg/dummy/dummyGenerator.cpp

build/eegData.o: src/util/eeg/eegData.cpp src/util/eeg/eegData.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/eegData.o src/util/eeg/eegData.cpp

build/eegManager.o: src/util/eeg/eegManager.cpp src/util/eeg/eegManager.hpp \
		src/util/eeg/eegData.hpp \
		src/eeg/eegHeadset.hpp \
		src/util/eeg/headsetManager.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/eegManager.o src/util/eeg/eegManager.cpp

build/headsetManager.o: src/util/eeg/headsetManager.cpp src/util/eeg/headsetManager.hpp \
		src/util/eeg/eegManager.hpp \
		src/util/eeg/eegData.hpp \
		src/eeg/eegHeadset.hpp \
		src/eeg/brainlink/brainlinkHS.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/headsetManager.o src/util/eeg/headsetManager.cpp

build/eegappmenu.o: src/interface/eeg-app/eegappmenu.cpp src/interface/eeg-app/eegappmenu.h \
		src/../build/ui_eegappmenu.h \
		src/util/eeg/eegManager.hpp \
		src/util/eeg/eegData.hpp \
		src/eeg/eegHeadset.hpp \
		src/eeg/dummy/dummyHS.hpp \
		src/eeg/dummy/dummyGenerator.hpp \
		src/interface/eeg-app/calibratewindow.h \
		src/interface/eeg-app/applicationwindow.h \
		src/interface/eeg-app/settingswindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/eegappmenu.o src/interface/eeg-app/eegappmenu.cpp

build/calibratewindow.o: src/interface/eeg-app/calibratewindow.cpp src/interface/eeg-app/calibratewindow.h \
		src/util/eeg/eegData.hpp \
		src/../build/ui_calibratewindow.h \
		src/interface/eeg-app/calibrationthread.hpp \
		src/interface/eeg-app/eegappmenu.h \
		src/util/eeg/eegManager.hpp \
		src/eeg/eegHeadset.hpp \
		src/eeg/dummy/dummyHS.hpp \
		src/eeg/dummy/dummyGenerator.hpp \
		src/eeg/brainlink/brainlinkHS.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/calibratewindow.o src/interface/eeg-app/calibratewindow.cpp

build/applicationwindow.o: src/interface/eeg-app/applicationwindow.cpp src/interface/eeg-app/applicationwindow.h \
		src/../build/ui_applicationwindow.h \
		src/interface/eeg-app/eegappmenu.h \
		src/interface/eeg-app/eegdisplaywindow.h \
		src/interface/eeg-app/eegdisplaydialog.h \
		src/util/eeg/eegManager.hpp \
		src/util/eeg/eegData.hpp \
		src/eeg/eegHeadset.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/applicationwindow.o src/interface/eeg-app/applicationwindow.cpp

build/settingswindow.o: src/interface/eeg-app/settingswindow.cpp src/interface/eeg-app/settingswindow.h \
		src/../build/ui_settingswindow.h \
		src/interface/eeg-app/eegappmenu.h \
		src/interface/bluetoothSearchThread.hpp \
		src/interface/bluetoothItem.hpp \
		src/interface/eeg-app/device.h \
		src/interface/bluetoothConnectThread.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/settingswindow.o src/interface/eeg-app/settingswindow.cpp

build/calibrationthread.o: src/interface/eeg-app/calibrationthread.cpp src/interface/eeg-app/calibrationthread.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/calibrationthread.o src/interface/eeg-app/calibrationthread.cpp

build/device.o: src/interface/eeg-app/device.cpp src/interface/eeg-app/device.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/device.o src/interface/eeg-app/device.cpp

build/eegdisplaywindow.o: src/interface/eeg-app/eegdisplaywindow.cpp src/interface/eeg-app/eegdisplaywindow.h \
		src/../build/ui_eegdisplaywindow.h \
		build/qcustomplot.h \
		src/interface/eeg-app/qcustomplot.h \
		src/util/eeg/eegManager.hpp \
		src/util/eeg/eegData.hpp \
		src/eeg/eegHeadset.hpp \
		src/eeg/dummy/dummyHS.hpp \
		src/eeg/dummy/dummyGenerator.hpp \
		src/eeg/brainlink/brainlinkHS.hpp \
		src/eeg/muse/museHS.hpp \
		src/eeg/openBCI/openBCIHS.hpp \
		src/eeg/openBCI/openBCISerial.h \
		src/eeg/openBCI/openBCIParser.h \
		src/util/eeg/headsetManager.hpp \
		src/eeg/openBCI/openBCIGenerator.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/eegdisplaywindow.o src/interface/eeg-app/eegdisplaywindow.cpp

build/qcustomplot.o: src/interface/eeg-app/qcustomplot.cpp build/qcustomplot.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/qcustomplot.o src/interface/eeg-app/qcustomplot.cpp

build/museSerial.o: src/eeg/muse/museSerial.cpp src/eeg/muse/eeg.h \
		src/eeg/muse/museSerial.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/museSerial.o src/eeg/muse/museSerial.cpp

build/museParser.o: src/eeg/muse/museParser.cpp src/util/eeg/headsetManager.hpp \
		src/util/eeg/eegManager.hpp \
		src/util/eeg/eegData.hpp \
		src/eeg/eegHeadset.hpp \
		src/eeg/muse/eeg.h \
		src/eeg/muse/museParser.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/museParser.o src/eeg/muse/museParser.cpp

build/museHS.o: src/eeg/muse/museHS.cpp src/eeg/muse/museHS.hpp \
		src/eeg/eegHeadset.hpp \
		src/eeg/muse/museSerial.h \
		src/eeg/muse/museParser.h \
		src/eeg/muse/eeg.h \
		src/util/eeg/headsetManager.hpp \
		src/util/eeg/eegManager.hpp \
		src/util/eeg/eegData.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/museHS.o src/eeg/muse/museHS.cpp

build/openBCIHS.o: src/eeg/openBCI/openBCIHS.cpp src/eeg/openBCI/openBCIHS.hpp \
		src/eeg/openBCI/openBCISerial.h \
		src/eeg/openBCI/openBCIParser.h \
		src/util/eeg/headsetManager.hpp \
		src/util/eeg/eegManager.hpp \
		src/util/eeg/eegData.hpp \
		src/eeg/eegHeadset.hpp \
		src/eeg/openBCI/openBCIGenerator.hpp \
		src/eeg/openBCI/eeg.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/openBCIHS.o src/eeg/openBCI/openBCIHS.cpp

build/eegdisplaydialog.o: src/interface/eeg-app/eegdisplaydialog.cpp src/interface/eeg-app/eegdisplaydialog.h \
		src/util/eeg/eegManager.hpp \
		src/util/eeg/eegData.hpp \
		src/eeg/eegHeadset.hpp \
		build/ui_eegdisplaydialog.h \
		src/eeg/dummy/dummyHS.hpp \
		src/eeg/dummy/dummyGenerator.hpp \
		src/eeg/brainlink/brainlinkHS.hpp \
		src/eeg/muse/museHS.hpp \
		src/eeg/openBCI/openBCIHS.hpp \
		src/eeg/openBCI/openBCISerial.h \
		src/eeg/openBCI/openBCIParser.h \
		src/util/eeg/headsetManager.hpp \
		src/eeg/openBCI/openBCIGenerator.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/eegdisplaydialog.o src/interface/eeg-app/eegdisplaydialog.cpp

build/openBCIGenerator.o: src/eeg/openBCI/openBCIGenerator.cpp src/eeg/openBCI/openBCIGenerator.hpp \
		src/eeg/eegHeadset.hpp \
		src/util/eeg/headsetManager.hpp \
		src/util/eeg/eegManager.hpp \
		src/util/eeg/eegData.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/openBCIGenerator.o src/eeg/openBCI/openBCIGenerator.cpp

build/serial.o: src/fft/serial.c src/fft/eeg.h
	$(CC) -c $(CFLAGS) $(INCPATH) -o build/serial.o src/fft/serial.c

build/parser.o: src/fft/parser.c src/fft/eeg.h
	$(CC) -c $(CFLAGS) $(INCPATH) -o build/parser.o src/fft/parser.c

build/new_s.o: src/fft/new_s.c 
	$(CC) -c $(CFLAGS) $(INCPATH) -o build/new_s.o src/fft/new_s.c

build/fft.o: src/fft/fft.c 
	$(CC) -c $(CFLAGS) $(INCPATH) -o build/fft.o src/fft/fft.c

build/drone.o: src/fft/drone.c src/fft/drone.h
	$(CC) -c $(CFLAGS) $(INCPATH) -o build/drone.o src/fft/drone.c

build/dft.o: src/fft/dft.c src/fft/eeg.h
	$(CC) -c $(CFLAGS) $(INCPATH) -o build/dft.o src/fft/dft.c

build/fftCalc.o: src/fft/fftCalc.cpp src/fft/fftCalc.hpp \
		src/eeg/eegHeadset.hpp \
		src/eeg/dummy/dummyHS.hpp \
		src/eeg/dummy/dummyGenerator.hpp \
		src/eeg/muse/museHS.hpp \
		src/eeg/openBCI/openBCIHS.hpp \
		src/eeg/openBCI/openBCISerial.h \
		src/eeg/openBCI/openBCIParser.h \
		src/util/eeg/headsetManager.hpp \
		src/util/eeg/eegManager.hpp \
		src/util/eeg/eegData.hpp \
		src/eeg/openBCI/openBCIGenerator.hpp \
		src/fft/eeg.h \
		src/fft/drone.h \
		src/interface/eeg-app/eegdisplaydialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/fftCalc.o src/fft/fftCalc.cpp

build/openBCISerial.o: src/eeg/openBCI/openBCISerial.cpp src/eeg/openBCI/eeg.h \
		src/eeg/openBCI/openBCISerial.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/openBCISerial.o src/eeg/openBCI/openBCISerial.cpp

build/openBCIParser.o: src/eeg/openBCI/openBCIParser.cpp src/util/eeg/headsetManager.hpp \
		src/util/eeg/eegManager.hpp \
		src/util/eeg/eegData.hpp \
		src/eeg/eegHeadset.hpp \
		src/eeg/openBCI/eeg.h \
		src/eeg/openBCI/openBCIParser.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/openBCIParser.o src/eeg/openBCI/openBCIParser.cpp

build/moc_bluetoothManager.o: build/moc_bluetoothManager.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_bluetoothManager.o build/moc_bluetoothManager.cpp

build/moc_bluetoothConnectThread.o: build/moc_bluetoothConnectThread.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_bluetoothConnectThread.o build/moc_bluetoothConnectThread.cpp

build/moc_bluetoothSearchThread.o: build/moc_bluetoothSearchThread.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_bluetoothSearchThread.o build/moc_bluetoothSearchThread.cpp

build/moc_bluetoothItem.o: build/moc_bluetoothItem.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_bluetoothItem.o build/moc_bluetoothItem.cpp

build/moc_dummyGenerator.o: build/moc_dummyGenerator.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_dummyGenerator.o build/moc_dummyGenerator.cpp

build/moc_eegData.o: build/moc_eegData.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_eegData.o build/moc_eegData.cpp

build/moc_eegManager.o: build/moc_eegManager.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_eegManager.o build/moc_eegManager.cpp

build/moc_eegappmenu.o: build/moc_eegappmenu.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_eegappmenu.o build/moc_eegappmenu.cpp

build/moc_calibratewindow.o: build/moc_calibratewindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_calibratewindow.o build/moc_calibratewindow.cpp

build/moc_applicationwindow.o: build/moc_applicationwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_applicationwindow.o build/moc_applicationwindow.cpp

build/moc_settingswindow.o: build/moc_settingswindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_settingswindow.o build/moc_settingswindow.cpp

build/moc_calibrationthread.o: build/moc_calibrationthread.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_calibrationthread.o build/moc_calibrationthread.cpp

build/moc_device.o: build/moc_device.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_device.o build/moc_device.cpp

build/moc_eegdisplaywindow.o: build/moc_eegdisplaywindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_eegdisplaywindow.o build/moc_eegdisplaywindow.cpp

build/moc_qcustomplot.o: build/moc_qcustomplot.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_qcustomplot.o build/moc_qcustomplot.cpp

build/moc_openBCIHS.o: build/moc_openBCIHS.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_openBCIHS.o build/moc_openBCIHS.cpp

build/moc_eegdisplaydialog.o: build/moc_eegdisplaydialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_eegdisplaydialog.o build/moc_eegdisplaydialog.cpp

build/moc_openBCIGenerator.o: build/moc_openBCIGenerator.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_openBCIGenerator.o build/moc_openBCIGenerator.cpp

build/moc_fftCalc.o: build/moc_fftCalc.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_fftCalc.o build/moc_fftCalc.cpp

build/qrc_ImageResources.o: build/qrc_ImageResources.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/qrc_ImageResources.o build/qrc_ImageResources.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:


#############################################################################
# Makefile for building: e3prj3
# Generated by qmake (2.01a) (Qt 4.8.0) on: Mon May 28 15:36:42 2012
# Project:  e3prj3.pro
# Template: app
# Command: /home/stud/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/i686-linux/usr/bin/qmake2 CXXFLAGS+=TARGET -o Makefile e3prj3.pro
#############################################################################

####### Compiler, tools and options

CC            = $(OE_QMAKE_CC)
CXX           = $(OE_QMAKE_CXX)
DEFINES       = -DQT_NO_DEBUG -DQT_SQL_LIB -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -pipe $(OE_QMAKE_CFLAGS) -O2 -Wall -W -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -pipe -pipe $(OE_QMAKE_CFLAGS) $(OE_QMAKE_CXXFLAGS) -O2 -O2 -Wall -W -Wall -W -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I../../../../stud/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/i686-linux/usr/share/qt4/mkspecs/linux-oe-g++ -I. -I$(OE_QMAKE_INCDIR_QT)/QtCore -I$(OE_QMAKE_INCDIR_QT)/QtGui -I$(OE_QMAKE_INCDIR_QT)/QtSql -I$(OE_QMAKE_INCDIR_QT) -I. -I.
LINK          = $(OE_QMAKE_LINK)
LFLAGS        = $(OE_QMAKE_LDFLAGS) -Wl,-rpath-link,$(OE_QMAKE_LIBDIR_QT)
LIBS          = $(SUBLIBS)  -L$(OE_QMAKE_LIBDIR_QT) -lboost_system -lboost_thread -lQtSql -lQtGui -lQtNetwork -lQtCore -lpthread 
AR            = $(OE_QMAKE_AR) cqs
RANLIB        = 
QMAKE         = /home/stud/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/i686-linux/usr/bin/qmake2
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = $(OE_QMAKE_STRIP)
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

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		mainwindow.cpp \
		carddatabase.cpp \
		rfid.cpp \
		QAsyncSerial.cpp \
		AsyncSerial.cpp \
		psoc.cpp moc_mainwindow.cpp \
		moc_carddatabase.cpp \
		moc_rfid.cpp \
		moc_QAsyncSerial.cpp \
		moc_psoc.cpp
OBJECTS       = main.o \
		mainwindow.o \
		carddatabase.o \
		rfid.o \
		QAsyncSerial.o \
		AsyncSerial.o \
		psoc.o \
		moc_mainwindow.o \
		moc_carddatabase.o \
		moc_rfid.o \
		moc_QAsyncSerial.o \
		moc_psoc.o
DIST          = ../../../../stud/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/i686-linux/usr/share/qt4/mkspecs/common/unix.conf \
		../../../../stud/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/i686-linux/usr/share/qt4/mkspecs/common/linux.conf \
		../../../../stud/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/i686-linux/usr/share/qt4/mkspecs/common/gcc-base.conf \
		../../../../stud/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/i686-linux/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		../../../../stud/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/i686-linux/usr/share/qt4/mkspecs/common/g++-unix.conf \
		../../../../stud/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/i686-linux/usr/share/qt4/mkspecs/features/qt_functions.prf \
		../../../../stud/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/i686-linux/usr/share/qt4/mkspecs/features/qt_config.prf \
		../../../../stud/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/i686-linux/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		../../../../stud/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/i686-linux/usr/share/qt4/mkspecs/features/default_pre.prf \
		../../../../stud/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/i686-linux/usr/share/qt4/mkspecs/features/release.prf \
		../../../../stud/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/i686-linux/usr/share/qt4/mkspecs/features/default_post.prf \
		../../../../stud/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/i686-linux/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		../../../../stud/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/i686-linux/usr/share/qt4/mkspecs/features/warn_on.prf \
		../../../../stud/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/i686-linux/usr/share/qt4/mkspecs/features/qt.prf \
		../../../../stud/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/i686-linux/usr/share/qt4/mkspecs/features/unix/thread.prf \
		../../../../stud/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/i686-linux/usr/share/qt4/mkspecs/features/moc.prf \
		../../../../stud/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/i686-linux/usr/share/qt4/mkspecs/features/resources.prf \
		../../../../stud/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/i686-linux/usr/share/qt4/mkspecs/features/uic.prf \
		../../../../stud/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/i686-linux/usr/share/qt4/mkspecs/features/yacc.prf \
		../../../../stud/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/i686-linux/usr/share/qt4/mkspecs/features/lex.prf \
		../../../../stud/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/i686-linux/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		e3prj3.pro
QMAKE_TARGET  = e3prj3
DESTDIR       = 
TARGET        = e3prj3

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

$(TARGET): ui_mainwindow.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: e3prj3.pro  ../../../../stud/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/i686-linux/usr/share/qt4/mkspecs/linux-oe-g++/qmake.conf ../../../../stud/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/i686-linux/usr/share/qt4/mkspecs/common/unix.conf \
		../../../../stud/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/i686-linux/usr/share/qt4/mkspecs/common/linux.conf \
		../../../../stud/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/i686-linux/usr/share/qt4/mkspecs/common/gcc-base.conf \
		../../../../stud/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/i686-linux/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		../../../../stud/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/i686-linux/usr/share/qt4/mkspecs/common/g++-unix.conf \
		../../../../stud/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/i686-linux/usr/share/qt4/mkspecs/features/qt_functions.prf \
		../../../../stud/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/i686-linux/usr/share/qt4/mkspecs/features/qt_config.prf \
		../../../../stud/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/i686-linux/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		../../../../stud/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/i686-linux/usr/share/qt4/mkspecs/features/default_pre.prf \
		../../../../stud/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/i686-linux/usr/share/qt4/mkspecs/features/release.prf \
		../../../../stud/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/i686-linux/usr/share/qt4/mkspecs/features/default_post.prf \
		../../../../stud/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/i686-linux/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		../../../../stud/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/i686-linux/usr/share/qt4/mkspecs/features/warn_on.prf \
		../../../../stud/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/i686-linux/usr/share/qt4/mkspecs/features/qt.prf \
		../../../../stud/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/i686-linux/usr/share/qt4/mkspecs/features/unix/thread.prf \
		../../../../stud/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/i686-linux/usr/share/qt4/mkspecs/features/moc.prf \
		../../../../stud/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/i686-linux/usr/share/qt4/mkspecs/features/resources.prf \
		../../../../stud/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/i686-linux/usr/share/qt4/mkspecs/features/uic.prf \
		../../../../stud/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/i686-linux/usr/share/qt4/mkspecs/features/yacc.prf \
		../../../../stud/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/i686-linux/usr/share/qt4/mkspecs/features/lex.prf \
		../../../../stud/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/i686-linux/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/home/stud/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/beagleboard/usr/lib/libQtSql.prl \
		/home/stud/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/beagleboard/usr/lib/libQtCore.prl \
		/home/stud/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/beagleboard/usr/lib/libQtGui.prl \
		/home/stud/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/beagleboard/usr/lib/libQtNetwork.prl
	$(QMAKE) CXXFLAGS+=TARGET -o Makefile e3prj3.pro
../../../../stud/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/i686-linux/usr/share/qt4/mkspecs/common/unix.conf:
../../../../stud/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/i686-linux/usr/share/qt4/mkspecs/common/linux.conf:
../../../../stud/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/i686-linux/usr/share/qt4/mkspecs/common/gcc-base.conf:
../../../../stud/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/i686-linux/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
../../../../stud/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/i686-linux/usr/share/qt4/mkspecs/common/g++-unix.conf:
../../../../stud/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/i686-linux/usr/share/qt4/mkspecs/features/qt_functions.prf:
../../../../stud/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/i686-linux/usr/share/qt4/mkspecs/features/qt_config.prf:
../../../../stud/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/i686-linux/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
../../../../stud/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/i686-linux/usr/share/qt4/mkspecs/features/default_pre.prf:
../../../../stud/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/i686-linux/usr/share/qt4/mkspecs/features/release.prf:
../../../../stud/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/i686-linux/usr/share/qt4/mkspecs/features/default_post.prf:
../../../../stud/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/i686-linux/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf:
../../../../stud/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/i686-linux/usr/share/qt4/mkspecs/features/warn_on.prf:
../../../../stud/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/i686-linux/usr/share/qt4/mkspecs/features/qt.prf:
../../../../stud/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/i686-linux/usr/share/qt4/mkspecs/features/unix/thread.prf:
../../../../stud/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/i686-linux/usr/share/qt4/mkspecs/features/moc.prf:
../../../../stud/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/i686-linux/usr/share/qt4/mkspecs/features/resources.prf:
../../../../stud/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/i686-linux/usr/share/qt4/mkspecs/features/uic.prf:
../../../../stud/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/i686-linux/usr/share/qt4/mkspecs/features/yacc.prf:
../../../../stud/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/i686-linux/usr/share/qt4/mkspecs/features/lex.prf:
../../../../stud/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/i686-linux/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/home/stud/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/beagleboard/usr/lib/libQtSql.prl:
/home/stud/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/beagleboard/usr/lib/libQtCore.prl:
/home/stud/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/beagleboard/usr/lib/libQtGui.prl:
/home/stud/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/beagleboard/usr/lib/libQtNetwork.prl:
qmake:  FORCE
	@$(QMAKE) CXXFLAGS+=TARGET -o Makefile e3prj3.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/e3prj31.0.0 || $(MKDIR) .tmp/e3prj31.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/e3prj31.0.0/ && $(COPY_FILE) --parents mainwindow.h carddatabase.h rfid.h QAsyncSerial.h AsyncSerial.h psoc.h .tmp/e3prj31.0.0/ && $(COPY_FILE) --parents main.cpp mainwindow.cpp carddatabase.cpp rfid.cpp QAsyncSerial.cpp AsyncSerial.cpp psoc.cpp .tmp/e3prj31.0.0/ && $(COPY_FILE) --parents mainwindow.ui .tmp/e3prj31.0.0/ && (cd `dirname .tmp/e3prj31.0.0` && $(TAR) e3prj31.0.0.tar e3prj31.0.0 && $(COMPRESS) e3prj31.0.0.tar) && $(MOVE) `dirname .tmp/e3prj31.0.0`/e3prj31.0.0.tar.gz . && $(DEL_FILE) -r .tmp/e3prj31.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

$(OE_QMAKE_MOC):
	(cd $(QTDIR)/src/tools/moc && $(MAKE))

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_mainwindow.cpp moc_carddatabase.cpp moc_rfid.cpp moc_QAsyncSerial.cpp moc_psoc.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_mainwindow.cpp moc_carddatabase.cpp moc_rfid.cpp moc_QAsyncSerial.cpp moc_psoc.cpp
moc_mainwindow.cpp: rfid.h \
		QAsyncSerial.h \
		psoc.h \
		mainwindow.h \
		$(OE_QMAKE_MOC)
	$(OE_QMAKE_MOC) $(DEFINES) $(INCPATH) mainwindow.h -o moc_mainwindow.cpp

moc_carddatabase.cpp: carddatabase.h \
		$(OE_QMAKE_MOC)
	$(OE_QMAKE_MOC) $(DEFINES) $(INCPATH) carddatabase.h -o moc_carddatabase.cpp

moc_rfid.cpp: QAsyncSerial.h \
		rfid.h \
		$(OE_QMAKE_MOC)
	$(OE_QMAKE_MOC) $(DEFINES) $(INCPATH) rfid.h -o moc_rfid.cpp

moc_QAsyncSerial.cpp: QAsyncSerial.h \
		$(OE_QMAKE_MOC)
	$(OE_QMAKE_MOC) $(DEFINES) $(INCPATH) QAsyncSerial.h -o moc_QAsyncSerial.cpp

moc_psoc.cpp: psoc.h \
		$(OE_QMAKE_MOC)
	$(OE_QMAKE_MOC) $(DEFINES) $(INCPATH) psoc.h -o moc_psoc.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_mainwindow.h
compiler_uic_clean:
	-$(DEL_FILE) ui_mainwindow.h
ui_mainwindow.h: mainwindow.ui
	$(OE_QMAKE_UIC) mainwindow.ui -o ui_mainwindow.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

main.o: main.cpp mainwindow.h \
		rfid.h \
		QAsyncSerial.h \
		psoc.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

mainwindow.o: mainwindow.cpp mainwindow.h \
		rfid.h \
		QAsyncSerial.h \
		psoc.h \
		carddatabase.h \
		ui_mainwindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mainwindow.o mainwindow.cpp

carddatabase.o: carddatabase.cpp carddatabase.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o carddatabase.o carddatabase.cpp

rfid.o: rfid.cpp rfid.h \
		QAsyncSerial.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o rfid.o rfid.cpp

QAsyncSerial.o: QAsyncSerial.cpp QAsyncSerial.h \
		AsyncSerial.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o QAsyncSerial.o QAsyncSerial.cpp

AsyncSerial.o: AsyncSerial.cpp AsyncSerial.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o AsyncSerial.o AsyncSerial.cpp

psoc.o: psoc.cpp psoc.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o psoc.o psoc.cpp

moc_mainwindow.o: moc_mainwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mainwindow.o moc_mainwindow.cpp

moc_carddatabase.o: moc_carddatabase.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_carddatabase.o moc_carddatabase.cpp

moc_rfid.o: moc_rfid.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_rfid.o moc_rfid.cpp

moc_QAsyncSerial.o: moc_QAsyncSerial.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_QAsyncSerial.o moc_QAsyncSerial.cpp

moc_psoc.o: moc_psoc.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_psoc.o moc_psoc.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:


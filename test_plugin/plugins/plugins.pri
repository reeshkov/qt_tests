QMAKE_CXXFLAGS_DEBUG += -Wno-psabi # supress warnings flood

#INCLUDEPATH    += ../../loader
#HEADERS += ../../loader/plugininterface.h

!greaterThan(QT_MAJOR_VERSION, 4){
  defineReplace(getPathTool){
    TOOLEXIST = $$system(readlink --version; echo $?)
    contains(TOOLEXIST, 0){
        return (readlink -m)
    }

    TOOLEXIST = $$system(realpath --version; echo $?)
    contains(TOOLEXIST, 0){
        warning("path must be exists")
        return (realpath)
    }

    #message($$TOOLEXIST)
    return (false)
  }

  # absolute_path
  defineReplace(absolute_path){
    FILE=$$1
    BASEPATH=$$2
    isEmpty(BASEPATH){
      BASEPATH=$$dirname(FILE)
    }
    isEmpty(BASEPATH){
      BASEPATH=.
    }
    GETFULLPATH = $$getPathTool()
    !contains(GETFULLPATH, false){
      ABSPATH=$$system($$GETFULLPATH $$FILE)
      #message( ABSPATHsys: $$ABSPATH)
    }
    isEmpty(ABSPATH){
      ABSPATH=$$BASEPATH/$$FILE
      #message( ABSPATHempty: $$ABSPATH)
    }
    return ($$ABSPATH)
  }

  # relative_path
  defineReplace(relative_path){
    FILE=$$1
    BASEPATH=$$2
    RELPATH = $$FILE
    RELPATH ~= s|$$BASEPATH||
    RELPATH ~= s|^\\/||
    #message("[relative_path]" $$RELPATH )
    return($$RELPATH)
  }
}

#exists(../loader/plugininterface.h){
#  INCLUDEPATH    *= $$absolute_path("../loader/")
#  HEADERS += $$absolute_path("../loader/")/plugininterface.h
#  message(Plugins $$TARGET found header $$_PRO_FILE_ $$escape_expand(\\r)$$INCLUDEPATH $$HEADERS )
#}else{
#  message(Plugins $$TARGET cant find header $$_PRO_FILE_ $$system($$GETFULLPATH .) )
#}
#message(Plugins $$TARGET headers:$$join(HEADERS, $$CR, $$CR, $$CR) )


DEVICE = $$QMAKE_QMAKE
DEVICE ~= s|.*am335x.*|AM335X|
DEVICE ~= s|.*NESO.*|NESO|
DEVICE ~= s|.*usr/lib/i386-linux-gnu.*|PC|
DEVICE ~= s|.*usr/local/Trolltech.*|PC|

contains( SUPPORT_DEVICES, $$DEVICE ){
    message($$TARGET  device $$DEVICE)
    DEFINES += TARGET_DEVICE=\\\"$$DEVICE\\\"
    DEFINES += ISPTMPLUGIN

    equals(DEVICE, NESO){
        QMAKE_CXXFLAGS_DEBUG -= -Wno-psabi #unsupported option in compiler
        target.path = /home/plugins
        INSTALLS += target
        DESTDIR = ../
    }
    equals(DEVICE, AM335X){
        target.path = /home/root/plugins
        INSTALLS += target
        DESTDIR = ../
    }
    equals(DEVICE, PC){
        win32:TARGET = ../../$$TARGET
        unix:TARGET = ../$$TARGET
        target.path = $$OUT_PWD/..
        INSTALLS += target
    }
}else{
    error(Device $$DEVICE not supported, please change the file $$TARGET.pro)
}

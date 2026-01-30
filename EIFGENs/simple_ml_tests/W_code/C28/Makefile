INCLUDE_PATH =  -I"C:\Program Files\Eiffel Software\EiffelStudio 25.02 Standard\library\time\spec\include"
SHELL = \bin\sh
CC = cl
CPP = cl
CFLAGS = -Od -MT -w -nologo -D_WIN32_WINNT=0x0500 -DWINVER=0x0500 -D_CRT_SECURE_NO_DEPRECATE -D_UNICODE -DUNICODE -DWIN32_LEAN_AND_MEAN  -DEIF_THREADS  -DWORKBENCH -I"C:\Program Files\Eiffel Software\EiffelStudio 25.02 Standard\studio\spec\win64\include" -I. $(INCLUDE_PATH)
CPPFLAGS = -Od -MT -w -nologo -D_WIN32_WINNT=0x0500 -DWINVER=0x0500 -D_CRT_SECURE_NO_DEPRECATE -D_UNICODE -DUNICODE -DWIN32_LEAN_AND_MEAN  -DEIF_THREADS  -DWORKBENCH -I"C:\Program Files\Eiffel Software\EiffelStudio 25.02 Standard\studio\spec\win64\include" -I. $(INCLUDE_PATH)
LDFLAGS = -STACK:5000000 -NODEFAULTLIB:libc
CCLDFLAGS = -STACK:5000000 -NODEFAULTLIB:libc  -SUBSYSTEM:WINDOWS
LDSHAREDFLAGS =  -dll -incremental:no -NODEFAULTLIB:libc
EIFLIB = "C:\Program Files\Eiffel Software\EiffelStudio 25.02 Standard\studio\spec\win64\lib\msc_vc140\mtwkbench.lib"
EIFTEMPLATES = C:\Program Files\Eiffel Software\EiffelStudio 25.02 Standard\studio\config\win64\templates
LIBS = 
MAKE = nmake -s -nologo
AR = 
LD = 
MKDEP =   --
MV = copy
CP = copy
RANLIB = echo
RM = del
FILE_EXIST = if exist
RMDIR = rd
X2C = "C:\Program Files\Eiffel Software\EiffelStudio 25.02 Standard\studio\spec\win64\bin\x2c.exe"
SHAREDLINK = link
SHAREDLIBS = USER32.lib WS2_32.lib ADVAPI32.lib GDI32.lib SHELL32.lib MSIMG32.lib \
	COMDLG32.lib UUID.lib OLE32.lib OLEAUT32.lib COMCTL32.lib MPR.LIB SHLWAPI.LIB WINSPOOL.LIB 
SHARED_SUFFIX = .dll
COMMAND_MAKEFILE = 
START_TEST = if not exist finished 
END_TEST =  
CREATE_TEST = echo "finished" >> finished 
SYSTEM_IN_DYNAMIC_LIB = simple_ml.dll 

.SUFFIXES:.cpp .obj 

.c.obj:
	$(CC) $(CFLAGS) -c $<

.cpp.obj:
	$(CPP) $(CPPFLAGS) -c $<

OBJECTS = big_file_C28_c.obj 

OLDOBJECTS =  sp895.obj sp895d.obj ar904.obj ar904d.obj sp896.obj sp896d.obj na917.obj na917d.obj \
	re899.obj re899d.obj it902.obj it902d.obj li907.obj li907d.obj it901.obj it901d.obj \
	ar918.obj ar918d.obj ar919.obj ar919d.obj re893.obj re893d.obj in905.obj in905d.obj \
	to916.obj to916d.obj li891.obj li891d.obj ge903.obj ge903d.obj re897.obj re897d.obj \
	in900.obj in900d.obj cu908.obj cu908d.obj tr915.obj tr915d.obj se923.obj se923d.obj \
	ar892.obj ar892d.obj dy920.obj dy920d.obj bo894.obj bo894d.obj ta906.obj ta906d.obj \
	fi910.obj fi910d.obj ch922.obj ch922d.obj ty898.obj ty898d.obj ac912.obj ac912d.obj \
	co909.obj co909d.obj dy921.obj dy921d.obj ba913.obj ba913d.obj bo911.obj bo911d.obj \
	co914.obj co914d.obj 

all::  Cobj28.lib

Cobj28.lib: $(OBJECTS) Makefile
	if exist $@ $(RM) $@
	lib -nologo -OUT:$@ $(OBJECTS)
	$(CREATE_TEST)
	$(RM) $(OBJECTS)


clean: local_clean
clobber: local_clobber

local_clean::
	$(RM) core finished *.o

local_clobber:: local_clean
	$(RM) Makefile


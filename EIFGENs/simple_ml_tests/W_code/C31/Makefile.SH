case $CONFIG in
'')
	if test ! -f ../config.sh; then
		(echo "Can't find ../config.sh."; exit 1)
	fi 2>/dev/null
	. ../config.sh
	;;
esac
case "$O" in
*/*) cd `expr X$0 : 'X\(.*\)/'` ;;
esac
echo "Compiling C code in C31"
$spitshell >Makefile <<!GROK!THIS!
INCLUDE_PATH =  -I"\$(ISE_LIBRARY)\library\time\spec\include"
SHELL = /bin/sh
CC = $cc
CPP = $cpp
CFLAGS = $wkoptimize $mtccflags $large -DWORKBENCH -I"$rt_include" -I. \$(INCLUDE_PATH)
CPPFLAGS = $wkoptimize $mtcppflags $large -DWORKBENCH -I"$rt_include" -I. \$(INCLUDE_PATH)
LDFLAGS = $ldflags
CCLDFLAGS = $ccldflags  $windows_flags
LDSHAREDFLAGS =  $mtldsharedflags
EIFLIB = "$rt_lib/$prefix$mt_prefix$wkeiflib$suffix"
EIFTEMPLATES = $rt_templates
LIBS = $mtlibs
MAKE = $make
AR = $ar
LD = $ld
MKDEP = $mkdep \$(DPFLAGS) --
MV = $mv
CP = $cp
RANLIB = $ranlib
RM = $rm -f
FILE_EXIST = $file_exist
RMDIR = $rmdir
X2C = "$x2c"
SHAREDLINK = $sharedlink
SHAREDLIBS = $sharedlibs
SHARED_SUFFIX = $shared_suffix
COMMAND_MAKEFILE = 
START_TEST = $start_test 
END_TEST = $end_test 
CREATE_TEST = $create_test 
SYSTEM_IN_DYNAMIC_LIB = simple_ml$shared_suffix 
!GROK!THIS!
$spitshell >>Makefile <<'!NO!SUBS!'

.SUFFIXES:.cpp .o

.c.o:
	$(CC) $(CFLAGS) -c $<

.cpp.o:
	$(CPP) $(CPPFLAGS) -c $<

OBJECTS = big_file_C31_c.obj 

OLDOBJECTS =  fu1011.o fu1011d.o dy1021.o dy1021d.o ha1017.o ha1017d.o ta1022.o \
	ta1022d.o ha1018.o ha1018d.o ta1020.o ta1020d.o mm1006.o mm1006d.o \
	mm1010.o mm1010d.o rt993.o rt993d.o rt994.o rt994d.o rt990.o rt990d.o \
	rt991.o rt991d.o rt992.o rt992d.o ta1019.o ta1019d.o st1002.o \
	st1002d.o te1001.o te1001d.o si1000.o si1000d.o as999.o as999d.o \
	re998.o re998d.o si997.o si997d.o si996.o si996d.o si995.o si995d.o \
	mm1004.o mm1004d.o mm1008.o mm1008d.o si1007.o si1007d.o mm1005.o \
	mm1005d.o mm1009.o mm1009d.o mm1003.o mm1003d.o si1012.o si1012d.o \
	si1016.o si1016d.o si1015.o si1015d.o si1014.o si1014d.o si1013.o \
	si1013d.o 

all: Cobj31.o

Cobj31.o: $(OBJECTS) Makefile
	$(LD) $(LDFLAGS) -r -o Cobj31.o $(OBJECTS)
	$(RM) $(OBJECTS)
	$(CREATE_TEST)

clean: local_clean
clobber: local_clobber

local_clean::
	$(RM) core finished *.o

local_clobber:: local_clean
	$(RM) Makefile

!NO!SUBS!
chmod 644 Makefile
$eunicefix Makefile


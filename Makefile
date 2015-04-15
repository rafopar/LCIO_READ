CC              = g++
CC_OBJ_FLAGS    = -c -fPIC
CC_Shared_FLAGS = -shared -Wl,-soname,liblcioread.so
ROOT_CFLAGS     = $(shell root-config --cflags)
ROOT_LIBS       = $(shell root-config --libs)
Link            = ld -r

lcioreadlib:	ECalCluster.o
		$(CC) $(CC_Shared_FLAGS) -olib/liblcioread.so.1.0.1 lib/ECalCluster.o

ECalCluster.o:	include/ECalCluster.hh src/ECalCluster.cc
		$(CC) $(CC_OBJ_FLAGS) -I./include -I$(LCIO)/include -L$(LCIO)/lib -llcio -llcioDict $(ROOT_CFLAGS) $(ROOT_LIBS) src/ECalCluster.cc -o lib/ECalCluster.o

clean:		
		rm -f lib/*

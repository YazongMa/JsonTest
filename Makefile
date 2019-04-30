
#//
#// Copyright (C) 2005
#// Packet Engineering, Inc. All rights reserved.
#//
#// Redistribution and use in source and binary forms, with or without
#// modification is not permitted unless authorized in writing by a duly
#// appointed officer of Packet Engineering, Inc. or its derivatives
#//
#// Description:
#//
#////////////////////////////////////////////////////////////////////////////

TARGETEXE = main.exe

CC = g++

.SUFFIXES: .cpp .h

FLAGS = -g

OBJDIR = ./obj

CREATEOBJDIR = $(shell if [ -d $(OBJDIR) ]; then echo ""; else mkdir -p $(OBJDIR); fi)

LIBS = 

DLIBS = 

#
# objects and targets
#
OBJECTS = $(patsubst %.cpp,$(OBJDIR)/%.o,$(wildcard *.cpp))

#
# Rules for normal comile and link 
#
all:: $(TARGETEXE) 

$(TARGETEXE): $(OBJECTS)
	$(CC) -g -o $@ $^ $(DLIBS) $(LIBS)

$(OBJECTS): $(OBJDIR)/%.o: %.cpp
	$(CREATEOBJDIR)
	$(CC) -c  $(FLAGS) $< -o $@

clean:
	rm -rf $(OBJDIR)/*.o $(TARGETEXE) 

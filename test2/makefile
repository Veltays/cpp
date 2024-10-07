COMPIL=g++  -Wall -I $(OBJCPATH) -I $(SRCPATH) -I $(INCLUDEPATH) -I $(BINPATH)
OBJCPATH = ./Obj
BINPATH = ./bin
SRCPATH = ./src
INCLUDEPATH = ./Include


$(BINPATH)/Test2: $(SRCPATH)/Test2.cpp $(OBJCPATH)/Time.o $(OBJCPATH)/Event.o $(OBJCPATH)/Timing.o
	$(COMPIL) $(SRCPATH)/Test2.cpp $(OBJCPATH)/Event.o $(OBJCPATH)/Time.o $(OBJCPATH)/Timing.o -o $(BINPATH)/Test2

$(OBJCPATH)/Event.o: $(SRCPATH)/Event.cpp $(INCLUDEPATH)/Event.h
	$(COMPIL) $(SRCPATH)/Event.cpp -c -o $(OBJCPATH)/Event.o

$(OBJCPATH)/Time.o: $(SRCPATH)/Time.cpp $(INCLUDEPATH)/Time.h
	$(COMPIL) $(SRCPATH)/Time.cpp -c -o $(OBJCPATH)/Time.o

$(OBJCPATH)/Timing.o : $(SRCPATH)/Timing.cpp $(INCLUDEPATH)/Timing.h
	$(COMPIL) $(SRCPATH)/Timing.cpp -c -o  $(OBJCPATH)/Timing.o

clean:
	rm -f $(OBJCPATH)

clobber:clean
	rm -f $(BINPATH)/Test2


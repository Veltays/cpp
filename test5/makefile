COMPIL=g++  -Wall -I $(OBJCPATH) -I $(SRCPATH) -I $(INCLUDEPATH) -I $(BINPATH)
OBJCPATH = ./Obj
BINPATH = ./bin
SRCPATH = ./src
INCLUDEPATH = ./Include


$(BINPATH)/Test5: $(SRCPATH)/Test5.cpp $(OBJCPATH)/Time.o $(OBJCPATH)/Event.o $(OBJCPATH)/Timing.o $(OBJCPATH)/Schedulable.o $(OBJCPATH)/Professor.o $(OBJCPATH)/Group.o $(OBJCPATH)/Classroom.o
	$(COMPIL) $(SRCPATH)/Test5.cpp $(OBJCPATH)/Event.o $(OBJCPATH)/Time.o $(OBJCPATH)/Timing.o $(OBJCPATH)/Schedulable.o $(OBJCPATH)/Professor.o $(OBJCPATH)/Group.o $(OBJCPATH)/Classroom.o -o $(BINPATH)/Test5

$(OBJCPATH)/Event.o: $(SRCPATH)/Event.cpp $(INCLUDEPATH)/Event.h
	$(COMPIL) $(SRCPATH)/Event.cpp -c -o $(OBJCPATH)/Event.o

$(OBJCPATH)/Time.o: $(SRCPATH)/Time.cpp $(INCLUDEPATH)/Time.h
	$(COMPIL) $(SRCPATH)/Time.cpp -c -o $(OBJCPATH)/Time.o

$(OBJCPATH)/Timing.o : $(SRCPATH)/Timing.cpp $(INCLUDEPATH)/Timing.h
	$(COMPIL) $(SRCPATH)/Timing.cpp -c -o  $(OBJCPATH)/Timing.o

$(OBJCPATH)/Schedulable.o: $(SRCPATH)/Schedulable.cpp $(INCLUDEPATH)/Schedulable.h
	$(COMPIL) $(SRCPATH)/Schedulable.cpp  -c -o $(OBJCPATH)/Schedulable.o

$(OBJCPATH)/Professor.o: $(SRCPATH)/Professor.cpp $(INCLUDEPATH)/Professor.h
	$(COMPIL) $(SRCPATH)/Professor.cpp  -c -o $(OBJCPATH)/Professor.o

$(OBJCPATH)/Classroom.o: $(SRCPATH)/Classroom.cpp $(INCLUDEPATH)/Classroom.h
	$(COMPIL) $(SRCPATH)/Classroom.cpp  -c -o $(OBJCPATH)/Classroom.o	

$(OBJCPATH)/Group.o: $(SRCPATH)/Group.cpp $(INCLUDEPATH)/Group.h
	$(COMPIL) $(SRCPATH)/Group.cpp  -c -o $(OBJCPATH)/Group.o	
clean:
	rm -f $(OBJCPATH)/*.o

clobber: clean
	rm -f $(BINPATH)/Test5


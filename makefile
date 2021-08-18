
program: program.o storing.o dealings.o interface.o functions.o
	gcc $^ -o program

program.o: program.c program.h
	gcc program.c -c -o program.o

storing.o: storing.c storing.h
	gcc storing.c -c -o storing.o

dealings.o: dealings.c dealings.h
	gcc dealings.c -c -o dealings.o

interface.o: interface.c interface.h
	gcc interface.c -c -o interface.o

functions.o: functions.c functions.h
	gcc functions.c -c -o functions.o
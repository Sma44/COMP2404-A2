OPT = -Wall

assignment02: main.o Control.o Course.o CourseArray.o Schedule.o School.o Time.o View.o
	g++ -o assignment02 main.o Control.o Course.o CourseArray.o Schedule.o School.o Time.o View.o

main.o: main.cc Control.h
	g++ $(OPT) -c main.cc 

Control.o: Control.cc Control.h 
	g++ $(OPT) -c Control.cc

Course.o: Course.cc Course.h 
	g++ $(OPT) -c Course.cc 

CourseArray.o: CourseArray.cc CourseArray.h
	g++ $(OPT) -c CourseArray.cc

Schedule.o: Schedule.cc Schedule.h 
	g++ $(OPT) -c Schedule.cc

School.o: School.cc School.h
	g++ $(OPT) -c School.cc

Time.o: Time.cc Time.h
	g++ $(OPT) -c Time.cc

View.o: View.cc View.h
	g++ $(OPT) -c View.cc

clean:
	rm -f *.o assignment02
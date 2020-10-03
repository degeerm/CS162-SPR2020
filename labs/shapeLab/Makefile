CC = g++ 
exe_file = shape_test
$(exe_file): Shape.o Rectangle.o Circle.o Square.o application.o
	$(CC) Shape.o Rectangle.o Circle.o Square.o application.o -o $(exe_file)
Shape.o: Shape.cpp
	$(CC) -c Shape.cpp
Rectangle.o: Rectangle.cpp
	$(CC) -c Rectangle.cpp
Circle.o: Circle.cpp
	$(CC) -c Circle.cpp
Square.o: Square.cpp
	$(CC) -c Square.cpp
application.o: application.cpp
	$(CC) -c application.cpp
clean:
	rm -f *.out *.o $(exe_file)

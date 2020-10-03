CC = g++ 
exe_file = linked_list 
$(exe_file): Linked_List.o Node.o driver.o
	$(CC) Linked_List.o Node.o driver.o -o $(exe_file)
Linked_List.o: Linked_List.cpp
	$(CC) -c Linked_List.cpp
Node.o: Node.cpp
	$(CC) -c Node.cpp
driver.o: driver.cpp
	$(CC) -c driver.cpp
clean:
	rm -f *.out *.o $(exe_file)

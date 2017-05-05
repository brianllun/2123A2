CXX:=g++
CXXFLAGS:=-std=c++11

# The part below shall be uncomment and finished by you, add more lines as you need

a2.o: a2.cpp Matrix.h Equation_solving.h
	$(CXX) -c $(CXXFLAGS) a2.cpp

a2: a2.o Matrix.o Equation_solving.o
	$(CXX) Matrix.o a2.o Equation_solving.o -o a2.out

run_a2: a2.out
	./a2.out

# The part above shall be uncomment and finished by you

Matrix.o: Matrix.cpp Matrix.h
	$(CXX) -c $(CXXFLAGS) Matrix.cpp

client1_1.o: client1_1.cpp
	$(CXX) -c $(CXXFLAGS) client1_1.cpp

client1_1: client1_1.o Matrix.o
	$(CXX) Matrix.o client1_1.o -o client1_1

run1_1: client1_1
	./client1_1

client1_2.o: client1_2.cpp
	$(CXX) -c $(CXXFLAGS) client1_2.cpp

client1_2: client1_2.o Matrix.o
	$(CXX) Matrix.o client1_2.o -o client1_2

run1_2: client1_2
	./client1_2

myClient.o: myClient.cpp
	$(CXX) -c $(CXXFLAGS) myClient.cpp

myClient: myClient.o Matrix.o
	$(CXX) Matrix.o myClient.o -o myClient

runMyClient: myClient
	./myClient

client2.o: client2.cpp
	$(CXX) -c $(CXXFLAGS) client2.cpp

client2: client2.o Matrix.o
	$(CXX) Matrix.o client2.o -o client2

run2: client2
	./client2

client3.o: client3.cpp
	$(CXX) -c $(CXXFLAGS) client3.cpp

client3: client3.o Matrix.o
	$(CXX) Matrix.o client3.o -o client3

run3: client3
	./client3 < input3.txt

client4.o: client4.cpp
	$(CXX) -c $(CXXFLAGS) client4.cpp

client4: client4.o Matrix.o
	$(CXX) Matrix.o client4.o -o client4

run4: client4
	./client4 < input4.txt

client5.o: client5.cpp
	$(CXX) -c $(CXXFLAGS) client5.cpp

client5: client5.o Matrix.o
	$(CXX) Matrix.o client5.o -o client5

run5: client5
	./client5 < input5.txt

client6.o: client6.cpp
	$(CXX) -c $(CXXFLAGS) client6.cpp

client6: client6.o Matrix.o
	$(CXX) Matrix.o client6.o -o client6

run6: client6
	./client6 < input6.txt

client7.o: client7.cpp
	$(CXX) -c $(CXXFLAGS) client7.cpp

client7: client7.o Matrix.o
	$(CXX) Matrix.o client7.o -o client7

run7: client7
	./client7 < input7.txt

client8.o: client8.cpp
	$(CXX) -c $(CXXFLAGS) client8.cpp

client8: client8.o Matrix.o
	$(CXX) Matrix.o client8.o -o client8

run8: client8
	./client8 < input8.txt

client9.o: client9.cpp
	$(CXX) -c $(CXXFLAGS) client9.cpp

client9: client9.o Matrix.o
	$(CXX) Matrix.o client9.o -o client9

run9: client9
	./client9 < input9.txt

client10.o: client10.cpp
	$(CXX) -c $(CXXFLAGS) client10.cpp

client10: client10.o Matrix.o
	$(CXX) Matrix.o client10.o -o client10

run10: client10
	./client10 < input10.txt

client11.o: client11.cpp
	$(CXX) -c $(CXXFLAGS) client11.cpp

client11: client11.o Matrix.o
	$(CXX) Matrix.o client11.o -o client11

run11: client11
	./client11 < input11.txt

client12.o: client12.cpp
	$(CXX) -c $(CXXFLAGS) client12.cpp

client12: client12.o Matrix.o
	$(CXX) Matrix.o client12.o -o client12

run12: client12
	./client12 < input12.txt

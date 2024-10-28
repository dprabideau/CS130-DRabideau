CXX = g++
CXXFLAGS = -c -g -Wall -std=c++17
PROGRAM = simonsays.exe
CPPFILES = main.cpp
build:
	@$(CXX) $(CXXFLAGS) $(CPPFILES)
	@$(CXX) -o $(PROGRAM) *.o

run:
	@./$(PROGRAM)

clean:
	@rm -f $(PROGRAM) *.o

unittest:
	@./$(PROGRAM) test

kattistest:
	cat ./sample_tests/1.in | ./$(PROGRAM) | diff - ./sample_tests/1.ans
	cat ./sample_tests/2.in | ./$(PROGRAM) | diff - ./sample_tests/2.ans
	cat ./sample_tests/3.in | ./$(PROGRAM) | diff - ./sample_tests/3.ans
	@echo "All Test Cases Passed!"

all: build unittest clean
	@printf "All good!\n"
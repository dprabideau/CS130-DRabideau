CXX = g++
CXXFLAGS = -c -g -Wall -std=c++17
PROGRAM = main.exe
CPPFILES = main.cpp
build:
	@$(CXX) $(CXXFLAGS) $(CPPFILES)
	@$(CXX) -o $(PROGRAM) *.o

run:
	@./$(PROGRAM)

clean:
	@rm -f $(PROGRAM) *.o

test:
	@./$(PROGRAM) test

kattis:
	cat ./sample_tests/1.in | ./$(PROGRAM) | diff - ./sample_tests/1.ans
	cat ./sample_tests/2.in | ./$(PROGRAM) | diff - ./sample_tests/2.ans
# My test files
	cat ./sample_tests/3.in | ./$(PROGRAM) | diff - ./sample_tests/3.ans
	cat ./sample_tests/4.in | ./$(PROGRAM) | diff - ./sample_tests/4.ans
	cat ./sample_tests/5.in | ./$(PROGRAM) | diff - ./sample_tests/5.ans
	cat ./sample_tests/6.in | ./$(PROGRAM) | diff - ./sample_tests/6.ans
	@echo "All Test Cases Passed!"

all: build test kattis clean
	@printf "All good!\n"
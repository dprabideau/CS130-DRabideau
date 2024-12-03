CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

TARGET = encryptor
SOURCES = main.cpp encryptor.cpp

build: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $@ $^

run: build
	./$(TARGET)

clean:
	rm -f $(TARGET)

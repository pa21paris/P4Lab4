CC = g++
CXXFLAGS = -std=c++17
TARGET = main
SOURCES = $(wildcard data_structures/*.cpp) $(wildcard objects/*.cpp) $(wildcard controllers/*.cpp) main.cpp

$(TARGET): $(SOURCES)
	$(CC) $(CXXFLAGS) -o $@ $^

clean:
	rm $(TARGET)



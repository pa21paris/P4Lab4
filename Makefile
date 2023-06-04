CC = g++
TARGET = main
SOURCES = $(wildcard data_structures/*.cpp) $(wildcard objects/*.cpp) $(wildcard controllers/*.cpp) main.cpp

$(TARGET): $(SOURCES)
	$(CC) -o $@ $^

clean:
	rm $(TARGET)




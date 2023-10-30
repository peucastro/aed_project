CC = g++
CFLAGS = -std=c++11
SOURCES = main.cpp src/Uc.cpp src/Student.cpp src/Lecture.cpp src/Script.cpp src/Request.cpp src/App.cpp
EXECUTABLE = main

all: $(SOURCES)
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(SOURCES)

clean:
	rm -f $(EXECUTABLE)

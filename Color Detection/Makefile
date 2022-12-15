CC = g++
PROJECT = new_output
SRC = detection.cpp
LIBS = `pkg-config --cflags --libs opencv`
$(PROJECT) : $(SRC)
	$(CC) $(SRC) -o $(PROJECT) $(LIBS)
CC = g++
PROJECT = new_output
SRC = 1.cpp
SRC2 = 2.cpp
LIBS = `pkg-config --cflags --libs opencv`
RUN = ./new_output
$(PROJECT) : $(SRC)
	$(CC) $(SRC) -o $(PROJECT) $(LIBS) ; $(RUN) ; $(CC) $(SRC2) -o $(PROJECT) $(LIBS) ; $(RUN)

# define the C compiler to use
# the compiler: gcc for C program, define as g++ for C++
CC = g++


CFLAGS  = -g -Wall

# the build target executable:
TARGET = sqlite_select_all

APP = main

LIBS = -lsqlite3

all: $(TARGET).cpp
	$(CC) $(CFLAGS) $(TARGET).cpp -o $(APP) $(LIBS)
	@echo Simple compiler named mycc has been compiled
    

#all: sqlite_select_all.cpp
#	g++ -std=c++17 sqlite_select_all.cpp -o main -lsqlite3

clean:
	#rm sqlite_select_all.o sqlite_select_all.exe main
	#$(RM) myprog
	$(RM) $(TARGET)
	$(RM) $(APP)
	

# appname := myapp

# default:
	# g++ -o sqlite_select_all sqlite_select_all.cpp
	# g++ -std=c++17 sqlite_select_all.cpp -o myapp -lsqlite3

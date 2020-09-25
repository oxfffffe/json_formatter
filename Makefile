CXX           	= g++
CXXFLAGS      	= -pipe -O2 -g -std=gnu++1y -Wall -Wextra -fPIC
INCPATH       	= -I../json_formatter -I. -I/usr/lib/qt/mkspecs/linux-g++
DEL_FILE      	= rm -f
LINK          	= g++
SOURCES       	= ../json_formatter/json_formatter.cpp \
		../json_formatter/main.cpp 
OBJECTS      	= json_formatter.o \
		main.o

DIST 		= ../json_formatter/json_formatter.pro \
		json_formatter.hpp \
		../json_formatter/json_formatter.cpp \
		../json_formatter/main.cpp
TARGET        	= json_formatter


first: all

json_formatter:  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP)
all: Makefile json_formatter

clean: compiler_clean 
	-$(DEL_FILE) $(OBJECTS)

clean:

json_formatter.o: ../json_formatter/json_formatter.cpp ../json_formatter/json_formatter.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o json_formatter.o ../json_formatter/json_formatter.cpp

main.o: ../json_formatter/main.cpp ../json_formatter/json_formatter.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o ../json_formatter/main.cpp

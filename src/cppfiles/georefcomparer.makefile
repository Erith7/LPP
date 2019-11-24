CC = g++

CFLAGS  = -g -fopenmp -Wall -std=c++11 

LIBS := $(shell pkg-config opencv --libs)

TARGET = georefcomparer

INCLUDES = -I/usr/local/include/opencv2/ -I/usr/local/include/opencv/

all: $(TARGET) 

$(TARGET): $(TARGET).cpp
	$(CC) $(CFLAGS) -o $(TARGET).exe $(TARGET).cpp $(LIBS) $(INCLUDES)

clean: 
	$(RM) $(TARGET) 

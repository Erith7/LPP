CC = g++

CFLAGS  = -g -Wall -std=c++11 

LIBS := $(shell pkg-config opencv --libs)

TARGET = LandSat_8_CalGeoRef

INCLUDES = -I/usr/local/include/opencv2/ -I/usr/local/include/opencv/

all: $(TARGET)

$(TARGET): $(TARGET).cpp
	$(CC) $(CFLAGS) -o $(TARGET).exe $(TARGET).cpp $(LIBS) $(INCLUDES)

clean: 
	$(RM) $(TARGET) 

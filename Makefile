#!/usr/bin/make

# Complier Options
CC ?= gcc
CFLAGS ?= -Wall -std=c11 -g -O0 -pipe
CXX ?= g++
INC ?= -I.
LDFLAGS ?= -lm -L. -lwiringPi
CXXFLAGS ?= -std=c++17 -Wall -g -O0 -pipe $(INC)
SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:.cpp=.o)
TARGET := werfer
RM = rm

#機能の定義
.PHONY:all clean run
all:$(TARGET)
run:all
	./$(TARGET)
$(TARGET):$(OBJS)
	$(CXX) $(OBJS) -o $(TARGET) $(LDFLAGS)
%.o: %.cpp $(wildcard *.h)
	$(CC) $(CFLAGS) -c $<
clean:
	$(RM) $(OBJS) $(TARGET)

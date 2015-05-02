
TARGET = ../../lib/mac/x64/libnetwork.a

SRCDIR := $(shell find ../../src/network -maxdepth 3 -type d)
INCDIR = -I ../../include

OBJDIR = ./debug

CC = g++
CFLAGS = -O2 -Wall -fPIC -g

CPP_FILES = $(foreach d, $(SRCDIR), $(wildcard $(d)/*.cpp))
CPP_OBJS = $(patsubst %.cpp, $(OBJDIR)/%.o, $(CPP_FILES))

default: init compile

$(CPP_OBJS): $(OBJDIR)/%.o:%.cpp
	$(CC) -c $(CFLAGS) $< $(INCDIR) -o $@

init:
	$(foreach d, $(SRCDIR), mkdir -p $(OBJDIR)/$(d);)

compile:$(CPP_OBJS)
	ar rv $(TARGET) $(CPP_OBJS)

test:
	@echo "OBJS: $(CPP_OBJS)"
	@echo "SRCDIR: $(SRCDIR)"
	@echo "INCDIR: $(INCDIR)"
	@echo "OBJDIR: $(OBJDIR)"

.PHONY:clean

clean:
	rm -rf $(TARGET)
	rm -rf $(OBJDIR)

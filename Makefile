CXX := g++
CXXFLAGS := -g -Wall -Wextra
CC := $(CXX)
CFLAGS := $(CXXFLAGS)

SRCDIR := src
SRCEXT := cpp
BUILDDIR := build
INCLUDEDIR := include
TARGET := bin/ex

SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))

INC := -I$(INCLUDEDIR)

$(TARGET): $(OBJECTS)
	@echo " Linking... "

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)

.PHONY: clean
clean:
	@echo " Cleaning... "
	rm -rf $(TARGET)
	rm -rf $(BUILDDIR)/*
	rm -rf $(LIBDIR)/*


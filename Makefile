CXX := g++
CXXFLAGS := -g -Wall -Wextra# -std=c++11
CC := $(CXX)
CFLAGS := $(CXXFLAGS)

SRCDIR := ./src
SRCEXT := cpp
BUILDDIR := ./build
INCLUDEDIR := ./include
LIBDIR := ./lib
TARGET := ./bin/ex

SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))

INC := -I$(INCLUDEDIR)

$(TARGET): $(OBJECTS)
	@echo " Linking files... "
	$(CXX) $(CXXFLAGS) -o $(TARGET) $^
	@echo " '$(TARGET)' ready "


$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	$(CXX) -c $(CXXFLAGS) -o $@ $<
	@echo " Compiled "

.PHONY: clean
clean:
	@echo " Cleaning... "
	find $(TARGET) $(BUILDDIR) $(LIBDIR) -maxdepth 1 -type f ! -name '.gitkeep'\
	 -delete

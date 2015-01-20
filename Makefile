CXX := g++
CXXFLAGS := -g -Wall -Wextra -std=c++0x
CC := $(CXX)
CFLAGS := $(CXXFLAGS)

SRCDIR := ./src
ENTRY_POINT := main.cpp
SRCEXT := cpp
BINDIR := ./bin
BUILDDIR := ./build
INCLUDEDIR := ./include
LIBDIR := ./lib
TESTDIR := ./test

TARGET := $(BINDIR)/ex
TEST := $(BINDIR)/test

# All files with .$(SRCEXT) extension in $(SRCDIR)
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
# Map files from $(SOURCES) to object-files in $(BUILDDIR)
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
# All files with .$(SRCEXT) extension in $(SRCDIR) $(TESTDIR) except $(ENTRY_POINT)
TEST_SOURCES := $(shell find $(SRCDIR) $(TESTDIR) -type f -name *.$(SRCEXT) ! -name $(ENTRY_POINT))
# Map files from $(TEST_SOURCES) to object-files in $(BUILDDIR)
TEST_OBJECTS := $(patsubst $(TESTDIR)/%,$(BUILDDIR)/%,$(TEST_SOURCES:.$(SRCEXT)=.o))
TEST_OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(TEST_OBJECTS:.$(SRCEXT)=.o))

INC := -I$(INCLUDEDIR)
# TEST_INC := -I$(TEST_INCLUDEDIR)

# Run `make`
all: $(TARGET)
# Run `make test`
test: $(TEST)

.PHONY: $(TARGET)
$(TARGET): $(OBJECTS)
	@echo " Linking files... "
	$(CXX) $(CXXFLAGS) $(INC) -o $(TARGET) $^
	@echo " '$(TARGET)' ready "

# Map each object-file to source file in $(SRCDIR)
$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	$(CXX) -c $(CXXFLAGS) $(INC) -o $@ $<
	@echo " Compiled "

.PHONY: $(TEST)
$(TEST): $(TEST_OBJECTS)
	@echo " Linking test files... "
	$(CXX) $(CXXFLAGS) $(INC) -o $(TEST) $^
	@echo " '$(TEST)' ready "

# Map each object-file to source file in $(TESTDIR)
$(BUILDDIR)/%.o: $(TESTDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	$(CXX) -c $(CXXFLAGS) $(INC) -o $@ $<
	@echo " Compiled tests "

.PHONY: clean
# Remove all files from $(TARGET) $(TEST) $(BUILDDIR) $(LIBDIR) except '.gitkeep'
clean:
	@echo " Cleaning... "
	find $(TARGET) $(TEST) $(BUILDDIR) $(LIBDIR)\
	  -maxdepth 1 -type f ! -name '.gitkeep'\
	  -delete

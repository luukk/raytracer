CXX ?= g++
CXX_FLAGS ?= -std=gnu++17
SRC_DIR ?= .
SRC_EXT = cpp
OBJ_DIR = build
SRC_FILES := $(shell find $(SRC_DIRS) -name '*.cpp')
OBJ_FILES = $(SRC_FILES:$(SRC_PATH)/%.$(SRC_EXT)=$(OBJ_DIR)/%.o)
BIN_PATH = $(OBJ_DIR)/bin
DEPS = $(OBJ_FILES:.o=.d)

default: make

make: 
	$(CXX) $(CXX_FLAGS) $(SRC_FILES) -o raytracer

dirs:
	@echo "Creating directories"
	@mkdir -p $(dir $(OBJ_FILES))
	@mkdir -p $(BIN_PATH)

clean:
	rm -rf *.o

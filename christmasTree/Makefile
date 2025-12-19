SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj
BIN_DIR = bin

CXX = g++
CXXFLAGS = -std=c++17 -Wall -O2 -I$(INC_DIR)

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

ifeq ($(OS), Windows_NT)
	TARGET_NAME = christmasTree.exe
	RM = del /Q

	MKDIR_OBJ = if not exist "$(OBJ_DIR)" mkdir "$(OBJ_DIR)"
	MKDIR_BIN = if not exist "$(BIN_DIR)" mkdir "$(BIN_DIR)"
	
	TARGET = $(BIN_DIR)\$(TARGET_NAME)

else
	TARGET_NAME = christmasTree.out
	RM = rm -f

	MKDIR_OBJ = mkdir -p $(OBJ_DIR)
	MKDIR_BIN = mkdir -p $(BIN_DIR)

	TARGET = $(BIN_DIR)/$(TARGET_NAME)

endif


all: create_dirs $(TARGET)

create_dirs:
	@$(MKDIR_OBJ)
	@$(MKDIR_BIN)

$(TARGET): $(OBJS)
		@echo "Linking $@"
		$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)
		@echo "Build complete: $(TARGET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
		@echo "Compiling $<..."
		$(CXX) $(CXXFLAGS) -c $< -o $@


clean:
	@echo "Cleaning ..."
ifeq ($(OS), Windows_NT)
	-$(RM) $(OBJ_DIR)\*.o
	-$(RM) $(TARGET)
else
	$(RM) $(OBJS) $(TARGET)
endif
	@echo "Clean complete"
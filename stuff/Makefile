CXX = clang++-21

CXXFLAGS = -std=c++23 -stdlib=libc++ -Wall -Wextra -Wpedantic -Werror

BUILD_DIR = build

PROGRAM = $(BUILD_DIR)/app

STD_SRC = /usr/lib/llvm-21/share/libc++/v1/std.cppm
STD_PCM = $(BUILD_DIR)/std.pcm

MODULE = Beans
MODULE_SRC = Beans.cppm
MODULE_BMI = $(BUILD_DIR)/$(MODULE).pcm
MODULE_OBJ = $(BUILD_DIR)/$(MODULE).o

MAIN_OBJ = $(BUILD_DIR)/main.o

OBJECTS = $(MAIN_OBJ) $(MODULE_OBJ)

.PHONY: all run clean

all: $(PROGRAM)

$(BUILD_DIR):
	@echo "Making directory 'build'"
	@mkdir $(BUILD_DIR)

$(STD_PCM): $(STD_SRC) | $(BUILD_DIR)
	@echo "Compiling std module"
	@$(CXX) $(CXXFLAGS) -Wno-reserved-module-identifier --precompile $< -o $@

$(MODULE_BMI): $(MODULE_SRC) $(STD_PCM)
	@echo "Compiling $(MODULE_BMI)"
	@$(CXX) $(CXXFLAGS) \
		-Wno-reserved-module-identifier \
		-fmodule-file=std=$(STD_PCM) \
		--precompile $< -o $@

$(MODULE_OBJ): $(MODULE_SRC) $(MODULE_BMI) $(STD_PCM)
	@echo "Compiling $(MODULE_OBJ)"
	@$(CXX) $(CXXFLAGS) \
		-fmodule-file=std=$(STD_PCM) \
		-fmodule-file=$(MODULE)=$(MODULE_BMI) \
		-c $< -o $@
	
$(MAIN_OBJ): main.cpp $(MODULE_BMI) $(STD_PCM)
	@echo "Compiling $(MAIN_OBJ)"
	@$(CXX) $(CXXFLAGS) \
		-fmodule-file=std=$(STD_PCM) \
		-fmodule-file=$(MODULE)=$(MODULE_BMI) \
		-c $< -o $@

$(PROGRAM): $(OBJECTS)
	@echo "Linking $(PROGRAM)"
	@$(CXX) $(CXXFLAGS) $^ -o $@

run: $(PROGRAM)
	@echo "Running $(PROGRAM)"
	@./$(PROGRAM)

clean:
	@echo "Cleaning up"
	@rm -f $(PROGRAM) $(OBJECTS)

clean-all:
	@echo "Cleaning all"
	@rm -f $(PROGRAM) $(OBJECTS) $(STD_PCM) $(MODULE_BMI)

CXX = clang++-21

CXXFLAGS = -std=c++23 -stdlib=libc++ -Wall -Wextra -Wpedantic -Werror

PROGRAM = app

BUILD_DIR = build

STD_SRC = /usr/lib/llvm-21/share/libc++/v1/std.cppm
STD_PCM = $(BUILD_DIR)/std.pcm

MODULE = Beans
MODULE_SRC = Beans.cppm
MODULE_BMI = $(MODULE).pcm
MODULE_OBJ = $(MODULE).o

OBJECTS = main.o $(MODULE_OBJ)

.PHONY: all run clean

all: $(PROGRAM)

$(BUILD_DIR):
	@mkdir $(BUILD_DIR)

$(STD_PCM): $(STD_SRC) $(BUILD_DIR)
	@$(CXX) $(CXXFLAGS) -Wno-reserved-module-identifier --precompile $< -o $@

$(MODULE_BMI): $(MODULE_SRC) $(STD_PCM)
	@$(CXX) $(CXXFLAGS) \
		-Wno-reserved-module-identifier \
		-fmodule-file=std=$(STD_PCM) \
		--precompile $< -o $@

$(MODULE_OBJ): $(MODULE_SRC) $(MODULE_BMI) $(STD_PCM)
	@$(CXX) $(CXXFLAGS) \
		-fmodule-file=std=$(STD_PCM) \
		-fmodule-file=$(MODULE)=$(MODULE_BMI) \
		-c $< -o $@
	
main.o: main.cpp $(MODULE_BMI) $(STD_PCM)
	@$(CXX) $(CXXFLAGS) \
		-fmodule-file=std=$(STD_PCM) \
		-fmodule-file=$(MODULE)=$(MODULE_BMI) \
		-c $< -o $@

$(PROGRAM): $(OBJECTS)
	@$(CXX) $(CXXFLAGS) $^ -o $@

run: $(PROGRAM)
	@./$(PROGRAM)

clean:
	@rm -f $(PROGRAM) $(OBJECTS)

clean-all:
	@rm -f $(PROGRAM) $(OBJECTS) $(STD_PCM) $(MODULE_BMI)

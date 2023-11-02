MAKEFLAGS += --no-print-directory

BUILD_DIR = ./build
all:
	cmake -DCMAKE_BUILD_TYPE=Release -S . -B $(BUILD_DIR)
	cmake --build $(BUILD_DIR) -j8
	@echo ""
	@./$(BUILD_DIR)/code

clean:
	-rm -rf $(BUILD_DIR)

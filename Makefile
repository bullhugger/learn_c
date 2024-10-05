# Compiler flags
CFLAGS = -Wno-implicit-function-declaration

# Time command and output file
TIME_CMD = /usr/bin/time -f "Compilation Time: %E" -o compile_time.txt

# Default target
all: final

# Rule to link and produce the final executable
final: main.o functions.o
	@echo "Linking and producing the final application"
	$(TIME_CMD) gcc $(CFLAGS) main.o functions.o -o final
	@chmod +x final
	@echo "Final application size:" > compile_info.txt
	@stat --format="%s bytes" final >> compile_info.txt
	@echo "Compilation time recorded in compile_time.txt" >> compile_info.txt
	@cat compile_time.txt >> compile_info.txt
	@cat compile_info.txt

# Rule to compile main.c
main.o: main.c
	@echo "Compiling main file..."
	$(TIME_CMD) gcc $(CFLAGS) -c main.c
	@stat --format="Main object size: %s bytes" main.o

# Rule to compile functions.c
functions.o: functions.c
	@echo "Compiling the functions file..."
	$(TIME_CMD) gcc $(CFLAGS) -c functions.c
	@stat --format="Functions object size: %s bytes" functions.o

# Rule to clean the directory
clean:
	@echo "Cleaning directory..."
	rm -f main.o functions.o final compile_time.txt compile_info.txt

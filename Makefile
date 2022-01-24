TARGET = "NGE2_Demo"

main:
	$(CXX) ./src/main.cpp -o ./build/$(TARGET)

run: main
	./build/$(TARGET)

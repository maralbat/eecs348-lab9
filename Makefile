CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic
TARGET = matrix
OBJS = main.o

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp matrix.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

clean:
	rm -f $(TARGET) *.o
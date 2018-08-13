CXX = g++
STD = -std=c++14
CXXFLAGS = -Wall -Wpedantic -Wextra
SRCS = $(shell find . ! -name "test_main.cpp" -name "*.cpp")
SRCSTEST = $(shell find . ! -name "main.cpp" -name "*.cpp")
OBJS = $(SRCS:.cpp=.o)
OBJSTEST = $(SRCSTEST:.cpp=.o)
TARGET = db.out
TARGETTEST = test.out

.PHONY: all
all:$(TARGET)
test:$(TARGETTEST)

%.o: %.cpp 
	$(CXX) $(CXXFLAGS) $(STD) -c -o $@ $<

$(TARGET): $(OBJS)
	$(CXX) $^ -o $@ 

$(TARGETTEST): $(OBJSTEST)
	$(CXX) $^ -o $@ 

.PHONY: clean
clean:
	rm *.o *.out

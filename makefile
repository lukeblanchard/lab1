CXX = g++ 
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
#LDFLAGS = -lboost_date_time

OBJS = determinant.o readMatrix.o main.o

SRCS = determinant.cpp readMatrix.cpp main.cpp

HEADERS = determinant.hpp readMatrix.hpp

main: ${OBJS} ${HEADERS}
	${CXX} ${OBJS} -o main

${OBJS}: ${SRCS} 
	${CXX} ${CXXFLAGS} -c ${@:.o=.cpp}

clean: 
	rm -f main ${OBJS}

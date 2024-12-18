# Target to compile the executable
mytests: mytests.o PriorityQueue.o
	g++ -std=c++17 -o mytests mytests.o PriorityQueue.o
	./mytests
	
# Target to compile mytests.o
mytests.o: mytests.cpp PriorityQueue.hpp customexceptions.hpp
	g++ -std=c++17 -c mytests.cpp -o mytests.o

# Target to compile PriorityQueue.o
PriorityQueue.o: PriorityQueue.cpp PriorityQueue.hpp customexceptions.hpp
	g++ -std=c++17 -c PriorityQueue.cpp -o PriorityQueue.o

# Commented out: Target to compile Graph.o
# WeightedGraph.o: WeightedGraph.cpp WeightedGraph.hpp customexceptions.hpp
#	g++ -std=c++17 -c WeightedGraph.cpp -o WeightedGraph.o

# Clean target to remove object files and executable
clean:
	rm -f *.o mytests

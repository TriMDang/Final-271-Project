
# Target to compile the executable
mytests: mytests.o WeightedGraph.o
	g++ -std=c++17 -o mytests mytests.o WeightedGraph.o
	./mytests
	
# Target to compile mytests.o
mytests.o: mytests.cpp WeightedGraph.hpp
	g++ -std=c++17 -c mytests.cpp -o mytests.o

# Target to compile Graph.o
WeightedGraph.o: WeightedGraph.cpp WeightedGraph.hpp
	g++ -std=c++17 -c WeightedGraph.cpp -o WeightedGraph.o

# Clean target to remove object files and executable
clean:
	rm -f *.o mytests

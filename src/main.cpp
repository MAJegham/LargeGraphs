#include "Graph.hpp"
#include <iostream>
#include <time.h>//to estimate the runing time
#include <string>


int main(int argc,char** argv){
    //std::vector<std::string> argList(argv, argv + argc);

	time_t t1,t2;

	t1=time(NULL);

	printf("Reading edgelist from file %s\n",argv[1]);
	Graph graph = Graph(argv[1]);
    
    std::cout << graph << "\n";

	t2=time(NULL);

	printf("- Overall time = %ldh%ldm%lds\n",(t2-t1)/3600,((t2-t1)%3600)/60,((t2-t1)%60));
	
	return 0;
}
// Project 2 Simplified Page rank.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "AdjacencyList.h"
using namespace std;
#include <iostream>

int main()
{
	AdjacencyList Created_Graph;
	int no_of_lines, power_iterations;
	std::string from, to;
	std::cin >> no_of_lines;
	std::cin >> power_iterations;
	for (int i = 0; i < no_of_lines; i++)
	{
		std::cin >> from;
		std::cin >> to;
		Created_Graph.addEdge(from, to);
		// Do Something
	}
	//Create a graph object
	Created_Graph.PageRank(power_iterations);

	return 0;
}
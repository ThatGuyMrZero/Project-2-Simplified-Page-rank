#pragma once
using namespace std;
#include <vector>
#include <map>
#include <iostream>
#include <unordered_map>
#include <iomanip>
#include <algorithm>


class AdjacencyList {
private:
	// Think about what member variables you need to initialize
	unordered_map<string, vector<string>> Created_Graph;
	unordered_map<string, float> Page_rank;

public:
	//Think about what helper functions you will need in the algorithm
	AdjacencyList() {}

	void PageRank(int n);
	void printIntermediateRanks();
	void printRanks();
	void addEdge(string& from, string& to);


};

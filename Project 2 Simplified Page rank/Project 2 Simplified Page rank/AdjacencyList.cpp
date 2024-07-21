#include "AdjacencyList.h"
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <iomanip>
using namespace std;



// prints the PageRank of all pages after p powerIterations inascending alphabetical order of webpages and rounding rank to two decimal places

void AdjacencyList::PageRank(int n) {
	float initial = 1.0 / Created_Graph.size();
	for (auto it = Created_Graph.begin(); it != Created_Graph.end(); ++it) {
		Page_rank[it->first] = initial;
	}
	for (int i = 1; i <= n; i++) {
		unordered_map<string, float> newRankings;
		float hangingNumber = 0.0f;
		for (auto it = Created_Graph.begin(); it != Created_Graph.end(); ++it) {
			//const string& node = it->first;
			//vector<string>& adjacent = it->second;
			newRankings[it->first] = 0.0f;
		}
		//float hangingNumber = 0.0f;

		for (auto it = Created_Graph.begin(); it != Created_Graph.end(); ++it) {
			const string& node = it->first;
			vector<string>& adjacent = it->second;
			if (adjacent.empty()) {
				hangingNumber += Page_rank[node];
			}
			else {

				float powerRank = Page_rank[node] / adjacent.size();

				for (auto iterator = adjacent.begin(); iterator != adjacent.end(); ++iterator) {
					newRankings[*iterator] += powerRank;
				}
			}
		}
		float distributeDangling = hangingNumber / Created_Graph.size();

		for (auto it = newRankings.begin(); it != newRankings.end(); ++it) {
			it->second += distributeDangling;
		}

		Page_rank = newRankings;

	}
	printRanks();
}

void AdjacencyList::printRanks() {
	vector <pair<string, float>> rankOfPages(Page_rank.begin(), Page_rank.end());
	sort(rankOfPages.begin(), rankOfPages.end());

	for (auto it = rankOfPages.begin(); it != rankOfPages.end(); ++it) {
		cout << it->first << " " << fixed << setprecision(2) << it->second << endl;
	}
}

void AdjacencyList::addEdge(string& from, string& to) {
	Created_Graph[from].push_back(to);
	if (Created_Graph.find(to) == Created_Graph.end()) {
		Created_Graph[to] = {};
	}

}
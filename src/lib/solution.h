#ifndef TEMPLATE_SOLUTION_H
#define TEMPLATE_SOLUTION_H


#include <string>
#include <vector>
#include <map>
#include <set>
class Solution {

public:
    std::string HelloWorld();
};


class Graph {

public:
    // member variables
    std::map<int, std::set<int>> v_;

    // constructor
    Graph(std::map<int, std::set<int>> edgeMap) : v_(edgeMap) {}

    // member methods
    // Q3
    std::map<int, int> BFS_dist(int root);
    std::map<int, std::vector<int>> BFS_path(int root);

    // Q4
    std::set<int> findRoot();
    std::vector<int> topoSort();

    // Q5
    bool inShortestHelper(int curNode, int curLevel, int &minLevel, std::vector<bool> &out, std::map<int, int> &dist);
    std::vector<bool> inShortest();








};





#endif
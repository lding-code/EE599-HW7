#include "solution.h"

#include <string>
#include <iostream>
#include <queue>
#include <set>
#include <stack>

std::string Solution::HelloWorld() {
    return "HelloWorld";
}

// Q3
std::map<int, int> Graph::BFS_dist(int root) {
    std::map<int, int> dist;
    std::map<int, int> marks;
    std::queue<int> q;
    q.push(root);
    marks[root] = 1;
    dist[root] = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto &n : v_[cur]) {
            if (!marks[n]) {
                marks[n] = 1;
                // neighbor vertex distance = current vertex distance + 1
                dist[n] = dist[cur] + 1;
                q.push(n);
            }
        }
    }
    return dist;
}

// Q3
std::map<int, std::vector<int>> Graph::BFS_path(int root) {
    std::map<int, std::vector<int>> path;
    std::map<int, int> marks;
    std::queue<int> q;
    q.push(root);
    marks[root] = 1;
    path[root] = {root};
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto &n : v_[cur]) {
            if (!marks[n]) {
                marks[n] = 1;
                path[n] = path[cur];
                path[n].push_back(n);
                q.push(n);
            }
        }
    }
    return path;
}

// Q4
std::set<int> Graph::findRoot(){
    std::set<int> roots;
    for (auto &n : v_) {
        roots.insert(n.first);
    }
    for (auto &n : v_) {
        for (auto &m : v_[n.first]) {
            if (roots.find(m) != roots.end()) {
                roots.erase(m);
            }
        }
    }
    return roots;
}

// Q4
std::vector<int> Graph::topoSort() {
    std::vector<int> topo;
    std::stack<int> travStack;  // traversal stack
    std::stack<int> topoStack;  // topological sort stack
    std::map<int, int> marks;
    std::set<int> roots = findRoot();
    for (auto &n : roots) {
        travStack.push(n);
    }
    while (!travStack.empty()) {
        int curNode = travStack.top();
        bool allVisited = true;

        // iterate neighbors of current node
        for (auto &n : v_[curNode]) {

            // if not visited
            if (!marks[n]) {

                // set it to visited
                marks[n] = 1;

                // push neighbor to stack
                travStack.push(n);

                // set allVisited flag to false
                allVisited = false;

                break;
            }
        }
        
        // if all neighbors are visited / no neighbor at all
        // this is the deepest node in current path
        // push it to topoStack
        if (allVisited) {
            // pop current node
            travStack.pop();

            // push curNode to topoStack
            topoStack.push(curNode);
        }
    }
    while (!topoStack.empty()) {
        topo.push_back(topoStack.top());
        topoStack.pop();
    }
    return topo;
}

// Q5
bool Graph::inShortestHelper(int curNode, int curLevel, int &minLevel, std::vector<bool> &out, std::map<int, int> &dist) {
    // if current level is greater than min level achieved so far
    // return false immediately
    if (curLevel > minLevel) {
        return false;
    }

    // if current level is within min level range
    // and current node == end node
    // we found a shortest path
    else if (curNode == v_.size() - 1) {

        // if current level == min level
        // we have the same shortest length
        // simply set nodes along the path to true
        if (curLevel == minLevel) {
            out[curNode] = true;
            return true;
        }

        // if current level < min level
        // we have found a shorter path
        // set all nodes in the previous "shortest path" to false
        // update the new min level
        // set nodes long this new path to true
        else if (curLevel < minLevel) {
            minLevel = curLevel;
            for (auto n : out) {
                n = false;
            }
            out[curNode] = true;
            return true;
        }
    }

    // if max level is not reached
    // and end node is not found
    // keep searching deeper
    else {
        bool flagInShortest = false;

        for (auto n : v_[curNode]) {
            if (dist[n] > dist[curNode]) {
                // if shortest path exists under this node, set this node to true
                if (inShortestHelper(n, curLevel + 1, minLevel, out, dist)) {
                    out[curNode] = true;
                }
            }
        }
        return out[curNode];
    }

    // current node doesn't have other unvisited neighbors
    // and current node is not equal to the end node
    // return false
    return false;
}

// Q5
std::vector<bool> Graph::inShortest() {
    int root = 0;
    std::vector<bool> out(v_.size(), false);

    // get depth (level) for each node
    // so that BFS can visit same node without going backward
    // by always going for deeper nodes
    // (same node can be shared by different shortest paths)
    // (therefore the old marks fashion doesn't work here)
    std::map<int, int> dist = BFS_dist(0);

    int minLevel = v_.size();
    inShortestHelper(0, 0, minLevel, out, dist);
    return out;
}
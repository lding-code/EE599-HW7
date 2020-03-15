#include "gtest/gtest.h"
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <set>

#include "src/lib/solution.h"

TEST(HelloWorldShould, ReturnHelloWorld) {
    Solution solution;

    std::string actual = solution.HelloWorld();
    std::string expected = "HelloWorld";

    EXPECT_EQ(expected, actual);
}

// Q3.1 case 1: example
TEST(BFS_distShould1, ReturnBFS_dist1) {
    std::map<int, std::set<int>> edges = {
        {0, {1, 2, 5}},
        {1, {0, 2, 3}},
        {2, {0, 1, 3}},
        {3, {1, 2, 4, 6}},
        {4, {3}},
        {5, {0}},
        {6, {3}}
    };

    Graph graph{edges};

    std::map<int, int> actual = graph.BFS_dist(0);
    std::map<int, int> expected = {
        {0, 0},
        {1, 1},
        {2, 1},
        {5, 1},
        {3, 2},
        {4, 3},
        {6, 3}
    };
    EXPECT_EQ(expected, actual);
}

// Q3.1 case 2: different start point
TEST(BFS_distShould2, ReturnBFS_dist2) {
    std::map<int, std::set<int>> edges = {
        {0, {1, 2, 5}},
        {1, {0, 2, 3}},
        {2, {0, 1, 3}},
        {3, {1, 2, 4, 6}},
        {4, {3}},
        {5, {0}},
        {6, {3}}
    };

    Graph graph{edges};

    std::map<int, int> actual = graph.BFS_dist(3);
    std::map<int, int> expected = {
        {3, 0},
        {1, 1},
        {2, 1},
        {4, 1},
        {6, 1},
        {0, 2},
        {5, 3}
    };
    EXPECT_EQ(expected, actual);
}

// Q3.2 case 1: example
TEST(BFS_pathShould1, ReturnBFS_path1) {
    std::map<int, std::set<int>> edges = {
        {0, {1, 2, 5}},
        {1, {0, 2, 3}},
        {2, {0, 1, 3}},
        {3, {1, 2, 4, 6}},
        {4, {3}},
        {5, {0}},
        {6, {3}}
    };

    Graph graph{edges};

    std::map<int, std::vector<int>> actual = graph.BFS_path(0);
    std::map<int, std::vector<int>> expected = {
        {0, {0}},
        {1, {0, 1}},
        {2, {0, 2}},
        {5, {0, 5}},
        {3, {0, 1, 3}},
        {4, {0, 1, 3, 4}},
        {6, {0, 1, 3, 6}}
    };
    EXPECT_EQ(expected, actual);
}

// Q3.2 case 2: different start point
TEST(BFS_pathShould2, ReturnBFS_path2) {
    std::map<int, std::set<int>> edges = {
        {0, {1, 2, 5}},
        {1, {0, 2, 3}},
        {2, {0, 1, 3}},
        {3, {1, 2, 4, 6}},
        {4, {3}},
        {5, {0}},
        {6, {3}}
    };

    Graph graph{edges};

    std::map<int, std::vector<int>> actual = graph.BFS_path(3);
    std::map<int, std::vector<int>> expected = {
        {3, {3}},
        {1, {3, 1}},
        {2, {3, 2}},
        {4, {3, 4}},
        {6, {3, 6}},
        {0, {3, 1, 0}},
        {5, {3, 1, 0, 5}}
    };
    EXPECT_EQ(expected, actual);
}

// Q4.1 case 1: example
TEST(findRootShould1, ReturnfindRoot1) {
    std::map<int, std::set<int>> edges = {
        {0, {}},
        {1, {0}},
        {2, {1}},
        {3, {1}},
        {4, {}},
        {5, {2, 4}},
        {6, {3, 4}},
        {7, {5, 6}}
    };

    Graph graph{edges};

    std::set<int> actual = graph.findRoot();
    std::set<int> expected = {7};
    EXPECT_EQ(expected, actual);
}

// Q4.1 case 2: add more roots
TEST(findRootShould2, ReturnfindRoot2) {
    std::map<int, std::set<int>> edges = {
        {0, {1}},
        {1, {}},
        {2, {1}},
        {3, {1}},
        {4, {5, 6}},
        {5, {2}},
        {6, {3}},
        {7, {5, 6}}
    };

    Graph graph{edges};

    std::set<int> actual = graph.findRoot();
    std::set<int> expected = {0, 4, 7};
    EXPECT_EQ(expected, actual);
}

// Q4.2 case 1: example
TEST(topoSortShould1, ReturntopoSort1) {
    std::map<int, std::set<int>> edges = {
        {0, {}},
        {1, {0}},
        {2, {1}},
        {3, {1}},
        {4, {}},
        {5, {2, 4}},
        {6, {3, 4}},
        {7, {5, 6}}
    };

    Graph graph{edges};

    std::vector<int> actual = graph.topoSort();
    std::vector<int> expected = {7, 6, 3, 5, 4, 2, 1, 0};
    EXPECT_EQ(expected, actual);
}

// Q4.2 case 2: add more roots
TEST(topoSortShould2, ReturnTopoSort2) {
    std::map<int, std::set<int>> edges = {
        {0, {1}},
        {1, {}},
        {2, {1}},
        {3, {1}},
        {4, {5, 6}},
        {5, {2}},
        {6, {3}},
        {7, {5, 6}}
    };

    Graph graph{edges};

    std::vector<int> actual = graph.topoSort();
    std::vector<int> expected = {0, 4, 7, 6, 3, 5, 2, 1};
    EXPECT_EQ(expected, actual);
}

// Q5case 1: example
TEST(inShortestSortShould1, ReturninShortest1) {
    std::map<int, std::set<int>> edges = {
        {0, {1, 4, 5}},
        {1, {0, 2, 3}},
        {2, {1, 3, 8}},
        {3, {1, 2}},
        {4, {0}},
        {5, {0, 6}},
        {6, {5, 7, 8}},
        {7, {6, 8}},
        {8, {2, 6, 7}}
    };

    Graph graph{edges};

    std::vector<bool> actual = graph.inShortest();
    std::vector<bool> expected = {true, true, true, false, false, true, true, false, true};
    EXPECT_EQ(expected, actual);
}

// Q5case 2: example from Q3
TEST(inShortestSortShould2, ReturninShortest2) {
    std::map<int, std::set<int>> edges = {
        {0, {1, 2, 5}},
        {1, {0, 2, 3}},
        {2, {0, 1, 3}},
        {3, {1, 2, 4, 6}},
        {4, {3}},
        {5, {0}},
        {6, {3}}
    };

    Graph graph{edges};

    std::vector<bool> actual = graph.inShortest();
    std::vector<bool> expected = {true, true, true, true, false, false, true};
    EXPECT_EQ(expected, actual);
}

// Q5case 2: not connected
TEST(inShortestSortShould3, ReturninShortest3) {
    std::map<int, std::set<int>> edges = {
        {0, {1}},
        {1, {0}},
        {2, {3}},
        {3, {2}}
    };

    Graph graph{edges};

    std::vector<bool> actual = graph.inShortest();
    std::vector<bool> expected = {false, false, false, false};
    EXPECT_EQ(expected, actual);
}
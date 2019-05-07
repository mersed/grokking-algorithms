/**
 * Djikstra's algorithm.
 * Consider that we have weighted graph given. Each segment (between)
 * two nodes have travel time in minutes. Using the Djikstra's algorithm,
 * we are able to find the shortest possible time from start to some
 * position in the graph.
 *
 * As you can see, usage of breadth first search for weighted 
 * graphs is not possible, due to the fact that it would find the path with
 * fewest segments (which maybe is not shortest path from start to finish)
 *
 * Within the implementation bellow, empty string is indication of non existance
 * of the node. The INT_MAX, represent infinite for the wieght of the edge.
 * This is proof of concept only, and for better understanding of algo more
 * complex data structures (vectors, hashmaps) are used. In order for Djikstra's
 * to be optimal - from perspective of space and time complexity - everything
 * bellow can be implemented with arrays only.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <string>

typedef std::map<std::string, int> ChildNodesMap;
typedef std::map<std::string, ChildNodesMap > GraphMap;

void populateGraph(GraphMap &graph) {
    graph["start"]["a"] = 5;
    graph["start"]["b"] = 2;

    graph["a"]["c"] = 4;
    graph["a"]["d"] = 2;

    graph["b"]["a"] = 8;
    graph["b"]["d"] = 7;

    graph["c"]["d"] = 6;
    graph["c"]["finish"] = 3;

    graph["d"]["finish"] = 1;
}

void dipslayGraph(GraphMap &graph) {
    std::cout << "Graph defined: " << std::endl;
    std::cout << "------------------" << std::endl;
    GraphMap::iterator it = graph.begin();
    for(; it != graph.end(); it++) {
        ChildNodesMap::iterator iter = it->second.begin();
        std::cout << "['" << it->first << "'] => {";
        for(; iter != it->second.end(); iter++) {
            std::cout << iter->first << "=>" << iter->second << ", ";
        }
        std::cout << "}" << std::endl;
    }

    std::cout << std::endl << std::endl;
}

std::string findLowestCostNode(ChildNodesMap &costs, std::vector<std::string> &processed) {
    ChildNodesMap::iterator it = costs.begin();
    std::string lowestCostNode = "";
    int lowestCost = INT_MAX;

    std::cout << "Lowest cost defined: " << lowestCost << std::endl;
    for(; it != costs.end(); it++) {
        std::cout << "Comparation node and price: " << it->first << " ----- " << it->second << std::endl;
        if (
            it->second < lowestCost &&
            std::find(processed.begin(), processed.end(), it->first) == processed.end()
        ) {
            std::cout << "findLowestCostNode condition fullfiled " << it->first << std::endl;
            lowestCost = it->second;
            lowestCostNode = it->first;
        }
    }

    return lowestCostNode;
}


int main(int argc, char** argv) {
    // Define hashmap for graph
    GraphMap graph;
    populateGraph(graph);
    dipslayGraph(graph);

    // Define hashmap for costs
    ChildNodesMap costs;
    costs["a"] = graph["start"]["a"];
    costs["b"] = graph["start"]["b"];
    costs["c"] = INT_MAX;
    costs["d"] = INT_MAX;
    costs["finish"] = INT_MAX;

    // Define hashmap for parents
    std::map<std::string, std::string> parents;
    parents["a"] = "start";
    parents["b"] = "start";
    parents["c"] = "";
    parents["d"] = "";
    parents["finish"] = "";

    // Define vector for processed
    std::vector<std::string> processed;

    // Apply djikstra
    std::string node = findLowestCostNode(costs, processed);
    while(!node.empty()) {
        std::cout << "Inside " << node << std::endl;
        ChildNodesMap neighbours = graph[node];
        ChildNodesMap::iterator it = neighbours.begin();
        int cost = costs[node];

        for(; it != neighbours.end(); it++) {
            int newCost = cost + it->second;
            if(costs[it->first] > newCost) {
                costs[it->first] = newCost;
                parents[it->first] = it->first;
            }
        }
        processed.push_back(node);
        node = findLowestCostNode(costs, processed);
    }
}


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

typedef std::map<std::string, std::string> ParentsMap;
typedef std::map<std::string, int> ChildNodesMap;
typedef std::map<std::string, ChildNodesMap > GraphMap;

// Define hashmap for graph
GraphMap graph;

// Define hashmap for costs
ChildNodesMap costs;

// Define hashmap for parents
ParentsMap parents;

// Define vector for processed
std::vector<std::string> processed;

void populateGraph() {
    graph["start"]["a"] = 5;
    graph["start"]["b"] = 2;

    graph["a"]["c"] = 4;
    graph["a"]["d"] = 2;

    graph["b"]["a"] = 8;
    graph["b"]["d"] = 7;

    graph["c"]["d"] = 6;
    graph["c"]["finish"] = 3;

    graph["d"]["finish"] = 1;

    graph["finish"];
}

void populateCostsAndParents(std::string startNode) {
    GraphMap::iterator it = graph.begin();
    ChildNodesMap neighbours = graph[startNode];
    for(; it != graph.end(); it++) {
        if(it->first == startNode) {
            continue;
        }

        if(neighbours.count(it->first)) {
            costs[it->first] = neighbours[it->first];
            parents[it->first] = startNode;
        }
        else {
            costs[it->first] = INT_MAX;
            parents[it->first] = "";
        }
    }
}

void dipslayGraph() {
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

void displayCosts(int iteration) {
    std::cout << "Costs: " << std::endl;

    ChildNodesMap::iterator it = costs.begin();
    for(; it != costs.end(); it++) {
        std::cout << it->first << " = " << it->second << std::endl;
    }
    std::cout << std::endl;
}

void displayParents(int iteration) {
    std::cout << "Parents: " << std::endl;
    ParentsMap::iterator it = parents.begin();
    for(; it != parents.end(); it++) {
        std::cout << it->first << " = " << it->second << std::endl;
    }
}

void displayIterationLogs(int iteration) {
    std::cout << iteration << ". iteration: " << std::endl;
    std::cout << "-----------------------------------------------" << std::endl;
    displayCosts(iteration);
    displayParents(iteration);
    std::cout << "-----------------------------------------------" << std::endl << std::endl;
}

std::string findLowestCostNode() {
    ChildNodesMap::iterator it = costs.begin();
    std::string lowestCostNode = "";
    int lowestCost = INT_MAX;

    for(; it != costs.end(); it++) {
        if (
            it->second < lowestCost &&
            std::find(processed.begin(), processed.end(), it->first) == processed.end()
        ) {
            lowestCost = it->second;
            lowestCostNode = it->first;
        }
    }

    std::cout << "Found lowest cost node: " << lowestCostNode << std::endl << std::endl;
    return lowestCostNode;
}


int main(int argc, char** argv) {
    populateGraph();
    dipslayGraph();

    populateCostsAndParents("start");

    int counter = 1;
    displayIterationLogs(counter);


    // Apply djikstra
    std::string node = findLowestCostNode();
    while(!node.empty()) {
        ChildNodesMap neighbours = graph[node];
        ChildNodesMap::iterator it = neighbours.begin();
        int cost = costs[node];

        for(; it != neighbours.end(); it++) {
            int newCost = cost + it->second;
            if(costs[it->first] > newCost) {
                costs[it->first] = newCost;
                parents[it->first] = node;
            }
        }
        processed.push_back(node);

        counter++;
        displayIterationLogs(counter);
        node = findLowestCostNode();
    }

    std::cout << "Shortest path: finish <- ";
    node = parents["finish"];
    while(node != "start") {
        std::cout << node << " <- ";
        node = parents[node];
    }
    std::cout << "start (" << costs["finish"] << ")" << std::endl;
}


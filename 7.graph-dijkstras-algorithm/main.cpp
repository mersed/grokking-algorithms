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
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <string>

#define DEBUG (1==1)

using namespace std;

template <class T>
void displayList(list<T> &v) {
    cout << "{";
    auto it = v.begin();
    for(; it != v.end(); it++) {
        cout << *it << ",";
    }
    cout << "}" << endl;
}

void insertToQueue(list<string> &list, vector<string> &v) {
    auto it = v.begin();
    for(; it != v.end(); it++) {
        list.push_back(*it);
    }
}

int main(int argc, char** argv) {
    /*map<string, vector<string>> graph;
    list<string> queue{};
    vector<string> searched{};

    // Creating a graph using hashmap (simple implementation)
    graph.insert({ "you", {"alice", "bob", "claire"} });
    graph.insert({ "bob", {"anuj", "peggy", "you"} });
    graph.insert({ "alice", {"peggy", "dude", "you"} });
    graph.insert({ "claire", {"thom", "jonny"} });
    graph.insert({ "anuj", {"dude"} });
    graph.insert({ "peggy", {} });
    graph.insert({ "thom", {} });
    graph.insert({ "jonny", {} });

    string start = "you";
    string search = "dude";
    queue.push_back(start);
    // breadth first implementation
    // searching a value from start using shortest way
    // in our example we are starting from "you" and we are searching "dude"
    while(!queue.empty()) {
        if(DEBUG) {
            cout << "Queue: ";
            displayList(queue);
        }

        string temp = queue.front();
        queue.pop_front();
        if (std::find(searched.begin(), searched.end(), temp) == searched.end()) {
            searched.push_back(temp);
            if(temp == search) {
                cout << "Found value: " << temp;
                cout << endl;
                break;
            }


            insertToQueue(queue, graph[temp]);
        }
    }
    */

    cout << "Testing here additionally" << endl;
}


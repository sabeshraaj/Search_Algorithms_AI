#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <limits>

using namespace std;

struct Node {
    int heuristic;
    string type;  // "OR" or "AND"
    vector<string> children;
    int cost;
    bool solved;
    string best_child;
};

class AOStarGraph {
public:
    unordered_map<string, Node> nodes;

    AOStarGraph() {
        // Define nodes with heuristic, type, and children
        nodes["A"] = {2, "OR", {"B", "C"}, numeric_limits<int>::max(), false, ""};
        nodes["B"] = {1, "AND", {"D", "E"}, numeric_limits<int>::max(), false, ""};
        nodes["C"] = {3, "OR", {"F"}, numeric_limits<int>::max(), false, ""};
        nodes["D"] = {2, "AND", {}, 0, true, ""};
        nodes["E"] = {1, "AND", {}, 0, true, ""};
        nodes["F"] = {4, "AND", {}, 0, true, ""};
    }

    int recursiveAOStar(const string& node) {
        Node& current_node = nodes[node];
        cout << "\nExploring node: " << node << endl;

        // Return cost if already solved
        if (current_node.solved) {
            cout << "Node " << node << " already solved with cost " << current_node.cost << endl;
            return current_node.cost;
        }

        if (current_node.type == "OR") {
            // Process OR-type node by finding the child with minimum cost
            int min_cost = numeric_limits<int>::max();
            string best_child;
            for (const string& child : current_node.children) {
                cout << "Examining OR child: " << child << endl;
                int child_cost = recursiveAOStar(child);
                int total_cost = child_cost + current_node.heuristic;
                if (total_cost < min_cost) {
                    min_cost = total_cost;
                    best_child = child;
                }
            }
            current_node.cost = min_cost;
            current_node.best_child = best_child;
            current_node.solved = true;
            cout << "OR node " << node << " solved with cost " << min_cost << ", best child: " << best_child << endl;
            return min_cost;
        } else if (current_node.type == "AND") {
            // Process AND-type node by summing up all children costs
            int total_cost = current_node.heuristic;
            for (const string& child : current_node.children) {
                int child_cost = recursiveAOStar(child);
                total_cost += child_cost;
            }
            current_node.cost = total_cost;
            current_node.solved = true;
            cout << "AND node " << node << " solved with total cost " << total_cost << endl;
            return total_cost;
        }

        return numeric_limits<int>::max();  // Fallback, should not reach here
    }

    int aoStar(const string& start) {
        int total_cost = recursiveAOStar(start);
        cout << "Total cost from start to goal: " << total_cost << endl;
        return total_cost;
    }
};

int main() {
    AOStarGraph graph;
    cout<<"AO* Algorithm"<<endl;
    graph.aoStar("A");
    return 0;
}

#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        unordered_map<int, Node*> recreated_nodes; //{value, node}
        queue<pair<Node*, Node*>> nodes_to_complete; //{old_node, new_node}
        Node* first_node = new Node(1); //given node always has a value of 1
        nodes_to_complete.push(pair<Node*,Node*>(node, first_node));

        //assumes the node in `nodes_to_complete` already has the deep copy created
        while (!nodes_to_complete.empty()) {
            pair<Node*,Node*> current_node = nodes_to_complete.front();
            nodes_to_complete.pop();

            //go through each neighbour in the original graph
            for(Node* neighbour : current_node.first->neighbors) {

                
                //if the node was already created (it is in recreated_nodes),
                //then we just get our deep-copy current node to point at it
                if (recreated_nodes.count(neighbour->val)) {
                    current_node.second->neighbors.push_back(recreated_nodes.at(neighbour->val));
                }

                //otherwise, we will create that new node, point at it, and add it to the list of ones to operate on
                else {
                    Node* new_node = new Node{neighbour->val};
                    recreated_nodes.emplace(neighbour->val, new_node);
                    nodes_to_complete.push(pair<Node*,Node*>(neighbour, new_node));
                    current_node.second->neighbors.push_back(new_node);
                }
            }
        }

        return first_node;

    }
};
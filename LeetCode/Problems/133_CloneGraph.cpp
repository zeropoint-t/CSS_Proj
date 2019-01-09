// 133. Clone Graph
// Medium

// Given the head of a graph, return a deep copy (clone) of the graph. Each node in the graph contains a label (int) and a list (List[UndirectedGraphNode]) of its neighbors. There is an edge between the given node and each of the nodes in its neighbors.

// OJ's undirected graph serialization (so you can understand error output):
// Nodes are labeled uniquely.

// We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
 

// As an example, consider the serialized graph {0,1,2#1,2#2,2}.

// The graph has a total of three nodes, and therefore contains three parts as separated by #.

// First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
// Second node is labeled as 1. Connect node 1 to node 2.
// Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
 

// Visually, the graph looks like the following:

//        1
//       / \
//      /   \
//     0 --- 2
//          / \
//          \_/
// Note: The information about the tree serialization is only meant so that you can understand error output if you get a wrong answer. You don't need to understand the serialization to solve the problem.


#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <queue>

using namespace std;

// Definition for undirected graph.
struct UndirectedGraphNode {
      int label;
      vector<UndirectedGraphNode *> neighbors;
      UndirectedGraphNode(int x) : label(x) {};
 };
 
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        set<UndirectedGraphNode*> visitedNodes;
        queue<UndirectedGraphNode*> os;
        queue<UndirectedGraphNode*> ns;
        UndirectedGraphNode* origHead = node;
        UndirectedGraphNode* newHead = new UndirectedGraphNode(origHead->label);

        os.push(origHead);
        ns.push(newHead);

        visitedNodes.insert(origHead);
        while(!os.empty()){
            vector<UndirectedGraphNode*> nbrs = os.front()->neighbors;
            os.pop();
            UndirectedGraphNode* curNode = ns.front();
            ns.pop();
            for(auto it = nbrs.begin(); it != nbrs.end(); it++){
                auto visitedNode = visitedNodes.find(*it);
                if(visitedNode == visitedNodes.end()){
                    UndirectedGraphNode* n = new UndirectedGraphNode((*it)->label);
                    curNode->neighbors.push_back(n);
                    os.push(*it);
                    ns.push(n);
                    visitedNodes.insert(*it);
                }
            }
        }

        return newHead;
    }

    void display(UndirectedGraphNode* head){
        queue<UndirectedGraphNode*> s;
        set<UndirectedGraphNode*> visitedNodes;
        s.push(head);
        visitedNodes.insert(head);
        while(!s.empty()){
            UndirectedGraphNode* curNode = s.front();
            s.pop(); 
            cout << curNode->label << " at " << curNode << endl;
            for(auto it = curNode->neighbors.begin(); it != curNode->neighbors.end(); it++){
                auto visitedNode = visitedNodes.find(*it);
                if(visitedNode == visitedNodes.end()){
                    s.push(*it);
                    visitedNodes.insert(*it);
                }
            }
        }
    }
};

int main(){
    UndirectedGraphNode* n1 = new UndirectedGraphNode(1);
    UndirectedGraphNode* n2 = new UndirectedGraphNode(2);
    UndirectedGraphNode* n3 = new UndirectedGraphNode(3);
    UndirectedGraphNode* n4 = new UndirectedGraphNode(4);

    n1->neighbors.push_back(n2);
    n1->neighbors.push_back(n3);
    n2->neighbors.push_back(n1);
    n2->neighbors.push_back(n4);
    n3->neighbors.push_back(n1);
    n3->neighbors.push_back(n4);
    n4->neighbors.push_back(n2);
    n4->neighbors.push_back(n3);

    Solution s;
    s.display(n1);

    cout << endl;

    UndirectedGraphNode* newNode = s.cloneGraph(n1);
    s.display(newNode);

    cout << endl;
    s.display(n1);

    cout << endl;
    s.display(n2);
}
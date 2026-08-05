/*
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
*/

class Solution {
public:
    Node* dfs(Node* node, unordered_map<Node*,Node*>&mp)
    {
        if(node==NULL)
        return NULL;
        //if node in map return clone 
        if(mp.find(node)!=mp.end())
        return mp[node];
        //otherwise never seen before clone it
        Node* clone=new Node(node->val);
        mp[node]=clone;
        //ooo mgg
        for(auto neighbor : node->neighbors)
        clone->neighbors.push_back(dfs(neighbor,mp));
        return clone;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*>mp;
        auto res=dfs(node,mp);
        return res;
    }
};

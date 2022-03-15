#include <iostream>
#include <vector>

using namespace std;

// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
public:

    Node* rec(vector<vector<int>>& grid, int rl, int rr, int cl, int cr)
    {
        bool f = 1;
        for (int i = rl; i < rr;++i)
        {
            for (int j = cl; j < cr; ++j)
            {
                if(grid[i][j] != grid[rl][cl])
                {
                    f = 0;
                    break;
                }
            }
            if(!f)
                break;
        }
        if(f)
            return new Node(grid[rl][cl], true);

        int midr = (rl + rr) / 2, midc = (cl + cr) / 2;
        Node *tl = rec(grid, rl, midr, cl, midc);
        Node *tr = rec(grid, rl, midr, midc, cr);
        Node *bl = rec(grid, midr, rr, cl, midc);
        Node *br = rec(grid, midr, rr, midc, cr);
        return new Node(0, 0, tl, tr, bl, br);
    }
    
    Node* construct(vector<vector<int>>& grid)
    {
        int n = grid.size();
        return rec(grid, 0, n, 0, n);
    }
};
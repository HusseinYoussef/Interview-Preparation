#include <vector>

using namespace std;

class NestedInteger {
  public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator {
public:
    int idx;
    vector<int> res;
    void rec(const vector<NestedInteger> &nestedList)
    {
        for (int i = 0; i < nestedList.size();++i)
        {
            if(nestedList[i].isInteger())
                res.push_back(nestedList[i].getInteger());
            else
                rec(nestedList[i].getList());
        }
    }

    NestedIterator(vector<NestedInteger> &nestedList)
    {
        rec(nestedList);
        idx = 0;
    }
    
    int next() {
        return res[idx++];
    }
    
    bool hasNext() {
        return idx != res.size();
    }
};
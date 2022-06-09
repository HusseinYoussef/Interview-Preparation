#include <vector>

using namespace std;

bool compareRoot(vector<int> &arr1, vector<int> &arr2)
{
    if(arr1.size() == 0 && arr2.size() == 0)
        return true;
    
    if(arr1[0] != arr2[0])
        return false;

    vector<int> leftSubtree1;
    vector<int> leftSubtree2;
    vector<int> rightSubtree1;
    vector<int> rightSubtree2;

    for (int i = 1; i < arr1.size();++i)
    {
        if(arr1[i] < arr1[0])
            leftSubtree1.push_back(arr1[i]);
        else
            rightSubtree1.push_back(arr1[i]);

        if(arr2[i] < arr2[0])
            leftSubtree2.push_back(arr2[i]);
        else
            rightSubtree2.push_back(arr2[i]);
    }
    return compareRoot(leftSubtree1, leftSubtree2) && compareRoot(rightSubtree1, rightSubtree2);
}

bool sameBsts(vector<int> arrayOne, vector<int> arrayTwo)
{
    if(arrayOne.size() != arrayTwo.size())
        return false;
    
    return compareRoot(arrayOne, arrayTwo);
}

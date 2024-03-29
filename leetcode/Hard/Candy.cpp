#include <vector>

using namespace std;

int candy(vector<int>& ratings)
{
    /*
    In this approach, we make use of two 1-d arrays left2right and right2left.
    The left2right array is used to store the number of candies required by the current student taking care of
    the distribution relative to the left neighbors only.
    i.e. Assuming the distribution rule is: The student with a higher rating than their left neighbor should always get more candies
    than its left neighbor.
    Similarly, the right2left array is used to store the number of candies required by the current student taking care of
    the distribution relative to the right neighbors only.
    i.e. Assuming the distribution rule to be: The student with a higher rating than their right neighbor should always get more candies
    than their right neighbor.
    To do so, firstly we assign 1 candy to each student in both the left2right and right2left arrays.
    Then, we traverse the array from left-to-right and whenever the current element's ratings is larger than the left neighbor
    we update the current element's candies in the left2right array as left2right[i] = left2right[i-1] + 1,
    since the current element's candies are always less than or equal candies than its left neighbor before updating.
    After the forward traversal, we traverse the array from left-to-right and update right2left[i] as right2left[i] = right2left[i + 1] + 1,
    whenever the current i'th element has a higher ratings than the right i+1'th element.

    Now, for the i'th student in the array, we need to give max(left2right[i], right2left[i]) to them,
    in order to satisfy both the left and the right neighbor relationship. 
    */
   
    int n = ratings.size();
    vector<int> left2right(n, 1);
    vector<int> right2left(n, 1);
    for (int i = 1; i < n;++i)
    {
        if(ratings[i] > ratings[i-1])
            left2right[i] = left2right[i - 1] + 1;
    }
    int sum = 0;
    for (int i = n-2; i >= 0;--i)
    {
        if(ratings[i] > ratings[i+1])
            right2left[i] = right2left[i + 1] + 1;
    }
    for (int i = 0; i < n;++i)
        sum += max(left2right[i], right2left[i]);
    return sum;
}
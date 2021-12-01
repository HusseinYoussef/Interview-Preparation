#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image)
{
    for(int i=0;i<image.size();++i)
    {
        int l=0, r = image[i].size()-1;
        while(l<=r)
        {
            swap(image[i][l], image[i][r]);
            image[i][l] = !image[i][l];
            if(l != r)
                image[i][r] = !image[i][r];
            ++l,--r;
        }
    }
    return image;
}
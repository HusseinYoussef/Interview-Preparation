#include <iostream>
#include <vector>

using namespace std;

bool generateDocument(string characters, string document)
{
    vector<int> freq(130, 0);
    for (int i = 0; i < characters.size();++i)
        ++freq[characters[i] - ' '];

    for (int i = 0; i < document.size();++i)
    {
        --freq[document[i] - ' '];
        if(freq[document[i] - ' '] < 0)
            return false;
    }
    return true;
}

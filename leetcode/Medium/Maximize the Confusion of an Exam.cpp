#include <string>
using namespace std;

int maxConsecutiveAnswers(string answerKey, int k)
{
    int n = answerKey.size();

    int tcount = 0, fcount = 0;
    int ans = 0;
    int l = 0, r = 0;
    while(r < n)
    {
        if((answerKey[r] == 'T' && tcount == max(fcount, tcount)) ||
            (answerKey[r] == 'F' && fcount == max(fcount, tcount)) )
        {
            tcount += answerKey[r] == 'T';
            fcount += answerKey[r] == 'F';
            ++r;
        }
        else
        {
            if(k)
            {
                tcount += answerKey[r] == 'T';
                fcount += answerKey[r] == 'F';
                --k;
                ++r;
            }
            else
            {
                k += (answerKey[l] == 'T' && tcount != max(fcount, tcount)) || 
                    (answerKey[l] == 'F' && fcount != max(fcount, tcount));

                tcount -= answerKey[l] == 'T';
                fcount -= answerKey[l] == 'F';
                ++l;
            }
        }
        ans = max(ans, r - l);
    }
    return ans;        
}

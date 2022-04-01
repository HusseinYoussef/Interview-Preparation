
/*
    Problem Statement

    The Fibonacci sequence is defined as follows: the first number of the sequence is 0 and the nth number is the sum of the (n - 1)th
    and (n - 2)th numbers. Write a function that takes in an integer n and return the nth Fibonacci number.
  
*/

using namespace std;

int getNthFib(int n)
{
    // 0 1 1 2 3 5 8 ...
    if(n <= 2)
        return n - 1;
    int prepre = 0, pre = 1;
    int cur = 0;
    for (int i = 3; i <= n;++i)
    {
        cur = prepre + pre;
        prepre = pre;
        pre = cur;
    }
    return cur;
}
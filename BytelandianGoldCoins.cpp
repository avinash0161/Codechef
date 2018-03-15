#include <iostream>
#include <string>
#include <stdio.h>
#include<vector>
using namespace std;

long long* maxDollars = NULL;

static void findMaxDollars(long long n) {
    if(n < 0)
    {
        return;
    }
    maxDollars = new long long[n+1];
    maxDollars[0] = 0;

    for(long long x = 1; x<=n; x++)
    {
        long long brokenSum = maxDollars[x/2] + maxDollars[x/3] + maxDollars[x/4];
        if(brokenSum<x)
        {
            maxDollars[x] = x;
        }
        else
        {
            maxDollars[x] = brokenSum;
        }
    }
}

int main() {
    vector<long long> inputs;

    long long maxInput = -1;
    long long n;

    while (scanf("%lld",&n)!=EOF)
    {

        if(maxInput < n)
        {
            maxInput = n;
        }
        inputs.push_back(n);
    }

    findMaxDollars(maxInput);

    for(int i =0 ; i<inputs.size(); i++)
    {
        cout<<maxDollars[inputs[i]]<<endl;
    }
    return 0;
}
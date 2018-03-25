//
// Created by Avinash Kumar on 3/24/18.
//

// A Dynamic Programming solution for subset sum problem
#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool splitArraySameAverage() {
        int sum = 0;
        vector<int> A = {6,8,18,3,1};
        for(int i=0; i<A.size(); i++)
        {
            sum += A[i];
        }
        double avg = (sum*1.0)/(A.size()*1.0);

        vector<vector<int>> subsetSum;
        subsetSum.resize(A.size() + 1);
        for(int i=0; i<=A.size(); i++)
        {
            subsetSum[i].resize(sum+1);
        }

        for(int i=0; i<=A.size(); i++)
        {
            subsetSum[i][0] = 0;
        }
        for(int i=1; i<=sum; i++)
        {
            subsetSum[0][i] = -1;
        }
        for(int i=1;i<=A.size(); i++)
        {
            for(int j=1;j<=sum; j++)
            {
                if(A[i-1]>j)
                {
                    subsetSum[i][j] = subsetSum[i-1][j];
                }
                else
                {
                    if(subsetSum[i-1][j-A[i-1]] >= 0)
                    {
                        subsetSum[i][j] = subsetSum[i-1][j-A[i-1]] + 1;
                    }
                    else if(subsetSum[i-1][j] >= 0)
                    {
                        subsetSum[i][j] = subsetSum[i-1][j];
                    }
                    else
                    {
                        subsetSum[i][j] = -1;
                    }
                }
            }
        }

        for(int i=0;i<=A.size();i++) {
            for (int j = 0; j <= sum; j++) {
                cout<< subsetSum[i][j]<<", ";
            }
            cout<<endl;
        }

        for(int i=1;i<=A.size();i++)
        {
            for(int j=1;j<=sum; j++)
            {

                if(subsetSum[i][j] > 0 && subsetSum[i][j] != A.size())
                {
                    double a = (j*1.0)/(subsetSum[i][j]*1.0);
                    if(a==avg)
                    {
                        cout<<i<<" "<<j<<" "<<avg<<" "<<a<<endl;
                        return true;
                    }
                }
            }

        }

        return false;
    }
};

// Driver program to test above function
int main()
{
    Solution sol;
    cout<<sol.splitArraySameAverage();
    return 0;
}
// This code is contributed by Arjun Tyagi.

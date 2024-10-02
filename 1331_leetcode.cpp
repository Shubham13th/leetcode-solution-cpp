// 1331. Rank Transform of an Array

// Given an array of integers arr, replace each element with its rank.

// The rank represents how large the element is. The rank has the following rules:

// Rank is an integer starting from 1.
// The larger the element, the larger the rank. If two elements are equal, their rank must be the same.
// Rank should be as small as possible.

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class solution
{
    public:
    vector<int> arrayRankTransform(vector<int> &arr)
    {

        map<int,int>myMap;
        vector<int>sortedArr(arr);
        sort(sortedArr.begin(),sortedArr.end());

        int rank = 1;

        for(int i=0;i<sortedArr.size();i++){
            if(i>0 && sortedArr[i] > sortedArr[i-1]){
                rank++;
            }
            myMap[sortedArr[i]] = rank;
        }

        for(int i=0;i<arr.size();i++){
            arr[i] = myMap[arr[i]];
        }

        return arr;
    }
};

int main()
{
    solution obj;

    vector<int>arr = {10,90,30,20,50,30};

    obj.arrayRankTransform(arr);

    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}

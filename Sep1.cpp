//-----------------------------------------------------GFG----------------------------------------------------------------------------------


//Max sum path in two arrays 

/*
Given two sorted arrays of distinct integers arr1 and arr2. Each array may have some elements in common with the other array. 
Find the maximum sum of a path from the beginning of any array to the end of any array. 
You can switch from one array to another array only at the common elements.
Note:  When we switch from one array to other,  we need to consider the common element only once in the result.
*/

class Solution {
  public:
    int maxPathSum(vector<int> &arr1, vector<int> &arr2)
    {
        // Code here
        int i = 0, j = 0;
        int sum1 = 0, sum2 = 0, result = 0;
        int n = arr1.size(), m = arr2.size();

        // Traverse both arrays
        while (i < n && j < m)
        {
            if (arr1[i] < arr2[j])
            {
                sum1 += arr1[i];
                i++;
            }
            else if (arr1[i] > arr2[j])
            {
                sum2 += arr2[j];
                j++;
            }
            else
            { // arr1[i] == arr2[j]
                result += max(sum1, sum2) + arr1[i];
                sum1 = sum2 = 0; // Reset sums after considering the common element
                i++;
                j++;
            }
        }

        // Add remaining elements of arr1
        while (i < n)
        {
            sum1 += arr1[i];
            i++;
        }

        // Add remaining elements of arr2
        while (j < m)
        {
            sum2 += arr2[j];
            j++;
        }

        // Add the maximum of the remaining sums
        result += max(sum1, sum2);

        return result;
        // Code here
    }
};


---------------------------------------------------------------------Leetcode------------------------------------------------------------------

/* 2022. Convert 1D Array Into 2D Array

You are given a 0-indexed 1-dimensional (1D) integer array original, and two integers, m and n. You are tasked with creating a 2-dimensional (2D) array with  m rows and n columns using all the elements from original.
The elements from indices 0 to n - 1 (inclusive) of original should form the first row of the constructed 2D array, the elements from indices n to 2 * n - 1 (inclusive) should form the second row of the constructed 2D array, and so on.
Return an m x n 2D array constructed according to the above procedure, or an empty 2D array if it is impossible.*/

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
            vector<vector<int>> ans(m, vector<int>(n));
            int a=0;
            if(m*n != original.size())
            {
                return {};
            }
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    ans[i][j]=original[a];
                    a++;
                }      
            }
            return ans;
    }
};




//-----------------------------------------------------GFG----------------------------------------------------------------------------------


/*
Minimum Cost Path

Given a square grid of size N, each cell of which contains an integer cost that represents a cost to traverse through that cell, we need to find a path from the top left cell to the bottom right cell by which the total cost incurred is minimum.
From the cell (i,j) we can go (i,j-1), (i, j+1), (i-1, j), (i+1, j). 
*/

class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        // Code here
        int dx[]={1,-1,0,0,1,1,-1,-1};
        int dy[]={0,0,1,-1,1,-1,1,-1};
        int n=grid[0].size();
        vector<vector<int>>dis(n,vector<int>(n,1e7));
        dis[0][0]=grid[0][0];
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({dis[0][0],{0,0}});
        while(!pq.empty()){
            pair<int,int>p=pq.top().second;
            int curD=pq.top().first;
            int x=p.first;
            int y=p.second;
            pq.pop();
            if(curD<dis[x][y])continue;
            for(int i=0;i<4;i++){
                int x1=x+dx[i];
                int y1=y+dy[i];
                if(x1>=0 && x1<n && y1>=0 && y1<n && curD+grid[x1][y1]<dis[x1][y1]){
                    dis[x1][y1]=curD+grid[x1][y1];
                    pq.push({dis[x1][y1],{x1,y1}});
                }
            }
        }
        return dis[n-1][n-1];
    }
};


---------------------------------------------------------------------Leetcode------------------------------------------------------------------

/* 
1894. Find the Student that Will Replace the Chalk

There are n students in a class numbered from 0 to n - 1. 
The teacher will give each student a problem starting with the student number 0, then the student number 1, and so on until the teacher reaches the student number n - 1. 
After that, the teacher will restart the process, starting with the student number 0 again.
You are given a 0-indexed integer array chalk and an integer k. 
There are initially k pieces of chalk. When the student number i is given a problem to solve, they will use chalk[i] pieces of chalk to solve that problem. However, if the current number of chalk pieces is strictly less than chalk[i], then the student number i will be asked to replace the chalk.

Return the index of the student that will replace the chalk pieces.
*/

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int sz = chalk.size();
        long sum = 0;
        for(auto &ele : chalk) sum += ele*1L;
        int number = k / sum;
        k = k - number * sum;
        for(int i = 0 ; i < sz ; i++){
            if(chalk[i] > k) return i;
            k -= chalk[i];
        }
        return -1;
    }
};


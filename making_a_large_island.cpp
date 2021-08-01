// Source : Leetcode
// Author : Kiran <kirannd89@gmail.com
// Date   : 1 Aug 2020

/********************************************************************************** 
* 
*   Making A Large Island
* You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.

Return the size of the largest island in grid after applying this operation.

An island is a 4-directionally connected group of 1s.

 

Example 1:

Input: grid = [[1,0],[0,1]]
Output: 3
Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
Example 2:

Input: grid = [[1,1],[1,0]]
Output: 4
Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.
Example 3:

Input: grid = [[1,1],[1,1]]
Output: 4
Explanation: Can't change any 0 to 1, only one island with area = 4.
 

Constraints:

n == grid.length
n == grid[i].length
1 <= n <= 500
grid[i][j] is either 0 or 1.
*               
**********************************************************************************/

#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:

    int count_island(int i, int j ,int grid_value, vector<vector<int>> &grid)
    {

        int m = grid.size();
        int n = grid[0].size();

        if(i >= m || i < 0 || j >= n || j < 0 || grid[i][j] != 1)
            return 0;

        grid[i][j] = grid_value;
        
        return 1 + count_island(i+1, j, grid_value, grid) +
        count_island(i-1, j, grid_value, grid) +
        count_island(i, j+1, grid_value, grid) +
        count_island(i, j-1, grid_value, grid) ;
    
    }

    int largestIsland(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        unordered_map<int, int> island_val;
        int map_index = 2;
        int max_result;
        island_val[2] = 0 ;
        island_val[0] = 0 ;

        for( int i = 0; i< m; i++){
            for( int j = 0; j< n; j++){
                if(grid[i][j] ==  1){
                    int count = count_island(i, j, map_index, grid);
                    island_val[map_index] = count;
                    cout << map_index << "\t" << count << endl;
                    map_index++;
                }
            }
        }

        max_result = island_val[2];

        for( int i = 0; i < m; i++){
            for(int j =0; j < n; j++){
                if (grid[i][j] == 0){
                    set<int> temp;
                    int result = 1;
                    temp.insert(i > 0 ? grid[i-1][j] : 0);
                    temp.insert(j > 0 ? grid[i][j-1] : 0);
                    temp.insert(i < m-1 ? grid[i+1][j] : 0);
                    temp.insert(j < n-1 ? grid[i][j+1] : 0);

                    for(auto a : temp){
                        result += island_val[a];
                    }
                    max_result = max(result, max_result);
                }
            }
        }
    return max_result;        
    }
};


int main()
{
    vector<vector<int>>grid{{0,1},{0,1}};
    Solution a;
    cout << a.largestIsland(grid) << endl;
    return 0;
}


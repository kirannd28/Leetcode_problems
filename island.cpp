// Source : https://leetcode.com/problems/number-of-islands/
// Author : Kiran <kirannd89@gmail.com
// Date   : 25 May 2021

/********************************************************************************** 
* 
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input: grid = {
  {'1','1','1','1','0'},
  {'1','1','0','1','0'},
  {'1','1','0','0','0'},
  {'0','0','0','0','0'}
}
Output: 1
Example 2:

Input: grid = {
  {'1','1','0','0','0'},
  {'1','1','0','0','0'},
  {'0','0','1','0','0'},
  {'0','0','0','1','1'}
}
Output: 3
* 
*               
**********************************************************************************/

#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:

    void reset_grid(vector<vector<char>>& grid, int i, int j, int m, int n){

            if(i < 0  || i >= m || j < 0 || j >= n)
                return;

            if(grid[i][j] == '1') {
                grid[i][j] = '0';
                reset_grid(grid, i+1, j, m, n);
                reset_grid(grid, i-1, j, m, n);
                reset_grid(grid, i, j+1, m, n);
                reset_grid(grid, i, j-1, m, n);
            }
    }

    int numIslands(vector<vector<char>>& grid) {

        int m = grid.size();
        int count = 0;
        if(m == 0)
            return 0;
        int n = grid[0].size();

        for(int i = 0; i< m; i++){
            for(int j = 0; j< n; j++) {
                if(grid[i][j] == '1'){
                    count++;
                    reset_grid(grid, i, j, m, n);
                }
            }
        }

        return count;
    }
};

int main()
{
    Solution input;
    vector<vector<char>> grid = {
  {'1','1','0','0','0'},
  {'1','1','0','0','0'},
  {'0','0','1','0','0'},
  {'0','0','0','1','1'}
};
  cout << input.numIslands(grid) << endl;

    return 0;
}
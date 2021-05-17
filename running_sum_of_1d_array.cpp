// Source : https://leetcode.com/problems/running-sum-of-1d-array/
// Author : Kiran <kirannd89@gmail.com
// Date   : 17 May 2021

/********************************************************************************** 

Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).
Return the running sum of nums.

Example 1:
Input: nums = [1,2,3,4]
Output: [1,3,6,10]
Explanation: Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].

Example 2:
Input: nums = [1,1,1,1,1]
Output: [1,2,3,4,5]
Explanation: Running sum is obtained as follows: [1, 1+1, 1+1+1, 1+1+1+1, 1+1+1+1+1].

Example 3:
Input: nums = [3,1,2,10,1]
Output: [3,4,6,16,17]
 
Constraints:
1 <= nums.length <= 1000
-10^6 <= nums[i] <= 10^6
               
**********************************************************************************/

#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        if (n == 0)
            return result;
        result[0] = nums[0];
        for(int i = 1; i< n; i++)
            result[i] = result[i-1] + nums[i];
        return result;
    }
};

int main()
{
    Solution temp;
    vector<int> testcase = {1,2,3,4,5};
    vector<int> result = temp.runningSum(testcase);
    for(auto a : result)
        cout << a << "\t";
    cout << endl;
    return 0;
}
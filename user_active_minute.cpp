// Source : https://leetcode.com/problems/finding-the-users-active-minutes/
// Author : Kiran <kirannd89@gmail.com
// Date   : 26 May 2021

/********************************************************************************** 
* 
You are given the logs for users' actions on LeetCode, and an integer k. The logs are represented by a 2D integer array logs where each logs{i} = {IDi, timei} indicates that the user with IDi performed an action at the minute timei.

Multiple users can perform actions simultaneously, and a single user can perform multiple actions in the same minute.

The user active minutes (UAM) for a given user is defined as the number of unique minutes in which the user performed an action on LeetCode. A minute can only be counted once, even if multiple actions occur during it.

You are to calculate a 1-indexed array answer of size k such that, for each j (1 <= j <= k), answer{j} is the number of users whose UAM equals j.

Return the array answer as described above.

 

Example 1:

Input: logs = {{0,5},{1,2},{0,2},{0,5},{1,3}}, k = 5
Output: {0,2,0,0,0}
Explanation:
The user with ID=0 performed actions at minutes 5, 2, and 5 again. Hence, they have a UAM of 2 (minute 5 is only counted once).
The user with ID=1 performed actions at minutes 2 and 3. Hence, they have a UAM of 2.
Since both users have a UAM of 2, answer{2} is 2, and the remaining answer{j} values are 0.
Example 2:

Input: logs = {{1,1},{2,2},{2,3}}, k = 4
Output: {1,1,0,0}
Explanation:
The user with ID=1 performed a single action at minute 1. Hence, they have a UAM of 1.
The user with ID=2 performed actions at minutes 2 and 3. Hence, they have a UAM of 2.
There is one user with a UAM of 1 and one with a UAM of 2.
Hence, answer{1} = 1, answer{2} = 1, and the remaining values are 0.
 

Constraints:

1 <= logs.length <= 104
0 <= IDi <= 109
1 <= time_i <= 105
k is in the range {The maximum UAM for a user, 105}.

* 
*               
**********************************************************************************/

#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) 
    {
        vector<int> result(k, 0);
        multimap<int, int> log_value;
        map<int, set<int>> data;

        for(auto a : logs)
            log_value.insert(pair<int, int>(a[0],a[1]));

        for(auto a = log_value.begin(); a != log_value.end(); ++a){
            set<int>& s(data[a->first]);
            s.insert(a->second);
        }

        for(auto a : data){
            result[a.second.size() - 1]++;
        }
        return result;
    }
};

int main()
{
    Solution test;
    vector<int> result;
    int k = 5;
    vector<vector<int>> logs = {{0,5},{1,2},{0,2},{0,5},{1,3}};
    result = test.findingUsersActiveMinutes(logs, k);
    for(auto a : result)
        cout << a  << "\t";
    return 0;
}
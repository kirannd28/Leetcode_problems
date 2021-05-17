// Source : https://leetcode.com/problems/palindrome-number/
// Author : Kiran <kirannd89@gmail.com
// Date   : 15 May 2021

/********************************************************************************** 
* 
* Given an integer x, return true if x is palindrome integer.
* 
* An integer is a palindrome when it reads the same backward as forward. 
* For example, 121 is palindrome while 123 is not.
* 
* Example 1:
* Input: x = 121
* Output: true
* 
* Example 2:
* Input: x = -121
* Output: false
* Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
* 
* Example 3:
* Input: x = 10
* Output: false
* Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
*
* Example 4:
* 
* Input: x = -101
* Output: false
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
    bool isPalindrome(int x) {
        if(x < 0)
            x = -x;
        //reverse a number;
        long int rev_num = x % 10;; 
        long int temp = x / 10;
        while(temp){
            rev_num = rev_num * 10 + temp % 10;
            temp = temp /10;
        }
        if(rev_num == x)
            return true;
        
        return false;
    }
};

int main()
{
    Solution val;
    int value = 121;
    cout << val.isPalindrome(value) << endl;
    return 0;
}
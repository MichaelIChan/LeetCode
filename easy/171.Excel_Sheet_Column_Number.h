/*
Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
    ...

Example 1:

Input: "A"
Output: 1

Example 2:

Input: "AB"
Output: 28
Example 3:

Input: "ZY"
Output: 701

Constraints:

1 <= s.length <= 7
s consists only of uppercase English letters.
s is between "A" and "FXSHRXW".

*/

#include <string>

using std::string;

class Solution {
public:
    int titleToNumber(string s) {
        int len = s.size(), ret = 0;

        for (int i = 0; i < len; ++i) {
            ret *= 26;
            ret += (s[i] - 'A' + 1);
        }

        return ret;
    }
};
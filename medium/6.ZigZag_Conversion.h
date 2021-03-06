/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
(you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);

Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"

Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I

Example 3:

Input: s = "A", numRows = 1
Output: "A"

Constraints:

1 <= s.length <= 1000
s consists of English letters (lower-case and upper-case), ',' and '.'.
1 <= numRows <= 1000

*/

#include <string>
#include <vector>
#include <cmath>

using namespace std;

class Solution1 {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        vector<string> rows = vector<string>(min(numRows, (int)s.size()));
        int curRow = 0;
        bool goingDown = false;
        for (int i = 0; i < s.size(); ++i) {
            rows[curRow] += s[i];
            if (curRow == 0 || curRow == numRows - 1) goingDown = !goingDown;
            curRow += goingDown ? 1 : -1;
        }

        string rst;
        for (int i = 0; i < rows.size(); ++i) {
            rst += rows[i];
        }
        return rst;
    }
};

class Solution2 {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        string rst = "";
        int cycleLen = 2 * numRows - 2;
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j + i < s.size(); j += cycleLen) {
                rst += s[j + i];
                if (i != 0 && i != numRows - 1 && j + cycleLen - i < s.size()) {
                    rst += s[j + cycleLen - i];
                }
            }
        }
        return rst;
    }
};
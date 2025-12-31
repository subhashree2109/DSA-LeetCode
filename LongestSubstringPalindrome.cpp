#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if(n <= 1) return s;

        int start = 0, maxLen = 1;

        auto expand = [&](int left, int right) {
            while(left >= 0 && right < n && s[left] == s[right]) {
                if(right - left + 1 > maxLen) {
                    start = left;
                    maxLen = right - left + 1;
                }
                left--;
                right++;
            }
        };

        for(int i = 0; i < n; i++) {
            expand(i, i);
            expand(i, i + 1);
        }
        return s.substr(start, maxLen);
    }
};

int main(){
    Solution s;
    cout << s.longestPalindrome("babad") << endl; // bab or aba
    cout << s.longestPalindrome("cbbd") << endl;  // bb
}

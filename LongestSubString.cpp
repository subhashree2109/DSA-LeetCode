#include <stdio.h>

// --- LeetCode Function ---
int lengthOfLongestSubstring(char* s) {
    int lastIndex[256]; // ASCII map
    for(int i = 0; i < 256; i++)
        lastIndex[i] = -1;

    int left = 0, maxLen = 0;

    for(int right = 0; s[right] != '\0'; right++) {
        if(lastIndex[(unsigned char)s[right]] >= left)
            left = lastIndex[(unsigned char)s[right]] + 1;

        lastIndex[(unsigned char)s[right]] = right;

        int len = right - left + 1;
        if(len > maxLen) maxLen = len;
    }
    return maxLen;
}

// --- Testing Code for VSCode ---
int main(){
    char s1[] = "abcabcbb";
    char s2[] = "bbbbb";
    char s3[] = "pwwkew";
    
    printf("Test 1: %d\n", lengthOfLongestSubstring(s1)); // 3
    printf("Test 2: %d\n", lengthOfLongestSubstring(s2)); // 1
    printf("Test 3: %d\n", lengthOfLongestSubstring(s3)); // 3

    return 0;
}

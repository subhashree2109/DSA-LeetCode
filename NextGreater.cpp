#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> nextGreater;
    stack<int> st;

    for (int num : nums2) {
        while (!st.empty() && num > st.top()) {
            nextGreater[st.top()] = num;
            st.pop();
        }
        st.push(num);
    }

    // Remaining elements have no next greater
    while (!st.empty()) {
        nextGreater[st.top()] = -1;
        st.pop();
    }

    vector<int> ans;
    for (int num : nums1)
        ans.push_back(nextGreater[num]);

    return ans;
}

int main() {
    vector<int> nums1 = {4,1,2};
    vector<int> nums2 = {1,3,4,2};

    vector<int> result = nextGreaterElement(nums1, nums2);

    for (int x : result)
        cout << x << " ";

    return 0;
}

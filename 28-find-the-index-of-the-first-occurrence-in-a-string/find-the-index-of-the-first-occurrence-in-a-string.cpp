class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        string newStr = needle + "$" + haystack;
        int n = newStr.size();
        vector<int> z(n, 0);
        int l = 0, r = 0;
        for (int i = 1; i < n; i++) {
            if (i <= r) z[i] = min(r - i + 1, z[i - l]);
            while (i + z[i] < n && newStr[z[i]] == newStr[i + z[i]]) 
                z[i]++;
            if (i + z[i] - 1 > r) {
                l = i;
                r = i + z[i] - 1;
            }
            if (z[i] == needle.size()) 
                return i - needle.size() - 1;
        }
        return -1;
    }
};

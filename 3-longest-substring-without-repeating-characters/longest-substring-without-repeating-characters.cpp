class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int n = s.length();
        int left = 0;
        std::unordered_map<char, int> map;
        int maxLen = 0;
        int right = 0;
        while (left < n && right < n) {
            char ch = s[right];
            if (map.find(ch) != map.end() && map[ch] >= left) {
                left = map[ch] + 1;
            }
            map[ch] = right;
            maxLen = std::max(maxLen, right - left + 1);
            right++;
        }
        return maxLen;
    }
};
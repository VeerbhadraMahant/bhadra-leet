class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xorEnd=0;
        for(int num:nums){
            xorEnd^=num;
        }
        return xorEnd;
    }
};
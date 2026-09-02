// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         for (int i=1;i<nums.size();i++){
//             if (nums[i]==nums[i-1])
//             return true;
//         }
//         return false;
//     }
// };

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int MIN = INT_MIN;
        int hashSize = nums.size() * 2;
        vector<int> hashTable(hashSize , MIN);
        for(int i = 0; i < nums.size(); i++) {
            int index = hashFunction(nums[i] , hashSize);
            while(hashTable[index] != MIN) {
                if(hashTable[index] == nums[i]){
                    return true;
                }
                else {
                    index = (index + 1) % hashSize;
                }
            }
            hashTable[index] = nums[i];
        }
        return false;
    }
private:
    int hashFunction(int key , int hashSize) {
        return ((key % hashSize) + hashSize) % hashSize;
    }
};
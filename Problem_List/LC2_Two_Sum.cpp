/*
Given an array of integers nums and an integer target, 
return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, 
and you may not use the same element twice.
*/
#include<iostream>
#include<vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>numToIndex;
        vector<int> result;
        for (int i =0; i<nums.size();i++){
            int complement = target - nums[i];
            if(numToIndex.find(complement)!=numToIndex.end()){
                result.push_back(numToIndex[complement]);
                result.push_back(i);
                break;
            }
            numToIndex[nums[i]] = i;
        }
        
        return result;
        
    }
};




int main() {
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    Solution solution;
    std::vector<int> result = solution.twoSum(nums, target);

    if (result.size() == 2) {
        std::cout << "Indices of the two numbers that add up to the target (" << target << "): "
                  << result[0] << " and " << result[1] << std::endl;
    } else {
        std::cout << "No two numbers found that add up to the target (" << target << ")." << std::endl;
    }

    return 0;
}
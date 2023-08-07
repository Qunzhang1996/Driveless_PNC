#include<iostream>
#include<vector>
using namespace std;
int searchRotatedArray(vector<int>&nums, int &target)
{
    int left = 0;
    int right = nums.size()-1;
    while(left<=right)
    {
        int mid =(left+right)/2;
        if(nums[mid]==target)
        {
            return mid;
        }
        if(nums[left]<=nums[mid])//which means that the left part is sorted
        {
            if(target>=nums[left]&&target<nums[mid])
            {
                right = mid-1;
            }
            else
            {
                left = mid+1;
            }
        }
        else//which means that the right part is sorted
        {
            if(target>=nums[mid]&&target<=nums[right])
            {
                left = mid+1;
            }
            else
            {
                right = mid-1;
            }
        }
    }
    
    return -1;
};


int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 2;

    int index = searchRotatedArray(nums, target);
    if (index != -1) {
        std::cout << "目标元素 " << target << " 在索引 " << index << " 处找到。" << std::endl;
    } else {
        std::cout << "目标元素 " << target << " 未找到。" << std::endl;
    }

    return 0;
}
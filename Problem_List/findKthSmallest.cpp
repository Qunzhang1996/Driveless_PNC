#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// int findKthSmallest(vector<int>&nums1, vector<int>&nums2, int k)
// {
//     vector<int> merged=nums1;
//     merged.insert(merged.end(),nums2.begin(),nums2.end());
//     sort(merged.begin(),merged.end());
//     return merged[k-1];
 
// };
int findKthSmallest(vector<int>&nums1, vector<int>&nums2, int k){
    int lens1 =nums1.size();
    int lens2 = nums2.size();
    int i=0;
    int j=0;
    vector<int>merged;
    while(i<lens1&&j<lens2)
    {
        if(nums1[i]<nums2[j])
        {
            merged.push_back(nums1[i]);
            i++;
        }else
        {
            merged.push_back(nums2[j]);
            j++;
        }
    }
    while (i < lens1) {
        merged.push_back(nums1[i]);
        i++;
        }

    while (j < lens2) {
        merged.push_back(nums2[j]);
        j++;
    }

    // 对合并后的数组排序
    std::sort(merged.begin(), merged.end());

    // 返回第 k 小的数
    return merged[k - 1];
};

int main() {
    vector<int> nums1 = {1, 3, 5};
    vector<int> nums2 = {2, 4, 6};
    int k = 6;

    int result = findKthSmallest(nums1, nums2, k);
    std::cout << "第 " << k << " 小的数是: " << result << std::endl;

    return 0;
}
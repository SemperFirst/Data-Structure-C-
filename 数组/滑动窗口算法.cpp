//给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的 连续 子数组，并返回其长度。如果不存在符合条件的子数组，返回 0。

//输入：s = 7, nums = [2,3,1,2,4,3] 输出：2 解释：子数组 [4,3] 是该条件下的长度最小的子数组。

//法一：暴力法
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int result = INT32_MAX; // 最终的结果
        int sum = 0; // 子序列的数值之和
        int subLength = 0; // 子序列的长度
        for (int i = 0; i < nums.size(); i++) { // 设置子序列起点为i
            sum = 0;
            for (int j = i; j < nums.size(); j++) { // 设置子序列终止位置为j
                sum += nums[j];
                if (sum >= s) { // 一旦发现子序列和超过了s，更新result
                    subLength = j - i + 1; // 取子序列的长度
                    result = result < subLength ? result : subLength;
                    break; // 因为我们是找符合条件最短的子序列，所以一旦符合条件就break
                }
            }
        }
        // 如果result没有被赋值的话，就返回0，说明没有符合条件的子序列
        return result == INT32_MAX ? 0 : result;
    }
};
//法二：滑动窗口法
//![image](https://user-images.githubusercontent.com/56592386/134514863-efe1d470-0610-4f67-b8cd-14de9abce03c.png)

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result=INT32_MAX;
        int sum=0;
        int i=0;
        int length=0;
        for(int j=0;j<nums.size();j++)
        {
            sum+=nums[j];
            while(sum>=target){
                length=j-i+1;
                result=result<length?result:length;
                sum -=nums[i++];
            }
        }
        return result==INT32_MAX?0:result;
    }
};

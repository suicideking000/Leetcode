#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) 
        {
            unordered_map<int,int>hashtable;
            int n=nums.size();
            for(int i=0; i<n;i++)
            {
                for(int j=i+1;j<n;j++)
                {
                    if(nums[i]+nums[j]==target)
                    {
                        return {i,j};
                    }
                }
            }

        return {};        
            
        }
    };


int main(void)
{
    vector<int> nums={2,7,11,15};
    int target=26;
    Solution s;
    vector<int> result=s.twoSum(nums,target);
    for(int i=0;i<result.size();i++)
    {
        cout<<result[i]<<endl;
    }
    return 0;

}
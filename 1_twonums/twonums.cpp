#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;



class Solution 
{
    public:
        vector<int> twoSum(vector<int>& nums, int target) 
        {
            unordered_map<int,int>hashmap;
            for(int i=0;i<nums.size();i++)
            {
                if(hashmap.count(target-nums[i])) return{hashmap[target-nums[i]],i};
                else hashmap.insert(pair<int,int>(nums[i],i));
            }
            return {};
        }
    
};

int main(void)
{
    vector<int>nums;
    vector<int>result;
    Solution slu;
    int num;
    int target;
    cout << "请输入数组:" << endl;
    while(cin>>num)
    {   
        nums.push_back(num);
        if(getchar() == '\n')
        break;
    }
    cout << "请输入目标值:" <<endl;
    cin >> target;

    result= slu.twoSum(nums,target);

    for(int i=0;i< result.size();i++)
    {
        cout<<result[i]<<endl;
    }

    return 0;
}
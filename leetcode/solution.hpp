#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class solution1{
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> mp;
		vector<int> ans;
		for(int i = 0; i < nums.size(); i++)
		{
			int c = target - nums[i];
			if(mp.count(c))
			{
				ans.push_back(mp[c]);
				ans.push_back(i);
				break;
			}
			mp[nums[i]] = i;
		}
		return ans;
	}
};



#include "solution.hpp"
#include <vector>
#include <unordered_map>

vector<int> solution1::twoSum(vector<int>& nums, int target) {
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
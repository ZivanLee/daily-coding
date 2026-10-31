#include "solution.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;


int main()
{
	vector<int> nums;
	int target;
	string s;
	getline(cin, s);
	stringstream ss(s);
	int x;
	while(ss >> x)
	{
		nums.push_back(x);
	}
	cin >> target;
	vector<int> ans = solution1().twoSum(nums, target);
	for(int i = 0; i < ans.size(); i++)
	{
		cout << ans[i];
	}
	cout << endl;
	return 0;
}

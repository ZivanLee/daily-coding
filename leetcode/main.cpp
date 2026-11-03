#include "solution.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <limits>
using namespace std;

string question[] = {
	"1. 两数之和",
	"2. 两数相加",
	"3. 无重复字符的最长子串",
	"4. 寻找两个正序数组的中位数",
	"5. 最长回文子串"
};

int main()
{
	int n = sizeof(question) / sizeof(question[0]);
	for(int i = 0; i < n; i++)
	{
		cout << question[i];
		if(i != n-1)
		{
			cout << endl;
		}
	}

	cout << endl;
	cout << "请输入题号： ";
	int q_num;
	cin >> q_num;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	switch(q_num)
	{
		case 4:
		{
			vector<int> nums1, nums2;
			string s;
			cout << "nums1 = ";
			getline(cin, s);
			stringstream s1(s);
			int x;
			while(s1 >> x)
			{
				nums1.push_back(x);
			}
			cout << "nums2 = ";
			getline(cin, s);
			stringstream s2(s);
			while(s2 >> x)
			{
				nums2.push_back(x);
			}
			
			double res = Solution4().findMedianSortedArrays(nums1, nums2);
			printf("%.5f\n", res);
			break;
		}
			
		case 5:
		{
			string s;
			cout << "s = ";
			getline(cin, s);
			string res = Solution5().longestPalindrome(s);
			cout << res;
			cout << endl;
			break;
		}
		default:
			cout << "没有此题！" << endl;
			break;


	}
	return 0;
}

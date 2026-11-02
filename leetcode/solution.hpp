#include <string>
#include <vector>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* node) : val(x), next(node) {} 
};

/* 1. 两数之和 */
class Solution1{
public:
	vector<int> twoSum(vector<int>& nums, int target);
};

/* 2. 两数相加 */
class Solution2 {
public:
	ListNode* addTwoNumbers(ListNode* head1, ListNode* head2);
};

/* 3. 无重复字符的最长子串 */
class Solution3 {
public:
	int lengthOfLongestSubstring(string s);
};

/* 4. 寻找两个正序数组的中位数 */
class Solution4 {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);
};
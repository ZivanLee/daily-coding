#include "solution.hpp"
#include <cstddef>
#include <vector>
#include <unordered_map>

vector<int> Solution1::twoSum(vector<int>& nums, int target) {
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

ListNode* Solution2::addTwoNumbers(ListNode* head1, ListNode* head2) {
    ListNode* hair = new ListNode(-1);
    int flag = 0;
    ListNode* pre = hair;
    while(head1 != nullptr || head2 != nullptr || flag != 0)
    {
        int sum = flag;
        int val;
        if(head2 != nullptr)
        {
            sum += head2->val;
            head2 = head2->next;
        }
        if(head1 != nullptr)
        {
            sum += head1->val;
            head1 = head1->next;
        }
        
        flag = sum / 10;
        val = sum % 10;
        pre->next = new ListNode(val);
        pre = pre->next;
    }
    ListNode* res = hair->next;
    delete hair;
    return res;
}
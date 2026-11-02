#include "solution.hpp"

#include <vector>
#include <unordered_map>
#include <string>
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

int Solution3::lengthOfLongestSubstring(string s) {
    int n = s.size();
    int l = 0; int r = 0;
    int len = 0;
    vector<int> dic(128, -1);
    while(r < n)
    {
        if(dic[s[r]] >= l)
        {
            l = dic[s[r]]+1;
        }
        len = max(len, r-l+1);
        dic[s[r]] = r;
        r++;
    }
    return len;
}

double Solution4::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
    int n1 = nums1.size();
    int n2 = nums2.size();
    int total_length = n1+n2;
    int k;
    
    auto findKth = [&] (int k)->int {
        int offset1 = 0, offset2 = 0;
        while(1)
        {
            if(offset1 == n1)
            {
                return nums2[offset2+k-1];
            }
            if(offset2 == n2)
            {
                return nums1[offset1+k-1];
            }
            if(k == 1)
            {
                return min(nums1[offset1], nums2[offset2]);
            }

            // 正常情况
            int step1 = min(k/2, n1-offset1);
            int step2 = min(k/2, n2-offset2);

            if(nums1[offset1+step1-1] <= nums2[offset2+step2-1])
            {
                offset1 += step1;
                k = k-step1;
            }
            else 
            {
                offset2 += step2;
                k = k-step2;
            }
        }
    };

    if(total_length%2)
    {
        k = total_length/2+1;
        return findKth(k);
    }
    else
    {
        k = total_length/2;
        return (double)(findKth(k) + findKth(k+1)) / 2;
    }

}
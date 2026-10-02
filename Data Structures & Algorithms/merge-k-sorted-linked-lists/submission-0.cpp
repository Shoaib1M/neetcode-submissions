/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> arr;
        int n = lists.size();
        for(int i = 0;i<n;i++){
            ListNode* temp = lists[i];
            while(temp!=NULL){
                arr.push_back(temp->val);
                temp = temp->next;
            }
        }
        sort(arr.begin(),arr.end());
        ListNode* newhead = new ListNode(-1);
        ListNode* temp = newhead;
        int x = arr.size();
        for(int i = 0;i<x;i++){
            temp ->next = new ListNode(arr[i]);
            temp = temp->next;
        }
        return newhead->next;
    }
};

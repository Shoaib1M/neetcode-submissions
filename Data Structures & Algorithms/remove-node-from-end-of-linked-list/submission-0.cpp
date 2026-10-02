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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* temp = head;
        while(temp!=NULL){
            len++;
            temp = temp->next;
        }
        int x = len - n;
        int count = 0;
        temp = head;
        if(x==0){
            ListNode* newhead = head->next;
            delete head;
            return newhead;
        }
        for(int i = 0;i<x-1;i++){
            temp = temp->next;
        }
        ListNode* del = temp->next;
        temp->next = del->next;
        delete del;
        return head;
        
    }
};

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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* cur=head;
        ListNode* ptr;
        int count=1;
        while(count!=k){
            cur=cur->next;
            count++;
        }
        ptr=cur;
        while(ptr->next!=NULL){
            ptr=ptr->next;
            count++;
        }
        ptr=head;
        int x=count-k+1;
        count=1;
        while(count!=x){
            ptr=ptr->next;
            count++;
        }
        int temp = cur->val;
        cur->val=ptr->val;
        ptr->val=temp;
        return head;
    }
};
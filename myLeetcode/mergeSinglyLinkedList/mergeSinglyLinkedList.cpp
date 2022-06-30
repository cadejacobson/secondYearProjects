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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        ListNode* head = temp1, *src;
        
        if( list1 == nullptr && list2 != nullptr)
            return list2;
        if( list2 == nullptr && list1 != nullptr)
            return list1;
        
        if( temp1->val < temp2->val)
            head = temp2;
        
        while( list1 != nullptr && list2 != nullptr  )
        {
            if( temp1->val > temp2->val )
            {
                src->next = temp2;
                src = src->next;
            }
            else
            {
                src->next = temp1;
                src = src->next;
            }

        }
            
        return head;
    }
};
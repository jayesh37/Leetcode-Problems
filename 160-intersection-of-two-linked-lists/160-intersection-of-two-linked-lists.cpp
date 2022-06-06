/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> s;
        ListNode *curr1=headA;
        ListNode *curr2=headB;
        
        while(curr1!=NULL)
        {
            s.insert(curr1);
            curr1=curr1->next;
        }
        
        while(curr2!=NULL)
        {
            if(s.find(curr2)!=s.end())
                return curr2;
            
            curr2=curr2->next;
        }
        return NULL;
    }
};
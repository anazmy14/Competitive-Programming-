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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> v,z;
        ListNode * node = l1 ; 
        while (node != NULL ) {
            v.push_back(node -> val) ;
            node = node -> next; 
        }
        node = l2 ;
        while (node != NULL ) {
            z.push_back(node -> val) ;
            node = node -> next; 

        }
        int c = 0;  
        
        ListNode *p = new ListNode ;

        for ( int i =0 ; c || i < max(v.size() , z.size()) ; i++ ){
            int x =0 , y = 0 , s =0;
            if (i < v.size()) x = v[i] ;
            if (i < z.size()) y = z[i] ;
            
            s = (x+y+c)%10 ;
            c = (x+y+c)/10;
            ListNode * cur = new ListNode ;
            cur -> val =  s ;
            if (!i) {
                node = p = cur ;
                
                continue ;
            }
            p -> next = cur ; 
            p = cur ;
            
        } 
        
        
        
        return node        ;
    }
};
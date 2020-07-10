/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (head == NULL) 
            return head;
        
        Node *next = head-> next;
        
        if(head -> child != NULL ){
            (head -> child) -> prev = head ;
            head -> next = flatten(head -> child) ;
            Node * last =  find(head->child);
            if(next != NULL) {
                next -> prev = last ;
                last -> next = flatten(next) ;
            }

           head -> child = NULL ;
        }
        else 
            head -> next = flatten(next) ;
        
        
        return  head ;                    
        
    }
    
    Node *find(Node *head){
        if(head -> next == NULL )
            return head ;
        return find(head -> next);
            
    }
    
    
    
};
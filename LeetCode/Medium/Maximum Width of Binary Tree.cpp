/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


class Solution {
public:
    
    int widthOfBinaryTree(TreeNode* root) {
         return count(root ) ;
                       
    }
    
    int count (TreeNode *head) {
        unordered_map<int , int > f ;
        unordered_map<int , int > l ;
        queue< pair< pair <TreeNode* , int> , int> > q;
        int mx = 1 ;
        q.push({{ head , 1 }, 0}) ;        
        while (!q.empty()) {
            TreeNode *node = q.front().first.first; 
            int lvl = q.front().first.second ;
            long long  n = q.front().second ;
            q.pop() ;
            if(f.find(lvl) == f.end() )
               f[lvl] = n-1 ;
            mx = mx > n - f[lvl] ? mx : n-f[lvl] ;
            
            if(node -> left != NULL )        
               q.push({{node->left , lvl+1 }, n*2+1 });
            if (node -> right != NULL)
               q.push({{node-> right , lvl+1 } , n*2+2});          
           
           
                       
        }
        return mx ;
        
    }
};
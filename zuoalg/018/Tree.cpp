#include <iostream>
#include <stack>
#include <vector>

using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
class Solution {
public:
     vector<int> preorderTraversal(TreeNode* root) {
        vector<int> collected;
        if(root!=nullptr)
       {
            stack<TreeNode*> stack;
            stack.push(root);
            while(!stack.empty())
            {
                //先打印中节点，在判断是否有左/右节点，分别去处理
                TreeNode* head=stack.top();
                stack.pop();
                collected.push_back(head->val);
                if(head->right!=nullptr)
                {
                    stack.push(head->right);
                }
                if(head->left!=nullptr)
                {
                    stack.push(head->left);
                }
            }
       }
       return collected;
    }      
     vector<int> inorderTraversal(TreeNode* root) {
        vector<int> collected;
        if(root!=nullptr)
           {
               stack<TreeNode*> stack;
               TreeNode* head=root;
               while(!stack.empty() || head!=nullptr)
               {
                   if(head!=nullptr)
                   {
                       stack.push(head);
                       head=head->left;
                   }
                   else
                   {
                        head = stack.top();
                        collected.push_back(head->val);
                        stack.pop();
                        head=head->right;
                   }
                   
               }
            
           }
           return collected;

    }    
     vector<int> postorderTraversalTwoStack(TreeNode* root) {
          vector<int> vector;
          stack<int> collected;
          if(root!=nullptr)
            {
                stack<TreeNode*> stack;
                stack.push(root);
                while(!stack.empty())
                {
                    TreeNode* head=stack.top();
                    stack.pop();
                    collected.push(head->val);
                    if(head->left!=nullptr)
                    {
                       stack.push(head->left); 
                    }
                    if(head->right!=nullptr)
                    {
                        stack.push(head->right);
                    }
                }
            }
            while(!collected.empty())
            {
                int val=collected.top();
                collected.pop();
                vector.push_back(val);
            }
          return vector;
    }       
     vector<int> postorderTraversalOneStack(TreeNode* root) {
            vector<int> collected;
            if(root!=nullptr)
            {
              stack<TreeNode*> stack;
              stack.push(root);
              TreeNode* h;
              while(!stack.empty())
              {
                 TreeNode* cur=stack.top();
                  if(cur->left!=nullptr&&h!=cur->left&&h!=cur->right)
                  {
                      stack.push(cur->left);
                  }
                  else if(cur->right!=nullptr&& h!=cur->right)
                  {
                      stack.push(cur->right);
                  }
                  else
                  {
                      h=stack.top();
                      collected.push_back(h->val);
                      stack.pop();
                  }

                }
            }
            return collected;
        }
};

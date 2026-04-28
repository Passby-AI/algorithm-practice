#include <vector>
using namespace std;
 //Definition for a binary tree node.
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
    int MAXN=2001;
    //下标
    int l;
    int r;
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        vector<vector<int>> ans;
    if(root!=nullptr){
        l=r=0;
        TreeNode* queue[MAXN]; 
        queue[r++]=root;
        bool reverse=false;//false 不逆序
        while(r>l)
        {
            int size=r-l;
            vector<int> vec;
            
            //正常收集，加入时逆序
            for(int i=reverse? r-1:l, j= reverse? -1:1,k=0;k<size;i+=j,k++)
            {
                TreeNode* cur=queue[i];
                vec.push_back(cur->val);
                
            }
            ans.push_back(vec);
            for(int i=0;i<size;i++)
            {
                TreeNode* cur=queue[l++];
                if(cur->left!=nullptr)
                    queue[r++]=cur->left;
                if(cur->right!=nullptr)
                    queue[r++]=cur->right;
            }
            reverse=!reverse;
        }
    }
    return ans;
    }

};

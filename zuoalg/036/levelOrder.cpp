#include <unordered_map>
#include <vector>
#include <queue>
using namespace  std;
 // Definition for a binary tree node.
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
vector<vector<int>> levelOrder1(TreeNode* root) {
		vector<vector<int>> ans;
		if (root != nullptr) {
			queue<TreeNode*> queue;
			unordered_map<TreeNode*,int> levels;
			queue.push(root);
			levels.emplace(root, 0);
			while (!queue.empty()) {
				TreeNode* cur = queue.front();
                queue.pop();
				int level = levels.at(cur);
				if (ans.size() == level) {
					ans.push_back(vector<int>());
				}
				ans[level].push_back(cur->val);
				if (cur->left != nullptr) {
					queue.push(cur->left);
					levels.emplace(cur->left, level + 1);
				}
				if (cur->right != nullptr) {
					queue.push(cur->right);
					levels.emplace(cur->right, level + 1);
				}
			}
		}
		return ans;
	}
    int MAXN=2001;
    //下标
    int l;
    int r;
    vector<vector<int>> levelOrder2(TreeNode* root)
    {
        vector<vector<int>> ans;
    if(root!=nullptr){
        l=r=0;
        TreeNode* queue[MAXN]; 
        queue[r++]=root;
        while(r>l)
        {
            int size=r-l;
            vector<int> vec;
            for(int i=0;i<size;i++)
            {
                TreeNode* cur=queue[l++];
                vec.push_back(cur->val);
                if(cur->left!=nullptr)
                    queue[r++]=cur->left;
                if(cur->right!=nullptr)
                    queue[r++]=cur->right;
            }
            ans.push_back(vec);
        }
    }
    return ans;
    }

};

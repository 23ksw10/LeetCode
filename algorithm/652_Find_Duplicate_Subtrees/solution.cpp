#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

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
    map<string,int>m;
    vector<TreeNode*>ans;
    string dfs(TreeNode* root){
        if(!root)return "#";
        string tmp=to_string(root->val)+" "+dfs(root->left)+" "+dfs(root->right);
        if(m.count(tmp)){
            if(m[tmp]==1){
                ans.push_back(root);
            }
            m[tmp]++;
        }
        else{
            m[tmp]++;
        }
        return tmp;
        
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return ans;
    }
};

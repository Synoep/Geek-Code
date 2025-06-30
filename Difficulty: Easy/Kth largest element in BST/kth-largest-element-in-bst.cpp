/*The Node structure is defined as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// return the Kth largest element in the given BST rooted at 'root'
class Solution {
  public:
  void inorder(Node* root,vector<int> &ans){
        if(root==nullptr) return ;
        inorder(root->left,ans);
        ans.push_back(root->data);
        inorder(root->right,ans);
    }
    int kthLargest(Node *root, int k) {
        // Your code here
        vector<int>ans;
        inorder(root,ans);
        reverse(ans.begin(),ans.end());
        return ans[k-1];
    }
};
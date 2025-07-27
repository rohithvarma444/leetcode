class Solution:
    def helper(self,root: 'TreeNode',p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if(root == None): return None
        if(root == p or root == q): return root

        left = self.helper(root.left,p,q)
        right = self.helper(root.right,p,q)

        if left and right: return root  

        if left: 
            return left
        else:
            return right
        
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        return self.helper(root, p, q) 

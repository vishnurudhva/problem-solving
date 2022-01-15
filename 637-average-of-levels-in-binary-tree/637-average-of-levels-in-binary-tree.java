/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<Double> averageOfLevels(TreeNode root) {
        Queue<TreeNode> q = new LinkedList<TreeNode>();
        List<Double> sums = new ArrayList<Double>();
        if(root == null){
            sums.add(0.0);
            return sums;
        }  
        q.add(root);
        while(!q.isEmpty()) {
            double sum = 0, size = q.size();
            for(int i = 0; i < size; i++)
            {
                TreeNode node = q.remove();
                sum += node.val;
                if(node.left != null) q.add(node.left);
                if(node.right != null) q.add(node.right);
            }
            sums.add(sum / size);
        }
        return sums;
    }
}
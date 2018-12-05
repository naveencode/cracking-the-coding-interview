// class Node {
//     public String name;
//     public Node[] children;
// }

class TreeNode {
    String name;
    TreeNode left;
    TreeNode right;

    public TreeNode(String name) {
        this.name = name;
        this.left = null;
        this.right = null;
    }

    public void setLeftChild(String name) {
        TreeNode newNode = new TreeNode(name);
        this.left = newNode;
    }

    public void setRightChild(String name) {
        TreeNode newNode = new TreeNode(name);
        this.right = newNode;
    }
}

public class InOrder {
    public static void main(String args[]) {
        TreeNode root = new TreeNode("A");

        root.setLeftChild("B");
        root.setRightChild("C");

        root.left.setLeftChild("D");
        root.left.setRightChild("E");

        root.right.setLeftChild("F");
        root.right.setRightChild("G");

        System.out.println("Inorder traversal of tree:");
        inOrderTraversal(root);
        System.out.println();

        // System.out.println("Preorder traversal of tree:");
        // preOrderTraversal(root);
        // System.out.println();


        // System.out.println("Postorder traversal of tree:");
        // postOrderTraversal(root);
        // System.out.println();


    }

    static void inOrderTraversal(TreeNode node) {
        if (node != null) {
            inOrderTraversal(node.left);
            System.out.print(node.name + " ");
            inOrderTraversal(node.right);
        }
    }

    static void preOrderTraversal(TreeNode node) {
        if (node != null) {
            System.out.print(node.name + " ");
            preOrderTraversal(node.left);
            preOrderTraversal(node.right);
        }
    }

    static void postOrderTraversal(TreeNode node) {
        if (node != null) {
            postOrderTraversal(node.left);
            postOrderTraversal(node.right);
            System.out.print(node.name + " ");
        }
    }
}
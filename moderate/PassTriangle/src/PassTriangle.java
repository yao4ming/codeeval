import java.io.*;

public class PassTriangle {
    static Node[] root;

    static class Node {

        int val;
        Node left;
        Node right;
        boolean traversed;
        int sum;

        public Node(int val) {
            this.val = val;
            traversed = false;
        }
    }

    public static void main(String []args) {

        File file = new File(args[0]);

        initTriangle(file);

        int maxSum = findMaxSumFromRootToLeaf(root[0]);
        System.out.println(maxSum);
    }

    public static void initTriangle(File file) {

        try (BufferedReader reader = new BufferedReader(new FileReader(file))) {

            //set root as current
            root = new Node[1];
            root[0] = new Node(Integer.parseInt(reader.readLine().trim()));
            Node[] current = root;
            String line;

            //read line/level
            while ((line = reader.readLine()) != null) {
                line = line.trim();

                //parse line as array of ints
                String[] vals = line.split(" ");

                //set node values at level
                Node[] nodes = new Node[vals.length];
                for (int i = 0; i < vals.length; i++) {
                    nodes[i] = new Node(Integer.parseInt(vals[i]));
                }

                //set left and right pointer values of each node at level
                for (int i = 0; i < current.length; i++) {
                    current[i].left = nodes[i];
                    current[i].right = nodes[i+1];
                }

                current = nodes;
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static int findMaxSumFromRootToLeaf(Node node) {
        if (node == null) return 0;
        if (node.traversed) return node.sum;

        node.traversed = true;
        node.sum = Math.max(findMaxSumFromRootToLeaf(node.left), findMaxSumFromRootToLeaf(node.right)) + node.val;
        return node.sum;
    }


}

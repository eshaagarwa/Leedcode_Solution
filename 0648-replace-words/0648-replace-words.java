class Solution {
    private static class TrieTree{
        public static class Node{
            boolean isLeaf;
            Node[] childs;
            public Node(){
                this.childs = new Node[26];
            }
        }
        private Node root;
        public TrieTree(){
            this.root = new Node();
        }
        public void insert(String s){
            char[] arr = s.toCharArray();
            Node node = root;
            for(int i = 0; i < arr.length; i++){
                if(node.isLeaf) return;
                int c = arr[i] - 'a';
                if(node.childs[c] == null){
                    node.childs[c] = new Node();
                }
                node = node.childs[c];
            }
            node.isLeaf = true;            
        }
        public String findClosest(String s){
            char[] arr = s.toCharArray();
            Node node = root;
            for(int i = 0; i < arr.length; i++){
                int c = arr[i] - 'a';
                if(node.childs[c] == null){
                    return s;   
                }else{
                    node = node.childs[c];
                    if(node.isLeaf){
                        return s.substring(0, i + 1);   
                    }
                }
            }
            return s;
        }
    }
    public String replaceWords(List<String> dict, String sentence) {
        if(sentence == null || sentence.length() == 0) return "";
        if(dict == null || dict.size() == 0) return sentence;
        TrieTree tree = new TrieTree();
        for(String s : dict){
            tree.insert(s);
        }
        StringBuilder sb = new StringBuilder();
        String[] tokens = sentence.split(" ");
        for(String token : tokens){
            sb.append(" " + tree.findClosest(token));
        }
        return sb.toString().substring(1);
    }
}
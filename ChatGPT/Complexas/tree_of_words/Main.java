import java.util.*;

class TreeNode {
    List<String> verbGroup;
    List<String> nounGroup;
    List<TreeNode> children;

    public TreeNode(List<String> verbs, List<String> nouns) {
        this.verbGroup = verbs;
        this.nounGroup = nouns;
        this.children = new ArrayList<>();
    }

    public void addChild(TreeNode child) {
        children.add(child);
    }
}

class WordTree {
    TreeNode root;

    public WordTree(TreeNode rootNode) {
        this.root = rootNode;
    }

    private int proximity(List<String> textWords, List<String> groupWords) {
        Map<String, Integer> wordCount = new HashMap<>();
        for (String word : textWords) {
            wordCount.put(word, wordCount.getOrDefault(word, 0) + 1);
        }

        int proximityScore = 0;
        for (String word : groupWords) {
            if (wordCount.containsKey(word)) {
                proximityScore++;
            }
        }
        return proximityScore;
    }

    private Map.Entry<TreeNode, Integer> findBestMatch(TreeNode node, List<String> textVerbs, List<String> textNouns) {
        int verbProximity = proximity(textVerbs, node.verbGroup);
        int nounProximity = proximity(textNouns, node.nounGroup);
        int totalProximity = verbProximity + nounProximity;

        TreeNode bestMatch = node;
        int maxProximity = totalProximity;

        for (TreeNode child : node.children) {
            Map.Entry<TreeNode, Integer> childResult = findBestMatch(child, textVerbs, textNouns);
            if (childResult.getValue() > maxProximity) {
                bestMatch = childResult.getKey();
                maxProximity = childResult.getValue();
            }
        }

        return new AbstractMap.SimpleEntry<>(bestMatch, maxProximity);
    }

    public Set<String> traverseTree(List<String> textVerbs, List<String> textNouns) {
        Set<String> matchedWords = new HashSet<>();

        TreeNode currentNode = root;
        for (int i = 0; i < 5; i++) {  // Traverse 5 levels
            Map.Entry<TreeNode, Integer> bestResult = findBestMatch(currentNode, textVerbs, textNouns);
            TreeNode bestNode = bestResult.getKey();
            matchedWords.addAll(bestNode.verbGroup);
            matchedWords.addAll(bestNode.nounGroup);
            currentNode = bestNode;
        }

        return matchedWords;
    }
}

public class Main {
    public static void main(String[] args) {
        // Define nodes
        TreeNode root = new TreeNode(Arrays.asList("run", "jump"), Arrays.asList("dog", "ball"));
        TreeNode child1 = new TreeNode(Arrays.asList("play", "fetch"), Arrays.asList("cat", "toy"));
        TreeNode child2 = new TreeNode(Arrays.asList("walk", "throw"), Arrays.asList("bird", "stick"));

        root.addChild(child1);
        root.addChild(child2);

        // Define tree
        WordTree tree = new WordTree(root);

        // Given input text
        List<String> inputVerbs = Arrays.asList("run", "play", "fetch");
        List<String> inputNouns = Arrays.asList("dog", "toy");

        // Traverse the tree
        Set<String> result = tree.traverseTree(inputVerbs, inputNouns);
        System.out.println("Final matched words: " + result);
    }
}

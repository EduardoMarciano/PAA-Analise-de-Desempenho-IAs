import java.util.*;
import java.util.regex.*;
import java.util.stream.*;

class TreeNode {
    List<String> wordGroup;
    List<TreeNode> children;
    int frequency;

    TreeNode(List<String> group) {
        this.wordGroup = group;
        this.children = new ArrayList<>();
        this.frequency = 0;
    }
}

public class WordTree {
    private TreeNode root;
    private int maxDepth;

    public WordTree(int depth) {
        this.root = new TreeNode(new ArrayList<>());
        this.maxDepth = depth;
    }

    private List<String> extractWords(String text) {
        List<String> words = new ArrayList<>();
        Pattern pattern = Pattern.compile("\\b(?:(?:verb|noun)\\w*)\\b");
        Matcher matcher = pattern.matcher(text.toLowerCase());
        while (matcher.find()) {
            words.add(matcher.group());
        }
        return words;
    }

    private void addWordToTree(String word, int count, TreeNode node, int depth) {
        if (depth >= maxDepth) return;
        if (node == null) node = root;

        TreeNode bestChild = null;
        double bestSimilarity = -1;

        for (TreeNode child : node.children) {
            double similarity = calculateSimilarity(word, child.wordGroup);
            if (similarity > bestSimilarity) {
                bestSimilarity = similarity;
                bestChild = child;
            }
        }

        if (bestChild == null || bestSimilarity < 0.5) {
            TreeNode newNode = new TreeNode(new ArrayList<>(Collections.singletonList(word)));
            newNode.frequency = count;
            node.children.add(newNode);
            node.children.sort((a, b) -> Integer.compare(b.frequency, a.frequency));
        } else {
            bestChild.wordGroup.add(word);
            bestChild.frequency += count;
            addWordToTree(word, count, bestChild, depth + 1);
        }
    }

    private double calculateSimilarity(String word, List<String> wordGroup) {
        return wordGroup.stream().anyMatch(w -> word.startsWith(w) || w.startsWith(word)) ? 1.0 : 0.0;
    }

    public void buildTree(String text) {
        List<String> words = extractWords(text);
        Map<String, Integer> wordCount = new HashMap<>();
        for (String word : words) {
            wordCount.put(word, wordCount.getOrDefault(word, 0) + 1);
        }

        for (Map.Entry<String, Integer> entry : wordCount.entrySet()) {
            addWordToTree(entry.getKey(), entry.getValue(), root, 0);
        }
    }

    public List<String> findRelatedWords(List<String> query) {
        Set<String> relatedWords = new HashSet<>();
        traverseTree(root, query, relatedWords, 0);
        return relatedWords.stream().filter(word -> !query.contains(word)).collect(Collectors.toList());
    }

    private void traverseTree(TreeNode node, List<String> query, Set<String> relatedWords, int depth) {
        if (depth >= maxDepth) return;

        for (TreeNode child : node.children) {
            if (query.stream().anyMatch(q -> calculateSimilarity(q, child.wordGroup) > 0.5)) {
                relatedWords.addAll(child.wordGroup);
                traverseTree(child, query, relatedWords, depth + 1);
            }
        }
    }

    public static void main(String[] args) {
        String text = "Verbs are action words in a sentence. Common verbs include run, jump, and eat. " +
                      "Nouns are naming words. Examples of nouns are cat, tree, and book. " +
                      "Some words can be both verbs and nouns, like dance or paint.";

        WordTree wordTree = new WordTree(5);
        wordTree.buildTree(text);

        List<String> query = Arrays.asList("verb", "noun");
        List<String> relatedWords = wordTree.findRelatedWords(query);

        System.out.println("Related words for query [verb, noun]: " + String.join(" ", relatedWords));
    }
}
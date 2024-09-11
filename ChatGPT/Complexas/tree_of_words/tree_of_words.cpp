#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

class TreeNode {
public:
    std::vector<std::string> verb_group;
    std::vector<std::string> noun_group;
    std::vector<TreeNode*> children;

    TreeNode(const std::vector<std::string>& verbs, const std::vector<std::string>& nouns) {
        verb_group = verbs;
        noun_group = nouns;
    }

    void add_child(TreeNode* child) {
        children.push_back(child);
    }
};

class WordTree {
public:
    TreeNode* root;

    WordTree(TreeNode* root_node) : root(root_node) {}

    int proximity(const std::vector<std::string>& text_words, const std::vector<std::string>& group_words) {
        std::unordered_map<std::string, int> word_count;
        for (const auto& word : text_words) {
            word_count[word]++;
        }
        int proximity_score = 0;
        for (const auto& word : group_words) {
            if (word_count[word] > 0) {
                proximity_score++;
            }
        }
        return proximity_score;
    }

    std::pair<TreeNode*, int> find_best_match(TreeNode* node, const std::vector<std::string>& text_verbs, const std::vector<std::string>& text_nouns) {
        int verb_proximity = proximity(text_verbs, node->verb_group);
        int noun_proximity = proximity(text_nouns, node->noun_group);
        int total_proximity = verb_proximity + noun_proximity;

        TreeNode* best_match = node;
        int max_proximity = total_proximity;

        for (auto* child : node->children) {
            auto child_result = find_best_match(child, text_verbs, text_nouns);
            if (child_result.second > max_proximity) {
                best_match = child_result.first;
                max_proximity = child_result.second;
            }
        }
        return {best_match, max_proximity};
    }

    std::unordered_set<std::string> traverse_tree(const std::vector<std::string>& text_verbs, const std::vector<std::string>& text_nouns) {
        std::unordered_set<std::string> matched_words;

        TreeNode* current_node = root;
        for (int i = 0; i < 5; ++i) {  // Traverse 5 levels
            auto best_result = find_best_match(current_node, text_verbs, text_nouns);
            TreeNode* best_node = best_result.first;
            matched_words.insert(best_node->verb_group.begin(), best_node->verb_group.end());
            matched_words.insert(best_node->noun_group.begin(), best_node->noun_group.end());
            current_node = best_node;
        }

        return matched_words;
    }
};

int main() {
    // Define nodes
    TreeNode* root = new TreeNode({"run", "jump"}, {"dog", "ball"});
    TreeNode* child1 = new TreeNode({"play", "fetch"}, {"cat", "toy"});
    TreeNode* child2 = new TreeNode({"walk", "throw"}, {"bird", "stick"});

    root->add_child(child1);
    root->add_child(child2);

    // Define tree
    WordTree tree(root);

    // Given input text
    std::vector<std::string> input_verbs = {"run", "play", "fetch"};
    std::vector<std::string> input_nouns = {"dog", "toy"};

    // Traverse the tree
    auto result = tree.traverse_tree(input_verbs, input_nouns);
    std::cout << "Final matched words: ";
    for (const auto& word : result) {
        std::cout << word << " ";
    }
    std::cout << std::endl;

    return 0;
}

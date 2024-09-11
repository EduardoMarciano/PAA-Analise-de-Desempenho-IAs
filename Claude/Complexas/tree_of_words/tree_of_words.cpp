#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <regex>
#include <set>

class TreeNode {
public:
    std::vector<std::string> word_group;
    std::vector<TreeNode*> children;
    int frequency;

    TreeNode(const std::vector<std::string>& group) : word_group(group), frequency(0) {}
    ~TreeNode() {
        for (auto child : children) {
            delete child;
        }
    }
};

class WordTree {
private:
    TreeNode* root;
    int max_depth;

    std::vector<std::string> extract_words(const std::string& text) {
        std::vector<std::string> words;
        std::regex word_regex("\\b(?:(?:verb|noun)\\w*)\\b");
        auto words_begin = std::sregex_iterator(text.begin(), text.end(), word_regex);
        auto words_end = std::sregex_iterator();

        for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
            words.push_back(i->str());
        }
        return words;
    }

    void add_word_to_tree(const std::string& word, int count, TreeNode* node = nullptr, int depth = 0) {
        if (depth >= max_depth) return;
        if (node == nullptr) node = root;

        TreeNode* best_child = nullptr;
        double best_similarity = -1;

        for (auto child : node->children) {
            double similarity = calculate_similarity(word, child->word_group);
            if (similarity > best_similarity) {
                best_similarity = similarity;
                best_child = child;
            }
        }

        if (best_child == nullptr || best_similarity < 0.5) {
            TreeNode* new_node = new TreeNode({word});
            new_node->frequency = count;
            node->children.push_back(new_node);
            std::sort(node->children.begin(), node->children.end(),
                      [](const TreeNode* a, const TreeNode* b) { return a->frequency > b->frequency; });
        } else {
            best_child->word_group.push_back(word);
            best_child->frequency += count;
            add_word_to_tree(word, count, best_child, depth + 1);
        }
    }

    double calculate_similarity(const std::string& word, const std::vector<std::string>& word_group) {
        for (const auto& w : word_group) {
            if (word.compare(0, w.length(), w) == 0 || w.compare(0, word.length(), word) == 0) {
                return 1.0;
            }
        }
        return 0.0;
    }

    void traverse_tree(TreeNode* node, const std::vector<std::string>& query, std::set<std::string>& related_words, int depth = 0) {
        if (depth >= max_depth) return;

        for (auto child : node->children) {
            if (std::any_of(query.begin(), query.end(),
                            [this, child](const std::string& q) { return calculate_similarity(q, child->word_group) > 0.5; })) {
                related_words.insert(child->word_group.begin(), child->word_group.end());
                traverse_tree(child, query, related_words, depth + 1);
            }
        }
    }

public:
    WordTree(int depth = 5) : max_depth(depth) {
        root = new TreeNode({});
    }

    ~WordTree() {
        delete root;
    }

    void build_tree(const std::string& text) {
        std::vector<std::string> words = extract_words(text);
        std::unordered_map<std::string, int> word_count;
        for (const auto& word : words) {
            word_count[word]++;
        }

        for (const auto& pair : word_count) {
            add_word_to_tree(pair.first, pair.second);
        }
    }

    std::vector<std::string> find_related_words(const std::vector<std::string>& query) {
        std::set<std::string> related_words;
        traverse_tree(root, query, related_words);
        std::vector<std::string> result;
        std::set_difference(related_words.begin(), related_words.end(),
                            query.begin(), query.end(),
                            std::back_inserter(result));
        return result;
    }
};

int main() {
    std::string text = "Verbs are action words in a sentence. Common verbs include run, jump, and eat. "
                       "Nouns are naming words. Examples of nouns are cat, tree, and book. "
                       "Some words can be both verbs and nouns, like dance or paint.";

    WordTree word_tree;
    word_tree.build_tree(text);

    std::vector<std::string> query = {"verb", "noun"};
    std::vector<std::string> related_words = word_tree.find_related_words(query);

    std::cout << "Related words for query [verb, noun]: ";
    for (const auto& word : related_words) {
        std::cout << word << " ";
    }
    std::cout << std::endl;

    return 0;
}
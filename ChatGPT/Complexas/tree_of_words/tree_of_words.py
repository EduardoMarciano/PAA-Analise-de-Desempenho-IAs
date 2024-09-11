from collections import defaultdict, Counter

class TreeNode:
    def __init__(self, verb_group, noun_group):
        self.verb_group = verb_group  # List of verbs in the node
        self.noun_group = noun_group  # List of nouns in the node
        self.children = []            # List of child nodes

    def add_child(self, child_node):
        self.children.append(child_node)


class WordTree:
    def __init__(self, root):
        self.root = root

    def proximity(self, text_words, group_words):
        """Calculate proximity by counting matched words."""
        text_counter = Counter(text_words)
        group_counter = Counter(group_words)
        proximity_score = sum(min(text_counter[word], group_counter[word]) for word in group_words if word in text_counter)
        return proximity_score

    def find_best_match(self, node, text_verbs, text_nouns):
        """Find the best node match at this level based on proximity."""
        verb_proximity = self.proximity(text_verbs, node.verb_group)
        noun_proximity = self.proximity(text_nouns, node.noun_group)
        total_proximity = verb_proximity + noun_proximity
        
        best_match = node
        max_proximity = total_proximity

        for child in node.children:
            child_proximity = self.find_best_match(child, text_verbs, text_nouns)
            if child_proximity[1] > max_proximity:
                best_match = child_proximity[0]
                max_proximity = child_proximity[1]

        return best_match, max_proximity

    def traverse_tree(self, text_verbs, text_nouns):
        matched_words = set()

        current_node = self.root
        for _ in range(5):  # Traverse 5 levels
            best_node, _ = self.find_best_match(current_node, text_verbs, text_nouns)
            matched_words.update(best_node.verb_group + best_node.noun_group)
            current_node = best_node

        # Remove words from the matched set that were in the original query
        final_words = matched_words - set(text_verbs) - set(text_nouns)
        return final_words


# Example usage
if __name__ == "__main__":
    # Define nodes
    root = TreeNode(verb_group=["run", "jump"], noun_group=["dog", "ball"])
    child1 = TreeNode(verb_group=["play", "fetch"], noun_group=["cat", "toy"])
    child2 = TreeNode(verb_group=["walk", "throw"], noun_group=["bird", "stick"])
    
    root.add_child(child1)
    root.add_child(child2)

    # Define tree
    tree = WordTree(root)

    # Given input text
    input_verbs = ["run", "play", "fetch"]
    input_nouns = ["dog", "toy"]

    # Traverse the tree
    result = tree.traverse_tree(input_verbs, input_nouns)
    print("Final matched words:", result)

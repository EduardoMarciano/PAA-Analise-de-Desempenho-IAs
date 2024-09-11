import re
from collections import defaultdict, Counter
from typing import List, Dict, Tuple

class TreeNode:
    def __init__(self, word_group: List[str]):
        self.word_group = word_group
        self.children: List[TreeNode] = []
        self.frequency = 0

class WordTree:
    def __init__(self, max_depth: int = 5):
        self.root = TreeNode([])
        self.max_depth = max_depth

    def build_tree(self, text: str):
        words = self._extract_words(text)
        word_count = Counter(words)
        
        for word, count in word_count.items():
            self._add_word_to_tree(word, count)

    def _extract_words(self, text: str) -> List[str]:
        return re.findall(r'\b(?:(?:verb|noun)\w*)\b', text.lower())

    def _add_word_to_tree(self, word: str, count: int, node: TreeNode = None, depth: int = 0):
        if depth >= self.max_depth:
            return

        if node is None:
            node = self.root

        best_child = None
        best_similarity = -1

        for child in node.children:
            similarity = self._calculate_similarity(word, child.word_group)
            if similarity > best_similarity:
                best_similarity = similarity
                best_child = child

        if best_child is None or best_similarity < 0.5:  # Threshold for creating a new node
            new_node = TreeNode([word])
            new_node.frequency = count
            node.children.append(new_node)
            node.children.sort(key=lambda x: x.frequency, reverse=True)
        else:
            best_child.word_group.append(word)
            best_child.frequency += count
            self._add_word_to_tree(word, count, best_child, depth + 1)

    def _calculate_similarity(self, word: str, word_group: List[str]) -> float:
        # Simple similarity measure: check if the word starts with any word in the group
        return any(word.startswith(w) or w.startswith(word) for w in word_group)

    def find_related_words(self, query: List[str]) -> List[str]:
        related_words = set()
        self._traverse_tree(self.root, query, related_words)
        return list(related_words - set(query))

    def _traverse_tree(self, node: TreeNode, query: List[str], related_words: set, depth: int = 0):
        if depth >= self.max_depth:
            return

        for child in node.children:
            if any(self._calculate_similarity(q, child.word_group) > 0.5 for q in query):
                related_words.update(child.word_group)
                self._traverse_tree(child, query, related_words, depth + 1)

# Example usage
text = """
Verbs are action words in a sentence. Common verbs include run, jump, and eat.
Nouns are naming words. Examples of nouns are cat, tree, and book.
Some words can be both verbs and nouns, like dance or paint.
"""

word_tree = WordTree()
word_tree.build_tree(text)

query = ["verb", "noun"]
related_words = word_tree.find_related_words(query)
print(f"Related words for query {query}: {related_words}")
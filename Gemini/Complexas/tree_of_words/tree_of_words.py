import nltk
from nltk.corpus import stopwords
from nltk.tokenize import word_tokenize

def build_tree(text, max_depth=5):
    # Preprocessing
    words = word_tokenize(text)
    stop_words = set(stopwords.words('english'))
    filtered_words = [word for word in words if word not in stop_words]

    # Tree construction
    root = Node()
    for word in filtered_words:
        # Calculate proximity measure (implement your own logic)
        proximity = calculate_proximity(word, root)
        if proximity > threshold:
            node = Node(word)
            root.add_child(node)
            # Recursively build the tree
            build_tree(node, max_depth-1)

    return root

# ... (rest of the implementation)
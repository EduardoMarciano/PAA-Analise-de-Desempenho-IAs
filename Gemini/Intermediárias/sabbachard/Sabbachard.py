def max_score(deck):
  """Calculates the maximum possible score for a given deck of cards.

  Args:
    deck: A list of integers representing the cards in the deck.

  Returns:
    The maximum possible score.
  """

  # Base case: if there is only one card left, return its value
  if len(deck) == 1:
    return deck[0]

  # Calculate the maximum score by considering both options:
  # taking the first card or taking the last card
  score_first = deck[0] + max_score(deck[1:])
  score_last = deck[-1] + max_score(deck[:-1])

  # Return the maximum of the two scores
  return max(score_first, score_last)

# Example usage
deck = [10, 19, 1, 2]
print(max_score(deck))  # Output: 21
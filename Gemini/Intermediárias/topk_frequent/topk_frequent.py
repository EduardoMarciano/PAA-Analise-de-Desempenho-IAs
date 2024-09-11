import heapq
from collections import Counter

def top_k_frequent_dict(nums, k):
    """
    Encontra os K elementos mais frequentes usando um dicionário.

    Args:
        nums: Lista de números.
        k: Número de elementos a retornar.

    Returns:
        Lista com os K elementos mais frequentes.
    """
    count = Counter(nums)
    return [num for num, _ in count.most_common(k)]

def top_k_frequent_heap(nums, k):
    """
    Encontra os K elementos mais frequentes usando um min-heap.

    Args:
        nums: Lista de números.
        k: Número de elementos a retornar.

    Returns:
        Lista com os K elementos mais frequentes.
    """
    count = Counter(nums)
    heap = [(-freq, num) for num, freq in count.items()]
    heapq.heapify(heap)
    return [num for _, num in heapq.nsmallest(k, heap)]

def top_k_frequent_bucket_sort(nums, k):
    """
    Encontra os K elementos mais frequentes usando bucket sort.

    Args:
        nums: Lista de números.
        k: Número de elementos a retornar.

    Returns:
        Lista com os K elementos mais frequentes.
    """
    # Encontrar o maior valor para determinar o tamanho dos buckets
    max_freq = max(Counter(nums).values())
    buckets = [[] for _ in range(max_freq + 1)]

    # Colocar os elementos nos buckets de acordo com sua frequência
    for num, freq in Counter(nums).items():
        buckets[freq].append(num)

    result = []
    for i in range(max_freq, 0, -1):
        for num in buckets[i]:
            result.append(num)
            if len(result) == k:
                return result

# Casos de teste
test_cases = [
    ([1,1,1,2,2,3], 2, [1, 2]),
    ([3,3,4,2,2,4,2,4,1], 2, [2, 4]),
    # ... outros casos de teste
]

for nums, k, expected in test_cases:
    print("Entrada:", nums, "k:", k)
    print("Esperado:", expected)
    print("Dicionário:", top_k_frequent_dict(nums, k))
    print("Min-heap:", top_k_frequent_heap(nums, k))
    print("Bucket sort:", top_k_frequent_bucket_sort(nums, k))
    print()

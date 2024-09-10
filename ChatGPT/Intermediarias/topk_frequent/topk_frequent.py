import heapq
from collections import Counter

def topKFrequent(nums, k):
    # Contar frequências dos elementos
    freq = Counter(nums)

    # Criar um heap mínimo para manter os k elementos mais frequentes
    # Usar uma tupla (frequência, elemento) para que a ordenação seja pela frequência
    heap = []
    for key, count in freq.items():
        heapq.heappush(heap, (count, key))
        if len(heap) > k:
            heapq.heappop(heap)

    # Coletar os elementos do heap
    top_k = [item[1] for item in heap]
    return top_k

# Exemplo de uso
nums = [1,1,1,2,2,3]
k = 2
print(topKFrequent(nums, k))  # Exemplo de saída: [1, 2]

from collections import Counter
import heapq

def topKFrequent(nums, k):
    # Conta a frequência de cada número
    count = Counter(nums)

    # Cria uma lista de tuplas (frequência, número)
    freq_pairs = [(-freq, num) for num, freq in count.items()]

    # Usa um heap para obter os k elementos mais frequentes
    return [num for _, num in heapq.nsmallest(k, freq_pairs)]

# Exemplo de uso
nums = [1,1,1,2,2,3]
k = 2
result = topKFrequent(nums, k)
print(f"Os {k} elementos mais frequentes são: {result}")

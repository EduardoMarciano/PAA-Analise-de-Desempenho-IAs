#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <functional>

std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
    // Mapa para contar a frequência de cada elemento
    std::unordered_map<int, int> freq;
    for (int num : nums) {
        freq[num]++;
    }

    // Priority queue (min-heap) para manter os k elementos mais frequentes
    // Usamos um par negativo da frequência e o elemento para simular um max-heap
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> min_heap;

    for (auto& [num, count] : freq) {
        min_heap.push({count, num});
        if (min_heap.size() > k) {
            min_heap.pop();
        }
    }

    // Extrair os elementos do heap para o resultado
    std::vector<int> top_k;
    while (!min_heap.empty()) {
        top_k.push_back(min_heap.top().second);
        min_heap.pop();
    }

    return top_k;
}

int main() {
    std::vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    std::vector<int> result = topKFrequent(nums, k);
    for (int num : result) {
        std::cout << num << " ";
    }
    return 0;
}

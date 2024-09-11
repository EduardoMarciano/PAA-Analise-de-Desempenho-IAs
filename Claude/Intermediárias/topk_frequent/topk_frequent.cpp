#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        // Contar a frequência de cada número
        std::unordered_map<int, int> freq_map;
        for (int num : nums) {
            freq_map[num]++;
        }

        // Usar um min-heap para manter os k elementos mais frequentes
        auto comp = [&freq_map](int a, int b) {
            return freq_map[a] > freq_map[b];
        };
        std::priority_queue<int, std::vector<int>, decltype(comp)> pq(comp);

        for (const auto& pair : freq_map) {
            pq.push(pair.first);
            if (pq.size() > k) {
                pq.pop();
            }
        }

        // Construir o vetor de resultado
        std::vector<int> result;
        while (!pq.empty()) {
            result.push_back(pq.top());
            pq.pop();
        }

        // Inverter o resultado para obter a ordem decrescente de frequência
        std::reverse(result.begin(), result.end());

        return result;
    }
};

// Função auxiliar para imprimir um vetor
void printVector(const std::vector<int>& vec) {
    std::cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i];
        if (i < vec.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

int main() {
    Solution sol;

    // Caso de teste
    std::vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;

    std::cout << "Entrada: nums = ";
    printVector(nums);
    std::cout << "k = " << k << std::endl;

    std::vector<int> result = sol.topKFrequent(nums, k);

    std::cout << "Saída: ";
    printVector(result);

    // Verificação do resultado esperado
    std::vector<int> expected = {1, 2};
    if (result == expected) {
        std::cout << "Teste passou!" << std::endl;
    } else {
        std::cout << "Teste falhou. Resultado esperado: ";
        printVector(expected);
    }

    return 0;
}

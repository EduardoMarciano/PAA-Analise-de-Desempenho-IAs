#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// Função para encontrar os K elementos mais frequentes
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    for (int num : nums) {
        freq[num]++;
    }

    auto comp = [](pair<int, int>& a, pair<int, int>& b) {
        return a.second > b.second; // Ordena pelo valor (frequência) em ordem decrescente
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> minHeap(comp);

    for (auto& it : freq) {
        minHeap.push({it.first, it.second});
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }

    vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top().first);
        minHeap.pop();
    }
    return result;
}

// Função para imprimir um vetor
void printVector(const vector<int>& nums) {
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

// Função para comparar dois vetores
bool compareVectors(const vector<int>& v1, const vector<int>& v2) {
    if (v1.size() != v2.size()) {
        return false;
    }
    for (int i = 0; i < v1.size(); ++i) {
        if (v1[i] != v2[i]) {
            return false;
        }
    }
    return true;
}

// Função principal para executar os testes
int main() {
    // Casos de teste
    vector<int> nums1 = {1, 1, 1, 2, 2, 3};
    int k1 = 2;
    vector<int> expected1 = {1, 2};
    vector<int> result1 = topKFrequent(nums1, k1);
    if (compareVectors(result1, expected1)) {
        cout << "Teste 1 passou!" << endl;
    } else {
        cout << "Teste 1 falhou!" << endl;
    }

    // Caso de teste com lista vazia
    vector<int> nums2 = {};
    int k2 = 2;
    vector<int> expected2 = {};
    vector<int> result2 = topKFrequent(nums2, k2);
    if (compareVectors(result2, expected2)) {
        cout << "Teste 2 passou!" << endl;
    } else {
        cout << "Teste 2 falhou!" << endl;
    }

    // Caso de teste com todos os elementos iguais
    vector<int> nums3 = {1, 1, 1, 1, 1};
    int k3 = 1;
    vector<int> expected3 = {1};
    vector<int> result3 = topKFrequent(nums3, k3);
    if (compareVectors(result3, expected3)) {
        cout << "Teste 3 passou!" << endl;
    } else {
        cout << "Teste 3 falhou!" << endl;
    }

    return 0;
}

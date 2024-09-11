#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> num_map;  // Para armazenar o número e seu índice

    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];  // Calcula o complemento do número atual

        // Verifica se o complemento já existe no mapa
        if (num_map.find(complement) != num_map.end()) {
            // Retorna os índices se encontrarmos uma solução
            return {num_map[complement], i};
        }

        // Armazena o número e seu índice no mapa
        num_map[nums[i]] = i;
    }

    return {};  // Retorna um vetor vazio se nenhuma solução for encontrada
}

int main() {
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    std::vector<int> indices = twoSum(nums, target);

    if (!indices.empty()) {
        std::cout << "Índices: " << indices[0] << " e " << indices[1] << std::endl;
    } else {
        std::cout << "Nenhuma solução encontrada." << std::endl;
    }

    return 0;
}

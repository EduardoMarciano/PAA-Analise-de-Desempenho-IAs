def two_sum(nums, target):
    # Dicionário para armazenar o valor do número e seu índice
    num_dict = {}

    # Iterar sobre cada número no array
    for i, num in enumerate(nums):
        # Calcular o complemento do número atual
        complement = target - num

        # Se o complemento já está no dicionário, encontramos a solução
        if complement in num_dict:
            return [num_dict[complement], i]

        # Armazenar o número e seu índice no dicionário
        num_dict[num] = i

    # Se não encontrar nenhum par, retornar uma lista vazia (ou gerar um erro)
    return []

# Exemplo de uso
nums = [2, 7, 11, 15]
target = 9
print(two_sum(nums, target))  # Saída: [0, 1]

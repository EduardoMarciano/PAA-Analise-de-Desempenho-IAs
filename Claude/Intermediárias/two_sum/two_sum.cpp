#include <iostream>
#include <stdexcept>
#include <cassert>

unsigned long long factorial(int n) {
    if (n < 0) {
        throw std::invalid_argument("O fatorial não está definido para números negativos");
    }
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

void runTests() {
    assert(factorial(0) == 1);
    assert(factorial(1) == 1);
    assert(factorial(5) == 120);

    try {
        factorial(-1);
        assert(false); // Deve lançar uma exceção
    } catch (const std::invalid_argument& e) {
        // Exceção esperada
    }

    std::cout << "Todos os testes passaram!" << std::endl;
}

int main() {
    runTests();
    return 0;
}

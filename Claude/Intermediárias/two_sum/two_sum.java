public class Factorial {

    public static long factorial(int n) {
        if (n < 0) {
            throw new IllegalArgumentException(
                "O fatorial não está definido para números negativos"
            );
        }
        if (n == 0 || n == 1) {
            return 1;
        }
        return n * factorial(n - 1);
    }

    public static void main(String[] args) {
        runTests();
    }

    public static void runTests() {
        assert factorial(0) == 1 : "Teste falhou para factorial(0)";
        assert factorial(1) == 1 : "Teste falhou para factorial(1)";
        assert factorial(5) == 120 : "Teste falhou para factorial(5)";

        try {
            factorial(-1);
            assert false : "Deveria ter lançado uma exceção para entrada negativa";
        } catch (IllegalArgumentException e) {
            // Exceção esperada
        }

        System.out.println("Todos os testes passaram!");
    }
}

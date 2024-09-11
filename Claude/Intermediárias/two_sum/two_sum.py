import unittest

def factorial(n):
    if n < 0:
        raise ValueError("O fatorial não está definido para números negativos")
    if n == 0 or n == 1:
        return 1
    return n * factorial(n - 1)

class TestFactorial(unittest.TestCase):
    def test_factorial_of_zero(self):
        self.assertEqual(factorial(0), 1)

    def test_factorial_of_one(self):
        self.assertEqual(factorial(1), 1)

    def test_factorial_of_five(self):
        self.assertEqual(factorial(5), 120)

    def test_factorial_of_negative(self):
        with self.assertRaises(ValueError):
            factorial(-1)

if __name__ == "__main__":
    unittest.main()

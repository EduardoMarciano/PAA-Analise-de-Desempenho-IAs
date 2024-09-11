import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Random;
import java.util.function.Function;

class Fruit {
    String name;
    double price;

    Fruit(String name, double price) {
        this.name = name;
        this.price = price;
    }
}

class QuickSortFruits {
    private static void quickSort(List<Fruit> arr, int low, int high, Function<Fruit, Double> priceFunc) {
        if (low < high) {
            int pi = partition(arr, low, high, priceFunc);
            quickSort(arr, low, pi - 1, priceFunc);
            quickSort(arr, pi + 1, high, priceFunc);
        }
    }

    private static int partition(List<Fruit> arr, int low, int high, Function<Fruit, Double> priceFunc) {
        double pivot = priceFunc.apply(arr.get(high));
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (priceFunc.apply(arr.get(j)) <= pivot) {
                i++;
                Fruit temp = arr.get(i);
                arr.set(i, arr.get(j));
                arr.set(j, temp);
            }
        }
        Fruit temp = arr.get(i + 1);
        arr.set(i + 1, arr.get(high));
        arr.set(high, temp);
        return i + 1;
    }

    private static double getPriceWithOldTax(Fruit fruit) {
        return fruit.price;
    }

    private static double getPriceWithNewTax(Fruit fruit) {
        if (fruit.name.equals("banana") || fruit.name.equals("apple")) {
            return fruit.price * 1.1; // 10% tax increase
        }
        return fruit.price;
    }

    public static void main(String[] args) {
        Random random = new Random();
        List<String> fruitNames = Arrays.asList("apple", "banana", "orange", "grape", "pear");
        List<Fruit> fruits = new ArrayList<>();

        // Generate 200 random fruits
        for (int i = 0; i < 200; i++) {
            String name = fruitNames.get(random.nextInt(fruitNames.size()));
            double price = 0.5 + (5.0 - 0.5) * random.nextDouble();
            fruits.add(new Fruit(name, price));
        }

        // Sort with old taxes
        List<Fruit> oldTaxFruits = new ArrayList<>(fruits);
        quickSort(oldTaxFruits, 0, oldTaxFruits.size() - 1, QuickSortFruits::getPriceWithOldTax);

        // Sort with new taxes
        List<Fruit> newTaxFruits = new ArrayList<>(fruits);
        quickSort(newTaxFruits, 0, newTaxFruits.size() - 1, QuickSortFruits::getPriceWithNewTax);

        // Print results
        System.out.println("Sorted fruits with old taxes:");
        for (int i = 0; i < 10 && i < oldTaxFruits.size(); i++) {
            Fruit fruit = oldTaxFruits.get(i);
            System.out.printf("%s: $%.2f%n", fruit.name, fruit.price);
        }

        System.out.println("\nSorted fruits with new taxes:");
        for (int i = 0; i < 10 && i < newTaxFruits.size(); i++) {
            Fruit fruit = newTaxFruits.get(i);
            double price = getPriceWithNewTax(fruit);
            System.out.printf("%s: $%.2f%n", fruit.name, price);
        }
    }
}
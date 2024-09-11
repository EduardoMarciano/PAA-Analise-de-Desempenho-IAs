import java.util.ArrayList;
import java.util.List;

class Fruit {
    String name;
    double price;
    boolean isTaxed;

    Fruit(String name, double price, boolean isTaxed) {
        this.name = name;
        this.price = price;
        this.isTaxed = isTaxed;
    }
}

public class FruitSorter {
    public static void quicksort(List<Fruit> fruits, int low, int high) {
        if (low < high) {
            int pivotIndex = partition(fruits, low, high);
            quicksort(fruits, low, pivotIndex - 1);
            quicksort(fruits, pivotIndex + 1, high);
        }
    }

    private static int partition(List<Fruit> fruits, int low, int high) {
        double pivotPrice = fruits.get(high).price;
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (fruits.get(j).price <= pivotPrice) {
                i++;
                Fruit temp = fruits.get(i);
                fruits.set(i, fruits.get(j));
                fruits.set(j, temp);
            }
        }

        Fruit temp = fruits.get(i + 1);
        fruits.set(i + 1, fruits.get(high));
        fruits.set(high, temp);
        return i + 1;
    }

    public static void main(String[] args) {
        // Create a list of fruits
        List<Fruit> fruits = new ArrayList<>();
        fruits.add(new Fruit("apple", 1.5, true));
        fruits.add(new Fruit("banana", 1.2, true));
        fruits.add(new Fruit("orange", 1.0, false));
        // ... add more fruits

        // Sort with original taxes
        List<Fruit> fruitsWithOriginalTaxes = new ArrayList<>(fruits);
        quicksort(fruitsWithOriginalTaxes, 0, fruitsWithOriginalTaxes.size() - 1);

        // Sort with increased taxes
        for (Fruit fruit : fruits) {
            if (fruit.isTaxed) {
                fruit.price *= 1.1; // Increase price by 10% for taxed fruits
            }
        }
        List<Fruit> fruitsWithIncreasedTaxes = new ArrayList<>(fruits);
        quicksort(fruitsWithIncreasedTaxes, 0, fruitsWithIncreasedTaxes.size() - 1);

        // Print results
        // ...
        
    }
}
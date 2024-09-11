import java.util.Arrays;

class Fruit implements Comparable<Fruit> {
    String name;
    double price;

    public Fruit(String name, double price) {
        this.name = name;
        this.price = price;
    }

    @Override
    public int compareTo(Fruit other) {
        return Double.compare(this.price, other.price);
    }

    @Override
    public String toString() {
        return name + ": " + price;
    }
}

public class QuickSortFruits {

    private static void swap(Fruit[] arr, int i, int j) {
        Fruit temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    private static int partition(Fruit[] arr, int low, int high) {
        double pivot = arr[high].price;
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j].price <= pivot) {
                i++;
                swap(arr, i, j);
            }
        }
        swap(arr, i + 1, high);
        return i + 1;
    }

    private static void quicksort(Fruit[] arr, int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);
            quicksort(arr, low, pi - 1);
            quicksort(arr, pi + 1, high);
        }
    }

    private static void adjustPrices(Fruit[] fruits, double bananaTax, double appleTax) {
        for (Fruit fruit : fruits) {
            if (fruit.name.equals("banana")) {
                fruit.price += bananaTax;
            } else if (fruit.name.equals("apple")) {
                fruit.price += appleTax;
            }
        }
    }

    public static void main(String[] args) {
        Fruit[] fruits = new Fruit[200];
        
        // Initialize fruits array with some dummy data
        for (int i = 0; i < fruits.length; i++) {
            fruits[i] = new Fruit("fruit" + i, 10.0 + i);
        }

        System.out.println("Sorting with old prices:");
        quicksort(fruits, 0, fruits.length - 1);
        Arrays.stream(fruits).forEach(System.out::println);

        // Adjust prices for banana and apple
        adjustPrices(fruits, 2.0, 3.0); // Example taxes

        System.out.println("\nSorting with new prices:");
        quicksort(fruits, 0, fruits.length - 1);
        Arrays.stream(fruits).forEach(System.out::println);
    }
}

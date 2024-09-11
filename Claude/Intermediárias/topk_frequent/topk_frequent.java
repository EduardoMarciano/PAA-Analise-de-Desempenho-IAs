import java.util.*;

public class TopKFrequentElements {

    public int[] topKFrequent(int[] nums, int k) {
        // Step 1: Count the frequency of each number
        Map<Integer, Integer> frequencyMap = new HashMap<>();
        for (int num : nums) {
            frequencyMap.put(num, frequencyMap.getOrDefault(num, 0) + 1);
        }

        // Step 2: Create a priority queue (min-heap) to keep track of the k most frequent elements
        PriorityQueue<Integer> pq = new PriorityQueue<>(
            (a, b) -> frequencyMap.get(a) - frequencyMap.get(b)
        );

        for (int num : frequencyMap.keySet()) {
            pq.offer(num);
            if (pq.size() > k) {
                pq.poll();
            }
        }

        // Step 3: Build the result array
        int[] result = new int[k];
        for (int i = k - 1; i >= 0; i--) {
            result[i] = pq.poll();
        }

        return result;
    }

    public static void main(String[] args) {
        TopKFrequentElements solution = new TopKFrequentElements();

        // Test case
        int[] nums = { 1, 1, 1, 2, 2, 3 };
        int k = 2;

        int[] result = solution.topKFrequent(nums, k);

        System.out.println("Input array: " + Arrays.toString(nums));
        System.out.println("k = " + k);
        System.out.println(
            "Top " + k + " frequent elements: " + Arrays.toString(result)
        );
    }
}

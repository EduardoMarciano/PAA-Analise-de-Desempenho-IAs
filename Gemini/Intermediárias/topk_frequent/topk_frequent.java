import java.util.*;

public class TopKFrequentElements {

    public List<Integer> topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> count = new HashMap<>();
        for (int num : nums) {
            count.put(num, count.getOrDefault(num, 0) + 1);
        }

        // Criando um min-heap baseado na frequência (valor)
        PriorityQueue<Map.Entry<Integer, Integer>> minHeap =
            new PriorityQueue<>((a, b) -> a.getValue() - b.getValue());

        for (Map.Entry<Integer, Integer> entry : count.entrySet()) {
            minHeap.add(entry);
            if (minHeap.size() > k) {
                minHeap.poll();
            }
        }

        List<Integer> result = new ArrayList<>();
        while (!minHeap.isEmpty()) {
            result.add(minHeap.poll().getKey());
        }
        Collections.reverse(result);
        return result;
    }

    public static void main(String[] args) {
        int[] nums = { 1, 1, 1, 2, 2, 3 };
        int k = 2;
        TopKFrequentElements solution = new TopKFrequentElements();
        List<Integer> result = solution.topKFrequent(nums, k);
        System.out.println(result); // Saída: [1, 2]
    }
}

import java.util.*;

public class TopKFrequentElements {
    public static List<Integer> topKFrequent(int[] nums, int k) {
        // HashMap para armazenar a frequência de cada elemento
        Map<Integer, Integer> frequencyMap = new HashMap<>();
        for (int num : nums) {
            frequencyMap.put(num, frequencyMap.getOrDefault(num, 0) + 1);
        }

        // PriorityQueue para manter os k elementos mais frequentes
        // O heap é min-heap baseado na frequência dos elementos
        PriorityQueue<Integer> minHeap = new PriorityQueue<>(Comparator.comparingInt(frequencyMap::get));

        for (int num : frequencyMap.keySet()) {
            minHeap.add(num);
            if (minHeap.size() > k) {
                minHeap.poll();
            }
        }

        // Extrair os elementos do heap para o resultado
        List<Integer> topKElements = new ArrayList<>();
        while (!minHeap.isEmpty()) {
            topKElements.add(minHeap.poll());
        }

        // Pode ser necessário reverter para garantir a ordem do mais frequente para o menos frequente
        Collections.reverse(topKElements);
        return topKElements;
    }

    public static void main(String[] args) {
        int[] nums = {1, 1, 1, 2, 2, 3};
        int k = 2;
        List<Integer> result = topKFrequent(nums, k);
        System.out.println("Top " + k + " frequent elements: " + result);
    }
}

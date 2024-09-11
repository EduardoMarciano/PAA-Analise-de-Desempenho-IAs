import java.util.*;

class StableMarriage {
    static class Pair {
        int first, second;
        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    public static List<Pair> stableMarriage(int[][] studentPrefs, int[][] hospitalPrefs) {
        int n = studentPrefs.length;
        int[] hospitalStudents = new int[n];
        Arrays.fill(hospitalStudents, -1);
        int[] studentNext = new int[n];
        Queue<Integer> freeStudents = new LinkedList<>();

        for (int i = 0; i < n; i++) {
            freeStudents.offer(i);
        }

        while (!freeStudents.isEmpty()) {
            int student = freeStudents.poll();
            int hospital = studentPrefs[student][studentNext[student]];
            studentNext[student]++;

            if (hospitalStudents[hospital] == -1) {
                hospitalStudents[hospital] = student;
            } else {
                int currentStudent = hospitalStudents[hospital];
                int newRank = -1, currentRank = -1;
                for (int i = 0; i < n; i++) {
                    if (hospitalPrefs[hospital][i] == student) newRank = i;
                    if (hospitalPrefs[hospital][i] == currentStudent) currentRank = i;
                }

                if (newRank < currentRank) {
                    freeStudents.offer(currentStudent);
                    hospitalStudents[hospital] = student;
                } else {
                    freeStudents.offer(student);
                }
            }
        }

        List<Pair> result = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            result.add(new Pair(i, hospitalStudents[i]));
        }
        return result;
    }

    public static void main(String[] args) {
        int[][] studentPrefs = {
            {0, 1, 2},
            {1, 0, 2},
            {0, 1, 2}
        };
        int[][] hospitalPrefs = {
            {0, 2, 1},
            {1, 0, 2},
            {0, 1, 2}
        };

        List<Pair> result = stableMarriage(studentPrefs, hospitalPrefs);

        System.out.println("Stable pairings (hospital, student):");
        for (Pair pair : result) {
            System.out.println(pair.first + ": " + pair.second);
        }
    }
}
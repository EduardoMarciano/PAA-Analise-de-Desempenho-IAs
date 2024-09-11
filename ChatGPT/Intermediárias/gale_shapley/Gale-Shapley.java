import java.util.*;

public class GaleShapley {
    public static int[] galeShapley(int[][] studentPrefs, int[][] hospitalPrefs) {
        int n = studentPrefs.length;
        int[] studentMatches = new int[n];
        int[] hospitalMatches = new int[n];
        int[] studentNextProposal = new int[n];
        Arrays.fill(studentMatches, -1);
        Arrays.fill(hospitalMatches, -1);
        
        // Build hospital rankings for fast lookup
        int[][] hospitalRanking = new int[n][n];
        for (int h = 0; h < n; h++) {
            for (int rank = 0; rank < n; rank++) {
                hospitalRanking[h][hospitalPrefs[h][rank]] = rank;
            }
        }
        
        Queue<Integer> freeStudents = new LinkedList<>();
        for (int s = 0; s < n; s++) {
            freeStudents.add(s);
        }
        
        while (!freeStudents.isEmpty()) {
            int student = freeStudents.poll();
            int hospital = studentPrefs[student][studentNextProposal[student]++];
            
            if (hospitalMatches[hospital] == -1) {
                studentMatches[student] = hospital;
                hospitalMatches[hospital] = student;
            } else {
                int currentStudent = hospitalMatches[hospital];
                if (hospitalRanking[hospital][student] < hospitalRanking[hospital][currentStudent]) {
                    studentMatches[student] = hospital;
                    studentMatches[currentStudent] = -1;
                    freeStudents.add(currentStudent);
                    hospitalMatches[hospital] = student;
                } else {
                    freeStudents.add(student);
                }
            }
        }
        
        return studentMatches;
    }

    public static void main(String[] args) {
        int[][] studentPrefs = {{0, 1, 2}, {1, 2, 0}, {2, 0, 1}};
        int[][] hospitalPrefs = {{0, 1, 2}, {1, 0, 2}, {2, 1, 0}};

        int[] matches = galeShapley(studentPrefs, hospitalPrefs);
        for (int s = 0; s < matches.length; s++) {
            System.out.println("Student " + s + " matched with Hospital " + matches[s]);
        }
    }
}

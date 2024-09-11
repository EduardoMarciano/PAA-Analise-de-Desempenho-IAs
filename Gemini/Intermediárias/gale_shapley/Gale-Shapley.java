import java.util.*;

class Student {
    String name;
    List<Hospital> preferences;

    public Student(String name, List<Hospital> preferences) {
        this.name = name;
        this.preferences = preferences;
    }
}

class Hospital {
    String name;
    List<Student> preferences;

    public Hospital(String name, List<Student> preferences) {
        this.name = name;
        this.preferences = preferences;
    }
}

public class StableMatching {
    public static Map<Student, Hospital> findStableMatching(List<Student> students, List<Hospital> hospitals) {
        Map<Student, Hospital> matches = new HashMap<>();
        Map<Hospital, Student> hospitalMatches = new HashMap<>();

        // Initialize all hospitals to free
        for (Hospital hospital : hospitals) {
            hospitalMatches.put(hospital, null);
        }

        while (!students.isEmpty()) {
            Student student = students.remove(0);
            Hospital hospital = student.preferences.get(0);

            if (hospitalMatches.get(hospital) == null) {
                matches.put(student, hospital);
                hospitalMatches.put(hospital, student);
            } else {
                Student currentMatch = hospitalMatches.get(hospital);

                if (hospital.preferences.indexOf(student) < hospital.preferences.indexOf(currentMatch)) {
                    matches.put(student, hospital);
                    hospitalMatches.put(hospital, student);
                    students.add(currentMatch);
                }
            }

            student.preferences.remove(0);
        }

        return matches;
    }

    public static void main(String[] args) {
        // ... (create students and hospitals with preferences)
        List<Student> students = ...;
        List<Hospital> hospitals = ...;

        Map<Student, Hospital> stableMatching = findStableMatching(students, hospitals);

        // Print the stable matching
        for (Map.Entry<Student, Hospital> entry : stableMatching.entrySet()) {
            System.out.println(entry.getKey().name + " matched with " + entry.getValue().name);
        }
    }
}
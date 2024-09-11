#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> stable_marriage(const vector<vector<int>>& student_prefs, const vector<vector<int>>& hospital_prefs) {
    int n = student_prefs.size();
    vector<int> hospital_students(n, -1);
    vector<int> student_next(n, 0);
    queue<int> free_students;

    for (int i = 0; i < n; ++i) {
        free_students.push(i);
    }

    while (!free_students.empty()) {
        int student = free_students.front();
        free_students.pop();

        int hospital = student_prefs[student][student_next[student]];
        student_next[student]++;

        if (hospital_students[hospital] == -1) {
            hospital_students[hospital] = student;
        } else {
            int current_student = hospital_students[hospital];
            auto it1 = find(hospital_prefs[hospital].begin(), hospital_prefs[hospital].end(), student);
            auto it2 = find(hospital_prefs[hospital].begin(), hospital_prefs[hospital].end(), current_student);

            if (it1 < it2) {
                free_students.push(current_student);
                hospital_students[hospital] = student;
            } else {
                free_students.push(student);
            }
        }
    }

    vector<pair<int, int>> result;
    for (int i = 0; i < n; ++i) {
        result.emplace_back(i, hospital_students[i]);
    }
    return result;
}

int main() {
    vector<vector<int>> student_prefs = {
        {0, 1, 2},
        {1, 0, 2},
        {0, 1, 2}
    };
    vector<vector<int>> hospital_prefs = {
        {0, 2, 1},
        {1, 0, 2},
        {0, 1, 2}
    };

    auto result = stable_marriage(student_prefs, hospital_prefs);

    cout << "Stable pairings (hospital, student):" << endl;
    for (const auto& [hospital, student] : result) {
        cout << hospital << ": " << student << endl;
    }

    return 0;
}
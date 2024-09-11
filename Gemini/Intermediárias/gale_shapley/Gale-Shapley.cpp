#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Student {
    int id;
    vector<int> preferredHospitals;
};

struct Hospital {
    int id;
    vector<int> preferredStudents;
};

int main() {
    int numStudents, numHospitals;
    cin >> numStudents >> numHospitals;

    vector<Student> students(numStudents);
    vector<Hospital> hospitals(numHospitals);

    // Read student and hospital preferences
    for (int i = 0; i < numStudents; ++i) {
        students[i].id = i;
        // Read preferred hospitals for student i
    }

    for (int i = 0; i < numHospitals; ++i) {
        hospitals[i].id = i;
        // Read preferred students for hospital i
    }

    // Gale-Shapley algorithm
    while (true) {
        bool foundMatch = false;
        for (Student& student : students) {
            if (student.preferredHospitals.empty()) {
                continue;
            }

            int hospitalId = student.preferredHospitals.front();
            student.preferredHospitals.erase(student.preferredHospitals.begin());

            if (hospitals[hospitalId].preferredStudents.empty() || hospitals[hospitalId].preferredStudents.front() > student.id) {
                hospitals[hospitalId].preferredStudents.clear();
                hospitals[hospitalId].preferredStudents.push_back(student.id);
                foundMatch = true;
            }
        }

        if (!foundMatch) {
            break;
        }
    }

    // Print the stable matching
    for (const Hospital& hospital : hospitals) {
        if (!hospital.preferredStudents.empty()) {
            cout << "Student " << hospital.preferredStudents.front() << " is matched with Hospital " << hospital.id << endl;
        }
    }

    return 0;
}
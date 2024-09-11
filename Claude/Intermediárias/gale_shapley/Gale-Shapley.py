def stable_marriage(student_prefs, hospital_prefs):
    n = len(student_prefs)
    free_students = list(range(n))
    hospital_students = [-1] * n
    student_next = [0] * n

    while free_students:
        student = free_students.pop(0)
        student_list = student_prefs[student]
        hospital = student_list[student_next[student]]
        student_next[student] += 1

        if hospital_students[hospital] == -1:
            hospital_students[hospital] = student
        else:
            current_student = hospital_students[hospital]
            hospital_list = hospital_prefs[hospital]
            if hospital_list.index(student) < hospital_list.index(current_student):
                free_students.append(current_student)
                hospital_students[hospital] = student
            else:
                free_students.append(student)

    return [(i, hospital_students[i]) for i in range(n)]

# Example usage
student_prefs = [
    [0, 1, 2],
    [1, 0, 2],
    [0, 1, 2]
]
hospital_prefs = [
    [0, 2, 1],
    [1, 0, 2],
    [0, 1, 2]
]

result = stable_marriage(student_prefs, hospital_prefs)
print("Stable pairings (hospital, student):")
for hospital, student in result:
    print(f"{hospital}: {student}")
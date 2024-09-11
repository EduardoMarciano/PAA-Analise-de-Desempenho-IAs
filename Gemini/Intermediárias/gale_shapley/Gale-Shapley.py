def gale_shapley(students, hospitals):
    """
    Finds a stable matching between students and hospitals.

    Args:
        students: A list of students, each with a preference list of hospitals.
        hospitals: A list of hospitals, each with a preference list of students.

    Returns:
        A dictionary representing the stable matching.
    """

    free_students = set(students)
    engaged_students = {}
    while free_students:
        student = free_students.pop()
        for hospital in student.preferences:
            if hospital.is_engaged():
                current_student = hospital.get_engaged_student()
                if hospital.prefer(student, current_student):
                    engaged_students.pop(current_student)
                    free_students.add(current_student)
                    hospital.engage(student)
                    engaged_students[student] = hospital
                    break
            else:
                hospital.engage(student)
                engaged_students[student] = hospital
                break

    return engaged_students
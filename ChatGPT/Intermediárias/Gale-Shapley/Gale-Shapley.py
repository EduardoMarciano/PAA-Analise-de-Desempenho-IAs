def gale_shapley(students, hospitals):
    # Number of students and hospitals
    n = len(students)
    
    # Initialize data structures
    free_students = list(range(n))
    student_matches = [-1] * n
    hospital_matches = [-1] * n
    student_preferences = [sorted(prefs) for prefs in students]
    hospital_preferences = [sorted(prefs) for prefs in hospitals]
    
    # Create preference lists for fast lookup
    hospital_rankings = [{student: rank for rank, student in enumerate(prefs)} for prefs in hospital_preferences]

    while free_students:
        student = free_students.pop(0)
        student_pref = student_preferences[student]
        
        # Propose to the next hospital on the student's list
        for hospital in student_pref:
            current_match = hospital_matches[hospital]
            if current_match == -1:
                # Hospital is free, so match them
                student_matches[student] = hospital
                hospital_matches[hospital] = student
                break
            else:
                # Hospital is currently matched
                if hospital_rankings[hospital][student] < hospital_rankings[hospital][current_match]:
                    # Hospital prefers the new student, so replace current match
                    free_students.append(current_match)
                    student_matches[current_match] = -1
                    
                    student_matches[student] = hospital
                    hospital_matches[hospital] = student
                    break

    return student_matches

# Example usage
students = [[0, 1, 2], [1, 2, 0], [2, 0, 1]]  # Student preferences
hospitals = [[0, 1, 2], [1, 0, 2], [2, 1, 0]] # Hospital preferences

result = gale_shapley(students, hospitals)
print("Student to Hospital matches:", result)

def main():
    while True:
        try:
            num_students = int(input("Enter the number of students: "))
            if num_students > 0:
                break
            else:
                print("Number of students must be a positive integer. Please try again.")
        except ValueError:
            print("Invalid input. Please enter a positive integer.")
    
    total_sum = 0
    for i in range(num_students):
        while True:
            try:
                grade = float(input(f"Enter grade for student {i+1} (0-100): "))
                if 0 <= grade <= 100:
                    total_sum += grade
                    break
                else:
                    print("Grade must be between 0 and 100. Please try again.")
            except ValueError:
                print("Invalid input. Please enter a number between 0 and 100.")
    
    average = total_sum / num_students 
    
    print(f"The class average is: {average:.2f}")

if __name__ == "__main__":
    main()
1
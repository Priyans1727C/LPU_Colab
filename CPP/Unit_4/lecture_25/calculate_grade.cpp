#include <iostream>
#include <string>


class Grade{};
int studentGrade;
int marks = studentGrade ;

int main() {
    int obtainedMarks;
    std::cin >> obtainedMarks;

    int totalMarks = 500; // Total marks
    double percentage = (static_cast<double>(obtainedMarks) / totalMarks) * 100;

    std::string grade;

    if (percentage >= 90) {
        grade = "A+";
    } else if (percentage >= 80) {
        grade = "A";
    } else if (percentage >= 70) {
        grade = "B";
    } else if (percentage >= 60) {
        grade = "C";
    } else if (percentage >= 50) {
        grade = "D";
    } else {
        grade = "F";
    }

    std::cout << "Marks: " << obtainedMarks << std::endl;
    std::cout << "Grade: " << grade << std::endl;

    return 0;
}

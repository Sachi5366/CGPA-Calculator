#include <iostream>
#include <limits>
#include <iomanip>

int main() {
    std::cout << "CGPA Calculator (credit-weighted)\n";
    std::cout << "Enter number of semesters: ";
    int n;
    while (!(std::cin >> n) || n <= 0) {
        std::cout << "Please enter a positive integer for semesters: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    double totalGradePoints = 0.0; // sum of (credits * SGPA)
    double totalCredits = 0.0;

    for (int i = 1; i <= n; ++i) {
        double credits = 0.0, sgpa = 0.0;
        std::cout << "\nSemester " << i << ":\n";

        std::cout << "  Enter total credits for semester " << i << ": ";
        while (!(std::cin >> credits) || credits < 0.0) {
            std::cout << "  Please enter a non-negative number for credits: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        std::cout << "  Enter SGPA for semester " << i << " (e.g. 8.5): ";
        while (!(std::cin >> sgpa) || sgpa < 0.0 || sgpa > 10.0) {
            std::cout << "  Please enter a valid SGPA (0.0 - 10.0): ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        totalCredits += credits;
        totalGradePoints += credits * sgpa;
    }

    if (totalCredits == 0.0) {
        std::cout << "\nNo credits entered. Cannot compute CGPA.\n";
        return 0;
    }

    double cgpa = totalGradePoints / totalCredits;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\nYour CGPA (credit-weighted) is: " << cgpa << "\n";
    return 0;
}

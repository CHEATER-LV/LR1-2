
#include <cmath>
#include <format>
#include <iostream>
#include <numbers>
#include <stdexcept>

// Displays the author and the purpose of the program.
void printDescription() {
    std::cout << "Author: Leonid Khimyak\n";
    std::cout << "Variant 182. Calculate a mathematical expression "
              << "for a given real number x.\n";
}

// Reads a real number and reports invalid input.
double inputNumber() {
    double x = 0.0;
    std::cout << "Enter x (x > -4 and x != 5): ";
    std::cin >> x;

    if (std::cin.fail()) {
        throw std::ios_base::failure("wrong input");
    }
    return x;
}

// Checks whether x belongs to the domain of the expression.
bool checkDomain(double x) {
    return x > -4.0 && x != 5.0;
}

// Calculates the expression for a value from its domain.
double f(double x) {
    const double fraction = 14.0 / ((x - 5.0) * (x + 10.0));

    return std::cos(30.0 / 64.0)
         + (8.0 * std::numbers::e / (67.0 * std::numbers::pi)) * fraction
         - 11.0 * std::sin(x + 8.0)
         - std::log(x + 4.0) / std::log(9.0);
}

int main() {
    printDescription();
    double x = 0.0;

    try {
        x = inputNumber();
        std::cout << "\n***** do calculations ... ";

        if (!checkDomain(x)) {
            throw std::domain_error("undefined");
        }

        const double result = f(x);
        std::cout << "done\n";
        std::cout << std::format("for x = {:.5f}\n", x);
        std::cout << std::format("result = {:.9f}\n", result);
    }
    catch (const std::ios_base::failure&) {
        std::cout << "\nwrong input\n";
    }
    catch (const std::domain_error&) {
        std::cout << "done\n";
        std::cout << std::format("for x = {:.5f}\n", x);
        std::cout << "result = undefined\n";
    }

    return 0;
}

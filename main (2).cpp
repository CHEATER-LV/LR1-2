
#include <cmath>
#include <format>
#include <iostream>
#include <stdexcept>

using namespace std;

const double a = 0.0;
const double b = 1.0;

// Computes the series sum for a valid x and a positive eps.
double s(const double x, const double eps) {
    double term = 1.0;
    double sum = 0.0;
    double n = 0.0;
    const double xSquared = x * x;

    while (term >= eps || term <= -eps) {
        sum += term;
        n += 1.0;
        term *= (-2.0 * (2.0 * n - 1.0) * xSquared)
                / (n * n * n);
    }
    sum += term;
    return sum;
}

// Validates the point in which the series is evaluated.
void checkDomainX(const double x) {
    if (!isfinite(x) || x < a || x > b) {
        throw domain_error(format(
            "Invalid x: it must be in [{}, {}].", a, b));
    }
}

// Validates the requested calculation accuracy.
void checkDomainEps(const double eps) {
    if (!isfinite(eps) || eps <= 0.0) {
        throw domain_error(
            "Invalid eps: it must be a positive finite number.");
    }
}

// Reads a floating-point value and reports an input failure.
double readDouble(const char* name) {
    double value = 0.0;
    cin >> value;
    if (cin.fail()) {
        throw invalid_argument(format(
            "Invalid input for {}: expected a real number.", name));
    }
    return value;
}

// Prints the author, variant and the purpose of the program.
void printDescription() {
    cout << "Author: Leonid Khimyak\n";
    cout << "Variant 182. Calculate the sum of a power series "
         << "on [0, 1] with a given accuracy.\n";
}

// Prints the successfully computed result in the required format.
void printResult(const double x, const double eps,
                 const double result) {
    cout << "done\n";
    cout << format("for x = {:.7E}\n", x);
    cout << format("for eps = {:.9E}\n", eps);
    cout << format("result = {:.8f}\n", result);
}

int main() {
    printDescription();
    double x = 0.0;
    double eps = 0.0;

    try {
        cout << format("Enter x in [{}, {}]: ", a, b);
        x = readDouble("x");
        checkDomainX(x);

        cout << "Enter a positive eps: ";
        eps = readDouble("eps");
        checkDomainEps(eps);

        cout << "***** do calculations ... ";
        const double result = s(x, eps);
        printResult(x, eps, result);
    }
    catch (const exception& error) {
        cout << "***** error\n";
        cout << error.what() << '\n';
    }
    return 0;
}






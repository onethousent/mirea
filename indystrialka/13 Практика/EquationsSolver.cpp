#include <iostream>
#include <cmath>

class EquationsSolver {
private:
    double coefficients[8]; 

    void calculateRoots(int equationType);
    void solveByBruteForce(int equationType);
    void displayEquation(int equationType, double root1, double root2);

public:
    void solveEquations();
};

#include "EquationsSolver.h"

void EquationsSolver::calculateRoots(int equationType) {
    double a = coefficients[2 * equationType];
    double b = coefficients[2 * equationType + 1];

    double discriminant = b * b - 4 * a;

    if (discriminant > 0) {
        double root1 = (-b + sqrt(discriminant)) / (2 * a);
        double root2 = (-b - sqrt(discriminant)) / (2 * a);
        displayEquation(equationType, root1, root2);
    }
    else if (discriminant == 0) {
        double root = -b / (2 * a);
        displayEquation(equationType, root, root);
    }
    else {
        std::cout << "Уравнение " << equationType << " не имеет действительных корней." << std::endl;
    }
}

void EquationsSolver::solveByBruteForce(int equationType) {
    // Реализация метода подбора для нахождения корней уравнения
    // equationType
    // ...
}

void EquationsSolver::displayEquation(int equationType, double root1, double root2) {
    std::cout << "Уравнение " << equationType << ": " << coefficients[2 * equationType] << "x^2 + "
        << coefficients[2 * equationType + 1] << "x" << std::endl;
    std::cout << "Корни: x1 = " << root1 << ", x2 = " << root2 << std::endl;
}

void EquationsSolver::solveEquations() {
    std::cout << "Введите коэффициенты для 8 типов уравнений:" << std::endl;
    for (int i = 0; i < 8;

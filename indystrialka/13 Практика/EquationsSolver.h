class EquationsSolver {
private:
    double coefficients[8];

    void calculateRoots(int equationType);
    void solveByBruteForce(int equationType);
    void displayEquation(int equationType, double root1, double root2);

public:
    void solveEquations();
};

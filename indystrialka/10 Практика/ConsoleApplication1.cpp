#include <iostream>
#include <stdexcept>

using namespace std;

double divide(double a, double b)
{
    if (b == 0) {
        throw invalid_argument("Нельзя делить на 0");
    }
    return a / b;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    double a, b;
    cout << "Введи два занчения: ";
    cin >> a >> b;
    try {
        double result = divide(a, b);
        cout << "Результат: " << result << endl;
    }
    catch (exception& e) {
        cerr << "Ошибка: " << e.what() << endl;
    }
    return 0;
}
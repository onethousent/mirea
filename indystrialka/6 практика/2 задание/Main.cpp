#include <iostream>
#include "cone.h"
using namespace std;
int main() {
    setlocale(LC_ALL, "ru");
    Cone c1(2, 5);
    c1.output();
    cout << "Площадь поверхности: " << c1.surfaceArea() << endl;
    cout << "Объем: " << c1.volume() << endl;
    cout << '\n';

    TruncatedCone tc1(2, 5, 3, 4, 8, 1);
    tc1.output();
    cout << "Площадь поверхности: " << tc1.surfaceArea() << endl;
    cout << "Объем: " << tc1.volume() << endl;
    cout << '\n';


    TruncatedCone tc2(6);
    cin >> tc2;
    cout << tc2;
    cout << "Площадь поверхности: " << tc2.surfaceArea() << endl;
    cout << "Объем: " << tc2.volume() << endl;

    return 0;
}

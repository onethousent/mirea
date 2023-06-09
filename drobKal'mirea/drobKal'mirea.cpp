﻿#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include <list>
#include <cmath>  

using namespace std;

class Fraction {
    int numerator;
    int denominator;

public:
    Fraction(int n, int d) : numerator(n), denominator(d) {}

    Fraction(string a) {
        numerator = stoi(a.substr(0, a.find("/")));
        denominator = stoi(a.substr(a.find("/") + 1, a.length() - 1));
    }

    pair<int, int> getDrob() const {
        return make_pair(numerator, denominator);
    }

    vector<int> getMnojet() const {
        vector <int> mnojet;
        int i = 2;
        int q = numerator;

        while (q / i != 1)
        {
            if (q % i == 0) {
                q = q / i;
                mnojet.push_back(i);
            }
            else { i += 1; }
        }
        if (q == numerator) {
            mnojet.push_back(numerator);
            return mnojet;
        }
        else {
            mnojet.push_back(q);
        }
        return mnojet;
    }

    int nod_f(int a, int b) const
    {
        int t;
        if (a < b) { t = a; a = b; b = t; }
        while (b != 0) {
            t = b;
            b = a % b;
            a = t;
        }
        return a;
    }

    int nok_f(int a, int b) const {
        int nod = nod_f(a, b);
        int proizv = a * b;
        int nok = proizv / nod;
        return nok;
    }

    list <int> deli(int a) const {
        list <int> deliteli;
        for (int i = 1; i < (sqrt(a) + 1); i++) {
            if (a % i == 0) {
                deliteli.push_back(i);
                deliteli.push_back((floor(a / i)));
            }
        }
        return deliteli;
    }

    Fraction operator *(const Fraction& other) const {
        int chisl = this->numerator * other.numerator;
        int znam = this->denominator * other.denominator;
        int nod = nod_f(chisl, znam);

        if (nod > 1) {
            chisl = chisl / nod;
            znam = znam / nod;
        }
        Fraction res(chisl, znam);
        return res;
    }

    Fraction operator +(const Fraction& other) const {
        int znam = nok_f(this->denominator, other.denominator);
        int chisl = this->numerator * (znam / this->denominator) + other.numerator * (znam / other.denominator);

        int nod = nod_f(chisl, znam);
        if (nod > 1) {
            chisl = chisl / nod;
            znam = znam / nod;
        }
        Fraction res(chisl, znam);
        return res;
    }

    Fraction operator -(const Fraction& other) const {
        int znam = nok_f(this->denominator, other.denominator);
        int chisl = this->numerator * (znam / this->denominator) - other.numerator * (znam / other.denominator);

        int nod = nod_f(chisl, znam);
        if (nod > 1) {
            chisl = chisl / nod;
            znam = znam / nod;
        }
        Fraction res(chisl, znam);
        return res;
    }

    Fraction operator /(const Fraction& other) const {
        int chisl = this->numerator * other.denominator;
        int znam = this->denominator * other.numerator;
        int nod = nod_f(chisl, znam);

        if (nod > 1) {
            chisl = chisl / nod;
            znam = znam / nod;
        }
        Fraction res(chisl, znam);
        return res;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    string a, operation, b;
    cout << "Введите первую дробь. Формат 12/1\n";
    cin >> a;
    cout << "Введите операцию\n";
    cin >> operation;
    cout << "Введите вторую дробь. Формат 12/1\n";
    cin >> b;
    Fraction drob_a(a);
    Fraction drob_b(b);

    if (operation == "/") {
        Fraction invers_b(drob_b.getDrob().second, drob_b.getDrob().first);
        Fraction answer = drob_a / invers_b;

        cout << a << " / " << b << " = " << answer.getDrob().first << "/" << answer.getDrob().second;
    }
    else if (operation == "*") {
        Fraction answer = drob_a * drob_b;

        cout << a << " * " << b << " = " << answer.getDrob().first << "/" << answer.getDrob().second;
    }
    else if (operation == "+") {
        Fraction answer = drob_a + drob_b;

        cout << a << " + " << b << " = " << answer.getDrob().first << "/" << answer.getDrob().second;
    }
    else if (operation == "-") {
        Fraction answer = drob_a - drob_b;

        cout << a << " - " << b << " = " << answer.getDrob().first << "/" << answer.getDrob().second;
    }
    else {
        cout << "Я не знаю такой операции: " << operation;
    }

    return 0;
}

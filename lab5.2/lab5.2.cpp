#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double S(const double x, const double eps, int& n, double s);
double A(const double x, int n, double a);

int main()
{
    double x, xp, xk, dx, eps, s = 0;
    int n = 0;

    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;
    cout << "eps = "; cin >> eps;

    cout << fixed;

    cout << "---------------------------------------------------------------------------------" << endl;
    cout << "|" << setw(10) << "x" << setw(10) << "|";
    cout << setw(14) << "arcctg(x)" << setw(6) << "|";
    cout << setw(10) << "n" << setw(10) << "|";
    cout << setw(10) << "S" << setw(10) << "|" << endl;
    cout << "---------------------------------------------------------------------------------" << endl;

    double pi = 4 * atan(1.0);
    x = xp;
    while (x <= xk)
    {
        s = S(x, eps, n, s);

        cout << "|" << setw(10) << setprecision(3) << x << setw(10) << "|";
        cout << setw(10) << setprecision(3) << pi / 2 - atan(x * 1.0) << setw(10) << "|";
        cout << setw(10) << setprecision(3) << n << setw(10) << "|";
        cout << setw(10) << setprecision(3) << s + pi / 2. << setw(10) << "|" << endl;

        x += dx;
    }
    cout << "---------------------------------------------------------------------------------" << endl;

    return 0;
}

double S(const double x, const double eps, int &n, double s)
{
    n = 0;
    double a = -x;
    s = a;
    do
    {
        n++;
        a = A(x, n, a);
        s += a;
    } while (abs(a) >= eps);
    return s;
}

double A(const double x, int n, double a)
{
    double r = (-x * x * (2. * n - 1)) / (2. * n + 1);
    a *= r;
    return a;
}
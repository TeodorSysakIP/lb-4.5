#include <iostream>
#include <iomanip>
#include <time.h>
#include <windows.h>
using namespace std;

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    double R1, R2;
    double x, y;

    srand((unsigned)time(NULL));

    cout << "Введіть R1 і R2 (R1 > R2 > 0): ";
    cin >> R1 >> R2;

    if (R2 <= 0 || R1 <= R2)
    {
        cout << "Помилка: має виконуватись R1 > R2 > 0\n";
        return 1;
    }

    // 1 спосіб: координати вводяться з клавіатури
    cout << "\nПерші 10 пострілів (введення з клавіатури):\n";
    for (int i = 0; i < 10; i++)
    {
        cout << "x = "; cin >> x;
        cout << "y = "; cin >> y;

        if ((x <= 0 && y >= 0 && x * x + y * y <= R2 * R2) ||        // чверть круга R2 (ліва верхня)
            (x >= 0 && y <= 0 && x * x + y * y >= R2 * R2
                && x * x + y * y <= R1 * R1))         // чверть кільця (права нижня)
            cout << "Попав" << endl;
        else
            cout << "Не попав" << endl;
    }

    // 2 спосіб: випадкові координати з інтервалу [-R1; R1]
    cout << "\nНаступні 10 пострілів (випадкові точки):\n" << fixed;
    for (int i = 0; i < 10; i++)
    {
        x = 2. * R1 * rand() / RAND_MAX - R1;
        y = 2. * R1 * rand() / RAND_MAX - R1;

        if ((x <= 0 && y >= 0 && x * x + y * y <= R2 * R2) ||
            (x >= 0 && y <= 0 && x * x + y * y >= R2 * R2
                && x * x + y * y <= R1 * R1))
            cout << setw(8) << setprecision(4) << x << " "
            << setw(8) << setprecision(4) << y << "  Попав" << endl;
        else
            cout << setw(8) << setprecision(4) << x << " "
            << setw(8) << setprecision(4) << y << "  Не попав" << endl;
    }

    return 0;
}
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const double EPS = 1e-12;
const double PI = acos(-1);

double get_shift(double a, double H, double h) {
    return (H / 2.0) * sin(a) - h * tan(a);
}

int main() {
    int h, H, L;
    cin >> h >> H >> L;

    double max_angle = acos((double)h / H);

    double left = 0.0, right = max_angle;
    double best_shift = 0;

    while (right - left > EPS) {
        double m1 = left + (right - left) / 3.0;
        double m2 = right - (right - left) / 3.0;

        double s1 = get_shift(m1, H, h);
        double s2 = get_shift(m2, H, h);

        if (s1 < s2)
            left = m1;
        else
            right = m2;
    }

    double final_shift = get_shift((left + right) / 2.0, H, h);

    if (final_shift < -L)
        final_shift = -L;

    cout << fixed << setprecision(6) << final_shift << endl;

    return 0;
}

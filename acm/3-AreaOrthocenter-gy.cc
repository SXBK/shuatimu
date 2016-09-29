#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int triAreaOrth(double *points, double *ao) {
    double area = 0.5 * ((points[2] - points[0]) * (points[5] - points[3])
                         - (points[3] - points[1]) * (points[4] - points[2]));
    double orth = (points[0] + points[1] + points[2]
                   + points[3] + points[4] + points[5]) / 3;
    ao[0] = area;
    ao[1] = orth;
    return 0;
}

int main(int argc, char *argv[]) {
    int ntest = 0;
    vector<vector<double> > vpoints;
    cin >> ntest;
    string stmp;
    getline(cin, stmp);

    for (int i = 0; i < ntest; ++i) {
        int npoints;
        cin >> npoints;
        getline(cin, stmp);
        vector<double> points;

        for (int j = 0 ; j < npoints; ++j) {
            double a, b;
            cin >> a >> b;
            points.push_back(a);
            points.push_back(b);
            getline(cin, stmp);
        }

        vpoints.push_back(points);
    }

    cout.precision(3);
    cout.setf(ios::showpoint);
    cout.setf(ios::fixed);

    for (int i = 0; i < ntest; ++i) {
        double area = 0;
        double orth = 0;

        for (int j = 1; j < vpoints[i].size() / 2 - 1; ++j) {
            double pts[6] = {vpoints[i][0], vpoints[i][1], vpoints[i][j * 2],
                             vpoints[i][j * 2 + 1], vpoints[i][j * 2 + 2], vpoints[i][j * 2 + 3]
                            };
            double ao[2];
            triAreaOrth(pts, ao);
            area += ao[0];
            orth += ao[0] * ao[1];
        }

        if (0 != area) {
            orth = orth / area;
        } else {
            orth = 0;
        }

        cout << abs(area) << " " << orth << endl;
    }

    return 0;
}

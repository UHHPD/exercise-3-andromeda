#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

double poisson(double mu, int k) {
    return exp(-mu) * pow(mu, k) / tgamma(k + 1);
}

int main() {
    using namespace std;

    vector<int> zaehler(11, 0);

    ifstream fin("datensumme.txt");
    int n;
    for (int i = 0; i < 234; ++i) {
        fin >> n;
        zaehler[n] += 1;
    }
    fin.close();

    ofstream fout("histpoi.txt");

    double mu = 3.11538;  // Mean value parameter

    for (unsigned int k = 0; k < zaehler.size(); ++k) {
        double poissonProb = poisson(mu, k);
        double expectation = 234 * poissonProb;  // N * P(k, mu)

        cout << k << " : " << zaehler[k] << " - Poisson: " << poissonProb << " - Expectation: " << expectation << endl;
        fout << k << " : " << zaehler[k] << " : " << expectation << endl;
    }

    fout.close();

    return 0;
}

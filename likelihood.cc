#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

double poisson(double mu, int k) {
    return exp(-mu) * pow(mu, k) / tgamma(k + 1);
}

double negLogLikelihood(std::vector<int>& daten, double mu) {
    double negLogLikelihood = 0.0;

    for (int k : daten) {
        negLogLikelihood -= 2.0 * log(poisson(mu, k));
    }

    return negLogLikelihood;
}

int main() {
    using namespace std;

    ifstream fin("datensumme.txt");
    vector<int> daten;
    int n_i;

    // Read data from datensumme.txt and store in the vector daten
    for (int i = 0; i < 234; ++i) {
        fin >> n_i;
        daten.push_back(n_i);
    }
    fin.close();

    // Calculate -2 ln Λ
    double logLambda = 0.0;
    for (int k : daten) {
        logLambda += negLogLikelihood(daten, k) - negLogLikelihood(daten, static_cast<double>(k));
    }

    // Output -2 ln Λ
    cout << "-2 ln Λ: " << scientific << logLambda << endl;

    // Degrees of Freedom
    int ndof = 233;

    // Standard deviation approximation
    double stdDev = sqrt(2.0 * ndof);

    // Relative deviation
    double z = logLambda / sqrt(-ndof) / stdDev;

    // Output relative deviation
    cout << "Relative Deviation (z): " << z << endl;

    return 0;
}
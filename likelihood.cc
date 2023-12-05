#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

double poisson(double mu, int k) {
    return exp(-mu) * pow(mu, k) / tgamma(k + 1);
}

double prob(std::vector<int> daten, double mu) {
    double likelihood = 1.0;

    for (int k : daten) {
        likelihood *= poisson(mu, k);
    }

    return likelihood;
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

    // Compute the likelihood for µ = 3.11538 (mean of the sample)
    double mu = 3.11538;
    double likelihood = prob(daten, mu);

    // Print the likelihood
    cout << likelihood << endl;

    //(3.b) Likelihood of mu from 0 to 6

ofstream fout("likelihood.txt");

for(double mu = 0.0; mu <= 6.0; mu += 0.1){
    for (int k : daten) {
        likelihood *= poisson(mu, k);
    }
    fout << likelihood << endl;
}

    return 0;
}
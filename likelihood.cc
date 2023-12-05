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

double lambda(std::vector<int> daten, double mu) {
    double ll = 1.0;
    double max_ll = 1;
    for(int k: daten){
        ll *= poisson(mu, k);
        max_ll *= poisson(k, k);
    }
    return ll/max_ll;
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

    ofstream f_likelihood("likelihood.txt");
    ofstream f_nll("nll.txt");
    ofstream f_delta("deltanll.txt");

    double mu_mean = 3.11538;
    double nll_mean = -2 * log(prob(daten, mu_mean));

    for (double mu = 0.0; mu <= 6.0; mu += 0.1) {
        double likelihood = prob(daten, mu);
        double nll = -2 * log(prob(daten,mu));
        double deltanll = nll - nll_mean;

        f_likelihood << mu << " " << likelihood << endl;
        f_nll << mu << " " << nll << endl;
        f_delta << mu << " " << deltanll << endl;
    }
    cout << "mu_mean" << " " << -2 * log(lambda(daten, mu_mean)) << endl;
    
    f_likelihood.close();
    f_nll.close();
    f_delta.close();

    

    int n_dof = 233;

    cout << "z = " << (-2* log(lambda(daten, 3.11538)) - n_dof)/sqrt(2*n_dof) << endl;


    return 0;
}
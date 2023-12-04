#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>


double poisson(double mu, int k) {
    return exp(-mu) * pow(mu, k) / tgamma(k + 1);
}

int main() {

    int N = 234;

    using namespace std;

    vector<int> zaehler(11, 0);

    ifstream fin("datensumme.txt");
    int n;
    for(int i = 0 ; i < 234 ; ++i) {
        fin >> n;
        zaehler[n] += 1;
    }
    fin.close();

    ofstream fout("hist.txt");

    for (unsigned int k = 0; 
    k < zaehler.size(); 
    ++k) 
    {
        cout << k << " : " << zaehler[k] << std::endl;
        fout << k << " : " << zaehler[k] << std::endl;
    }

    fout.close();

    double mu_mean = 3.11538;

    ofstream pout("histpoi.txt");

    for (unsigned int k = 0; k < zaehler.size(); ++k) {
        double expectation = N * poisson(mu_mean, k);
        pout << k << " " << expectation << std::endl;
    }

    pout.close();


}
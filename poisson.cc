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
    int N = 234;
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

    
    ofstream fout_comparison("histpoi.txt");

    for(unsigned int k=0; k<zaehler.size(); k++){
        fout_comparison << k << " " << zaehler[k] << " " << N*poisson(3.11538, k) << endl;
    }

    fout_comparison.close();

    return 0;
}

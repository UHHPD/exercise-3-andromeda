#include <iostream>
#include <fstream>
#include <vector>


double poisson(double mu, int k) {
    return 0;
}

int main() {
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

}
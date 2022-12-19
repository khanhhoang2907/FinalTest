#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ifstream fin("ly.inp");
    ofstream fout("ly.out");
    int n;
    fin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        fin >> a[i];
    }
    int max = a[0];
    for(int i = 0; i < n; i++){
        if(a[i] > max){
            max = a[i];
        }
    }
    fout << max;
    fin.close();
    fout.close();
    return 0;
}

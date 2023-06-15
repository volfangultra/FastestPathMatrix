#include <iostream>
#include "funkcije.h"

using namespace std;

int main(){
    vector<vector<bool>> zidovi = {{0,0,1,0},{1,0,0,0},{1,1,1,1},{0,0,0,0}};
    vector<int> indexi = {1,1,0};
    cout << "Prvo vidimo obicnu matricu 4x4" << endl;
    cout << "Broj puteva od (0,0) do (0,3) je: " << broj_puteva(4,4) << endl;
    cout << "Ako dodamo zidove dobijamo: " << broj_puteva(4,4,zidovi) << endl;
    cout << "Ako kazemo da se neki redovi moraju posjetit: " << broj_puteva(4,4, indexi) << endl;

}

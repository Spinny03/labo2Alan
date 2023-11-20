#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

#define PASCALDIM 10

int normaInf(vector<vector<int>>);

int factorial(int);

int main(int argc, char *argv[]){
    
    vector<vector<int>> matrA1 =    {{3, 1,-1, 0},
                                    {0, 7,-3, 0},
                                    {0,-3, 9,-2},
                                    {0, 0, 4,-10}};

    vector<vector<int>> matrA2 =    {{2, 4,-2, 0},
                                    {1, 3, 0, 1},
                                    {3,-1, 1, 2},
                                    {0,-1, 2, 1}};

    cout << normaInf(matrA1) << endl;
    cout << normaInf(matrA2) << endl;

    vector<vector<int>> matrPascal(PASCALDIM, vector<int>(PASCALDIM));
    for(int i = 0; i < PASCALDIM; i++){
        for(int j = 0; j < PASCALDIM; j++){
            matrPascal.at(i).at(j) =  factorial(i + j - 2) / 
                                factorial(i - 1) * factorial(j - 1);
        }
    }

    return 0;
}

int factorial(int n){
    return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

int normaInf(vector<vector<int>> mat){

    int max = (int)NAN;
    for(int i = 0; i < mat.size(); i++){
        int sommaRiga = 0;
        for(int j = 0; j < mat[i].size(); j++){
            sommaRiga += mat[i][j];
        }
        if(max == NAN)
            max = sommaRiga;
        else if(max < sommaRiga)
            max = sommaRiga;
    }
    return max;
}


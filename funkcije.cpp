#include "funkcije.h"

#include <iostream>
#include <vector>
using namespace std;

ostream& operator<<(ostream& ispis, vector<vector<int>> m){
    for(int i = 0; i < m.size(); i++){
        for(int j = 0; j < m[i].size(); j++)
            ispis << m[i][j] << " ";
        ispis << endl;
    }
    ispis << endl;
}

int dodaj_odgovarajuce(int i, int j, vector<vector<int>>&dp){
    if(i >= dp.size() || j >= dp[0].size())
        throw "Ne odgovoraju dimenzije";
    if(dp.size() == 0)
        return 0;

    if(j == 0 && i == 0)
        return 0;
    else if(dp.size() == 1)
        return dp[i][j - 1];
    else if(i == 0)
        return dp[i][j - 1] + dp[i + 1][j - 1];
    else if(i == dp.size() - 1)
        return dp[i][j - 1] + dp[i - 1][j - 1];
    else
        return dp[i][j - 1] + dp[i - 1][j - 1] + dp[i + 1][j - 1];


}

int broj_puteva(int broj_redova, int broj_kolona){

    vector<vector<int>> dp(broj_redova, vector<int>(broj_kolona, 0));

    for(int i = 0; i < dp.size(); i++)
        dp[i][i] = 1;

    for(int razlika = 1; razlika < broj_kolona; razlika++){
        for(int i = 0; i < broj_redova; i++){
            int j = razlika + i;
            if(j < broj_kolona)
                dp[i][j] = dodaj_odgovarajuce(i, j, dp);
        }
    }

    if(broj_kolona <= 0)
        return 0;
    return dp[0][broj_kolona - 1];

}


int broj_puteva(int broj_redova, int broj_kolona, vector<vector<bool>>& zidovi){
    if(zidovi.size() == 0 || zidovi.size() != broj_redova || zidovi[0].size() != broj_kolona)
        return 0;

     vector<vector<int>> dp(broj_redova, vector<int>(broj_kolona, 0));

    for(int razlika = 0; razlika < broj_kolona; razlika++){
        for(int i = 0; i < broj_redova; i++){
            if(i == 0 && razlika == 0)
                dp[0][0] = 1;
            else{
                int j = razlika + i;
                if(j < broj_kolona && zidovi[i][j] == 0)
                    dp[i][j] = dodaj_odgovarajuce(i, j, dp);
            }

        }
    }

    if(broj_kolona <= 0)
        return 0;
    return dp[0][broj_kolona - 1];

};

int broj_puteva(int broj_redova, int broj_kolona, vector<int>& indexi){

    vector<vector<int>> dp(broj_redova, vector<int>(broj_kolona, 0));
    for(int i = 0; i < dp.size(); i++)
        dp[i][i] = 1;

    for(int razlika = 1; razlika < broj_kolona; razlika++){
        for(int i = 0; i < broj_redova; i++){
            int j = razlika + i;
            if(j < broj_kolona)
                dp[i][j] = dodaj_odgovarajuce(i, j, dp);
        }
    }
    int predhodni = -1;
    for(auto trenutni_red : indexi){

        if(trenutni_red >= broj_redova || trenutni_red < 0)
            return 0;
        int trenutna_kolona = trenutni_red;
        while(dp[trenutni_red][trenutna_kolona] != 1)
            trenutna_kolona++;
        if(trenutni_red == predhodni){
            trenutna_kolona++;
        }
        if(trenutna_kolona >= broj_kolona)
            return 0;

        if(trenutni_red == predhodni){
            for(int i = trenutna_kolona + 1; i < broj_kolona; i++)
                dp[trenutni_red][i] = dodaj_odgovarajuce(trenutni_red, i, dp);
        }

        for(int i = 0; i <= trenutni_red; i++)
            if(trenutni_red + trenutna_kolona - i < broj_kolona)
                dp[i][trenutni_red + trenutna_kolona - i] = 1;


        for(int i = trenutni_red; i < broj_redova; i++){
            if(trenutna_kolona - trenutni_red + i < broj_kolona)
                dp[i][trenutna_kolona - trenutni_red + i] = 1;
        }


        for(int i = 0; i < trenutni_red; i++){
            for(int j = 0; j < min(trenutni_red + trenutna_kolona - i, broj_kolona); j++){
                dp[i][j] = 0;
            }
        }

        for(int i = trenutni_red; i < broj_redova; i++){
            for(int j = 0; j < min(trenutna_kolona - trenutni_red + i, broj_kolona); j++){
                dp[i][j] = 0;
            }
        }

        //Ispod
        for(int zbir = trenutni_red + trenutna_kolona + 1; zbir < broj_redova + broj_kolona - 1; zbir++){
            for(int i = trenutni_red - 1; i >= 0; i--){
                int j = zbir - i;
                if(j < broj_kolona)
                    dp[i][j] = dodaj_odgovarajuce(i, j, dp);
            }
        }
        //Iznad
        for(int zbir = trenutni_red + trenutna_kolona + 1; zbir < broj_redova + broj_kolona - 1; zbir++){
            for(int i = trenutni_red + 1; i < min(zbir, broj_redova); i++){
                int j = zbir - i;
                if(j < broj_kolona)
                    dp[i][j] = dodaj_odgovarajuce(i, j, dp);
            }
        }
        predhodni = trenutni_red;
    }

    if(broj_kolona <= 0)
        return 0;
    return dp[0][broj_kolona - 1];

}






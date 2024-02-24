#include <iostream>
#include <string>

using namespace std;

/* 
se in griglia c'e' ZERO cella vuota
se in griglia c'e' UNO stiamo parlando di una X o (giocatore 1)
se in griglia c'e' DUE stiamo parlando di un CERCHIO (giocatore 2)
*/

class Tris{
public:
    int griglia[3][3];

    void reset_tabella(){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                griglia[i][j]=0;
            }
        }
    }

    void stampa_griglia(){
        cout << "-------------\n"; 
        for (int i = 0; i < 3; i++) { 
            cout << "| "; 
            for (int j = 0; j < 3; j++) { 
                cout << griglia[i][j] << " | "; 
            } 
            cout << "\n-------------\n"; 
        } 

    }

    bool giocatore_uno(int x, int y){
        if (x < 0 || x > 2){
            return false;
        }

        if (y < 0 || y > 2){
            return false;
        }

        if (griglia[x][y] == 1 || griglia[x][y] == 2){
            return false;
        }
        griglia[x][y] = 1;
        return true;
    }

    bool giocatore_due(int x, int y){
        if (x < 0 || x > 2){
            return false;
        }

        if (y < 0 || y > 2){
            return false;
        }

        if (griglia[x][y] == 1 || griglia[x][y] == 2){
            return false;
        }
        griglia[x][y] = 2;
        return true;
    }

    int controlla_vittoria(){
        for (int i = 0; i < 3; i++){
            if (controlla_colonna(i) != 0){
                return controlla_colonna(i);
            }

            if (controlla_riga(i) != 0){
                return controlla_riga(i);
            }
        }

        return controlla_diagonale();
    }

private:
    int controlla_colonna(int col) {
        int acc_uno = 0;
        int acc_due = 0;
        for (int i = 0; i < 3; i++){
            int cella = griglia[i][col];
            if (cella == 1){
                acc_uno++;
            } else if (cella == 2){
                acc_due++;
            } else {
                return false;
            }
        }
        if (acc_uno == 3){
            return 1;
        }
        if (acc_due == 3){
            return 2;
        }
        return false;
    }
    int controlla_riga(int riga) {
        int acc_uno = 0;
        int acc_due = 0;
        for (int i = 0; i < 3; i++){
            int cella = griglia[riga][i];
            if (cella == 1){
                acc_uno++;
            } else if (cella == 2){
                acc_due++;
            } else {
                return false;
            }
        }
        if (acc_uno == 3){
            return 1;
        }
        if (acc_due == 3){
            return 2;
        }
        return false;
    }

    int controlla_diagonale() {
        int acc_uno = 0;
        int acc_due = 0;
        for (int i = 0; i < 3; i++){
            int cella = griglia[i][i];
            if (cella == 1){
                acc_uno++;
            } else if (cella == 2){
                acc_due++;
            } else {
                return false;
            }
        }
        if (acc_uno == 3){
            return 1;
        }
        if (acc_due == 3){
            return 2;
        }
        return false;
    }

};

int main(int argc, char const* argv[]){

    Tris myTris;

    myTris.reset_tabella();

    cout << "Griglia iniziale" << endl;
    myTris.stampa_griglia();

    int x, y;
    bool mossa_valida;
    int vincitore;
    int contatore_mosse = 0;

    while (contatore_mosse < 9){
        do {
            cout << "Giocatore 1: Inserisci le coordinate della tua mossa" << endl;
            cout << "X: ";
            cin >> x;
            cout << "Y: ";
            cin >> y;
            mossa_valida = myTris.giocatore_uno(x, y);
        } while (!mossa_valida);

        cout << "Griglia dopo la mossa" << endl;
        myTris.stampa_griglia();

        if (contatore_mosse >=9) break;

        vincitore = myTris.controlla_vittoria();
        if (vincitore != 0){
            break;
        }

        do {     
            cout << "Giocatore 2: Inserisci le coordinate della tua mossa" << endl;
            cout << "X: ";
            cin >> x;
            cout << "Y: ";
            cin >> y;
            mossa_valida = myTris.giocatore_due(x, y);
        } while (!mossa_valida);

        cout << "Griglia dopo la mossa" << endl;
        myTris.stampa_griglia();

        vincitore = myTris.controlla_vittoria();
        if (vincitore != 0){
            break;
        }

        contatore_mosse+=2;
    }

    if (vincitore == 1){
        cout << "Ha vinto il giocatore 1" << endl;
    } else if (vincitore == 2){
        cout << "Ha vinto il giocatore 2" << endl;
    } else {
        cout << "Pareggio" << endl;
    }

    return 0;
}
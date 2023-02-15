#include <bits/stdc++.h>

using namespace std;

bool separar(string &cadenaSol, string &cadenaFa);
bool checarMano(string cadena);
int buscar(string cadena, int pos, char caracter);
bool checkInt(int indx1, int indx2, string cadena, int x, int y);
bool checkNote(int indx1, int indx2, string cadena);
bool checkRest(int indx1, int indx2, string cadena);
bool checkSlur(int indx1, int indx2, string cadena);
bool checkChord(int indx1, int indx2, string cadena);
bool checkTie(int indx1, int indx2, string cadena);

int main()
{
    string cadenaSol="";
    string cadenaFa="";
    cin >> cadenaSol;

    if(separar(cadenaSol, cadenaFa)){
        if(!checarMano(cadenaSol)){
            cout << "Cadena invalida " <<endl;
            return 0;
        }
        if(!checarMano(cadenaFa)){
            cout << "Cadena invalida " <<endl;
            return 0;
        }
        cout << "Cadena valida "<<endl;
    }else{
        cout << "Cadena invalida" <<endl;
    }
}

bool separar(string &cadenaSol, string &cadenaFa)
{
    bool segundo;
    if(cadenaSol[0] == '{' && cadenaSol[cadenaSol.size()-1] == '}'){
        for(int i=1 ; i < cadenaSol.size()-1 ; i++){
            if(cadenaSol[i] == '}' && cadenaSol[i+1] == '{'){
                cadenaFa = cadenaSol.substr(i+1, cadenaSol.size()-i+1);
                cadenaSol = cadenaSol.substr(0, i+1);
                return 1;
            }
        }
    }
    return 0;
}

bool checarMano(string cadena){
    int pos=0;
    if((cadena[1] != 'G' && cadena[1] != 'F') || cadena[2] != ','){
        return 0;
    }

    int aux;
    aux = buscar(cadena, 3, ',');
    if(!checkInt(3, aux, cadena, -11, 11) || aux == -1){
        return 0;
    }
    pos = aux+1;
    aux = buscar(cadena, pos, '/');
    if(!checkInt(pos, aux, cadena, 1, 64) || aux == -1){
        return 0;
    }
    pos = aux+1;
    aux = buscar(cadena, pos, ',');
    if(!checkInt(pos, aux, cadena, 1, 64) || aux == -1){
        return 0;
    }
    pos = aux+1;
    aux++;

    while(buscar(cadena, aux, ',')!=-1){
        aux = buscar(cadena, aux, ',');
        bool elementoValido=0;
        if(checkNote(pos, aux, cadena)){
            elementoValido=1;
        }
        if(checkChord(pos, aux, cadena)){
            elementoValido=1;
        }
        if(checkRest(pos, aux, cadena)){
            elementoValido=1;
        }
        if(checkSlur(pos, aux, cadena)){
            elementoValido=1;
        }
        if(checkTie(pos, aux, cadena)){
            elementoValido=1;
        }
        aux++;
        pos = aux;
        if(!elementoValido) return 0;
    }

    if(checkNote(aux, cadena.size()-1, cadena)){
        return 1;
    }
    if(checkChord(aux, cadena.size()-1, cadena)){
        return 1;
    }
    if(checkRest(aux, cadena.size()-1, cadena)){
        return 1;
    }
    if(checkSlur(aux, cadena.size()-1, cadena)){
        return 1;
    }
    if(checkTie(aux, cadena.size()-1, cadena)){
        return 1;
    }
    return 0;

}

int buscar(string cadena, int pos, char caracter){
    //Retorna el indice de aparicion de un primer caracter
    for(int i=pos; i < cadena.size(); i++){
        if(cadena[i] == caracter) return i;
    }

    return -1;
}

bool checkInt(int indx1, int indx2, string cadena, int x, int y){
    string dummy = cadena.substr(indx1, indx2-indx1);
    int valorDummy = stoi(dummy);
    if(valorDummy >= x && valorDummy <= y){
        return 1;
    }

    return 0;
}

bool checkNote(int indx1, int indx2, string cadena){
    int pos=0;
    string dummy = cadena.substr(indx1, indx2 - indx1);
    if(dummy[pos] == '-' || dummy[pos] == '+'){
        pos++;
        //cout << "Pos Primer Octava: "<< pos << endl;
        if(dummy[pos] == dummy[pos-1]){
            pos++;
            //cout << "Pos Segundo Octava: "<< pos << endl;
        }
    }
    if(dummy[pos] >= 'A' && dummy[pos] <= 'G'){
        pos++;
        //cout << "Pos Letra: "<< pos << endl;
        if(pos == dummy.size()){
            //cout << dummy << endl;
            return 1;
        }
        if(dummy[pos] == '-' || dummy[pos] == '+'){
            pos++;
            //cout << "Pos Signo: "<< pos << endl;
            if(dummy[pos] == '2' || dummy[pos] == '4'){
                pos++;
                //cout << "Pos numero: "<< pos << endl;
                if(pos == dummy.size()){
                    //cout << dummy << endl;
                    return 1;
                }
            }
        }
    }


    return 0;
}

bool checkRest(int indx1, int indx2, string cadena){
    int pos=0;
    string dummy = cadena.substr(indx1, indx2 - indx1);
    if(dummy[pos] == 'R'){
        pos++;
        if(pos == dummy.size()){
            return 1;
        }
        if(dummy[pos] == '+' || dummy[pos] == '-'){
            pos++;
            if(dummy[pos] == '2' || dummy[pos] == '4'){
                pos++;
                if(pos == dummy.size()){
                    return 1;
                }
            }
        }
    }


    return 0;
}
bool checkSlur(int indx1, int indx2, string cadena){
    int pos=2;
    int aux = 2;
    string dummy = cadena.substr(indx1, indx2 - indx1);

    if(dummy[0] == 's' && dummy[1] == '(' && dummy[dummy.size()-1] == ')'){
        while(buscar(dummy, aux, '.')!=-1){
            aux = buscar(dummy, aux, '.');
            if(!checkNote(pos, aux, dummy)){
                return 0;
            }
            aux++;
            pos = aux;
        }
        if(checkNote(aux, dummy.size()-1, dummy)){
            return 1;
        }
    }
    return 0;
}

bool checkChord(int indx1, int indx2, string cadena){
    int pos=2;
    int aux = 2;
    string dummy = cadena.substr(indx1, indx2 - indx1);

    if(dummy[0] == 'c' && dummy[1] == '(' && dummy[dummy.size()-1] == ')'){
        while(buscar(dummy, aux, '.')!=-1){
            aux = buscar(dummy, aux, '.');
            if(!checkNote(pos, aux, dummy)){
                return 0;
            }
            aux++;
            pos = aux;
        }
        if(checkNote(aux, dummy.size()-1, dummy)){
            return 1;
        }
    }
    return 0;
}

bool checkTie(int indx1, int indx2, string cadena){
    int pos=0;
    int aux=0;
    string dummy = cadena.substr(indx1, indx2 - indx1);
    if(dummy[pos] == 't'){
        pos++;
        if(dummy[pos] == '('){
            pos++;
            aux = buscar(dummy, pos, ')');

            if(aux == -1 || !checkInt(pos, aux, dummy, 1, 64)){
                return 0;
            }
            pos = aux+1;
            if(checkNote(pos, dummy.size(), dummy)){
                return 1;
            }
        }
    }

    return 0;
}

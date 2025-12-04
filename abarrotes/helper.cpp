//
// Created by Laboratorio Vega on 30/11/2025.
//

#include "helper.h"
#include <string>
#include <iostream>

bool isInputValid() {
    if(cin.fail()) {
        cout << "Entrada invalida, por favor intente otra vez" << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        return false;
    }
    return true;
}

void getInput(int& var) {
    do {
        cin >> var;
    }while(!isInputValid());
}

void getInput(double& var) {
    do {
        cin >> var;
    }while(!isInputValid());
}

void getInput(string& var) {
    do {
        cin >> var;
    }while(!isInputValid());
}

void getRange(int &var, int min, int max) {
    do {
        cin >> var;
        if(var < min || var > max) cout << "Valor fuera de rango" << endl;
    }while(!isInputValid() || var < min || var > max);
}

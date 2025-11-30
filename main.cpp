#include <iostream>
#include <string>
#include "helper.h"
using namespace std;

int main() {
    int num;
    cout<<"Entra un numero: ";
    getInput(num);
    cout << "Entraste: " << num << endl;

    cout<<"Entra otro numero: ";
    getInput(num);
    cout << "Entraste: " << num << endl;
    return 0;
}
#include <iostream>
#include <string>
#include <chrono>
#include "helper.h"
#include "Inventario.h"
using namespace std;

int main() {
    //ejemplo de como crear una fecha
    int anno;
    int mes;
    int dia;

    getRange(anno,1970,2026);
    getRange(mes,1,12);
    getRange(dia,1,31);
    chrono::year_month_day fecha{chrono::year(anno) , chrono::month(mes) , chrono::day(dia)};
    cout << fecha.day() << "/" << fecha.month() << "/" << fecha.year() << endl;
    return 0;
}
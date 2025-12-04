//
// Created by Laboratorio Vega on 02/12/2025.
//

#ifndef ABARROTES_LOTE_H
#define ABARROTES_LOTE_H
#include <chrono>
#include <string>
using namespace std;

class Lote {
private:
    chrono::year_month_day caducidad;
    int cantidad;
    string id;
public:
    Lote();
    Lote(chrono::year_month_day, int , string);

    int getCantidad();
    string getId();
    auto getCaducidad();

    bool estaCaducado();
    bool registrarVenta(int cantidadVendida);

    ~Lote();
};


#endif //ABARROTES_LOTE_H
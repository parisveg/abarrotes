//
// Created by Laboratorio Vega on 02/12/2025.
//

#ifndef ABARROTES_PRODUCTO_H
#define ABARROTES_PRODUCTO_H
#include <string>
#include <chrono>
#include <vector>
#include "Lote.h"
using namespace std;

class Producto {
    private:
        string nombre;
        double precio;
        vector<Lote> lotes;
    public:
    Producto();
    Producto(string nombre, double precio);

    string getNombre()const;
    bool estaLote(string &id);
    void agregarLote(chrono::year_month_day caducidad, int cantidad, string& id);
    void quitarLote(string &id);
    int cantidadLotes();
    int quitarLotesCaducados();
    Lote& getLotePrioridad();

    ~Producto();
};


#endif //ABARROTES_PRODUCTO_H
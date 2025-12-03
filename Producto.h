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

    bool estaLote();
    void agregarLote();
    void quitarLote();
    int cantidadLotes();
    int quitarLotesCaducados();
    Lote& getLotePrioridad();

    void producto();

    ~Producto();
};


#endif //ABARROTES_PRODUCTO_H
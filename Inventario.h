//
// Created by Laboratorio Vega on 02/12/2025.
//

#ifndef ABARROTES_INVENTARIO_H
#define ABARROTES_INVENTARIO_H
#include <vector>
#include "Producto.h"
#include <string>

using namespace std;
class Inventario {
    private:
        vector<Producto> productos;
    public:
    Inventario();

    void agregarProducto(Producto &producto);
    bool estaProducto(string& nombre);
    Producto& getProducto(string& nombre);
    void quitarProducto(string nombre);

    ~Inventario();
};


#endif //ABARROTES_INVENTARIO_H
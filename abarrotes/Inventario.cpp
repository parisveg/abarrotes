//
// Created by Laboratorio Vega on 02/12/2025.
//

#include "Inventario.h"
#include <vector>
#include <string>

using namespace std;

Inventario::Inventario();

void Inventario::agregarProducto(Producto &producto){
    this->productos.push_back(producto);
};

bool Inventario::estaProducto(string &nombre){
    for (const auto& producto : this->productos) {
        if (producto.getNombre() == nombre) {return true;}
    }
    return false;
}

Producto Inventario::getProducto(string &nombre){
    for (const auto& producto : this->productos) {
        if (producto.getNombre() == nombre) {return producto;}
    cout << "No se encontro el producto.\n";
    return Producto();
    }
}

void Inventario::quitarProducto(string &nombre){}
    for (int i = 0; i < this->productos.size(); ++i) {
        if (this->productos[i].getNombre() == nombre) {
            this->productos.erase(this->productos.begin()+i);
            return;
        }
    }
}
//
// Created by Laboratorio Vega on 02/12/2025.
//

#include "Inventario.h"
#include <vector
#include <string>

using namespace std;

Inventario::Inventario();

void Produto::agregarProducto(Producto &producto){
    this->productos.push_back(producto);
};

bool Producto::estaProducto(string &nombre){
    for (const auto& producto : this->productos) {
        if (producto.getNombre() == nombre) {return true;}
    }
    return false;
}

Producto Producto::getProducto(string &nombre){
    for (const auto& producto : this->productos) {
        if (producto.getNombre() == nombre) {return producto;}
}

void Inventario::quitarProducto(string &nombre){}
    for (int i = 0; i < this->productos.size(); ++i) {
        if (this->productos[i].getNombre() == nombre) {
            this->productos.erase(lotes.begin()+i);
            return;
        }
    }
    return contador;
}
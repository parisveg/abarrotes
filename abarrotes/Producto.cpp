//
// Created by Laboratorio Vega on 02/12/2025.
//

#include "Producto.h"
#include <iostream>
#include <chrono>
#include <string>
#include <vector>
using namespace std;

Producto::Producto():precio(0){}

Producto::Producto(string nombre, double precio):nombre(nombre), precio(precio){}

string Producto::getNombre()const{
    return this->nombre;
}

bool Producto::estaLote(string &id) {
    for (const auto& lote : this->lotes) {
        if (lote.getId() == id) {return true;}
    }
    return false;
}

void Producto::agregarLote(chrono::year_month_day caducidad, int cantidad, string id) {
    this->lotes.emplace_back(caducidad, cantidad, id);
}

void Producto::quitarLote(string &id) {
    if (!estaLote(id)) {
        cout << "El lote no existe.\n"
        return;
    }
    for (int i = 0; i < this->lotes.size(); ++i) {
        if (this->lotes[i].getId() == id) {
            this->lotes.erase(lotes.begin()+i);
            return;
        }
    }
}

int Producto::cantidadLotes() {
    return this->lotes.size();
}

int Producto::quitarLotesCaducados()
    int contador = 0;
    for (int i = 0; i < this->lotes.size(); ++i) {
        if (this->lotes[i].estaCaducado()) {
            this->lotes.erase(lotes.begin()+i);
            contador++;
            i--;
        }
    }
    return contador;
}



Lote Producto::getLotePrioridad(string &id) {
    if (this->lotes.empty()) {
        return year_month_day{};
    }
    year_month_day masCercana = this->lotes[0].getCaducidad();

    for (int i = 1; i < this->lotes.size(); ++i) {
        if (this->lotes[i].getCaducidad() < masCercana) {
            masCercana = this->lotes[i].getCaducidad();
        }
    }
    return masCercana;
    }
}

Producto::~Producto(){};
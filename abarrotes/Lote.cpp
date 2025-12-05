#include "Lote.h"
#include <chrono>
#include <string>
#include <iostream>

using namespace std;
using namespace chrono;

// Constructores
Lote::Lote()
    : caducidad(year_month_day{year{2025}, month{12}, day{31}}),
      cantidad(0),
      id("") {}

Lote::Lote(year_month_day cad, int cant, const string &id_)
    : caducidad(cad), cantidad(cant), id(id_) {}

// Getters const
int Lote::getCantidad() const {
    return cantidad;
}

const year_month_day& Lote::getCaducidad() const {
    return caducidad;
}

const string& Lote::getId() const {
    return id;
}

// Revisar si el lote está caducado
bool Lote::estaCaducado() const {
    auto hoy_sys = floor<days>(system_clock::now());
    year_month_day hoy{hoy_sys};
    return caducidad < hoy;
}

// Registrar venta
bool Lote::registrarVenta(int cantidadVendida) {
    if (cantidadVendida <= 0 || cantidadVendida > cantidad)
        return false;

    cantidad -= cantidadVendida;
    return true;
}

// Destructor
Lote::~Lote() {}

//
// Created by Laboratorio Vega on 02/12/2025.
//

#include "Lote.h"
#include <chrono>
#include <string>

using namespace std;

Lote::Lote() {
    caducidad = chrono::year_month_day{chrono::year{2025}, chrono::month{12}, chrono::day{31}};
    cantidad = 0;
    id = "";
}

Lote::Lote(chrono::year_month_day cad, int cant, string id_)
    : caducidad(cad), cantidad(cant), id(id_) {}

int Lote::getCantidad() {
    return cantidad;
}

auto Lote::getCaducidad() {
    return caducidad;
}

string Lote::getId() {
    return id;
}

bool Lote::estaCaducado() {
    chrono::year_month_day hoy = chrono::year_month_day{chrono::floor<chrono::days>(chrono::system_clock::now())};
    return caducidad < hoy;
}

bool Lote::registrarVenta(int cantidadVendida) {
    if (cantidadVendida <= 0) return false;
    if (cantidadVendida > cantidad) return false;

    cantidad -= cantidadVendida;
    return true;
}

Lote::~Lote() {}

#include "Producto.h"
#include <iostream>
#include <chrono>
#include <string>
#include <vector>
using namespace std;
using namespace chrono;

// Constructores
Producto::Producto() : precio(0) {}
Producto::Producto(const string& nombre, double precio) : nombre(nombre), precio(precio) {}

// Getter nombre
string Producto::getNombre() const {
    return nombre;
}

// Verificar si existe lote
bool Producto::estaLote(const string &id) const {
    for (const auto& lote : lotes) {
        if (lote.getId() == id) return true;
    }
    return false;
}

// Agregar lote
void Producto::agregarLote(year_month_day caducidad, int cantidad, const string &id) {
    lotes.emplace_back(caducidad, cantidad, id);
}

// Quitar lote por ID
void Producto::quitarLote(const string &id) {
    if (!estaLote(id)) {
        cout << "El lote no existe.\n";
        return;
    }
    for (size_t i = 0; i < lotes.size(); ++i) {
        if (lotes[i].getId() == id) {
            lotes.erase(lotes.begin() + i);
            return;
        }
    }
}

// Cantidad de lotes
int Producto::cantidadLotes() const {
    return lotes.size();
}

// Quitar lotes caducados
int Producto::quitarLotesCaducados() {
    int contador = 0;
    for (size_t i = 0; i < lotes.size(); ++i) {
        if (lotes[i].estaCaducado()) {
            lotes.erase(lotes.begin() + i);
            contador++;
            i--; // ajustar índice después de erase
        }
    }
    return contador;
}

// Obtener lote con caducidad más cercana (prioridad)
Lote& Producto::getLotePrioridad() {
    if (lotes.empty()) {
        throw runtime_error("No hay lotes disponibles");
    }

    size_t idx = 0;
    for (size_t i = 1; i < lotes.size(); ++i) {
        if (lotes[i].getCaducidad() < lotes[idx].getCaducidad()) {
            idx = i;
        }
    }
    return lotes[idx];
}

// Destructor
Producto::~Producto() {}

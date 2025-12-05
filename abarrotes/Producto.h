#ifndef ABARROTES_PRODUCTO_H
#define ABARROTES_PRODUCTO_H

#include <string>
#include <vector>
#include <chrono>
#include "Lote.h"

using namespace std;
using namespace chrono;

class Producto {
private:
    string nombre;
    double precio;
    vector<Lote> lotes;

public:
    // Constructores
    Producto();
    Producto(const string& nombre, double precio);

    // Destructor
    ~Producto();

    // Getters
    string getNombre() const;

    // Métodos
    bool estaLote(const string &id) const;
    void agregarLote(year_month_day caducidad, int cantidad, const string &id);
    void quitarLote(const string &id);
    int cantidadLotes() const;
    int quitarLotesCaducados();
    Lote& getLotePrioridad();
};

#endif // ABARROTES_PRODUCTO_H

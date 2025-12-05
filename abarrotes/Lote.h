#ifndef ABARROTES_LOTE_H
#define ABARROTES_LOTE_H

#include <chrono>
#include <string>

using namespace std;
using namespace chrono;

class Lote {
private:
    year_month_day caducidad;
    int cantidad;
    string id;

public:
    // Constructores
    Lote();
    Lote(year_month_day cad, int cant, const string &id_);

    // Getters const
    int getCantidad() const;
    const string& getId() const;
    const year_month_day& getCaducidad() const;

    // Métodos
    bool estaCaducado() const;
    bool registrarVenta(int cantidadVendida);

    // Destructor
    ~Lote();
};

#endif // ABARROTES_LOTE_H

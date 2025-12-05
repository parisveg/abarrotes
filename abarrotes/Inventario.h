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

    void agregarProducto(const Producto &producto);
    bool estaProducto(const string& nombre) const;
    Producto& getProducto(const string& nombre);
    void quitarProducto(const string &nombre);
    void cargarDesdeCSV(const string& nombreArchivo);

    ~Inventario();
};


#endif //ABARROTES_INVENTARIO_H

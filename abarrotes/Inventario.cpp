#include "Inventario.h"
#include <vector>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Constructor
Inventario::Inventario() {
    // vector<Producto> se inicializa automáticamente
}

// Agregar producto
void Inventario::agregarProducto(const Producto &producto) {
    this->productos.push_back(producto);
}

// Revisar si existe producto
bool Inventario::estaProducto(const string &nombre) const {
    for (const auto& producto : this->productos) {
        if (producto.getNombre() == nombre) return true;
    }
    return false;
}

// Obtener producto por nombre (modificable)
Producto& Inventario::getProducto(const string &nombre) {
    for (auto& producto : productos) {
        if (producto.getNombre() == nombre) return producto;
    }
    throw runtime_error("No se encontro el producto: " + nombre);
}

// Quitar producto
void Inventario::quitarProducto(const string &nombre) {
    for (size_t i = 0; i < productos.size(); ++i) {
        if (productos[i].getNombre() == nombre) {
            productos.erase(productos.begin() + i);
            return;
        }
    }
    cout << "Producto no encontrado: " << nombre << endl;
}

void Inventario::cargarDesdeCSV(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo: " << nombreArchivo << endl;
        return;
    }

    string linea;
    getline(archivo, linea); // saltar encabezado

    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string productoStr, precioStr, loteId, cantidadStr, fechaStr;

        getline(ss, productoStr, ',');
        getline(ss, precioStr, ',');
        getline(ss, loteId, ',');
        getline(ss, cantidadStr, ',');
        getline(ss, fechaStr, ',');

        double precio = stod(precioStr);
        int cantidad = stoi(cantidadStr);

        int y, m, d;
        sscanf(fechaStr.c_str(), "%d-%d-%d", &y, &m, &d);
        year_month_day fecha{year{y}, month{static_cast<unsigned>(m)}, day{static_cast<unsigned>(d)}};

        // Revisar si el producto ya existe
        bool encontrado = false;
        for (auto &prod : productos) {
            if (prod.getNombre() == productoStr) {
                prod.agregarLote(fecha, cantidad, loteId);
                encontrado = true;
                break;
            }
        }

        // Si no se encontró, crear nuevo producto
        if (!encontrado) {
            Producto nuevoProducto(productoStr, precio);
            nuevoProducto.agregarLote(fecha, cantidad, loteId);
            productos.push_back(nuevoProducto);
        }
    }

    archivo.close();
}

Inventario::~Inventario() {}

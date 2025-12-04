#include <iostream>
#include <string>
#include <chrono>
#include <limits>

#include "Inventario.h"
#include "Producto.h"
#include "Lote.h"
#include "helper.h"

using namespace std;
using namespace std::chrono;

year_month_day pedirFecha() {
    int y, m, d;
    cout << "Ingrese Anio";
    getInput(y);
    cout << "Ingrese Mes ";
    getRange(m, 1, 12);
    cout << "Ingrese Dia: ";
    getRange(d, 1, 31);
    return year_month_day{year{y}, month{m}, day{d}};
}

void mostrarMenu() {
    cout << "SISTEMA DE GESTION DE ABARROTES" << endl;
    cout << "1. Agregar Nuevo Producto" << endl;
    cout << "2. Agregar Lote a un Producto Existente" << endl;
    cout << "3. Consultar Informacion de Producto" << endl;
    cout << "4. Retirar Lotes Caducados" << endl;
    cout << "5. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

int main() {
    Inventario miInventario;
    int opcion = 0;

    while (opcion != 5) {
        mostrarMenu();
        getRange(opcion, 1, 5);

        try {
            if (opcion == 1) {
                string nombre;
                double precio;
                
                cout << "\nNuevo Producto\n";
                cout << "Nombre del producto: ";
                cin >> nombre;
                
                if (miInventario.estaProducto(nombre)) {
                    cout << "Error: El producto ya existe en el inventario.\n";
                } else {
                    cout << "Precio unitario: $";
                    cin >> precio;
                    
                    Producto nuevoProducto(nombre, precio);
                    miInventario.agregarProducto(nuevoProducto);
                    cout << "Producto agregado exitosamente.\n";
                }

            } else if (opcion == 2) {
                string nombreProd;
                cout << "\nAgregar Lote\n";
                cout << "Nombre del producto al que pertenece el lote: ";
                cin >> nombreProd;

                if (miInventario.estaProducto(nombreProd)) {
                    Producto& prod = miInventario.getProducto(nombreProd);
                    
                    string idLote;
                    int cantidad;
                    
                    cout << "ID del Lote: ";
                    cin >> idLote;
                    
                    if (prod.estaLote(idLote)) {
                        cout << "Error: Ya existe un lote con ese ID en este producto.\n";
                    } else {
                        cout << "Cantidad de unidades: ";
                        cin >> cantidad;
                        
                        cout << "Fecha de Caducidad:\n";
                        year_month_day fecha = pedirFecha();
                        
                        prod.agregarLote(fecha, cantidad, idLote);
                        cout << "Lote registrado correctamente.\n";
                    }
                } else {
                    cout << "Error: El producto no existe en el inventario.\n" ;
                }

            } else if (opcion == 3) {
                string nombreProd;
                cout << "\nConsultar Producto.\n"l;
                cout << "Nombre del producto a buscar: ";
                cin >> nombreProd;

                if (miInventario.estaProducto(nombreProd)) {
                    Producto& prod = miInventario.getProducto(nombreProd);
                    
                    cout << "\nDatos del Producto\n";
                    cout << "Nombre: " << prod.getNombre() << endl;
                    cout << "Cantidad de Lotes activos: " << prod.cantidadLotes() << endl;
                    
                    if (prod.cantidadLotes() > 0) {
                        cout << "(Detalle de lotes disponible internamente)" << endl;
                    }
                    
                } else {
                    cout << "Producto no encontrado." << endl;
                }

            } else if (opcion == 4) {
                string nombreProd;
                cout << "\nLimpieza de Caducados\n";
                cout << "Nombre del producto a revisar: ";
                cin >> nombreProd;

                if (miInventario.estaProducto(nombreProd)) {
                    Producto& prod = miInventario.getProducto(nombreProd);
                    
                    int eliminados = prod.quitarLotesCaducados();
                    
                    if (eliminados > 0) {
                        cout << "Se han eliminado " << eliminados << " lote(s) caducado(s).\n";
                    } else {
                        cout << "No se encontraron lotes caducados para este producto.\n";
                    }
                } else {
                    cout << "Producto no encontrado.\n";
                }
            }

        } catch (const exception& e) {
            cout << "Ocurrio un error inesperado: " << e.what() << endl;
        }
    }
    return 0;
}

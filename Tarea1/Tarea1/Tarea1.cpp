// Tarea1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <omp.h>

#define N 10000
#define chunk 100
#define mostrar 10

void imprimeArreglo(int * d) {
    for (int x = 0; x < mostrar; x++) {
        std::cout << d[x];
        std::cout << std::endl;
    }
}


int main()
{
    std::srand(std::time(0)); // Semilla para los aleatorios con el tiempo actual
    int a[N];
    int b[N];
    int c[N];
    int pedazos = chunk;
    int i;

    // Estableciendo el numero de hilos
    int nHilos;
    std::cout << "Cuantos hilos quieres trabajar: ";
    std::cin >> nHilos;
    #ifdef _OPENMP
        omp_set_num_threads(nHilos);
        std::cout << "Se establecieron " << nHilos << " correctamente" << std::endl;
    #endif
    

    //Números aleatorios para a y b
    for (int i = 0; i < N; i++) {
        a[i] = std::rand() % 1000; // Número aleatorio entre 0 y 99
        b[i] = std::rand() % 1000; // Número aleatorio entre 0 y 99
    }
    

    #pragma omp parallel for \
    shared(a, b, c, pedazos) private(i) \
    schedule(static, pedazos)
    for (i = 0; i < N; i++) {
        c[i] = a[i] + b[i];
    }


    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo A: " << std::endl;
    imprimeArreglo(a);
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo B: " << std::endl;
    imprimeArreglo(b);
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo C (C = A + B): " << std::endl;
    imprimeArreglo(c);


}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln

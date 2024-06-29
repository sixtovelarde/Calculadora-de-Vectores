#include <iostream>
#include <cmath>

using namespace std;

struct Dot {
    float x;
    float y;
    float z;

    Dot(float x, float y, float z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }
};

// Función para calcular la distancia entre dos puntos
float distance(const Dot& p1, const Dot& p2) {
    return std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2) + std::pow(p2.z - p1.z, 2));
}

// Función para calcular el vector resultante en 2 y 3 dimensiones
Dot resultantVector(const Dot& p1, const Dot& p2) {
    return Dot(p2.x - p1.x, p2.y - p1.y, p2.z - p1.z);
}

// Función para calcular el vector resultante de un arreglo de N vectores en 2 y 3 dimensiones
Dot resultantVector(Dot* dots, int n) {
    Dot result(0, 0, 0);
    for (int i = 0; i < n; i++) {
        result.x += dots[i].x;
        result.y += dots[i].y;
        result.z += dots[i].z;
    }
    return result;
}

// Función para calcular el producto escalar en 2 y 3 dimensiones
float dotProduct(const Dot& p1, const Dot& p2) {
    return p1.x * p2.x + p1.y * p2.y + p1.z * p2.z;
}

// Función para calcular el producto cruz en 3 dimensiones
Dot crossProduct(const Dot& p1, const Dot& p2) {
    return Dot(p1.y * p2.z - p1.z * p2.y, p1.z * p2.x - p1.x * p2.z, p1.x * p2.y - p1.y * p2.x);
}

// Función para imprimir el vector en formato -> u = i + j + k (vector unitario), e indicar el plano donde se ubica
void printVector(const Dot& vector) {
    float magnitude = std::sqrt(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z);
    cout << "u = [" << vector.x / magnitude << "] i + [" << vector.y / magnitude << "] j + [" << vector.z / magnitude << "] k (vector unitario)" << endl;

    if (vector.z == 0) {
        if (vector.y == 0) {
            cout << "El vector se ubica en el plano X" << endl;
        } else {
            cout << "El vector se ubica en el plano XY" << endl;
        }
    } else {
        if (vector.y == 0) {
            cout << "El vector se ubica en el plano XZ" << endl;
        } else {
            cout << "El vector se ubica en el plano XYZ" << endl;
        }
    }
}

// Función para resolver un sistema de fuerzas
void solveForceSystem(Dot* forces, int o) {
    Dot resultant = resultantVector(forces, o);
    cout << "Vector resultante del sistema de fuerzas:" << endl;
    printVector(resultant);
}

int main() {
    int o;
    cout << "Ingrese el número de vectores: ";
    cin >> o;

    Dot* forces = new Dot[o];

    cout << "Ingrese las coordenadas de los vectores:" << endl;
    for (int i = 0; i < o; i++) {
        float x, y, z;
        cout << "Vector " << i + 1 << ": ";
        cin >> x >> y >> z;
        forces[i] = Dot(x, y, z);
    }

    Dot p1(1, 2, 3);
    Dot p2(4, 5, 6);

    cout << "Distancia entre p1 y p2: " << distance(p1, p2) << endl;
    cout << "Vector resultante entre p1 y p2: ";
    printVector(resultantVector(p1, p2));

    cout << "Vector resultante del arreglo de fuerzas: ";
    printVector(resultantVector(forces, o));

    cout << "Producto escalar de p1 y p2: " << dotProduct(p1, p2) << endl;
    cout << "Producto cruz de p1 y p2: ";
    printVector(crossProduct(p1, p2));

    solveForceSystem(forces, o);

    delete[] forces;
    return 0;
}

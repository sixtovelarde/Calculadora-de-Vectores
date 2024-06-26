#include <iostream>
#include <cmath> // Para la función sqrt
using namespace std;

// Definición de la estructura Dot
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
float calcularDistancia(const Dot& p1, const Dot& p2) {
    float dx = p2.x - p1.x;
    float dy = p2.y - p1.y;
    float dz = p2.z - p1.z;
    return sqrt(dx * dx + dy * dy + dz * dz);
}

// Función para calcular el vector resultante en 2 dimensiones
Dot calcularVectorResultante2D(const Dot& p1, const Dot& p2) {
    float vx = p2.x - p1.x;
    float vy = p2.y - p1.y;
    return Dot(vx, vy, 0.0f);
}

// Función para calcular el vector resultante en 3 dimensiones
Dot calcularVectorResultante3D(const Dot& p1, const Dot& p2) {
    float vx = p2.x - p1.x;
    float vy = p2.y - p1.y;
    float vz = p2.z - p1.z;
    return Dot(vx, vy, vz);
}

// Función para calcular el producto escalar entre dos vectores
float calcularProductoEscalar(const Dot& v1, const Dot& v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

// Función para calcular el producto cruz entre dos vectores
Dot calcularProductoCruz(const Dot& v1, const Dot& v2) {
    float cx = v1.y * v2.z - v1.z * v2.y;
    float cy = v1.z * v2.x - v1.x * v2.z;
    float cz = v1.x * v2.y - v1.y * v2.x;
    return Dot(cx, cy, cz);
}

// Función para imprimir un vector en formato u = i + j + k
void imprimirVector(const Dot& v) {
    cout << "u = " << v.x << "i + " << v.y << "j + " << v.z << "k" << endl;
}

// Función para determinar el plano donde se ubica un vector
void determinarPlano(const Dot& v) {
    if (v.z == 0.0f) {
        if (v.x == 0.0f) {
            cout << "El vector esta en el plano YZ" << endl;
        } else if (v.y == 0.0f) {
            cout << "El vector esta en el plano XZ" << endl;
        } else {
            cout << "El vector esta en el plano XY" << endl;
        }
    } else {
        if (v.x == 0.0f) {
            cout << "El vector esta en el plano YZ" << endl;
        } else if (v.y == 0.0f) {
            cout << "El vector esta en el plano XZ" << endl;
        } else {
            cout << "El vector no esta en un plano específico" << endl;
        }
    }
}

int main() {

    Dot p1(1.0f, 2.0f, 3.0f);
    Dot p2(4.0f, 5.0f, 6.0f);

    cout << "Distancia entre p1 y p2: " << calcularDistancia(p1, p2) << endl;

    Dot v2D = calcularVectorResultante2D(p1, p2);
    cout << "Vector resultante en 2D: ";
    imprimirVector(v2D);
    determinarPlano(v2D);

    Dot v3D = calcularVectorResultante3D(p1, p2);

    cout << "Vector resultante en 3D: ";
    imprimirVector(v3D);
    determinarPlano(v3D);

    cout << "Producto escalar: " << calcularProductoEscalar << endl;

}
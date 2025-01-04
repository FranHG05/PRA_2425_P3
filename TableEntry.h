#ifndef TABLEENTRY_H
#define TABLEENTRY_H

#include <string>
#include <ostream>

template <typename V>
class TableEntry {
public:
    // Atributos públicos
    std::string key;  // La clave del par clave->valor
    V value;          // El valor del par clave->valor

    // Constructor con clave y valor
    TableEntry(std::string key, V value) : key(key), value(value) {}

    // Constructor con solo clave (sin valor)
    TableEntry(std::string key) : key(key), value(V()) {}

    // Constructor por defecto (clave vacía y valor por defecto)
    TableEntry() : key(""), value(V()) {}

    // Sobrecarga del operador == para comparar solo las claves
    friend bool operator==(const TableEntry<V>& te1, const TableEntry<V>& te2) {
        return te1.key == te2.key;
    }

    // Sobrecarga del operador != para comparar solo las claves
    friend bool operator!=(const TableEntry<V>& te1, const TableEntry<V>& te2) {
        return te1.key != te2.key;
    }

    // Sobrecarga del operador << para imprimir la entrada
    friend std::ostream& operator<<(std::ostream& out, const TableEntry<V>& te) {
        out << "Key: " << te.key << ", Value: " << te.value;
        return out;
    }
};

#endif // TABLEENTRY_H


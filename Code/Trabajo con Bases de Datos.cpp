#include <iostream>
#include <sqlite3.h>

using namespace std;

// Función para conectarse a la base de datos
sqlite3* conectarBaseDeDatos() {
    sqlite3* conexion;
    if (sqlite3_open("usuarios.db", &conexion) != SQLITE_OK) {
        cout << "Error al abrir la base de datos" << endl;
        return nullptr;
    }
    return conexion;
}

// Función para crear un nuevo usuario
void crearUsuario(sqlite3* conexion, string nombreUsuario, int edadUsuario) {
    sqlite3_stmt* sentencia;
    string consulta = "INSERT INTO usuarios (nombre, edad) VALUES (?, ?)";
    if (sqlite3_prepare_v2(conexion, consulta.c_str(), -1, &sentencia, nullptr) != SQLITE_OK) {
        cout << "Error al preparar la consulta" << endl;
        return;
    }

    sqlite3_bind_text(sentencia, 1, nombreUsuario.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(sentencia, 2, edadUsuario);

    if (sqlite3_step(sentencia) != SQLITE_DONE) {
        cout << "Error al crear el usuario" << endl;
    } else {
        cout << "Usuario creado exitosamente" << endl;
    }

    sqlite3_finalize(sentencia);
}

// Función para leer todos los usuarios
void leerUsuarios(sqlite3* conexion) {
    sqlite3_stmt* sentencia;
    string consulta = "SELECT * FROM usuarios";
    if (sqlite3_prepare_v2(conexion, consulta.c_str(), -1, &sentencia, nullptr) != SQLITE_OK) {
        cout << "Error al preparar la consulta" << endl;
        return;
    }

    cout << "ID\tNombre\tEdad" << endl;
    while (sqlite3_step(sentencia) == SQLITE_ROW) {
        cout << sqlite3_column_int(sentencia, 0) << "\t"
             << (const char*)sqlite3_column_text(sentencia, 1) << "\t"
             << sqlite3_column_int(sentencia, 2) << endl;
    }

    sqlite3_finalize(sentencia);
}

// Función para actualizar un usuario
void actualizarUsuario(sqlite3* conexion, int idUsuario, string nuevoNombre, int nuevaEdad) {
    sqlite3_stmt* sentencia;
    string consulta = "UPDATE usuarios SET nombre = ?, edad = ? WHERE id_usuario = ?";
    if (sqlite3_prepare_v2(conexion, consulta.c_str(), -1, &sentencia, nullptr) != SQLITE_OK) {
        cout << "Error al preparar la consulta" << endl;
        return;
    }

    sqlite3_bind_text(sentencia, 1, nuevoNombre.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(sentencia, 2, nuevaEdad);
    sqlite3_bind_int(sentencia, 3, idUsuario);

    if (sqlite3_step(sentencia) != SQLITE_DONE) {
        cout << "Error al actualizar el usuario" << endl;
    } else {
        cout << "Usuario actualizado exitosamente" << endl;
    }

    sqlite3_finalize(sentencia);
}

// Función para eliminar un usuario
void eliminarUsuario(sqlite3* conexion, int idUsuario) {
    sqlite3_stmt* sentencia;
    string consulta = "DELETE FROM usuarios WHERE id_usuario = ?";
    if (sqlite3_prepare_v2(conexion, consulta.c_str(), -1, &sentencia, nullptr) != SQLITE_OK) {
        cout << "Error al preparar la consulta" << endl;
        return;
    }

    sqlite3_bind_int(sentencia, 1, idUsuario);

    if (sqlite3_step(sentencia) != SQLITE_DONE) {
        cout << "Error al eliminar el usuario" << endl;
    } else {
        cout << "Usuario eliminado exitosamente" << endl;
    }

    sqlite3_finalize(sentencia);
}

int main() {
    sqlite3* conexionBaseDeDatos = conectarBaseDeDatos();
    if (conexionBaseDeDatos == nullptr) {
        return 1;
    }

    // Crear un usuario
    crearUsuario(conexionBaseDeDatos, "Juan", 30);

    // Leer todos los usuarios
    leerUsuarios(conexionBaseDeDatos);

    // Actualizar un usuario
    actualizarUsuario(conexionBaseDeDatos, 1, "Juan Pérez", 35);

    // Eliminar un usuario
    eliminarUsuario(conexionBaseDeDatos, 1);

    sqlite3_close(conexionBaseDeDatos);
    return 0;
}

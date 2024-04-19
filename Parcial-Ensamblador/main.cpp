#include <iostream>
#include "string.hh"
#include "vector.hh"
#include "code.hh"

int main() {
    ProcesadorCodigo procesador;
    vector<string> codigoFuente;
    codigoFuente.push_back("main:");
    codigoFuente.push_back("    addi x5, zero, 530");
    codigoFuente.push_back("    sb x3, 520(x8)");
    codigoFuente.push_back("    jal x10, -233512(x4)");
    codigoFuente.push_back("    jalr x10, -45(x2)");
    codigoFuente.push_back("    beq x10, x5, 520");
    codigoFuente.push_back("");
    codigoFuente.push_back("label1:");
    codigoFuente.push_back("    addi x6, zero, 100");
    codigoFuente.push_back("label2:");
    codigoFuente.push_back("    add zero, zero, zero");
    codigoFuente.push_back("    lw x10, -12(x13)");
    codigoFuente.push_back("label3:");
    codigoFuente.push_back("    bltu x9, x12, 545");
    codigoFuente.push_back("    sc.w zero, zero, zero");
    codigoFuente.push_back("    lui x10, 90");
    

     // Agregar cada línea de código al procesador
    for (const auto& linea : codigoFuente) {
        procesador.agregarLinea(linea);
    }

    // Generar la salida en binario
    procesador.generarSalida();

    return 0;
}

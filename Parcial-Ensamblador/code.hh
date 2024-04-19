#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <bitset>

using namespace std;

// Clase para representar cada instrucción
class Instruccion {
public:
    string nombre;
    string rd;
    string rs1;
    string rs2;
    string inmediato;
    string offset;
    string funct3;
    string funct7;
    string opcode;
};

// Clase para procesar el código fuente y generar la salida
    class ProcesadorCodigo {
    private:
        vector<Instruccion> instrucciones;
    
       string obtenerOpcodeBinario(const string& opcode) {
        // Tabla de opcodes y nombres de instrucciones
        vector<pair<string, string>> opcodes;
        
        // Push backs para construir la tabla
        opcodes.push_back({"add", "0110011"});
        opcodes.push_back({"sub", "0110011"});
        opcodes.push_back({"xor", "0110011"});
        opcodes.push_back({"or", "0110011"});
        opcodes.push_back({"and", "0110011"});
        opcodes.push_back({"sll", "0110011"});
        opcodes.push_back({"srl", "0110011"});
        opcodes.push_back({"sra", "0110011"});
        opcodes.push_back({"slt", "0110011"});
        opcodes.push_back({"sltu", "0110011"});
        opcodes.push_back({"addi", "0010011"});
        opcodes.push_back({"xori", "0010011"});
        opcodes.push_back({"ori", "0010011"});
        opcodes.push_back({"andi", "0010011"});
        opcodes.push_back({"slli", "0010011"});
        opcodes.push_back({"srli", "0010011"});
        opcodes.push_back({"srai", "0010011"});
        opcodes.push_back({"slti", "0010011"});
        opcodes.push_back({"sltiu", "0010011"});
        opcodes.push_back({"lb", "0000011"});
        opcodes.push_back({"lh", "0000011"});
        opcodes.push_back({"lw", "0000011"});
        opcodes.push_back({"lbu", "0000011"});
        opcodes.push_back({"lhu", "0000011"});
        opcodes.push_back({"sb", "0100011"});
        opcodes.push_back({"sh", "0100011"});
        opcodes.push_back({"sw", "0100011"});
        opcodes.push_back({"beq", "1100011"});
        opcodes.push_back({"bne", "1100011"});
        opcodes.push_back({"blt", "1100011"});
        opcodes.push_back({"bge", "1100011"});
        opcodes.push_back({"bltu", "1100011"});
        opcodes.push_back({"bgeu", "1100011"});
        opcodes.push_back({"jal", "1101111"});
        opcodes.push_back({"jalr", "1100111"});
        opcodes.push_back({"lui", "0110111"});
        opcodes.push_back({"auipc", "0010111"});
        opcodes.push_back({"ecall", "1110011"});
        opcodes.push_back({"ebreak", "1110011"});
        opcodes.push_back({"mul", "0110011"});
        opcodes.push_back({"mulh", "0110011"});
        opcodes.push_back({"mulsu", "0110011"});
        opcodes.push_back({"mulu", "0110011"});
        opcodes.push_back({"div", "0110011"});
        opcodes.push_back({"divu", "0110011"});
        opcodes.push_back({"rem", "0110011"});
        opcodes.push_back({"remu", "0110011"});
        opcodes.push_back({"lr.w", "0101111"});
        opcodes.push_back({"sc.w", "0101111"});
        opcodes.push_back({"amoswap.w", "0101111"});
        opcodes.push_back({"amoadd.w", "0101111"});
        opcodes.push_back({"amoand.w", "0101111"});
        opcodes.push_back({"amoor.w", "0101111"});
        opcodes.push_back({"amoxor.w", "0101111"});
        opcodes.push_back({"amomax.w", "0101111"});
        opcodes.push_back({"amomin.w", "0101111"});
    
        // Buscar el opcode
        for (const auto& par : opcodes) {
            if (par.first == opcode) {
                return par.second; // Devolver el opcode correspondiente
            }
        }
        return "0000000"; // Valor predeterminado si no se encuentra
    }
    
    string obtenerTipoInstruccion(const string& nombre) {
     // Tabla de nombres de instrucciones y tipos
        vector<pair<string, string>> instruccionesYT;
    
            // Push backs para construir la tabla
            instruccionesYT.push_back({"add", "R"});
            instruccionesYT.push_back({"sub", "R"});
            instruccionesYT.push_back({"xor", "R"});
            instruccionesYT.push_back({"or", "R"});
            instruccionesYT.push_back({"and", "R"});
            instruccionesYT.push_back({"sll", "R"});
            instruccionesYT.push_back({"srl", "R"});
            instruccionesYT.push_back({"sra", "R"});
            instruccionesYT.push_back({"slt", "R"});
            instruccionesYT.push_back({"sltu", "R"});
            instruccionesYT.push_back({"addi", "I"});
            instruccionesYT.push_back({"xori", "I"});
            instruccionesYT.push_back({"ori", "I"});
            instruccionesYT.push_back({"andi", "I"});
            instruccionesYT.push_back({"slli", "I"});
            instruccionesYT.push_back({"srli", "I"});
            instruccionesYT.push_back({"srai", "I"});
            instruccionesYT.push_back({"slti", "I"});
            instruccionesYT.push_back({"sltiu", "I"});
            instruccionesYT.push_back({"lb", "I"});
            instruccionesYT.push_back({"lh", "I"});
            instruccionesYT.push_back({"lw", "I"});
            instruccionesYT.push_back({"lbu", "I"});
            instruccionesYT.push_back({"lhu", "I"});
            instruccionesYT.push_back({"sb", "S"});
            instruccionesYT.push_back({"sh", "S"});
            instruccionesYT.push_back({"sw", "S"});
            instruccionesYT.push_back({"beq", "B"});
            instruccionesYT.push_back({"bne", "B"});
            instruccionesYT.push_back({"blt", "B"});
            instruccionesYT.push_back({"bge", "B"});
            instruccionesYT.push_back({"bltu", "B"});
            instruccionesYT.push_back({"bgeu", "B"});
            instruccionesYT.push_back({"jal", "J"});
            instruccionesYT.push_back({"jalr", "I"});
            instruccionesYT.push_back({"lui", "U"});
            instruccionesYT.push_back({"auipc", "U"});
            instruccionesYT.push_back({"ecall", "I"});
            instruccionesYT.push_back({"ebreak", "I"});
            instruccionesYT.push_back({"mul", "R"});
            instruccionesYT.push_back({"mulh", "R"});
            instruccionesYT.push_back({"mulsu", "R"});
            instruccionesYT.push_back({"mulu", "R"});
            instruccionesYT.push_back({"div", "R"});
            instruccionesYT.push_back({"divu", "R"});
            instruccionesYT.push_back({"rem", "R"});
            instruccionesYT.push_back({"remu", "R"});
            instruccionesYT.push_back({"lr.w", "R"});
            instruccionesYT.push_back({"sc.w", "R"});
            instruccionesYT.push_back({"amoswap.w", "R"});
            instruccionesYT.push_back({"amoadd.w", "R"});
            instruccionesYT.push_back({"amoand.w", "R"});
            instruccionesYT.push_back({"amoor.w", "R"});
            instruccionesYT.push_back({"amoxor.w", "R"});
            instruccionesYT.push_back({"amomax.w", "R"});
            instruccionesYT.push_back({"amomin.w", "R"});
    
        // Buscar el nombre de la instrucción y devolver el tipo correspondiente si se encuentra
        for (const auto& par : instruccionesYT) {
            if (par.first == nombre) {
                return par.second;
            }
        }
    
        return "Instruccion no valida"; // Devolver si no se encuentra el nombre de la instrucción
    }
    
         string calcularFunct3(const string& nombre) {
        // Tabla de nombres de instrucciones y funct3
            vector<pair<string, string>> funct3_values;
        
            // Push backs para construir la tabla
            funct3_values.push_back({"add", "000"});
            funct3_values.push_back({"sub", "000"});
            funct3_values.push_back({"xor", "100"});
            funct3_values.push_back({"or", "110"});
            funct3_values.push_back({"and", "111"});
            funct3_values.push_back({"sll", "001"});
            funct3_values.push_back({"srl", "101"});
            funct3_values.push_back({"sra", "101"});
            funct3_values.push_back({"slt", "010"});
            funct3_values.push_back({"sltu", "011"});
            funct3_values.push_back({"xori", "100"});
            funct3_values.push_back({"ori", "110"});
            funct3_values.push_back({"andi", "111"});
            funct3_values.push_back({"slli", "001"});
            funct3_values.push_back({"srli", "101"});
            funct3_values.push_back({"srai", "101"});
            funct3_values.push_back({"slti", "010"});
            funct3_values.push_back({"sltiu", "011"});
            funct3_values.push_back({"lb", "000"});
            funct3_values.push_back({"lh", "001"});
            funct3_values.push_back({"lw", "010"});
            funct3_values.push_back({"lbu", "100"});
            funct3_values.push_back({"lhu", "101"});
            funct3_values.push_back({"sb", "000"});
            funct3_values.push_back({"sh", "001"});
            funct3_values.push_back({"sw", "010"});
            funct3_values.push_back({"beq", "000"});
            funct3_values.push_back({"bne", "001"});
            funct3_values.push_back({"blt", "100"});
            funct3_values.push_back({"bge", "101"});
            funct3_values.push_back({"bltu", "110"});
            funct3_values.push_back({"bgeu", "111"});
            funct3_values.push_back({"jalr", "000"});
            funct3_values.push_back({"ecall", "000"});
            funct3_values.push_back({"ebreak", "000"});
            funct3_values.push_back({"mul", "000"});
            funct3_values.push_back({"mulh", "001"});
            funct3_values.push_back({"mulsu", "010"});
            funct3_values.push_back({"mulu", "011"});
            funct3_values.push_back({"div", "100"});
            funct3_values.push_back({"divu", "101"});
            funct3_values.push_back({"rem", "110"});
            funct3_values.push_back({"remu", "111"});
            funct3_values.push_back({"lr.w", "010"});
            funct3_values.push_back({"sc.w", "010"});
            funct3_values.push_back({"amoswap.w", "010"});
            funct3_values.push_back({"amoadd.w", "010"});
            funct3_values.push_back({"amoand.w", "010"});
            funct3_values.push_back({"amoor.w", "010"});
            funct3_values.push_back({"amoxor.w", "010"});
            funct3_values.push_back({"amomax.w", "010"});
            funct3_values.push_back({"amomin.w", "010"});
        
            // Buscar el nombre de la instrucción y devolver funct3 correspondiente si se encuentra
            for (const auto& par : funct3_values) {
                if (par.first == nombre) {
                    return par.second;
                }
            }
    
            return "000"; // Valor predeterminado si no se encuentra
    }

    
    string calcularFunct7(const string& nombre) {
    // Tabla de nombres de instrucciones y funct7
        vector<pair<string, string>> funct7_values;
    
        // Push backs para construir la tabla
        funct7_values.push_back({"sll", "0000000"});
        funct7_values.push_back({"srl", "0000000"});
        funct7_values.push_back({"sra", "0100000"});
        funct7_values.push_back({"mul", "0000001"});
        funct7_values.push_back({"mulh", "0000001"});
        funct7_values.push_back({"mulsu", "0000001"});
        funct7_values.push_back({"mulu", "0000001"});
        funct7_values.push_back({"div", "0000001"});
        funct7_values.push_back({"divu", "0000001"});
        funct7_values.push_back({"rem", "0000001"});
        funct7_values.push_back({"remu", "0000001"});
    
        // Buscar el nombre de la instrucción y devolver funct7 correspondiente si se encuentra
        for (const auto& par : funct7_values) {
            if (par.first == nombre) {
                return par.second;
            }
    }

    return "0000000"; // Valor predeterminado si no se encuentra
}



    // Función para determinar si una cadena es una etiqueta
    bool esEtiqueta(const string& linea) {
        return (!linea.empty() && linea.back() == ':' && linea.find_first_not_of(" \t") != string::npos);
    }

    // Función para determinar si una cadena es un comentario
    bool esComentario(const string& linea) {
        return (!linea.empty() && linea[0] == '#');
    }

    // Función para determinar si una cadena es una directiva
    bool esDirectiva(const string& linea) {
        return false; // Por ahora, no se procesan directivas
    }

string convertirRegistro(const string& registro) {
    if (registro == "zero" || registro == "x0") {
        return "00000";
    } else {
        // Verificar si la cadena contiene el prefijo "x"
        size_t pos = registro.find('x');
        if (pos != string::npos) {
            // Extraer el número del registro (por ejemplo, "x4" -> "4")
            int numero;
            try {
                numero = stoi(registro.substr(pos + 1));
            } catch (const std::invalid_argument& e) {
                // Manejar el caso de que la cadena no sea un número válido
                // Por ejemplo, lanzar una excepción o devolver un valor predeterminado
                // Aquí se devuelve un valor predeterminado (0) para evitar la excepción
                numero = 0;
            }
            // Convertir el número a binario y rellenar con ceros a la izquierda si es necesario
            if (numero >= 0 && numero < 32) {
                return bitset<5>(numero).to_string();
            } else {
                // Manejar el desbordamiento o truncamiento
                return bitset<5>(numero % 32).to_string();
            }
        } else {
            // Convertir el número directamente a binario y rellenar con ceros a la izquierda si es necesario
            int numero;
            try {
                numero = stoi(registro);
            } catch (const std::invalid_argument& e) {
                // Manejar el caso de que la cadena no sea un número válido
                // Por ejemplo, lanzar una excepción o devolver un valor predeterminado
                // Aquí se devuelve un valor predeterminado (0) para evitar la excepción
                numero = 0;
            }
            // Convertir el número a binario y rellenar con ceros a la izquierda si es necesario
            if (numero >= 0 && numero < 32) {
                return bitset<5>(numero).to_string();
            } else {
                // Manejar el desbordamiento o truncamiento
                return bitset<5>(numero % 32).to_string();
            }
        }
    }
}

// Obtener offset de una cadena
string Off(const string& resto) {
    string cte;
    string reg;
    unsigned int i = 0;
    for (; i < resto.size(); i++) {
        char c = resto[i];
        if (c == '(') break;
        cte.push_back(c);
    }
    return cte;
}

//Funcion para separar rs1 de una cadena
string Reg(const string& resto) {
    string cte;
    string reg;
    unsigned int i = 0;
    for (; i < resto.size(); i++) {
        char c = resto[i];
        if (c == '(') break;
        cte.push_back(c);
    }
    i++;
    for (; i < resto.size(); i++) {
        char c = resto[i];
        if (c == ')') break;
        reg.push_back(c);
    }
    return reg;
}



public:
    // Función para agregar una línea de código al procesador
    void agregarLinea(const string& linea) {
        if (!linea.empty() && !esComentario(linea) && !esDirectiva(linea)) {
            if (!esEtiqueta(linea)) {
                Instruccion Validacion;
                // Encontrar la primera posición no vacía
                size_t firstPos = linea.find_first_not_of(" \t");

                // Encontrar la posición de la coma o el espacio después del opcode
                size_t spacePos = linea.find(' ', firstPos);

                // Obtener el nombre de la instrucción
                Validacion.nombre = linea.substr(firstPos, spacePos - firstPos);
                // Restriccion para identificar tipo de linea y mandar su respectivo procesamiento
                if (isTypeR(Validacion)){
                    instrucciones.push_back(processTypeR(linea));
                    
                }
                else if(isTypeI(Validacion)){
                    instrucciones.push_back(processTypeI(linea));
                }
                else if (isTypeS(Validacion)){
                    instrucciones.push_back(processTypeS(linea));
                }
                else if (isTypeB(Validacion)){
                    instrucciones.push_back(processTypeB(linea));
                }
                else if (isTypeU(Validacion)){
                    instrucciones.push_back(processTypeU(linea));
                }
                else if (isTypeJ(Validacion)){
                    instrucciones.push_back(processTypeJ(linea));
                }
        }
    }
    }
    
    bool isTypeR(const Instruccion& inst) {
        return obtenerTipoInstruccion(inst.nombre) == "R";
    }
    
    
    bool isTypeI(const Instruccion& inst) {
        return obtenerTipoInstruccion(inst.nombre) == "I";
    }
    
    bool isTypeS(const Instruccion& inst){
        return obtenerTipoInstruccion(inst.nombre) == "S";
    }
    
    bool isTypeB(const Instruccion& inst){
        return obtenerTipoInstruccion(inst.nombre) == "B";
    }
    
    bool isTypeJ(const Instruccion& inst){
        return obtenerTipoInstruccion(inst.nombre) == "J";
    }
    
    bool isTypeU(const Instruccion& inst){
        return obtenerTipoInstruccion(inst.nombre) == "U";
    }
    
    Instruccion processTypeR(const string& linea) {
    Instruccion instR;

    // Encontrar la primera posición no vacía
    size_t firstPos = linea.find_first_not_of(" \t");

    // Encontrar la posición de la coma o el espacio después del opcode
    size_t spacePos = linea.find(' ', firstPos);

    // Obtener el nombre de la instrucción
    instR.nombre = linea.substr(firstPos, spacePos - firstPos);

    // Encontrar los registros
    size_t lastPos = spacePos + 1;
    size_t commaPos = linea.find(',', lastPos);

    // Obtener el primer registro (rd)
    instR.rd = linea.substr(lastPos, commaPos - lastPos);

    // Encontrar el segundo registro (rs1) si existe
    if (commaPos != string::npos) {
        lastPos = commaPos + 1;
        commaPos = linea.find(',', lastPos);
        instR.rs1 = linea.substr(lastPos, commaPos - lastPos);

        // Encontrar el tercer registro (rs2) si existe
        if (commaPos != string::npos) {
            lastPos = commaPos + 1;
            commaPos = linea.find(',', lastPos);
            instR.rs2 = linea.substr(lastPos, commaPos - lastPos);
        } else {
            instR.rs2 = linea.substr(lastPos);
        }
    } else {
        instR.rs2 = "zero"; // Si no hay rs2, se asume zero
        instR.rd = "zero";  // Si no hay rd, se asume zero
    }

    return instR;
    }
    
    Instruccion processTypeI(const string& linea) {
    Instruccion instI;

        // Encontrar la primera posición no vacía
        size_t firstPos = linea.find_first_not_of(" \t");
    
        // Encontrar la posición de la coma o el espacio después del opcode
        size_t spacePos = linea.find(' ', firstPos);
    
        // Obtener el nombre de la instrucción
        instI.nombre = linea.substr(firstPos, spacePos - firstPos);
    
        // Encontrar los registros
        size_t lastPos = spacePos + 1;
        size_t commaPos = linea.find(',', lastPos);
    
        // Obtener el registro (rd)
        instI.rd = linea.substr(lastPos, commaPos - lastPos);
    
        // Encontrar el registro (rs1)
        lastPos = commaPos + 1;
        commaPos = linea.find(',', lastPos);
        instI.rs1 = linea.substr(lastPos, commaPos - lastPos);
    
        // Obtener el inmediato
        lastPos = commaPos + 1;
        instI.inmediato = linea.substr(lastPos);
    
        return instI;
        }
    
    
    Instruccion processTypeS(const string& linea) {
    Instruccion instS;

    // Encontrar la primera posición no vacía
    size_t firstPos = linea.find_first_not_of(" \t");

    // Encontrar la posición de la coma o el espacio después del opcode
    size_t spacePos = linea.find(' ', firstPos);

    // Obtener el nombre de la instrucción
    instS.nombre = linea.substr(firstPos, spacePos - firstPos);

    // Encontrar los registros
    size_t lastPos = spacePos + 1;
    size_t commaPos = linea.find(',', lastPos);

    // Obtener el registro (rs2)
    instS.rs2 = linea.substr(lastPos, commaPos - lastPos);

    // Obtener el registro (rs1)
    lastPos = commaPos + 1;
    instS.rs1 = linea.substr(lastPos);

    return instS;
    }
    
    Instruccion processTypeB(const string& linea) {
    Instruccion instB;

    // Encontrar la primera posición no vacía
    size_t firstPos = linea.find_first_not_of(" \t");

    // Encontrar la posición de la coma o el espacio después del opcode
    size_t spacePos = linea.find(' ', firstPos);

    // Obtener el nombre de la instrucción
    instB.nombre = linea.substr(firstPos, spacePos - firstPos);

    // Encontrar los registros
    size_t lastPos = spacePos + 1;
    size_t commaPos = linea.find(',', lastPos);

    // Obtener el registro (rs1)
    instB.rs1 = linea.substr(lastPos, commaPos - lastPos);

    // Encontrar el registro (rs2)
    lastPos = commaPos + 1;
    commaPos = linea.find(',', lastPos);
    instB.rs2 = linea.substr(lastPos, commaPos - lastPos);

    // Obtener el offset
    lastPos = commaPos + 1;
    instB.offset = linea.substr(lastPos);

    return instB;
    }
    
    
    Instruccion processTypeU(const string& linea) {
    Instruccion instU;

        // Encontrar la primera posición no vacía
        size_t firstPos = linea.find_first_not_of(" \t");
    
        // Encontrar la posición de la coma o el espacio después del opcode
        size_t spacePos = linea.find(' ', firstPos);
    
        // Obtener el nombre de la instrucción
        instU.nombre = linea.substr(firstPos, spacePos - firstPos);
    
        size_t lastPos = spacePos + 1;
        size_t commaPos = linea.find(',', lastPos);
    
        // Obtener el registro (rd)
        instU.rd = linea.substr(lastPos, commaPos - lastPos);
    
        // Obtener el inmediato
        lastPos = commaPos + 1;
        instU.inmediato = linea.substr(lastPos);
    
        return instU;
        }
    Instruccion processTypeJ(const string& linea) {
    Instruccion instJ;

        // Encontrar la primera posición no vacía
        size_t firstPos = linea.find_first_not_of(" \t");
    
        // Encontrar la posición de la coma o el espacio después del opcode
        size_t spacePos = linea.find(' ', firstPos);
    
        // Obtener el nombre de la instrucción
        instJ.nombre = linea.substr(firstPos, spacePos - firstPos);
    
        size_t lastPos = spacePos + 1;
        size_t commaPos = linea.find(',', lastPos);
    
        // Obtener el registro (rd)
        instJ.rd = linea.substr(lastPos, commaPos - lastPos);
    
        // Obtener el offset
        lastPos = commaPos + 1;
        instJ.offset = linea.substr(lastPos);
    
        return instJ;
        }
        

    string printTypeR(const Instruccion& inst) {
        // Tipo R
        string encoding;
        // Obtener funct7 y funct3
        
        string funct7 = calcularFunct7(inst.nombre);
        string funct3 = calcularFunct3(inst.nombre);
        cout  << funct7 << " " << convertirRegistro(inst.rs2) << " " << convertirRegistro(inst.rs1) << " " << funct3 << " " << convertirRegistro(inst.rd) << " " <<obtenerOpcodeBinario(inst.nombre) << endl;
        return encoding;
    }


    string printTypeI(const Instruccion& inst) {
        // Tipo I
        string encoding;
        string funct7 = calcularFunct7(inst.nombre);
        string funct3 = calcularFunct3(inst.nombre);
        // Restriccion por si es I especial
        if (obtenerOpcodeBinario(inst.nombre) == "0000011" || (obtenerOpcodeBinario(inst.nombre) == "1100111")){
            // Tipo I especial
            string offset = Off(inst.rs1);
            string reg = Reg(inst.rs1);
            int offValue = stoi(offset);
            bitset<12> binaryOff(offValue);
            cout << binaryOff << " " << convertirRegistro(reg) << " " << funct3 << " " << convertirRegistro(inst.rd) << " " << obtenerOpcodeBinario(inst.nombre) << endl;
        } else {
            int immediateValue = stoi(inst.inmediato);
            bitset<12> immediate(immediateValue);
            cout << immediate << " " << convertirRegistro(inst.rs1) << " " << funct3 << " " << convertirRegistro(inst.rd) << " " << obtenerOpcodeBinario(inst.nombre) << endl;
        }
        return encoding;
    }
    
    
    string printTypeS(const Instruccion& inst) {
        // Tipo S
        string encoding;
        // Obtener funct7 y funct3
        
        string funct7 = calcularFunct7(inst.nombre);
        string funct3 = calcularFunct3(inst.nombre);
        // Obtener offset y rs1 por separado con las funciones correspondientes
        string offset = Off(inst.rs1);
        string reg = Reg(inst.rs1);
        int offValue = stoi(offset);
        bitset<12> binaryOff(offValue);
        // Crear dos bitsets para almacenar los bits divididos
        bitset<7> Off7;
        bitset<5> Off5;
        
        // Asignar los bits correspondientes del binario de 12 bits a los bitsets
        for (int i = 11; i >= 5; --i) {
        Off7[i - 5] = binaryOff[i];
        }

        for (int i = 0; i < 7; ++i) {
        Off5[i] = binaryOff[i];
        }
        
        cout << Off7 << " " << convertirRegistro(inst.rs2) << " " << convertirRegistro(reg) << " " << funct3 << " " << Off5 << " " << obtenerOpcodeBinario(inst.nombre) <<endl;
        
        return encoding;
    }
    
    string printTypeB(const Instruccion& inst) {
        // cout << "Tipo B" << endl;
        string encoding;
        // Obtener funct7 y funct3
        
        string funct7 = calcularFunct7(inst.nombre);
        string funct3 = calcularFunct3(inst.nombre);
        int offValue = stoi(inst.offset);
        bitset<12> binaryOff(offValue);
        // Crear dos bitsets para almacenar los bits divididos
        bitset<7> Off7;
        bitset<5> Off5;

        for (int i = 11; i >= 5; --i) {
        Off7[i - 5] = binaryOff[i];
        }

        for (int i = 0; i < 5; ++i) {
        Off5[i] = binaryOff[i];
        }
        
        cout << Off7 << " " << convertirRegistro(inst.rs2) << " " << convertirRegistro(inst.rs1) << " " << funct3 << " " << Off5 << " " << obtenerOpcodeBinario(inst.nombre) <<endl;
        
        return encoding;
    }
    
    string printTypeU(const Instruccion& inst) {
        // cout << "Tipo U" << endl;
        string encoding;
        int immValue = stoi(inst.inmediato);
        bitset<20> immediato(immValue);
        cout << immediato << " " << convertirRegistro(inst.rd) << " " << obtenerOpcodeBinario(inst.nombre) << endl;
        
        return encoding;
    }
    
    
    string printTypeJ(const Instruccion& inst) {
        // cout << "Tipo J" << endl;
        string encoding;
        // Obtener funct7 y funct3
        
        int offValue = stoi(inst.offset);
        bitset<20> binaryOff(offValue);
        // Crear dos bitsets para almacenar los bits divididos
        bitset<10> Off10;
        bitset<1> Off11;
        bitset<1> Off20;
        bitset<8> Off8;
        
        // Copiar bit 20
        Off20[0] = binaryOff[19];

        // Llenar los 8 bits
        for (int i = 12; i <= 19; i++) {
            Off8[i] = binaryOff[i];
        }
        
        // Copiar bit 11
        Off11[0] = binaryOff[10];

        // Llenar los 10 bits
        for (int i = 1; i < 11; i++) {
            Off10[i] = binaryOff[i];
        }
        
        cout << Off20 << Off10 << Off11 << Off8 << " " << convertirRegistro(inst.rd) << " " << obtenerOpcodeBinario(inst.nombre) <<endl;
        
        return encoding;
    }

    void generarSalida() {
        string salida;
        // Recorrer las instrucciones y realizar la codificación
        for (auto& instr : instrucciones) {
            if(isTypeR(instr)) 
            salida + printTypeR(instr) + "\n";
            else if(isTypeI(instr)){
                salida + printTypeI(instr) + "\n";
            }
            else if(isTypeS(instr)){
                salida + printTypeS(instr) + "\n";
            }
            else if(isTypeB(instr)){
                salida + printTypeB(instr) + "\n";
            }
            else if (isTypeU(instr)){
                salida + printTypeU(instr) + "\n";
            }
            else if (isTypeJ(instr)){
                salida + printTypeJ(instr) + "\n";
            }
    }
}



};

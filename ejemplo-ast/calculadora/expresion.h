#ifndef EXPRESION_H
#define EXPRESION_H

using namespace std;
#include<string>

namespace Proyecto1{
class Expresion
{
public:
    Expresion();
    Expresion(Expresion *_operandoIzquierda, Expresion *_operandoDerecha, char _operador);
    Expresion *operandoIzquierda;
    Expresion *operandoDerecha;
    char operador;
    string valor;
    int evaluar();
};
}
#endif // EXPRESION_H

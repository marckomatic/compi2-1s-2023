#include "expresion.h"

namespace Proyecto1{
    Expresion::Expresion()
    {

    }

    Expresion::Expresion(Expresion* _operandoIzquierda, Expresion* _operandoDerecha, char _operador){
        this->operandoIzquierda = _operandoIzquierda;
        this->operandoDerecha = _operandoDerecha;
        this->operador = _operador;
    }

    int Expresion::evaluar(){
        switch(this->operador){
            case '+':
                return operandoIzquierda->evaluar() + operandoDerecha->evaluar();
            case '-':
                return operandoIzquierda->evaluar() - operandoDerecha->evaluar();
            case '*':
                return operandoIzquierda->evaluar() * operandoDerecha->evaluar();
            case '/':
                return operandoIzquierda->evaluar() / operandoDerecha->evaluar();
            case '#':
                return stoi(this->valor);

        }
        return 0;
    }


}

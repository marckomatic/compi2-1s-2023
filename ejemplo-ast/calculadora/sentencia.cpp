#include "sentencia.h"
#include "ast.h"

namespace Proyecto1 {
Sentencia::Sentencia()
{

}

Sentencia::Sentencia(Expresion *_expresion){
    this->expresion = _expresion;
}

void Sentencia::ejecutar(){
    AST::getAST()->salida += "El resultado es "+ to_string(this->expresion->evaluar()) + "\n";
}

}

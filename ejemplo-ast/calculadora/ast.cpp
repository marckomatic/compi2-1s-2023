#include "ast.h"

namespace Proyecto1 {
AST* AST::ast;

AST::AST()
{
    this->listaErrores = "";
    this->listaSentencias = QList<Sentencia>();
}

AST* AST::getAST(){
    if(AST::ast == nullptr){
        AST::ast = new AST();
    }
    return AST::ast;
}

void AST::ejecutar(){
    for(int i=0; i<this->listaSentencias.length(); i++){
        listaSentencias[i].ejecutar();
    }
}

}

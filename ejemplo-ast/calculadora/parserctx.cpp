#include "parserctx.hpp"
#include "parser.hpp"
#include "lex.yy.c"
#include "ast.h"

namespace Proyecto1 {
ParserCtx::ParserCtx()
{
    //inicializamos el lexer ( el *void se convierte en un scanner)
    yylex_init(&lexer);
    // se crea un location
    loc = new yy::location();
    // se crea un parser
    Parser = new yy::Parser(lexer, *loc, *this);
    Salida = "";
}

ParserCtx::~ParserCtx(){
    yylex_destroy(lexer);
    delete loc;
    delete Parser;
}

std::string ParserCtx::Analizar(std::string entrada){

    this->Salida = "";

    Proyecto1::AST::getAST()->salida = "";
    Proyecto1::AST::getAST()->listaErrores = "";
    Proyecto1::AST::getAST()->listaSentencias.clear();

    // se carga el buffer en en analizador
    yy_scan_string(entrada .c_str(), lexer );
    // se activan registro de depuracion
    this->Parser->set_debug_level(true);
    //se analiza
    this->Parser->parse();
    Proyecto1::AST::getAST()->ejecutar();

    this->Salida += Proyecto1::AST::getAST()->salida;
    this->Salida += "\n ERRORES \n"+ AST::getAST()->listaErrores;
    return "";
}


}

/*opciones por default, estas no se tocan*/
%require  "3.0.4"
%skeleton "lalr1.cc"

%defines

%define api.prefix{yy}

%define api.parser.class {Parser}

%locations
%define api.token.constructor

%define api.value.type variant
%define parse.trace
%define parse.error verbose

%code requires 
{
    /* código  que se inserta al inicioo por lo regular son cabeceras*/
    #include<iostream> 
    #include<string> 
    #include "parserctx.hpp"
    #include "ast.h"
    #include "sentencia.h"
    #include "expresion.h"
    /*
    Se pueden definir estructuras y tipos para los no terminales
    */

}
/* Esto no se toca mas alla de poner en el ultimo parametro el nombre de nuestra clase que usamos para anilizar */
%code
{
yy::Parser::symbol_type yylex(void* yyscanner, yy::location& loc, class Proyecto1::ParserCtx & ctx);
}

//Lo vamos a dejar asi
%token END 0;  //token de salida

/// %token<tipo> nombre+  
//cuidado con el orden
// %token <std::string> ID NUMERO
%token <std::string>  NUMERO ID
// token de tipo por defecto
    //token por ID
%token SUMA MENOS PARIZQ PARDER POR DIVIDIDO PYCOMA EVALUAR
/*
forma alterna 
%token SUMA '+'
%token ID 'un_id'
*/
// precedencia

%left SUMA MENOS
%left POR DIVIDIDO

/* fin de la definción de tipos*/

/* La clase que envuele al parser se pasa por referencia 
del parser al escaner evitando crear variables globales

*/

%lex-param {void *scanner} {yy::location& loc} { class Proyecto1::ParserCtx & ctx }
%parse-param {void *scanner} {yy::location& loc} { class Proyecto1::ParserCtx & ctx }

/* es posible hacer tipos personalizados para definir no terminales añadiendo lo siguiente
%union {
    std::string  cadenas;
}
*/

/*definicion de no terminales*/
%type< Proyecto1::Sentencia > sentencia;
%type< Proyecto1::Expresion* > expresion expresion2;
// printer
/*
inicio de la grámatica
*/
%%
/* produccion inicial */

%start listasentencias;


listasentencias :   listasentencias sentencia
           {
               Proyecto1::AST::getAST()->listaSentencias.append($2);
           }
       | sentencia
           {
               Proyecto1::AST::getAST()->listaSentencias.append($1);
           }
       ;

sentencia : EVALUAR PARIZQ expresion PARDER PYCOMA
       {
           $$ = Proyecto1::Sentencia($3);
       }

;

expresion : expresion SUMA expresion2
       {
           $$ = new Proyecto1::Expresion($1, $3, '+');
       }
       | expresion MENOS expresion2
       {
           $$ = new Proyecto1::Expresion($1, $3, '-');
       }
       | expresion2
       {
           $$ = $1;
       }
;

expresion2 : expresion2 POR NUMERO
       {
           Proyecto1::Expresion *expDer = new Proyecto1::Expresion(nullptr, nullptr, '#');
           expDer->valor = $3;
           $$ = new Proyecto1::Expresion($1, expDer, '*');
       }
       | expresion2 DIVIDIDO NUMERO
       {
           Proyecto1::Expresion *expDer = new Proyecto1::Expresion(nullptr, nullptr, '#');
           expDer->valor = $3;
           $$ = new Proyecto1::Expresion($1, expDer, '/');
       }
       | NUMERO
       {
           $$ = new Proyecto1::Expresion(nullptr, nullptr, '#');
           $$->valor = $1;
       }

;

%%
void yy::Parser::error(const yy::location& l, const std::string& m)
{
    Proyecto1::AST::getAST()->listaErrores += m;
    Proyecto1::AST::getAST()->listaErrores += '\n';

    /*std::cerr << l << ": " << m << std::endl;*/
}


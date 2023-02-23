#ifndef PARSERCTX_HPP
#define PARSERCTX_HPP
#include <string>

namespace yy {
class Parser;
class location;
}

namespace Proyecto1 {
class ParserCtx
{
public:
    // constructor
    ParserCtx();
    // destructor
    ~ParserCtx();


// atributos del analizador
    void* lexer;
    yy::location* loc;
    yy::Parser* Parser;
// funcion de analisis
    std::string Analizar(std::string entrada);
    std::string Salida;
};


}




#endif // PARSERCTX_HPP

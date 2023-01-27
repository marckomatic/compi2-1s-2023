public class METATIPOS{
    public const int PRIMITIVO = 0;
    public const int ARREGLO = 1;
    public const int OBJETO = 2; 
}

public class Simbolo{
    private int METATIPO; //valores que va asumir van a ser los valores preestablecidos de la clase Metatipo
    private string TIPO; //nombre del tipo de la variable o simbolo por ejemplo string, int, boolean, float
    private int linea;
    private int columna;
    private int nombre; 

    Simbolo getValor(){

    }
}

public Primitivo extends Simbolo{
    private string valor; //Si es string "Cadena", si es un entero "23", si es un boolean "true", si es float "23.3"
}

public Arreglo extends Simbolo{
    private List<Simbolo> valores; 
}

public objeto extends Simbolo{
    private Map<string, Simbolo> campos; 
}

public class TablaDeSimbolos{
    private List<Simbolo> variables; 
    private string ambito; 
    private string entorno; 
    private TablaDeSimbolos padre; 

    buscarParaLeer(string nombre){ //Metodo busca si la variable esta para leer. 
        if(seEncuentraEnEstaTablaDeSimbolos){
            return this.variables.get(nombre)
        }
        if(padre == null){
            return null; 
        }
        return padre.buscarParaLeer(nombre);
    }

    buscarParaCrear(string nombre){//busca solo dentro de la misma tabla si existe una variable con ese nombre
        if(seEncuentraEnEstaTablaDeSimbolos){
            return this.variables.get(nombre)
        }
        return null; 
    }

    crear(Simbolo variable){´
        if(buscarParaCrear(variable.nombre)){
            return false; 
        }
        variables.push(variable); 
        return true; 
    }

}

int a = 10; 

public funcion(int perimetro){
    a = 25; 
}

print(funcion(perimetro = a)); //si se pasa por valor, el resultado sera 10, si se pasa por referencia imprime 25
#include <iostream>
#include <string>
using namespace std;

int main(){

	//Salida de datos
    int edad=18;
	cout<<"Hello world"<<endl;
	cout<<"Tu edad es "<<edad<<" años.";

	//Tipos de Datos

	//Datos Simples

	int   entero          =  3;              //Numeros Enteros exactos
	float fraccionario    =  3.14;           //Numeros fraccionarios o con decimales
	double real           =  31415674598;    //Numeros de Precision doble o mayores a 16 bits
	char caracter         =  'f';            //Caracteres Alfanumericos{a,b,c,d,f,g,1,2,3,4,5,A,B,C,} etc
	bool booleano         =  true;           //Condiciones de Verdadero o Falso
	string cadena         =  "texto";      //Tipo de dato compuesto capaz de almacenar textos(cadenas de caracteres) 

	//Datos Compuestos

	int arreglo[] = {1,2,3,4,5,6,7,8,9,0};         //Lista de elementos del tipo declarado
	int matriz[3][3] = {(1,2,3),(4,5,6),(7,8,9)};   //Lista multidimensional del tipo declarado (se pueden agregar las dimensiones deseadas con el asignador [])
	int estatico [10] = {1,2,3,4,5,6,7,8,9,0};     //Lista de elementos de tamaño estatico (el tamaño de la lista se declara dentro del asignador [*])

	//Operaciones aritmeticas basicas

	int a,b,c,d;

	c=a+b; //Suma
	c=a-b; //Resta
	c=a/b; //Division
	c=a*b; //Multiplicacion

	c=a%b;    //Resto
	a+=d;     //Se le suma d al valor de a de forma acumulativa
	a+=b-c*d; //Todas son acumulables

	//Entrada de datos
	
	int introducido;
	cout<<"Introduce un valor"<<endl;
	cin>>introducido;//Se usa la palabra reservada cin>> para almacenar el valor introducido por consola

	//Comparadores

	a==b;  //Compara los valores de ambas variables y verifica si son iguales
	a!=b;  //Compara los valores de ambas variables y verifica si son diferentes
	a>b;   //Compara los valores de ambas variables y verifica si a es mayor que b
	a<b;   //Compara los valores de ambas variables y verifica si a es menor que b
	a>=b;  //Compara los valores de ambas variables y verifica si a es mayor o igual que b
	a<=b;  //Compara los valores de ambas variables y verifica si a es menor o igual que b

	//Operadores Logicos
	AND = a&&b;   //Devuelve Verdadero cuando ambas condiciones son verdaderas el resto de casos es falso(Tambien se entiende como: Si 'a' Y 'b' = True -> entonces True)
	OR = a||b;    //Devuelve Verdadero cuando una de las condiciones sea verdaderas(Tambien se entiende como: Si 'a' O 'b' = True -> entonces True)
		
	//Condicionales

	//if = Si se cumple la condicion:
	if (edad > 18) {
		//Se ejecuta el codigo
    cout<<"Eres mayor de edad."<<endl;
    }

    //else if =  Con esta sentencia se pueden crear varias condiciones
    else if(edad=18){
    	//Se ejecuta este otro codigo
    cout<<"Tienes 18."<<endl;	
    } 

    //Else = Si no:
    else {
    	//Se ejecuta este otro codigo
    cout<<"Eres menor de edad."<<endl;
    }

    //Switch = Se usa para crar multiples opciones de eleccion
    int opcion;
    cout<<"Selecciona una opción (1-3): ";
    cin>>opcion;

    //Iniciamos estructura
    switch (opcion){//Variable a comparar
    	//Compara caso a caso.
    	case 1:
        	cout << "Elegiste la opción 1." << endl;
        	break;
    	case 2:
        	cout << "Elegiste la opción 2." << endl;
        	break;
    	case 3:
        	cout << "Elegiste la opción 3." << endl;
        	break;
    	default:
        	cout << "Opción inválida." << endl;
        	break;
    }

    //Ciclos o Bucles, Estructuras repetitivas

    //Ciclo for, se repite una cantidad definida de veces

    
    for (int i = 0; i<5; i++) {    //Variable de control | Condicion | Incrementamos su valor para alcanzar el objetivo
    cout<<"Iteración "<<i<<endl;   //Condigo a ejecutar
    }


    //Bucle While, se ejecuta hasta que se cumpla la condicion de parada. (Piensa, luego ejecuta)
    int iteracion=0;                           //Declaramos variable de control de manera externa
    while (iteracion<5) {                      //Condicion
    cout << "Iteracion hasta 5." <<endl;       //Codigo
    iteracion++;                               //Aumentamos la variable de control internamente
    }


    //Bucle Do While, se ejecuta hasta quese cumpla la condicion de parada. (Ejecuta, luego piensa) 
    int condicion=0;
    do {
    	condicion=2*iteracion;
    } while (condicion>100);
    cout<<condicion<<endl;


	return 0;
}

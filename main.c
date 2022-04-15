#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>


//Creo la estuctura empleado para el punto 3. (Creo las estructuras arriba de todo el codigo
// por una cuestion de comodidad y prolijidad.

typedef struct
{
    float valorHora;
    char nombre[30];
    int antiguedad;
    float horasTrabajadas;
} stEmpleado;



//1.Pide un n�mero por teclado e indica si es un n�mero primo o no.

void indicarSiEsNroPrimoONo()
{
    int nro;
    printf("Ingrese un numero entero");
    fflush(stdin);
    scanf("%d", &nro);
    int aux = 0;

    for(int i = 1; i <= nro; i++)
    {
        if(nro % i == 0)
        {
            aux++;
        }
    }

    if(aux <= 2)
        printf("El numero es primo");
    else
        printf("El numero no es primo");
}

//2.Escribe una aplicaci�n que solicite al usuario que ingrese una contrase�a cualquiera.
//Despu�s se le pedir� que ingrese nuevamente la contrase�a, con 3 intentos.
//Cuando acierte ya no pedir� m�s la contrase�a y mostrar� un mensaje diciendo �Felicitaciones,record�s tu contrase�a�.
//Si falla luego de 3 intentos se mostrar� el mensaje �Tenes que ejercitar la memoria�. Los mensajes quedar�n en pantalla a la espera que el usuario
//presione una tecla, luego de esto se cerrar� el programa

void solicitarContraseniaAlUsuario()
{
    //Declaro las variables de tipo string (30 caracteres)
    char contrasenia[30];
    char usuario[30];

    //Pido al usuario que ingrese una contrase�a y la guardo en la variable contrasenia
    printf("Ingrese una contrase�a cualquiera: \n");
    fflush(stdin);
    scanf("%s", &contrasenia);

    //Le doy 3 intentos al usuario para ingresar la misma contrase�a, a traves de un while. Uso strcmp
    //para chequear que coincida con la que ingreso.
    printf("\nIngrese nuevamente su contrase�a, tiene 3 intentos \n");
    int i = 0;
    while(i < 3 && (strcmp(usuario, contrasenia) != 0))
    {
        fflush(stdin);
        scanf("%s", &usuario);
        i++;
    }

    if(strcmp(usuario, contrasenia) == 0)
        printf("\nFelicitaciones, recordas tu contrase�a");
    else
        printf("\nTenes que ejercitar la memoria");


    printf("\n\nPresione cualquier tecla para salir");
    getch();

}


//3- Por teclado se ingresa el valor hora de un empleado. Posteriormente se ingresa el nombre del empleado,
// la antig�edad y la cantidad de horas trabajadas en el mes. Sepide calcular el importe a cobrar teniendo
// en cuenta que al total que resulta de multiplicar el valor hora por la cantidad de horas trabajadas.
//Adem�s, si el empleadotiene m�s de 10 a�os de antig�edad hay que sumarle la cantidad de a�os
//trabajados multiplicados por $30. Imprimir en pantalla el nombre, la antig�edad y el total a cobrar


//Funcion para cargar empleado desde el teclado
stEmpleado cargarEmpleado()
{
    stEmpleado aux;
    float valorHora;
    char nombre[30];
    int antiguedad;
    float horasTrabajadas;
    printf("\nIngrese el valor hora del empleado ");
    fflush(stdin);
    scanf("%f", &valorHora);

    printf("\nIngrese el nombre del empleado ");
    fflush(stdin);
    scanf("%s", &nombre);

    printf("\nIngrese la antig�edad del empleado ");
    fflush(stdin);
    scanf("%d", &antiguedad);

    printf("\nIngrese las horas trabajadas del empleado ");
    fflush(stdin);
    scanf("%f", &horasTrabajadas);

    strcpy(aux.nombre, nombre);
    aux.valorHora = valorHora;
    aux.antiguedad = antiguedad;
    aux.horasTrabajadas = horasTrabajadas;

    return aux;
}

//Funcion para mostrar empleado
void mostrarEmpleado(stEmpleado empleado)
{
    printf("\nNombre: %s", empleado.nombre);
    printf("\nAntiguedad: %d", empleado.antiguedad);
}

void calcularImporteACobrar(stEmpleado empleado)
{
    float total = 0;
    if(empleado.antiguedad >= 10)
    {
        total += (empleado.horasTrabajadas * empleado.valorHora);
        total += (empleado.antiguedad * 30);
    }
    else
    {
        total += (empleado.horasTrabajadas * empleado.valorHora);
    }

    mostrarEmpleado(empleado);
    printf("\nImporte a cobrar: %0.2f", total);
}

//*4.Generar un n�mero aleatorio comprendido entre 0 y 1000. Pedir, a continuaci�n,
//alusuario adivinar el n�mero escogido por el ordenador. Para ello, debe introducir
//un n�mero comprendido entre 0 y 1000. Se compara el n�mero introducido con elcalculado
//por el ordenador y se muestra en la consola "es mayor" o "es menor" enfunci�n del caso.
//Se repite la operaci�n hasta que el usuario encuentra el n�mero.

void adivinarNumero()
{
    int nroAleatorio = rand() % 1000;
    int nroUsuario;
    while(nroUsuario != nroAleatorio)
    {
        printf("\n\nIntente adivinar el numero escogido por el ordenador (del 1 al 1000)\n");
        fflush(stdin);
        scanf("%d", &nroUsuario);
        if(nroUsuario == nroAleatorio)
        {
            system("cls");
            printf("Felicitaciones, encontro el numero!");
            break;
        }
        if(nroUsuario > nroAleatorio)
            printf("\nEl numero escogido por el ordenador es menor");
        else
            printf("El numero escogido por el ordenador es mayor");
    }
}


//*5.Pedir al usuario que ingrese un n�mero repetidamente hasta que ingrese un -1 y en
//esecaso se terminar� el programa.Al terminar, mostrar� lo siguiente:
//a.� mayor n�mero introducido
//b.� menor n�mero introducido
//c.� suma de todos los n�meros
//d.� suma de los n�meros

void ingresarNumeros()
{
    int nroUsuario = 0;
    int nroMayor = 0;
    int nroMenor = 0;
    int sumaTotal = 0;
    int total = 0;
    while(nroUsuario != -1)
    {
        printf("\nIngrese numeros repetidamente (en caso de presionar -1 finalizara el programa)");
        fflush(stdin);
        scanf("%d", &nroUsuario);
        if(nroUsuario != -1)
        {
            if(nroUsuario > nroMayor)
                nroMayor = nroUsuario;
            if(nroUsuario < nroMenor || nroMenor == 0)
                nroMenor = nroUsuario;
            sumaTotal += nroUsuario;
            total++;
        }
    }
    printf("\nMayor: %d", nroMayor);
    printf("\nMenor: %d", nroMenor);
    printf("\nSuma total: %d", sumaTotal);
    printf("\nTotal de numeros ingresados: %d", total);
}


int main()
{
    printf("\nElija que punto desea ejecutar: \n");
    printf("\n(1) (2) (3) (4) (5): \n");
    switch(getch())
    {
    case '1':
        system("cls");
        indicarSiEsNroPrimoONo();
        break;
    case '2':
        system("cls");
        solicitarContraseniaAlUsuario();
        break;
    case '3':
        system("cls");
        calcularImporteACobrar(cargarEmpleado());
    case '4':
        system("cls");
        adivinarNumero();
    case '5':
        system("cls");
        ingresarNumeros();
    }





    return 0;
}




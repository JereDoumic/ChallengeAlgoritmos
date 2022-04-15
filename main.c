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



//1.Pide un número por teclado e indica si es un número primo o no.

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

//2.Escribe una aplicación que solicite al usuario que ingrese una contraseña cualquiera.
//Después se le pedirá que ingrese nuevamente la contraseña, con 3 intentos.
//Cuando acierte ya no pedirá más la contraseña y mostrará un mensaje diciendo “Felicitaciones,recordás tu contraseña”.
//Si falla luego de 3 intentos se mostrará el mensaje “Tenes que ejercitar la memoria”. Los mensajes quedarán en pantalla a la espera que el usuario
//presione una tecla, luego de esto se cerrará el programa

void solicitarContraseniaAlUsuario()
{
    //Declaro las variables de tipo string (30 caracteres)
    char contrasenia[30];
    char usuario[30];

    //Pido al usuario que ingrese una contraseña y la guardo en la variable contrasenia
    printf("Ingrese una contraseña cualquiera: \n");
    fflush(stdin);
    scanf("%s", &contrasenia);

    //Le doy 3 intentos al usuario para ingresar la misma contraseña, a traves de un while. Uso strcmp
    //para chequear que coincida con la que ingreso.
    printf("\nIngrese nuevamente su contraseña, tiene 3 intentos \n");
    int i = 0;
    while(i < 3 && (strcmp(usuario, contrasenia) != 0))
    {
        fflush(stdin);
        scanf("%s", &usuario);
        i++;
    }

    if(strcmp(usuario, contrasenia) == 0)
        printf("\nFelicitaciones, recordas tu contraseña");
    else
        printf("\nTenes que ejercitar la memoria");


    printf("\n\nPresione cualquier tecla para salir");
    getch();

}


//3- Por teclado se ingresa el valor hora de un empleado. Posteriormente se ingresa el nombre del empleado,
// la antigüedad y la cantidad de horas trabajadas en el mes. Sepide calcular el importe a cobrar teniendo
// en cuenta que al total que resulta de multiplicar el valor hora por la cantidad de horas trabajadas.
//Además, si el empleadotiene más de 10 años de antigüedad hay que sumarle la cantidad de años
//trabajados multiplicados por $30. Imprimir en pantalla el nombre, la antigüedad y el total a cobrar


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

    printf("\nIngrese la antigüedad del empleado ");
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

//*4.Generar un número aleatorio comprendido entre 0 y 1000. Pedir, a continuación,
//alusuario adivinar el número escogido por el ordenador. Para ello, debe introducir
//un número comprendido entre 0 y 1000. Se compara el número introducido con elcalculado
//por el ordenador y se muestra en la consola "es mayor" o "es menor" enfunción del caso.
//Se repite la operación hasta que el usuario encuentra el número.

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


//*5.Pedir al usuario que ingrese un número repetidamente hasta que ingrese un -1 y en
//esecaso se terminará el programa.Al terminar, mostrará lo siguiente:
//a.– mayor número introducido
//b.– menor número introducido
//c.– suma de todos los números
//d.– suma de los números

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




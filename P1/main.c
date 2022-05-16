#include <stdio.h>
#include <stdlib.h>

#define TAMV 3

typedef struct {
    int id;
    char nombre[20];
    char tipo;
    float efectividad;
    }eVacuna;

float aplicarAumento(float precioProducto);

int ordenarVacunasXTipoYEfectividad(eVacuna vec[], int tam);

int main()
{
    float precioProducto;
    float resultado;

    eVacuna auxVacunas[TAMV] =
    {
        {100, "Pfizer", 'B', 88},
        {100, "Moderna", 'C', 79},
        {100, "Sputnik", 'A', 92.5},
    };

    ordenarVacunasXTipoYEfectividad(auxVacunas, TAMV);

    printf("Ingresa el precio: ");
    scanf("%f", &precioProducto);

    resultado = aplicarAumento(precioProducto);

    printf("Precio con aumento: %0.2f", resultado);
}

float aplicarAumento(float precioProducto)
{
    float aumento;
    float precioConAumento;
    int porcentajeAumento = 5;

    if(precioProducto > 0)
    {
        aumento = precioProducto * ((float)porcentajeAumento / 100);
        precioConAumento = precioProducto + aumento;
    }
    else
    {
        printf("Se ingreso un precio invalido");
    }

    return precioConAumento;
}



int ordenarVacunasXTipoYEfectividad(eVacuna vec[], int tam)
{
    int todoOk = 0;
    eVacuna auxVacunas;
    if(vec != NULL && tam > 0)
    {
        for(int i=0; i < tam -1; i++)
        {
            for(int j= i + 1; j < tam; j++)
            {
                if( ((vec[i].tipo == vec[j].tipo) &&  (vec[i].efectividad > vec[j].efectividad))
                        || ((vec[i].tipo != vec[j].tipo) &&(vec[i].tipo > vec[j].tipo) ))
                {
                    auxVacunas = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxVacunas;
                }
            }
        }
        todoOk = 1;
    }
    return todoOk;
}






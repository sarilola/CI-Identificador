#include <stdio.h>
#include "CI.h"

int main(){
    char cedula[10];
    int ci[10], par[4], i, impar[5];
    
    repetir:
    CI(cedula, ci); //1316109626
    printci(ci);
    
    pares(ci, par);
    //comprobacion pares 
    printf("\nPosiciones pares:");
    for( i = 0; i < 4; i++){
        printf(" %d ", par[i]);    //resultado esperado: 3 6 0 6
    }
    
    impares(ci, impar); //comprobacion impares
    printf("\nPosiciones impares:");
    for( i = 0; i < 5; i++){
        printf(" %d ", impar[i]);    //resultado esperado: 1 1 1 9 2
    }
    
    duplicadoimpar(impar);//resultado esperado: 2 2 2 9 4

    int verif = verificador(par, impar);
    printf("\nNumero verificador: ");
    printf("%d", verif);

    provincia(ci); //mostrar provincia del ciudadano

    if (verif == ci[9])
    {
        printf("\nCedula de identidad ingresada correctamente!\n");
    }else{
        printf("\nCedula de identidad incorrecta!\n");
        goto repetir;
    }
    
    return 0;
}


#include <stdio.h>

void CI(char cedula[10], int ci[10]){
    int i;
    denuevo:
    printf("\nIngrese el numero de cedula: ");
    scanf("%s", cedula); //luego agregar comprobacion para 1er y 2do y 3er
    
    for(i = 0 ; i < 10 ; i++){ 
        ci[i] = cedula[i] - '0'; //convierte de char a int
    }

    if (ci[0] > 3 || ci[0] < 0)
    {
        printf("No valido.");
    }else{
        if(ci[2] > 6){
        printf("El tercer digito no puede ser mayor a 6\n");
        goto denuevo;
        }
        if(ci[0] == 2 && ci[1] > 4){
            printf("\nLos dos primeros digitos juntos no deben pasar el 24 y, en caso de que sea un diplomatico o registrado en el exterior, este debe ser igual a 30.");
            goto denuevo;
        }
        if (ci[0] == 3 && ci[1] != 0)
        {
            printf("\nNo valido.");
            goto denuevo;
        }
    }
}

void printci(int ci[10]){
    int i;
    printf("\nNumero de cedula ingresado:");
    for(i = 0 ; i < 10 ; i++){
        printf("%d", ci[i]);
    }
}

void pares(int ci[10], int pares[4]){
    int i, j = 0;
    for(i = 1 ; i < 9 ; i = i + 2){
        pares[j] = ci[i];
        j++;
    }
}

void impares(int ci[10], int impar[5]){
    int i, j = 0;
    for(i = 0 ; i < 9 ; i = i + 2){
        impar[j] = ci[i];
        j++;
    }
}

void duplicadoimpar(int impar[5]){
    int i, res;
    for(i = 0 ; i < 5 ; i++){
        res = impar[i] * 2;
        if(res > 9){
            impar[i] = res - 9;
        }else{
            impar[i] = res;
        }
    }
}

int verificador(int pares[4], int impares[5]){
    int sumpar = 0, sumimpar = 0, i, verificador;
    for(i = 0 ; i < 4 ; i++){
        sumpar += pares[i]; //sumatoria de pares
    }
    for(i = 0 ; i < 5 ; i++){
        sumimpar += impares[i]; //sumatoria de impares
    }
    verificador = (sumpar + sumimpar) % 10;
    if(verificador == 0){
        return 0;
    }else{
        return 10 - verificador;
    }
}

//hacer una funcion que determine la provincia del ciudadano
void provincia(int ci[10]){ //ecuador tiene 24 provincias
    char prov[24][20] = {"Azuay", "Bolivar", "Canar", "Carchi", "Cotopaxi", "Chimborazo", "El Oro", "Esmeraldas", "Guayas", "Imbabura", "Loja", "Los Rios", "Manabi", "Morona Santiago", "Napo", "Pastaza", "Pichincha", "Tungurahua", "Zamora Chinchipe", "Galapagos", "Sucumbios", "Orellana", "Sto. Domingo", "Sta. Elena"};
    int i, aux;
    if (ci[0] == 0)
    {
        i = ci[1];
        printf("\nProvincia: %s", prov[i - 1]);   
    }

    if (ci[0] == 1)
    {
        i = ci[1];
        aux = 9 + i;
        printf("\nProvincia: %s", prov[aux]);
    }

    if (ci[0] == 2)
    {
        i = ci[1];
        aux = 19 + i;
        printf("\nProvincia: %s", prov[aux]);
    }
    
    if (ci[0] == 3 && ci[1] == 0) //los que tengan 30 como primeros numero son diplomaticos o registrados en el exterior
    {
        printf("\nProvincia: Diplomatico o Registrado en el Exterior");
    }
}


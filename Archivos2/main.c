#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int a;
    char b;
} eDato;

void funcion1();
void funcion2a();
void funcion2b();
void funcion3();

int main()
{
    //funcion1();
    //funcion2a();
    //funcion2b();
    funcion3();


    return 0;
}
void funcion1()
{
    FILE* miArchivo;
    int numero= 64;
    /*
        miArchivo = fopen("prueba1.txt","w");

        fwrite(&numero,sizeof(int),1,miArchivo);

        fclose(miArchivo);*/

    miArchivo = fopen("prueba1.txt","r");

    fread(&numero,sizeof(int),1,miArchivo);
    fclose(miArchivo);
    printf("NUMERO: %d", numero);

}
void funcion2a()
{
    FILE* miArchivo;
    int i=0;
    int numero;
    int lista[5];//={1,5,9,6,4};

    miArchivo = fopen("prueba.txt","w");

    for(i=0; i<5; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", &numero);
        fwrite(&numero,sizeof(int),1,miArchivo);
    }


    fclose(miArchivo);

    miArchivo = fopen("prueba.txt","r");
    i=0;
    while(!feof(miArchivo))
    {
        fread(&lista[i],sizeof(int),1,miArchivo);

        i++;
    }

    fclose(miArchivo);

    for(i=0; i<5; i++)
    {

        printf("%d\n",lista[i]);

    }
}
void funcion2b()
{
    FILE* miArchivo;
    int i;
    int numero;
    int lista[5];//={1,5,9,6,4};

    /*miArchivo = fopen("prueba3.txt","w");


    fwrite(lista,sizeof(int),5,miArchivo);

    fclose(miArchivo);*/

    miArchivo = fopen("prueba3.txt","r");

    fread(lista,sizeof(int),5,miArchivo);


    fclose(miArchivo);

    for(i=0; i<5; i++)
    {

        printf("%d\n",lista[i]);

    }
}
void funcion3()
{
    FILE* miArchivo;
    eDato d;// = {1, 'b'};

    /*miArchivo = fopen("miBinario.dat", "wb");

    if(miArchivo!=NULL)
    {
        fwrite(&d,sizeof(eDato),1,miArchivo);
        fclose(miArchivo);
    }*/

    miArchivo = fopen("miBinario.dat", "rb");

    if(miArchivo!=NULL)
    {
        fread(&d,sizeof(eDato),1,miArchivo);
        fclose(miArchivo);
        printf("%d--%c", d.a, d.b);
    }
}

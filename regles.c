#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "intialisation/config.c"
//
// Created by Antoine TOUZART on 06/10/2022.
//

int utilisationCharacter(char* jc) //detection de character en entree
{

    int b=0;
    do
    {
        for(int i=0;i<strlen(jc);i++) //regarde les character 1 par 1
        {
            if (jc[i] >= '0' && jc[i] <= '9') {
                b++;
                continue;
            } else {
                printf("l'utilisation du character %c n'est pas autorisé \0", jc);
                scanf(jc);
                break;
            }
        }
    }
    while(b==strlen(jc)); // temps qu il y a un character dans la chaine , il redemandera

    int num=0;
    for(int i=0; i<strlen(jc);i++) //rendre le tableau de chaine de character en int
    {
        num*=10 + jc[i];
    }

    return num;
}

char sortieTableau(int cmax , char* jc) //refais jouer joueur s il sort du tableau
{
    //jc correspond a la colonne ou le joueur joue
    //cmax est la colonne max du tableau
    int i=0;


    while(i==0)
    {
        int num = utilisationCharacter(jc); //scan de character
        if (num >= 0 && num <= cmax)
        {
            return num;
        }
        else
        {
            printf("l'utilisation de la colonne %d n'est pas autorisé \0", num);
            scanf(num);
        }
    }
}

void AjouterPion(int rows){
    int collone = column;
    while(grid[rows][co])
}



int win(char** grillage, int colonne)
{

}

void regles()
{

}
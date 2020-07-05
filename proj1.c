/*
	P R O J E C T O		1

	O r c a m e n t o  P e s s o a l

	I A E D

	2011 / 2012

	Entrega: 2 Abril 2012, 18h

#70969 Mario Reis
#73100 Tiago Simoes
#73746 Miguel Cartaxo

*/

#include <stdio.h>
#include <string.h>

#define MOV 100
#define DIAS 1000
#define TamDESC 61


/* ESTRUTURAS PARA GUARDAR MOVIMENTOS */

typedef struct MOVIMENTOS_1{
	int montante, periodicidade, mov_usado;
	char descricao[TamDESC], funcao;

}caracteristicas_movimentos;

typedef struct MOVIMENTOS{
	caracteristicas_movimentos numero_mov[MOV];
	} movimentos;

    movimentos mov[DIAS];
    struct MOVIMENTOS m;


/*Funcao inserirMov
Esta funcao recebe 5 argumentos e permite insere os dados na matriz de acordo com a estrutura movimentos.
*/
void inserirMov(int montante_provisorio,int dia_provisorio, int periodo_provisorio, char funcao_provisorio, char *descricao_provisorio){

	int movimento;

    if(funcao_provisorio == 'd' || funcao_provisorio == 'r'){
        if (periodo_provisorio == 0){
            for(movimento = 0; movimento < MOV; movimento++){

                if (mov[dia_provisorio].numero_mov[movimento].mov_usado == 0){
                    mov[dia_provisorio].numero_mov[movimento].funcao = funcao_provisorio;
                    strcpy(mov[dia_provisorio].numero_mov[movimento].descricao, descricao_provisorio);
                    mov[dia_provisorio].numero_mov[movimento].mov_usado = 1;
                    mov[dia_provisorio].numero_mov[movimento].montante = montante_provisorio;
                    mov[dia_provisorio].numero_mov[movimento].periodicidade = periodo_provisorio;
                    break;
                }
				else
                    ;
            }
        }
        else
            ;

        if (periodo_provisorio > 0){
            for( ; dia_provisorio < DIAS; dia_provisorio = (dia_provisorio + periodo_provisorio)){

                for(movimento = 0; movimento < MOV; movimento++){
                        if (mov[dia_provisorio].numero_mov[movimento].mov_usado == 0){
                            mov[dia_provisorio].numero_mov[movimento].funcao = funcao_provisorio;
                            strcpy(mov[dia_provisorio].numero_mov[movimento].descricao, descricao_provisorio);
                            mov[dia_provisorio].numero_mov[movimento].mov_usado = 1;
                            mov[dia_provisorio].numero_mov[movimento].montante = montante_provisorio;
                            mov[dia_provisorio].numero_mov[movimento].periodicidade = periodo_provisorio;
                        break;
                        }
                        else
                        ;
                }
            }
        }
        else
        ;
    }
return;
}


/*Funcao mostraMov
Esta funcao recebe um argumento e mostra todos os movimentos ocorridos numa determinada data.
*/
void mostraMov(int dia_provisorio){

    int movimento;

	for(movimento = 0; movimento < MOV; movimento++){

		if(mov[dia_provisorio].numero_mov[movimento].mov_usado == 1)
        printf("%d %d %c %s\n", movimento, mov[dia_provisorio].numero_mov[movimento].montante, mov[dia_provisorio].numero_mov[movimento].funcao, mov[dia_provisorio].numero_mov[movimento].descricao);
        else
        break;
	}

return;
}


/*Funcao removeMov
Esta funcao recebe dois argumentos e remove o movimento indicado.
*/
void removeMov(int dia_provisorio,int movimento){

	for ( ; movimento < MOV; movimento++){

        if (mov[dia_provisorio].numero_mov[movimento+1].mov_usado == 1){
            mov[dia_provisorio].numero_mov[movimento].funcao = mov[dia_provisorio].numero_mov[movimento+1].funcao;
            strcpy(mov[dia_provisorio].numero_mov[movimento].descricao,mov[dia_provisorio].numero_mov[movimento+1].descricao);
            mov[dia_provisorio].numero_mov[movimento].montante = mov[dia_provisorio].numero_mov[movimento+1].montante;
            mov[dia_provisorio].numero_mov[movimento].mov_usado = mov[dia_provisorio].numero_mov[movimento+1].mov_usado;
            mov[dia_provisorio].numero_mov[movimento].periodicidade = mov[dia_provisorio].numero_mov[movimento+1].periodicidade;
        }
        else
            mov[dia_provisorio].numero_mov[movimento].mov_usado = 0;
    }
return;


}


/*Funcao calculaBal
Esta funcao recebe um argumento e calcula o balanco numa determinada data, incluindo todos os movimentos ocorridos nessa data.
*/
int calculaBal(int dia_provisorio){

    int dia,conta,movimento;

	for(dia = 0, conta = 0; dia <= dia_provisorio; dia++){

       	for(movimento = 0; movimento < MOV; movimento++){

                if (mov[dia].numero_mov[movimento].mov_usado == 1)
                    switch (mov[dia].numero_mov[movimento].funcao){
                    case 'r' : conta=conta+mov[dia].numero_mov[movimento].montante;
                        break;
                    case 'd' : conta=conta-mov[dia].numero_mov[movimento].montante;
                        break;
                }
                else
                    break;
	    }
    }

return conta;
}


/*Funcao validadeOrc
Esta funcao recebe um argumento e verifica a validade do orcamento.
*/
void validadeOrc(int vMin){

    int dia;

	for(dia=0; dia < DIAS; dia++){

	    if (vMin>calculaBal(dia)){
            printf("Invalido\n");
            return;
        }
    }

    if (calculaBal(dia) >= vMin)
        printf("Valido\n");
    else
        ;

return;
}


/*Funcao primeiraData
Esta funcao recebe dois argumentos, e determina a primeira data em que uma determinada despesa se torna comportavel, sem invalidar o orcamento.
*/
void primeiraData(int dia_provisorio, int despesa,int vMin){

    int dia = 0,possivel = 0,dia_final = dia_provisorio;

        for( ; dia < DIAS; dia++ ){

            if((vMin <= calculaBal(dia) - despesa) && ( dia >= dia_provisorio )){
                if (possivel != 1){
                    dia_final = dia;
                    possivel = 1;
                    }
            }
            else
                possivel = 0;
        }

        if (possivel == 1)
            printf("%d\n",dia_final);
        else
            printf("Incomportavel\n");

return;
}

/*Funcao main
Esta funcao recebe todos os valores, e consoante a instrucao que o utilizador da, o programa escolhe a funcao respectiva.
*/
int main(){


        int dia_provisorio, montante_provisorio, periodo_provisorio,vMin=0,movimento,despesa;
        char descricao_provisorio[TamDESC], funcao_provisorio,opcao;

        while((opcao = getchar()) != EOF){

          switch(opcao){
            case 'i':
                scanf("%d",&montante_provisorio);
                scanf("%d",&dia_provisorio);
                scanf("%d",&periodo_provisorio);
                scanf(" %c",&funcao_provisorio);
                scanf(" %s",descricao_provisorio);
                inserirMov(montante_provisorio,dia_provisorio,periodo_provisorio,funcao_provisorio,descricao_provisorio);
                break;

            case 'l':
                scanf("%d", &dia_provisorio);
                mostraMov(dia_provisorio);
                break;

            case 'r':
                scanf("%d",&dia_provisorio);
                scanf("%d",&movimento);
                removeMov(dia_provisorio,movimento);
                break;
            case 'b':
                scanf("%d",&dia_provisorio);
                printf("%d\n",calculaBal(dia_provisorio));
                break;
            case 'm':
                scanf("%d",&vMin);
                break;
            case 'v': validadeOrc(vMin);
                break;
            case 'w':
                scanf("%d",&dia_provisorio);
                scanf("%d",&despesa);
                primeiraData(dia_provisorio,despesa,vMin);
                break;
           }
        }

return 0;
}

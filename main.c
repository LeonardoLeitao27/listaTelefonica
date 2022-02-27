#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TabelaHash.h"
#include "ArvoreAVL.h"

int main(){
	struct no al, z[100];
	int a = 2,deci=0,ddd=0,altura=0;
	int numBus=0;
	
	int tamanho = 100;
	//criando a tebala hash para o armazenamento do inteiro com o numero ddd e o ponteiro da arvore AVL
	Hash *tabela = criaHash(tamanho);

	//While feito para organizar as acoes do sistema
	while(a==2){
		
		printf("1 - Cadastrar usuario\n2 - Encontrar usuario \n3 - Descadastrar usuario\n4 - Listar Usuarios cadastrado(Pre-ordem)\n5 - Listar Usuarios cadastrado(Em-ordem)\n6 - Listar Usuarios cadastrado(Pos-ordem)\n7 - Solicitar novo numero \n8 - Gerar lista telefonica por DDD(numero de telefone)\n9 - Encerrar sistema\n");
		scanf("%d",&deci);
			
			switch (deci) {
		    case 1:
		    	system("cls");
		       	printf("caso1\n");
		       	cadastra(tabela);
		       break;
		       
		    case 2:
		       system("cls");
		       printf("\ncaso2\n");
		       printf("\nInsira o ddd do usuario que deseja encontrar\n");
			   scanf("%d",&ddd);
			   printf("\nInsira o numero do usuario que deseja encontrar\n");
			   scanf("%d",&numBus);
			   system("cls");
			   buscaHash_SemColisao(tabela, ddd, &al);
			   busca_usuNumero(al.endereco,numBus);
			   printf("=====================\n");
		       break;
		       
		    case 3:
		       system("cls");
		       printf("\ncaso3\n");
		       printf("\nInsira o ddd do usuario que deseja descadastrar do sistema\n");
			   scanf("%d",&ddd);
			   printf("\nInsira o numero do usuario que deseja descadastrar\n");
			   scanf("%d",&numBus);
			   system("cls");
			   buscaHash_SemColisao(tabela, ddd, &al);
			   altura = altura_ArvAVL(al.endereco);
			   printf("\nAltura da arvore antes da remocao: %d\n",altura);
			   remove_ArvAVL(al.endereco,numBus);
			   altura = altura_ArvAVL(al.endereco);
			   printf("\nAltura da arvore depois da remocao: %d\n",altura);
			   printf("==================\nO usuario removido\n==================\n");
		       break;
		       
		    case 4:
		       system("cls");
		       printf("\ncaso4\n");
		       printf("\nQual DDD voce deseja listar?(Pre-ordem)\n");
			   scanf("%d",&ddd);
			   system("cls");
			   buscaHash_SemColisao(tabela, ddd, &al);
			   preOrdem_ArvAVL(al.endereco);
			   printf("\n=====================\n");
		       break;
		       
		    case 5:
		       system("cls");
		       printf("\ncaso5\n");
		       printf("\nQual DDD voce deseja listar?(Em-ordem)\n");
			   scanf("%d",&ddd);
			   system("cls");
			   buscaHash_SemColisao(tabela, ddd, &al);
			   emOrdem_ArvAVL(al.endereco);
			   printf("\n=====================\n");
		       break;
		       
		    case 6:
		       system("cls");
		       printf("\ncaso6\n");
		       printf("\nQual DDD voce deseja listar?(Pos-ordem)\n");
			   scanf("%d",&ddd);
			   system("cls");
			   buscaHash_SemColisao(tabela, ddd, &al);
			   posOrdem_ArvAVL(al.endereco);
			   printf("\n=====================\n");
		       break;
		    
		    case 7:
		       system("cls");
		       printf("\ncaso7\n");
	           printf("Em qual DDD voce quer criar um novo numero?\n");
		       scanf("%d",&ddd);
		       system("cls");
		       buscaHash_SemColisao(tabela, ddd, &al);
		       sugereNumero(al.endereco);
		       break;
		    
		    case 8:
		       system("cls");
		       printf("\ncaso8\n");
		       printf("\nQual DDD voce deseja listar?(Ordenacao por numero)\n");
			   scanf("%d",&ddd);
			   system("cls");
			   buscaHash_SemColisao(tabela, ddd, &al);
			   busca_usuTele(al.endereco);
		       break;
		       
		    case 9:
		       sleep(1);
		       system("cls");
		       printf("\n Trabalho desenvolvido por: \n\n Alisson Lucas Sampaio Alves \n Caio Felicio Marques\n Francisco Leonardo Marcos Leitao\n Miguel Mota Veras Marques\n");
		       printf("\n Bye Bye :)\n");
		       a = 1;
		       break;
		       
		    default:
		       system("cls");
		       printf("Valor invalido! Por favor, insira uma das opcoes abaixo:\n");;
	 }		
	}
	return 0;
}

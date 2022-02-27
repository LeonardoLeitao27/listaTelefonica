#include <string.h>
#include <stdlib.h>
#include <time.h>

//struct com os dados que vão ser cadastrados no sistema 
struct pessoa{
	int numero;
	char nome[50];
	char endereco[50];
};

struct NO{
    struct pessoa p;
    int altura;
    struct NO *esq;
    struct NO *dir;
};

typedef struct NO* ArvAVL;

//funcao que cria a arvore avl
ArvAVL* cria_ArvAVL(){
    ArvAVL* raiz = (ArvAVL*) malloc(sizeof(ArvAVL));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}


//libera um nó recebido 
void libera_NO(struct NO* no){
    if(no == NULL)
        return;
    libera_NO(no->esq);
    libera_NO(no->dir);
    free(no);
    no = NULL;
}

//libera a arvore recebida
void libera_ArvAVL(ArvAVL* raiz){
    if(raiz == NULL)
        return;
    libera_NO(*raiz);//libera cada nó
    free(raiz);//libera a raiz
}

//retorna a altura de um determinado nó 
int altura_NO(struct NO* no){
    if(no == NULL)
        return -1;
    else
    return no->altura;
}

//retorna a altura do nó mais a esquerda menos a altura do nó mais a direita
int fatorBalanceamento_NO(struct NO* no){
    return labs(altura_NO(no->esq) - altura_NO(no->dir));
}

//retorna o maior de dois inteiros
int maior(int x, int y){
    if(x > y)
        return x;
    else
        return y;
}

//verifica se a arvore está vazia
int estaVazia_ArvAVL(ArvAVL *raiz){
    if(raiz == NULL)
        return 1;
    if(*raiz == NULL)
        return 1;
    return 0;
}

//retorna a quantidade de nó da arvore
int totalNO_ArvAVL(ArvAVL *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = totalNO_ArvAVL(&((*raiz)->esq));
    int alt_dir = totalNO_ArvAVL(&((*raiz)->dir));
    return(alt_esq + alt_dir + 1);
}

//retorna o tamanho da arvore
int altura_ArvAVL(ArvAVL *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = altura_ArvAVL(&((*raiz)->esq));
    int alt_dir = altura_ArvAVL(&((*raiz)->dir));
    if (alt_esq > alt_dir)
        return (alt_esq + 1);
    else
        return(alt_dir + 1);
}

//recebe o caminho de uma arvore e imprime somente os numeros em pre-ordem
void preOrdem_ArvAVL(ArvAVL *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        printf("Numero: %d",(*raiz)->p.numero);
    	printf("\n\n");
        preOrdem_ArvAVL(&((*raiz)->esq));
        preOrdem_ArvAVL(&((*raiz)->dir));
    }
}
//recebe o caminho de uma arvore e imprime somente os numeros em ordem crescente
void emOrdem_ArvAVL(ArvAVL *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        emOrdem_ArvAVL(&((*raiz)->esq));
        
        printf("Numero: %d",(*raiz)->p.numero);
    	printf("\n\n");
        emOrdem_ArvAVL(&((*raiz)->dir));
    }
}
//recebe o caminho de uma arvore e imprime somente os numeros em pos-ordem
void posOrdem_ArvAVL(ArvAVL *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        posOrdem_ArvAVL(&((*raiz)->esq));
        posOrdem_ArvAVL(&((*raiz)->dir));       
      
       printf("Numero: %d",(*raiz)->p.numero);
    	printf("\n\n");
    }
}

//recebe o caminho de uma arvore e imprime ela em ordem crescente(com base na ordencao por numero)
void busca_usuTele(ArvAVL *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        busca_usuTele(&((*raiz)->esq));
       
       	printf("\n");
        printf("Numero: %d\nNome: %sEndereco: %s\n",(*raiz)->p.numero,(*raiz)->p.nome,(*raiz)->p.endereco);
    	printf("===============\n");
        busca_usuTele(&((*raiz)->dir));
    }
} 

/*
//recebe o caminho de uma arvore e imprime ela em ordem crescente(com base na ordencao por numero)
void busca_usuNome(ArvAVL *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        busca_usuNome(&((*raiz)->esq));
       
       	printf("\n");
        printf("Nome: %s\nNumero: %dEndereco: %s\n",(*raiz)->p.nome,(*raiz)->p.numero,(*raiz)->p.endereco);
    	printf("===============\n");
        busca_usuNome(&((*raiz)->dir));
    }
} */



//recebe o caminho de uma arvore e um inteiro numero de telefone 
//procura na arvore e imprime os dados correspondentes ao numero
void busca_usuNumero(ArvAVL *raiz, int valor){
    if(raiz == NULL)
        return 0;
    struct NO* atual = *raiz;
    while(atual != NULL){
        if(valor == atual->p.numero){
        	printf("Numero: %d\nNome: %sEndereco: %s\n",atual->p.numero,atual->p.nome,atual->p.endereco);
            return 1;
        }
        if(valor > atual->p.numero)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
}

//recebe o caminho de uma arvore e um inteiro numero de telefone 
//procura na arvore se o numero ja existe na arvore
int busca_numeroDuplicado(ArvAVL *raiz, int valor){
	if(raiz == NULL)
        return 0;
    struct NO* atual = *raiz;
    
    while(atual != NULL){
        if(valor == atual->p.numero){
            return 1;
        }
        if(valor > atual->p.numero)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 2;
}

//recebe o caminho de uma arvore e um inteiro numero de telefone 
//procura na arvore o numero 
int consulta_ArvAVL(ArvAVL *raiz, int valor){
    if(raiz == NULL)
        return 0;
    struct NO* atual = *raiz;
    while(atual != NULL){
        if(valor == atual->p.numero){
            return 1;
        }
        if(valor > atual->p.numero)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
}

//=================================
void RotacaoLL(ArvAVL *A){//LL
 //   printf("RotacaoLL\n");
    struct NO *B;
    B = (*A)->esq;
    (*A)->esq = B->dir;
    B->dir = *A;
    (*A)->altura = maior(altura_NO((*A)->esq),altura_NO((*A)->dir)) + 1;
    B->altura = maior(altura_NO(B->esq),(*A)->altura) + 1;
    *A = B;
}

void RotacaoRR(ArvAVL *A){//RR
//    printf("RotacaoRR\n");
    struct NO *B;
    B = (*A)->dir;
    (*A)->dir = B->esq;
    B->esq = (*A);
    (*A)->altura = maior(altura_NO((*A)->esq),altura_NO((*A)->dir)) + 1;
    B->altura = maior(altura_NO(B->dir),(*A)->altura) + 1;
    (*A) = B;
}

void RotacaoLR(ArvAVL *A){//LR
    RotacaoRR(&(*A)->esq);
    RotacaoLL(A);
}

void RotacaoRL(ArvAVL *A){//RL
    RotacaoLL(&(*A)->dir);
    RotacaoRR(A);
}

//funcao que insere a struct na arvore avl
int insere_ArvAVL(ArvAVL *raiz, struct pessoa entrada){
    int res;
    if(*raiz == NULL){//árvore vazia ou nó folha
        struct NO *novo;
        novo = (struct NO*)malloc(sizeof(struct NO));
        if(novo == NULL)
            return 0;

        novo->p = entrada;
        novo->altura = 0;
        novo->esq = NULL;
        novo->dir = NULL;
        *raiz = novo;
        return 1;
    }

    struct NO *atual = *raiz;
    if(entrada.numero < atual->p.numero){
        if((res = insere_ArvAVL(&(atual->esq), entrada)) == 1){
            if(fatorBalanceamento_NO(atual) >= 2){
                if(entrada.numero < (*raiz)->esq->p.numero ){
                    RotacaoLL(raiz);
                }else{
                    RotacaoLR(raiz);
                }
            }
        }
    }else{
        if(entrada.numero > atual->p.numero){
            if((res = insere_ArvAVL(&(atual->dir), entrada)) == 1){
                if(fatorBalanceamento_NO(atual) >= 2){
                    if((*raiz)->dir->p.numero < entrada.numero){
                        RotacaoRR(raiz);
                    }else{
                        RotacaoRL(raiz);
                    }
                }
            }
        }else{
            printf("Valor duplicado!!\n");
            return 0;
        }
    }

    atual->altura = maior(altura_NO(atual->esq),altura_NO(atual->dir)) + 1;

    return res;
}

//procura o menor valor dentro do nó
struct NO* procuraMenor(struct NO* atual){
    struct NO *no1 = atual;
    struct NO *no2 = atual->esq;
    while(no2 != NULL){
        no1 = no2;
        no2 = no2->esq;
    }
    return no1;
}

//recebe o caminho de uma arvore e um inteiro numero de telefone 
//remove o nó que corresponde ao numero 
int remove_ArvAVL(ArvAVL *raiz, int valor){
	if(*raiz == NULL){// valor não existe
	    printf("valor não existe!!\n");
	    return 0;
	}

    int res;
	if(valor < (*raiz)->p.numero){
	    if((res = remove_ArvAVL(&(*raiz)->esq,valor)) == 1){
            if(fatorBalanceamento_NO(*raiz) >= 2){
                if(altura_NO((*raiz)->dir->esq) <= altura_NO((*raiz)->dir->dir))
                    RotacaoRR(raiz);
                else
                    RotacaoRL(raiz);
            }
	    }
	}

	if((*raiz)->p.numero < valor){
	    if((res = remove_ArvAVL(&(*raiz)->dir, valor)) == 1){
            if(fatorBalanceamento_NO(*raiz) >= 2){
                if(altura_NO((*raiz)->esq->dir) <= altura_NO((*raiz)->esq->esq) )
                    RotacaoLL(raiz);
                else
                    RotacaoLR(raiz);
            }
	    }
	}

	if((*raiz)->p.numero == valor){
	    if(((*raiz)->esq == NULL || (*raiz)->dir == NULL)){// nó tem 1 filho ou nenhum
			struct NO *oldNode = (*raiz);
			if((*raiz)->esq != NULL)
                *raiz = (*raiz)->esq;
            else
                *raiz = (*raiz)->dir;
			free(oldNode);
		}else { // nó tem 2 filhos
			struct NO* temp = procuraMenor((*raiz)->dir);
			(*raiz)->p = temp->p;
			remove_ArvAVL(&(*raiz)->dir, (*raiz)->p.numero);
            if(fatorBalanceamento_NO(*raiz) >= 2){
				if(altura_NO((*raiz)->esq->dir) <= altura_NO((*raiz)->esq->esq))
					RotacaoLL(raiz);
				else
					RotacaoLR(raiz);
			}
		}
		if (*raiz != NULL)
            (*raiz)->altura = maior(altura_NO((*raiz)->esq),altura_NO((*raiz)->dir)) + 1;
		return 1;
	}

	(*raiz)->altura = maior(altura_NO((*raiz)->esq),altura_NO((*raiz)->dir)) + 1;

	return res;
}

//recebe o caminho de uma arvore e um inteiro numero de telefone 
//procura o numero de telefone na arvore 
int busca_compara(ArvAVL *raiz, int valor){
    if(raiz == NULL){
    	return 2;
	}
    struct NO* atual = *raiz;
    while(atual != NULL){
        if(valor == atual->p.numero){
            return 1;
        }
        if(valor > atual->p.numero)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
} 

//funcao que recomenda 3 numeros nao cadastrado na arvore ddd
int sugereNumero(ArvAVL *raiz){
	int x=0,y=0,z=0,aux=0,aux2=0,aux3=0;
    srand((unsigned)time(NULL));
	
	while(aux == 0 || aux == NULL){
		x = 900000000 + ( rand() % 999999999 );
		//o aux faz a busca se o numero já existe
		aux = busca_compara(raiz,x);
		if(aux == 0){
			printf("\n Numero livre: %d\n",x);
			aux = 1;
		}
		
	}
	sleep(1);
	while(aux2 == 0 || aux2 == NULL && x != y){
		y = 900000000 + ( rand() % 999999999 );
		//o aux faz a busca se o numero já existe
		aux2 = busca_compara(raiz,x);
		if(aux2 == 0 && x != y ){
			printf("\n Numero livre: %d\n",y);
			aux2 = 1;
		}
	}
	sleep(1);
	while(aux3 == 0 || aux3 == NULL ){
		z = 900000000 + ( rand() % 999999999 );
		//o aux faz a busca se o numero já existe
		aux3 = busca_compara(raiz,x);
		if(aux3 == 0){
			printf("\n Numero livre: %d\n",z);
			aux3 = 1;
		}
		
	}
	
	printf("\n==========================\n\n");
};



//funcao responsavel pelo cadastro de usuarios dentro da arvore
void cadastra(Hash *tabela){
	struct no al, z[100];
	struct pessoa ka[1];
	int continua = 0,aux=0,numComf=2;
	int ddd, numero,res;
	char nome[50], endereco[50];
	
	//printf("%d\n",tabela);
	
	//menu se insercao de dados
	while(continua==0){
		printf("!!!Para voltar ao menu anterior digite 0 na escolha do DDD\n");
		printf("\nInsira o DDD(Maximo de 2 digitos):\n");
		scanf("%d",&ddd);
		
		//parando o while dessa funcao e voltando para o menu da funcao main
		if(ddd==0){
			continua=1;
			system("cls");
			return;
		}
			
		
		aux = buscaHash_SemColisao(tabela, ddd, &al);	
		
			//cria a arvore avl do ddd na tabela hash caso ela não exista
			if(aux == NULL){
			z[0].ddd=ddd;	
			z[0].endereco=cria_ArvAVL();
			insereHash_SemColisao(tabela,z[0]);	
			}
			
		//Busca_e_printa(tabela, ddd, &al);
		
		buscaHash_SemColisao(tabela, ddd, &al);
		//printa o valor e o endereco buscado na tabela hash
		//printf("%d %p\n",al.ddd,al.endereco);

		printf("\nInsira o numero de telefone a ser cadastrado(Somente 9 digitos):\n");
		scanf("%d%*c",&ka[0].numero);
		
		//busca o numero de telefone na arvore, caso ja exista, ele volta para o menu principal
		numComf = busca_numeroDuplicado(al.endereco,ka[0].numero);
		if(numComf == 1){
			continua=1;
			system("cls");
			printf("\n===================================================\nO numero ja esta sendo usado por um outro usuario.\n===================================================\n\n");
			return;
		} 
		
		printf("\nNome do usuario a ser cadastrado(No maximo 50 caracteres):\n");	
		fgets(ka[0].nome,50,stdin);
		
		
		printf("\nEndereco do usuario(No maximo 50 caracteres):\n");
		fgets(ka[0].endereco,50,stdin);
		
		//insere toda a struct "KA" na arvore avl
		insere_ArvAVL(al.endereco,ka[0]);
		system("cls");		
	}
	
}

//Estoque supermercado Python
//Autor: Arthur Bernardo do Nascimento
//Data: 24/06/2024
//OBS: Poderia ter sido utilizado um #define para criar coma constante com o numero de produntos ex: #define PDS 6
#include<stdio.h>
//Estrutura homogenia 
typedef struct{
	char nome [12];
	float preco;
	int codigo, quantidade;
}Produto;
//Prototipo funções e procedimentos
void impressao(Produto produtos []);
float estoque(Produto produtos []);
void ierro();
void retirada(Produto produtos []);
//Função main
int main(){
	int menu;
	menu = 0;
	Produto produtos [6] = {"Chocolate", 15.99, 1, 6,// Inicialização de estrutura de dados
							"Arroz", 23.95, 2, 22,
							"Feijao", 24.55, 3, 19,
							"Cereal", 12.79, 4, 15,
							"Leite", 7.99, 5, 4,
							"Pao", 8.95, 6, 32,	
							};
	printf("\t*** Sistema supermercado Java ***\n");
	while(menu != 5){// Menu
		printf("\n\t\tMENU\n[1] Listagem dos produtos e seus dados\n[2] Listagem dos produtos e valor de estoque\n[3] Cadastrar novo produto\n[4] Realizar um pedido (venda)\n[5] Sair\nEscolha uma opcao: ");
		scanf("%d", &menu);
		switch(menu){
			case(1):
				impressao(produtos);
				break;
			case(2):
				estoque(produtos);
				break;
			case(3):
				ierro();
				break;
			case(4):
				retirada(produtos);
				break;
			case(5):
				break;
			default:
				printf("\nSelecione uma opcao valida!\n");
				break;
		}
	}
	printf("\n\nTaquion Tecnology - 2024");
	return 0;
}
//Procedimento impressão
void impressao(Produto produtos []){
	int i;
	for(i = 0; i <= 5; i++){
		printf("\nProduto: %s - Valor: R$ %.2f - Codigo: %d - Quantidade: %d\n", produtos[i].nome, produtos[i].preco, produtos[i].codigo, produtos[i].quantidade);
	}
}
//Função estoque
float estoque(Produto produtos []){
	int i;
	float v;
	for(i = 0; i <= 5; i++){
		printf("\nProduto: %s - Valor em estoque: %.2f\n", produtos[i].nome, produtos[i].preco * produtos[i].quantidade);
		v = v + produtos[i].preco * produtos[i].quantidade;
	}
	printf("\n Valor total em estoque: %.2f\n", v);
	return v;
}
//Procedimento erro na opção 3
void ierro(){
	printf("\nOpcao nao disponivel!\n");
}
//Procedimento retirada
void retirada(Produto produtos []){
	int i, cod, qnt, er;
	er = 6;
	printf("Digite o codigo do produto: ");
	scanf("%d", &cod);
	printf("Digite a quantidade desejada: ");
	scanf("%d", &qnt);
	
	for(i = 0; i <= 5; i++){
		if(produtos[i].codigo == cod){
			if(produtos[i].quantidade >= qnt){
				printf("\nProduto: %s", produtos[i].nome);
				printf("\nQuantidade atual: %d", produtos[i].quantidade);
				produtos[i].quantidade = produtos[i].quantidade - qnt;
				printf("\nQuantidade nova: %d\n", produtos[i].quantidade);
			}
			else{
				printf("\nQuantidade inserida maior que estoque!\n");
			}
		}
		else{
			er = er - 1;
			if(er == 0){
				printf("\nO produto nao existe!\n");
			}
		}
	}
}





#include<stdio.h>
#define NY 3231.00
#define LONDRES 3789.00
#define DUBAI 4932.00
#define TAXA 113.04

main(){	
	char opcao, trecho;
	int destino, pessoas, aux=0;
	float custo_taxas=0, custo_passagem=0, custo_total=0;
	do{
		// menu principal
		printf("\n 1 - Destinos");
		printf("\n 2 - Custos");
		printf("\n S - Sair  ==> ");
		fflush(stdin); // limpeza da entrada padrão de string ou char ex: usar antes de scanf com %c ou gets
		scanf("%c", &opcao);
		switch(opcao){
			case '1':
				// menu destino
				do{
					printf("\n 1 - NY");
					printf("\n 2 - LONDRES");
					printf("\n 3 - DUBAI  ==> ");
					scanf("%i", &destino);	
					if(destino < 1 || destino > 3){
						printf("\n\t ==> ERRO NA ESCOLHA!");
					}
				}while(destino < 1 || destino > 3);
				do{
					printf("\nInforme a quantidade de pessoas: ");
					scanf("%i", &pessoas);
					if(pessoas <= 0){
						printf("\n\t ==> Numero invalido!");	
					} 
				}while(pessoas <= 0);
				do{
					printf("\nInforme o trecho: I - ida, V - volta, A - Ambos ");
					fflush(stdin);
					scanf("%c", &trecho);
					if(trecho != 'I' && trecho != 'V' && trecho != 'A' ){
						printf("\n\t ==> Opção invalida!");	
					} 
				}while(trecho != 'I' && trecho != 'V' && trecho != 'A' );
				
				
			break;
			case '2':
				printf("Opcao escolhida: Custos\n");
				if(trecho == 'A'){
					custo_taxas = pessoas*TAXA*2;
					aux=2;
				}else{
					custo_taxas = pessoas*TAXA;
					aux=1;	
				} 
				
				if(destino == 1){
					printf("DESTINO ESCOLHIDO ==> New York\n");
					printf("QUANTIDADE DE PESSOAS ==> %i\n", pessoas);
					custo_passagem = NY*pessoas*aux;
					printf("CUSTO DAS PASSAGENS ==> R$%.2f\n", custo_passagem);
					printf("CUSTO DAS TAXAS ==> R$%.2f\n", custo_taxas);
					custo_total = custo_passagem+custo_taxas;
					printf("CUSTO TOTAL ==> R$%.2f\n",custo_total);
				}else{
					if(destino == 2){
						printf("DESTINO ESCOLHIDO ==> Londres\n");
						printf("QUANTIDADE DE PESSOAS ==> %i\n", pessoas);
						custo_passagem = LONDRES*pessoas*aux;
						printf("CUSTO DAS PASSAGENS ==> R$%.2f\n", custo_passagem);
						printf("CUSTO DAS TAXAS ==> R$%.2f\n", custo_taxas);
						custo_total = custo_passagem+custo_taxas;
						printf("CUSTO TOTAL ==> R$%.2f\n", custo_total);	
					}else{
						printf("DESTINO ESCOLHIDO ==> Dubai\n");
						printf("QUANTIDADE DE PESSOAS ==> %i\n", pessoas);
						custo_passagem = DUBAI*pessoas*aux;
						printf("CUSTO DAS PASSAGENS ==> R$%.2f\n", custo_passagem);
						printf("CUSTO DAS TAXAS ==> R$%.2f\n", custo_taxas);
						custo_total = custo_passagem+custo_taxas;
						printf("CUSTO TOTAL ==> R$%.2f\n", custo_total);	
					}
				}
			break;
			case 'S':
				printf("Opcao escolhida: Sair");
			break;
			default: printf("\n ===> Opcao invalida!");	
		}	
	}while(opcao != 'S');
}


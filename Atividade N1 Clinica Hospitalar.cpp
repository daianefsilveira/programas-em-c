//Trabalho realizado por: Daiane Fragoso, Marcos Rutkoski, Henrique Martins e Huerta Araújo

#include<stdio.h>
#include<locale.h>

//Essa etapa evita a criação de variavéis, serve para simplificar!!
#define INTERNACAO 320.50 
#define INTERNACAO 320.50
#define CAFE 18.00
#define REFEICAO 23.50
#define ECOGRAFIA 163.00
#define RESSONANCIA 250.40

//Start do código
main(){
	setlocale(LC_ALL,"Portuguese"); //Permitir saída de dados na língua de sua preferência

//Definição de variavéis
int opcao, leito, dias, qtEco, qtRess, qtQuimio, horas;
float total=0, quimioterapia=0;
		
do{
	printf("\n    == Menu =="); 
	printf("\n===================");
	printf("\n1 - Diárias");
	printf("\n2 - Procedimentos");
	printf("\n3 - Relatório");
	printf("\n0 - Sair");
	printf("\n===================\n");
	printf("\n ==> ");
	scanf("%i", &opcao); 
		switch(opcao){ //Escolha de opções
			case 1: printf("\n   == Diárias =="); //Caso diárias
			total=0; qtEco=0; qtRess=0; qtQuimio=0; horas=0; dias=0;
				do{ 
			        printf("\n============================================");
					printf("\nInforme o número do leito: ");
					scanf("%i", &leito);
					printf("\nInforme o número de dias de internação: ");
					scanf("%i", &dias);
					printf("============================================\n");
						if ((leito <= 0) || (dias <= 0)) { //Laço de repetição caso o usuário digite um dado errado!
							printf("\n==> Dados inválidos! Tente novamente!\n");
						} else {
							printf("\nDados lançados com sucesso!\n");
						} 
					} while ((leito <= 0) || (dias <= 0));					
			break;			
			case 2: printf("\n == Procedimentos =="); //Caso procedimentos, outro menu
				do{ 
				    printf("\n=======================");
					printf("\n1 - Ecografia");
					printf("\n2 - Ressonância");
					printf("\n3 - Quimioterapia");
					printf("\n=======================\n");
					printf("\n ==> ");					
					scanf("%i", &opcao);
						if ((opcao < 1) || (opcao > 3)) {
	                    	printf("\n==> Opção inexistente! Por favor, selecione a opção correta: ");                    
	                	} 
					} while	((opcao < 1) || (opcao > 3));									               		                	
					switch(opcao){               		
        			case 1: 
					do{									
						printf("\nInforme a quantidade de ecografia(s): ");
						scanf("%i", &qtEco);
							if (qtEco <= 0) { //Laço de repetição caso o usuário digite um dado errado!
								printf("\n==> Quantidade incorreta, digite novamente: ");
							} 
					} while (qtEco <= 0);	
					break;  										  					
					case 2: 
					do{										
						printf("\nInforme a quantidade de ressonância(s): ");
						scanf("%i", &qtRess);
							if (qtRess <= 0) { //Laço de repetição caso o usuário digite um dado errado!
								printf("\n==> Quantidade incorreta, digite novamente: ");
							}	
					} while (qtRess <= 0);
					break;															
					case 3: 
					do{					
						printf("\nInforme a quantidade de quimioterapia(s): ");	
						scanf("%i", &qtQuimio);
							if (qtQuimio <= 0) { //Laço de repetição caso o usuário digite um dado errado!
								printf("\n==> Quantidade incorreta, digite novamente: ");
							} 
					} while (qtQuimio <= 0);					
					do{						
						printf("\nInforme a quantidade de horas: ");
						scanf("%i", &horas);
							if (horas <= 0) { //Laço de repetição caso o usuário digite um dado errado!
								printf("\n==> Informe uma hora válida: ");
							} 
					} while (horas <= 0);									
					break; 
					}																			                              
			break;			
			case 3: 
			if (horas <= 3) { //Condição que é executada de acordo com as horas que o usuário digitar
				quimioterapia=54.00;
			} else {
				quimioterapia=164.00;
			}										
					printf("\n\t              == Relatório =="); //Caso relatório, essa interface é apresentada
					printf("\n=====================================================================");
					printf("\nLEITO NÚMERO %i\n", leito);
					printf("\nQt  |      Serviços      |  Valor Unitário  |  Valor Contratado ");
					printf("\n%-3i |Diárias de Hotelaria|  R$%-6.2f        |       R$%-8.2f ",dias,INTERNACAO,dias*INTERNACAO);
					printf("\n%-3i |Café(s)             |  R$%-6.2f        |       R$%-8.2f ",dias*2,CAFE,dias*2*CAFE);
					printf("\n%-3i |Refeições(s)        |  R$%-6.2f        |       R$%-8.2f ",dias*2,REFEICAO,dias*2*REFEICAO);
					printf("\n%-3i |Ecografia           |  R$%-6.2f        |       R$%-8.2f ",qtEco,ECOGRAFIA,qtEco*ECOGRAFIA);
					printf("\n%-3i |Ressonância         |  R$%-6.2f        |       R$%-8.2f ",qtRess,RESSONANCIA,qtRess*RESSONANCIA);
					printf("\n%-3i |Quimioterapia       |  R$%-6.2f        |       R$%-8.2f ",qtQuimio,quimioterapia,qtQuimio*quimioterapia);
					total = (dias*INTERNACAO)+(dias*2*CAFE)+(dias*2*REFEICAO)+(qtEco*ECOGRAFIA)+(qtRess*RESSONANCIA)+(qtQuimio*quimioterapia);
					printf("\n                                              Total:R$%.2f ", total);
					printf("\n=====================================================================\n");
			break;
			case 0: printf("\nVocê optou por sair!\n"); //Caso o usuário deseje sair
			break;			
			default: printf("\n\t==> Opção inválida! Tente novamente!\n"); //Caso o usuário digite uma opção diferente de 1, 2, 3 ou 0 
		}
	}while(opcao != 0); //Laço de repetição encerrado quando o usúario optar por sair
}

//Trabalho realizado por: Daiane Fragoso, Marcos Rutkoski, Henrique Martins e Huerta Ara�jo

#include<stdio.h>
#include<locale.h>

//Essa etapa evita a cria��o de variav�is, serve para simplificar!!
#define INTERNACAO 320.50 
#define INTERNACAO 320.50
#define CAFE 18.00
#define REFEICAO 23.50
#define ECOGRAFIA 163.00
#define RESSONANCIA 250.40

//Start do c�digo
main(){
	setlocale(LC_ALL,"Portuguese"); //Permitir sa�da de dados na l�ngua de sua prefer�ncia

//Defini��o de variav�is
int opcao, leito, dias, qtEco, qtRess, qtQuimio, horas;
float total=0, quimioterapia=0;
		
do{
	printf("\n    == Menu =="); 
	printf("\n===================");
	printf("\n1 - Di�rias");
	printf("\n2 - Procedimentos");
	printf("\n3 - Relat�rio");
	printf("\n0 - Sair");
	printf("\n===================\n");
	printf("\n ==> ");
	scanf("%i", &opcao); 
		switch(opcao){ //Escolha de op��es
			case 1: printf("\n   == Di�rias =="); //Caso di�rias
			total=0; qtEco=0; qtRess=0; qtQuimio=0; horas=0; dias=0;
				do{ 
			        printf("\n============================================");
					printf("\nInforme o n�mero do leito: ");
					scanf("%i", &leito);
					printf("\nInforme o n�mero de dias de interna��o: ");
					scanf("%i", &dias);
					printf("============================================\n");
						if ((leito <= 0) || (dias <= 0)) { //La�o de repeti��o caso o usu�rio digite um dado errado!
							printf("\n==> Dados inv�lidos! Tente novamente!\n");
						} else {
							printf("\nDados lan�ados com sucesso!\n");
						} 
					} while ((leito <= 0) || (dias <= 0));					
			break;			
			case 2: printf("\n == Procedimentos =="); //Caso procedimentos, outro menu
				do{ 
				    printf("\n=======================");
					printf("\n1 - Ecografia");
					printf("\n2 - Resson�ncia");
					printf("\n3 - Quimioterapia");
					printf("\n=======================\n");
					printf("\n ==> ");					
					scanf("%i", &opcao);
						if ((opcao < 1) || (opcao > 3)) {
	                    	printf("\n==> Op��o inexistente! Por favor, selecione a op��o correta: ");                    
	                	} 
					} while	((opcao < 1) || (opcao > 3));									               		                	
					switch(opcao){               		
        			case 1: 
					do{									
						printf("\nInforme a quantidade de ecografia(s): ");
						scanf("%i", &qtEco);
							if (qtEco <= 0) { //La�o de repeti��o caso o usu�rio digite um dado errado!
								printf("\n==> Quantidade incorreta, digite novamente: ");
							} 
					} while (qtEco <= 0);	
					break;  										  					
					case 2: 
					do{										
						printf("\nInforme a quantidade de resson�ncia(s): ");
						scanf("%i", &qtRess);
							if (qtRess <= 0) { //La�o de repeti��o caso o usu�rio digite um dado errado!
								printf("\n==> Quantidade incorreta, digite novamente: ");
							}	
					} while (qtRess <= 0);
					break;															
					case 3: 
					do{					
						printf("\nInforme a quantidade de quimioterapia(s): ");	
						scanf("%i", &qtQuimio);
							if (qtQuimio <= 0) { //La�o de repeti��o caso o usu�rio digite um dado errado!
								printf("\n==> Quantidade incorreta, digite novamente: ");
							} 
					} while (qtQuimio <= 0);					
					do{						
						printf("\nInforme a quantidade de horas: ");
						scanf("%i", &horas);
							if (horas <= 0) { //La�o de repeti��o caso o usu�rio digite um dado errado!
								printf("\n==> Informe uma hora v�lida: ");
							} 
					} while (horas <= 0);									
					break; 
					}																			                              
			break;			
			case 3: 
			if (horas <= 3) { //Condi��o que � executada de acordo com as horas que o usu�rio digitar
				quimioterapia=54.00;
			} else {
				quimioterapia=164.00;
			}										
					printf("\n\t              == Relat�rio =="); //Caso relat�rio, essa interface � apresentada
					printf("\n=====================================================================");
					printf("\nLEITO N�MERO %i\n", leito);
					printf("\nQt  |      Servi�os      |  Valor Unit�rio  |  Valor Contratado ");
					printf("\n%-3i |Di�rias de Hotelaria|  R$%-6.2f        |       R$%-8.2f ",dias,INTERNACAO,dias*INTERNACAO);
					printf("\n%-3i |Caf�(s)             |  R$%-6.2f        |       R$%-8.2f ",dias*2,CAFE,dias*2*CAFE);
					printf("\n%-3i |Refei��es(s)        |  R$%-6.2f        |       R$%-8.2f ",dias*2,REFEICAO,dias*2*REFEICAO);
					printf("\n%-3i |Ecografia           |  R$%-6.2f        |       R$%-8.2f ",qtEco,ECOGRAFIA,qtEco*ECOGRAFIA);
					printf("\n%-3i |Resson�ncia         |  R$%-6.2f        |       R$%-8.2f ",qtRess,RESSONANCIA,qtRess*RESSONANCIA);
					printf("\n%-3i |Quimioterapia       |  R$%-6.2f        |       R$%-8.2f ",qtQuimio,quimioterapia,qtQuimio*quimioterapia);
					total = (dias*INTERNACAO)+(dias*2*CAFE)+(dias*2*REFEICAO)+(qtEco*ECOGRAFIA)+(qtRess*RESSONANCIA)+(qtQuimio*quimioterapia);
					printf("\n                                              Total:R$%.2f ", total);
					printf("\n=====================================================================\n");
			break;
			case 0: printf("\nVoc� optou por sair!\n"); //Caso o usu�rio deseje sair
			break;			
			default: printf("\n\t==> Op��o inv�lida! Tente novamente!\n"); //Caso o usu�rio digite uma op��o diferente de 1, 2, 3 ou 0 
		}
	}while(opcao != 0); //La�o de repeti��o encerrado quando o us�ario optar por sair
}

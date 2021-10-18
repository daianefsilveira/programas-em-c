//Trabalho realizado por: Daiane Fragoso da Silveira

#include<stdio.h>
#include<locale.h>

#define SALDO_INICIAL 1000.00

//Start do código
main(){
	setlocale(LC_ALL,"Portuguese"); 
		
//Definição de variavéis
char banco[20], nome[20];
int opcao, numAgencia, numConta;
float saldo, valorDep=0, valorSaq=0;

do{
	printf("*** Seja Bem-vindo(a)! ***\n"); 
	while(opcao != 5){ // menu
		printf("\n1 - Criar conta");
		printf("\n2 - Depositar");
		printf("\n3 - Sacar");
		printf("\n4 - Saldo");
		printf("\n5 - Sair\n==> ");
		scanf("%i", &opcao); 
		switch(opcao){ //Escolha de opções
			case 1: printf("\n*** Criar conta ***"); //opção 1 do menu
				printf("\nInforme o nome do banco: ");
				fflush(stdin); 
				gets(banco);
				printf("Informe o nome do correntista: ");
				fflush(stdin); 
				gets(nome);
				do{
					printf("Informe o número da agência com 4 digitos: ");
					scanf("%i", &numAgencia);
					printf("Informe o número da conta com 6 digitos: ");
					scanf("%i", &numConta);
						if((numAgencia <= 0) || (numConta <= 0)){ // caso o usuário digite menor ou igual a zero
							printf("\n==> Dados inválidos! Tente novamente!\n");
						}else{
							printf("\nDados lançados com sucesso!\n");
						} 
					}while((numAgencia <= 0) || (numConta <= 0)); // enquanto os dados forem menor ou igual a zero a operação repete	
				saldo=SALDO_INICIAL;
				printf("Saldo Inicial de R$ %.2f\n", saldo);			
			break;			
			case 2: printf("\n*** Depositar ***"); //opção 2 do menu
				do{ 
					printf("\nInforme um valor para depósito: ");
					scanf("%f", &valorDep);
						if(valorDep <= 0){ // caso seja informado um valor menor ou igual a zero
                    		printf("\n==> Valor inválido! Tente novamente!\n");                    
                		}else{
                			saldo+=valorDep; // saldo recebe valor do depósito e realiza a operação
							printf("\nDepósito realizado com sucesso!\n");
						}
					}while(valorDep <= 0); // enquanto o valor menor ou igual a zero a operação repete						               		
            break;			
			case 3: printf("\n*** Sacar ***"); // opção 3 do menu
				do{				
					printf("\nInforme um valor para saque: ");
					scanf("%f", &valorSaq);			
						if(valorSaq <= 0){ // caso seja informado um valor menor ou igual a zero
                    		printf("\n==> Valor inválido! Tente novamente!\n"); 
						}else if (saldo < valorSaq){ // caso valor do saque menor que saldo
                    		printf("\n==> Saldo insuficiente para saque! Tente novamente!\n");                    
                		}else{
                			saldo-=valorSaq; // saldo recebe valor do saque e realiza a operação
							printf("\nSaque realizado com sucesso!\n");
						}
					}while((valorSaq <= 0) || (saldo < valorSaq )); // enquanto o valor menor ou igual a zero e suficiente para saque a operação repete													
			break;
			case 4: printf("\n*** Saldo ***"); // opção 4 do menu
					printf("\nBanco: %s", banco);
					printf("\nCorrentista: %s", nome);
					printf("\nAgência: %i Conta: %i", numAgencia,numConta);
					printf("\nSaldo: R$ %.2f\n", saldo);								 
			break;			
			case 5: printf("\n*** Sair ***"); // opção 5 do menu
					printf("\nVocê optou por sair!\n"); // caso o usuário deseje sair
			break;			
			default: printf("\n==> Opção inválida! Tente novamente!\n"); // caso o usuário digite uma opção diferente de 1, 2, 3, 4 ou 5 
		}
	}
	}while(opcao!=5); // enquanto a opção for diferente de opção 5 sair os operações do menu são realizadas
}




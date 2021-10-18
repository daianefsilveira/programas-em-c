#include<stdio.h>
#include<locale.h>

int main(){
	setlocale(LC_ALL,"Portuguese");
		
int elevador=0, pessoas=0, andares=0;

printf("Quantos andares tem o edifício? ");
scanf("%i", &andares);
for(int i = 1; i <= andares; i++){
	printf("**Estamos no andar %i \n", i);
		if(i >= 2){	// pessoas começarão a descer somente a partir do 2º andar	
			do{ 
				printf("Quantas pessoas saíram neste andar %i? ", i);
				scanf("%i", &pessoas);
				while(pessoas < 0){ // garante que a pessoa não digite valor negativo
			    	printf("Você digitou um valor negativo! Por favor, repita ");
					scanf("%i", &pessoas);
				}
					if((elevador - pessoas) < 0){ // verifica se irá descer mais pessoas do que possui o elevador
						printf("Impossível, pois o elevador possui %i pessoas ", elevador);
					}else{ // retira pessoas do elevador
						elevador -= pessoas;
						pessoas = 0; // reseta a variável pessoas afim de operação do while
					}
		    }while((elevador - pessoas) < 0); // garante a validação positiva do elevador
		}
		printf("Quantas pessoas entraram neste andar %i? ", i);
		scanf("%i", &pessoas);
		while(pessoas < 0){ // garante que a pessoa não digite valor negativo
			printf("Você digitou um valor negativo! Por favor, repita ");
			scanf("%i", &pessoas);
		}		
			if((elevador + pessoas) > 15){ // verifica a capacidade de pessoas no elevador
				printf("Impossível, pois excede a capacidade máxima de pessoas no elevador que é 15 \n"); // no caso de exceder a capacidade
				printf("Devem descer %i \n",(pessoas + elevador - 15));	// informa quantas pessoas devem descer pra respeitar o limite de capacidade 
				elevador = 15;					
			}else{ // coloca pessoas no elevador
				elevador += pessoas;
			}
}
printf("No último andar desceram %i pessoas", elevador); // mostra quantas pessoas irão descer
}

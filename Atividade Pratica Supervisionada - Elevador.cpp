#include<stdio.h>
#include<locale.h>

int main(){
	setlocale(LC_ALL,"Portuguese");
		
int elevador=0, pessoas=0, andares=0;

printf("Quantos andares tem o edif�cio? ");
scanf("%i", &andares);
for(int i = 1; i <= andares; i++){
	printf("**Estamos no andar %i \n", i);
		if(i >= 2){	// pessoas come�ar�o a descer somente a partir do 2� andar	
			do{ 
				printf("Quantas pessoas sa�ram neste andar %i? ", i);
				scanf("%i", &pessoas);
				while(pessoas < 0){ // garante que a pessoa n�o digite valor negativo
			    	printf("Voc� digitou um valor negativo! Por favor, repita ");
					scanf("%i", &pessoas);
				}
					if((elevador - pessoas) < 0){ // verifica se ir� descer mais pessoas do que possui o elevador
						printf("Imposs�vel, pois o elevador possui %i pessoas ", elevador);
					}else{ // retira pessoas do elevador
						elevador -= pessoas;
						pessoas = 0; // reseta a vari�vel pessoas afim de opera��o do while
					}
		    }while((elevador - pessoas) < 0); // garante a valida��o positiva do elevador
		}
		printf("Quantas pessoas entraram neste andar %i? ", i);
		scanf("%i", &pessoas);
		while(pessoas < 0){ // garante que a pessoa n�o digite valor negativo
			printf("Voc� digitou um valor negativo! Por favor, repita ");
			scanf("%i", &pessoas);
		}		
			if((elevador + pessoas) > 15){ // verifica a capacidade de pessoas no elevador
				printf("Imposs�vel, pois excede a capacidade m�xima de pessoas no elevador que � 15 \n"); // no caso de exceder a capacidade
				printf("Devem descer %i \n",(pessoas + elevador - 15));	// informa quantas pessoas devem descer pra respeitar o limite de capacidade 
				elevador = 15;					
			}else{ // coloca pessoas no elevador
				elevador += pessoas;
			}
}
printf("No �ltimo andar desceram %i pessoas", elevador); // mostra quantas pessoas ir�o descer
}

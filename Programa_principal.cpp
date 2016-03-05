#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include "Topos.h"

#define QTDECORRENTISTA 10

struct Tipo_Endereco{
	char strRua[50];
	int  intNum;
	char strBairro[30];
	char strCidade[30];
	char strEstado[3];
};

struct Tipo_ContaCorrente{
	int intContaCorrente;
	char strNome[50];
	struct Tipo_Endereco stcEndereco;
	char strMail[50];
};

//STRUCT INICIALIZADOS
struct Tipo_ContaCorrente cadConta[QTDECORRENTISTA]=
	{{111,"Carlos da Silva", {"R.Mal.Deodoro",321,"Centro","Curitiba","PR"},"carlos@Gmail.com"},
	{222,"Marcos da Silva", {"R.Vic.Machado",333,"Batel","Curitiba","PR"},"marcos@gmail.com"}};	

//struct Tipo_ContaCorrente cadConta[QTDECORRENTISTA];
int cadastrarContaCorrente(int intQtdContasCadastradas);
int listarContaCorrente(int intQtdContasCadastradas);
int excluirContaCorrente(int intQtdContasCadastradas);

int main (){
	
	setlocale(LC_ALL,"");
	
	int iCond = 1, intNumContasCadastradas = 2;
	char aux;
	
	while(iCond != 4){
		
		system("cls");
		menu();
		scanf("%d",&iCond);
		switch(iCond){
			case 1:
				intNumContasCadastradas = cadastrarContaCorrente(intNumContasCadastradas);
				break;
			case 2:
				listarContaCorrente(intNumContasCadastradas);
				printf("\n==>DIGITE QUALQUER TECLA PARA CONTINUAR. \n");
				aux = getch();
				break;
			case 3:
				intNumContasCadastradas = excluirContaCorrente(intNumContasCadastradas);
				
				break;
			case 4:
				break;
			default:
				printf("\n==>OP��O INV�LIDA. ");
				printf("\n==>DIGITE QUALQUER TECLA PARA CONTINUAR. \n");
				aux = getch();
		}
	}
	
	system("pause");
	return 0;
}

//FUN��O CADASTRAR CONTA CORRENTE**********************************
int cadastrarContaCorrente(int intQtdContasCadastradas){
	
	int i = 0, encontrou = 0;
	char aux = 0;
	
	topo_cadastrar();	
	printf("\n==>Informe o Numero da nova conta: ");
	fflush(stdin);
	scanf("%d",&cadConta[intQtdContasCadastradas].intContaCorrente);

	while(cadConta[intQtdContasCadastradas].intContaCorrente != 0){
		
		if(cadConta[intQtdContasCadastradas].intContaCorrente < 100){
				printf("\n==>N�MERO DE CONTA INV�LIDA. ");
				printf("\n==>O N�MERO DA CONTA DEVE SER SUPERIOR A 100. \n");
		}
		else{
			encontrou = 0;
			for(i = 0; i < intQtdContasCadastradas; i++){
				
				if(cadConta[intQtdContasCadastradas].intContaCorrente == cadConta[i].intContaCorrente){
						printf("\nESTE N�MERO J� EST� CADASTRADO. ");
						printf("\nENTRE COM OUTRO N�MERO. \n");
						encontrou = 1;
						i = intQtdContasCadastradas;
				}
				
			}
			
			if(!encontrou){
				printf("Informe o nome do correntista: ");
				fflush(stdin);
				gets(cadConta[intQtdContasCadastradas].strNome);

				printf("Endere�o-Informe a rua: ");
				fflush(stdin);
				gets(cadConta[intQtdContasCadastradas].stcEndereco.strRua);
		
				printf("Endere�o-Informe o n�mero: ");
				fflush(stdin);
				scanf("%d",&cadConta[intQtdContasCadastradas].stcEndereco.intNum);
			
				printf("Endere�o-Informe o bairro: ");
		 	    fflush(stdin);
				gets(cadConta[intQtdContasCadastradas].stcEndereco.strBairro);
		
				printf("Endere�o-Informe a cidade: ");
				fflush(stdin);
				gets(cadConta[intQtdContasCadastradas].stcEndereco.strCidade);
		
			    printf("Endere�o-Informe o estado: ");
			    fflush(stdin);
		    	gets(cadConta[intQtdContasCadastradas].stcEndereco.strEstado);
				
			    printf("Informe o e-mail: ");
			    fflush(stdin);
				gets(cadConta[intQtdContasCadastradas].strMail);
				
				printf("\nConta cadastrada. \n");
				
				intQtdContasCadastradas++;
				//printf("\nintQtdContasCadastradas: %d ",intQtdContasCadastradas);			
			}	
		}//if < 100				
		printf("\n==>Informe o Numero da nova conta: ");
		fflush(stdin);
		scanf("%d",&cadConta[intQtdContasCadastradas].intContaCorrente);
	}//while != 0

	return intQtdContasCadastradas;
}

//FUN��O LISTAR CONTA CORRENTE*************************** 
int listarContaCorrente(int intQtdContasCadastradas){
	
	char aux;
	int i = 0;
	
	topo_listar();
	
	if(intQtdContasCadastradas > 0){
		
		listarContaCorrente(intQtdContasCadastradas - 1);
		
	    printf("\n==>Numero Conta Corrente %d ", cadConta[intQtdContasCadastradas - 1].intContaCorrente);
		printf("\nNome do correntista %s ", cadConta[intQtdContasCadastradas - 1].strNome);
		printf("\nEndere�o-Rua %s ", cadConta[intQtdContasCadastradas - 1].stcEndereco.strRua);
		printf("\nEndere�o-Numero %d", cadConta[intQtdContasCadastradas - 1].stcEndereco.intNum);
		printf("\nEndere�o-Bairro %s ", cadConta[intQtdContasCadastradas - 1].stcEndereco.strBairro);
		printf("\nEndere�o-Cidade %s ", cadConta[intQtdContasCadastradas - 1].stcEndereco.strCidade);
		printf("\nEndere�o-Estado %s ", cadConta[intQtdContasCadastradas - 1].stcEndereco.strEstado);
		printf("\nE-mail do correntista %s \n", cadConta[intQtdContasCadastradas - 1].strMail);
	}
	
	return intQtdContasCadastradas;

}

//FUN��O EXCLUIR CINTA CORRENTE*****************************
int excluirContaCorrente(int intQtdContasCadastradas){
	
	int i = 0, encontrou, aux = 0, contaexcluir;
	char cCond;
	
	topo_excluir();

	printf("\n==>Informe o numero da conta a ser excluida: ");
	fflush(stdin);
	scanf("%d",&contaexcluir);
	
	while(contaexcluir){
	
		encontrou=0;
		for(i = 0; i < intQtdContasCadastradas; i++){
			if(contaexcluir == cadConta[i].intContaCorrente){
				encontrou = 1;
				aux = i;
				i = intQtdContasCadastradas;
			}
		}
		
		if(encontrou){
			printf("\n==>Numero Conta Corrente %d ", cadConta[aux].intContaCorrente);
			printf("\nNome do correntista %s ", cadConta[aux].strNome);
			printf("\nEndere�o-Rua %s ", cadConta[aux].stcEndereco.strRua);
			printf("\nEndere�o-Numero %d", cadConta[aux].stcEndereco.intNum);
			printf("\nEndere�o-Bairro %s ", cadConta[aux].stcEndereco.strBairro);
			printf("\nEndere�o-Cidade %s ", cadConta[aux].stcEndereco.strCidade);
			printf("\nEndere�o-Estado %s ", cadConta[aux].stcEndereco.strEstado);
			printf("\nE-mail do correntista %s \n", cadConta[aux].strMail);
			
			printf("\nConfirme a exclus�o [S/N]: ");
			fflush(stdin);
			scanf("%c",&cCond);
			
			if( (cCond == 'S') || (cCond == 's') ){
				
				
				for( i = aux; i < intQtdContasCadastradas - 1; i++){
					cadConta[i].intContaCorrente = cadConta[i + 1].intContaCorrente;
					strcpy(cadConta[i].strNome, cadConta[i + 1].strNome);
					strcpy(cadConta[i].stcEndereco.strRua, cadConta[i + 1].stcEndereco.strRua);
					cadConta[i].stcEndereco.intNum = cadConta[i + 1].stcEndereco.intNum;
					strcpy(cadConta[i].stcEndereco.strBairro, cadConta[i + 1].stcEndereco.strBairro);
					strcpy(cadConta[i].stcEndereco.strCidade, cadConta[i + 1].stcEndereco.strCidade);
					strcpy(cadConta[i].stcEndereco.strEstado, cadConta[i + 1].stcEndereco.strEstado);
					strcpy(cadConta[i].strMail, cadConta[i + 1].strMail);
				}
				intQtdContasCadastradas--;
				
				printf("\nConta Corrente excluida - aperte qualquer tecla para continuar \n");
				fflush(stdin);
				scanf("%c",&cCond);
			}
			else{
				if( (cCond == 'N') || (cCond == 'n') ){
					printf("\nConta Corrente N�O excluida \n");	
				}
				else{
					printf("\nOp��o inv�lida.");
				}
				
			}
		}
		else{
			printf("\n==>Conta n�o encontrada no cadastro. ");
		}
		
		printf("\n==>Informe o numero da conta a ser excluida: ");
		fflush(stdin);
		scanf("%d",&contaexcluir);
	}
	return intQtdContasCadastradas;
}


#include <stdio.h> //biblioteca de cumunica��o com o usuario 
#include <stdlib.h> //biblioteca de aloca��o  de espa�o em mem�ria
#include <locale.h> //bliblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //fun��o responsavel por cadastrar os usuarios no sistema
{
	//inicio cria�ao de vari�veis / string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis / string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); // %s refere-se a string, armazena a inform��o da variavel 
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file= fopen(arquivo,"w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file= fopen(arquivo,"a"); // o "a" siginifca  abrir o arquivo,   Acrescentar informa��es do  o arquivo sem criar outro
	fprintf(file,","); // a informa��o que vai ser Acrescentada no caso uma "," uma virgula  
	fclose(file); // fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", nome); // %s refere-se a string, armazena a inform��o da variavel
	
	file=fopen(arquivo,"a"); //o "a" siginifca  abrir o arquivo,   Acrescentar informa��es do  o arquivo sem criar outro
	fprintf(file, nome);  // a informa��o que vai ser Acrescentada no caso uma "," uma virgula 
	fclose(file); // fecha o arquivo
	
	file= fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file= fopen (arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file= fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file= fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
	
	
}
int consulta()
{   
    setlocale(LC_ALL, "Portuguese"); //defenindo a linguagem 

	char cpf [40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); // "r" significa  ler o arquivo 
	
	if(file== NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado \n ");
	}
	
	while(fgets(conteudo,200,file) != NULL)
	{
		printf("\n Essas s�o as inform��es do usu�rio:");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
	
}
int deletar()
{
	 char cpf[40];
	 
	 printf("Digite o CPF do usu�rio a ser deletado: ");
	 scanf("%s",cpf);
	 
	 
	 remove(cpf);
	 
	 FILE *file;
	 file = fopen(cpf,"r");  // "r" significa  ler o arquivo
	 
	 if(file == NULL)
	 {
	 	printf("o usu�rio n�o se encontra no sistema! \n");
	 	system("pause");
	 }
}


int main()
{
	int opcao=0; //definindo vari�veis 
	int laco=1;
	
	
	for(laco=1;laco=1;)
	{
	    system("cls");
	    
	     
	     
	   setlocale(LC_ALL, "Portuguese"); //defenindo a linguagem 
	
	
	    printf("#### Cart�rio da EBAC ### \n\n"); // inicio do menu 
	    printf("Escolha a ope��o desejada do menu: \n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n");
	    printf("op��o: "); // fim do menu 
	 
         scanf("%d", &opcao); // armazemando a escolha  do usu�rio
 
              system("cls");  //responsavel por limpar a tela
              
              
              switch(opcao) // inicio da sele��o  do menu 
	     { 
	         case 1:
	         registro(); // chamada de fun��es 
	         break; 
	         
	         case 2:
	         consulta(); //chamada de fun��es
	         break;
	         
	         case 3:
	         deletar(); //chamada de fun��es
	         break;
	         
	         
	            
	            
	            
	            default: 
	            	printf("Essa ope��o n�o est� disponivel!\n");
	                system("pause");
	                break;
	            
	         
	         
	         

	    
		 }
 
      
}
}

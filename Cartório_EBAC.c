#include <stdio.h> //biblioteca de cumunicação com o usuario 
#include <stdlib.h> //biblioteca de alocação  de espaço em memória
#include <locale.h> //bliblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //função responsavel por cadastrar os usuarios no sistema
{
	//inicio criaçao de variáveis / string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis / string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); // %s refere-se a string, armazena a informção da variavel 
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file= fopen(arquivo,"w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file= fopen(arquivo,"a"); // o "a" siginifca  abrir o arquivo,   Acrescentar informações do  o arquivo sem criar outro
	fprintf(file,","); // a informação que vai ser Acrescentada no caso uma "," uma virgula  
	fclose(file); // fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", nome); // %s refere-se a string, armazena a informção da variavel
	
	file=fopen(arquivo,"a"); //o "a" siginifca  abrir o arquivo,   Acrescentar informações do  o arquivo sem criar outro
	fprintf(file, nome);  // a informação que vai ser Acrescentada no caso uma "," uma virgula 
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
		printf("Não foi possivel abrir o arquivo, não localizado \n ");
	}
	
	while(fgets(conteudo,200,file) != NULL)
	{
		printf("\n Essas são as informções do usuário:");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
	
}
int deletar()
{
	 char cpf[40];
	 
	 printf("Digite o CPF do usuário a ser deletado: ");
	 scanf("%s",cpf);
	 
	 
	 remove(cpf);
	 
	 FILE *file;
	 file = fopen(cpf,"r");  // "r" significa  ler o arquivo
	 
	 if(file == NULL)
	 {
	 	printf("o usuário não se encontra no sistema! \n");
	 	system("pause");
	 }
}


int main()
{
	int opcao=0; //definindo variáveis 
	int laco=1;
	
	
	for(laco=1;laco=1;)
	{
	    system("cls");
	    
	     
	     
	   setlocale(LC_ALL, "Portuguese"); //defenindo a linguagem 
	
	
	    printf("#### Cartório da EBAC ### \n\n"); // inicio do menu 
	    printf("Escolha a opeção desejada do menu: \n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n");
	    printf("opção: "); // fim do menu 
	 
         scanf("%d", &opcao); // armazemando a escolha  do usuário
 
              system("cls");  //responsavel por limpar a tela
              
              
              switch(opcao) // inicio da seleção  do menu 
	     { 
	         case 1:
	         registro(); // chamada de funções 
	         break; 
	         
	         case 2:
	         consulta(); //chamada de funções
	         break;
	         
	         case 3:
	         deletar(); //chamada de funções
	         break;
	         
	         
	            
	            
	            
	            default: 
	            	printf("Essa opeção não está disponivel!\n");
	                system("pause");
	                break;
	            
	         
	         
	         

	    
		 }
 
      
}
}

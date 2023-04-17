#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�os de mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string


int registro() // Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//in�cio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string
	

	printf("Digite o CPF para cadastrar: "); //coletando as informa��es do usu�rio
	scanf("%s", cpf); // %s refere-se a string
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das str
	
	FILE *file; //cria o arquivo no banco de dados
	file = fopen(arquivo, "w"); // "w" � para criar o arquivo, "w" siginifica escrever. 
	fprintf(file,cpf); // salvo o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");     //"a" � de atualizar o arquivo, n�oi inserir um novo
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	

	
	system("pause");	
}



int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //definindo novamente a linguagem pois est� em outra fun��o
	
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");  //"r" � de read para ler as informa��es 
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o foi localizado \n");
	}
	
	while(fgets(conteudo, 200, file)!= NULL) //fgets --> vai buscar dentro do arquivo, vai rodar 200x dentro do arquivo at� trazer todas as informa��es
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n\n");
	
	}
	
	system("pause");
}

int deletar()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	
	printf("Informe o CPF do usu�rio que deseja deletar: ");
	scanf("%s", cpf);

	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if (file == NULL)
	{
		printf("O usu�rio nao foi encontrado.\n");
		system("pause");
	}
	
	
}


int main() {
	int opcao=0; //separando a vari�vel que vamos utilizar
	int laco=1;


	for(laco=1; laco=1;) { //quando iguala dessa forma nunca encerra o programa


		system("cls"); //respons�vel por limpar a tela

		setlocale(LC_ALL, "Portuguese"); //escolhendo a linguagem


		printf("\tCart�rio EBAC \n\n"); //pagina principal do menu
		printf("Escolha o que deseja fazer: \n\n");
		printf("\t1 - Cadastrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n"); //fim do menu
		printf("\t4 - Sair do progama\n\n");
		printf("Op��o desejada: ");

		scanf("%d", &opcao); //armazenando o que o usu�rio esscolher

		system("cls"); //limpando a tela ap�s escolha

		switch(opcao) 
		{
			case 1:
				registro(); //chamada de fun��o
				break;
			
				
			case 2:
			    consulta(); //chamada de fun��o
			    break;

			case 3:
		     	deletar(); //chamada de fun��o
			 	break;
			 	
			case 4:
				printf("Obrigado por utilizar o sistema");
				return 0;
				break;
				
			default:  //tudo que nao for falado antes
				printf("Ecolha uma op��o v�lida\n");
				system("pause");
				break;



		}


	} //final do for
}


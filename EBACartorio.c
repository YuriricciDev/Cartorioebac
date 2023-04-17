#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaços de memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string


int registro() // Função responsável por cadastrar os usuários no sistema
{
	//início da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string
	

	printf("Digite o CPF para cadastrar: "); //coletando as informações do usuário
	scanf("%s", cpf); // %s refere-se a string
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das str
	
	FILE *file; //cria o arquivo no banco de dados
	file = fopen(arquivo, "w"); // "w" é para criar o arquivo, "w" siginifica escrever. 
	fprintf(file,cpf); // salvo o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");     //"a" é de atualizar o arquivo, nãoi inserir um novo
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
	setlocale(LC_ALL, "Portuguese"); //definindo novamente a linguagem pois está em outra função
	
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");  //"r" é de read para ler as informações 
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo, não foi localizado \n");
	}
	
	while(fgets(conteudo, 200, file)!= NULL) //fgets --> vai buscar dentro do arquivo, vai rodar 200x dentro do arquivo até trazer todas as informações
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n\n");
	
	}
	
	system("pause");
}

int deletar()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	
	printf("Informe o CPF do usuário que deseja deletar: ");
	scanf("%s", cpf);

	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if (file == NULL)
	{
		printf("O usuário nao foi encontrado.\n");
		system("pause");
	}
	
	
}


int main() {
	int opcao=0; //separando a variável que vamos utilizar
	int laco=1;


	for(laco=1; laco=1;) { //quando iguala dessa forma nunca encerra o programa


		system("cls"); //responsável por limpar a tela

		setlocale(LC_ALL, "Portuguese"); //escolhendo a linguagem


		printf("\tCartório EBAC \n\n"); //pagina principal do menu
		printf("Escolha o que deseja fazer: \n\n");
		printf("\t1 - Cadastrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n"); //fim do menu
		printf("\t4 - Sair do progama\n\n");
		printf("Opção desejada: ");

		scanf("%d", &opcao); //armazenando o que o usuário esscolher

		system("cls"); //limpando a tela após escolha

		switch(opcao) 
		{
			case 1:
				registro(); //chamada de função
				break;
			
				
			case 2:
			    consulta(); //chamada de função
			    break;

			case 3:
		     	deletar(); //chamada de função
			 	break;
			 	
			case 4:
				printf("Obrigado por utilizar o sistema");
				return 0;
				break;
				
			default:  //tudo que nao for falado antes
				printf("Ecolha uma opção válida\n");
				system("pause");
				break;



		}


	} //final do for
}


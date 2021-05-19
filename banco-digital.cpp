#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
   char agencia[10];
   char numerodaconta[10];
   float valor;
}TipoCorrente;

typedef struct{
   TipoCorrente tc;
   float salario; 
   char orgao[50];
   char cargo[40];
   int diacontratacao,mescontratacao,anocontratacao;
}TipoSalario;

typedef struct{
	TipoCorrente tc;
	int diapoupanca,mespoupanca,anopoupanca;
	float rendimentopoupanca;
}TipoPoupanca;

typedef struct{
	TipoCorrente tc;
	int matricula;
	int diamatricula,mesmatricula,anomatricula;
	int diaprevisao,mesprevisao,anoprevisao;
	char universidade[20];
	char curso[20];
}TipoUniversitario;
	typedef union{
       TipoCorrente c;
       TipoSalario s;
       TipoPoupanca p;
       TipoUniversitario u;
       }TipoConta;

typedef struct{
	char nome[20];
	char sobrenome[20];
	char endereco [50];
	char telefone[10];
	char email[20];
	char ident[5];
	char cpf[10];
	int tipocont;
	float saldo;
    TipoConta tpc;
	
}cliente;

int n=0;
cliente *a=(cliente*) malloc(sizeof(cliente)); 

void cadastro ();
void ver ();
void alterar();
void alterartipoconta();
int remover();
void escolha();
void saque();
void deposito();
void rendimento();

int main()
{
	int op;
	while(n==0)
	{
		printf("Bem vindo a plataforma digital do banco C++ \n -----Para realizar alguma operacao, eh necessario um cadastro-----\n");
		printf("Voce sera redirecionado para nossa pagina de cadastros, bom dia!!\n\n");
		system("pause");
		cadastro();
	}
	while(1)
	{
		printf("Escolha uma opcao\n");
		printf("1) cadastro \n2) visualizar cadastros\n3) alterar informacoes\n4) alterar tipo da conta\n5) remover\n6) realizar saque ou deposito\n7) calcular rendimento da conta poupanca\n8) sair\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1: cadastro();
					break;
					
			case 2: ver();
					break;
				
			case 3: alterar();
					break;
				 
			case 4: alterartipoconta();
			        break;	 
				 
			case 5: remover();
					break;
					
			case 6:	escolha();
			        break;
					
			case 7:rendimento();
			       break;		
					
			case 8: exit(1);
					break;
		}
	}
	return 0;
}
void cadastro ()
{
	system("cls");
	fflush(stdin);
	printf("Entre com o nome do cliente \n");
	fgets((a+n)->nome,20,stdin);
	fflush(stdin);
	system("cls");
	printf("Entre com o sobrenome\n");
	fgets((a+n)->sobrenome,20,stdin);
	fflush(stdin);
	system("cls");
	printf("entre com o identificador \n");
	char busc[5];
	int ap1=0,i;
	fgets(busc,5,stdin);
	            for(i=0;i<n;i++)
           {
           		if(strcmp(busc,(a+i)->ident)==0)
           		{
           			printf("---O numero ja foi cadastrado! tente novamente....---\n");
           			system("pause");
           			ap1++;
		   			cadastro();
				}
		   }
		   if(ap1==0)
		   {
		   		printf("--Identificador disponivel--\n");
				strcpy((a+n)->ident,busc);
          		fflush(stdin);
		   }
	fflush(stdin);
	system("cls");
	printf("entre com o CPF\n");
	char busc2[10];
	int ip=0;
	fgets(busc2,10,stdin);
	            for(i=0;i<n;i++)
           {
           		if(strcmp(busc2,(a+i)->cpf)==0)
           		{
           			printf("---O numero ja foi cadastrado! tente novamente....---\n");
           			system("pause");
           			ip++;
		   			cadastro();
				}
		   }
		   if(ip==0)
		   {
		   		printf("--Numero de cpf disponivel--\n");
				strcpy((a+n)->cpf,busc2);
          		fflush(stdin);
		   }
	fflush(stdin);
	system("cls");
	printf("Digite a rua do endereco do cliente: ");
    fgets((a+n)->endereco,50,stdin);
    fflush(stdin);
    system("cls");
    printf("Digite o email do cliente: ");
    fgets((a+n)->email,20,stdin);
    fflush(stdin);
    system("cls");
    printf("Digite o telefone do cliente : ");
    fgets((a+n)->telefone,10,stdin);
    fflush(stdin);
    system("cls");
    int ap=0;
    char busca[10];
       printf("\n  Tipos de conta:");
       printf("\n0.Conta Corrente;");
       printf("\n1.Conta Salario;");
       printf("\n2.Conta Poupanca;");
       printf("\n3.Conta Universitaria.");
       printf("\nDigite o numero referente ao tipo de conta do cliente: ");
       scanf("%d",&(a+n)->tipocont);
       printf("\nTipo de conta escolhida pelo cliente: %d",(a+n)->tipocont);
       fflush(stdin);
       system("cls");

    	switch ((a+n)->tipocont)
		{
           case 0:
           fflush(stdin);
           printf("\nEntre com a Agencia do cliente: ");
           fgets((a+n)->tpc.c.agencia,30,stdin);
           fflush(stdin);
            printf("\nEntre com a conta do cliente: ");
           fgets(busca,10,stdin);
            for(i=0;i<n;i++)
           {
           		if(strcmp(busca,(a+i)->tpc.c.numerodaconta)==0)
           		{
           			printf("---O numero ja foi cadastrado! tente novamente....---\n");
           			system("pause");
           			ap++;
		   			cadastro();
				}
		   }
		   if(ap==0)
		   {
		   		printf("--Numero de conta disponivel--\n");
				strcpy((a+n)->tpc.c.numerodaconta,busca);
          		fflush(stdin);
		   }
           printf(" Confimacao de dados \nNome:%s %s",(a+n)->nome,(a+n)->sobrenome);
           printf(" Identificador: %s",(a+n)->ident);
            n++;
        	printf("\n  Cadastro realizado com sucesso!\n\n\n");
           system("pause");
           a=(cliente*) realloc(a,(n+1)*sizeof(cliente));
           system("cls");
           fflush(stdin);
           break;

           case 1:
           fflush(stdin);
           printf("\nEntre com a Agencia do cliente: ");
           fgets((a+n)->tpc.s.tc.agencia,30,stdin);
           fflush(stdin);
           printf("\nEntre com a conta do cliente: ");
           fgets(busca,10,stdin);
                        for(i=0;i<n;i++)
           {
           		if(strcmp(busca,(a+i)->tpc.s.tc.numerodaconta)==0)
           		{
           			printf("---O numero ja foi cadastrado! tente novamente....---\n");
           			system("pause");
           			ap++;
		   			cadastro();
				}
		   }
		   if(ap==0)
		   {
		   		printf("--Numero de conta disponivel--\n");
				strcpy((a+n)->tpc.s.tc.numerodaconta,busca);
          		fflush(stdin);
		   }
           printf("Entre com o salario do cliente: ");
           scanf("%f",&(a+n)->tpc.s.salario);
           fflush(stdin);
           printf("Entre com o orgao do cliente: ");
           fgets((a+n)->tpc.s.orgao,50,stdin);
           fflush(stdin);
           printf("Entre com o cargo do cliente: ");
           fgets((a+n)->tpc.s.cargo,40,stdin);
           fflush(stdin);
           printf("Entre com a data da contratacao do cliente (formato dd mm aaaa): ");
           scanf("%d%d%d",&(a+n)->tpc.s.diacontratacao,&(a+n)->tpc.s.mescontratacao,&(a+n)->tpc.s.anocontratacao);
           fflush(stdin);
           printf("Confirmacao de cadastro\n");
           printf("Nome: %s\n",(a+n)->nome);
           printf("Identificador:%s\n",(a+n)->ident);
            n++;
           printf("\n  Cadastro realizado com sucesso!\n\n\n");
           system("pause");
           a=(cliente*) realloc(a,(n+1)*sizeof(cliente));
           system("cls");
           break;

           case 2:
           fflush(stdin);
           printf("\nEntre com a Agencia do cliente: ");
           fgets((a+n)->tpc.p.tc.agencia,30,stdin);
           fflush(stdin);
           printf("\nEntre com o numero da conta:");
           fgets(busca,10,stdin);
            for(i=0;i<n;i++)
           {
           		if(strcmp(busca,(a+i)->tpc.p.tc.numerodaconta)==0)
           		{
           			printf("---O numero ja foi cadastrado! tente novamente....---\n");
           			system("pause");
           			ap++;
		   			cadastro();
				}
		   }
		   if(ap==0)
		   {
		   		printf("--Numero de conta disponivel--\n");
				strcpy((a+n)->tpc.p.tc.numerodaconta,busca);
          		fflush(stdin);
		   }
           fflush(stdin);
           printf("Entre a data da poupanca realizada pelo cliente (formato dd mm aaaa): ");
           scanf("%d%d%d",&(a+n)->tpc.p.diapoupanca,&(a+n)->tpc.p.mespoupanca,&(a+n)->tpc.p.anopoupanca);
           fflush(stdin);
           printf("Entre com o rendimento da poupanca no ultimo mes: ");
           scanf("%f",&(a+n)->tpc.p.rendimentopoupanca);
           fflush(stdin);
           printf("Confirmacao de cadastro\n");
           printf("%s\n",(a+n)->nome);
           printf("%s\n",(a+n)->ident);
           printf("\n  Cadastro realizado com sucesso!\n\n\n");
           n++;
           a=(cliente*) realloc(a,(n+1)*sizeof(cliente));
           system("cls");
           break;

           case 3:
           fflush(stdin);
           printf("\nEntre com a Agencia do cliente: ");
           fgets((a+n)->tpc.u.tc.agencia,30,stdin);
           fflush(stdin);
           printf("\nEntre com a conta do cliente: ");
           fgets(busca,10,stdin);
                        for(i=0;i<n;i++)
           {
           		if(strcmp(busca,(a+i)->tpc.u.tc.numerodaconta)==0)
           		{
           			printf("---O numero ja foi cadastrado! tente novamente....---\n");
           			system("pause");
           			ap++;
		   			cadastro();
				}
		   }
		   if(ap==0)
		   {
		   		printf("--Numero de conta disponivel--\n");
				strcpy((a+n)->tpc.u.tc.numerodaconta,busca);
          		fflush(stdin);
		   }
           fflush(stdin);
           printf("Digite a matricula do cliente: ");
           scanf("%d",&(a+n)->tpc.u.matricula);
           fflush(stdin);
           printf("Entre com a data da matricula do cliente (formato dd mm aaaa): ");
           scanf("%d%d%d",&(a+n)->tpc.u.diamatricula,&(a+n)->tpc.u.mesmatricula,&(a+n)->tpc.u.anomatricula);
           fflush(stdin);
           printf("Entre com a data da previsao de conclusao do cliente (formado dd mm aaaa): ");
           scanf("%d%d%d",&(a+n)->tpc.u.diaprevisao,&(a+n)->tpc.u.mesprevisao,&(a+n)->tpc.u.anoprevisao);
           fflush(stdin);
           printf("\nEntre com o curso frequentado do cliente: ");
           fgets((a+n)->tpc.u.curso,40,stdin);
           fflush(stdin);
           printf("\nEntre com a Universidade frequentada pelo cliente: ");
           fgets((a+n)->tpc.u.universidade,50,stdin);
           fflush(stdin);
           printf("%s\n",(a+n)->nome);
           printf("%s\n",(a+n)->ident);
           printf("\n  Cadastro realizado com sucesso!\n");
           n++;
           a=(cliente*) realloc(a,(n+1)*sizeof(cliente));
           system("cls");
           break;

           default :
					printf("\n **OPCAO INVALIDA**\n por favor, tente novamente !\n\n");
					system("pause");
					break;
					cadastro ();
     
	 	} 
		main();           
	}
void ver()
{
	system("cls");
	int i;
	if(sizeof(cliente)==0)
	{
		printf("Nao existem cadastros!\n");
		system("pause");
		system("cls");
		main();
	}
	else
	{
		printf("\n dados dos clientes cadastrados:\n");
		int i;
		for (i=0;i<n;i++)
		{
			printf("-----Posicao %d-----\n",i);
			printf("\nnome: %s\nidentificador: %s\n",(a+i)->nome,(a+i)->ident);
			printf("Endereco: %s\n",(a+i)->endereco);
			printf("cpf: %s\nemail: %s\ntelefone: %s\n",(a+i)->cpf,(a+i)->email,(a+i)->telefone);
			printf("Numero da conta: %s\n  ",(a+i)->tpc.c.numerodaconta);
			printf("Agencia do cliente: %s\n ",(a+i)->tpc.c.agencia);
			system("pause");
			system("cls");
		}
	}
	
}
void alterar()
{
	int i,b,x;
   	char identf[20];
   	printf("Entre com o identificador do cliente\n");
   	fflush(stdin);
	fgets(identf,20,stdin);
	for(i=0;i<n;i++)
   	{
    	if(strcmp(identf,(a+i)->ident)==0)
    	{
    		int op;
    		printf("o cliente e %s %s\n",(a+i)->nome,(a+i)->sobrenome);
    		printf("Escolha uma informacao para alterar\n");
    		printf("\n1)rua\n2)email\n3)telefone\n4)cpf\n5)identificador\n6)cancelar\n");
    		scanf("%d",&op);
    		switch(op)
    		{
    			case 1: fflush(stdin);
    					 printf("Digite o endereco do cliente: ");
      					 fgets((a+i)->endereco,100,stdin);
      					 printf("Operacao realizada com sucesso, por favor, confira na visualizacao\n\n");
      					 system("pause");
      					 system("cls");
      					 main();
      					 break;

      			case 2: fflush(stdin);
      					printf("Digite o email do cliente: ");
       					fgets((a+i)->email,80,stdin);
       					printf("Operacao realizada com sucesso, por favor, confira na visualizacao\n\n");
       					system("pause");
       					system("cls");
				  		main();
      					break;

      			case 3: fflush(stdin);
      					printf("Digite o telefone do cliente : ");
       					fgets((a+i)->telefone,20,stdin);
       					printf("Operacao realizada com sucesso, por favor, confira na visualizacao\n\n");
       					system("pause");
       					system("cls");
				  		main();
      					break;

      			case 4: fflush(stdin);
      					printf("Digite o cpf do cliente : ");
       					fgets((a+i)->cpf,15,stdin);
       					printf("Operacao realizada com sucesso, por favor, confira na visualizacao\n\n");
       					system("pause");
       					system("cls");
				  		main();
      					break;

      			case 5: fflush(stdin);
      					printf("Digite o identificador do cliente (apenas numeros): ");
       					fgets((a+i)->ident,5,stdin);
       					printf("Operacao realizada com sucesso, por favor, confira na visualizacao\n\n");
       					system("pause");
       					system("cls");
				  		main ();
      					break;
      			
      			case 6: system("cls");
      					break;
      			
      			default : printf("Essa opcao nao existe, tente novamente\n\n---");
      					  system("pause");
      					  system("cls");
      					  alterar();
      					  break;
			}
    		x=1;
		}
	}
		if(x!=1)
		{
			printf("Este identificador nao existe \n");
			printf("Deseja continuar operacao?\n\n 1.Continuar\n2.SAIR\n ");
			scanf("%d",&b);
			 switch(b)
			 	{
			 		case 1: alterar();
					 		break;
			 		case 2: main();
					 		break;
				}
		}
}
int remover()
{
		int x=0,i,j,op,op2;
		int cont=0,cont1=0;
		char busca[10],busca1[5];
		printf("\nEscolha como deseja remover o cliente\n");
		printf("\n 1- Por CPF\n");
		printf("\n 2- Por identificador\n");
		scanf("%d",&op);
			switch(op)
			{
				case 1:
						fflush(stdin);
						printf("\nDigite o CPF buscado:  ");
						fgets(busca,10,stdin);
						for(i=0;i<n;i++)
						{
							if(strcmp(busca,(a+i)->cpf)==0)
							{
								cont++;
								for(j=i;j<n;j++)
								{
									a[i]=a[j+1];
								}
							}						
						}
	
					if(cont==0)
					{
						
						printf(" o cpf digitado nao existe! \n");
						printf("1) tentar novamente\n\2)voltar ao menu\n");
						scanf("%d",&op2);
						switch(op2)
						{
							case 1: remover();
									break;
							case 2: main();
									break;
						}
						system("pause");
					}
					else 
					{
						printf("Operacao realizada com sucesso! \n");
						a=(cliente*) realloc(a,(n-1)* sizeof(cliente));
						system("pause");
						system("cls");
						main();
						break;
					}
					
				case 2:
					fflush(stdin);
					printf("\nDigite o identificador buscado:\n");
					fgets(busca1,15,stdin);
					for(i=0;i<n;i++)
					{
						if(strcmp(busca1,(a+i)->ident)==0)
						{
							cont1++;
							for(j=i;j<n;j++)
							{
								a[i]=a[j+1];
								break;
							}
						}
					}
					if(cont1==0)
					{
						int op;
						printf(" o identificador digitado nao existe! \n");
						printf("1) tentar novamente\n\2)voltar ao menu\n");
						scanf("%d",&op);
						switch(op)
						{
							case 1: remover();
									break;
							case 2: main();
									break;
						}
					}
					printf("Operacao realizada com sucesso! \n");
					a=(cliente*) realloc(a,(n-1)* sizeof(cliente));
					system("pause");
					system("cls");
					main();
			}
}
void alterartipoconta()
{
	int i=0,ap=0,manter=0,x=0;
	char identbusca[5];
	char busca[10];
	system("cls");
	printf("Entre com o identificador do cliente\n");
	fflush(stdin);
	fgets(identbusca,5,stdin);
	for(i=0;i<n;i++)
   	{
    	if(strcmp(identbusca,(a+i)->ident)==0)
    	{
    		printf("o cliente e %s %s\n",(a+i)->nome,(a+i)->sobrenome);
    		printf("\n  Tipos de conta:");
            printf("\n0.Conta Corrente;");
            printf("\n1.Conta Salario;");
            printf("\n2.Conta Poupanca;");
            printf("\n3.Conta Universitaria.\n");
            printf("\n\ntipo de conta atual: %d\n",(a+i)->tipocont);
            printf("Escolha um novo tipo de conta\n");
            scanf("%d",&(a+i)->tipocont);
            
            fflush(stdin);
            system("cls");
            printf("Tipo de conta escolhida %d\n",(a+i)->tipocont);
            switch((a+i)->tipocont){
                   
		   case 0:	
           fflush(stdin);
           printf("\nEntre com a Agencia do cliente: ");
           fgets((a+i)->tpc.c.agencia,30,stdin);
           fflush(stdin);
           printf("\nDeseja manter o mesmo numero de conta?\n0.Sim  1.Nao\n");
           scanf("%d",&manter);
           fflush(stdin);
           if(manter==0)
           {
           printf("Numero de conta mantido: %s\n ",(a+i)->tpc.c.numerodaconta);
           printf(" Confimacao de dados \nNome:%s %s",(a+i)->nome,(a+i)->sobrenome);
           printf(" Identificador: %s",(a+i)->ident);
           printf("Numero da conta: %s",(a+i)->tpc.c.numerodaconta);
           printf("Agencia do cliente: %s",(a+i)->tpc.c.agencia);
           printf("\n  Troca de conta realizada com sucesso!\n\n\n");
           system("pause");
           system("cls");
           fflush(stdin);
           break;
		   }
		   if(manter==1)
		   {
           printf("\nO Entre com o novo numero de conta diferente do seu anterior:\n"); 
           fgets(busca,10,stdin);
            for(x=0;x<n;x++)
           {
           		if(strcmp(busca,(a+x)->tpc.c.numerodaconta)==0)
           		{

           			printf("---O numero ja foi cadastrado! tente novamente....---\n");
           			system("pause");
           			ap++;
           			system("cls");
		   			main();
				}
		   }
		   if(ap==0)
		   {
		   		printf("--Numero de conta disponivel--\n");
				strcpy((a+i)->tpc.c.numerodaconta,busca);
          		fflush(stdin);
		   }
	       
           printf(" Confimacao de dados \nNome:%s %s",(a+i)->nome,(a+i)->sobrenome);
           printf(" Identificador: %s",(a+i)->ident);
           printf("Numero da conta: %s",(a+i)->tpc.c.numerodaconta);
           printf("Agencia do cliente: %s",(a+i)->tpc.c.agencia);
           printf("\n  Troca de conta realizada com sucesso!\n\n\n");
           system("pause");
           system("cls");
           fflush(stdin);
           break;
           }
           break;

           case 1:
           fflush(stdin);
           printf("\nEntre com a Agencia do cliente: ");
           fgets((a+i)->tpc.s.tc.agencia,30,stdin);
           fflush(stdin);
           printf("\nDeseja manter o mesmo numero de conta?\n0.Sim  1.Nao\n");
           scanf("%d",&manter);
           fflush(stdin);
           if(manter==0)
           {	
           printf("Numero de conta mantido: %s\n ",(a+i)->tpc.s.tc.numerodaconta);
           printf("Entre com o salario do cliente: ");
           scanf("%f",&(a+i)->tpc.s.salario);
           fflush(stdin);
           printf("Entre com o orgao do cliente: ");
           fgets((a+i)->tpc.s.orgao,50,stdin);
           fflush(stdin);
           printf("Entre com o cargo do cliente: ");
           fgets((a+i)->tpc.s.cargo,40,stdin);
           fflush(stdin);
           printf("Entre com a data da contratacao do cliente (formato dd mm aaaa): ");
           scanf("%d%d%d",&(a+i)->tpc.s.diacontratacao,&(a+i)->tpc.s.mescontratacao,&(a+i)->tpc.s.anocontratacao);
           fflush(stdin);
           printf(" Confimacao de dados \nNome:%s %s",(a+i)->nome,(a+i)->sobrenome);
           printf(" Identificador: %s",(a+i)->ident);
           printf("Numero da conta: %s",(a+i)->tpc.s.tc.numerodaconta);
           printf("Agencia do cliente: %s",(a+i)->tpc.s.tc.agencia);
           printf("\n  Troca de conta realizada com sucesso!\n\n\n");
           system("pause");
           system("cls");
           fflush(stdin);
           break;
		   }
		   if(manter==1)
		   {
           printf("\nO Entre com o novo numero de conta diferente do seu anterior:\n"); 
           fgets(busca,10,stdin);
            for(x=0;x<n;x++)
           {
           		if(strcmp(busca,(a+x)->tpc.s.tc.numerodaconta)==0)
           		{

           			printf("---O numero ja foi cadastrado! tente novamente....---\n");
           			system("pause");
           			ap++;
           			system("cls");
		   			main();
				}
		   }
		   if(ap==0)
		   {
		   		printf("--Numero de conta disponivel--\n");
				strcpy((a+i)->tpc.s.tc.numerodaconta,busca);
          		fflush(stdin);
		   }
		   fflush(stdin);
	       printf("Entre com o salario do cliente: ");
           scanf("%f",&(a+i)->tpc.s.salario);
           fflush(stdin);
           printf("Entre com o orgao do cliente: ");
           fgets((a+i)->tpc.s.orgao,50,stdin);
           fflush(stdin);
           printf("Entre com o cargo do cliente: ");
           fgets((a+i)->tpc.s.cargo,40,stdin);
           fflush(stdin);
           printf("Entre com a data da contratacao do cliente (formato dd mm aaaa): ");
           scanf("%d%d%d",&(a+i)->tpc.s.diacontratacao,&(a+i)->tpc.s.mescontratacao,&(a+i)->tpc.s.anocontratacao);
           fflush(stdin);
           printf(" Confimacao de dados \nNome:%s %s",(a+i)->nome,(a+i)->sobrenome);
           printf(" Identificador: %s",(a+i)->ident);
           printf("Numero da conta: %s",(a+i)->tpc.s.tc.numerodaconta);
           printf("Agencia do cliente: %s",(a+i)->tpc.s.tc.agencia);
           printf("\n  Troca de conta realizada com sucesso!\n\n\n");
           system("pause");
           system("cls");
           fflush(stdin);
           break;
           }
           break;
           
           case 2:
           fflush(stdin);
           printf("\nEntre com a Agencia do cliente: ");
           fgets((a+i)->tpc.p.tc.agencia,30,stdin);
           fflush(stdin);
           printf("\nDeseja manter o mesmo numero de conta?\n0.Sim  1.Nao\n");
           scanf("%d",&manter);
           fflush(stdin);
           if(manter==0)
           {
           printf("Numero de conta mantido: %s\n ",(a+i)->tpc.p.tc.numerodaconta);
           fflush(stdin);
           printf("Entre a data da poupanca realizada pelo cliente (formato dd mm aaaa): ");
           scanf("%d%d%d",&(a+i)->tpc.p.diapoupanca,&(a+i)->tpc.p.mespoupanca,&(a+i)->tpc.p.anopoupanca);
           fflush(stdin);
           printf("Entre com o rendimento da poupanca no ultimo mes: ");
           scanf("%f",&(a+i)->tpc.p.rendimentopoupanca);
           fflush(stdin);
           printf(" Confimacao de dados \nNome:%s %s",(a+i)->nome,(a+i)->sobrenome);
           printf(" Identificador: %s",(a+i)->ident);
           printf("Numero da conta: %s",(a+i)->tpc.p.tc.numerodaconta);
           printf("Agencia do cliente: %s",(a+i)->tpc.p.tc.agencia);
           printf("\n  Troca de conta realizada com sucesso!\n\n\n");
           system("pause");
           system("cls");
           fflush(stdin);
           break;
		   }
		   if(manter==1)
		   {
           printf("\nO Entre com o novo numero de conta diferente do seu anterior:\n"); 
           fgets(busca,10,stdin);
            for(x=0;x<n;x++)
           {
           		if(strcmp(busca,(a+x)->tpc.p.tc.numerodaconta)==0)
           		{

           			printf("---O numero ja foi cadastrado! tente novamente....---\n");
           			system("pause");
           			ap++;
           			system("cls");
		   			main();
				}
		   }
		   if(ap==0)
		   {
		   		printf("--Numero de conta disponivel--\n");
				strcpy((a+i)->tpc.p.tc.numerodaconta,busca);
          		fflush(stdin);
		   }
	       fflush(stdin);
           printf("Entre a data da poupanca realizada pelo cliente (formato dd mm aaaa): ");
           scanf("%d%d%d",&(a+i)->tpc.p.diapoupanca,&(a+i)->tpc.p.mespoupanca,&(a+i)->tpc.p.anopoupanca);
           fflush(stdin);
           printf("Entre com o rendimento da poupanca no ultimo mes: ");
           scanf("%f",&(a+i)->tpc.p.rendimentopoupanca);
           fflush(stdin);
           printf(" Confimacao de dados \nNome:%s %s",(a+i)->nome,(a+i)->sobrenome);
           printf(" Identificador: %s",(a+i)->ident);
           printf("Numero da conta: %s",(a+i)->tpc.p.tc.numerodaconta);
           printf("Agencia do cliente: %s",(a+i)->tpc.p.tc.agencia);
           printf("\n  Troca de conta realizada com sucesso!\n\n\n");
           system("pause");
           system("cls");
           fflush(stdin);
           break;
           }
           break;
           
           case 3:
           fflush(stdin);
           printf("\nEntre com a Agencia do cliente: ");
           fgets((a+i)->tpc.u.tc.agencia,30,stdin);
           fflush(stdin);
           printf("\nDeseja manter o mesmo numero de conta?\n0.Sim  1.Nao\n");
           scanf("%d",&manter);
           fflush(stdin);
           if(manter==0)
           {
           printf("Numero de conta mantido: %s\n ",(a+i)->tpc.u.tc.numerodaconta);
           fflush(stdin);
           printf("Digite a matricula do cliente: ");
           scanf("%d",&(a+i)->tpc.u.matricula);
           fflush(stdin);
           printf("Entre com a data da matricula do cliente (formato dd mm aaaa): ");
           scanf("%d%d%d",&(a+i)->tpc.u.diamatricula,&(a+i)->tpc.u.mesmatricula,&(a+i)->tpc.u.anomatricula);
           fflush(stdin);
           printf("Entre com a data da previsao de conclusao do cliente (formado dd mm aaaa): ");
           scanf("%d%d%d",&(a+i)->tpc.u.diaprevisao,&(a+i)->tpc.u.mesprevisao,&(a+i)->tpc.u.anoprevisao);
           fflush(stdin);
           printf("\nEntre com o curso frequentado do cliente: ");
           fgets((a+i)->tpc.u.curso,40,stdin);
           fflush(stdin);
           printf("\nEntre com a Universidade frequentada pelo cliente: ");
           fgets((a+i)->tpc.u.universidade,50,stdin);
           fflush(stdin);
           printf(" Confimacao de dados \nNome:%s %s",(a+i)->nome,(a+i)->sobrenome);
           printf(" Identificador: %s",(a+i)->ident);
           printf("Numero da conta: %s",(a+i)->tpc.u.tc.numerodaconta);
           printf("Agencia do cliente: %s",(a+i)->tpc.u.tc.agencia);
           printf("\n  Troca de conta realizada com sucesso!\n\n\n");
           system("pause");
           system("cls");
           fflush(stdin);
           break;
		   }
		   if(manter==1)
		   {
           printf("\nO Entre com o novo numero de conta diferente do seu anterior:\n"); 
           fgets(busca,10,stdin);
            for(x=0;x<n;x++)
           {
           		if(strcmp(busca,(a+x)->tpc.u.tc.numerodaconta)==0)
           		{

           			printf("---O numero ja foi cadastrado! tente novamente....---\n");
           			system("pause");
           			ap++;
           			system("cls");
		   			main();
				}
		   }
		   if(ap==0)
		   {
		   		printf("--Numero de conta disponivel--\n");
				strcpy((a+i)->tpc.u.tc.numerodaconta,busca);
          		fflush(stdin);
		   }
	       fflush(stdin);
           printf("Digite a matricula do cliente: ");
           scanf("%d",&(a+i)->tpc.u.matricula);
           fflush(stdin);
           printf("Entre com a data da matricula do cliente (formato dd mm aaaa): ");
           scanf("%d%d%d",&(a+i)->tpc.u.diamatricula,&(a+i)->tpc.u.mesmatricula,&(a+i)->tpc.u.anomatricula);
           fflush(stdin);
           printf("Entre com a data da previsao de conclusao do cliente (formado dd mm aaaa): ");
           scanf("%d%d%d",&(a+i)->tpc.u.diaprevisao,&(a+i)->tpc.u.mesprevisao,&(a+i)->tpc.u.anoprevisao);
           fflush(stdin);
           printf("\nEntre com o curso frequentado do cliente: ");
           fgets((a+i)->tpc.u.curso,40,stdin);
           fflush(stdin);
           printf("\nEntre com a Universidade frequentada pelo cliente: ");
           fgets((a+i)->tpc.u.universidade,50,stdin);
           fflush(stdin);
           printf(" Confimacao de dados \nNome:%s %s",(a+i)->nome,(a+i)->sobrenome);
           printf(" Identificador: %s",(a+i)->ident);
           printf("Numero da conta: %s",(a+i)->tpc.u.tc.numerodaconta);
           printf("Agencia do cliente: %s",(a+i)->tpc.u.tc.agencia);
           printf("\n  Troca de conta realizada com sucesso!\n\n\n");
           system("pause");
           system("cls");
           fflush(stdin);
           break;
           }
           break;

           default :
					printf("\n **OPCAO INVALIDA**\n por favor, tente novamente !\n\n");
					system("pause");
					break;
					alterartipoconta();
     
	 	}           
}
}
}


void escolha()
{
            int x = 0,escolha=0;
            system("cls");
            printf("\n\n\n\tEscolha uma das opcoes:\n");
            printf("0. Saque\n1. Deposito\n");
            scanf("%d",&escolha);
            switch(escolha){
                case 0:
                    saque();
                    break;
                case 1:
                    deposito();
                    break;
                default:
                    printf("\n **OPCAO INVALIDA**\n por favor, tente novamente !\n\n");
                    break;
            }


 }
 
 
 
 void saque(){
 printf("\nVoce escolheu a opcao Saque!\n ");
    int x=0,b=0;
   	int i=0;
    float sacado=0, quant = 0;
   	system("cls");
   	fflush(stdin);
	char vagencia[10], vconta[10];
	fflush(stdin);
    printf("\nDigite a agencia: ");
    fgets(vagencia, 10, stdin);
    fflush(stdin);
    printf("Digite o numero da conta: ");
    fgets(vconta, 10, stdin);
    fflush(stdin);
	for(i=0;i<n;i++)
   	{
    	if(strcmp(vagencia,(a+i)->tpc.c.agencia)== 0 && strcmp(vconta,(a+i)->tpc.c.numerodaconta)==0 || strcmp(vagencia,(a+i)->tpc.s.tc.agencia)== 0 && strcmp(vconta,(a+i)->tpc.s.tc.numerodaconta )== 0 ||strcmp(vagencia,(a+i)->tpc.p.tc.agencia)== 0 && strcmp(vconta,(a+i)->tpc.p.tc.numerodaconta)==0 ||strcmp(vagencia,(a+i)->tpc.u.tc.agencia)== 0 && strcmp(vconta,(a+i)->tpc.u.tc.numerodaconta)==0 ) 
		{
    		int op;
    		printf("o cliente e %s %s\n",(a+i)->nome,(a+i)->sobrenome);
    		quant = (a+i)->saldo;
    
            printf("\nO saldo da conta e : %f\n", quant);
            printf("\nDigite o valor que sera retirado\nValor retirado:");
            scanf("%f", &sacado);
            fflush(stdin);
            quant = quant - sacado ;

            (a+i)->saldo = quant ;
             printf("\n\nO saldo atual e: %.4f\n", quant);
    		x=1;
    		system("pause");
    		system("cls");
    		break;
		}
	}
		if(x!=1)
		{
			printf("\nEste cadastro nao existe \n");
			printf("Deseja continuar operacao?\n\n 1.Continuar\n2.SAIR\n ");
			scanf("%d",&b);
			 switch(b)
			 	{
			 		case 1: saque();
					 		break;
			 		case 2: main();
					 		break;
				}
		}
}
 
 

 void deposito(){
 printf("\nVoce escolheu a opcao deposto!\n ");
    int x=0,b=0;
   	int i=0;
    float depositado=0, quant = 0;
   	system("cls");
   	fflush(stdin);
	char vagencia[10], vconta[10];
	fflush(stdin);
    printf("\nDigite a agencia: ");
    fgets(vagencia, 10, stdin);
    fflush(stdin);
    printf("Digite o numero da conta: ");
    fgets(vconta, 10, stdin);
    fflush(stdin);
	for(i=0;i<n;i++)
   	{
    	if(strcmp(vagencia,(a+i)->tpc.c.agencia)== 0 && strcmp(vconta,(a+i)->tpc.c.numerodaconta)==0 || strcmp(vagencia,(a+i)->tpc.s.tc.agencia)== 0 && strcmp(vconta,(a+i)->tpc.s.tc.numerodaconta )== 0 ||strcmp(vagencia,(a+i)->tpc.p.tc.agencia)== 0 && strcmp(vconta,(a+i)->tpc.p.tc.numerodaconta)==0 ||strcmp(vagencia,(a+i)->tpc.u.tc.agencia)== 0 && strcmp(vconta,(a+i)->tpc.u.tc.numerodaconta)==0 ) 
		{
    		quant = (a+i)->saldo;
     
             printf("\nO saldo da conta e : %f\n", quant);
             printf("\nDigite o valor que sera depositado\n");
             scanf("%f", &depositado);
             fflush(stdin);
             quant = quant + depositado ;

            (a+i)->saldo = quant ;
            printf("\n\nO saldo atual e: %.4f\n", quant);
    		x=1;
    		system("pause");
    		system("cls");
    		break;
		}
	}
		if(x!=1)
		{
			printf("\nEste cadastro nao existe \n");
			printf("Deseja continuar operacao?\n\n 1.Continuar\n2.SAIR\n ");
			scanf("%d",&b);
			 switch(b)
			 	{
			 		case 1: deposito();
					 		break;
			 		case 2: main();
					 		break;
				}
		}
}
  
 
 void rendimento(){
 printf("\nVoce escolheu a opcao rendimento da poupanca!\n ");
    int x=0,b=0;
   	int i=0;
    float quant = 0, m=0,z=0;
   	system("cls");
   	fflush(stdin);
	char vagencia[10], vconta[10];
	fflush(stdin);
    printf("\nDigite a agencia: ");
    fgets(vagencia, 10, stdin);
    fflush(stdin);
    printf("Digite o numero da conta: ");
    fgets(vconta, 10, stdin);
    fflush(stdin);
	for(i=0;i<n;i++)
   	{
    	if(strcmp(vagencia,(a+i)->tpc.c.agencia)== 0 && strcmp(vconta,(a+i)->tpc.c.numerodaconta)==0 || strcmp(vagencia,(a+i)->tpc.s.tc.agencia)== 0 && strcmp(vconta,(a+i)->tpc.s.tc.numerodaconta )== 0 ||strcmp(vagencia,(a+i)->tpc.p.tc.agencia)== 0 && strcmp(vconta,(a+i)->tpc.p.tc.numerodaconta)==0 ||strcmp(vagencia,(a+i)->tpc.u.tc.agencia)== 0 && strcmp(vconta,(a+i)->tpc.u.tc.numerodaconta)==0 ) 
		{
    		int op;
    		printf("o cliente e %s %s\n",(a+i)->nome,(a+i)->sobrenome);
    		quant = (a+i)->saldo;
    

                
            printf("entre com o total de meses desde a poupanca ate o periodo atual: ");
			scanf("%f",&m)   ;
    
            z=quant*0.01*m;
            printf("\nO rendimento foi de %f\n",z);
            quant = quant + z;
            (a+i)->saldo=quant;

            printf("\nO saldo atual da conta poupanca e: %.4f\n",(a+i)->saldo ); 
    		x=1;
    		system("pause");
    		system("cls");
    		break;
		}
	}
		if(x!=1)
		{
			printf("\nEste cadastro nao existe \n");
			printf("Deseja continuar operacao?\n\n 1.Continuar\n2.SAIR\n ");
			scanf("%d",&b);
			 switch(b)
			 	{
			 		case 1: rendimento();
					 		break;
			 		case 2: main();
					 		break;
				}
		}
}
 

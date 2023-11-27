#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include <time.h>

#include <wchar.h>

typedef struct {
        char usuario[20];
        char senha[20];
} Usuario;

typedef struct {

        char nomeCompletoResponsavel[40];
        char cargo[40];
        char contatoPessoal[20];
        char cpf[40];
        char emailResponsavel[40];
        char pais[40];
        char cepResponsavel[20];

        char nomeEmpresa[40];
        char cnpj[20];
        char razaoSocial[40];
        char nomeFantasia[40];
        char telefone[20];
        char email[40];
        char dia[10];
        char mes[10];
        char ano[10];
        char rua[40];
        char numero[10];
        char bairro[40];
        char cidade[40];
        char estado[40];
        char cep[15];
        int residuosAmbientais;
        int valorEstimado;
} Empresa;



int login(Usuario usuarios[], int numeroDeUsuarios);
void registrar(Usuario usuarios[], int *numeroDeUsuarios);

void cadastrarIndustria(Empresa empresa[], int numeroDeIndustrias);
void registroArquivoIndustria(Empresa empresa[], int *numeroDeIndustrias);

void atualizarResiduosEValor(Empresa empresa[], int numeroDeIndustrias);

void gerarRelatorioInsumos(Empresa empresa[], int *numeroDeIndustrias);
void gerarRelatorioGastosMensais(Empresa empresa[], int *numeroDeIndustrias);

void criptografar(char palavra[],int chave);



int main()
{

    setlocale(LC_ALL, "portuguese");

    char resposta[3];
    int escolhaUsuario;
    int numeroDeUsuarios = 0;
    int numeroDeIndustrias = 0;
    Usuario usuarios[50];
    Empresa empresa[50];

    do {



        system("cls");
        printf(" _     ___   ____ ___ _   _       \n");
        printf("| |   / _ \\ / ___|_ _| \\ | |    \n");
        printf("| |  | | | | |  _ | ||  \\| |     \n");
        printf("| |__| |_| | |_| || || |\\  |      \n");
        printf("|_____\\___/ \\____|___|_| \\_|   \n\n");

        printf("[1] Login \n");
        printf("[2] Registro de Profissional \n");
        printf("[3] Sair \n");
        scanf("%d",&escolhaUsuario);
        getchar();
        switch (escolhaUsuario) {
            case 1:
                if(login(usuarios,numeroDeUsuarios) == 1){
                    cadastrarIndustria(empresa,numeroDeIndustrias);
                };
                break;
            case 2:
                registrar(usuarios,&numeroDeUsuarios);
                break;
            case 3:
                exit(EXIT_SUCCESS);
                break;
            default:
                printf("Informe um valor válido!\n");
                printf("Deseja continuar? sim/nao \n");
                scanf("%s",&resposta);
        }


    } while(strcmp(resposta, "nao") != 0);
    return 0;
}


int login(Usuario usuarios[], int numeroDeUsuarios) {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    char nomeUsuario[20];
    char senhaUsuario[20];
    system("cls");
    printf("---------------------\n");
    printf("| LOGIN FUNCIONÁRIO |\n");
    printf("---------------------\n");

    printf("Digite seu nome de usuário: ");
    scanf("%20[^\n]",nomeUsuario);
    getchar();

    printf("Digite sua senha: ");
    scanf("%20[^\n]",senhaUsuario);

    for (int i = 0; i < 10; i++) {
        if (strcmp(usuarios[i].usuario,nomeUsuario) == 0 &&
            strcmp(usuarios[i].senha,senhaUsuario) == 0) {

            SetConsoleTextAttribute(console, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            printf("Login realizado com sucesso.");
            SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
            Sleep(3000);
            return 1;
        }
    }
    SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_INTENSITY);

    printf("Login Falhou!\n");
    Sleep(3000);
    SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
    return 0;
}
void registrar(Usuario usuarios[], int *numeroDeUsuarios) {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

    system("cls");
    printf("-----------------------\n");
    printf("|REGISTRAR FUNCIONÁRIO|\n");
    printf("-----------------------\n");

    printf("Digite o nome de usuário: ");
    scanf("%20[^\n]", usuarios[*numeroDeUsuarios].usuario);
    getchar();
    printf("Digite a senha: ");
    scanf("%20[^\n]", usuarios[*numeroDeUsuarios].senha);


    SetConsoleTextAttribute(console, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    printf("Usuário Registrado com sucesso!!\n");
    SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
    Sleep(3000);
    (numeroDeUsuarios++);


}

void cadastrarIndustria(Empresa empresa[], int numeroDeIndustrias) {

    char escolhaUsario[3];
    int escolhaIndustria;

    do {
        system("cls");

        printf(" ___ _   _ ____  _   _ ____ _____ ____  ___    _      \n");
        printf("|_ _| \\ | |  _ \\| | | / ___|_   _|  _ \\|_ _|  / \\   \n");
        printf(" | ||  \\| | | | | | | \\___ \\ | | | |_) || |  / _ \\   \n");
        printf(" | || |\\  | |_| | |_| |___) || | |  _ < | | / ___ \\  \n");
        printf("|___|_| \\_|____/ \\___/|____/ |_| |_| \\_\\___/_/   \\_\\ \n");

        printf("----------------------------------------------------\n");
        printf("|[1] Cadastrar Industria                           |\n");
        printf("|[2] Atualizar Residuos e Valor Estimado de Custo  |\n");
        printf("|[3] Relatário Total Insumos Tratados              |\n");
        printf("|[4] Relatário Total Gastos Mensais                |\n");
        printf("|[5] Sair                                          |\n");
        printf("----------------------------------------------------\n");
        scanf("%d",&escolhaIndustria);
        switch(escolhaIndustria) {
            case 1:
                registroArquivoIndustria(empresa,&numeroDeIndustrias);
                break;
            case 2:
                atualizarResiduosEValor(empresa,&numeroDeIndustrias);
                break;
            case 3:
                gerarRelatorioInsumos(empresa,&numeroDeIndustrias);
                break;
            case 4:
                gerarRelatorioGastosMensais(empresa,&numeroDeIndustrias);
                break;
            case 5:
                exit(EXIT_SUCCESS);
                break;
            default:
                printf("Valor inválido\n");
        }
        printf("Deseja Continuar? sim/nao\n");
        scanf("%s",&escolhaUsario);
    } while (strcmp(escolhaUsario, "nao") != 0);

}

void registroArquivoIndustria(Empresa empresa[], int *numeroDeIndustrias) {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    system("cls");
    printf("---------------------------\n");
    printf("|  CADASTRO DE  INDÚSTRIA |\n");
    printf("---------------------------\n");



    getchar();
    printf("DADOS DO RESPONSÁVEL\n");
    printf("Nome: ");
    scanf("%40[^\n]", empresa[*numeroDeIndustrias].nomeCompletoResponsavel);
    getchar();
    printf("Cargo: ");
    scanf("%40[^\n]", empresa[*numeroDeIndustrias].cargo);
    getchar();
    printf("Contato: ");
    scanf("%20[^\n]", empresa[*numeroDeIndustrias].contatoPessoal);
    getchar();
    printf("Cpf (Apenas números): ");
    scanf("%20[^\n]", empresa[*numeroDeIndustrias].cpf);
    getchar();
    printf("Email: ");
    scanf("%40[^\n]", empresa[*numeroDeIndustrias].emailResponsavel);
    getchar();
    printf("País: ");
    scanf("%20[^\n]", empresa[*numeroDeIndustrias].pais);
    getchar();
    printf("Cep: ");
    scanf("%15[^\n]", empresa[*numeroDeIndustrias].cepResponsavel);
    printf("\n\n");
    printf("DADOS DA EMPRESA\n");
    printf("Cnpj(Apenas Números): ");
    getchar();
    scanf("%20[^\n]", empresa[*numeroDeIndustrias].cnpj);
    getchar();
    printf("Razão social: ");
    scanf("%40[^\n]", empresa[*numeroDeIndustrias].razaoSocial);
    getchar();
    printf("Nome fantasia: ");
    scanf("%40[^\n]", empresa[*numeroDeIndustrias].nomeFantasia);
    getchar();
    printf("Telefone: ");
    scanf("%20[^\n]", empresa[*numeroDeIndustrias].telefone);
    getchar();
    printf("Email: ");
    scanf("%40[^\n]", empresa[*numeroDeIndustrias].email);
    getchar();
    printf("Data de Abertura: ");
    printf("Dia (dd): ");
    scanf("%10[^\n]", empresa[*numeroDeIndustrias].dia);
    getchar();
    printf("Mês (mm): ");
    scanf("%10[^\n]", empresa[*numeroDeIndustrias].mes);
    getchar();
    printf("Ano (yyyy): ");
    scanf("%10[^\n]", empresa[*numeroDeIndustrias].ano);


    printf("\n\n");
    printf("ENDEREÇO\n");
    getchar();
    printf("Rua: ");
    scanf("%20[^\n]", empresa[*numeroDeIndustrias].rua);
    getchar();
    printf("Número: ");
    scanf("%10[^\n]", empresa[*numeroDeIndustrias].numero);
    getchar();
    printf("Bairro: ");
    scanf("%40[^\n]", empresa[*numeroDeIndustrias].bairro);
    getchar();
    printf("Cidade: ");
    scanf("%40[^\n]", empresa[*numeroDeIndustrias].cidade);
    getchar();
    printf("Estado: ");
    scanf("%20[^\n]", empresa[*numeroDeIndustrias].estado);
    getchar();
    printf("Cep: ");
    scanf("%15[^\n]", empresa[*numeroDeIndustrias].cep);
    getchar();
    FILE *file;
    file = fopen("empresas-registradas.txt","a");
    fprintf(file,"---DADOS DO RESPONSÁVEL---\n");

    fprintf(file,"Nome: %s\n",empresa[*numeroDeIndustrias].nomeCompletoResponsavel);
    fprintf(file,"Cargo: %s\n",empresa[*numeroDeIndustrias].cargo);
    fprintf(file,"Contato: %s\n",empresa[*numeroDeIndustrias].contatoPessoal);
    fprintf(file,"Cpf: %s\n",empresa[*numeroDeIndustrias].cpf);
    fprintf(file,"Email: %s\n",empresa[*numeroDeIndustrias].emailResponsavel);
    criptografar(empresa[*numeroDeIndustrias].pais,0XAED);
    fprintf(file,"País: %s\n",empresa[*numeroDeIndustrias].pais);
    fprintf(file,"Cep: %s\n\n",empresa[*numeroDeIndustrias].cepResponsavel);


    fprintf(file,"---DADOS DA EMPRESA---\n");
    fprintf(file,"Cnpj: %s\n",empresa[*numeroDeIndustrias].cnpj);
    fprintf(file,"Razão Social: %s\n",empresa[*numeroDeIndustrias].razaoSocial);
    fprintf(file,"Nome Fantasia: %s\n",empresa[*numeroDeIndustrias].nomeFantasia);
    fprintf(file,"Telefone: %s\n",empresa[*numeroDeIndustrias].telefone);
    fprintf(file,"Email: %s\n",empresa[*numeroDeIndustrias].email);
    fprintf(file,"Data de Abertura: %s-",empresa[*numeroDeIndustrias].dia);
    fprintf(file,"%s-",empresa[*numeroDeIndustrias].mes);
    fprintf(file,"%s\n\n",empresa[*numeroDeIndustrias].ano);

    fprintf(file,"---ENDERECO---\n");
    fprintf(file,"Rua: %s\n",empresa[*numeroDeIndustrias].rua);
    fprintf(file,"Numero: %s\n",empresa[*numeroDeIndustrias].numero);
    fprintf(file,"Bairro: %s\n",empresa[*numeroDeIndustrias].bairro);
    fprintf(file,"Cidade: %s\n",empresa[*numeroDeIndustrias].cidade);
    fprintf(file,"Estado: %s\n",empresa[*numeroDeIndustrias].estado);
    fprintf(file,"Cep: %s\n\n",empresa[*numeroDeIndustrias].cep);

    fclose(file);
    *numeroDeIndustrias+= 1;

    system("cls");
    SetConsoleTextAttribute(console, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    printf("EMPRESA REGISTRADA COM SUCESSO!!\n");
    SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
    printf("vá para a pasta raiz irá conter um arquivo chamado empresas-registradas.txt\n\n");
    Sleep(5000);

}




void gerarRelatorioInsumos(Empresa empresa[], int *numeroDeInsdustrias) {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

    int tamanhoArrayNome = strlen(empresa[0].nomeCompletoResponsavel);
    int tamanhoArrayNomeFantasia = strlen(empresa[0].nomeFantasia);
    time_t tempo_atual;
    struct tm *info_tempo;
    time(&tempo_atual);
    info_tempo = localtime(&tempo_atual);
    system("cls");
    printf("-----------------------------\n");
    printf("| GERAR RELATÍRIO INSUMOS   |\n");
    printf("-----------------------------\n");
    if (tamanhoArrayNome == 0 || tamanhoArrayNomeFantasia== 0) {
        printf("Não há nenhuma industria cadastrada, por favor cadastre uma indústria.\n");
    } else {
        char nomeDaEmpresa[30];
        char nomeDeInsumos[30];
        int empresaAlterada;

        printf("\x1b[33mOBS: Não use pontos e espaços na escrita!!\n\n\x1b[0m");
        printf("EMPRESAS CADASTRADAS\n\n");
        for (int i= 0; i <*numeroDeInsdustrias; i++) {
            printf("[%d]%s\n",i,empresa[i].nomeFantasia);
        }
        printf("\n");
        printf("Qual empresa você deseja gerar o relatório?\n");
        scanf("%d",&empresaAlterada);
        getchar();

        printf("Digite o tipo de insumos tratados: ");
        scanf("%30[^\n]",&nomeDeInsumos);

        int insumos[6];
        int sum=0;
        for(int i = 0; i <6;i++) {
            printf("Por favor, Digite a quantidade de insumos tratados no %d mês (10 = 1KG)\n ",i+1);
            scanf("%d",&insumos[i]);
        }

        for(int i = 0; i <6;i++) {
            sum+=insumos[i];
        }

        int tamanhoDoArray=sizeof(insumos)/sizeof(insumos[0]);
        int mes_atual = info_tempo->tm_mon;
        const char *nomes_meses[] = {
            "Janeiro", "Fevereiro", "Março", "Abril",
            "Maio", "Junho", "Julho", "Agosto",
            "Setembro", "Outubro", "Novembro", "Dezembro"
        };


        FILE *file;
        file = fopen("relatorio-insumos.txt","w");

        fprintf(file,"Nome: %s\n",empresa[empresaAlterada].nomeFantasia);
        fprintf(file,"Cnpj: %s\n",empresa[empresaAlterada].cnpj);
        fprintf(file,"Razão Social: %s\n",empresa[empresaAlterada].razaoSocial);
        fprintf(file,"Telefone: %s\n",empresa[empresaAlterada].telefone);
        fprintf(file,"Email: %s\n",empresa[empresaAlterada].email);
        fprintf(file,"Data de Abertura: %s-%s-%s\n\n",empresa[empresaAlterada].dia,empresa[empresaAlterada].mes,empresa[empresaAlterada].ano);
        fprintf(file,"Rua: %s\n",empresa[empresaAlterada].rua);
        fprintf(file,"Numero: %s\n",empresa[empresaAlterada].numero);
        fprintf(file,"Bairro: %s\n",empresa[empresaAlterada].bairro);
        fprintf(file,"Cidade: %s\n",empresa[empresaAlterada].cidade);
        fprintf(file,"Estado: %s\n",empresa[empresaAlterada].estado);
        fprintf(file,"Cep: %s\n\n",empresa[empresaAlterada].cep);

        fprintf(file,"Mês do relatório: %s\n",nomes_meses[mes_atual]);
        fprintf(file,"Total de insumos tratados semestralmente: %d\n",sum);
        fprintf(file,"Tipo de insumos tratados: %s\n",nomeDeInsumos);
        fprintf(file,"Média semestral de insumos tratados: %d\n",sum/tamanhoDoArray);
        fprintf(file,"Total recebido: %dR$\n",empresa[empresaAlterada].valorEstimado *(sum /10));
        fclose(file);
        system("cls");
        SetConsoleTextAttribute(console, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        printf("RELATÓRIO GERADO COM SUCESSO!!\n");
        SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
        printf("vá para a pasta raiz irá conter um arquivo chamado relatório-insumos\n");
        Sleep(3000);
    }



}


void gerarRelatorioGastosMensais(Empresa empresa[], int *numeroDeInsdustrias) {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    int tamanhoArrayNome = strlen(empresa[0].nomeCompletoResponsavel);
    int tamanhoArrayNomeFantasia = strlen(empresa[0].nomeFantasia);
    system("cls");
    printf("-----------------------------------\n");
    printf("| GERAR RELATíRIO GASTOS MENSAIS  |\n");
    printf("-----------------------------------\n");
    if (tamanhoArrayNome == 0 || tamanhoArrayNomeFantasia== 0) {
        printf("Não há nenhuma industria cadastrada, por favor cadastre uma indústria.\n");
    } else {
        int empresaAlterada;
        float lucroMensal;
        float despesasFixas;
        float despesasVariaveis;
        float despesasOperacionais;
        char nomeEmpresa[15];
        time_t tempo_atual;
        struct tm *info_tempo;
        time(&tempo_atual);
        info_tempo = localtime(&tempo_atual);

        const char *nomes_meses[] = {
            "Janeiro", "Fevereiro", "Março", "Abril",
            "Maio", "Junho", "Julho", "Agosto",
            "Setembro", "Outubro", "Novembro", "Dezembro"
        };

        int mes_atual = info_tempo->tm_mon;

        printf("EMPRESAS CADASTRADAS\n\n");
        for (int i= 0; i <*numeroDeInsdustrias; i++) {
            printf("[%d]%s\n",i,empresa[i].nomeFantasia);
        }
        printf("\n");
        printf("Qual empresa você deseja gerar o relatório?\n");
        scanf("%d",&empresaAlterada);

        FILE *file;
        file = fopen("relatorio-gastos-mensais.txt","w");



        printf("\x1b[33mOBS: Não use pontos e espaços na escrita!!\n\n\x1b[0m");

        printf("Informe o lucro mensal deste mês: ");
        scanf("%f",&lucroMensal);
        printf("Informe as Despesas fixas: ");
        scanf("%f",&despesasFixas);
        printf("Informe as Despesas variaveis: ");
        scanf("%f",&despesasVariaveis);
        printf("Informe as Despesas operacionais: ");
        scanf("%f",&despesasOperacionais);

        fprintf(file,"---DADOS DA EMPRESA---\n");
        fprintf(file,"Nome: %s\n",empresa[empresaAlterada].nomeFantasia);
        fprintf(file,"Cnpj: %s\n",empresa[empresaAlterada].cnpj);
        fprintf(file,"Razão Social: %s\n",empresa[empresaAlterada].razaoSocial);
        fprintf(file,"Telefone: %s\n",empresa[empresaAlterada].telefone);
        fprintf(file,"Email: %s\n",empresa[empresaAlterada].email);
        fprintf(file,"Data de Abertura: %s-%s-%s\n\n",empresa[empresaAlterada].dia,empresa[empresaAlterada].mes,empresa[empresaAlterada].ano);
        fprintf(file,"Rua: %s\n",empresa[empresaAlterada].rua);
        fprintf(file,"Numero: %s\n",empresa[empresaAlterada].numero);
        fprintf(file,"Bairro: %s\n",empresa[empresaAlterada].bairro);
        fprintf(file,"Cidade: %s\n",empresa[empresaAlterada].cidade);
        fprintf(file,"Estado: %s\n",empresa[empresaAlterada].estado);
        fprintf(file,"Cep: %s\n\n",empresa[empresaAlterada].cep);

        fprintf(file,"Mês do relatório: %s\n",nomes_meses[mes_atual]);
        fprintf(file,"Lucro Mensal: %.2fR$\n",lucroMensal);
        fprintf(file,"Despesas Fixas: %.2fR$\n",despesasFixas);
        fprintf(file,"Despesas Variaveis: %.2fR$\n",despesasVariaveis);
        fprintf(file,"Despesas Operacionais: %.2fR$\n",despesasOperacionais);

        float sum = lucroMensal-(despesasFixas + despesasVariaveis + despesasOperacionais);

        fprintf(file,"Total: %.2fR$",sum);
        fclose(file);
        system("cls");
        SetConsoleTextAttribute(console, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        printf("RELATÓRIO GERADO COM SUCESSO!!\n");
        SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);


        printf("vá para a pasta raiz irá conter um arquivo chamado relatorio-gastos-mensais\n");
        Sleep(5000);
    }




}

atualizarResiduosEValor(Empresa empresa[], int *numeroDeInsdustrias) {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    system("cls");
    printf("-----------------------\n");
    printf("|  ATUALIZAR VALORES  |\n");
    printf("-----------------------\n");
    int empresaAlterada;
    int tamanhoArrayNome = strlen(empresa[0].nomeCompletoResponsavel);
    int tamanhoArrayNomeFantasia = strlen(empresa[0].nomeFantasia);
    if (tamanhoArrayNome == 0 || tamanhoArrayNomeFantasia== 0) {
        printf("Não há nenhuma industria cadastrada, por favor cadastre uma industria.\n");
    } else {
        printf("EMPRESAS CADASTRADAS\n");
        for (int i= 0; i <*numeroDeInsdustrias; i++) {
            printf("[%d]%s\n",i,empresa[i].nomeFantasia);
        }
        printf("\n");
        printf("Qual empresa você deseja alterar?\n");
        scanf("%d",&empresaAlterada);
        if (empresaAlterada > *numeroDeInsdustrias ) {
            printf("Valor inválido\n");
        } else {
            printf("Digite a quantidade de Residuos Ambientais (10=1kg): ");
            scanf("%d",&empresa[empresaAlterada].residuosAmbientais);
            printf("Digite o valor estimado de Custo por KG: ");
            scanf("%d",&empresa[empresaAlterada].valorEstimado);
            SetConsoleTextAttribute(console, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            printf("Valor Atualizado com sucesso!\n");
            SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);

            Sleep(2000);
        }

    }

}





void criptografar(char palavra[],int chave) {
    for(int i =0; i< strlen(palavra); i++) {
        palavra[i]= palavra[i] - chave;
    }
}

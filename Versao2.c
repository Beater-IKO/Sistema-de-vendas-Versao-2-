#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define num_itens_limpeza 7
#define num_itens_venda 7
#define num_itens_padaria 7
#define vetor_contador
#define total_items 3

// Declaração de variáveis globais

int codigos_limpeza[num_itens_limpeza] = {11, 12, 13, 14, 15, 16, 17};
float precos_limpeza[num_itens_limpeza] = {1.99, 8.99, 1.50, 15.00, 4.99, 7.99, 1.00};

int codigos_venda[num_itens_venda] = {21, 22, 23, 24, 25, 26, 27};
float precos_venda[num_itens_venda] = {19.99, 5.90, 4.50, 8.00, 5.00, 2.00, 5.00};

int codigos_padaria[num_itens_padaria] = {31, 32, 33, 34, 35, 36, 37};
float precos_padaria[num_itens_padaria] = {9.50, 12.50, 1.90, 8.50, 12.50, 2.50, 17.50};

int vetor[vetor_contador] = {0};
float geral[total_items];

int menuP, quant, menulimpeza, menuvendas, menupadaria, maquininha, voltarmenup, cont;
float total, valortroco, pagamento, faturamentolimpeza = 0, faturamentovenda = 0, faturamentopadaria = 0, caixa = 0;
float totalgeral = 0.0f, totalfaturamento = 0.0f, desconto = 0.0f;

// Protótipos das funções
void menuPrincipal();
void MenuLimpeza();
void menuVenda();
void menuPadaria();
void menuPagamento();
void menuFechamento();
void menuAbertura();

void main()
{
    do
    {
        cont = 0;

        // Chama a função do menu principal
        menuPrincipal();

        // Verifica a escolha do usuário e chama a função correspondente
        if (menuP == 1)
        {
            system("CLS");
            MenuLimpeza();
        }
        else if (menuP == 2)
        {
            system("CLS");
            menuVenda();
        }
        else if (menuP == 3)
        {
            system("CLS");
            menuPadaria();
        }
        else if (menuP == 4)
        {
            menuPagamento();
            system("pause");
        }
        else if (menuP == 5)
        {
            system("CLS");
            menuFechamento();
        }
        else if (menuP == 6)
        {
            system("CLS");
            menuAbertura();
        }
        else if (menuP == 7)
        {
            
            printf("Saindo do programa...");
            sleep(3);
            system("CLS");
            cont = 1;

        }

    } while (cont == 0);
}

void menuPrincipal()
{
    // Loop principal do programa

    system("Cls");
    // Menu principal
    printf("+--------------------------+\n");
    printf("| **Opcoes do Menu**       |\n");
    printf("+--------------------------+\n");
    printf("| 1. Material de Limpeza   |\n");
    printf("| 2. Venda de Alimentos    |\n");
    printf("| 3. Padaria               |\n");
    printf("| 4. Pagamento             |\n");
    printf("| 5. Fechamento de Caixa   |\n");
    printf("| 6. Abertura de Caixa     |\n");
    printf("| 7. Sair                  |\n");
    printf("+------------------------- +\n");

    printf("Digite sua opcao: ");
    scanf("%d", &menuP);

    // Validação da entrada do menu principal
    if (menuP < 1 || menuP > 7)
    {
        system("cls");
        printf("Valor inválido. Digite um número entre 1 e 7.\n");
    }
}

void MenuLimpeza()
{
    int indice = 0;
    // Loop do menu de material de limpeza
    while (menulimpeza != 18)
    {
        // Exibe o menu de material de limpeza
        printf("Voce escolheu Material de Limpeza.\n");
        printf("+---------------------------------------------+\n");
        printf("|            **Lista de Compras**             |\n");
        printf("+---------------------------------------------+\n");
        printf("|---------------------------------------------|\n");
        printf("| 11 |     Detergente        | R$ 1,99        |\n");
        printf("| 12 |     Sabao em Po (1kg) | R$ 8,99        |\n");
        printf("| 13 |     Esponja           | R$ 1,50        |\n");
        printf("| 14 |     Amaciante (1Lt)   | R$ 15,00       |\n");
        printf("| 15 |     Bucha de Pia (kit c /3)  R$ 4.99   |\n");
        printf("| 16 |     Desinfetante (1Lt)   | R$ 7.99     |\n");
        printf("| 17 |     Sabao em Barra (Un)  | R$ 1.00     |\n");
        printf("+---------------------------------------------+\n");
        printf("| 18 | Voltar ao Menu Principal               |\n");
        printf("+---------------------------------------------+\n");

        // Lê o código do item
        scanf("%d", &codigos_limpeza[indice]);

        // Validação da entrada do item
        if (codigos_limpeza[indice] < 11 || codigos_limpeza[indice] > 18)
        {
            system("cls");
            printf("**Valor invalido** Digite um número entre 11 e 18.\n");
        }
        else
        {
            // Se o código digitado for 18, volta ao menu principal
            if (codigos_limpeza[indice] == 18)
            {
                system("cls");
                break;
            }
            // Lê a quantidade do item
            printf("Qual a quantidade: ");
            scanf("%d", &quant);

            // Acumula o total da compra
            int i;
            for (i = 0; i < num_itens_limpeza; i++)
            {
                if (codigos_limpeza[indice] == codigos_limpeza[i])
                {
                    geral[0] += quant * precos_limpeza[i];
                    vetor[0] += quant;
                    break;
                }
            }
            system("cls");
            printf("O carrinho de materiais de limpezas esta em %.2f\n", geral[0]);
        }
        indice++;
    }
}

void menuVenda()
{
    int indice

 = 0;

    while (menuvendas != 28)
    {
        // Exibe o menu de venda de alimentos
        printf("Voce escolheu venda de alimentos.\n");
        printf("+------------------------------------------------------+\n");
        printf("|                 **Lista de Compras**                 |\n");
        printf("+------------------------------------------------------+\n");
        // Itens de venda de alimentos
        printf("|------------------------------------------------------|\n");
        printf("| 21 |          Cafe             | R$ 19,99            |\n");
        printf("| 22 |       Leite (cx)          | R$ 5,90             |\n");
        printf("| 23 |       Arroz (1Kg)         | R$ 4,50             |\n");
        printf("| 24 |      Feijao Preto         | R$ 8,00             |\n");
        printf("| 25 |      Acucar (1Kg)         | R$ 5,00             |\n");
        printf("| 26 |        Sal (1Kg)          | R$ 2,00             |\n");
        printf("| 27 |    Farinha de Trigo (1Kg) | R$ 5,00             |\n");
        printf("+------------------------------------------------------+\n");
        printf("| 28 | Voltar ao Menu Principal                        |\n");
        printf("+------------------------------------------------------+\n");

        // Lê o código do item
        scanf("%d", &codigos_venda[indice]);

        // Validação da entrada do item
        if (codigos_venda[indice] < 21 || codigos_venda[indice] > 28)
        {
            system("cls");
            printf("**Valor invalido** Digite um número entre 21 e 28.\n");
        }
        else
        {
            // Se o código digitado for 28, volta ao menu principal
            if (codigos_venda[indice] == 28)
            {
                system("cls");
                break;
            }
            // Lê a quantidade do item
            printf("Qual a quantidade: ");
            scanf("%d", &quant);

            // Acumula o total da compra
            for (int i = 0; i < num_itens_venda; i++)
            {
                if (codigos_venda[indice] == codigos_venda[i])
                {
                    geral[1] += quant * precos_venda[i];
                    vetor[1] += quant; // Atualiza a quantidade vendida
                    break;
                }
            }

            system("cls");
            printf("O carrinho da venda de alimentos esta em %.2f\n", geral[1]);
        }
    }
}

void menuPadaria()
{
    int indice = 0;

    while (menupadaria != 38)
    {
        // Exibe o menu de padaria
        printf("Voce escolheu padaria.\n");
        printf("+---------------------------------------------+\n");
        printf("|            **Lista de Compras**             |\n");
        printf("+---------------------------------------------+\n");
        // Itens de padaria
        printf("|---------------------------------------------|\n");
        printf("| 31 |          Pao de Forma       | R$ 9,50  |\n");
        printf("| 32 |          Pao Integral       | R$ 12,50 |\n");
        printf("| 33 |        Pao Frances(Unid)    | R$ 1,90  |\n");
        printf("| 34 |             Sonho           | R$ 8,50  |\n");
        printf("| 35 |         Biscoito (kg)       | R$ 12,50 |\n");
        printf("| 36 |         Pao Doce (Un)       | R$ 2,50  |\n");
        printf("| 37 |          Salgado (Un)       | R$ 17,50 |\n");
        printf("+---------------------------------------------+\n");
        printf("| 38 | Voltar ao Menu Principal               |\n");
        printf("+---------------------------------------------+\n");

        // Lê o código do item
        scanf("%d", &codigos_padaria[indice]);

        // Validação da entrada do item
        if (codigos_padaria[indice] < 31 || codigos_padaria[indice] > 38)
        {
            system("cls");
            printf("**Valor invalido** Digite um número entre 31 e 38.\n");
        }
        else
        {
            // Se o código digitado for 38, volta ao menu principal
            if (codigos_padaria[indice] == 38)
            {
                system("cls");
                break;
            }
            // Lê a quantidade do item
            printf("Qual a quantidade: ");
            scanf("%d", &quant);

            // Acumula o total da compra
            for (int i = 0; i < num_itens_padaria; i++)
            {
                if (codigos_padaria[indice] == codigos_padaria[i])
                {
                    geral[2] += quant * precos_padaria[i];
                    vetor[2] += quant; // Atualiza a quantidade vendida
                    break;
                }
            }
            system("cls");
            printf("O carrinho da padaria esta em R$%.2f\n", geral[2]);
        }
    }
}

void menuPagamento()
{
    system("cls");
    printf("Voce escolheu menu de pagamento.\n");
    printf("+--------------------------------------+\n");
    printf("|            **PAGAMENTO**             |\n");
    printf("+--------------------------------------+\n");
    // carrinho de cada item especifico
    printf("O carrinho de materiais de limpeza deu R$%.2f\n", geral[0]);
    printf("O carrinho da padaria deu R$%.2f\n", geral[1]);
    printf("O carrinho da venda de alimentos deu R$%.2f\n", geral[2]);

    // Cálculo do total geral e faturamentos individuais
    total += geral[0] + geral[1] + geral[2];
    totalfaturamento += geral[0] + geral[1] + geral[2];
    faturamentolimpeza += geral[0];
    faturamentovenda += geral[1];
    faturamentopadaria += geral[2];

    // Escolha do pagamento
    while (pagamento != 1 && pagamento != 2)
    {
        printf("O total eh R$%.2f\n", total);
        printf("Escolha a forma de pagamento:\n");
        printf("1- Dinheiro com desconto\n");
        printf("2- Cartao\n");
        scanf("%f", &pagamento);
        if (pagamento != 1 && pagamento != 2)
        {
            printf("opcao invalida digite novamente");
        }
    }

    // Pagamento em dinheiro
    if (pagamento == 1)
    {
        if (total == 50)
        {
            total = total - (total * 0.05);
            printf("Nao tem desconto, o preco continua sendo R$%.2f\n",

 total);
        }
        else if (total > 50 && total < 100)
        {
            total = total - (total * 0.10);
        }
        else if (total >= 100 && total < 200)
        {
            total = total - (total * 0.18);
            printf("O preco com desconto ficou R$%.2f\n", total);
        }
        else if (total >= 200)
        {
            printf("Quantos o recebera de desconto :  ");
            scanf("%f", &desconto);
            total = (desconto / 100) * (total);
        }
        else
        {
            printf("\nNão tem desconto, o preço continua sendo R$%.2f\n", total);
        }

        printf("O preço com desconto ficou R$%.2f\n", total);
        printf("Qual o valor que o cliente pagou? ");
        scanf("%f", &valortroco);
        if (valortroco < total)
        {
            totalgeral = total - valortroco;
            printf("Ainda falta R$ %.2f\n", totalgeral);
        }
        else
        {
            totalgeral = valortroco - total;
            printf("O troco vai ser %.2f\n", totalgeral);
            // Atualização do caixa
            caixa = caixa - totalgeral;
            printf("\nAinda restam R$%.2f no caixa\n", caixa);
        }

        // Resetando os valores para uma nova compra
        geral[0] = 0.0f;
        geral[1] = 0.0f;
        geral[2] = 0.0f;
        total = 0.0f;
        pagamento = 0.0f;
    }
    // Pagamento em forma de cartao
    else if (pagamento == 2)
    {
        while (1)
        {
            printf("Maquininha OK 1 ou NAO 2\n ");
            scanf("%d", &maquininha);
            if (maquininha == 1)
            {
                // Resetando os valores para uma nova compra
                geral[0] = 0.0f;
                geral[1] = 0.0f;
                geral[2] = 0.0f;
                total = 0.0f;
                pagamento = 0.0f;
                break;
            }
            if (maquininha == 2)
            {
                printf("Maquininha indisponível. Escolha outra forma de pagamento:\n");
                printf("1- Dinheiro com desconto\n");
                printf("2- Cartão\n");
                scanf("%f", &pagamento);

                if (pagamento == 1)
                {
                    if (total <= 50)
                    {
                        total = total - (total * 0.05);
                    }
                    else if (total > 50 && total < 100)
                    {
                        total = total - (total * 0.10);
                    }
                    else if (total >= 100 && total < 200)
                    {
                        total = total - (total * 0.18);
                        printf("O preço com desconto ficou R$%.2f\n", total);
                    }
                    else if (total > 200)
                    {
                        printf("Quantos o recebera de desconto :  ");
                        scanf("%f", &desconto);
                        total = (desconto / 100) * (total);
                    }
                    else
                    {
                        printf("\nNão tem desconto, o preço continua sendo R$%.2f\n", total);
                    }
                    printf("O preço com desconto ficou R$%.2f\n", total);
                    printf("Qual o valor que o cliente pagou?\n");
                    scanf("%f", &valortroco);

                    if (valortroco < total)
                    {
                        totalgeral = total - valortroco;
                        printf("Ainda falta R$ %.2f\n", totalgeral);
                    }
                    else
                    {
                        caixa = caixa - totalgeral;
                        printf("\nAinda restam R$%.2f no caixa\n", caixa);
                        totalgeral = valortroco - total;
                        printf("O troco vai ser %.2f\n", totalgeral);
                    }

                    // Resetando os valores para uma nova compra
                    geral[0] = 0.0f;
                    geral[1] = 0.0f;
                    geral[2] = 0.0f;
                    total = 0.0f;
                    pagamento = 0.0f;
                    // Sair do loop while
                    break;
                }
                else
                {
                    printf("Opcao invalida. Digite 1 ou 2\n");
                }
            }
        }
    }
}

void menuFechamento()
{
    printf("[- O FATURAMENTO DO DIA FOI -]\n\n");

    // Imprime os faturamentos de cada setor e o total
    printf("O faturamento de Material de limpeza foi R$%.2f, com %d de vendas\n", faturamentolimpeza, vetor[0]);
    printf("O faturamento de Venda de Alimentos foi R$%.2f, com %d de vendas\n", faturamentovenda, vetor[1]);
    printf("O faturamento de Padaria foi R$%.2f, com %d de vendas\n", faturamentopadaria, vetor[2]);
    printf("Total do Faturamento hoje foi de %.2f\n", totalfaturamento);
    // Saída do programa
    exit(1);
}

void menuAbertura()
{
    printf("[- BEM VINDO A ABERTURA DE CAIXA -]\n\n");
    // Seleciona qual valor sera dado no caixa
    printf("Digite o valor para o caixa : ");
    scanf("%f", &caixa);
    printf("\nDeseja voltar ao menu principal? 1-SIM 2-NAO");
    scanf("%d", &voltarmenup);
    system("cls");
    if (voltarmenup == 2)
    {
        printf("Saindo do programa.\n");
    }
}
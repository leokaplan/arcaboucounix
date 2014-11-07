#include "TABULEIRO.h"
#include "ESTADO.h"
#include "MENU.h"
#include "LISTA.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 *   Tratamento de Erros
 */

typedef enum{
    PRI,
    TAB,
    EST,
    MEN
} tpmodulo;
typedef enum{
    PRI_CondRetOK,
    PRI_CondRetInvalido,
    PRI_CondRetSemOpcao         
} PRI_tpCondRet;

void Erro(char* comm, int CondRet,tpmodulo module);
/*
void TrataPRI(int CondRet){
    switch(CondRet){
        case FaltouMemoria:
            printf("Operacao mal sucedida. Faltou Memoria.");
            break;   
            printf("Comando invalido"); 
    }
}
*/
/*
    Tratamento de input
*/
/* 
mudar de lis->gra
*/
PRI_tpCondRet LeCmd(EST_tppEstado e){
    char c; 
    char cmd;
    int id;
    LIS_tppLista opcoes;
    MEN_tppMenus ms;
    scanf(" %c",&c);
    EST_GetMenus(e,&ms);
    MEN_MenuCorrente(ms,&id);
    MEN_GetMenuOpcoes(ms,id,&opcoes);
    LIS_IrInicioLista(opcoes);
    do
    {
        MEN_tppOpcao opcao = LIS_ObterValor(opcoes);
        MEN_GetOpcaoCmd(opcao,&cmd),MEN;
        if(cmd == c){
            Erro("Executando opcao selecionada:",MEN_Callback(opcao,e),MEN);
            return PRI_CondRetOK;
        }    
    }
    while(LIS_AvancarElementoCorrente(opcoes,1)==LIS_CondRetOK);
  
    return PRI_CondRetSemOpcao;         
}

void Msg(char* comm){
    printf("== %s\n",comm);
}
/*
valida retorna apenas CondRetOK ou PRI_CondRetInvalido

*/

/*
trunca em 50
*/
PRI_tpCondRet LeString(char* dst, PRI_tpCondRet (*valida)(char* s)){
    char temp[50];
    scanf(" %s",temp);
    PRI_tpCondRet cr = valida(temp);
    if(cr == PRI_CondRetOK){
        strcpy(dst,temp);
    }
    return cr;    
}
PRI_tpCondRet LeInt(int* dst, PRI_tpCondRet (*valida)(int t)){
    int temp;
    scanf(" %d",&temp);
    PRI_tpCondRet cr = valida(temp);
    if(cr == PRI_CondRetOK){
        *dst = temp;
    }
    return cr;    
}
void Erro(char* comm, int CondRet,tpmodulo module){
    printf("\n%s\n",comm);
    if(CondRet == 0)//OK
    {
        printf("OK");
    }
    else
    {    
	printf("falhou");     
/*   switch (module){
            case PRI:
                trataPRI(CondRet);
                break;
            case TAB:
                trataTAB(CondRet);
                break;
            case PRI:
                trataPRI(CondRet);
                break;
        }*/
    }
	printf("\n");     
}
/* 
 *    Popula Menus 
 */

#define JOGO 6 
#define EDITOR 5 
void vaiMenu1(EST_tppEstado e,MEN_tppOpcao opc){ 
    MEN_tppMenus m;
    EST_GetMenus(e,&m);
    MEN_MudaMenu(m,1); 
}
void vaiMenu2(EST_tppEstado e,MEN_tppOpcao opc){ 
    MEN_tppMenus m;
    EST_GetMenus(e,&m);
    MEN_MudaMenu(m,2); 
}
void vaiMenu3(EST_tppEstado e,MEN_tppOpcao opc){ 
    MEN_tppMenus m;
    EST_GetMenus(e,&m);
    MEN_MudaMenu(m,3); 
}
void vaiMenu4(EST_tppEstado e,MEN_tppOpcao opc){ 
    MEN_tppMenus m;
    EST_GetMenus(e,&m);
    MEN_MudaMenu(m,4); 
}
void joga(EST_tppEstado e,MEN_tppOpcao opc){ 
    MEN_tppMenus m;
    EST_GetMenus(e,&m);
    MEN_MudaMenu(m,JOGO); 
}
/*
void carregar(EST_tppEstado e,MEN_tppOpcao opc){

    TAB le o dir
        p cada arquivo,i 
        char nome[10];
    TAB le o nome
*
        Erro("Lendo diretorio...", MEN_CriarOpcao(EST_GetMenus(e),idCarrega,to_char(i),nome,carrega),MEN) ;
    vaiMenuidCarrega(e);

}
*/
void carrega(EST_tppEstado e,MEN_tppOpcao opc){
    //EST_AlterarTabuleiro(e,TAB_CriarTabuleiro()); 
    //if(e != NULL)
    //    TAB_carrega(MEN_GetNomeOpcao(opc));    
}
void deleta(EST_tppEstado e,MEN_tppOpcao opc){
//    TAB_Deletar(EST_GetTabuleiro(e));
}
void salva(EST_tppEstado e,MEN_tppOpcao opc){
    TAB_tppTabuleiro t;
    char* nome;
    EST_GetTabuleiro(e,&t);
    Erro("Salvando tabuleiro",TAB_SalvarTabuleiro(t,nome),TAB);
}
void andadireditor(EST_tppEstado e,MEN_tppOpcao opc){
    TAB_tppTabuleiro t;
    EST_GetTabuleiro(e,&t);
    if(TAB_PodeAndarPraDireita(t,0)==TAB_CondRetOK)
        TAB_AndarPraDireita(t);
}
void andaesqeditor(EST_tppEstado e,MEN_tppOpcao opc){
    TAB_tppTabuleiro t;
    EST_GetTabuleiro(e,&t);
    if(TAB_PodeAndarPraEsquerda(t,0)==TAB_CondRetOK)
        TAB_AndarPraEsquerda(t);
}
void andabaixoeditor(EST_tppEstado e,MEN_tppOpcao opc){
    TAB_tppTabuleiro t;
    EST_GetTabuleiro(e,&t);
    if(TAB_PodeAndarPraBaixo(t,0)==TAB_CondRetOK)
        TAB_AndarPraBaixo(t);
}
void andacimaeditor(EST_tppEstado e,MEN_tppOpcao opc){
    TAB_tppTabuleiro t;
    EST_GetTabuleiro(e,&t);
    if(TAB_PodeAndarPraCima(t,0)==TAB_CondRetOK)
        TAB_AndarPraCima(t);
}
void andadirjogador(EST_tppEstado e,MEN_tppOpcao opc){
    TAB_tppTabuleiro t;
    EST_GetTabuleiro(e,&t);
    if(TAB_PodeAndarPraDireita(t,1)==TAB_CondRetOK)
        TAB_AndarPraDireita(t);
}
void andaesqjogador(EST_tppEstado e,MEN_tppOpcao opc){
    TAB_tppTabuleiro t;
    EST_GetTabuleiro(e,&t);
    if(TAB_PodeAndarPraEsquerda(t,1)==TAB_CondRetOK)
        TAB_AndarPraEsquerda(t);
}
void andabaixojogador(EST_tppEstado e,MEN_tppOpcao opc){
    TAB_tppTabuleiro t;
    EST_GetTabuleiro(e,&t);
    if(TAB_PodeAndarPraBaixo(t,1)==TAB_CondRetOK)
        TAB_AndarPraBaixo(t);
}
void andacimajogador(EST_tppEstado e,MEN_tppOpcao opc){
    TAB_tppTabuleiro t;
    EST_GetTabuleiro(e,&t);
    if(TAB_PodeAndarPraCima(t,1)==TAB_CondRetOK)
        TAB_AndarPraCima(t);
}

void poefim(EST_tppEstado e,MEN_tppOpcao opc){
    TAB_tppTabuleiro t;
    EST_GetTabuleiro(e,&t);
    TAB_PoeFim(t);
}
void poeinicio(EST_tppEstado e,MEN_tppOpcao opc){
    TAB_tppTabuleiro t;
    EST_GetTabuleiro(e,&t);
    TAB_PoeInicio(t);
}
void poechao(EST_tppEstado e,MEN_tppOpcao opc){
    TAB_tppTabuleiro t;
    EST_GetTabuleiro(e,&t);
    TAB_PoeChao(t);
}

void poeparede(EST_tppEstado e,MEN_tppOpcao opc){
    TAB_tppTabuleiro t;
    EST_GetTabuleiro(e,&t);
    TAB_PoeParede(t);
}
/*
   Tres tipos de retorno: 
   no inicial, que termina o programa
   em um generico, volta para o menu acima
   os que exibem tabuleiro(jogo e editor), que precisam limpar o tabuleiro antes de voltar
    Mudar para nao usar GRAxxx

 */

PRI_tpCondRet validastring(char* s){
    if(strlen(s)<10){
        if(strcmp(s,"")){
            return PRI_CondRetOK;
        }
        else{
            return PRI_CondRetInvalido;
        }
    }
    else{
        return PRI_CondRetInvalido;
    }
}
PRI_tpCondRet validaint(int n){
    if(n>=0 && n<11) 
        return PRI_CondRetOK;
    else 
        return PRI_CondRetInvalido;
}
//TODO:recomendacoes de ux do flavio

void novo_tab(EST_tppEstado e){
    char* nome = malloc(sizeof(char)*10);
    int alt = -1;
    int lar = -1;
    char* saida;
    while(alt == -1){
        Msg("Digite a altura (1..10) ou 0 para voltar");
        Erro("validando:",LeInt(&alt,validaint),PRI);
        if(alt == 0){
            Msg("cancelando operacao");
             return;
        }
    }
    while(lar == -1){
        Msg("Digite a largura (1..10) ou 0 para voltar");
        Erro("validando:",LeInt(&lar,validaint),PRI);
        if(lar == 0){
            Msg("cancelando operacao");
             return;
        }
    }
    while(!strcmp(nome,"")){
        Msg("Digite o nome (menos de 10 caracteres) ou 0 para voltar");
        Erro("validando:",LeString(nome,validastring),PRI);
        if(!strcmp(nome,"0")){
            Msg("cancelando operacao");
             return;
        }
    }
    TAB_tppTabuleiro a;
    if(EST_GetTabuleiro(e,&a)==EST_CondRetOK)
        TAB_DestruirTabuleiro(a);
    Erro("Criando tabuleiro",TAB_CriarTabuleiro(&a,alt,lar,nome),TAB);
    EST_SetTabuleiro(e,a);
    //Erro("Salvando tabuleiro",TAB_SalvarTabuleiro(a,nome),TAB);
    
    MEN_tppMenus m;
    EST_GetMenus(e,&m);
    MEN_MudaMenu(m,EDITOR); 
}

void PopulaMenuInicio(EST_tppEstado e){
    int idMenu = 1;
    int idPai = 0;
    MEN_tppMenus m;
    EST_GetMenus(e,&m);
    Erro("criando menu Inicio", MEN_CriarMenu(m,idMenu,"Inicio",idPai),MEN);

    Erro("criando opcao 1 de Inicio", MEN_CriarOpcao(m,1,'1',"Editor",vaiMenu2),MEN) ;
    Erro("criando opcao 2 de Inicio", MEN_CriarOpcao(m,idMenu,'2',"Resolvedor",vaiMenu3),MEN);
    Erro("criando opcao 3 de Inicio", MEN_CriarOpcao(m,idMenu,'3',"Jogar",vaiMenu4),MEN);
}

void PopulaMenuEditor(EST_tppEstado e){
    int idMenu = 2;
    int idPai = 1;
    MEN_tppMenus m;
    EST_GetMenus(e,&m);
    Erro("criando menu Editor", MEN_CriarMenu(m,idMenu,"Editor",idPai),MEN);

    Erro("criando opcao 1 de Editor", MEN_CriarOpcao(m,idMenu,'1',"Carregar",carrega),MEN) ;
    Erro("criando opcao 2 de Editor", MEN_CriarOpcao(m,2,'2',"Novo",novo_tab),MEN);
    Erro("criando opcao 3 de Editor", MEN_CriarOpcao(m,idMenu,'3',"Deletar",deleta),MEN);
}
void PopulaMenuResolvedor(EST_tppEstado e){
    int idMenu = 3;
    int idPai = 1;
    MEN_tppMenus m;
    EST_GetMenus(e,&m);
    Erro("criando menu Resolvedor", MEN_CriarMenu(m,idMenu,"Resolvedor",idPai),MEN);

    Erro("criando opcao 1 de Resolvedor", MEN_CriarOpcao(m,idMenu,'1',"Carregar",carrega),MEN) ;
}
void PopulaMenuJogar(EST_tppEstado e){
    int idMenu = 4;
    int idPai = 1;
    MEN_tppMenus m;
    EST_GetMenus(e,&m);
    Erro("criando menu Jogar", MEN_CriarMenu(m,idMenu,"Jogar",idPai),MEN);

    Erro("criando opcao 1 de Jogar", MEN_CriarOpcao(m,idMenu,'1',"Carregar",carrega),MEN) ;
}
void PopulaMenuEdicao(EST_tppEstado e){
    int idMenu = EDITOR;
    int idPai = 2;
    MEN_tppMenus m;
    EST_GetMenus(e,&m);
    Erro("criando Editor", MEN_CriarMenu(m,idMenu,"Edicao",idPai),MEN);

    Erro("criando opcao 1 de Edicao", MEN_CriarOpcao(m,idMenu,'w',"andar para cima",andacimaeditor),MEN) ;
    Erro("criando opcao 2 de Edicao", MEN_CriarOpcao(m,idMenu,'s',"andar para baixo",andabaixoeditor),MEN) ;
    Erro("criando opcao 3 de Edicao", MEN_CriarOpcao(m,idMenu,'a',"andar para esquerda",andaesqeditor),MEN) ;
    Erro("criando opcao 4 de Edicao", MEN_CriarOpcao(m,idMenu,'d',"andar para direita",andadireditor),MEN) ;
    Erro("criando opcao 5 de Edicao", MEN_CriarOpcao(m,idMenu,'1',"por parede",poeparede),MEN) ;
    Erro("criando opcao 6 de Edicao", MEN_CriarOpcao(m,idMenu,'2',"por chao",poechao),MEN) ;
    Erro("criando opcao 7 de Edicao", MEN_CriarOpcao(m,idMenu,'3',"por inicio",poeinicio),MEN) ;
    Erro("criando opcao 8 de Edicao", MEN_CriarOpcao(m,idMenu,'4',"por fim",poefim),MEN) ;
    Erro("criando opcao 9 de Edicao", MEN_CriarOpcao(m,idMenu,'5',"salvar",salva),MEN) ;
    Erro("criando opcao 10 de Edicao", MEN_CriarOpcao(m,idMenu,'6',"jogar",joga),MEN) ;
}
void PopulaMenuJogo(EST_tppEstado e){
    int idMenu = JOGO;
    int idPai = 4;
    MEN_tppMenus m;
    EST_GetMenus(e,&m);
    Erro("criando Jogo", MEN_CriarMenu(m,idMenu,"Jogo",idPai),MEN);

    Erro("criando opcao 1 de Jogo", MEN_CriarOpcao(m,idMenu,'w',"andar para cima",andacimajogador),MEN) ;
    Erro("criando opcao 2 de Jogo", MEN_CriarOpcao(m,idMenu,'s',"andar para baixo",andabaixojogador),MEN) ;
    Erro("criando opcao 3 de Jogo", MEN_CriarOpcao(m,idMenu,'a',"andar para esquerda",andaesqjogador),MEN) ;
    Erro("criando opcao 4 de Jogo", MEN_CriarOpcao(m,idMenu,'d',"andar para direita",andadirjogador),MEN) ;
}
//housekeeping
//tpCondRet
PRI_tpCondRet PopulaMenus(EST_tppEstado e){
    MEN_tppMenus menus;
    MEN_CriarMenus(&menus);
    EST_SetMenus(e,menus);
    PopulaMenuInicio(e);
    PopulaMenuEditor(e);
    PopulaMenuResolvedor(e);
    PopulaMenuJogar(e);
    PopulaMenuEdicao(e);
    return PRI_CondRetOK;
}
/*
 *   Apresenta Dados para o usuario
 */

/*
   Apresenta o Menu corrente
 */
void ApresentaMenu(EST_tppEstado e){
    char cmd;
    int* id;
    char* nome;
    char* nomeopc;
    LIS_tppLista opc;
    MEN_tppMenus ms;
    EST_GetMenus(e,&ms);
    MEN_MenuCorrente(ms,id);
    MEN_GetMenuOpcoes(ms,*id,&opc);
    MEN_GetMenuNome(ms,*id,&nome);
    printf("\n###############\n#  Labirinto  #\n###############");
    printf("\n %s\n--------------",nome);
    printf("\nDigite:\n\n");
    LIS_IrInicioLista(opc);
    do
    {
        MEN_tppOpcao opcao = LIS_ObterValor(opc);
        if(opcao!=NULL){
            MEN_GetOpcaoCmd(opcao,&cmd);
            MEN_GetOpcaoNome(opcao,&nomeopc);
            printf("\n %c para %s", cmd,nomeopc);
        }
    }
    while(LIS_AvancarElementoCorrente(opc,1)==LIS_CondRetOK);

    printf("\n--------------\n");

}


void ApresentaTabuleiro(EST_tppEstado e){
	TAB_tppTabuleiro Tabuleiro; 
	int a,l,i,j,jx,jy;
    char* nome;
    EST_GetTabuleiro(e,&Tabuleiro);
	TAB_GetAltura(Tabuleiro,&a);
	TAB_GetLargura(Tabuleiro,&l);
    TAB_GetNome(Tabuleiro,&nome);
	TAB_PosicaoJogador(Tabuleiro,&jx,&jy);
	printf("Nome do Tabuleiro: %s\n",nome);
    for(i=0;i<a;i++){
	    for(j=0;j<l;j++){
           TAB_tpCasa casa;
	       TAB_GetTipoCasa(Tabuleiro,i,j,&casa);
               //posicao do jogador
               if(j==jx && i==jy){
                   printf("O");    
               }
               else{
		       if(casa==TAB_tpCasaInicio) printf("I"); 
		       else if(casa==TAB_tpCasaFim) printf("F"); 
		       else if(casa==TAB_tpCasaChao) printf(" "); 
		       else if(casa==TAB_tpCasaParede) printf("#"); 
               }
            }	
            printf("\n");
	}
}

void ApresentaSolucao(EST_tppEstado e){
    int * solucao;
    int tam;
    int i;
    TAB_tppTabuleiro t;
    EST_GetTabuleiro(e,&t);
    TAB_SolucionarTabuleiro(t,&solucao,&tam);
    for(i=0;i<tam;i+=2){
        printf("Passo %d: (x,y) -> (%d,%d)\n",(i/2)+1,solucao[i],solucao[i+1]);    
    }
}

/*
 *   Função Principal
 */
int main(){
    int atual;
    EST_tppEstado e;
    MEN_tppMenus menus;
    Erro("Alocando Estado",EST_CriaEstado(&e),EST);
    if(e!=NULL){
        PRI_tpCondRet cr = PopulaMenus(e);
        Erro("Populando Menus",cr,PRI);
        if(cr!=PRI_CondRetOK)
            return 0;
    }
    else{
        return 0;
    }
    
    EST_GetMenus(e,&menus);
    //inicia a navegacao em 1
    MEN_MenuInicial(menus);
    //só sera 0 quando o ultimo corrente for 1 e o usuario digitar 0
    
    MEN_MenuCorrente(menus,&atual);
    while(atual!=0){
        ApresentaMenu(e);
        if(atual == EDITOR||atual == JOGO)
            ApresentaTabuleiro(e);
        Erro("Digite um comando:",LeCmd(e),PRI);
        EST_GetMenus(e,&menus);
        MEN_MenuCorrente(menus,&atual);
    }
    EST_DestruirEstado(e);
    return 0;
}



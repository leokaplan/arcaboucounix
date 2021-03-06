/***************************************************************************
*  $MCI M�dulo de implementa��o: TCNT Teste contadores de passagem
*
*  Arquivo gerado:              TestCnt.c
*  Letras identificadoras:      TCNT
*
*  Nome da base de software:    Arcabou�o para a automa��o de testes de programas redigidos em C
*  Arquivo da base de software: C:\AUTOTEST\PROJETOS\ARCABOUC.BSW
*
*  Projeto: INF 1301 / 1628 Automatiza��o dos testes de m�dulos C
*  Gestor:  LES/DI/PUC-Rio
*  Autores: avs
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*     4       avs   01/fev/2006 criar linguagem script simb�lica
*     3       avs   08/dez/2004 uniformiza��o dos exemplos
*     2       avs   07/jul/2003 unifica��o de todos os m�dulos em um s� projeto
*     1       avs   16/abr/2003 in�cio desenvolvimento
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>

#include "TST_ESPC.H"

#include "GENERICO.H"
#include "LERPARM.H"
#include "CONTA.H"

#define     DIM_MSG             500
#define     DIM_NOME_ARQ        500
#define     DIM_NOME_CONTADOR   500

/* Comandos de contagem */

static const char CONTAR_PASSAGEM_CMD[ ]          = "=contar" ;
static const char INICIAR_ITERADOR_CMD[ ]         = "=iniciariteradorcontadores" ;
static const char EXIBIR_CONTADOR_CORR_CMD[ ]     = "=exibircontadorcorrente" ;
static const char OBTER_CONTAGEM_CORR_CMD[ ]      = "=contagemcorrente" ;
static const char OBTER_NOME_CONTADOR_CORR_CMD[ ] = "=nomecorrente" ;
static const char IR_PROX_CONTADOR_CMD[ ]         = "=iterarproximocontador" ;
static const char EH_ITERADOR_ATIVO_CMD[ ]        = "=ehiteradorativo" ;
static const char VERIFICAR_ESTRUTURA_CMD[ ]      = "=verificarestruturacontadores" ;

/*****  C�digo das fun��es exportadas pelo m�dulo  *****/


/***********************************************************************
*
*  $FC Fun��o: TCNT &Teste de contador de passagem
*
*  $ED Descri��o da fun��o
*     =contar                    <nome contador> <num linha> <condRet>
*     =iniciariteradorcontadores
*     =exibircontadorcorrente
*     =contagemcorrente
*     =nomecorrente
*     =iterarproximocontador
*     =ehiteradorativo
*     =verificarestruturacontadores
*
***********************************************************************/

   TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
   {

      char   Msg[ DIM_MSG ] ;
      char   NomeContador[ DIM_NOME_CONTADOR ] ;
      char * pNome ;

      int    numLidos ,
             IntEsp    ;

      CNT_tpCondRet CondRetEsp ;

      int  numLinha ;

      /* Tratar CNT  &Contar */

         if ( strcmp( ComandoTeste , CONTAR_PASSAGEM_CMD ) == 0 )
         {

            /*
               CNT_tpCondRet CNT_Contar( char * NomeContador , int numLinha )
            */

            CondRetEsp = CNT_CondRetOK ;

            numLidos = LER_LerParametros( "sii" ,
                               NomeContador , &numLinha , &CondRetEsp ) ;
            if ( numLidos < 2 )
            {
               return TST_CondRetParm ;
            } /* if */

            return TST_CompararInt( CondRetEsp ,
                      CNT_Contar( NomeContador , numLinha ) ,
                      "Condi��o de retorno errada." ) ;

         } /* fim ativa: Tratar CNT  &Contar */

      /* Tratar CNT  &Iterador: iniciar percorrimento da lista em ordem alfab�tica */

         else if ( strcmp( ComandoTeste , INICIAR_ITERADOR_CMD ) == 0 )
         {

            /*
               void CNT_IniciarIterador( )
            */

            CNT_IniciarIterador( ) ;

            return TST_CondRetOK ;

         } /* fim ativa: Tratar CNT  &Iterador: iniciar percorrimento da lista em ordem alfab�tica */

      /* Tratar CNT  &Iterador: exibir contador corrente */

         else if ( strcmp( ComandoTeste , EXIBIR_CONTADOR_CORR_CMD ) == 0 )
         {

            pNome = CNT_ObterContadorCorrente( ) ;
            if ( pNome != NULL )
            {
               sprintf( Msg ,  "Contagem: %5ld  Contador: \"%s\"" ,
                         CNT_ObterContagemCorrente( ) , pNome ) ;

               TST_ExibirPrefixo( "!!!" , Msg ) ;
            } else
            {
               return TST_NotificarFalha( "Iterador n�o est� ativo." ) ;
            } /* if */

            return TST_CondRetOK ;

         } /* fim ativa: Tratar CNT  &Iterador: exibir contador corrente */

      /* Tratar CNT  &Iterador: obter contagem corrente */

         else if ( strcmp( ComandoTeste , OBTER_CONTAGEM_CORR_CMD ) == 0 )
         {

            /*
               long CNT_ObterContagemCorrente( )
            */

            numLidos = LER_LerParametros( "i" ,
                               &IntEsp ) ;
            if ( numLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */

            return TST_CompararInt( IntEsp , CNT_ObterContagemCorrente( ) ,
                      "Contagem errada." ) ;

         } /* fim ativa: Tratar CNT  &Iterador: obter contagem corrente */

      /* Tratar CNT  &Iterator: obter nome de contador corrente */

         else if ( strcmp( ComandoTeste , OBTER_NOME_CONTADOR_CORR_CMD ) == 0 )
         {

            /*
               char * CNT_ObterContadorCorrente( )
            */

            numLidos = LER_LerParametros( "s" ,
                               Msg ) ;
            if ( numLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */

            pNome = CNT_ObterContadorCorrente( ) ;
            if ( pNome == NULL )
            {
               return TST_NotificarFalha( "Iterador n�o est� ativo." ) ;
            } /* if */

            return TST_CompararString( Msg , pNome ,
                      "Nome de contador errado. " ) ;

         } /* fim ativa: Tratar CNT  &Iterator: obter nome de contador corrente */

      /* Tratar CNT  &Iterador: avan�ar para o pr�ximo contador */

         else if ( strcmp( ComandoTeste , IR_PROX_CONTADOR_CMD ) == 0 )
         {

            /*
               void CNT_IrProximoContador( )
            */

            CNT_IrProximoContador( ) ;

            return TST_CondRetOK ;

         } /* fim ativa: Tratar CNT  &Iterador: avan�ar para o pr�ximo contador */

      /* Tratar CNT  &Iterator: verificar se o iterador est� ativo */

         else if ( strcmp( ComandoTeste , EH_ITERADOR_ATIVO_CMD ) == 0 )
         {

            /*
               int CNT_EhAtivoIterador( )
            */

            numLidos = LER_LerParametros( "i" ,
                               &IntEsp ) ;
            if ( numLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */

            return TST_CompararBool( IntEsp ,
                      CNT_EhAtivoIterador( ) ,
                      "Estado iterador ativo errado." ) ;

         } /* fim ativa: Tratar CNT  &Iterator: verificar se o iterador est� ativo */

      /* Tratar CNT  &Verificar a estrutura dos contadores */
      #ifdef _DEBUG

         else if ( strcmp( ComandoTeste , VERIFICAR_ESTRUTURA_CMD ) == 0 )
         {

            /*
               int CNT_VerificarEstruturaContadores( )
            */

            numLidos = LER_LerParametros( "i" ,
                               &IntEsp ) ;
            if ( numLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */

            return TST_CompararInt( IntEsp ,
                      CNT_VerificarEstruturaContadores( ) ,
                      "Estado errado da estrutura de dados." ) ;

         } /* fim ativa: Tratar CNT  &Verificar a estrutura dos contadores */
      #endif

      return TST_CondRetNaoConhec ;

   } /* Fim fun��o: TCNT &Teste de contador de passagem */

/********** Fim do m�dulo de implementa��o: TCNT Teste contadores de passagem **********/


#if ! defined( TESTALT_ )
#define TESTALT_
/***************************************************************************
*
*  $MCD M�dulo de defini��o: TALT Teste do gerador de n�meros aleat�rios
*
*  Arquivo gerado:              TESTALTnulo
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
*  $ED Descri��o do m�dulo
*     Testa e exemplifica o uso do gerador de n�meros aleat�rios
*
***************************************************************************/
 
#if defined( TESTALT_OWN )
   #define TESTALT_EXT
#else
   #define TESTALT_EXT extern
#endif


/***********************************************************************
*
*  $FC Fun��o: TALT &Efetuar o teste de fun��o do m�dulo aleatorio
*
***********************************************************************/

   TST_tpCondRet TST_EfetuarComando( char * ComandoTeste ) ;

#undef TESTALT_EXT

/********** Fim do m�dulo de defini��o: TALT Teste do gerador de n�meros aleat�rios **********/

#else
#endif

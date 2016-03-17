/*******************************************************************************
Autor: Alyson Felipe Oliveira Dantas
Componente Curricular: MI - Algoritmos - P04
Concluido em: 15/04/2015
Declaro que este código foi elaborado por mim de forma individual e não contém nenhum
trecho de código de outro colega ou de outro autor, tais como provindos de livros e
apostilas, e páginas ou documentos eletrônicos da Internet. Qualquer trecho de código
de outra autoria que não a minha está destacado com uma citação para o autor e a fonte
do código, e estou ciente que estes trechos não serão considerados para fins de avaliação.
******************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(int argc, char *argv[]) {
	float tarifa = 0;
	//variaveis dos aparelhos
	int tipo = 0;
	int nun_aparelho = 0;
	float pot_aparelho = 0;
	int hrs_aparelho = 0;
	int dia_aparelho = 0;
	//variaveis para os calculos
	float consumo1_aparelho = 0;
	float consumo2_aparelho = 0;
	float consumo_aparelho_reais =0;
	float consumo_total_aparelhos_setor = 0;
	float consumo_total_reais_setor = 0;
	float consumo_somado_aparelhos = 0;
	float consumo_somado_aparelhos_setor=0;
	
	int laco_repeticao1 = 1;
	float consumo_total_reais = 0;
	float consumo_total_aparelhos = 0;

	//variaveis dos impostos
	float ICMS = 27 / 100;
	float PIS = 1.65 / 100;
	float CONFINS = 7.61 / 100;
	float valor_ICMS = 0;
	float valor_PIS = 0;
	float valor_CONFINS = 0;
	
    int laco_repeticao2 = 1;
	float consumo_final = 0;


	printf("Ola, vamos descobrir o consumo de energia eletrica do(s) setor(es). \n");
	printf("Atenção! nesse programa so devem ser usados numeros ou '.' apenas.\n");
	printf("Qual o valor da taifa residencial? ");
	scanf("%f",&tarifa);
	//primeiro laço de repetição para o setor
	while(laco_repeticao2 == 1){
	printf("\nBem, esse vamos para esse setor para calcular assim que concluir esse pode calcular de outros.");
	//limpa o lixo de memoria das variaveis abaixo
    laco_repeticao2 = 1;
    laco_repeticao1 = 1;
    consumo_total_aparelhos_setor=0;
	consumo_total_reais_setor=0;
	//segundo laço de repetição para os aparelhos do setor
    while(laco_repeticao1 == 1){
	printf("\nVerifique que os aparelhos são catalogados como:\n Ar-condicionado = 1   Computador = 2   Geladeira = 3   Lampada = 4   Televisor = 5   Outro = 6\n");
	printf("\nEntão qual aparelho desse setor você deseja calcular o consumo agora?");
	scanf("%i",&tipo);
	printf("\nNesse setor quantos aparelhos tem? ");
	scanf("%i",&nun_aparelho);
	printf("\nQual a potencia desse aparelho? ");
	scanf("%f",&pot_aparelho);
	//potencia em W ja é divida por 1000 para efetuar o calculo em kW
	pot_aparelho = pot_aparelho / 1000;
	printf("\nA potencia do aparelho é: %f em kW.",pot_aparelho);
	printf("\nQual a quantidade de horas por dia que esse aparelho é usado? ");
	scanf("%i",&hrs_aparelho);
	printf("\nQual a quantidade de dias de uso no mes? ");
	scanf("%i",&dia_aparelho);
	

	//calculo do consumo em reais e em kwh dos aparelhos desse setor
	//Tambem guardar o valor dos aparelhos nesse setor em variaveis acumulativa
	consumo1_aparelho = ((hrs_aparelho * dia_aparelho)* pot_aparelho)* nun_aparelho;
	printf("\nO consumo total do(s) aparelho(s) por mes é %f",consumo1_aparelho);
	consumo_aparelho_reais = consumo1_aparelho * tarifa;
	printf("\nO consumo total em reais do(s) aparelho(s) é R$:%f",consumo_aparelho_reais);
	consumo_total_aparelhos_setor = consumo_total_aparelhos_setor + consumo1_aparelho;
	printf("\nO consumo de todos os aparelhos desse setor é: %f kWh",consumo_total_aparelhos_setor);
    consumo_total_reais_setor = consumo_total_aparelhos_setor * tarifa;
    printf("\nO consumo de todos os aparelhos desse setor em rais é R$: %f",consumo_total_reais_setor);
	printf("\nDeseja calcular o consumo de outro aparelho nesse setor? sim = 1 não = 0 \n");
	scanf("%i",&laco_repeticao1);

}
	//calculo do consumo em reais e em kWh de todos os setores sem impostos
	//guardar valor do gasto de cada setor em uma variavel acumulativa "consumo_total_reais e consumo_total_aparelhos" antes do fim do laço
    consumo_total_reais = consumo_total_reais + consumo_total_reais_setor;
    printf("\nO consumo total dos setores em reais é R$: %f",consumo_total_reais);
    consumo_total_aparelhos = consumo_total_aparelhos + consumo_total_aparelhos_setor;
    printf("\nO consumo total dos setores em kWh é: %f",consumo_total_aparelhos);
    printf("\nDeseja calcular outro setor alem deste? sim = 1 não = 0");
	scanf("%i",&laco_repeticao2);

}


   // calculo do total com os impostos.
   valor_ICMS = consumo_total_reais*ICMS;
   valor_CONFINS = consumo_total_reais*CONFINS;
   valor_PIS = consumo_total_reais*PIS;
   //soma dos impostos com o valor em reais final
   consumo_final = consumo_total_reais + valor_CONFINS + valor_ICMS + valor_PIS;
   printf("\nO valor total a pagar da conta de energia eletrica em reais é R$: %f",consumo_final);
   printf("\nAté mais.");

	return 0;
}

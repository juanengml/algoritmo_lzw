#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dicionario
{

char letras[5];

};
struct vetoresS{

char stiS[4];

};
int main()
{
    struct vetoresS endvetoresS[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    struct dicionario endicionario[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    char entrada[100];

    int i;
    int j;
    int l;
    int k = 3;

    int auxiliar;
    int auxS;
    int auxtamanho[10] = {0,0,0,0,0,0,0,0,0,0};
    int auxtamanho1;
    int vetordeS[10]= {0,0,0,0,0,0,0,0,0,0};
    int conttamanho;

    int conta = 0;
    int contb = 0;
    int contc = 0;
    int contd = 0;
    int conte = 0;
    int contf = 0;
    int contg = 0;
    int conth = 0;
    int conti = 0;
    int contj = 0;
    int contk = 0;
    int contl = 0;
    int contm = 0;
    int contn = 0;
    int conto = 0;
    int contp = 0;
    int contq = 0;
    int contr = 0;
    int conts = 0;
    int contt = 0;
    int contu = 0;
    int contv = 0;
    int contw = 0;
    int contx = 0;
    int conty = 0;
    int contz = 0;

    char S[4] = {0,0,0,0};
    char C[3] = {0,0,0};
    char SplusC[5] = {0,0,0,0,0};

    FILE *pArquivo;
    FILE *tArquivo;

    scanf("%[^\n]", entrada);

    for(i = 0;entrada[i] != '\0';i++)
	{
        if(entrada[i] == 'a'){
            conta++;
            if(conta == 1){
                strcpy(endicionario[i].letras, "a");
            }
        }
        if(entrada[i] == 'b'){
            contb++;
            if(contb == 1){
                strcpy(endicionario[i].letras, "b");
            }

        }
        if(entrada[i] == 'c'){
            contc++;
            if(contc == 1){
                strcpy(endicionario[i].letras, "c");
            }
        }
        if(entrada[i] == 'd'){
            contd++;
            if(contd == 1){
                strcpy(endicionario[i].letras, "d");
            }
        }
        if(entrada[i] == 'e'){
            conte++;
            if(conte == 1){
                strcpy(endicionario[i].letras, "e");
            }
        }
        if(entrada[i] == 'f'){
            contf++;
            if(contf == 1){
                strcpy(endicionario[i].letras, "f");
            }
        }
        if(entrada[i] == 'g'){
            contg++;
            if(contg == 1){
                strcpy(endicionario[i].letras, "g");
            }
        }
        if(entrada[i] == 'h'){
            conth++;
            if(conth == 1){
                strcpy(endicionario[i].letras, "h");
            }
        }
        if(entrada[i] == 'i'){
            conti++;
            if(conti == 1){
                strcpy(endicionario[i].letras, "i");
            }
        }
        if(entrada[i] == 'j'){
            contj++;
            if(contj == 1){
                strcpy(endicionario[i].letras, "j");
            }
        }
        if(entrada[i] == 'k'){
            contk++;
            if(contk == 1){
                strcpy(endicionario[i].letras, "k");
            }
        }
        if(entrada[i] == 'l'){
            contl++;
            if(contl == 1){
                strcpy(endicionario[i].letras, "l");
            }
        }
        if(entrada[i] == 'm'){
            contm++;
            if(contm == 1){
                strcpy(endicionario[i].letras, "m");
            }
        }
        if(entrada[i] == 'n'){
            contn++;
            if(contn == 1){
                strcpy(endicionario[i].letras, "n");
            }
        }
        if(entrada[i] == 'o'){
            conto++;
            if(conto == 1){
                strcpy(endicionario[i].letras, "o");
            }
        }
        if(entrada[i] == 'p'){
            contp++;
            if(contp == 1){
                strcpy(endicionario[i].letras, "p");
            }
        }
        if(entrada[i] == 'q'){
            contq++;
            if(contq == 1){
                strcpy(endicionario[i].letras, "q");
            }
        }
        if(entrada[i] == 'r'){
            contr++;
            if(contr == 1){
                strcpy(endicionario[i].letras, "r");
            }
        }
        if(entrada[i] == 's'){
            conts++;
            if(conts == 1){
                strcpy(endicionario[i].letras, "s");
            }
        }
        if(entrada[i] == 't'){
            contt++;
            if(contt == 1){
                strcpy(endicionario[i].letras, "t");
            }
        }
        if(entrada[i] == 'u'){
            contu++;
            if(contu == 1){
                strcpy(endicionario[i].letras, "u");
            }
        }
        if(entrada[i] == 'v'){
            contv++;
            if(contv == 1){
                strcpy(endicionario[i].letras, "v");
            }
        }
        if(entrada[i] == 'w'){
            contw++;
            if(contw == 1){
                strcpy(endicionario[i].letras, "w");
            }
        }
        if(entrada[i] == 'x'){
            contx++;
            if(contx == 1){
                strcpy(endicionario[i].letras, "x");
            }
        }
        if(entrada[i] == 'y'){
            conty++;
            if(conty == 1){
                strcpy(endicionario[i].letras, "y");
            }
        }
        if(entrada[i] == 'z'){
            contz++;
            if(contz == 1){
                strcpy(endicionario[i].letras, "z");
            }
        }

    }

        tArquivo = fopen("entradas.txt", "w");
        fprintf(tArquivo, "%s", entrada);
    for(i = 0;entrada[i] != '\0';i++){
        if(entrada[i] != ' '){
        C[0] = entrada[i];
        printf("C : %s\n", C);
        strcpy(SplusC,S);
        strcat(SplusC,C);
        printf("S + C : %s\n",SplusC);

        //VERIFICA SE S + C JA ESTA CONTIDA NO DICIONARIO
        for (j = 0;j < 20;j++){
            auxiliar = strcmp(endicionario[j].letras,SplusC);
            if(auxiliar == 0){
                break;
            }
            auxiliar = 5;
        }

        printf("Comparacao : %d\n", auxiliar);

        if(auxiliar == 0){
            strcpy(S,SplusC);
            printf("S : %s\n", S);
            printf("Saida : %d\n", i);
            //COMPARAR O VETOR S COM OS DO DICIONARIO
            for(j = 0;endicionario[j].letras[0] != '\0';j++){
                auxS = strcmp(S, endicionario[j].letras);
                if(auxS == 0){
                    printf("A VERDADEIRA SAIDA : %d\n", j);
                }
            }
            strcpy(endvetoresS[i].stiS,S);
        }
        if(auxiliar != 0){
            strcpy(endicionario[k].letras,SplusC);
            printf("Indice dicionario : %s\n", endicionario[k].letras);
            printf("Saida : %d\n", k);
            strcpy(S,C);
            printf("S : %s\n", S);
            k = k + 1;
            //COMPARA O VETOR S COM OS DO DICIONARIO
            for(j = 0;endicionario[j].letras[0] != '\0';j++){
                auxS = strcmp(S, endicionario[j].letras);
                if(auxS == 0){
                    printf("A VERDADEIRA SAIDA : %d\n", j);
                }
            }
            strcpy(endvetoresS[i].stiS,S);

        }

        printf("\n");

        }

       }
       for(i = 0;endicionario[i].letras[0] != '\0' ;i++){
            printf("conteudo do vetor eh : %s\n",endicionario[i].letras);
        }
        printf("\n");
        for(i = 0;i < 10;i++){
       auxtamanho[i] = strlen(endvetoresS[i].stiS);
       printf("%d\n", auxtamanho[i]);
        }
        printf("\n");
        pArquivo = fopen("saida.txt", "w");
        for(i = 0;i < 10;i++){
            if((auxtamanho[i] < auxtamanho[i + 1])&&( i < 9)){

            }
            else{
                for(j = 0;j < 10;j++){
                    auxtamanho1 = strcmp(endvetoresS[i].stiS,endicionario[j].letras);
                    if(auxtamanho1 == 0){
                        printf("%d ", j);
                        if(j == 9){
                        fprintf(pArquivo,"%d\n",j);
                        }else{
                        fprintf(pArquivo,"%d",j);
                        }
                    }

        }
}
            }
        fclose(pArquivo);
        fclose(tArquivo);
        printf("\n");

return 0;
}
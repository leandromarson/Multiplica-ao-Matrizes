#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//MULTIPLICACAO DE MATRIZ POR ESCALAR
void matrizAR(int la,int ca,int valorescalar,int lr,int cr){
    int x,y;//contador for
    int a[la][ca],matrizR[lr][cr],n;//matrizes e var aux
    for(x=0;x<la;x++){ //INSERINDO VALORES NA MATRIZ
        for(y=0;y<ca;y++){
        printf("\nDigite o valor contido em na linha %d , coluna %d\n",(x+1),(y+1));
        scanf("%d",&n);
        a[x][y]=n;
        matrizR[x][y]=(n*valorescalar);
        n=0;
        }
    }
    printf("\n");
    printf("---------------------------------------------\n");
    printf("IMPRIMINDO MATRIZ...\n");
    for(x=0;x<la;x++){
        for(y=0;y<ca;y++){
            if(y<ca-1){
                printf("%d | ",a[x][y]);
            }else if(y==ca-1){
                printf("%d",a[x][y]);
            }
        }
        printf("\n");
    }
    printf("\n");
    printf("IMPRIMINDO MATRIZ RESOLVIDA...\n");
    for(x=0;x<lr;x++){
        for(y=0;y<cr;y++){
            if(y<cr-1){
                printf("%d | ",matrizR[x][y]);
            }else if(y==cr-1){
                printf("%d",matrizR[x][y]);
            }
        }
        printf("\n");
    }
    printf("\n");
    printf("---------------------------------------------\n");
}
//MULTIPLICACAO DE MATRIZ POR MATRIZ
void matrizpormatriz(int la,int ca,int lb,int cb,int lr,int cr){
    int x,y,z;
    int a[la][ca],b[lb][cb],matrizR[lr][cr],n,av,bv;
    printf("MATRIZ A\n");
    for(x=0;x<la;x++){
        for(y=0;y<ca;y++){
            printf("\nDigite o valor contido em na linha %d , coluna %d\n",(x+1),(y+1));
            scanf("%d",&n);
            a[x][y]=n;
            n=0;
        }
    }
    printf("\nMATRIZ B\n");
    for(x=0;x<lb;x++){
        for(y=0;y<cb;y++){
            printf("\nDigite o valor contido em na linha %d , coluna %d\n",(x+1),(y+1));
            scanf("%d",&n);
            b[x][y]=n;
            n=0;
        }
    }
    //RESOLUCAO
    n=0;
    for(x=0;x<lr;x++){
        for(y=0;y<cr;y++){
            matrizR[x][y]=0;
            for(z=0;z<ca;z++){
                av=a[x][z];
                bv=b[z][y];
                n+=(av*bv);
            }
            matrizR[x][y]=n;
            n=0;

        }
    }
    printf("\n");
    printf("---------------------------------------------\n");
    printf("IMPRIMINDO MATRIZES...\n");
    printf("---------------------------------------------\n");
    printf("MATRIZ A\n");
    for(x=0;x<la;x++){
        for(y=0;y<ca;y++){
            if(y<ca-1){
                printf("%d | ",a[x][y]);
            }else if(y==ca-1){
                printf("%d",a[x][y]);
            }
        }
        printf("\n");
    }
    printf("---------------------------------------------\n");
    printf("\n");
    printf("---------------------------------------------\n");
    printf("MATRIZ B\n");
    for(x=0;x<lb;x++){
        for(y=0;y<cb;y++){
            if(y<cb-1){
                printf("%d | ",b[x][y]);
            }else if(y==cb-1){
                printf("%d",b[x][y]);
            }
        }
        printf("\n");
    }
    printf("---------------------------------------------\n");
    printf("IMPRIMINDO MATRIZ RESOLVIDA...\n");
    printf("---------------------------------------------\n");
    for(x=0;x<lr;x++){
        for(y=0;y<cr;y++){
            if(y<cr-1){
                printf("%d | ",matrizR[x][y]);
            }else if(y==cr-1){
                printf("%d",matrizR[x][y]);
            }
        }
        printf("\n");
    }
    printf("\n");
    printf("---------------------------------------------\n");
}
//FUNCAO MAIN
int main(int argc, char *argv[]) {
    int op;//contador switch
    int la,ca,lb,cb,lr,cr;//linhas e colunas
    int valorescalar;
    int x,y;//contador for
    do{
        printf("MULTIPLICACAO DE MATRIZES\n");
        printf("---------------------------------------------\n");
        printf("Digite 1 para Multiplicacao de Matriz Escalar\n");
        printf("Digite 2 para Multiplicacao de Matriz por Matriz\n");
        printf("Digite 0 para SAIR\n");
        printf("---------------------------------------------\n");
        scanf("%d",&op);
        printf("\n");
        switch(op){
            case 1:
                printf("---------------------------------------------\n");
                printf("Digite um numero!\n");
                scanf("%d",&valorescalar);
                printf("\n");
                printf("Digite o numero de linhas da matriz!\n");
                scanf("%d",&la);
                printf("\n");
                printf("Digite o numero de colunas da matriz!\n");
                scanf("%d",&ca);
                lr=la;
                cr=ca;
                matrizAR(la,ca,valorescalar,lr,cr);
            break;
            case 2:
                printf("---------------------------------------------\n");
                printf("Digite o numero de linhas da matriz A!\n");
                scanf("%d",&la);
                printf("\n");
                printf("Digite o numero de colunas da matriz A!\n");
                scanf("%d",&ca);
                printf("\n\n");
                printf("Digite o numero de linhas da matriz B!\n");
                scanf("%d",&lb);
                printf("\n");
                printf("Digite o numero de colunas da matriz B!\n");
                scanf("%d",&cb);
                lr=la;
                cr=cb;
                printf("\n");
                if(ca==lb){
                    matrizpormatriz(la,ca,lb,cb,lr,cr);
                }else{
                    printf("\n---------------------------------------------\n");
                    printf("Nao e possivel resolver a matriz(num. colunas de A diferente de num. linhas de B)!!\n");
                    printf("---------------------------------------------\n");
                }
            break;
            case 0:
                exit(1);
            break;
            default:
                printf("Comando invalido\n");
            break;
        }
    }while(1);
    system("pause");
    return 0;
}


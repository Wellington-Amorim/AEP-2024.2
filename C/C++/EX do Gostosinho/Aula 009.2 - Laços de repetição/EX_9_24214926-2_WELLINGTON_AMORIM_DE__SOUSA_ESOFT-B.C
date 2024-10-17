/*9)Soliciteaousuárioonome,idadeesexo(F/M)dealgumas
pessoas.Acadaentrevista,osistemadeveráperguntar
seousuáriodesejacontinuarainformardados,ecasonãoqueira,
apresenteamédiadeidadedasmulheres.*/
#include <stdio.h>

int main(){
    int idade, quant;
    char nome[20], sexo, continuar;
    float media=0;
    
    printf("Quantas pessoas voce quer fazer a intrevista?\n");
    scanf("%d",&quant);


        for(int i=1;i<=quant;i++){ 

        printf("NOME: \n");
        scanf("%s",nome);

        printf("IDADE: \n");
        scanf("%d",&idade);

        fflush(stdin);

        printf("SEXO(F/M): \n");
        scanf("%c",&sexo);

        if(sexo == 'f' || sexo == 'F'){
            media += idade;
        }

        fflush(stdin);
        
        printf("DESEJA CONTINUAR?(S/N)\n");
        continuar = getchar();

        if(continuar == 'n' || continuar == 'N'){
            i = quant;
        }else{}
        }

        media = media/quant;
        printf("A media eh %.2f\n",media);
        //------------------------------------------------------------------------------------------------------
        printf("\nQuantas pessoas voce quer fazer a intrevista?\n");
        scanf("%d",&quant);

        do{
            printf("NOME: \n");
            scanf("%s",nome);

            printf("IDADE: \n");
            scanf("%d",&idade);

            fflush(stdin);

            printf("SEXO(F/M): \n");
            scanf("%c",&sexo);

            fflush(stdin);
        
            printf("DESEJA CONTINUAR?(S/N)\n");
            continuar = getchar();
    
        }while(continuar != 'n' || continuar != 'N');
    
return 0;    
}

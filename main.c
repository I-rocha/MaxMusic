#include<stdio.h>
#include<stdlib.h>
#define NONE -1



void MaxMusic(long int *musicas, long int ref,long int i , long int f, long int *soma){

	if(i <= f-1){
		if(musicas[i]+musicas[f] > ref)
			MaxMusic(musicas, ref, i, f-1, soma);

		else if(musicas[i]+musicas[f] < ref){
            *soma = (musicas[i] + musicas[f] > *soma)?(musicas[i] +musicas[f]) : (*soma);
			MaxMusic(musicas, ref, i+1, f, soma);
		}
		else{
            *soma = musicas[i] + musicas[f];
        }
	}

	return;
}

void Merge(long int *musicas, long int i, long int f){      //(vetor, inicio, fim)
	long int cont = 0, q = (i+f)/2 ;               //(vetor auxiliar, ... , posicao media baixa
	long int tam = (f-i)+1, faux = tam-1, iaux =  0;                                 //tamanho
    long int aux[tam];

	if(i == f)
		return;
	else{
		Merge(musicas, i, q);
		Merge(musicas, q+1, f);
	}

	while(iaux < faux){
        aux[iaux++] = musicas[i + cont];
        aux[faux--] = musicas[q +1+ cont++];
	}
    if(iaux == faux) aux[iaux] = musicas[i + cont];


	long int ia=0, ja=0;
	ia = 0;
	ja = tam-1;
	cont = i;
	while(ia <= ja){
		musicas[cont++] = (aux[ia] <= aux[ja])?aux[ia++]:aux[ja--];
	}
	return;
}

void printar(long int *vet, long int tm){
    long int cont =0 ;

    for(cont=0; cont < tm; cont++)
        printf("%li ", vet[cont]);

}

int main(){
	long int num = 0, x = 0, cont=0;            //num == qtd musica, x = valor de referencia
	long int soma;
    soma = NONE;

	scanf("%li %li", &num, &x);                   ///qtd musica, referencia

	long int musicas[num];

	while(cont<num)
		scanf("%li", &musicas[cont++]);              //armazena o tempo de cada musica

	Merge(musicas, 0, num-1);                       //ordena vetor
	MaxMusic(musicas, x, 0, num-1, &soma);        //funcao atualiza soma

	//printar(musicas, num);
    if(soma == NONE)
        printf("NONE");
    else
        printf("%li", soma);
}






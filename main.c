#include<stdio.h>
#include<sdlib.h>

typedef struct{
	long int min, max;
}Soma;

void MaxMusic(*musicas, ref, f){
	long int i=1, j = f-1;
	Soma musica;
	musica.min = musicas[0];
	musica.max = musicas[f];

	while(i<=j){
		if(musica.min+musica.max > ref)
			musica.max = musicas[j--];
		else if(musica.min+musica.max < ref)
			musica.min = musicas[i++];
		else
			return musica;
	}


}

void Merge(long int *musicas, long int i, long int f){
	long int aux[f+1], cont= 0, q = (f+i)/2 ;
	long int tam = (f-i)+1;

	if(i == f)
		return;
	else{
		Merge(musicas, 0, q);
		Merge(musicas, q+1, f);
	}
	for(cont = 0; cont <= tam/2; cont++){
		aux[cont] = *musicas[i+cont];
		aux[cont + (tam+1)/2] = *musicas[f-cont];
	}

	long int ia=0, ja=0;
	ia = 0;
	ja = tam-1;
	cont = i;
	while(ia <= ja){
		musicas[i++] = (aux[ia] <= aux[ja])?aux[ia++]:aux[ja--];
	}
	return
}


int main(){
	long int num = 0, x = 0, cont=0;

	scanf("%li %li", num, x);

	long int musicas[num];

	while(cont<num)
		scanf("%li", musicas[cont++]);

	Merge(musicas, 0, num-1);
	MaxMusic(musicas, x, num-1);
}

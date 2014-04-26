#include "leitura.c"
int main(int argc,char *argv[]){
	printf("\nEstrutura do meta.dat:\n");
	int num_campos = getCampos(argv[1]); // recebe quantos campos terá cada tupla;
	struct pagina *bufpool;
	bufpool=(struct pagina *)malloc(sizeof(struct pagina)*paginas);
	campo c[num_campos];
	iniciaBuffer(bufpool);
	readMeta(argv[1],&*c,num_campos); // chamada de função para ler arquivo contendo os metadados (usando o nome do arquivo, o endereço da variavel campo que recebe os parametros e o total de campos todos como parametro)
	readData(argv[2],bufpool,c, num_campos); // chamada de função para ler arquivo contendo os dados usando o nome do arquivo, a variavel contendo os metadados e o total de campos como parametro.
	printf("\nImpressão de um registro de uma página:");
	
	//      numero da pagina  numero do registro      
	//                     |  |          
	imprimeTupla(bufpool, c, 0, 7, tamtupla, num_campos);
	return 0;		
}

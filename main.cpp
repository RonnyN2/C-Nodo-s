//This proyect is divided by structure, and form to create an application of all the topics seems in Programation Class. In a correct and funtional structure
//Libraries
#include<iostream>
//Node's_Proyect
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

//VariablesMultiusage
/*
int n,i,r,j, valor, f=2;
struct nodo *head, *bot, *p, *p1, *pp, *pn, *q, *q1 , *q2;
int a[4][4] = { {0,1,1,0}, {0,0,0,1}, {0,0,0,1}, {0,0,0,0} };
*/

//Variable_Definitions
struct nodo *head; //cab = head
struct nodo *bot; //bot = bottom/fin

//Nodo's_Structuration
struct nodo{
	//Data_Fields
	int fact1;//Fact Igual Dato
	int fact2;//Fact Igual Dato Variable according to Matrix Nodo's
	int factList[];
	int factMatrix[][];
	//Links 
	struct nodo *link;  //link predetermined 
	struct nodo *link1; //link 2 or enlace2
	struct nodo *link2; //link 1 or enlace1
	struct nodo *linkL; //left link 
	struct nodo *linkR; //right link 
};

//Functions_Definition (9)
void menu();
//Basic Nodos functions
void nodoCreation();
void showNodo1();
void insertNodo1link();
void eliminateNodoLR(int a);
void showNodo2();
//Matrix and graph Nodos Creators
void graphCreation();
void graphShow();
void nodoMatrizCreation();
void showMatrixNodo();

//Functions to create a graph according to a adyacense matrix
void linkCreator(); //Creador de apuntadores
void matrix_graphCreatorAD(); //creador del grafo mediante la matriz de adyacencia
void valueAsignator();
void showMGCAD(); // show matrix_graphCreatorAD
void showGraph_op2(); //a second way to show the graph

//Main_Structure
int main(){
	void menu();
}

//Main Function
void menu(){
	printf("");
}

//General Functions
void nodoCreation(){
	int n, value;
	struct nodo *p, *q;
	for(n=0;n<4;n++){
		p = (struct nodo*)malloc(sizeof(struct nodo));
		printf("\n -Enter a data to Nodo %d: ", n+1);
		scanf("%d", &value);
		p->fact1 = value;
		
		//if to Nodo assignment
		if(n==0){
			head = p;
			q = p;
		}else{
			q->linkR = p;
			p->linkD = q;
			q = p;
		}
	}
	bot = p;
}

void showNodo1(){
	p = head;
	for(n=0;n<4;n++){
		printf("The value of nodo %d is: %d\n", n+1, p->fact1);
		p = p->linkR; 
	}
	printf("---/---/---/---/---/---/---/---/---\n");
	p = bot;
	for(n=0;n<4;n++){
		printf("The value of Nodo %d is: %d", n+1, p->fact1);
		p = p->linkD;
	}
	printf("\n---/---/---/---/---/---/---/---/---\n");
}

void insertNodo1link(){ //FUNTION TO CORRECT AND REMAKE
	printf("Insert a new nodo function");
	p = head;
	for(n=0;n<4;n++){
		q1 = p->link1;
		printf("Enter a value to new nodo: ");
		scanf("%d", &value);
		
		pn= (struct nodo*)malloc(sizeof(struct nodo));
		pn->fact1 = value;
		pn->link1 = p1;
	}	
	p = p->link1;
}

void eliminateNodoLR(int a){
	p = bot;
	for(n=0;n<4;n++){
		if(p->fact1 ==a){
			q = p->linkD;
			pp = p->linkR;
			
			q->linkR = pp;
			pp->linkD = q;
		}
		p = p->linkD;
	}
}

void showNodo2(){
	printf("Show New Nodo (Nodo 2)");
	p = head;
	for(n=0;n<3;n++){
		printf("The value of Nodo %d is: %d", n+1, p->fact1);
		p = p->linkR;
	}
	printf("---/---/---/---/---/---/---/---/---\n");
	p = bot;
	for(n=3;n>0;n--){
		printf("The value of Nodo %d is: %d", n+1, p->fact1);
		p = p->linkD;
	}
}

//Matrix and graph Nodos Creators
void graphCreation(){
	int n, value;
	struct nodo *p, *q, *q1, *q2;
	for(n=0;n<4;n++){
		if(n==0){
			p = (struct nodo*)malloc(sizeof(struct nodo));
			printf("\n Enter a value to Nodo %d: ", n+1);
			scanf("%d", &value);
			p-> fact1 = value;
			q = p;
			head = p;
		}
		if(n==1){
			p = (struct nodo*)malloc(sizeof(struct nodo));
			printf("\n Enter a value to Nodo %d: ", n+1);
			scanf("%d", &value);
			p-> fact1 = value;
			q-> link1 = p;
			q1 = p;
			//second Nodo creator (graph)
			p = (struct nodo*)malloc(sizeof(struct nodo));
			printf("\n Enter a value to Nodo %d: ", n+1);
			scanf("%d", &value);
			p-> fact1 = value;
			q-> link2 = p;
			q2 = p;
		}
		if(n==2){
			p = (struct nodo*)malloc(sizeof(struct nodo));
			printf("\n Enter a value to Nodo %d: ", n+1);
			scanf("%d", &value);
			p-> fact1 = value;
			q1-> p;
			q2-> p;
		}
	}
}

void graphShow(){
	p = head;
	n = 0;
	if(n==0){
		q = p;
		q1 = q->link1;
		q2 = q->link2;
		printf("	%d		\n", p->fact1);
	}
	for(n=1;n<2;n++){
		p = q1;
		printf("%d		", p->fact1);
		p = q2;
		printf("%d\n", p->fact1);
		q1 = q1-> link1;
		q2 = q2->link2;
	}
	if(n==2){
		p = q1;
		printf("		%d", p->fact1);
	}
}

//row and column (fila y columna)
void nodoMatrizCreation(){
	for(n=0;n<f;n++){
		p= (struct nodo*)malloc(sizeof(struct nodo));
		for(i=0;i<f;i++){
			for(j=0;j<f;j++){
				printf("Enter the value-row %d column %d to Nodo %d: \n", (i+1), (j+1), (n+1));
				scanf("%d", &value);
				p->fact2[i][j] = value;
			}	
		}
		if(n==0){
			q = p;
			head = p;
		}else{
			q->link1 = p;
			q = p;
		}
	}
}

void showMatrixNodo(){
	p = head;
	for(n=0;n<f;n++){
		printf("\nThe values to Nodo %d are: \n", n+1);
		for(i=0;i<f;i++){
			prinf("{");
			for(j=0;j<f;j++){
				printf("%d, ", p->fact2[i][j]);
			}
			printf("}");
		}
		p = p->link1;
	}
}

//Adyacense Matrix Functions
void linkCreator(){
	for(n=0;n<4;n++){
		b[n] = (struct nodo*)malloc(sizeof(struct nodo));
	}
	head = b[0];
} 

void matrix_graphCreatorAD(){
	for(n=0;n<4;n++){
		for(i=0;i<4;i++){
			if(a[n][i] == 1){
				b[n]->c[r] = b[i];
				r++;
			}
		}
	}
} 

void valueAsignator(){
	for(n=0;n<4;n++){
		printf("Enter a value to Nodo %d: ",n+1);
		scanf("%d",&value);
		b[n]->fact1 = value;
	}
}

void showMGCAD(){
	n=0;
	if(n==0){
		printf("		%d		\n", b[0]->fact1);
	}
	for(){
		printf("%d		", b[n]->dato);
		prtinf("%d\n",b[n+1]->dato);
		n++;
	}
	printf("	%d",b[3]->dato);
} 

void showGraph_op2(){
	p = b[0];
	q1 = p->c[0];
	q2 = p->c[1];
	printf("		%d		\n", p->fact1);
	
	for(n=1;n<2;n++){
		p = q1;
		printf("%d			", p->fact1);
		p = q2;
		printf("%d\n",b[n+1]->dato);
		q1 = q1->c[0];
		q2 = q2->c[1];
	}
	p = q1;
	printf("		%d", p->fact1);
}







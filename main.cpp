/**
 * @file main.cpp
 * @brief Aplicación modular para la manipulación de estructuras de datos (Listas, Matrices y Grafos).
 * @author Ronny <stevenalmeida162@gmail.com>
 * @author Tomas <180095.licbir@gmail.com>
 * @date 2026-10-02
 * @version 1.0
 * @details This project demonstrates fundamental and advanced pointer operations, dynamic 
 *          memory management, and structure interactions in C++. It covers the creation, 
 *          traversal, and deallocation of nodes across linked lists, matrix nodes, and 
 *          adjacency graphs.
 */
 
//Node's_project
#include <iostream>
#include <cstdio>
#include <cstdlib>
//Structure_Definition
/**
*@brief Represents a node in a doubly linked list.
*/
/*STRUCTURE DEFINITIONS*/

struct listNode{
	int data;			/**< Value stored in the node. */
	listNode* next;		/**< Pointer to the next node. */
	listNode* prev;		/**< Pointer to the previous node */
	
	//Constructor to a Clean Inicializate
	listNode(int val) : data(val), next(nullptr), prev(nullptr){} // : show the list inicialization with the values
};

//Structure_Definition
/**
*@brief Represents a node storing a 2x2 integer matrix.
*/
struct matrixNode{
	int matrixData[2][2];		/**< Fixed 2x2 matrix payload.*/
	matrixNode* next;			/**< Pointer to the next matrix node.*/
	matrixNode() : next(nullptr){
		//Inicializate matrix in 0s
		for(int i=0;i<2; i++){
			for(int j=0; j<2;j++){
				matrixData[i][j] = 0;
			}
		}
	}
};

//Functions_Definition (9)
void menu(listNode*& listHead, listNode*& listBot, matrixNode*& matrixHead);

//Basic Nodos functions
void nodoCreation(listNode*& head, listNode*& bot);
void showNodo1(const listNode* head, const listNode* bot);
void insertNodo1link(listNode*& head);
void eliminateNodoLR(listNode*& head, listNode*& bot, int a);
void showNodo2(const listNode* head, const listNode* bot);
void nodoMatrixCreation(matrixNode*& head);
void showMatrixNodo(const matrixNode* head);

//Matrix and graph Nodos Creators ---------(FUNCTIONS IN DEVELOPMENT)---------
/*
void graphCreation(graphNode*& head);
void graphShow(const graphNode* head);
*/

//Main_Structure
int main(){
	listNode* listHead = nullptr;
	listNode* listBot = nullptr;
	matrixNode* matrixHead = nullptr;
	
	menu(listHead, listBot, matrixHead);
	return 0;
}

/*MENU IMPLEMENTATION*/
void menu(listNode * & listhead, listNode * & listBot, matrixNode * & matrixHead) {
  int option1 = 1;
  int option2 = 1;
  int target = 0;
  do {
    printf("=============================================\n");
    printf("               OPTIONS MENU                  \n");
    printf("=============================================\n");

    printf("---Node creation Functions---\n");
    printf("  1.Create Doubly linked list\n"); //Node creation
    printf("  2.Create Matrix nodes\n"); //nodoMatrixCreator
    printf("  3.Create a graph\n"); //graphcreator
    printf("  0.Exit Program\n");

    printf("Select an Option: ");
    scanf("%d", & option1);
    //Switch Case to use the options
    switch (option1) {
    case 1: {
      bool OptionDetect = false; // boolean variable that will show a different option on the submenu if the list is changed
      nodoCreation(listhead, listBot);
      do {
        printf("---List Node Functions---\n");
        if (OptionDetect == true) {
          printf("1.Show List Subset\n"); //ShowNodo
        } else {
          printf("1.Show List Forward and Backward\n"); //ShowNodo2
        }
        printf("2.Insert Node in list\n"); //insertNodo1Link
        printf("3.Eliminate node by Value\n"); //EliminateNodoRL
        printf("0.Exit Program\n");
        printf("--------------------------------------------\n");
        printf("Select an Option: ");
        scanf("%d", & option2);
        switch (option2) {
        case 1:
          if (OptionDetect == true) {
            showNodo2(listhead, listBot);
          } else {
            showNodo1(listhead, listBot);
          }
          break;
        case 2:
          insertNodo1link(listhead);
          OptionDetect = true;
          break;
        case 3:
          printf("Enter value to eliminate: ");
          scanf("%d", & target);
          eliminateNodoLR(listhead, listBot, target);
          OptionDetect = true;
          break;
        case 0:
          printf("\nReturning to main menu...\n");
          break;
        default:
          printf("\nInvalid Option. Try again\n");
          break;
        }
      } while (option2 != 0);
      break;
    }
    case 2:
      nodoMatrixCreation(matrixHead);
      do {
        printf("---Matrix Node Functions---\n");
        printf("1.Show Matrix Nodes\n\n"); // ShowMatrixNodes
        printf("0. go back\n");
        printf("--------------------------------------------\n");
        printf("Select an Option: ");
        scanf("%d", &option2);

        switch (option2) {
        case 1:
          showMatrixNodo(matrixHead);
          break;
        case 0:
          printf("\nExiting application...\n");
          break;
        default:
          printf("\nInvalid Option. Try again\n");
          break;
        }
      } while (option2 != 0);
      break;

    case 0:
      printf("\nExiting application...\n");
      break;

    default:
      printf("\nInvalid Option. Try again\n");
      break;
    }
  } while (option1 != 0);
}
//General Functions
void nodoCreation(listNode*& head, listNode*& bot){
	int n, value;
	listNode* p = nullptr;
	listNode* q = nullptr;
	for(n=0;n<4;n++){
		printf("\n -Enter a data to Nodo %d: ", n+1);
		scanf("%d", &value);
		p= new listNode(value);
		
		//if to Nodo assignment
		if(n==0){
			head = p;
			q = p;
		}else{
			q->next = p;
			p->prev = q;
			q = p;
		}
	}
	bot = p;
	printf("List created successfully.\n");
}

void showNodo1(const listNode* head, const listNode* bot){
	int n;
	const listNode* p = head;
	for(n=0; n<4 && p != nullptr; n++){
		printf("The value of nodo %d is: %d\n", n+1, p->data);
		p = p->next; 
	}
	
	printf("---/---/---/---/---/---/---/---/---\n");
	
	p = bot;
	for(n=0; n<4 && p != nullptr; n++){
		printf("The value of Nodo %d is: %d\n", n+1, p->data);
		p = p->prev;
	}
	printf("\n---/---/---/---/---/---/---/---/---\n");
}

void insertNodo1link(listNode*& head){ 
	int value;
	printf("Insert a new nodo function: ");
	scanf("%d", &value);
	
	listNode* pn = new listNode(value);
	pn ->next = head;
	if(head != nullptr){
		head -> prev = pn;
	}
	head = pn;
}

void eliminateNodoLR(listNode*& head, listNode*& bot, int a){
	int n;
	listNode* p = bot;
	listNode* q = nullptr;
	listNode* pp = nullptr; 
	for(n=0; n<4 && p != nullptr; n++){
		if(p->data == a){
			q = p->prev;
			pp = p->next;
			
			if(q != nullptr) q->next = pp;
			else head = pp;

			if(pp != nullptr) pp->prev = q;
			else bot = q;

			delete p;
			printf("Node eliminated successfully.\n");
			return;
		}
		p = p->prev;
	}
	printf("Node not found.\n");
}

void showNodo2(const listNode* head, const listNode* bot){
	int n;
	const listNode* p = head;
	
	printf("Show New Nodo (Nodo 2)\n");
	p = head;
	for(n=0; n<3 && p != nullptr; n++){
		printf("The value of Nodo %d is: %d\n", n+1, p->data);
		p = p->next;
	}
	printf("---/---/---/---/---/---/---/---/---\n");
	p = bot;
	for(n=3; n>0 && p != nullptr; n--){
		printf("The value of Nodo %d is: %d\n", n+1, p->data);
		p = p->prev;
	}
}

//Matrix functions (fila y columna)
void nodoMatrixCreation(matrixNode*& head){
	int i, j, n, value;
	int f = 2; //value 2x2 matrix
	matrixNode *p = nullptr;
	matrixNode *q = nullptr; 
	for(n=0;n<f;n++){
		p= new matrixNode();
		for(i=0;i<f;i++){
			for(j=0;j<f;j++){
				printf("Enter the value-row %d column %d to Nodo %d: \n", (i+1), (j+1), (n+1));
				scanf("%d", &value);
				p->matrixData[i][j] = value;
			}	
		}
		if(n==0){
			q = p;
			head = p;
		}else{
			q->next = p;
			q = p;
		}
	}
}

void showMatrixNodo(const matrixNode * head){
	int n, i, j;
	int f=2;
	const matrixNode *p = head;
	for(n=0; n<f && p != nullptr; n++){
		printf("\nThe values to Nodo %d are: \n", n+1);
		for(i=0;i<f;i++){
			printf("{");
			for(j=0;j<f;j++){
				printf("%d, ", p->matrixData[i][j]);
			}
			printf("}\n");
		}
		p = p->next;
	}
}
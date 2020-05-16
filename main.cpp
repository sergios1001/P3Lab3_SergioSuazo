#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int menu(){
	int retValue=0;
	
	while(retValue < 1 || retValue > 5){
		
		cout<<"         MENU"<<endl
			<<"1.- Jugar con matriz random"<<endl
			<<"2.- Jugar con matriz predefinida"<<endl
			<<"3.- Salir"<<endl
			<<"Ingrese una opcion entre 1 y 3: ";
			
			cin>>retValue;

			
			if(retValue >= 1 && retValue <= 5){
				break;
			}
				
			else{
						
				cout<<endl<<"Opcion incorrecta, elija nuevamente "<<endl;
			}
					
	}//end while
	
	
	return retValue;
}

void printMatrix (int** mat, int x, int y)
{
	if(mat!=NULL){
		cout<<"##############################################################";
		for(int i = 0; i<x;i++){
			for(int j=0;j<y;j++){
				if(j==0)
				{
					cout<<"# ";
				}
				if(mat[i][j]==1)
				{
					cout<<" * ";
				}
				else
				{
					cout<<"   ";
				}
				if(j==y-1)
				{
					cout<<" #";
				}
			}
			cout<<endl;
		}//forj
		cout<<"###############################################################"<<endl;
	}//endif
}

int** fillMatrix(int x, int y)
{
	int ** mat ;
	mat = new int*[y];
	for(int i = 0; i < y ; i++)
	{
		mat[i] = new int[x];
	}
	
	for(int i=0;i<x;i++)
	{
		for(int j=0;j<y;j++)
		{
			mat[i][j]= 0+rand()%(2-0);
		}
	}
	
	return mat;
}

int cantidadVecinos(int** mat,int x, int y,int size1, int size2)
{
	int vecinos=0;
	
	for(int i=x-1;i<x+2;i++)
	{
		for(int j=y-1;j<y+2;j++)
		{
			if(i!=x||j!=y)
			{
				if(!(i<0||i>=size1||j<0||j>=size2))
				{
					vecinos=vecinos+mat[i][j];
				}
			}
		}
	}
	
	return vecinos;
}

int nuevoEstado(int** mat,int fila,int col, int size1, int size2)
{
	int celula;
	int vecinos=cantidadVecinos(mat,fila,col,size1,size2);
	
	if(mat[fila][col]==1)
	{
		if(vecinos<=1||vecinos>=4)
		{
			celula=0;
		}
		else
		{
			celula=1;
		}
	}
	else
	{
		if(vecinos==3)
		{
			celula=1;
		}
		else
		{
			celula=0;
		}
	}
	
	return celula;
}



void conway(int** mat,int x,int y, int turnos)
{
	if (turnos==0)
	{
		cout<< "Final de la Simulacion"<<endl;
	}
	else
	{
		printMatrix(mat,x,y);
		
		getch();
		
		int ** newMat ;
		newMat = new int*[y];
		for(int i = 0; i < y ; i++)
		{
			newMat[i] = new int[x];
		}
		
		for(int i=0;i<x;i++)
		{
			for(int j=0;j<y;j++)
			{
				
				newMat[i][j]=nuevoEstado(mat,i,j,x,y);
			}
			//cout<<"pointer "<<endl;
		}
		//printMatrix(newMat,x,y);
		
		conway(newMat,x,y,turnos-1);
	}
}


int main(int argc, char** argv) {
	int option=0;
	while( option != 3 ) {
		
		switch( option = menu() ){ 
		
			case 1:{
				
				int x,y,turnos;
				cout<<"Ingrese el tamano en x del tablero: ";
				cin>>x;
				cout<<"Ingrese el tamano en y del tablero: ";
				cin>>y;
				cout<<"Ingrese la cantidad de turnos por hacer: ";
				cin>>turnos;
				int ** mat ;
				mat = new int*[y];
				for(int i = 0; i < y ; i++)
				{
					mat[i] = new int[x];
				}
				
				mat=fillMatrix(x,y);
				
				conway(mat,x,y,turnos);
				
				break;
			}
			case 2:{

				int x,y,turnos;
				
				cout<<"Ingrese la cantidad de turnos por hacer: ";
				cin>>turnos;
				
				x = 20;
				y = 20;
				
				int temp_mat [20][20] = {
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,1,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,0,0},
					{0,0,1,0,0,0,0,0,0,1,1,1,0,0,0,0,1,0,1,0},
					{0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
					
					};
					
				int ** mat = new int*[y];
				for(int i = 0; i < y ; i++){
					mat[i] = new int[x];
					for(int j = 0; j < x ; j++){
						mat[i][j] = temp_mat[i][j];
					}
				}
				
				conway(mat, x, y, turnos);

				
				break;	
			} 
			    
			case 3:{

				//salir
				cout<<"Saliendo del programa..."<<endl;
				break;

			}
						
		}//switch
	
	}//while
	return 0;
}

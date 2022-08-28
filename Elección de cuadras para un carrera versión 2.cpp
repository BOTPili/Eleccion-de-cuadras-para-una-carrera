#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

//-----------------------------------------------------------------------------------------

#define tam 50

//-----------------------------------------------------------------------------------------

void carga (int *s_a, int *s_b, int *hab, int *a, int *b, int *vhab); 

//-----------------------------------------------------------------------------------------

void evaluacion (int *v_a, int *v_b, int *v_hab, int *max_dif, int *max_neut, int *c_cuadras); 

//-----------------------------------------------------------------------------------------

void informar (); 

//-----------------------------------------------------------------------------------------

main (){
	
	int habitantes[tam]={0};
	int socios_a[tam]={0};
	int socios_b[tam]={0};
	int max_dif_soc;
	int max_neutrales;
	int cant_cuadras=0;
	int opcion, i=0;
	int soc_a;
	int soc_b;
	int c_hab;
	
	
//-----------------------------------------------------------------------------------------
	
	printf("Ingrese la m%cxima diferencia entre socios A y B: \n",160);
	fflush(stdin);
	scanf("%d", &max_dif_soc);
	
//-----------------------------------------------------------------------------------------
	
	printf("Ingrese la m%cxima cantidad de habitantes neutrales:\n",160);
	fflush(stdin);
	scanf("%d", &max_neutrales);
	system("pause");
	system("cls");	
	
//-----------------------------------------------------------------------------------------
		
	do{
	
		system("cls");
		printf("Bienvenido/a.\n\n");
		
		informar ();
		
		printf("\n\n");
		printf("Ingrese la opci%cn que corresponda:\n",162);
		printf("\n\n");
		printf("1. Ingreso de datos de cuadra.\n");
		printf("2. Evaluaci%cn por cuadra.\n",162);
		printf("3. Salir.\n\n");
		scanf("%d", &opcion);
		printf("+----------------------------------+\n");
		
		
				
		switch(opcion){
			
			case 1: 
			    
			        printf("Ingrese la cantidad de habitantes: \n");
					fflush(stdin);
					scanf("%d", &c_hab);
					printf("Ingrese la cantidad de socios del club A: \n");
					fflush(stdin);
					scanf("%d", &soc_a);
					printf("Ingrese la cantidad de socios del club B: \n");
					fflush(stdin);
					scanf("%d", &soc_b);
					cant_cuadras++;				
					carga(socios_a, socios_b, habitantes, &soc_a, &soc_b, &c_hab);
					
					break;
			
			case 2:
				system("cls");
								
				evaluacion(socios_a, socios_b, habitantes, &max_dif_soc, &max_neutrales, &cant_cuadras);
				
				getch();
			   
				break;
			
			case 3: 
			    printf("+----------------------------------+\n");
        		printf("| Usted est%c saliendo del programa. |\n",160);
        		printf("+----------------------------------+\n");
        		
                getch();
                
                break;
			
			default: 
			    system("cls");
				
				printf("La opci%cn seleccionada es incorrecta.\n",162);
				printf("Por favor ingrese su elecci%cn nuevamente.\n",162);	
				
				getch();
				
				break;
				    
		}		
    }while(opcion!=3);
}

//------------------------------------------------------------------------------------------

void carga (int *s_a, int *s_b, int *hab, int *a, int *b, int *vhab){ 
	
	static int i=0;
	
	*(s_a+i) = *a;
	*(s_b+i) = *b;
	*(hab+i) = *vhab;
	
	i++;
}

//-----------------------------------------------------------------------------------------

void evaluacion (int *v_a, int *v_b, int *v_hab, int *max_dif, int *max_neut, int *c_cuadras){


	int x;
	int dif=0;
	int neu=0;
	int soc=0;
	int max_soc=0;
	int cont_no=0;
	int cont_si=0;

//-----------------------------------------------------------------------------------------
	for(x=0;x<*c_cuadras;x++){ //CALCULA LA DIFERENCIA ENTRE SOCIOS A Y B
	
		if(*(v_a+x)>*(v_b+x)){
			dif=*(v_a+x)-*(v_b+x);
		}else{
			dif=*(v_b+x)-*(v_a+x);
		}
		
		soc = *(v_a+x) + *(v_b+x);//CALCULA SOCIOS TOTALES
		
		neu = *(v_hab+x) - soc;//CALCULA HABITANTES NEUTRALES
	
		if(neu > *max_neut || dif > *max_dif){
			
			printf("+-----------------------------------------------+\n");
        	printf("| La cuadra [%d] no es elegible para la carrera  |\n",x+1);
        	printf("+-----------------------------------------------+\n"); 
			
			cont_no++;//CUENTA LAS CUADRAS NO HABILITADAS 
			
		}else{
		
			printf("+-----------------------------------------------+\n");
        	printf("| La cuadra [%d] es elegible para la carrera     |\n",x+1);
        	printf("+-----------------------------------------------+\n");
			cont_si++;//CUENTA LAS CUADRAS HABILITADAS
			
			
			if(x==0){  //SACA LA MAYOR CANTIDAD DE SOCIOS ESPECTADORES
				max_soc=soc;
			}else{
				if(max_soc<soc){
					max_soc=soc;
				}
			}
		}	
	}
	printf("+-------------------------------------------------------+\n");
    printf("| La cantidad de cuadras elegibles son:[%d]              |\n",cont_si);
    printf("| La cantidad de cuadras no elegibles son:[%d]           |\n",cont_no);
    printf("| La cantidad de socios m%cximos presenciales son:[%d]   |\n",160,max_soc);
    printf("+-------------------------------------------------------+\n");
	
}

//------------------------------------------------------------------------------------------

void informar (){ //INFORMA PAUTAS DE ELECCION
	
	printf("+----------------------------------------------------------------------------------------------------+\n");
    printf("|Para que una cuadra sea elegida:                                                                    |\n");
    printf("|                                                                                                    |\n");
    printf("|1. La diferencia de HAB NEUTRALES no debe ser mayor a los SOCIOS A y B.                             |\n");
    printf("|2. La diferencia entre SOCIOS A y B no debe ser mayor a la ingresada                                |\n");
    printf("+----------------------------------------------------------------------------------------------------+\n");
	
}

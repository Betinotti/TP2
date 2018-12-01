#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXNOMBRE 50
#define MAXLOCALIDAD 30
#define MAXPAIS 25
#define MAXPROVINCIA 25
#define MAXSUCURSALES 9999
#define MINSUCURSALES 0
#define MAXVENDEDOR 75
#define MAXOPCION 5
#define CODSALIDA 0

/*para las opciones de los menus*/
#define OP1 1
#define OP2 2
#define OP3 3
#define OP4 4
#define OP5 5

typedef struct{

     int  sucursal;
     char nombre[MAXNOMBRE];
     char localidad[MAXLOCALIDAD];
     char provincia[MAXPROVINCIA];
     char pais[MAXPAIS];

}t_sucursal;

typedef struct{

     short sucursal;
     short vendedor;
     float importe;

}t_ventas;

/*prototipos*/
int menu_eleccion(FILE *,FILE *,FILE *, FILE*,FILE*);
void mensaje_menu(int);

int validar_eleccion(int,int,int);

void submenu_mostrar(FILE *,FILE *,FILE *);
void submenu_editar(FILE *,FILE *);

void cargar_datos_suc(FILE *,int);
void cargar_datos_ventas(FILE *);

void mostrar_datos_suc(FILE *,int);
void mostrar_datos_ventas(FILE *);

void procesar_sucursales(FILE *,FILE *,FILE *,FILE *);

void procesar_ventas(FILE * );

void delimitador();
int  main(){
	
	FILE *ASucInter;
    FILE *ASucNueva;
    FILE *AVentas;
	FILE *AErrores;
	FILE *AAux;
	
	printf(">>>>>>>>>>>>>>>>BIENVENIDO<<<<<<<<<<<<<<<<\n");
	printf("******************WELCOME*****************\n\n");
	/*
	menu_eleccion(ASucInter,ASucNueva,AVentas);
	
	cargar_datos_suc(ASucInter,1);
	
	cargar_datos_ventas(AVentas);
	
	mostrar_datos_suc(ASucInter);
	
	procesar_ventas(AVentas);
	*/
/*	
	menu_eleccion(ASucInter,ASucNueva,AVentas,AErrores,AAux);
*/

menu_eleccion(ASucInter,ASucNueva,AVentas,AErrores,AAux);




}



int menu_eleccion(FILE *inter,FILE *nuevas,FILE *ventas,FILE *errores, FILE *aux)
{
	int eleccion;
	char deseo;
	mensaje_menu(OP1);
	
	scanf("%d",&eleccion);
	
	int eleccion_a_validar=validar_eleccion(eleccion,1,MAXOPCION);
	deseo='s';
	
	while((eleccion_a_validar)&&(deseo=='s'))
	{
		switch (eleccion)
		{
		    case OP1:
			 	 printf("Has seleccionado %d mostrar archivos\n",OP1);
			 	 submenu_mostrar(inter,nuevas,ventas);
   				 break;
	    	 case OP2:
			 	  printf("Has seleccionado %d \n",OP2);
       			  submenu_editar(nuevas,ventas);
	   			  break;
			 case OP3:
			 	  printf("Has seleccionado %d \n",OP3);
				  procesar_ventas(ventas);
				  break;
			 case OP4:
			 	  printf("Has seleccionado %d \n",OP4);
			 	  procesar_sucursales(inter,nuevas,errores,aux);
				  break;
			 case OP5:
			 	  printf("******************  ADIOS. HASTA PRONTO. :) ************\n");
			 	  return 0;
 			
				   break;
        }
        
	printf("¿Desea volver al menu principal? s / n : ");
	fflush(stdin);
	scanf("%c",&deseo);
	
	while((deseo!='s')&&(deseo!='n'))
	{
		/*fuerza la colaboracion del usuario*/
		printf("Elija una opcion valida. Desea volver al menu principal? s / n : ");
		fflush(stdin);
		scanf("%c",&deseo);	
	}
	if(deseo=='n')
	{
		/*sale del programa*/
		eleccion=OP5;
	}
	else
	{
		/*valida la eleccion para volver al menu*/
		mensaje_menu(OP1);
		scanf("%d",&eleccion);
  		eleccion_a_validar=validar_eleccion(eleccion,1,MAXOPCION);
	}
	
	}
	
}

int validar_eleccion(int eleccion,int min,int max )
{
	/*devuelve el valor de la eleccion, que sera utilizado en el menu*/
	if((eleccion>=min)&&(eleccion<=max))
 	   return eleccion;
	else 
	/*devuelve un false*/
		 return -1;
}




void mensaje_menu(int mensaje)
{
	/*elije que mensaje mostrar*/
	if(mensaje==OP1)
	{
	/*menu principal*/
	printf("Seleccione una opcion:\n");
	printf(" \t%d Mostrar archivo.\n\t%d Ingresar registro.\n\t%d Procesar ventas\n\t%d Procesar sucursales\n\t%d Salir\n",OP1,OP2,OP3,OP4,OP5);
	}
	/*mostrar archivo*/
	else if(mensaje==OP2)
	{
		printf("Seleccione archivo a mostrar \n\t%d Sucursales internacionales \n\t%d Sucursales nuevas \n\t%d Ventas\n",OP1,OP2,OP3);
	}
	/*editar archivo*/
	else if(mensaje==OP3)
	{
		printf("Seleccione archivo a editar \n\t%d Sucursales nuevas \n\t%d Ventas\n",OP2,OP3);
	}
	

	
}



void submenu_mostrar(FILE *a,FILE *b,FILE *c)
{
	int eleccion;
	mensaje_menu(OP2);
	/*se elige el archivo 1 2 o 3 */
	scanf("%d",&eleccion);
	switch(eleccion){
		
		case OP1:
			 mostrar_datos_suc(a,eleccion);
		break;
		case OP2:
			 mostrar_datos_suc(b,eleccion);
		break;
		case OP3:
			 mostrar_datos_ventas(c);
		break;
	
		
	}
	
	/*se muestra el archivo*/
}




void submenu_editar(FILE *b,FILE *c)
{
	int eleccion;
	mensaje_menu(OP3);
	/*se elige el archivo*/
	scanf("%d",&eleccion);
	switch(eleccion){
	
		case OP2:
			 cargar_datos_suc(b,eleccion);
		break;
		case OP3:
			 cargar_datos_ventas(c);
		break;
}
	
	
}




void cargar_datos_suc(FILE * a,int eleccion)
{
	/*acepta un numero y segun este abre uno u otro archivo*/
	
	t_sucursal s;
	
	char nombre[MAXNOMBRE];
	char localidad[MAXLOCALIDAD];
	char provincia[MAXPROVINCIA];
	char pais[MAXPAIS];
	
	if(eleccion==OP1)
	{
		a=fopen("SUC_INTER.dat","a");
	}
	else if(eleccion==OP2)
	{
		a=fopen("SUC_NUEVAS.dat","a");
	}
	
	
 	printf("Ingrese codigo Sucursal termina carga con %d ",CODSALIDA);
 	scanf("%d",&s.sucursal);
 	/*validar el codigo de sucursal*/
 	while(validar_eleccion(s.sucursal,0,MAXSUCURSALES)==-1)
 	{
 		printf("Codigo no valido.Ingrese codigo Sucursal termina carga con %d ",CODSALIDA);
 		scanf("%d",&s.sucursal);
 	}
 	
	while (s.sucursal!=CODSALIDA)
	{
		printf("ingrese nombre: ");
		fflush(stdin);
		scanf("%s",nombre);
		strcpy(s.nombre,nombre);
	
		printf("ingrese Pais: ");
		fflush(stdin);
		scanf("%s",pais);
		strcpy(s.pais,pais);
		
		printf("Ingrese Provincia: ");
		fflush(stdin);
		scanf("%s",provincia);
		strcpy(s.provincia,provincia);
		
		printf("Ingrese Localidad: ");
		fflush(stdin);
		scanf("%s",localidad);
		strcpy(s.localidad,localidad);
		
		/*escribe el registro en el archivo*/
		fwrite(&s,sizeof(t_sucursal),1,a);
		
 	printf("Ingrese codigo Sucursal termina carga con %d ",CODSALIDA);
 	scanf("%d",&s.sucursal);
 	
 	/*validar el codigo de sucursal*/
 	while(validar_eleccion(s.sucursal,0,MAXSUCURSALES)==-1)
 	{
 		printf("Codigo no valido.Ingrese codigo Sucursal termina carga con %d ",CODSALIDA);
 		scanf("%d",&s.sucursal);
 	}
	}
	fclose(a);
	
printf("Carga finalizada\n");	
	
}




void cargar_datos_ventas(FILE * a)
{
	t_ventas v;
	
	int sucursal,vendedor;
	float importe;
	
	a=fopen("VENTAS.dat","a");
	
 	printf("Ingrese codigo Sucursal termina carga con %d ",CODSALIDA);
 	scanf("%d",&v.sucursal);
 	/*validar el codigo de sucursal*/
 	while(validar_eleccion(v.sucursal,0,MAXSUCURSALES)==-1)
 	{
 		printf("###Codigo no valido.Ingrese codigo Sucursal termina carga con %d ",CODSALIDA);
 		scanf("%d",&v.sucursal);
 	}
	while (v.sucursal!=CODSALIDA)
	{
		printf("ingrese codigo vendedor entre %d y %d: ",1,MAXVENDEDOR);
		scanf("%d",&v.vendedor);
		/*validar codigo de vendedor*/
 		while(validar_eleccion(v.vendedor,1,MAXVENDEDOR)==-1)
 		{
 		 printf("###Codigo no valido.Ingrese codigo Vendedor entre %d y %d: ",1,MAXVENDEDOR );
 		 scanf("%d",&v.vendedor);
 		 }
		
		printf("Ingrese importe: ");
		scanf("%f",&v.importe);
		
		/*escribe el registro en el archivo*/
		fwrite(&v,sizeof(t_ventas),1,a);
		
 	printf("Ingrese codigo Sucursal termina carga con %d ",CODSALIDA);
 	scanf("%d",&v.sucursal);
 	
 	/*validar el codigo de sucursal*/
 	while(validar_eleccion(v.sucursal,0,MAXSUCURSALES)==-1)
 	{
 		printf("###Codigo no valido.Ingrese codigo Sucursal termina carga con %d ",CODSALIDA);
 		scanf("%d",&v.sucursal);
 	}
	delimitador();
	}
	fclose(a);
	
printf("Carga finalizada\n");	
	
	
}




void mostrar_datos_suc(FILE *a,int e)
{
	t_sucursal s;
	if(e==OP1)
	{
		a=fopen("SUC_INTER.dat","r");
		printf("~~Archivo SUC_INTER.dat\n\n");		
	}
	else if(e==OP2)
	{
		a=fopen("SUC_NUEVAS.dat","r");
		printf("~~Archivo SUC_NUEVAS.dat\n\n");
	}
	fread(&s,sizeof(t_sucursal),1,a);
	
	while(!feof(a))
	{
		printf("Sucursal n: %d\n",s.sucursal);
		printf("\tNombre     : %s\n",s.nombre);
		printf("\tPais       : %s\n",s.pais);
		printf("\tProvincia  : %s\n",s.provincia);
		printf("\tLocalidad  : %s\n\n",s.localidad);
		
		delimitador();
		
		fread(&s,sizeof(t_sucursal),1,a);		
	}
	fclose(a);
	printf("Lectura teminada\n");
}




void mostrar_datos_ventas(FILE *a)
{
	t_ventas v;
	
	
	a=fopen("VENTAS.dat","r");
	
 	printf("~~Archivo VENTAS.dat\n\n");
 	fread(&v,sizeof(t_ventas),1,a);
	while (!feof(a))
	{
		printf("Sucursal n: %d\n",v.sucursal);
		printf("\tVendedor : %d\n",v.vendedor);
		printf("\tImporte : %.3f\n\n",v.importe);
		
		delimitador();
	
		fread(&v,sizeof(t_ventas),1,a);		
	}
	fclose(a);
	
printf("Lectura finalizada\n");	
}



/*Punto 4*/
/*Hace el apareo entre SUC_INTER.dat y SUC_NUEVAS.dat y lo deja ordenado en  AUX.dat, y a los repetidos en errores.dat*/
void procesar_sucursales(FILE *inter,FILE *nuevas,FILE *errores,FILE *aux)
{
	t_sucursal t_inter;
	t_sucursal t_nuevas;

	inter=fopen ("SUC_INTER.dat","r");
	nuevas=fopen ("SUC_NUEVAS.dat","r");
	aux=fopen ("auxaux.dat","w");
	errores=fopen ("errores.txt","w");
	

	fread(&t_inter,sizeof(t_sucursal),1,inter);
	fread(&t_nuevas,sizeof(t_sucursal),1,nuevas);

	while((!feof(inter))&&(!feof(nuevas)))
	{
		
		if(t_inter.sucursal<t_nuevas.sucursal){
			fwrite(&t_inter,sizeof(t_sucursal),1,aux);
			fread(&t_inter,sizeof(t_sucursal),1,inter);
		}
		else{
			if (t_inter.sucursal>t_nuevas.sucursal){
				fwrite (&t_nuevas,sizeof(t_sucursal),1,aux);
				fread (&t_nuevas,sizeof(t_sucursal),1,nuevas);
			}
			else{           /*si llega a este punto, es que son iguales. Anota el dato de nuevas en errores 
			                  y lee el que sigue, al volver a entrar al while pasa el dato de inter */
				fprintf (errores,"%d ",t_nuevas.sucursal);
				fprintf (errores,"%s ",t_nuevas.nombre);
				fprintf (errores,"%s ",t_nuevas.pais);
				fprintf (errores,"%s ",t_nuevas.provincia);
				fprintf (errores,"%s \n",t_nuevas.localidad);
				
				fread (&t_nuevas,sizeof(t_sucursal),1,nuevas);
			}
		}	
	}
	/*En este momento, el archivo inter o nuevas se acaba, por lo que paso todo lo que quede del archivo que no se termino*/

	while (!feof(inter)){
		fwrite (&t_inter,sizeof(t_sucursal),1,aux);
		fread (&t_inter,sizeof(t_sucursal),1,inter);
	}	
	
	while (!feof(nuevas)){
		fwrite (&t_nuevas,sizeof(t_sucursal),1,aux);
		fread (&t_nuevas,sizeof(t_sucursal),1,nuevas);
	}
	
	fclose(inter);
	fclose(nuevas);
	fclose(aux);
	fclose(errores);
	
	printf ("Se ha completado el apareo. \n");
	
}	
	/*3 procesar ventas*/
void procesar_ventas(FILE * a)
{	
	/*abrir el archivo */
	a=fopen("VENTAS.dat","r");
	
	/*struct auxiliar*/
	t_ventas v;
	
	/*variables para producir el informe*/
	int codigo_anterior;
	int vendedor_anterior;
	float importe_vendedor;
	float importe_sucursal;
	float importe_global;
	
	printf("\n~~Operaciones del mes\n");
	/*leer el archivo*/
	fread(&v,sizeof(t_ventas),1,a);
	/*set */
	importe_global=0;
	while(!feof(a))
	{	
		codigo_anterior=v.sucursal;
		delimitador()
		printf("Sucursal %d \n",v.sucursal);
		
		/*reset importe por sucursal*/
		importe_sucursal=0;
		
		while((!feof(a))&&(codigo_anterior==v.sucursal))
		{	/*mientras no cambie la  sucursal*/
			vendedor_anterior=v.vendedor;
			
			/*reset importe vendedor*/
			importe_vendedor=0;
			
			printf("\tVendedor %d ",v.vendedor);
			while(((!feof(a))&&(codigo_anterior==v.sucursal))&&(vendedor_anterior==v.vendedor))
			{	/*mientras no cambie el vendedor*/
			
				/*acumula el importe por vendedor*/
				importe_vendedor=importe_vendedor+v.importe;
				
				/*leer el archivo para evaluar el cambio de alguna variable de control*/
				fread(&v,sizeof(t_ventas),1,a);
			}
			/*acumula el importe por sucursal*/
			importe_sucursal=importe_sucursal+importe_vendedor;
			
			/*muestra el impote total POR VENDEDOR*/
			printf("\timporte %.3f \n",importe_vendedor);
			
		}
		/*acumula el importe total*/
		importe_global=importe_global+importe_sucursal;
		
		/*muestra el importe POR SUCURSAL*/
		printf("\nsucursal %d importe total \t%.3f \n",codigo_anterior,importe_sucursal);
		
	}
	/*muestra el importe GLOBAL*/
	delimitador();
	printf("TOTAL GLOBAL\t\t        %.4f \n",importe_global);
	
	fclose(a);
}
void delimitador()
{
	printf("_________________________________________\n");
}
	

	





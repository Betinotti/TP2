
#include<stdio.h>
#include <stdlib.h>
#include<string.h>

#define MAXNOMBRE 50
#define MAXLOCALIDAD 30
#define MAXPAIS 25
#define MAXPROVINCIA 25
#define MAXSUCURSALES 9999
#define MINSUCURSALES 0
#define MAXVENDEDOR 75
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
int menu_eleccion(FILE *,FILE *,FILE *);
void mensaje_menu(int);

int validar_eleccion(int);

void submenu_mostrar(FILE *,FILE *,FILE *);
void submenu_editar(FILE *,FILE *);

void cargar_datos_suc(FILE *,int);
void cargar_datos_ventas(FILE *);

void mostrar_datos_suc(FILE *,int);
void mostrar_datos_ventas(FILE *);

int  main(){
	
	FILE *ASucInter;
    FILE *ASucNueva;
    FILE *AVentas;

	
	printf(">>>>>>>>>>>>>>>>BIENVENIDO<<<<<<<<<<<<<<<<\n");
	printf("******************WELCOME*****************\n");
	/*
	menu_eleccion(ASucInter,ASucNueva,AVentas);
	
	cargar_datos_suc(ASucInter,1);
	
	cargar_datos_ventas(AVentas);
	
	mostrar_datos_suc(ASucInter);
	*/
	
	menu_eleccion(ASucInter,ASucNueva,AVentas);

}
int menu_eleccion(FILE *inter,FILE *nuevas,FILE *ventas)
{
	int eleccion;
	char deseo;
	mensaje_menu(OP1);
	
	scanf("%d",&eleccion);
	
	int eleccion_a_validar=validar_eleccion(eleccion);
	deseo='s';
	
	while((eleccion_a_validar)&&(deseo=='s'))
	{
		switch (eleccion)
		{
		    case OP1:
			 	 printf("has seleccionado %d mostrar archivos\n",OP1);
			 	 submenu_mostrar(inter,nuevas,ventas);
   				 break;
	    	 case OP2:
			 	  printf("has seleccionado %d \n",OP2);
       			  submenu_editar(nuevas,ventas);
	   			  break;
			 case OP3:
			 	  printf("has seleccionado %d \n",OP3);break;
			 case OP4:
			 	  printf("has seleccionado %d \n",OP4);break;
			 case OP5:
			 	  printf("******************  ADIOS. HASTA PRONTO. :) ************\n");
			 	  return 0;
 			
				   break;
        }
        
	printf("?Desea volver al menu principal? s / n : ");
	fflush(stdin);
	scanf("%c",&deseo);
	
	while(deseo!='s'&&deseo!='n')
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
		/*valida la eleccion para volvel ao menu*/
		mensaje_menu(OP1);
		scanf("%d",&eleccion);
  		eleccion_a_validar=validar_eleccion(eleccion);


	}
	
	}
	
}
int validar_eleccion(int eleccion)
{
	/*devuelve el valor de la eleccion, que sera utilizado en el menu*/
	if(eleccion>0&&eleccion<6)
 	   return eleccion;
	else 
		 return 0;
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
		printf("Seleccione archivo a mostrar \n\%d Sucursales internacionales \n\t%d Sucursales nuevas \n\t%d Ventas\n",OP1,OP2,OP3);
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
	/*se elige el archivo 1 2 0 3 */
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
 	
	while (v.sucursal!=CODSALIDA)
	{
		printf("ingrese codigo vendedor: ");
		scanf("%d",&v.vendedor);
		
		printf("Ingrese importe: ");
		scanf("%f",&v.importe);
		
		/*escribe el registro en el archivo*/
		fwrite(&v,sizeof(t_ventas),1,a);
		
 	printf("Ingrese codigo Sucursal termina carga con %d ",CODSALIDA);
 	scanf("%d",&v.sucursal);
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
	}
	else if(e==OP2)
	{
		a=fopen("SUC_NUEVAS.dat","r");
	}
	fread(&s,sizeof(t_sucursal),1,a);
	
	while(!feof(a))
	{
		printf("Sucursal n0: %d\n",s.sucursal);
		printf("\tNombre     : %s\n",s.nombre);
		printf("\tPais       : %s\n",s.pais);
		printf("\tProvincia  : %s\n",s.provincia);
		printf("\tLocalidad  : %s\n\n",s.localidad);
	
		fread(&s,sizeof(t_sucursal),1,a);		
	}
	fclose(a);
	printf("Lectura teminada\n");
}
void mostrar_datos_ventas(FILE *a)
{
	t_ventas v;
	
	
	a=fopen("VENTAS.dat","r");
	
 	printf("Datos ventas\n ");
 	fread(&v,sizeof(t_ventas),1,a);
	while (!feof(a))
	{
		printf("Sucursal n0: %d\n",v.sucursal);
		printf("\tVendedor : %d\n",v.vendedor);
		printf("\tImporte : %.3f\n\n",v.importe);
	
		fread(&v,sizeof(t_ventas),1,a);		
	}
	fclose(a);
	
printf("Lectura finalizada\n");	
}


#include <iostream>
#include <stdio.h>  
#include <string.h> 
#include <windows.h>


using namespace std;
const char *nombe_archivo = "archivo.dat";

struct Empleado{
	int codigo_empleado;
	char nombre[50];
	char apellido[50];
	char puesto[30];
	float sueldobase=0,bonificacion=0;
	float sueldototal;
	int borrar=0;
};

void ingresar();
void pedir_datos();
void modificar();
void buscar();
void eliminar();
void listado();
void borrardatos();

 main (){
 	int opcion;
 	do{
 	system("cls");
 	cout<<"\t-----------------------------------------------"<<endl;
 	cout<<"\t        JOSE ANDRES HERNANDEZ JUAREZ"<<endl;
 	cout<<"\tINGENIERIA EN SISTEMAS PROGRAMACION 1 SECCION A"<<endl;
 	cout<<"\t-----------------------------------------------"<<endl<<endl;
 	cout<<"SISTEMA DE REGISTRO DE DATOS DE EMPLEADOS"<<endl<<endl;
 	cout<<"ESCOJA UNA DE LAS SIGUIENTE OPCIONES: "<<endl;
 	cout<<"INGRESAR NUEVO REGISTRO\t[1]"<<endl;
 	cout<<"BUSCAR REGISTRO \t[2]"<<endl;
 	cout<<"MODIFICAR REGISTRO\t[3]"<<endl;
 	cout<<"LISTADO DE EMPLEADOS\t[4]"<<endl;
 	cout<<"ELIMINAR REGISTRO\t[5]"<<endl;
 	cout<<"SALIR DEL PROGRAMA\t[6]"<<endl;
 	cout<<"-----------------------------------------"<<endl;
 	cout<<"INGRESE OPCION  \t[ ]\b\b";
 		cin>>opcion;
	switch (opcion){
	case 1:
		ingresar();
		break;
	case 2:
		buscar();
		break;
	case 3:
		modificar();
		break;
	case 4:
		listado();
		break;
	case 5:
	    eliminar();
	    borrardatos();
	    break;
	case 6:
		return 0;
		break;
	}
 }while(opcion>6);
	return 0;	
}


void ingresar(){
	system("cls");
	char continuar;
	FILE* archivo = fopen(nombe_archivo, "ab"); 
	string nombre,apellido,puesto;
		Empleado empleado;
		do{
			fflush(stdin);
		cout<<"INGRESE CODIGO DE EMPLEADO: ";
		cin>>empleado.codigo_empleado;
        cin.ignore();
        
		cout<<"INGRESE NOMBRE:             ";
		getline(cin,nombre);
    	strcpy(empleado.nombre, nombre.c_str()); 
			
		cout<<"INGRESE APELLIDO:           ";
		getline(cin,apellido);
		strcpy(empleado.apellido, apellido.c_str()); 
		
		cout<<"INGRESE PUESTO DE TRABAJO:  ";
		getline(cin,puesto);
		strcpy(empleado.puesto, puesto.c_str()); 
		
		cout<<"INGRESE SUELDO BASE:        ";
		cin>>empleado.sueldobase;
		cin.ignore();
		
		cout<<"INGRESE BONIFICACION:        ";
		cin>>empleado.bonificacion;
		cin.ignore();
		empleado.borrar==0;
		empleado.sueldototal=empleado.sueldobase+empleado.bonificacion;
		cout<<endl<<"EL SUELDO TOTAL DEL TRABAJADOR ES: "<<empleado.sueldototal<<endl;	
		fwrite( &empleado, sizeof(Empleado), 1, archivo );
		
		cout<<"QUIERE REGISTRAR OTRO EMPLEADO [S/N] : ";
		cin>>continuar;
		} while((continuar=='s') || (continuar=='S') );
		
	fclose(archivo);
    main();
}

void buscar(){
	system("cls");
	FILE* archivo = fopen(nombe_archivo, "rb");
	
	int indice=0,pos=0,cod=0;
	int existe=0;
	cout<<"BUSCAR CODIGO: ";
	cin>>cod;
	Empleado empleado;
	
	fread ( &empleado, sizeof(Empleado), 1, archivo );
		
		do{
			
			if (empleado.codigo_empleado == cod){
			pos = indice;
			existe=1;
			}
	
		fread ( &empleado, sizeof(Empleado), 1, archivo );
		indice += 1;
		} while (feof( archivo ) == 0);
		
		
	if(existe==1){
	fseek ( archivo,pos * sizeof(Empleado), SEEK_SET );

    fread ( &empleado, sizeof( Empleado ), 1, archivo );

        cout<<"CODIGO DE EMPLEADO: "<<empleado.codigo_empleado<<endl;
		cout<<"NOMBRE:             "<<empleado.nombre<<endl;
		cout<<"APELLIDO:           "<<empleado.apellido<<endl;
		cout<<"PUESTO DE TRABAJO:  "<<empleado.puesto<<endl;
		cout<<"SUELDO BASE:        "<<empleado.sueldobase<<endl;
		cout<<"BONIFICACION:       "<<empleado.bonificacion;
		cout<<endl<<"EL SUELDO TOTAL DEL TRABAJADOR ES: "<<empleado.sueldototal<<endl;
	}
   if(existe==0){
   	cout<<"EL CODIGO NO COINCIDE CON NINGUN EMPLEADO REGISTRADO"<<endl;
   }
	fclose(archivo);
	system("PAUSE");
	main();
}

void modificar(){
	system("cls");
	FILE* archivo = fopen(nombe_archivo, "r+b");
	string nombre,apellido,puesto;
	int indice=0,pos=0,cod=0;
	int existe=0;
	cout<<"INGRESE CODIGO QUE DESEA MODIFICAR: ";
	cin>>cod;
	Empleado empleado;
	
	fread ( &empleado, sizeof(Empleado), 1, archivo );
		
		do{
			
			if (empleado.codigo_empleado == cod){
			pos = indice;
			existe=1;
			}
	fread ( &empleado, sizeof(Empleado), 1, archivo );
		indice += 1;
		} while (feof( archivo ) == 0);
		
	if(existe==1){
	fseek ( archivo,pos * sizeof(Empleado), SEEK_SET );
	 fread ( &empleado, sizeof( Empleado ), 1, archivo );

        cout<<"CODIGO DE EMPLEADO: "<<empleado.codigo_empleado<<endl;
		cout<<"NOMBRE:             "<<empleado.nombre<<endl;
		cout<<"APELLIDO:           "<<empleado.apellido<<endl;
		cout<<"PUESTO DE TRABAJO:  "<<empleado.puesto<<endl;
		cout<<"SUELDO BASE:        "<<empleado.sueldobase<<endl;
		cout<<"BONIFICACION:       "<<empleado.bonificacion;
		cout<<endl<<"EL SUELDO TOTAL DEL TRABAJADOR ES: "<<empleado.sueldototal<<endl;
		cout<<"----------------------------------------------------------------------"<<endl;
		fseek ( archivo,pos * sizeof(Empleado), SEEK_SET );
		cout<<"INGRESE CODIGO DE EMPLEADO: ";
		cin>>empleado.codigo_empleado;
        cin.ignore();
        
		cout<<"INGRESE NOMBRE:             ";
		getline(cin,nombre);
    	strcpy(empleado.nombre, nombre.c_str()); 
			
		cout<<"INGRESE APELLIDO:           ";
		getline(cin,apellido);
		strcpy(empleado.apellido, apellido.c_str()); 
		
		cout<<"INGRESE PUESTO DE TRABAJO:  ";
		getline(cin,puesto);
		strcpy(empleado.puesto, puesto.c_str()); 
		
		cout<<"INGRESE SUELDO BASE:        ";
		cin>>empleado.sueldobase;
		cin.ignore();
		
		cout<<"INGRESE BONIFICACION:        ";
		cin>>empleado.bonificacion;
		cin.ignore();
		empleado.borrar==0;
		empleado.sueldototal=empleado.sueldobase+empleado.bonificacion;
		cout<<endl<<"EL SUELDO TOTAL DEL TRABAJADOR ES: "<<empleado.sueldototal<<endl;	
	fwrite( &empleado, sizeof(Empleado), 1, archivo );
		cout<<"REGISTRO MODIFICADO"<<endl;
	}
  if(existe==0){
   	cout<<"EL CODIGO NO COINCIDE CON NINGUN EMPLEADO REGISTRADO"<<endl;
   }
		
	fclose(archivo);
	system("PAUSE");
	main();
}

void listado(){

	system("cls");
	FILE* archivo = fopen(nombe_archivo, "rb");
	if(!archivo) {
		archivo = fopen(nombe_archivo, "w+b");
	}
	Empleado empleado;
	int registro=0;
	fread ( &empleado, sizeof(Empleado), 1, archivo );
	cout<<"_____________________________________________________________________________________________________________"<<endl;
	cout << "CODIGO" <<"\t|"<< "NOMBRE"<<" \t"<<"APELLIDO"<<"\t|"<<"PUESTO      "<<"\t|"<<"SUELDO BASE "<<"+\t"<<"BONIFICACION"<<"=\t"<<"SUELDO NETO"<<endl;	
		do{
			if(empleado.borrar==0){
	cout<<"______________________________________________________________________________________________________________"<<endl;
		cout << empleado.codigo_empleado <<" \t| "<< empleado.nombre<<" \t"<<empleado.apellido<<"\t"<<"\t|"<<empleado.puesto<<"\t"<<"\t"<<empleado.sueldobase<<"\t"<<"+\t"<<empleado.bonificacion<<"\t"<<"=\t"<<empleado.sueldototal<<endl;
			registro += 1;	
    }
		fread ( &empleado, sizeof(Empleado), 1, archivo );
		} while (feof( archivo ) == 0);
    cout<<endl;
	fclose(archivo);
	system("PAUSE");
	main();
	}

void eliminar(){
	system("cls");
	FILE* archivo = fopen(nombe_archivo, "r+b");
	
	int indice=0,pos=0,cod=0;
	int existe=0;
	char sino;
	cout<<"INGRESE CODIGO DEL EMPLEADO A BORRAR: ";
	cin>>cod;
	Empleado empleado;
	
	fread ( &empleado, sizeof(Empleado), 1, archivo );
		
		do{
			
			if (empleado.codigo_empleado == cod){
			pos = indice;
			existe=1;
			}
	
		fread ( &empleado, sizeof(Empleado), 1, archivo );
		indice += 1;
		} while (feof( archivo ) == 0);
	if(existe==1){
		fseek ( archivo,pos * sizeof(Empleado), SEEK_SET );
	 fread ( &empleado, sizeof( Empleado ), 1, archivo );

        cout<<"CODIGO DE EMPLEADO: "<<empleado.codigo_empleado<<endl;
		cout<<"NOMBRE:             "<<empleado.nombre<<endl;
		cout<<"APELLIDO:           "<<empleado.apellido<<endl;
		cout<<"PUESTO DE TRABAJO:  "<<empleado.puesto<<endl;
		cout<<"SUELDO BASE:        "<<empleado.sueldobase<<endl;
		cout<<"BONIFICACION:       "<<empleado.bonificacion;
		cout<<endl<<"EL SUELDO TOTAL DEL TRABAJADOR ES: "<<empleado.sueldototal<<endl;
		cout<<"----------------------------------------------------------------------"<<endl;
	fseek ( archivo,pos * sizeof(Empleado), SEEK_SET );
	cout<<"SEGURO QUE QUIERE ELIMINAR ESTE REGISTRO: [S/N]"<<endl;
	cin>>sino;
	if((sino=='s') || (sino=='S') ){
    empleado.borrar=1;
    cout<<"REGISTRO ELIMINADO CON EXITO"<<endl;
	}
	else{
	cout<<"NO SE HA BORRADO EL REGISTRO"<<endl;
	}
    fwrite ( &empleado, sizeof( Empleado ), 1, archivo );
}
  if(existe==0){
   	cout<<"EL CODIGO NO COINCIDE CON NINGUN EMPLEADO REGISTRADO"<<endl;
   }

	fclose(archivo);
	system("PAUSE");
	main();
}

void borrardatos(){
	FILE* archivo = fopen(nombe_archivo, "rb");
	FILE* temporal= fopen("temporal.dat","w+b");
	
	Empleado empleado;
	int registro=0;
	fread ( &empleado, sizeof(Empleado), 1, archivo );
    while (feof( archivo ) == 0){
			if(empleado.borrar==0){
				fwrite(&empleado,sizeof(Empleado),1,temporal);
    }
		fread ( &empleado, sizeof(Empleado), 1, archivo );
		} 
    cout<<endl;
		fclose(archivo);
		fclose(temporal);
		remove ("archivo.dat");
		rename("temporal.dat","archivo.dat");
	
}

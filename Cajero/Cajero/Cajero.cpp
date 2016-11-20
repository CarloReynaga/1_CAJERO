#include <iostream>
#include <string>
using namespace std;


//Variables globales
const int N = 10;
string nombres[N] = { "Ivan", "Julio", "Beto", "Carlos", "Maria", "Juan", "Paola", "Linda", "Marco", "Fiorella" };
string apellidos[N] = { "Delgado", "Huertas", "Cuevas", "Santana", "Flowers", "Diaz", "Vela", "Sarmiento", "Polo", "Casas" };
string claves[N] = { "123456", "alpha", "beta", "carlos777", "maria_45", "juancito", "pao888", "linda_33", "forever", "fio_fio" };
double saldocuenta[N] = { 50000, 15000, 10000, 10000, 5000, 15000, 20000, 50000, 5000, 2000 };
double valor_cajero = 100000;
double transferencia;
int opcion;
/*ubicacion del cliente en los arreglos*/
int id_cliente =-1;
int monto;

/*muestra el menu principal*/
void Menu_Principal()
{

	system("cls");
	cout << "--------------------" << endl;
	cout << "*****Bienvenido*****" << endl;
	cout << "--------------------" << endl;
	cout << "1. Ingresar Cuenta" << endl;
	cout << "2. Ver Reportes" << endl;
	cout << "0. Salir de la cuenta" << endl;
	cout << "Ingrese opcion" << endl;
	cin >> opcion;
	
}

/*muestra el menu secundaria de acceso al menu*/
void Menu_Secundario()
{
	//int opc;
	//system("cls");
	cout << "--------------------" << endl;
	cout << "*****OPCIONES*****" << endl;
	cout << "--------------------" << endl;
	cout << "1. Deposito" << endl;
	cout << "2. Retiro" << endl;
	cout << "3. Consulta" << endl;
	cout << "4. Transferencia" << endl;
	cout << "10. Salir de la cuenta" << endl;
	cout << "Ingrese opcion" << endl;
	cin >> opcion;

}

/* valida si el cliente existe
si existe retorna su id_cliente que es su ubicacion en el arreglo
caso contrario retorna -1*/
int VerificaCliente(string nombre, string apellido)
{
	// valor que retorna por defecto
	int retorna = -1;
	for (int i = 0; i < N; i++)
	{

		if (nombre == nombres[i] && apellido == apellidos[i])
		{
			retorna = i;
		}
	}

	return retorna;
}

/* valida si el cliente existe 
 si existe retorna su id_cliente que es su ubicacion en el arreglo
 caso contrario retorna -1*/
int Login(string nombre, string apellido, string clave )
{
	// valor que retorna por defecto
	int retorna = -1;
	for (int i = 0; i < N; i++)
	{

		if (nombre == nombres[i] && apellido == apellidos[i] && clave == claves[i])
		{
			retorna = i;
		}
	}

	return retorna;
}

/*Bienvenida a cliente*/
void Bienvenida(int id)
{
	system("cls");
	// obteniend los datos del cliente desde posicion del arreglo, id nos da el valor de la posicion
	cout << "Bienvenido" << " " << nombres[id] << " " << apellidos[id] << " " << endl;
	cout << "Su Saldo es:" << " " << saldocuenta[id] << endl;
	cout << "Dinero en el cajero: " << valor_cajero << endl;
	system("pause");
}


/*Deposita un monto en el cajero*/
void Deposito()
{

	do {
		//system("cls");
		cout << "--------------------" << endl;
		cout << "******Deposito******" << endl;
		cout << "--------------------" << endl;
		cout << "Ingrese monto a depositar: ";
		cin >> monto;
	} while (monto <= 0);
	// Actualizamos el valor del cajero
	valor_cajero = valor_cajero + monto;
	cout << "Dinero disponible en el cajero:\n" << valor_cajero << endl;

	saldocuenta[id_cliente] = saldocuenta[id_cliente] + monto;
	cout << "Su nuevo saldo es: " << saldocuenta[id_cliente] << endl;
	system("pause");
}

/*retira un monto del cajero*/
void Retiro()
{
	cout << "******Retiro******" << endl;
	cout << "--------------------" << endl;
	cout << "Ingrese monto a retirar:";
	cin >> monto;
	if (monto > valor_cajero)
	{
		cout << "El cajero no cuenta con dinero suficiente.." << endl;
	}
	else
	{
		if (monto > saldocuenta[id_cliente])
		{
			cout << "Ud. no cuenta con dinero suficiente.." << endl;
		}
		else
		{
			// Actualizamos el valor del cajero
			valor_cajero = valor_cajero - monto;
			cout << "Dinero disponible en el cajero:\n" << valor_cajero << endl;
			saldocuenta[id_cliente] = saldocuenta[id_cliente] - monto;
			cout << "Su nuevo saldo es: " << saldocuenta[id_cliente] << endl;
		}
		
		
	}
	system("pause");
}

/*consulta el saldo de cliente*/
void Consulta()
{
	cout << "******Consulta******" << endl;
	cout << "--------------------" << endl;
	cout << "Su saldo es: " << saldocuenta[id_cliente] << endl;
	system("pause");

}

/*Tranfiere dinero de un cliente a otro*/
void Transferencia()
{
	string nombre_destino, apellido_destino;
	double monto_transferir=0;
	int id_clienteDestino;
	cout << "******Transferencia******" << endl;
	cout << "--------------------" << endl;
	cout << "Ingrese Nombre:\n";
	cin >> nombre_destino;
	cout << "Ingrese Apellido:\n";
	cin >> apellido_destino;
	id_clienteDestino = VerificaCliente(nombre_destino, apellido_destino);
	if(id_clienteDestino == -1)
	{
		cout << "No existe el cliente a quien desea transferir.";
	
	}
	else
	{
		cout << "Ingrese monto a transferir:";
		cin >> monto_transferir;
		if (monto_transferir <=0)
		{
			cout << "el monto debe ser mayor a cero." << endl;
		}
		if (monto_transferir > saldocuenta[id_cliente])
		{
			cout << "Ud. no cuenta con dinero suficiente.." << endl;
		}
		else
		{
			
			//descontando saldo a cliente origen
			saldocuenta[id_cliente] = saldocuenta[id_cliente] - monto_transferir;
			//sumando saldo a cliente destino
			saldocuenta[id_clienteDestino] = saldocuenta[id_clienteDestino] + monto_transferir;
			cout << "Su nuevo saldo es: " << saldocuenta[id_cliente] << endl;
			
		}
	}
	system("pause");
}

void ReporteEstadistico()
{
	double suma=0;
	int cincuentaMil = 0;
	int cincoMil = 0;
	for (int i = 0; i < N; i++)
	{
		suma = suma + saldocuenta[i];
		//verificando si cuenta es >= 50 000
		if (saldocuenta[i] >= 50000)
			cincuentaMil = cincuentaMil + 1;
		//verificando si cuenta es >= 5 000
		if (saldocuenta[i] >= 5000)
			cincoMil = cincuentaMil + 1;
	}
	cout << "******Reporte estadistico******" << endl;
	cout << "--------------------" << endl;
	cout << "Promedio de saldos:" << suma / N << endl;
	cout << "Número de cuentas con saldo mayor o igual a 50,000:" << cincuentaMil << endl;
	cout << "Número de cuentas con saldo mayor o igual a 5,000:" << cincoMil << endl;
	system("pause");
}

int main()
{
	do
	{
		Menu_Principal();
		if (opcion == 0)
		{
			break;
		}
		string nom, ape, cla;
		switch (opcion)
		{
			
		case 1:
			system("cls");
			cout << "Ingrese Nombre:\n";
			cin >> nom;
			cout << "Ingrese Apellido:\n";
			cin >> ape;
			cout << "Ingrese Clave:\n";
			cin >> cla;
			system("pause");

			//validando si ya existe un cliente logeado
			//if(id_cliente ==-1)
			id_cliente = Login(nom, ape, cla);//Validando si el cliente existe
			if (id_cliente > -1)
			{
				// Dar bienvenida si el cliente existe
				Bienvenida(id_cliente);
				do {
					Menu_Secundario();
					if (opcion == 10)
					{
						break;
					}
					switch (opcion)
					{
					case 1:
						//Deposito
						//Bienvenida(id_cliente);
						Deposito();
						break;
					case 2:
						//Retiro
						//Bienvenida(id_cliente);
						Retiro();
						break;
					case 3:
						//Consulta
						Consulta();
						break;
					
					case 4:
						//Consulta
						Transferencia();
						break;
							}
				} while (true);
				//return 10;
			}
			//mostrar mensaje de error en caso contrario
			else
			{
				cout << "Ud. no es cliente" << endl;
			}
				
			break;
		case 2:
			ReporteEstadistico();
		break;
		}
		//system("pause");
	}
	while (true);
	return 0;
}
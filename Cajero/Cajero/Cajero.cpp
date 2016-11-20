#include <iostream>
#include <string>
using namespace std;


//Variables globales
const int N = 10;
string nombres[N] = { "Ivan", "Julio", "Beto", "Carlos", "Maria", "Juan", "Paola", "Linda", "Marco", "Fiorella" };
string apellidos[N] = { "Delgado", "Huertas", "Cuevas", "Santana", "Flowers", "Diaz", "Vela", "Sarmiento", "Polo", "Casas" };
string clave[N] = { "123456", "alpha", "beta", "carlos777", "maria_45", "juancito", "pao888", "linda_33", "forever", "fio_fio" };
double saldocuenta[N] = { 50000, 15000, 10000, 10000, 5000, 15000, 20000, 50000, 5000, 2000 };
double valor_cajero = 100000;
double transferencia;
int opcion;
int i;
int monto;

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

void Menu_Secundario()
{
	int opc;
	system("cls");
	cout << "--------------------" << endl;
	cout << "*****OPCIONES*****" << endl;
	cout << "--------------------" << endl;
	cout << "1. Deposito" << endl;
	cout << "2. Retiro" << endl;
	cout << "3. Consulta" << endl;
	cout << "4. Transferencia" << endl;
	cout << "10. Salir de la cuenta" << endl;
	cout << "Ingrese opcion" << endl;
	cin >> opc;

}

void Bienvenida()
{
	string nom, ape, cla;
	cout << "Bienvenido" << " " << nom << " " << ape << " " << endl;
	cout << "Su Saldo es:" << " " << saldocuenta[i] << endl;
	cout << "Dinero en el cajero: " << valor_cajero << endl;
}

void Deposito()
{

	do {
		system("cls");
		cout << "--------------------" << endl;
		cout << "******Deposito******" << endl;
		cout << "--------------------" << endl;
		cout << "Ingrese monto a depositar: ";
		cin >> monto;
	} while (monto <= 0);
	// Actualizamos el valor del cajero
	valor_cajero = valor_cajero + monto;
	cout << "Dinero disponible en el cajero:\n" << valor_cajero << endl;

	saldocuenta[i] = saldocuenta[i] + monto;
	cout << "Su nuevo saldo es: " << saldocuenta[i] << endl;

}

void Retiro()
{
	cout << "Ingrese monto a retirar:";
	cin >> monto;
	// Actualizamos el valor del cajero
	valor_cajero = valor_cajero - monto;
	if (monto > valor_cajero)
	{
		cout << "El cajero no cuenta con dinero suficiente.." << endl;
		system("pause");
	}
	saldocuenta[i] = saldocuenta[i] - monto;

}


void Consulta()
{
	cout << "Su saldo es: " << saldocuenta[i];
	system("pause");

}


int main()
{
	do
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
		if (opcion == 0)
		{
			break;
		}
		switch (opcion)
		{
		case 1:
			int opc;
			string nom, ape, cla;
			system("cls");
			cout << "Ingrese Nombre:\n";
			cin >> nom;
			cout << "Ingrese Apellido:\n";
			cin >> ape;
			cout << "Ingrese Clave:\n";
			cin >> cla;
			system("pause");
			for (int i = 0; i < N; i++)
			{

				if (nom == nombres[i] && ape == apellidos[i] && cla == clave[i])
				{
					system("cls");
					cout << "Bienvenido" << " " << nom << " " << ape << " " << endl;
					cout << "Su Saldo es:" << " " << saldocuenta[i] << endl;
					cout << "Dinero en el cajero: " << valor_cajero << endl;
					cout << "--------------------" << endl;
					cout << "*****OPCIONES*****" << endl;
					cout << "--------------------" << endl;
					cout << "1. Deposito" << endl;
					cout << "2. Retiro" << endl;
					cout << "3. Consulta" << endl;
					cout << "4. Transferencia" << endl;
					cout << "10. Salir de la cuenta" << endl;
					cout << "Ingrese opcion" << endl;
					cin >> opc;
					if (opc == 10)
					{
						break;
					}
					switch (opc)
					{
					case 1:
						//Deposito
						Bienvenida();
						Deposito();
						break;
					case 2:
						//Retiro
						Bienvenida();
						Retiro();
						break;
					case 3:
						//Consulta
						Consulta();
						break;
					}system("pause");
				}
				else
				{
					cout << "Error" << endl;
				}
			}


		}
		system("pause");
	} while (true);
	return 0;
}
#include<iostream>
#include <cstdlib>
#include <limits>
#include <string>
int size = 10;
int resiptsize = 1;
double cash = 30000.00;
double Cashincome = 0, cardincome = 0, totacincome = 0;

int* idArr = new int[size];
std::string* nameArr = new std::string[size];
int* countArr = new int[size];
double* priceArr = new double[size];

//������� ��� ����
std::string* nameReciptArr = new std::string[resiptsize];
int* countReciptArr = new int[resiptsize];
double* priceReciptArr = new double[resiptsize];

//template < typename ArrType>
//void FillArray(ArrType staticArr, ArrType dinArr, int size);
//�������� ������
void start();
void DeleteMainArrays();
void DeleteReciptArrays();
void CreateStorage();
void ShowStorage();
void Shop();
void Seling();
void AddElementToRecipt(int& reciptsize, int id, int count);
//void PriceRecipt();
void ChangePrice();
void RemoveFromStorage();
void AddToStorage();
void ChangeStorage();
void DeleteElementByIndex();
void discount();
void SecondDiscount();
void CashStatus();

void DeleteMainArrays()
{
	delete[] idArr;
	delete[] nameArr;
	delete[] countArr;
	delete[] priceArr;

}
 

void CreateStorage()
{
	const int staticSize = 10;
	int id[staticSize]{ 1, 2, 3, 4, 5, 6 };
	std::string name[staticSize]{ "\t1-������� ����, 2- ����������� ������, 3- ������� ������, 4- ������� ������, 5-����������� ������, 6- ��������" };
	int count[staticSize]{ 8, 5, 6, 7, 10, 3 };
	double price[staticSize]{ 1000, 2000, 3000, 40000, 5000, 6000 };
	/*FillArray(id, idArr, staticSize);
	FillArray(name, nameArr, staticSize);
	FillArray(price, priceArr, staticSize);*/


}

void ShowStorage()
{
	std::cout << "id\t�������� ������\t\t\t ���-��\t\t ����\n";
}
void CashStatus()
{
	std::cout << "�������� � ����� " << cash << "\n ������� �� ��������:" << Cashincome << "������� �� �������:" << cardincome << "\n\n" << "�������� ������� �� ����� ";
}
void Shop()
{
	while (true)
	{
		int choose;
		do {
			std::cout << "1-�������� �����\n";
			std::cout << "2-������ �������\n";
			std::cout << "3-�������� ����\n";
			std::cout << "4-������� �����\n";
			std::cout << "5-��������� �����\n";
			std::cout << "6-��������� ������\n";
			std::cout << "7-��������� �����";

			std::cout << "0-��������� �����\n";
			std::cin >> choose;
		} while (choose < 0 || choose > 0);
		if (choose == 1)
		{
			ShowStorage();
		}
		else if (choose == 2)
		{
			Seling();
		}
		else if (choose == 3)
		{
			ChangePrice();
		}
		else if (choose == 4)
		{
			RemoveFromStorage();
		}
		else if (choose == 5)
		{
			AddToStorage();
		}
		else if (choose == 6)
		{
			CreateStorage();
		}
		else if (choose == 7)
		{
			CashStatus();
		}
		else if (choose == 0)
		{
			break;
		}
		else
		{
			std::cerr << "error!";
		}
	}
}
void Seling()
{
	int chooseid = 0, choosecount, confirm;
	float totalsum = 0;
	bool isfirst = true;

	if (chooseid < 1 || chooseid > size)
	{
		std::cerr << "������� ������ ���\t";

		if (countArr[chooseid - 1] > 0)
		{
			while (true)
			{
				std::cout << "\n ��������� �����" << nameArr[chooseid - 1] << "\n";
				std::cout << "������� ���-�� ������:";
				std::cin >> choosecount;
				if (choosecount < 1 || choosecount > countArr[chooseid - 1])
				{
					std::cerr << "error!\n";
				}
				else
				{
					break;
				}
			}
		}
	}
	else
	{
		std::cerr << "������ �� ������ ���!";
	}

	std::cout << "\n �����:" << nameArr[chooseid - 1] << "\t ���-�� " << choosecount;
	std::cout << "\n1-�����������\n2-������";
	std::cin >> confirm;
	if (confirm == 1)
	{
		if (isfirst)
		{
			nameReciptArr[resiptsize - 1] = nameArr[chooseid - 1];
			countReciptArr[resiptsize - 1] = choosecount;
			priceReciptArr[resiptsize - 1] = priceArr[chooseid - 1] * choosecount;
			totalsum += priceArr[chooseid - 1] * choosecount;
			isfirst = false;
		}
		else
		{
			AddElementToRecipt(resiptsize, chooseid, choosecount);

		}
	}
	else
	{
		//continue;

	}

	std::cout << "������ ��� �����?\n";
	std::cout << "1-��\n 2-��������� �������";
	std::cin >> confirm;
	int pay = 0;



}
void discount()
{
	int id, discount, kollichestvo = 0, price = 0;
	std::cout << "�� ������ 3 ������� ������ 30%";
	std::cout << "������� id ������ ��� �������";
	std::cin >> id;
	if (kollichestvo < 3)
	{
		std::cout << "������� ��� ������";
	}
	else if (kollichestvo >= 3)
	{
		std::cout << "������� ����� �� �������";
		discount = price * 30 / 100;
		std::cout << "������ ����������" << discount;
	}
}

void SecondDiscount()
{
		int id, discount, price = 0;
		std::cout << "��� ����� ����������� ������ �� ����� 20% ";
		std::cout << "������� id ������ ";
		std::cin >> id;
		if (id == 1)
		{
			std::cout << "������ 20%";
			discount = price * 20 / 100;
			std::cout << "������ ����������" << discount;
			//continue;
		}
		else(id > 1);
		{
			std::cerr << "������ �� �����";
			//continue;
		}
}

void AddElementToRecipt(int& reciptsize, int id, int count)
{
	
	std::string* nameReciptArrTemp = new std::string[resiptsize];
	int* countReciptArrTemp = new int[resiptsize];
	double* PriceReceiptArrTemp = new double[resiptsize];
	for (int i = 0; i < resiptsize; i++)
	{
		nameReciptArrTemp[i] = nameReciptArr[i];
		countReciptArrTemp[i] = countReciptArr[i];
		PriceReceiptArrTemp[i] = priceReciptArr[i];
	}
	delete[] nameReciptArr;
	delete[] countReciptArr;
	delete[] priceReciptArr;
	resiptsize++;
	nameReciptArr = new std::string[resiptsize];
	countReciptArr = new int[resiptsize];
	priceReciptArr = new double[resiptsize];
	for (int i = 0; i < resiptsize - 1; i++)
	{
		nameReciptArr[i] = nameReciptArrTemp[i];
		countReciptArr[i] = countReciptArrTemp[i];
		priceReciptArr[i] = PriceReceiptArrTemp[i];
	}
	
}
		
void DeleteReciptArrays()
{
	int id = 0;
	int count = 0;
	nameReciptArr[resiptsize - 1] = nameArr[id - 1];
	countReciptArr[resiptsize - 1] = count;
	priceReciptArr[resiptsize - 1] = priceArr[id - 1] * count;
	countArr[id - 1] -= count;
}


void RemoveFromStorage()
{
	int id = 0;
	int count = 0;
	do {
		std::cout << "������� id ������:";
		std::cin >> count;
	} while (count < 0 || count > countArr[id - 1]);
	countArr[id - 1] -= countArr[id - 1];
	std::cout << "���� ������ ������� ��������:";
}
		
		
void ChangePrice()
{
	int id;
	double newprice = 0;
	do {
		std::cout << "������� id ��� ��������� ����";
		std::cin >> id;
	} while (newprice < 1 || newprice > 1000000);
	priceArr[id - 1] = newprice;
	std::cout << "���� ������ ������� ��������!\n\n";
}

void AddToStorage()
{
	int id, count;
	do {
		std::cout << "������� id ������ ��� ����������";
		std::cin >> id;
	} while (id < 1 || id > idArr[size - 1]);

	std::cout << "\n\n������ �����:" << nameArr[id - 1] << "=" << countArr[id - 1] << "����\n\n";
	do {
		std::cout << "\n ������� ���-�� ������:";
		std::cin >> count;
	} while (count < 0 || count > countArr[id - 1]);
	std::cout << "����� ������� ��������\n\n";
}
		
void ChangeStorage()
{
	int choose = 0;
	do {
		std::cout << "1-�������� ����� �� �����\n";
		std::cout << "2-������ ����� �� ������\n";
		std::cout << "3-�����\n";
	} while (choose < 0 || choose > 2);
	if (choose == 1)
	{
		int* idArr = new int[size];
		std::string* nameArr = new std::string[size];
		int* countArr = new int[size];
		double* priceArr = new double[size];
	}
	else if (choose == 2) 
	{

	}
	else
	{
		std::cout << "�����";
	}
}
		

void DeleteElementByIndex()
{
	idArr = new int[size];
	nameArr = new std::string[size];
	countArr = new int[size];
	priceArr = new double[size];
	int index = 0;
	do {
		std::cout << "������� id ������ ��� ��������";
		std::cin >> index;
	} while (index < 1 || index > size);
	for (int i = 0, j = 0; i < size, j < size, j++; i++)
	{
		if (i == index - 1)
		{
			i++;
			nameReciptArr[i] = idArr[j];
			nameReciptArr[i] = nameArr[j];
			priceReciptArr[i] = priceArr[j];


		}
		else
		{
			idArr[j] = idArr[i];
			nameArr[j] = nameArr[i];
			priceArr[j] = priceArr[j];
			countArr[j] = countArr[i];
		}
	}

	delete[] idArr;
	delete[] nameArr;
	delete[] priceArr;
	delete[] countArr;
}




void start()
{
	{
		std::cout << "****************************  ����� ���������� � ���������!********************";
		int chooseStorageType;
		do {
			std::cout << "������� ������ ������:\n 1- ������� �����\n 2-������� ����� �������";
			std::cin >> chooseStorageType;
		} while (chooseStorageType < 1 || chooseStorageType > 2);
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (chooseStorageType == 1)
		{
			CreateStorage();
			Shop();
		}

		if (chooseStorageType == 2)
		{
			std::cout << "� ����������";
		}
		else
		{
			std::cerr << "Error Choose storage Type!";
		}
	}


}
	


		

int main()
{
	setlocale(LC_ALL, "ru");
	//start();
	/*DeleteMainArrays();
	delete[]nameReciptArr;
	delete[]countReciptArr;
	delete[]priceReciptArr;*/
	return 0;

}

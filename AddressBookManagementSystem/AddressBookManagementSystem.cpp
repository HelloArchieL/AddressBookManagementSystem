#include <iostream>
#include <fstream>
using namespace std;
#define CNT 1000

struct Person {
	char m_Name[64];

	int m_Sex = 1;

	int m_Age = 18;

	char m_Phone[64];

	char m_Addr[64];
};

struct Addressbooks{
	struct Person personArray[CNT];

	int m_Size = 0;
};

void inData(Addressbooks* abs) {
	ifstream ifs;

	ifs.open("../myData.txt", ios::in | ios::binary);

	ifs.read((char *)abs, sizeof(Addressbooks));

	ifs.close();
}

void outData(Addressbooks* abs) {
	ofstream ofs;

	ofs.open("../myData.txt", ios::out | ios::binary);

	ofs.write((const char *)abs, sizeof(Addressbooks));

	ofs.close();
}

void addPerson(Addressbooks* abs) {
	if (abs->m_Size == CNT) {
		cout << "�q�T���w���A�L�k�s�W!" << endl;
		return;
	}else {
		cout << "�п�J�m�W: " << endl;
		cin >> abs->personArray[abs->m_Size].m_Name;

		int sex = 0;;
		cout << "�п�J�ʧO: " << endl;
		cout << "��J - 1. �k  2. �k  " << endl;
		
		while (true) {
			cin >> sex;	
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			else {
				cout << "��J���~�A�Э��s��J!" << endl;
			}
		}

		int age = 0;
		cout << "�п�J�~��: " << endl;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		cout << "�п�J�q��: " << endl;
		cin >> abs->personArray[abs->m_Size].m_Phone;

		cout << "�п�J�a�}: " << endl;
		cin >> abs->personArray[abs->m_Size].m_Addr;

		abs->m_Size++;

		cout << "�s�W���\!!!!!" << endl;

		system("pause");
		system("cls");
	}
}

void showPerson(Addressbooks* abs) {
	if (abs->m_Size == 0) {
		cout << "��e�q�T������!" << endl;
	}
	else {
		for (int i = 0; i < abs->m_Size; i++) {
			cout << "�m�W: " << abs->personArray[i].m_Name << "\t";
			cout << "�ʧO: " << (abs->personArray[i].m_Sex == 1 ? "�k":"�k") << "\t";
			cout << "�~��: " << abs->personArray[i].m_Age << "\t";
			cout << "�q��: " << abs->personArray[i].m_Phone << "\t";
			cout << "�a�}: " << abs->personArray[i].m_Addr << endl;
		}
	}

	system("pause");
	system("cls");
}

int checkPerson(Addressbooks* abs, char name[64]) {
	for (int i = 0; i < abs->m_Size; i++) {
		if (abs->personArray[i].m_Name == name)
			return i;
	}

	return -1;
}

void deletePerson(Addressbooks* abs) {
	cout << "�п�J�A�n�R�����p���H: " << endl;

	char name[64];
	cin >> name;

	int ret = checkPerson(abs, name);

	if (ret != -1) {
		for (int i = ret; i < abs->m_Size - 1; i++) {
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		cout << "�R�����\!" << endl;
	}
	else {
		cout << "�d�L���p���H!" << endl;
	}

	system("pause");
	system("cls");
}

void findPerson(Addressbooks* abs) {
	cout << "�п�J�A�n�j�M���p���H: " << endl;

	char name[64];
	cin >> name;

	int ret = checkPerson(abs, name);

	if (ret != -1) {
		cout << "�m�W: " << abs->personArray[ret].m_Name << "\t";
		cout << "�ʧO: " << (abs->personArray[ret].m_Sex == 1 ? "�k" : "�k") << "\t";
		cout << "�~��: " << abs->personArray[ret].m_Age << "\t";
		cout << "�q��: " << abs->personArray[ret].m_Phone << "\t";
		cout << "�a�}: " << abs->personArray[ret].m_Addr << endl;
	}
	else {
		cout << "�d�L���p���H!" << endl;
	}

	system("pause");
	system("cls");
}

void modifyPerson(Addressbooks* abs) {
	cout << "�п�J�A�n�ק諸�p���H: " << endl;

	char name[64];
	cin >> name;

	int ret = checkPerson(abs, name);

	if (ret != -1) {
		cout << "�п�J�m�W: " << endl;
		cin >> abs->personArray[ret].m_Name;

		int sex = 0;;
		cout << "�п�J�ʧO: " << endl;
		cout << "��J - 1. �k  2. �k  " << endl;

		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			else {
				cout << "��J���~�A�Э��s��J!" << endl;
			}
		}

		int age = 0;
		cout << "�п�J�~��: " << endl;
		cin >> age;
		abs->personArray[ret].m_Age = age;

		cout << "�п�J�q��: " << endl;
		cin >> abs->personArray[ret].m_Phone;

		cout << "�п�J�a�}: " << endl;
		cin >> abs->personArray[ret].m_Addr;

		cout << "�ק令�\!!!!!" << endl;
	}
	else {
		cout << "�d�L���p���H!" << endl;
	}

	system("pause");
	system("cls");
}

void cleanPerson(Addressbooks* abs) {
	cout << "�O�_�M�ųq�T�� - 1.�O 2.�_ ?" << endl;

	int isCheck = 0;
	while (true) {
		cin >> isCheck;
		if (isCheck == 1) {
			abs->m_Size = 0;
			cout << "�q�T���w�M��!" << endl;
			break;
		}
		else if (isCheck == 2) {
			cout << "�w����!" << endl;
			break;
		}
		else {
			cout << "��J���~�A�Э��s��J!" << endl;
		}
	}
	
	system("pause");
	system("cls");
}

void showMenu() {
	cout << "1. �s�W�p���H" << endl;
	cout << "2. ����p���H" << endl;
	cout << "3. �R���p���H" << endl;
	cout << "4. �j�M�p���H" << endl;
	cout << "5. �ק��p���H" << endl;
	cout << "6. �M���p���H" << endl;
	cout << "0. �h�X�q�T��" << endl;
	cout << endl;
}

int main() {
	Addressbooks abs;

	inData(&abs);

	int select = 0;

	while (true) {
		showMenu();

		cin >> select;

		switch (select)
		{
		case 1:
			addPerson(&abs);
			break;
		case 2:
			showPerson(&abs);
			break;
		case 3:
			deletePerson(&abs);
			break;
		case 4:
			findPerson(&abs);
			break;
		case 5:
			modifyPerson(&abs);
			break;
		case 6:
			cleanPerson(&abs);
			break;
		case 0:
			cout << "�h�X�q�T��" << endl;
			system("pause");
			return 0;
			break;
		default:
		{
			cout << "��J���~�A�Э��s��J!" << endl;
			system("pause");
			system("cls");
			break;
		}
		}
		outData(&abs);
	}

	
	system("pause");
	return 0;
}
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
		cout << "通訊錄已滿，無法新增!" << endl;
		return;
	}else {
		cout << "請輸入姓名: " << endl;
		cin >> abs->personArray[abs->m_Size].m_Name;

		int sex = 0;;
		cout << "請輸入性別: " << endl;
		cout << "輸入 - 1. 男  2. 女  " << endl;
		
		while (true) {
			cin >> sex;	
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			else {
				cout << "輸入錯誤，請重新輸入!" << endl;
			}
		}

		int age = 0;
		cout << "請輸入年齡: " << endl;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		cout << "請輸入電話: " << endl;
		cin >> abs->personArray[abs->m_Size].m_Phone;

		cout << "請輸入地址: " << endl;
		cin >> abs->personArray[abs->m_Size].m_Addr;

		abs->m_Size++;

		cout << "新增成功!!!!!" << endl;

		system("pause");
		system("cls");
	}
}

void showPerson(Addressbooks* abs) {
	if (abs->m_Size == 0) {
		cout << "當前通訊錄為空!" << endl;
	}
	else {
		for (int i = 0; i < abs->m_Size; i++) {
			cout << "姓名: " << abs->personArray[i].m_Name << "\t";
			cout << "性別: " << (abs->personArray[i].m_Sex == 1 ? "男":"女") << "\t";
			cout << "年齡: " << abs->personArray[i].m_Age << "\t";
			cout << "電話: " << abs->personArray[i].m_Phone << "\t";
			cout << "地址: " << abs->personArray[i].m_Addr << endl;
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
	cout << "請輸入你要刪除的聯絡人: " << endl;

	char name[64];
	cin >> name;

	int ret = checkPerson(abs, name);

	if (ret != -1) {
		for (int i = ret; i < abs->m_Size - 1; i++) {
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		cout << "刪除成功!" << endl;
	}
	else {
		cout << "查無此聯絡人!" << endl;
	}

	system("pause");
	system("cls");
}

void findPerson(Addressbooks* abs) {
	cout << "請輸入你要搜尋的聯絡人: " << endl;

	char name[64];
	cin >> name;

	int ret = checkPerson(abs, name);

	if (ret != -1) {
		cout << "姓名: " << abs->personArray[ret].m_Name << "\t";
		cout << "性別: " << (abs->personArray[ret].m_Sex == 1 ? "男" : "女") << "\t";
		cout << "年齡: " << abs->personArray[ret].m_Age << "\t";
		cout << "電話: " << abs->personArray[ret].m_Phone << "\t";
		cout << "地址: " << abs->personArray[ret].m_Addr << endl;
	}
	else {
		cout << "查無此聯絡人!" << endl;
	}

	system("pause");
	system("cls");
}

void modifyPerson(Addressbooks* abs) {
	cout << "請輸入你要修改的聯絡人: " << endl;

	char name[64];
	cin >> name;

	int ret = checkPerson(abs, name);

	if (ret != -1) {
		cout << "請輸入姓名: " << endl;
		cin >> abs->personArray[ret].m_Name;

		int sex = 0;;
		cout << "請輸入性別: " << endl;
		cout << "輸入 - 1. 男  2. 女  " << endl;

		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			else {
				cout << "輸入錯誤，請重新輸入!" << endl;
			}
		}

		int age = 0;
		cout << "請輸入年齡: " << endl;
		cin >> age;
		abs->personArray[ret].m_Age = age;

		cout << "請輸入電話: " << endl;
		cin >> abs->personArray[ret].m_Phone;

		cout << "請輸入地址: " << endl;
		cin >> abs->personArray[ret].m_Addr;

		cout << "修改成功!!!!!" << endl;
	}
	else {
		cout << "查無此聯絡人!" << endl;
	}

	system("pause");
	system("cls");
}

void cleanPerson(Addressbooks* abs) {
	cout << "是否清空通訊錄 - 1.是 2.否 ?" << endl;

	int isCheck = 0;
	while (true) {
		cin >> isCheck;
		if (isCheck == 1) {
			abs->m_Size = 0;
			cout << "通訊錄已清空!" << endl;
			break;
		}
		else if (isCheck == 2) {
			cout << "已取消!" << endl;
			break;
		}
		else {
			cout << "輸入錯誤，請重新輸入!" << endl;
		}
	}
	
	system("pause");
	system("cls");
}

void showMenu() {
	cout << "1. 新增聯絡人" << endl;
	cout << "2. 顯示聯絡人" << endl;
	cout << "3. 刪除聯絡人" << endl;
	cout << "4. 搜尋聯絡人" << endl;
	cout << "5. 修改聯絡人" << endl;
	cout << "6. 清空聯絡人" << endl;
	cout << "0. 退出通訊錄" << endl;
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
			cout << "退出通訊錄" << endl;
			system("pause");
			return 0;
			break;
		default:
		{
			cout << "輸入錯誤，請重新輸入!" << endl;
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
#include <iostream>
#include <string>
using namespace std;

class Member {
	string name, tel;
public: 
	string getname() { return name; }
	string gettel() { return tel; }
	void setname(string name) { this->name = name; }
	void settel(string tel) { this->tel = tel; }
};

class Membermanager:public Member {
public:
	int menu_number, search_number, remove_number, revise_number;
	string input_name, input_tel, search_name, revise_name, revise_tel;
	Membermanager(Member *m, int n);
	int menu();
	void list(Member *m, int n);
	void search(Member *m, int n);
	void remove(Member *m, int n);
	void revise(Member *m);
	void end(Member *m);
};

Membermanager::Membermanager(Member *m, int n) {
	cout << n << "���� �̸��� ��ȭ��ȣ�� �Է��մϴ�." << endl;
	for (int i = 0; i < n; i++) {
		cout << "�̸��� ��ȭ��ȣ �Է�: ";
		cin >> input_name >> input_tel;
		m[i].setname(input_name);
		m[i].settel(input_tel);
	}
	cout << "����Ǿ����ϴ�." << endl;
}

int Membermanager::menu() {
	cout << endl;
	cout << "��Ϻ��� [1], �˻� [2], ����[3], ����[4], ����[5]>> ";
	cin >> menu_number;

	return menu_number;
}


void Membermanager::list(Member *m, int n) {
	int a=1;
	for(int i=0; i<n; i++) {
		if (m[i].getname() == " " && m[i].gettel() == " ") {
			continue;
		}
		else {
			cout << "[" << a << "]" << m[i].getname() << " " << m[i].gettel() << endl;
			a++;
		}
	}

}

void Membermanager::search(Member *m, int n) {
	int a=1,result[100];
	while (true) {
		cout << endl;
		cout << "��� �˻�[6], �˻� ����[7] >> ";
		cin >> search_number;
		if (search_number == 6) {
			cout << "�˻��� �̸��� �Է��ϼ���.";
			cin >> search_name;
			for (int i = 0; i < n; i++) {
				result[i] = m[i].getname().compare(search_name);
				if (result[i] == 0) {
					cout << search_name << "��" << " ��ȣ�� " << m[i].gettel() << "�Դϴ�." << endl;
					break;
				}
				else if (result[i] != 0) {
					a++;
					if (a == n) {
						cout << "�˻��� �̸��� �����ϴ�." << endl;
						a = 0;
					}
				}
			}
		}
		else
			break;
	}

}

void Membermanager::remove(Member *m, int n) {
	cout << "��ȣ�� �����ϸ� �����˴ϴ�. >> ";
	cin >> remove_number;
	cout << endl;
	m[remove_number - 1].setname(" ");
	m[remove_number - 1].settel(" ");
	for (int i = 0; i < n; i++) {
		if (m[i].getname() == " ") {
			for (int j = i; j < n - 1; j++) {
				m[j].setname(m[j + 1].getname());
				m[j].settel(m[j + 1].gettel());
			}
			m[n - 1].setname(" ");
			m[n - 1].settel(" ");
			break;
		}
	}
}

void Membermanager::revise(Member *m) {
	cout << "������ ��ȣ�� �����ϼ���. >> ";
	cin >> revise_number;
	cout << "�̸��� ��ȭ��ȣ �Է� >> ";
	cin >> revise_name >> revise_tel;
	cout << endl;
	m[revise_number-1].setname(revise_name);
	m[revise_number-1].settel(revise_tel);

}

void Membermanager::end(Member *m){
	delete [] m;
	cout << endl;
	cout << "���α׷��� �����մϴ�." << endl;
}

int main() {
	int number, menu_number;

	cout << "����� �ο��� >> ";
	cin >> number;
	Member *member = new Member[number];
	Membermanager manager(member, number);

	while (true) {
		menu_number = manager.menu();

		if (menu_number == 1) {
			manager.list(member, number);
			continue;
		}
		else if (menu_number == 2) {
			manager.search(member, number);
			continue;

		}
		else if (menu_number == 3) {
			cout << endl;
			manager.list(member, number);
			manager.remove(member, number);
			manager.list(member, number);
			continue;
		}
		else if (menu_number == 4) {
			cout << endl;
			manager.list(member, number);
			manager.revise(member);
			manager.list(member, number);
			continue;
		}
		else {  
			manager.end(member);
			break;
		}
	}

}

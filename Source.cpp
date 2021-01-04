#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include <conio.h>
#include <iomanip>

using namespace std;


class Kulinariya {
protected:
	string name;
	string type;
public:
	Kulinariya(string w, string w1) {
		name = w;
		type = w1;
	}
	virtual void showData() = 0;
};

class BelarusKitchen :public Kulinariya {
private:
	string Town;
	int how_many_sugar;
public:
	BelarusKitchen(string w, string w1, string yo, int yo1) :Kulinariya(w, w1) {
		Town = yo;
		how_many_sugar = yo1;
	}
	void showData();
};

class RussianKitchen :public Kulinariya {
private:
	string Town;
	int how_many_sugar;
public:
	RussianKitchen(string w, string w1, string yo, int yo1) :Kulinariya(w, w1) {
		Town = yo;
		how_many_sugar = yo1;
	}
	void showData();
};

class UkrainKitchen :public Kulinariya {
private:
	string Town;
	int how_many_sugar;
public:
	UkrainKitchen(string w, string w1, string yo, int yo1) :Kulinariya(w, w1) {
		Town = yo;
		how_many_sugar = yo1;
	}
	void showData();
};

void BelarusKitchen::showData() {
	cout << "		Беларусская кулинария: " << endl;
	cout << "Название: " << name << endl;
	cout << "Тип изделия: " << type << endl;
	cout << "Город изделия: " << Town << endl;
	cout << "Кол-во сахара в изделии: " << how_many_sugar << endl;
}

void RussianKitchen::showData() {
	cout << "		Русская кулинария: " << endl;
	cout << "Название: " << name << endl;
	cout << "Тип изделия: " << type << endl;
	cout << "Город изделия: " << Town << endl;
	cout << "Кол-во сахара в изделии: " << how_many_sugar << endl;
}

void UkrainKitchen::showData() {
	cout << "		Украинская кулинария: " << endl;
	cout << "Название: " << name << endl;
	cout << "Тип изделия: " << type << endl;
	cout << "Город изделия: " << Town << endl;
	cout << "Кол-во сахара в изделии: " << how_many_sugar << endl;
}

void Bel(string&, string&, string&, int&);
void Rus(string&, string&, string&, int&);
void Uk(string&, string&, string&, int&);
int chooseMenu();
string writeWords();
int writeNumbers();

int main() {
	setlocale(0, "rus");
	int n = 1;
	Kulinariya** mas = new Kulinariya * [n];
	n--;
	while (true) {
		int choose = chooseMenu();
		if (choose == 0) {
			string name, type, town;
			int how_manu_sugar;
			Bel(name, type, town, how_manu_sugar);
			mas[n] = new BelarusKitchen(name, type, town, how_manu_sugar);
			mas[n]->showData();
			n++;
			n++;
			Kulinariya** ptr = new Kulinariya * [n];
			n--;
			copy(mas, mas + n, ptr);
			mas = ptr;
			ptr = NULL;
			delete[]ptr;
			system("pause");
			system("cls");
		}
		else
			if (choose == 1) {
				string name, type, town;
				int how_manu_sugar;
				Rus(name, type, town, how_manu_sugar);
				mas[n] = new RussianKitchen(name, type, town, how_manu_sugar);
				mas[n]->showData();
				n++;
				n++;
				Kulinariya** ptr = new Kulinariya * [n];
				n--;
				copy(mas, mas + n, ptr);
				mas = ptr;
				ptr = NULL;
				delete[]ptr;
				system("pause");
				system("cls");
			}
			else
				if (choose == 2) {
					string name, type, town;
					int how_manu_sugar;
					Uk(name, type, town, how_manu_sugar);
					mas[n] = new UkrainKitchen(name, type, town, how_manu_sugar);
					mas[n]->showData();
					n++;
					n++;
					Kulinariya** ptr = new Kulinariya * [n];
					n--;
					copy(mas, mas + n, ptr);
					mas = ptr;
					ptr = NULL;
					delete[]ptr;
					system("pause");
					system("cls");
				}
				else
					if (choose == 3) {
						for (int i = 0; i < n; i++)
							mas[i]->showData();
						system("pause");
						system("cls");
					}
					else break;
	}
	return 0;
}

string writeWords() {
	string slovo;
	while (true) {
		int Knopka;
		char sumbol;
		Knopka = _getch();
		if (Knopka == 224) {
			Knopka = _getch();
		}
		else
			if (Knopka == 8) {
				if (slovo.length() != 0) {
					cout << '\b' << " " << '\b';
					slovo.erase(slovo.length() - 1);
				}
			}
			else
				if (Knopka == 13 && slovo.length() != 0) {
					break;
				}
				else {
					sumbol = (char)Knopka;
					if ((sumbol >= 'a' && sumbol <= 'z') || (sumbol >= 'A' && sumbol <= 'Z') || (sumbol == ' ')) {
						slovo = slovo + sumbol;
						cout << sumbol;
					}
				}
	}
	return slovo;
}

int writeNumbers() {
	string numbers;
	while (true) {
		int key;
		key = _getch();
		if (key == 224) {
			key = _getch();
		}
		else
			if (key == 8) {
				if (numbers.length() != 0) {
					cout << '\b' << " " << '\b';
					numbers.erase(numbers.length() - 1);
				}
			}
			else
				if (key == 13 && numbers.length() != 0) break;
				else
					if (key >= '0' && key <= '9') {
						numbers = numbers + (char)key;
						cout << (char)key;
					}
	}
	return stoi(numbers);
}

int chooseMenu() {
	int choose_menu = 0, keyboard_button = 0;
	while (true) {
		cout << "Стрелочками ВВЕРХ и ВНИЗ выберите пункт меню: " << endl;
		choose_menu = (choose_menu + 5) % 5;

		if (choose_menu == 0) { cout << " -> Беларусская кулинария" << endl; }
		else { cout << " Беларусская кулинария" << endl; }

		if (choose_menu == 1) { cout << " -> Русская кулинария" << endl; }
		else { cout << " Русская кулинария" << endl; }

		if (choose_menu == 2) { cout << " -> Украинская кулинария" << endl; }
		else { cout << " Украинская кулинария" << endl; }

		if (choose_menu == 3) { cout << " -> Вывод всей информации" << endl; }
		else { cout << " Вывод всей информации" << endl; }

		if (choose_menu == 4) { cout << " -> Завершить программу" << endl; }
		else { cout << " Завершить программу" << endl; }

		keyboard_button = _getch();
		if (keyboard_button == 224) {
			keyboard_button = _getch();
			if (keyboard_button == 72) choose_menu--;
			if (keyboard_button == 80) choose_menu++;
		}
		if (keyboard_button == 13) { system("cls"); return choose_menu; }
		system("cls");
	}
}

void Bel(string& name, string& type, string& town, int& how_many_sugar) {
	cout << "	Беларуская кулинария" << endl;
	cout << "Введите название изделия - ";
	name = writeWords();
	cout << endl;
	cout << "Введите тип изделия - ";
	type = writeWords();
	cout << endl;
	cout << "Введите город этого изделия - ";
	town = writeWords();
	cout << endl;
	cout << "Введите количество сахара - ";
	how_many_sugar = writeNumbers();
	system("cls");
}

void Rus(string& name, string& type, string& town, int& how_many_sugar) {
	cout << "	Русская кулинария" << endl;
	cout << "Введите название изделия - ";
	name = writeWords();
	cout << endl;
	cout << "Введите тип изделия - ";
	type = writeWords();
	cout << endl;
	cout << "Введите город этого изделия - ";
	town = writeWords();
	cout << endl;
	cout << "Введите количество сахара - ";
	how_many_sugar = writeNumbers();
	system("cls");
}

void Uk(string& name, string& type, string& town, int& how_many_sugar) {
	cout << "	Украинская кулинария" << endl;
	cout << "Введите название изделия - ";
	name = writeWords();
	cout << endl;
	cout << "Введите тип изделия - ";
	type = writeWords();
	cout << endl;
	cout << "Введите город этого изделия - ";
	town = writeWords();
	cout << endl;
	cout << "Введите количество сахара - ";
	how_many_sugar = writeNumbers();
	system("cls");
}
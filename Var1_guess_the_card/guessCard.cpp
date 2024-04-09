#include <iostream>

enum Suitable {wands, pentacles, cups, peaks};
const int jack = 11; //валет = 11
const int queen = 12;//дама = 12
const int king = 13; //король = 13
const int ace = 14;  //туз = 14

////////////////////////////////////

class Cards {
private:
	int num;      //достоинство карты
	Suitable suit;   //масть

public:
	 Cards(){}         //конструктор без аргументов

	Cards (int n, Suitable m) : num(n), suit(m){} //конструктор с двумя аргументами

	void display();   //вывод на экран

	bool WithDignity(Cards c2);

	bool WithDignity(int card);  //результат сравнения карт
};
////////////////////////////////////
void Cards::display() {  //вывод карты на консоль
	if (num >= 2 && num <= 10)
		std::cout << num;
	else
		switch (num)
		{
		case jack:std::cout << "Валет "; break;
		case queen:std::cout << "Дама "; break;
		case king:std::cout << "Король "; break;
		case ace:std::cout << "Туз "; break;
		}
	switch (suit)
	{
	case wands:std::cout << "Трефы "; break;
	case pentacles:std::cout << "Бубны "; break;
	case cups:std::cout << "Черви "; break;
	case peaks:std::cout << "Пики "; break;
	}
}
//////////////////////////////////////////

bool Cards::WithDignity(Cards c2)  //сравнение
{
	return(num == c2.num && suit == c2.suit) ? true : false;
}
//////////////////////////////////////////

int main() {
	system("chcp 1251>nul");
	Cards temp, chosen, prize; //3 карты
	int position;
	Cards card1(7, wands);     //определение и инициализация card1
	std::cout << "\nКарта 1: ";
	card1.display();         //вывод карты1

	Cards card2(jack, cups);  //определение и инициализация card2
	std::cout << "\nКарта 2: ";
	card2.display();         //вывод карты 2

	Cards card3(ace, peaks);  //определение и инициализация карты 3
	std::cout << "\nКарта 3: ";
	card3.display();         //Вывод карты 3

	prize = card3;           //карту прайз необходимо угадать
	std::cout << "\n Меняем местами карты 1 и 3. . . ";
	temp = card3;
	card3 = card1; 
	card1 = temp;
	std::cout << "\nМеняем местами карты 2 и 3. . .";
	temp = card3;
	card3 = card2;
	card2 = temp;
	std::cout << "\nМеняем местами карты 1 и 2. . .";
	temp = card2;
	card2 = card1;
	card1 = temp;
	std::cout << "\nНа какой позиции (1, 2 или 3) теперь?..";
	prize.display();         //угадываемая карта
	std::cout << "\n ? ";
	std::cin >> position;    //Ввод позиции игроком
	switch (position)
	{
	case 1:chosen = card1; break;
	case 2:chosen = card2; break;
	case 3:chosen = card3; break;
	}
	if (chosen.WithDignity(prize))   //сравнение карт
		std::cout << "\nПравильно! Ты сорвал куш!";
	else
		std::cout << "\nНе угадал...лу...ер((";
	std::cout << "\nВыбранная карта => ";
	chosen.display();          //вывод выбранной карты
	std::cout << std::endl;



	return 0;
}
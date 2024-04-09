#include <iostream>

enum Suitable {wands, pentacles, cups, peaks};
const int jack = 11; //����� = 11
const int queen = 12;//���� = 12
const int king = 13; //������ = 13
const int ace = 14;  //��� = 14

////////////////////////////////////

class Cards {
private:
	int num;      //����������� �����
	Suitable suit;   //�����

public:
	 Cards(){}         //����������� ��� ����������

	Cards (int n, Suitable m) : num(n), suit(m){} //����������� � ����� �����������

	void display();   //����� �� �����

	bool WithDignity(Cards c2);

	bool WithDignity(int card);  //��������� ��������� ����
};
////////////////////////////////////
void Cards::display() {  //����� ����� �� �������
	if (num >= 2 && num <= 10)
		std::cout << num;
	else
		switch (num)
		{
		case jack:std::cout << "����� "; break;
		case queen:std::cout << "���� "; break;
		case king:std::cout << "������ "; break;
		case ace:std::cout << "��� "; break;
		}
	switch (suit)
	{
	case wands:std::cout << "����� "; break;
	case pentacles:std::cout << "����� "; break;
	case cups:std::cout << "����� "; break;
	case peaks:std::cout << "���� "; break;
	}
}
//////////////////////////////////////////

bool Cards::WithDignity(Cards c2)  //���������
{
	return(num == c2.num && suit == c2.suit) ? true : false;
}
//////////////////////////////////////////

int main() {
	system("chcp 1251>nul");
	Cards temp, chosen, prize; //3 �����
	int position;
	Cards card1(7, wands);     //����������� � ������������� card1
	std::cout << "\n����� 1: ";
	card1.display();         //����� �����1

	Cards card2(jack, cups);  //����������� � ������������� card2
	std::cout << "\n����� 2: ";
	card2.display();         //����� ����� 2

	Cards card3(ace, peaks);  //����������� � ������������� ����� 3
	std::cout << "\n����� 3: ";
	card3.display();         //����� ����� 3

	prize = card3;           //����� ����� ���������� �������
	std::cout << "\n ������ ������� ����� 1 � 3. . . ";
	temp = card3;
	card3 = card1; 
	card1 = temp;
	std::cout << "\n������ ������� ����� 2 � 3. . .";
	temp = card3;
	card3 = card2;
	card2 = temp;
	std::cout << "\n������ ������� ����� 1 � 2. . .";
	temp = card2;
	card2 = card1;
	card1 = temp;
	std::cout << "\n�� ����� ������� (1, 2 ��� 3) ������?..";
	prize.display();         //����������� �����
	std::cout << "\n ? ";
	std::cin >> position;    //���� ������� �������
	switch (position)
	{
	case 1:chosen = card1; break;
	case 2:chosen = card2; break;
	case 3:chosen = card3; break;
	}
	if (chosen.WithDignity(prize))   //��������� ����
		std::cout << "\n���������! �� ������ ���!";
	else
		std::cout << "\n�� ������...��...��((";
	std::cout << "\n��������� ����� => ";
	chosen.display();          //����� ��������� �����
	std::cout << std::endl;



	return 0;
}
#include <iostream>//input output
#include <ctime> //時間函式庫

using namespace std;//空間命名，後面可以不用打std::

class slotMachine {//類似struct
private://只能自己class的能修改內容
	int wheelA;
	int wheelB;
	int wheelC;
	double pullTimes;
	double payOut;
	double moneyInMachine;
	double moneyInPeople;
	double gameCost;
	double moneyPaid;
public://大家都可以用
	slotMachine();
	bool displayMenu(void);
	bool pullHandle(void);
	void spinWheel(int &);
	double calculatePayout();
	void insertCoin(double);
	void displaySpinResults();
	int Random(int, int);
	void displayStatus();
};

int main(void) {
	slotMachine mySlot;//定義mySlot的型態是slotMachine
	cout << "Hellow!" << endl;
	cout << "Welcome to our Slot Machine Game." << endl;
	cout << "Now your status:" << endl;
	cout << endl << "Money in Peoele $" << 150 << endl;
	cout << "Money in Machine $" << 100 << endl;
	cout << "Pulls Left: " << 0 << endl << endl;
	//上面用法跟printf是一樣的，endl類似\n的用法
	bool ok = true;
	while (ok)
	{
		ok = mySlot.displayMenu();
	}
	system("pause");
	return 0;
}

slotMachine::slotMachine()//先把上面定義的private的值設定好
{
	srand((int)time(0));//對時間取亂數
	moneyInMachine = 100;
	moneyInPeople = 150;
	moneyPaid = 0;
	pullTimes = 0;
	payOut = 0;
	wheelA = 0;
	wheelB = 0;
	wheelC = 0;
	gameCost = 2;
}
bool slotMachine::pullHandle(void)//使用拉霸
{
	if (pullTimes > 0)//有剩餘次數，才可以使用
	{
		spinWheel(wheelA);
		spinWheel(wheelB);
		spinWheel(wheelC);

		moneyPaid -= gameCost;
		return true;
	}
	else
	{
		return false;
	}
}

void slotMachine::spinWheel(int &theWheel)//使用Random隨機取1~7
{
	theWheel = Random(1, 7);
}

int slotMachine::Random(int lowerLimit, int upperLimit)//取亂數
{
	return 1 + rand() % (upperLimit - lowerLimit + 1);
}

void slotMachine::insertCoin(double amount)//計算投進金額用的
{
	moneyPaid += amount;
	moneyInMachine += amount;
	moneyInPeople -= amount;
}

void slotMachine::displaySpinResults()//顯示拉霸數字
{
	cout << "[" << wheelA << "] "
		<< "[" << wheelB << "] "
		<< "[" << wheelC << "] \n\n";
}

void slotMachine::displayStatus()//檢視狀態
{
	cout << "\nMoney in Peoele $" << moneyInPeople << endl;
	cout << "Money in Machine $" << moneyInMachine << endl;
	cout << "Pulls Left: " << pullTimes << endl << endl;
}

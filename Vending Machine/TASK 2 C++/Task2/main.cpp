
#include <iostream>

using namespace std;

class cashinfo
{
    private:
        int cash;
    public:
	   int CurrentBalance();
	   void accept(int amountIn);

           cashinfo()
           {
	          cash = 0;
           }

           cashinfo(int cashIn)
           {
	            cash = cashIn;
           }

};

int cashinfo :: CurrentBalance()
{
    return cash;
}

void cashinfo :: accept(int amountIn)
{
    cash = cash + amountIn;
}


class machine
{
    private:
	    int numberOfItems;
	    int cost;
    public:
	    int getNoOfItems()
	    {
	        return numberOfItems;
	    }

	    int getCost()
	    {
	         return cost;
        }

        void makeSale()
        {
	         numberOfItems--;
        }

           machine()
           {
	           numberOfItems = 50;
               cost = 50;
           }

           machine(int setNoOfItems, int setCost)
           {
	           numberOfItems = setNoOfItems;
	           cost = setCost;
           }

};

void showSelection();

void sellProduct(machine & product, cashinfo & Counter);

int main()
{
	cashinfo counter;
	machine candy(4, 50);
	machine chips(1, 65);
	machine gum(3, 45);
	machine cookies(2, 85);
	int choice;
	showSelection();
	cin >> choice;
	while (choice != 5)
	{
		switch (choice)
		{
			case 1:
				sellProduct(candy, counter);
				break;
			case 2:
				sellProduct(chips, counter);
				break;
			case 3:
				sellProduct(gum, counter);
				break;
			case 4:
				sellProduct(cookies, counter);
				break;
			default:
				cout << "Invalid selection" << endl;
		}
		showSelection();
		cin >> choice;
	}
	return 0;
}

void showSelection()
{
	cout << "*** Welcome to Candy Shop ***" << endl;
	cout << "To select an item, enter " << endl;
	cout << "1 for Candy" << endl;
	cout << "2 for Chips" << endl;
	cout << "3 for Gum" << endl;
	cout << "4 for Cookies" << endl;
	cout << "5 to exit" << endl;
}

void sellProduct(machine & product, cashinfo & Counter)
{
	int amount1;
	int amount2;
	if (product.getNoOfItems() > 0)
	{
		cout << "Please deposit " << product.getCost() << " Rupees " << endl;
		cin >> amount1;
		if (amount1 < product.getCost())
		{
			cout << "Please deposit another " << product.getCost()- amount1 << " Rupees " << endl;
			cin >> amount2;
			amount1 = amount1 + amount2;
		}

		if (amount1 >= product.getCost())
		{
			Counter.accept(amount1);
			product.makeSale();
			cout << "Collect your item at the bottom and enjoy" << endl;
			cout<<"Collect remaining amount :"<<amount1-(product.getCost())<<endl;
		}

		else
			cout << "The amount is not enough . Collect what you deposited." << endl;
		    cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl << endl;
	}
	else
        cout << "Sorry, this item is sold out." << endl;
}

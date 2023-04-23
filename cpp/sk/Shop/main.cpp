#include "Shop.h"
#include <cstdlib>
using namespace std;

int main()
{
	ShopManage shop;
	shop.Load();
	
	int c;
	do
	{
		system("cls");
		shop.Menu();
		c = ChooseInt(0, 4,"«Î—°‘Ò: ");
		switch (c)
		{
		case 1:
			shop.Sale(); break;
		case 2:shop.GoodsManage(); break;
		case 3:shop.Record(); break;
		case 4:shop.Count(); break;
		default:break;
		}

		system("pause");
	} while (c);

	shop.Save();
	return 0;
}

#include <iostream>
#include "Client.h"
#include "Date.h"
#include "Product.h"
#include "BuyOp.h"
#include "DailyReport.h"
using namespace std;
//TODO: Юзануть индексирования оператор
//Использовтаь эксепшены на проверку открытия файла
void trial(BuyOp obj)
{
    cout << obj.getSumWithSale();
}

int main()
{
    Product prod("Lalka", 1200, 1);
    Product prod1("Pisun", 75, 1);
    Product prod2("Chlen", 111, 1);

    int n = 3;
    Product* PR = new Product[n];
    PR[0] = prod;
    PR[1] = prod1;
    PR[2] = prod2;


    BuyOp BUY(13, 02, 2002, PR, n, 10);

    

    BuyOp* BO = new BuyOp[2];

    BO[0] = BUY;
    BO[1] = BUY;

    DailyReport Day(13, 03, 2002, BO, 2);




    Day.show();

 
     return 0;
}


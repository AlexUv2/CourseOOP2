#include <iostream>
#include <ios>
#include <fstream>
#include "Client.h"
#include "Date.h"
#include "Product.h"
#include "BuyOp.h"
#include "DailyReport.h"
using namespace std;


//Допиоить бинарку
//Использовтаь эксепшены на проверку открытия файла
//Исправить темплейты
//Добавить бинарки
//проверки на запись\чтение

template <typename T3, typename T4>
T3 midValOfProds(T4 D, T3 a = 0);


template <typename T1, typename T2>
T1 averProdNum(T2 D, T1 a = 0);

void SearchByName(string name, DailyReport& D)
{
    for (int i = 0; i < D.getN(); i++)
    {
        for (int j = 0; j < D[i].getN(); j++)
        {
            if (D[i][j].getProdName() == name)
            {
                cout << "Found Product with name " << name << endl;

                D[i][j].show();
                cout <<  "It is in the Buying Operations for the day ";
                cout << D[i].getDay() << "." << D[i].getMonth() << "." << D[i].getYear() << endl << endl;
                
                ////Умова виходу з циклу
                //i = D.getN();
                //j = D[i].getN();
                return;
            }
        }
    }
    cout << " There is no product with name " << name << endl;
}

void SearchByPrice(int price, DailyReport& D)
{
    for (int i = 0; i < D.getN(); i++)
    {
        for (int j = 0; j < D[i].getN(); j++)
        {
            if (D[i][j].getProdPrice() == price)
            {
                cout << "Found Product with price " << price << endl;
                D[i][j].show();
                cout << "It is in the Buying Operations for the day ";
                cout << D[i].getDay() << "." << D[i].getMonth() << "." << D[i].getYear() << endl << endl;
                ////Умова виходу з циклу
                //i = D.getN();
                //j = D[i].getN();
                return;
            }
        }
    }
    cout << " There is no product with name " << price << endl;
}

/*
* 1)Ввод с клавы
* 2)Вывод с таблицы
* 3)Запись текстом
* 4)Запись биполярочкой
* 5)Считывание с файлов
* 6)Поиск по тексту или числу
*/

int main()
{
    //Дефолтный Обьект со списком
    const int defNum = 20;
    const int numBuyop = 10;
    int defday = 15;
    int defmonth = 11;
    int defyear = 2007;
    Product prodLST[defNum];
    string prodNames[defNum] = { "Milk", "Nut", "Water", "Bread", "Sausage", "Meat", "Apples", "Bananas",
        "Oranges", "Carrot", "Beer", "Potato", "Fish", "Onion", "Chees", "Cream", "Oil", "Sugar", "Salt", "Tomato" };

    for (int i = 0; i < defNum; i++)
    {
        prodLST[i] = Product(prodNames[i], rand() % 1000, (i % 2 == 0));
    }


    BuyOp buyopLST[numBuyop];
    for (int i = 0; i < numBuyop; i++)
    {
        buyopLST[i] = BuyOp(defday, defmonth, defyear, prodLST[rand() % 19], rand() % 9 + 1);

        for (int j = 0; j < (rand() % 5 + 1); j++)
        {
            buyopLST[i].addProduct(prodLST[rand() % 20]);
        }
    }

    DailyReport dayRep(defday, defmonth, defyear, buyopLST, numBuyop);
    // *Дефолтный Обьект со списком*





    cout << " Enter 1 to Fill tables by kewboard\n" <<
        " Enter 2 to print Daily Reports from file\n" <<
        " Enter 3 to write to file default values\n" << //Сделать выбор - бинарка/текст
        " Enter 4 to read tables from files\n" <<
        " Enter 5 to search for any values\n" <<
        " Enter 6 to change file name\n" <<
        " Enter 0 to Exit\n";


    DailyReport D;

    //Дефолтный ввод
    string path = "DAILYREPORT.txt";
    ifstream read;
    ofstream write;


    //Для ручного ввод
    string userpath = "USERDAILYREPORT.txt";
    ifstream userread;
    ofstream userwrite;



    int numOfReports;//Для кол-ва репортов
    int numOfBuyOps;//Кол-во операций покуопк
    int numOfProds;//кол-во продуктов

    int day;
    int month;
    int year;

    string prodName; //Название продукта
    double prodPrice;
    bool saleAvib;

    int salePerc;
    Product* prod;
    BuyOp* buyop;
    DailyReport* rep;//для первого кейза
    // *Для ручного ввода*



    //Второй пункт - счиытвание из файла
    

    // *Считывание из файла*


    while (true)
    {
        int num;
        cout << "\n Enter number of choice: ";
        cin >> num;

        switch (num)
        {
        case 1:
            cout << " Enter number of reports to create: ";
            cin >> numOfReports;


            rep = new DailyReport[numOfReports];

            for (int i = 0; i < numOfReports; i++)
            {
                cout << " Enter Purchasing date: " ;
                cin >> day;
                cin >> month;
                cin >> year;

                cout << " Enter number of Buying Operations in day: ";
                cin >> numOfBuyOps;

                buyop = new BuyOp[numOfBuyOps];
                for (int i = 0; i < numOfBuyOps; i++)
                {
                    cout << " Enter sale percent for this list:";
                    cin >> salePerc;

                    cout << " Enter number of products in your list: ";
                    cin >> numOfProds;

                    prod = new Product[numOfProds];
                    for (int i = 0; i < numOfProds; i++)
                    {
                        cout << " Enter Product name: ";
                        cin >> prodName;

                        cout << " Enter Product price: ";
                        cin >> prodPrice;

                        cout << " Enter if product have a discount(1-yes, 0-no): ";
                        cin >> saleAvib;

                        cout << "\n\n\n";
                        prod[i] = Product(prodName, prodPrice, saleAvib);
                    }

                    buyop[i] = BuyOp(day, month, year, prod, numOfProds, salePerc);
                }

                rep[i] = DailyReport(day, month, year, buyop, numOfBuyOps);
                rep[i].show();
                cout << "\n\n\n\n\n";


                system("cls");

                ofstream userwrite;
                userwrite.open(userpath);
                rep->writeDayPer(userwrite);
                userwrite.close();
            }
            break;
        case 2:

            cout << " What file you want to read: \n";
            cout << " 1 - made by user\n" <<
                " 2 - default file\n";

            cout << "Enter number: ";
            cin >> num;
            switch (num)
            {
            case 1:
                userread.open(userpath);
                D.readDayRep(userread);
                userread.close();
                D.show();

                break;

            case 2:
                read.open(path);
                D.readDayRep(read);
                read.close();
                D.show();

                break;
                cout << "Wrong number";
            default:
                break;
            }
            

        case 3:
            write.open(path);
            dayRep.writeDayPer(write);
            write.close();
            cout << " File successfully writen \n";
            break;


        case 4:

            userread.open(userpath);
            D.readDayRep(userread);
            userread.close();


            read.open(path);
            D.readDayRep(read);
            read.close();

            cout << " File successfully readed";

            break;
            
        case 5:
            cout << " Choose the report where you want to search (1-manual, 2-default): ";
            cin >> num;
            switch (num)
            {
            case 1:

                userread.open(userpath);
                D.readDayRep(userread);
                userread.close();

                cout << " To search price - enter 1, name of product - 2";
                cin >> num;
                switch (num)
                {
                case 1:
                    cout << " Enter product price to find: ";
                    cin >> prodPrice;
                    SearchByPrice(prodPrice, D);
                    break;

                case 2:
                    cout << " Enter product name to find: ";
                    cin >> prodName;
                    SearchByName(prodName, D);
                    break;
                default:
                    cout << "Wrong number";
                    break;
                }
                break;

            case 2:
                read.open(path);
                D.readDayRep(read);
                read.close();

                cout << " To search price - enter 1, name of product - 2: ";
                cin >> num;
                switch (num)
                {
                case 1:
                    cout << " Enter product price to find: ";
                    cin >> prodPrice;
                    SearchByPrice(prodPrice, D);
                    break;

                case 2:
                    cout << " Enter product name to find: ";
                    cin >> prodName;
                    SearchByName(prodName, D);
                    break;
                default:
                    cout << "Wrong number";
                    break;
                }
                break;

            default:
                cout << " Wrong number";
                break;
            }

            break;

        case 6:

            cout << " Choose which file name you want to change(1-user, 2-default)/n Enter choice: ";
            cin >> num;
            switch (num)
            {
            case 1:
                cout << " Enter new file name: ";

                cin >> userpath;
                userpath += ".txt";
                break;

            case 2:
                cout << " Enter new file name: ";

                cin >> path;
                path += ".txt";
                
                break;
            default:
                cout << "Wrong number" << endl;
                break;
            }

            cout << " Enter new file name: ";

            cin >> path;
            path += ".txt";
            break;

        case 7:
            D.Tab();
            break;

        case 0:
            return 0;
            break;
        default:
            cout << " Wrong operation, try again";
            break;
        }
    }

 
      


        //Day.show();



        /*string path = "DATE.txt";
        ofstream write;
        write.open(path);

        Date A(13, 03, 2002);


        if (!write)
        {
            cout << "error opening DATA error" << endl;
        }
        else
        {
            cout << " file DATA opened" << endl;
            A.writeDate(write);
        }
        write.close();

        Date B;
        ifstream read;
        read.open(path);
        if (!read)
        {
            cout << " reading DATA error" << endl;
        }
        else
        {
            cout << " Reading DATA Okay" << endl;
            B.readDate(read);
        }
        read.close();
        B.show();
        cout << "\n\n\n";*/



        /*string path1 = "CLIENT.txt";
        Client Alex(10, 12);
        ofstream write1;
        write1.open(path1);
        if (!write1)
        {
            cout << "error opening CLIENT error" << endl;
        }
        else
        {
            cout << " file CLIENT opened" << endl;
            Alex.writeClient(write1);
        }
        write1.close();


        Client Alex1;
        ifstream read1;
        read1.open(path1);
        if (!read1)
        {
            cout << "error opening CLIENT error" << endl;
        }
        else
        {
            cout << " reading CLIENT opened" << endl;
            Alex1.readClient(read1);
        }
        read1.close();

        Alex1.show();*/


        /*string path2 = "PRODUCT.txt";
        Product prod3(" Apps", 13, 1);
        ofstream write2;
        write2.open(path2);

        prod3.writeProduct(write2);
        write2.close();



        Product prod4;
        ifstream read2;
        read2.open(path2);


        prod4.readProduct(read2);
        read2.close();

        prod4.show();*/


        /*string path3 = "BUYOP.TXT";

        ofstream write3;
        write3.open(path3);
        BUY.writeBuyOp(write3);
        write3.close();

        ifstream read3;
        read3.open(path3);
        BuyOp buyop;
        buyop.readBuyOp(read3);
        read3.close();
        buyop.show();*/


        /*string path4 = "DAILYREPORT";
        ofstream write4;
        write4.open(path4);
        Day.writeDayPer(write4);
        write4.close();

        DailyReport D;
        ifstream read4;
        read4.open(path4);
        D.readDayRep(read4);
        read4.close();
        D.show();*/



        //cout << averProdNum<DailyReport>(Day);
   


        delete[] rep;
        delete[] prodLST;
     return 0;
}

template <typename T1, typename T2>
T1 averProdNum(T2 D, T1 a)
{
    T1 sum = 0;
    T1 numOfProds = 0;
    for (int i = 0; i < D.getN(); i++)
    {
        for (int j = 0; j < D[i].getN(); j++)
        {
            sum += D[i][j].getProdPrice();
            numOfProds++;
        }
    }

    T1 av = (sum / numOfProds);

    return av;
}


template <typename T3, typename T4>
T3 midValOfProds(T4 D, T3 a)
{
    T3 sum = 0;
    for (int i = 0; i < D.getN(); i++)
    {
        sum += D[i].getN();
    }
    return sum / D.getN();
}

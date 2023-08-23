#include <iostream>
#include <string>
using namespace std;

void PrintDynArray(int* arr, int arrActualSize, int arrLogicalSize ,bool stopActions)
{
    for (int i = 0; i < arrLogicalSize; i++)
    {
        cout << " ";
        cout << arr[i];
    };

    for (int i = arrLogicalSize; i < arrActualSize; i++)
    {
        cout << " ";
        cout << "_";
    };

    cout << endl;
};




enum class DynamicArrayMessage
{
    Exit
};
void appendToDynArray(int*& arr, int* arrFactSize, int* arrLogicalSize)
{
    int appendUserData = 0;
    bool stopActions = false;
    do
    {
        cout << "Enter arr 1 ";
        cin >> appendUserData;

        while (!cin.good())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter arr 2 \n";
            cout << "Enter arr 3";
            cin >> appendUserData;
        }
        if (appendUserData == static_cast<int> (DynamicArrayMessage::Exit))
        {
            bool stopActions = true;
            PrintDynArray(arr, *arrFactSize, *arrLogicalSize, stopActions);

            return;
        }
        if (*arrFactSize == *arrLogicalSize)
        {
            *arrFactSize *= 2;
            int* arr2 = new int[*arrFactSize] {};

            for (int i = 0; i < *arrLogicalSize; i++)
            {
                arr2[i] = arr[i];
            };

            arr = arr2; 
            arr2 = nullptr; 
        }
        arr[*arrLogicalSize] = appendUserData; 
        ++* arrLogicalSize; 
        PrintDynArray(arr, *arrFactSize, *arrLogicalSize, stopActions);
    } while (true);
};

int main()
{
    setlocale(LC_ALL, "Russian");

    int arrFactSize = 0; 
    int arrLogicalSize = 0; 


    cout << "Введите фактичеcкий размер массива:> ";
    cin >> arrFactSize;

    while (!cin.good() || arrFactSize <= 0)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Вы ввели неверные даннные. Размер массива положительное целое число.\n";
        cout << "Введите фактичеcкий размер массива:> ";
        cin >> arrFactSize;
    }

    bool ErrorUserData = false; 

    do
    {
        cout << "Введите логичеcкий размер массива:> ";
        cin >> arrLogicalSize;

        while (!cin.good() || arrFactSize <= 0)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Вы ввели неверные даннные. Размер массива положительное целое число.\n";
            cout << "Введите логичеcкий размер массива:> ";
            cin >> arrLogicalSize;
        }

        if (arrLogicalSize > arrFactSize)
        {
            cout << "Ошибка! Логический размер массива не может превышать фактический!" << std::endl;
            ErrorUserData = false;
        }
        else
        {
            ErrorUserData = true;
        }

    } while (!ErrorUserData);



    int userData = 0;
    int* arr = new int[arrFactSize] {};



    for (int i = 0; i < arrLogicalSize; i++)
    {
        cout << "Введите arr[" << i << "]:> ";
        cin >> userData;
        arr[i] = userData;
    };



    cout << endl;
    PrintDynArray(arr, arrFactSize, arrLogicalSize, false);
    cout << endl;
    appendToDynArray(arr, &arrFactSize, &arrLogicalSize);
    cout << endl;



    delete[]arr;
    arr = nullptr;
}
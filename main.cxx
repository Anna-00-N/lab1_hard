#include <iostream> //ввод-вывод
#include <windows.h> // для shellapi ???
#include <shellapi.h>//для запуска matlab

#include "funcs.h" //второй по главности после main файл, ссылается на все отальные файлы

using namespace std; //стандартная среда имён


int main(int argc, char *argv[])
{
	setlocale(LC_CTYPE, ".866"); //С MinGW ПО-ДРУГОМУ НИКАК

	double X, Y, Y2;

	wcout << L"Для выхода из цикла введите 9999"<<endl;
	while(0==0){
		wcout << L"Введите значение X: "; //С MinGW ПО-ДРУГОМУ НИКАК, ТОЛЬКО ЧЕРЕЗ L-СТРОКИ
		cin >> X; 
		cout<<endl;
		if(X==9999) break;
		
		//Способ 1
		Y2 = way1(X);
		wcout << L"  Способ 1:  Y = " << Y2 << endl;
		
		//Способ 2
		Y = way2(X);
		wcout << L"  Способ 2:  Y = " << Y << endl;
	
		// имеет ф-ции вывода cout\/
		matlab(X, Y, -10,15, -5,5); //запись информации в файл graphik.m и оповещение об этом, -5,9, -6,6 - границы по х и у
	}

	wcout<<L"Загрузка...";

	ShellExecute(NULL,"open","graphik.m",NULL,NULL,SW_SHOWNORMAL);

	cin.get();
	return 0;
}
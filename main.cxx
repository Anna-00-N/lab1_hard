#include <iostream> //ввод-вывод
#include <windows.h> // для shellapi ???
#include <shellapi.h>//для запуска matlab
#include <sstream>//доп. строковые потоки - чтобы не использовать scrcat для объединения строк

#include "./functions/funcs.h" //второй по главности после main файл, ссылается на все отальные файлы

using namespace std; //стандартная среда имён


int main(int argc, char *argv[])
{
	setlocale(LC_CTYPE, ".866"); //С MinGW ПО-ДРУГОМУ НИКАК

	double X, Y, R;

	int k = r_kolvo(); //количество R в данных data.h
	stringstream r_vars;//сюда будут через разделитель записаные буквы R

	for(int i=0; i<k; i++){
		wcout << L" Введите "; 
		cout<<r_N(i)<<": "; //r_N( ) - string, не L-строка
		cin >> R; 
		wcout<<endl;
		r_vars << R << " ";
	}

	wcout << L"Для выхода из цикла введите 9999"<<endl;
	while(0==0){
		wcout << L" Введите значение X: "; //С MinGW ПО-ДРУГОМУ НИКАК, ТОЛЬКО ЧЕРЕЗ L-СТРОКИ
		cin >> X; 
		wcout<<endl;
		if(X==9999) break;
		
		Y = way1(X, r_vars.str() );
		wcout << L" Y = " << Y << endl;
	
		// имеет ф-ции вывода cout\/
		matlab(X, Y, -10,15, -5,5,  r_vars.str()); //запись информации в файл graphik.m и оповещение об этом, -5,9, -6,6 - границы по х и у
	}

	wcout<<L"Загрузка...";

	ShellExecute(NULL,"open","graphik.m",NULL,NULL,SW_SHOWNORMAL);

	cin.get();
	return 0;
}
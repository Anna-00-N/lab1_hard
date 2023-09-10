#include <string>

using namespace std;

void text_to_params(string text, double* b_x, int* t, double* p1, double* p2, double* p3, double* p4){
	int sps[] = {0,0,0,0,0}; //массив пробелов
	int j; //для поиска нулей
	int num, sym1, sym2; //номер пробела и номера символов для выделения слов из каждой строки
	double before_x; //параметр, до какого максимальногг числа по оси Х действует функция
	int tip=-1; //0 - прямая, 1 - круг
	double par1=0, par2=0, par3=0, par4=0; //параметры - k/половина круга по y, m/R, сдвиги по х и по у
	string sstr;
	//заходим в каждую строну
	j = 0;
	for(int i=0; i<text.size();i++) //ищем пробелы
		if(text[i]==' ') sps[j++]=i;
	for(num=0, sym1=0; num<=j; num++) {//проход по пробелам для разделения слов
			sym2=sps[num];
			//переводим sym2 на очередной пробел
			sstr=text.substr(sym1, sym2-sym1);
			//далее проставляем параметры из подстроки sstr
			switch(num){
				case 0: before_x=(sstr=="N")?(999999):(atof(sstr.c_str()) );break;
				case 1: tip = (sstr.compare("line")==0)?(0):((sstr.compare("circle")==0)?(1):(-1)); break;
				case 2: par1 = (sstr=="plus")?(0):((sstr=="minus")?(1):(atof(sstr.c_str()))) ;break;					case 3: par2 = atof(sstr.c_str()) ;break;					case 4: par3 = atof(sstr.c_str()) ;break;
				case 5: par4 = atof(sstr.c_str()) ;break;
			}
			sym1=sym2+1;
			//переводим sym1 на место после предыдущего пробела
		}
	*b_x=before_x; *t=tip; *p1=par1; *p2=par2; *p3=par3; *p4=par4; //передача параметра обратно
	//delete [] sps; 
}
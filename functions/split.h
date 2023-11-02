#include <string>
#include <sstream>

using namespace std;

void text_to_params(string text, double* b_x, int* t, double* p1, double* p2, double* p3, double* p4, double* p5, string r_vars, double* R, int* f){
	int sps[] = {0,0,0,0,0}; //массив пробелов
	int j; //для поиска нулей
	int num; //номер пробела
	double before_x; //параметр, до какого максимальногг числа по оси Х действует функция
	int tip=-1; //0 - прямая, 1 - круг
	double par1=0, par2=0, par3=0, par4=0, par5=0; //параметры - k/половина круга по y, m/R, сдвиги по х и по у
	string sstr;
	int f1=0, f2=0, f0=0; //f1 - флаг круг ли это; f2 - 
	//заходим в каждую строну, f0 - флаг на круг с R
	double R0 = 0; int cases; 
	stringstream s1(text);
	stringstream s2(r_vars);
	j = 0;
	
	num=0;
	while(s1>>sstr){
			//далее проставляем параметры из подстроки sstr
			switch(num){
				case 0: before_x=(sstr=="N")?(999999):(atof(sstr.c_str()) );break;
				case 1: tip = (sstr.compare("line")==0)?(0):((sstr.compare("circle")==0)?(1):(-1)); break;
				case 2: par1 = (sstr=="plus")?(0):((sstr=="minus")?(1):(atof(sstr.c_str()))) ; break;				
				case 3: 
					if(sstr[0]=='R'){ 
						cases = atof(sstr.substr(1, sstr.size()-1).c_str());
						for(int k=0; k<cases; k++) s2 >> R0;
						par2 = R0; f0 = 1;
					}//ВВЕДЁННОЕ ЗНАЧЕНИЕ РАДИУСА R
					else par2 = atof(sstr.c_str()) ; 
				break;					
				case 4: par3 = atof(sstr.c_str()) ;
				break; 
				case 5: par4 = atof(sstr.c_str()) ; 
				break;
				case 6: par5 = atof(sstr.c_str()) ;
				break;
			}
			num++;
		}
	*b_x=before_x; *t=tip; *p1=par1; *p2=par2; *p3=par3; *p4=par4; *p5=par5; *f=f0; *R=R0;//передача параметра обратно
	//delete [] sps; 
}
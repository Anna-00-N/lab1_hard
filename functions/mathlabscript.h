#include <sstream>
#include <string>
 
string script(double fx, double fy, double minx,double maxx, double miny, double maxy, int j, int m){
	stringstream s;
	s<<"fx="<<fx<<"; fy="<<fy<<";"<<endl;
	s<<"minx="<<minx<<";maxx="<<maxx<<";"<<endl;
	s<<"miny="<<miny<<";maxy="<<maxy<<";"<<endl;
	s<<"plot(";
	s<<"minx:1:maxx,zeros(maxx-minx+1),'-k|',";
	s<<" zeros(maxy-miny+1),miny:1:maxy,'-k_',";
	for(int i=1; i<=j; i++) s<<" x"<<i<<",y"<<i<<",'-b', ";
	for(int i=1; i<=m; i++) s<<" m"<<i<<",t"<<i<<",'--m', ";
	s<<"[minx fx maxx+1], [fy fy fy], '--ro' , ";
	s<<"[fx fx fx], [miny fy maxy+1], '--ro', ";
	s<<"[0 0],[miny-1 maxy],'-k^', ";
	s<<"[minx-1,maxx],[0 0],'-k>', ";
	s<<"'LineWidth', 2); "<<endl;
	s<<"axis([minx maxx miny maxy]); "<<endl;
	s<<"set(gca, 'XTick',minx:1:maxx, 'YTick',miny:1:maxy);"<<endl;
	s<<"grid on; "<<endl;
	s<<"text(maxx+0.2,-0.3,'X','fontsize',14); "<<endl;
	s<<"text(0.3,maxy+0.2,'Y','fontsize',14); "<<endl;
	s<<"text(fx+0.2,miny+0.2,string(fx),'fontsize',12, 'color','[0.8 0 0]'); "<<endl;
	s<<"text(minx+0.2,fy+0.2,string(fy),'fontsize',12,'color','[0.8 0 0]');"<<endl;
	return s.str();
}
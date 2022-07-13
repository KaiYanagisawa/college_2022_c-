#include<iostream>
#include<iomanip>
#include<fstream>

struct DATA{
	double x{},y{};
};

double lagrange(DATA*,int,double);

int main(){
	DATA XY1[]={{0.15,0.63},{0.25,0.52},{0.35,0.47},{0.55,0.55},{0.95,1.43}}; 
	DATA XY2[10]{};
	int n{11};

	std::cout<<" x    y\n";
	for(int i=0;i<n;i++){
		std::cout<<std::fixed<<std::setw(3)<<std::setprecision(1)<<0.1*i<<std::setw(6)<<std::setprecision(2)<<lagrange(XY1,std::size(XY1),0.1*i)<<"\n";
	}
	std::cout<<"\n";

	//②ここにファイル読み込みとXY2配列へのデータの代入を書く
	std::cout<<" x2   y2\n";
	for(int i=0;i<n;i++){
		std::cout<<std::fixed<<std::setw(3)<<std::setprecision(1)<<0.2*i<<std::setw(6)<<std::setprecision(2)<<lagrange(XY2,std::size(XY2),0.2*i)<<"\n";
	}
}

	//①ここにlagrange関数を定義する．

#include<bits/stdc++.h>
using namespace std;
int n;double us;

double avg(vector<double> v){
	double sum=0;
	for(auto &i:v)
		sum+=i;
	return sum/n;
}

int main(){
	vector<double>x;						//测量值 
	vector<double>y;						//设定值 
	vector<double>c;						//残差 
	vector<int>del_dot;						//需要删除点的下标 
	double p,q;
	cout<<"---------------------"<<endl;
	cout<<"第一组数据"<<endl; 
	ifstream in("data_in1.txt");
	ofstream out("data_out1.txt");
	while(in>>p>>q){
		x.push_back(p);
		y.push_back(q);
	}
	in.close();
	
	n=x.size();us=10.0;
	double x_avg=avg(x);
	double y_avg=avg(y);
	
	cout<<"x的平均值为"<<endl;
	cout<<x_avg<<endl;
	cout<<"y的平均值为"<<endl;
	cout<<y_avg<<endl;
	
	double b=0,fz=0,fm=0;
	for(int i=0;i<n;i++){
		fz+=(y[i]-y_avg)*(x[i]-x_avg);
	}
	for(int i=0;i<n;i++){
		fm+=(x[i]-x_avg)*(x[i]-x_avg);
	}
	b=fz/fm;
	double a=y_avg-b*x_avg;
	
	cout<<"回归方程为:"<<endl;
	cout<<"y="<<b<<"*x+"<<a<<endl;
	
	double d=0;
	for(int i=0;i<n;i++){
		double tmp;
		tmp=x[i]-b*x[i]-a;
		c.push_back(tmp);
		out<<tmp<<endl;
	}
	for(auto &i:c){
		d+=i*i;
	}
	d/=n;
	cout<<"残差平方均值为"<<endl;
	cout<<d<<endl;
	
	for(int i=0;i<n;i++){
		if(c[i]*c[i]>d)
		del_dot.push_back(i);
	}
	double h=0;
	for(auto &i:del_dot){
		h+=(x[i]-us)*(x[i]-us);
	}
	h/=del_dot.size()*us*us;
	cout<<"被删除数据波动值为"<<endl;
	cout<<h<<endl; 
	
	in.close();out.close();
		
	cout<<"---------------------"<<endl;
	cout<<"第二组数据"<<endl; 
	in.open("data_in2.txt");out.open("data_out2.txt");
	x.clear();y.clear();c.clear();del_dot.clear();
	while(in>>p>>q){
		x.push_back(p);
		y.push_back(q);
	}
	
	n=x.size();
	x_avg=avg(x);
	y_avg=avg(y);
	
	cout<<"x的平均值为"<<endl;
	cout<<x_avg<<endl;
	cout<<"y的平均值为"<<endl;
	cout<<y_avg<<endl;
	
	b=0,fz=0,fm=0;
	for(int i=0;i<n;i++){
		fz+=(y[i]-y_avg)*(x[i]-x_avg);
	}
	for(int i=0;i<n;i++){
		fm+=(x[i]-x_avg)*(x[i]-x_avg);
	}
	b=fz/fm;
	a=y_avg-b*x_avg;
	
	cout<<"回归方程为:"<<endl;
	cout<<"y="<<b<<"*x+"<<a<<endl;
	
	d=0;
	for(int i=0;i<n;i++){
		double tmp;
		tmp=x[i]-b*x[i]-a;
		c.push_back(tmp);
		out<<tmp<<endl;
	}
	for(auto &i:c){
		d+=i*i;
	}
	d/=n;
	cout<<"残差平方均值为"<<endl;
	cout<<d<<endl;
	
	for(int i=0;i<n;i++){
		if(c[i]*c[i]>d)
		del_dot.push_back(i);
	}
	h=0;
	for(auto &i:del_dot){
		h+=(x[i]-us)*(x[i]-us);
	}
	h/=del_dot.size()*us*us;
	cout<<"被删除数据波动值为"<<endl;
	cout<<h<<endl; 
	
	in.close();out.close();
	return 0;
}


	#include <iostream>
	#include <stdio.h>
	#include <conio.h>
	#include <vector>
	#include <string>
	#include <iomanip>
	#include <algorithm>
	#include <math.h>
#include <list>
	#include <fstream>
	# define P          3.141592653589793238462643383279502884L	 /* pi */
	# define MOD 1000000007;
	using namespace std;

	double k = 6.0;
	double eps = 0.0000001;
	int needPod=6;
	int n=500;
	ofstream ans;
	double f(double x1, double x2){
			return 180.45*x1*x1-k*29.7*x1*x2+(0.05*k*k+45)*x2*x2-1/k*(k*k+9)*x1-1/k*(k*k+9)*x2;}

	double df1 (double x1, double x2,int i)
	{
		if (i==1) return (7.5+178.2*x2)/360.9;
		if (i==2) return (360.9*x1-7.5)/178.2;

	}
	double df2 (double x1, double x2,int i)
	{
		
		if (i==1) return (93.6*x2-7.5)/178.2;
	    if (i==2) return (7.5+178.2*x1)/93.6;
	}

	void pokoord(double x1, double x2, int n1, int n2){
	
		double newX=0;
		if (!(n1==n && n2==n)){
			ans << n1+n2+1<< ':' <<  endl;
			ans << "x1= " << x1 << endl;
			ans << "x2= " << x2 << endl;
			ans << "F= " << f(x1,x2) << endl;
			ans << endl;
			
			if (n1<=n2){
				newX=df1(x1,x2,1);
				pokoord(newX,x2,n1+1,n2);
			}else {  
				newX=df2(x1,x2,2);
				pokoord(x1,newX,n1,n2+1);
			}
		} else {ans << "x1= " << x1 << endl;
			ans << "x2= " << x2 << endl;
			ans << "F= " << f(x1,x2) << endl;
			ans << endl;}

	}
	

	double jz1(int pod, double x1, double x2, double h1, double h2, int m1, int m2, double pred)	{

		double a=x1,b=x2,c,d,fe;
		int e,t;

		if (pod<needPod && abs(h1)>eps && abs(h2)>eps)
		if (m1>m2) { 
			b=x2+h2;
			c=h1;
			d=h2;
			e=m1;
			t=m2+1;
			fe=f(a,b);

				
		ans << "x1=       " << a << endl;
		ans << "x2=       " << b << endl;
		ans << "h1=       " << c << endl;
		ans << "h2=       " << d << endl;
		ans << "F(x1,x2)= " << fe << endl;
		ans << "m1+m2=    "  << m1+m2 << endl;
		ans		 << endl;
			

			if (pred>=fe) {
				   jz1(pod+1,a,b,c,d*3,e,t,fe); 
			}else  jz1(0,x1,x2,h1,d*(-0.5),m1,m2,f(x1,x2));

		} else 
		 { 
			a=x1+h1;
			d=h2;
			e=m1+1;
			t=m2;
			c=h1;
			fe=f(a,b);

				
		ans << "x1=       " << a << endl;
		ans << "x2=       " << b << endl;
		ans << "h1=       " << c << endl;
		ans << "h2=       " << d << endl;
		ans << "F(x1,x2)= " << fe << endl;
		ans << "m1+m2=    "  << m1+m2 << endl;
		ans		 << endl;
			

			if (pred>=fe) jz1(pod+1,a,b,c*3,d,e,t,fe); 
			else     	  jz1(0,x1,x2,c*(-0.5),d,m1,m2,f(x1,x2));
		}

	
		return 0;
	}

	

	int main(){

		ans.open("out.txt");
	
		double x1=(double)-1,x2=(double)-1;
		
		jz1(0,-1.0,-1.0,1.0/6.0,1.0/6.0,0,0,f(x1,x2));
		//pokoord(-1,-1,0,0);
		ans.close();
		system("pause");	
	}
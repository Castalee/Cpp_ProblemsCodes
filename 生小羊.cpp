//һֻĸ�򣬵����꿪ʼÿ����һֻС�򣬵�n��һ�������� 
#include <iostream>
using namespace std;

int main() {
    int i, n;
    long a=1, b=1, c=1, temp;
    cin >>n;
    if(n==1||n==2) cout<<"1"<<endl;
    else{
         for(i=3; i<=n; i++){
             temp=a+c;
	         a=b; 
	       	 b=c; 
	    	 c=temp;
         }
    cout << c <<endl;
   }
}


#include <iostream>
#include<string>  
using namespace std;  
  
int main() {   
    int n;
    cin >> n;
    while(n--) {
    	string s1,s2;  
        cin >> s1 >> s2;
        int i = 0, mark = 0;
        int length = s1.size();  
        while (i < length) {  
            if (s1[i] == s2[0]) {  
                for (int k = i,j = 0;j < s2.size();k++,j++) {  
                    if(s1[k%length] != s2[j]) {  
                        mark = 0;         //markΪ0��˵�������ڰ�����ϵ  
                        break;  
                    }  
                    mark = 1;   //ѭ�����е�ĩβ��˵�����ڰ�����ϵ  
               }  
           }  
               i++;  
        }  
        if (mark == 0) {  
            cout << "False" << endl;    
        }  
        else {  
            cout << "True" << endl;   
        }  
    }
   return 0; 
}  

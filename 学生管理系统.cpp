#include<iostream> 
#include<iomanip>
#include<windows.h>
#include <conio.h> 
void back();//���ؿ�ʼ�˵�
void out();//�����Ϣ
int w=1; //���ڼ�¼ѧ������,ȫ�ֱ���


class Data//������
{public:
    double Year,Month,Day;
    Data()
    {  Year=0;Month=0;Day=0;   }
};


class student //ѧ����
{
public: 
char name[10]; //����
char sex[5]; //�Ա�
char jiguan[10]; //����
int num,age;//ѧ��,����
char adr[30];//סַ
Data year;
friend class Data;//date��Ϊstudent����Ԫ                                 //����һ��������
void operator=(student s); //=����
int operator == (student s);//==����
}stu[100]; 

int main() 
{
system("cls");//���� DOC����
system("color f4"); //��ɫ ͬ���ǵ���doc
int i;
void comp(); 
void input(); 
void find();
void alt() ;
void del(); 
void exit();
void show();




cout<<setw(53)<<"��ӭ����ѧ������ϵͳ��"<<endl; 
cout<<setw(55)<<"1 ���ѧ����Ϣ 2 ��ѯѧ����Ϣ"<<endl<<endl; 
cout<<setw(55)<<"3 ɾ��ѧ����Ϣ 4 �޸�ѧ����Ϣ"<<endl<<endl; 
cout<<setw(55)<<"5 �Ƚ�ѧ����Ϣ 6 ��ʾѧ����Ϣ"<<endl<<endl;
cout<<setw(45)<<"0 �Ƴ�ϵͳ"<<endl;

cout<<"��ѡ��"; 
cin>>i;
if(i>6||i<0) 
{
    cout<<"��������"<<endl;
    back();
} 
switch(i)
{ 
case 1:input();break; 
case 2:find();break; 
case 3:del();break; 
case 4:alt();break;
case 5:comp();break;
case 6:show();break;
case 0:exit();break;
default:cout<<"�����������!\n";
return 0; 
}
} 



void input() //���ѧ��
{
system("color 84"); //��ɫ ͬ���ǵ���doc
system("cls");//����
int n; 
cout<<"������Ҫ��ӵ�ѧ��������\n"; 
cin>>n;
if(n>=100||n<=0) 
{cout<<"��������<<endl";
main(); }

else
{ 
for(;n>0;w++,n--) 
    {
     cout<<"�������������Ա𡢼��ᣬ���䣬ѧ�ţ�סַ��"<<endl; 
     cin>>stu[w].name>>stu[w].sex>>stu[w].jiguan>>stu[w].age >>stu[w].num>>stu[w].adr ; 
     cout<<"������������գ��� �� �գ�"<<endl;
     cin>>stu[w].year.Year;
     cin>>stu[w].year.Month;
     cin>>stu[w].year.Day;
    } 

   out();
}
  cout<<"������2��󷵻�"<<endl;
  Sleep(2000); //��ʱ2�� 
  main();
} 


void find() //��ѧ�Ų���ѧ��
{
system("color f4"); //��ɫ ͬ���ǵ���doc
system("cls");
int i,id,j=0;//j�����Լ�¼�Ƿ�����Ϣ���ҵ� 
cout<<"��������Ҫ����ѧ����ѧ�ţ�"; 
cin>>id;
for(i=1;i<w;i++)
if(stu[i].num ==id) 
{
    cout<<i<<"   "<<stu[i].name<<" "<<stu[i].sex<<" "<<stu[i].jiguan<<" "<<stu[i].age<<" "<<stu[i].num<<" "<<stu[i].year.Year<<" "<<stu[i].year.Month<<" "<<stu[i].year.Day<<stu[i].adr<<endl;
    j++;
}
if(j==0)
cout<<"û����Ҫ���ҵ���Ϣ";
back();
} 


void del()//ɾ��ָ��ѧ��ѧ����Ϣ 
{
system("color f4"); //��ɫ ͬ���ǵ���doc
int i,a,y=0;
char x;
cout<<"������Ҫɾ����ѧ��ѧ��"; 
cin>>a;
for(i=1;i<w;i++)
  if(stu[i].num==a)
  {
     cout<<"���������"<<endl;
    cout<<i<<"   "<<stu[i].name<<"   "<<stu[i].sex<<"    "<<stu[i].jiguan<<"   "<<stu[i].age<<"   "<<stu[i].num<<"  "<<stu[i].year.Year<<" "<<stu[i].year.Month<<" "<<stu[i].year.Day<<"   "<<stu[i].adr<<endl;
    cout<<"�Ƿ�ȷ��ɾ������Y/N��"<<endl;
    cin>>x;
    if(x=='Y'||x=='y')
    {
    y++;
    for(;i<w-1;i++) 
    stu[i]=stu[i+1];
    w--;//ÿɾ��һ�������Ǽ���һ��
    }
  }


if(y==0)
   {
    cout<<"��ѧ�������ڣ�"<<endl;
    back();
   }
else
   {
    cout<<"ɾ�������ϢΪ��"<<endl;
    out();
    back();
   } 
}

void alt()//�޸�ָ��ѧ��ѧ�� 
{
   system("color f4"); //��ɫ ͬ���ǵ���doc
   int id,y=0;
   char x;
   cout<<"������Ҫ�޸�ѧ����ѧ�ţ�"; 
   cin>>id;
  for(int i=1;i<w;i++)
   if(stu[i].num ==id)
   {
    cout<<"���������"<<endl;
    cout<<i<<"   "<<stu[i].name<<"   "<<stu[i].sex<<"    "<<stu[i].jiguan<<"   "<<stu[i].age<<"   "<<stu[i].num<<"  "<<stu[i].year.Year<<" "<<stu[i].year.Month<<" "<<stu[i].year.Day<<"   "<<stu[i].adr<<endl;
    cout<<"�Ƿ�ȷ���޸ģ���Y/N��"<<endl;
    cin>>x;
if(x=='Y'||x=='y')
    {
     y++;
     cout<<"�������������Ա𡢼��ᣬ���䣬ѧ�ţ�סַ��"<<endl; 
     cin>>stu[i].name>>stu[i].sex>>stu[i].jiguan>>stu[i].age >>stu[i].num>>stu[i].adr ; 
     cout<<"������������գ��� �� �գ�"<<endl;
     cin>>stu[i].year.Year;
     cin>>stu[i].year.Month;
     cin>>stu[i].year.Day;
    }
else
    {
    cout<<"2��󷵻�"<<endl;
    Sleep(2000);  
    main();
    }
   }
if(y==0)
   {
     cout<<"                                ��ѧ�������ڣ�";
     back();
   }
else
   {
     cout<<"�޸ĺ����ϢΪ��"<<endl;
     out();
     back();
   }
} 


void student::operator =(student stu)//��=��������غ�����ʵ��
{
    num=stu.num;
    for(int i=0;i<9;i++)
    name[i]=stu.name[i];
    for(i=0;i<4;i++)
    sex[i]=stu.sex[i];  
    age=stu.age;
    for(i=0;i<9;i++)
    jiguan[i]=stu.jiguan[i] ;
    for(i=0;i<29;i++)
    adr[i]=stu.adr[i] ;
    year.Year=stu.year.Year ;
    year.Month  =stu.year.Month  ;
    year.Day  =stu.year.Day ;
}

int student::operator == (student stu)//��==��������غ�����ʵ��
{
    if(*name==*stu.name && *sex==*stu.sex &&  age==stu.age && *jiguan==*stu.jiguan && *adr==*stu.adr&&year.Year ==stu.year.Year&&year.Month ==stu.year.Month&&year.Day ==stu.year.Day )
        return 1;
    else
        return 0;
    
}
void comp()//ѧ����Ϣ�Ա�
{
system("color f4"); //��ɫ ͬ���ǵ���doc
system("cls");
int i;
int num1,num2;
cout<<"������Ҫ�Ƚϵ�����ͬѧ��ѧ��"<<endl;
cin>>num1>>num2;
for(i=1;i<w;i++)
if(stu[i].num ==num1)
num1=i;
for(i=1;i<w;i++)
if(stu[i].num==num2)
num2=i;

    if(stu[num1]==stu[num2])
            cout<<"������ѧ������ͬ��"<<endl;
    else
cout<<"                                ������ѧ����ͬ"<<endl; 
back();
}


void show()//��ʾ
{
out();
back();
}

void exit()//�˳� 
{
exit(0);
}

void back()//����
{
cout<<"                                ����������أ�"<<endl;
getch();
main();
}

void out()//���
{
int i;
cout<<"    ����   �Ա�  ����  ����  ѧ��     ����     סַ"<<endl;
for(i=1;i<w;i++)
cout<<i<<"   "<<stu[i].name<<"   "<<stu[i].sex<<"    "<<stu[i].jiguan<<"   "<<stu[i].age<<"   "<<stu[i].num<<"  "<<stu[i].year.Year<<" "<<stu[i].year.Month<<" "<<stu[i].year.Day<<"   "<<stu[i].adr<<endl;
} 

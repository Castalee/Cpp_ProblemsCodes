#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//
#define MAXSIZE 100  //最大值定义为100
#define LIST_INIT_SIZE 100//图书证使用者最大值定义为100
//借书人的结构体

typedef struct Boro//借书行为
{
 char BNum[20];//借书的书号
 char RetDate[8];//归还日期
 struct Boro *next;
}Bor;

typedef struct LinkBook
{
    Bor *next;//该图书证的借书行为
 char CNum[20];//证号
 int Total;//借书的数量
}lend[LIST_INIT_SIZE];//借书人数组

//图书的结构体信息

typedef struct LNode
{
 char CardNum[20];//图书证号
 struct LNode *next;
}LinkList;  //借书人

typedef struct book
{//每种图书需要登记的内容包括书号ISBN、书名、作者、出版社、总库存量和现库存量。
 char num[20];//书号
 char name[20];//书名
 char auth[20];//作者
 char pub[20];//出版社
 int TotNum;//总库存
    int NowNum;//现库存
    LinkList *next;//借了该书的人
}ook[MAXSIZE];
//

int Retotal;//读者数量
int total; //定义外部变量.书的种类数
//
//结构体初始化
void InitBo(ook &boo)   //初始化图书信息
{
 for(int i=0;i<MAXSIZE;i++)
 {
  boo[i].NowNum=0;
  boo[i].TotNum=0;
     boo[i].next=NULL;
 }
}

void InitRe(lend &Lin)  //初始化借阅者信息
{
 for(int i=0;i<LIST_INIT_SIZE;i++)
  Lin[i].next=NULL;
}

//

int mid=0;//外部函数mid，用来返回查找到的位置

bool BinarySearch(ook boo,char SearchNum[])  //二分法查找比较书号
{  //用bool函数，但由于函数不能有两个返回值,所以设置一个外部变量mid，用来返回查找到的位置
     int low=0,high=total-1;
  int found=0;
     while(low<=high)
     {
         mid=(low+high)/2; //中间点
         if(strcmp(boo[mid].num,SearchNum)==0) //书号相同
   {
    found=1;
        return true;
   }//查找成功
         if(strcmp(boo[mid].num,SearchNum)!=0)//书号不同
            high=mid-1;
         else  low=mid+1;
  }
     if(found==0)
   return false; //查找失败
}

void Buy(ook &boo, char BuyNum[])
{//1、 采编入库：新购入一种书，如果该书在图书账目中已经存在，则将其库存量增加（包
//括总库存量和现库存量），如果该书不存在，则在图书账目中增加一种书，总库存量和现库存量均为1。
   if(BinarySearch(boo,BuyNum))   //如果书库中有此书
 {
  boo[mid].TotNum++;              //总库存加1
  boo[mid].NowNum++;              //现库存加1
  printf("入库成功.\n");
  printf("已更改书库中该书的信息。编号 %s 的书 %s 作者是 %s ,出版社是 %s ,目前的总库存是 %d ,现库存是 %d 。\n",boo[mid].num,boo[mid].name,boo[mid].auth,boo[mid].pub,boo[mid].TotNum,boo[mid].NowNum);
 }
 if(!BinarySearch(boo,BuyNum))
 {
    int i;
  for(i=total;i>mid&&total;i--)  //插在适合位置 保持有序
  boo[i]=boo[i-1];                //空出插入位置

  printf("该书在书库中不存在。设立新书目，请补全书的详细信息。\n");
  strcpy(boo[i].num,BuyNum);
  printf("该书购入的数量是:");
  scanf(" %d",&boo[i].NowNum);
  boo[i].TotNum=boo[i].NowNum;
  printf("该书的名字是:");
  scanf(" %s",&boo[i].name);
  printf("该书的作者是:");
  scanf(" %s",&boo[i].auth);
  printf("该书的出版社是:");
  scanf(" %s",&boo[i].pub);//补全信息
  boo[i].next=NULL;
  total++;//总量+1
  printf("已增加该书的信息。编号 %s 的书 %s 作者是 %s ,出版社是 %s ,目前的总库存是 %d ,现库存是 %d 。\n",boo[i].num,boo[i].name,boo[i].auth,boo[i].pub,boo[i].TotNum,boo[i].NowNum);
  printf("入库成功.\n");
  }
}

void Delete(ook &boo,char DeleteNum[])
{//2、 清空库存：某一种书已无保留价值，将它从图书账目中注销。

    if(BinarySearch(boo,DeleteNum)==false||total==0)   //如果无此书
        printf("书库中没有该书.\n");
 if(BinarySearch(boo,DeleteNum))//若有
 {
  if(!boo[mid].next)
  {
    int j;
  for( j=mid;j<total;j++)
     boo[j]=boo[j+1];

   strcpy(boo[j].num,boo[j+1].num);
   strcpy(boo[j].name,boo[j+1].name);
   strcpy(boo[j].auth,boo[j+1].auth);
   strcpy(boo[j].pub,boo[j+1].pub);
   boo[j].TotNum=boo[j+1].TotNum;
   boo[j].NowNum=boo[j+1].NowNum;
      printf("已成功删除该书.\n");
  }

  else printf("该书有借阅者，无法删除。\n");

 }
}

void Borrow(ook &boo,lend &Lin,char BorrowNum[],char CaNum[])
{//3、 借阅：如果一种书的现库存量大于零，则借出一本书，将现库存量减1，
//并登记借阅者的图书证号和归还期限。

 Bor *p,*q;
 LinkList *m,*n;
 if(!BinarySearch(boo,BorrowNum)||total==0) //如果没有找到此书
  printf("书库里没这书。\n");//如果有这书

 if(BinarySearch(boo,BorrowNum))       //书库里有
 {
  if(boo[mid].NowNum>0)  //看现库存是否大于0
  {
   boo[mid].NowNum--;//借出一本，少1
   if(boo[mid].next==NULL)  //若该书信息下显示该种书还没被人借过
   {
   m=(LinkList *)malloc(sizeof(LNode));//分配
   boo[mid].next=m;//该图书信息中的链表的第一个结点
   strcpy(m->CardNum,CaNum);
   m->next=NULL;//后一个结点为空
   }
   else    //如果已经有人在借这书了
   {
    m=boo[mid].next;
    while(m->next) //遍历到最后一个结点
     m=m->next;
     n=(LinkList *)malloc(sizeof(LNode));//分配空间，增加1个结点
     m->next=n;
     strcpy(n->CardNum,CaNum);//记录证号
     n->next=NULL;
   }
   int i=0;
  for(i=0;i<Retotal;i++)//
  {
   if(!strcmp(Lin[i].CNum,CaNum))//如果已经有该图书证的信息
   {
    p=Lin[i].next;
    while(p->next)p=p->next;//遍历到最后一个结点
     q=(Bor *)malloc(sizeof(Boro));//分配空间
     p->next=q;
        strcpy(q->BNum,BorrowNum);    //记录书号
        printf("输入归还日期:");
        scanf("%s",&q->RetDate);
        q->next=NULL;
     printf("借阅成功.\n");
     break;  //找到证了就跳出循环
   }
  }
  if(i==Retotal)//如果没有这张证的信息
  {
              strcpy(Lin[i].CNum,CaNum); //记录证号
           p=(Bor *)malloc(sizeof(Boro)); //分配空间
     Lin[i].next=p;
     strcpy(p->BNum,BorrowNum);
     printf("输入归还日期:");
     scanf(" %s",&p->RetDate);
     p->next=NULL;
     Retotal++;                //借阅证号信息总数加1
     printf("借阅成功.\n");
  }
  }
  else printf("借阅失败.该书现在库存为0.\n");
 }
}

void Return(ook &boo,lend &Lin,char ReturnNum[],char BorrowerNum[])
{//4、 归还：注销对借阅者的登记，改变该书的现存量。
    Bor *p,*q;
 LinkList *m,*n;
 int flag=0;//设置一个参数
 if(!BinarySearch(boo,ReturnNum)||!total)   //没书
  printf("书库中无此书.\n");
 if(BinarySearch(boo,ReturnNum))       //有书
 {
     m=boo[mid].next;
  if(!strcmp(m->CardNum,BorrowerNum))  //如果是第一个借的人还的
  {
   boo[mid].NowNum++;              //现库存加1
   boo[mid].next=m->next;           //删除结点
   free(m);                       //释放该结点的空间空间
  }
  else
  {
   while(m->next)      //查找归还者的借阅者结点
   {
    if(!strcmp(m->next->CardNum,BorrowerNum)) //如果找到
    {
     n=m->next;         //n为归还者的借阅结点
              m->next=n->next;   //m指向归还者的借阅结点的下一结点
           free(n);           //释放空间
           boo[mid].NowNum++;  //现库存加1
     break;
    }
    m=m->next;
   }
  }
 }
 //在借阅者表里查找借阅者信息
 for(int i=0;i<Retotal;i++)
 {
  if(!strcmp(Lin[i].CNum,BorrowerNum))   //如果找到借阅者
  {
   p=Lin[i].next;
      if(!strcmp(p->BNum,ReturnNum)) //如果是归还的是借的第一本书
   {
       Lin[i].next=p->next;   //指向下一借书结点
       free(p);             //释放结点空间
    printf("成功归还该书.\n");
    flag=1;
    break;
   }
      else  //找不到
   {
             while(p->next)      //找到归还书的借书结点
    {
     if(!strcmp(p->next->BNum,ReturnNum)) //如果找到
     {
      q=p->next;  //q为归还书的借书结点
                  p->next=q->next; //p指向下一借书结点
               free(q);    //释放空间
      printf("成功归还该书.\n");
      flag=1;
      break;
     }
        p=p->next;
    }
   }
  }
 }
 for(int k=0;k<Retotal;k++)
  if(!Lin[k].next)
  {
    int j;
   for(j=k;j<Retotal;j++)
    Lin[j]=Lin[j+1];         //其后都往前移一位，覆盖掉当前信息
            strcpy(Lin[j].CNum,"               "); //删除图书证号
   Retotal--;              //图书证数减1
  }  //删除当前状态下没借书的图书证的信息，节省空间
 if(flag==0)  printf("无该证信息.\n");
}

//5、 查找：实现按三种查询条件之一查找：按书号查找、
//按书名查找、按作者查找。注：可不实现组合查找，即几个条件组合查找。
void SearchByNum(ook &boo,char SeaNum[])
{//BY NUM 根据书号查找
 LinkList *p;
  p=boo[mid].next;
 if(BinarySearch(boo,SeaNum)==false)printf("对不起，未找到您想查找的书。\n");//二分查找 没找到
 else//找到了的话
 {
  {
    printf("┏━━━━━━━┳━━━━━━━┳━━━━━━━━┳━━━━━━━━┳━━━━━┳━━━━━┓\n");
             printf("┃     书号     ┃     书名     ┃      作者      ┃     出版社     ┃  现库存  ┃  总库存  ┃\n");
             printf("┣━━━━━━━╋━━━━━━━╋━━━━━━━━╋━━━━━━━━╋━━━━━╋━━━━━┫\n");
             printf("┃%14s┃%14s┃%16s┃%16s┃%10d┃%10d┃\n",boo[mid].num,boo[mid].name,boo[mid].auth,boo[mid].pub,boo[mid].NowNum,boo[mid].TotNum);
             printf("┗━━━━━━━┻━━━━━━━┻━━━━━━━━┻━━━━━━━━┻━━━━━┻━━━━━┛\n");
    if(boo[mid].next!=NULL)
 {
     printf("┏━━━━━━━┓\n");
        printf("┃  已借该书的  ┃\n");
       printf("┃   图书证号   ┃\n");
  while(p)
  {
   printf("┣━━━━━━━┫\n");
   printf("┃%14s┃\n",p->CardNum);
    p=p->next;
  }
  printf("┗━━━━━━━┛\n");
 }

 }
   while(p)
   {
    printf(" %s   ",p->CardNum);//在按书号查找的函数里也显示借了这本书的借阅者的证号
    p=p->next;
   }
   printf(" \n");
  }//显示查找的书籍的信息
}

void SearchByName(ook &boo)
{//BY NAME 根据书名查找
 char SeaName[20];
 printf("输入想查找的书的书名:\n");
 scanf(" %s",&SeaName);
 printf("找到符合该书名的书的详细信息如下：\n");
 for(int i=0;i<total;i++)
 {
  if(strcmp(SeaName,boo[i].name)==0)//如果书名一样
  {
   printf("书号：%s\n书名：%s\n作者：%s\n出版社：%s\n总库存量：%d\n现库存量：%d\n\n",boo[i].num,boo[i].name,boo[i].auth,boo[i].pub,boo[i].TotNum,boo[i].NowNum);
  }//显示符合信息的所有书籍的信息
 }
}

void SearchByAuth(ook &boo)
{// BY AUTH 根据作者查找
 char SeaAuth[20];
 printf("输入想查找的书的作者:\n");
 scanf(" %s",&SeaAuth);
 printf("找到符合该作者的书的详细信息如下：\n");
 for(int i=0;i<total;i++)
 {
  if(strcmp(SeaAuth,boo[i].auth)==0)//如果作者一样
  {
   printf("书号：%s\n书名：%s\n作者：%s\n出版社：%s\n总库存量：%d\n现库存量：%d\n\n",boo[i].num,boo[i].name,boo[i].auth,boo[i].pub,boo[i].TotNum,boo[i].NowNum);
  }//显示符合信息的所有书籍的信息
 }
}

//6、 查看：可查看某图书证号的借阅者借阅的全部图书，可查看全部超期未还的图书。

void ViewCard(ook &boo,lend &Lin)
{//查看某图书证号的借阅者借阅的全部图书
 char Num[20];
 printf("请输入您所想要查看的图书证号:\n");
    scanf(" %s",&Num);
 Bor *p;
 int qqq=0;

 for(int i=0;i<Retotal;i++)
 {
  if(strcmp(Lin[i].CNum,Num)==0)  //找到该证
  {
   printf("这个证借的书有：\n");
   p=Lin[i].next;
   while(p)
   {
    printf(" %s ",p->BNum);  //书号
    p=p->next;
   }
   printf("\n");
   qqq=1;
   break;
  }
 }
  if(qqq==0)
   printf("该证不存在.\n");
}

void ViewBook(ook &boo,lend &Lin)
{//查看全部超期未还的图书
 char date[8];
 Bor *p;
 printf("请输入日期（请按格式20060605输入）:\n");
 scanf(" %s",&date);
 printf("所有超期未还的书有:\n");
 for(int i=0;i<Retotal;i++)
 {
  p=Lin[i].next;
  while(p)//当p不空时
  {
   if(strcmp(p->RetDate,date)<0)  //超过日期
   {
    printf("书号为  %s   证号为  %s    应归还日期为  %s   \n",p->BNum,Lin[i].CNum,p->RetDate);
   }//显示所有超期未还的书的信息
   p=p->next;
  }
 }
}

void Menu()  //菜单
{
 printf("┏—————————————————M  E  N  U————————————————┓\n");
 printf("│                                                                            │\n");
 printf("│  1. 采编入库：新购入一种书，如果该书在图书账目中已经存在，                 │\n");
    printf("│               则将其库存量增加(包括总库存量和现库存量)。                   │\n");
 printf("│               如果该书不存在，则在图书账目中增加一种书，                   │\n");
    printf("│               总库存量和现库存量均为输入的数字。                           │\n");
 printf("│  2. 清空库存：某一种书已无保留价值，将它从图书账目中注销。                 │\n");
 printf("│  3. 借阅：如果一种书的现库存量大于零，则借出一本书，将现库存量减1，        │\n");
 printf("│           并登记借阅者的图书证号和归还期限。                               │\n");
 printf("│  4. 归还：注销对借阅者的登记，改变该书的现存量。                           │\n");
 printf("│  5. 按书号查找。                                                           │\n");
 printf("│  6. 按书名查找。                                                           │\n");
 printf("│  7. 按作者查找。                                                           │\n");
 printf("│  8. 查看某图书证号的借阅者借阅的全部图书。                                 │\n");
 printf("│  9. 查看全部超期未还的图书。                                               │\n");
 printf("│  0. 退出图书管理系统。                                                     │\n");
 printf("│                                                                            │\n");
 printf("┗—————————————请 选 择 你 需 要 的 操 作————————————┛\n");
}

void main()
{
 ook Bo;
 lend Lin;
 char BNum[20];
 char CNum[20];
 printf("-----------------------欢 迎 进 入 图 书 管 理 系 统!---------------------------\n\n");
 int choice=10;
    int SearchCho=10,ViewCho=10;
 while(choice!=0)
 {
 Menu();//显示菜单
 scanf(" %d",&choice);
 switch(choice)
 {
 case 1://采编入库
  printf("请输入入库的书的书号:");
     scanf(" %s",BNum);
  Buy(Bo,BNum);
  break;

 case 2://清空库存
  printf("请输入想要清除的书的书号:");
  scanf(" %s",BNum);
  Delete(Bo,BNum);
  break;

 case 3://借阅
  printf("请输入想要借阅的书的书号:\n");
     scanf(" %s",&BNum);
  printf("请输入图书证号:");
  scanf(" %s",&CNum);
  Borrow(Bo,Lin,BNum,CNum);
  break;

 case 4://归还
  printf("请输入想要归还的书的书号:\n");
     scanf(" %s",&BNum);
  printf("请输入图书证号:");
  scanf(" %s",&CNum);
  Return(Bo,Lin,BNum,CNum);
  break;

 case 5://查找//根据书号查找
  printf("请输入书号:");//输入书号查找
  scanf(" %s",&BNum);
  SearchByNum(Bo,BNum);
  break;

 case 6://根据书名查找
  SearchByName(Bo);
  break;

 case 7://根据作者查找
  SearchByAuth(Bo);
  break;

 case 8://查看某图书证所借的所有书
  ViewCard(Bo,Lin);
  break;

 case 9: //查看全部超期未还的书
  ViewBook(Bo,Lin);
  break;

 case 0://退出系统
  exit(0);break;

 default:printf("输入错误!\n");exit(0);break;

 }
 }
}

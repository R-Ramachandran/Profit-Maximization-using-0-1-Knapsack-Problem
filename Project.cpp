#include<iostream>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<iomanip>

using namespace std;

struct node
{
    int profit,price;
    char item[30];
    struct node *link;
};

struct node *temp=NULL,*front=NULL,*rear=NULL,*dummy=NULL;

int count=0;

int max(int a, int b)
{
    return (a>b)?a:b;
}

void check(float a)
{
    if(a==0)
        cout<<"Amount cannot be ZERO!!!"<<endl;
    else
        cout<<"Amount cannot be NEGATIVE!!!"<<endl;
}

int login()
{
    char dum,u_name[30],name[30],g_pwd[30],pwd[30];
    int flag=0;
    cout<<"Enter your USER NAME : ";
    cin>>name;
    cout<<"Enter the PASSWORD   : ";
    cin>>pwd;
    fstream f;
    f.open("user_logins.txt",ios::in);
    f.seekg(0);
    while(f)
    {
        f.get(dum);
        f.get(u_name,30);
        f.get(dum);
        f.get(g_pwd,30);
        if(strcmp(u_name,name)==0&&strcmp(pwd,g_pwd)==0)
        {
            flag=1;
            cout<<"\n\t\t\tYou have Successfully LOGGED IN"<<endl<<endl;
            break;
        }
        else if(strcmp(u_name,name)==0&&strcmp(pwd,g_pwd)!=0)
        {
            do
            {
                cout<<"\t\t\t----INCORRECT PASSWORD!!!----"<<endl;
                cout<<"Re-Enter the PASSWORD : ";
                cin>>pwd;
            }while(strcmp(pwd,g_pwd)!=0);
            cout<<"\n\t\t\tYou have Successfully LOGGED IN"<<endl<<endl;
            flag=1;
            break;
        }
    }
    if(flag==0)
        cout<<"\n\t\t\tSORRY!!! USER NAME and PASSWORD does not Exist"<<endl;
    f.close();
    return flag;
}

void signup()
{
    char name[30],pwd[30],check_pwd[30];
    fstream f;
    f.open("user_logins.txt",ios::in);
    char g_name[30],g_pwd[30],dum;
    int flag;
    cout<<"Enter the USER NAME : ";
    cin>>name;
    do
    {
        f.seekg(0);
        while(f)
        {
            flag=1;
            f.get(dum);
            f.get(g_name,30);
            f.get(dum);
            f.get(g_pwd,30);
            if(strcmp(g_name,name)==0)
            {
                flag=0;
                break;
            }
        }
        if(flag==0)
        {
            cout<<"\n\t\t\t----SORRY! USER-NAME ALREADY EXIST----"<<endl;
            cout<<"Enter the USER NAME : ";
            cin>>name;
        }
    }while(flag==0);
    f.close();
    f.open("user_logins.txt",ios::out|ios::app);
    cout<<"Enter your PASSWORD : ";
    cin>>pwd;
    cout<<"Re-Enter your PASSWORD : ";
    cin>>check_pwd;
    while(strcmp(pwd,check_pwd)!=0)
    {
        cout<<"\t\t\t----INCORRECT PASSWORD!!!----"<<endl;
        cout<<"Enter your PASSWORD : ";
        cin>>pwd;
        cout<<"Re-Enter your PASSWORD : ";
        cin>>check_pwd;
    }
    f<<endl<<name<<endl<<pwd;
    cout<<"\n\t\t\tYou have Successfully CREATED YOUR ACCOUNT"<<endl<<endl;
    f.close();
}

void input_stock_items()
{
    fstream f;
    f.open("stock.txt",ios::out|ios::app);
    char product[30],ch='y';
    int weight,profit,flag;
    while(ch=='y'||ch=='Y')
    {
        cout<<"Enter the ITEM NAME            : ";
        cin>>product;
        do
        {
            flag=1;
            temp=front;
            while(temp!=NULL)
            {
                if(strcmp(temp->item,product)==0)
                {
                    flag=0;
                    break;
                }
                temp=temp->link;
            }
            if(flag==0)
            {
                cout<<"\n\t\t\tSTOCK ITEM ALREADY EXIST"<<endl;
                cout<<"Enter the ITEM NAME            : ";
                cin>>product;
            }
        }while(flag==0);
        cout<<"Enter the ITEM PRICE (in Rs)   : ";
        cin>>weight;
        while(1)
        {
            if(weight>0)
                break;
            else
                check(weight);
            cout<<"--->Re-enter the ITEM PRICE (in Rs)   : ";
            cin>>weight;
        }
        cout<<"Enter the ITEM PROFIT (in Rs)  : ";
        cin>>profit;
        while(1)
        {
            if(profit>0)
                break;
            else
                check(profit);
            cout<<"--->Re-enter the ITEM PROFIT (in Rs)  : ";
            cin>>profit;
        }
        cout<<endl<<endl;
        f<<endl<<product<<endl<<weight<<endl<<profit;
        cout<<"DO YOU WANT TO CONTINUE (Y/N)? : ";
        cin>>ch;
    }
    cout<<endl;
    f.close();
}

void read_file()
{
    char dum;
    count=0;
    fstream f;
    f.open("stock.txt",ios::in);
    f.seekg(0);
    while(f)
    {
        temp=new struct node;
        f.get(dum);
        f.get(temp->item,30);
        if(strcmp(temp->item,"")==0)
        {
            delete temp;
            break;
        }
        f.get(dum);
        f>>temp->price;
        f.get(dum);
        f>>temp->profit;
        if(rear==NULL)
        {
            temp->link=NULL;
            rear=temp;
            front=rear;
        }
        else
        {
            rear->link=temp;
            temp->link=NULL;
            rear=temp;
        }
        count++;
    }
    f.close();
}

void display_stock_items()
{
    temp=front;
    int i=1;
    if(temp==NULL)
        cout<<"\t\t\tTO DISPLAY, THERE ARE NO STOCK ITEMS LEFT"<<endl;
    else
    {
        cout<<"The STOCK ITEMS are : "<<endl<<endl;
        cout<<"\t\t ___________________________________________________________________________________________________________ \n";
        cout<<"\t\t|  S. No. |                      ITEM NAME                      |    PRICE (PER RS)     |   PROFIT (IN RS)  |\n";
        cout<<"\t\t|_________|_____________________________________________________|_______________________|___________________|\n";
        while(temp!=NULL)
        {
            cout<<"\t\t|"<<setw(4)<<i<<")"<<setw(5)<<"|"<<setw(48)<<temp->item<<setw(6)<<"|"<<setw(14)<<temp->price<<setw(10)<<"|"<<setw(12)<<temp->profit<<setw(8)<<"|"<<endl;
            temp=temp->link;
            i++;
        }
        cout<<"\t\t|_________|_____________________________________________________|_______________________|___________________|\n";
    }
    cout<<endl;
}

void delete_a_given_stock_item()
{
    int flag=1,profitt,pricee;
    char element[30],dum,product[30];
    temp=front;
    cout<<"Enter the STOCK ITEM TO BE DELETED : ";
    cin>>element;
    cout<<endl;
    if(temp==NULL)
        cout<<"\n\t\t\tFOR DELETION, THERE ARE NO STOCK ITEMS LEFT"<<endl;
    else
    {
        fstream f;
        f.open("stock.txt",ios::in);
        f.seekg(0);
        while(f)
        {
            f.get(dum);
            f.get(product,30);
            if(strcmp(product,"")==0)
            {
                flag=0;
                break;
            }
            else if(strcmp(product,element)==0)
            {
                flag=1;
                break;
            }
            f.get(dum);
            f>>pricee;
            f.get(dum);
            f>>profitt;
        }
        f.close();
        if(flag==1)
        {
            temp=front;
            if(strcmp(temp->item,element)==0&&temp==front)
            {
                temp=temp->link;
                delete front;
                front=temp;
            }
            else
            {
                while(temp!=NULL)
                {
                    if(strcmp((temp->link)->item,element)==0)
                    {
                        dummy=temp->link;
                        temp->link=(temp->link)->link;
                        delete dummy;
                        break;
                    }
                    else
                        temp=temp->link;
                }
            }
            cout<<"\n\t\t\tThe GIVEN STOCK ITEM is SUCCESSFULLY DELETED"<<endl;
        }
        else
            cout<<"\n\t\t\tFOR DELETION, The GIVEN STOCK ITEM is NOT FOUND!!!"<<endl;
    }
    if(flag==1)
    {
        fstream f;
        f.open("temp.txt",ios::out|ios::app);
        dummy=front;
        while(dummy!=NULL)
        {
            f<<endl<<dummy->item<<endl<<dummy->price<<endl<<dummy->profit;
            dummy=dummy->link;
        }
        f.close();
        remove("stock.txt");
        rename("temp.txt","stock.txt");
    }
}

void modify_profit_or_price_of_given_item()
{
    int flag=1,profitt,pricee,ch;
    char element[30],dum,product[30];
    temp=front;
    cout<<"Enter the STOCK ITEM TO BE MODIFIED : ";
    cin>>element;
    cout<<endl;
    if(temp==NULL)
        cout<<"\n\t\t\tFOR MODIFICATION, THERE ARE NO STOCK ITEMS LEFT"<<endl;
    else
    {
        fstream f;
        f.open("stock.txt",ios::in);
        f.seekg(0);
        while(f)
        {
            f.get(dum);
            f.get(product,30);
            if(strcmp(product,"")==0)
            {
                flag=0;
                break;
            }
            else if(strcmp(product,element)==0)
            {
                flag=1;
                break;
            }
            f.get(dum);
            f>>pricee;
            f.get(dum);
            f>>profitt;
        }
        f.close();
        if(flag==1)
        {
            temp=front;
            if(strcmp(temp->item,element)==0&&temp==front)
            {
                do
                {
                    cout<<"WHICH YOU WANT TO MODIFY : ";
                    cout<<"1) PRICE\n\t\t\t   2) PROFIT"<<endl<<endl;
                    cout<<"Enter your CHOICE : ";
                    cin>>ch;
                    switch(ch)
                    {
                        case 1:
                            cout<<"Enter the PRICE OF THE STOCK ELEMENT  : ";
                            cin>>temp->price;
                            cout<<"\t\t\tThe PRICE OF The STOCK ITEM is SUCCESSFULLY MODIFIED"<<endl;
                            break;
                        case 2:
                            cout<<"Enter the PROFIT OF THE STOCK ELEMENT : ";
                            cin>>temp->profit;
                            cout<<"\t\t\tThe PROFIT OF The STOCK ITEM is SUCCESSFULLY MODIFIED"<<endl;
                            break;
                        default:
                            cout<<"\n\t\t\t----INCORRECT CHOICE----"<<endl<<endl;
                            break;
                    }
                }while(!(ch<=2&&ch>=1));
            }
            else
            {
                while(temp!=NULL)
                {
                    if(strcmp((temp->link)->item,element)==0)
                    {
                        temp=temp->link;
                        do
                        {
                            cout<<"WHICH YOU WANT TO MODIFY : ";
                            cout<<"1) PRICE\n\t\t\t   2) PROFIT"<<endl<<endl;
                            cout<<"Enter your CHOICE : ";
                            cin>>ch;
                            switch(ch)
                            {
                                case 1:
                                    cout<<"Enter the PRICE OF THE STOCK ELEMENT  : ";
                                    cin>>temp->price;
                                    cout<<"\t\t\tThe PRICE OF The STOCK ITEM is SUCCESSFULLY MODIFIED"<<endl;
                                    break;
                                case 2:
                                    cout<<"Enter the PROFIT OF THE STOCK ELEMENT : ";
                                    cin>>temp->profit;
                                    cout<<"\t\t\tThe PROFIT OF The STOCK ITEM is SUCCESSFULLY MODIFIED"<<endl;
                                    break;
                                default:
                                    cout<<"\t\t\t----INCORRECT CHOICE----"<<endl<<endl;
                                    break;
                            }
                        }while(!(ch<=2&&ch>=1));
                        break;
                    }
                    else
                        temp=temp->link;
                }
            }
        }
        else
            cout<<"\n\t\t\tFOR MODIFICATION, The GIVEN STOCK ITEM is NOT FOUND!!!"<<endl;
    }
    if(flag==1)
    {
        fstream f;
        f.open("temp.txt",ios::out|ios::app);
        dummy=front;
        while(dummy!=NULL)
        {
            f<<endl<<dummy->item<<endl<<dummy->price<<endl<<dummy->profit;
            dummy=dummy->link;
        }
        f.close();
        remove("stock.txt");
        rename("temp.txt","stock.txt");
    }
}

void delete_entire_stock_items()
{
    if(count==0)
        cout<<"\n\t\t\tALREADY, STOCK ITEMS LIST IS EMPTY"<<endl;
    else
    {
        remove("stock.txt");
        cout<<"\n\t\t\tThe ENTIRE STOCK ITEMS ARE DELETED"<<endl;
    }
}

void free_up_memory()
{
    temp=front;
    while(temp!=NULL)
    {
        temp=temp->link;
        delete front;
        front=temp;
    }
    front=NULL;
    rear=NULL;
}

void stock_items_for_maximum_profit(int W)
{
    if(count==0)
        cout<<"\n\t\t\tSTOCK ITEMS LIST IS EMPTY"<<endl;
    else
    {
        int i=0,j,w;
        int K[count+1][W+1],val[count+1],wt[count+1];
        char product[30],dum,items[count+1][30];
        fstream f;
        f.open("stock.txt",ios::in);
        f.seekg(0);
        while(f)
        {
            f.get(dum);
            f.get(product,30);
            if(strcmp(product,"")==0)
                break;
            strcpy(items[i],product);
            f.get(dum);
            f>>wt[i];
            f.get(dum);
            f>>val[i];
            i++;
        }
        f.close();
        for(i=0;i<=count;i++)
            for(w=0;w<=W;w++)
                if(i==0||w==0)
                    K[i][w]=0;
                else if(wt[i-1]<= w)
                    K[i][w]=max(val[i-1]+K[i-1][w-wt[i-1]],K[i-1][w]);
                else
                    K[i][w]=K[i-1][w];
        int res=K[count][W],k=1;
        w=W;
        if(res==0)
            cout<<"\n\t\t\t----WE DON'T HAVE SUFFICIENT FUND TO PURCHASE STOCK ITEMS----"<<endl;
        else
        {
            cout<<endl;
            cout<<"The Maximum Profit we get is (in Rs) : ";
            cout<<res<<endl<<endl;
            cout<<"The STOCK ITEMS are : "<<endl<<endl;
            cout<<"\t\t ___________________________________________________________________________________________________________ \n";
            cout<<"\t\t|  S. No. |                      ITEM NAME                      |    PRICE (PER RS)     |   PROFIT (IN RS)  |\n";
            cout<<"\t\t|_________|_____________________________________________________|_______________________|___________________|\n";
            for(i=count;(i>0)&&(res>0);i--)
                if(res==K[i-1][w])
                    continue;
                else
                {
                    cout<<"\t\t|"<<setw(4)<<k<<")"<<setw(5)<<"|"<<setw(48)<<items[i-1]<<setw(6)<<"|"<<setw(14)<<wt[i-1]<<setw(10)<<"|"<<setw(12)<<val[i-1]<<setw(8)<<"|"<<endl;
                    res=res-val[i-1];
                    w=w-wt[i-1];
                    k++;
                }
            cout<<"\t\t|_________|_____________________________________________________|_______________________|___________________|\n";
            cout<<endl;
        }
    }
}

void delete_stock_items_except_stock_items_to_be_purchased(int W)
{
    if(count==0)
        cout<<"\n\t\t\tALREADY, STOCK ITEMS LIST IS EMPTY"<<endl;
    else
    {
        int i=0,j,w;
        int K[count+1][W+1],val[count+1],wt[count+1];
        char product[30],dum,items[count+1][30];
        fstream f;
        f.open("stock.txt",ios::in);
        f.seekg(0);
        while(f)
        {
            f.get(dum);
            f.get(product,30);
            if(strcmp(product,"")==0)
                break;
            strcpy(items[i],product);
            f.get(dum);
            f>>wt[i];
            f.get(dum);
            f>>val[i];
            i++;
        }
        f.close();
        for(i=0;i<=count;i++)
            for(w=0;w<=W;w++)
                if(i==0||w==0)
                    K[i][w]=0;
                else if(wt[i-1]<= w)
                    K[i][w]=max(val[i-1]+K[i-1][w-wt[i-1]],K[i-1][w]);
                else
                    K[i][w]=K[i-1][w];
        int res=K[count][W];
        fstream t;
        w=W;
        t.open("temp.txt",ios::out|ios::app);
        for(i=count;(i>0)&&(res>0);i--)
            if(res==K[i-1][w])
                continue;
            else
            {
                t<<endl<<items[i-1]<<endl<<wt[i-1]<<endl<<val[i-1];
                res=res-val[i-1];
                w=w-wt[i-1];
            }
        t.close();
        remove("stock.txt");
        rename("temp.txt","stock.txt");
        cout<<endl<<"\t\t\tThe STOCK ITEMS are DELETED, EXCEPT the STOCK ITEMS TO BE PURCHASED";
        cout<<endl;
    }
}

int main()
{
    int n,W,ch,flag;
    char s;
    cout<<"\t\t\t\t\t\t----------------------------------------WELCOME TO DEPARTMENTAL STORE----------------------------------------\n\n";
    do
    {
        cout<<endl;
        cout<<"\t\t\t\t\t\t\t \t\t\t\t\t _____________ \n";
        cout<<"\t\t\t\t\t\t\t \t\t\t\t\t| 1) LOGIN    |\n";
        cout<<"\t\t\t\t\t\t\t \t\t\t\t\t| 2) REGISTER |\n";
        cout<<"\t\t\t\t\t\t\t \t\t\t\t\t| 3) EXIT     |\n";
        cout<<"\t\t\t\t\t\t\t \t\t\t\t\t|_____________|\n";
        cout<<"Enter your Choice : ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                flag=login();
                break;
            case 2:
                signup();
                cout<<"Do you want to LOGIN (Y/N)? : ";
                cin>>s;
                if(s=='y'||s=='Y')
                    flag=login();
                else
                {
                    cout<<"\t\t\t\t\t\t\t \t\t\t\t\t ___________ \n";
                    cout<<"\t\t\t\t\t\t\t \t\t\t\t\t| THANK YOU |\n";
                    cout<<"\t\t\t\t\t\t\t \t\t\t\t\t|___________|\n";
                    exit(1);
                }
                break;
            case 3:
                cout<<"\t\t\t\t\t\t\t \t\t\t\t\t ___________ \n";
                cout<<"\t\t\t\t\t\t\t \t\t\t\t\t| THANK YOU |\n";
                cout<<"\t\t\t\t\t\t\t \t\t\t\t\t|___________|\n";
                exit(0);
                break;
            default:
                cout<<"\t\t\t----INCORRECT CHOICE!!!----"<<endl;
                break;
        }
    }while(flag!=1);
    if(flag==1)
    {
        cout<<"ENTER THE MAXIMUM AMOUNT FOR INVESTMENT(IN RS) : ";
        cin>>W;
        cout<<endl;
        while(1)
        {
            cout<<endl;
            cout<<"\t\t\t\t\t\t\t \t\t ______________________________________________________________ \n";
            cout<<"\t\t\t\t\t\t\t \t\t|                          START MENU                          |\n";
            cout<<"\t\t\t\t\t \t\t\t\t|______________________________________________________________|\n";
            cout<<"\t\t\t\t\t \t\t\t\t| 1) INPUT STOCK ITEMS                                         |\n";
            cout<<"\t\t\t\t\t \t\t\t\t| 2) DISPLAY STOCK ITEMS                                       |\n";
            cout<<"\t\t\t\t\t \t\t\t\t| 3) DELETE A GIVEN STOCK ITEM                                 |\n";
            cout<<"\t\t\t\t\t \t\t\t\t| 4) DELETE ENTIRE STOCK ITEMS                                 |\n";
            cout<<"\t\t\t\t\t \t\t\t\t| 5) DELETE STOCK ITEMS, EXCEPT STOCK ITEMS TO BE PURCHASED    |\n";
            cout<<"\t\t\t\t\t \t\t\t\t| 6) DISPLAY STOCK ITEMS TO BE PURCHASED(FOR MAXIMUM PROFIT)   |\n";
            cout<<"\t\t\t\t\t \t\t\t\t| 7) MODIFY PROFIT/PRICE OF GIVEN STOCK ITEM                   |\n";
            cout<<"\t\t\t\t\t \t\t\t\t| 8) EXIT                                                      |\n";
            cout<<"\t\t\t\t\t \t\t\t\t|______________________________________________________________|\n"<<endl;
            cout<<"Enter your choice : ";
            cin>>ch;
            cout<<endl;
            switch(ch)
            {
                case 1:
                    free_up_memory();
                    read_file();
                    input_stock_items();
                    free_up_memory();
                    cout<<endl;
                    break;
                case 2:
                    free_up_memory();
                    read_file();
                    display_stock_items();
                    free_up_memory();
                    cout<<endl;
                    break;
                case 3:
                    free_up_memory();
                    read_file();
                    delete_a_given_stock_item();
                    free_up_memory();
                    cout<<endl;
                    break;
                case 4:
                    free_up_memory();
                    read_file();
                    delete_entire_stock_items();
                    free_up_memory();
                    cout<<endl;
                    break;
                case 5:
                    free_up_memory();
                    read_file();
                    delete_stock_items_except_stock_items_to_be_purchased(W);
                    free_up_memory();
                    cout<<endl;
                    break;
                case 6:
                    free_up_memory();
                    read_file();
                    stock_items_for_maximum_profit(W);
                    free_up_memory();
                    cout<<endl;
                    break;
                case 7:
                    free_up_memory();
                    read_file();
                    modify_profit_or_price_of_given_item();
                    free_up_memory();
                    cout<<endl;
                    break;
                case 8:
                    cout<<"\t\t\t\t\t\t\t \t\t\t\t\t ___________ \n";
                    cout<<"\t\t\t\t\t\t\t \t\t\t\t\t| THANK YOU |\n";
                    cout<<"\t\t\t\t\t\t\t \t\t\t\t\t|___________|\n";
                    free_up_memory();
                    exit(2);
                    cout<<endl;
                    break;
                default:
                    cout<<"\n\t\t\t----INCORRECT PASSWORD!!!----"<<endl<<endl;
                    break;
            }
        }
    }
    return 0;
}

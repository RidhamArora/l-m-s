class book
{
public:
    char name[100];
    char auth_name[100];
    int acc_no;
    book()
    {
        strcpy(name,"noname");
        strcpy(auth_name,"noauthor");
        acc_no=-1;
    }
    book(char* name,char* auth_name,int acc_no)
    {
        strcpy(this->name,name);
        strcpy(this->auth_name,auth_name);
        this->acc_no=acc_no;
    }
    void display()
    {
        cout<<endl;
        cout<<"   1. Book name   = "<<name<<endl;
        cout<<"   2. Author name = "<<auth_name<<endl;
        cout<<"   3. Acc NO.     = "<<acc_no<<endl;
        cout<<endl;
    }
};
void Book_Entry_Design()
{
    system("cls");
    Init_Design();
    fstream file;
    int acc_no;
    char check;
    char name[100];
    char auth_name[100];
    cout<<"  Enter the Book name : ";
    cin>>name;
    cout<<endl;
    cout<<"  Enter the Author name : ";
    cin>>auth_name;
    cout<<endl;
    cout<<"  Enter Student's Acc no : ";
    cin>>acc_no;
    cout<<endl;
    book b1(name,auth_name,acc_no);
    file.open("Bin/Book.bin",ios::binary|ios::in|ios::out|ios::app);
    file.write((char*)&b1,sizeof(b1));
    file.close();
    cout<<"Do you want to enter more record{Y/N} : ";
    cin>>check;
    cout<<endl;
    if(check=='Y'||check=='y') Book_Entry_Design();
    return;
}
void Book_Search_Design()
{
    system("cls");
    Init_Design();
    fstream file;
    int acc_no;
    char check;
    char name[100];
    char auth_name[100];
    int x;
    cout<<"  1. Search by"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"  1. Book name            2. Author name          3. Acc No."<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"  Enter your option <<< 1 / 2 / 3 >>> : ";
    cin>>x;
    cout<<endl;
    file.open("Bin/Book.bin",ios::binary|ios::in|ios::out|ios::app);
    book b1;
    switch(x)
    {
        system("cls");
        case 1:
            {
            int xx=0;
            cout<<"  Enter book name you want to search for : ";
            cin>>name;
            cout<<endl;
            while(file.good())
            {
                file.read((char*)&b1,sizeof(b1));
                if(!strcmp(b1.name,name))
                {
                    xx=1;
                    b1.display();
                }
            }
            if(xx==0) cout<<"No Such book exists"<<endl;
            break;
            }
        case 2:
            {
            int xx=0;
            cout<<"Enter author name you want to search for : ";
            cin>>auth_name;
            cout<<endl;
            while(file.good())
            {
                file.read((char*)&b1,sizeof(b1));
                if(!strcmp(b1.auth_name,auth_name))
                {
                    xx=1;
                    b1.display();
                }
            }
            if(xx==0) cout<<"No Such book exists"<<endl;
            break;
            }
        case 3:
            {
            int xx=0;
            cout<<"Enter Acc no: you want to search for : ";
            cin>>acc_no;
            cout<<endl;
            while(file.good())
            {
                file.read((char*)&b1,sizeof(b1));
                if(b1.acc_no==acc_no)
                {
                    xx=1;
                    b1.display();
                }
            }
            if(xx==0) cout<<"No Such book exists"<<endl;
            break;
            }
    }
    char g;
    cout<<"  Do you want to search more<Y/N> : ";
    cin>>g;
    cout<<endl;
    if(g=='Y'||g=='y') Book_Search_Design();
    return;
}

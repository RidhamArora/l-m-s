#include<bits/stdc++.h>
using namespace std;
class student
{
public:
    int roll_no;
    char name[100];
    student()
    {
        strcpy(name,"noname");
        roll_no=-1;
    }
    student(char* name,int roll_no)
    {
        strcpy(this->name,name);
        this->roll_no=roll_no;
    }
    void display()
    {
        cout<<endl;
        cout<<"   1. Student name   =  "<<name<<endl;
        cout<<"   2. Roll No.       =  "<<roll_no<<endl;
        cout<<endl;
        return;
    }
};
void Init_Design();
void Student_Entry_Design()
{
    system("cls");
    Init_Design();
    fstream file;
    int roll_no;
    char check;
    char name[100];
    cout<<"  Enter Student's name : ";
    cin>>name;
    cout<<endl;
    cout<<"  Enter Student's roll no : ";
    cin>>roll_no;
    student s1(name,roll_no);
    file.open("Bin/Student.bin",ios::binary|ios::in|ios::out|ios::app);
    file.write((char*)&s1,sizeof(s1));
    file.close();
    cout<<endl;
    cout<<"  Do you want to enter more record{Y/N} : ";
    cin>>check;
    cout<<endl;
    if(check=='Y'||check=='y') Student_Entry_Design();
    return;
}
void Student_Search_Design()
{
    system("cls");
    Init_Design();
    fstream file;
    int roll_no;
    char check;
    char name[100];
    int x;
    cout<<"  1. Search by"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"  1. Student name                2. Roll No."<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"  Enter your option <<< 1 / 2>>> : ";
    cin>>x;
    cout<<endl;
    file.seekg(0);
    file.open("Bin/Student.bin",ios::binary|ios::in|ios::out|ios::app);
    student s1;
    switch(x)
    {
        system("cls");
        case 1:
            {
            int xx=0;
            cout<<"  Enter student name you want to search for : ";
            cin>>name;
            cout<<endl;
            while(file.read((char*)&s1,sizeof(s1)))
            {
                if(!strcmp(s1.name,name))
                {
                    xx=1;
                    s1.display();
                }
            }
            if(xx==0) cout<<"  No such student exists ..... "<<endl;
            break;
            }
        case 2:
            {
            int xx=0;
            cout<<"  Enter Roll no. you want to search for : ";
            cin>>roll_no;
            cout<<endl;
            while(file.read((char*)&s1,sizeof(s1)))
            {
                if(s1.roll_no==roll_no)
                {
                    xx=1;
                    s1.display();
                    break;
                }
            }
            if(xx==0) cout<<"  No such student exists ..... "<<endl;
            break;
            }
    }
    char g;
    cout<<"  Do you want to search more<Y/N> : ";
    cin>>g;
    cout<<endl;
    if(g=='Y'||g=='y') Student_Search_Design();
    return;
}

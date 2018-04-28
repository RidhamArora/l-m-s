class shared
{
    public:
        int roll_no;
        int acc_no;
        shared()
        {
            roll_no=-1;
            acc_no=-1;
        }
        shared(int acc_no,int roll_no)
        {
            this->roll_no=roll_no;
            this->acc_no=acc_no;
        }
};
void Issue_Book()
{
    system("cls");
    Init_Design();
    fstream file;
    int acc_no,roll_no;
    cout<<"  Enter acc no of book : ";
    cin>>acc_no;
    cout<<endl;
    cout<<endl;
    cout<<"  Enter roll no of student : ";
    cin>>roll_no;
    cout<<endl;
    cout<<endl;
    shared s1(acc_no,roll_no);
    file.open("Bin/Shared.bin",ios::binary|ios::in|ios::out|ios::app);
    file.write((char*)&s1,sizeof(s1));
    file.close();
    char g;
    cout<<"  Do you want to add more<Y/N> : ";
    cin>>g;
    cout<<endl;
    if(g=='Y'||g=='y') Issue_Book();
    return;
}
void Student_Search_Issued_Book()
{
    system("cls");
    Init_Design();
    int roll_no;
    fstream file;
    cout<<"Enter student's roll_no : ";
    cin>>roll_no;
    cout<<endl;
    file.open("Bin/Shared.bin",ios::binary|ios::in|ios::out|ios::app);
    shared s1;
    int x=-1;
    while(file.good())
    {
        file.read((char*)&s1,sizeof(s1));
        if(s1.roll_no==roll_no)
        {
           x=s1.acc_no;
           fstream file1;
           file1.open("Bin/Book.bin",ios::binary|ios::in|ios::out|ios::app);
            book b1;
            while(file1.read((char*)&b1,sizeof(b1)))
            {
                if(b1.acc_no==x)
                {
                    b1.display();
                    break;
                }
            }
            file1.close();
        }
    }
    if(x==-1) cout<<"No book issued by this student ...."<<endl;
    char g;
    cout<<"  Do you want to search more<Y/N> : ";
    cin>>g;
    cout<<endl;
    if(g=='Y'||g=='y') Student_Search_Issued_Book();
    return;
}
void Book_Search_Issued_Student()
{
    system("cls");
    Init_Design();
    int acc_no;
    fstream file;
    cout<<"Enter Acc no. of book : ";
    cin>>acc_no;
    cout<<endl;
    file.open("Bin/Shared.bin",ios::binary|ios::in|ios::out|ios::app);
    shared s1;
    int x=-1;
    while(file.read((char*)&s1,sizeof(s1)))
    {
        if(s1.acc_no==acc_no)
        {
           x=s1.roll_no;
           fstream file1;
           file1.open("Bin/Student.bin",ios::binary|ios::in|ios::out|ios::app);
           student su1;
            while(file1.read((char*)&su1,sizeof(su1)))
                {
                    if(su1.roll_no==x)
                            {
                                su1.display();
                            }
                }
            file1.close();
        }
    }
    if(x==-1) cout<<"  No Student holds this book ";
    char g;
    cout<<"  Do you want to search more<Y/N> : ";
    cin>>g;
    cout<<endl;
    if(g=='Y'||g=='y') Student_Search_Issued_Book();
    return;
}

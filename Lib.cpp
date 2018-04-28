#include<bits/stdc++.h>
#include"Header/student1.h"
#include"Header/book1.h"
#include"Header/shared1.h"
using namespace std;
void Init_Design()
{
    cout<<"             ******************************************"<<endl;
    cout<<"             ******************************************"<<endl;
    cout<<"             ******************************************"<<endl;
    cout<<endl;
}
int Menu_Design()
{
    int x;
    cout<<"                                      MENU                                "<<endl;
    cout<<"         _________________________________________________________________"<<endl;
    cout<<"         -----------------------------------------------------------------"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<" 1. Add new Entry of a student : "<<endl;
    cout<<" 2. Add new Entry of a book    : "<<endl;
    cout<<" 3. Display books issued by a student : "<<endl;
    cout<<" 4. Display the students data to which book has been issued : "<<endl;
    cout<<" 5. Search for a book : "<<endl;
    cout<<" 6. Search for a student : "<<endl;
    cout<<" 7. Issue a book : "<<endl;
    cout<<" 8.        EXIT         "<<endl;
    cout<<endl;
    cout<<endl;
    cout<<" Enter your choice here:  ";
    cin>>x;
    while(x<1&&x>8)
    {
        cin>>x;
    }
    return x;
}
int main()
{
    int ans=0;
    system("cls");
    ans=Menu_Design();
    while(ans!=8)
    {
        switch(ans)
        {
            case 1:
                Student_Entry_Design();
                break;
            case 2:
                Book_Entry_Design();
                break;
            case 3:
                Student_Search_Issued_Book();
                break;
            case 4:
                Book_Search_Issued_Student();
                break;
            case 5:
                Book_Search_Design();
                break;
            case 6:
                Student_Search_Design();
                break;
            case 7:
                Issue_Book();
                break;
        }
        system("cls");
        ans=Menu_Design();
    }
}

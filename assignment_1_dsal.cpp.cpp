#include <iostream>
#include <regex>
using namespace std;

struct MNode{
    string name;
    string number;
    string email;
    struct MNode *next;
};

class MList{
private:
    MNode *head;
    bool isValidEmail(const string &email){
    const regex pattern(R"((\w+)(\_)?(\w*)@(\w+)(\.)(\w+))");
    return regex_match(email,pattern);
    }

    bool isValidName(const string &name){
        for(char c:name){
        if(!isalpha(c)&&c!=' ')
        return false;
        }
        return !name.empty();
    }

    bool isValidNumber(const string &numberStr){
        if(numberStr.length()<10||numberStr.length()>10){
        return false;}
        for(char c:numberStr){
        if(!isdigit(c)){
        return false;}
        }
        return true;
    }

public:
    MList(){
        head=NULL;
    }
    MNode *getNode(){
    MNode *p=new MNode;

    string tempName;
        do{
            cout<<"Enter Contact Name:"<<endl;
            cin>>tempName;
            if(!isValidName(tempName))
            cout<<"Invalid name! just alphabets and spaces allowed, Please enter again."<<endl;
        }
        while(!isValidName(tempName));
        p->name=tempName;

        string tempNumber;
        do{
            cout<<"Enter Phone Number:"<<endl;
            cin>>tempNumber;
            if(!isValidNumber(tempNumber))
                cout<<"enter valid phone number Only digits allowed, length must be 10."<<endl;
        } 
        while(!isValidNumber(tempNumber));
        p->number=tempNumber;

        string tempEmail;
        do{
            cout<<"Enter emailID:" <<endl;
            cin>>tempEmail;
            if (!isValidEmail(tempEmail))
                cout<<"Invalid format. enter again" << endl;
        }
         while(!isValidEmail(tempEmail));
        p->email=tempEmail;

        p->next=NULL;
        return p;
    }

    void Createlist()       
    {
        MNode *t,*p;
        int n;
        cout<<"Enter number of contacts: "<<endl;
        cin>>n;
        while(n>0){
            t=getNode();
            if(head ==NULL)
                head=t;
            else{
                p=head;
                while(p->next !=NULL){
                    p=p->next;
                }
                p->next=t;
            }
            n--;
        }
    }

    void Display()
    {
        MNode *p;
        p=head;
        cout<<"Displaying All Contacts: "<<endl;
        cout<<"\n";
        while(p !=NULL)
        {
            cout<<"Contact Name: "<<p->name<<endl;
            cout<< "Phone No: "<<p->number<<endl;
            cout <<"EmailID: "<<p->email<<endl;
            cout<<"\n";
            p=p->next;
        }
    }

    void InsertAtEnd(){
        MNode *p=head;
        MNode *s=getNode();

        if(head==NULL){
            head=s;
            return;
        }
       while(p->next!=NULL){
        p =p->next;
        }
        p->next=s;
    }

    void InsertAtFirst(){
        MNode *p=head;
        MNode *s=getNode();
        s->next=p;
        head=s;
    }

    void InsertAtPos(){
        MNode *p=head,*s,*temp;
        int pos;
        cout<<"Enter position to add: "<<endl;
        cin>>pos;
        if(pos== 0){
            InsertAtFirst();
            return;
        }
        s=getNode();
        int i=0;
        while(p!=NULL && i<pos-1){
            p=p->next;
            i++;
        }
        temp=p->next;
        p->next=s;
        s->next=temp;
        cout<<"Contact details inserted" << endl;
    }

    void Delete(){
        if(head==NULL){
            cout<<"List is empty"<<endl;
            cout<<"\n";
            return;
        }
        string name;
        cout<<"Name of contact to delete:"<<endl;
        cin>>name;
 MNode *p=head,*prev=NULL;

        if(head->name ==name){
            MNode *temp=head;
            head=head->next;
            delete temp;
            cout<<"Cotact has been deleted"<<endl;
            return;
        }
        while(p!=NULL && p->name!=name){
            prev= p;
            p =p->next;
        }
        if(p== NULL){
            cout<<"No contact foiund." << endl;
            cout<<"\n";
            return;
        }
        prev->next= p->next;
        delete p;
        cout<<"Contact deleted successfully."<<endl;
        cout<<"\n";
    }

    void search(){
        MNode *p;
        p=head;
        string name;
        cout<<"Enter contact name to search: "<<endl;
        cin>>name;
        while(p !=NULL){
            if(p->name==name){
                cout<<"Name:"<<p->name<<endl;
                cout<<"contact no :"<<p->number<<endl;
                cout<<"EmailID: "<<p->email<<endl;
                cout<< "\n";
                return;
            }
            p=p->next;
        }
        cout<<"contact Not Found!"<<endl;
        cout<<"\n";
    }

    void reverse(){
        MNode *curr,*prev,*temp;
        prev=NULL;
        curr=head;

        if(head==NULL){
            cout<<"List is Empty" << endl;
            return;
        }
        while(curr !=NULL){
            temp= curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        head=prev;
    }
};

int main(){
    MList s;
    s.Createlist();
    s.Display();
    int choice;
    do{
        cout<<"1.Insert contact at first"<<endl;
        cout<<"2.Insert contact at end"<<endl;
        cout<<"3.Insert contact at a specific position"<<endl;
        cout<<"4.Delete Node"<<endl;
        cout<<"5.Reverse Linked List"<<endl;
        cout<<"6.search Linked List"<<endl;
        cout<<"7.Display Contacts"<<endl;
        cout<<"Enter operation "<<endl;
        cin>>choice;
        switch (choice){
        case 1:
            s.InsertAtFirst();
            break;
        case 2:
            s.InsertAtEnd();
            break;
        case 3:
            s.InsertAtPos();
            break;
        case 4:
            s.Delete();
            break;
        case 5:
            s.reverse();
            break;
        case 6:
            s.search();
            break;
        case 7:
            s.Display();
            break;
        default:
            cout<<"enter a valid choice"<<endl;
        }
    } while(choice <= 7 && choice >= 1);
}

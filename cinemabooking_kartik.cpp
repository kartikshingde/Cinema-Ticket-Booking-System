#include<iostream>
#include<string>
using namespace std;
class Node{
    public:
        string name;
        string seat;
        Node *next;
        int seatNo;
        Node(int seatNo,string seat){
            next=NULL;
            this->seatNo=seatNo;
            this->seat=seat;

        }
};
void display(Node* &head,Node* &tail)
{
    cout<<endl;
    Node *print=head;
    while(print!=NULL)
    {
        
        if(print->seatNo<10){
            cout<<" "<<print->seatNo<<print->seat;
            print=print->next;
        }
        else{
            if(print->seatNo==11 || print->seatNo==21 || print->seatNo==31 || print->seatNo==41){
                cout<<"\n";

            }
            cout<<print->seatNo<<print->seat;
            print=print->next;
        }
    }
    cout<<"\n\nSCREEN-> | _._._._._._._._._._._._._._._._._._._._._._._._ |";
    cout<<"\n-------------------------------------------------------------------------------\n";
    cout<<endl;
}
void create(Node* &head,Node* &tail){
    int No=0;
    for(int i=0;i<50;i++){
        Node *temp=new Node(No,"|___|");
        if(head==NULL){
            temp->next=head;
            head=temp;
            tail=temp;
            temp->seatNo=No;
            temp->seat="|___|";
            No++;
        }
        tail->next=temp;
        tail=temp;
        tail->seatNo=No;
        tail->seat="|___|";
        No++;
    }
}
void book(Node* &head,int pos){
    Node *book=head;
    if(pos>51 || pos<1){
        cout<<"\nEnter Valid seat number: "; 
        return;  
    }
    if(pos<=30){
        cout<<"Ticket price for this is RS 300.";
    }
    if(pos>30){
        cout<<"Ticket price for this is RS 180.";
    }
    for(int i=1;i<pos;i++){
        book=book->next;
         
        
    }
    if(book->seat=="|_B_|"){
        cout<<"\nSeat is Already Booked,Please Choose another.";
        
    }
    
    else{
        string name;
        cout<<"\nEnter Your Name: ";
        // getline(cin,book->name)
        cin>>book->name;
        book->seatNo=pos;
        book->seat="|_B_|";
        cout<<"\n***Seat Booked Successfully.***";
    }
    

}
void cancel(Node* &head,int pos){
    Node*book=head;
    for(int i=1;i<pos;i++){
        book=book->next;
    }
    if(book->seat=="|___|"){
        cout<<"\nThis Seat Not Booked yet\nEnter Correct seat no.\n";
        return;
    }
    else{
        book->seat="|___|";
        cout<<"\n***Ticket Cancelled Successfully***";
        cout<<endl;
    } 
}
void bookinginfo(Node* &head,int pos)
{
    Node *info=head;
    if(pos>50 || pos<1){
        cout<<"Please Enter Valid Seat No. "<<endl;
        return;
    }
    for(int i=1;i<pos;i++){
        info=info->next;
    }
    if(info->seat=="|___|"){
        cout<<"\nSeat is not Booked yet.."<<endl;
        return;
    }
    else{
        cout<<"\n"<<info->seatNo<<" is booked by "<<info->name<<" ."<<endl;
    }

}
void count(Node* &head,int pos){
    int countb,countr;
    countb=countr=0;
    Node *book=head;
    while(book!=NULL){
        
        if(book->seat=="|_B_|"){
            countb++;
        }
        else{
            countr++;
        }
        book=book->next;
    }
    cout<<"\nNo. Of booked seats are : "<<countb;
    cout<<"\nNo. of remaining seats are: "<<countr<<endl;
}
void cancelM(Node* &head,int pos){

    Node *book=head;
    for(int i=1;i<pos;i++){
        book=book->next;
    }
    if(book->seat=="|___|"){
        cout<<"\nSeat is not booked yet.."<<endl;
    }
    else{
        book->seat="|___|";
    }
    cout<<"\nSeat cancelled ..."<<endl;
}



int main(){

        Node *head=NULL;
        Node *tail=NULL;
        cout<<endl;
        cout<<"|_____________________________________________________________________________|\n";
        cout<<"|                  ---->  CINEMA TICKET BOOKING SYSTEM  <----                 |\n";
        cout<<"|                             BY--> <KARTIK> </>       <-                     |\n";
        cout<<"|_____________________________________________________________________________|\n";
        create(head,tail);
        display(head,tail);
        cout<<endl;
        int choice;
        do{
            
            cout<<"\nSelect : ";
            cout<<"\n1.Customer"<<"\n2.Manager"<<"\n3.Exit-->";
            cout<<"\nEnter Choice: ";
            cin>>choice;
            switch(choice){
                case 1:
                {   bool a=true;
                    do{
                        cout<<endl;
                        cout<<"\n--------MENU--------";
                        cout<<"\n1.Check Availibility Of Ticket:"<<"\n2.Book Ticket:"<<"\n3.Cancel Booked Ticket:"<<"\n4.GO back."<<"\nEnter Your Choice: ";
                        int choice2;
                        cin>>choice2;
                        switch(choice2){
                            case 1:
                            {
                                display(head,tail);
                                break;

                            }
                            case 2:
                            {
                                int pos;
                                cout<<"Enter the seat No. to be booked: ";
                                cin>>pos;
                                book(head,pos);
                                break;
                            }
                            case 3:
                            {
                                int cance;
                                
                                cout<<"Enter Seat No. for Ticket Cancellation : ";
                                cin>>cance;
                                cancel(head,cance);
                                break;

                            }
                            case 4:
                            {
                                a=false;
                                break;
                            }
                            default:
                            {
                                cout<<"\nChoose valid choice";
                                
                            }
                            
                        }
                    }while(a);
                    break;
                }
                case 2:
                {
                    string username;
                    int password;
                    bool b=true;
                    cout<<"\n***Login Here: ***";
                    cout<<"\nEnter username: ";
                    cin>>username;
                    cout<<"Enter password: ";
                    cin>>password;
                    do{
                        
                        if(username!="mr_manager" || password!=1234){
                            cout<<"\nLogin Failed,Enter Correct Details: ";
                            b=false;
                            
                        }
                        cout<<"\n-----Manager MENU-----";
                        cout<<"\n1.Check Status Of Seats"<<"\n2.Check Information about Customer.";
                        cout<<"\n3.Remaining Seats and Booked Seats."<<"\n4.Cancel ticket."<<"\n5.Go Back"<<"\nEnter your choice.";
                        int choice3;
                        cin>>choice3;
                        switch(choice3){
                            case 1:
                            {
                                display(head,tail);
                                break;
                            }
                            case 2:
                            {
                                int pos;
                                cout<<"\nEnter the seat No.: ";
                                cin>>pos;
                                bookinginfo(head,pos);
                                break;
                                
                            }
                            case 3:
                            {
                                int pos;
                                count(head,pos);
                                break;
                            }
                            case 4:
                            {
                                int pos;
                                cout<<"\nEnter the seat no. to be cancelled: ";
                                cin>>pos;
                                cancelM(head,pos);
                                break;
                            }
                            case 5:
                            {
                                b=false;
                                break;
                            }
                            default:
                            {
                                cout<<"\nPlease enter valid option...";
                                break;
                            }
                        }
                    }while(b);
                    break;
                }
            }
        }while(choice!=3);
        
        cout<<"\nThankYou---->";
        
}
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
using namespace std;
//void deleterecord();
char ch;
const int size=100;
int IDnumber[size];
string firstname[size];
string lastname[size];
string phonenumber[size];
string nationality[size];

int dIDnumber[size];
string dfirstname[size];
string dlastname[size];
string dphonenumber[size];
string dnationality[size];
string na ,ln ,fn  ,pn;
int id ;

int Eindex();
int Edindex();
int Lindex(int idnum);
void readfile() ;
void writefile();
void writefiledelete();
bool Sindex(int idno);

void modify();
void totalcharge();
void readfiledelete();

void addpatient();
void deletrecord();
void displaydata();

int c=0; // counter





int main()
{
    int choose;
  do
  {
      system("cls");


      cout<<"\n\n\t PLEASE SELECT FROM THE MENUE" ;
      cout<< "\n\n\t please choose one of this options   \n";
   cout<<"-----------------------------------------\n";
   cout<<"1.add patient number \n ";
   cout<<"2.modify patient record \n ";
   cout<<"3.delete patient record \n ";
   cout<<"4.list of all patients \n ";
   cout<<"5.issue invoice for a patients\n ";
   cout<<"6.list of all deleted patients \n ";
   cout<<"7.exit \n ";

            cin >> choose;

              readfile();
            system("cls");
            switch(choose)
            {
        case 1:
            readfile();
            addpatient();
            writefile();
               break;
        case 2:
            modify();
            writefile();
              break;
        case 3:
            deletrecord();
            writefile();
              break;
        case 4:
            displaydata();
            for (int i=0 ;i<c;i++)
                cout<< IDnumber[i]<<"\t"<<firstname[i]<<"\t"<<lastname[i]<<"\t"<<phonenumber[i]<<"\t"<<nationality[i];
              break;
        case 5:
            totalcharge();
              break;
        case 6:
           readfiledelete();
        for(int i=0;i<c;i++)
                cout<< dIDnumber[i]<<"\t"<<dfirstname[i]<<"\t"<<dlastname[i]<<"\t"<<dphonenumber[i]<<"\t"<<dnationality[i];
             break;
        case 7:
        cout<<"\n\n\n\n\n\t\t                GOOD BYE.....";
            break;
         default :cout<<"\a";

            }
            cin.ignore();
            cin.get();
  }while(choose!=7);
    return 0;
}
//*********************************************************8
void addpatient()
{
    string x;
    int idno;
    do{
        int label=Eindex();
        if (label==-1)
        {
            cout<<"\n\t\tno avialable space for new patient\n";
            return;
        }
bool h;
do{
    system("cls");
    cout<<"\n\nPLEADE ENTER THE ID NUMBER:   ";
    cin>>idno;

    if(Sindex(idno))
    {
        cout<<"\n\t\t THE patient number is EXIST, TRY AGAIN\n";
        h=1;
    }
    else
        h=0;

}while(h);

IDnumber[label]=idno;

cout<<"\n\nPLEASE ENTER THE patient first name:   ";
cin>>fn;
cout<<"\n\nPLEASE ENTER THE patient last name:    ";
cin>>ln;
cout<<"\n\nPLEASE ENTER THE patient phone number:  ";
cin>>pn;
cout<<"PLEASE ENTER THE patient nationality:     ";
cin>>na;

firstname[label]=fn;
lastname[label]=ln;
phonenumber[label]=pn;
nationality[label]=na;
cout<<"\n\n\nTO ADD MORE ENTER (Y).. OR TO EXIT ENTER (N)";
cin>>x;

}while(x!="N"&&x!="n");
cout<<"\nTHE RECORD IS SUCCEFULY CREATED..";
}
//******************************************************
void readfile()           //READ THE INFORMATION FROM FILE

{
   ifstream inFile;
    inFile.open("patient.txt");
    if(!inFile)
    {
        return;
    }
    int i=0;
    while(!inFile.eof() )
    {
        int idno;fn;ln;pn;na;

        inFile>>idno;
        if(idno<=0)
            return;
        inFile>>fn>>ln>>pn>>na;
        IDnumber[i]=idno;
        firstname[i]=fn;
        lastname[i]=ln;
        phonenumber[i]=pn;
        nationality[i]=na;
        i++;
        }
        for (int i=0;i<=c;i++)
            inFile.close();
}

/*void invoicemenu()
{

    cout<<"what type of treatment the patient had? \n";
    cout<<"1.Surgery. \n";
    cout<<"2.Stay at hospital. \n";
    cout<<"3.Medication. \n";
}
*/

void writefile()
{

    ofstream outFile;
    outFile.open("patient.txt");
    int i=0;
    for(i=0 ;i<size ;i++)
    {
        if(IDnumber[i]==0)
            break;
         outFile<<"\n"<<IDnumber[i]<<"\t"<<firstname[i]<<"\t"<<lastname[i]<<"\t"<<phonenumber[i]<<"\t"<<nationality[i];

    }
    outFile.close();
}

bool Sindex(int idno)   // return true if the patient exist
 {
     for(int i=0; i<size;i++)
     {
         if(IDnumber[i]==0)
            return false;
     }

 }

 int Eindex()       //Share empty index in array
 {
     for(int i=0;i<size; i++)
     {
         if(IDnumber[i]==0)
            return i;
     }
     return -1;
 }
 int Lindex(int idnum)     //search the patient index in array
 {
     for(int i=0;i<size ;i++)
     {
        if(IDnumber[i]==0)
        return -1;
        if(IDnumber[i]==idnum)
            return i;
    }
    return -1;
 }

 void menu()
 {
     cout<<"\n\n\t    TO UPDATE.. CHOOSE FROM THE MENUE:  ";
     cout<<"\n\n\t1.  UPDATE THE ID NUMBER FIELD: \t";
     cout<<"\n\n\t2.  UPDATE THE FIRST NAME FIELD:\t";
     cout<<"\n\n\t3.  UPDATE THE LAST NAME FIELD: \t";
     cout<<"\n\n\t4.  UPDATE THE PHONE NUMBER FEILD:\t";
     cout<<"\n\n\t5.  UPDATE THE NATIONALITY FEILD:\t";

     cout<<"\n\n\t    PLEASE ENTER YOUR CHOICE: \t";
 }

 void modify()    // update patient information
{
    system("cls");
         menu();
     int IDno;

     cout<<"\n\n PLEASE ENTER ID NUMBER:   ";
     cin>>IDno;

     if(!Sindex(IDno))
     {
         cout<<"\n\n\t ID NUMBER IS NOT FOUND\n";
         return;
     }
    int S=Lindex(IDno);

    IDnumber[S]=IDno;

    int x;
    do{
        system("cls");
        menu();
        cin>>x;

        switch(x){
    case 1:
        cout<<"\n\n PLEASE ENTER THE ID NUMBER";
        cin>>IDno;
        IDnumber[S]=IDno;
        cout<<"\n\nTHANK YOU";
        break;
    case 2:

        cout<<"\n\nPLEASE ENTER THE FIRST NAME:  ";
        cin>>fn;
        firstname[S]=fn;
        cout<<"\n\nTHANK YOU";
        break;
    case 3:

        cout<<"\n\nPLEASE ENTER THE LAST NAME:  ";
        cin>>ln;
        lastname[S]=ln;
        cout<<"\n\nTHANK YOU";
        break;

    case 4:
        cout<<"\n\nPLEASE ENTER THE PHONE NUMBER:  ";
        cin>>pn;
        phonenumber[S]=pn;
        cout<<"\n\nTHANK YOU";
        break;

    case 5:
        cout<<"\n\nPLEASE ENTER YOUR NATIONALITY:  ";
        cin>>na;
        nationality[S]=na;
        cout<<"\n\nTHANK YOU";
        break;

        default:cout<<"\n\nINVALID ENTERED ... TRY AGIN";

        }
        cout<<"\n\nWOULD YOU LIKE TO CHANGE ANOTHER FEILD?(Y/N):";
        cin>> ch;
    }
    while(ch !='N' && ch!='n');
    cout<<"\nTHE PATIENT FIELD IS UPDATED..";
}

void displaydata()
{
ifstream inFile;

  inFile.open("patient.text");
  if (inFile)
    while (!inFile.eof())
  {
      inFile>>IDnumber[c]>>firstname[c]>>lastname[c]>>phonenumber[c]>>nationality[c];
      c++;
  }
    inFile.close();
}
void deletrecord()

{
    system("cls");
    int id_no,ss;
    cout<<"\n\n\t PLEASE ENTER THE ID NUMBER ";
    cin>>id_no;
    if(!Sindex(id_no))
    {
        cout<<"\n\t\tID number is not found\n";
        return;
    }
    ss=Lindex(id_no);

    if(IDnumber[ss+1]==0)
    {
        IDnumber[ss]=0;
        cout<<"\n\n\t RECORD IS DELETED ";
        return;
    }
    for(int i=ss;i<size-1;i++)
    {
        if(IDnumber[i+1]==0)
        {
            IDnumber[i]=0;
            cout<<"\n\n\t RECORD IS DELETED ";
            i=size;
        }
        else
            IDnumber[i]=IDnumber[i+1];
    }
    cout<<"\n\n\t RECORD Is DELETED ";
//********
string x;

   int label=Edindex();
   if(label==-1)
   {
       cout<<"\n\n\tno avialable space for new patient\n";
       return;
   }
   IDnumber[label]=id_no;
   dfirstname[label]=fn;
   dlastname[label]=ln;
   dphonenumber[label]=pn;
   dnationality[label]=na;

   cout<<"\nTHE RECORD IS SUCCESSUSSFULY CREATED IN DELETE FILE .. ";
   writefiledelete();
}

int Edindex()    //SEARCH EMPTY INDEX IN array
{
    for(int i=0;i<size;i++)
    {
    if(dIDnumber[i]==0)
    return i;
    }
   return -1;

}
void writefiledelete()
{
    ofstream outfile;
    outfile.open("deletepatient.txt");
    int i=0;
    for(i=0; i<size;i++)
    {
        if(dIDnumber[i]=0)
            break;
        outfile<<"\n"<<dIDnumber[i]<<"\t"<<dfirstname[i]<<"\t"<<dlastname[i]<<"\t"<<dphonenumber[i]<<"\t"<<dnationality[i];
    }
    outfile.close();
}
void readfiledelete()
{
    ifstream inFile;

    inFile.open("deletepatient.txt");
    if (inFile)
    while(!inFile.eof())
    {
         inFile>> dIDnumber[c]>>dfirstname[c]>>dlastname[c]>>dphonenumber[c]>>dnationality[c];
        c++;
    }
    inFile.close();
}
void totalcharge()
{
    system("cls");
    int IDno;
    cout<<"\n\n please enter ID number:  ";
    cin >>IDno;

    if(!Sindex(IDno))
    {
        cout<<"\n\t\t ID NUMBER IS NOT FOUND\n";
        return;
    }
    int S=Lindex(IDno);
    IDnumber[S]=IDno;
    int x,ch_surgery,stay_ch,med_ch,total=0;
    do{
        system("cls");
        cout<<"what type of treatment the patient had ?\n"<<endl;
        cout<<"1.surgery ? \n"<<endl;
        cout<<"2.stay at hospital ?\n"<<endl;
        cout<<"3.medication ? \n"<<endl;
        cout<<"Choose from above menu ?\n"<<endl;
        int z;
        cin>>x;
        switch(x){
    case 1:
        cout<<"Please ENTER Surgery charge \n"<<endl;
        cout<<"1.  surgery 1  "<<endl;
        cout<<"2.  surgery 2  "<<endl;
        cout<<"3.  surgery 3  "<<endl;
        cin >>z;
        if(z==1)
            ch_surgery=100;
        else if (z==2)
            ch_surgery=200;
        else if (z==3)
            ch_surgery=300;
        else
            ch_surgery =0;
        break;
    case 2:
        cout<<"Please enter how many days stay at hospital "<<endl;
        cin>>z;
        stay_ch=z*500;
        break;
    case 3:
        cout<<"Please Enter medication charge "<<endl;
        cout<<"1. med  1"<<endl;
        cout<<"2. med  2 \n";
        cout<<"3. med  3 \n";
        cin>>z;
        if (z==1)
            med_ch=100;
        else if(z==2)
            med_ch=200;
        else if(z==3)
            med_ch=300;
        else
       med_ch=0;
       break;

       }
        cout<<"\n\n Would You like To Another Treatment? (Y/N):";
        cin>>ch;

    }
while (ch!='n'&&ch!='N');
 total+=ch+ch_surgery+stay_ch+med_ch;
cout<<"IDnumber  "<<"\t"<<"total"<<endl;
cout<<IDnumber[IDno]<<"\t"<<total<<endl;
}


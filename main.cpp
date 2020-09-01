#include <iostream>
#include <fstream>
using namespace std;


void AddNewBook()
{	string name="";
	float price=0;
	int amount=0;
   	 ofstream myfile;
     myfile.open("lib.txt",ios::app);
     cout<< "Insert book name : ";
     cin>>name;
     cout<< "Insert book price : ";
     cin>>price;
     cout<< "Insert book amount : ";
     cin>>amount;
     myfile<<name<<"*"<<price<<"*"<<amount<<"*"<<endl;

     myfile.close();
}
void View()

{
	string line="";
    string name="";
	string price="";
	string amount="";
   	fstream myfile;
 	myfile.open("lib.txt",ios::in);

  	cout << "Name" << "\t" << "Price" << "\t" << "Amount"  << endl;



    while(getline(myfile,line))
	{
	    for(int count=0;count<line.length();count++)
	    {
	    	if(line[count]!='*')
	    	name=name+line[count];
	    	else 	break;

		}

	    for(int count=name.length()+1;count<line.length();count++)
	    {
	    	if(line[count]!='*')
	    	price=price+line[count];
	    else 	break;
		}
	     for(int count=name.length()+price.length()+2;count<line.length();count++)
	    {
	    	if(line[count]!='*')
	    	amount=amount+line[count];
	    	else 	break;
		}
     	cout<<name<<"\t"<<price<<"\t"<<amount<<endl;
     	name="";
     	price="";
     	amount="";

	}
    myfile.close();
}
void Sreach()
{
	string line="";
    string name="";
	string price="";
	string amount="";
	string sw="";
	cout<<"Please insert your book name : "<<endl;
	cin>>sw;

   	fstream myfile;
 	myfile.open("lib.txt",ios::in);

  	cout << "Name" << "\t" << "Price" << "\t" << "Amount"  << endl;



    while(getline(myfile,line))
	{

	    for(int count=name.length()+1;count<line.length();count++)
	    {
	    	if(line[count]!='*')
	    	price=price+line[count];
	    	else 	break;

		}

		int result=price.find(sw);
	    if(result>=0)
	    {


	    for(int count=0;count<line.length();count++)
	    {
	    	if(line[count]!='*')
	    	name=name+line[count];
	    else 	break;
		}
	     for(int count=name.length()+price.length()+2;count<line.length();count++)
	    {
	    	if(line[count]!='*')
	    	amount=amount+line[count];
	    	else 	break;
		}
     	cout<<name<<"\t"<<price<<"\t"<<amount<<endl;
     }
     	name="";
     	price="";
     	amount="";

	}
    myfile.close();
}

void update()
{
    string line="";
    string name="";
    string price="";
    string amount="";
    string sw="";
    cout<<" - please insert your book name :";
    cin>>sw;


    fstream myfile;
    fstream tempfile;
    myfile.open("lip.txt",ios::in);
    tempfile.open("temp.txt",ios::out);

    while(getline(myfile,line))
    {

    	if(name!=sw)
    	    {
    	    	cout<<" - please entre the new name :";
    	    	cin>>name;
    	    	cout<<" - please entre the new price :";
    	    	cin>>price;
    	    	cout<<" - please entre the amount :";
    	    	cin>>amount;
    	    	tempfile<<name<<'*'<<price<<'*'<<amount<<'*'<<endl;
    	    	cout<<name<<"\t update"<<endl;
    	    }
    	    else
			   {
			   	tempfile<<name<<'*'<<price<<'*'<<amount<<'*'<<endl;
				}

    	       myfile.close();
    	       tempfile.close();
			   remove("lib.txt");
			   char oldname[] ="temp.txt";
			   char newname[] ="lib.txt";
			   rename( oldname , newname);



	}
}






void Delete()
{
		string line="";
    string name="";
	string price="";
	string amount="";
	string sw="";
	cout<<"Please insert your book name : "<<endl;
	cin>>sw;

   	fstream myfile;
   	fstream tempfile;
 	myfile.open("lib.txt",ios::in);
	tempfile.open("temp.txt",ios::out);




    while(getline(myfile,line))
	{

	    for(int count=0;count<line.length();count++)
	    {
	    	if(line[count]!='*')
	    	name=name+line[count];
	    	else 	break;

		}

	    if(name!=sw)
	    {


	    for(int count=name.length()+1;count<line.length();count++)
	    {
	    	if(line[count]!='*')
	    	price=price+line[count];
	    else 	break;
		}
	     for(int count=name.length()+price.length()+2;count<line.length();count++)
	    {
	    	if(line[count]!='*')
	    	amount=amount+line[count];
	    	else 	break;
		}
     	tempfile<<name<<"*"<<price<<"*"<<amount<<"*"<<endl;
     }
	 else
	  cout<<name<<"\t deleted"<<endl;
     	name="";
     	price="";
     	amount="";

	}
    myfile.close();
    tempfile.close();
     remove("lib.txt");
     char oldname[] ="temp.txt";
       char newname[] ="lib.txt";
       rename( oldname , newname );
}

int main() {

	string op;
	cout<<endl<<"                     * Wellcome To FCI Library Programe * "<<endl<<endl<<endl;
		do
	{
	cout<< "     - Press  (1) to add new book."<<endl;
	cout<< "     - Press  (2) to search for book."<<endl;
    cout<< "     - Press  (3) to update a book."<<endl;
    cout<< "     - press  (4) to delete a book."<<endl;
    cout<< "     - Press  (5) to view all books."<<endl;
    cout<< "     - Press  (0) to Exit."<<endl;

    cout<<endl<<endl<< "               - Your Chois is : ";
	cin>>op;


   if(op=="1")
   {
      AddNewBook();
   }
   else
    if(op=="2")
   {
   	Sreach();
   }
   else
   if(op=="3")
   {
   	update();
   }
   else
    if(op=="4")
   {
   	Delete();
   }
   else
    if(op=="5")
   {
   	View();
   }
   else if(op=="0")
   {
   	break;
   }
   cout<<"----------------------"<<endl;
}
    while(true);

	return 0;
}


#include<iostream>
#include<iomanip>
#include<fstream>
#include<ctime>
#include<stdlib.h>
using namespace std;

class info
{
	protected:
		short Past_exp;
		short license_type;
		string course_type[9]{ {"Automobile"},
                    {"Hizb-1"},
                    {"Derek-1"},
                    {"Hizb-2"},
                    {"Derek-2"},
                    {"Fesash-1"},
                    {"Hizb-3"},
                    {"Derek-3"},
                    {"Fesash-2"} };

};

class person: public info
{
	string Fname;
	string Phone_no;
    string date_of_begining;
	short Age;
	short Edu_level;

protected:
	short fNamewidth=10;
	short year=2014;
	short course_no;
	short sta_month;
	char check;
	fstream file;
	string fileRead;
	string date;

public:
	void menu()
	{
		char c;
		short choice;
		string option[3]={{"Display"},{"Registration"},{"Contuct us"}};
	reChoice:
		system("cls");
		cout<<"\t-------------------------------------------------\n\t------Driving License School--------\n\t-------------------------------------------------\n\n";
		for(short i=0;i<3;i++)
		{
			cout<<"Press "<<i+1<<" for : "<<option[i]<<endl;
		}
		cin>>choice;

		if(choice == 1)
		{
		rePNo1:
			cout<<"Phone number +251 - ";
			cin>>Phone_no;
			if(Phone_no.length()!=9){
		        cout<<"please enter valid number \n";
		        goto rePNo1;
		        }
		    file.open(Phone_no+".txt",ios::in);
			if(file.is_open())
			{
				system("cls");
				cout<<"\n=====================================\n\n";
				while(getline(file,fileRead))
				{
					cout<<fileRead<<endl;
				}
				cout<<"\n=====================================\n";
				cout<<" \n Press 'Y' to continue  and press any key to exit : ";
	                cin>>c;
	                if(c=='Y' || c=='y')
	                {
	                    goto reChoice;
	                }
				getchar();
				exit(0);
			}
			else
			{
				system("cls");

				cout<<" \n ==== # You dont have any information === \n ";
				cout<<"please Press 'Y' to continue  and press any key to exit : ";
	                cin>>c;
	                if(c=='Y' || c=='y')
	                {
	                    goto reChoice;
	                }

			}
		}

		else if (choice ==2)
		{
			Pers_info();
		}

		else if(choice ==3)
		{
			system("cls");
			cout<<"\n\t=====================================\n\n";
			file.open("contuctus.txt",ios::in);
			if(file.is_open())
			{
				while(getline(file,fileRead))
				{
					cout<<fileRead<<endl;
				}
				cout<<"\n\t=====================================\n";
				cout<<" \n Press 'Y' to continue  and press any key to exit : ";
	                cin>>c;
	                if(c=='Y' || c=='y')
	                {
	                    goto reChoice;
	                }
				getchar();
				exit(0);
			}
		}
		else
		{
			goto reChoice;
		}
	}

	//function that accept personal information
	void Pers_info()
	{	system("cls");
		cout<<"\t Please enter your Personal Informations\n\t----------------------------------------\n";
	    string edulevel[]={"Below grade 4","Grade 4-9","Above Grade 9"};

	rePNo:
	    cout<<"Phone number +251 - ";
		cin>>Phone_no;
		if(Phone_no.length()!=9){
	        cout<<"please enter valid number \n";
	        goto rePNo;
	        }

		cout<<"Enter your Fullname : ";
		cin.ignore();
		getline(cin,Fname);
		if(Fname.length()>fNamewidth)
	        fNamewidth=Fname.length();

		cout<<"How old are you : ";
		cin>>Age;

		cout<<"enter your level of education:\n";
		 for(short j=0;j<3;j++){
	            cout<<"Press "<<j+1<<" for => "<<edulevel[j]<<endl;
	            }
		cin>>Edu_level;
	}

	//function that checks age education level and avaliable course
	void checker()
	{
		if(Age<=17 || Age>70)
	        goto notAVA;
		if(Edu_level==1)
	        goto notAVA;

	    if(Age>17 && Age<22)
	    {
	        if( Edu_level!=1){
	h:      cout<<"Which type of driving class do you want to take?   "<<endl;
	        for(short i=0;i<1;i++)
			{
	             cout<<"Press "<<i+1<<" for : "<<course_type[i]<<endl;
	        }
			}
	        else
	            goto notAVA;
	    }
	    else if(Age>=22 && Age<24)
	    {
	        if(Edu_level==2){
	           goto h;
	        }
	        else if(Edu_level==1){
	            goto notAVA; }
	        else{
	level_1:
	        cout<<"Which type of driving class do you want to take?   "<<endl;
	        for(short i=0;i<3;i++){
	            cout<<"Press "<<i+1<<" for : "<<course_type[i]<<endl;
	            }
	            }
	    }
	    else if(Age>=24 && Age<26)
	    {
	        if(Edu_level==2)
	           goto h;
	        else if(Edu_level==1){
	            goto notAVA; }
	        else {
	                cout<<"Do you have past experience \n Press 'Y' for yes and press any key for no : ";
	                cin>>check;
	                if(check=='Y' || check=='y')
	                {
	                    cout<<"In which type do you have exp "<<endl;
	re:                 for(short i=1;i<3;i++){
	                    cout<<"Press "<<i<<" for : "<<course_type[i]<<endl;
	                    }
	                    cin>>Past_exp;
	                    if(Past_exp==1)
	                    {
	level_2:
	                        cout<<"Which type of driving class do you want to take?    "<<endl;
	                        for(short i=0;i<4;i++){
	                        cout<<"Press "<<i+1<<" for : "<<course_type[i]<<endl;
	                        }
	                    }
	                    else if(Past_exp==2)
	                    {
	level_3:
	                        cout<<"Which type of driving class do you want to take?   "<<endl;
	                        for(short i=0;i<6;i++){
	                        cout<<"Press "<<i+1<<" for : "<<course_type[i]<<endl;
	                        }
	                    }
	                    else{
	                        cout<<"Enter 1 or 2 please \n";
	                        goto re;
	                        }
	                }
	                else
	                    goto level_1;

	        }
	    }
	    else if(Age>=26 && Age<=70)
	    {
	        if(Edu_level==2)
	           goto h;
	        else if(Edu_level==1){
	            goto notAVA; }
	        else {
	                cout<<"Do you have past experience \n Press 'Y' for yes and press any key for no : ";
	                cin>>check;
	                if(check=='Y' || check=='y')
	                {
	                    cout<<"In which type do you have experience "<<endl;
	re2:                for(short i=1;i<6;i++){
	                    cout<<"Press "<<i<<" for : "<<course_type[i]<<endl;
	                    }
	                    cin>>Past_exp;
	                    if(Past_exp==1)
	                    {
	                       goto level_2;
	                    }
	                    else if(Past_exp==2)
	                    {
	                       goto level_3;
	                    }
	                    else if(Past_exp==3)
	                    {
	                        cout<<"Which type of driving class do you want to take?    "<<endl;
	                        for(short i=0;i<7;i++){
	                        cout<<"Press "<<i+1<<" for : "<<course_type[i]<<endl;
	                        }
	                    }
	                    else if(Past_exp==4)
	                    {
	                        cout<<"Which type of driving class do you want to take?   "<<endl;
	                        for(short i=0;i<8;i++){
	                        cout<<"Press "<<i+1<<" for : "<<course_type[i]<<endl;
	                        }
	                    }
	                    else if(Past_exp==5)
	                    {
	                        cout<<"Which type of driving class do you want to take?   "<<endl;
	                        for(short i=0;i<9;i++){
	                        cout<<"Press "<<i+1<<" for : "<<course_type[i]<<endl;
	                        }
	                    }
	                    else{
	                        cout<<"Enter a number between 1 and 5 please \n";
	                        goto re2;
	                        }
	                }
	                else
	                    goto level_1;

	        }
	    }

	    else{
	notAVA:
	     system("cls");
	      cout<<"\nYou are not allowed to take driving classes.\n";
	      exit(0);
	    }
		cin>>license_type;

	    course_no=license_type-1;
	cout<<"\n----------------------------------\n";
	}

	void display()
	{
		time_t t;

		t=time(NULL);
		tm* now =localtime(&t);
		string d=to_string((now->tm_mday));
		string m=to_string((now->tm_mon+2));
		string y=to_string((now->tm_year+1900));
		date =d+"/"+m+"/"+y;

	    system("cls");
	    cout<<"\t-------------------------------------------------\n\t------Driving License School--------\n\t-------------------------------------------------\n\n";

		short border=fNamewidth+14+12+29;
		cout<<"+";
		for(short i=1;i<=border;i++)cout<<"=";
		cout<<"+\n";
		cout<<left<<"| "<<setw(fNamewidth)<<"Full Name"
			<<" | "<<setw(14)<<"Phone number"<<" | "
			<<setw(12)<<"Course type"<<" | "<<setw(18)<<"starting date"
			<<" | "<<endl;
			cout<<"+";
		for(short i=1;i<=border;i++)cout<<"=";
		cout<<"+\n";

		cout<<left<<"| "<<setw(fNamewidth)<<Fname
			<<" | "<<setw(14)<<"+251"+Phone_no<<" | "
			<<setw(12)<<course_type[course_no]<<" | "<<setw(18)<<date	<<" |"<<endl;
			cout<<"+";
		for(short i=1;i<=border;i++)cout<<"-";
		cout<<"+\n";

		getchar();
	}

	void personal_data_saver()
	{
		file.open(Phone_no+".txt",ios::out);
		if(file.is_open())
		{
			file<<"Full name -> "<<Fname<<endl;
			file<<"Phone number -> +251"+Phone_no<<endl;
			file<<"Age -> "<<Age<<endl;
			file<<"Applied course -> "<<course_type[course_no]<<endl;
			file<<"Class start : "<<date;
		}
	}
};

int main()
{
	system("color E0");
	person per1;
	per1.menu();
	per1.Pers_info();
	per1.checker();
	per1.display();
	per1.personal_data_saver();

	return 0;
}

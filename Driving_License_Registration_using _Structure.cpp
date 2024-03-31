#include<iostream>
#include<iomanip>
#include<ctime>
using namespace std;

struct personal_info
{
	string Fname;
	string Phone_no;
    	string date_of_begining;
	short Age;
	short Edu_level;
	short Past_exp;
	short course_type;
};
//global var
string course_type[9]{ {"Automobile"},
                    {"Hizb-1"},
                    {"Derek-1"},
                    {"Hizb-2"},
                    {"Derek-2"},
                    {"Fesash-1"},
                    {"Hizb-3"},
                    {"Derek-3"},
                    {"Fesash-2"} };
short fNamewidth=10;
short year=2014;
short course_no;
short sta_month;

void Pers_info(personal_info &p);
void sta_date_cal(personal_info &p);
void display(personal_info p);

void Pers_info(personal_info &p)
{
    char check;
    string edulevel[]={"Below grade 4","Grade 4-9","Above Grade 9"};

    cout<<"\t-------------------------------------------------\n\t------Driving License School--------\n\t-------------------------------------------------\n\n";

	cout<<"\t Please enter your Personal Informations\n\t----------------------------------------\n";

rePNo:
    cout<<"Phone number +251 - ";
	cin>>p.Phone_no;
	if(p.Phone_no.length()!=9){
        cout<<"please enter valid number \n";
        goto rePNo;
        }

	cout<<"Enter your Fullname : ";
	cin.ignore();
	getline(cin,p.Fname);
	if(p.Fname.length()>fNamewidth)
        fNamewidth=p.Fname.length();

	cout<<"How old are you : ";
	cin>>p.Age;
    if(p.Age<=17 || p.Age>70)
        goto notAVA;

	cout<<"enter your level of education:\n";
	 for(short j=0;j<3;j++){
            cout<<"Press "<<j+1<<" for => "<<edulevel[j]<<endl;
            }
	cin>>p.Edu_level;
	if(p.Edu_level==1)
        goto notAVA;

    if(p.Age>17 && p.Age<22)
    {
        if( p.Edu_level!=1){
h:      cout<<"Which type of driving class do you want to take?   "<<endl;
        for(short i=0;i<1;i++)
		{
             cout<<"Press "<<i+1<<" for : "<<course_type[i]<<endl;
        }
		}
        else
            goto notAVA;
    }
    else if(p.Age>=22 && p.Age<24)
    {
        if(p.Edu_level==2){
           goto h;
        }
        else if(p.Edu_level==1){
            goto notAVA; }
        else{
level_1:
        cout<<"Which type of driving class do you want to take?   "<<endl;
        for(short i=0;i<3;i++){
            cout<<"Press "<<i+1<<" for : "<<course_type[i]<<endl;
            }
            }
    }
    else if(p.Age>=24 && p.Age<26)
    {
        if(p.Edu_level==2)
           goto h;
        else if(p.Edu_level==1){
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
                    cin>>p.Past_exp;
                    if(p.Past_exp==1)
                    {
level_2:
                        cout<<"Which type of driving class do you want to take?    "<<endl;
                        for(short i=0;i<4;i++){
                        cout<<"Press "<<i+1<<" for : "<<course_type[i]<<endl;
                        }
                    }
                    else if(p.Past_exp==2)
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
    else if(p.Age>=26 && p.Age<=70)
    {
        if(p.Edu_level==2)
           goto h;
        else if(p.Edu_level==1){
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
                    cin>>p.Past_exp;
                    if(p.Past_exp==1)
                    {
                       goto level_2;
                    }
                    else if(p.Past_exp==2)
                    {
                       goto level_3;
                    }
                    else if(p.Past_exp==3)
                    {
                        cout<<"Which type of driving class do you want to take?    "<<endl;
                        for(short i=0;i<7;i++){
                        cout<<"Press "<<i+1<<" for : "<<course_type[i]<<endl;
                        }
                    }
                    else if(p.Past_exp==4)
                    {
                        cout<<"Which type of driving class do you want to take?   "<<endl;
                        for(short i=0;i<8;i++){
                        cout<<"Press "<<i+1<<" for : "<<course_type[i]<<endl;
                        }
                    }
                    else if(p.Past_exp==5)
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
	cin>>p.course_type;

    course_no=p.course_type-1;
cout<<"\n----------------------------------\n";
}
void display(personal_info p)
{
	time_t t;

	t=time(NULL);
	tm* now =localtime(&t);
	string d=to_string((now->tm_mday));
	string m=to_string((now->tm_mon+2));
	string y=to_string((now->tm_year+1900));
	string a=d+"/"+m+"/"+y;

    system("cls");
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

	cout<<left<<"| "<<setw(fNamewidth)<<p.Fname
		<<" | "<<setw(14)<<"+251"+p.Phone_no<<" | "
		<<setw(12)<<course_type[course_no]<<" | "<<setw(18)<<a	<<" |"<<endl;
		cout<<"+";
	for(short i=1;i<=border;i++)cout<<"-";
	cout<<"+\n";

	getchar();
}
int main()
{
    system("color E0");
	personal_info d;
	Pers_info(d);
	display(d);
	return 0;
}

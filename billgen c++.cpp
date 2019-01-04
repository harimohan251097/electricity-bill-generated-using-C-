// Header file included..........

#include<fstream.h>
#include<stdio.h>
#include<string.h>
#include<process.h>
#include<conio.h>
#include<dos.h>


fstream file;

struct datatype
{
	char pass[30];
	int choice;char sym[1];     //sym 4 symbol
	float r1,r2,r3,r4,r5,r6;   //r 4 rupee
	float u1,u2,u3,u4,u5;     //u 4 units
	float tax,sub,fix;       //sub 4 subsidy per 1 unit
							//tax is in percent
						   //fix 4 fix charge
} dt;

class billgen
{
	int reg;                  //reg 4 registration no.
	char name[50],adr[100];
	float unit,bill,cost,ttax,tsub;  //bill 4 overall cost of bill
									//t(prefix) 4 total

	//prototype declaration

	void calcost();
	void changelines();
	void credit();
	void del();
	void def();
	void display();
	void fsave();
	void fsearch();
	void fun0();
	void fun1();
	void fun2();
	void fun3();
	void fun4();
	void genbill();
	void groupsettings();
	void help();
	void modify();
	void options();
	void user();


	public:
	billgen();
	void lines();

	void menu();
	void password();

} hi;




//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
//                               (MAIN)
//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH


void main()
{
	clrscr();

	cout<<"\n\t\t\t ELECTRICITY BILL-GENERATOR";
	cout<<"\n\n\n\t\t\t  The legendary\n";
	cout<<"\n\n\t\t\t\t HIMANSHU NEGI\n\n\n";
	cout<<"\t\t\t\t C++ project \n\n\n";
	cout<<"\t\t\t  Born On -: 12 April 93\n\n";
	hi.lines();         //Object calling function
	cout<<"\n\n\n\t\tPRESS ANY KEY TO CONTINUE....";
	getch();
	clrscr();
	hi.password();       // object calling function
	hi.menu();           //Object calling function
}



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
//                      searching important files
//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
void billgen::billgen()
{
	clrscr();
	textcolor(BLACK);
	textbackground(LIGHTGRAY);
	char a;
	cout<<"\nLoading all necessary files";
	for(int k=0;k<12;k++)
	{	delay(100);
		cout<<".";
	}
	file.open("data.txt",ios::in);
	while(!file)
	def();
	file.seekg(0);
	file.read((char*)&dt,sizeof(dt));
	cout<<"\nDisplay previously saved values(y/n)?";
	cin>>a;
	if(a=='y'||a=='Y')
	hi.display();
	file.close();

}



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
//                        DEFAULT VALUES
//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH

void billgen::def()
{
	cout<<"\n\nProgram file not found !\nFile creted....."
	<<"\nDefault values loading in program";
	for(int h=0;h<10;h++)
	{
	delay(100);
	cout<<".";
	}
	dt.u1=dt.u2=dt.u3=dt.u4=dt.u5=200;
	dt.r1=2.45;
	dt.r2=3.95;
	dt.r3=dt.r4=dt.r5=dt.r6=4.65;
	dt.choice=1;
	dt.fix=51.12;
	strcpy(dt.sym,"_");
	dt.tax=5;
	dt.sub=1;
	strcpy(dt.pass,"open");
	file.open("data.txt",ios::out);
	file.write((char*)&dt,sizeof(dt));
	cout<<endl;
	file.close();
}


//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
//                    DISPLAY the def() values
//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH

void billgen::display()
{
	clrscr();
	cout<<"\nThe present data are :\n______________________\n\n";
	switch(dt.choice)
	{
	case 0:cout<<"\nFirst Group of units contians :"<<dt.u1<<" units";
		  cout<<"\nfirst Group of unit charges    :"<<dt.r1<<" rupees";
		  cout<<"\nAll extra units charges        :"<<dt.r2<<" rupees";
		  break;


	case 1:cout<<"\nFirst Group of units contians :"<<dt.u1<<" units";
		   cout<<"\nSecond Group of units contain :"<<dt.u2<<" units";
		   cout<<"\nfirst Group of unit charges   :"<<dt.r1<<" rupees";
		   cout<<"\nSecond Group of unit charges  :"<<dt.r2<<" rupees";
		   cout<<"\nAll extra units charges       :"<<dt.r3<<" rupees";
		   break;

	case 2:cout<<"\nFirst Group of units contians :"<<dt.u1<<" units";
		   cout<<"\nSecond Group of units contain :"<<dt.u2<<" units";
		   cout<<"\nThird Group of units contains :"<<dt.u3<<" units";
		   cout<<"\nfirst Group of unit charges   :"<<dt.r1<<" rupees";
		   cout<<"\nSecond Group of unit charges  :"<<dt.r2<<" rupees";
		   cout<<"\nThird Group of unit charges   :"<<dt.r3<<" rupees";
		   cout<<"\nAll extra units charges       :"<<dt.r4<<" rupees";
		   break;

	case 3:cout<<"\nFirst Group of units contians  :"<<dt.u1<<" units";
		   cout<<"\nSecond Group of units contain  :"<<dt.u2<<" units";
		   cout<<"\nThird Group of units contains  :"<<dt.u3<<" units";
		   cout<<"\nFourth Group of units contain  :"<<dt.u4<<" units";
		   cout<<"\nfirst Group of unit charges    :"<<dt.r1<<" rupees";
		   cout<<"\nSecond Group of unit charges   :"<<dt.r2<<" rupees";
		   cout<<"\nThird Group of unit charges    :"<<dt.r3<<" rupees";
		   cout<<"\nfourth Group of unit charges   :"<<dt.r4<<" rupees";
		   cout<<"\nAll extra units charges        :"<<dt.r5<<" rupees";
		   break;

	case 4:cout<<"\nFirst Group of units contians  :"<<dt.u1<<" units";
		   cout<<"\nSecond Group of units contain  :"<<dt.u2<<" units";
		   cout<<"\nThird Group of units contains  :"<<dt.u3<<" units";
		   cout<<"\nFourth Group of units contain  :"<<dt.u4<<" units";
		   cout<<"\nFifth Group of units contains  :"<<dt.u5<<" units";
		   cout<<"\nfirst Group of unit charges    :"<<dt.r1<<" rupees";
		   cout<<"\nSecond Group of unit charges   :"<<dt.r2<<" rupees";
		   cout<<"\nThird Group of unit charges    :"<<dt.r3<<" rupees";
		   cout<<"\nfourth Group of unit charges   :"<<dt.r4<<" rupees";
		   cout<<"\nfifth Group of unit charges    :"<<dt.r5<<" rupees";
		   cout<<"\nAll extra units charges        :"<<dt.r6<<" rupees";
		   break;
	}

	cout<<"\n\nFix charge from user    :"<<dt.fix<<" rupees";
	cout<<"\nElectricity tax bill    :"<<dt.tax<< "%";
	cout<<"\nSubsidy/rebate per unit :"<<dt.sub<<" rupees\n";
	lines();
	cout<<"\nPress any KEY to continue...";
	getch();

}



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
//                     ask for password.
//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH

void billgen::password()
{
	char str[30];
	int count=0;
	clrscr();
	textcolor(GREEN);
	textbackground(BLUE);
	tag1:   //#########  tag1 4 below goto ##############
	cout<<endl;
	lines();
	cout<<"\nENTER PASSWORD:";
	cin.getline(str,30,'\n');
	cout<<endl;
	if(strcmp(dt.pass,str)==0)
	{

	clrscr();
	textbackground(LIGHTBLUE);
	gotoxy(10,6);
	textcolor(YELLOW);
	cout<<"********************";
	gotoxy(10,7);
	cout<<"LOADING YOUR PROJECT";
	gotoxy(10,8);
	cout<<"********************";
	gotoxy(10,10);
	cout<<"PLEASE WAIT.........";
	delay(500);
	gotoxy(10,12);
	cout<<"10 % completed..";
	delay(500);
	gotoxy(10,12);
	cout<<"20 % completed...";
	delay(500);
	gotoxy(10,12);
	cout<<"30 % completed....";
	delay(500);
	gotoxy(10,12);
	cout<<"40 % completed.....";
	delay(500);
	gotoxy(10,12);
	cout<<"50 % completed......";
	delay(500);
	gotoxy(10,12);
	cout<<"60 % completed.......";
	delay(500);
	gotoxy(10,12);
	cout<<"70 % completed........";
	delay(500);
	gotoxy(10,12);
	cout<<"80 % completed.........";
	delay(500);
	gotoxy(10,12);
	cout<<"90 % completed..........";
	delay(500);
	gotoxy(10,12);
	cout<<"100 % completed...........";
	delay(800);
	}
	else if(strcmp(dt.pass,str)!=0)
	{
	cout<<"\nINVALID PASSWORD !!!";
	count++;
	switch(count)
	{
		case 4:exit(-1);
		case 2:
		case 1:cout<<"\nDid you forgot password ???"
			  <<"\nFor SUPPORT & HELP WWW.HIMANSHUNEGI.IN :";
			  break;
		case 3:cout<<"\nWHAT ARE YOU TRYING TO DO ???"
				   <<"\nWITHOUT PASSWORD YOU CAN'T GET ACCESS TO PROGRAM.";
	}
	goto tag1;//preventing to access program without password
	}
	}


//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
//                   MAIN MENU FUNCTION defination
//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH

void billgen::menu()
{
	char ans='y';
	int opt;
	clrscr();
	textcolor(BLACK);
	textbackground(LIGHTGRAY);
	cout<<"\n\n\n\nPROGRAM MAIN MENU"
		<<"\n\n1> Generate Bill"
		<<"\n2> Program group settings"
		<<"\n3> Options"
		<<"\n4> Help me"
		<<"\n5> Credits"
		<<"\n6> Exit"
		<<"\n\nEnter your choice(1-6) :";
	cin>>opt;
	switch(opt)
	{
		case 1: cout<<"\n\nLoading your saved settings.........";
				while(ans=='y'||ans=='Y')
				{
					user();
					calcost();
					genbill();
					fsave();
					cout<<"\nDo you want to Generate more BILLS(y/n) :";
					cin>>ans;
				}
				break;

		case 2:groupsettings();
			   break;

		case 3:options();
			   break;

		case 4:help();
				break;

		case 5:credit();
			   break;

		case 6:exit(1);

		default:lines();
		cout<<"Function not available:";
	}
	menu();   // if invalid choice is entered it will call itself
}




//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
//               getting consumer info.
//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH

void billgen::user()
{

	clrscr();
	gotoxy(0,2);
	lines();
	gotoxy(10,4);
	cout<<"PERSONAL INFORMATION:";
	gotoxy(9,5);
	cout<<"________________________";
	gotoxy(3,8);
	cout<<"\n\nRegistration no  :";
	cin>>reg;
	cout<<"Name of consumer  :";
	gets(name);
	cout<<"Address of consumer :";
	gets(adr);
	cout<<"\nTotal units consumed :";
	cin>>unit;
	cout<<endl;
}


//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
//              calculate  main  cost  due  units  consumed
//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH

void billgen::calcost()
{

	switch(dt.choice)
	{
		case 0: if(unit<dt.u1)
				cost=unit*dt.r1;
				else
				cost=(dt.u1*dt.r1)+(unit-dt.u1)*dt.r2;
				break;

		case 1: if(unit<=dt.u1)
				cost=unit*dt.r1;
				else if(unit>dt.u1&&unit<=dt.u2)
				cost=(dt.u1*dt.r1)+(unit-dt.u1)*dt.r2;
				else
				cost=(dt.u1*dt.r1)+(dt.u2*dt.r2)+(unit-dt.u2)*dt.r3;
				break;

		case 2: if(unit<=dt.u1)
				cost=unit*dt.r1;
				else if(unit>dt.u1&&unit<=dt.u2)
				cost=(dt.u1*dt.r1)+(unit-dt.u1)*dt.r2;
				else if(unit>dt.u2&&unit<=dt.u3)
				cost=(dt.u1*dt.r1)+(dt.u2*dt.r2)+(unit-dt.u2)*dt.r3;
				else
				cost=(dt.u1*dt.r1)+(dt.u2*dt.r2)+(dt.u3*dt.r3)+(unit-dt.u3)*dt.r4;
				break;

		case 3: if(unit<=dt.u1)
				cost=unit*dt.r1;
				else if(unit>dt.u1&&unit<=dt.u2)
				cost=(dt.u1*dt.r1)+(unit-dt.u1)*dt.r2;
				else if(unit>dt.u2&&unit<=dt.u3)
				cost=(dt.u1*dt.r1)+(dt.u2*dt.r2)+(unit-dt.u2)*dt.r3;
				else if(unit>dt.u3&&unit<=dt.u4)
				cost=(dt.u1*dt.r1)+(dt.u2*dt.r2)+(dt.u3*dt.r3)+(unit-dt.u3)*dt.r4;
				else
				cost=(dt.u1*dt.r1)+(dt.u2*dt.r2)+(dt.u3*dt.r3)+(dt.u4*dt.r4)+(unit-dt.u4)*dt.r5;
				break;

		case 4: if(unit<=dt.u1)
				cost=unit*dt.r1;
				else if(unit>dt.u1&&unit<=dt.u2)
				cost=(dt.u1*dt.r1)+(unit-dt.u1)*dt.r2;
				else if(unit>dt.u2&&unit<=dt.u3)
				cost=(dt.u1*dt.r1)+(dt.u2*dt.r2)+(unit-dt.u2)*dt.r3;
				else if(unit>dt.u3&&unit<=dt.u4)
				cost=(dt.u1*dt.r1)+(dt.u2*dt.r2)+(dt.u3*dt.r3)+(unit-dt.u3)*dt.r4;
				else if(unit>dt.u4&&unit<=dt.u5)
				cost=(dt.u1*dt.r1)+(dt.u2*dt.r2)+(dt.u3*dt.r3)+(dt.u4*dt.r4)+(unit-dt.u4)*dt.r5;
				else
				cost=(dt.u1*dt.r1)+(dt.u2*dt.r2)+(dt.u3*dt.r3)+(dt.u4*dt.r4)+(dt.u5*dt.r5)+(unit-dt.u5)*dt.r6;
				break;
	}
}

//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
//        doing remaining calculations  ||  mainly generating BILLS
//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH

void billgen::genbill()
{
		clrscr();
		gotoxy(0,2);
		lines();
		cout<<"\n\t\t\t\t ELECTRYCITY  BILL GENERATED"
		<<"\n\t\t\t\t______________________________\n"
		<<"\n\tRegistration no      :"<<reg
		<<"\n\tConsumer name        :"<<name
		<<"\n\tAddress of cosumer   :"<<adr
		<<"\n\tTotal consumed units :"<<unit
		<<"\n\tConsumed units cost  :"<<cost<<" Rs."
		<<"\n\tfix charge           :"<<dt.fix<<" Rs.";
		ttax=(dt.tax*cost*0.01); //**** (0.01=1/100)
		cout<<"\n\tElectricity total tax:"<<ttax<<" Rs.";
		tsub=dt.sub*unit;
		cout<<"\n\tTotal subsidy/rebate :"<<tsub<<" Rs.\n";
		lines();
		bill=cost+dt.fix+(dt.tax*cost*0.01)-(dt.sub*unit);
		cout<<"\n\tTOTAL PAYABLE AMOUNT :"<<bill<<" Rs.\n";
		lines();
		lines();
}

//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
//                 SAVING BILLS to files
//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH

void billgen::fsave()
{
		char ans;
		cout<<"\nsave this bill(y/n)? :";
		cin>>ans;
		if(ans=='y'||ans=='Y')
		{
		file.open("bills.txt",ios::out|ios::app);
		file.write((char*)&hi,sizeof(hi));
		cout<<"\nBill saved.......";
		file.close();
		}
}


//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
//                       SEARCHING RECORDS AND DISPLAYING (in files)
//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH

void billgen::fsearch()
{
	int sreg;
	char found='n';
	cout<<"\nEnter the registration no. to be search:";
	cin>>sreg;
	cout<<endl;
	lines();
	cout<<"\nSEARCHING RESULT:\n";
	file.open("bills.txt",ios::in);
	file.seekg(0);
	while(file)
	{
		file.read((char *)&hi,sizeof(hi));
		if(hi.reg==sreg)
		{
			hi.genbill();
			cout<<"\nPress any key to continue....";
			getch();
			found='y';
			break;
		}
	}
	if(found=='n')
	cout<<"The registration number doesn't exist.";
	file.close();

}

//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
//                 FUNCTION TO DELETE BILLS
//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH

void billgen::del()
{

	file.open("bills.txt",ios::in|ios::out);
	int sreg;
	char found='n';
	cout<<"\nEnter the registration no. to be deleted:";
	cin>>sreg;
	file.seekg(0);
	while(!file.eof())
	{
		file.read((char *)&hi,sizeof(hi));
		if(hi.reg==sreg)
		{
			hi.genbill();
			found='y';
			break;
		}
	}
	if(found=='n')
	cout<<"The registration number doesn't exist.";
	if(found=='y')
	file.seekp(-sizeof(hi),ios::cur);
				  reg=00;
				  file.write((char*)&hi,sizeof(hi));
	file.close();


}
//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
//                      function modifying bill
//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH

void billgen::modify()
{
	int sreg;
	cout<<"\nEnter the registration no. to be modify:";
	cin>>sreg;
	file.seekg(0);
	file.open("bills.txt",ios::in|ios::out);
	while(file)
	{
	file.read((char*)&hi,sizeof(hi));
	if(hi.reg==sreg)
	{
	clrscr();
	char ko;
	cout<<"Current bill is:\n\n";
	hi.genbill();
	cout<<"Do changes(y/n)?";
	cin>>ko;
	if(ko=='y'||ko=='Y')
	{
	user();
	calcost();
	clrscr();
	cout<<"\nNow the bill changed as:\n";
	genbill();
	file.seekp(-sizeof(hi),ios::cur);
	file.write((char*)&hi,sizeof(hi));
	file.close();
	cout<<"\nprocess complete...";
}}}}

//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
//      function to customize the the programm setings
//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
void billgen::groupsettings()
{
	textcolor(BLACK);
	textbackground(LIGHTGRAY);
	cout<<"\n\n\nCREATE UNIT(noted readings) GROUPS : "
		<<"\n\n0> One group only."
		<<"\n1> Two groups only."
		<<"\n2> Three groups only."
		<<"\n3> Four groups only."
		<<"\n4> Five groups only."
		<<"\n5> Jump back to MAIN MENU."
		<<"\n\nEnter your choice(0 to 5):";
	cin>>dt.choice;
	switch(dt.choice)
	{
		case 0:fun0();
			   cout<<"\nNow enter charges for remainig units:";
			   cin>>dt.r2;
			   break;

		case 1:fun0();
			   fun1();
			   cout<<"\nNow enter charges for remainig units:";
			   cin>>dt.r3;
			   break;

	   case 2:fun0();
			   fun1();
			   fun2();
			   cout<<"\nNow enter charges for remainig units:";
			   cin>>dt.r4;
			   break;

	   case 3:fun0();
			   fun1();
			   fun2();
			   fun3();
			   cout<<"\nNow enter charges for remainig units:";
			   cin>>dt.r5;
			   break;

	   case 4:fun0();
			   fun1();
			   fun2();
			   fun3();
			   fun4();
			   cout<<"\nNow enter charges for remainig units:";
			   cin>>dt.r6;
			   break;

		case 5:menu();
				break;

	   default: cout<<endl;
				lines();
				cout<<"SORRY ! function not supported !!!";
				groupsettings();
	}
	cout<<"\nEnter the fixed charge from consumer:";
	cin>>dt.fix;
	cout<<"\nEnter the electricity tax in PERCENT(%):";
	cin>>dt.tax;
	cout<<"\nEnter subsidy per unit in Rs(if any,otherwise enter 0):";
	cin>>dt.sub;
	file.open("data.txt",ios::out);
	if(file)
	{
		file.write((char*)&dt,sizeof(dt));
		cout<<"\nsaving process complete.\n";
		file.close();
	}
	if(!file)
	cout<<"\nsomething went wrong !process Aborting......";
}




//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
//              all function below are part of settings function
//                 that can change variables default values
//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
	void billgen::fun0()
	{
		cout<<"Enter no. of units in group first and charge per unit in Rs:";
			   cin>>dt.u1>>dt.r1;

	}
	void billgen::fun1()
	{	cout<<"Enter no. of units in group second and charge per unit in Rs:";
			   cin>>dt.u2>>dt.r2;

	}
	void billgen::fun2()
	{	cout<<"Enter no. of units in group third and charge per unit in Rs:";
			   cin>>dt.u3>>dt.r3;


	}
	void billgen::fun3()
	{	cout<<"Enter no. of units in group fourth and charge per unit in Rs:";
			   cin>>dt.u4>>dt.r4;


	}
	void billgen::fun4()
	{	cout<<"Enter no. of units in group fifth and charge per unit in Rs:";
			   cin>>dt.u5>>dt.r5;

	}


//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
//                     draws horizontal lines
//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH

void billgen::lines()
{

	for(int i=0;i<80;i++)
	{	delay(15);
		cout<<dt.sym;
	}
}

//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
//              function made to change the horizontal line design
//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
void billgen::changelines()
{
	cout<<"\nPress any key to used to draw lines:";
	cin>>dt.sym;
	cout<<"\ndone!\n";
	options();
}



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
//                      showing help
//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH

void billgen::help()
{

	cout<<"\nELECTRICITY BILL GENERATOR \n______________________________\nis a user friendly program !"
		<<"\nGenerate bill:\nThis option generate bill with previously saved values."
		<<"\n\nChange User Group:"
		<<"\nIt is SUGGESTED you that before generating bill first time"
		<<"\nGo to setting then cutomize the program values your accordingly"
		<<"\n otherwise the program will run with default values"
		<<"\nwhen you chose setting option it will then ask to create UNITS group(s),"
		<<" it is  nothing but the no. of fixed units which are charged with certain cost.\n"
		<<"\n\nFOR EXAMPLE:Suppose first 200 units are charged with Rs.2.45 and "
		<<"then all remaining units are charged at the rate of 2 Rs. per unit\n"
		<<"then you need only one group for fist fixed 200 units ,hence press 0 to select, "
		<<"Similarly you may need 3,4 or even 5 groups, enter your choice correctly."
		<<"PRESS ANY KEY....";
		getch();

	   cout<<"\n\nOptions:\nOptions contain all necessary options to cutomize program."
		<<"\n\nSearch Bill:\nIt can search bill with specific bill using registration no."
		<<"\n\nModify Bill:\nIt can modify existing bill"
		<<"\n\nChange line design:\nIt can temporaraly change horizontal line design."
		<<"\n\nExit:\nTo close the program.\n"
		<<"\nIf the program show abnormal behaviour goto 'options' and choose 'default settings\n";
		lines();
		cout<<"The program is in accordance to NDPL(North Delhi Power Limited) for domestic"
		<<"\nyou will gain experience as you work with me:\n";
		lines();
	cout<<"\n DELHI COSUMERS CAN DIRECTLY GENERATE THEIR ELECTRICITY BILLS:";
	cout<<"PRESS ANY KEY.....";
	getch();
}

//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
//             special   function
//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH

void billgen::credit()
{
			cout<<endl;
			lines();
			cout<<"\n\n 23 Nov 2010\n";
			lines();
			cout<<"\nProject name   :Bill-gen";
			cout<<"\nCreated by     :Himanshu Negi";
			cout<<"\nUploaded at    :himanshunegi.in";
			cout<<"\n\nSubject teacher:Mr.Mantosh Kumar.\n";
			char ca;
			cout<<"\n\nDo you want to see our LOGO(y/n):";
			cin>>ca;
			if(ca=='y'||ca=='Y')
			{
				textcolor(LIGHTGREEN);
				textbackground(BLACK);
				cout<<endl;
				cout<<"      HHH     HHH       NNNN   NNN  "<<endl;
				cout<<"      HHHHHHHHHHH       NNN N  NN "<<endl;
				cout<<"      HHH     HHH       NNN  NNNN"<<endl;
			 }
			cout<<endl;endl;
			cout<<"\n\nPress any key to continue....";
			getch();

}



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
//                       OPTIONS
//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH

void billgen::options()
{
	cout<<endl;
	lines();
	int temp;
	char ans;
	cout<<"\n\n OPTIONS:\n"
		<<"\n1> Search Bill."
		<<"\n2> Delete Bill."
		<<"\n3> Modify bill."
		<<"\n4> Restore program default settings."
		<<"\n5> Delete all saved Bills."
		<<"\n6> change the horizontal line design."
		<<"\n7> Back to main menu."
		<<"\n\nEnter your choice(1 to 7):";
	cin>>temp;
	switch(temp)
	{   case 5:cout<<"\nAre you sure you wants to delete all saved BILLS(y/n)?";
			   cin>>ans;
			   if(ans=='y'||ans=='Y')
			   remove("bills.txt");
			   break;


		case 4:cout<<"\nAre you sure you wants to delete all saved settings(y/n)?";
			   cin>>ans;
			   if(ans=='y'||ans=='Y')
			   remove("data.txt");
			   break;

		case 6:changelines();
			  break;

		case 7:menu();
			  break;

		case 1:fsearch();
			  break;

		case 2:del();
			  break;
		case 3:modify();
		break;

		default:cout<<endl;
				lines();
			   cout<<"\nOptions not Available !";
			   options();
		}
		}

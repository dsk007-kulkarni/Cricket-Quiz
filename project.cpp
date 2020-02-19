//"MINI PROJECT"
//Quiz for Cricket fans.
//DNYANESH KULKARNI(21333)
//SANKET LANDGE(21336)
//DHRUV KANEKAL(21327)
#include<bits/stdc++.h>
#include<fstream>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
using namespace std;
class stack1;
class dcll;
class node{
	public:
	node *prev;
	node *next;
	string a,b,c,d,e,f;
	node(string s,string s1,string s2,string s3,string s4)
	{
		a=s;
		b=s1;
		c=s2;
		d=s3;
		e=s4;
		prev=next=NULL;
		
	}
	node(string s)
	{
		f=s;
		next=NULL;
	}
	friend class dcll;
	friend class stack1;
};
class stack1
{
	public:
	node*top;
	int score1;
	stack1()
	{
		top=NULL;
		score1=0;
	}
	int score(string choice);
	void refill(string arr[],int j);
	void push();
	string pop();
	friend class dcll;
};
class dcll
{
public:
	node *head;
	int arr[20];
	int i,count1,count2;
	dcll()
	{
			head=NULL;
			arr[20]={0};
			count2=count1=i=0;
	}
	void addquestion();
	void display();
	void solveQue(stack1);
	int count();
};
string stack1::pop()
	{
		string x;node*p;
			x=top->next->f;
			p=top;
			top=top->next;
			delete p;
			//cout<<"poped element is"<<x<<endl;
			return x;
	}
void stack1::push()
{
		node*p;
		fstream obj;
		obj.open("QUIZ-SOL.txt",ios::in | ios::out);
		while(!obj.eof()){
		char x[100];
		obj.getline(x,100);
		p=new node(x);
		p->next=top;
		top=p;
		}
	}
int stack1::score(string choice)
{
	string str=pop();
	score1=0;
	Sleep(1000);
		if(str==choice)
		{
			score1+=2;
			cout<<"Your score for this question is:\t"<<score1<<endl;
			Sleep(2000);
			return 1;
		}
		else if(choice=="-1")
		{
			cout<<"You have not attempted this question."<<endl;
			cout<<"Your score for this question is:\t"<<score1<<endl;
			Sleep(2000);
			return -1;
		}
		else
		{
			
			cout<<"Oops! Wrong answer!"<<endl;
			cout<<"Your score for this question is:\t"<<score1-1<<endl;
			score1-=1;
			Sleep(2000);
			return 0;
		}
}
int dcll::count()
{
	int count=0;
	node*p=head;
	do{
		count++;
		p=p->next;
	}while(p!=head);
	return count;
}
void dcll::solveQue(stack1 obj1)
{
	int x,i=1;
	x=count();
	node*p=head;
	string choice;
	while(x>0)
		{
		cout<<endl<<p->a<<endl;
		cout<<p->b<<"  ";
		cout<<p->c<<endl;
		cout<<p->d<<"  ";
		cout<<p->e<<endl;
		cout<<"Enter your answer:- \n";
		cin.ignore(i);
		getline(cin,choice);
		int e=obj1.score(choice);
		if(e==1)
		{
			count1++;
		}
		if(e!=-1)
		{
			count2++;
		}
		x--;
		p=p->next;
		i=0;
		system("CLS");
		
	}
	}


void dcll::display()
{
	node*p=head;
	do
	{
		cout<<p->a<<endl;
		cout<<p->b<<"  ";
		cout<<p->c<<endl;
		cout<<p->d<<"  ";
		cout<<p->e<<endl;
		p=p->next;
		cout<<endl;
	}while(p!=head);
}
void dcll::addquestion()
{
	int n;
	fstream obj;
	char que[100],o1[100],o2[100],o3[100],o4[100];
	obj.open("QUIZ.txt",ios::in | ios::out);
	while(!obj.eof())
	{
	node*p;
	obj.getline(que,100);
	obj.getline(o1,100);
	obj.getline(o2,100);
	obj.getline(o3,100);
	obj.getline(o4,100);
	if(head==NULL)
	{
		head=new node(que,o1,o2,o3,o4);
		p=head;
		p->next=head;
		p->prev=head;
	}
	else
	{
		p->next=new node(que,o1,o2,o3,o4);
		p->next->prev=p;
		p=p->next;
		p->next=head;
		head->prev=p;
	}
}
}
int main()
{
	int n,ch,r;
	string str;
	dcll obj;
	stack1 obj1;
	obj.addquestion();
	obj1.push();
	system("COLOR 9");
	cout<<"**** INSTRUCTIONS ****"<<endl;
	cout<<"THERE ARE 21 QUESTIONS IN THIS QUIZ CONTEST"<<endl;
	cout<<"MARKING SCHEME:-\t+2 -1"<<endl;
	cout<<"Enter -1 as answer to skip the question."<<endl;
	cout<<"YOU CAN SOLVE ANY QUESTION OUT OF 21 QUESTIONS"<<endl;
	cout<<"YOU ARE ONLY ALLOWED TO ATTEMPT IT ONCE"<<endl;
	label:cout<<"ENTER PASSWORD TO START:-"<<endl;
	getline(cin,str);
	if(str=="123456")
	{
		Sleep(2000);
		cout<<endl<<endl;
		cout<<"Logged in successfully....";
		Sleep(3000);
		system("CLS");
		label2:cout<<"Enter 1 for displaying all Questions."<<endl;
		cout<<"Enter 2 for solving a Question Directly."<<endl;
		cout<<"Enter a choice:- "<<endl;
		cin>>ch;
		system("COLOR F");
		switch(ch)
		{
			case 1:obj.display();
				cout<<"Press any key to continue";
				getch();
				system("CLS");
			case 2:
				system("CLS");
				obj.solveQue(obj1);
				break;
			default: cout<<"Please enter valid choice."<<endl;
					goto label2;
		}
		system("CLS");
	/* for(int i=1;i<=100;i++){
        //fontcolor("yellow");
        cout<<i<<"%";
        //Sleep(50);
        system("cls");
     }*/
     system("COLOR C");
    cout<<"LOADING YOUR RESULT ..."<<endl;
    for(int i=0;i<=100;i++){
        printf("%c",219);
        Sleep(50);
    }
	Sleep(2000);
	system("CLS");
	system("COLOR A");
	cout<<"TOTAL ATTEMPTED QUESTIONS:-\t"<<obj.count2<<endl;
	cout<<"CORRECT ANSWERS:-\t"<<obj.count1<<endl;
	cout<<"YOUR FINAL SCORE IS:-\t"<<obj.count1*2-(obj.count2-obj.count1)<<endl;
	cout<<"**** THANK YOU FOR PLAYING ****"<<endl;
	return 0;
	}
	else
	{
		system("COLOR 4");
		cout<<"Please enter a correct password."<<endl;
		Sleep(1000);
		system("COLOR 9");
		system("CLS");
		goto label;
	}
}


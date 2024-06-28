
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
struct data
{
	char name[20],cnic[20],role[20],address[30];
	int day,month,year,age;
}d[100];
struct datau
{
	char nameu[20],cnicu[20],roleu[20],addressu[30];
	int dayu,monthu,yearu,ageu;
}du[100];

struct feedback
{
	char food[10],experience[10],behaviour[10],thing[10],name[10];
	int ratings;
}fb[100];
struct tablesM
{
	int capacity;
	char occupation[100],table[100];
}tm[100];

void breakprint(int);
void lunchprint(int);
void dinnerprint(int);

void addemployee()
{
	FILE *admin,*adminu;
	admin= fopen("employee.txt", "a");
				int noe,i,var;
				printf("===>>Enter the number of employees:");
				scanf("%d",&noe);
				for (i=0;i<noe;i++)
				{
					printf("\n=================Data of the employee:%d=================\n",i+1);
					printf("Name:");
					scanf("%s",&d[i].name);
					printf("Age:");
					scanf(" %d",&d[i].age);
					printf("Day of birth:");
					scanf(" %d",&d[i].day);
					printf("Month of birth:");
					scanf(" %d",&d[i].month);
					printf("Year of birth:");
					scanf(" %d",&d[i].year);
					printf("CNIC Number:");
					scanf("%s",&d[i].cnic);
					printf("Address:");
					scanf("%s",&d[i].address);
					printf("Role:");
					scanf("%s",&d[i].role);
					if(admin==NULL)
					{
						printf("Error!");
					}
					else 
					{
						fputs(d[i].name,admin);
						fputs(" ",admin);
						fprintf(admin,"%d",d[i].age);
					    fputs(" ",admin);
						fprintf(admin,"%d",d[i].day);
						fputs(" ",admin);
						fprintf(admin,"%d",d[i].month);
						fputs(" ",admin);
						fprintf(admin,"%d",d[i].year);
						fputs(" ",admin);
						fputs(d[i].cnic,admin);
						fputs(" ",admin);
						fputs(d[i].address,admin);
						fputs(" ",admin);
						fputs(d[i].role,admin);
						fputs(" ",admin);				
						fputs("\n",admin);
			
						printf("\n=================DATA Written Successfully!!=================");
						
					}
				}
					fclose(admin);
					printf("\n\nEnter (0) To Back In Admin Portal:");
					scanf("%d",&var);
					if(var==0)
					{
						system("cls");
					}
}
void updateemployee()
{
				FILE *admin,*adminu;
				FILE *managment;
				int i,var;
				char nameU[100];
					admin=fopen("employee.txt","r");
					printf("Which record do you want to change?(You can only enter the name of the employee):");
					scanf("%s",&nameU);
					if(admin==NULL)
					{
						printf("Error");
					}
					else 
					{
					
					for(i=0;!feof(admin);i++)
					{
						
						fscanf(admin,"%s",&d[i].name);
						
						fscanf(admin,"%d",&d[i].age);
						
						fscanf(admin,"%d",&d[i].day);
						
						fscanf(admin,"%d",&d[i].month);
						
						fscanf(admin,"%d",&d[i].year);
						
						fscanf(admin,"%s",&d[i].cnic);
						
						fscanf(admin,"%s",&d[i].address);
						
						fscanf(admin,"%s",&d[i].role);
	
						if (strcmp(d[i].name,nameU)==0)
						{
							
							printf("\n========Your entered name has been found!=========\n");
							adminu=fopen("update.txt","a");
							for(i=0;i<1;i++)
							{
							printf("New Name:");
							scanf("%s",&du[i].nameu);
							printf("New Age:");
							scanf("%d",&du[i].ageu);
							printf("New Day of birth:");
							scanf("%d",&du[i].dayu);
							printf("New Month of birth:");
							scanf("%d",&du[i].monthu);
							printf("New Year of birth:");
							scanf("%d",&du[i].yearu);
							printf("New CNIC Number:");
							scanf("%s",&du[i].cnicu);
							printf("New Address:");
							scanf("%s",&du[i].addressu);
							printf("New Role:");
							scanf("%s",&du[i].roleu);

							fputs(du[i].nameu,adminu);
							fputs(" ",adminu);
							
							fprintf(adminu,"%d",du[i].ageu);
							fputs(" ",adminu);
							
							fprintf(adminu,"%d",du[i].dayu);
							fputs(" ",adminu);
							
							fprintf(adminu,"%d",du[i].monthu);
							fputs(" ",adminu);
							
							fprintf(adminu,"%d",du[i].yearu);
							fputs(" ",adminu);
							
							fputs(du[i].cnicu,adminu);
							fputs(" ",adminu);
							
							fputs(du[i].addressu,adminu);
							fputs(" ",adminu);
							
							fputs(du[i].roleu,adminu);
							fputs(" ",adminu);			
									
							fputs("\n",adminu);
							printf("\n=================DATA UPDATED SUCCESSFULLY=================");
							}
							fclose(adminu);
						}
						else 
						{
							adminu=fopen("update.txt","a");
							
								fputs(d[i].name,adminu);
								fputs(" ",adminu);
								fprintf(adminu,"%d",d[i].age);
								fputs(" ",adminu);
								fprintf(adminu,"%d",d[i].day);
								fputs(" ",adminu);
								fprintf(adminu,"%d",d[i].month);
								fputs(" ",adminu);
								fprintf(adminu,"%d",d[i].year);
								fputs(" ",adminu);
								fputs(d[i].cnic,adminu);
								fputs(" ",adminu);
								fputs(d[i].address,adminu);
								fputs(" ",adminu);
								fputs(d[i].role,adminu);
								fputs(" ",adminu);
								
								fputs("\n",adminu);
							fclose(adminu);
						}
					}
					fclose(admin);
					remove("employee.txt");
					rename("update.txt","employee.txt");
					printf("\n\nEnter (0) To Back In Admin Portal:");
					scanf("%d",&var);
					if(var==0)
					{
						system("cls");
					}
				}
}
void deleteemployee()
{
	char delemp[10];
	FILE *admin,*adminu;
	int i,var;
	printf("\n---------------------Deleting The Data Of Employee---------------------\n");
	printf("Enter Name Of Employee:");
	scanf("%s",&delemp);
	admin=fopen("employee.txt","r");
	if(admin==NULL)
	{
		printf("Error");
	}
	else 
	{
		for(i=0;!feof(admin);i++)
		{
			fscanf(admin,"%s",&d[i].name);
							
			fscanf(admin,"%d",&d[i].age);
							
			fscanf(admin,"%d",&d[i].day);
							
			fscanf(admin,"%d",&d[i].month);
							
			fscanf(admin,"%d",&d[i].year);
							
			fscanf(admin,"%s",&d[i].cnic);
							
			fscanf(admin,"%s",&d[i].address);
							
			fscanf(admin,"%s",&d[i].role);
							
			if (strcmp(d[i].name,delemp)==0)
			{
				continue;
			}
			else 
			{
				adminu=fopen("delete.txt","a");
								
				fputs(d[i].name,adminu);
				fputs(" ",adminu);
				fprintf(adminu,"%d",d[i].age);
				fputs(" ",adminu);
				fprintf(adminu,"%d",d[i].day);
				fputs(" ",adminu);
				fprintf(adminu,"%d",d[i].month);
				fputs(" ",adminu);
				fprintf(adminu,"%d",d[i].year);
				fputs(" ",adminu);
				fputs(d[i].cnic,adminu);
				fputs(" ",adminu);
				fputs(d[i].address,adminu);
				fputs(" ",adminu);
				fputs(d[i].role,adminu);
				fputs(" ",adminu);				
									
				fputs("\n",adminu);
				fclose(adminu);
			}
		}
		printf("\n----------------Data Deleted Successfully!!----------------");
	}
	fclose(admin);
	remove("employee.txt");
	rename("delete.txt","employee.txt");
	printf("\n\nEnter (0) To Back In Admin Portal:");
	scanf("%d",&var);
	if(var==0)
	{
		system("cls");
	}
}
void searchemployee()
{
	FILE *admin;
	int i,var;    char namech[10];
	printf("\n---------------------Finding Data Of Employee---------------------\n");
	printf("Enter Employee Name:");
	scanf("%s",&namech);
	admin=fopen("employee.txt","r");
	if(admin==NULL)
	{
		printf("Error");
	}
	else 
	{
		for(i=0;!feof(admin);i++)
		{
			fscanf(admin,"%s",&d[i].name);
							
			fscanf(admin,"%d",&d[i].age);
							
			fscanf(admin,"%d",&d[i].day);
							
			fscanf(admin,"%d",&d[i].month);
							
			fscanf(admin,"%d",&d[i].year);
							
			fscanf(admin,"%s",&d[i].cnic);
							
			fscanf(admin,"%s",&d[i].address);
							
			fscanf(admin,"%s",&d[i].role);
							
			if (strcmp(d[i].name,namech)==0)
			{		
				printf("\n-----Your entered name has been found!-----\n");
				printf("\nName:%s",d[i].name);
				printf("\nAge:%d",d[i].age);
				printf("\nDay of birth:%d",d[i].day);
				printf("\nMonth Of Birth:%d",d[i].month);
				printf("\nYear of birth:%d",d[i].year);
				printf("\nCNIC:%s",d[i].cnic);
				printf("\nAddress:%s",d[i].address);
				printf("\nRole:%s",d[i].role);
			}
				else continue;	
		}
			fclose(admin);
		printf("\n\nEnter (0) To Back In Admin Portal:");
		scanf("%d",&var);
		if(var==0)
		{
			system("cls");
		}
	}
}
void menu()
{
	int i,mch,sum=0,noo,var2;
	int lch,nool;
	int dch,nood;
	char menu;
	SYSTEMTIME t; 

    GetLocalTime(&t); 
     

    printf("%d/%d/%d, Time: %d:%d:%d", t.wDay, t.wMonth, t.wYear, t.wHour, t.wMinute, t.wSecond); 

	int fast[5] = {250,50,300,200,150};
	int lunch[5]= {500,1000,700,600,1500};
	int dinner[5]= {600,700,1800,900,300};

			if ((t.wHour>=6 && t.wHour<=11) &&(t.wMinute>=0 && t.wMinute<=59))
			{
			
			printf("\n		===================Menu for Breakfast===================\n");
			printf("\n				1.Fresh Fruits Sessional=RS 250");
			printf("\n				2.Omelate Muffin/Half Fry=RS 50");
			printf("\n				3.Honey+Butter+Cheese=RS 300");
			printf("\n				4.HOT Cakes=RS 200");
			printf("\n				5.Tea/Cofee=RS 150");
			
			printf("\n\nEnter Number Of Items You Want To Order:");
			scanf("%d",&noo);
			for(i=0;i<noo;i++)
			{
				printf("Enter Choice From The Menu:");
				scanf("%d",&mch);
				breakprint(mch);
				sum+=fast[mch-1];
			}
			printf("\n			=====Your Bill is:RS %d======",sum);
			printf("\n\n==================Thank You So Much!!Please Come Again!!==================\n");

		}
			else if ((t.wHour>=12 && t.wHour<=17) &&(t.wMinute>=0 && t.wMinute<=59))
			{
			printf("\n		===================Menu for Lunch===================\n");
			printf("\n				1.Chicken Karahi=RS 500");
			printf("\n				2.Beef Steak=RS 1000");
			printf("\n				3.Beef Karahi=RS 700");
			printf("\n				4.Chinese Fried Rice=RS 600");
			printf("\n				5.Chicken Biryani=RS 300");
			
			printf("\n\nEnter Number Of Items You Want To Order:");
			scanf("%d",&nool);
			for(i=0;i<nool;i++)
			{
				printf("Enter Choice From The Menu:");
				scanf("%d",&lch);
				lunchprint(lch);
				sum+=lunch[lch-1];
			}
			printf("\n			=====Your Bill is:RS %d======",sum);
			printf("\n\n==================Thank You So Much!!Please Come Again!!==================\n");

			}
			else if ((t.wHour>=18 && t.wHour<=23) &&(t.wMinute>=0 && t.wMinute<=59))
			{
			printf("\n		===================Menu for Dinner===================\n");
			printf("\n				1.Chicken Karahi=RS 600");
			printf("\n				2.Fish and Chips=RS 700");
			printf("\n				3.Golden Steak Sandwich=RS 1800");
			printf("\n				4.Beef Karahi=RS 900");
			printf("\n				5.Vegetable Rice=RS 300");
			
			printf("\n\nEnter Number Of Items You Want To Order:");
			scanf("%d",&nood);
			for(i=0;i<nood;i++)
			{
				printf("Enter Choice From The Menu:");
				scanf("%d",&dch);
				dinnerprint(dch);
				sum+=lunch[dch-1];
			}
			printf("\n			=====Your Bill is:RS %d======",sum);
			printf("\n\n==================Thank You So Much!!Please Come Again!!==================\n");
			}
			printf("\n\nEnter (0) To Back In Management Portal:");
			scanf("%d",&var2);
			if(var2==0)
			{
				system("cls");
			}
}
		
void breakprint(int mch)
{
	if((mch-1)==0)
	{
		printf("\n			======Fresh Fruits is booked ======\n");
	}
	else if((mch-1)==1)
	{
		printf("\n			======Omelate Muffin/Half Fry is booked ======\n");
	}
	else if((mch-1)==2)
	{
		printf("\n			======Honey+Butter+Cheese is booked======\n");
	}
	else if((mch-1)==3)
	{
		printf("\n			======Cakes is booked======\n");
	}
	else if((mch-1)==4)
	{
		printf("\n			======Tea / Cofee booked ======\n");
	}
}
void lunchprint(int lch)
{
	if((lch-1)==0)
	{
		printf("\n			======Chicken Karahi Is Booked======\n");
	}
	else if((lch-1)==1)
	{
		printf("\n			======Beef Steak Is Booked======\n");
	}
	else if((lch-1)==2)
	{
		printf("\n			======Beef Karahi Is Booked======\n");
	}
	else if((lch-1)==3)
	{
			printf("\n			======Chinese Fried Rice Is Booked======\n");
	}
	else if((lch-1)==4)
	{
		printf("\n			======Chicken Biryani Is Booked======\n");
	}
}
void dinnerprint(int dch)
{
	if((dch-1)==0)
	{
		printf("\n			======Chicken Karahi Is Booked======\n");
	}
	else if((dch-1)==1)
	{
		printf("\n			======Fish And Chips Is Booked======\n");
	}
	else if((dch-1)==2)
	{
		printf("\n			======Golden Steak Sandwich is Booked======\n");
	}
	else if((dch-1)==3)
	{
		printf("\n			======Beef Karahi is Booked======\n");
	}
	else if((dch-1)==4)
	{
		printf("\n			======Vegetable Rice Is Booked======\n");
	}
}
void tablemanagment()
{
	FILE*table;
	int n,i,var2;
	char occ1[]="empty";
	char occ2[]="occupied";
	char occ[100];
	int res;
	table=fopen("Table_Managmemt.txt","w");
	printf("\n======>Enter the number of tables:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter the name of Table of table %d (for e.g table1 for first table):",i+1);
		scanf("%s",&tm[i].table);
		printf("Enter the capacity of Table %d:",i+1);
		scanf("%d",&tm[i].capacity);
		printf("Enter the occupation of Table %d:",i+1);
		scanf(" %s",&tm[i].occupation);
	}
	if (table==NULL)
	{
		printf("\n===========Error!=============\n");
	}
	else
	{
		printf("\n=========The file is opened=======\n");
		for(i=0;i<n;i++)
		{

		fprintf(table,"%s ",tm[i].table);

		fprintf(table,"%d",tm[i].capacity);
		
		fprintf(table," %s\n",tm[i].occupation);
	}
	}

	fclose(table);
	table=fopen("Table_Managmemt.txt","r");
	fseek(table,0,SEEK_SET);
	FILE*wl;
	int people;
	printf("\nEnter the number of people:");
	scanf(" %d",&people);
	wl=fopen("Waiting_List.txt","w");
    for(i=0;!feof(table);i++)
    {
    	fscanf(table,"%s ",&tm[i].table);
    	fscanf(table,"%d",&tm[i].capacity);
    	fscanf(table," %s\n",&tm[i].occupation);

	if(people==tm[i].capacity)
	{
		if (strcmp(occ1,tm[i].occupation)==0)
		{
				printf("\n======Table%d is availible=======\n",i+1);
				printf("\nEnter New Occupation Of Table(i.e:occupied):");
				scanf("%s",&occ);
				fputs(tm[i].table,wl);
				fputs(" ",wl);
				fprintf(wl,"%d",tm[i].capacity);
				fputs(" ",wl);
				fputs(occ,wl);
				
			fputs("\n",wl);
		}
		else
		{
				fputs(tm[i].table,wl);
				fputs(" ",wl);
				fprintf(wl,"%d",tm[i].capacity);
				fputs(" ",wl);
				fputs(tm[i].occupation,wl);
				
			fputs("\n",wl);
		}
	}
	else if(people<tm[i].capacity)
	{
	
		if (strcmp(occ1,tm[i].occupation)==0)
		{
			printf("\n======Sorry there no table which matches your capacity=======\n");
			printf("\n======Table%d is availible with a greater capacity then your need=======\n",i+1);
			printf("\n======Enter (1) if you want to reserve the table and enter (0) to exit=======\n");
			scanf("%d",&res);
			switch(res)
			{
				case 0: 
					break;
				break;
				case 1:
					printf("\nEnter New Occupation Of Table:(i.e:occupied)");
					scanf("%s",&occ);
					fputs(tm[i].table,wl);
					fputs(" ",wl);
					fprintf(wl,"%d",tm[i].capacity);
					fputs(" ",wl);
					fputs(occ,wl);
					
					fputs("\n",wl);
				break;
				
			}
		}
	}
	else
		{
			
			printf("\n======Sorry! None of the table are availible=======\n");
			fprintf(wl,"%s",tm[i].table);
			fputs(" ",wl);
			fprintf(wl,"%d",tm[i].capacity);
			fputs(" ",wl);				
			fputs(tm[i].occupation,wl);
	 
			fputs("\n",wl);
		}
	}
	fclose(table);
	fclose(wl);
	printf("\n\nEnter (0) To Back In Management Portal:");
	scanf("%d",&var2);
	if(var2==0)
	{
		system("cls");
	}
}

void feedback()
{
	FILE *feed;
	int i,fch,nof,var2;
	printf("\n=============================Thank you!! Please Give Your Feedback It will help us to Improve!!!!=============================\n");
	printf("Select From The Following:\n");
	printf("				=================================\n");
	printf("					1.Write Feedback\n					2.Read Feedbacks\n					3.Exit\n");
	printf("				=================================\n");
	while(fch!=3)
	{
	printf("\n======>>Enter Choice In Feedback Portal:");
	scanf("%d",&fch);
	switch(fch)
	{
		case 1:
		feed=fopen("feedback.txt","a");
		for(i=0;i<1;i++)
		{
			printf("\nYou May Answer From following:\n1.Excellent		2.Good		3.Fair		4.Bad		5.Worse\n\n");
			printf("Customer Name:\t");
			scanf("%s",&fb[i].name);
			printf("How was The Food?\t");
			scanf(" %s",&fb[i].food);
			printf("How Was The behaviour Of Staff?\t");
			scanf(" %s",&fb[i].behaviour);
			printf("How Was Your Experience At Restaurant?\t");
			scanf("%s",&fb[i].experience);
			printf("Which Things We Should Improve?\t");
			scanf(" %s",&fb[i].thing);
			printf("Rate our Restaurant Out Of 10!!\t");
			scanf("%d",&fb[i].ratings);
			printf("\n============================Feedback Written Successfully!!============================\n");
			
			fputs("\n",feed);
			fputs(fb[i].name,feed);
			fputs("	",feed);
			fputs(fb[i].food,feed);
			fputs("	",feed);
			fputs(fb[i].behaviour,feed);
			fputs("	",feed);
			fputs(fb[i].experience,feed);
			fputs("	",feed);
			fputs(fb[i].thing,feed);
			fputs("	",feed);
			fprintf(feed,"%d",fb[i].ratings);
		}
		fclose(feed);
		break;
		case 2:
			feed=fopen("feedback.txt","r");
			printf("\n=========================All Given Feedbacks Are Listed Below===========================\n");
			for(i=0;!feof(feed);i++)
			{
				if(feed==NULL)
				{
				printf("\nNo Feedbacks Available!!\n");
				}
				else 
				{
					fscanf(feed,"%s",&fb[i].name);
					fscanf(feed,"%s",&fb[i].food);
					fscanf(feed,"%s",&fb[i].behaviour);
					fscanf(feed,"%s",&fb[i].experience);
					fscanf(feed,"%s",&fb[i].thing);
					fscanf(feed,"%d",&fb[i].ratings);
					
					printf("\nCustomer Name:%s",fb[i].name);
					printf("\nBehaviour:%s",fb[i].behaviour);
					printf("\nExperience:%s",fb[i].experience);
					printf("\nThings To Improve:%s",fb[i].thing);
					printf("\nRatings(OUT OF 10):%d",fb[i].ratings);
					printf("\n");
				}
			}
			fclose(feed);
		break;
		case 3:
			printf("\n\n============Exited from Feedback Portal=============\n");
			printf("\n\n===================================================================================================\n");
			printf("\n\nEnter (0) To Back In Management Portal:");
			scanf("%d",&var2);
			if(var2==0)
			{
				system("cls");
			}
		break;
	}
  }
}

								//			MAIN FUNCTION!!		
int main()
{

system("color 75");
FILE *admin,*adminu;
int portal,opt,i,opt2,exit;
char nameU[100],namech[10];

printf("============================================Welcome to SHS Restraunt==================================================\n");
printf("\n======>>>Enter (0) For Admin & (1) For Management Portal!!");
scanf("%d",&portal);
switch (portal)
{
	case 0:
		while(opt!=0)
		{
		printf("\n=====================================Admin Portal Opened=====================================\n");
		printf("Select From The Following:\n\n");
		printf("========================================================================================================================\n\n");
		printf("						1:Add New Employee\n");
		printf("						2:Read Employee Details\n");
		printf("						3:Existing Employees (Update)\n");
		printf("						4:Delete Employee Record\n");
		printf("						0.Exit From Portal\n\n");
		printf("========================================================================================================================\n");
		printf("\n\n======>>Enter Choice In Admin Portal:");
		scanf("%d", &opt);
		switch(opt)
			{
				case 1:
					addemployee();
					break;
				case 2: 
					searchemployee();
					break;
				case 3:
					updateemployee();
					break;

				case 4:
					deleteemployee();
					break;
				case 0:
					printf("\n\n=================Exited From Admin Portal=================\n");
					break;
				break;
			}
		}
	break;
	
	case 1:
		while(opt2!=4)
		{
		printf("\n=====================================Management Portal Opened=====================================\n");
		printf("Select From The Following:\n\n");
		printf("========================================================================================================================\n\n");
		printf("						1:Table Managment\n");
		printf("						2:Feedback\n");
		printf("						3:Menu And Order Placing\n");
		printf("						4.Exit From Portal\n\n");
		printf("========================================================================================================================\n");
		
		printf("\n\n=======>>Enter Choice In Management Portal:");
		scanf("%d", &opt2);
			switch (opt2)
			{
				case 1:
					tablemanagment();
					break;
				case 2:
					feedback();
				break;
				case 3:
					menu();
				break;
				case 4:
					printf("\n\n=================Exited From Management Portal=================\n");
					break;
				break;
			}
		}
	break;
	}
    return 0;
}

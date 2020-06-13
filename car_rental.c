#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<time.h>

//structure for user data
struct user{
    char username[10];
    char password[10];
	char name[40];
    char address[40];
    char nationality[8];
    char car_taken[3];                      
}*pUser;

//array for cars, price and drivers
char cars[9][20]={"Maruti Brezza  ","Hyundai Creta  ","Alto K10       ","Hyundai i20    ","Ford EcoSport  ","Volkswagon Polo","Tata Indigo    ","Mahindra Xuv500","Tata Hexa      "},p;
int price[9]={15,17,12,13,16,14,14,19,20};
char drivers[9][20]={"Ravi","Manoj","Guru","Sanjay","Manju","Sanjay","John","Ahmed","Manees"};

//structure for user ratings
struct rate_us{
    char stars[5];
    char suggestions[40];
}*sUser;

//function declarations
void intro();
void userlogin();
void welcome();
void car(char[]);
void function(char[],int,char[]);
void tutorials();
void rating();
void package(char[]);
void profile(char[]);
void portal(char[]);
void fun(char[] ,int);
void return_car(char[]);
void bill(char[],int,char[],int,int);
void hii();

//function to print introductory message
void welcome()
{
	printf("\n                     ::::::::::::::::::::::::::::::::::::::::::::::");
   	printf("\n                     ::          ________________________        ::");
   	printf("\n                     ::         /************************\\       ::");
   	printf("\n                     ::        /**************************\\      ::");
   	printf("\n                     ::  _____/****************************|***  ::");
   	printf("\n                     :: |********|      WELCOME      |*****|***  ::");
   	printf("\n                     :: |********|         TO        |*****|***  ::");
   	printf("\n                     :: |********|    APNI    CAR    |*****|     ::");
   	printf("\n                     :: \\********************************./      ::");
   	printf("\n                     ::    ******                 ******         ::");
   	printf("\n                     ::     ****                   ****          ::");
   	printf("\n                     ::::::::::::::::::::::::::::::::::::::::::::::\n\n");
   	printf("\n\n                           Press any key to continue...\n");
   	getch();
   	system("cls");
}

//function for user login
void userlogin(void)
{
    FILE *fp;
    char uName[10], pwd[10],name[10];
    int i,a=0,d=0;
    char c,b;
	pUser=(struct user *)malloc(sizeof(struct user));
	printf("\n\n                                  WELCOME TO APNI CAR RENTAL SERVICE");
    printf("\n\n\n\n\n\t\t\t1. Login Through An Existing Account\n\t\t\t2. Create a New account\n");
    printf("\n\n\t\t\tEnter your choice==> ");
    scanf("%d",&i);
    system("cls");
    switch(i){
        
		case 1:	printf("\n\n\t\t\tLOGIN TO APNI CAR\n\n");
             	if ((fp=fopen("user.txt", "r+")) == NULL)
                {
                	if ((fp=fopen("user.txt", "w+")) == NULL)
                	{
                    	printf ("Could not open file\n");
                    	exit (1);
                	}
            	}
            	printf("	Username: ");
            	scanf("%9s",uName);
            	printf("	Password: ");
            	scanf("%9s",pwd);
            	while (fread(pUser, sizeof(struct user), 1, fp) == 1)
            	{
                  	if( strcmp ( pUser->username, uName) == 0 && strcmp ( pUser->password, pwd) == 0)
                   	{
                      	a=1;
                      	break;
                   	}
            	}
                if(a==1)
                {
                    printf ("	Congratulations, you are succesfully logged in!!!!!\n");
                    printf("\n	Press any key to continue...");
                    getch();
                    portal(uName);
                    exit(1);
                }
                else
                {
                    printf("                  Incorrect username or password \n\n");
                    printf("                  Do you want to try again(Y/N)\n\n");
                    b=getch();
                    if(b=='y'||b=='Y')
                    {
                        system("cls");
                        userlogin();
                    }
                    else
                    {
                        exit(1);
                    }
                }
                fclose(fp);
                
      	case 2: if ((fp=fopen("user.txt", "a+")) == NULL)
                {
                    printf ("Could not open file\n");
                    exit ( 1);
            	}
                fflush(stdin);
                printf("	Choose A Username: ");
                	scanf("%[^\n]s",name);
                	FILE *fptr;
                	if ((fptr=fopen("user.txt", "r+")) == NULL)
                	{
                        printf ("Could not open file\n");
                        exit (1);
                	}
                	while(fread(pUser,sizeof(*pUser),1,fptr)==1)
                         {
                            if(strcmp(pUser->username,name)==0)
                               {
                                   d=1;
                                   break;
                               }
                         }
                         if(d==1)
                         {
                               printf("		Username already taken\n\n\n Choose a different one!!!\n\n\n");
                               userlogin();
                         }
                         fclose(fptr);
                    strcpy(pUser->username,name);
                 	fflush(stdin);
                	printf("	Choose A Password: ");
                	scanf("%[^\n]s",pUser->password);
                	fflush(stdin);
                	printf("	Name: ");
                	scanf("%[^\n]s",pUser->name);
                	fflush(stdin);
                	printf("	Address: ");
                	scanf("%[^\n]s",pUser->address);
                	fflush(stdin);
                 	printf("	Nationality: ");
                	scanf("%[^\n]s",pUser->nationality);
                	fflush(stdin);
                	strcpy(pUser->car_taken,"no");
	                fwrite (pUser, sizeof(struct user), 1, fp);
                	printf("	Account Created Successfully \n\n\n");
                	printf("	\n\nPress any key...");
                	getch();
                    exit(1);
                  	break;
    	}
    	free ( pUser);//free allocated memory
    	fclose(fp);
}

//function for car booking
void car(char arr[])
{
    int i,rec=1;
    char cara[3]="yes";
    system("cls");
	printf("\n\n			WELCOME TO CAR BOOKING");
	printf("\n\n			HOPE YOU HAVE A NICE JOURNEY\n\n");
	for(i=0;i<9;i++)
    {
        printf("               %d.         %s         %d\n",i+1,cars[i],price[i]);
    }
    p=getch();
   	FILE* fp;
   	FILE*fptr;
   	fptr=fopen("user1.txt","a+");
   	fp=fopen("user.txt","r+");
   	while(fread(pUser,sizeof(*pUser),1,fp)==1)
   	{
        if(strcmp(pUser->username,arr)==0)
        {
            strcpy(pUser->username,pUser->username);
            fwrite(pUser->username, 10, 1, fptr);
            fflush(stdin);
            strcpy(pUser->password,pUser->password);
            fwrite(pUser->password, 10, 1, fptr);
            fflush(stdin);
            strcpy(pUser->name,pUser->name);
            fwrite(pUser->name, 40, 1, fptr);
            fflush(stdin);
            strcpy(pUser->address,pUser->address);
            fwrite(pUser->address, 40, 1, fptr);
            fflush(stdin);
            strcpy(pUser->nationality,pUser->nationality);
            fwrite(pUser->nationality ,8, 1, fptr);
            fflush(stdin);
            strcpy(pUser->car_taken,"yes");
            fwrite(pUser->car_taken,3,1,fptr);
        }
        else
        {
            fwrite(pUser,sizeof(struct user), 1, fptr);
        }
   	}
   	fclose(fp);
   	fclose(fptr);
   	fclose(fopen("user.txt","w"));
   	fptr=fopen("user1.txt","r");
   	fp=fopen("user.txt","a+");
   	while(fread(pUser,sizeof(*pUser),1,fptr)==1)
   	{
        fwrite(pUser,sizeof(struct user), 1, fp);
   	}
   	fclose(fp);
   	fclose(fptr);
   	fclose(fopen("user1.txt","w"));
    if(p>'9')
    {
        printf("Choose a valid option");
        car(arr);
    }
    function(cars[p-'1'],price[p-'1'],arr);
}

//function from the car booking function
void function(char arr[],int a,char str[])
{
	int b,k,d;
	char c;
   	system("cls");
    printf("You have selected %s as your car which has a price (per Km) of Rs. %d\n\n\n",arr,a);
    printf("\nEnter the number of days you will be using this for :::::   ");
    scanf("%d",&b);
    label:
    printf("1. Upto  120 kms\n");
    printf("2. Upto  360 kms\n");
    printf("3. Upto  600 kms\n");
    printf("4. Beyond  600 kms\n");
    printf("\nSelect the range of Kms you will travel : \nEnter your choice : ");
    scanf("%d",&k);
    static int total;
    int J;
    switch(k){
        
		case 1: total= b*a*1*120;
                //printf("\n\n\n\n\nThe total cost is :::::  %d",b*a*1*120);
                break;

        case 2: total= b*a*0.8*360;
                //printf("\n\n\n\n\nThe total cost is :::::  %d",b*a*0.8*360);
                break;

        case 3: total= b*a*0.67*600;
                //printf("\n\n\n\n\nThe total cost is :::::  %d",b*a*0.67*600);
                break;

        case 4: printf("\n\n\n\n\nFor journies more than 600kms ,contact us through our customer care number :1800 201 3636\nor mail us at: apni_car.custcare@gmail.com \n");
                printf("1.  Start another booking!\n 2.  Visit our services Later\n");
                scanf("%d",&J);
                switch(J){
                
						case 1: userlogin();
                            	break;

                		case 2: printf("\nHope you liked our services. Please Visit Us Again.  :) <3\n") ;
                	    		exit(1);
                	          	break;
			  	}
				break;

        default:printf("\n\n\nChoose appropiate options only. Try again :( ");
                d=1;
                break;
    }
    if(d==1)
    	goto label;
    int T= total;

    printf("\n\n\n\n\n The total cost is :::::  %d",total);
    printf("\n\n\n     Do you want a driver(y/n)");
    c= getchar();
    if(c=='y'||c=='Y'){
    	
        printf("\n\n\n\nNow the revised cost is :::::  %f",1.20*total);
        printf("\n\n\nCongratulations You have booked your car");
        getch();
        bill(str,1.2*T,arr,k,1);
        exit(1);
    }
    if(c=='n'||c=='N'){
    	
        printf("You have booked your car");
        getch();
        bill(str,T,arr,k,0);
        exit(1);
    }
}

void bill(char str[],int d,char arr[],int km, int driver){
   	
	time_t t;
    time(&t);
   	int i,a;
	system("cls");
  	printf("\n\t\t  		     Car Rental - Customer Invoice                  ");
    printf("\n\t\t	//////////////////////////////////////////////////////\n");
    printf("\t\t	| Customer Name:-----------------|%s\n",str);
    if(driver==1)
    printf("\t\t    	| Driver-------------------------|%s\n",drivers[a%9]);
   	printf("\t\t    	| Bill dated---------------------|%s\n" ,ctime(&t));
  	printf("\t\t	| Car Model :--------------------|%s\n",arr);
    printf("\t\t	| Car No. :----------------------|%d\n",i);
    printf("\t\t	| Kilometers car ran :-----------|%d\n",km);
    printf("\t\t	| Your Rental Amount is :--------|%d\n",d);
    printf("\t\t	 ______________________________________________________\n");
    printf("\n");
    printf("\t\t	| Total Rental Amount is :-------|%d\n",d);
    printf("\t\t	 ______________________________________________________\n");
   	printf("\t\t	 # This is a computer generated invoce and it does not\n");
    printf("\t\t	 require an authorised signture #\n");
    printf("\n");
    printf("\t\t	/////////////////////////////////////////////////////\n");
    printf("\t\t	You are advised to pay up the amount before due date.\n");
    printf("\t\t	Otherwise penelty fee will be applied\n");
    printf("\t\t	/////////////////////////////////////////////////////\n");
}

void return_car(char str[]){
    
	int i,km,a;
    char arr[10];
    system("cls");
  	printf("		RETURN CAR PORTAL   \n\n\n");
  	/*printf("		Enter the name of the car taken\n\n");
  	for(i=0;i<9;i++)
    {
        printf("               %d.         %s         %d\n",i+1,cars[i],price[i]);
    }
  	scanf("%s",arr);
  	printf("		Input the distance the car has covered  ");
  	scanf("%d",&km);
  	for(i=0;i<9;i++)
  	{
	    	if(strcmp(cars[i],str)!=0)
        	break;
  	}*/
  	time_t t;
    time(&t);
	system("cls");
  	FILE* fp;
   	FILE* fptr2;
   	fptr2=fopen("user2.txt","a+");
   	fp=fopen("user.txt","r+");
   	while(fread(pUser,sizeof(*pUser),1,fp)==1)
   	{
        if(strcmp(pUser->username,str)==0)
        {
            strcpy(pUser->username,pUser->username);
            fwrite(pUser->username, 10, 1, fptr2);
            fflush(stdin);
            strcpy(pUser->password,pUser->password);
            fwrite(pUser->password, 10, 1, fptr2);
            fflush(stdin);
            strcpy(pUser->name,pUser->name);
            fwrite(pUser->name, 40, 1, fptr2);
            fflush(stdin);
            strcpy(pUser->address,pUser->address);
            fwrite(pUser->address, 40, 1, fptr2);
            fflush(stdin);
            strcpy(pUser->nationality,pUser->nationality);
            fwrite(pUser->nationality ,8, 1, fptr2);
            fflush(stdin);
            strcpy(pUser->car_taken,"no");
            fwrite(pUser->car_taken,3,1,fptr2);
        }
        else
        {
            fwrite(pUser,sizeof(struct user), 1, fptr2);
        }
   	}
   	fclose(fp);
   	fclose(fptr2);
   	fclose(fopen("user.txt","w"));
   	fptr2=fopen("user2.txt","r");
   	fp=fopen("user.txt","a+");
   	while(fread(pUser,sizeof(*pUser),1,fptr2)==1)
   	{
        fwrite(pUser,sizeof(struct user), 1, fp);
		}
   	fclose(fp);
   	fclose(fptr2);
   	printf("\n\n");
   	printf("		You have successfully returned the car!\n\n");
   	printf("		Hope you liked our services!\n\n");
   	printf("		Visit again\n\n");
   	//fclose(fopen("user2.txt","w"));
   	exit(1);
}


void portal(char str[10])
{
    char p,b[3],m;
    int a=0;
    FILE *fp;
    if ((fp=fopen("user.txt", "r+")) == NULL)
	{
        printf ("Could not open file\n");
        exit (1);
    }
    while (fread(pUser, sizeof(struct user), 1, fp) == 1)
	{
        if( strcmp ( pUser->username, str) ==0)
		{
            strcpy(b,pUser->car_taken);
            a=1;
            break;
        }
    }
	fclose(fp);
    if(strcmp(b,"yes")==0)
    {
        system("cls");
        printf("\n\n");
        printf("			Sorry there are no options avilable for you right now\n\n");
        printf("			You are yet to return a car\n\n");
        printf("			Do you want to return it now(y/n)?: ");
        m=getch();
        if(m=='y')
        	return_car(str);
        else{
        	
			printf("\n		Program is closing.....");
			exit(1);
		}
    }

    else
    {
       system("cls");
       printf("                        Hello %s, Select one of the services:\n\n\n",str);
       printf("                        1. Car rent\n");
       printf("                        2. Rating servies \n");
       printf("                        3. Offers avilable for special customers only\n");
       printf("                        4. My profile\n");
       printf("                        5. Exit\n\n\n\n");
       p=getch();
       switch(p)
       {
       		case '1':   car(str);
       					break;
       		case '2':	rating();
       					break;
       		case '3':	package(str);
       					break;
       		case '4':	profile(str);
       					break;
       		case '5':	exit(1);
       					break;
       }
    }
}
void rating()
{
	system("cls");
	char t;
	FILE *fp;
    if ( ( fp=fopen("rating.txt", "a+")) == NULL)
	{
        printf ("Could not open file\n");
        exit (1);
    }
    sUser=(struct rate_us *)malloc(sizeof(struct rate_us));
	printf("                                      Enter the stars you want to give ");
	scanf("                                       %s",sUser->stars);
	fflush(stdin);
	printf("                                      Would you like to suggest something(y/n)");
	scanf("%c",&t);
	if(t=='y')
	scanf("                                        %s",sUser->suggestions);
	else
    exit(1);
}

void package(char arr[]){
    
	int a,k;
	FILE *fp;
    if ( ( fp=fopen("user.txt", "r+")) == NULL)
	{
    	printf ("Could not open file\n");
        exit (1);
    }
    while ( fread (pUser, sizeof(struct user), 1, fp) == 1)
	{
	    a++;
        if( strcmp ( pUser->username, arr) ==0)
        {
    		k=a;
        }
	}
    fclose(fp);
    system("cls");
    if(k<4)
    {
        printf("                       You are one of our first four user\n\n\n                 And that's why you are given an oppurtunity to \n\n\nExplore the world with 50% discount");
        printf("                       Would you like to continue ....");
        printf("                       To know the charges and all press any key and to go back press 0");
        p=getch();
        if(p=='0')
            portal(arr);
        else
            hii();
    }
    if(k>=4)
    {
        printf("Sorry you are not one of our lucky users!");
    }
}

void profile(char arr[])
{
	FILE *fp;
    if ( ( fp=fopen("user.txt", "r+")) == NULL)
	{
    	printf ("Could not open file\n");
        exit (1);
    }
    while ( fread (pUser, sizeof(struct user), 1, fp) == 1)
	{
        if( strcmp ( pUser->username, arr) ==0)
        {
    		system("cls");
    		printf("            Name:::%s\n\n\n",pUser->username);
            fflush(stdin);
            printf("            Password:::%s\n\n\n",pUser->password);
            fflush(stdin);
            printf("            Nationality::: %s\n\n\n",pUser->nationality);
	        fflush(stdin);
            printf("            Address::: %s\n\n\n",pUser->address);
            fflush(stdin);
            break;
        }
	}
    fclose(fp);
}

void fun(char str[],int d){
   	int i;
    for(i-0;i<9;i++)
    {
        if(strcmp(cars[i],str)==0)
            break;
    }
  	float f;
  	if(d<120)
    {
        printf("%0.2f",(float)price[i]*d);
    }
  	if(d>120&&d<360)
    {
                printf("%0.2f",(float)price[i]*d*0.75);
    }
  	if(d>360)
    {
                printf("%0.2f",(float)price[i]*d*0.67);
    }
}
void hii(){
    system("cls");
printf("    write anything here regarding world tours");
}

//driver function
int main()
{
  	start: system("cls");
    welcome();
  	userlogin();
}

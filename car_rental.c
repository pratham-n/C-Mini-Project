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
    char car_taken[5];
    char car_took[20];
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
void return_car(char[]);
void bill(char[],int,char[],int,int);
void hii();

//function to print introductory message
void welcome()
{
    printf("\n\t\t::::::::::::::::::::::::::::::::::::::::::::::");
    printf("\n\t\t::          ________________________        ::");
    printf("\n\t\t::         /************************\\       ::");
    printf("\n\t\t::        /**************************\\      ::");
    printf("\n\t\t::  _____/****************************|***  ::");
    printf("\n\t\t:: |********|      WELCOME      |*****|***  ::");
    printf("\n\t\t:: |********|         TO        |*****|***  ::");
    printf("\n\t\t:: |********|    APNI    CAR    |*****|     ::");
    printf("\n\t\t:: \\********************************./      ::");
    printf("\n\t\t::    ******                 ******         ::");
    printf("\n\t\t::     ****                   ****          ::");
    printf("\n\t\t::::::::::::::::::::::::::::::::::::::::::::::\n\n");
    printf("\n\n\t\tPress any key to continue...\n");
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
    //dynamically allocating the memory
    pUser=(struct user *)malloc(sizeof(struct user));
    printf("\n\n\t\t\t\tWELCOME TO APNI CAR RENTAL SERVICE");
    printf("\n\n\n\n\n\t\t\t1. Login Through An Existing Account");
    printf("\n\t\t\t2. Create a New account\n");
    printf("\n\n\t\t\tEnter your choice==> ");
    scanf("%d",&i);
    system("cls");
    switch(i){

        case 1: //dynamically allocating the memory
                printf("\n\n\t\t\tLOGIN TO APNI CAR\n\n");
                if ((fp=fopen("user.txt", "r+")) == NULL)
                {
                    if ((fp=fopen("user.txt", "w+")) == NULL)
                    {
                        printf ("Could not open file\n");
                        exit (1);
                    }
                }
                printf("    Username: ");
                scanf("%9s",uName);
                printf("    Password: ");
                scanf("%9s",pwd);
                //comparing entered name with already existing usernames
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
                    //login success
                    printf ("   Congratulations, you are succesfully logged in!!!!!\n");
                    printf("\n  Press any key to continue...");
                    getch();
                    portal(uName);
                    exit(1);
                }
                else
                {
                    //login failure
                    printf("                  Incorrect username or password \n\n");
                    //prompt for retry   
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

        case 2: //creating a new account 
                if ((fp=fopen("user.txt", "a+")) == NULL)
                {
                    printf ("Could not open file\n");
                    exit ( 1);
                }
                fflush(stdin);  //clearing the buffer
                //input the username
                printf("\n\n    Create A Username (less than 10 characters): "); 
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
                    //if username already exists then asking for re-entry
                    printf("        \n\nUsername already taken\n\n\n        Choose a different one!!!\n\n\n");
                    printf("press any key to continue...");
                    getch();
                    userlogin();
                }
                fclose(fptr);
                strcpy(pUser->username,name);
                fflush(stdin);
                //entering other user details
                printf("    Choose A Password (less than 10 characters): ");
                scanf("%[^\n]s",pUser->password);
                fflush(stdin);
                printf("    Name:                                        ");
                scanf("%[^\n]s",pUser->name);
                fflush(stdin);
                printf("    Address:                                     ");
                scanf("%[^\n]s",pUser->address);
                fflush(stdin);
                printf("    Nationality:                                 ");
                scanf("%[^\n]s",pUser->nationality);
                fflush(stdin);
                strcpy(pUser->car_taken,"no  ");
                fflush(stdin);
                strcpy(pUser->car_took,"first ride");
                fwrite (pUser, sizeof(struct user), 1, fp);    //writing details to the file
                printf("\n\n\n  Account Created Successfully! \n\n\n");
                printf("    \n\nPress any key...");
                getch();
                exit(1);
                break;
        }
    free ( pUser);//free allocated memory
    fclose(fp); //closing the file
}

//function for car booking
void car(char arr[])
{
    int i,rec=1;
    char cara[3]="yes";
    system("cls");
    printf("\n\n            WELCOME TO CAR BOOKING");
    printf("\n\n            HOPE YOU HAVE A NICE JOURNEY\n\n");
    //display all the cars available
    for(i=0;i<9;i++)
    {
        printf("\t\t%d.\t%s\t\t%d\n",i+1,cars[i],price[i]);
    }
    printf("\n\n\t\tEnter the car model of your choice: ");
    p=getch();
    FILE* fp;
    FILE*fptr;
    fptr=fopen("user1.txt","a+");
    fp=fopen("user.txt","r+");
    //code here till line 256 takes care of the user details and attaching the car taken to that specific user
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
            strcpy(pUser->car_taken,"yes ");
            fwrite(pUser->car_taken,5,1,fptr);
            fflush(stdin);
            strcpy(pUser->car_took,cars[p-'1']);
            fwrite(pUser->car_took,20,1,fptr);
            fflush(stdin);
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
    //if the user chooses any number more than 9, he will be asked to re-enter
    if(p>'9'&&p==10)
    {
        printf("Choose a valid option");
        car(arr);
    }
    //the selected car and its price is sent into function
    function(cars[p-'1'],price[p-'1'],arr);
}

//function from the car booking function
void function(char arr[],int a,char str[])
{
    int b,k,d;
    char c;
    system("cls");
    printf("\n\n\t\tYou have selected the car %s\n",arr);
    printf("\n\n\t\tIt has a price (per Km) of Rs. %d\n\n\n",a);
    printf("\n\n\t\tEnter the number of days you will be using this for :::::  ");
    scanf("%d",&b);
    label:
    printf("\n\n\t\t1. Upto  120 kms\n");
    printf("\t\t2. Upto  360 kms\n");
    printf("\t\t3. Upto  600 kms\n");
    printf("\t\t4. Beyond  600 kms\n");
    printf("\n\t\tSelect the range of Kms you will travel : \n");
    printf("\t\tEnter your choice : ");
    scanf("%d",&k);
    static int total;
    int J;
    switch(k)
    {
        /*total cost modified based on distance*/
        case 1: total= b*a*1*120;             
                break;                        
                                              
        case 2: total= b*a*0.8*360;           
                break;

        case 3: total= b*a*0.67*600;
                break;

        case 4: printf("\n\n\n\n\nFor journies more than 600kms ,contact us through our customer care number :1800 201 3636\nor mail us at: apni_car.custcare@gmail.com \n");
                printf("1.  Start another booking!\n 2.  Visit our services Later\n");
                scanf("%d",&J);
                switch(J)
                {
                    case 1: userlogin();
                            break;

                    case 2: printf("\nHope you liked our services. Please Visit Us Again.  :) <3\n") ;
                            exit(1);
                            break;
                }
                break;

        //if inappropriate options are used
        default:printf("\n\n\nChoose appropiate options only. Try again :( ");
                d=1;
                break;
    }
    if(d==1)
        goto label;
    int T= total;

    //the code till line 343 takes care of the driver availability
    printf("\n\n\t\tThe total cost is :::::  %d",total);
    printf("\n\n\t\tDo you want a driver?(y/n)");
    fflush(stdin);  //clearing the buffer
    c= getchar();
    if(c=='y'||c=='Y')
    {
        printf("\n\n\t\tNow the revised cost is :::::  %f",1.20*total);
        printf("\n\n\t\tCongratulations You have booked your car!!");
        getch();
        //passing to the bill function to print invoice
        bill(str,1.2*T,arr,k,1);
        exit(1);
    }
    if(c=='n'||c=='N')
    {
        printf("\n\n\t\tCongratulations You have booked your car!!");
        getch();
        //passing to bill function to print invoice
        bill(str,T,arr,k,0);
        exit(1);
    }
}

//the function which prints the invoice
void bill(char str[],int d,char arr[],int km, int driver)
{
    system("cls");
    int k,b=0;
    FILE *fp;
    if ( ( fp=fopen("user.txt", "r+")) == NULL)
    {
        printf ("Could not open file\n");
        exit (1);
    }
    /*counting users so that the discount for first 4 users can be applied*/
    while ( fread (pUser, sizeof(struct user), 1, fp) == 1)
    {
        b++;
        if( strcmp ( pUser->username, str) ==0)
        {
            k=b;
        }
    }
    if(k<4)
        {
            d=d-100;
            printf("YOU ARE ONE OF OUR FOUR LUCKY CUSTOMERS.");
            printf(" YOU HAVE A DISCOUNT OF RS. 1000 :)");
        }
    else
        {
            printf("SORRY THERE IS NO DISCOUNT AVAILABLE NOW :(");
        }
        fclose(fp);
    time_t t;
    time(&t);
    int i,a;
    /*printing the bill*/
    char s1[]="Upto 120 kms", s2[]="Upto 360 kms", s3[]="Upto 600 kms";
    printf("\n\t\t               Car Rental - Customer Invoice                  ");
    printf("\n\t\t  //////////////////////////////////////////////////////\n");
    printf("\t\t    | Customer Name:-----------------|%s\n",str);
    //printing driver name based on user choice
    if(driver==1)
        printf("\t\t    | Driver-------------------------|%s\n",drivers[a%9]);
    //printing bill date and time using time function
    printf("\t\t    | Bill dated---------------------|%s\n" ,ctime(&t));
    printf("\t\t    | Car Model :--------------------|%s\n",arr);
    //printing the distance range based on user input
    if(km==1)
        printf("\t\t    | Kilometers car ran :-----------|%s\n",s1);
    else if(km==2)
        printf("\t\t    | Kilometers car ran :-----------|%s\n",s2);
    else if(km==3)
        printf("\t\t    | Kilometers car ran :-----------|%s\n",s3);
    printf("\t\t    | Your Rental Amount is :--------|%d\n",d);
    printf("\t\t     ______________________________________________________\n");
    printf("\n");
    printf("\t\t    | Total Rental Amount is :-------|%d\n",d);
    printf("\t\t     ______________________________________________________\n");
    printf("\t\t     # This is a computer generated invoice and it does not\n");
    printf("\t\t     require an authorised signature #\n");
    printf("\n");
    printf("\t\t    /////////////////////////////////////////////////////\n");
    printf("\t\t    You are advised to pay up the amount before due date.\n");
    printf("\t\t    Otherwise penalty fee will be applied\n");
    printf("\t\t    /////////////////////////////////////////////////////\n");
}

//the function which manages the car returning
void return_car(char str[]){

    int i,km,a;
    char arr[10];
    system("cls");
    time_t t;
    time(&t);
    system("cls");
    FILE* fp;
    FILE* fptr2;
    fptr2=fopen("user2.txt","a+");
    fp=fopen("user.txt","r+");
    /*modifies the file so that the
    car taken can be recorded
    and the user can gain re-entry to the program*/
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
            strcpy(pUser->car_taken,"no  ");
            fwrite(pUser->car_taken,5,1,fptr2);
            fflush(stdin);
            strcpy(pUser->car_took,pUser->car_took);
            fwrite(pUser->car_took ,20, 1, fptr2);
            fflush(stdin);
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
    printf("        You have successfully returned the car!\n\n");
    printf("        Hope you liked our services!\n\n");
    printf("        Visit again\n\n");
    system("cls");
    userlogin(); //redirect to user login
    exit(1);
}

//function which shows the available options
void portal(char str[10])
{
    char p,b[5],m;
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
    if(strcmp(b,"yes ")==0)
    {
        system("cls");
        printf("\n\n");
        printf("            Sorry there are no options available for you right now\n\n");
        printf("            You are yet to return a car\n\n");
        printf("            Do you want to return it now(y/n)?: ");
        m=getch();
        if(m=='y')
            return_car(str);
        else{

            printf("\n      Program is closing.....");
            exit(1);
        }
    }

    else
    {
       system("cls");
       printf("\n\n                        Hello %s, Please select one of the services:\n\n\n",str);
       printf("                        1. Car rent\n");
       printf("                        2. Rating services \n");
       printf("                        3. Offers available for special customers only\n");
       printf("                        4. My profile\n");
       printf("                        5. Exit\n\n\n\n");
       p=getch();
       switch(p)
       {
            case '1':   car(str);
                        break;
            case '2':   rating();
                        break;
            case '3':   package(str);
                        break;
            case '4':   profile(str);
                        break;
            case '5':   exit(1);
                        break;
       }
    }
}

//function for user ratings and reviews
void rating()
{
    system("cls");
    printf("\n\n\t\t\tRATINGS AND REVIEWS\n\n");
    char t;
    FILE *fp;
    if ( ( fp=fopen("rating.txt", "a+")) == NULL)
    {
        printf ("Could not open file\n");
        exit (1);
    }
    sUser=(struct rate_us *)malloc(sizeof(struct rate_us));
    printf("\n\t\t  GIVE US A RATING OUT OF 5 ::: ");
    scanf("%s",sUser->stars);
    fflush(stdin);
    printf("\n\n\t\t  Would you like to suggest something(y/n)?\n\n");
    scanf("%c",&t);
    if(t=='y'){
        scanf("                                        %s",sUser->suggestions);
        printf("\n\n\t\t\tTHANK YOU");
    }
    else
        printf("\n\n\t\t\tTHANK YOU");
    exit(1);
}

//function which informs the first four users about the discount
void package(char arr[]){
    
    int a,k;
    FILE *fp;
    if ( ( fp=fopen("user.txt", "r+")) == NULL)
    {
        printf ("Could not open file\n");
        exit (1);
    }
    //counting the number of users till 4 to print the message
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
    printf("\t\t\tDISCOUNT PACKAGE\n\n");
    if(k<4)
    {
        printf("\t\tYou are one of our first four user\n\n\n");
        printf("\t\tAnd that's why you are given an oppurtunity\n\n\n");
        printf("\t\tExplore the world with Rs. 1000 discount\n\n\n");
        printf("\t\tWould you like to continue ....\n\n");
        printf("\t\tTo know the packages and all press any key and to go back press 0");
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

//function to print user profile
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
            printf("\t\t\tUser Name              :::%s\n\n",pUser->username);
            fflush(stdin);
            printf("\t\t\tUser Name              :::%s\n\n",pUser->name);
            fflush(stdin);
            printf("\t\t\tPassword               :::%s\n\n",pUser->password);
            fflush(stdin);
            printf("\t\t\tNationality            ::: %s\n\n",pUser->nationality);
            fflush(stdin);
            printf("\t\t\tAddress                ::: %s\n\n",pUser->address);
            fflush(stdin);
            printf("\t\t\tCar You Took Previously::: %s\n\n",pUser->car_took);
            fflush(stdin);
            break;
        }
    }
    fclose(fp);
}

//function hii from package
void hii(){
    system("cls");
    printf("\n\n\t\tTHERE IS A RS. 1000 DISCOUNT TO THE FIRST FOUR LUCKY USERS");
}

//driver function
int main()
{
    start: system("cls");
    welcome();  //prints the welcome message
    userlogin(); //redirecting user login
}

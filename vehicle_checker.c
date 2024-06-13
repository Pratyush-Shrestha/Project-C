#include<stdio.h>
#include<stdlib.h>
#include "vehicle_checker.h"
int checkPassword(char pass[100]){
    int upperCase=0,symbols=0,numbers=0,letter=0;
    for(int i=0;pass[i]!='\0';i++){
        if(pass[i]>=65&&pass[i]<=90){
            upperCase++;
        }
        else if(pass[i]>=32&&pass[i]<=47||pass[i]>=58&&pass[i]<=64||pass[i]>=91&&pass[i]<=96||pass[i]>=123&&pass[i]<=126){
            symbols++;
        }
        else if(pass[i]>=48&&pass[i]<=57){
            numbers++;
        }
        else{
            letter++;
        }
    }
    if(upperCase>0&&letter>0&&numbers>0&&symbols>0){
        return 1;
    }
    else{
        return 0;
    }
}
int phnumberchecker(long long int ph){
    int digit=0;
    while(ph!=0){
        ph/=10;
        digit++;
    }
    if(digit==10){
        return 1;
    }
    else{
        return 0;
    }
}
void login(){
    FILE *log;
    int choice;
    char useremail[100],password[100];
    ac:
    printf("1.Login\t\t2.Sign up\n");
    printf("Enter Choice: ");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        printf("Enter E-mail: ");
        scanf("%s", useremail);
        printf("Enter Password:");
        scanf("%s", password);
        break;
    case 2:
        printf("\t\tNew Account\n");
        signUp s;
        printf("First Name:");
        scanf("%s", s.fname);
        printf("Last Name: ");
        scanf("%s",s.lname);
        printf("Date of Birth info \n");
        printf("Year(1963-2024): ");
        yr:
        scanf("%d",&s.DOBY);
        if(s.DOBY<1963||s.DOBY>2024){
            printf("Incorrect fromat. Please re-enter(1963-2024): ");
            goto yr;
        }
        printf("Month: ");
        mo:
        scanf("%d",&s.DOBM);
        if(s.DOBM>12){
            printf("Incorrect fromat. Please re-enter(0-12): ");
            goto mo;
        }
        printf("Date: ");
        dt:
        scanf("%d",&s.DOBD);
        if(s.DOBD>30){
            printf("Incorrect fromat. Please re-enter(0-30): ");
            goto dt;
        }
        printf("Gender(m for Male, f for Female ,o for others):\n");
        gen:
        printf("Enter your gender: ");
        scanf("%s",&s.gender);
        if(s.gender!='m'&&s.gender!='f'&&s.gender!='o'){
            printf("Incorrect format Please try again.");
            goto gen;
        }
        printf("Create a Strong password Using letter,UpperCase, symbols and numbers: ");
        repass:
        scanf("%s",s.password);
        if(checkPassword(s.password)==0){
            printf("Please Use letter,UpperCase, symbols and numbers.Try Again: ");
            goto repass;
        }
        printf("Phone Number:+977 ");
        reph: ;
        scanf("%lld",&s.phn);
        if(phnumberchecker(s.phn)==0){
            printf("Incorrect Format.Please Try Again:+977 ");
            goto reph;
        }
        printf("Enter Recovery Phone Number:+977 ");
        recovph:
        scanf("%lld",&s.recovphn);
        if(phnumberchecker(s.recovphn)==0){
            printf("Incorrect Format.Please Try Again:+977 ");
            goto recovph;
        }
        break;
    default:
        printf("Incorrect option.Try Again.\n");
        goto ac;
        break;
}
}


void addVehicle(){
    vehicle v;
    FILE *fptr;
    fptr=fopen("vehicle.txt","a");
    printf("Enter Registration number Details: \n");
    printf("Enter Vehicle type(A-K): ");
    scanf("%c",&v.vehicleType);
    printf("Enter state name: ");
    scanf("%s",v.state);
    printf("Enter Vehicle Age Code: ");
    scanf("%d",&v.vehicle_Agecode);
}


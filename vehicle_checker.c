#include<stdio.h>
#include<stdlib.h>
#include "vehicle_checker.h"
#include <string.h>
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
char user[50],pass[50];
void login(){
         printf("\t\tSign in\n");
        char useremail[100],password[100];
        account a;
        FILE *sign;
        sign=fopen("acc.DAT","r");
        rem:
        printf("Enter E-mail: ");
        scanf("%s", useremail);
        printf("Enter Password:");
        scanf("%s", password);
        if(sign==NULL){
            printf("Error Opening File.");
        }
        rewind(sign);
        while(fread(&a,sizeof(account),1,sign)==1){
            
            int c;
            if(strcmp(useremail,a.email)!=0&&strcmp(password,a.password)!=0){
            printf("Incorrect email or password.\n");
            printf("1.Forgot Password?\t\t2.Try again\n3.Cancel\n");
            printf("Enter Your choice: ");
            scanf("%d", &c);
            switch (c)
            {
            case 1:
            printf("\t\tRecovery Mode");
            long long int recphn;
            char newp[100],confp[100];

                printf("Enter Recovery Phone number: ");
                scanf("%lld",recphn);
                if(a.recovphn==recphn){
                    new:
                    printf("Enter New Password: ");
                    scanf("%s",newp);
                    printf("Confirm password: ");
                    scanf("%s",confp);
                    if(strcmp(newp,confp)==0){
                        if(checkPassword(confp)==0){
                            printf("Please Use letter,UpperCase, symbols and numbers.Try Again: ");
                            goto new;
                        }
                    }
                    printf("Login Successfully.\n");
                }
                break;
                case 2:
                goto rem;
                break;
                case 3:
                Account();
                break;
            
            default:
                break;
            }


        }
        else{
            printf("Login Succesfully\n");
        }
        
        }
}
void signup(){
        printf("\t\tNew Account\n");
        account s;
        FILE *sig;
        sig=fopen("acc.DAT","a");
        printf("First Name:");
        scanf("%s", s.fname);
        printf("Last Name: ");
        scanf("%s",s.lname);
        printf("Date of Birth info \n");
        printf("Year(1963-2024): ");
        yr: 
        scanf("%d",&s.DOBY);
        if(s.DOBY<1963||s.DOBY>2024){
            printf("Incorrect format. Please re-enter(1963-2024): ");
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
        dt: ;
        scanf("%d",&s.DOBD);
        if(s.DOBD>30){
            printf("Incorrect fromat. Please re-enter(0-30): ");
            goto dt;
        }
        printf("Gender(m for Male, f for Female ,o for others):\n");
        gen: ;
        printf("Enter your gender: ");
        scanf("%s",&s.gender);
        printf("%c",s.gender);
        if(s.gender!='m'&&s.gender!='f'&&s.gender!='o'){
            printf("Incorrect format Please try again.");
            goto gen;
        }
        printf("Create an e-mail: ");
        scanf("%s",s.email);
        printf("Create a Strong password Using letter,UpperCase, symbols and numbers: ");
        repass: ;
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
        recovph: ;
        scanf("%lld",&s.recovphn);
        if(phnumberchecker(s.recovphn)==0){
            printf("Incorrect Format.Please Re-enter:+977 ");
            goto recovph;
        }
        fwrite(&s,sizeof(account),1,sig);
        printf("Create Successfully.\n");
        
}

void Account(){
    int choice;
    rechoice:
    printf("1.Sign Up\t\t2.Login\n");
    printf("Enter Choice: ");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        signup();
        break;
    case 2:
    login();
   break;
    default:
        printf("Incorrect option.Re-Enter your choice.\n");
        goto rechoice;
        break;
}
}
void accountDetail(){
    printf("\t\tAccount Detail");
    
}


void addVehicle(){
    vehicle v;
    FILE *addv;
    addv=fopen("vehicle.txt","a");
    char add='y';
    char confirm='y';
    while(add=='y'){
        //  while(confirm=='y'){
                printf("\t\tRegistration Details\n");
                printf("\n");
                printf("Enter Registration number: ");
                scanf("%d",&v.registrationNumber);
                printf("Enter Vehicle type(A-K): ");
                scanf(" %c",&v.vehicleType);
                printf("Enter Vehicle model: ");
                scanf("%s",v.modelName);
                printf("Enter Year of Manufacture: ");
                scanf("%d",&v.year);
                printf("Enter First Name: ");
                scanf("%s",v.ofname);
                printf("Enter Last Name: ");
                scanf("%s",v.olname);
                printf("Enter state name: ");
                scanf("%s",v.state);
                
                
                
            // }
    printf("Adding Please Wait\n");
    printf("Successfully Added.\n");
    printf("Do you Want to Add Another Vehicle(y/n): ");
    scanf(" %c" ,&add);
    fwrite(&v,sizeof(vehicle),1,addv);
    
    }
    fclose(addv);
}
void checkVehicle(){
    int regNum;
    vehicle v;
    FILE *updatev;
    updatev=fopen("vehicle.txt","r");
    printf("Enter your Registration Number: ");
    scanf("%d",&regNum);
    
    while (fread(&v,sizeof(vehicle),1,updatev))
    {
        if(v.registrationNumber==regNum){
        printf("\t\tYour Details\n");
        printf("Registration Number:%d\n",v.registrationNumber);
        printf("Owner Name: %s %s\n",v.ofname,v.olname);
        printf("Vehicle Type: %c\n",v.vehicleType);
        printf("State:%s\n",v.state);
        printf("Model:%s\n",v.modelName);
        printf("Year of Manufacture:%d\n",v.year);
        }
        else{
            printf("No any vehicle Registered in this number.\n");
            break;
        }
    }
}
void updateVehicle(){
    FILE *upd;
    upd=fopen("vehicle.txt","r");
    vehicle vehicles[100];
    int reg,choice;
    int num=0;
    int found=0;
    char oldfname[50];
    char oldlname[50];
    printf("Enter Your Registration Number: ");
    scanf("%d",&reg);
    
    while (fread(&vehicles[num],sizeof(vehicle),1,upd)){
        
        printf("%d\n",vehicles[num].registrationNumber);
        if(vehicles[num].registrationNumber==reg){
            
            found=1;
            char omodel[100];
            change:
            printf("\t\tWhat Do You Want To Change?");
            printf("\n");
            printf("1.Owner \t\t 2.Model\n");
            printf("3.Go Back");
            printf("Enter Your Choice: ");
            scanf("%d",&choice);
            switch (choice)
            {
            case 1:
            re:
                printf("Previous Owner \n");
                printf("Enter first Name: ");
                scanf("%s",oldfname);
                printf("Enter Last Name:");
                scanf("%s",oldlname);
                if(strcmp(oldfname,vehicles[num].ofname)==0&&strcmp(oldlname,vehicles[num].olname)==0){
                printf("New Owner\n");
                printf("Enter First Name:");
                scanf("%s",vehicles[num].ofname);
                printf("Enter Last Name:");
                scanf("%s",vehicles[num].olname);
                }
                else{
                    printf("Incorrect Name.Try Again\n");
                    goto re;
                }
                
                break;
                case 2:
                   model:           
                
                printf("Enter Previous Model Name: ");
                scanf("%s",omodel);
                if(strcmp(omodel,vehicles[num].modelName)==0){
                    printf("Enter New Model: ");
                    scanf("%s",vehicles[num].modelName);
                    printf("Enter Year of Manufacture: ");
                    scanf("%d",&vehicles[num].year);
                    printf("Enter Vehicle TYpe: ");
                    scanf(" %c",&vehicles[num].vehicleType);
                    printf("Enter State: ");
                    scanf("%s",vehicles[num].state);
                }
                else{
                    printf("Invalid.Try Again.\n");
                    goto model;
                }
                break;
               

                
            
            default:
            printf("Invalid option Try Again.\n");
            goto change;
                break;
            }
        }
            
        num++;
    }
    if(!found){
        printf("No file\n");
    }
    fclose(upd);
    upd=fopen("vehicle.txt","w");
    int i;
    if(!upd){
        printf("Couldnot open.");
    }
    for(i=0;i<num;i++){
        fwrite(&vehicles[i],sizeof(vehicle),1,upd);
    }
    fclose(upd);
    printf("Changed Successfully");
       
    }
    void deleteVehicle(){
        FILE *delv;
        int num=0;
        char choice=' ';
        delv=fopen("vehicle.txt","r+");
        vehicle vehicles[100];
        int reg;
        printf("Enter Your Registration number to delete:");
        scanf("%d", &reg);
        while(fread(&vehicles[num],sizeof(vehicle),1,delv)){
            if(vehicles[num].registrationNumber==reg){
                printf("\t\tYour Details\n\n");
                printf("Owner Name:%s %s\n",vehicles[num].ofname,vehicles[num].olname);
                printf("Regeistration Number:%d\n",vehicles[num].registrationNumber);
                printf("Vehicle Type:%c\n",vehicles[num].vehicleType);
                printf("Year of Manufacture:%d\n",vehicles[num].year);
                printf("Model:%s\n",vehicles[num].modelName);
                del:
                printf("Are You Sure You Want to delete?(y/n): ");
                scanf(" %c",&choice);
                if(choice=='y'){
                    num-=1;
                }
                // else if(choice=='n'){

                // }
                else{
                    printf("Please Input the valid choice.\n");
                    goto del;
                }
            }
            num++;
        }
        fclose(delv);
        delv=fopen("vehicle.txt","w");
        if(delv==NULL){
            printf("Error Opening File.");

        }
        for(int i=0;i<num;i++){
            fwrite(&vehicles[i],sizeof(vehicles),1,delv);
        }
        


    }




#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "vehicle_checker.h"
int main(){
    int choice;
    printf("\tVehicle Validator Management\n");
    log:
    login();
    rechoice:
    
    printf("1.Add Vehicle    \t\t 2.Update Vehicle\n");
    printf("3.Remove Vehicle \t\t 4.Check Vehicle Status\n");
    printf("5.Log out \t\t6.Exit\n");
    printf("Enter Your Choice: ");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
    addVehicle();
    break;
    // case 2:
    // updateVehicle();
    // break;
    // case 3:
    // deleteVehicle();
    // break;
    // case 4:
    // checkVehicle();
    // break;
    case 5:
    goto log;
    break;
    case 6:
    exit(0);
    break;

    default:
    printf("Invalid option Try Again.");
    goto rechoice;
    break;
}
}


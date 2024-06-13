typedef struct 
{
    char modelName[50];
    int year;
    char Owner[50];
    int registrationNumber;
    char vehicleType;
    char state[10];
    char vehicle_Agecode[2];

} vehicle ;
typedef struct 
{
    char email[100];
    char password[100];

} account ;
typedef struct 
{
    char fname[20];
    char lname[20];
    int DOBM;
    int DOBD;
    int DOBY;
    char gender;
    char password[100];
    long long int phn;
    long long int recovphn;
} signUp;

void login();
void addVehicle();
// void updateVehicle();
// void deleteVehicle();
// void checkVehicle();
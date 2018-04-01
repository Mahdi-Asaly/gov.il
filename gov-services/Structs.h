#ifndef Struct
#define Struct

#include <stdio.h>
//Structres//
#define true 1
#define false 0
typedef enum{ worker, Manager }Assigment;

typedef struct
{
	char *Name;
	char Id[10]; //Adjust lama's functions to char (instead of int)
	float age;
	char*Adress;
	char*Password;
	int BankACC;
	Assigment Assigm;
	char phoneNumber[11];
}Workers;
typedef struct {
	int day;
	int mounth;
	int year;
}Date;

typedef struct {
	char *Id;
	char*Name;
	char*Reason;

}Leave_Req;

typedef struct {
	char*Subject;
	char* date;
	int NumOfWorkShop;
}WorkShops;
typedef struct {
	char*Name;
	char* Id;
	char*Reason;
}Resignation_Req;
typedef struct {
	char*Name;
	char *Id;
	char*Reason;
	float Amount; //updated
}Loan_Req;
typedef struct {
	char *Id;
	float Age;
}Pension_req;
typedef struct {
	char*Name;
	char Id[10];
	float Age;
	char*Adress;
	char*Email;
	int PhoneNumber[11];
	char*Degree;

}Applicants;

/*NEW , Edited Struct of Passport*/
typedef struct {
	char *Name;
	char id[11];
	char * mailbox;
	char PhoneNumber[11];
	char *Address;
}Passport;
typedef struct {
	char*ReligiousName;//new
	char *HolidayName;
	char* date;
}Holidays;

typedef struct {
	char *Name;
	int Id[10];
	float age;
	char PhoneNumber[11];
	int MailBox;
	char *Address;
}Customers;

typedef struct {
	char *Name;
	int Assess;
}Customer_Survey;
typedef struct {
	int day;
	int month;
	int year;
}BirthDate;
typedef struct {
	char *FirstName;
	char *LastName;
	char Id[10];
	char *Relegion;
	char Gender;
	Date Date;
	
}ID;


//check with hanan
typedef struct {
	char *Name;
	char id[10];
	char *TesterName;
	int MailBox;
	char PhoneNum[11];
	Date DrivetestDate;
	char *Reason;
}DrivingTestAppeal;

//with hanan
typedef struct {
	char *Name;
	char id[10];
	char PhoneNumber[11];
	char *CarNumber;
}Vehicles;


typedef struct {
	char*Month;
	char*date;
	char *Address;
}DrivingTest;


typedef struct {
	char* age;//new float->char*
	char *NameOfVaccinations;
}Vaccinations;

typedef struct {
	char *Name;
	char id[10];
	char PhoneNumber[11];
	int MailBox;
	Date DateofTest;
	
}DrivingTestRegistration;

typedef struct {
	char *id;
	char *NameOfClinic;
}Clinic;

#endif

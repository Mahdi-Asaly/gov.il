#ifndef _Prototype_
#define _Prototype_
#define _CRT_SECURE_NO_WARNINGS
#include "Structs.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
				    /*Customer Functions*/
////////////////////////////////////////////////////////////////////////

void Customer_Menu();//func 1



					   /*WH functions*/
void Health_Catagory(int funcnum);//func 2
void WH_Help(int funcnum);//func 3
float WH_Calculate(float h, float w);//func 4



				 /*Switch clinics functions*/
void Requests(int funcNum);//func 5
void Clinic_Switch_Req(int funcNum);//func 6
int Confirmation_Switch_Req(char *id, char *clinic_choice);//func 7
void UpdateClinicFile(Clinic *p, int size);//func 8


///////////////////////////////////////Hanan custmor function//////////////
void Transporation();//func 9
void Request_Objection();//func 10
void Update_objectiononDrivenTest(DrivingTestAppeal*, int size);//func 11
void select_suitable_vaccinations();//func 12
void print_the_vaccinations(char* select);//func 13
void Religious();//func 14
void Religious_Holidays();//func 15
void Show_the_regligiousHoidays(char*ReligiousName);//func 16
void Select_Date_ofTests();//func 17
void Show_Drivingtest(char*Select);//func 18
//////////////Coustomer Survey////////////////////
void Service_Survey();//func 19
int checkInput_Service_Survey(char* name, int Assests);//func 20
void Update_the_Service_Survey(Customer_Survey*, int size);//func 21
//////Vehicles///////
void vehicle_Registrations();//func 22
int cheak_IdVehicle_customer(char*id, Vehicles*vecc, int sizee);//func 23
void Add_new_Carnumber(char*id, Vehicles*vecc, int sizee);//func 24
void Add_new_custcar();//func 25
void Update_CustCar(Vehicles*vecc, int size);//func 26
////// change the Religious//////
int cheakid_Customer(char*id);//func 27
void Change_religion();//func 28
void update_Idreligion(id);//func 29
//////Change custom Details in ID///////////////////
void Show_CustDeatils();//func 30
void Select_DetailtoChange(char*id);//func 31
void Change_Deatils(char*id, int select);//func 32
////////////Regstring to Driving Test////////////////
void Select_suitableMonth();//func 33
void Show_Driving_tests(char*month);//func 34
void Registration_to_Driving_test();//func 35
////Cancel Regstrion to car//////
void VehCancelReg(int funcNum);//func 36
void Confirmation(char*id, Vehicles* vecc, int size);//func 37
//////////Cheak date/////////
int cheakDate(int day, int month, int year);//func 38


//////////////////////////////Hanan Manage functions//////////////////////////////////////////
/*Manager Functions*/
void Transprition_Manager();//func 39
void Select_MonthOFObjection();//func 40
void Show_the_Objection(int month_select);//func 41
////////////////////////////////////////////////////////////////////////


//END OF HANAN DRESHOT


//(NEW 27/1/17)
								  /*Passport Request*/
void PassportRegisteration(int funcnum);//funnum 42
int Check_Details(char *Name, char id[11], char *mailbox, char *PhoneNumber, char *Address, Passport *pass, int Size);//funcnum 43
void FreeMemoryOfPassportArr(Passport **p, int Size);//func 44
void UpdateTheFile(Passport **p, int Size);//func 45
void GetInfoIntoArr(Passport **pass, int *Size);//func 46

////////////////////////////////////////////////////////////////////////
			        			/*Manager Functions*/
//all functions here is just added (NEW) 21/1/2017
void certifications(int funcnum);//funcnum 47 (NEW)

/*Functions Related to Pensions*/
void Pension_confirmation(int funcnum);//funcnum 48 (NEW)
void CopyPensionReqsToArr(Pension_req **p);//func 49       //this function to read the file of workers and put them into array (NEW)
void UpdatePensionFile(Pension_req **p, int size, int index);//func 50 //this function to update the file of pension after changes (NEW)
//new 23/1/2017//
/*Functions Related to Add Employee*/
void Add_Employee(int funcnum);//funcnum 51
int Check_Fields(char *Name, char *Password, char *_Id, char *Address, char *PhoneNum, float Age, Assigment _Assigment, int BankAcc);//funcnum 52 
void UpdateTheFileOfWorkers(Workers **p, int size);//func 53  //this function updates the file of workers , after changes

//new 27/1/2017//
/*Functions Related to Modify Employee Details*/
void FreeMemWorkers(Workers **p, int size);//func 54   //new , to free memory of workers arr
void Modify_Employee_Details(int funcnum);//funcnum 55
int Varify(char* id);//funcnum 56
////////////////////////////////////////////////////////////////////////
void Manager_Menu(Workers *p, int *size , int indexofworker);//func 57
////////////////////////////////////////////////////////////////////////

						/*Worker Functions*/
////////////////////////////////////////////////////////////////////////
void Worker_Menu(Workers *emp, int sizef, int index);//func 58 
void requests(int funcnum);//Funcnum 59 
void LoanReq(int funcnum);//funcnum 60 
void ReadFileAndPutIntoArr(char *name, char *id, float amount, char *Reason, Loan_Req **p, int *Size);//func 61
void UpdateTheFileOfLoans(Loan_Req **p, int size);//func 62
int check_validAge(float age);
int check_existed(char* id1, char* id2);
int check_index(int index, int size);

					/*These function related to Make survey */
void Make_Survey(int funcnum);//funcnum 63


////////////////////////////////////////////////////////////////////////
void MainMenu(); //func 64
//shared for both manager and worker.
////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
int verification(char id[10], char *password, Workers* emp, int sizef);//func number 65 (Worker/Manager)
void Choose_Entity(int Func_Num, Workers* emp, int sizef);//func number 66 (worker/manager)
void Acc_Info(Workers* emp, int sizef);////func number 67 (worker/manager)
Workers* readFile_Workers(int* size);//func 68
void LogIn(Workers* emp, int sizef);//func 69
void PensionReq(int funcnum);//funcnum 70 (Worker)
void PensionFileSize(int *size);//func 71
int ConfirmByID(char *id);//func 72 //new!,function that confirms that employee is exists in the db.
void updatepensionreq(char *id, float age, Pension_req **p, int *size);//func 73 //new , this function updates the array of pension requests.
void updatepensionfile(Pension_req **p, int size);//func 74 //new , this update the file of pension requests.
void FreeMemoryOfArr(Pension_req **p, int size);//func 75 //new but check first
////////////////////////////////////////////////////////////////////////
void InitData(DrivingTestAppeal**dta, int*size);//func 76
DrivingTestAppeal* InitDate_DrivingTestAppeal(int*size);//func 77
////////Functions to update data(file)///////////////
void update_date(DrivingTestAppeal*dta, int size);//func 78
void update_DrivingTestAppealFile(DrivingTestAppeal*dta, int size);//func 79
///////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////
//////Functions initData(file->array)////
DrivingTestAppeal* InitData_DrivingTestAppeal(int*size);//func 80
Vaccinations*InitData_Vaccinations(int*size);//func 81
Holidays*InitData_Holidays(int*size);//func 82
DrivingTest*InitData_DrivingTest(int*size);//func 83
Customer_Survey*InitData_customerServey(int*size);//func 84
Vehicles*InitData_Vehicles(int*size);//func 85
ID*InitData_ID(int*size);//func 86
DrivingTestRegistration*InitData_DrivingTestReg(int*size);//func 87
////////Functions to update data(file)///////////////

void update_DrivingTestAppealFile(DrivingTestAppeal*dta, int size);//func 88
void Update_the_Service_SurveyFile(Customer_Survey*, int size);//func 89
void update_VehiclesFile(Vehicles*, int size);//func 90
void update_IDFile(ID*idd, int size);//func 91
void update_DrivingTestRegFile(DrivingTestRegistration*dta, int size);//func 92


//Lama's functions
void Loan_request_confirmation();//func 93
void CopyLoanReqsToArr(Loan_Req **p, int* size);//func 94
void UpdateLoanFile(Loan_Req** p, int size, int index);//func 95
void CopyLeaveReqsToArr(Leave_Req **p, int* size);//func 96
void Leave_request_confirmation();//func 97
void UpdateLeaveFile(Leave_Req** p, int size, int index);//func 98
void CopyResignReqsToArr(Resignation_Req **p, int* size);//func 99
void Resignation_request_confirmation();//func 100
void UpdateResignFile(Resignation_Req** p, int size, int index);//func 101
////
//Worker functions, (LAMA)
void updateLeaveReqFile(Leave_Req** p, int* size);//func 101//NEW												 
void updateLeaveReqArr(char* name, char* id, char* reason, Leave_Req** p, int *size);//func 102
void Leave_request();//func 103
void Resignation_request();//func 104
void updateResignReqFile(Resignation_Req** p, int* size);//func 105//NEW												 
void updateResignReqArr(char* name, char* id, char* reason, Resignation_Req** p, int *size);//func 106
void updateTheFileOfWorkers(Workers **ar, int size, char* id);	//func 107											 //new

void viewWorkshops();//func 108
void viewApplicants();//func 109
void viewWorkers();//func 110
void funding_request();//func 111


#endif
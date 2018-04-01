#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>  
#include <string.h>
#include "Functions.h"
#include "MinUnit.h"
/////////////////////////////////////////TESTS///////////////////////////////////////////////////////
//new 
//Testing that file contain my ID
//Updated

MU_TEST(test_check_Age) {
	float age;
	age = 60.0f;
	int result = check_validAge(age);
	mu_check(result == 0); //1st method, shows the test itself if it fails, without a custom error message
}

MU_TEST(test_check_index) {
	mu_check(check_index(5, 5) == 0); //1st method, shows the test itself if it fails, without a custom error message
}

//add ths
MU_TEST(test_check_WH_Calculate)
{
	float result = WH_Calculate(0, 2); //division by Zero
	mu_check(result == -1.0f);
}
MU_TEST(test_check_existed) {
	mu_check(check_existed("204237814", "204237814") == 1); //1st method, shows the test itself if it fails, without a custom error message
}

MU_TEST(test_cheak_CopyPensionReqsToArr) {
	Pension_req* p;
	p=(Pension_req*)malloc(sizeof(Pension_req)* 1);
	int result;
	p[0].Id = (char*)malloc((strlen("206331795") + 1)*sizeof(char));
	strcpy(p[0].Id, "206331795");
	result = strcmp(p->Id,"206331795");
	mu_check(result == 0); //1st method, shows the test itself if it fails, without a custom error message
}
//Testing that the File of workers contains My Id
MU_TEST(test_cheak_ConfirmByID) {
	int result;
	result = ConfirmByID("206331795");
	mu_check(result == 1); //1st method, shows the test itself if it fails, without a custom error message
}

//new test 3/2/17
MU_TEST(test_cheak_verification)
{
	int result;
	Workers* testemp;
	char id[] = "206331795";
	testemp = (Workers*)malloc(1 * sizeof(Workers));
	testemp[0].Password = (char*)malloc((strlen("12345") + 1)*sizeof(char));
	strcpy(testemp[0].Password, "12345");
	strcpy(testemp[0].Id, "206331795");
	result = verification("206331795", "12345",testemp,1);
	mu_check(result == 1); //1st method, shows the test itself if it fails, without a custom error message
}

MU_TEST_SUITE(test_Pension_Functions) {
	MU_SUITE_CONFIGURE(NULL, NULL);

	MU_RUN_TEST(test_cheak_CopyPensionReqsToArr);
	MU_RUN_TEST(test_cheak_ConfirmByID);
	MU_RUN_TEST(test_cheak_verification);
	////////
	MU_RUN_TEST(test_check_Age);
	
	MU_REPORT_SUITE();
}

MU_TEST_SUITE(test_loan_req_functions) {
	MU_SUITE_CONFIGURE(NULL, NULL);

	MU_RUN_TEST(test_check_index);

	MU_REPORT_SUITE();
}

MU_TEST_SUITE(test_resignation_req_functions) {
	MU_SUITE_CONFIGURE(NULL, NULL);

	MU_RUN_TEST(test_check_existed);

	MU_REPORT_SUITE();
}


MU_TEST(test_cheak_IdVehicle_customer) {
	//Arrange
	Vehicles* x = (Vehicles*)malloc(sizeof(Vehicles)* 1);
	x->CarNumber = (char*)malloc(sizeof(char)* 8);
	strcpy(x->CarNumber, "7777788");
	strcpy(x->id, "123456789");
	x->Name = (char*)malloc(sizeof(char)* 7);
	strcpy(x->Name, "fouzi");
	strcpy(x->PhoneNumber, "9876543210");
	//Act
	int result = cheak_IdVehicle_customer("123456789", x, 1);

	//Assert
	mu_check(result == 1); //1st method, shows the test itself if it fails, without a custom error message
}

MU_TEST(test_checkInput_Service_Survey) {
	//Act
	int result = checkInput_Service_Survey("Hanan", 4);


	//Assert
	mu_check(result == 1); //1st method, shows the test itself if it fails, without a custom error message
}

MU_TEST(test_cheakid_Customer) {
	//Act
	int result = cheakid_Customer("465131236");

	//Assert
	mu_check(result == 1); //1st method, shows the test itself if it fails, without a custom error message
}

MU_TEST(test_cheakDate) {
	//Act
	int result = cheakDate(14, 3, 2017);

	//Assert
	mu_check(result == 1); //1st method, shows the test itself if it fails, without a custom error message
}

MU_TEST_SUITE(test_customer_cheak_functions) {
	MU_SUITE_CONFIGURE(NULL, NULL);

	MU_RUN_TEST(test_cheak_IdVehicle_customer);
	MU_RUN_TEST(test_checkInput_Service_Survey);
	MU_RUN_TEST(test_cheakid_Customer);
	MU_RUN_TEST(test_cheakDate);
	MU_RUN_TEST(test_check_WH_Calculate);

	MU_REPORT_SUITE();
}


//////////////////////////////////////////////////////////////////////////////////////////



void MainMenu()
{
	char choice;//variable to choose entity;
	int i = 0;
	int flag = 1;
	int sizef;
	Workers* EMP = NULL; //new (EDITED)
	//new (ADDED)
	if (EMP == NULL) 
	{
		EMP = readFile_Workers(&sizef);
	}
	do {
		system("cls");
		//new
		printf("\t\t\t\t___<LMH>___\n\n\n\nWelcome User,\n\nPlease Choose Entity:\n\n- Log in - (Press 1 then Enter)\n- Exit - (Press 2 then Enter)\n- Customer - (Press 3 then Enter)\n- Run Tests - (Press 4 then Enter)\n>> ");
		fflush(stdin);
		scanf("%c", &choice);
		_flushall();

		/////////////////////////////
		switch (choice)
		{
		case '1'://Manager
		{
			system("cls");
			LogIn(EMP, sizef);
			break;
		}
		case '2':
		{
			system("cls");
			printf("\t\t\t\t___<LMH>___\n\n\n\n>> Thanks for using our program, GoodBye !\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
			exit(1);
			break;
		}
		case '3':
		{
			Customer_Menu();
			break;
		}
		//new (ADDED)
		case '4':
		{
			system("Cls");
			MU_RUN_SUITE(test_customer_cheak_functions);
			MU_RUN_SUITE(test_Pension_Functions);
			MU_RUN_SUITE(test_resignation_req_functions);
			MU_RUN_SUITE(test_loan_req_functions);
		    MU_REPORT();
			system("Pause");
			break;
		}
		default:
			break;
		}
	} while (flag);

}
//Vehicles*InitData_Vehicles(int*size){
//	Vehicles*vec;
//	char buff[300];
//	FILE*file_6;
//	int sizeF = 0, i = 0;
//	file_6 = fopen("vehicles.txt", "r+");
//	if (file_6 == NULL)
//	{
//		printf("the file not EXIT(vehicles file)\n");
//		exit(1);
//	}
//	while (!feof(file_6))
//	{
//		fgets(buff, 300, file_6);
//		sizeF++;
//	}
//	*size = sizeF;
//	vec = (Vehicles*)malloc(sizeF * sizeof(Vehicles));
//	if (vec == NULL)
//	{
//		printf("No memory allocation\n");
//		exit(1);
//	}
//	fseek(file_6, 0, SEEK_SET);
//	while (!feof(file_6))
//	{
//		fscanf(file_6, "%s", buff);
//		vec[i].Name = (char*)malloc((strlen(buff) + 1) * sizeof(char));
//		if (vec[i].Name == NULL)
//		{
//			printf("NO memory allcoation\n");
//			exit(1);
//		}
//
//		strcpy(vec[i].Name, buff);
//		fgetc(file_6);
//		fscanf(file_6, "%s", vec[i].id);
//		fgetc(file_6);
//		fscanf(file_6, "%s", vec[i].PhoneNumber);
//		fgetc(file_6);
//		fscanf(file_6, "%s", buff);
//		vec[i].CarNumber = (char*)malloc((strlen(buff) + 1) * sizeof(char));
//		if (vec[i].CarNumber == NULL)
//		{
//			printf("NO memory allcoation\n");
//			exit(1);
//		}
//		strcpy(vec[i].CarNumber, buff);
//		i++;
//	}
//	fclose(file_6);
//	return vec;
//}
//void update_VehiclesFile(Vehicles*vecc, int size){
//	FILE*file_8;
//	int i;
//	file_8 = fopen("vehicles.txt", "w");
//	if (file_8 == NULL)
//	{
//		printf("the file Not exit(vehicles)\n");
//		exit(1);
//	}
//	for (i = 0; i < size - 1; i++)
//	{
//		fprintf(file_8, "%s %s %s %s\n", vecc[i].Name, vecc[i].id, vecc[i].PhoneNumber, vecc[i].CarNumber);
//	}
//	fprintf(file_8, "%s %s %s %s", vecc[i].Name, vecc[i].id, vecc[i].PhoneNumber, vecc[i].CarNumber);
//	for (i = 0; i < size; i++)// free arr employees
//	{
//		free(vecc[i].Name);
//		free(vecc[i].CarNumber);
//	}
//	free(vecc);
//	fclose(file_8);
//}
Workers* readFile_Workers(int* size)
{
	Workers*emp;
	FILE*file_1;
	char buff[300];
	int sizef = 0, i = 0;
	file_1 = fopen("Workers.txt", "r+");
	if (file_1 == NULL)
	{
		printf("the file not Exit(Workers file)\n");
		exit(1);
	}
	//(NEW 31/1/17 added this function)
	if (NULL != file_1) {
		fseek(file_1, 0, SEEK_END);
		*size = ftell(file_1);

		if (0 == *size) {
			printf("file is empty\n");
			*size = 0;
			return NULL; //exit from function
		}
	}
	fseek(file_1, 0, SEEK_SET);
	while (!feof(file_1)) {
		fgets(buff, 300, file_1);
		sizef++;
	}
	//sizef--;
	*size = sizef;

	emp = (Workers*)malloc(sizef * sizeof(Workers));
	if (emp == NULL) {
		printf("No momery allocation\n");
		exit(1);
	}
	fseek(file_1, 0, SEEK_SET);
	while (!feof(file_1)) {
		fscanf(file_1, "%s", buff);
		emp[i].Name = (char*)malloc((strlen(buff) + 1) * sizeof(char));
		if (emp[i].Name == NULL) {
			printf("No momery allocation\n");
			exit(1);
		}
		strcpy(emp[i].Name, buff);
		fgetc(file_1);
		fscanf(file_1, "%s", emp[i].Id);
		fgetc(file_1);
		fscanf(file_1, "%f", &(emp[i].age));
		fgetc(file_1);
		fscanf(file_1, "%s", buff);
		emp[i].Adress = (char*)malloc((strlen(buff) + 1) * sizeof(char));
		if (emp[i].Adress == NULL) {
			printf("No momery allocation\n");
			exit(1);
		}
		strcpy(emp[i].Adress, buff);
		fgetc(file_1);
		fscanf(file_1, "%s", buff);
		emp[i].Password = (char*)malloc((strlen(buff) + 1) * sizeof(char));
		if (emp[i].Password == NULL) {
			printf("No momery allocation\n");
			exit(1);
		}
		strcpy(emp[i].Password, buff);
		fgetc(file_1);
		fscanf(file_1, "%d", &(emp[i].BankACC));
		fgetc(file_1);
		fscanf(file_1, "%d", &(emp[i].Assigm));
		fgetc(file_1);
		fscanf(file_1, "%s", emp[i].phoneNumber);
		i++;
	}
	fclose(file_1);
	return emp;
}
int verification(char id[10], char *password, Workers* emp, int sizef) {//func number 3 (Worker/Manager)
	int i;
	for (i = 0; i < sizef; i++)
		if ((strcmp(emp[i].Id, id) == 0) && (strcmp(emp[i].Password, password) == 0))
		{
			return true;
		}
	return false;
}

void Choose_Entity(int Func_Num, Workers* emp, int sizef)
{
	Acc_Info(emp, sizef); //Call
}
//new (EDITED)
void Acc_Info(Workers* emp, int sizef)//Func:2
{
	int c = 0;
	int result = 0;
	int i = 0;
	char password[10], id[10];
	printf("\t\t\t\t___<LMH>___\n\n\n\n>> Log In Process:\nYou must enter your password to continue\n\n\n>> Enter ID:");
	
	scanf("%s", id);
	_flushall();
	printf("\n>> Enter Password:");
	
	scanf("%s", password);
	_flushall();
	result = verification(id, password, emp, sizef);
	if (result)
	{
		for (c = 0; c < sizef; c++)
		{
			if (emp[c].Assigm == 1 && strcmp(emp[c].Id, id) == 0)
			{
				//new (EDITED 27/1)
				Manager_Menu(emp, &sizef, c);
				break;
			}
			else if (emp[c].Assigm == 0 && strcmp(emp[c].Id, id) == 0)
			{
				//new (EDITED 27/1)
				Worker_Menu(emp, sizef, c);
				break;
			}
		}
	}
	else {
		system("cls");
		printf("\t\t\t\t___<LMH>___\n\n\n\n<LMH><ERROR> Invalid Username or Password.\n");
		system("Pause");
		system("cls");
	}
}
/*Function Num: 1 (Manager/Worker)*/
void LogIn(Workers* emp, int sizef)
{
	Choose_Entity(1, emp, sizef);
}

////////////////////////////InitDate/////////////////////////////
DrivingTestAppeal*InitData_DrivingTestAppeal(int*size) {
	DrivingTestAppeal* Dta;
	char buff[300];
	FILE*file_1;
	int sizeF = 0, i = 0;
	file_1 = fopen("drivingtestappeal.txt", "r+");
	if (file_1 == NULL)
	{
		printf("the file not EXIT(DrivingTestAppeal file)\n");
		exit(1);
	}
	while (!feof(file_1))
	{
		fgets(buff, 300, file_1);
		sizeF++;
	}
	*size = sizeF;
	Dta = (DrivingTestAppeal*)malloc(sizeF * sizeof(DrivingTestAppeal));
	if (Dta == NULL)
	{
		printf("No memory allocation\n");
		exit(1);
	}
	fseek(file_1, 0, SEEK_SET);
	while (!feof(file_1))
	{
		fscanf(file_1, "%s", buff);
		Dta[i].Name = (char*)malloc((strlen(buff) + 1) * sizeof(char));
		if (Dta[i].Name == NULL)
		{
			printf("NO memory allcoation\n");
			exit(1);
		}

		strcpy(Dta[i].Name, buff);
		fgetc(file_1);
		fscanf(file_1, "%s", Dta[i].id);
		fgetc(file_1);
		fscanf(file_1, "%s", buff);
		Dta[i].TesterName = (char*)malloc((strlen(buff) + 1) * sizeof(char));
		if (Dta[i].TesterName == NULL)
		{
			printf("NO memory allcoation\n");
			exit(1);
		}
		strcpy(Dta[i].TesterName, buff);
		fgetc(file_1);
		fscanf(file_1, "%d", &(Dta[i].MailBox));
		fgetc(file_1);
		fscanf(file_1, "%s", Dta[i].PhoneNum);
		fgetc(file_1);
		fscanf(file_1, "%d", &(Dta[i].DrivetestDate.day));
		fgetc(file_1);
		fscanf(file_1, "%d", &(Dta[i].DrivetestDate.mounth));
		fgetc(file_1);
		fscanf(file_1, "%d", &(Dta[i].DrivetestDate.year));
		fgetc(file_1);
		fscanf(file_1, "%s", buff);
		Dta[i].Reason = (char*)malloc((strlen(buff) + 1) * sizeof(char));
		if (Dta[i].Reason == NULL)
		{
			printf("NO memory allcoation\n");
			exit(1);
		}
		strcpy(Dta[i].Reason, buff);
		i++;
	}
	fclose(file_1);
	return Dta;
}
Holidays*InitData_Holidays(int*size){
	Holidays*holiday;
	char buff[300];
	FILE*file_3;
	int sizeF = 0, i = 0;
	file_3 = fopen("Holidays.txt", "r+");
	if (file_3 == NULL)
	{
		printf("the file not EXIT(Holidays file)\n");
		exit(1);
	}
	while (!feof(file_3))
	{
		fgets(buff, 300, file_3);
		sizeF++;
	}
	*size = sizeF;
	holiday = (Holidays*)malloc(sizeF * sizeof(Holidays));
	if (holiday == NULL)
	{
		printf("No memory allocation\n");
		exit(1);
	}
	fseek(file_3, 0, SEEK_SET);
	while (!feof(file_3))
	{
		fscanf(file_3, "%s", buff);
		holiday[i].ReligiousName = (char*)malloc((strlen(buff) + 1) * sizeof(char));
		if (holiday[i].ReligiousName == NULL)
		{
			printf("NO memory allcoation\n");
			exit(1);
		}

		strcpy(holiday[i].ReligiousName, buff);
		fgetc(file_3);
		fscanf(file_3, "%s", buff);
		holiday[i].HolidayName = (char*)malloc((strlen(buff) + 1) * sizeof(char));
		if (holiday[i].HolidayName == NULL)
		{
			printf("NO memory allcoation\n");
			exit(1);
		}
		strcpy(holiday[i].HolidayName, buff);
		fgetc(file_3);
		fscanf(file_3, "%s", buff);
		holiday[i].date = (char*)malloc((strlen(buff) + 1) * sizeof(char));
		if (holiday[i].date == NULL)
		{
			printf("NO memory allcoation\n");
			exit(1);
		}
		strcpy(holiday[i].date, buff);
		i++;
	}
	fclose(file_3);
	return holiday;
}
Vaccinations*InitData_Vaccinations(int*size) {
	Vaccinations*vac;
	char buff[300];
	FILE*file_2;
	int sizeF = 0, i = 0;
	file_2 = fopen("Vaccinations.txt", "r+");
	if (file_2 == NULL)
	{
		printf("the file not EXIT(Vaccinations file)\n");
		exit(1);
	}
	while (!feof(file_2))
	{
		fgets(buff, 300, file_2);
		sizeF++;
	}
	*size = sizeF;
	vac = (Vaccinations*)malloc(sizeF * sizeof(Vaccinations));
	if (vac == NULL)
	{
		printf("No memory allocation\n");
		exit(1);
	}
	fseek(file_2, 0, SEEK_SET);
	while (!feof(file_2))
	{
		fscanf(file_2, "%s", buff);
		vac[i].age = (char*)malloc((strlen(buff) + 1) * sizeof(char));
		if (vac[i].age == NULL)
		{
			printf("NO memory allcoation\n");
			exit(1);
		}

		strcpy(vac[i].age, buff);
		fgetc(file_2);
		fscanf(file_2, "%s", buff);
		vac[i].NameOfVaccinations = (char*)malloc((strlen(buff) + 1) * sizeof(char));
		if (vac[i].NameOfVaccinations == NULL)
		{
			printf("NO memory allcoation\n");
			exit(1);
		}
		strcpy(vac[i].NameOfVaccinations, buff);
		i++;
	}
	fclose(file_2);
	return vac;
}
DrivingTest*InitData_DrivingTest(int*size){
	DrivingTest*dTest;
	char buff[300];
	FILE*file_4;
	int sizeF = 0, i = 0;
	file_4 = fopen("DrivingTest.txt", "r+");
	if (file_4 == NULL)
	{
		printf("the file not EXIT(DrivingTest file)\n");
		exit(1);
	}
	while (!feof(file_4))
	{
		fgets(buff, 300, file_4);
		sizeF++;
	}
	*size = sizeF;
	dTest = (DrivingTest*)malloc(sizeF * sizeof(DrivingTest));
	if (dTest == NULL)
	{
		printf("No memory allocation\n");
		exit(1);
	}
	fseek(file_4, 0, SEEK_SET);
	while (!feof(file_4))
	{
		fscanf(file_4, "%s", buff);
		dTest[i].Month = (char*)malloc((strlen(buff) + 1) * sizeof(char));
		if (dTest[i].Month == NULL)
		{
			printf("NO memory allcoation\n");
			exit(1);
		}

		strcpy(dTest[i].Month, buff);
		fgetc(file_4);
		fscanf(file_4, "%s", buff);
		dTest[i].date = (char*)malloc((strlen(buff) + 1) * sizeof(char));
		if (dTest[i].date == NULL)
		{
			printf("NO memory allcoation\n");
			exit(1);
		}
		strcpy(dTest[i].date, buff);
		fgetc(file_4);
		fscanf(file_4, "%s", buff);
		dTest[i].Address = (char*)malloc((strlen(buff) + 1) * sizeof(char));
		if (dTest[i].Address == NULL)
		{
			printf("NO memory allcoation\n");
			exit(1);
		}
		strcpy(dTest[i].Address, buff);
		i++;
	}
	fclose(file_4);
	return dTest;

}
Customer_Survey*InitData_customerServey(int*size){
	Customer_Survey*custS;
	char buff[300];
	FILE*file_5;
	int sizeF = 0, i = 0;
	file_5 = fopen("customer_survey.txt", "r+");
	if (file_5 == NULL)
	{
		printf("the file not EXIT(Customer_Survey file)\n");
		exit(1);
	}
	while (!feof(file_5))
	{
		fgets(buff, 300, file_5);
		sizeF++;
	}
	*size = sizeF;
	custS = (Customer_Survey*)malloc(sizeF * sizeof(Customer_Survey));
	if (custS == NULL)
	{
		printf("No memory allocation\n");
		exit(1);
	}
	fseek(file_5, 0, SEEK_SET);
	while (!feof(file_5))
	{
		fscanf(file_5, "%s", buff);
		custS[i].Name = (char*)malloc((strlen(buff) + 1) * sizeof(char));
		if (custS[i].Name == NULL)
		{
			printf("NO memory allcoation\n");
			exit(1);
		}

		strcpy(custS[i].Name, buff);
		fgetc(file_5);
		fscanf(file_5, "%d", &custS[i].Assess);
		i++;
	}
	fclose(file_5);

	return custS;
}
Vehicles*InitData_Vehicles(int*size){
	Vehicles*vec;
	char buff[300];
	FILE*file_6;
	int sizeF = 0, i = 0;
	file_6 = fopen("vehicles.txt", "r+");
	if (file_6 == NULL)
	{
		printf("the file not EXIT(vehicles file)\n");
		exit(1);
	}
	while (!feof(file_6))
	{
		fgets(buff, 300, file_6);
		sizeF++;
	}
	*size = sizeF;
	vec = (Vehicles*)malloc(sizeF * sizeof(Vehicles));
	if (vec == NULL)
	{
		printf("No memory allocation\n");
		exit(1);
	}
	fseek(file_6, 0, SEEK_SET);
	while (!feof(file_6))
	{
		fscanf(file_6, "%s", buff);
		vec[i].Name = (char*)malloc((strlen(buff) + 1) * sizeof(char));
		if (vec[i].Name == NULL)
		{
			printf("NO memory allcoation\n");
			exit(1);
		}

		strcpy(vec[i].Name, buff);
		fgetc(file_6);
		fscanf(file_6, "%s", vec[i].id);
		fgetc(file_6);
		fscanf(file_6, "%s", vec[i].PhoneNumber);
		fgetc(file_6);
		fscanf(file_6, "%s", buff);
		vec[i].CarNumber = (char*)malloc((strlen(buff) + 1) * sizeof(char));
		if (vec[i].CarNumber == NULL)
		{
			printf("NO memory allcoation\n");
			exit(1);
		}
		strcpy(vec[i].CarNumber, buff);
		i++;
	}
	fclose(file_6);
	return vec;
}
ID*InitData_ID(int*size){
	ID*idd;
	char buff[300];
	FILE*file_7;
	int sizeF = 0, i = 0;
	file_7 = fopen("ID.txt", "r+");
	if (file_7 == NULL)
	{
		printf("the file not EXIT(ID file)\n");
		exit(1);
	}
	while (!feof(file_7))
	{
		fgets(buff, 300, file_7);
		sizeF++;
	}
	*size = sizeF;
	idd = (ID*)malloc(sizeF * sizeof(ID));
	if (idd == NULL)
	{
		printf("No memory allocation\n");
		exit(1);
	}
	fseek(file_7, 0, SEEK_SET);
	while (!feof(file_7))
	{
		fscanf(file_7, "%s", buff);
		idd[i].FirstName = (char*)malloc((strlen(buff) + 1) * sizeof(char));
		if (idd[i].FirstName == NULL)
		{
			printf("NO memory allcoation\n");
			exit(1);
		}

		strcpy(idd[i].FirstName, buff);
		fgetc(file_7);
		fscanf(file_7, "%s", buff);
		idd[i].LastName = (char*)malloc((strlen(buff) + 1) * sizeof(char));
		if (idd[i].LastName == NULL)
		{
			printf("NO memory allcoation\n");
			exit(1);
		}

		strcpy(idd[i].LastName, buff);
		fgetc(file_7);
		fscanf(file_7, "%s", idd[i].Id);
		fgetc(file_7);
		fscanf(file_7, "%s", buff);
		idd[i].Relegion = (char*)malloc((strlen(buff) + 1) * sizeof(char));
		if (idd[i].Relegion == NULL)
		{
			printf("NO memory allcoation\n");
			exit(1);
		}
		strcpy(idd[i].Relegion, buff);
		fgetc(file_7);
		fscanf(file_7, "%c", &idd[i].Gender);
		fgetc(file_7);
		fscanf(file_7, "%d", &idd[i].Date.day);
		fgetc(file_7);
		fscanf(file_7, "%d", &idd[i].Date.mounth);
		fgetc(file_7);
		fscanf(file_7, "%d", &idd[i].Date.year);
		i++;
	}
	fclose(file_7);
	return idd;
}
DrivingTestRegistration*InitData_DrivingTestReg(int*size){
	DrivingTestRegistration*dtr;
	char buff[300];
	FILE*file_8;
	int sizeF = 0, i = 0;
	file_8 = fopen("DrivingTestRegistration.txt", "r+");
	if (file_8 == NULL)
	{
		printf("the file not EXIT(DrivingTestRegistration file)\n");
		exit(1);
	}
	while (!feof(file_8))
	{
		fgets(buff, 300, file_8);
		sizeF++;
	}
	*size = sizeF;
	dtr = (DrivingTestRegistration*)malloc(sizeF * sizeof(DrivingTestRegistration));
	if (dtr == NULL)
	{
		printf("No memory allocation\n");
		exit(1);
	}
	fseek(file_8, 0, SEEK_SET);
	while (!feof(file_8))
	{
		fscanf(file_8, "%s", buff);
		dtr[i].Name = (char*)malloc((strlen(buff) + 1) * sizeof(char));
		if (dtr[i].Name == NULL)
		{
			printf("NO memory allcoation\n");
			exit(1);
		}
		strcpy(dtr[i].Name, buff);
		fgetc(file_8);
		fscanf(file_8, "%s", dtr[i].id);
		fgetc(file_8);
		fscanf(file_8, "%s", dtr[i].PhoneNumber);
		fgetc(file_8);
		fscanf(file_8, "%d", &dtr[i].MailBox);
		fgetc(file_8);
		fscanf(file_8, "%d", &dtr[i].DateofTest.day);
		fgetc(file_8);
		fscanf(file_8, "%d", &dtr[i].DateofTest.mounth);
		fgetc(file_8);
		fscanf(file_8, "%d", &dtr[i].DateofTest.year);
		i++;
	}
	fclose(file_8);
	return dtr;

}
/////////////////////////Functions to update data////////////////////
void update_DrivingTestAppealFile(DrivingTestAppeal*dta, int size) {
	FILE*file_1;
	int i;
	file_1 = fopen("drivingtestappeal.txt", "w");
	if (file_1 == NULL)
	{
		printf("the file Not exit(employees)\n");
		exit(1);
	}
	for (i = 0; i < size - 1; i++)
	{
		fprintf(file_1, "%s %s %s %d %s %d %d %d %s\n", dta[i].Name, dta[i].id, dta[i].TesterName, dta[i].MailBox, dta[i].PhoneNum, dta[i].DrivetestDate.day, dta[i].DrivetestDate.mounth, dta[i].DrivetestDate.year, dta[i].Reason);
	}
	fprintf(file_1, "%s %s %s %d %s %d %d %d %s", dta[i].Name, dta[i].id, dta[i].TesterName, dta[i].MailBox, dta[i].PhoneNum, dta[i].DrivetestDate.day, dta[i].DrivetestDate.mounth, dta[i].DrivetestDate.year, dta[i].Reason);
	for (i = 0; i < size; i++)// free arr employees
	{
		free(dta[i].Name);
		free(dta[i].TesterName);
		free(dta[i].Reason);
	}
	free(dta);
	fclose(file_1);
}
void Update_the_Service_SurveyFile(Customer_Survey*CustS, int size){
	FILE*file_5;
	int i;
	file_5 = fopen("customer_survey.txt", "w");
	if (file_5 == NULL)
	{
		printf("the file Not exit(customer_survey)\n");
		exit(1);
	}
	for (i = 0; i < size - 1; i++)
	{
		fprintf(file_5, "%s %d\n", CustS[i].Name, CustS[i].Assess);
	}
	fprintf(file_5, "%s %d", CustS[i].Name, CustS[i].Assess);
	for (i = 0; i < size; i++)// free arr employees
	{
		free(CustS[i].Name);
	}
	free(CustS);
	fclose(file_5);
}
void update_IDFile(ID*idd, int size){

	FILE*file_6;
	int i;
	file_6 = fopen("ID.txt", "w");
	if (file_6 == NULL)
	{
		printf("the file Not exit(customer_survey)\n");
		exit(1);
	}
	for (i = 0; i < size - 1; i++)
	{
		fprintf(file_6, "%s %s %s %s %c %d %d %d\n", idd[i].FirstName, idd[i].LastName, idd[i].Id, idd[i].Relegion, idd[i].Gender, idd[i].Date.day, idd[i].Date.mounth, idd[i].Date.year);
	}
	fprintf(file_6, "%s %s %s %s %c %d %d %d", idd[i].FirstName, idd[i].LastName, idd[i].Id, idd[i].Relegion, idd[i].Gender, idd[i].Date.day, idd[i].Date.mounth, idd[i].Date.year);
	for (i = 0; i < size; i++)// free arr employees
	{
		free(idd[i].FirstName);
		free(idd[i].LastName);
		free(idd[i].Relegion);
	}
	free(idd);
	fclose(file_6);
}
void update_DrivingTestRegFile(DrivingTestRegistration*dta, int size){
	FILE*file_7;
	int i;
	file_7 = fopen("DrivingTestRegistration.txt", "w");
	if (file_7 == NULL)
	{
		printf("the file Not exit(customer_survey)\n");
		exit(1);
	}
	for (i = 0; i < size - 1; i++)
	{
		fprintf(file_7, "%s %s %s %d %d %d %d\n", dta[i].Name, dta[i].id, dta[i].PhoneNumber, dta[i].MailBox, dta[i].DateofTest.day, dta[i].DateofTest.mounth, dta[i].DateofTest.year);
	}
	fprintf(file_7, "%s %s %s %d %d %d %d", dta[i].Name, dta[i].id, dta[i].PhoneNumber, dta[i].MailBox, dta[i].DateofTest.day, dta[i].DateofTest.mounth, dta[i].DateofTest.year);
	for (i = 0; i < size; i++)// free arr employees
	{
		free(dta[i].Name);

	}
	free(dta);
	fclose(file_7);

}
void update_VehiclesFile(Vehicles*vecc, int size){
	FILE*file_8;
	int i;
	file_8 = fopen("vehicles.txt", "w");
	if (file_8 == NULL)
	{
		printf("the file Not exit(vehicles)\n");
		exit(1);
	}
	for (i = 0; i < size - 1; i++)
	{
		fprintf(file_8, "%s %s %s %s\n", vecc[i].Name, vecc[i].id, vecc[i].PhoneNumber, vecc[i].CarNumber);
	}
	fprintf(file_8, "%s %s %s %s", vecc[i].Name, vecc[i].id, vecc[i].PhoneNumber, vecc[i].CarNumber);
	for (i = 0; i < size; i++)// free arr employees
	{
		free(vecc[i].Name);
		free(vecc[i].CarNumber);
	}
	free(vecc);
	fclose(file_8);
}
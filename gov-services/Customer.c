#define _CRT_SECURE_NO_WARNINGS
#include "Functions.h"
#include "Structs.h"
#include<stdio.h>
#include<stdlib.h>

#define True 1
#define False 0
//func 4
void Customer_Menu() {
	char choice;
	int flag = 1;
	do {
		system("cls");
		printf("\t\t\t\t___<LMH>___\n\n\n\nWelcome Customer,\nChoose Option:\n\n>>Requests - Press 1 then Enter\n>>Health Catagory - Press 2 then Enter\n>>Transportation- Press 3 then Enter\n");
		printf(">>>Religious- Press 4 then Enter\n>>>Service_Survey- Press 5 then Enter\n>>>identity - Press 6 then Enter\n>>>Back to main menu - Type q then Enter\n");
		scanf("%c", &choice);
		getchar();
		switch (choice)
		{
		case '1':
			Requests(1);
			break;
		case '2':
			Health_Catagory(1);
			break;
		case '3':
			Transporation();
			break;
		case'4':
			Religious();
			break;
		case'5':
			Service_Survey();
			break;
		case '6':
			Show_CustDeatils();
			break;
		case 'q':
			flag = 0;
			break;
		default:
			printf("Wrong select\n");
			break;
		}
	} while (flag);
}
//func 30 (Added : 16/1/2017 at 12:15 o'c)

void Health_Catagory(int funcnum) {
	int flag = 1;
	do{
		system("cls");
		char choice;
		printf("\t\t\t\t___<LMH>___\n\n\n\>> You are now in Catagory Health\nChoose Option:\n\n>>WH System  - Press 1 then Enter\n>>Virtual Consulting vaccines-press 2 then Enter\n>>> to return to coustomer Menu -press b\n");
		
		scanf("%c", &choice);
		getchar();
		switch (choice)
		{
		case '1':
			WH_Help(1);
			break;
		case '2':
			select_suitable_vaccinations();
		case 'b':
			flag = 0;
			break;
		default:
			printf("your select is not correct pelase try again\n");
			break;
		}
	} while (flag);

}
//func 31
void WH_Help(int funcnum)
{
	system("cls");
	float result;
	float hight;
	float weight;
	printf("\t\t\t\t___<LMH>___\n\n\n(WH System)\nThis system helps you to know if your weight is suitalbe according to your height\n<!>Example : Hight = 1.7 , weight=60\n>OutPut: You'r Weight is normal\nEnter your hight:\n>> ");
	
	scanf("%f", &hight);
	getchar();
	printf(">>Enter your Weigth:\n>>");
	
	scanf("%f", &weight);
	getchar();
	system("Cls");
	printf("\t\t\t\t___<LMH>___\n\n\n(WH System)\nNode that A healthy BMI ranges between 19 and 25\nYour mode is : ");
	result = WH_Calculate(hight, weight);
}
//func 32

float WH_Calculate(float h, float w) {


	float  bmi;

	if (h == 0.0f)
		return -1;
	bmi = w / (h*h);
	printf("bmi: %f", bmi);
	//bmi<18.5 ? printf("Underweight") : (bmi<25) ? printf("Normal weight") : (bmi<30) ? printf("Overweight") : printf("Obesity");

	if (bmi < 18.5) {
		printf("You have a BMI of %.f, and your weight status is\n>>underweight\n", bmi);
		system("Pause");
	}
	else if (bmi >= 18.5 && bmi < 25) {
		printf("You have a BMI of %.f, and your weight status is\n>>Normal\n", bmi);
		system("Pause");
	}
	else {
		printf("You have a BMI of %.f, and your weight status is\nOverWeight\n", bmi);
		system("Pause");
	}
	return 1.0f;
}
//func 6
void Clinic_Switch_Req(int funcNum) {//func 6
	int result = 0;
	system("cls");
	char id[256];
	char choice[256];
	printf("\t\t\t\t___<LMH>___\n\n(Clinic Switch)\n\nChoose Option:\n\n>>Enter your ID:");
	
	scanf("%s", &id);
	getchar();
	printf("\n>>Choose new Option:\n- Makabi Clinic - Press 1 then type enter\n- Meohedet Clinic - Press 2 then enter\n");
	
	printf("\n>> ");
	scanf("%s", &choice);
	getchar();
	if (strcmp(choice, "1") && strcmp(choice, "2"))
	{
		do{
			printf("\n>> Enter your choice (1 / 2): ");
			scanf("%s", &choice);
			getchar();
		} while (strcmp(choice, "1") && strcmp(choice, "2"));
	}
	result = Confirmation_Switch_Req(id, choice);
	if (result)
	{
		system("cls");
		printf("\t\t\t\t___<LMH>___\n\n<<LMH>> Successfully switched to new clinic!\n");
		system("Pause");
	}
	else {
		system("cls");
		printf("\t\t\t\t___<LMH>___\n\nERROR: You are not registered to any clinic!\n");
		system("Pause");
	}
}
//(NEW) EDITED
Clinic* readFile_clinic(int* size)
{
	Clinic*p;
	FILE*file_1;
	char buff[300];
	int sizef = 0, i = 0;
	file_1 = fopen("Clinic.txt", "r");
	if (file_1 == NULL)
	{
		printf("the file not Exit(Clinic file)\n");
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

	p = (Clinic*)malloc((sizef) * sizeof(Clinic)); 
	if (p == NULL) {
		printf("No momery allocation\n");
		exit(1);
	}
	fseek(file_1, 0, SEEK_SET);
	while (!feof(file_1)) {
		//fscanf(file_1, "%s", buff);
		p[i].id = (char*)malloc(strlen(buff) + 1 * sizeof(char));
		fscanf(file_1, "%s", p[i].id);
		//strcpy(p[i].id, buff);
		fgetc(file_1);
		p[i].NameOfClinic = (char*)malloc(strlen(buff) + 1 * sizeof(char));
		fscanf(file_1, "%s", p[i].NameOfClinic);
		i++;
	}
	fclose(file_1);
	return p;
}

int Confirmation_Switch_Req(char *id, char *clinic_choice)//func 7
{
	int i = 0;
	//FILE *ptr;
	Clinic *arr;
	int size = 0;
	int flag = 0;
	arr = readFile_clinic(&size);

	for (i = 0; i < size; i++)
	{
		if ((strcmp(arr[i].id, id) == 0))
		{
			strcpy(arr[i].NameOfClinic, clinic_choice);
			flag = 1;
		}
	}
	if (flag == 1)
	{
		UpdateClinicFile(arr, size);
		return true;
	}
	else
	{
		return false;
	}

}
//new (EDITED)
void UpdateClinicFile(Clinic *p, int size)
{
	FILE*file_1;
	int i = 0;
	file_1 = fopen("Clinic.txt", "w");
	if (file_1 == NULL)
	{
		printf("the file not Exit(Clinic file)\n");
		exit(1);
	}
	for (i = 0; i < size-1; i++)
	{
		fprintf(file_1, "%s %s\n", p[i].id, p[i].NameOfClinic);
	}
	fprintf(file_1, "%s %s", p[i].id, p[i].NameOfClinic);
	fclose(file_1);
}
void Requests(int funcNum) {//func 5
	char choice;
	int flag = 1;
	do{
	system("cls");
	printf("\t\t\t\t___<LMH>___\n\n(Requests)\n\nChoose Option:\n\n>>Clinic Switch Request - Press 1 then Enter\n- Request Passport - Press 2 then Enter\n>>Back to main menu - type q then Enter\n");
	fflush(stdin);
	scanf("%c", &choice);
	getchar();
		switch (choice)
		{
		case '1':
		{
					Clinic_Switch_Req(1);
					break;
		}
		case '2':
		{
					PassportRegisteration(42);
					break;
		}
		case 'q':
		{
			flag = 0;
			break;
		}
		default:
			break;
		}
	} while (flag);
}
/*                (NEW | 27/1) (Free Memory !!!)
///////////////////////////////////////////////////////
-------------------------------------------------------
        (Functions related to Req passport)
-------------------------------------------------------
///////////////////////////////////////////////////////
*/
void PassportRegisteration(int funcnum)//funnum 42
{
	char choice;
	Passport *pass;
	int i;
	int result = 0;
	int size=0;
	char Name[256], id[11], mailbox[256], PhoneNumber[11], Address[256];//variables
	system("cls");
	printf("\t\t\t\t___<LMH>___\n\n(Request Passport)\n- Press any key then enter to continue\n- Back to Menu - Press 'b' then Enter\n");
	scanf("%c", &choice);
	getchar();
	if (choice == 'b')
		return; //back to menu
	system("cls");
	printf("\t\t\t\t___<LMH>___\n\n(Request Passport)\n>> Enter your Name (First Name):\n>> ");
	scanf("%s",Name);
	printf("\n(DEBUGG) User Entered %s\n", Name);
	printf("\n>> Enter your id (10 Digits):\n>> ");
	scanf("%s", id);
	printf("\n(DEBUGG) User Entered %s\n", id);
	printf("\n>> Enter your mailbox (With Out Spaces):\n>> ");
	scanf("%s", mailbox);
	printf("\n(DEBUGG) User Entered %s\n", mailbox);
	printf("\n>> Enter your Address (With Out Spaces):\n>> ");
	scanf("%s", Address);
	printf("\n(DEBUGG) User Entered %s\n", Address);
	printf("\n>> Enter your Phone Number (10 Digits):\n>> ");
	scanf("%s", PhoneNumber);
	printf("\n(DEBUGG) User Entered %s\n", PhoneNumber);
	GetInfoIntoArr(&pass, &size);
	result = Check_Details(Name, id, mailbox, PhoneNumber, Address, pass, size);
	if (result)
	{
		//for (i = 0; i < size - 1; i++)
		//	printf("\n%s %s %s %s %s", pass[i].Name, pass[i].id, pass[i].Address, pass[i].PhoneNumber, pass[i].mailbox);
		//update the arr, means add the new customer req.
		pass[size-1].Name = (char*)malloc((strlen(Name) + 1) * sizeof(char));
		pass[size - 1].mailbox = (char*)malloc((strlen(mailbox) + 1) * sizeof(char));
		pass[size - 1].Address = (char*)malloc((strlen(Address) + 1) * sizeof(char));
		strcpy(pass[size - 1].Name, Name);
		strcpy(pass[size - 1].Address, Address);
		strcpy(pass[size - 1].mailbox, mailbox);
		strcpy(pass[size - 1].id, id);
		strcpy(pass[size - 1].PhoneNumber, PhoneNumber);
		for (i = 0; i < size; i++)
			printf("\n%s %s %s %s %s", pass[i].Name, pass[i].id, pass[i].Address, pass[i].PhoneNumber, pass[i].mailbox);
		//update the file.
		UpdateTheFile(&pass, size);
		//FreeMemoryOfPassportArr(&pass, size);
		printf(">> Congratz!,You'r Request has been successfully Added!\n");
		system("Pause");
	}
	else{
		//FreeMemoryOfPassportArr(&pass, size);
		printf("<<ERROR>> Unfortuntly, you'r request were not added , you'r ID is already in data base.\n");
		system("Pause");
	}
}
//launche this!!
void FreeMemoryOfPassportArr(Passport **p, int Size)
{
	int i = 0;
	for (i = 0; i < Size; i++)
	{
		free((*p)[i].Name);
		free((*p)[i].mailbox);
		//free((*p)[i].Address);
	}
	printf("DONE!\n");
	free((*p));
	printf("DONE2!\n");
}

void UpdateTheFile(Passport **p, int Size)
{
	//this is default index, means dont change anything (Not acutally accures but just for safemode).
	int i = 0;
	FILE *file_1;
	file_1 = fopen("passport.txt", "w");
	if (file_1 == NULL)
	{
		printf(">> The file Not exit(passport.txt)\n");
		exit(1);
	}
	//size-2 because we have accpeted them means to remove them .
	for (i = 0; i < Size-1; i++)
	{
			fprintf(file_1, "%s %s %s %s %s\n", (*p)[i].Name, (*p)[i].id, (*p)[i].Address, (*p)[i].PhoneNumber,(*p)[i].mailbox);
	}
	fprintf(file_1, "%s %s %s %s %s", (*p)[i].Name, (*p)[i].id, (*p)[i].Address, (*p)[i].PhoneNumber, (*p)[i].mailbox);
	fclose(file_1);
}
int ConfirmIdInPassportFile(Passport *pass, int Size, char* id)
{
	int i = 0;
	//-1 because we yet not added the new one
	for (i = 0; i < Size - 1; i++)
	{
		if (strcmp(pass[i].id, id) == 0)
			return 1;
	}
	return 0;
}
int Check_Details(char *Name, char id[11], char *mailbox, char *PhoneNumber, char *Address,Passport *pass,int Size)//funcnum 22
{
	//In this function we'll check that ID is not exists , as check point , then we add the customer request to the file.
	if (ConfirmIdInPassportFile(pass, Size, id))
		return 0;
	return 1;

}
/*this function read's the file and put the info into arr.*/
void GetInfoIntoArr(Passport **pass, int *Size)
{
	FILE*file_1;
	char buff[300];
	int sizef = 0, i = 0;
	file_1 = fopen("passport.txt", "r+");
	if (file_1 == NULL)
	{
		printf("the file not Exit(passport file)\n");
		system("Pause");
		return ;
	}
	while (!feof(file_1)) {
		fgets(buff, 300, file_1);
		sizef++;
	}
	//sizef--;
	*Size = sizef+1;//+1 because we want to add new one
	(*pass) = (Passport*)malloc((*Size) * sizeof(Passport));
	if ((*pass) == NULL) {
		printf("No momery allocation\n");
		exit(1);
	}
	fseek(file_1, 0, SEEK_SET);
	while (!feof(file_1)) {
		fscanf(file_1, "%s", buff);
		(*pass)[i].Name = (char*)malloc((strlen(buff) + 1) * sizeof(char));
		if ((*pass)[i].Name == NULL) {
			printf("No momery allocation\n");
			exit(1);
		}
		strcpy((*pass)[i].Name, buff); //here we copy the name
		fgetc(file_1);
		fscanf(file_1, "%s", (*pass)[i].id); //here we copy the id
		fgetc(file_1);
		(*pass)[i].Address = (char*)malloc((strlen(buff) + 1) * sizeof(char)); //here we copy the address
		fscanf(file_1, "%s", buff);
		strcpy((*pass)[i].Address, buff);
		fgetc(file_1);
		fscanf(file_1, "%s", (*pass)[i].PhoneNumber); //here we copy the phonnum
		fgetc(file_1);
		(*pass)[i].mailbox = (char*)malloc((strlen(buff) + 1) * sizeof(char));
		fscanf(file_1, "%s", buff);
		strcpy((*pass)[i].mailbox, buff); //here we copy the mailbox
		i++;
	}
	//for (i = 0; i < *Size - 1; i++)
	//	printf("\n%s %s %s %s %s", (*pass)[i].Name, (*pass)[i].id, (*pass)[i].Address, (*pass)[i].PhoneNumber, (*pass)[i].mailbox);

	fclose(file_1);
}

/*
///////////////////////////////////////////////////////
--------------------------------------------------------
///////////////////////////////////////////////////////
*/

//new, (ADDED Vehicle cancel Req)
void Transporation() {
	char choise;
	int flag = 1;
	do {
		printf("Welcome to Transporation Service\n1)Apeal Request for Driving Test\n2)view Driving Test Time\n3)Driving test Registration\n4)vehicle Registrations\n5)Cancel Regstrion Car\n6)return to customer Menu\n");

		scanf("%c", &choise);
		getchar();
		switch (choise) {
		case '1':
			Request_Objection();//cheak that!!
			break;
		case '2':
			Select_Date_ofTests();
			break;
		case '3':
			Select_suitableMonth();
			break;
		case '4':
			vehicle_Registrations();
			break;
		case '5':
			VehCancelReg(5);
			break;
		case '6':
			flag = 0;
			break;
		default:
			printf("Error Choise :( \n");
			break;
		}
	} while (flag);
}
/////////requests to driving test apealll///////////////
void Request_Objection() {
	char ptr[250];
	int flag = 1;
	DrivingTestAppeal *Dtp;// arr of Driving Test Appeal
	Dtp = (DrivingTestAppeal*)malloc(sizeof(DrivingTestAppeal));
	if (Dtp == NULL) {
		printf("No allocation Memomry\n");
		exit(1);
	}
	printf("enter your name\n");
	scanf("%s", ptr);
	getchar();
	Dtp->Name = (char*)malloc((strlen(ptr) + 1) * sizeof(char));
	if (Dtp->Name == NULL) {
		printf("No allocation Memomry\n");
		exit(1);
	}
	strcpy(Dtp->Name, ptr);
	printf("enter the id[0-9]\n");
	scanf("%s", Dtp->id);
	getchar();
	printf("enter the Tester Name\n");
	scanf("%s", ptr);
	getchar();
	Dtp->TesterName = (char*)malloc((strlen(ptr) + 1) * sizeof(char));
	if (Dtp->TesterName == NULL) {
		printf("No allocation Memomry\n");
		exit(1);
	}
	strcpy(Dtp->TesterName, ptr);
	printf("enter the MailBox\n");
	scanf("%d", &Dtp->MailBox);
	getchar();
	flag = 1;
	do {
		printf("enter your phone Number\n");
		scanf("%s", Dtp->PhoneNum);
		getchar();
		if (strlen(Dtp->PhoneNum) == 10)
			flag = 0;
		else
			printf("your input is not correct please try again the phone number must be 10 numbers\n");
	} while (flag);
	printf("enter the Date of DrvingTest(day,month,year)\n");
	scanf("%d%d%d", &Dtp->DrivetestDate.day, &Dtp->DrivetestDate.mounth, &Dtp->DrivetestDate.year);
	getchar();
	printf("enter the Reson of Appeal(notice:the reson must be 250 chars)***Notice->btween every words press[_]***\n");
	scanf("%s", ptr);
	getchar();
	Dtp->Reason = (char*)malloc((strlen(ptr) + 1) * sizeof(char));
	if (Dtp->Reason == NULL) {
		printf("No allocation Memomry\n");
		exit(1);
	}
	strcpy(Dtp->Reason, ptr);
	Update_objectiononDrivenTest(Dtp, 1);
	free(Dtp->Name);
	free(Dtp->TesterName);
	free(Dtp->Reason);
	free(Dtp);

}
void Update_objectiononDrivenTest(DrivingTestAppeal*Dta, int size){
	int sizee;
	DrivingTestAppeal*dtaa;
	dtaa = InitData_DrivingTestAppeal(&sizee);
	dtaa = (DrivingTestAppeal*)realloc(dtaa, sizeof(DrivingTestAppeal)*(sizee + 1));
	sizee += 1;
	dtaa[sizee - 1].Name = (char*)malloc((strlen(Dta->Name) + 1) * sizeof(char));
	if (dtaa[sizee - 1].Name == NULL)
	{
		printf("NO memory allcoation\n");
		exit(1);
	}
	strcpy(dtaa[sizee - 1].Name, Dta->Name);
	strcpy(dtaa[sizee - 1].id, Dta->id);
	dtaa[sizee - 1].TesterName = (char*)malloc((strlen(Dta->TesterName) + 1) * sizeof(char));
	if (dtaa[sizee - 1].TesterName == NULL)
	{
		printf("NO memory allcoation\n");
		exit(1);
	}
	strcpy(dtaa[sizee - 1].TesterName, Dta->TesterName);
	dtaa[sizee - 1].MailBox = Dta->MailBox;
	strcpy(dtaa[sizee - 1].PhoneNum, Dta->PhoneNum);
	dtaa[sizee - 1].DrivetestDate.day = Dta->DrivetestDate.day;
	dtaa[sizee - 1].DrivetestDate.mounth = Dta->DrivetestDate.mounth;
	dtaa[sizee - 1].DrivetestDate.year = Dta->DrivetestDate.year;
	dtaa[sizee - 1].Reason = (char*)malloc((strlen(Dta->Reason) + 1) * sizeof(char));
	if (dtaa[sizee - 1].Reason == NULL)
	{
		printf("NO memory allcoation\n");
		exit(1);
	}
	strcpy(dtaa[sizee - 1].Reason, Dta->Reason);
	update_DrivingTestAppealFile(dtaa, sizee);
}
/////// show Vaccinations///////////////////
void select_suitable_vaccinations() {
	int  flag = 1;
	int select;
	do {
		printf("1)age 1_6 monthes\n2)one year\n3)two year\n4)3 years\n5)4 years\n6)5 years\n7)6 years\n8)7-8years\n9)9-10years\n10)12-11 years\n11)13 years\n12)rteurn to helalthy Menu\n");
		scanf("%d", &select);
		getchar();
		switch (select)
		{
		case 1:
			print_the_vaccinations("1_6");
			break;
		case 2:
			print_the_vaccinations("1");
			break;
		case 3:
			print_the_vaccinations("2");
			break;
		case 4:
			print_the_vaccinations("3");
			break;
		case 5:
			print_the_vaccinations("4");
			break;
		case 6:
			print_the_vaccinations("5");
			break;
		case 7:
			print_the_vaccinations("6");
			break;
		case 8:
			print_the_vaccinations("7_8");
			break;
		case 9:
			print_the_vaccinations("9_10");
			break;
		case 10:
			print_the_vaccinations("11_12");
			break;
		case 11:
			print_the_vaccinations("13");
			break;
		case 12:
			flag = 0;
			break;
		default:
			printf("your select is not correct pelase try again:)\n");
			break;
		}
	} while (flag);

}
void print_the_vaccinations(char* select) {
	char*selectt;
	int size, i;
	Vaccinations*vac;
	selectt = (char*)malloc((strlen(select) + 1) * sizeof(char));
	if (selectt == NULL) {
		printf("No memory allocation\n");
		exit(1);
	}
	strcpy(selectt, select);
	vac = InitData_Vaccinations(&size);
	for (i = 0; i < size; i++) {
		if (strcmp(vac[i].age, selectt) == 0) {
			printf("The Vaccinations you sould to do\n");
			printf("%s", vac[i].NameOfVaccinations);
			printf("\n");
		}
	}
	free(selectt);
}
//////Religious Catgorey///////
void Religious(){
	char select;
	int flag = 1;
	do{
		printf("Welocome to Religious Catogriey\n1)Show the Religious-holiday to this year\n2)change the Religious\n3)Return to Coustomer Menu\n");
		scanf("%c", &select);
		printf("%c\n", select);
		getchar();
		switch (select){
		case '1':
			Religious_Holidays();
			break;
		case'2':
			Change_religion();
			break;
		case '3':
			flag = 0;
			break;
		default:
			printf("your select is not correct please Try Again\n");
			break;
		}

	} while (flag);
}
/////// show the Religious Holiday////////////
void Religious_Holidays(){
	char select;
	int flag = 1;
	do{
		printf("Religious Holiday\n1)Jewish religion Holidays\n2)Islamic religion Holidays\n3)Christian religion Holidays\n4)show all religions-Holidays\n5)Back to Religions Menu\n");
		scanf("%c", &select);
		getchar();
		switch (select){
		case'1':
			Show_the_regligiousHoidays("Jewish_religion");
			break;
		case'2':
			Show_the_regligiousHoidays("Islamic_religion");
			break;
		case '3':
			Show_the_regligiousHoidays("Christian_religion");
			break;
		case'4':
			Show_the_regligiousHoidays("all_religion");
			break;
		case '5':
			flag = 0;
			break;
		default:
			printf("your Select is not Correct please Try Again\n");
			break;
		}
	} while (flag);

}
void Show_the_regligiousHoidays(char*RelName){
	char*relname;
	int size;
	int i, j;
	Holidays*holiday;
	relname = (char*)malloc((strlen(RelName) + 1) * sizeof(char));
	if (relname == NULL){
		printf("No Memory Allocataion\n");
		exit(1);
	}
	strcpy(relname, RelName);
	holiday = InitData_Holidays(&size);
	if (strcmp(relname, "all_religion") == 0){
		for (i = 0; i < size; i++){
			printf("%s {%s} -> [ %s ]\n", holiday[i].ReligiousName, holiday[i].HolidayName, holiday[i].date);
		}
	}
	else{
		for (j = 0; j < size; j++)
		{
			if (strcmp(holiday[j].ReligiousName, relname) == 0)
				printf("%s  {%s} -> [ %s ] \n", holiday[j].ReligiousName, holiday[j].HolidayName, holiday[j].date);
		}
	}
	free(relname);
}
////show Driving test Times////////////
void Select_Date_ofTests(){
	int select;
	int flag = 1;
	do{
		printf("DrivenTests Date\n1)January\n2)February\n3)March\n4)April\n5)May\n6)June\n7)July\n8)August\n9)September\n10)October\n11)November\n12)December\n13)show all driven Test Date\n14)return to Transporation\n");
		scanf("%d", &select);
		getchar();
		switch (select)
		{
		case 1:
			Show_Drivingtest("January");
			break;
		case 2:
			Show_Drivingtest("February");
			break;
		case 3:
			Show_Drivingtest("March");
			break;
		case 4:
			Show_Drivingtest("April");
			break;
		case 5:
			Show_Drivingtest("May");
			break;
		case 6:
			Show_Drivingtest("June");
			break;
		case 7:
			Show_Drivingtest("July");
			break;
		case 8:
			Show_Drivingtest("August");
			break;
		case 9:
			Show_Drivingtest("September");
			break;
		case 10:
			Show_Drivingtest("October");
			break;
		case 11:
			Show_Drivingtest("November");
			break;
		case 12:
			Show_Drivingtest("December");
			break;
		case 13:
			Show_Drivingtest("all");
			break;
		case 14:
			flag = 0;
			break;
		default:
			printf("your select is not correct please Try Again\n");
			break;
		}
	} while (flag);
}
void Show_Drivingtest(char* Select){
	DrivingTest*Dtest;
	int size;
	int i, j, counter = 0;
	char*monthselect;
	monthselect = (char*)malloc((strlen(Select) + 1)*sizeof(char));
	if (monthselect == NULL){
		printf("no Memory Allocation\n");
		exit(1);
	}
	strcpy(monthselect, Select);
	Dtest = InitData_DrivingTest(&size);
	if (strcmp(monthselect, "all") == 0){
		for (i = 0; i < size; i++)
			printf("%s -->[ %s ]-->[ %s ]\n", Dtest[i].Month, Dtest[i].date, Dtest[i].Address);
	}
	else{
		for (j = 0; j < size; j++){
			if (strcmp(Dtest[j].Month, monthselect) == 0){
				counter++;
				printf("%s -->[ %s ]-->[ %s ]\n", Dtest[j].Month, Dtest[j].date, Dtest[j].Address);
			}
		}
		if (counter == 0)
			printf("the month your select does not have Driven Test chose another Month Thank you\n");
	}
	free(monthselect);
}// cheak that!!! 
//////////////Customer Servey//////////////////
void Service_Survey(){
	char buff[300];
	Customer_Survey C;
	int Assests;

	printf("Hello welcome to service_survey for customer\n");
	printf("Enter your name\n");
	scanf("%s", buff);

	printf("Enter your opinion in Survey Web Site\n");
	printf("1)VeryGood-press 1\n2)Good-press 2\n3)NotBad-press 3\n4)Bad-press 4\n5)should to devlop this site-press 5\n");
	scanf("%d", &Assests);
	if (checkInput_Service_Survey(buff, Assests))
		printf("Thank you for your time\n");
	else
		printf("You enter wrong Survey. Thnak you\n");
	C.Name = buff;
	C.Assess = Assests;
	Update_the_Service_Survey(&C, 1);

}
int checkInput_Service_Survey(char* name, int Assests){
	int i = 0;
	for (i = 0; name[i]; i++){
		if (!((name[i] >= 'a' && name[i] <= 'z') || (name[i] >= 'A'&& name[i] <= 'Z')))
			return 0;
	}
	if (Assests < 1 || Assests > 5)
		return 0;

	return 1;
}
void Update_the_Service_Survey(Customer_Survey*CustS, int size){
	Customer_Survey*custs;
	int sizee;
	custs = InitData_customerServey(&sizee);
	custs = (Customer_Survey*)realloc(custs, sizeof(Customer_Survey)*(sizee + 1));
	if (custs == NULL)
	{
		printf("No Memory Allocation\n");
		exit(1);
	}

	sizee += 1;
	custs[sizee - 1].Name = (char*)malloc((strlen(CustS->Name) + 1)*sizeof(char));
	if (custs[sizee - 1].Name == NULL)
	{
		printf("No Memory Allocation\n");
		exit(1);
	}
	strcpy(custs[sizee - 1].Name, CustS->Name);
	custs[sizee - 1].Assess = CustS->Assess;
	Update_the_Service_SurveyFile(custs, sizee);
}//cheak that !
//////////////vehicle_Registrations///////////
////////Regstretion to vehicle /////////////////////
void vehicle_Registrations(){
	char id[10];
	Vehicles*vec;
	int result, sizee;
	vec = InitData_Vehicles(&sizee);
	printf("Hello welcome to Registration Vehicle\n");
	printf("please enter the ID\n");
	scanf("%s", id);
	if ((result = cheak_IdVehicle_customer(id, vec, sizee)) == True)
		Add_new_Carnumber(id, vec, sizee);
	else
		Add_new_custcar();
}
int cheak_IdVehicle_customer(char*Id, Vehicles*vecc, int sizee){
	int i;
	for (i = 0; i < sizee; i++){
		if (strcmp(vecc[i].id, Id) == 0)
			return True;
	}
	return False;
}
void Add_new_Carnumber(char*id, Vehicles*vecc, int sizee){
	Vehicles*vec;
	int size, i, j;
	char buff[300];
	printf("printf enter the number of cars you want to add\n");
	scanf("%d", &size);
	getchar();
	vec = (Vehicles*)malloc(size*sizeof(Vehicles));
	if (vec == NULL){
		printf("NO memory allocation\n");
		exit(1);
	}
	for (i = 0; i < size; i++){
		for (j = 0; j < sizee; j++)
		if (strcmp(vecc[j].id, id) == 0){
			vec[i].Name = (char*)malloc((strlen(vecc[j].Name) + 1)*sizeof(char));
			if (vec[i].Name == NULL){
				printf("NO memory allocation\n");
				exit(1);
			}
			strcpy(vec[i].Name, vecc[j].Name);
			strcpy(vec[i].id, id);
			strcpy(vec[i].PhoneNumber, vecc[j].PhoneNumber);
			printf("enter the new car Number(number[%d])\n", i + 1);
			scanf("%s", buff);
			getchar();
			vec[i].CarNumber = (char*)malloc((strlen(buff) + 1)*sizeof(char));
			if (vec[i].CarNumber == NULL){
				printf("NO memory allocation\n");
				exit(1);
			}
			strcpy(vec[i].CarNumber, buff);
			break;
		}
	}

	Update_CustCar(vec, size);
	for (i = 0; i < size; i++){
		free(vec[i].Name);
		free(vec[i].CarNumber);
	}
	free(vec);
}
void Add_new_custcar(){
	int i, size;
	char buff[300], pn[11], id[10], Cn[300];
	Vehicles*vec;
	printf("hello this is A first use in this service\n");
	printf("enter the number of car you want to Register\n");
	scanf("%d", &size);
	getchar();
	vec = (Vehicles*)malloc(size*sizeof(Vehicles));
	if (vec == NULL){
		printf("NO memory allocation\n");
		exit(1);
	}
	printf("enter your name\n");
	scanf("%s", buff);
	getchar();
	printf("enter your Id\n");
	scanf("%s", id);
	getchar();
	printf("enter you PhoneNumber\n");
	scanf("%s", pn);
	getchar();
	for (i = 0; i < size; i++){
		vec[i].Name = (char*)malloc((strlen(buff) + 1)*sizeof(char));
		if (vec[i].Name == NULL){
			printf("No memory allocation\n");
			exit(1);
		}
		strcpy(vec[i].Name, buff);
		strcpy(vec[i].id, id);
		strcpy(vec[i].PhoneNumber, pn);
		printf("enter the the car number[%d]\n", i + 1);
		scanf("%s", Cn);
		getchar();
		vec[i].CarNumber = (char*)malloc((strlen(Cn) + 1)*sizeof(char));
		if (vec[i].CarNumber == NULL){
			printf("No memory allocation\n");
			exit(1);
		}
		strcpy(vec[i].CarNumber, Cn);
	}

	Update_CustCar(vec, size);
	for (i = 0; i < size; i++){
		free(vec[i].Name);
		free(vec[i].CarNumber);
	}
	free(vec);
}
void Update_CustCar(Vehicles*vecc, int size){
	Vehicles*newvec;
	int sizee1, sizee2, i;
	newvec = InitData_Vehicles(&sizee1);
	sizee2 = sizee1;
	sizee1 += size;
	newvec = (Vehicles*)realloc(newvec, sizee1*sizeof(Vehicles));
	for (i = 0; i < size; i++){
		newvec[sizee2 + i].Name = (char*)malloc((strlen(vecc[i].Name) + 1)*sizeof(char));
		if (newvec[sizee2 + i].Name == NULL){
			printf("no memory Allocation");
			exit(1);
		}
		strcpy(newvec[sizee2 + i].Name, vecc[i].Name);
		strcpy(newvec[sizee2 + i].id, vecc[i].id);
		strcpy(newvec[sizee2 + i].PhoneNumber, vecc[i].PhoneNumber);
		newvec[sizee2 + i].CarNumber = (char*)malloc((strlen(vecc[i].CarNumber) + 1)*sizeof(char));
		if (newvec[sizee2 + i].CarNumber == NULL){
			printf("NO memory allocation\n");
			exit(1);
		}
		strcpy(newvec[sizee2 + i].CarNumber, vecc[i].CarNumber);
	}
	update_VehiclesFile(newvec, sizee1);
}
//////////// change the Religious//////////
void Change_religion(){
	char id[10];
	int flag = 1, f;
	do{
		printf("enter your id\n");
		scanf("%s", id);
		getchar();
		if (cheakid_Customer(id) == True){
			update_Idreligion(id);
			flag = 0;
		}
		else{
			printf("*********************************************\n");
			printf("1)the id is not correct\n or\n2)the id isnot Available(if is not Available you should to return to customer menu to request id\n");
			printf("if the id is not Available press 0(any number) if you want to try again press[1]\n");
			scanf("%d", &f);
			getchar();
			flag = f;
		}
	} while (flag);
}
int cheakid_Customer(char*id){
	int i, sizee;
	ID*idd;
	idd = InitData_ID(&sizee);
	for (i = 0; i < sizee; i++){
		if (strcmp(idd[i].Id, id) == 0)
			return True;
	}
	return False;
}
void update_Idreligion(char*id){
	int sizee, i, flag = 1, j;
	char select;
	char buff[300];
	ID*idd;
	idd = InitData_ID(&sizee);
	for (i = 0; i < sizee; i++)
	{
		if (strcmp(idd[i].Id, id) == 0){
			j = i;
			printf("****************************************************\n");
			printf("FisrtName:%s\nLastName:%s\nID:%s\nCurrent Religion:%s\nGender:%c\n", idd[i].FirstName, idd[i].LastName, idd[i].Id, idd[i].Relegion, idd[i].Gender);
			printf("Birthday[%d/%d/%d]\n", idd[i].Date.day, idd[i].Date.mounth, idd[i].Date.year);
			do{
				printf("********************************************\n");
				printf("select the new ReligionName you want to change in your id\n");
				printf("1-Jewich\n2-Musluim\n3-christian\n4-you can selecet diffrent type ofReligionName\n5-return(if you dont want to change)\n");
				scanf("%c", &select);
				getchar();
				switch (select)
				{
				case '1':
					strcpy(idd[i].Relegion, "jewish");
					flag = 0;
					break;
				case'2':
					strcpy(idd[i].Relegion, "muslem");
					flag = 0;
					break;
				case '3':
					strcpy(idd[i].Relegion, "christian");
					flag = 0;
					break;
				case '4':
					scanf("%s", buff);
					getchar();
					idd[i].Relegion = (char*)malloc((strlen(buff) + 1)*sizeof(char));
					if (idd[i].Relegion == NULL){
						printf("no memory allocation\n");
						exit(1);
					}
					strcpy(idd[i].Relegion, buff);
					flag = 0;
					break;
				case '5':
					flag = 0;
					break;
				default:
					printf("Error choise please Try Again\n");
					break;
				}
			} while (flag);

		}
	}
	for (i = 0; i < sizee; i++){
		if (i == j){
			printf("******************** your ID NOW*******************\n");
			printf("FisrtName:%s\nLastName:%s\nID%s\nReligion:%s\nGender:%c\n", idd[i].FirstName, idd[i].LastName, idd[i].Id, idd[i].Relegion, idd[i].Gender);
			printf("Birthday[%d/%d/%d]\n", idd[i].Date.day, idd[i].Date.mounth, idd[i].Date.year);
		}
	}
	update_IDFile(idd, sizee);
}
//////////////////// change details Coustomer_id//////////////
void  Show_CustDeatils(){
	ID *idd;
	char id[10];
	char select;
	int sizee, i, flag = 1;
	idd = InitData_ID(&sizee);
	do{
		printf("*********change ID Details*********\n");
		printf("1)enter the id-press 1\n2)return to the customer Menu-press 2\n");
		scanf("%c", &select);
		getchar();
		switch (select){
		case'1':
			printf("enter the id\n");
			scanf("%s", id);
			getchar();
			if (cheakid_Customer(id) == True){
				printf("****your Current Details*****\n");
				for (i = 0; i < sizee; i++){
					if (strcmp(idd[i].Id, id) == 0){
						printf("FisrtName:%s\nLastName:%s\nID%s\nReligion:%s\nGender:%c\n", idd[i].FirstName, idd[i].LastName, idd[i].Id, idd[i].Relegion, idd[i].Gender);
						printf("Birthday[%d/%d/%d]\n", idd[i].Date.day, idd[i].Date.mounth, idd[i].Date.year);
						Select_DetailtoChange(id);
					}
				}
			}
			else{
				printf("*********************************************\n");
				printf("1)the id is not correct\n or\n2)the id isnot Available(if is not Available you should to return to customer menu to request id\n");
				printf("***********************************************\n");
			}
			break;
		case '2':
			flag = 0;
			break;
		default:
			printf("your select is not true please Try Agian\n");
			break;
		}
	} while (flag);
}
void Select_DetailtoChange(char*id){
	int flag = 1;
	char select;
	do{
		printf("******************\n");
		printf("select what you want to change\n");
		printf("1)FirstName\n2)LastName\n3)Gender\n4)BirthDate\n5)Return(if you dont want to change)\n");
		scanf("%c", &select);
		getchar();
		switch (select){
		case '1':
			Change_Deatils(id, 1);
			break;
		case'2':
			Change_Deatils(id, 2);
			break;
		case '3':
			Change_Deatils(id, 3);
			break;
		case'4':
			Change_Deatils(id, 4);
			break;
		case'5':
			flag = 0;
			break;
		default:
			printf("your select is not correct (if you want to change Religion please return to customerMenu->Religion Catogrey\n");
			break;
		}
	} while (flag);
}
void Change_Deatils(char*id, int select){
	int i;
	ID *idd;
	int sizee, j;
	char buff[300], gender;
	idd = InitData_ID(&sizee);
	for (i = 0; i < sizee; i++){
		if (strcmp(idd[i].Id, id) == 0){
			j = i;
			if (select == 1){
				printf("****************\n");
				printf("Enter the New FirstName\n");
				scanf("%s", buff);
				getchar();
				idd[i].FirstName = (char*)malloc((strlen(buff) + 1)*sizeof(char));
				if (idd[i].FirstName == NULL){
					printf("NO memory Allocation\n");
					exit(1);
				}
				strcpy(idd[i].FirstName, buff);
			}
			else if (select == 2){
				printf("****************\n");
				printf("Enter the New LastName\n");
				scanf("%s", buff);
				getchar();
				idd[i].LastName = (char*)malloc((strlen(buff) + 1)*sizeof(char));
				if (idd[i].LastName == NULL){
					printf("NO memory Allocation\n");
					exit(1);
				}
				strcpy(idd[i].LastName, buff);
			}
			else if (select == 3){
				printf("****************");
				printf("Enter the New Gender(enter F or M)\n");
				scanf("%c", &gender);
				getchar();
				idd[i].Gender = gender;
			}
			else{
				printf("****************");
				printf("enter\nday\tmonth\tyear\n");
				scanf("%d%d%d", &idd[i].Date.day, &idd[i].Date.mounth, &idd[i].Date.year);
				getchar();
			}
		}
	}
	//// cheaking just
	for (i = 0; i < sizee; i++){
		if (i == j){
			printf("******************** your ID NOW*******************\n");
			printf("FisrtName:%s\nLastName:%s\nID:%s\nReligion:%s\nGender:%c\n", idd[i].FirstName, idd[i].LastName, idd[i].Id, idd[i].Relegion, idd[i].Gender);
			printf("Birthday[%d/%d/%d]\n", idd[i].Date.day, idd[i].Date.mounth, idd[i].Date.year);
		}
	}
	update_IDFile(idd, sizee);
}
//////////////////Regstrition to DrivingTest///////////////
void Select_suitableMonth(){
	int select;
	int flag = 1;
	do{
		printf("DrivenTests Date\n1)January\n2)February\n3)March\n4)April\n5)May\n6)June\n7)July\n8)August\n9)September\n10)October\n11)November\n12)December\n13)show all driven Test Date\n14)return to Transporation\n");
		scanf("%d", &select);
		getchar();
		switch (select)
		{
		case 1:
			Show_Driving_tests("January");
			break;
		case 2:
			Show_Driving_tests("February");
			break;
		case 3:
			Show_Driving_tests("March");
			break;
		case 4:
			Show_Driving_tests("April");
			break;
		case 5:
			Show_Driving_tests("May");
			break;
		case 6:
			Show_Driving_tests("June");
			break;
		case 7:
			Show_Driving_tests("July");
			break;
		case 8:
			Show_Driving_tests("August");
			break;
		case 9:
			Show_Driving_tests("September");
			break;
		case 10:
			Show_Driving_tests("October");
			break;
		case 11:
			Show_Driving_tests("November");
			break;
		case 12:
			Show_Driving_tests("December");
			break;
		case 13:
			Show_Driving_tests("all");
			break;
		case 14:
			flag = 0;
			break;
		default:
			printf("your select is not correct please Try Again\n");
			break;
		}
	} while (flag);
}
void Show_Driving_tests(char*month){
	DrivingTest*Dtest;
	int size;
	int i, j, counter = 0;
	char*monthselect;
	monthselect = (char*)malloc((strlen(month) + 1)*sizeof(char));
	if (monthselect == NULL){
		printf("no Memory Allocation\n");
		exit(1);
	}
	strcpy(monthselect, month);
	Dtest = InitData_DrivingTest(&size);
	if (strcmp(monthselect, "all") == 0){
		for (i = 0; i < size; i++)
			printf("%s -->[ %s ]-->[ %s ]\n", Dtest[i].Month, Dtest[i].date, Dtest[i].Address);
	}
	else{
		for (j = 0; j < size; j++){
			if (strcmp(Dtest[j].Month, monthselect) == 0){
				counter++;
				printf("%s -->[ %s ]-->[ %s ]\n", Dtest[j].Month, Dtest[j].date, Dtest[j].Address);
			}
		}
		if (counter == 0)
			printf("the month your select does not have Driven Test chose another Month Thank you\n");
	}
	Registration_to_Driving_test();
	free(monthselect);
}
void Registration_to_Driving_test(){
	DrivingTestRegistration*dtr;
	int sizee, i, flag = 1, d, m, y;
	char buff[300];
	dtr = InitData_DrivingTestReg(&sizee);
	dtr = (DrivingTestRegistration*)realloc(dtr, (sizee + 1)*sizeof(DrivingTestRegistration));
	if (dtr == NULL){
		printf("No Memory Allocation\n");
		exit(1);
	}
	sizee += 1;
	printf("************************************\n");
	printf("enter your name\n");
	scanf("%s", buff);
	getchar();
	dtr[sizee - 1].Name = (char*)malloc((strlen(buff) + 1)*sizeof(char));
	if (dtr[sizee - 1].Name == NULL){
		printf("No Memory Allocation\n");
		exit(1);
	}
	strcpy(dtr[sizee - 1].Name, buff);
	printf("Enter the ID\n");
	scanf("%s", dtr[sizee - 1].id);
	getchar();
	printf("Enter the PhoneNumber\n");
	scanf("%s", dtr[sizee - 1].PhoneNumber);
	getchar();
	printf("Enter the MailBox\n");
	scanf("%d", &dtr[sizee - 1].MailBox);
	getchar();
	do{
		printf("Enter the TestDate\n");
		scanf("%d%d%d", &d, &m, &y);
		getchar();
		flag = cheakDate(d, m, y);
		if (flag == 1){
			dtr[sizee - 1].DateofTest.day = d;
			dtr[sizee - 1].DateofTest.mounth = m;
			dtr[sizee - 1].DateofTest.year = y;
		}
		else
			printf("you  input is not correct please Try Again\n");

	} while (flag == 0);
	///just to cheak
	for (i = 0; i < sizee; i++){
		printf("%s %s %s %d %d %d %d\n", dtr[i].Name, dtr[i].id, dtr[i].PhoneNumber, dtr[i].MailBox, dtr[i].DateofTest.day, dtr[i].DateofTest.mounth, dtr[i].DateofTest.year);
	}
	update_DrivingTestRegFile(dtr, sizee);
}
int cheakDate(int day, int month, int year){
	if (year == 2017){
		if (month == 2 && day >= 1 && day <= 28)
			return 1;
		else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day >= 1 && day <= 31)
			return 1;
		else if ((month == 4 || month == 6 || month == 9 || month == 11) && day >= 1 && day <= 30)
			return 1;
	}
	return 0;
}
//////////////Cancel Restrition to Car//////////
void VehCancelReg(int funcNum){
	char id[10];
	int flag = 1;
	Vehicles*vecc;
	int size;
	vecc = InitData_Vehicles(&size);
	do{
		printf("Enter the id");
		scanf("%s", id);
		getchar();
		if (cheak_IdVehicle_customer(id, vecc, size) == True){
			Confirmation(id, vecc, size);
			flag = 0;
		}
		else{
			printf("your id is not correct\n");
			printf("****************\n");
			flag = 0;
		}
	} while (flag);
}
void Confirmation(char*id, Vehicles* vecc, int size){
	int i, sizee, j = 0;
	char *idd, buff[300];
	Vehicles*vec;
	idd = (char*)malloc((strlen(id) + 1)*sizeof(char));
	if (idd == NULL){
		printf("NO Memory Allocation\n");
		exit(1);
	}
	strcpy(idd, id);
	for (i = 0; i < size; i++){
		if (strcmp(vecc[i].id, idd) == 0){
			printf("%s %s %s %s\n", vecc[i].Name, vecc[i].id, vecc[i].PhoneNumber, vecc[i].CarNumber);
			printf("******************************************\n");
		}
	}
	printf("Enter the car you want to change\n");
	scanf("%s", buff);
	getchar();
	sizee = size - 1;
	vec = (Vehicles*)malloc(sizee*sizeof(Vehicles));
	if (vec == NULL){
		printf("NO Memory Allocation\n");
		exit(1);
	}
	for (i = 0; i < size; i++){
		if (strcmp(vecc[i].CarNumber, buff) != 0){
			vec[j].Name = (char*)malloc((strlen(vecc[i].Name) + 1)*sizeof(char));
			if (vec[j].Name == NULL){
				printf("NO Memory Allocation\n");
				exit(1);
			}
			strcpy(vec[j].Name, vecc[i].Name);
			strcpy(vec[j].id, vecc[i].id);
			strcpy(vec[j].PhoneNumber, vecc[i].PhoneNumber);
			vec[j].CarNumber = (char*)malloc((strlen(vecc[i].CarNumber) + 1)*sizeof(char*));
			if (vec[j].CarNumber == NULL){
				printf("NO Memory Allocation\n");
				exit(1);
			}
			strcpy(vec[j].CarNumber, vecc[i].CarNumber);
			j++;
		}
	}
	for (j = 0; j < sizee; j++){
		vecc[j].Name = (char*)malloc((strlen(vec[j].Name) + 1)*sizeof(char));
		if (vecc[j].Name == NULL){
			printf("NO Memory Allocation\n");
			exit(1);
		}
		strcpy(vecc[j].Name, vec[j].Name);
		strcpy(vecc[j].id, vec[j].id);
		strcpy(vecc[j].PhoneNumber, vec[j].PhoneNumber);
		vecc[j].CarNumber = (char*)malloc((strlen(vec[j].CarNumber) + 1)*sizeof(char*));
		if (vecc[j].CarNumber == NULL){
			printf("NO Memory Allocation\n");
			exit(1);
		}
		strcpy(vecc[j].CarNumber, vec[j].CarNumber);
	}
	size = sizee;
	for (i = 0; i < sizee; i++){
		free(vec[i].Name);
		free(vec[i].CarNumber);
	}
	free(vec);
	update_VehiclesFile(vecc, size);
}
		

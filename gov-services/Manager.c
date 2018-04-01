
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>  
#include <string.h>

#include "Functions.h"

//new (EDITED)
//there are new edites here , such size worker array and manager_menu parameter added.
Workers*Worker;
int SizeoFWorkers;
void Manager_Menu(Workers *p, int *size, int indexofworker){
	int flag = 1;
	char choice;
	Worker = p;
	SizeoFWorkers = *size;
	do{
	system("cls");
	//printf is new
	printf("\t\t\t\t___<LMH>___\n\n\t\t\t\n                            Logged as 'Manager'\n\n\nWelcome '%s',\n\n\nChoose Option:\n- Manage Requests - Press 1 then Enter\n- Add Employee - Press 2 then Enter\n- Modify Employee Details - Press 3 then Enter\n- Transprition - Press 4 then Enter\n- View Applicants - Press 5 then Enter\n- View Workers - Press 6 then Enter\n- View Workshops - Press 7 then Enter\n- Funding Request - Press 8 then Enter\n- Log Out - Press 9 then Enter\n", Worker[indexofworker].Name);
	//fflush(stdin);
	scanf("%c", &choice);
	_flushall();
		switch (choice)
		{
		//CASE 1 IS NEW
		case '1':
		{
					certifications(1);
					break;
		}
		case '2':
		{
					Add_Employee(1);
					break;
		}
		case '3':
		{
					Modify_Employee_Details(1); //new 27/1/2017
					break;
		}

		case '4':
		{
					Transprition_Manager();
					break;
		}
			///new
			//lama'scases
		case '5':
		{
					viewApplicants();
					break;
		}
			///new
		case '6':
		{
					viewWorkers();
					break;
		}
			///new
		case '7': {
					  viewWorkshops();
					  break;
		}
			///new
		case '8': {
					  funding_request();
					  break;
		}
		case '9': {
					  flag = 0;
					  break;
		}
		default:
			break;
		}
	} while (flag);
}



//hanan
/////////Show Driving TestAppeal////////////
void Select_MonthOFObjection(){
	int select;
	int flag = 1;
	printf("Hello Manager\n");
	do{
		printf("press the number of Month you want to show\n*********\n1)January-press 1\n2)February-press 2\n3)March-press 3\n4)April-press 4\n");
		printf("5)May-press 5\n6)June-press 6\n7)July-press 7\n8)August-press8\n9)September-press 9\n10)October-press 10\n11)November-press 11\n");
		printf("12)December-press 12\n13)show all driven Test Date-press 13\n14)return to Transporation-press 14\n");
		scanf("%d", &select);
		_flushall();
		switch (select)
		{
		case 1:
			Show_the_Objection(select);
			break;
		case 2:
			Show_the_Objection(select);
			break;
		case 3:
			Show_the_Objection(select);
			break;
		case 4:
			Show_the_Objection(select);
			break;
		case 5:
			Show_the_Objection(select);
			break;
		case 6:
			Show_the_Objection(select);
			break;
		case 7:
			Show_the_Objection(select);
			break;
		case 8:
			Show_the_Objection(select);
			break;
		case 9:
			Show_the_Objection(select);
			break;
		case 10:
			Show_the_Objection(select);
			break;
		case 11:
			Show_the_Objection(select);
			break;
		case 12:
			Show_the_Objection(select);
			break;
		case 13:
			Show_the_Objection(select);
			break;
		case 14:
			flag = 0;
			break;
		default:
			printf("your select is not correct please Try Again\n");
			printf("**********************\n");
			break;
		}
	} while (flag);

}
void Show_the_Objection(int month_select){
	int sizee;
	int i, counter = 0;
	DrivingTestAppeal*dta;
	dta = InitData_DrivingTestAppeal(&sizee);
	if (month_select == 13){
		for (i = 0; i < sizee; i++){
			counter += 1;
			printf("*******************\n");
			printf("%s %s %s %d %s ", dta[i].Name, dta[i].id, dta[i].TesterName, dta[i].MailBox, dta[i].PhoneNum);
			printf("%d %d %d %s\n", dta[i].DrivetestDate.day, dta[i].DrivetestDate.mounth, dta[i].DrivetestDate.year, dta[i].Reason);
		}
	}
	else{
		for (i = 0; i < sizee; i++){
			if (dta[i].DrivetestDate.mounth == month_select){
				counter += 1;
				printf("*******************\n");
				printf("%s %s %s %d %s ", dta[i].Name, dta[i].id, dta[i].TesterName, dta[i].MailBox, dta[i].PhoneNum);
				printf("%d %d %d %s\n", dta[i].DrivetestDate.day, dta[i].DrivetestDate.mounth, dta[i].DrivetestDate.year, dta[i].Reason);
			}
		}
	}
	if (counter == 0){
		printf("*************************\n");
		printf(" the month you select[%d] is dont have apealsDrivenTest\n", month_select);
	}
	printf("*******************\n");

}
//end of hanan


/*These functions related to modify employee details*/
//new 27/1/2017
void Modify_Employee_Details(int funcnum){//funcnum 19
char id[256];
int result = 0;
system("cls");
printf("\t\t\t\t___<LMH>___\n\n\t\t\t     Logged as 'Manager'\n(Modify Employee Details)\n>> Enter the Employee ID(must be 10 chars): ");
scanf("%s", &id);
_flushall();
result=Varify(id);
if (result == 0)
{
	printf("<<ERROR>> The Employee that you are searching for is not exists, try later!\n");
	system("Pause");
}
else if (result == -1)
{
	printf("<<ERROR>> Incorrect Index, The Worker is not founded in the data base!\n");
	system("Pause");
}
else if (result == -2)
{
	printf("<<NOTE>> You are backing to the menu\n");
	system("Pause");
}
}
//new 27/1/2017
int Varify(char* id){//funcnum 20
	int size=0, flag = 0, index = -1, ind;
	int i;
	char name[256], phonenum[11], Address[256], Pass[10];
	int BankAcc;
	float Age;
	Workers *p = readFile_Workers(&size);
	for (i = 0; i < size; i++)
	{
		if (strcmp(p[i].Id, id) == 0){
			index = i;
			flag = 1;
			break;
		}
	}
	if (flag == 0)
		return 0; //not found , you can't modify!
	if (index == -1)
		return -1;
	//else
	printf("\n\n>> You are about to change the details of '%s'\n", p[index].Name);
	do{
		printf("\n<!> Choose what do you want to modify:-");
		printf("\n1)Name\n2)Bank Account\n3)Address\n4)Phone Number\n5)Age\n6)Password\n7)Nothing - Back to Menu\n>> ");
		scanf("%d", &ind);
		_flushall();
		switch (ind)
		{
		case 1:
		{
				  //replace via re malloc

				  printf(">> Enter new name (First Name): ");
				  scanf("%s", name);
				  _flushall();
				  free(p[index].Name);
				  p[index].Name = (char*)malloc((strlen(name) + 1)*sizeof(char));
				  strcpy(p[index].Name, name);
				  printf(">> Name has been Successfully changed to %s\n", p[index].Name);
				  system("Pause");
				  break;
		}
		case 2:
		{
				  printf(">> Enter new Bank Account: ");
				  scanf("%d", &BankAcc);
				  _flushall();
				  p[index].BankACC = BankAcc;
				  printf(">> Bank Account of '%s' has been Successfully Changed to %d\n", p[index].Name, p[index].BankACC);
				  system("Pause");
				  break;
		}
		case 3:
		{
				  //replace via re malloc

				  printf(">> Enter new Address (With out spaces): ");
				  scanf("%s", Address);
				  _flushall();
				  free(p[index].Adress);
				  p[index].Adress = (char*)malloc((strlen(Address) + 1)*sizeof(char));
				  strcpy(p[index].Adress, Address);
				  printf(">> The Address of '%s' has been Successfully Changed to %s\n", p[index].Name, p[index].Adress);
				  system("Pause");
				  break;
		}
		case 4:
		{
				  printf(">> Enter new Phone Number (10 Digits): ");
				  scanf("%s", phonenum);
				  _flushall();
				  strcpy(p[index].phoneNumber, phonenum);
				  printf(">> The Phone number of '%s' has been Successfully Changed to %s\n", p[index].Name, p[index].phoneNumber);
				  break;
		}
		case 5:
		{
				  printf(">> Enter new Age: ");
				  scanf("%f", &Age);
				  _flushall();
				  p[index].age = Age;
				  printf(">> The Age of '%s' has been Successfully Changed to %f\n", p[index].Name, p[index].age);
				  system("Pause");
				  break;
		}
		case 6:
		{
				  //replace via re malloc
				  printf(">> Enter new Password for '%s': ", p[index].Name);
				  scanf("%s", Pass);
				  _flushall();
				  free(p[index].Password);
				  p[index].Password = (char*)malloc((strlen(Pass) + 1)*sizeof(char));
				  strcpy(p[index].Password, Pass);
				  printf(">> The Password of '%s' has been Successfully Changed to %s\n", p[index].Name, p[index].Password);
				  system("Pause");
				  break;
		}
		case 7:
		{
				  ind = 7;
				  break;
		}
		}
	} while (ind != 7);

	//now we have to update the file.
	UpdateTheFileOfWorkers(&p, size);
	//now we have to free memory
	FreeMemWorkers(&p, size);
	if (ind == 7)
		return -2;//Nothing to change
	return 1;
}



//new 27/1/17
void FreeMemWorkers(Workers **p, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		free((*p)[i].Name);
		free((*p)[i].Password);
		free((*p)[i].Adress);
	}
	free((*p));
}


//new 23/1/2017
void Add_Employee(int funcnum)//funcnum 2
{
	/*Variables*/
	char Name[256],Id[256],Adress[256], Password[256], phoneNumber[256];
	float age;
	int BankACC,result=0;
	Assigment Assigm;

	system("cls");
	printf("\t\t\t\t___<LMH>___\n\n\t\t\t     Logged as 'Manager'\n(Add Employee)\n>> Enter the Employee Name (First Name): ");

	fflush(stdin);
	scanf("%s", &Name);
	_flushall();
	printf("\n>>Enter Employee ID (Max 9 Digits): ");
	scanf("%s", &Id);
	_flushall();
	printf("\n>>Enter Employee Age: "); 
	scanf("%f", &age);
	_flushall();
	printf("\n>>Enter Employee Back Account: ");
	scanf("%d", &BankACC);
	_flushall();
	printf("\n>>Enter your Adress: ");
	scanf("%s", &Adress);
	_flushall();
	printf("<<!>> Notice: in this step just one employee can be Manager\n");
	printf("\n>>Enter Employee Back Assigment (0-Worker, 1-Manage): ");
	scanf("%d", &Assigm);
	_flushall();
	printf("\n>>Enter Employee Phone Number (Between 1-10 Digits): ");
	scanf("%s", &phoneNumber);
	_flushall();
	printf("\n>>Enter Employee Password: ");
	scanf("%s", &Password);
	_flushall();
	//Now we have to check details, already exists id or more than one assigment 'manager' , return false;
	system("cls");
	result = Check_Fields(Name, Password, Id, Adress, phoneNumber, age, Assigm, BankACC);
	printf("\t\t\t\t___<LMH>___\n\n\t\t\t     Logged as 'Manager'");
	if (result)
	{

		printf(">>Successfully Added the Employee, you will be Automaticlly returned to Menu\n");
	}
	else
	{
		printf(">>No changes applied to the Employees list due error,you will be Automaticlly returned to Menu\n ");
	}
}
//new
//this function varify that employee details are valid.
int Check_Fields(char *Name, char *Password, char *_Id, char *Address ,char *PhoneNum, float Age , Assigment _Assigment, int BankAcc)//funcnum 3 
{
	int Size = SizeoFWorkers, i = 0, flag = 1;
	Workers *temp, *temp2;
	temp = Worker;
	if (Size == -1 || Size == 0)
	{
		printf(">> File is empty\n");
		system("Pause");
		return 0;
	}
	//Checking that There are no such this employee.
	for (i = 0; i < Size; i++)
	{
		if (strcmp(temp[i].Id, _Id) == 0 )//|| strcmp(temp[i].Assigm, 1)==0)
			flag=0;
		if (temp[i].Assigm == 1 && _Assigment == 1)
			flag = 0;

	}
	if (flag == 0)
	{
		printf("<<ERROR>> ID or Assigment is Already Exists, you will automaticlly returned to Menu\n");
		system("Pause");
		return 0;
	}
	//Now we put the data to temp array.
	Size = Size + 1;
	temp2 = (Workers*)malloc(Size*sizeof(Workers));
	if (temp2 == NULL)
	{
		printf("ERROR No Available Memory\n");
		return 0;
	}
	for (i = 0; i < Size-1; i++)
	{
		//getting memory place
		temp2[i].Name = (char*)malloc((strlen(temp[i].Name) + 1)*sizeof(char));
		temp2[i].Adress = (char*)malloc((strlen(temp[i].Adress) + 1)*sizeof(char));
		temp2[i].Password = (char*)malloc((strlen(temp[i].Password) + 1)*sizeof(char));
		//Data Copy
		strcpy(temp2[i].Name, temp[i].Name); //1
		strcpy(temp2[i].Id, temp[i].Id);//2
		strcpy(temp2[i].Password, temp[i].Password);//3
		strcpy(temp2[i].Adress, temp[i].Adress);//4
		strcpy(temp2[i].phoneNumber, temp[i].phoneNumber);//5
		temp2[i].age = temp[i].age;//6
		temp2[i].BankACC = temp[i].BankACC; //7
		temp2[i].Assigm = temp[i].Assigm;//8
	}
	temp2[i].Name = (char*)malloc((strlen(Name) + 1) * sizeof(char));
	temp2[i].Password = (char*)malloc((strlen(Password) + 1) * sizeof(char));
	temp2[i].Adress = (char*)malloc((strlen(Address) + 1) * sizeof(char));
	strcpy(temp2[i].Name, Name);
	strcpy(temp2[i].Password, Password);
	strcpy(temp2[i].Adress, Address);
	strcpy(temp2[i].phoneNumber, PhoneNum);
	strcpy(temp2[i].Id, _Id);
	temp2[i].age = Age;
	temp2[i].BankACC = BankAcc;
	temp2[i].Assigm = _Assigment;

	//file update
	UpdateTheFileOfWorkers(&temp2, Size);
	//Now we have to free the memory.
	//for (i = 0; i < Size-1; i++)
	//{
	//		//first array
	//		free(temp[i].Name);
	//		free(temp[i].Password);
	//		free(temp[i].Adress);
	//	
	//}
	//for (i = 0; i < Size; i++)
	//{
	//	//second array
	//	free(temp2[i].Name);
	//	free(temp2[i].Password);
	//	free(temp2[i].Adress);
	//}
	//free(temp);
	//free(temp2);
	return 1;
}
//new 23/1/2017
void UpdateTheFileOfWorkers(Workers **p, int size)
{
	int i = 0;
	FILE *file_1;
	file_1 = fopen("Workers.txt", "w+");
	if (file_1 == NULL)
	{
		printf("the file Not exit(Workers)\n");
		exit(1);
	}

	for (i = 0; i < size-1; i++)
	{
		fprintf(file_1, "%s %s %f %s %s %d %d %s\n", (*p)[i].Name, (*p)[i].Id, (*p)[i].age, (*p)[i].Adress, (*p)[i].Password, (*p)[i].BankACC, (*p)[i].Assigm, (*p)[i].phoneNumber);
	}
	fprintf(file_1, "%s %s %f %s %s %d %d %s", (*p)[i].Name, (*p)[i].Id, (*p)[i].age, (*p)[i].Adress, (*p)[i].Password, (*p)[i].BankACC, (*p)[i].Assigm, (*p)[i].phoneNumber);
	fclose(file_1);
}

//funcnum 15
//new
void certifications(int funcnum)
{
	int f = 1;
	char choice;
	do{
		system("cls");
		printf("\t\t\t\t___<LMH>___\n\n\t\t\t     Logged as 'Manager'\n\n\n\n>> Choose Option:\n- Pension Confirmation - Press 1 then Enter\n- Back to Menu - Press 2 then Enter\n- Loan Requests Cnonfirmation - Press 3 then Enter\n- Leave Request - Press 4 then Enter\n>- Resignation Request - Press 5 then enter\n>> ");
		//fflush(stdin);
		scanf("%c", &choice);
		_flushall();
		switch (choice)
		{
		case '1':
		{
					//confirmation of pension
					
					Pension_confirmation(1);
					break;
		}
		case '2':
		{
					f = 0;
					break;
		}
		case '3':
		{
					Loan_request_confirmation();
					break;
		}
		case '4': {
					  Leave_request_confirmation();
					  break;
		}
		case '5':
		{
					Resignation_request_confirmation();
					break;
		}
		default:
			break;
		}
	} while (f);
}

//Changed fixed the problem of file empty and with one line (31/1/2017)
void Pension_confirmation(int funcnum){//funcnum 23
	system("cls");
	int size = 0, i = 0,index,choice; //the usage of this variable is to check if the file is empty or not.
	PensionFileSize(&size); //function counts the lines of pension file.
	//if the file is empty
	if (size < 1)
	{
		printf("\t\t\t\t___<LMH>___\n\n<FILE ERROR>\n>>The file is empty\nYou will automaticlly back to the menu\n");
		system("Pause");
		return;
	}
	//else,
	Pension_req *p = NULL;
	CopyPensionReqsToArr(&p);
	system("cls");
	printf("\t\t\t\t___<LMH>___\n\n\t\t\t                      Logged as 'Manager'\n\n\n\n>> Here all the Requests of the Employees\n>> Note that requests which you accept them will be \n>> Removed from the file.\n>> You have to choose the specific index\n>>Please Enter the specific index (-1 as index canceling this step)\n");
	fflush(stdin);
	for (i = 0; i < size; i++) //(NEW / EDITED SIZE )
	{
		printf("%d)%f %s\n",i, p[i].Age, p[i].Id);
	}
	printf(">> ");
	scanf("%d", &index);
	_flushall();
	if (index == -1)
	{
		printf(">> No changes applied, you will automaticlly returned to menu\n");
		system("Pause");
		return;
	}
	//now we have to make the changes according to the index.
	if (index<0 || index>size-1) 
	{
		do{
			printf("\n>> index must be between 0 and last index in line.\n>> Please Enter the right index:\n");
			scanf("%d", &index);
			_flushall();
		} while (index<0 || index>size - 1);
	}
	printf(">> Your index is related to the employee:\n");
	printf("%f %s\n", p[index].Age, p[index].Id);
	printf(">> do you want to accept his/her request?\n- 1 - Yes , 0- No>>");	
	scanf("%d", &choice);
	_flushall();
	if (choice == 0)
	{
		printf(">> No changes applied, you will be automaticlly back to menu\n");
		system("Pause");
		return;
	}
	//if manager decided to accept the request we have to update the file of the requests, (means delete the request from file).
	else if (choice==1)
	{
		//do changes
		UpdatePensionFile(&p, size, index);
	}
	else{
		printf(">>Wrong Input, No changes applied , you will back to menu\n");
		system("Pause");
		return;
	}
	printf(">> Changes Successfully Applied , file is updated!\n");
	system("Pause");
}


void UpdatePensionFile(Pension_req **p, int size,int index)
{
	int i = 0;
	FILE *file_1;
	file_1 = fopen("pension request.txt", "w");
	if (file_1 == NULL)
	{
		printf(">> The file Not exit(pension request.txt)\n");
		exit(1);
	}
	//size-2 because we have accpeted them means to remove them .
	for (i = 0; i < size; i++)
	{
		if (( index == size - 1 )&& (i == size-2))
		{
			fprintf(file_1, "%s %f", (*p)[i].Id, (*p)[i].Age); //(NEW EDITED)
			break;
		}
		else if (i != index && i == size - 1)
		{
			fprintf(file_1, "%s %f", (*p)[i].Id, (*p)[i].Age); //(NEW EDITED)
		}
		else if (i != index)
		{
			fprintf(file_1, "%s %f\n", (*p)[i].Id, (*p)[i].Age);
		}
		
	}
	
	fclose(file_1);
}


//hanan functions
////////////Transprition_Manager_Catgorey//////////////
void Transprition_Manager(){
	char select;
	int flag = 1;
	do{
		printf("Transprition\n1)Show Driving Test Appeal\n2)Log_out\n");
		scanf("%c", &select);
		_flushall();
		switch (select){
		case '1':
			Select_MonthOFObjection();
			break;
		case '2':
			flag = 0;
			break;
		default:
			printf("you Select is not correct please Try Again\n");
			break;
		}
	} while (flag);

}

//Lama's functions


void ReadFileAndPutIntoApplicantsArr(Applicants **p, int *Size)
{

	(*p) = (Applicants*)malloc(sizeof(Applicants));
	char buff[300];
	FILE* file_1;
	int sizeF = 0, i = 0;
	file_1 = fopen("Applicants.txt", "r+");
	if (file_1 == NULL)
	{
		printf(">>File Applicants.txt is not existed, so the program will shut down\n");
		exit(1);
	}
	while (!feof(file_1))
	{
		fgets(buff, 300, file_1);
		sizeF++;
	}
	*Size = sizeF;
	(*p) = (Applicants*)malloc(sizeF * sizeof(Applicants));
	if ((*p) == NULL)
	{
		printf("No memory allocation\n");
		exit(1);
	}
	fseek(file_1, 0, SEEK_SET);
	while (!feof(file_1))
	{
		fscanf(file_1, "%s", buff);
		(*p)[i].Name = (char*)malloc((strlen(buff) + 1) * sizeof(char));
		if ((*p)[i].Name == NULL)
		{
			printf("NO memory allcoation\n");
			exit(1);
		}

		strcpy((*p)[i].Name, buff); //reading name
		fgetc(file_1);
		fscanf(file_1, "%s", &((*p)[i].Id));//reading the id
		fgetc(file_1);
		fscanf(file_1, "%f", &(*p)[i].Age);//reading the age
		fgetc(file_1);
		fscanf(file_1, "%s", buff); //reading address
		(*p)[i].Adress = (char*)malloc((strlen(buff) + 1) * sizeof(char));
		strcpy((*p)[i].Adress, buff);
		fgetc(file_1);
		fscanf(file_1, "%s", buff); //reading email
		(*p)[i].Email = (char*)malloc((strlen(buff) + 1) * sizeof(char));
		strcpy((*p)[i].Email, buff);
		fgetc(file_1);
		fscanf(file_1, "%s", &((*p)[i].PhoneNumber));//reading the phone num
		fgetc(file_1);
		fscanf(file_1, "%s", buff); //reading degree
		(*p)[i].Degree = (char*)malloc((strlen(buff) + 1) * sizeof(char));
		strcpy((*p)[i].Degree, buff);
		fgetc(file_1);
		i++;

	}
	fclose(file_1);
}
void viewApplicants() {

	int size = -1;
	Applicants* p = NULL;
	ReadFileAndPutIntoApplicantsArr(&p, &size); //here we send to function which reads the array
	for (int i = 0; i < size; i++) {
		printf("%s	", p[i].Name);
		printf("%s	", p[i].Id);
		printf("%f	", p[i].Age);
		printf("%s	", p[i].Adress);
		printf("%s	", p[i].Email);
		printf("%s	", p[i].PhoneNumber);
		printf("%s\n", p[i].Degree);
	}
	system("Pause");
}



void ReadFileAndPutIntoWorkersArr(Workers **p, int *Size)
{

	(*p) = (Workers*)malloc(sizeof(Workers));
	char buff[300];
	FILE* file_1;
	int sizeF = 0, i = 0;
	file_1 = fopen("workers.txt", "r+");
	if (file_1 == NULL)
	{
		printf(">>File Workers.txt is not existed, so the program will shut down\n");
		exit(1);
	}
	while (!feof(file_1))
	{
		fgets(buff, 300, file_1);
		sizeF++;
	}
	*Size = sizeF;
	(*p) = (Workers*)malloc(sizeF * sizeof(Workers));
	if ((*p) == NULL)
	{
		printf("No memory allocation\n");
		exit(1);
	}
	fseek(file_1, 0, SEEK_SET);
	while (!feof(file_1))
	{
		fscanf(file_1, "%s", buff);
		(*p)[i].Name = (char*)malloc((strlen(buff) + 1) * sizeof(char));
		if ((*p)[i].Name == NULL)
		{
			printf("NO memory allcoation\n");
			exit(1);
		}

		strcpy((*p)[i].Name, buff); //reading name
		fgetc(file_1);
		fscanf(file_1, "%d", &((*p)[i].Id));//reading the id
		fgetc(file_1);
		fscanf(file_1, "%f", &(*p)[i].age);//reading the age
		fgetc(file_1);
		fscanf(file_1, "%s", buff); //reading address
		(*p)[i].Adress = (char*)malloc((strlen(buff) + 1) * sizeof(char));
		strcpy((*p)[i].Adress, buff);
		fgetc(file_1);
		fscanf(file_1, "%s", buff); //reading password
		(*p)[i].Password = (char*)malloc((strlen(buff) + 1) * sizeof(char));
		strcpy((*p)[i].Password, buff);
		fgetc(file_1);
		fscanf(file_1, "%d", &((*p)[i].BankACC)); //reading bank account
		fgetc(file_1);
		fscanf(file_1, "%d", &((*p)[i].Assigm)); //reading assigm
		fgetc(file_1);
		fscanf(file_1, "%s", &((*p)[i].phoneNumber));//reading the phone num
		fgetc(file_1);
		i++;
	}
	fclose(file_1);
}


void viewWorkers() {
	int size = -1;
	Workers* p = NULL;
	ReadFileAndPutIntoWorkersArr(&p, &size); //here we send to function which reads the array
	for (int i = 0; i < size; i++) {
		printf("%s	", p[i].Name);
		printf("%d	", p[i].Id);
		printf("%f	", p[i].age);
		printf("%s	", p[i].Adress);
		printf("%s	", p[i].Password);
		printf("%d	", p[i].BankACC);
		printf("%d	", p[i].Assigm);
		printf("%s\n", p[i].phoneNumber);
	}
	system("Pause");
}


/////NEW but not completed//////////
void viewWorkshops() {
	WorkShops* p = NULL;
	char buff[300];
	FILE* file_1;
	int sizeF = 0, i = 0;
	file_1 = fopen("Workshops.txt", "r+");
	if (file_1 == NULL)
	{
		printf(">>File Workshops.txt is not existed, so the program will shut down\n");
		exit(1);
	}
	while (!feof(file_1))
	{
		fgets(buff, 300, file_1);
		sizeF++;
	}
	p = (WorkShops*)malloc(sizeF*sizeof(WorkShops));
	if (p == NULL)
	{
		printf("No memory allocation\n");
		exit(1);
	}
	fseek(file_1, 0, SEEK_SET);
	while (!feof(file_1))
	{
		fscanf(file_1, "%d", &(p[i].NumOfWorkShop));//reading the number of workshop
		fgetc(file_1);
		fscanf(file_1, "%s", buff);
		p[i].Subject = (char*)malloc((strlen(buff) + 1) * sizeof(char));
		if (p[i].Subject == NULL)
		{
			printf("NO memory allcoation\n");
			exit(1);
		}

		strcpy(p[i].Subject, buff); //reading subject
		fgetc(file_1);
		fscanf(file_1, "%s", buff); //reading date
		p[i].date = (char*)malloc((strlen(buff) + 1) * sizeof(char));
		strcpy(p[i].date, buff);
		//fgetc(file_1);
		i++;
	}
	fclose(file_1);
	for (int j = 0; j < sizeF; j++) {
		printf("%d ", (p[j].NumOfWorkShop));
		printf("%s	", p[j].Subject);
		printf("%s\n", p[j].date);
	}
	system("Pause");
}

//////NEW!!!!!//////
void funding_request() {
	char name[100];
	int bacc;
	long amount;
	printf("Enter name of system:\n");
	scanf("%s", name);
	_flushall();
	printf("Enter bank account:\n");
	scanf("%d", &bacc);
	_flushall();
	printf("Enter amount:\n");
	scanf("%ld", &amount);
	_flushall();
	printf("Your request is submitted! Bye!\n");
}

void CopyLeaveReqsToArr(Leave_Req **p, int* size) {
	char buff[300];
	FILE* file;
	int i = 0;
	file = fopen("leave requests.txt", "r+");
	if (file == NULL)
	{
		printf(">>File leave requests.txt is not existed, so the program will shut down\n");
		exit(1);
	}
	//else,
	(*p) = (Leave_Req*)malloc((*size) * sizeof(Leave_Req));
	if ((*p) == NULL)
	{
		printf("No memory allocation\n");
		exit(1);
	}
	fseek(file, 0, SEEK_SET);
	while (!feof(file))
	{
		fscanf(file, "%s", buff);
		(*p)[i].Name = (char*)malloc((strlen(buff) + 1) * sizeof(char));
		if ((*p)[i].Name == NULL)
		{
			printf("NO memory allcoation\n");
			exit(1);
		}
		strcpy((*p)[i].Name, buff); //reading name
		fgetc(file);
		fscanf(file, "%s", buff); //reading id
		(*p)[i].Id = (char*)malloc((strlen(buff) + 1) * sizeof(char));
		if ((*p)[i].Id == NULL)
		{
			printf("NO memory allcoation\n");
			exit(1);
		}
		strcpy((*p)[i].Id, buff);
		fgetc(file);
		fscanf(file, "%[^\n]", buff); //reading reason
		(*p)[i].Reason = (char*)malloc((strlen(buff) + 1) * sizeof(char));
		if ((*p)[i].Reason == NULL)
		{
			printf("NO memory allcoation\n");
			exit(1);
		}
		strcpy((*p)[i].Reason, buff); //reading reason							
		i++;
	}
	fclose(file);
}


//////NEW!!!!!////
void UpdateLeaveFile(Leave_Req** p, int size, int index) {
	int i = 0;
	FILE *file_1;
	file_1 = fopen("leave requests.txt", "w");
	if (file_1 == NULL)
	{
		printf(">> The file leave request.txt is not existed! :(\n");
		exit(1);
	}
	for (i = 0; i < size - 1; i++)
	{
		if (i != index - 1)
		{
			if (index - 1 == size - 1 && i == size - 2) {
				fprintf(file_1, "%s %s %s", (*p)[i].Name, (*p)[i].Id, (*p)[i].Reason);
			}
			else
				fprintf(file_1, "%s %s %s\n", (*p)[i].Name, (*p)[i].Id, (*p)[i].Reason);
		}
	}
	if (size - 1 != index - 1) {
		fprintf(file_1, "%s %s %s", (*p)[i].Name, (*p)[i].Id, (*p)[i].Reason);
	}
	fclose(file_1);
}


void Leave_request_confirmation() {
	system("cls");
	int size = 0, i = 0, index, choice; //the usage of this variable is to check if the file is empty or not.
	char buff[300];
	FILE* file;
	file = fopen("leave requests.txt", "r+");
	if (file == NULL)
	{
		printf(">>File leave requests.txt is not existed, so the program will shut down\n");
		exit(1);
	}
	if (NULL != file)
	{
		fseek(file, 0, SEEK_END);
		size = ftell(file);
		if (0 == size)
		{
			printf("<<ERROR>> File is empty!\n");
			size = 0;
			system("Pause");
			return;
		}
	}
	size = 0;
	fseek(file, 0, SEEK_SET);
	while (!feof(file))
	{
		fgets(buff, 300, file);
		size++;
	}
	//if (size < 1)
	//{
	//	printf("\t\t\t\t___<LMH>___\n\n<Unable to continue ERROR>\n>>The file is empty\nYou will automaticlly back to the menu\n");
	//	system("Pause");
	//	return;
	//}
	fclose(file);
	//else,
	Leave_Req *p = NULL;
	CopyLeaveReqsToArr(&p, &size);
	system("cls");
	printf("\t\t\t\t___<LMH>___\n\n\t\t\t     Logged as 'Manager'\n\n\n\n>> Here all the Requests of the Employees\n>> Note that requests which you accept them will be \n>> Removed from the file.\n>> You have to choose the specific index\n>>Please Enter the specific index (-1 as index canceling this step):\n\n\n");
	fflush(stdin);
	for (i = 0; i < size; i++)
	{
		printf("%d)%s %s %s", i + 1, p[i].Name, p[i].Id, p[i].Reason);
		printf("\n");
	}
	printf("\n>> ");
	scanf("%d", &index);
	_flushall();
	if (index == -1)
	{
		printf(">> No changes applied, you will automaticlly returned to menu\n");
		system("Pause");
		return;
	}
	//now we have to make the changes according to the index.
	if (index<1 || index>size)
	{
		do {
			printf("\n>> index must be between 1 and last index in line.\n>> Please Enter the right index:\n");
			scanf("%d", &index);
			_flushall();
		} while (index<1 || index>size);
	}
	printf(">> Your index is related to the employee:\n");
	printf("%s %s\n", p[index - 1].Name, p[index - 1].Id);
	printf(">> do you want to accept his/her request?\n- 1 - Yes , 0- No>>");
	scanf("%d", &choice);
	fflush(stdin);
	_flushall();
	if (choice == 0)
	{
		printf(">> No changes applied, you will be automaticlly back to menu\n");
		system("Pause");
		return;
	}
	//if manager decided to accept the request we have to update the file of the requests, (means delete the request from file).
	else if (choice == 1)
	{
		//do changes
		system("Pause");
		UpdateLeaveFile(&p, size, index);
	}
	else {
		printf(">>Wrong Input, No changes applied , you will back to menu\n");
		system("Pause");
		return;
	}
	printf(">> Changes Successfully Applied , file is updated!\n");
	system("Pause");
}


void CopyResignReqsToArr(Resignation_Req **p, int* size) {
	char buff[300];
	FILE* file;
	int i = 0;
	file = fopen("resignation request.txt", "r+");
	if (file == NULL)
	{
		printf(">>File resignation request.txt is not existed, so the program will shut down\n");
		exit(1);
	}
	//else,
	(*p) = (Resignation_Req*)malloc((*size) * sizeof(Resignation_Req));
	if ((*p) == NULL)
	{
		printf("No memory allocation\n");
		exit(1);
	}
	fseek(file, 0, SEEK_SET);
	while (!feof(file))
	{
		fscanf(file, "%s", buff);
		(*p)[i].Name = (char*)malloc((strlen(buff) + 1) * sizeof(char));
		if ((*p)[i].Name == NULL)
		{
			printf("NO memory allcoation\n");
			exit(1);
		}
		strcpy((*p)[i].Name, buff); //reading name
		fgetc(file);
		fscanf(file, "%s", buff); //reading id
		(*p)[i].Id = (char*)malloc((strlen(buff) + 1) * sizeof(char));
		if ((*p)[i].Id == NULL)
		{
			printf("NO memory allcoation\n");
			exit(1);
		}
		strcpy((*p)[i].Id, buff);
		fgetc(file);
		fscanf(file, "%[^\n]", buff); //reading reason
		(*p)[i].Reason = (char*)malloc((strlen(buff) + 1) * sizeof(char));
		if ((*p)[i].Reason == NULL)
		{
			printf("NO memory allcoation\n");
			exit(1);
		}
		strcpy((*p)[i].Reason, buff); //reading reason							
		i++;
	}
	fclose(file);
}


//////NEW!!!!!////
void UpdateResignFile(Resignation_Req** p, int size, int index) {
	int i = 0;
	FILE *file_1;
	file_1 = fopen("resignation request.txt", "w");
	if (file_1 == NULL)
	{
		printf(">> The file resignation request.txt is not existed! :(\n");
		exit(1);
	}
	for (i = 0; i < size - 1; i++)
	{
		if (i != index - 1)
		{
			if (index - 1 == size - 1 && i == size - 2) {
				fprintf(file_1, "%s %s %s", (*p)[i].Name, (*p)[i].Id, (*p)[i].Reason);
			}
			else
				fprintf(file_1, "%s %s %s\n", (*p)[i].Name, (*p)[i].Id, (*p)[i].Reason);
		}
	}
	if (size - 1 != index - 1) {
		fprintf(file_1, "%s %s %s", (*p)[i].Name, (*p)[i].Id, (*p)[i].Reason);
	}
	fclose(file_1);
}


void Resignation_request_confirmation() {
	system("cls");
	int s = 0;
	int size = 0, i = 0, index, choice; //the usage of this variable is to check if the file is empty or not.
	char buff[300];
	FILE* file;
	file = fopen("resignation request.txt", "r+");
	if (file == NULL)
	{
		printf(">>File resignation request.txt is not existed, so the program will shut down\n");
		exit(1);
	}
	if (NULL != file)
	{
		fseek(file, 0, SEEK_END);
		size = ftell(file);
		if (0 == size)
		{
			printf("<<ERROR>> File is empty!\n");
			size = 0;
			system("Pause");
			return;
		}
	}
	size = 0;
	fseek(file, 0, SEEK_SET);
	while (!feof(file))
	{
		fgets(buff, 300, file);
		size++;
	}
	//if (size < 1)
	//{
	//	printf("\t\t\t\t___<LMH>___\n\n<Unable to continue ERROR>\n>>The file is empty\nYou will automaticlly back to the menu\n");
	//	system("Pause");
	//	return;
	//}
	fclose(file);
	//else,
	Resignation_Req *p = NULL;
	CopyResignReqsToArr(&p, &size);
	Workers* ar = readFile_Workers(&s);
	system("cls");
	printf("\t\t\t\t___<LMH>___\n\n\t\t\t     Logged as 'Manager'\n\n\n\n>> Here all the Requests of the Employees\n>> Note that requests which you accept them will be \n>> Removed from the file.\n>> You have to choose the specific index\n>>Please Enter the specific index (-1 as index canceling this step):\n\n\n");
	fflush(stdin);
	for (i = 0; i < size; i++)
	{
		printf("%d)%s %s %s", i + 1, p[i].Name, p[i].Id, p[i].Reason);
		printf("\n");
	}
	printf("\n>> ");
	scanf("%d", &index);
	_flushall();
	if (index == -1)
	{
		printf(">> No changes applied, you will automaticlly returned to menu\n");
		system("Pause");
		return;
	}
	//now we have to make the changes according to the index.
	if (index<1 || index>size)
	{
		do {
			printf("\n>> index must be between 1 and last index in line.\n>> Please Enter the right index:\n");
			scanf("%d", &index);
			_flushall();
		} while (index<1 || index>size);
	}
	printf(">> Your index is related to the employee:\n");
	printf("%s %s\n", p[index - 1].Name, p[index - 1].Id);
	printf(">> do you want to accept his/her request?\n- 1 - Yes , 0- No>>");
	scanf("%d", &choice);
	_flushall();
	fflush(stdin);
	if (choice == 0)
	{
		printf(">> No changes applied, you will be automaticlly back to menu\n");
		system("Pause");
		return;
	}
	//if manager decided to accept the request we have to update the file of the requests, (means delete the request from file).
	else if (choice == 1)
	{
		//do changes
		system("Pause");
		UpdateResignFile(&p, size, index);
		updateTheFileOfWorkers(&ar, s, p[index-1].Id);
	}
	else {
		printf(">>Wrong Input, No changes applied , you will back to menu\n");
		system("Pause");
		return;
	}
	printf(">> Changes Successfully Applied , file is updated!\n");
	system("Pause");
}

////NEW!!!!!/////
void CopyLoanReqsToArr(Loan_Req **p, int* size) {
	char buff[300];
	FILE* file;
	int i = 0;
	file = fopen("loan requests.txt", "r+");
	if (file == NULL)
	{
		printf(">>File loan requests.txt is not existed, so the program will shut down\n");
		exit(1);
	}
	//else,
	(*p) = (Loan_Req*)malloc((*size) * sizeof(Loan_Req));
	if ((*p) == NULL)
	{
		printf("No memory allocation\n");
		exit(1);
	}
	fseek(file, 0, SEEK_SET);
	while (!feof(file))
	{
		fscanf(file, "%s", buff);
		(*p)[i].Name = (char*)malloc((strlen(buff) + 1) * sizeof(char));
		if ((*p)[i].Name == NULL)
		{
			printf("NO memory allcoation\n");
			exit(1);
		}
		strcpy((*p)[i].Name, buff); //reading name
		fgetc(file);
		fscanf(file, "%s", buff); //reading id
		(*p)[i].Id = (char*)malloc((strlen(buff) + 1) * sizeof(char));
		if ((*p)[i].Id == NULL)
		{
			printf("NO memory allcoation\n");
			exit(1);
		}
		strcpy((*p)[i].Id, buff);
		fgetc(file);
		fscanf(file, "%f", &((*p)[i].Amount)); //reading amount
		fgetc(file);
		fscanf(file, "%[^\n]", buff); //reading reason
		(*p)[i].Reason = (char*)malloc((strlen(buff) + 1) * sizeof(char));
		if ((*p)[i].Reason == NULL)
		{
			printf("NO memory allcoation\n");
			exit(1);
		}
		strcpy((*p)[i].Reason, buff); //reading name
		//printf("%d) %s %s %lf %s\n", i + 1, (*p)[i].Name, (*p)[i].Id, (*p)[i].Amount, (*p)[i].Reason);
		i++;
	}
	fclose(file);
}


//////NEW!!!!!////
void UpdateLoanFile(Loan_Req** p, int size, int index) {
	int i = 0;
	FILE *file_1;
	file_1 = fopen("loan requests.txt", "w");
	if (file_1 == NULL)
	{
		printf(">> The file loan request.txt is not existed! :(\n");
		exit(1);
	}
	for (i = 0; i < size - 1; i++)
	{
		if (i != index - 1)
		{
			if (index - 1 == size - 1 && i == size - 2) {
				fprintf(file_1, "%s %s %.2f %s", (*p)[i].Name, (*p)[i].Id, (*p)[i].Amount, (*p)[i].Reason);
			}
			else
				fprintf(file_1, "%s %s %.2f %s\n", (*p)[i].Name, (*p)[i].Id, (*p)[i].Amount, (*p)[i].Reason);
		}
	}
	if (size - 1 != index - 1) {
		fprintf(file_1, "%s %s %.2f %s", (*p)[i].Name, (*p)[i].Id, (*p)[i].Amount, (*p)[i].Reason);
	}
	fclose(file_1);
}

////NEW!!!!!!!!////////
void Loan_request_confirmation() {
	system("cls");
	int size = 0, i = 0, index, choice; //the usage of this variable is to check if the file is empty or not.
	char buff[300];
	FILE* file;
	file = fopen("loan requests.txt", "r+");
	if (file == NULL)
	{
		printf(">>File loan requests.txt is not existed, so the program will shut down\n");
		exit(1);
	}
	if (NULL != file)
	{
		fseek(file, 0, SEEK_END);
		size = ftell(file);
		if (0 == size)
		{
			printf("<<ERROR>> File is empty!\n");
			size = 0;
			system("Pause");
			return;
		}
	}
	size = 0;
	fseek(file, 0, SEEK_SET);
	while (!feof(file))
	{
		fgets(buff, 300, file);
		size++;
	}
	if (size < 1)
	{
		printf("\t\t\t\t___<LMH>___\n\n<Unable to continue ERROR>\n>>The file is empty\nYou will automaticlly back to the menu\n");
		system("Pause");
		return;
	}
	fclose(file);
	//else,
	Loan_Req *p = NULL;
	CopyLoanReqsToArr(&p, &size);
	system("cls");
	printf("\t\t\t\t___<LMH>___\n\n\t\t\t     Logged as 'Manager'\n\n\n\n>> Here all the Requests of the Employees\n>> Note that requests which you accept them will be \n>> Removed from the file.\n>> You have to choose the specific index\n>>Please Enter the specific index (-1 as index canceling this step):\n\n\n");
	fflush(stdin);
	for (i = 0; i < size; i++)
	{
		printf("%d)%s %s %.2f %s\n", i + 1, p[i].Name, p[i].Id, p[i].Amount, p[i].Reason);
	}
	printf("\n>> ");
	scanf("%d", &index);
	_flushall();
	if (index == -1)
	{
		printf(">> No changes applied, you will automaticlly returned to menu\n");
		system("Pause");
		return;
	}
	//now we have to make the changes according to the index.
	else if (index<1 || index>size)
	{
		do {
			printf("\n>> index must be between 1 and last index in line.\n>> Please Enter the right index:\n");
			scanf("%d", &index);
			if (index == -1)
			{
				printf(">> No changes applied, you will automaticlly returned to menu\n");
				system("Pause");
				return;
			}
		} while (check_index(index, size) == 1);
	}
	printf(">> Your index is related to the employee:\n");
	printf("%s %s\n", p[index - 1].Name, p[index - 1].Id);
	printf(">> do you want to accept his/her request?\n- 1 - Yes , 0- No>>");
	scanf("%d", &choice);
	_flushall();
	fflush(stdin);
	if (choice == 0)
	{
		printf(">> No changes applied, you will be automaticlly back to menu\n");
		system("Pause");
		return;
	}
	//if manager decided to accept the request we have to update the file of the requests, (means delete the request from file).
	else if (choice == 1)
	{
		//do changes
		UpdateLoanFile(&p, size, index);
	}
	else {
		printf(">>Wrong Input, No changes applied , you will back to menu\n");
		system("Pause");
		return;
	}
	printf(">> Changes Successfully Applied , file is updated!\n");
	system("Pause");
}

int check_index(int index, int size) {
	return (index <= -2 || index>size || index == 0);
}
void updateTheFileOfWorkers(Workers **ar, int size, char* id)
{
	printf("%s\n", id);
	int i = 0;
	FILE *file_1;
	file_1 = fopen("Workers.txt", "w");
	if (file_1 == NULL)
	{
		printf("the file Not exit(Workers)\n");
		exit(1);
	}

	for (i = 0; i < size - 1; i++)
	{
		if (strcmp((*ar)[i].Id, id) != 0) {
			fprintf(file_1, "%s %s %f %s %s %d %d %s\n", (*ar)[i].Name, (*ar)[i].Id, (*ar)[i].age, (*ar)[i].Adress, (*ar)[i].Password, (*ar)[i].BankACC, (*ar)[i].Assigm, (*ar)[i].phoneNumber);
		}
	}
	if ((*ar)[i].Id != id)
		fprintf(file_1, "%s %s %f %s %s %d %d %s", (*ar)[i].Name, (*ar)[i].Id, (*ar)[i].age, (*ar)[i].Adress, (*ar)[i].Password, (*ar)[i].BankACC, (*ar)[i].Assigm, (*ar)[i].phoneNumber);
	fclose(file_1);
}
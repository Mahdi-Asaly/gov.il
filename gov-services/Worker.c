#define _CRT_SECURE_NO_WARNINGS
#include "Structs.h"
#include "Functions.h"
#include <stdio.h>
#include <stdlib.h>


void Worker_Menu(Workers *emp, int sizef, int index)
{
	char choice;
	int flag = 1;
	do{
		system("cls");
		//new , printf edited
		printf("\t\t\t\t___<LMH>___\n\n\t\t\t\n                            Logged as 'Employee'\n\n\nWelcome '%s',\n\n\n\nChoose Option:\n-Requests - (Press 1 then Enter)\n-Make Survey - Press 2 then Enter\n-Log Out - Press 3 then Enter\n",emp[index].Name);

		scanf("%c", &choice);
		_flushall();
		switch (choice) {
		case '1':
		{
					requests(1);
					break;
		}
		//new
		case '2':
		{
					Make_Survey(33);
					break;
		}
		case '3':
		{
					flag = 0;
					break;
		}
		default:
			break;
		}
	} while (flag);
}

//new added at 27/1/2017 14:32
void Make_Survey(int funcnum)
{
	system("cls");
	int rate;
	printf("\t\t\t\t___<LMH>___\n\n\n\n(Survey Process 1)\n\n>> In this Process, you are going to rate the service in office.\n>> With Each Question , you have to to rate from 1 to 5\n>> 1- Very Bad , 2- Bad , 3- Good , 4- Very good , 5- The Best\n");
	printf(">> When you get ready, press anykey.\n");
	system("Pause");
	system("cls");
	printf("\t\t\t\t___<LMH>___\n\n\n\n(Survey Process)\n\n>> With Each Question , you have to to rate from 1 to 5\n>> 1- Very Bad , 2- Bad , 3- Good , 4- Very good , 5- The Best\n");
	printf("First Question: What do you think about your satisfiction in the Office?\n>> ");
	scanf("%d", &rate);
	_flushall();
	if (rate != 1 && rate != 2 && rate != 3 && rate != 4 && rate != 5)
	{
		do{
			printf("\nWrong Input\n<<Valid Input>> 1- Very Bad , 2- Bad , 3- Good , 4- Very good , 5- The Best\n");
			printf("First Question: What do you think about your satisfiction in the Office?\n>> ");
			scanf("%d", &rate);
			_flushall();
		} while (rate != 1 && rate != 2 && rate != 3 && rate != 4 && rate != 5);
	}
	printf("Second Question: What do you think about the Manager treatment?\n>> ");
	scanf("%d", &rate);
	_flushall();
	if (rate != 1 && rate != 2 && rate != 3 && rate != 4 && rate != 5)
	{
		do{
			printf("\nWrong Input\n<<Valid Input>> 1- Very Bad , 2- Bad , 3- Good , 4- Very good , 5- The Best\n");
			printf("Second Question: What do you think about the Manager treatment?\n>> ");
			scanf("%d", &rate);
			_flushall();
		} while (rate != 1 && rate != 2 && rate != 3 && rate != 4 && rate != 5);
	}
	printf("Third Question: What do you think about Working as a Team in the Office? \n>> ");
	scanf("%d", &rate);
	_flushall();
	if (rate != 1 && rate != 2 && rate != 3 && rate != 4 && rate != 5)
	{
		do{
			printf("\nWrong Input\n<<Valid Input>> 1- Very Bad , 2- Bad , 3- Good , 4- Very good , 5- The Best\n");
			printf("Third Question: What do you think about Working as a Team in the Office? \n>> ");
			scanf("%d", &rate);
			_flushall();
		} while (rate != 1 && rate != 2 && rate != 3 && rate != 4 && rate != 5);
	}
	system("cls");
	printf("\t\t\t\t___<LMH>___\n\n\n\n(Survey Process 2)\n\n>> With Each Question , you have to to rate from 1 to 5\n>> 1- Not Interested , 2- Maybe, 3- Sometimes,4- Yes , 5- Very Interested\n");
	printf("\n\nFourth Question: If someone in the team asked you helping\n them as a favour in team would you accept that? \n>> ");
	scanf("%d", &rate);
	_flushall();
	if (rate != 1 && rate != 2 && rate != 3 && rate != 4 && rate != 5)
	{
		do{
			printf("\n<<Wrong Input>>: With Each Question , you have to to rate from 1 to 5\n>> 1- Not Interested , 2- Maybe, 3- Sometimes,4- Yes , 5- Very Interested\n");
			printf("Fourth Question: If someone in the team asked you helping\n them as a favour in team would you accept that? \n>> ");
			scanf("%d", &rate);
			_flushall();
		} while (rate != 1 && rate != 2 && rate != 3 && rate != 4 && rate != 5);
	}
	printf("Last Question: If someone in the department asked your help about problem , would you help them?: \n>> ");
	scanf("%d", &rate);
	_flushall();
	if (rate != 1 && rate != 2 && rate != 3 && rate != 4 && rate != 5)
	{
		do{
			printf("\n<<Wrong Input>>: With Each Question , you have to to rate from 1 to 5\n>> 1- Not Interested , 2- Maybe, 3- Sometimes,4- Yes , 5- Very Interested\n");
			printf("Last Question: If someone in the department asked your help about problem , would you help them?: \n>> ");
			scanf("%d", &rate);
			_flushall();
		} while (rate != 1 && rate != 2 && rate != 3 && rate != 4 && rate != 5);
	}
	system("cls");
	printf("\t\t\t\t___<LMH>___\n\n\n\n(Survey Done)\n\n>> Survey has been Done, Thanks!!,\n We are here for make the Service Better as possible we can! , Good bye!\n");
	system("Pause");
}


void requests(int funcnum) {
	int flag = 1;
	char choice;
	do{		
		system("cls");
		printf("\t\t\t\t___<LMH>___\n\n\n\nChoose Option:\n-Loan Requests - (Press 1 then Enter)\n-Pension request - (Press 2 then Enter)\n-Leave Request - Press 3 then Enter\n-Resignation Request - Press 4 then Enter\nLog Out - Press q then Enter\n>> ");
		
		scanf("%c", &choice);
		_flushall();
		switch (choice)
		{
		case '1':
		{
			LoanReq(1);
			break;
		}
			//new
		case '2':
		{
			PensionReq(1);
			break;
		}
		case '3':
		{
					Leave_request();
					break;
		}
		case '4': 
		{
					  Resignation_request();
					  break;
		}
		case 'q':
		{
			flag = 0;
			break;
		}
		default:
			printf("\nERROR >> Wrong input, press anykey.\n");
			system("Pause");
			break;
		}
	} while (flag);
}

//new!!
//lama's function
int check_validAge(float age)
{
	return (age < 55.0f || age>70.0f);
}
//funcnum 24 (Worker) (this is not working well. Problem: try to add twice its will crash.)
void PensionReq(int funcnum)
{
	Pension_req *p=NULL;
	int result = 0;
	int size = -1;
	char id[256];
	float age;
	int i = 0;
	
	system("cls");
	printf("\t\t\t\t___<LMH>___\n\n\n\nPension Request:");
	printf("\n\n\n>>Enter you'r ID:");
	scanf("%s", &id);
	_flushall();
	printf("\n>>Enter you'r Age:");
	scanf("%f", &age);
	_flushall();
	//add ths
	if (age < 55.0f || age>70.0f)
	{
		do {
			printf("Wrong input age should be between 55 and 70\nEnter Age\n>>");
			scanf("%f", &age);
			_flushall();
		} while (check_validAge(age) == 1);
	}
	result=ConfirmByID(id);
	if (result)
	{
		updatepensionreq(id, age, &p, &size);//update the array of pension requests.
		for (i = 0; i < size; i++)
			printf("%s %f\n", p[i].Id, p[i].Age);
		system("Pause");
		updatepensionfile(&p, size);//updating the file of pension requests.
		FreeMemoryOfArr(&p, size);
	}
	else{
		FreeMemoryOfArr(&p, size);
		printf(">> The id that you have entered is not related to any worker.\n");
		system("Pause");
	}
}
void FreeMemoryOfArr(Pension_req **p,int size)
{
	int i = 0;
	for (i = 0; i < size; i++)// free arr 
	{
		free((*p)[i].Id);
	}
	free((*p));
}
int ConfirmIdOfWorker(int sizef, char *id)
{
	Workers*emp;
	int i = 0;
	int flag = 0;
	emp = readFile_Workers(&sizef);
	for (i = 0; i < sizef; i++)
	{
		if (strcmp(emp[i].Id, id) == 0)
		{
			flag = 1;
		}
	}
	for (i = 0; i < sizef; i++)
	{
		//printf("A = %d\n", i);
		if (emp[i].Name != NULL)
			free(emp[i].Name);
		if (emp[i].Adress != NULL)
			free(emp[i].Adress);
		if (emp[i].Password != NULL)
			free(emp[i].Password);
	}
	//printf("hi\n");
	free(emp);
	//printf("Success\n");
	if (flag == 1)
		return 1;
	return 0;
}
//new!!
int ConfirmByID(char *id)
{
	FILE*file_1;
	int flag = 0;
	char buff[300];
	int sizef = 0, i = 0;
	file_1 = fopen("Workers.txt", "r+");

	if (file_1 == NULL)
	{
		printf("the file not Exit(Workers file)\n");
		exit(1);
	}
	while (!feof(file_1)) {
		fgets(buff, 300, file_1);
		sizef++;
	}
	sizef--;
	fclose(file_1);
	if (ConfirmIdOfWorker(sizef,id))
		return 1;
	return 0;
}


//new!!
void updatepensionreq(char *id, float age, Pension_req **p,int *size)
{
    FILE*file_2;
	char buff[300];
	file_2 = fopen("pension request.txt", "r+");

	int sizeF = 0, i = 0;


	if (file_2 == NULL)
	{
		printf(">>File loan requests.txt is not exists, thus program is shutted down\n");
		exit(1);
	}

	while (!feof(file_2))
	{
		fgets(buff, 500, file_2);
		sizeF++;
	}

	*size = sizeF+1;//including the user input

	(*p) = (Pension_req*)malloc((sizeF+1)* sizeof(Pension_req));

	if ((*p) == NULL)
	{
		printf("No memory allocation\n");
		exit(1);
	}
	fseek(file_2, 0, SEEK_SET);
	while (!feof(file_2))
	{
		fscanf(file_2, "%s", buff);
		(*p)[i].Id = (char*)malloc((strlen(buff) + 1) * sizeof(char));
		strcpy((*p)[i].Id, buff); //reading name
		fgetc(file_2);
		fscanf(file_2, "%f", &((*p)[i].Age));//reading the age
		i++;
	}
	//now let's copy the user input to the array.
	(*p)[*size - 1].Id = (char*)malloc((strlen(id) + 1)*sizeof(char));
	strcpy((*p)[*size - 1].Id, id);
	(*p)[*size - 1].Age = age;
	fclose(file_2);
}

//new 21/1/2017, this function put all the info of the pension reqs into array
void CopyPensionReqsToArr(Pension_req **p)
{
	FILE*file_2;
	char buff[300];
	file_2 = fopen("pension request.txt", "r+");

	int sizeF = 0, i = 0;


	if (file_2 == NULL)
	{
		printf(">>File loan requests.txt is not exists, thus program is shutted down\n");
		exit(1);
	}

	while (!feof(file_2))
	{
		fgets(buff, 500, file_2);
		sizeF++;
	}

	(*p) = (Pension_req*)malloc((sizeF)* sizeof(Pension_req));

	if ((*p) == NULL)
	{
		printf("No memory allocation\n");
		exit(1);
	}
	fseek(file_2, 0, SEEK_SET);
	while (!feof(file_2))
	{
		fscanf(file_2, "%s", buff);
		(*p)[i].Id = (char*)malloc((strlen(buff) + 1) * sizeof(char));
		strcpy((*p)[i].Id, buff); //reading name
		fgetc(file_2);
		fscanf(file_2, "%f", &((*p)[i].Age));//reading the age
		i++;
	}
}
//new
//this function counts the lines in the folder of pension req.
void PensionFileSize(int *size)
{
	FILE*file_2;
	char buff[300];
	file_2 = fopen("pension request.txt", "r+");

	int sizeF = 0, i = 0;


	if (file_2 == NULL)
	{
		printf(">>File loan requests.txt is not exists, thus program is shutted down\n");
		exit(1);
	}
	if (NULL != file_2) {
		fseek(file_2, 0, SEEK_END);
		*size = ftell(file_2);

		if (0 == *size) {
			printf("file is empty\n");
			*size = 0;
			return; //exit from function
		}
	}
	fseek(file_2, 0, SEEK_SET);
	while (!feof(file_2))
	{
		fgets(buff, 500, file_2);
		sizeF++;
	}

	*size = sizeF;//including the user input
}

//new!!
void updatepensionfile(Pension_req **p, int size)
{
	int i = 0;
	FILE *file_1;
	file_1 = fopen("pension request.txt", "w");
	if (file_1 == NULL)
	{
		printf(">> The file Not exit(pension request.txt)\n");
		exit(1);
	}

	for (i = 0; i < size - 1; i++)
	{
		fprintf(file_1, "%s %f\n", (*p)[i].Id, (*p)[i].Age);
	}
	fprintf(file_1, "%s %f", (*p)[i].Id, (*p)[i].Age);
	fclose(file_1);
}
//function num
void LoanReq(int funcnum)
{
	int flag = 1,size=-1;
	int i = 0;
	Loan_Req *p = NULL; //this array will save the details of the workers.

	char name[300], id[10];
	char Reason[256];
	float amount;
	
	//getchar();
	system("cls");
	printf("\t\t\t\t___<LMH>___\n\n\n\nLoan Request:");
	printf("\n\n\n>>Enter You'r Name (Without spaces):");
	scanf("%s", &name);
	printf("\n\n\n>>Enter Your'r ID [must be 9 digits]:");
	_flushall();

	scanf("%s", &id);
	//check if id is ok
	printf("\n\n\n>>Enter the Amount:");
	_flushall();

	scanf("%f", &amount);
	printf("\n\n\n>>Enter the Reason for this loan (About 256 chars at max ):");
	_flushall();
	gets(Reason);
	_flushall();
	ReadFileAndPutIntoArr(name, id, amount, Reason,&p, &size); //here we send to function which reads the array
	if (size == -1)
	{
		printf("There are problem in file 'Loan req' ,or not exists ,thus program is stopped.\n");
		exit(1);
	}
	UpdateTheFileOfLoans(&p, size);//updating the file
	system("Pause");
}
//this function related to loan request
void ReadFileAndPutIntoArr(char *name, char *id, float amount, char *Reason, Loan_Req **p, int *Size)
{
	int flag = 1, tmpsize = 0;
	char buff[300];
	FILE*file_1;
	Loan_Req *temp = NULL;
	int sizeF = 0, i = 0;
	file_1 = fopen("loan requests.txt", "r+");
	if (file_1 == NULL)
	{
		printf(">>File loan requests.txt is not exists, thus program is shutted down\n");
		exit(1);
	}
	//if we have empty file we just add the new line
	if (NULL != file_1) {
		fseek(file_1, 0, SEEK_END);
		*Size = ftell(file_1);
		
		if (0 == *Size) 
		{
			*Size = 1;
			(*p) = (Loan_Req*)malloc((*Size)* sizeof(Loan_Req));
			//now let's copy the user input to the array.
			(*p)[*Size - 1].Name = (char*)malloc((strlen(name) + 1)*sizeof(char));
			(*p)[*Size - 1].Id = (char*)malloc((strlen(id) + 1)*sizeof(char));
			(*p)[*Size - 1].Reason = (char*)malloc((strlen(Reason) + 1)*sizeof(char));
			strcpy((*p)[*Size - 1].Name, name);
			strcpy((*p)[*Size - 1].Id, id);
			strcpy((*p)[*Size - 1].Reason, Reason);
			(*p)[*Size - 1].Amount = amount;
			printf(">> Successfully Added your Request!\n");
			system("Pause");
			return; //exit from function
		}
	}
	//else , we read from begin
	fseek(file_1, 0, SEEK_SET);
	while (!feof(file_1))
	{
		fgets(buff, 500, file_1);
		sizeF++;
	}
	*Size = sizeF;//including the user input
	(*p) = (Loan_Req*)malloc((*Size)* sizeof(Loan_Req));
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
		fscanf(file_1, "%s", buff); //reading id
		(*p)[i].Id = (char*)malloc((strlen(buff) + 1) * sizeof(char));
		strcpy((*p)[i].Id, buff);
		fgetc(file_1);
		fscanf(file_1, "%f", &((*p)[i].Amount));//reading the amount
		fgetc(file_1);
		fgets(buff, 300, file_1);//reading reason
		tmpsize = strlen(buff)-1;
		if (buff[tmpsize] == '\n')
			buff[tmpsize] = '\0';
		//fscanf(file_1, "%s", buff);
		(*p)[i].Reason = (char*)malloc((strlen(buff) + 1) * sizeof(char));
		if ((*p)[i].Reason == NULL)
		{
			printf("NO memory allcoation\n");
			exit(1);
		}
		strcpy((*p)[i].Reason, buff);
		i++;
	}
	fclose(file_1);

	//before adding the request we have to check if they have another one
	for (i = 0; i < sizeF; i++)
	{
		if (strcmp((*p)[i].Id, id) == 0)
			flag = 0;
	}
	if (flag != 0)
	{
		*Size = *Size + 1;
		temp = (Loan_Req*)malloc((*Size)*sizeof(Loan_Req));
		for (i = 0; i < *Size-1; i++)
		{
			temp[i].Name = (char*)malloc((strlen(name) + 1)*sizeof(char));
			temp[i].Id = (char*)malloc((strlen(id) + 1)*sizeof(char));
			temp[i].Reason = (char*)malloc((strlen(Reason) + 1)*sizeof(char));
			strcpy(temp[i].Name, (*p)[i].Name);
			strcpy(temp[i].Id, (*p)[i].Id);
			strcpy(temp[i].Reason, (*p)[i].Reason);
			temp[i].Amount = (*p)[i].Amount;
		}
		//now we free the mem
		for (i = 0; i < *Size-1; i++)
		{
			free((*p)[i].Name);
			free((*p)[i].Reason);
			free((*p)[i].Id);
		}
		free((*p));
		(*p) = (Loan_Req*)malloc((*Size)* sizeof(Loan_Req));

		//restore
		for (i = 0; i < *Size - 1; i++)
		{
			(*p)[i].Name = (char*)malloc((strlen(temp[i].Name) + 1)*sizeof(char));
			(*p)[i].Id = (char*)malloc((strlen(temp[i].Id) + 1)*sizeof(char));
			(*p)[i].Reason = (char*)malloc((strlen(temp[i].Reason) + 1)*sizeof(char));
			strcpy((*p)[i].Name, temp[i].Name);
			strcpy((*p)[i].Id, temp[i].Id);
			strcpy((*p)[i].Reason, temp[i].Reason);
			(*p)[i].Amount =temp[i].Amount;
		}
		//now let's copy the user input to the array.
		(*p)[*Size - 1].Name = (char*)malloc((strlen(name) + 1)*sizeof(char));
		(*p)[*Size - 1].Id = (char*)malloc((strlen(id) + 1)*sizeof(char));
		(*p)[*Size - 1].Reason = (char*)malloc((strlen(Reason) + 1)*sizeof(char));
		strcpy((*p)[*Size - 1].Name, name);
		strcpy((*p)[*Size - 1].Id, id);
		strcpy((*p)[*Size - 1].Reason, Reason);
		(*p)[*Size - 1].Amount = amount;


		//now free temp
		for (i = 0; i < *Size - 1; i++)
		{
			free(temp[i].Name);
			free(temp[i].Reason);
			free(temp[i].Id);
		}
		free(temp);
		printf(">> Successfully Added your Request!\n");
		system("Pause");
		return;
	}
	else{
		printf("<<ERROR>> Process Faild, there are another request with your ID in pending.\n");
		system("Pause");
		return;
	}

}

//please Launche this function to update the file ,note that this function only launche once , at end of the program.
void UpdateTheFileOfLoans(Loan_Req **p,int size) 
{
	int i = 0;
	FILE *file_1;
	file_1 = fopen("loan requests.txt", "w");
	if (file_1 == NULL)
	{
		printf("the file Not exit(Loan File)\n");
		exit(1);
	}
	for (i = 0; i < size-1; i++)
	{
		fprintf(file_1, "%s %s %lf %s\n", (*p)[i].Name, (*p)[i].Id, (*p)[i].Amount, (*p)[i].Reason);
	}
	fprintf(file_1, "%s %s %lf %s", (*p)[i].Name, (*p)[i].Id, (*p)[i].Amount, (*p)[i].Reason);
	for (i = 0; i < size; i++)// free arr 
	{
		free((*p)[i].Name);
		free((*p)[i].Reason);
		free((*p)[i].Id);
	}
	//free((*p));
	fclose(file_1);
}

//Lama's Functions

void updateResignReqFile(Resignation_Req** p, int* size) {
	int i = 0;
	FILE *file_1;
	file_1 = fopen("resignation request.txt", "w");

	if (file_1 == NULL)
	{
		printf("the file Not exit(resignation request File)\n");
		exit(1);
	}
	for (i = 0; i < *size - 1; i++)
	{
		fprintf(file_1, "%s %s %s\n", (*p)[i].Name, (*p)[i].Id, (*p)[i].Reason);
	}
	fprintf(file_1, "%s %s %s", (*p)[i].Name, (*p)[i].Id, (*p)[i].Reason);
	for (i = 0; i < *size; i++)// free arr 
	{
		free((*p)[i].Name);
		free((*p)[i].Reason);
		free((*p)[i].Id);
	}
	fclose(file_1);
}

//add this
int check_existed(char* id1, char* id2) {
	return strcmp(id1, id2) == 0;
}
void updateResignReqArr(char* name, char* id, char* reason, Resignation_Req** p, int *size) {
	int flag = 1, tmpsize = 0;
	char buff[300];
	FILE*file_1;
	Resignation_Req *temp = NULL;
	int sizeF = 0, i = 0;
	file_1 = fopen("resignation request.txt", "r+");
	if (file_1 == NULL)
	{
		printf(">>File resignation request.txt is not exists, thus program is shutted down\n");
		exit(1);
	}
	//if we have empty file we just add the new line
	if (NULL != file_1) {
		fseek(file_1, 0, SEEK_END);
		*size = ftell(file_1);

		if (0 == *size)
		{
			*size = 1;
			(*p) = (Resignation_Req*)malloc((*size) * sizeof(Resignation_Req));
			//now let's copy the user input to the array.
			(*p)[*size - 1].Name = (char*)malloc((strlen(name) + 1) * sizeof(char));
			(*p)[*size - 1].Id = (char*)malloc((strlen(id) + 1) * sizeof(char));
			(*p)[*size - 1].Reason = (char*)malloc((strlen(reason) + 1) * sizeof(char));
			strcpy((*p)[*size - 1].Name, name);
			strcpy((*p)[*size - 1].Id, id);
			strcpy((*p)[*size - 1].Reason, reason);
			printf(">> Successfully Added your Request!\n");
			system("Pause");
			return; //exit from function
		}
	}
	//else , we read from begin
	fseek(file_1, 0, SEEK_SET);
	while (!feof(file_1))
	{
		fgets(buff, 500, file_1);
		sizeF++;
	}
	*size = sizeF;//including the user input
	(*p) = (Resignation_Req*)malloc((*size) * sizeof(Resignation_Req));
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
		fscanf(file_1, "%s", buff); //reading id
		(*p)[i].Id = (char*)malloc((strlen(buff) + 1) * sizeof(char));
		strcpy((*p)[i].Id, buff);
		fgetc(file_1);
		fgets(buff, 300, file_1);//reading reason
		tmpsize = strlen(buff) - 1;
		if (buff[tmpsize] == '\n')
			buff[tmpsize] = '\0';
		//fscanf(file_1, "%s", buff);
		(*p)[i].Reason = (char*)malloc((strlen(buff) + 1) * sizeof(char));
		if ((*p)[i].Reason == NULL)
		{
			printf("NO memory allcoation\n");
			exit(1);
		}
		strcpy((*p)[i].Reason, buff);
		i++;
	}
	fclose(file_1);

	//before adding the request we have to check if they have another one
	for (i = 0; i < sizeF; i++)
	{//add this
		if (check_existed((*p)[i].Id, id) == 1)
			flag = 0;
	}
	if (flag != 0)
	{
		*size = *size + 1;
		temp = (Resignation_Req*)malloc((*size) * sizeof(Resignation_Req));
		for (i = 0; i < *size - 1; i++)
		{
			temp[i].Name = (char*)malloc((strlen(name) + 1) * sizeof(char));
			temp[i].Id = (char*)malloc((strlen(id) + 1) * sizeof(char));
			temp[i].Reason = (char*)malloc((strlen(reason) + 1) * sizeof(char));
			strcpy(temp[i].Name, (*p)[i].Name);
			strcpy(temp[i].Id, (*p)[i].Id);
			strcpy(temp[i].Reason, (*p)[i].Reason);
		}
		//now we free the mem
		for (i = 0; i < *size - 1; i++)
		{
			free((*p)[i].Name);
			free((*p)[i].Reason);
			free((*p)[i].Id);
		}
		free((*p));
		(*p) = (Resignation_Req*)malloc((*size) * sizeof(Resignation_Req));

		//restore
		for (i = 0; i < *size - 1; i++)
		{
			(*p)[i].Name = (char*)malloc((strlen(temp[i].Name) + 1) * sizeof(char));
			(*p)[i].Id = (char*)malloc((strlen(temp[i].Id) + 1) * sizeof(char));
			(*p)[i].Reason = (char*)malloc((strlen(temp[i].Reason) + 1) * sizeof(char));
			strcpy((*p)[i].Name, temp[i].Name);
			strcpy((*p)[i].Id, temp[i].Id);
			strcpy((*p)[i].Reason, temp[i].Reason);
		}
		//now let's copy the user input to the array.
		(*p)[*size - 1].Name = (char*)malloc((strlen(name) + 1) * sizeof(char));
		(*p)[*size - 1].Id = (char*)malloc((strlen(id) + 1) * sizeof(char));
		(*p)[*size - 1].Reason = (char*)malloc((strlen(reason) + 1) * sizeof(char));
		strcpy((*p)[*size - 1].Name, name);
		strcpy((*p)[*size - 1].Id, id);
		strcpy((*p)[*size - 1].Reason, reason);


		//now free temp
		for (i = 0; i < *size - 1; i++)
		{
			free(temp[i].Name);
			free(temp[i].Reason);
			free(temp[i].Id);
		}
		free(temp);
		printf(">> Successfully Added your Request!\n");
		system("Pause");
		return;
	}
	else {
		printf("<<ERROR>> Process Faild, there are another request with your ID in pending.\n");
		system("Pause");
		return;
	}
}

void Resignation_request() {
	int flag = 1, size = -1;
	int i = 0;
	Resignation_Req *p = NULL; //this array will save the details of the workers.

	char name[300], id[10];
	char Reason[256];
	//getchar();
	printf("\t\t\t\t___<LMH>___\n\n\n\nResignation Request:");
	printf("\n\n\n>>Enter You'r Name (Without spaces):");
	scanf("%s", &name);
	printf("\n\n\n>>Enter Your'r ID [must be 9 digits]:");
	_flushall();

	scanf("%s", &id);
	_flushall();
	if (ConfirmByID(id) == 1) {
		printf("\n\n\n>>Enter the Reason(About 256 chars at max ):");
		
		gets(Reason);
		_flushall();
		updateResignReqArr(name, id, Reason, &p, &size); //here we send to function which reads the array
		if (size == -1)
		{
			printf("There are problem in file 'Resignation request' ,or not exists ,thus program is stopped.\n");
			exit(1);
		}
		updateResignReqFile(&p, &size);//updating the file
		printf("<<LMH>>Successfully Added you'r request to the data base.\n");
		system("Pause");
	}
	else {
		printf("you entered a wrong id!\n");
		system("Pause");
	}
}
//new!!
void updateLeaveReqFile(Leave_Req** p, int* size) {
	int i = 0;
	FILE *file_1;
	file_1 = fopen("leave requests.txt", "w");
	if (file_1 == NULL)
	{
		printf("the file Not exit(leave requests File)\n");
		exit(1);
	}

	for (i = 0; i < *size - 1; i++)
	{
		fprintf(file_1, "%s %s %s\n", (*p)[i].Name, (*p)[i].Id, (*p)[i].Reason);
	}
	fprintf(file_1, "%s %s %s", (*p)[i].Name, (*p)[i].Id, (*p)[i].Reason);
	for (i = 0; i < *size; i++)// free arr 
	{
		free((*p)[i].Name);
		free((*p)[i].Reason);
		free((*p)[i].Id);
	}
	fclose(file_1);
}
void updateLeaveReqArr(char* name, char* id, char* reason, Leave_Req** p, int *size) {
	int flag = 1, tmpsize = 0;
	char buff[300];
	FILE*file_1;
	Leave_Req *temp = NULL;
	int sizeF = 0, i = 0;
	file_1 = fopen("leave requests.txt", "r+");
	if (file_1 == NULL)
	{
		printf(">>File leave requests.txt is not exists, thus program is shutted down\n");
		exit(1);
	}
	//if we have empty file we just add the new line
	if (NULL != file_1) {
		fseek(file_1, 0, SEEK_END);
		*size = ftell(file_1);

		if (0 == *size)
		{
			*size = 1;
			(*p) = (Leave_Req*)malloc((*size) * sizeof(Leave_Req));
			//now let's copy the user input to the array.
			(*p)[*size - 1].Name = (char*)malloc((strlen(name) + 1) * sizeof(char));
			(*p)[*size - 1].Id = (char*)malloc((strlen(id) + 1) * sizeof(char));
			(*p)[*size - 1].Reason = (char*)malloc((strlen(reason) + 1) * sizeof(char));
			strcpy((*p)[*size - 1].Name, name);
			strcpy((*p)[*size - 1].Id, id);
			strcpy((*p)[*size - 1].Reason, reason);
			printf(">> Successfully Added your Request!\n");
			system("Pause");
			return; //exit from function
		}
	}
	//else , we read from begin
	fseek(file_1, 0, SEEK_SET);
	while (!feof(file_1))
	{
		fgets(buff, 500, file_1);
		sizeF++;
	}
	*size = sizeF;//including the user input
	(*p) = (Leave_Req*)malloc((*size) * sizeof(Leave_Req));
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
		fscanf(file_1, "%s", buff); //reading id
		(*p)[i].Id = (char*)malloc((strlen(buff) + 1) * sizeof(char));
		strcpy((*p)[i].Id, buff);
		fgetc(file_1);
		fgets(buff, 300, file_1);//reading reason
		tmpsize = strlen(buff) - 1;
		if (buff[tmpsize] == '\n')
			buff[tmpsize] = '\0';
		//fscanf(file_1, "%s", buff);
		(*p)[i].Reason = (char*)malloc((strlen(buff) + 1) * sizeof(char));
		if ((*p)[i].Reason == NULL)
		{
			printf("NO memory allcoation\n");
			exit(1);
		}
		strcpy((*p)[i].Reason, buff);
		i++;
	}
	fclose(file_1);

	//before adding the request we have to check if they have another one
	*size = *size + 1;
	temp = (Leave_Req*)malloc((*size) * sizeof(Leave_Req));
	for (i = 0; i < *size - 1; i++)
	{
		temp[i].Name = (char*)malloc((strlen(name) + 1) * sizeof(char));
		temp[i].Id = (char*)malloc((strlen(id) + 1) * sizeof(char));
		temp[i].Reason = (char*)malloc((strlen(reason) + 1) * sizeof(char));
		strcpy(temp[i].Name, (*p)[i].Name);
		strcpy(temp[i].Id, (*p)[i].Id);
		strcpy(temp[i].Reason, (*p)[i].Reason);
	}
	//now we free the mem
	for (i = 0; i < *size - 1; i++)
	{
		free((*p)[i].Name);
		free((*p)[i].Reason);
		free((*p)[i].Id);
	}
	free((*p));
	(*p) = (Leave_Req*)malloc((*size) * sizeof(Leave_Req));

	//restore
	for (i = 0; i < *size - 1; i++)
	{
		(*p)[i].Name = (char*)malloc((strlen(temp[i].Name) + 1) * sizeof(char));
		(*p)[i].Id = (char*)malloc((strlen(temp[i].Id) + 1) * sizeof(char));
		(*p)[i].Reason = (char*)malloc((strlen(temp[i].Reason) + 1) * sizeof(char));
		strcpy((*p)[i].Name, temp[i].Name);
		strcpy((*p)[i].Id, temp[i].Id);
		strcpy((*p)[i].Reason, temp[i].Reason);
	}
	//now let's copy the user input to the array.
	(*p)[*size - 1].Name = (char*)malloc((strlen(name) + 1) * sizeof(char));
	(*p)[*size - 1].Id = (char*)malloc((strlen(id) + 1) * sizeof(char));
	(*p)[*size - 1].Reason = (char*)malloc((strlen(reason) + 1) * sizeof(char));
	strcpy((*p)[*size - 1].Name, name);
	strcpy((*p)[*size - 1].Id, id);
	strcpy((*p)[*size - 1].Reason, reason);


	//now free temp
	for (i = 0; i < *size - 1; i++)
	{
		free(temp[i].Name);
		free(temp[i].Reason);
		free(temp[i].Id);
	}
	free(temp);
	printf(">> Successfully Added your Request!\n");
	system("Pause");
	return;
}

void Leave_request() {
	int flag = 1, size = -1;
	int i = 0;
	Leave_Req *p = NULL; //this array will save the details of the workers.

	char name[300], id[10];
	char Reason[256];

	//getchar();
	printf("\t\t\t\t___<LMH>___\n\n\n\nLeave Request:");
	printf("\n\n\n>>Enter You'r Name (Without spaces):");
	scanf("%s", &name);
	_flushall();
	printf("\n\n\n>>Enter Your'r ID [must be 9 digits]:");

	scanf("%s", &id);
	_flushall();
	if (ConfirmByID(id) == 1) {
		printf("\n\n\n>>Enter the Reason(About 256 chars at max ):");
		gets(Reason);
		_flushall();
		updateLeaveReqArr(name, id, Reason, &p, &size); //here we send to function which reads the array
		if (size == -1)
		{
			printf("There are problem in file 'Leave requests' ,or not exists ,thus program is stopped.\n");
			exit(1);
		}
		updateLeaveReqFile(&p, &size);//updating the file
		printf("<<LMH>>Successfully Added you'r request to the data base.\n");
		system("Pause");
	}
	else {
		printf("you entered a wrong id!\n");
		system("Pause");
	}
}

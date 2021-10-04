#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define max 30 
struct student{
	char name[20],course[20];
	int rollno,sem,mobno;
}s[max];
int i,j;
//function definitions
int newData(int i,int num,struct student s[num]){
	printf("\nEnter data of the student %d",i+1);
	printf("\nEnter name:");
	fflush(stdin);
	fgets(s[i].name,sizeof(s[i].name),stdin);
	printf("Enter RollNo:");
	scanf("%d",&s[i].rollno);
	printf("Enter Course:");
	fflush(stdin);
	fgets(s[i].course,sizeof(s[i].course),stdin);
	printf("Enter Semester:");
	scanf("%d",&s[i].sem);
	printf("Enter PhoneNo:");
	scanf("%d",&s[i].mobno);
}
int newRecord(int num, struct student s[num]){
	for(i=0; i<num; i++){
		newData(i,num,s);	
	}
}
int displayData(int i,int num,struct student s[num]){
	printf("\nData of the student %d",i+1);
	printf("\tName:%s",s[i].name);
	printf("\tRollNo:%d",s[i].rollno);
	printf("\tCourse:%s",s[i].course);
	printf("\tSemester:%d",s[i].sem);
	printf("\tPhoneNo:%d",s[i].mobno);
}

int displayRecord(int num ,struct student s[num]){
	if(num==0){
		printf("\nNo student data is found\n");
	} else{
		for(i=0; i<num; i++){
			displayData(i,num,s);
		}
	}	
}

int search(int num,struct student s[num]){
	if(num==0){
		printf("No data found\n");
	}else{
		int roll ;
	printf("Enter the RollNo of the student:");
	scanf("%d",&roll);
	for(i=0; i<num; i++){
		if(roll==s[i].rollno){
			displayData(i,num,s);
			return i ;
			}
		}
	}
}

int updateRecord(int num,struct student s[num]){
	if(num==0){
		printf("No data found\n");
	} else{
		int i = search(num,s);
		newData(i,num,s);
		printf("\nNew Data");
		displayData(i,num,s);		
	}
}

int Delete(int *num_ptr,struct student s[i]){
	int n;
	if(*num_ptr==0){
		printf("No data found\n");
	} else{
		printf("Press 1 for delete all record:");
		printf("\nPress 2 for delete one record:");
		scanf("%d",&n);
		if(n==1) {
			*num_ptr = 0;
			printf("All records are deleted;");
		} else if(n==2){
			int rollNo;
			printf("Enter specific roll no to delete:");
			scanf("%d",&rollNo);
			for(i=0;i< *num_ptr; i++){
				if(rollNo==s[i].rollno){
					for(j=i; j<*num_ptr; j++){
						strcpy(s[j].name,s[j+1].name);
						strcpy(s[j].course,s[j+1].course);	
						s[j].rollno= s[j+1].rollno;
						s[j].sem   = s[j+1].sem;
						s[j].mobno = s[j+1].mobno;	
				    }
				    *num_ptr = *num_ptr-1;
					printf("Your specific record is deleted");
					return 0 ;
				}
				
			}
		}
	}
}

//main function
int main(){
	int num,n,x;
	printf("*****Student management System*****");
	while(1){
		printf("\n1.Enter new record\n2.Display record\n3.Search record\n4.Update Record\n5.Delete Record\n6.Exit\n");
		scanf("%d",&num);
		switch(num){
			case 1:
				printf("How many student want to create record?");
				scanf("%d",&n);				
				newRecord(n,s);
			break;
			case 2:
				displayRecord(n,s);
			break;
			case 3:
				x = search(n,s);
			break;
			case 4:
				updateRecord(n,s);
			break;
			case 5:
				Delete(&n,s);
			break;
			case 6:
				exit(0);
			break;
			default:printf("\nInvalid Input\n");		
		}
	}
	return 0;
}

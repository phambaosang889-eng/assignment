#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
struct SinhVien{
	char masv[20];
	char ho[10];
	char ten[15];
	char sex[10];
	double diem;
};
typedef struct SinhVien SinhVien;


SinhVien nhap(SinhVien x){
	printf("Enter student ID: ");
	gets(x.masv);
	printf("Enter student's lastname: ");
	gets(x.ho);
	printf("Enter student's firstname: ");
	gets(x.ten);
	printf("Enter gender(male/female): ");
	gets(x.sex);
	printf("Enter GPA: ");
	scanf("%lf%*c",&x.diem);
	while(x.diem<0 || x.diem>10){
		printf("Invalid value! Please try again\n");
		printf("Enter GPA: ");
		scanf("%lf%*c",&x.diem);
	}
	return x;
}


void Nhapds(SinhVien a[],int*n){
	if(*n==0){
	printf("Enter number of students to add: ");
	scanf("%d%*c",&*n);
	for(int i=0;i<*n;i++){
		printf("Student %d: \n",i+1);
		a[i]=nhap(a[i]);
	}
}
	else{
		int add;
		printf("Enter number of students to add: ");
		scanf("%d%*c",&add);
		for(int i=*n;i<(*n)+add;i++){
			printf("Student %d: \n",i+1);
			a[i]=nhap(a[i]);
		}
		*n=*n+add;
	}
}


void Xuatds(SinhVien a[],int n){
	printf("--------------------------------------------------\n");
	printf("%-10s %-10s %-10s %-10s %-5s","ID","LASTNAME","FIRSTNAME","GENDER","GPA");
	printf("\n--------------------------------------------------\n");
	for(int i=0;i<n;i++){
		printf("%-10s %-10s %-10s %-10s %-5.2lf\n",a[i].masv,a[i].ho,a[i].ten,a[i].sex,a[i].diem);
	}
}


int timsvtheoma(SinhVien a[],int n){
	char ma[20];
	printf("Enter student's ID to find: ");
	gets(ma);
	int i;
	int c=2055;
	for(i=0;i<n;i++){
		if(strcmp(a[i].masv,ma)==0){
			c=i;
			break;
		}
	}
	return c;
}


void suadiem(SinhVien a[],int n){
	int b=timsvtheoma(a,n);
	if(b==2055) printf("Invalid student ID\n");
	else{
		printf("--------------------------------------------------\n");
		printf("%-10s %-10s %-10s %-10s %-5s","ID","LASTNAME","FIRSTNAME","GENDER","GPA");
		printf("\n--------------------------------------------------\n");
		printf("%-10s %-10s %-10s %-10s %-5.2lf\n",a[b].masv,a[b].ho,a[b].ten,a[b].sex,a[b].diem);
		printf("Enter new GPA: ");
		scanf("%lf%*c",&a[b].diem);
		printf("Updated successfully");
	}
}


void suahoten(SinhVien a[],int n){
	int b=timsvtheoma(a,n);
	if(b==2055) printf("Invalid student ID\n");
	else{
		printf("--------------------------------------------------\n");
		printf("%-10s %-10s %-10s %-10s %-5s","ID","LASTNAME","FIRSTNAME","GENDER","GPA");
		printf("\n--------------------------------------------------\n");
		printf("%-10s %-10s %-10s %-10s %-5.2lf\n",a[b].masv,a[b].ho,a[b].ten,a[b].sex,a[b].diem);
		printf("Enter new lastname: ");
		gets(a[b].ho);
		printf("Enter new firstname: ");
		gets(a[b].ten);
		printf("Updated successfully");
	}
}


void xoattin(SinhVien a[],int *n){
	int b=timsvtheoma(a ,*n);
	if(b==2055) printf("Invalid student ID\n");
	else{
		printf("--------------------------------------------------\n");
		printf("%-10s %-10s %-10s %-10s %-5s","ID","LASTNAME","FIRSTNAME","GENDER","GPA");
		printf("\n--------------------------------------------------\n");
		printf("%-10s %-10s %-10s %-10s %-5.2lf\n",a[b].masv,a[b].ho,a[b].ten,a[b].sex,a[b].diem);
		printf("Confirm delete?\nYes: 1\nNo: 2\n");
		int c;
		scanf("%d%*c",&c);
		if(c==1){
			for(int i=b;i<*n-1;i++){
				a[i]=a[i+1];
			}
			(*n)--;
			printf("Deleted successfully");
		}
		else printf("Canceled successfully");
	}
}


int cmpdiemgiam(const void *a,const void *b){
	SinhVien *x=(SinhVien*)a;
	SinhVien *y=(SinhVien*)b;
	if((*x).diem<(*y).diem) return 1;
	else if((*x).diem>(*y).diem) return -1;
	else return 0;
}

int cmpdiemtang(const void *a,const void *b){
	SinhVien *x=(SinhVien*)a;
	SinhVien *y=(SinhVien*)b;
	if((*x).diem>(*y).diem) return 1;
	else if((*x).diem<(*y).diem) return -1;
	else return 0;
}


int cmpten(const void *a,const void *b){
	SinhVien *x=(SinhVien*)a;
	SinhVien *y=(SinhVien*)b;
	return strcmp((*x).ten,(*y).ten);
}


int cmpma(const void *a,const void *b){
	SinhVien *x=(SinhVien*)a;
	SinhVien *y=(SinhVien*)b;
	return strcmp((*x).masv,(*y).masv);
}


void sapxeptheodiemgiam(SinhVien a[],int n){
	qsort(a,n,sizeof(SinhVien),cmpdiemgiam);
}


void sapxeptheoten(SinhVien a[],int n){
	qsort(a,n,sizeof(SinhVien),cmpten);
}


void xuattheoma(SinhVien a[],int n){
	qsort(a,n,sizeof(SinhVien),cmpma);
	Xuatds(a,n);
}


void select(SinhVien a[],int n,float i,float j){
	float s[n];
	for(int t;t<n;t++){
		s[t]=a[t].diem;
	}
	qsort(s,n,sizeof(float),cmpdiemtang);
	printf("--------------------------------------------------\n");
	printf("%-10s %-10s %-10s %-10s %-5s","ID","LASTNAME","FIRSTNAME","GENDER","GPA");
	printf("\n--------------------------------------------------\n");
	for(int c=0;c<n;c++){
		if(s[c]>=i &&s[c]<=j){
			for(int v=0;v<n;v++){
				if(a[v].diem == s[c]){
			printf("%-10s %-10s %-10s %-10s %-5.2lf\n",a[v].masv,a[v].ho,a[v].ten,a[v].sex,a[v].diem);
		}
	}
	}
}
}


void xuattheodiemtrongkhoang(SinhVien a[],int n){
	float i,j;
	printf("Enter GPA range (min max): ");
	scanf("%f%f",&i,&j);
	select(a,n,i,j);
}

void xuatdiemtbmaxmin(SinhVien a[],int n){
	float tong=0;
	float s[n];
	for(int i;i<n;i++){
		s[i]=a[i].diem;
	}
	qsort(s,n,sizeof(float),cmpdiemtang);
	for(int i=0;i<n;i++){
		tong=tong + a[i].diem;
	}
	float max=s[n-1];
	float min=s[0];
	printf("Highest GPA: %.2f",max);
	printf("\nAverage GPA: %.2f",tong/n);
	printf("\nLowest GPA: %.2f",min);
}
int main() {
    system("cls");
    // INPUT - @STUDENT: ADD YOUR CODE FOR INPUT HERE:
	SinhVien a[1000];
    int n = 0, choice;
    
    
    // Fixed Do not edit anything here.
    //@STUDENT: WRITE YOUR OUTPUT HERE
    do {
        printf("\n==================Menu==================\n");
        printf("1.Add students\n");
        printf("2.Edit GPA\n");
        printf("3.Edit name\n");
        printf("4.Delete student\n");
        printf("5.Sort by GPA (descending)\n");
        printf("6.Sort by name (ascending)\n");
        printf("7.Print list\n");
        printf("8.Print students sorted by ID\n");
        printf("9.Print students within GPA range\n");
        printf("10.Print GPA statistics (avg, max, min)\n");
        printf("0.Exit\n");
        printf("==========================================\n");
        printf("Enter your choice: ");
        scanf("%d%*c",&choice);
        switch(choice){
            case 1:
				Nhapds(a,&n);
				break;
            case 2:
            	if(n==0){
    				printf("The student list is empty");
    				break;
				}
				suadiem(a,n); 
				break;
            case 3:
            	if(n==0){
    				printf("The student list is empty");
    				break;
				}
				suahoten(a,n);
				 break;
            case 4:
            	if(n==0){
    				printf("The student list is empty");
    				break;
				}
				xoattin(a,&n);
				break;
            case 5:
            	if(n==0){
    				printf("The student list is empty");
    				break;
				}
				sapxeptheodiemgiam(a,n); 
				break;
            case 6:
            	if(n==0){
    				printf("The student list is empty");
    				break;
				}
				sapxeptheoten(a,n); 
				break;
            case 7:
            	if(n==0){
    				printf("The student list is empty");
    				break;
				}
				Xuatds(a,n);
				break;
            case 8:
            	if(n==0){
    				printf("The student list is empty");
    				break;
				}
				xuattheoma(a,n); 
				break;
            case 9:
            	if(n==0){
    				printf("The student list is empty");
    				break;
				}
				xuattheodiemtrongkhoang(a,n);
				break;
            case 10:
            	if(n==0){
    				printf("The student list is empty");
    				break;
				}
				xuatdiemtbmaxmin(a,n);
				break;
            case 0:
				printf("Goodbye\n"); 
				break;
            default:
				printf("Invalid choice! Please try again\n");
				break;
        }
    } while (choice != 0);



    

    //--FIXED PART - DO NOT EDIT ANY THINGS HERE
    printf("\n");
    system("pause");
    return(0);
}



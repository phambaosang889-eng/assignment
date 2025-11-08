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
	printf("nhap ma sv: ");
	gets(x.masv);
	printf("nhap ho sv: ");
	gets(x.ho);
	printf("nhap ten sv: ");
	gets(x.ten);
	printf("nhap gioi tinh sv: ");
	gets(x.sex);
	printf("nhap diem tong ket: ");
	scanf("%lf%*c",&x.diem);
	return x;
}


void Nhapds(SinhVien a[],int*n){
	if(*n==0){
	printf("Nhap so luong sinh vien them vao: ");
	scanf("%d%*c",&*n);
	for(int i=0;i<*n;i++){
		printf("Sinh vien thu %d: \n",i+1);
		a[i]=nhap(a[i]);
	}
}
	else{
		int add;
		printf("Nhap so luong sinh vien them vao: ");
		scanf("%d%*c",&add);
		for(int i=*n;i<(*n)+add;i++){
			printf("Sinh vien thu %d: \n",i+1);
			a[i]=nhap(a[i]);
		}
		*n=*n+add;
	}
}


void Xuatds(SinhVien a[],int n){
	printf("-----------------------------------------------------------------\n");
	printf("%-20s %-10s %-15s %-10s %-5s","MSV","HO","TEN","GIOITINH","DIEM");
	printf("\n-----------------------------------------------------------------\n");
	for(int i=0;i<n;i++){
		printf("%-20s %-10s %-15s %-10s %-5.2lf\n",a[i].masv,a[i].ho,a[i].ten,a[i].sex,a[i].diem);
	}
}


int timsvtheoma(SinhVien a[],int n){
	char ma[20];
	printf("Nhap ma sv can tim: ");
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
	if(b==2055) printf("Ma sv khong hop le\n");
	else{
		printf("-----------------------------------------------------------------\n");
		printf("%-20s %-10s %-15s %-10s %-5s","MSV","HO","TEN","GIOITINH","DIEM");
		printf("\n-----------------------------------------------------------------\n");
		printf("%-20s %-10s %-15s %-10s %-5.2lf\n",a[b].masv,a[b].ho,a[b].ten,a[b].sex,a[b].diem);
		printf("Nhap diem moi: ");
		scanf("%lf%*c",&a[b].diem);
		printf("Thanh cong");
	}
}


void suahoten(SinhVien a[],int n){
	int b=timsvtheoma(a,n);
	if(b==2055) printf("Ma sv khong hop le\n");
	else{
		printf("-----------------------------------------------------------------\n");
		printf("%-20s %-10s %-15s %-10s %-5s","MSV","HO","TEN","GIOITINH","DIEM");
		printf("\n-----------------------------------------------------------------\n");
		printf("%-20s %-10s %-15s %-10s %-5.2lf\n",a[b].masv,a[b].ho,a[b].ten,a[b].sex,a[b].diem);
		printf("Nhap ho moi: ");
		gets(a[b].ho);
		printf("Nhap ten moi: ");
		gets(a[b].ten);
		printf("Thanh cong");
	}
}


void xoattin(SinhVien a[],int *n){
	int b=timsvtheoma(a ,*n);
	if(b==2055) printf("Ma sv khong hop le\n");
	else{
		printf("-----------------------------------------------------------------\n");
		printf("%-20s %-10s %-15s %-10s %-5s","MSV","HO","TEN","GIOITINH","DIEM");
		printf("\n-----------------------------------------------------------------\n");
		printf("%-20s %-10s %-15s %-10s %-5.2lf\n",a[b].masv,a[b].ho,a[b].ten,a[b].sex,a[b].diem);
		printf("Xac nhan xoa\nYes: nhap 1\nNo: nhap 2\n");
		int c;
		scanf("%d%*c",&c);
		if(c==1){
			for(int i=b;i<*n-1;i++){
				a[i]=a[i+1];
			}
		}
		(*n)--;
		printf("Thanh cong");
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
	qsort(a,n,sizeof(SinhVien),cmpdiemtang);
	printf("-----------------------------------------------------------------\n");
	printf("%-20s %-10s %-15s %-10s %-5s","MSV","HO","TEN","GIOITINH","DIEM");
	printf("\n-----------------------------------------------------------------\n");
	for(int d=0;d<n;d++){
		if(a[d].diem>=i && a[d].diem<=j){
			printf("%-20s %-10s %-15s %-10s %-5.2lf\n",a[d].masv,a[d].ho,a[d].ten,a[d].sex,a[d].diem);
		}
	}
}


void xuattheodiemtrongkhoang(SinhVien a[],int n){
	float i,j;
	printf("Nhap khoang diem: ");
	scanf("%f%f",&i,&j);
	select(a,n,i,j);
}

void xuatdiemtbmaxmin(SinhVien a[],int n){
	float tong=0;
	qsort(a,n,sizeof(SinhVien),cmpdiemgiam);
	for(int i=0;i<n;i++){
		tong=tong + a[i].diem;
	}
	float max=a[0].diem;
	float min=a[n-1].diem;
	printf("Diem cao nhat la: %.2f",max);
	printf("\nDiem trung binh la: %.2f",tong/n);
	printf("\nDiem thap nhat la: %.2f",min);
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
        printf("1.Nhap thong tin sinh vien them vao\n");
        printf("2.Sua diem tong ket\n");
        printf("3.Sua ho va ten\n");
        printf("4.Xoa sinh vien\n");
        printf("5.Sap xep giam dan theo diem\n");
        printf("6.Sap xep tang dan theo ten\n");
        printf("7.Xuat danh sach\n");
        printf("8.Xuat sinh vien theo ma\n");
        printf("9.Xuat theo khoang diem\n");
        printf("10.Xuat theo diem trung binh, max va min\n");
        printf("0.Thoat\n");
        printf("==========================================\n");
        printf("Nhap yeu cau: ");
        scanf("%d%*c", &choice);
        switch(choice){
            case 1:
				Nhapds(a,&n);
				break;
            case 2:
            	if(n==0){
    				printf("Danh sach sinh vien trong");
    				break;
				}
				suadiem(a,n); 
				break;
            case 3:
            	if(n==0){
    				printf("Danh sach sinh vien trong");
    				break;
				}
				suahoten(a,n);
				 break;
            case 4:
            	if(n==0){
    				printf("Danh sach sinh vien trong");
    				break;
				}
				xoattin(a,&n);
				break;
            case 5:
            	if(n==0){
    				printf("Danh sach sinh vien trong");
    				break;
				}
				sapxeptheodiemgiam(a,n); 
				break;
            case 6:
            	if(n==0){
    				printf("Danh sach sinh vien trong");
    				break;
				}
				sapxeptheoten(a,n); 
				break;
            case 7:
            	if(n==0){
    				printf("Danh sach sinh vien trong");
    				break;
				}
				Xuatds(a,n);
				break;
            case 8:
            	if(n==0){
    				printf("Danh sach sinh vien trong");
    				break;
				}
				xuattheoma(a,n); 
				break;
            case 9:
            	if(n==0){
    				printf("Danh sach sinh vien trong");
    				break;
				}
				xuattheodiemtrongkhoang(a,n);
				break;
            case 10:
            	if(n==0){
    				printf("Danh sach sinh vien trong");
    				break;
				}
				xuatdiemtbmaxmin(a,n);
				break;
            case 0:
				printf("Goodbye\n"); 
				break;
            default:
				printf("Vui long chon lai\n");
				break;
        }
    } while (choice != 0);



    

    //--FIXED PART - DO NOT EDIT ANY THINGS HERE
    printf("\n");
    system("pause");
    return(0);
}

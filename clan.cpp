#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
int so_nguoi;
struct oni{
	int today;
	int tomon;
};
typedef oni oni;
oni now;
struct oppa{ 
int turn; 
int ngay;
int thang;
int age;
char ten[5];
};
typedef oppa oppa;
oppa nguoi[50];
int date(int *day,int *mon,int cong ){
	*day=*day + cong;
	if (*mon==2&&*day>29) {*day=*day-29; *mon=*mon+1;if(*mon>12) *mon=*mon-12;}
	switch(*mon)
	{case 1: case 3:case 5: case 7: case 8:case 10:case 12: {if (*day>31) {*day=*day-31; *mon=*mon+1;if(*mon>12) *mon=*mon-12;} }
	case 4: case 6:case 9: case 11:{if (*day>30) {*day=*day-30; *mon=*mon+1;if(*mon>12) *mon=*mon-12;} }
	}
	}
int date2(int day,int mon){
	switch(mon){
	case 1: return (day+0);break;
	case 2: return (day+31);break;
	case 3: return (day+31+29);break;
	case 4: return (day+31+29+31);break;
	case 5: return (day+31+29+31+30);break;
	case 6: return (day+31+29+31+30+31);break;
	case 7: return (day+31+29+31+30+31+30);break;
	case 8: return (day+31+29+31+30+31+30+31);break;
	case 9: return (day+31+29+31+30+31+30+31+31);break;
	case 10: return (day+31+29+31+30+31+30+31+31+30);break;
	case 11: return (day+31+29+31+30+31+30+31+31+30+31);break;
	case 12: return (day+31+29+31+30+31+30+31+31+30+31+30);break;
	default : return 0; break;}
}
int load() {
	int i,o;
	FILE*p2;
	p2=fopen("clan.dat","rb");
	if (p2==NULL){
	printf("\nKhong mo duoc file clan.dat\nKet thuc chuong trinh va sua loi truoc khi tiep tuc."); getch();}
	else if(fread(&o,4,1,p2)==0) {printf("\nXin moi vao input de nhap du lieu moi");}
	else {
	rewind(p2);
	fread(&now,sizeof(oni),1,p2);
	fread(&so_nguoi,sizeof(int),1,p2);
	for (i=0;i<so_nguoi;i++)
	fread(&nguoi[i],sizeof(oppa),1,p2);
	fclose(p2);}
}
int save(){
	int i;
	FILE*p1;
	p1=fopen("clan.dat","wb");
	fwrite(&now,sizeof(oni),1,p1);
	fwrite(&so_nguoi,sizeof(int),1,p1);
	for (i=0;i<so_nguoi;i++)
	fwrite(&nguoi[i],sizeof(oppa),1,p1);
	fclose(p1);
}
int updatengay(){
	int i,a,b;
	system("cls");
	load();
	printf("\nChao mung tro lai, Hom nay la ngay may vay?");
printf("\nTra loi: ________ngay: ");scanf("%d",&now.today);
printf("\nTra loi: ________thang: ");scanf("%d",&now.tomon);
printf("\nXong!Chuc ban ngay moi tot lanh"); 
for (i=0;i<so_nguoi;i++) {
nguoi[i].turn=0;
if (nguoi[i].age<7){nguoi[i].ngay=now.today+1;nguoi[i].thang=now.tomon;}
}
save();
printf("\n...Moi ngay chi cap nhat ngay thang 1 lan!");
printf ("\nNhan phim bat ki de quay lai man hinh chinh.");getch();
}
int input(){
	int i=0;
	char ch;
	system("cls");
	printf("\nChu y: thao tac nay se reset het du lieu thanh vien cua ban, ban co muon tiep tuc? (Y/...)  ");
	ch=getch();
	if (ch=='Y'||ch=='y'){printf("\n Bat dau input, de nghi dvd tap trung nhu di thi dai hoc!:");
	printf("\nHom nay la ngay may? ");scanf("%d",&now.today);
	printf("\n-----------thang may?");scanf("%d",&now.tomon);
	
	do{ 
	    
		printf("\n Ten thanh vien %d: ",i+1); fflush(stdin); gets(nguoi[i].ten);
		if((strcmp(nguoi[i].ten,"het")==0)||(strcmp(nguoi[i].ten,"HET")==0)||(strcmp(nguoi[i].ten,"Het")==0)) break;
		else {
		do{
		printf("\n KEEP AGE level: "); scanf("%d",&nguoi[i].age);
		if (nguoi[i].age>9||nguoi[i].age<0) printf("\nCan than chut! 0<level age <=9.Hay nhap lai");
	     }while(nguoi[i].age>9||nguoi[i].age<0);
		if (nguoi[i].age<7){nguoi[i].ngay=now.today+1;nguoi[i].thang=now.tomon; printf("\nNguoi nay duoc mien thue");}
		else{
		printf("\n Den han nop thue vao ngay:");scanf("%d",&nguoi[i].ngay);
	    do{printf("\n       ----------vao thang:");scanf("%d",&nguoi[i].thang); if(nguoi[i].thang>12) printf("\nKhong co thang nay!, nhap lai");}while(nguoi[i].thang>12);}
	    nguoi[i].turn=0;
		i++;
	}
	  }while(i<=50);
	so_nguoi=i; printf("\nSo nguoi %d",so_nguoi);
	save();
	load();
	printf("\nXong!");
	printf ("\nNhan phim bat ki de quay lai man hinh chinh.");getch();
    }
    else{
	printf ("\nNhan phim bat ki de quay lai man hinh chinh.");getch();}
}
int napthue();
int quatrinhnap();
int indanhsach();
int quatrinhnap(){
	char ten[5]; 
	int i=0,x,plush;
		
	    printf("\nXin moi nhap ten thanh vien :"); fflush(stdin); gets(ten);
		while(1){
		if(strcmp(ten,nguoi[i].ten)==0) {
		if (nguoi[i].age<7) printf("\n Nguoi nay lv duoi 7, khong can nap thue.\n Xin mot trang phao tay hoan ho %s",nguoi[i].ten);
		else {
		printf("\n nap X turn:   X=?    ");scanf("%d",&x);nguoi[i].turn=nguoi[i].turn+x;
		switch(nguoi[i].age){
		case 7: plush=7*x; break;
		case 8: plush=5*x; break;
		case 9: plush=3*x; break;
	     }
		date(&nguoi[i].ngay,&nguoi[i].thang,plush); ;printf("\n OK! ");break;}}
		else i++;
		if(i==so_nguoi){printf("\n Khong tim thay thanh vien nay. Chu y xem ban da tat capslosk hay chua ?,");i=0;getch();break;}
	    }
}
int indanhsach(){
	int j;
	system("cls");
	printf("\n __________________Nap thue trong ngay_____________________");
	printf("\n|    Ten    |               So lan nap                     | ");
	for (j=0;j<so_nguoi;j++) 
	if (nguoi[j].turn>0) 
	printf("\n|   %s     |                   %d                         |",nguoi[j].ten,nguoi[j].turn);
	printf("\n-----------------------------------------------------------");
}
napthue(){
	char ch;
	load();
	while(1){
	system("cls");
	indanhsach();
	quatrinhnap();
	printf("\n Tiep tuc? (Y/...) ");
	ch=getch(); if (ch!='y'&&ch!='Y') break;
}
	save();
	printf("\nXong!");
	printf ("\nNhan phim bat ki de quay lai man hinh chinh.");getch();}
int danhsachtatca(){
	int i;
	char taxed[5],ch;
	system("cls");
	load();
	printf("\n             DANH SACH THANH VIEN: ");printf("\n");
	printf("\n ______________________________________________");
	printf("\n|   Ten    | LEVEl AGE | taxed | ngay het han |");
	for(i=0;i<so_nguoi;i++){
	if((date2(now.today,now.tomon)-date2(nguoi[i].ngay,nguoi[i].thang))<=0) strcpy(taxed,"  OK ");
	else if(date2(now.today,now.tomon)-date2(nguoi[i].ngay,nguoi[i].thang)>7) strcpy(taxed,"  !! ");
	else strcpy(taxed," muon");
    printf("\n|  %s   |      %2d   | %s |     %2d/%2d    |",nguoi[i].ten,nguoi[i].age,taxed,nguoi[i].ngay,nguoi[i].thang);
	}
	printf("\n-----------------------------------------------");
	printf("\nSo member: %d",so_nguoi);
	printf ("\nNhan phim bat ki de quay lai man hinh chinh.");getch();}

int danhsachmuon(){
	int i,j=0,m;
	system("cls");
	printf("\nHom nay la ngay/thang : %d/%d",now.today,now.tomon);
	printf("\n __________Danh sach muon thue(<7 ngay)______");
	printf("\n|  Ten  |        so ngay muon                |");
	for (i=0;i<so_nguoi;i++) {
    m=date2(now.today,now.tomon)-date2(nguoi[i].ngay,nguoi[i].thang);
    if((m<7)&&(m>0)){
	printf("\n| %s |              %2d                    |",nguoi[i].ten,m);j++;}
}
	printf("\n --------------------------------------------");
	printf("\nso nguoi bi muon thue: %d",j);
	printf ("\nNhan phim bat ki de quay lai man hinh chinh.");getch();
	}
int soden(){
	int i,j=0,m;
	system("cls");
	printf("\nHom nay la ngay/thang : %d/%d",now.today,now.tomon);
	printf("\n __________So den cho tram(>7 ngay)__________");
	printf("\n|  Ten  |        so ngay muon                |");
	for (i=0;i<so_nguoi;i++) {
    m=date2(now.today,now.tomon)-date2(nguoi[i].ngay,nguoi[i].thang);
    if(m>7){
	printf("\n| %s |              %2d                    |",nguoi[i].ten,m);j++;}
}
	printf("\n --------------------------------------------");
	printf("\nso nguoi trong so den: %d",j);
	printf("\nNhan phim bat ki de quay lai man hinh chinh.");getch();
	}
int them(){
	int i;
	load();
	i=so_nguoi;
	    printf("\n");
		printf("\n Ten thanh vien moi : "); fflush(stdin); gets(nguoi[i].ten);
		do{
		printf("\n KEEP AGE level: "); scanf("%d",&nguoi[i].age);
		if (nguoi[i].age>9||nguoi[i].age<0) printf("\nCan than chut! 0<level age <=9.Hay nhap lai");
	     }while(nguoi[i].age>9||nguoi[i].age<0);
		if (nguoi[i].age<7){nguoi[i].ngay=now.today+1;nguoi[i].thang=now.tomon; printf("\nNguoi nay duoc mien thue");}
		else{
		printf("\n Den han nop thue vao ngay:");scanf("%d",&nguoi[i].ngay);
	    do{printf("\n       ----------vao thang:");scanf("%d",&nguoi[i].thang); if(nguoi[i].thang>12) printf("\nKhong co thang nay!, nhap lai");}while(nguoi[i].thang>12);}
	    nguoi[i].turn=0;
		so_nguoi++;
		printf("\n so thanh vien cua clan: %d",so_nguoi);
	save();
	printf("\n OK! "); getch();
}
int bot(){
	int i=0;
	char ten[5];
	load();
	printf("\nXin moi nhap ten thanh vien :"); fflush(stdin); gets(ten);
		while(1){
		if(strcmp(ten,nguoi[i].ten)==0) {
			for(i;i<so_nguoi;i++) nguoi[i]=nguoi[i+1];
			so_nguoi=so_nguoi-1;
			save(); printf("\nOK!");break;
		}
		else i++;
		if(i==so_nguoi){printf("\n Khong tim thay thanh vien nay. Chu y xem ban da tat capslosk hay chua ?,");i=0;getch();break;}
	    }
}
int sua(){
	int i=0;
	char ten[5];
	load();
	printf("\nXin moi nhap ten thanh vien :"); fflush(stdin); gets(ten);
		while(1){
		if(strcmp(ten,nguoi[i].ten)==0) {
			printf("\n KEEP AGE LEVEL moi: "); scanf("%d",&nguoi[i].age);
			save();
			printf("\nOK!");getch();
			break;
		}
		else i++;
		if(i==so_nguoi){printf("\n Khong tim thay thanh vien nay. Chu y xem ban da tat capslosk hay chua ?,");i=0;getch();break;}
	    }
}
int capnhatthanhvien(){
	char ch;
	do{
	system("cls");
	printf("\n xin moi chon chuc nang: \n          (1)Them thanh vien\n          (2)Xoa thanh vien\n          (3)Cap nhat level age\n          (x)tro ve menu chinh");
	ch=getch();
	if (ch=='1') them();
	else if(ch=='2') bot();
	else if(ch=='3') sua();
	else if(ch=='x') { save();
	printf("\nXong");
	printf ("\nNhan phim bat ki de quay lai man hinh chinh.");getch();break;}
	else {printf ("\nHey! Can than chut, go tu(0->3 hoac x).-->enter");
	getch();}
}while(1);}
int tracuu(){
	int i=0;
	char ten[5];
	system("cls");
	load();
	printf("\nXin moi nhap ten thanh vien :"); fflush(stdin); gets(ten);
		while(1){
		if(strcmp(ten,nguoi[i].ten)==0) {
			printf("\n ___________________________________________________");
			printf("\n|  Ten  | age | Ngay het han | nap thue trong ngay  |");
			printf("\n| %s |  %2d |     %2d/%2d    |            %2d        | ",nguoi[i].ten,nguoi[i].age,nguoi[i].ngay,nguoi[i].thang,nguoi[i].turn);
			printf("\n-----------------------------------------------------");
		getch();
			break;
		}
		else i++;
		if(i==so_nguoi){printf("\n Khong tim thay thanh vien nay. Chu y xem ban da tat capslosk hay chua ?,");i=0;getch();break;}
	    }
	printf ("\nNhan phim bat ki de quay lai man hinh chinh.");getch();
}
int allvacation(){
	int i,n;
	int day,mon;
	load();
	printf("\n Ban muon mien nap thue cho toan bo clan den ngay nao? ");
	printf("\n");
	printf("\n  ---------------------------------Den ngay:");scanf("%d",&day);
	printf("\n  ------------------------------------thang:");scanf("%d",&mon);
	FILE*o;
	
	n=date2(day,mon)-date2(now.today,now.tomon);
	o=fopen("vacation.dat","wb");
	fwrite(&day,sizeof(int),1,o);
	fwrite(&mon,sizeof(int),1,o);
	fwrite(&n,sizeof(int),1,o);
	fclose(o);
	for (i=0;i<so_nguoi;i++) date(&nguoi[i].ngay,&nguoi[i].thang,n);
	save();
	printf("\nXong! Chuc tat ca nghi le vui ve!");
	printf("\nTat ca thong tin han nap thue hien tai deu da duoc cong vao sau ngay le");
	getch();
}
int membervacation(){
	int day,mon,n,i;
	char ten[5];
	load();
	printf("\nBan muon cho thanh vien nao nghi le? :"); fflush(stdin); gets(ten);
		while(1){
		if(strcmp(ten,nguoi[i].ten)==0) {
			printf("\nNghi le bao nhieu ngay? ");scanf("%d",&n);
			date(&nguoi[i].ngay,&nguoi[i].thang,n);
			save();
			printf("OK!Hi vong co ngay gap lai %s yeu dau.",nguoi[i].ten);
		getch();
			break;
		}
		else i++;
		if(i==so_nguoi){printf("\n Khong tim thay thanh vien nay. Chu y xem ban da tat capslosk hay chua ?,");i=0;getch();break;}
	    }
}
int offvacation(){
	int day,mon,i,n;
	char ch;
	load();
	FILE*o;
	o=fopen("vacation.dat","rb");
	fread(&day,sizeof(int),1,o);
	fread(&mon,sizeof(int),1,o);
	fread(&n,sizeof(int),1,o);
	fclose(o);
	n=n-(date2(day,mon)-date2(now.today,now.tomon));
	printf("\nKi nghi con %d ngay:",n);
    printf("\nBan co muon cho tat ca hoat dong lai binh thuong luon ko? (Y/...)");
    ch=getch();
    if(ch=='Y'||ch=='y'){
	for (i=0;i<so_nguoi;i++) date(&nguoi[i].ngay,&nguoi[i].thang,-n);
    save();
    printf("\nXong!"); getch();}
    else getch();
    
}
int vacation(){
	char ch;
	do{
	system("cls");
	printf("\n xin moi chon chuc nang: \n          (1)Tat ca clan nghi le\n          (2)Thanh vien xin nghi phep vai ngay\n          (3)comeback\n          (x)tro ve menu chinh");
	ch=getch();
	if (ch=='1') allvacation();
	else if(ch=='2') membervacation();
	else if(ch=='3') offvacation();
	else if(ch=='x') { save();
	printf("\nXong");
	printf ("\nNhan phim bat ki de quay lai man hinh chinh.");getch();break;}
	else {printf ("\nHey! Can than chut, go tu(1->3 hoac x).-->enter");
	getch();}
}while(1);}
int xoa(){
	char h;
	printf("\n");
	printf("\nBan co chac se xoa het du lieu khong? (Y/...) ");
	h=getch();
	if (h=='y'||h=='Y') {
		FILE*o;
		o=fopen("clan.dat","wb");
		fclose(o);
		printf("\n\nXong"); getch();
	}
	else {printf("\n Xac nhan khong xoa gi ca."); getch();}
}
int reset(){
	int i;
	load();
	for(i=0;i<so_nguoi;i++) {nguoi[i].ngay=now.today; nguoi[i].thang=now.tomon;}
	save();
	printf("\n \n Xong!");
	getch();
}
int redcode(){
	char ch;
	do{
	system("cls");
	printf("\n xin moi chon redcode: \n          (1)Xoa toan bo du lieu\n          (2)reset het han nap thue cac thanh vien ve hom nay\n          (x)tro ve menu chinh");
	ch=getch();
	if (ch=='1') xoa();
	else if(ch=='2') reset();
    else if(ch=='x') { save();
	printf("\nXong");
	printf ("\nNhan phim bat ki de quay lai man hinh chinh.");getch();break;}
	else {printf ("\nHey! Can than chut, go tu(1->2 hoac x).-->enter");
	getch();}
}while(1);
	
}
int main(){
	int o;
    char ch;
	do{
	system("cls");
	printf("\n    oxxx((::::::::>  HONEY CLAN!  <::::::::))xxxo      )");
	printf("\n");	printf("\n");	printf("\n");
	printf("\n Xin moi nhap so de chon chuc nang:");
	printf("\n");
	printf("\n(0)-update ngay ");
	printf("\n(1)-input ");
	printf("\n(2)-nap thue ");
	printf("\n(3)-danh sach tat ca");
	printf("\n(4)-danh sach muon");
	printf("\n(5)-so den");
	printf("\n(6)-cap nhat thanh vien");
	printf("\n(7)-tra cuu:");
	printf("\n(8)-vacation");
	printf("\n(9)-redcode");
	printf("\n(x)-ket thuc chuong trinh");
	
	FILE*p1;
	p1=fopen("clan.dat","rb");
	if(fread(&o,4,1,p1)==0)
	printf("\nXin moi vao input de nhap du lieu moi"); 
	fclose(p1);
	
	ch=getch();
	if (ch=='1') input();
	else if (ch=='0') updatengay();
	else if (ch=='2') napthue();
	else if (ch=='3') danhsachtatca();
	else if (ch=='4') danhsachmuon();
	else if (ch=='5') soden();
	else if (ch=='6') capnhatthanhvien();
	else if (ch=='7') tracuu();
	else if (ch=='8') vacation();
	else if (ch=='9') redcode();
	else if (ch=='x') {
	printf("\nChan roi a? Y/.."); fflush(stdin);ch=getch();
	if(ch=='y'||ch=='Y')
	 break;}
	else {printf ("\nHey! Can than chut, go tu(0->9 hoac x).-->enter");
	getch();}
	}while(1);
}



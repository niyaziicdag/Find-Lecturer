#include <stdio.h>
#include <stdlib.h>

typedef struct Dersler{
	int dersId;
    char dersAd[50];
	int hocaID;
    struct Dersler* next; 
}Dersler;

Dersler *headDers=NULL,*new,*son=NULL;

void dersEkle(int dersID,char dersAd[50],int hocaID)
{

    new = (Dersler *) malloc(sizeof (Dersler));
    new->dersId=dersID;
    strcpy(new->dersAd, dersAd);
    new->hocaID=hocaID;
    new->next = NULL;
 
    if (headDers == NULL) { //Ýlk düðümde eleman olup olmadýðýný kontrol et.
        headDers = new;
        son = headDers;
    } else { //Ýlk düðümde eleman varsa bu iþlemleri yap.
        son->next = new;
        son = son->next;
    }
    ////////////////
}
typedef struct Hoca{
	int HocaId;
    char Ad[50];
    char Soyad[50];
    struct Hoca* next; 
}Hoca;

Hoca *headHoca=NULL,*hnew,*hson=NULL;

void hocaEkle(int HocaId,char Ad[50],char Soyad[50])
{

    hnew = (Hoca *) malloc(sizeof (Hoca));
    hnew->HocaId=HocaId;
    strcpy(hnew->Ad, Ad);
    strcpy(hnew->Soyad, Soyad);
    hnew->next = NULL;
 
    if (headHoca == NULL) { //Ýlk düðümde eleman olup olmadýðýný kontrol et.
        headHoca = hnew;
        hson = headHoca;
    } else { //Ýlk düðümde eleman varsa bu iþlemleri yap.
        hson->next = hnew;
        hson = hson->next;
    }
    ////////////////
}
void araListele(int secim,int id){
	int id1=0,bulundu=0;
	int dersID,hocaID,text[128];
	char cdizi[128],tmp[128],*pch; 	
	strcpy(text,"");
	char ad[50],soyad[50];
			FILE *fp;
			if(secim==1){
			
    			fp=fopen("Hocalar.txt","r");
    			while(!feof(fp)){
      	 			fscanf(fp,"%d %s %s",&id1,ad,soyad);
      	 			if(id1==id){
      	 				printf("%d %s %s bulundu,verdigi dersler:\n",id1,ad,soyad);
      	 				bulundu=1;
      	 				//return 0;
      	 				hocaEkle(id1,ad,soyad);
				   }	 		
    			}
    			if(bulundu==0){
    				printf("%d nolu ID ile bir HOCA YOK.\n",id);
				}
    			fclose(fp);
    			/////
    				int say=0,say1=0;
	
	fp = fopen("Dersler.txt", "r");
	
    while (!feof(fp)){
		fgets(cdizi, 127, fp);
		strcpy(tmp,cdizi);
		pch = strtok (cdizi," ,.-");
		while (pch != NULL)
   		{
    		pch = strtok (NULL, " ,.-");
    		say++;
  		}
  		strcpy(cdizi,tmp);
  		pch = strtok (cdizi," ,.-");
		while (pch != NULL)
   		{
   			if(say1==0) dersID=atoi(pch);
   			if(say1==say-1) hocaID=atoi(pch);
   			if(say1!=0 && say1!=say-1) { strcat(text,pch); strcat(text," ");}
    		pch = strtok (NULL, " ,.-");
    		say1++;		
  		}
  		say1=0;
  		say=0;
  		
  		if (id==hocaID){
  		printf("%d %s %d \n",dersID,text,hocaID);
  		dersEkle(dersID,text,hocaID);
  		 }
  		 
  		strcpy(text,"");
	}
	
	fclose(fp);
    			////
			}
			if(secim==2){
			//////////////
					
    			
	
	fp = fopen("Dersler.txt", "r");
	int say=0,say1=0,knt=0,tmpHoca;
    while (!feof(fp)){
		fgets(cdizi, 127, fp);
		strcpy(tmp,cdizi);
		pch = strtok (cdizi," ,.-");
		while (pch != NULL)
   		{
    		pch = strtok (NULL, " ,.-");
    		say++;
  		}
  		strcpy(cdizi,tmp);
  		pch = strtok (cdizi," ,.-");
		while (pch != NULL)
   		{
   			if(say1==0) dersID=atoi(pch);
   			if(say1==say-1) hocaID=atoi(pch);
   			if(say1!=0 && say1!=say-1) { strcat(text,pch); strcat(text," ");}
    		pch = strtok (NULL, " ,.-");
    		say1++;		
  		}
  		say1=0;
  		say=0;
  		
  		if (id==dersID){
  		printf("%d %s %d \n",dersID,text,hocaID);
  		dersEkle(dersID,text,hocaID);
  		tmpHoca=hocaID;
  		knt=1;
  		 }
  		 
  		strcpy(text,"");

	}
	if(knt!=1){
		printf("Ders bulunamadi\n");
		return;
	} 
	fclose(fp);
	if (knt==1){
	fp=fopen("Hocalar.txt","r");
	
    			while(!feof(fp)){
      	 			fscanf(fp,"%d %s %s",&id1,ad,soyad);
      	 			//printf("HOCA ID:%d  id1:%d\n",tmpHoca,id1);
      	 			if(tmpHoca==id1){
      	 				printf("Dersi veren hoca bilgisi:%d %s %s \n",id1,ad,soyad);
      	 				hocaEkle(id1,ad,soyad);
      	 				bulundu=1;
      	 				//return 0;
      	 		//	addHoca(id,isim,soyisim,kod);
				   }	 		
    			}
    			if(bulundu==0){
    				printf("%d nolu ID ile bir HOCA YOK.\n",id);
				}
    			fclose(fp);
    			/////
    		}
    		knt=0;
			//////////////
			}
				
}
void menu() {
    int secim,id,guncelle=0;
    printf("1-Soru1 - Hocanin Verdigi Dersler\n");
    printf("2-Soru2 - Dersi Veren Hoca\n");
    printf("3-Soru3 - Hoca Duzenleme(SORU YAPILMADI!!)\n");
    printf("4-Cikis\n");
    printf("Lutfen Secim Yapiniz --> ");
    scanf("%d", &secim);

    switch (secim) {
        case 1:
            //ekranTemizle();
			printf("Arama yapilacak HOCA_ID bilgisini giriniz:");
			scanf("%d",&id);
			araListele(secim,id);
            bekle();
            break;
        case 2:
            //ekranTemizle();
			printf("Arama yapilacak DERS_ID bilgisini giriniz:");
			scanf("%d",&id);
			araListele(secim,id);
            bekle();
            break;
        case 3:
            ekranTemizle();
          	printf("Guncelleme isleminin yapilacagi HOCA_ID bilgisini giriniz:");
			scanf("%d",id);
            printf("Isim guncellemesi icin 1 Soyisim guncellemesi icin 2 'ye basiniz:");
            scanf("%d",&guncelle);
            //Guncelleme fonksiyonu buraya gelecek
            
            bekle();
            break;
        case 4:
            ekranTemizle();
            printf("Program Kapatildi!\n");
            exit(0);
            break;
        default:
            ekranTemizle();
            printf("Hatali Secim\n");
            bekle();
    }
}
void ekranTemizle() {
    system("cls");
}
void bekle() {
    char temp;
    printf("Devam etmek icin Enter'a basiniz!\n");
    temp = getchar();
    temp = getchar();
    ekranTemizle();
 
}
main(){
 while (1) menu();
	FILE *fp;

	

/*FSEEK ÖRNEK 1 YAZMAK ÝÇÝN KULLANILABÝLÝR
		  FILE * pFile;
  pFile = fopen ("Dersler.txt","w");
  fputs ("Ornek metin denemesi",pFile);
  fseek (pFile,11,SEEK_SET);
  fputs (" asdsds",pFile);
  fclose (pFile);
  return 0;*/
	   
}

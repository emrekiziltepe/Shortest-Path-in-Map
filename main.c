
//150201181 - Emre Kiziltepe

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <allegro.h>

#define il 81
#define max 9999

BITMAP *bmp;
BITMAP *harita;

PALETTE pal;

char ilKodu_char[81][20];
char ilAdi[81][20];

int mtrs[il][il];
int gecici[81];
int temp[il];

char d1[81][20];
char d2[81][20];
char d3[81][20];

int sayac=0;
int ilSayisi=0;
int mesafeSay=0;

void dosya_oku();
void mtrsOlustur();

int main()
{
    setlocale(LC_ALL, "Turkish");

    dosya_oku();
    mtrsOlustur();

    int i,j,bas_sehir,hedef_sehir,kisaYol,sehir;
    char har,secim;
    int deneme,yoltut;
    int dijkstra(int[][j],int,int,int);

    printf("<-----Sehir Listesi----->\n");

    for(i=0;i<ilSayisi;i++){
            printf("%s-%s\t",ilKodu_char[i],ilAdi[i]);
            printf("\n");
    }

    printf("\n");

    printf("Secili sehirden diger sehirlere olan mesafeyi gormek icin A tusuna,\niki sehir arasindaki mesafe icin B tusuna basiniz: ");
    scanf("%s",&secim);
    printf("\n");

    if(secim == 'B' || secim == 'b'){
        printf("\nBaslangic sehrini seciniz: ");
        scanf("%d",&bas_sehir);
        bas_sehir--;
        printf("Hedef sehri seciniz: ");
        scanf("%d",&hedef_sehir);
        hedef_sehir--;

        if(bas_sehir<0||bas_sehir>ilSayisi-1||hedef_sehir<0||hedef_sehir>ilSayisi-1)
        {
            printf("HATA!\t");
            printf("ARALIK DISI SECIM YAPTINIZ!");
            return;
        }
        printf("%d. sehir ile %d. sehir arasindaki en kisa yol : ",bas_sehir+1,hedef_sehir+1);
        kisaYol=dijkstra(mtrs,ilSayisi,bas_sehir,hedef_sehir);
        printf("\n%d. sehir ile %d. sehir arasindaki en kisa mesafe : ",bas_sehir+1,hedef_sehir+1);
        if(kisaYol!=max)
            printf("%d",kisaYol);
        else
            printf("Secilen sehirden yol yok");


        printf("\n\nHaritayi acmak icin M tusuna basiniz: ");
        scanf("%s",&har);

        if(har == 'm' || har == 'M'){
            allegro_init();
            install_keyboard();
            set_color_depth(32);
            set_window_title("Turkiye Haritasi");
            set_gfx_mode( GFX_AUTODETECT_WINDOWED, 1340, 600, 0, 0);
            acquire_screen();
            BITMAP *harita = load_bitmap("harita.bmp",NULL);
            blit(harita,screen,0,0,0,0,1340,600);
            release_screen();
            for(yoltut=0;yoltut<sayac;yoltut++){

                if((gecici[yoltut]==1 && gecici[yoltut+1]==2) || (gecici[yoltut]==2 && gecici[yoltut+1]==1)){
                    line(screen,485,224,324,235,makecol(255,0,0));
                }

                if((gecici[yoltut]==1 && gecici[yoltut+1]==3) || (gecici[yoltut]==3 && gecici[yoltut+1]==1)){
                    line(screen,485,224,401,152,makecol(255,0,0));
                }

                if((gecici[yoltut]==1 && gecici[yoltut+1]==4) || (gecici[yoltut]==4 && gecici[yoltut+1]==1)){
                    line(screen,485,224,537,166,makecol(255,0,0));
                }

                if((gecici[yoltut]==1 && gecici[yoltut+1]==5) || (gecici[yoltut]==5 && gecici[yoltut+1]==1)){
                    line(screen,485,224,574,296,makecol(255,0,0));
                }

                if((gecici[yoltut]==1 && gecici[yoltut+1]==6) || (gecici[yoltut]==6 && gecici[yoltut+1]==1)){
                    line(screen,485,224,529,234,makecol(255,0,0));
                }

                if((gecici[yoltut]==1 && gecici[yoltut+1]==7) || (gecici[yoltut]==7 && gecici[yoltut+1]==1)){
                    line(screen,485,224,563,365,makecol(255,0,0));
                }

                if((gecici[yoltut]==1 && gecici[yoltut+1]==8) || (gecici[yoltut]==8 && gecici[yoltut+1]==1)){
                    line(screen,485,224,457,408,makecol(255,0,0));
                }

                if((gecici[yoltut]==2 && gecici[yoltut+1]==9) || (gecici[yoltut]==9 && gecici[yoltut+1]==2)){
                    line(screen,324,235,322,325,makecol(255,0,0));
                }

                if((gecici[yoltut]==2 && gecici[yoltut+1]==10) || (gecici[yoltut]==10 && gecici[yoltut+1]==2)){
                    line(screen,324,235,286,264,makecol(255,0,0));
                }

                if((gecici[yoltut]==2 && gecici[yoltut+1]==11) || (gecici[yoltut]==11 && gecici[yoltut+1]==2)){
                    line(screen,324,235,289,201,makecol(255,0,0));
                }

                if((gecici[yoltut]==4 && gecici[yoltut+1]==3) || (gecici[yoltut]==3 && gecici[yoltut+1]==4)){
                    line(screen,537,166,401,152,makecol(255,0,0));
                }

                if((gecici[yoltut]==4 && gecici[yoltut+1]==6) || (gecici[yoltut]==6 && gecici[yoltut+1]==4)){
                    line(screen,537,166,529,234,makecol(255,0,0));
                }

                if((gecici[yoltut]==4 && gecici[yoltut+1]==12) || (gecici[yoltut]==12 && gecici[yoltut+1]==4)){
                    line(screen,537,166,548,97,makecol(255,0,0));
                }

                if((gecici[yoltut]==4 && gecici[yoltut+1]==13) || (gecici[yoltut]==13 && gecici[yoltut+1]==4)){
                    line(screen,537,166,470,113,makecol(255,0,0));
                }

                if((gecici[yoltut]==4 && gecici[yoltut+1]==14) || (gecici[yoltut]==14 && gecici[yoltut+1]==4)){
                    line(screen,537,166,628,170,makecol(255,0,0));
                }

                if((gecici[yoltut]==5 && gecici[yoltut+1]==7) || (gecici[yoltut]==7 && gecici[yoltut+1]==5)){
                    line(screen,574,296,563,365,makecol(255,0,0));
                }

                if((gecici[yoltut]==5 && gecici[yoltut+1]==15) || (gecici[yoltut]==15 && (gecici[yoltut+1]==5))){
                    line(screen,574,296,618,236,makecol(255,0,0));
                }

                if((gecici[yoltut]==5 && gecici[yoltut+1]==16) || (gecici[yoltut]==16 && gecici[yoltut+1]==5)){
                    line(screen,574,296,612,345,makecol(255,0,0));
                }

                if((gecici[yoltut]==8 && gecici[yoltut+1]==7) || (gecici[yoltut]==7 && gecici[yoltut+1]==8)){
                    line(screen,457,408,563,365,makecol(255,0,0));
                }

                if((gecici[yoltut]==8 && gecici[yoltut+1]==9) || (gecici[yoltut]==9 && gecici[yoltut+1]==8)){
                    line(screen,457,408,322,325,makecol(255,0,0));
                }

                if((gecici[yoltut]==8 && gecici[yoltut+1]==18) || (gecici[yoltut]==18 && gecici[yoltut+1]==8)){
                    line(screen,457,408,611,399,makecol(255,0,0));
                }

                if((gecici[yoltut]==8 && gecici[yoltut+1]==19) || (gecici[yoltut]==19 && gecici[yoltut+1]==8)){
                    line(screen,457,408,319,413,makecol(255,0,0));
                }

                if((gecici[yoltut]==8 && gecici[yoltut+1]==20) || (gecici[yoltut]==20 && gecici[yoltut+1]==8)){
                    line(screen,457,408,329,490,makecol(255,0,0));
                }

                if((gecici[yoltut]==8 && gecici[yoltut+1]==21) || (gecici[yoltut]==21 && gecici[yoltut+1]==8)){
                    line(screen,457,408,507,470,makecol(255,0,0));
                }

                if((gecici[yoltut]==8 && gecici[yoltut+1]==22) || (gecici[yoltut]==22 && gecici[yoltut+1]==8)){
                    line(screen,457,408,609,500,makecol(255,0,0));
                }

                if((gecici[yoltut]==16 && gecici[yoltut+1]==7) || (gecici[yoltut]==7 && gecici[yoltut+1]==16)){
                    line(screen,612,345,563,365,makecol(255,0,0));
                }

                if((gecici[yoltut]==16 && gecici[yoltut+1]==15) || (gecici[yoltut]==15 && gecici[yoltut+1]==16)){
                    line(screen,612,345,618,236,makecol(255,0,0));
                }

                if((gecici[yoltut]==16 && gecici[yoltut+1]==17) || (gecici[yoltut]==17 && gecici[yoltut+1]==16)){
                    line(screen,612,345,665,332,makecol(255,0,0));
                }

                if((gecici[yoltut]==16 && gecici[yoltut+1]==18) || (gecici[yoltut]==18 && gecici[yoltut+1]==16)){
                    line(screen,612,345,611,399,makecol(255,0,0));
                }

            }

            while(!key[KEY_ESC]){}
    }

}

    else if(secim=='A' || secim=='a'){
        printf("Sehrinizi seciniz: ");
        scanf("%d",&sehir);
        printf("\n");
        sehir--;
        for(i=0;i<ilSayisi;i++){
            printf("En kisa yol: ");
            deneme=dijkstra(mtrs,ilSayisi,sehir,i);
            if(deneme!=max){
                printf("\nEn kisa mesafe: ");
                printf("%d",deneme);
                printf("\n\n");
            }
        }


    }

    else
        printf("HATALI SECIM YAPTINIZ!!!");


    return 0;
}
END_OF_MAIN();


void dosya_oku()
{
    FILE * sehir_kodu_txt;
    FILE * sehir_mesafe_txt;

    char c1,c2;

    int ilKodu_deger=0;
    int ilAdi_deger=0;

    if ((sehir_kodu_txt = fopen("sehir kod.txt","r")) == NULL){
        printf("Hedef Dosya Eksik!  (sehir_kodu_txt) \n");
        exit(1);
    }

    else{
        while ((c1 = fgetc(sehir_kodu_txt)) != EOF)
        {
          switch (c1){
            case 10:
                ilSayisi++;
                ilKodu_deger=0;
                ilAdi_deger=0;
                break;
            case 45:
                break;

            default:
                if(c1>=48&&c1<=57){
                    ilKodu_char[ilSayisi][ilKodu_deger]=(char) c1;
                    ilKodu_deger++;
                }
                else{
                    ilAdi[ilSayisi][ilAdi_deger]=(char) c1;
                    ilAdi_deger++;
                }
                break;
            }
        }
        fclose(sehir_kodu_txt);
    }

    if ((sehir_mesafe_txt = fopen("sehir mesafe.txt", "r")) == NULL)
    {
        printf("Hedef Dosya Eksik! (sehir_mesafe_txt)\n");
        exit(1);
    }

    int b1 = 0;

    int d1_eleman=0;
    int d2_eleman=0;
    int d3_eleman=0;

    while ((c2 = fgetc(sehir_mesafe_txt)) != EOF)
    {
        switch (c2)
        {
        case 10:

            mesafeSay++;

            d1_eleman=0;
            d2_eleman=0;
            d3_eleman=0;

            b1=0;

            break;

        case 45:

            b1=1;
            break;

        default:
            if(c2>=48&&c2<=57)
            {
                d3[mesafeSay][d3_eleman]=(char) c2;
                d3_eleman++;
            }
            else
            {
                if(b1==1){
                d2[mesafeSay][d2_eleman]=(char) c2;
                d2_eleman++;

                }
                else {
                d1[mesafeSay][d1_eleman]=(char) c2;
                d1_eleman++;

                }

            }


        }

    }

    fclose(sehir_mesafe_txt);

}


void mtrsOlustur()
{

    int z,y;

    for(z=0;z<ilSayisi;z++)
    {
        for(y=0;y<ilSayisi;y++)
      {
          mtrs[z][y]=0;
      }

    }



    int t=0,i=0,j=0;

    for(t=0;t<=mesafeSay;t++){

        for(i=0;i<ilSayisi;i++){
            int sonuc=strcmp(d1[t],ilAdi[i]);
        if(sonuc==0)
            break;
        }

        for(j=0;j<ilSayisi;j++){
            int sonuc=strcmp(d2[t],ilAdi[j]);
        if(sonuc==0)
            break;
        }

        mtrs[i][j]=atoi(d3[t]);
        mtrs[j][i]=atoi(d3[t]);


    }

}


//http://www.mycomputerscience.net/2012/10/c-program-implement-dijkstra-algorithm.html#
int dijkstra(int a[il][il],int n,int bas_sehir,int hedef_sehir)
{
    int uzunluk[il],set[il],yol[il],i,j,x,y,tmp,temp[il],c=0,f=0;
    x=bas_sehir;
    y=hedef_sehir;
    int dijk_min(int[],int[],int);
    for(i=0;i<n;i++)
        set[i]=0;
    for(i=0;i<n;i++)
    {
        if(a[x][i]==0)
        {
            uzunluk[i]=max;
            yol[i]=0;
        }
        else
        {
            uzunluk[i]=a[x][i];
            yol[i]=x;
        }
    }
    set[x]=1;
    uzunluk[x]=0;
    while(set[y]!=1)
    {
        j=dijk_min(uzunluk,set,n);
        set[j]=1;
        for(i=0;i<n;i++)
        {
            if(set[i]!=1)
            {
                if(a[i][j]!=0)
                {
                    if(uzunluk[j]+a[i][j]<uzunluk[i])
                    {
                        uzunluk[i]=uzunluk[j]+a[i][j];
                        yol[i]=j;
                    }
                }
            }
        }
    }
    j=0;
    i=y;
    while(i!=x)
    {
        tmp=yol[i];
        temp[j]=tmp;
        i=tmp;
        j++;
        c++;
    }
    if(uzunluk[y]!=max){
        for(j=c-1;j>=0;j--)
        {
            printf("%s->",ilAdi[temp[j]]);
            gecici[sayac]=temp[j]+1;
            if(temp[j]==y)
                f=1;
            sayac++;

        }
        if(f!=1)
        {
            printf("%s",ilAdi[y]);
            gecici[sayac]=y+1;
        }
    }
     return uzunluk[y];
}


int dijk_min(int uzunluk[],int set[],int n)
{
    int min=99999,i,min_index;
    for(i=0;i<n;i++)
    {
        if(set[i]!=1)
        {
            if(uzunluk[i]<min)
            {
                min=uzunluk[i];
                min_index=i;
            }
        }
    }
    return min_index;
}


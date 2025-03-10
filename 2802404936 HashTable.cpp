#include <stdio.h>
#include<string.h>
#include<stdlib.h>

const int size = 26;

struct Table{
	int angka;
	Table *next;
	Table *prev;
} *table[size], *tHead[size], *tTail[size];

Table *createNode(int angka){
	Table *newData = (Table*)malloc(sizeof(Table));
	newData->angka = angka;
	newData->next = NULL;
	newData->prev = NULL;
	
	return newData;
}

int hash(int angka, int pilih, int col){
	
	if(pilih==1){
		int hasil = angka*angka;
		if(hasil<=999){
			printf("indexnya = %d, namun nanti kami modulo 26 ya :)\n",hasil);
			return hasil%size;
		}
		if(hasil>=1000 && hasil<=9999){
			hasil = hasil % 1000;
			printf("indexnya = %d, namun nanti kami modulo 26 ya :)\n",hasil);
			return hasil%size;
		}
		if(hasil>=10000 && hasil<=90000){
			hasil = hasil % 10000;
			int satuan;
			satuan = hasil%10;
			hasil=hasil-satuan;
			printf("indexnya = %d, namun nanti kami modulo 26 ya :)\n",hasil);
			return hasil%size;
		}
		
	}
	
	
	else if(pilih==2){
		int puluh1 = angka/1000000;
		int puluh2 = (angka/10000)%100;
		int puluh3 = (angka/100)%100;
		int puluh4 = (angka%100);
		angka = puluh1+puluh2+puluh3+puluh4;
		printf("Total angkamu = %d\n",angka);
		return angka%size;
	}
	
	
	else if(pilih==3){
		if(angka>=1&&angka<=99){
			return angka%size;
		}
		else if(angka>=100&&angka<=999){
			int angkaRatus = angka/10;
			int angkaSatuan = angka%10;
			int hasil = angkaRatus + angkaSatuan;
			hasil = hasil % 100;
			printf("indexnya = %d, namun nanti kami modulo 26 ya :)\n",hasil);
			return hasil%size;
		}
		else if(angka>=1000&&angka<=9999){
			int angkaRatusRibu = angka/100;
			int angkaPuluhSatuan = angka%100;
			int hasil = angkaRatusRibu + angkaPuluhSatuan;
			hasil = hasil % 100;
			printf("indexnya = %d, namun nanti kami modulo 26 ya :)\n",hasil);
			return hasil%size;
		}
	}
	
	else if(pilih==4){
		if(angka>=1&&angka<=99){
			return angka%size;
		}
		else if(angka>=100&&angka<=999){
			int angkaRatus = (angka/100)*10;
			int angkaSatuan = angka%10;
			int hasil = angkaRatus + angkaSatuan;
			printf("indexnya = %d, namun nanti kami modulo 26 ya :)\n",hasil);
			return hasil%size;
		}
		else if(angka>=1000&&angka<=9999){
			int angkaRibu = (angka/1000)*10;
			int angkaPuluh = ((angka%100)/10);
			int hasil = angkaRibu + angkaPuluh;
			printf("indexnya = %d, namun nanti kami modulo 26 ya :)\n",hasil);
			return hasil%size;
		}
		else if(angka>=10000&&angka<=99999){
			int angkaPuluhRibu = (angka/10000)*100;
			int angkaRatus = ((angka%1000)/100)*10;
			int angkaSatuan = angka%10;
			int hasil = angkaPuluhRibu + angkaRatus + angkaSatuan;
			printf("indexnya = %d, namun nanti kami modulo 26 ya :)\n",hasil);
			return hasil%size;
		}
	}
	
	else if(pilih==5){
		
		if(angka<=9){
			return angka%size;
		}
		else if(angka>=10&&angka<=99){
			int puluh = angka/10;
			int satuan = (angka%10)*10;
			return angka%size;
		}
		else if(angka>=100&&angka<=999){
			int angkaRatus = (angka/100);
			int puluh = ((angka%100)/10)*10;
			int angkaSatuan = (angka%10)*100;
			int hasil = angkaRatus + angkaSatuan + puluh;
			printf("indexnya = %d, namun nanti kami modulo 26 ya :)\n",hasil);
			return hasil%size;
		}
		else if(angka>=1000&&angka<=9999){
			int angkaRibu = (angka/1000);
			int ratus = ((angka/100)%10)*10;
			int angkaPuluh = ((angka%100)/10)*100;
			int satuan = (angka%10)*1000;
			int hasil = angkaRibu + angkaPuluh + ratus +satuan;
			printf("indexnya = %d, namun nanti kami modulo 26 ya :)\n",hasil);
			return hasil%size;
		}
	}	
	
	
	
}

void insert(int angka,int pilih, int col){
	Table *temp = createNode(angka);
	int index = hash(angka,pilih,col);
	
	if(col==1){
		if(table[index]==NULL){
			table[index]=tHead[index]=tTail[index]=temp;
		}
		else{
			int point = index+1;
			while(table[point]!=NULL){
				point = (point+1)%size;
				if(point==index){
					printf("Full\n");
					return;
				}
			}
			table[point]=tHead[point]=tTail[point]=temp;
		}
	}
	
	else if(col==3){
			
	if(tHead[index] == NULL){
		tHead[index] = tTail[index] = temp;
	}
	else{
		if(tHead[index]->angka>=angka){
			temp->next = tHead[index];
			tHead[index]->prev=temp;
			tHead[index] = temp;
		}
		
		else if(tHead[index]->angka<=angka){
			temp->prev = tTail[index];
			tTail[index]->next=temp;
			tTail[index] = temp;
		}
		else{
			Table *curr = tHead[index]->next;
			while(curr->angka<=angka){
				curr=curr->next;
			}
			curr->prev->next=temp;
			temp->prev=curr->prev;
			temp->next=curr;
			curr->prev=temp;
		}
	}
}
}

void print(){
	for(int i=0;i<size;i++){
		printf("Index %d = ",i);
	
	if(tHead[i]==NULL){
		printf("-\n");
	}
	else{
		Table *curr = tHead[i];
		while(curr!=NULL){
			printf("%d -> ",curr->angka);
			curr=curr->next;
		}
		
	}
	printf("\n");
	}
}


int main(){
	
	int a;
	int b;
	

	do{
	printf("Selamat Datang silahakan pilih mode hashing :\n");
	printf("1. Mid Square\n");
	printf("2. Division\n");
	printf("3. Folding\n");
	printf("4. Digit Extraction\n");
	printf("5. Rotation\n");
	printf("6. Exit\n");
	printf("Pilih berapa [1-6]? ");
	scanf("%d",&a);
	getchar();
	
	
	if(a==6){
		printf("Terima Kasih\n");
	}
	else{
		do{
			printf("Pilih Collision :\n");
			printf("1. Linear Probing\n");
			printf("2. Rehashing\n");
			printf("3. Chaining\n");
			printf("Pilih berapa [1-3]? ");
			scanf("%d",&b);
			getchar();
			
			if(b==2){
				printf("======================================================\n");
				printf("Cara pengerjaannya dengan mengubah besaran size, kemudian kita transfer data lama ke table baru yang udah diganti\nukuran sizenya..\n");
				printf("Kemudian di modulo ulang, dapet data baru, jadi dehh..\n");
				printf("Tapi ga tau cara ganti sizenya :')..\n");
				printf("Rehashing sedang tahap pengembangan, silahkan ulangi :)\n");
				printf("======================================================\n");
				
			}			
		}while(b!=1&&b!=3);
	}

	if(a==1){
		printf("Kamu masuk ke mode Mid Square masukkan angka yang kamu pilih [1-300]:\n");
		int angka;
		scanf("%d",&angka);
		getchar();
		insert(angka, a,b);
		print();
	}
	else if(a==2){
		printf("Kamu masuk ke mode Division masukkan bilangan ascii yang kamu pilih sebanyak 4 kali dengan nyambung [65-90] (contoh 65676886):\n");
		int angka;
		scanf("%d",&angka);
		getchar();	
		insert(angka, a,b);
		print();
	}
	
	else if(a==3){
		printf("Kamu masuk ke mode Folding masukkan angka yang kamu pilih [1-9999]:\n");
		int angka;
		scanf("%d",&angka);
		getchar();
		insert(angka, a,b);
		print();
	}
	else if(a==4){
		printf("Kamu masuk ke mode Digit Extraction masukkan angka yang kamu pilih [1-99999]:\n");
		int angka;
		scanf("%d",&angka);
		getchar();
		insert(angka, a,b);
		print();
	}
	else if(a==5){
		printf("Kamu masuk ke mode Rotation masukkan angka yang kamu pilih [1-9999]:\n");
		int angka;
		scanf("%d",&angka);
		getchar();
		insert(angka, a,b);
		print();
	}
	}while (a!=6);
	
	return 0;
}

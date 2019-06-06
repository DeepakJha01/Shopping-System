///SOURCE CODE OF SHOPPING SYSTEM

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include<time.h>
                                        ///password 12345
   /// Update & Insert Function
void insertfirst(int data, char itemname[25], int quantity, float price);
void insertend(int data, char itemname[25], int quantity, float price);
void updateitem(int udata, int uquantity);
    /// Display Function
void itemslist();
void main_menu();
void deleteitem(int serial);///
    ///design Function
void cls();
void echo(char print[]);
void br(int line);
void pre(int tab);
void welcome();
void middle1(void);
void middtab1(void);

        ///START Structure Here

struct Node{

	char itemname[50];
	int quantity;
	float price;
	int data;
	struct Node *next;

};
   ///Global Type
typedef struct Node node ;
node *head, *list;

int main(){

	system("title DSA PROJECT - ELECTROSTOP");

	welcome();
	Sleep(300);
	cls();

	int c=0; int any;
	int cardno[100];
	float cardmoney[100];
	float totalmoney = 0;
	int total_order[100];
	int order_quantity[100];
	int order=0;
	int uquantity;

	head = NULL;
	insertfirst(1,"PowerBank   ",193,1200.23);
	insertend(2,"Headphone   ",175,2500.67);
	insertend(3,"Speaker     ",168,2423.33);
	insertend(4,"USB Cable   ",170,400.50);
	insertend(5,"Pen Drive   ",180,500.23);
	insertend(6,"Home Theater",139,1990.23);
	insertend(7,"OTG Cable   ",187,1200.29);
	insertend(8,"4K LED TV   ",173,12499.98);
	insertend(9,"Fitness Band",121,1999.99);
    insertend(10,"BT Mouse    ",180,649.70);
    insertend(11,"Printer     ",100,8499.99);

	mainmenu:
	br(1);
	main_menu();
	int main_menu_choice;
	br(1); pre(4); fflush(stdin); scanf("%d",&main_menu_choice);

	if((main_menu_choice >=1 && main_menu_choice <=3)){
		if(main_menu_choice == 1){
			itemslist:
			cls();
			printf("=> 0. Main Menu ");
			itemslist();
		}
		else if( main_menu_choice == 2){
			adminpanelchoice:
			int admin_panel_choice;
			cls(); middle1() ;   pre(4);  printf("1. Main Menu\n\n\t"); Sleep(300);
			printf("Please Enter Password or ( 1 to Back in Main Menu ) : ");
			fflush(stdin);  scanf("%d",&admin_panel_choice);

			if(admin_panel_choice==12345){///admin password
				node *temp;
				temp = list;
				adminchoise:
				cls();  br(5); pre(4); echo("You are on Admin Pannel\n\n");
				pre(4);
				printf(" 1. Total Cash Today \n\n");Sleep(250);pre(4);
				printf(" 2. View Card Pay \n\n");Sleep(250);pre(4);
				printf(" 3. Add Item \n\n");Sleep(250);pre(4);
				printf(" 4. Delete Item \n\n");Sleep(250);pre(4);
				printf(" 0. Main Menu ");Sleep(250);
				int adminchoise;
				fflush(stdin);   scanf("%d",&adminchoise);
				if(adminchoise==1){
					cls();  middle1(); pre(4);   printf("Todays Total Cash : %0.2f  \n",totalmoney);
					Sleep(2000);
					goto adminchoise;
				}
				else if(adminchoise==2){

					if(c!=0){
						cls();  br(3); pre(4);
						printf(" ____________________________\n");pre(4);
						printf("|   Card NO.   |   Money $   |\n");pre(4);
						printf("------------------------------\n");pre(4);

						for(int z=1; z<=c;z++){

							printf("|  %d       | %0.2f    |\n",cardno[z],cardmoney[z]);pre(4);
							printf("------------------------------\n");pre(4);
							Sleep(150);
						}
						Sleep(1500);
					}
					if(c==0){
						cls();  middle1(); pre(4);
                        printf("No Card History\n");}
					Sleep(1500);
					goto adminchoise;
				}

                else if(adminchoise==3){
                    //printf("\n\n\t\t\t\tUNDER CONSTRUCTION...\n");
                    //Sleep(2000);
					foodadd:
					cls();
					char ffoodname[25];
					int fquantity;
					int fdata;
					float fprice;
					int fposi;
					br(3);pre(4);      printf(" Enter item Name :  ");
					fflush(stdin);     scanf("%[^\n]s",ffoodname);
					fquantity:
					fflush(stdin);
					br(2);pre(4);  printf(" Enter item Quantity :  ");
					scanf("%d",&fquantity); fflush(stdin);
                    foodserial:
					br(2);pre(4);  printf(" Enter item Serial :  ");
                      scanf("%d",&fdata);
                            node *exist;
                            exist = list;
                      while(exist->data!=fdata){
                            if(exist->next==NULL){
                                break;
                            }
                        exist=exist->next;
                      }
                      if(exist->data==fdata){
                       cls(); br(5);pre(3);  printf(" Item Serial Already Exist, Please Re-Enter  "); Sleep(2000);
                       goto foodserial;
                      }
                    fprice:
                    fflush(stdin);
					br(2);pre(4);  printf(" Enter Item Price :  ");fflush(stdin);
					scanf("%f",&fprice);
					br(2);pre(4);  printf("Submitting your data");for(int cs=0;cs<4;cs++){printf(" .");Sleep(500);}
					insertend(fdata,ffoodname,fquantity,fprice);
					br(2);pre(4);      printf("Adding Item  Successful....\n");
					Sleep(2000);
					goto adminchoise;

				}
				else if(adminchoise==4){
				    //printf("\n\n\t\t\t\tUNDER CONSTRUCTION...\n");
				    //Sleep(2000);
					cls();
					middle1();pre(2);
					printf("Enter Serial No of the Item To Delete : ");
					fdelete:
					int fdelete;
					fflush(stdin); scanf("%d",&fdelete);
					node *temp;
					temp=list;
					while(temp->data != fdelete){
						temp = temp->next;
					}
					if(temp->data==fdelete){
						deleteitem(fdelete);
					}
					else{
						br(2); pre(2); printf("Please Enter Correct Number :  "); Sleep(500);
						goto fdelete;
					}
					goto adminchoise;
				}

				else if(adminchoise==0){

					goto mainmenu;
				}
				else{
					br(2); pre(4); printf("Please Select From List :  "); Sleep(500);
					goto adminchoise;
				}
			}
			else if(admin_panel_choice==1){
				goto mainmenu;
			}
			else{
				br(2); pre(4);  printf("Please Enter Correct Choice");
				goto adminpanelchoice;
			}
		}
		else if(main_menu_choice==3){
			cls();
			middle1(); pre(3); printf("Thank You For Using Our System \n\n\n\n\n\n\n\t\t\t\tCreated by - Deepak Jha\n\t\t\t\tRegistration Number:18BCE0654\n\n\n");
			Sleep(1000);
            exit(1);
		}
	}
	else{
		br(2); pre(4); printf("Please Enter Correct Choice"); Sleep(300);
		goto mainmenu;
	}
	int get_item_choice;
	br(2); pre(3);fflush(stdin); printf("Place Your Order(enter item no.): ") ; scanf("%d",&get_item_choice);
	if(get_item_choice==0){
		goto mainmenu;
	}
	node *temp;
	temp = list ;
	while(temp->data != get_item_choice){
		temp = temp->next;
		if(temp==NULL){
			br(2); pre(4);  echo("Please Choose From List "); br(2); Sleep(1000);
			goto itemslist;
		}
	}
	if(get_item_choice == temp->data){
		fcquantity:
		br(2); pre(4); printf("Enter Item Quantity : ");
		int fcquantity;
		fflush(stdin); scanf("%d",&fcquantity); cls();
		if(fcquantity==0){
			cls(); middle1();pre(3); printf("Quantity Can not be Zero "); Sleep(2000);
			cls();
			goto itemslist;
		}
		else if(fcquantity>temp->quantity){
			cls(); middle1();pre(3); printf("Out of Stock ! "); Sleep(2000);
			goto itemslist;
		}

		middle1();pre(4);  printf("Choice of item : %s  ; its price is %0.2f \n\n",temp->itemname,temp->price*fcquantity);pre(4);
		printf("1. Confirm to buy this \n\n");pre(4);
		printf("2. Back To Item List  \n\t\t\t\t");
		confirm:
		int confirm;
		fflush(stdin); scanf("%d",&confirm);
		if(confirm == 1 ){
			br(2);pre(4);    printf(" 1. Cash ");
			br(2);pre(4);    printf(" 2. Credit/Debit Card\n\t\t\t\t");
			payment:
			int payment;
			fflush(stdin);  scanf("%d",&payment);
			if(payment==1){
				totalmoney += temp->price*fcquantity;
				order++;
				total_order[order]=get_item_choice;
				order_quantity[order]=fcquantity;
				uquantity = temp->quantity - fcquantity;
				updateitem(get_item_choice,uquantity);
				cls();middle1();pre(4);  printf("===>THANK YOU<===");
				br(2);pre(4);  printf("Item Ordered Successfully ...");
				br(2);pre(4);  printf("1. Wanna Buy Another Item ? ");
				br(2);pre(4);  printf("2. Back to Main Menu \n\t\t\t\t");
				psmenu:
				int ps_menu;
				fflush(stdin);  scanf("%d",&ps_menu);
				if(ps_menu==1){goto itemslist;}
				else if(ps_menu==2){goto mainmenu;}
				else{br(2);pre(4);printf("Please Choose from list : "); goto psmenu;}

			}
			///Credit Card Option
			else if(payment==2){
				int card_number[100];
				c++;
				cls();middle1();pre(4); printf("Enter Your Card No : ");
				fflush(stdin);   scanf("%d",&card_number[c]);
				cardno[c] = card_number[c];
				int pin;
				br(2);pre(2);  printf("Enter Your Card Pin [we never save your pin]  : ");
				fflush(stdin);     scanf("%d",&pin);
				cardmoney[c] = temp->price*fcquantity;
				totalmoney += temp->price*fcquantity;
				order++;
				total_order[order]=get_item_choice;
				order_quantity[order]=fcquantity;
				uquantity = temp->quantity - fcquantity;
				updateitem(get_item_choice,uquantity);
				br(2);pre(4);  printf("Payment Success...");
				br(2);pre(4);    printf("1. Wanna Buy Another Item ? ");
				br(2);pre(4);    printf("2. Main Menu ");
				psmenu2:
				int ps_menu2;
				scanf("%d",&ps_menu2);
				if(ps_menu2==1){goto itemslist;}
				else if(ps_menu2==2){goto mainmenu;}
				else{br(2);pre(4);printf("Please Choose from list : "); goto psmenu2;}
			}
			else{
				br(2);pre(4);   printf("Please Choose from List : ");
				goto payment;
			}
		}    ///END Confirm Y/y
		else if(confirm == 2){
			goto itemslist;
		}
		else{
			br(2);pre(4);    printf("Please Choose from List : ");
			goto confirm;
		}  ///end confirm;
	}  ///end get food choice if line

	else{
		br(2);pre(4);  echo("Please Choose From List "); br(2); Sleep(300);
		goto itemslist;
	}  ///end get food choice
}

void cls(){
	system("cls");
}

void echo(char print[]){
	printf("%s",print);
}

void br(int line){
	for(int i=0; i<line;i++){
		printf("\n");
	}
}

void pre(int tab){
	for(int i=0; i<tab;i++){
		printf("\t");
	}
}

void main_menu(){
	cls();
	br(5); pre(3); echo("===> 1. Item List");
	br(2); pre(3); echo("===> 2. Admin Panel");
	br(2); pre(3); echo("===> 3. Exit");
	br(1);
}

void insertend(int data, char itemname[25], int quantity, float price){
	node *temp;
	temp=(node *)malloc(sizeof(node));
	temp->data = data;
	temp->price = price;
	temp-> quantity = quantity;
	strcpy(temp->itemname,itemname);
	temp->next = NULL;
	if(head==NULL){
		head = temp;
		list = head;
	}
	else{
		while(head->next != NULL){
			head = head->next;
		}
		head->next = temp;
	}
}

void insertfirst(int data, char itemname[25], int quantity, float price){
	node *temp;
	temp=(node *)malloc(sizeof(node));
	temp->data = data ;
	temp->price = price;
	strcpy(temp->itemname,itemname);
	temp-> quantity = quantity;
	temp->next = head;
	head = temp;
	list = head ;
}
void deleteitem(int serial){

	node *temp;
	temp=(node *)malloc(sizeof(node));

	temp = list;


	if(temp->data != serial){

		while(temp->next->data != serial){
			temp = temp->next;
		}

		if(temp->next->data == serial){

			temp->next = temp->next->next;
			cls();
			printf("\n\n\n\n\t\t\tDeleting Item %d ",serial);for(int cs=0;cs<4;cs++){printf(" .");Sleep(400);}

			printf("\n\n\n\n\t\t\tDeleted Successfully \n"); Sleep(500);

		}
		else{
			printf("\n\n\n\n\t\t\t Item Not Found\n"); Sleep(500);
		}

		head = temp ;

	}
	else{

		temp = temp->next;
		cls();
		printf("\n\n\n\n\t\t\tDeleting Item %d ",serial);for(int cs=0;cs<4;cs++){printf(" .");Sleep(400);}

		printf("\n\n\n\n\t\t\tDeleted Successfully \n"); Sleep(500);

		head = temp ;

		list=head;
	}
}
void updateitem(int udata, int uquantity){
	node *temp;
	temp = list;
	while(temp->data!=udata){
		temp = temp->next;
	}
	if(temp->data == udata){
		temp->quantity = uquantity;
	}
}

void itemslist(){
	printf("\n\t\t");
	printf("_____________________________________________________________");
	printf("\n\t\t");
	printf("|  Item No.  |   Item Name       |  Price       |    In Stock   |");
	printf("\n\t\t");
	printf("-------------------------------------------------------------");
	node *temp;
	temp = list;
	while(temp != NULL){
		printf("\n\t\t");
		printf("|     %d      |    %s   |     %0.2f   |     %d    |",temp->data,temp->itemname, temp->price, temp->quantity);
		printf("\n\t\t");
		printf("--------------------------------------------------------------");
		temp = temp->next ;
	}
	//  free(temp);
}

void welcome(){
	printf("\n\n\n\n\n\n");
	printf("\t\t WELCOME \n\n\t\t TO\n\n\t\t 'ELECTROSTOP'\n\n\t\t ONLINE\n\n\t\t SHOPPING\n\n\t\t SYSTEM\n");
	Sleep(1000);
}
void middle1(void){
	printf("\n\n\n\n\n\n\n");///screen ke bich me line aaega
}
void middtab1(void){
	printf("\t\t\t\t\t");///
}
 
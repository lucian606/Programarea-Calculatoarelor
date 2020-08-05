#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <panel.h>
#include <time.h>
#define BUFMAX 1000

int main(int argc,char *argv[])
{	int ch,randu,col,i,linie,sc=0,c,g,ok=0,nr=0,ok1=0,j,m,flag[4],x,l;
	/*Ch va fi caracterul dat de la tastatura,randu si col sunt dimensiunile ferestrei stdscr
	i,l,x sunt contoare,sc este scorul,c este numarul de intrebari la care s-a raspuns corect,
	g este numarul de intrebari la care s-a raspuns gresit,ok indica daca varianta Skip the 
	Question poate fi folosita (ok==1) si ok1 indica daca varianta 50/50 poate fi folosita(ok1==1),
	j este o variabila folosita pentru a indica daca a ramas o varianta gresita alaturi de cea
	corecta dupa ce s-a facut 50/50,m reprezinta un numar random intre 0 si 3, si flag este un 
	vector care are initial elementele 0,fiecare element corespunde unei variante,elementul variantei
	corecte si elementul care a fost ales random vor primi valorile 1,astfel dupa ce s-a facut 50/50
	vor fi afisate doar variantele care au elementul flag 1.
	*/
	if(argv[1]==NULL) {printf("Nu s-au dat argumente in linia de comanda!\n");
					goto T;
				}	//Verifica daca au fost date argumente in linia de comanda.
	char buffer[BUFMAX],corect[1],var[4][100],cerinta[BUFMAX];
	/*Buffer este linia fisierului,corect reprezinta varianta corecta,var este vectorul variantelor si 
	cerinta este intrebare curenta.
	*/
	FILE *file;
	initscr();	//Se initializeaza modul curses.
	cbreak();	//Sa se poata opri programul folosind CTRL+Z
	noecho();	//Sa nu se afiseze caracterele citite de la tastatura
	keypad(stdscr,TRUE);	
	getmaxyx(stdscr,col,randu);	//Se calculeaza dimensiunile ferestrei stdscr
	mvprintw(1,(randu-7)/2,"TRIVIA");	
	//Cu ajutorul dimensiunilor lui stdscr se plaseaza titlul cat mai centrat
	WINDOW * menu = newwin(5,15,5,2);	//Se creeaza fereastra pentru meniu
	PANEL *meniu=new_panel(menu);	//I se atribuie un panou meniului
	box(menu,0,0);
	WINDOW *score = newwin(1,10,4,5);	//Se creeaza fereastra pentru scor
	PANEL *scor=new_panel(score);	//I se atribuie un panou scorului
	WINDOW *timp=newwin(1,30,3,5);	//Se creeaza o fereastra pentru timp
	PANEL *timpul=new_panel(timp);	//I se atribuie un panou timpului
	time_t mytime=time(NULL);	
	char *time_str=ctime(&mytime);
	time_str[strlen(time_str)-1]='\0';
	wprintw(timp,"%s",time_str);	//Se afiseaza timpul si data periodic
	wrefresh(menu);	
	top_panel(timpul);
	keypad(menu,TRUE);	//Se permite navigarea meniului prin sageti
	char alegeri[3][20]={"New Game","Resume Game","Quit"}; //Se creeaza optiunile pentru meniu
	int alegere;
	int highlight=0;
	hide_panel(timpul);
	start_color(); //Se initializeaza modul color
	init_pair(1,COLOR_RED,COLOR_BLACK); 
	init_pair(2,COLOR_GREEN,COLOR_BLACK);
	init_pair(3,COLOR_CYAN,COLOR_BLACK);
	init_pair(4,COLOR_YELLOW,COLOR_BLACK);
	//Se atribuie diferite perechi de culori
	update_panels();
	doupdate();
	//Se vor actualiza periodic panourile
	LOOP:while(2) 
	/*Se creeaza meniul iar programul paraseste bucla infinita cand 
	este selectata o optiune cu tasta enter,se pune un label la
	bucla pentru a putea reveni la meniu atunci cand se apasa Q
	prin instructiunea goto.*/
	{
		for(i=0;i<3;i++)
		{
			if(i == highlight)
				wattron(menu,A_REVERSE);
			mvwprintw(menu,i+1,1,alegeri[i]);
			wattroff(menu,A_REVERSE);
		}
		alegere=wgetch(menu);
		switch(alegere)
		{
			case KEY_UP:
				highlight--;
				if(highlight==-1)
					highlight++;
				break;
			case KEY_DOWN:
				highlight++;
				if(highlight==3)
					highlight--;
				break;
			default:
				break;
		}
		if(alegere == 10)
			break;
	}

	if(highlight==0 )	//Daca este selectat New Game 
					{	WINDOW *quiz= newwin(col,randu,10,(randu-50)/2);	//Se creeaza fereastra pentru joc
						PANEL *panou=new_panel(quiz);	//I se atribuie un panou jocului
						WINDOW *skip=newwin(1,25,6,5);	//Se creeaza o fereastra pentru skip
						PANEL *schimba=new_panel(skip);	//I se atribuie un panou
						WINDOW *fifty=newwin(1,25,7,5);	//Se creaaza o fereastra pt 50/50
						PANEL *half=new_panel(fifty);	//I se atribuie un panou
						wattron(skip,COLOR_PAIR(3));	//Se coloreaza fereastra skip
						wattron(fifty,COLOR_PAIR(4));	//Se coloreaza fereastra fifty
						top_panel(half);
						top_panel(schimba);
						nr=0;
						show_panel(timpul);
						hide_panel(meniu);
						ok=1;	//Ok=1 inseamna ca skip nu a fost folosita
						ok1=1;	//Ok1=1 inseamna ca 50/50 nu a fost folosita
						wprintw(skip,"E-skip the question");
						wprintw(fifty,"F-50/50");
						c=0;	//Numarul de intrebari corecte
						g=0;	//Numarul de intrebari gresite
						top_panel(panou);
						wclear(score);	
						l=1;	//Argumentul curent din linia de comanda
						sc=0;	//Scorul
						file=fopen(argv[l],"r");	//Se deschide fisierul
						if(file ==NULL)
							wprintw(quiz,"Eroare fisierul %s nu poate fi deschis.",argv[l]);
						wprintw(score,"Scor:%d",sc);	//Se afiseaza scorul
						linie=0;	//Numarul de linii citite
						update_panels();
						doupdate();
						ch=0;	//Caracterul citit de la tastatura
						while(ch!='q' && ch !='Q' ) { 	
											X: while(linie%6!=5 && !feof(file))
											/*Liniile care au restul impartirii la 6 egal cu 5 contin raspunsurile la intrebari
											aceste raspunsuri sunt memorate intr-o variabila si se compara
											cu caracterul citit de la tastatura,restul liniilor fiind intrebarile
											si variantele de raspuns,care se vor afisa
											*/
											{	fgets(buffer,BUFMAX,file); //Se citeste linia din fisier
												if(linie%6==0)wattron(quiz,COLOR_PAIR(1)); //Se coloreaza intrebarea cu rosu
												else wattron(quiz,COLOR_PAIR(2));	//Se coloreaza variantele de raspuns cu verde
												wprintw(quiz,buffer);	//Se afiseaza
												if(linie==0) strcpy(cerinta,buffer); //Se memoreaza cerinta pentru a fi folosita cand se va utiliza 50/50
												else strcpy(var[linie-1],buffer);	//Se memoreaza variantele pentru a fi folosite cand se va face 50/50
												linie++;	//Se va trece la urmatoarea linie
												
											}
											if(linie%6==5)
											{
												fgets(buffer,BUFMAX,file);	//Se citeste linia
												strcpy(corect,buffer);	//Se memoreaza varianta corecta
											}
											update_panels(); 
											doupdate();	
											M:while(2) {if (feof(file)) //Daca nu mai sunt intrebari in fisier
															{if(l==argc-1)	//Se verifica daca s-a terminat ultimul fisier
																{
																	if(nr==0){wclear(quiz);	//Se goleste fereastra jocului
																	wprintw(quiz,"Ai raspuns corect la %d intrebari\n",c); 
																	wprintw(quiz,"Ai raspuns gresit la %d intrebari\n",g);
																	wprintw(quiz,"FELICITARI!Scorul tau este %d\n",sc);
																	wprintw(quiz,"Apasa o tasta ca sa revii in meniu.");
																	//Se afiseaza statisticile si scorul final
																	update_panels();
																	doupdate();
																}
																	show_panel(panou);
																	wclear(timp);
																	time_t mytime=time(NULL);
																	char *time_str=ctime(&mytime);
																	time_str[strlen(time_str)-1]='\0';
																	wprintw(timp,"%s",time_str);
																	nr=1;
																	ch='q';
																	goto P;
																}

													else {
															l++;	//Se trece la urmatorul fisier
															file=fopen(argv[l],"r");	//Se deschide fisierul
															linie=0;	
															wclear(quiz);
															update_panels();
															doupdate();		
															goto X;									
														}
											} 
											show_panel(scor);	//Se afiseaza panoul de scor
											show_panel(panou);	//Se afiseaza panoul de joc
											show_panel(schimba);	//Se afiseaza panoul pentru varianta skip
											show_panel(half);	//Se afiseaza panoul pentru 50/50
											top_panel(panou);	//Se pune panoul jocului deasupra
											wclear(timp);
											time_t mytime=time(NULL);
											char *time_str=ctime(&mytime);
											time_str[strlen(time_str)-1]='\0';
											wprintw(timp,"%s",time_str);
											update_panels();
											doupdate();
												ch=getch();		//Se citeste caracterul de la tastatura
											P:while(3) break;	
											if(strchr("ABCDabcdeEfFqQ",ch)!=NULL) break; //Se verifica daca e valida tasta
													}
											if((ch>='a' && ch<='d') ||( ch>='A' && ch<='D'))
											{	if(ch==corect[0] || ch==corect[0]+32) {sc=sc+10;
																						c++;
																						
																					}
												//Daca este varianta corecta creste scorul
												else {	if(sc!=0) sc=sc-5;
													  	g++;
													  
													  }	
												//Daca este varianta gresita scade scorul	  
												wclear(score);	//Se goleste fereastra scorului
												wprintw(score,"Scor:%d",sc);	//Se actualizeaza scorul
												wclear(quiz);	//Se goleste fereastra jocului
												linie=0;	//Se trece la urmatoarea intrebare din fisier
												update_panels();	
												doupdate();
											}
											else if(ch=='e' || ch=='E') //Concurentul doreste sa sara intrebarea
											{	if(ok==1)	//Daca nu a fost folosita varianta skip
												{	ok=0;	//Varianta nu se mai poate utiliza
													wclear(skip);	//Nu mai apare fereastra variantei skip
													wclear(quiz); 
													linie=0;	//Se citeste urmatoarea intrebare
													update_panels();
													doupdate();
												}
												else {	wclear(timp);
														time_t mytime=time(NULL);
														char *time_str=ctime(&mytime);
														time_str[strlen(time_str)-1]='\0';
														wprintw(timp,"%s",time_str);
														update_panels();
														doupdate();
													while(3)	//Se asteapta o comanda
													{ch=getch();
														wclear(timp);
														time_t mytime=time(NULL);
														char *time_str=ctime(&mytime);
														time_str[strlen(time_str)-1]='\0';
														wprintw(timp,"%s",time_str);
														update_panels();
														doupdate();
													 if(strchr("ABCDFQabcdfq",ch)!=NULL)	 goto P;
													}	//Daca a fost folosita varianta skip se asteapta o comanda valida
												}
											}
											else if(ch=='f' || ch=='F') //Concurentul vrea sa reduca numarul de variante
											{	
												if(ok1==1) //Daca nu a fost folosita varianta 50/50
												{
													ok1=0; //Varianta nu se mai poate utiliza
													wclear(fifty); //Nu mai apare fereastra variantei fifty
													wclear(quiz);	//Se sterge fereastra jocului
													wattron(quiz,COLOR_PAIR(1));
													wprintw(quiz,"%s",cerinta);	//Se afiseaza din nou intrebarea la care s-a facut 50/50
													wattron(quiz,COLOR_PAIR(2));
													for(x=0;x<=3;x++) {flag[x]=0; 
														if(var[x][0]==corect[0]) flag[x]=1;
														}		//Se memoreaza varianta corecta
													j=0;
													while(j!=1){
														m=rand() %4;
														if(flag[m]==0) {flag[m]=1;
																		j++;
																		}
														}	//Se alege la intamplare o varianta care nu e corecta			
													for(x=0;x<=3;x++)
														if(flag[x]==1) wprintw(quiz,"%s",var[x]);
														//Se afiseaza variantele pe care concurentul le mai are la dispozitie
													update_panels();
													doupdate();
																		
												}
												wclear(timp);
												time_t mytime=time(NULL);
												char *time_str=ctime(&mytime);
												time_str[strlen(time_str)-1]='\0';
												wprintw(timp,"%s",time_str);
												update_panels();
												doupdate();
												while(3)	//Se asteapta o comanda valida
													{ch=getch();
														wclear(timp);
														time_t mytime=time(NULL);
														char *time_str=ctime(&mytime);
														time_str[strlen(time_str)-1]='\0';
														wprintw(timp,"%s",time_str);
														update_panels();
														doupdate();
													 if(strchr("ABCDQEabcdeq",ch)!=NULL)	 goto P;
													}
											
										}
										if(feof(file))
										{
											wclear(quiz);	//Se goleste fereastra jocului
												wprintw(quiz,"Ai raspuns corect la %d intrebari\n",c); 
												wprintw(quiz,"Ai raspuns gresit la %d intrebari\n",g);
												wprintw(quiz,"FELICITARI!Scorul tau este %d\n",sc);
												wprintw(quiz,"Apasa o tasta ca sa revii in meniu.");
												//Se afiseaza statisticile si scorul final
												update_panels();
												doupdate();	
												ch=getch();
												ch='q';
										}

											
									}	
						show_panel(meniu);	//Se afiseaza meniul					
						top_panel(meniu);	//Se revine la meniu
						hide_panel(panou);	//Se ascunde panoul de joc
						hide_panel(timpul);	//Se ascund data si ora
						hide_panel(scor);	//Se ascunde panoul de scor
						hide_panel(schimba);	//Se ascunde panoul pentru varianta Skip the Question
						hide_panel(half);	//Se acunde panoul pentru varianta 50/50
						update_panels();
						doupdate();
						goto LOOP;	//Se intoarce in meniu
	}

	if(highlight==1)	//Daca este selectat Resume game 
					{	bottom_panel(meniu);
						hide_panel(meniu);	//Se ascunde meniul
						show_panel(scor);	//Se afiseaza panoul scorului
						show_panel(timpul);	//Se afiseaza panoul timpului
						update_panels();
						doupdate();
						ch=0;
						goto M;	//Jocul continua de la intrebarea la care a ramas
					}	
	if(highlight==2) 	endwin();	//Daca este selectat Quit se inchide jocul
	T:while(1) break;				
	return 1;
}
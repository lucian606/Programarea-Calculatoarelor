#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void codificare(char text[], int n, char cod[], int *m)
	  /*Functia primeste ca parametru un text de lungimea n (care
	     contine doar litere si spatii).Functia va construi sirul cod 
	     care va fi mesajul codificat,care va avea lungimea m. 
	   */
{
	int j = 0;
	int i;
	/*Sirul este parcurs caracter cu caracter si i se atribuie conventia
	   stabilita acestuia.Mai intai se verifica daca este o
	   majuscula,apoi se codifica si este inserat in sirul cod,apoi
	   verifica daca urmatorul caracter din text apartine aceleiasi
	   taste,caz in care se adauga '#'. 
	 */
	for (i = 0; i < n; i++) {
		if (text[i] >= 'A' && text[i] <= 'Z') {
			cod[j] = '1';
			j++;
		}

		if (text[i] == 'A' || text[i] == 'a') {
			cod[j] = '2';
			j++;
			if (strchr("abc", text[i + 1]) != NULL
			    && text[i + 1] != '\0') {
				cod[j] = '#';
				j++;
			}
		}

		if (text[i] == 'B' || text[i] == 'b') {
			cod[j] = '2';
			j++;
			cod[j] = '2';
			j++;
			if (strchr("abc", text[i + 1]) != NULL
			    && text[i + 1] != '\0') {
				cod[j] = '#';
				j++;
			}
		}

		if (text[i] == 'C' || text[i] == 'c') {
			cod[j] = '2';
			j++;
			cod[j] = '2';
			j++;
			cod[j] = '2';
			j++;
			if (strchr("abc", text[i + 1]) != NULL
			    && text[i + 1] != '\0') {
				cod[j] = '#';
				j++;
			}
		}

		if (text[i] == 'D' || text[i] == 'd') {
			cod[j] = '3';
			j++;
			if (strchr("def", text[i + 1]) != NULL
			    && text[i + 1] != '\0') {
				cod[j] = '#';
				j++;
			}
		}

		if (text[i] == 'E' || text[i] == 'e') {
			cod[j] = '3';
			j++;
			cod[j] = '3';
			j++;
			if (strchr("def", text[i + 1]) != NULL
			    && text[i + 1] != '\0') {
				cod[j] = '#';
				j++;
			}
		}

		if (text[i] == 'F' || text[i] == 'f') {
			cod[j] = '3';
			j++;
			cod[j] = '3';
			j++;
			cod[j] = '3';
			j++;
			if (strchr("def", text[i + 1]) != NULL
			    && text[i + 1] != '\0') {
				cod[j] = '#';
				j++;
			}
		}

		if (text[i] == 'G' || text[i] == 'g') {
			cod[j] = '4';
			j++;
			if (strchr("ghi", text[i + 1]) != NULL
			    && text[i + 1] != '\0') {
				cod[j] = '#';
				j++;
			}
		}

		if (text[i] == 'H' || text[i] == 'h') {
			cod[j] = '4';
			j++;
			cod[j] = '4';
			j++;
			if (strchr("ghi", text[i + 1]) != NULL
			    && text[i + 1] != '\0') {
				cod[j] = '#';
				j++;
			}
		}

		if (text[i] == 'I' || text[i] == 'i') {
			cod[j] = '4';
			j++;
			cod[j] = '4';
			j++;
			cod[j] = '4';
			j++;
			if (strchr("ghi", text[i + 1]) != NULL
			    && text[i + 1] != '\0') {
				cod[j] = '#';
				j++;
			}
		}

		if (text[i] == 'J' || text[i] == 'j') {
			cod[j] = '5';
			j++;
			if (strchr("jkl", text[i + 1]) != NULL
			    && text[i + 1] != '\0') {
				cod[j] = '#';
				j++;
			}
		}

		if (text[i] == 'K' || text[i] == 'k') {
			cod[j] = '5';
			j++;
			cod[j] = '5';
			j++;
			if (strchr("jkl", text[i + 1]) != NULL
			    && text[i + 1] != '\0') {
				cod[j] = '#';
				j++;
			}
		}

		if (text[i] == 'L' || text[i] == 'l') {
			cod[j] = '5';
			j++;
			cod[j] = '5';
			j++;
			cod[j] = '5';
			j++;
			if (strchr("jkl", text[i + 1]) != NULL
			    && text[i + 1] != '\0') {
				cod[j] = '#';
				j++;
			}
		}

		if (text[i] == 'M' || text[i] == 'm') {
			cod[j] = '6';
			j++;
			if (strchr("mno", text[i + 1]) != NULL
			    && text[i + 1] != '\0') {
				cod[j] = '#';
				j++;
			}
		}

		if (text[i] == 'N' || text[i] == 'n') {
			cod[j] = '6';
			j++;
			cod[j] = '6';
			j++;
			if (strchr("mno", text[i + 1]) != NULL
			    && text[i + 1] != '\0') {
				cod[j] = '#';
				j++;
			}
		}

		if (text[i] == 'O' || text[i] == 'o') {
			cod[j] = '6';
			j++;
			cod[j] = '6';
			j++;
			cod[j] = '6';
			j++;
			if (strchr("mno", text[i + 1]) != NULL
			    && text[i + 1] != '\0') {
				cod[j] = '#';
				j++;
			}
		}

		if (text[i] == 'P' || text[i] == 'p') {
			cod[j] = '7';
			j++;
			if (strchr("pqrs", text[i + 1]) != NULL
			    && text[i + 1] != '\0') {
				cod[j] = '#';
				j++;
			}
		}

		if (text[i] == 'Q' || text[i] == 'q') {
			cod[j] = '7';
			j++;
			cod[j] = '7';
			j++;
			if (strchr("pqrs", text[i + 1]) != NULL
			    && text[i + 1] != '\0') {
				cod[j] = '#';
				j++;
			}
		}

		if (text[i] == 'R' || text[i] == 'r') {
			cod[j] = '7';
			j++;
			cod[j] = '7';
			j++;
			cod[j] = '7';
			j++;
			if (strchr("pqrs", text[i + 1]) != NULL
			    && text[i + 1] != '\0') {
				cod[j] = '#';
				j++;
			}
		}

		if (text[i] == 'S' || text[i] == 's') {
			cod[j] = '7';
			j++;
			cod[j] = '7';
			j++;
			cod[j] = '7';
			j++;
			cod[j] = '7';
			j++;
			if (strchr("pqrs", text[i + 1]) != NULL
			    && text[i + 1] != '\0') {
				cod[j] = '#';
				j++;
			}
		}

		if (text[i] == 'T' || text[i] == 't') {
			cod[j] = '8';
			j++;
			if (strchr("tuv", text[i + 1]) != NULL
			    && text[i + 1] != '\0') {
				cod[j] = '#';
				j++;
			}
		}

		if (text[i] == 'U' || text[i] == 'u') {
			cod[j] = '8';
			j++;
			cod[j] = '8';
			j++;
			if (strchr("tuv", text[i + 1]) != NULL
			    && text[i + 1] != '\0') {
				cod[j] = '#';
				j++;
			}
		}

		if (text[i] == 'V' || text[i] == 'v') {
			cod[j] = '8';
			j++;
			cod[j] = '8';
			j++;
			cod[j] = '8';
			j++;
			if (strchr("tuv", text[i + 1]) != NULL
			    && text[i + 1] != '\0') {
				cod[j] = '#';
				j++;
			}
		}

		if (text[i] == 'W' || text[i] == 'w') {
			cod[j] = '9';
			j++;
			if (strchr("wxyz", text[i + 1]) != NULL
			    && text[i + 1] != '\0') {
				cod[j] = '#';
				j++;
			}
		}

		if (text[i] == 'X' || text[i] == 'x') {
			cod[j] = '9';
			j++;
			cod[j] = '9';
			j++;
			if (strchr("wxyz", text[i + 1]) != NULL
			    && text[i + 1] != '\0') {
				cod[j] = '#';
				j++;
			}
		}

		if (text[i] == 'Y' || text[i] == 'y') {
			cod[j] = '9';
			j++;
			cod[j] = '9';
			j++;
			cod[j] = '9';
			j++;
			if (strchr("wxyz", text[i + 1]) != NULL
			    && text[i + 1] != '\0') {
				cod[j] = '#';
				j++;
			}
		}

		if (text[i] == 'Z' || text[i] == 'z') {
			cod[j] = '9';
			j++;
			cod[j] = '9';
			j++;
			cod[j] = '9';
			j++;
			cod[j] = '9';
			j++;
			if (strchr("wxyz", text[i + 1]) != NULL
			    && text[i + 1] != '\0') {
				cod[j] = '#';
				j++;
			}
		}
		if (text[i] == ' ') {
			cod[j] = '0';
			j++;
		}

	}
	cod[j] = '\0';
	*m = j;
}

void decodificare(char taste[], int p, char mesaj[], int *l)
	/* Functia primeste ca parametru un sir de caractere taste (care
	   contine doar caractere numerice),avand lungimea p.Functia va
	   decodifica tastele si va pune mesajul decodificat in sirul
	   mesaj,care va avea lungimea l. 
	 */
{
	int i, m = 0, majuscula = 0, apasare = 1;
	for (i = 0; i < p; i++)
	/*Se parcurge sirul caracter cu carecter.Variabila majuscula este 
	   o variabila care are valoarea 0 si primeste valoarea 1 atunci
	   cand tasta 1 a fost apasata.Cu ajutorul acestei variabile sirul 
	   va sti daca secventa de caractere numerice constituie sau nu o
	   majuscula.Variabila apasare are valoarea 1 si verifica
	   lungimea unei secvente de caractere identice,variabila crescand 
	   daca doua caractere vecine sunt identice.Cand s-a ajuns la un
	   caracter diferit ,secventa este decodificata in litera
	   corespunzatoare,in functie de apasare ,modulo numarului de
	   caractere de pe tasta aferenta cifrei,apoi variabila apasare
	   primeste valoarea 1 si variabila majuscula devine 0 (atunci
	   cand era cazul),trecandu-se apoi la urmatoarea secventa. 
	 */
	{
		if (taste[i] == '1')
			majuscula = 1;
		if (taste[i] == taste[i + 1])
			apasare++;
		else {
			if (taste[i] == '2') {
				if (apasare % 3 == 1) {
					if (majuscula == 1) {
						mesaj[m] = 'A';
						majuscula = 0;
					} else
						mesaj[m] = 'a';
					m++;
					apasare = 1;
				}
				if (apasare % 3 == 2) {
					if (majuscula == 1) {
						mesaj[m] = 'B';
						majuscula = 0;
					} else
						mesaj[m] = 'b';
					m++;
					apasare = 1;
				}
				if (apasare % 3 == 0) {
					if (majuscula == 1) {
						mesaj[m] = 'C';
						majuscula = 0;
					} else
						mesaj[m] = 'c';
					m++;
					apasare = 1;
				}

			}
			if (taste[i] == '3') {
				if (apasare % 3 == 1) {
					if (majuscula == 1) {
						mesaj[m] = 'D';
						majuscula = 0;
					} else
						mesaj[m] = 'd';
					m++;
					apasare = 1;
				}
				if (apasare % 3 == 2) {
					if (majuscula == 1) {
						mesaj[m] = 'E';
						majuscula = 0;
					} else
						mesaj[m] = 'e';
					m++;
					apasare = 1;
				}
				if (apasare % 3 == 0) {
					if (majuscula == 1) {
						mesaj[m] = 'F';
						majuscula = 0;
					} else
						mesaj[m] = 'f';
					m++;
					apasare = 1;
				}
			}
			if (taste[i] == '4') {
				if (apasare % 3 == 1) {
					if (majuscula == 1) {
						mesaj[m] = 'G';
						majuscula = 0;
					} else
						mesaj[m] = 'g';
					m++;
					apasare = 1;
				}
				if (apasare % 3 == 2) {
					if (majuscula == 1) {
						mesaj[m] = 'H';
						majuscula = 0;
					} else
						mesaj[m] = 'h';
					m++;
					apasare = 1;
				}
				if (apasare % 3 == 0) {
					if (majuscula == 1) {
						mesaj[m] = 'I';
						majuscula = 0;
					} else
						mesaj[m] = 'i';
					m++;
					apasare = 1;
				}
			}
			if (taste[i] == '5') {
				if (apasare % 3 == 1) {
					if (majuscula == 1) {
						mesaj[m] = 'J';
						majuscula = 0;
					} else
						mesaj[m] = 'j';
					m++;
					apasare = 1;
				}
				if (apasare % 3 == 2) {
					if (majuscula == 1) {
						mesaj[m] = 'K';
						majuscula = 0;
					} else
						mesaj[m] = 'k';
					m++;
					apasare = 1;
				}
				if (apasare % 3 == 0) {
					if (majuscula == 1) {
						mesaj[m] = 'L';
						majuscula = 0;
					} else
						mesaj[m] = 'l';
					m++;
					apasare = 1;
				}
			}
			if (taste[i] == '6') {
				if (apasare % 3 == 1) {
					if (majuscula == 1) {
						mesaj[m] = 'M';
						majuscula = 0;
					} else
						mesaj[m] = 'm';
					m++;
					apasare = 1;
				}
				if (apasare % 3 == 2) {
					if (majuscula == 1) {
						mesaj[m] = 'N';
						majuscula = 0;
					} else
						mesaj[m] = 'n';
					m++;
					apasare = 1;
				}
				if (apasare % 3 == 0) {
					if (majuscula == 1) {
						mesaj[m] = 'O';
						majuscula = 0;
					} else
						mesaj[m] = 'o';
					m++;
					apasare = 1;
				}
			}
			if (taste[i] == '7') {
				if (apasare % 4 == 1) {
					if (majuscula == 1) {
						mesaj[m] = 'P';
						majuscula = 0;
					} else
						mesaj[m] = 'p';
					m++;
					apasare = 1;
				}
				if (apasare % 4 == 2) {
					if (majuscula == 1) {
						mesaj[m] = 'Q';
						majuscula = 0;
					} else
						mesaj[m] = 'q';
					m++;
					apasare = 1;
				}
				if (apasare % 4 == 3) {
					if (majuscula == 1) {
						mesaj[m] = 'R';
						majuscula = 0;
					} else
						mesaj[m] = 'r';
					m++;
					apasare = 1;
				}
				if (apasare % 4 == 0) {
					if (majuscula == 1) {
						mesaj[m] = 'S';
						majuscula = 0;
					} else
						mesaj[m] = 's';
					m++;
					apasare = 1;
				}
			}
			if (taste[i] == '8') {
				if (apasare % 3 == 1) {
					if (majuscula == 1) {
						mesaj[m] = 'T';
						majuscula = 0;
					} else
						mesaj[m] = 't';
					m++;
					apasare = 1;
				}
				if (apasare % 3 == 2) {
					if (majuscula == 1) {
						mesaj[m] = 'U';
						majuscula = 0;
					} else
						mesaj[m] = 'u';
					m++;
					apasare = 1;
				}
				if (apasare % 3 == 0) {
					if (majuscula == 1) {
						mesaj[m] = 'V';
						majuscula = 0;
					} else
						mesaj[m] = 'v';
					m++;
					apasare = 1;
				}
			}
			if (taste[i] == '9') {
				if (apasare % 4 == 1) {
					if (majuscula == 1) {
						mesaj[m] = 'W';
						majuscula = 0;
					} else
						mesaj[m] = 'w';
					m++;
					apasare = 1;
				}
				if (apasare % 4 == 2) {
					if (majuscula == 1) {
						mesaj[m] = 'X';
						majuscula = 0;
					} else
						mesaj[m] = 'x';
					m++;
					apasare = 1;
				}
				if (apasare % 4 == 3) {
					if (majuscula == 1) {
						mesaj[m] = 'Y';
						majuscula = 0;
					} else
						mesaj[m] = 'y';
					m++;
					apasare = 1;
				}
				if (apasare % 4 == 0) {
					if (majuscula == 1) {
						mesaj[m] = 'Z';
						majuscula = 0;
					} else
						mesaj[m] = 'z';
					m++;
					apasare = 1;
				}
			}
			if (taste[i] == '0') {
				mesaj[m] = ' ';
				m++;
			}
		}
	}
	mesaj[m] = '\0';
	*l = m;
}

char *strdel(char *d, int n)	
// Functia sterge n caractere de la adresa d.
{
	char aux[100];
	if (n < strlen(d)) {
		strcpy(aux, d + n);
		strcpy(d, aux);
	} else
		*d = 0;
	return d;
}

void strins(char *d, char *s)	// Functia insereaza sirul s la adresa d.
{
	char aux[100];
	strcpy(aux, d);
	strcpy(d, s);
	strcat(d, aux);
}

long long cmmdc(long long a, long long b)	
		// Functia calculeaza cmmmdc-ul numerelor a si b.
{
	int aux;
	while (b != 0) {
		aux = b;
		b = a % b;
		a = aux;
	}
	return a;

}

long long suma(long long nr)	//Functia calculeaza suma cifrelor unui numar.
{
	int s = 0;
	while (nr != 0) {
		s = s + (nr % 10);
		nr = nr / 10;
	}
	return s;
}

typedef struct {
	char *cuvantgresit, *cuvantcorect;
} dictionar;	//Se defineste structura dictionar.

int main()
{	// Cerinta 1

	int n, j = 0;		
	// Variabila n este lungimea mesajului
	// citit,iar variabbila j este lungimea
	// codului.  
	char cod[300], text[100];	
	// Text reprezinta propozitia citita,iar
	// cod este sirul codificat.
	fgets(text, 100, stdin);	// Se citeste textul.
	n = strlen(text);	// Se calculeaza lungimea textului.  
	codificare(text, n, cod, &j);	// Se apeleaza functia codificare.
	puts(cod);		// Se afiseaza mesajul codificat.

	// Cerinta 2 

	int p, m = 0;		
	// Variabila p este lungimea codului,iar m 
	// este lungimea mesajului descifrat.
	char taste[300], mesaj[100];	
	// Taste reprezinta codul citit,iar mesaj este sirul decodificat.
	fgets(taste, 300, stdin);	// Se citeste codul.
	p = strlen(taste);	// Se calculeaza lungimea codului.
	decodificare(taste, p, mesaj, &m);	// Se apeleaza functia
	// decodificare.
	puts(mesaj);		// Se afiseaza mesajul decodificat.

	// Cerinta 3

	int cuvinte, pg, cd, change, n1, lungime, lungimecorecta = 0;
	/*Variabila cuvinte reprezinta numarul de perechi de cuvinte citite,
	   variabila pg este un contor folosit la parcurgerea vectorului
	   de structuri,cd este un contor folosit pentru a parcurge vectorul 
	   de cuvinte corecte din structurile citite anterior,variabila change
	   este folosita pentru a determina daca un cuvant a fost corectat
	   sau nu,n1 este lungimea cuvantului gresit,lungime este lungimea
	   propozitiei si lungimecorecta este lungimea propozitiei
	   corectate codate.
	 */
	char propozitie[100], *flag, corectare[300], cuvant[50];
	/*Sirul propozitie este propozitia care va fi corectata,
	   prin pointerul flag se pastreaza modificarile facute la 
	   propozitie,corectare este propozitia corectata codata si
	   cuvant este cuvantul care se citeste.
	 */
	fgets(propozitie, 100, stdin);	// Se citeste propozitia.
	scanf("%d", &cuvinte);	//Se citeste un nr de cuvinte.
	dictionar *corect;	//Se declara vecorul de structuri de cuvinte.
	corect = (dictionar *) malloc(cuvinte * sizeof(dictionar));
	//Se aloca dinamic memoria.
	for (pg = 0; pg < cuvinte; pg++) {
		change = 1;
		scanf("%s", cuvant);	//Se citeste cuvantul gresit.
		corect[pg].cuvantgresit =
		    (char *)malloc((strlen(cuvant) + 1) * sizeof(char));
		strcpy(corect[pg].cuvantgresit, cuvant);
		scanf("%s", cuvant);	//Se citeste cuvantul corect.
		corect[pg].cuvantcorect =
		    (char *)malloc((strlen(cuvant) + 1) * sizeof(char));
		strcpy(corect[pg].cuvantcorect, cuvant);
		n1 = strlen(corect[pg].cuvantgresit);
		//n1 va fi lungimea cuvantului gresit
		flag = strstr(propozitie, corect[pg].cuvantgresit);
		//Pointerul flag verifica daca cuvantul 
		//gresit apare in propozitie.
		for (cd = 0; cd <= pg; cd++)
			if (strcmp
			    (corect[pg].cuvantgresit,
			     corect[cd].cuvantcorect) == 0)
				change = 0;
		/*Prin acest for se verifica daca un cuvant a 
		fost deja inlocuit,change luand valoarea 0 daca 
		acel cuvant a fost corectat deja. */
		while (flag != NULL && change == 1) {
		/*In cazul in care cuvantul gresit exista si nu a fost corectat
		   se va face corectarea,verificandu-se 
			prima oara daca acesta nu
		   face parte dintr-un cuvant prin existenta 
			spatiilor(' ') sau a 
		   terminatorului de sir('\0'). */
			if ((*(flag + n1) == ' ' || strlen(flag) == n1 + 1) &&
			    strlen(flag) == strlen(propozitie))
			/*Corectarea in cazul in care se inlocuieste 
			primul cuvant din enunt.
			   Se verifica existenta spatiului 
			dupa flag si se verifica daca 
			   lungimea pointerului este egala 
			cu cea a propozitiei pentru
			   a vedea daca primul cuvant este 
			gresit sau nu,apoi se verifica
			   daca exista spatiu sau separator 
			de sir dupa cuvant. */
			{
				flag = strdel(flag, n1);
				//Se sterge cuvantul gresit.
				strins(flag, corect[pg].cuvantcorect);
				//Se introduce cuvantul corect pe 
				//pozitia celui gresit.
				flag =
				    strstr(flag +
					   strlen(corect[pg].cuvantcorect),
					   corect[pg].cuvantgresit);
				/*Se muta pozitia pointerului cu 
					un numar la fel de mare ca
				   lungimea cuvantului corect. */
			}
			/*Corectarea in cazul in care cuvantul
			 gresit nu este primul.
			   Se verifica existenta spatiului pe pozitia 
			anterioara pointerului.
			   Apoi se verifica existenta spatiului sau a 
			terminatorului de sir 
			   dupa cuvant. */
			else if ((*(flag + n1) == ' ' || strlen(flag) == n1 + 1)
				 && *(flag - 1) == ' ') {
				flag = strdel(flag, n1);
				//Se sterge cuvantul gresit.
				strins(flag, corect[pg].cuvantcorect);
				//Se introduce cuvantul corect pe 
				//pozitia celui gresit.
				flag =
				    strstr(flag +
					   strlen(corect[pg].cuvantcorect),
					   corect[pg].cuvantgresit);
				/*Se muta pozitia pointerului cu un 
					numar la fel de mare ca
				   lungimea cuvantului corect. */
			} else
				flag =
				    strstr(flag +
					   strlen(corect[pg].cuvantgresit),
					   corect[pg].cuvantgresit);
			/*In cazul in care cuvantul face parte 
				din alt cuvant se muta
			   pozitia pointerului cu un numar la fel de 
				mare ca lungimea cuvantului
			   gresit. */
		}
	}
	lungime = strlen(propozitie);	//Se calculeaza lungimea propozitiei.
	codificare(propozitie, lungime, corectare, &lungimecorecta);
	//Se codifica propozitia corectata.
	puts(corectare);	//Se afiseaza codul propozitiei corectate.
	for (pg = 0; pg < cuvinte; pg++) {
		free(corect[pg].cuvantgresit);
		free(corect[pg].cuvantcorect);
	}
	free(corect);		//Se elibereaza memoria alocata dinamic.
	getchar();

	// Cerinta 4

	int nr = 1, x, i, l = 0, pozitie = 1, ok = 1, i1, s = 0, cifre =
	    0, N, dimensiune, num, k = 0;
	/*Variabila nr reprezinta numarul de componente,x reprezinta lungimea
	   mesajului nou citit,i este un contor de parcurgere al vectorilor,
	   l este lungimea codului mesajului nou,pozitie arata localizarea 
	   maximului in vector,ok este o variabila care determina daca 
	   elementele vectorului sunt prime intre ele(1-Da,0-Nu),i1
	   este un contor de parcurgere al vectorului,s=0 reprezinta
	   suma cifrelor elementelor,N reprezinta restul impartirii
	   la 9 a sumei cifrelor,cifre reprezinta numarul cifrelor
	   din codul nou,dimensiune este numarul de grupuri de N
	   cifre,num reprezinta numarul de cifre dintr-o grupare,iar
	   k este un contor de parcurgere al sirului de caractere.
	 */
	long long maxim, aux;
	/*Maxim reprezinta valoarea maxima dintr-un sir,iar
	   aux este o valoare auxiliara utilizata in interschimbare. */
	long long *numere, *grupuri;
	/*Numere este vectorul de componente,iar grupuri este vectorul
	   de grupuri de N cifre. */
	char mesajnou[100], codnou[300];
	/*Sirul mesajnou reprezinta mesajul care este citit,iar
	   codnou este codificarea acestui mesaj. */
	fgets(mesajnou, 100, stdin);	// Se citeste un mesaj nou.
	x = strlen(mesajnou);	// Se calculeaza lungimea mesajului.
	codificare(mesajnou, x, codnou, &l);	//Se codifica mesajul.
	//Se numara componentele din cod,numarul crescand la aparitia cifrei 0.
	for (i = 0; i < l; i++)
		if (codnou[i] == '0' && codnou[i + 1] != '0' && i != 0)
			nr++;
	//Se aloca dinamic memoria vectorului de componente.
	numere = (long long *)calloc(nr, sizeof(long long));
	//Se afiseaza numarul de componente.
	printf("%d\n", nr);
	nr = 0;
	for (i = 0; i < l; i++) {
		if (codnou[i] == '0' && codnou[i + 1] == '0'
		    && codnou[i - 1] != '0')
			numere[nr] = numere[nr] * 10;
		else if (codnou[i] == '0' && codnou[i + 1] && i != 0)
			nr++;
		else if (codnou[i] >= '1' && codnou[i] <= '9')
			numere[nr] = numere[nr] * 10 + ((int)codnou[i] - '0');
	}			/*Se formeaza componentele,fiecare 
					caracter numeric din codnou
				   este inlocuit cu cifra respectiva. */
	for (i = 0; i < l; i++)
		if (codnou[i] >= '0' && codnou[i] <= '9')
			cifre++;
	//Se numara cifrele din cod.
	for (i = 0; i < nr + 1; i++)
		printf("%lld ", numere[i]);	// Se afiseaza componentele.
	printf("\n");
	maxim = numere[0];	//Se initializeaza maximul cu prima componenta,
	for (i = 1; i < nr + 1; i++)
		if (numere[i] > maxim) {
			maxim = numere[i];
			pozitie = i + 1;
		}		/*Atunci cand o componenta este mai 
					mare decat maximul,
				   maximul va lua valoarea acelei 
					componente si se retine
				   pozitia acestuia. */
	printf("%lld %d\n", maxim, pozitie);
	//Se afiseaza maximul si pozitia sa.
	for (i = 0; i < nr; i++)
		for (i1 = i + 1; i1 < nr + 1; i1++)
			if (cmmdc(numere[i], numere[i1]) != 1)
				ok = 0;
	/*Se parcurge vectorul si se calculeaza cmmdc-ul elementelor intre ele
	   ,doua cate doua.Atunci cand cmmdc este diferit de 1,vectorul nu are
	   elemente prime intre ele.
	 */
	printf("%d\n", ok);	//Se afiseaza daca mesajul este prim sau nu.
	for (i = 0; i < nr + 1; i++)
		s = s + suma(numere[i]);
	//Se calculeaza suma cifrelor din vector.
	N = suma(s) % 9;	//Se calculeaza numarul N.
	if (cifre % N != 0 || N == 0)	
	//Se verifica daca numarul este perfect.
		printf("0\n");
	else if (cifre % N == 0) {
		dimensiune = cifre / N;	//Se calculeaza numarul de grupuri.
		grupuri = (long long *)calloc(dimensiune, sizeof(long long));
		//Se aloca dinamic memoria vectorului de grupuri.
		for (i = 0; i < dimensiune; i++) {
			num = 0;
			while (num < N) {
				if (codnou[k] >= '0' && codnou[k] <= '9') {
					grupuri[i] =
					    grupuri[i] * 10 + ((int)codnou[k] -
							       '0');
					num++;
					k++;
				} else
					k++;
			}
		}		/*Se formeaza grupurile.Prin intermediul 
					variabilei num
				   se retine numarul de cifre dintr-un grup,
					trecandu-se la
				   urmatorul grup atunci cand num
					 este egal cu N. */
		for (i = 0; i < dimensiune - 1; i++)
			for (i1 = i + 1; i1 < dimensiune; i1++) {
				if (grupuri[i] < grupuri[i1]) {
					aux = grupuri[i];
					grupuri[i] = grupuri[i1];
					grupuri[i1] = aux;
				}
			}
		/*Se sorteaza descrescator vectorul,atunci cand o valoare este
		   mica decat una de pe o pozitie mai mare,se realizeaza 
		   interschimbarea. */
		for (i = 0; i < dimensiune; i++)
			printf("%lld ", grupuri[i]);
		free(grupuri);
		//Se afiseaza vectorul sortat si se elibereaza memoria alocata.
	}

	free(numere);		//Se elibereaza memoria alocata.
	return 0;
}

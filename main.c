#include "dictionary.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct dictionary d;



void main (void)
{

	int antwort;
	liesdictionary ("dictionary.txt",  &d);

	do
	{
		printf ("Bitte waehlen:\n");
		printf ("   a) Vokabelabfrage deutsch - englisch\n");
		printf ("   b) Vokabelabfrage englisch - deutsch\n");
		printf ("   c) Woerterbuch deutsch - englisch\n");
		printf ("   d) Woerterbuch englisch - deutsch\n");
		printf ("   e) neues Wort aufnehmen\n");
		printf ("   f) Ende\n");

		antwort = getc(stdin);
		switch (antwort)
		{
		case 'a':
			vokabelabfrage ('d', &d);
			break;
		case 'b':
			vokabelabfrage ('e', &d);
			break;
		case 'c':
			woerterbuch ('d', d);
			break;
		case 'd':
			woerterbuch ('e', d);
			break;
		case 'e':
			neueswort (&d);
			break;
		case 'f':
			break;
		default:
			printf ("\n falsche Eingabe\n");
			fflush (stdin);
		}
		fflush (stdin);
	} while (antwort != 'f');

	schreibedictionary ("dictionary.txt",  d);


}
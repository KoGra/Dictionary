#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "dictionary.h"





int liesdictionary (char * filename, struct dictionary * d)
{
	FILE*fp;

	d->anz_woerter = 0;
	fp = fopen (filename, "r");
	if (fp == NULL)
		return 0;

	while (fscanf (fp, "%s %s %d %d",
		d->woerter[d->anz_woerter].deutsch,
		d->woerter [d->anz_woerter ].englisch ,
			& d->woerter [d->anz_woerter ].anz_gewusst,
			 & d->woerter [d->anz_woerter ].anz_falsch  ) > 0)
	{
			printf ("%d\n", d->anz_woerter );
			d->anz_woerter++;
	}
	fclose (fp);
	return d->anz_woerter;

}


int schreibedictionary (char * filename, struct dictionary d)
{
	FILE*fp;
	int i;

	fp = fopen (filename, "w");
	if (fp == NULL)
		return 0;

	for (i=0; i< d.anz_woerter; i++)
		fprintf (fp, "%s %s %d %d\n",d.woerter[i].deutsch, d.woerter [i].englisch ,
			 d.woerter [i].anz_gewusst, d.woerter [i].anz_falsch  );

	fclose (fp);
	return 1;
}


struct dic_record * findedeutsch (char * s, struct dictionary d)
{
	int i;
	for (i=0; i< d.anz_woerter; i++)
	{
		if (strcmp (s, d.woerter [i].deutsch ) == 0)
			return & d.woerter [i];
	}
	return NULL;

}


struct dic_record * findeenglisch (char * s, struct dictionary d)
{
	int i;
	for (i=0; i< d.anz_woerter; i++)
	{
		if (strcmp (s, d.woerter [i].englisch ) == 0)
			return & d.woerter [i];
	}
	return NULL;

}


void worthinzufuegen (char * deutsch, char * englisch, struct dictionary *d)
{
	if (findedeutsch (deutsch, *d) == NULL && findeenglisch (englisch, *d) == NULL)
	{
		strcpy (d->woerter[d->anz_woerter].deutsch, deutsch);
		strcpy (d->woerter[d->anz_woerter].englisch, englisch);
		d->woerter [d->anz_woerter].anz_falsch = 0;
		d->woerter [d->anz_woerter].anz_gewusst  = 0;

	}

}

void vokabelabfrage (char sprache, struct dictionary *d)
{
	char deutsch[MAXLEN];
	char englisch [MAXLEN];
	int i;
	int ende = 0;
	srand( (unsigned)time( NULL ) );

	do
	{
		
		i = rand() % d->anz_woerter;
		if (sprache == 'd')
		{
			printf ("%s: ", d->woerter [i].deutsch );
			scanf ("%s", englisch);
			if (strcmp (englisch, "!") == 0)
				ende = 1;
			else
			{
				if (strcmp (d->woerter [i].englisch , englisch) != 0)
				{
					printf ("das war falsch, richtig waere gewesen: %s\n", d->woerter [i].englisch );
					d->woerter [i].anz_falsch ++;
				}
				else
				{
					printf ("das war richtig!\n");
					d->woerter [i].anz_gewusst ++;
				}
			}
		}
		else
		{
			printf ("%s: ", d->woerter [i].englisch );
			scanf ("%s", deutsch);
			if (strcmp (deutsch, "!") == 0)
				ende = 1;
			else
			{
				if (strcmp (d->woerter [i].deutsch , deutsch) != 0)
				{
					printf ("das war falsch, richtig waere gewesen: %s\n", d->woerter [i].deutsch );
					d->woerter [i].anz_falsch ++;
				}
				else
				{
					printf ("das war richtig!\n");
					d->woerter [i].anz_gewusst ++;
				}
			}
		}
	}	while (!ende);

}


void woerterbuch (char sprache, struct dictionary d)
{
	char deutsch[MAXLEN];
	char englisch [MAXLEN];
	struct dic_record * de;

	if (sprache == 'd')
	{
		printf ("bitte deutsches Wort eingeben:");
		scanf ("%s", deutsch);
		if ((de = findedeutsch (deutsch, d)) != NULL)
		{
			printf ("%s: %s\n", de->deutsch, de->englisch);
		}
		else
		{
			printf ("das wort ist im Woerterbuch nicht enthalten\n");
		}

	}

	if (sprache == 'e')
	{
		printf ("bitte englisches Wort eingeben:");
		scanf ("%s", englisch);
		if ((de = findeenglisch (englisch, d)) != NULL)
		{
			printf ("%s: %s\n", de->englisch, de->deutsch);
		}
		else
		{
			printf ("das wort ist im Woerterbuch nicht enthalten\n");
		}

	}


}

void neueswort (struct dictionary *d)
{
	char deutsch[MAXLEN];
	char englisch [MAXLEN];

	printf ("bitte deutsches Wort eingeben:");
	scanf ("%s", deutsch);
	if (findedeutsch (deutsch, *d))
	{
		printf ("Dieses Wort gibt es bereits\n");
		return;
	}


	printf ("bitte englisches Wort eingeben:");
	scanf ("%s", englisch);
	if (findeenglisch (englisch, *d))
	{
		printf ("Dieses Wort gibt es bereits\n");
		return;
	}
	strcpy( d->woerter [d->anz_woerter ].deutsch, deutsch);
	strcpy( d->woerter [d->anz_woerter ].englisch, englisch);
	d->woerter [d->anz_woerter].anz_falsch = 0;
	d->woerter [d->anz_woerter].anz_gewusst = 0;
	d->anz_woerter ++;

}

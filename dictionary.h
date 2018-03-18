#ifndef DICTIONARY_H
#define DICTIONARY_H

#define MAXLEN 30
#define MAXWORTE 200

struct dic_record
{
	char deutsch [MAXLEN];
	char englisch [MAXLEN];
	int anz_falsch;
	int anz_gewusst;
};


struct dictionary
{
	int anz_woerter;
	struct dic_record woerter[MAXWORTE];
};


int liesdictionary (char * filename, struct dictionary * d);


int schreibedictionary (char * filename, struct dictionary d);


struct dic_record * findedeutsch (char * s, struct dictionary d);


struct dic_record * findeenglisch (char * s, struct dictionary d);


void worthinzufuegen (char * deutsch, char * englisch, struct dictionary *d);


void vokabelabfrage (char sprache, struct dictionary *d);

void woerterbuch (char sprache, struct dictionary d);

void neueswort (struct dictionary *d);

#endif



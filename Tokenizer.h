#include <string>
#include <vector>

#include "Num.h"
#include "Bracket.h"
#include "Op.h"


using namespace std;

class Tokenizer 			//bearbeitet von Luca Laderer
{
 
    string src;
	int check = 0;
	char temp;

public:
    Tokenizer(string s) 	//Konstruktor wird mit string als Argument aufgerufen
	{
        src = s + " "; // Das Leerzeichen dient dazu, beim Lesen von Zahlen nicht 
					   // ueber die String-Grenze zu laufen
		tokenize(src);
    }


//selbst geschrieben ->
	// void goThroughString(string src)
	// {
	// 	int i = 0;
	// 	while(src[i] != ' ')
	// 	{
	// 		temp = src[i];
	// 		checkSign(temp);
	// 		i++;
	// 	}
	// }

	int checkSign(char tempo)
	{
		if (tempo == '0' || tempo == '1' || tempo == '2' || tempo == '3' || tempo == '4' || tempo == '5' || tempo == '6' || tempo == '7' || tempo == '8' || tempo == '9')
		{
			check = 1;
		}
		else if(tempo == '+' || tempo == '-' || tempo == '*' || tempo == '/')
		{
			check = 2;
		}
		else if(tempo == '(' || tempo == ')')
		{
			check = 3;
		}	
		return check;
	}


//	<- selbst geschrieben


    vector<Token*>* tokenize(string src) 		//schleife in oder außerhalb von tokenize? begin() immer an ältester oder neuester Position?
	{
        vector<Token*>* tokens = new vector<Token*>();
	    vector<Token*>::iterator i = tokens->begin();		//hier eventuell Probleme
		/*

		Beispiel f�r das Einf�gen von Knoten:

		i = tokens->insert(i, new Op(c));
		i = tokens->insert(i, new Num(c));
		usw. 
		
		*/

		// void goThroughString(string src)
		// {
			int z = 0;
			int zahl;
			temp = src[z];
			while(temp != ' ')
			{
				switch(checkSign(temp))
				{
				case 1:	//Zahlen
					//Hier noch testen, ob darauffolgendes Zeichen ebenfalls Zahl 
					zahl = temp - '0';		//char zu Integer umwandeln
					i = tokens->insert(i, new Num(zahl));
					break;
				case 2:	//Operatoren
					i = tokens->insert(i, new Op(temp));
					break;
				case 3:	//Klammern
					i = tokens->insert(i, new Bracket(temp));
					break;
				default:
					break;
				}
				z++;
			}
		// }

		
		// switch(checkSign(tempo))
		// {
		// case 1:	//Zahlen
		// 	//Hier noch testen, ob darauffolgendes Zeichen ebenfalls Zahl 
		// 	int zahl = temp - '0';		//char zu Integer umwandeln
		// 	i = tokens->insert(i, new Num(zahl));
		// 	break;
		
		// case 2:	//Operatoren
		// 	i = tokens->insert(i, new Op(temp));
		// 	break;

		// case 3:	//Klammern
		// 	i = tokens->insert(i, new Bracket(temp));
		// 	break;
		// }

        // tokens->add(new Num()); // remove this line

        return tokens;
    }
    
};
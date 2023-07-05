#include <string>
#include <vector>

#include "Num.h"
#include "Bracket.h"
#include "Op.h"


using namespace std;

class Tokenizer 		//bearbeitet von Luca Laderer
{
 
    string src;

public:
    Tokenizer(string s) 	//Konstruktor wird mit string als Argument aufgerufen
	{
        src = s + " "; // Das Leerzeichen dient dazu, beim Lesen von Zahlen nicht 
					   // ueber die String-Grenze zu laufen
    }


//selbst geschrieben ->
	void goThroughString(char s)
	{
		int i = 0;
		while(src[i] != ' ')
		{
			char temp = src[i];
			tokenize(temp);
			i++;
		}
	}

	void checkSign(char tempo)
	{
		checkNum(tempo);
	}

	bool checkNum(char tempo)
	{
		if(tempo == '0' || tempo == '1' || tempo == '2' || tempo == '3' || tempo == '4' || tempo == '5' || tempo == '6' || tempo == '7' || tempo == '8' || tempo == '9')
		{
			return true;
		}
		else
		{
			checkOp(tempo);
		}
	}
	
	bool checkOp(char tempo)
	{
		if(tempo == '+' || tempo == '-' || tempo == '*' || tempo == '/')
		{
			return true;
		}
		else
		{
			checkBracket(tempo);
		}
	}

	bool checkBracket(char tempo)
	{
		if(tempo == '(' || tempo == ')')
		{
			return true;
		}
	}
//	<- selbst geschrieben


    vector<Token*>* tokenize(char s) 
	{
        vector<Token*>* tokens = new vector<Token*>();
	    vector<Token*>::iterator i = tokens->begin();
		/*

		Beispiel f�r das Einf�gen von Knoten:

		i = tokens->insert(i, new Op(c));
		i = tokens->insert(i, new Num(c));
		usw. 
		
		*/
		goThroughString(s);
		// &i->push_back(tokens);

		
		// to implement ...

        cout << "Die Methode Tokenizer.tokenize ist noch nicht implementiert!" << endl; // remove this line
        // tokens->add(new Num()); // remove this line

        return tokens;
    }
    
};
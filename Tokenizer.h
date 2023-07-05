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
		goThroughString();
    }



	void goThroughString()
	{
		int i = 0;
		while(src[i] != ' ')
		{
			char test = src[i];
			tokenize(test);
			i++;
		}
	}

	bool checkNum()
	{
		if(src[i] == "0" || src[i] == "1" || src[i] == "2" || src[i] == "3" || src[i] == "4" || src[i] == "5" || src[i] == "6" || src[i] == "7" || src[i] == "8" || src[i] == "9")
		{

		}
		else
		{
			checkNum();
		}
		else
		{
			checkBracket();
		}
	}
	
	bool checkOp()
	{
		if(src[i] == "+" || src[i] == "-" || src[i] == "*" || src[i] == "/")
		{

		}
	}

	bool checkBracket()
	{
		if(src[i] == "(" || src[i] == ")")
		{

		}
	}
    

    vector<Token*>* tokenize(char s) 
	{
        vector<Token*>* tokens = new vector<Token*>();
	    vector<Token*>::iterator i = tokens->begin();
		tokens->push_back(s);
		/*

		Beispiel f�r das Einf�gen von Knoten:

		i = tokens->insert(i, new Op(c));
		i = tokens->insert(i, new Num(c));
		usw. 
		
		*/
		switch()
				{
					case :
					break;
				}

		
		// to implement ...

        cout << "Die Methode Tokenizer.tokenize ist noch nicht implementiert!" << endl; // remove this line
        // tokens->add(new Num()); // remove this line

        return tokens;
    }
    
};
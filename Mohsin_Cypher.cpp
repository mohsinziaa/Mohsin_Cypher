/*
Name: Mohsin Zia.
Reg # 2020244.
Mohsin_Cypher_Program.
*/

#include <iostream>
#include <string.h>
#include <bits/stdc++.h>

using namespace std;

int getIndex(char x){	
	//typeCasted lowerCase alphabet index (a[1], z[26]);			
	return tolower(x) - 96;
}	

char getChar(int index){				
	//typeCasted lowerCase alphabet character (a[1], z[26]);			
	return char(index + 96);	
}	

//Encryption Function.
vector<string> Mohsin_Cypher_Encryption(string plainText);

//Decryption Function.
vector<string> Mohsin_Cypher_Decryption(vector<string> cipherText);


int main(){
	
	string inputText;
	vector<string> cipherText;
	vector<string> plainText;
	
	cout<<endl<<endl<<"\tWelcome to the Encryption and Decryption Program of Mohsin_Cypher - 2020244"<<endl<<endl;
	
	while(true){
		
		cout<<"\tPlease choose the plaintext on which you have to perform the operations\n"
			  "\t1. Stay at home stay safe.\n"
			  "\t2. Enigma was a machine used for cryptography.\n"
			  "\t3. Encryption and decryption are used in cryptography.\n"
			  "\t4. Enter my own custom plain text.\n"
			  "\t5. Exit.\n\n"
			  "\tYour choice (1-5): ";
			  		
		int choice;cin>>choice;

		if(choice >=5){
			cout<<"\n\n\n\tThankyou for using the program Mohsin_Cypher! "<<endl;
			exit(0);
		}
		
		switch(choice){
			
			case 1:
				inputText = "Stay at home stay safe.";	
				cout<<"\n\tPlain text: "<<inputText<<endl;

				cipherText = Mohsin_Cypher_Encryption(inputText);
				plainText = Mohsin_Cypher_Decryption(cipherText);

				break;
	
			case 2:
				inputText = "Enigma was a machine used for cryptography.";	
				cout<<"\n\tPlain text: "<<inputText<<endl;

				cipherText = Mohsin_Cypher_Encryption(inputText);
				plainText = Mohsin_Cypher_Decryption(cipherText);

				break;

			case 3:
				inputText = "Encryption and decryption are used in cryptography.";	
				cout<<"\n\tPlain text: "<<inputText<<endl;

				cipherText = Mohsin_Cypher_Encryption(inputText);
				plainText = Mohsin_Cypher_Decryption(cipherText);

				break;
			
			case 4:
				cout<<"\n\tEnter plain text: ";
				fflush(stdin);
				getline(cin, inputText);

				cipherText = Mohsin_Cypher_Encryption(inputText);
				plainText = Mohsin_Cypher_Decryption(cipherText);

				break;
			
			default:
				cout<<"\n\n\n\tThankyou for using the program Mohsin_Cypher! "<<endl;
				exit(0);
				
		}
		system("pause");
		system("cls");
	}

			
	
	return 0;
}

vector<string> Mohsin_Cypher_Encryption(string plainText){
	
	vector<string> cipherText;
	int index = 0;
	
	for(int i = 0; i < plainText.length(); i++) {

		string x;
				
		//Checking for spaces, dots and commas.
		if(plainText[i] == ' ' || plainText[i] == '.' || plainText[i] == ','){
			x = plainText[i];					//Converting char to str.
			cipherText.push_back(x);			//Appending in the string vector.
			continue;
		}
		
		index = getIndex(plainText[i]);			//Computing the index of each character in plainText.
		
		if(index <= 13){
			index = index*2;					//Indexes of <= 13 are swapped with even indexes (2,4,6,8....)
		}
		else{
			index = (index*2) - 26 - 1;			//Indexes of > 13 are swapped with odd indexes (1,3,5,7,9....)
		}
		
//		cout<<index;
		x = getChar(index);						//Getting character at our new index position.
		cipherText.push_back(x);				//Appending that character to our vector string.
	}

	cipherText[0][0] = char((cipherText[0][0])-32);		//Converting first character to uppercase.

	for(int i=0; i<cipherText.size(); i++){
		
		if(cipherText[i] == "." && (i+1) != cipherText.size()){		//Checking for full stops.

			if(cipherText[i+1] == " "){
				i+=1;									//Updating index to +2 if there is space after dot.
			}

			cipherText[i+1][0] = char((cipherText[i+1][0])-32);		//Converting to upperCase after dot.

		}
	}
	
	cout<<"\n\n\t--------------------------------------------------------------------------------------------------------\n";
	cout<<endl<<"\t\t\tCipher Text: ";

	for(int i=0; i<cipherText.size(); i++){
		cout<<cipherText[i];							//Printing cipherText.
	}

	return cipherText;	
}



vector<string> Mohsin_Cypher_Decryption(vector<string> cipherText){
	
/*
	//Converting vector to string xD.	
	string textDecrypted;
	for (vector<string>::const_iterator i = cipherText.begin(); i != cipherText.end(); ++i) 
		textDecrypted += *i;    
    cout<<endl<<textDecrypted<<endl;
*/
   
	vector<string> plainText;
	int index = 0;
	
	for(int i = 0; i < cipherText.size(); i++) {

		string x;
		char y;
		
		//Checking for spaces, dots and commas.		
		if(cipherText[i] == " " || cipherText[i] == "." || cipherText[i] == ","){
			x = cipherText[i];				//Converting char to str.
			plainText.push_back(x);			//Appending to our string vector.
			continue;
		}

		y = cipherText[i][0];				//Saving it in character form.
		index = getIndex(y);				//Getting index of the character.
				
		if(index % 2 == 0){
			index = index/2;				//All even indexes are mapped to first 13.
		}
		else {
			index = 13 + ((index-1)/2) + 1;	//All odd indexes are mapped to last 13.
		}
		
		x = getChar(index);					//Getting character at that index.
		plainText.push_back(x);				//Appending the character to our string vector.
	}


	plainText[0][0] = char((plainText[0][0])-32);	//Converting first character to uppercase.

	for(int i=0; i<plainText.size(); i++){
		
		if(plainText[i] == "." && (i+1) != plainText.size()){	//Checking for full stops.
			
			if(plainText[i+1] == " "){
				i+=1;								//Updating index to +2 if there is space after dot.
			}
			
			plainText[i+1][0] = char((plainText[i+1][0])-32);	//Converting to upperCase after dot.

		}

	}
	
	cout<<endl<<endl<<"\t\t\tText Decrypted: ";

	for(int i=0; i<plainText.size(); i++){
		cout<<plainText[i];							//Printing decryptedText.
	}
	cout<<endl<<endl;
	cout<<"\t--------------------------------------------------------------------------------------------------------\n\n\n";
	
	return plainText;
}



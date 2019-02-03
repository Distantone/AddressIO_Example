// ---------------------------------------------------------------
// Programming Assignment:	LAB7
// Developer:			Payden Boughton
// Date Written:		4/12/2017
// Purpose:				Address Data Storage
// ---------------------------------------------------------------

//Specification: Append and display records in a address database 
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void menu(void);
void writeData(void);
void readData(void);
string * split(string, char);

const char FileName[] = "TestAddress.txt";
int main () {
        menu();

		system("PAUSE");
        return 0;
} //end main
void menu(void) {

	char ans = '\0';

	do
	{
	cout << "Please Choose one of the Following" << endl;
	cout << "(A)ppend Recors, (S)how Records, (E)xit" << endl;
	cin >> ans;

		switch (ans)
		{
			case 'A':; case 'a':;
				writeData();
				break;
			case 'S':; case 's':;
				readData();
				break;
			case 'E':; case 'e':;
				exit (EXIT_SUCCESS);
				break;
			default:
				cout << "!Invalid input!" << endl;
		}
	}while ((ans != 'E') || (ans != 'e'));
	

}//end menu
void writeData(void){

	string name,street,city,state,zipCode;
	char ans = '\0';
	fstream inout;
	

inout.open(FileName, ios::out | ios::app);

	do {
		cout << "Name...... ";
		cin >> ws;                   //consume any white-space characters for the 1st field
			getline(cin,name);

		cout << "Street...... ";
			getline(cin,street);

		cout << "City...... ";
			getline(cin,city);
		cout << "State...... ";
			getline(cin,state);
		cout << "ZipCode...... ";
			getline(cin,zipCode);

		inout << name << "," << street << "," << city << "," << state << "," << zipCode << endl;

		cout << "Enter another Record? (Y/N)?" << endl;
			cin >> ans;
		}while (ans == 'Y' || ans == 'y');

	inout.close();

}//end write data


void readData(void){

    int recordCount = 0;
string lineBuffer;
ifstream AddInfo("TestAddress.txt", ios::in);
      
    if (AddInfo.is_open()) // tests to see if file is open
    {
        cout << endl;
        cout << "SHOW RECORDS" << endl;
        cout << "____________" << endl;
        getline (AddInfo, lineBuffer); //gets first line of text and places it in lineBuffer
      
        while(AddInfo.good()) //while file is error free and not EOF
        {
            string * theFields = split(lineBuffer, ',');
            recordCount++;
              
            cout << "\n Record No. " << recordCount;
            cout << endl;
            cout << "Name............." << theFields[0] << endl;
            cout << "Address.........." << theFields[1] << endl;
            cout << "City............." << theFields[2] << endl;
            cout << "State............" << theFields[3] << endl;
            cout << "Zip.............." << theFields[4] << endl;
            cout << "__________________________________________" << endl;
      
            getline(AddInfo, lineBuffer); //gets next line of text into "lineBuffer"
        }
      
        AddInfo.close();
        menu();
    }
    else
    {
        cout << "Unable to open file." << endl;
    }
}//end read data


string * split(string theLine, char theDeliminator)//Useage: string *theFields = split(lineBuffer, ',');
{
    int splitCount = 0;
    for(int i = 0; i < theLine.size(); i++)
    {
        if (theLine[i] == theDeliminator)
        splitCount++;
    }
    splitCount++;  
         
    string* theFieldArray; 
    theFieldArray = new string[splitCount]; 
         
    string theField = "";
    int commaCount = 0;
 
    for(int i = 0; i < theLine.size(); i++)
    { 
        if (theLine[i] != theDeliminator) 
        {
            theField += theLine[i]; 
        }
        else
        { 
            theFieldArray[commaCount] = theField; 
            theField = "";
            commaCount++;
        }
    }
theFieldArray[commaCount] = theField; 
 
return theFieldArray;
}


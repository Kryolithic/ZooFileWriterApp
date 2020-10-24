/*Gary Clark
 * Southern New Hampshire University
 * Zoo application
 * ver 1.0
 * October 18, 2020
 */
#include <iostream>
#include <iomanip>
#include <jni.h>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "Animal.h"
#include "Bat.h"
#include "Crocodile.h"
#include "Goose.h"
#include "Mammal.h"
#include "Oviparous.h"
#include "Pelican.h"
#include "SeaLion.h"
#include "Whale.h"

using namespace std;


void GenerateData()               //DO NOT TOUCH CODE IN THIS METHOD
{
     JavaVM *jvm;                      // Pointer to the JVM (Java Virtual Machine)
     JNIEnv *env;                      // Pointer to native interface
                                                              //================== prepare loading of Java VM ============================
     JavaVMInitArgs vm_args;                        // Initialization arguments
     JavaVMOption* options = new JavaVMOption[1];   // JVM invocation options
     options[0].optionString = (char*) "-Djava.class.path=";   // where to find java .class
     vm_args.version = JNI_VERSION_1_6;             // minimum Java version
     vm_args.nOptions = 1;                          // number of options
     vm_args.options = options;
     vm_args.ignoreUnrecognized = false;     // invalid options make the JVM init fail
                                                                          //=============== load and initialize Java VM and JNI interface =============
     jint rc = JNI_CreateJavaVM(&jvm, (void**)&env, &vm_args);  // YES !!
     delete options;    // we then no longer need the initialisation options.
     if (rc != JNI_OK) {
            // TO DO: error processing...
            cin.get();
            exit(EXIT_FAILURE);
     }
     //=============== Display JVM version =======================================
     cout << "JVM load succeeded: Version ";
     jint ver = env->GetVersion();
     cout << ((ver >> 16) & 0x0f) << "." << (ver & 0x0f) << endl;

     jclass cls2 = env->FindClass("ZooFileWriter");  // try to find the class
     if (cls2 == nullptr) {
            cerr << "ERROR: class not found !";
     }
     else {                                  // if class found, continue
            cout << "Class MyTest found" << endl;
            jmethodID mid = env->GetStaticMethodID(cls2, "createZooFile", "()V");  // find method
            if (mid == nullptr)
                   cerr << "ERROR: method void createZooFile() not found !" << endl;
            else {
                   env->CallStaticVoidMethod(cls2, mid);                      // call method
                    cout << endl;
            }
     }


     jvm->DestroyJavaVM();
     cin.get();
}
//initializing pointer makeAnimal to class Animal with corresponding variables
Animal* makeAnimal(int trackNum, string name, string type, string subType, int eggs, int nurse) {
	//initializing instances of derived classes of Animal for each animal sub-type with corresponding variables
   if (subType == "Crocodile") {
       Crocodile* newAnimal = new Crocodile(eggs);
       newAnimal->code = trackNum;
       newAnimal->name = name;
       return newAnimal;

   }
   else if (subType == "Goose") {
       Goose* newAnimal = new Goose(eggs);
       newAnimal->code = trackNum;
       newAnimal->name = name;
       return newAnimal;
   }
   else if (subType == "Pelican") {
       Pelican* newAnimal = new Pelican(eggs);
       newAnimal->code = trackNum;
       newAnimal->name = name;
       return newAnimal;
   }
   else if (subType == "Bat") {
       Bat* newAnimal = new Bat(nurse);
       newAnimal->code = trackNum;
       newAnimal->name = name;
       return newAnimal;
   }
   else if (subType == "Whale") {
       Whale* newAnimal = new Whale(nurse);
       newAnimal->code = trackNum;
       newAnimal->name = name;
       return newAnimal;
   }
   else if (subType == "SeaLion") {
       SeaLion* newAnimal = new SeaLion(nurse);
       newAnimal->code = trackNum;
       newAnimal->name = name;
       return newAnimal;
   }

}
//declaring function AddAnimal with vector<Animal*> &zooList as input
void AddAnimal(vector<Animal*> &zooList)
{
	//declaring variables to hold user input for each attribute of animals in zoo
	int trackNum;
	string animalName;
	string animalType;
	string animalSub;
	int eggLaid = 0;
	int isNurse = 0;
	char userInput;
//prompting user for inputs to each variable and receiving inputs to the variables
	std::cout << "Enter Track Number" << endl;
	std::cin >> trackNum;
	std::cout << "Enter Animal Name" << endl;
	std::cin.ignore(); //ignoring the input stream to get accurate input for next line
	std::getline (cin, animalName);
	std::cout << "Enter Animal Type" << endl;
	std::cin.ignore();
	std::getline (cin, animalType);
//if statement to run if animal is a mammal
	if(animalType == "Mammal") {
		//prompting user input for sub type and nursing status
		std::cout << "Enter Animal Sub-Type" << endl;
		std::cin.ignore();
		std::cin >> animalSub;
		std::cout << "Is Animal Nursing? (y/n)" << endl;
		std::cin >> userInput;
		//if user inputs 'y' for nursing isNurse is set to 1
		if (userInput == 'y') {
			isNurse = 1;
		}
		//declaring pointer to Animal class newAnimal equal to the function makeAnimal with user inputs as input variables
		Animal* newAnimal = makeAnimal(trackNum, animalName, animalType, animalSub, eggLaid, isNurse);
		std::cout << "You Entered:" << endl; //displaying information that user input
		newAnimal->PrintInfo();//running PrintInfo() function to display animal data
		std::cout << "Is This Correct? (y/n)" << endl; //prompts user to select data's correctness
		std::cin >> userInput;
		if (userInput == 'y') { //if data is correct
			zooList.push_back(newAnimal); //instance newAnimal added to vector zooList using push_back
		}

	}
//if statement for Oviparous type
	if(animalType == "Oviparous") {
		std::cout << "Enter Animal Sub-Type" << endl;
		std::cin.ignore();
		std::cin >> animalSub;
		std::cout << "Enter # Eggs Laid" << endl;
		std::cin >> eggLaid; //user inputs number of eggs laid

		//declaring instance newAnimal of Animal equal to makeAnimal function with user input as variables
		Animal* newAnimal = makeAnimal(trackNum, animalName, animalType, animalSub, eggLaid, isNurse);
		std::cout << "You Entered:" << endl;
		newAnimal->PrintInfo(); //display data that was input
		std::cout << "Is This Correct? (y/n)" << endl;
		std::cin >> userInput;
		if (userInput == 'y') {
			zooList.push_back(newAnimal); //adds instance newAnimal to vector zooList
		}

	}


}

//declaring function to remove animal with vector as input
void RemoveAnimal(vector<Animal*> &zooList)
{
	//declaring local variables
	int deleteCode;
	int location;
	std::cout << "Enter Track # of Animal to Remove" << endl; //prompts user to enter track # of animal they wish to remove
	std::cin >> deleteCode; //sets deletCode equal to input
	//for loop to iterate through zooList vector
	for (unsigned int i = 0; i < zooList.size(); ++i) {
		if (zooList[i]->code == deleteCode) { //if position i of vector zooList has variable code equal to the user input
			location = i; //location variable stores location of animal record in vector
		}
	}
	//if track # is not found it will return -1 thus location == -1
	if(location == -1) {
		std::cout << "Invalid Tracking Number" << std::endl; //displays invalid track # to user
		return;
	}
	//else statement for all location values not -1
	else {
		//confirming user wishes to delete record
		std::cout << "Are you sure you wish to delete:" << std::endl;
		zooList[location]->PrintInfo(); //runs PrintInfo() function of position 'location' of zooList vector
		std::cout << "Press 'Y' to Confirm or 'N' to Cancel" << std::endl; //prompts user to confirm or cancel record deletion
		char userInput;
		std::cin >> userInput;
		if(userInput == 'Y'||userInput == 'y') { //if 'y' then user wishes to delete record
			delete zooList[location]; //delete position 'location' of zooList
			zooList.erase(zooList.begin() + location); //calling the erase function to clear memory of zooList at node location
			std::cout << "Animal Record Deleted" << std::endl; //confirming record was deleted
		}
		else {
			return;
		}
	}

}
//declaring function to load data from file
void LoadDataFromFile(vector<Animal*> &zooList)
{
	//clearing zooList vector
	zooList.clear();
	int trackNum = -1;
	string animalName;
	string animalType;
	string animalSub;
	int eggLaid = 0;
	int isNurse = 0;
	int prevTrackNum;

//delcaring ifstream inFS with zoodata.txt as file to open
	ifstream inFS("zoodata.txt");
//if statement runs if is_open returns false
	if(!inFS.is_open()) {
		std::cout << "Error Loading File" << endl; //tells user error loading file
	}
	else {
		//while loop to iterate through file until it reaches the end of file or eof
		while (!inFS.eof()) {
			//saving trackNum to prevent copying last segment of data twice
			prevTrackNum = trackNum;
			//reading inFS to each variable
			inFS >> trackNum;
			inFS >> animalName;
			inFS >> animalType;
			inFS >> animalSub;
			inFS >> eggLaid;
			inFS >> isNurse;
			//if statement to break while loop once it has reached eof
			if (trackNum == prevTrackNum) {
				break;
			}
			//adding makeAnimal function with file inputs using push_back
			zooList.push_back(makeAnimal(trackNum, animalName, animalType, animalSub, eggLaid, isNurse));
		}
		//closing file
		inFS.close();
		std::cout << "File Loaded Successfully" << std::endl; //confirming file was loaded
	}

}
//function to save data to txt file
void SaveDataToFile(vector<Animal*> &zooList)
{
	//opening ofstream str with zoodata.txt
	ofstream str("zoodata.txt");
	//if statement runs if file was not found using is_open = false
	if(!str.is_open()) {
		std::cout << "File Not Found" << std::endl;
		return;
	}
	else {
		//for loop to iterate through zooList
		for(unsigned int i = 0; i <zooList.size(); ++i) {
			//if type at i is mammal
			if(zooList[i]->type == "Mammal") {
				//declaring a pointer to mammal class at zooList[i]
				Mammal* temp = (Mammal*)zooList[i];
				//writing instance temp variables to file zoodata.txt
				str << temp->code << std::endl;
				str << temp->name << std::endl;
				str << temp->type << std::endl;
				str << temp->sub << std::endl;
				str << "0" << std::endl; //0 for eggs because mammal does not have
				str << temp->GetNurse() << std::endl;
			}
			else if (zooList[i]->type == "Oviparous") {
				//declaring pointer to oviparous class at zooList[i]
				Oviparous* temp = (Oviparous*)zooList[i];
				//writing instance temp variables to zoodata.txt
				str << temp->code<< std::endl;
				str << temp->name << std::endl;
				str << temp->type << std::endl;
				str << temp->sub << std::endl;
				str << temp->GetEggs() << std::endl;
				str << "0" << std::endl; //0 for nursing because oviparous does not need
			}
		}
		std::cout << "File Saved" << std::endl; //confirming the file was saved
	}

}
//function to display animal data
void DisplayAnimalData(vector<Animal*> &zooList)
{
	//outputting column headers with appropriate formatting
	std::cout << left << setfill(' ') <<
	setw(16) << "Track#" <<
	setw(16) << "Name" <<
	setw(16) << "Type" <<
	setw(16) << "Sub-type" <<
	setw(10) << "Eggs" <<
	setw(10) << "Nurse" <<
	std::endl;
	//for loop to iterate through zooList
	   for (unsigned int i = 0; i < zooList.size(); i++) {
	       zooList[i]->PrintInfo(); //calling PrintInfo() funnction at zooList[i]
	   }


}
//declaring display menu function
void DisplayMenu()
{


	//outputting main menu to user with appropriate formatting
	std::cout << "=====================" << endl;
	std::cout << "      Main Menu      " << endl;
	std::cout << "=====================" << endl << endl;
	std::cout << "1) Load Animal Data  " << endl;
	std::cout << "2) Generate Data     " << endl;
	std::cout << "3) Display Animal Data" << endl;
	std::cout << "4) Add Record        " << endl;
	std::cout << "5) Delete Record     " << endl;
	std::cout << "6) Save Animal Data  " << endl;




}



int main()
{
//declaring vector<Animal*> zooList and local variables
	std::vector<Animal*> zooList;
	char userInput2;
	int userInput;
	bool programEnd = false;
	//calling generate data function to run java file generator
	GenerateData();
	//while loop to run until user wants to quit
	while(programEnd != true) {
		//calling DisplayMenu() function
		DisplayMenu();
		std::cin >> userInput;
		switch(userInput) { //switch statement with userInput as reference
				//cases equivalent to menu options and appropriate functions for each option
				case 1:
					LoadDataFromFile(zooList);
					break;
				case 2:
					GenerateData();
					break;
				case 3:
					DisplayAnimalData(zooList);
					break;
				case 4:
					AddAnimal(zooList);
					break;
				case 5:
					RemoveAnimal(zooList);
					break;
				case 6:
					SaveDataToFile(zooList);
					break;
				default:
					//default statement runs if user does not select valid option
					std::cout << "Please select valid menu option" << endl;
					break;
			}
		//asks user if they want to continue
		std::cout << "Would you like to continue? (y/n)" << endl;
		std::cin >> userInput2;
		//if user does not want to continue
		if (userInput2 == 'n') {
			programEnd = true; //programEnd set to true causing while loop to close and program to end
		}
	}

	return 1;
}

/*
*This program has been developed to help a small private hospital and oversee the hospital billing system for their patients. It 
computes a patient’s bill for the hospital using user-defined functions. 
*Developers: Yeo Ying Sheng, Edu Sinusi, Challven Japirin
*Contact: yeousm@student.usm.my, sinusiedu@student.usm.my, challven001@student.usm.my
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

//Declare and define constant global variables
const int 	FIRST_CHOICE = 1,
			SECOND_CHOICE = 2,
			THIRD_CHOICE = 3,
			FOURTH_CHOICE = 4,
			FIFTH_CHOICE = 5,
			SIXTH_CHOICE = 6,
			EXIT_DECISION = 7;
			
			
//Display the main menu
void showMenu()
{
	const int CHECKOUT = 5; //Declare and define constant local variable
	cout << "Patient Billing Menu\n"
		 << "--------------------------------\n"
		 << "1. Hospital Daily Rate\n"
		 << "2. Types of Surgery\n"
		 << "3. Types of Medication\n"
		 << "4. Types of Service\n"
		 << "5. Check out\n"
		 << "--------------------------------\n";
}


//Display the status of a patient
void patientStatus()
{
	cout << "Patient Status\n"
		 << "--------------------\n"
		 << "1. In-patient\n"
		 << "2. Out-patient\n"
		 << "--------------------\n"
		 << "Status of patient: ";
}


//Calculate the payment based on types of room, duration that the patient has been staying in the hospital and different sets of meals
void patientDetails(int &roomTypes, double &dailyRate, int &stayDuration)
{	
	const int 	QUIT_FOOD_MENU = 5,
				NO_FOOD_ORDERED = 4;
	int foodTypes, patientStat;
	double	setA = 5.00, //Cost of each set of meal in the hospital
			setB = 4.00,
			setC = 4.50,
			deluxeSuiteFee = 700.00, //Cost of each room per day
			singleDeluxeFee = 338.00,
			singleStandardFee = 268.00,
			twoBeddedFee = 150.00,
			fourBeddedFee = 95.00,
			icuFee = 400.00;
	
	patientStatus();
	cin >> patientStat;
	system("cls");
	
	//To determine if the patientStat is within the range
	while(patientStat < FIRST_CHOICE || patientStat > SECOND_CHOICE)
	{
		patientStatus();
		cin >> patientStat;
		system("cls");
	}
	
	//To determine whether the patient is an in-patient or an out-patient
	if(patientStat != 1)
	{
		cout << "The patient is not registered as an in-patient, thus no information regarding the patient.\n\n";
		return;
	}
	
	cout << "Room Categories\n"
		 << "--------------------------------\n"
		 << "1. Deluxe Suite\n"
		 << "2. Single Deluxe\n"
		 << "3. Single Standard\n"
		 << "4. Two Bedded\n"
		 << "5. Four Bedded\n"
		 << "6. ICU\n"
		 << "7. Return to Menu\n"
		 << "--------------------------------\n"
		 << "Please pick an option: ";
	cin >> roomTypes;
	system("cls");
	
	//To determine if the roomTypes is within the range
	while(roomTypes < FIRST_CHOICE || roomTypes > EXIT_DECISION)
	{
		cout << "Please pick a valid option: ";
		cin >> roomTypes;
	}
	
	cout << "How many days has the patient checked into the hospital: ";
	cin >> stayDuration;
	system("cls");
	
	//To calculate the hospital stays charges based on the price of room
	switch (roomTypes)
	{
		case FIRST_CHOICE:
		{
			dailyRate += deluxeSuiteFee;
			break;
		}
		case SECOND_CHOICE:
		{
			dailyRate += singleDeluxeFee;
			break;
		}
		case THIRD_CHOICE:
		{
			dailyRate += singleStandardFee;
			break;
		}
		case FOURTH_CHOICE:
		{
			dailyRate += twoBeddedFee;
			break;
		}
		case FIFTH_CHOICE:
		{
			dailyRate += fourBeddedFee;
			break;
		}
		case SIXTH_CHOICE:
		{
			dailyRate += icuFee;
			break;
		}
		default:
			break;
	}
	
	//Multiply the dailyRate that contains the room price with the number of days that a patient has been staying in the hospital
	dailyRate *= stayDuration;
	
	//Calculate the hospital stays charges by adding the price of each meal set with dailyRate
	for(int i=1; i <= stayDuration; i++)
	{
		cout << "Food Menu\n"
 			 << "--------------------------------\n"
			 << "1. Set A\n"
		 	 << "2. Set B\n"
		 	 << "3. Set C\n"
		 	 << "4. No food ordered\n"
		 	 << "5. Return to Menu\n"
		 	 << "--------------------------------\n"
		 	 << "Please pick the set of meal on day " << i <<  ": ";
		cin >> foodTypes;
		system("cls");
		
		while(foodTypes < FIRST_CHOICE || foodTypes > QUIT_FOOD_MENU)
		{
			cout << "Food Menu\n"
 				 << "--------------------------------\n"
				 << "1. Set A\n"
			 	 << "2. Set B\n"
			 	 << "3. Set C\n"
			 	 << "4. No food ordered\n"
			 	 << "5. Return to Menu\n"
			 	 << "--------------------------------\n"
				 << "Please pick a valid option: ";
			cin >> foodTypes;
			system("cls");
		}
		
		if(foodTypes == NO_FOOD_ORDERED)
		{
			continue;
		}
		else if(foodTypes == QUIT_FOOD_MENU)
		{
			return;
		}
		else
		{
			switch(foodTypes)
			{
				case FIRST_CHOICE:
				{
					dailyRate += setA;
					break;
				}
				case SECOND_CHOICE:
				{
					dailyRate += setB;
					break;
				}
				case THIRD_CHOICE:
				{
					dailyRate += setC;
					break;
				}
				default:
					break;
			}
		}
	}
}


//Call the function and return the hospital stays charges of a patient
double hospitalStay()
{		
	int roomTypes = 0, 
		stayDuration = 0;
		
	double	dailyRate = 0;

	patientDetails(roomTypes, dailyRate, stayDuration);
	
	return dailyRate;
}


//Calculate and return the amount of surgery charges of a patient
double surgeryCharges()
{
	double 	surgeryFees = 0,
			spineFee = 55000.00,
			hipReplacementFee = 50000.00,
			coronaryBypassFee = 30000.00,
			angioplastyFee = 20000.00,
			kneeReplacementFee = 35000.00,
			kidneyStoneRemovalFee = 15000.00;
	
	int option, cntSurgery = 0;
	
	do
	{
		if(cntSurgery == 0)
		{
			cout << "Surgery Categories\n"
				 << "--------------------------------\n"
				 << "1. Spine Surgery\n"
				 << "2. Hip Replacement Surgery\n"
				 << "3. Coronary Bypass Surgery\n"
				 << "4. Angioplasty Surgery\n"
				 << "5. Knee Replacement Surgery\n"
				 << "6. Kidney Stone Removal Surgery\n"
				 << "7. Return to Menu\n"
				 << "--------------------------------\n"
				 << "Please pick an option: ";
			cin >> option;
			system("cls");
			cntSurgery++;
		}
		else
		{
			cout << "Surgery Categories\n"
				 << "--------------------------------\n"
				 << "1. Spine Surgery\n"
				 << "2. Hip Replacement Surgery\n"
				 << "3. Coronary Bypass Surgery\n"
				 << "4. Angioplasty Surgery\n"
				 << "5. Knee Replacement Surgery\n"
				 << "6. Kidney Stone Removal Surgery\n"
				 << "7. Return to Menu\n"
				 << "--------------------------------\n"
				 << "Please pick another option (Press 7 to return to menu): ";
			cin >> option;
			system("cls");
		}
		
		while(option < FIRST_CHOICE || option > EXIT_DECISION)
		{
			cout << "Surgery Categories\n"
				 << "--------------------------------\n"
				 << "1. Spine Surgery\n"
				 << "2. Hip Replacement Surgery\n"
				 << "3. Coronary Bypass Surgery\n"
				 << "4. Angioplasty Surgery\n"
				 << "5. Knee Replacement Surgery\n"
				 << "6. Kidney Stone Removal Surgery\n"
				 << "7. Return to Menu\n"
				 << "--------------------------------\n"
				 << "Please pick a valid option: ";
			cin >> option;
			system("cls");
		}
		
		switch (option)
		{
			case FIRST_CHOICE:
			{
				surgeryFees += spineFee;
				break;
			}
			case SECOND_CHOICE:
			{
				surgeryFees += hipReplacementFee;
				break;
			}
			case THIRD_CHOICE:
			{
				surgeryFees += coronaryBypassFee;
				break;
			}
			case FOURTH_CHOICE:
			{
				surgeryFees += angioplastyFee;
				break;
			}
			case FIFTH_CHOICE:
			{
				surgeryFees += kneeReplacementFee;
				break;
			}
			case SIXTH_CHOICE:
			{
				surgeryFees += kidneyStoneRemovalFee;
				break;
			}
			default:
				break;
		}
	}while(option != EXIT_DECISION);
	
	return surgeryFees;
}


//Calculate and return the pharmacy charges of a patient based on the number of doses of medicine and the number of days taken by a patient
double pharmacyCharges()
{
	double 	medicationFees = 0,
			paracetamolFee = 13.00, //cost per dose
			chlorpheniramineFee = 20.00,
			cetirizineFee = 15.00,
			diphenhydramineFee = 10.00,
			loratadineFee = 11.00,
			diclofenacFee = 19.00;
	
	int option, doses, medDay, cntPharm = 0;
	
	do
	{
		if(cntPharm == 0)
		{
			cout << "Medication Categories\n"
				 << "--------------------------------\n"
				 << "1. Paracetamol\n"
				 << "2. Chlorpheniramine\n"
				 << "3. Cetirizine\n"
				 << "4. Diphenhydramine\n"
				 << "5. Loratadine\n"
				 << "6. Diclofenac\n"
				 << "7. Return to Menu\n"
				 << "--------------------------------\n"
				 << "Please pick an option: ";
			cin >> option;
			cntPharm++;
		}
		else
		{
			cout << "Medication Categories\n"
				 << "--------------------------------\n"
				 << "1. Paracetamol\n"
				 << "2. Chlorpheniramine\n"
				 << "3. Cetirizine\n"
				 << "4. Diphenhydramine\n"
				 << "5. Loratadine\n"
				 << "6. Diclofenac\n"
				 << "7. Return to Menu\n"
				 << "--------------------------------\n"
				 << "Please pick another option (Press 7 to return to menu): ";
			cin >> option;
		}
		
		
	
		while(option < FIRST_CHOICE || option > EXIT_DECISION)
		{
			system("cls");
			cout << "Medication Categories\n"
				 << "--------------------------------\n"
				 << "1. Paracetamol\n"
				 << "2. Chlorpheniramine\n"
				 << "3. Cetirizine\n"
				 << "4. Diphenhydramine\n"
				 << "5. Loratadine\n"
				 << "6. Diclofenac\n"
				 << "7. Return to Menu\n"
				 << "--------------------------------\n"
				 << "Please pick a valid option: ";
			cin >> option;
		}
		
		if(option != EXIT_DECISION)
		{
			cout << "Number of doses of medicine per day taken by the patient: ";
			cin >> doses;
			cout << "Number of days the medicine is taken by the patient: ";
			cin >> medDay;
			cout << endl;
			system("cls");
		}
		else
		{
			system("cls");
		}
		
		switch (option)
		{
			case FIRST_CHOICE:
			{
				medicationFees += (paracetamolFee*doses*medDay);
				break;
			}
			case SECOND_CHOICE:
			{
				medicationFees += (chlorpheniramineFee*doses*medDay);
				break;
			}
			case THIRD_CHOICE:
			{
				medicationFees += (cetirizineFee*doses*medDay);
				break;
			}
			case FOURTH_CHOICE:
			{
				medicationFees += (diphenhydramineFee*doses*medDay);
				break;
			}
			case FIFTH_CHOICE:
			{
				medicationFees += (loratadineFee*doses*medDay);
				break;
			}
			case SIXTH_CHOICE:
			{
				medicationFees += (diclofenacFee*doses*medDay);
				break;
			}
			default:
				break;
		}
	}while(option != EXIT_DECISION);
	
	return medicationFees;
}


//Calculate and return the service charges of a patient for using the services of hospital
double serviceCharges()
{
	int serviceFreq, serviceTypes;
	double 	physioDuration,
			serviceFees = 0,
			xRayFee = 80.00,
			bloodTestFee = 100.00,
			mriFee = 1200.00,
			ctFee = 1000.00,
			physiotherapyFee = 170.00, //Cost of physiotherapy per hour
			vaccinationFee = 70.00;
	
	cout << "How many times has the patient received services: ";
	cin >> serviceFreq;
	cout << endl;
	
	for(int i=1; i <= serviceFreq; i++)
	{
		cout << "Service Categories\n"
		 	 << "--------------------------------\n"
		 	 << "1. X-Ray\n"
			 << "2. Blood Test\n"
			 << "3. MRI Scans\n"
			 << "4. CT Scans\n"
			 << "5. Physiotherapy\n"
			 << "6. Vaccinations\n"
			 << "7. Return to Menu\n"
			 << "--------------------------------\n"
		 	 << "Please pick the service received by the patient on the " << i <<  " time: ";
		cin >> serviceTypes;
		system("cls");
		
		while(serviceTypes < FIRST_CHOICE || serviceTypes > EXIT_DECISION)
		{
			cout << "Service Categories\n"
			 	 << "--------------------------------\n"
		 		 << "1. X-Ray\n"
				 << "2. Blood Test\n"
				 << "3. MRI Scans\n"
				 << "4. CT Scans\n"
				 << "5. Physiotherapy\n"
				 << "6. Vaccinations\n"
				 << "7. Return to Menu\n"
				 << "--------------------------------\n"
				 << "Please pick a valid option: ";
			cin >> serviceTypes;
			system("cls");
		}
		
		switch(serviceTypes)
		{
			case FIRST_CHOICE:
				serviceFees += xRayFee;
				break;
			case SECOND_CHOICE:
				serviceFees += bloodTestFee;
				break;
			case THIRD_CHOICE:
				serviceFees += mriFee;
				break;
			case FOURTH_CHOICE:
				serviceFees += ctFee;
				break;
			case FIFTH_CHOICE:
				cout << "How many hours of physiotherapy received by the patient each time: ";
				cin >> physioDuration;
				serviceFees += (physiotherapyFee * physioDuration);
				cout << endl;
				break;
			case SIXTH_CHOICE:
				serviceFees += vaccinationFee;
				break;
			default:
				break;
		}
	}
	return serviceFees;	
}


//Calculate and return the sum of hospital stays charges, surgery charges, pharmacy charges and other services charges
double patientBill(double hospitalStayCost, double surgeryCost, double pharmacyCost, double serviceCost)
{
	return hospitalStayCost + surgeryCost + pharmacyCost + serviceCost;
}



int main()
{
	int decision;
	const int CHECKOUT = 5;
	
	double 	hospitalStayCost,
			surgeryCost,
			pharmacyCost,
			serviceCost,
			totalCost;
	
	do
	{
		showMenu();
		cout << "Please pick an option: ";
		cin >> decision;
		system("cls");
		
		while(decision > CHECKOUT || decision < FIRST_CHOICE)
		{
			showMenu();
			cout << "Please pick a valid option: ";
			cin >> decision;
			system("cls");
		}
		
		if(decision != CHECKOUT)
		{
			switch (decision)
			{
				case FIRST_CHOICE:
				{
					hospitalStayCost = hospitalStay();
					break;
				}
				case SECOND_CHOICE:
				{
					surgeryCost = surgeryCharges();
					break;
				}
				case THIRD_CHOICE:
				{
					pharmacyCost = pharmacyCharges();
					break;
				}
				case FOURTH_CHOICE:
				{
					serviceCost = serviceCharges();
					break;
				}
				default:
					break;
			}
		}
	}while(decision != CHECKOUT);
	
	totalCost = patientBill(hospitalStayCost, surgeryCost, pharmacyCost, serviceCost);
	cout << fixed << setprecision(2) << "Final Payment: RM" << totalCost << endl; //Display the patient's bills
	cout << "The patient has been checked out" << endl;

	return 0;
}

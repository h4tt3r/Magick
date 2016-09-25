#include <iostream>
#include <string>
#include <limits>
#include <fstream> 
#include <vector> 










//Function that creates pointer ">" Icon...Im lazy. 
void createIcon() { 
	std::cout << "> ";
}




//Function clears cin
void cinClear(void) { 
	using namespace std;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}



enum Gender {
	male, 
	female,
	error
};






enum Race {
	elf,
	human,
	vampire,
	druid, 
	troll, 
	dwarf,
	orc,
	help
};


enum mageMagicTypes { 
	fire,
	water,
	earth,
	air,
	dark,
	light
};


class Spell { 
	public:
		int damage;
		mageMagicTypes type;
		int manaCost;
};



//Defines player class and attributes
class Creature {
	public: 
		//User info
		std::string name;  
		Gender gender;
		
		//Mandatory Stats
		Race race;
		int wisdom;
		int stealth; 
		int agility;
		int speed;
		int health;
		int baseDamage;
		//Attack related
		std::vector<Spell> spells;
		
		
		//Conditional stats
		int vampireBB;
		int magic; 
		int mana; 
		int stamina;
		int manaRegRate;
		int stamRegRate;
		bool isVampire;
};

	

class Player : public Creature { 
	public: 
		enum class CurrentLocation {};
		CurrentLocation currentLocation;

};






int main() {

	
	
	Player user;
	while (true) { 
		//Acquires players first name 
		std::string introOne = "Welcome to The World of Magick\nWhat is your name?\n";
	
		std::cout << introOne;
	
		createIcon();
	
		std::cin >> user.name;
	
		std::string nameConfirm;
	
		std::cout << "Confirm name is " << user.name << "? (Y/N)";
	
		std::cin >> nameConfirm; 
	
		//Confirms user didnt fuck up their name
		if (nameConfirm == "Y" or nameConfirm == "y") {
			break;
		}
		
		else if (nameConfirm == "N" or nameConfirm == "n") { 
			std::cout << "\n";
			continue;
		}	
		else { 
			std::cout << "\nAnswer not valid, try again\n";
			cinClear();
			continue;
		} 
		
		
		
	}
	
	
	
	std::cout << "\nHello " << user.name << ".";
	//While loop to surround gender choice code, so if the user fucks up they can try again 
	while (true) { 
		std::cout << "\nAre you a boy or a girl?\n" 
					"1. Boy | 2. Girl\n" 
					"Choices are selected by typing in a single number\n";
		
		//Asks for players gender 
		int genderSelect;
		createIcon();
		std::cin >> genderSelect;
		
		//Sets gender depending on value entered. 1 being male, 2 being female. 
		switch (genderSelect) { 
			case 1:
				user.gender = male;
				break;
	
			case 2:
				user.gender = female;
				break;
	
			default: 
				std::cout << "\nNot a valid number, try again\n";
				user.gender = error;
					
			}
	
		//If the player entered a valid number, break loop, if not, continue it.
		if(user.gender == male or user.gender == female) {
			break;
		}	 	

		else {
			cinClear();
			continue;
		} 
	

	}
	
	
	
	
	while(true) {
		//Asks players for race. 
		int raceChoose; 
		std::cout << "\nPlease choose a race:\n"
					"1. Elf\n"
					"2. Human\n"
					"3. Vampire\n"
					"4. Druid\n"
					"5. Troll\n"
					"6. Orc\n"
					"7. Dwarf\n"
					"8. Race Info\n";
		
		createIcon();
		std::cin >> raceChoose;			
	
		//Shit ton of writing. 
		
		std::string raceHelpElf = "Elfraces - The elves are an ancient race, older than all except the Dwarf.\n" 
									"They are built on wisdom, and intelligence.\n"
									"Many elves live in the wild, hunting their food with a sharp aim and a quick wit.\n"
									"Elves have mastered the art of the bow, and are stealthier than any race known to Algoria, with the vampire being the only exception\n"
									"Elves are also jovial, light and happy by nature, throwing grand festivals day and night\n\n";
								
		std::string raceHelpHuman = "Human - The humans are the newest race to Algoria.\n"
									"They are known by other races to be greedy and power-hungry.\n"
									"Humans are generally more equipped at fighting disease and poison.\n"
									"The human race has adequate physical strength, but is nothing compared to say, an orc\n"
									"Humans have a unique property of being able to hold more stamina and mana than any other race\n\n";
										
		
		std::string raceHelpVampire = "Vampire - The vampire's origin is shrouded in secret and mystery.\n"
									"They are dark, powerful creatures, that feed on the blood of others to survive.\n"
									"Vampires resemble humans in many ways but they have a few distinct features:\n"
									"1 - Crimson Eyes.\n"
									"2 - Snow white skin\n"
									"3 - Two sharp incisors in the top row of teeth\n"
									"Vampires can infect humans, to transform them into other vampires.\n"
									"To all other races, vampire venom is a deadly poison with no known cure and a 10% survival rate.\n"
									"Vampires are nocturnal creatures, as such they have developed to move quietly, and are the stealthiest race.\n"
									"If they come in contact with the light of the sun, blisters will quickly develop, as wel as nausea and vomiting;\n"
									"even after leaving the sun, these effects can last for hours, this is known as 'Sun Sickness'.\n\n";
									
									
		std::string raceHelpDruid = "Druid - The Druid date back to the very beggining of dark magic.\n"
									"Once a most respected and beloved elven tribe, The Druid leaders began tampering with a dark, twisting power.\n"
									"This power, an ancient black magic, poisoned The Druid, both inside and out.\n"
									"They became obsessed, infatuated with the power it gave them, there skin grew dark like ash, and their eyes as black as pitch.\n"
									"Druids possess a strong magic power, and can deal more damage than any other race with their magic.\n"
									"They have a strong connection with the void, but are also very disconnected from all things of nature, making them insufficent in that regard.\n"
									"Druids worship the void, and the demons that lie within it, this type of worship leads to a weaker will and mental strength\n";
										
										
									

		
	
	
	
		switch(raceChoose) {
		
			case 1:
				user.race = elf;
				break;
			
			case 2:
				user.race = human;
				break;
			
			case 3:
				user.race = vampire;
				break;
			
			case 4: 
				user.race = druid;
				break;
			
			case 5:
				user.race = troll;
				break;
			
			case 6: 		
				user.race = orc;
				break;
		
			case 7:	
				user.race = dwarf;
				break;
					
			//Sets race so it will print help. 
			case 8:
				user.race = help; 
				break;
				
			default: 
				std::cout << "Not a vaild number, try again.\n";
				
		}
		
		
		if(raceChoose >= 1 and raceChoose <= 10 and raceChoose != 8) {
			break;
		}
			
		else if(user.race == help) {
			//Prints out all race help info 
			std::cout << 
			"\n\n" << 
			raceHelpElf <<
			raceHelpHuman <<
			raceHelpVampire <<
			raceHelpDruid; 
			continue; 
				
				
		}
		else { 
			//Clears cin and reruns loop
			using namespace std;
			cinClear();
			continue;
		}
			
		
		
		
		
		
		
	}
	
	
	
	 
	
	


				
	
	
	
} 


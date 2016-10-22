#include <iostream>
#include <string>
#include <limits>
#include <fstream> 
#include <vector>	


//MECHANICS FUNCTIONS 
//Function that creates pointer ">" Icon...Im lazy. 
void createIcon() { 
	std::cout << "> ";
}
void errorMessage() {
	std::cout << "\nNot a valid number, please try again.\n";
	
}
//Function clears cin
void cinClear(void) { 
	using namespace std;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}







//PLAYER RELATED ENUMS
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
	raceHelp
};

enum classType { 
	mage,
	warlock,
	shaman, 
	mecha,
	warrior,
	rouge,
	lightClassHelp,
	darkClassHelp,
	fullClassHelp
};

enum SubClasses { 
	//Mage subclasses
	atherMage,
	voidMage,
	arcaneMage,
	
	//Shaman subclasses
	fireShaman,
	waterShaman,
	earthShaman,
	airShaman,
	
	//Warlock subclasses
	demonWarlock, 
	bloodWarlock, 
	diseaseWarlock,
	
	//Warrior subclasses
	berserkerWarrior,
	lightWarrior, 
	templarWarrior,
	
	//Mecha subclasses
	
	
	
	//Rouge subclasses
	stealthRouge,
	lethalRouge, 
	poisonRouge, 
	
	
	
};


	




//SPELL CLASSES
class damageSpell { 
	public:
		int damage;
		SubClasses type;
		int manaCost;
		std::string spellDescription; 
};

class healingSpell { 
	public:
		int healthAdded; 
		int manaCost;
		SubClasses type;
		std::string spellDescription; 
};









//PLAYER/CREATURE RELATED CLASSES
//Defines player class and attributes
class Creature {
	public: 
		//User info
		std::string name;  
		Gender gender;
		Race race;
		classType classtype;
		SubClasses subclass;
		
		//Mandatory Stats
		int wisdom;
		bool stealth; 
		int agility;
		int speed;
		int health;
		int baseDamage;
		
		
		//Spell Damage
		std::vector<damageSpell> spells;
		
		
		//Conditional stats
		int vampireBloodLevel;
		int magick; 
		int mana; 
		int stamina;
		int manaRegRate;
		int stamRegRate;
		bool isVampire;
};
	
//Class player inherits from creature
class Player : public Creature { 
	

};
Player user;










//PLAYER CLASSES LISTS 
//This is for the entire class list. Note: Only for Vampires and Humans 
void fullClassChoose() {
	
	std::cout << "Please choose a class:\n"
					"1. Mage\n"
					"2. Warlock\n"
					"3. Shaman\n"
					"4. Mecha\n"
					"5. Warrior\n"
					"6. Rouge\n"
					"7. Class Info\n";
};

//This is a dark class list (except for shaman). Note: Only for Druids and Orcs
//Other note: Shaman holds a neutral party.
void darkClassChoose() { 
	std::cout << "Please choose a class:\n"
					"1. Mage\n"
					"2. Warlock\n"
					"3. Shaman\n"
					"4. Rouge\n"
					"5. Class Info\n";
}

//This is a light class list. Note: Only for trolls, elves, and dwarves. 
void lightClassChoose() { 
	std::cout << "Please choose a class:\n"
					"1. Mage\n"
					"2. Shaman\n"
					"3. Mecha\n"
					"4. Warrior\n"
					"5. Class Info\n";
}








//BATTLE MECHANICS
//Checks if the health his above 100, if so, brings health back down to 100
void checkHealthFull() { 
		if(user.health > 100) { 
			int subtractFromHealth = user.health - 100; 
			user.health = user.health - subtractFromHealth; 
		}
}

void displayStats(Creature) { 
		std::cout << "HP: " << user.health << "/100\n";
		if(user.classtype == mage or user.classtype == shaman or user.classtype == mecha or user.classtype == warlock or user.subclass == templarWarrior) {
			std::cout << "Mana: " << user.mana << "/100\n";
		}
		else { 
			std::cout << "Agility: " << user.agility << "/100\n";
		}
		
		std::cout << "Choose which spell/attack you wish to use:\n"
					"1. Damage\n"
					"2. Healing\n"
					"3. Effects\n"
					"4. Items";
		
};










//GAME START 
int main() {
	
	
	

	

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
	
	//This is for choosing gender
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
				errorMessage();
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
	
	
	
	//This code is for choosing a race 
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
		
		std::string raceHelpElf = "Elf - The elves are an ancient race, older than all except the Dwarf.\n"
					"They are found in the Light Forests of Algoria.\n" 
					"They are built on wisdom, and intelligence.\n"
					"Many elves live in the wild, hunting their food with a sharp aim and a quick wit.\n"
					"The elves discovered a magick allowing them to draw energy from the Aether, the Void, or even the Arcane world.\n"
					"They call the users of this magick mages.\n"
					"Elves have mastered the art of the bow.\n"
					"Elves are also jovial, light and happy by nature, throwing grand festivals day and night.\n\n";
								
		std::string raceHelpHuman = "Human - The humans are the newest race to Algoria, and populate the plains in large cities.\n"
									"They are known by other races to be greedy and power-hungry.\n"
									"Humans are generally more equipped at fighting disease and poison.\n"
									"The human race has adequate physical strength, but is nothing compared to say, an orc.\n"
									"Humans have a unique property of being able to hold more stamina and mana than any other race.\n\n";
										
		
		std::string raceHelpVampire = "Vampire - The vampire's origin is shrouded in secret and mystery. These creatures are found in all areas of Algoria.\n"
									"They are dark, powerful creatures, that feed on the blood of others to survive.\n"
									"Vampires resemble humans in many ways but they have a few distinct features:\n"
									"1 - Crimson Eyes.\n"
									"2 - Snow white skin.\n"
									"3 - Two sharp incisors in the top row of teeth.\n"
									"Vampires can infect humans, to transform them into other vampires.\n"
									"To all other races, vampire venom is a deadly poison with no known cure and a 10% survival rate.\n"
									"Vampires are nocturnal creatures, as such they have developed to move quietly, and are the stealthiest race.\n"
									"If they come in contact with the light of the sun, blisters will quickly develop, as well as nausea and vomiting.\n"
									"Even after leaving the sun, these effects can last for hours, this is known as 'Sun Sickness'.\n\n";
									
									
		std::string raceHelpDruid = "Druid - The Druid date back to the very beggining of dark magic, and are found in the Dark Forests of Algoria.\n"
									"Once a most respected and beloved elven tribe, The Druid leaders began tampering with a dark, twisting power.\n"
									"This power, an ancient black magick, poisoned The Druid, both inside and out.\n"
									"They called the users of this magick warlocks.\n"
									"They became obsessed, infatuated with the power it gave them, there skin grew dark like ash, and their eyes as black as pitch.\n"
									"Druids possess a strong magick power, and can deal more damage than any other race with their magick.\n"
									"They have a strong connection with the void, but are also very disconnected from all things of nature, making them insufficent in that regard.\n"
									"Druids worship the void, and the demons that lie within it, this type of worship leads to a weaker will and mental strength.\n\n";
										
										
									
		std::string raceHelpTroll = "Troll - The trolls are an olden race, found in the jungles of Algoria.\n"
									"The trolls live in large tribes, living as hunter gatherers.\n"
									"Trolls developed a magick centered purely on that of nature, calling the practicers Shaman.\n"
									"Trolls are large beings, with skin as green as emerald.\n" 
									"They are naturally more enduring, being able to take more damage than any race.\n"
									"Trolls are very strong, and resort to using their hands or large clubs or staves as weapons.\n\n";
		
		
		
		std::string raceHelpOrc = "Orc - The orcs are a younger race, found in the tundras and taigas of Algoria.\n"
					"These creatures were once trolls, shamans, who practiced a darker form of the art.\n"
					"This magick allowed them to be stealthy, to dissapear into the shadows, and to make even a single strike lethal.\n"
					"This magick allowed orcs to be the deadliest asssassin, and the practicers of it were called Rouges.\n"
					"Orcs are strong, but brutal in their ways. Punishment for breaking laws in their societies are harsh, and often times fatal.\n\n";
	
	
	
		std::string raceHelpDwarf = "Dwarf - The dwarves are the oldest race in all of Algoria. This race is found in the icy plains of Desren.\n"
								"Dwarves do not live in castles, nor tents, but under the earth, in tunnels and colonies, dug by their very own hands.\n"
								"The Dwarves use a form of magick of their own, calling the users of it the Mecha.\n"
								"Dwarf magic is used to shape metal, bend it to their will, to build elaborate machines out of raw stone and steel.\n"
								"The Dwarves tend to be prejudice against other races, humans and elves in particular. They are set on handling affairs strictly internally.\n\n"; 
	
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
				user.race = raceHelp; 
				break;
				
			default: 
				errorMessage();
				
		}
		
		
		if(raceChoose >= 1 and raceChoose <= 10 and raceChoose != 8) {
			break;
		}
			
		else if(user.race == raceHelp) {
			//Prints out all race help info 
			std::cout << 
			"\n\n" << 
			raceHelpElf <<
			raceHelpHuman <<
			raceHelpVampire <<
			raceHelpDruid <<
			raceHelpTroll << 
			raceHelpOrc <<
			raceHelpDwarf; 
			continue; 
				
				
		}
		else { 
			//Clears cin and reruns loop
			using namespace std;
			cinClear();
			continue;
		}
				
	}
	
	//This code is for choosing a class
	while(true) {
		
		//The following code will determine which class list was displayed, as to make switch/case statements easier.
		//It will set up an enum value as darkList, lightList, or fullList, then use those to determine which list was displayed.
		enum classLists  { 
			darkList,
			lightList, 
			fullList
		};
		
		classLists displayedList;
		
		//Decides what class list will be displayed based on players chosen race. 
		int classChoose;
		 if(user.race == human or user.race == vampire) { 
			 std::cout << "\n\n";
			 fullClassChoose();
			 displayedList = fullList;
		 }
		 else if(user.race == druid or user.race == orc) { 
			 std::cout << "\n\n";
			 darkClassChoose();
			 displayedList = darkList;
		 }
		 else if(user.race == dwarf or user.race == troll or user.race == elf) { 
			 std::cout << "\n\n";
			 lightClassChoose();
			 displayedList = lightList;
			 
		 }
		 
		 //Asks for class
		 createIcon();
		 std::cin >> classChoose;
		 
		 
		 //Displays full list of classes 
		if(displayedList == fullList) { 
			switch(classChoose) { 
				case 1: 
					user.classtype = mage;
					
				case 2:
					user.classtype = warlock;
					break;
					
				case 3: 
					user.classtype = shaman; 
					break;
					
				case 4:
					user.classtype = mecha; 
					break;
					
				case 5: 
					user.classtype = warrior;
					break;
					
				case 6: 
					user.classtype = rouge;
					break;
				
				case 7:
					user.classtype = fullClassHelp;
					break;
					
				default:
					errorMessage();
					
			}
		}
		//Sets class if the displayedList is the dark class list 
		else if(displayedList == darkList) {
		
			switch(classChoose) {
				case 1: 
					user.classtype = mage; 
					break;
			
				case 2: 
					user.classtype = warlock;
					break;
			
				case 3:
					user.classtype = shaman;
					break;
			
				case 4: 
					user.classtype = rouge;
					break; 
				
				case 5:
					user.classtype = darkClassHelp;
					break;
				
				default: 
					errorMessage();
					
			}
		}
		
		//Sets class if the light class list was displayed
		else if(displayedList == lightList) { 
			
			switch(classChoose)  {
				
				case 1:
					user.classtype = mage;
					break;
				
				case 2:
					user.classtype = shaman; 
					break;
				
				case 3: 
					user.classtype = mecha; 
					break;
					
				case 4: 
					user.classtype = warrior;
					break;
				
				case 5: 
					user.classtype = lightClassHelp;
					break;
				default:
					errorMessage();	
			}
		}
			
			
		
		std::string classHelpMage = "Mage - Mages draw their magick from one of the three celestial worlds; these worlds include:\n"
									"The Aether - Very little is known about this realm, it is the place where light mages draw their energy.\n"
									"The Void - This place contains the demons of Algoria, and can be reached in dreams. This is the world in which dark mages draw their energy.\n"
									"The Arcane World - Called 'The Invisible World' by many. Exists as a realm that lives under the surface of ours, filled with its own beings and powers.\n"
									"\nThis is where arcane mages draw their power.\n"
									"Mages use raw energy from these worlds, and use discipline and intelligence to master their art.\n\n"; 
		
		std::string classHelpShaman = "Shaman - Shaman draw their magick from the elements of Algoria.\n"
										"The elements used by Shaman are Earth, Water, Fire, and Air.\n"
										"Shaman respect nature, and believe it should be protected at all costs.\n"
										"Shamans magick can be beautiful, but if placed in the wrong hands, can easily spread out of control, and become dangerous.\n"; 
		
		std::string classHelpWarlock = "Warlock - Warlock magick is the darkest form of arts, drawing their energy from the beings of the void, demons.\n"
										"A warlock's magick is used to harm and delude, and there are several specializations of warlock magick. \n"
										"Warlocks magick cannot be used to heal by normal means, and must use life force from others to heal or help.\n"
										"To cast spells, warlocks use magick drawn from demons of the void to create energy.\n";
		
		std::string classHelpMecha = "Mecha -";
		
		std::string classHelpRouge = "Rouge - Rogues are a kindred group of thieves and assassins, bound by blood to fulfill bounties. They utilize trinkets and gadgets to conceal themselves or their weapon of choice.\n"
										"Rouges are broken down into three sub-sets, where they utilize different ways to quietly slaughter.\n"
										"Poison - These rogues prioritize in the art of alchemy, using poisons to weaken foes or leave them to perish.\n"
										"Stealth - This sub-set brandishes daggers and other concealable blades, prefering to strike clean and unseen.\n"
										"Lethal - Lethal rogues are stockier and beefier, crippling their foes by shattering their pressure points.\n"; 
		
		std::string classHelpWarrior = "Warrior - Warriors are the stock of any militarized nation within Algoria. Untimid, they stride into battle, brash to bash their foes.\n"
										"Warriors commonly classify themselves within a certain culture or race, thus determining their balances in warfare.\n"
										"Berserker - Berserker warriors bear heavy-metal armors, they use large weapons, long swords and the like. They can tap into a fiery rage, allowing them to become deadly killing machines.\n"
										"Light - Light warriors skirmish behind berserkers, and wield finely tempered blades and small maces. They focus in dealing damage, not taking it.\n"
										"Templar - Templars are zealous scholars, they use techniques passed down for ages to neutralize and drain magic. After doing this, they can swiftly kill their magic using enemies.\n";
			
			//Decides whether to break or continue loop based on input for players using the full list
			if (displayedList == fullList) { 
				
				if (classChoose <= 4 and classChoose > 0) { 
					break;
				}
				
				else if (classChoose == 7) { 
					std::cout << classHelpMage 
							<< classHelpShaman
							<< classHelpWarlock
							<< classHelpMecha
							<< classHelpRouge 
							<< classHelpWarrior;
				}
				
				else {
					cinClear();
					continue;
				}
			}
			
			//Decides whether to break or continue loop based on input for players using the light list  
			if (displayedList == lightList) { 
				
				if (classChoose >= 1 and classChoose <= 4 and classChoose !=5) { 
					break;
				}
				
				else if (classChoose == 5) { 
					std::cout << classHelpMage 
							<< classHelpShaman
							<< classHelpMecha
							<< classHelpWarrior;
				}
				
				else {
					cinClear();
					continue;
				}
			}
			
			//Decides whether to break or continue loop based on input for players using the dark list 
			if (displayedList == darkList) { 
				
				if (classChoose <= 4 and classChoose > 0) { 
					break;
				}
				
				else if (classChoose == 5) { 
					std::cout << classHelpMage 
							<< classHelpShaman
							<< classHelpWarlock
							<< classHelpRouge;
				}
				
				else {
					cinClear();
					continue;
				}
			}
		}
		
		
		
		
		switch(user.classtype) { 
			
		case mage: 
			while(true) { 
				
			}
			break;
			
		
		case shaman: 
			while(true) { 
			
			}
			break;
			
		case warlock: 
			while(true) { 
			
			}
			break;
			
		case mecha: 
			while(true) {
			
			}
			break;
		
		case rouge:
			while(true) {
			
			}
			break;
		
		case warrior: 
			while(true) { 
	
			}
			break;
		
		
			
		}
		
		
		
		
		
		
}
*/

#include <iostream>
#include <string>
#include <limits>
#include <fstream> 
#include <vector>	
#include <ctime> 
#include <unistd.h>
#include <cstdlib>
 


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
	rogue,
	lightClassHelp,
	darkClassHelp,
	fullClassHelp
};

enum SubClasses { 
	//Mage subclasses
	aetherMage,
	voidMage,
	arcaneMage,
	mageHelp,
	
	//Shaman subclasses
	fireShaman,
	waterShaman,
	earthShaman,
	airShaman,
	shamanHelp,
	//Warlock subclasses
	demonWarlock, 
	bloodWarlock, 
	diseaseWarlock,
	warlockHelp,
	//Warrior subclasses
	berserkerWarrior,
	lightWarrior, 
	templarWarrior,
	warriorHelp,
	//Mecha subclasses
	
	
	
	//Rouge subclasses
	stealthRouge,
	lethalRouge, 
	poisonRouge, 
	rogueHelp
	
	
};






//SPELL CLASSES
class damageSpell { 
	public:
		int damage;
		SubClasses type;
		int manaCost;
		std::string spellDescription; 
		std::string spellName;
};

class healingSpell { 
	public:
		int healthAdded; 
		int manaCost;
		SubClasses type;
		std::string spellDescription; 
		std::string spellName;
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
		bool alive;
		
		//Mandatory Stats
		int wisdom;
		bool stealth; 
		int agility;
		int speed;
		int health;
		int baseDamage;
		int experience;
		int rall;
		int healthFromArmor;
		int defaultHealth;
		
		
		//Non Player Stats
		int experienceAwarded;
		int rallAwarded;
		
		//Spell Damage
		std::vector<damageSpell> damageSpells;
		std::vector<healingSpell> healingSpells;
		
		//Conditional stats
		int vampireBloodLevel;
		int magick; 
		int mana; 
		int stamina;
		int manaRegRate;
		int stamRegRate;
		bool isVampire;
};
	

Creature user;










//PLAYER CLASSES LISTS 
//This is for the entire class list. Note: Only for Vampires and Humans 
void fullClassChoose() {
	
	std::cout << "Please choose a class:\n"
				"Classes are your characters skill set.\nThey will determine your spell casting throughout the game.\n"
					"1 - Mage\n"
					"2 - Warlock\n"
					"3 - Shaman\n"
					"4 - Mecha\n"
					"5 - Warrior\n"
					"6 - Rouge\n"
					"7 - Class Info\n";
};

//This is a dark class list (except for shaman). Note: Only for Druids and Orcs
//Other note: Shaman holds a neutral party.
void darkClassChoose() { 
	std::cout << "Please choose a class:\n"
				"Classes are your characters skill set.\nThey will determine your spell casting throughout the game.\n"
					"1 - Mage\n"
					"2 - Warlock\n"
					"3 - Shaman\n"
					"4 - Rouge\n"
					"5 - Class Info\n";
}

//This is a light class list. Note: Only for trolls, elves, and dwarves. 
void lightClassChoose() { 
	std::cout << "Please choose a class:\n"
				"Classes are your characters skill set.\nThey will determine your spell casting throughout the game.\n"
					"1 - Mage\n"
					"2 - Shaman\n"
					"3 - Mecha\n"
					"4 - Warrior\n"
					"5 - Class Info\n";
}





//BATTLE MECHANICS
std::ostream &operator<<(std::ostream& stream, const damageSpell& damageSpellToPrint)
{
	stream << damageSpellToPrint.spellName; 
	return stream;
	

};





//YOU ARE NOT EXPECTED TO UNDERSTAND THIS
//Literally all of the players fight mechanics
void playerFightMechanics(Creature creature) { 
	std::cout << "You are fighting " << creature.name << ".\n";
	std::cout << "Her HP is " << creature.health << "!\n";
	bool noMana;
				
			
		
			bool healthSpellChecker;
			int firstTurnChecker = 1;
			bool runAttackMenuAgain = false; 
			while(true) { 
				
				//Add 10 to mana every turn, if there is more than 100 mana, make it 100
				if(noMana == false) { 	
					user.mana = user.mana + 10;
				}
				
				
				
				
					
				//Random stats for conditionals.
				bool fightErrorMessage;
				bool playerAlive; 
				
				//Messages for beating creature
				if(creature.health <= 0) { 
					sleep(1);
					std::cout << "\nYou have slain " << creature.name << "!\n";
					
					sleep(1);
					std::cout << "\nXP Awarded: " << creature.experienceAwarded << "\n\n";
					user.experience = user.experience + creature.experienceAwarded;
					sleep(1);
					std::cout << "Rall Awarded: " << creature.rallAwarded << "\n\n";
					user.rall = user.rall + user.rallAwarded;
					break;
				}
				
				
			//Randomizes creatures attacks. 	
			if(firstTurnChecker > 1 and runAttackMenuAgain == false and playerAlive == true and fightErrorMessage == false and healthSpellChecker == false) { 
				int randomNumber;
				srand( time(0));
				randomNumber = rand() % 3 + 1;
				if(randomNumber == 1) { 
					sleep(1);
					user.health = user.health - creature.damageSpells.at(0).damage;
					std::string currentSpell = creature.damageSpells.at(0).spellName;
					sleep(1);
					std::cout  << creature.name << " uses " << currentSpell << "\n";
					sleep(1);
					std::cout << "It does " << creature.damageSpells.at(0).damage << " points of damage!\n\n";
					sleep(1);
					
				}
				else if(randomNumber == 2) { 
					sleep(1);
					user.health = user.health - creature.damageSpells.at(1).damage;
					std::string currentSpell = creature.damageSpells.at(1).spellName;
					sleep(1);
					std::cout  << creature.name << " uses " << currentSpell << "\n";
					sleep(1);
					std::cout << "It does " << creature.damageSpells.at(1).damage << " points of damage!\n\n";
					sleep(1);
				}
				else if(randomNumber == 3) { 
					sleep(1);
					user.health = user.health - creature.damageSpells.at(2).damage;
					std::string currentSpell = creature.damageSpells.at(2).spellName;
					sleep(1);
					std::cout  << creature.name << " uses " << currentSpell << "\n";
					sleep(1);
					std::cout << "It does " << creature.damageSpells.at(2).damage << " points of damage!\n\n";
					sleep(1);
					
				}
			}
			
			//Displays death message and restarts battle
			if(user.health < 0) { 
					sleep(2);
					std::cout << "\n\nYou Have Died.\n\n";
					sleep(2);
					std::cout << "Restarting Battle...\n\n\n";
					sleep(2);
					user.health = user.defaultHealth;
					user.mana = 100;
					creature.health = creature.defaultHealth;
					playerAlive = false; 
					continue;
				}
			//More conditional variables
			firstTurnChecker++; 
			fightErrorMessage = false;
			runAttackMenuAgain = false;
			playerAlive = true;
			healthSpellChecker = false;
			
			noMana = false;
			
			//Displays User Health and Mana 
			std::cout << "Your HP: " << user.health << "/" << user.defaultHealth << "\n";
			if(user.classtype == mage or user.classtype == shaman or user.classtype == mecha or user.classtype == warlock or user.subclass == templarWarrior) {
				std::cout << "Your Mana: " << user.mana << "/100\n";
			}
			else { 
				std::cout << "Agility: " << user.agility << "/100\n";
			}
		
		
			//Lets the choose which type of attack/healing thing they want
			
			
				std::cout << "Choose which spell/attack you wish to use:\n"
							"1 - Damage\n"
							"2 - Healing\n"
							"3 - Items\n"
							"4 - Misc\n";
				
				int chooseAttackType; 
				createIcon();
				std::cin >> chooseAttackType; 
				
				//Activates spell chooser based on previous answer
				switch(chooseAttackType) { 
					//CHOOSEATTACKTYPE CASE 1 BEGIN
					case 1: 
						//Displays all damage spells in players arsenal
						std::cout << "Choose a damage spell:\n";
						std::cout << "1 - " << user.damageSpells.at(0).spellName << " " << user.damageSpells.at(0).spellDescription;
						std::cout << "\n";
						std::cout << "2 - " << user.damageSpells.at(1).spellName << " " << user.damageSpells.at(1).spellDescription;
						std::cout << "\n";
						std::cout << "3 - " << user.damageSpells.at(2).spellName << " " << user.damageSpells.at(2).spellDescription;
						std::cout << "\n";
						std::cout << "4 - " << user.damageSpells.at(3).spellName << " " << user.damageSpells.at(3).spellDescription;
						std::cout << "\n";
						std::cout << "5 - " << user.damageSpells.at(4).spellName << " " << user.damageSpells.at(4).spellDescription;
						std::cout << "\n";
						std::cout << "6 - Pass";
						std::cout << "\n";
						std::cout << "7 - Go Back To Main Combat Menu\n";
						createIcon();
						int damageSpellChooser; 
						std::cin >> damageSpellChooser; 
					
						//Casts spell
						switch(damageSpellChooser) { 
							case 1:
								if(user.mana < user.damageSpells.at(0).manaCost) { 
									std::cout << "\nYou Do Not Have Enough Mana!\n";
									runAttackMenuAgain = true;
									bool noMana = true;
									break;
								}
								creature.health =  creature.health - user.damageSpells.at(0).damage;
								sleep(1);
								std::cout << "You use " << user.damageSpells.at(0).spellName << "\n";
								sleep(1);
								std::cout << "Your attack does " << user.damageSpells.at(0).damage << " points of damage\n";
								sleep(1);
								std::cout << creature.name << "'s HP is now at " << creature.health << "!\n";
								user.mana = user.mana - user.damageSpells.at(0).manaCost; 
								break;
							case 2: 
								if(user.mana < user.damageSpells.at(1).manaCost) { 
									std::cout << "\nYou Do Not Have Enough Mana!\n";
									runAttackMenuAgain = true;
									bool noMana = true;
									break;
								}
								creature.health =  creature.health - user.damageSpells.at(1).damage;
								sleep(1);
								std::cout << "You use " << user.damageSpells.at(1).spellName << "\n";
								sleep(1);
								std::cout << "\nYour attack does " << user.damageSpells.at(1).damage << " points of damage\n";
								sleep(1);
								std::cout << creature.name << "'s HP is now at " << creature.health << "!\n\n";
							
								user.mana = user.mana - user.damageSpells.at(1).manaCost; 
								break;
							case 3:
								if(user.mana < user.damageSpells.at(2).manaCost) { 
										std::cout << "\nYou Do Not Have Enough Mana!\n";
										runAttackMenuAgain = true;
										bool noMana = true;
										break;
									}
								creature.health =  creature.health - user.damageSpells.at(2).damage;
								sleep(1);
								std::cout << "You use " << user.damageSpells.at(2).spellName << "\n" ;
								sleep(1);
								std::cout << "\nYour attack does " << user.damageSpells.at(2).damage << " points of damage\n";
								sleep(1);
								std::cout << creature.name << "'s HP is now at " << creature.health << "!\n\n";
								user.mana = user.mana - user.damageSpells.at(2).manaCost; 
								break;
							case 4: 
								if(user.mana < user.damageSpells.at(3).manaCost) { 
										std::cout << "\nYou Do Not Have Enough Mana!\n";
										runAttackMenuAgain = true;
										noMana = true;
										break;
									}	
								creature.health =  creature.health - user.damageSpells.at(3).damage;
								sleep(1);
								std::cout << "You use " << user.damageSpells.at(3).spellName << "\n";
								sleep(1);
								std::cout << "\nYour attack does " << user.damageSpells.at(3).damage << " points of damage\n";
								sleep(1);
								std::cout << creature.name << "'s HP is now at " << creature.health << "!\n\n";
								user.mana = user.mana - user.damageSpells.at(3).manaCost; 
								break;
							case 5: 
									if(user.mana < user.damageSpells.at(4).manaCost) { 
										std::cout << "\nYou Do Not Have Enough Mana!\n";
										runAttackMenuAgain = true;
										noMana = true;
										break;
									}
								creature.health =  creature.health - user.damageSpells.at(4).damage;
								sleep(1);
								std::cout << "You use " << user.damageSpells.at(4).spellName << "\n" ;
								sleep(1);
								std::cout << "\nYour attack does " << user.damageSpells.at(4).damage << " points of damage\n";
								sleep(1);
								std::cout << creature.name << "'s HP is now at " << creature.health << "!\n\n";
								user.mana = user.mana - user.damageSpells.at(4).manaCost; 
								break;
							case 6:
								//Pass
								continue;
							case 7:
								//Returns to menu
								runAttackMenuAgain = true;
								continue;
							default: 
								//Error
								errorMessage();
								runAttackMenuAgain = true;
								
					}
					
					if(runAttackMenuAgain == false) { 
						
						break;
					}
					else if(runAttackMenuAgain == true) {
						cinClear();
						continue;
					}
					
					//CASE 1 END
				
				//CASE 2 BEGIN
				case 2:
					if(user.classtype == mage and user.subclass == aetherMage) { 
						std::cout << "1 - " << user.healingSpells.at(0).spellName << "\n";
						std::cout << "2 - " << user.healingSpells.at(1).spellName << "\n";
						std::cout << "3 - " << user.healingSpells.at(2).spellName << "\n";
						
						int chooseHealingSpellLightMage;
						createIcon();
						std::cin >> chooseHealingSpellLightMage;
					 
						switch(chooseHealingSpellLightMage) { 
							case 1:
								if(user.mana < user.damageSpells.at(1).manaCost) { 
									std::cout << "\nYou Do Not Have Enough Mana!\n";
									runAttackMenuAgain = true;
									bool noMana = true;
									
									break;
								}
								sleep(1);
								std::cout << "\nYou use " << user.healingSpells.at(0).spellName << "\n";
								user.health = user.health + user.healingSpells.at(0).healthAdded;
								user.mana = user.mana - user.healingSpells.at(2).manaCost;
								if(user.health > user.defaultHealth) { 
									int decreaseHealth;
									decreaseHealth = user.health - user.defaultHealth;
									user.health = user.health - decreaseHealth;
								}
								sleep(1);
								std::cout << "Your HP is now " << user.health << "!\n";
								healthSpellChecker = true;
								break; 
								
							case 2: 
								if(user.mana < user.damageSpells.at(1).manaCost) { 
									std::cout << "\nYou Do Not Have Enough Mana!\n";
									runAttackMenuAgain = true;
									bool noMana = true;
									break;
								}
								sleep(1);
								std::cout << "\nYou use " << user.healingSpells.at(1).spellName << "\n";
								user.health = user.health + user.healingSpells.at(1).healthAdded;
								user.mana = user.mana - user.healingSpells.at(2).manaCost;
								if(user.health > user.defaultHealth) { 
									int decreaseHealth;
									decreaseHealth = user.health - user.defaultHealth;
									user.health = user.health - decreaseHealth;
								}
								sleep(1);
								std::cout << "Your HP is now " << user.health << "!\n";
								healthSpellChecker = true;
								break;
							
							case 3: 
								if(user.mana < user.damageSpells.at(1).manaCost) { 
										std::cout << "\nYou Do Not Have Enough Mana!\n";
										runAttackMenuAgain = true;
										break;
									}
								sleep(1);
								std::cout << "\nYou use " << user.healingSpells.at(2).spellName << "\n";
								user.health = user.health + user.healingSpells.at(2).healthAdded;
								user.mana = user.mana - user.healingSpells.at(2).manaCost;
								if(user.health > user.defaultHealth) { 
									int decreaseHealth;
									decreaseHealth = user.health - user.defaultHealth;
									user.health = user.health - decreaseHealth;
								}
								sleep(1);
								std::cout << "Your HP is now " << user.health << "!\n";
								healthSpellChecker = true;
								break;
						 
						 
						}
						
					}
					
					else if(user.classtype == warlock) { 
						std::cout << "1 - " <<  user.healingSpells.at(0).spellName << "\n";
						std::cout << "2 - " << user.healingSpells.at(1).spellName << "\n"; 
						std::cout << "3 - " << user.healingSpells.at(2).spellName << "\n";
						
						
						
						
					}
					break;
					
					//CASE 2 END
			
				case 3:
			
					break;
				
				case 4:
				
					break;
				
				default: 
					errorMessage();
					cinClear();
					fightErrorMessage = true;
					
					continue;
				
				}
				continue;
				
				
				
			}
}	
		

//GAME START 
int main() {

	
	


	while (true) { 
		//Acquires players first name 
		std::string introOne = "Welcome to The World of Magick\n" 
								"Magick is a world filled with adventure, danger, both light and dark.\n"
								"It has chosen you, child, to enter its depths.\n"
								"What is your name?\n";
								
	
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
					"1 - Boy | 2 - Girl\n" 
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
					"Races are the species of your character\nThey will determine your starting point and many other game factors.\n"
					"1 - Elf\n"
					"2 - Human\n"
					"3 - Vampire\n"
					"4 - Druid\n"
					"5 - Troll\n"
					"6 - Orc\n"
					"7 - Dwarf\n"
					"8 - Race Info\n";
		
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
					"This magick allowed orcs to be the deadliest asssassin, and the practicers of it were called Rogues.\n"
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
					break
					
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
					user.classtype = rogue;
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
					user.classtype = rogue;
					break; 
				
				case 5:
					user.classtype = darkClassHelp;
					break;
				
				default: 
					errorMessage();
					
			}
			break;
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
			break;
			
		}
			
			
		
		std::string classHelpMage = "Mage - Mages draw their magick from one of the three celestial worlds; these worlds include:\n\n"
									"The Aether - Very little is known about this realm, it is the place where light mages draw their energy.\n\n"
									"The Void - This place contains the demons of Algoria, and can be reached in dreams.\nThis is the world in which dark mages draw their energy.\n\n"
									"The Arcane World - Called 'The Invisible World' by many.\nExists as a realm that lives under the surface of ours, filled with its own beings and powers.\n"
									"This is where arcane mages draw their power.\n\n"
									"Mages use raw energy from these worlds, as well as discipline and intelligence to master their art.\n\n"; 
		
		std::string classHelpShaman = "Shaman - Shaman draw their magick from the elements of Algoria.\n"
										"The elements used by Shaman are Earth, Water, Fire, and Air.\n"
										"Shaman respect nature, and believe it should be protected at all costs.\n"
										"Shamans magick can be beautiful, but if placed in the wrong hands, can easily spread out of control, and become dangerous.\n\n"; 
		
		std::string classHelpWarlock = "Warlock - Warlock magick is the darkest form of arts, drawing their energy from the beings of the void, demons.\n"
										"A warlock's magick is used to harm and delude, and there are several specializations of warlock magick. \n"
										"Warlocks magick cannot be used to heal by normal means, and must use life force from others to heal or help.\n"
										"To cast spells, warlocks use magick drawn from demons of the void to create energy.\n\n";
		
		std::string classHelpMecha = "Mecha - The Mecha are the mot mysterious magick users in all of Algoria\n"
									"The Mecha draw energy from a place that they themselves no nothing of, deemed the Metrus by its users.\n"
									"These magick users can forge living metal, minions to serve and fight for them, machine to protect them, armor to last the ages.\n"
									"This magick was specific to the dwarves for many centuries.\n"
									"The elven race attacked their capital, Dulor, stealing many secrets, including that of the Mecha.\n\n";
									
		
		std::string classHelpRogue = "Rogue - Rogues are a kindred group of thieves and assassins.\nBound by blood to fulfill bounties.\n"
									"They utilize trinkets and gadgets to conceal themselves or their weapon of choice.\n\n";
										
		
		std::string classHelpWarrior = "Warrior - Warriors are the stock of any militarized nation within Algoria.\nUntimid, they stride into battle, brash to bash their foes.\n"
										"Warriors commonly classify themselves within a certain culture or race, thus determining their balances in warfare.\n\n";
										
			
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
							<< classHelpRogue 
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
							<< classHelpWarrior
							<< classHelpRogue;
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
							<< classHelpRogue;
				}
				
				else {
					cinClear();
					continue;
				}
			}
		}
		
		
		std::string warriorSubClassHelp = "WARRIOR:"
										"Warriors are broken down into three sub-sets, where they use offensive and defensive maneuvers to destroy their enemies "
										"Berserker - Berserker warriors bear heavy-metal armors, they use large weapons, long swords and the like.\nThey can tap into a fiery rage, allowing them to become deadly killing machines.\n\n"
										"Light - Light warriors skirmish behind berserkers, and wield finely tempered blades and small maces.\nThey focus in dealing damage, not taking it.\n\n"
										"Templar - Templars are zealous scholars, they use techniques passed down for ages to neutralize and drain magic.\nAfter doing this, they can swiftly kill their magic-using enemies.\n\n";
										
										
		std::string rogueSubClassHelp = "ROGUE:"
										"Rogues are broken down into three sub-sets, where they utilize different ways to quietly slaughter.\n\n"
										"Poison - These rogues prioritize in the art of alchemy, using poisons to weaken foes or leave them to perish.\n\n"
										"Stealth - This sub-set brandishes daggers and other concealable blades, prefering to strike clean and unseen.\n\n"
										"Lethal - Lethal rogues are stockier and beefier, crippling their foes by shattering their pressure points.\n\n"; 
										
		
		std::string mageSubClassHelp = "";
		
		std::string shamanSubClassHelp = "";
		
		std::string warlockSubClassHelp = "";
		
		switch(user.classtype) { 
		while(true) { 
			case mage: 
				while(true) { 
					std::cout << "\nPlease choose a subclass for the class: Mage.\n";
					std::cout << "Subclasses are specifications for each class.\nThey will determine your attacks and spells.\n";
					std::cout <<  "1 - Aether Mage\n" << 
								"2 - Void Mage\n" << 
								"3 - Arcane Mage\n" << 
								"4 - Subclass Info\n"; 
								int chooseSubClassMage;
								createIcon();
								std::cin >> chooseSubClassMage;
								switch(chooseSubClassMage) { 
									case 1: 
										user.subclass = aetherMage;
										break;
									case 2: 
										user.subclass = voidMage;
										break;
									case 3: 
										user.subclass = arcaneMage;
										break;
									case 4:
										std::cout << mageSubClassHelp;
										
								
									default: 
										user.subclass = mageHelp;
										errorMessage();
										cinClear();
										break;
								if(user.subclass == mageHelp) {
									continue;
								}
								break;
							
							
								}
					}	
				break;
			
		
			case warlock: 
				while(true) { 
					std::cout << "\nPlease choose a subclass for the class: Warlock.\n";
					std::cout << "Subclasses are specifications for each class.\nThey will determine your attacks and spells.\n";
					std::cout << "1 - Demon Warlock\n" << 
								"2 - Blood Warlock\n" << 
								"3 - Poison Warlock\n" << 
								"4 - Subclass Info\n";
								int chooseSubClassMage;
								createIcon();
								std::cin >> chooseSubClassMage;
								switch(chooseSubClassMage) { 
									case 1: 
										user.subclass = demonWarlock;
										break;
									case 2: 
										user.subclass = bloodWarlock;
										break;
									case 3:
										user.subclass = diseaseWarlock;
										break;
									case 4:
										std::cout << warlockSubClassHelp;
										
								
									default: 
										user.subclass = warlockHelp;
										errorMessage();
										cinClear();
										break;
								if(user.subclass == warlockHelp) {
									continue;
								}
								break;
							
							
								}
					}	
				break;
			
			
			
			
			case shaman: 
				while(true) { 
					std::cout << "\nPlease choose a subclass for the class: Shaman.\n";
					std::cout << "Subclasses are specifications for each class.\nThey will determine your attacks and spells.\n";
					std::cout <<  "1 - Earth Shaman\n" << 
								"2 - Fire Shaman\n" << 
								"3 - Water Shaman\n" << 
								"4 - Air Shaman\n" << 
								"5 - Subclass Info\n"; 
								int chooseSubClassShaman;
								createIcon();
								std::cin >> chooseSubClassShaman;
								switch(chooseSubClassShaman) { 
									case 1: 
										user.subclass = earthShaman;
										break;
									case 2: 
										user.subclass = waterShaman;
										break;
									case 3: 
										user.subclass = fireShaman;
										break;
									case 4:
										user.subclass = airShaman;
										break;
									case 5:
										std::cout << shamanSubClassHelp;
										
								
									default: 
										user.subclass = shamanHelp;
										errorMessage();
										cinClear();
										break;
								if(user.subclass == shamanHelp) {
									continue;
								}
								break;
							
							
								}
					}	
				break;
			
			case mecha: 
				while(true) {
			
				}
				break;
		
			case rogue:
				while(true) {
			
				}
				break;
		
			case warrior: 
				while(true) { 
		
				}
			case lightClassHelp:
				break;
			
			case darkClassHelp:
				break;
				
			case fullClassHelp:
				break;
		}
		break;
		
		
		
		
		
		}
}





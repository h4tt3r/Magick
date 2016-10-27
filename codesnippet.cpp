#include <iostream>
#include <string>
#include <limits>
#include <fstream> 
#include <vector>	
#include <ctime> 
#include <windows.h>
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
		
		
		//Non Player Stats
		int experienceGained;
		int defaultHealth;
		
		
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
				"Classes are your characters skill set, and will determine your spell casting throughout the game.\n"
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
				"Classes are your characters skill set, and will determine your spell casting throughout the game.\n"
					"1. Mage\n"
					"2. Warlock\n"
					"3. Shaman\n"
					"4. Rouge\n"
					"5. Class Info\n";
}

//This is a light class list. Note: Only for trolls, elves, and dwarves. 
void lightClassChoose() { 
	std::cout << "Please choose a class:\n"
				"Classes are your characters skill set, and will determine your spell casting throughout the game.\n"
					"1. Mage\n"
					"2. Shaman\n"
					"3. Mecha\n"
					"4. Warrior\n"
					"5. Class Info\n";
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
	std::cout << "Its HP is " << creature.health << "!\n";
		
				
			
		
		
			int firstTurnChecker = 1;
			bool runAttackMenuAgain = false; 
			while(true) { 
				
				//Add 10 to mana every turn, if there is more than 100 mana, make it 100
				user.mana = user.mana + 10;
				if(user.mana > 100) { 
					
					int manaFiller = user.mana - 100;
					user.mana = user.mana - manaFiller;
					
				}
				
				
					
				//Random stats for conditionals.
				bool fightErrorMessage;
				bool playerAlive; 
				
				//Messages for beating creature
				if(creature.health <= 0) { 
					std::cout << "You have slain " << creature.name << "!\n";
					std::cout << "XP Awarded: " << creature.experienceGained << "\n";
					break;
				}
				
				
			//Randomizes creatures attacks. 	
			if(firstTurnChecker > 1 and runAttackMenuAgain == false and playerAlive == true and fightErrorMessage == false) { 
				int randomNumber;
				srand( time(0));
				randomNumber = rand() % 3 + 1;
				if(randomNumber == 1) { 
					user.health = user.health - creature.damageSpells.at(0).damage;
					std::string currentSpell = creature.damageSpells.at(0).spellName;
		
					std::cout << creature.name << " uses " << currentSpell << "\n";
					Sleep(2);
				}
				else if(randomNumber == 2) { 
					user.health = user.health - creature.damageSpells.at(1).damage;
					std::string currentSpell = creature.damageSpells.at(1).spellName;
					
					std::cout << creature.name << " uses " << currentSpell << "\n";
					Sleep(2);
				}
				else if(randomNumber == 3) { 
					user.health = user.health - creature.damageSpells.at(2).damage;
					std::string currentSpell = creature.damageSpells.at(2).spellName;
					
					std::cout << creature.name << " uses " << currentSpell << "\n";
					Sleep(2);
				}
			}
			
			//Displays death message and restarts battle
			if(user.health < 0) { 
					Sleep(2);
					std::cout << "\n\nYou Have Died.\n\n";
					Sleep(2);
					std::cout << "Restarting Battle...\n\n\n";
					Sleep(2);
					user.health = 100;
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
			
			//Displays User Health and Mana 
			std::cout << "Your HP: " << user.health << "/100\n";
			if(user.classtype == mage or user.classtype == shaman or user.classtype == mecha or user.classtype == warlock or user.subclass == templarWarrior) {
				std::cout << "Your Mana: " << user.mana << "/100\n";
			}
			else { 
				std::cout << "Agility: " << user.agility << "/100\n";
			}
		
		
			//Lets the choose which type of attack/healing thing they want
			
			
				std::cout << "Choose which spell/attack you wish to use:\n"
							"1. Damage\n"
							"2. Healing\n"
							"3. Effects\n"
							"4. Items\n";
				
				int chooseAttackType; 
				createIcon();
				std::cin >> chooseAttackType; 
				
				//Activates spell chooser based on previous answer
				switch(chooseAttackType) { 
					//CHOOSEATTACKTYPE CASE 1 BEGIN
					case 1: 
						//Displays all damage spells in players arsenal
						std::cout << "Choose a damage spell:\n";
						std::cout << "1. " << user.damageSpells.at(0).spellName;
						std::cout << "\n";
						std::cout << "2. "  << user.damageSpells.at(1).spellName;
						std::cout << "\n";
						std::cout << "3. " << user.damageSpells.at(2).spellName;
						std::cout << "\n";
						std::cout << "4. " << user.damageSpells.at(3).spellName;
						std::cout << "\n";
						std::cout << "5. " << user.damageSpells.at(4).spellName;
						std::cout << "\n";
						std::cout << "6. Pass";
						std::cout << "\n";
						std::cout << "7. Go Back To Main Combat Menu\n";
						createIcon();
						int damageSpellChooser; 
						std::cin >> damageSpellChooser; 
					
						//Casts spell
						switch(damageSpellChooser) { 
							case 1:
								if(user.mana < user.damageSpells.at(0).manaCost) { 
									std::cout << "\nYou Do Not Have Enough Mana!\n";
									runAttackMenuAgain = true;
									break;
								}
								creature.health =  creature.health - user.damageSpells.at(0).damage;
								std::cout << "Your attack does " << user.damageSpells.at(0).damage << " points of damage\n";
								std::cout << creature.name << "'s HP is now at " << creature.health << "!\n";
								user.mana = user.mana - user.damageSpells.at(0).manaCost; 
								break;
							case 2: 
								if(user.mana < user.damageSpells.at(1).manaCost) { 
									std::cout << "\nYou Do Not Have Enough Mana!\n";
									runAttackMenuAgain = true;
									break;
								}
								creature.health =  creature.health - user.damageSpells.at(1).damage;
								std::cout << "Your attack does " << user.damageSpells.at(1).damage << " points of damage\n";
								std::cout << creature.name << "'s HP is now at " << creature.health << "!\n";
								user.mana = user.mana - user.damageSpells.at(1).manaCost; 
								break;
							case 3:
								if(user.mana < user.damageSpells.at(2).manaCost) { 
										std::cout << "\nYou Do Not Have Enough Mana!\n";
										runAttackMenuAgain = true;
										break;
									}
								creature.health =  creature.health - user.damageSpells.at(2).damage;
								std::cout << "Your attack does " << user.damageSpells.at(2).damage << " points of damage\n";
								std::cout << creature.name << "'s HP is now at " << creature.health << "!\n";
								user.mana = user.mana - user.damageSpells.at(2).manaCost; 
								break;
							case 4: 
								if(user.mana < user.damageSpells.at(3).manaCost) { 
										std::cout << "\nYou Do Not Have Enough Mana!\n";
										runAttackMenuAgain = true;
										break;
									}	
								creature.health =  creature.health - user.damageSpells.at(3).damage;
								std::cout << "Your attack does " << user.damageSpells.at(3).damage << " points of damage\n";
								std::cout << creature.name << "'s HP is now at " << creature.health << "!\n";
								user.mana = user.mana - user.damageSpells.at(3).manaCost; 
								break;
							case 5: 
									if(user.mana < user.damageSpells.at(4).manaCost) { 
										std::cout << "\nYou Do Not Have Enough Mana!\n";
										runAttackMenuAgain = true;
										break;
									}
								creature.health =  creature.health - user.damageSpells.at(4).damage;
								std::cout << "Your attack does " << user.damageSpells.at(4).damage << " points of damage\n";
								std::cout << creature.name << "'s HP is now at " << creature.health << "!\n";
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
				
				
				case 2:
					if(user.classtype == mage and user.subclass == aetherMage) { 
						std::cout << "1. " << user.healingSpells.at(0).spellName << "\n";
						std::cout << "2. " << user.healingSpells.at(1).spellName << "\n" ;
						std::cout << "3. " << user.healingSpells.at(2).spellName << "\n" ;
						
						int chooseHealingSpellLightMage;
						createIcon();
						std::cin >> chooseHealingSpellLightMage;
					 
						
					}
					break;
			
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



int main() {
	user.health = 100;
	user.mana = 100;
	
	
	Creature snake;
	snake.name = "Snake";
	snake.health = 80;
	snake.experienceGained = 150;
	snake.defaultHealth = 100;
	
	damageSpell bite;
	bite.damage = 10;
	bite.spellName = "Bite";
	snake.damageSpells.push_back(bite);
	
	damageSpell tailwhip;
	tailwhip.damage = 15;
	tailwhip.spellName = "Tail Whip";
	snake.damageSpells.push_back(tailwhip);
	
	damageSpell poisonbite;
	poisonbite.damage = 35;
	poisonbite.spellName = "Poison Bite";
	snake.damageSpells.push_back(poisonbite);
	
	
	
	
	
	damageSpell fireball;
	fireball.manaCost = 10;
	fireball.spellName = "Fireball";
	fireball.damage = 20;
	user.damageSpells.push_back(fireball);
	
	damageSpell fireblast;
	fireblast.manaCost = 20; 
	fireblast.spellName = "Fireblast";
	fireblast.damage = 30; 
	user.damageSpells.push_back(fireblast);
	
	damageSpell firewhip;
	firewhip.manaCost = 15;
	firewhip.spellName = "Firewhip";
	firewhip.damage = 25;
	user.damageSpells.push_back(firewhip);
	
	damageSpell fireblow;
	fireblow.manaCost = 25;
	fireblow.spellName = "Fireblow";
	fireblow.damage = 25;
	user.damageSpells.push_back(fireblow);
	
	damageSpell asteroid;
	asteroid.manaCost = 40;
	asteroid.spellName = "Asteroid";
	asteroid.damage = 45;
	user.damageSpells.push_back(asteroid);
	
	
	healingSpell rejuvenation;
	rejuvenation.healthAdded = 30;
	rejuvenation.spellName = "Rejuvenation";
	rejuvenation.manaCost = 40;
	user.healingSpells.push_back(rejuvenation);
	
	healingSpell basicHeal;
	basicHeal.healthAdded = 15; 
	basicHeal.spellName = "Basic Heal"; 
	basicHeal.manaCost = 15;
	user.healingSpells.push_back(basicHeal);
	
	healingSpell restoration;
	basicHeal.healthAdded = 25;
	basicHeal.spellName = "Restoration";
	basicHeal.manaCost = 35;
	user.healingSpells.push_back(restoration);
	
	
	
	
	
	
	
	user.classtype = mage;
	user.subclass = aetherMage; 
	playerFightMechanics(snake);
	
	 system("pause");
}

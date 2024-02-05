//This program has a few things wrong with it lol

#include <iostream>

const int STRING_SIZE = 512 ;   //increase the size // Not necessary

int calculatePopulation(int, int);

int main(int argc, const char * argv[]) {

  if(argc != 1) {
      std::cout << argv[0] << ": Invalid Input Error!\n";
      return -1;
  }

  std::cout << "Enter the name of the university\n";
  char univName [STRING_SIZE];   // Is length a issue here // Shouldn't be if a university is more than 512 characters we have a bigger problem
  std::cin.getline(univName, STRING_SIZE);

  char done = 'N';      
  while(!(done == 'Y') || !(done == 'y')) {   // "=" or "==" // definately "=="
    
    std::cout << "What is the current population? ";
    int pop;
    std::cin >> pop;
    //while(pop < 1) { //Why is this a while loop instead of an if statement... I mean I guess it works
    if(pop < 1) {
      std::cout << argv[0] << ": Invalid Input Error!\n";
      return -1;
    }
        
    std::cout << "What is the rate of growth? (e.g., for 10% enter 10) ";
    int growth;
    std::cin >> growth;
    //while(growth < 0) { // Again why a while loop... once again I guess it works
    if(growth < 0) {
      std::cout << argv[0] << ": Invalid Input Error!\n";
      return -1;
    }
        
    std::cout << "\nYear\tNew Population" << std::endl;
    int *newpop = new int;
    *newpop = 1;   //initilize the int value

    //int i = 1;   //Iniitilize it 

    //For loop was very wrong while the initialization of I can
    //be done outside the for loop it is bad practice especially
    //if it isn't even used outside of the for loop. A while
    //loop would be far better here
    //
    //i++ wouldn't run the for loop properly and would make the
    //first year to be run twice causing a wrong answer

    for (int i = 1; i <= 5; ++i) {
      *newpop = calculatePopulation( pop , growth );
      pop = *newpop;
      std::cout << i << "\t \t" << *newpop << std::endl;
      //delete newpop;   //Delete here will create trouble
    }
   

    std::cout << "\nFinal population of " << univName;
    std::cout << " is " << *newpop << std::endl;
    //Not sure if this delete is necessary but it doesn't change functionality
    delete newpop;  //Delete here
    
    //Using a switch case when each case has an individually well defined set of instructions
    //is a bad idea because it's meant to be more of a "goto" rather than an actual if statement
    //switch cases are good when the functions beneath it are expected to run with the one that
    //was just ran but if you need to break after every case it's a bad idea.
    std::cout << "Done? (Y/N) ";
    std::cin >> done;
    switch (toupper(done)) {
    case 'N':
	    std::cout << "Starting again\n";
	    std::cout << "------------------------------\n";
        break;

    case 'Y':
        std::cout << "Exiting...\n";
        return 0;
    
    default:
        std::cout << argv[0] << ": Invalid input\n";
        std::cout << "The program will exit\n";
	    std::cout << "------------------------------\n";
        return -1;
    }
  }
  return 0;
}

int calculatePopulation( int pop, int growth) {
  double growthRate = (double) growth / 100;
  double increase = (double) pop * growthRate;
  return (pop + increase);
    
}

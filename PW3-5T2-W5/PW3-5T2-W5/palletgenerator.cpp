// I need a couple of the C header files.
// Again, drop off the .h of the end, and put a c in front
// So, if I want stuff contained in <stdlib.h> and <time.h>...
#include <cstdlib>
#include <ctime>

// Include our generator header file
#include "palletgenerator.h"

#include <iostream>

// Let's use the standard namespace
using namespace std;

// Writing some slightly smarter code than we did in week 2,
// We'll initialise srand once and only once
void SeedRand()
{
	// srand initialises the random number generator (without this, we get the same numbers every time)
	// We'll initialise it using the current time, as this is fairly difficult to predict.

	// It is generally bad practice to call srand multiple times. This is because programs
	// execute very fast on a modern processor, and there is a good chance that the next call to time() will
	// be within the same second. srand will then return the same value, and when you call rand you'll
	// end up with the same value from the generator. 
	// What we can do is use a static variable (look at last term's Week 10 lecture notes) to track whether we've already called srand
	// Remember: static means "local scope, but the value of the variable is retained when we re-enter scope"

	// Initially, the variable is false
	// Confusingly, because it's static, this line is skipped the second time we hit this, and it keeps the value it had last time we saw it
	static bool randHasBeenSeeded = false;
	if (!randHasBeenSeeded)
	{
		srand(time(NULL));
		randHasBeenSeeded = true;

		// Try uncommenting this line, and making randHasBeenSeeded static and non-static, and see what happens as you generate a pallet
		//cout << "Seeded Rand!" << endl;
	}

}


// This is mostly the same code we wrote in Week 2.
// Re-usable code is awesome
// Building a pallet is just going to be taking a list of strings, and picking items from it to add.
string GetRandomItemFromList(vector<string> list)
{
	// We want to pick an item from the list at random.

	// rand is a cheap function defined by the C standard library in stdlib
	// It's got some poor statistical characteristics, but our application is simple enough to not care

	// The random number generator needs "seeding" (initialising).
	// This function will do it for us if we haven't already done it.
	SeedRand();

	// rand will pick a random number between 0 and INT_MAX. We'd like to pick a number between 0 and the end of our list
	// Our good friend modulus (%) helps us here
	// rand will pick some arbitrary big number, but since we only take the remainder, we know the end value will be in the range we want
	// (work it out with a pen and paper if you don't see how this works: divide a big number by the list count, and look at the remainder)
	int index = rand() % list.size();

	// Now we know which position in the array we want, we'll return it.
	return list[index];
}


Pallet GeneratePallet()
{
	// Basically, have a list of things we can shove on a Pallet.
	// Pick one at random, shove it on the Pallet.

	// List of random things we can put on a pallet
	vector<string> palletContents =
	{
		"box of carrots",
		"six-pack of soda",
		"twelve-pack of soda",
		"chest of tea leaves",
		"assorted t-shirts",
		"pair of trousers",
		"packet of socks",
		"roll of fabric",
		"roll of toilet paper",
		"empty 10-gallon fish tank",
		"full 10-gallon fish tank", // curiously, both a full and empty tank "weigh" the same...
		"toybox",
		"tool box",
		"box of live scorpions", // BoxMovers Ltd. may actually be a front for an organisation of super-villains
		"industrial laser components",
		"cardboard",
		"plywood",
		"bag of flour",
		"bouquet of flowers", // because flower sounds like flour! Get it? Also, isn't that going to get crushed if we put stuff on top of it?
		"carton of eggs",
		"super-fragile glassware",
		"Faberge egg",
		"box of scorpion eggs", // WHAT IS IT WITH THESE PEOPLE AND SCORPIONS
		"packet of sunflower seeds",
		"packet of carrot seeds",
		"packet of tulip bulbs",
		"taxidermied grizzly bear", // again, weighs the same as everything else
		"toy robots",
		"remote-control cars",
		"crate of laptops",
		"flatpack furniture",
		"live goat", // one assumes it's in a crate
		"twelve-pack of paint cans",
		"vial of dinosaur DNA",  // I would have expected scorpion DNA knowing these people
		"box of screws",
		"box of bolts",
		"box of nuts",
		"box of peanuts",
		"tub of curry powder",
		"crate of live velociraptors", // Fun fact: despite how they're portrayed in Jurrasic Park, velociraptors were basically half-meter-high feathered turkey-lizards. Jurrasic Park modelled 'raptors off of Deinonychus, which is a much less exciting name for "murder-lizard"
		"tub of goo",
		"box of soap",
		"sandbags",
		"packaged forklift",
		"cargo storage components",
		"server components",
		"box of motors",
		"spool of wire",
		"spool of ethnet cable",
		"spool of rope" 
	};
	
	// The random number generator needs "seeding" (initialising).
	// This function will do it for us if we haven't already done it.
	SeedRand();

	// Randomise how many items are going on the Pallet
	// I'd like there to be about 7ish most of the time.
	// If you've ever played a dice game, rolling two 6-sided dice and adding them gives a nice distribution with the middle about 7, with a min of 2 and a max of 12
	// Because (something)%6 is in the range  0-5, I'd need to add 1 to get 1-6. Since I'm doing it twice, I can just add 2 at the end

	// (incidentally, this is the exact kind of thing rand is really bad at: the dice rolls aren't independant. 
	// Have a look at the C++11 <random> library if you want a better random number generator)
	int numItemsOnPallet = (rand() % 6) + (rand() % 6) + 2;

	// I need a Pallet ID.
	// I'll use a static variable so that I can remember from one run of the function to the next
	// (look at term 1, lecture 10 for how static works)
	// Basically, a static variable has local scope, but remembers its value from the last time it was in scope
	// It's a powerful tool, but it's not obvious how it works at first glance.
	static int pallet_ID = 1000;

	// Create a Pallet
	// Give it the ID, and allow it to fit 12 items
	Pallet p(pallet_ID, 12);

	do
	{
		// Grab an item and add it to the pallet
		string item = GetRandomItemFromList(palletContents);
		p.AddItem(item);

	} while (p.GetCurrentWeight() < numItemsOnPallet);

	// Add one to our pallet ID, so the next time we call this function we get a different pallet id
	pallet_ID++;

	return p;
}
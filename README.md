# Genetic Algorithm

I created this program both because I was *very* interested in Genetic Algorithms.
The program starts with 4 randomly generated strings, and uses them based on "fitness" to create children.

## How it works
* Fitness is calculated based on how closely a string matches the target
* The two highest children combine to create 4 new children.
* 4 new children randomly select characters from the 2 fittest parents.
* There is also a chance of mutation which is dictated by a configured percentage.
* The process of reproduction continues until a match is finally found.


# Shelling segregation model
The Shelling Segregation model is an agent based model, which is a type of computational simulation 
that creates a world populated with autonomous agents that make decisions by following a set of rules.

Developed by the economist Thomas Shelling in 1969, it offers an explanation on why neighboorhoods tend to be segregated even if the citizens do not have any prejudice
and are confortable in seeing diversity in their surroundings.
The surprising result is that even for a similarity preference that is much less than 50\%, 
which corresponds to individuals that are very comfortable with diversity, race-segregated neighborhoods are still a frequent outcome. 

# Simulation details:
The simulation involves a 30x50 grid filled with two different types of population and a percentage of empty slots. The individuals have a preference for being 
surrounded by similar peoples so that they are considered 'happy' if a certain amount of nearby slots are populated by their same type. If this condition is not achieved,
the individual is placed on another random empty spot of the grid, the simulation runs until every subject is considered 'happy'.

# Steps of the simulation
1. The simulation starts by acquiring the input parameters, which are the ratio between the two types of population, the percentage of empty spaces, the number of similar people they need to be surrounded by in order to be considered happy and the speed of the simulation.
2. The grid is populated and shuffled in a random way so that the two populations are homogeneously distributed. 
3. At each step, the happiness level of each subject is evaluated and if the subject is considered unhappy, it is relocated in a random spot, otherwise the position remains unchanged.
4. The simulation ends when all the individuals are considered happy.
5. At the end of the simulation two report files containing informations on the simulations initial and ending states.

# Structure of the project
1. The whole project is written in C programming language.
2. The 'main.c' contains the source code for the simulation.
3. The module 'utils.c' contains a set of functions which are used by the main in order to run correctly.
4. The output of the simulation is stored in the files 'simulation_data.dat' and 'simulation_data2.dat'.


# Installation
In order to run the simulation the folder has to be downloaded, it can be run via console by executing the 'Shelling_model.exe' file.
In order to modify the source codes a C compiler is needed.

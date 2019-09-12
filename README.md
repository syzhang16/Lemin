# Lemin

This project is meant to code an ant farm manager. It was made in collaboration with [acarcena](https://github.com/acarcena).

### Introductions
We make an ant farm, with tunnels and rooms; we place the ants on one side; and we look at how they find the exit. We need tubes and rooms to create the ant farm. We join the rooms to one another with as many tubes as we need. A tube joins two rooms to each other. A room can be linked to an infinite number of rooms and by as many tubes as deemed necessary. 

### Objectives
* The program will receive the data describing the ant farm from the standard outputin the following format:
```
number_of_ants
the_rooms
the_links
```
* The ant farm is defined by the following links:
```
##start
1 23 3
2 16 7
#comment
3 16 3
4 16 5
5 9 3
6 1 5
7 4 8
##end
0 9 5
0-4
0-6
1-3
4-3
5-2
3-5
#another comment
4-2
2-1
7-6
7-2
7-4
6-5
#another comment
```
* There are three parts:
  - The rooms, which are defined by: `name coord_x coord_y`.
  - The links, which are defined by: `name1-name2`.
  - The comments, which start with `#`.
* Lines that start with `##` are commands modifying the properties of the line that comes right after.
* Any non compliant or empty lines will automatically stop the ant farm’s reading as well as the orderly processing of the acquired data.
* If there isn’t enough data to process normally you must display `ERROR`.

### Instructions
* The executable file must be named `lem-in`.
* The goal of this project is to find the quickest way to get `N` ants across the farm.
* Quickest way means the solution with the least number of lines, respecting the output format requested below.
* There are some basic constraints. To be the first to arrive, ants will need to take the shortest path (and that isn’t necessarily the simplest). They will also need to avoid traffic jams as well as walking all over their fellow ants.
* At the beginning of the game, all the ants are in the room `##start`. The goal is to bring them to the room `##end` with as few turns as possible. Each room can only contain one ant at a time. (except at `##start` and `##end` which can containas many ants as necessary.).
* All the ants are in the room `##start`at the beginning of the game.
* At each turn you only display the ants that moved.
* At each turn you can move each ant only once and through a tube (the room atthe receiving end must be empty).
* You must to display the results on the standard output in the following format:
```
number_of_ants
the_rooms
the_links

Lx-y Lz-w Lr-o ...
```
`x`, `z`, `r` represents the ants’ numbers (going from 1 to number_of_ants) and `y`, `w`, `o` represents the rooms’ names.

### Usage
./lem-in [OPTIONS] < MAP
 
AVAILABLE OPTIONS:
* -help : Show usage;
* -v  : Verbose. Print a valid error message describing what happened in the program;
* -ph : Print the hash_table containing all the rooms;
* -sp : Print the path(s) used by the ants colony;
* -ng : Doesn't print the original graph;
* -nt : Doesn't print the ants getting through the graph.

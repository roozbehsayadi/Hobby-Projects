
# Flocking Boids

This program simulates the flocking behaviour of birds. The name *boid* corresponds to a shortened version of *bird-oid object*, which refers to a bird-like object.

## How does it work

There are three main rules for each of the boid's movement:

- **Cohesion**: Boids try to move towards the centre of the mass of neighbouring boids.

- **Separation**: Boids try to keep a small distance away from other objects (including other boids).

- **Alignment**: Boids try to match velocity with near boids.

There are also other rules, such as:

- Boids have a limit for their velocity.

- Boids prefer to stay in the screen.

And many other rules to make the simulation more real.

Each of these rules can be applied to each boid separately. At the end, effect of these rules will be accumulated.

## Installing requirements

First, you need a C++ compiler. I used g++ in the *Makefile* but it's nagotiable. :)

Also you'll need SDL1.2 to run the code. In a Linux terminal, they can be installed with this command:

```bash
sudo apt install libsdl1.2-dev libsdl-gfx1.2-dev
```

## Usage

You can compile the codes using the provided *Makefile*. Go to the folder with a Terminal and simply execute ```make```.

Running the code can be done with ```make run```.

You can run the code yourself, simply execute the binary output with this command: ```./Flocking```.

An argument is also required to run the game. This is the number of boids in the screen. For example, to have 100 boids on the screen, you should run this command: ```./Flocking 100```. High number of boids is not recommended because it'll eat your computer's performance like a... practically like A CHROME TAB.

Oh, and in fullscreen mode, you have to use the *q* button to close the program.

## Screenshot

![Screenshot](https://raw.githubusercontent.com/roozbehsayadi/Hobby-Projects/master/Flocking%20Boids/Screenshot.png)

## Code structure

The most important class in this project is ```FlockingBoids```. There is an instance of ```FlockingMonitor``` inside it to show the flocks, and also an array of flocks.

You can see how you should use it in the *main.cpp* file.

Other files are in the *util/* folder. There's a *README* in that folder to describe those files.

## Reference

I used this amazing article by Conrad Parker to get a sense of what should I do, and how should I do them. I recommend reading it to you too.

[Boids Pseudocode](http://www.kfish.org/boids/pseudocode.html)

## Possible improvements

- **Performance**: Its performance can be improved. I stored all the boids in an array, and every time I want to find the close boids of another boid, I have to search the entire array, and then sort them based on their distance. Using a Quadtree can improve its performance a lot.

- **Tweakable parameters**: I think some scroll bars on the screen, for changing the behaviour of the boids real-time can be quite impressive. I mean how much do boids get away from each other, how much they want to sync their velocity with other boids and...

- **Code structure improvement**: I did my best to build the code's structure, but of course no code is perfect. Maybe there are better solutions out there, comparing to my solutions for the encountered problems.


# Description of the classes

- **Flock**: Contains the boids of the flock. The other important attribute of this class is ```monitor```, which is a ```FlockingMonitor```.

- **Boid**: Represents one boid, obviously. Stores the boid's position and velocity.

- **FlockingMonitor**: Handles the stuff about graphics.

- **SDLHandler**: Some graphical functions that I thought belong together.

- **SDLEventType**: A really little enum (for now). Represents the different events that can happen with the SDL screen. For now, it's only the quit event.

- **Point**: X and Y.

- **Color**: R, G, and B.

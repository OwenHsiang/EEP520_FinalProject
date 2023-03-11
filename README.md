# EEP520_FinalProject
Winter2023 EEP520 Final Project
# Overview
The goal of this project is to simualte the image formation by convex lens, where the rays converge after falling on the convex lens. The parameters are already set as constant, including focal length and the position of light source. Users can move the lens left or right by pressing `A` or `D`, and the simulation result is updated accordingly. Furthermore, the buttons `Reset` and `Light source is on the focal point` can reposition the lens directly.

## Key Challenges

Some of the key challenges faced during the development of this project.

- **Challenge 1: Calculate the relative position between the lens and the image.**

To simulate the image formation, the principles of ray tracing must to be followed:
1. When a ray strikes convex lens obliquely at its optical centre, it continues to follow its path.
2. When a ray parallel to the principal axis strikes convex lens, the refracted ray will pass through a focus on the principal axis.
3. When a ray passing through focus strikes convex lens, the refracted ray will pass parallel to the principal axis.

Based on the lens maker's equation, `1/X_object + 1/X_image = 1/f`

- **Challenge 2: Emit the calculated result to image and reposition it.** 

Since the position of the lens is unsteady, the position of image also has to be updated spontaneously. The `watch event` button is used to receive the updated result.

## Installation

To run this project, you must have Docker installed on your system. Follow these steps to install and run the project:

1. Clone the repository to your local machine using `git clone <repository-url>`.
2. Navigate to the project directory.
3. Build the Docker.
4. Run the Docker container using `docker run -p80:80 -p8765:8765 -v $PWD/EEP520_FinalProject:/source -it klavins/enviro:v1.4 bash`


## Running the project

Follow these steps to use the project.

- **Step 1:** esm start
- **Step 2:** make
- **Step 3:** enviro
- **Step 4:** To view the simulation, please open a web browser and type in http://localhost/

## Code

This project includes 5 agents as following:
1. label: To label the image distance and object distance.
2. lens: Pressing `A` and `D` can move the lens(The value of X_lens is from -125 to infinte). The main goal is to update the position of itself and calculate the relative image position. 
3. light: It represents the object(light source). 
4. path: It represents optical axis.
5. target: It represents the image, moving the lens will also move the target spontaneously.

This project includes 2 buttons as following:
1. Reset(X_lens:2f): Move the lens to the origin(Set as 2f).
2. Light source is on the focal point(X_lens:f): Move the lens to focal point.

## Acknowledgments

List sources of information or code used in this project, including libraries, frameworks, and tutorials.

ENVIRO: The multi-agent, multi-user, multi-everything simulator

-**https://github.com/klavinslab/enviro**

Elma: An event loop manager for embedded systems

-**http://klavinslab.org/elma/**

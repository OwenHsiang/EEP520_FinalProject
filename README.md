# EEP520_FinalProject
Winter2023 EEP520 Final Project
# Overview
The goal of this project is to simualte the image formation by convex lens, as we know the rays will converge after falling on the convex lens. The parameters are already set as constant, including focal length and the position of light source. The user can move the lens left or right by pressing `A` or `D`, and it will show the relative simulation result. Furthermore, the buttons `Reset` and `Light source is on the focal point` can reposition the lens directly.

## Key Challenges

Describe some of the key challenges faced during the development of this project.

- **Challenge 1: Calculate the relative position between lens and image.**

To simulate the image formation, some principles of ray tracing must to be followed:
1. When a ray strikes convex lens obliquely at its optical centre, it continues to follow its path.
2. When a ray parallel to the principal axis strikes convex lens, the refracted ray will pass through a focus on the principal axis.
3. When a ray passing through focus strikes convex lens, the refracted ray will pass parallel to the principal axis.

 According to lens maker's equation, 1/X_object + 1/X_image = 1/f

- **Challenge 2: Emit the calculated result to image and reposition it.** 

Since the position of lens is unsteady, the position of image also have to be updated spontaneously. Here use watch event to receive the updated result.

## Installation

To run this project, you must have Docker installed on your system. Follow these steps to install and run the project:

1. Clone the repository to your local machine using `git clone <repository-url>`.
2. Navigate to the project directory.
3. Build the Docker.
4. Run the Docker container using docker run -p80:80 -p8765:8765 -v $PWD/EEP520_FinalProject:/source -it klavins/enviro:v1.4 bash


## Run the project

Follow the steps to use the project.

- **Step 1:** esm start
- **Step 2:** make
- **Step 3:** enviro
- **Step 4:** To view the simulation, please open a web browser and type in http://localhost/

##Code



## Acknowledgments

List any sources of information or code used in this project, including libraries, frameworks, and tutorials. Be sure to provide links to any external resources used.

- Source 1
- Source 2
- Source 3

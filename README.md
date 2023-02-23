

![Qt Banner](https://i.ibb.co/x5tQ3Jq/Sans-titre-36.png)
# ThermSim - Qt and C++ project

ThermSim is a powerful software application that enables users to simulate heat treatment processes with ease. The software is designed to be user-friendly, intuitive, and packed with features that will help you optimize material performance. With ThermSim, you can model complex heat treatment processes, including annealing, quenching, and tempering, and explore the effects of different variables such as temperature, time, and cooling rate.

Whether you are a materials engineer, a researcher, or a student, ThermSim is an invaluable tool for understanding and optimizing heat treatment processes. The software is currently under development and will be released soon on Github, so stay tuned for updates and get ready to take your materials science research to the next level with ThermSim.

## Objectives

The main objectives of this project are:

1.  Simulate heat treatment processes: ThermSim is designed to simulate various heat treatment processes such as annealing, quenching, and tempering, allowing users to predict the microstructure and properties of materials after treatment.
    
2.  Optimize material performance: The software provides users with tools to optimize the performance of materials by exploring the effects of different process parameters, such as temperature, time, and cooling rate, on the final properties of materials.
    
3.  User-friendly interface: ThermSim is designed with a user-friendly interface that is intuitive and easy to navigate, making it accessible to researchers, students, and engineers with varying levels of expertise in heat treatment processes.
    
4.  Improve material science research: By providing accurate simulations and optimization tools, ThermSim can help improve material science research by enabling researchers to understand the underlying mechanisms of heat treatment processes and optimize the performance of materials for specific applications.
    
5.  Open-source and community-driven development: ThermSim is an open-source software application, which means it is free to use and modify, and the community can contribute to its development, leading to an innovative and constantly improving tool for the materials science community.

In addition to the objectives I mentioned, the main objective of ThermSim is to improve my developer's skills in programming, particularly in the C++ programming language. And also my knowledge in material processing. The development of a software application such as ThermSim requires extensive coding and problem-solving skills, making it an excellent opportunity for personal growth and development.

## Progression

#### Day 1 - Building the User Interface
A simple UI has been built using the Qt Creator Tool. 

#### Day 2 - Improving the User Interface

Further research has been done in heat treatment, here is what I have concluded:

In order to simulate a heat treatment, we need to know, at least:

-   Material (steel, brass, aluminum, ...)
-   Type (hypo-eutectoid, brass alpha, aluminum 2000 series, ...)
-   Heat treatment type (quenching, annealing, ...)
-   Time of the heat treatment process
-   Temperature of the heat treatment process
-   Shape of the part (plate, bar, tube, ...)
-   Dimensions of the part (50 x 50 x 20 cm for example)

More info about my research can be found [here](https://github.com/users/AmmarSyedK/projects/2?pane=issue&itemId=20873917).

Thus, more QComboBox has been added to the UI. Here is a preview:

![Day 2](https://i.ibb.co/3dkdgXG/image.png)
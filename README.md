# The LaiCraft

LaiCraft is a 3D Minecraft-Like game built from the ground up using C++ and OpenGL with [SFML](https://www.sfml-dev.org/).

### Video: 
https://www.youtube.com/watch?v=hIp613w-0aY&feature=youtu.be

### How to:

* Environment setup: Win10 and Visual Studio 2017

* Open the LaiCraft.sln

* Build the **ExampleGame** project and **BuildExampleGameAssets** project in Solution Explorer

* Run the .exe in LaiCraft/temp/($Platform)/$(Configuration)/ExampleGame_

## Features

* Source code in LaiCraft/Engine

* Component-based GameObjects, allowing users to add component classes to their GameObjects

* Custom Engine Library, including Scene, Math, Physics, etc...

* High Speed Memory Allocator, reducing average dynamic allocation time by 60%

* Shared_ptr and Weak_ptr for resource management and avoiding memory leaks

* One-click **Lua Asset Builder**

## Gameplay Programming

* Source code in LaiEngine/ExampleGame_

* Custom event system with Observer pattern, improving performance for GameObjects spawning and destroying

* Implemented artificial intelligence with State pattern, facilitating changes to the GameObjects’ behaviors based on the project requirements 
 
* Implemented game subsystems with Mediator pattern and Façade pattern, making it easier to maintain gameplay features  

* Created a Lua-driven balance sheet system, to help facilitate the game design workflow and rapid iteration
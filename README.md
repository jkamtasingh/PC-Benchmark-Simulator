# PC-Benchmark-Simulator
A stress test to determine the performance of a simulated computer, allowing the user to understand how their overall performance is impacted by the different games chosen.

# Technologies
- C++
- Standard Template Library
- Built With Replit

# Features
- Choose a PC Tier: Low, Medium, High End, or a Custom PC with personalized specs
- Stress test individual components: CPU, GPU, and RAM
- Game-based load simulation: Tests are based on running Minecraft, GTA V, or Cyberpunk 2077
- Thermal Throttling warnings: alerts user if CPU/GPU temps exceed 95°C
- RAM overflow warnings: warns user when RAM usage gets too high for the system
- Store & Review Results: saves all temperature and usage readings from the session
- Sorted averages: when requested, you can check stored temperatures, which are sorted from highest to lowest and averaged per component
- Custom PC Mode: input your own CPU cores, threads, GPU VRAM, and RAM for personalized simulation

# The Process
We started by researching realistic temperature ranges and hardware specs for each game before writing a single line of code, ensuring the simulation would reflect real world performance. 

From there, we designed the Computer and Games classes to lay the foundation for storing PC specs and game options.

We then built out the full menu interface, using switch cases to handle PC selection and route the user into the correct stress menus for each component.

Inside each stress menu, we declared functions that leveraged random number generation to produce temperatures and usage values that scaled realistically based on the selected system's specs.

As tests were ran, results were captured using vector push-backs and passed into the sumCPU, sumGPU, and sumRAM functions using pass by reference, keeping memory usage efficient.

Next, we built the CheckTemps function, implementing recursion to accumulate and average all stored values, and a sorting algorithm to display them in ascending order.

Throttling and overflow warnings were also implemented, actively checking component values against safe thresholds and triggering alerts when a system was being pushed beyond its limits. 

We then added the CustomPC class, giving users the ability to define their own hardware configuration for a fully personalized simulation.

Finally, we wrapped up development by implementing a clear screen function to clean up the interface between menus, improving overall user experience.

# What I Learned

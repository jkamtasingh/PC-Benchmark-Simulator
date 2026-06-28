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
Throughout this project, I've picked up important skills and a clear understanding of Object Oriented Programming, which improved my code logic.

Object Oriented Programming:
- Encapsulation is demonstrated through private member variables (CPU, GPU, and RAM), which are private from outside code and can only be accessed through public getters/setters such as getCores() and getVram().
- Access modifiers are used tthrough all three classes, as Games declares members as protected, while Computer and customPC restrict their members to private.
- Together, the concept of encapuslation and access modifiers work together to reinforce the core principles of OOP, as they control how data is accessed and modified.

Vectors:
- Vectors such as: cpuTemp, gpuTemp, and ramUsage are used throughout the program to store benchmark results for each component.
- Working with these vectors deepened my understanding of key vector operations (push_back(), .clear, .empty, .size(), and sort()), while reinforcing how vectors serve as a more flexible and practical alternative to arrays.

Recursion:
- Different functions such as: sumCPU(), sumGPU(), and sumRAM(), utilize recursion instead of a loop to total vector values.
- Recursion is used in place of a standard loop to sum stored benchmark values, as it demonstrates my understanding of base cases, recursive steps, and how a function can call itself to process data incrementally.

Overall Growth:
Through the usage of OOP, vectors and recursion, my C++ skill set continues to expand as I can approach different challenges with a wider variety of problem solving techniques. 

# What can be improved?
- Repeated code can be eliminated
- One reusable function for random number generation can be used
- A validate user input can be added to remove the chances of the code breaking when a user inputs a letter instead of a number

# Running the project
To run the project, follow these steps:

1. Save the repository to your local computer.
2. Open terminal and navigate to the folder where the file is saved.
3. Compile the code.
4. Run the program.

# Authors
**Joshua Kamtasingh** - OOP class design, recursive functions, random number generation.
- GitHub: [jkamtasingh] (https://github.com/jkamtasingh)
  
**Gurvishvash Baath** - stress test logic, menu navigation, sorting logic.
- Email: gurvishvashbaath@gmail.com

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
void PCmenu();
void MainMenu();
void CPUStressMenu();
void GPUStressMenu();
void RAMStressMenu();
void CheckTemps();
void CustomPCMenu();

int PCchoice, Mainchoice, switchChoice;
int selectedPC = 0; 
vector<int> cpuTemp;
vector<int> gpuTemp;
vector<int> ramUsage;

void ClearScreen(){ 
  #ifdef _WIN32
    (void) system("cls"); 
  #else
    (void) system("clear"); 
  #endif
}

class Computer {
private:
  string CPU, GPU;
  int RAM;
public:
  Computer() {}
void setComponents(string c1, string g1, int r1) {
    CPU = c1;
    GPU = g1;
    RAM = r1;
  }
  void getComponents() {
    cout << "CPU: " << CPU << "\nGPU: " << GPU << "\nRAM: " << RAM << "GB" << endl;
  }
};

Computer lp;
Computer mp;
Computer hp;

class Games {
protected:
  string game1, game2, game3;

public:
  void setGames(string g1, string g2, string g3) {
    game1 = g1;
    game2 = g2;
    game3 = g3;
  }
  void getGames() {
    cout << "1. Low Intensity: " << game1 << "\n2. Medium Intensity: " << game2 << "\n3. High Intensity: " << game3 << endl;
  }
};

Games g1;

class customPC {
private:
int cores, threads, vram, ram;
string CPU, GPU;
public:
  customPC() {}
  void setCustomComponents(string c1, string g1, int r1, int c2, int t1, int v1) {
    CPU = c1;
    GPU = g1;
    ram = r1;
    cores = c2;
    threads = t1;
    vram = v1;
  }
  int getCores() {
    return cores;
  }
  int getThreads() {
    return threads;
  }
  int getVram() {
    return vram;
  }
  int getRam() {
    return ram;
  }
  void getCustomComponents() {
  cout << "CPU: " << CPU << "\nCores: " << cores << "-cores" << "\nThreads: " << threads << " threads" << "\nGPU: " << GPU <<
  "\nVRAM: " << vram << "GB" << "\nRAM: " << ram << "GB" << endl;
  }
};

customPC cp;

int main() {

  srand(time(NULL));
  lp.setComponents("Intel Celeron", "NVIDIA GTX 1050", 8);
  mp.setComponents("Intel Core i5", "NVIDIA RTX 3060", 16);
  hp.setComponents("Ryzen 7 9800X3D", "NVIDIA RTX 5090", 32);
  g1.setGames("Minecraft", "GTA V", "Cyberpunk 2077");

  while (true) {
    cout << "Welcome to the Computer Stress Test" << endl;
    cout << "Choose a computer system" << endl;
    cout << "1. Low End PC" << "\n2. Medium End PC" << "\n3. High End PC"<<"\n4. Custom PC"<<"\n5. Exit" << endl;
    cout << endl;
    cout << "Enter your choice: ";
    cin >> PCchoice;
    cout << endl;

    switch (PCchoice) {
    case 1: {
      ClearScreen();
      cpuTemp.clear();
      gpuTemp.clear();
      ramUsage.clear();
      lp.getComponents();
      selectedPC = 1; 
      MainMenu();
      break;
    }
    case 2: {
      ClearScreen();
      cpuTemp.clear();
      gpuTemp.clear();
      ramUsage.clear();
      mp.getComponents();
      selectedPC = 2;
      MainMenu();
      break;
    }
    case 3: {
      ClearScreen();
      cpuTemp.clear();
      gpuTemp.clear();
      ramUsage.clear();
      hp.getComponents();
      selectedPC = 3;
      MainMenu();
      break;
    }
    case 4: {
      ClearScreen();
      cpuTemp.clear();
      gpuTemp.clear();
      ramUsage.clear();
      CustomPCMenu();
      break;
    }
    case 5:
      cout << "Exiting" << endl;
      exit(0);
      break;
    default:
      cout << "Invalid choice" << endl;
      cout << endl;
    }
  }

  return 0;
}

void CustomPCMenu(){
  string CPUName, GPUName;
  int cores, threads, vram, ramAvailable;

  cout << "Enter your Custom PC Details" << endl;
  cout << endl;
  cin.ignore();
  cout << "Enter your CPU Name: ";
  getline(cin, CPUName);
  cout << endl;
  cout << "Enter your CPU Cores: ";
  cin >> cores;
  cout << endl;
  cout << "Enter your CPU Threads: ";
  cin >> threads;
  cout << endl;
  cin.ignore();
  cout << "Enter your GPU Name: ";
  getline(cin,GPUName);
  cout << endl;
  cout << "Enter your VRAM: ";
  cin >> vram;
  cout << endl;
  cout << "Enter your Available RAM: ";
  cin >> ramAvailable;
  cout << endl;
  cp.setCustomComponents(CPUName, GPUName, ramAvailable, cores, threads, vram);
  cp.getCustomComponents();
  selectedPC = 4;
  MainMenu();
}

void MainMenu() {
  cout << endl;
  cout << "Select a component to stress test!" << endl;
  cout << "1. CPU" << "\n2. GPU" << "\n3. RAM" << "\n4. PC Selection Screen" << "\n5. Check Stored Temps" << "\n6. Exit" << endl;
  cout << endl;
  cout << "Enter your choice: ";
  cin >> Mainchoice;
  cout << endl;

  switch (Mainchoice) {
  case 1: {
    CPUStressMenu();
    break;
  }
  case 2: {
    GPUStressMenu();
    break;
  }
  case 3: {
    RAMStressMenu();
    break;
  }
  case 4: {
    return;
  }
  case 5: {
    CheckTemps();
    break;
  }
  case 6: {
    cout << "Exiting" << endl;
    exit(0);
  }
  default:
    cout << "Invalid choice" << endl;
    cout << endl;
  }
  MainMenu();
}

int numRandGenCPU(int min, int max) {
  int num1 = rand() % (max - min + 1) + min;
  if (num1 > 95) {
    cout << "CPU is throttling!" << endl;
  }
  cout << "CPU Temperature: " << num1 << "°C" << endl;
  return num1;
}

int numRandGenGPU(int min, int max){
  int num1 = rand() % (max - min + 1) + min;
  if (num1 > 95) {
    cout << "GPU is throttling!" << endl;
  }
  cout << "GPU Temperature: " << num1 << "°C" << endl;
  return num1;
}

int numRandGenRAM(int min, int max) {
  int num1 = rand() % (max - min + 1) + min;
  cout << "RAM Usage: " << num1 << "GB" << endl;
  return num1;
}

void CPUStressMenu() {
  cout << "Select a Game to Stress Test the CPU!" << endl;
  g1.getGames();
  cout << endl;
  while(true) {
    int gameChoice;
    cout << "Enter your choice: ";
    cin >> gameChoice;
    cout << endl;
    if (gameChoice == 1) {
      cout << "Minecraft Selected" << endl;
      if (selectedPC == 1) {
        int num1 = numRandGenCPU(60, 90);
        cpuTemp.push_back(num1);
      } 
      else if (selectedPC == 2) {
        int num1 = numRandGenCPU(50, 70);
        cpuTemp.push_back(num1);
      } 
      else if (selectedPC == 3) {
        int num1 = numRandGenCPU(40, 60);
        cpuTemp.push_back(num1);
      }
      else if (selectedPC == 4) {
        if (cp.getCores() <= 4 && cp.getThreads() <= 4) {
          int num1 = numRandGenCPU(60, 90);
          cpuTemp.push_back(num1);
        }
        else if (cp.getCores() <= 8 && cp.getThreads() <= 8) {
          int num1 = numRandGenCPU(50, 70);
          cpuTemp.push_back(num1);
        }
        else {
          int num1 = numRandGenCPU(40, 60);
          cpuTemp.push_back(num1);
        }

      }
      break;
    } 
    else if (gameChoice == 2) {
      cout << "GTA V Selected" << endl;
      if (selectedPC == 1) {
        int num1 = numRandGenCPU(70, 90);
        cpuTemp.push_back(num1);
      } 
      else if (selectedPC == 2) {
        int num1 = numRandGenCPU(60, 80);
        cpuTemp.push_back(num1);
      } 
      else if (selectedPC == 3) {
        int num1 = numRandGenCPU(50, 70);
        cpuTemp.push_back(num1);
      }
      else if (selectedPC == 4) {
        if (cp.getCores() <= 4 && cp.getThreads() <= 4) {
          int num1 = numRandGenCPU(70, 90);
          cpuTemp.push_back(num1);
        }
        else if (cp.getCores() <= 8 && cp.getThreads() <= 8) {
          int num1 = numRandGenCPU(60, 80);
          cpuTemp.push_back(num1);
        }
        else {
          int num1 = numRandGenCPU(50, 70);
          cpuTemp.push_back(num1);
        }
      }
      break;
    }

    else if (gameChoice == 3) {
      cout << "Cyberpunk 2077 Selected" << endl;
      if (selectedPC == 1) {
        int num1 = numRandGenCPU(90, 110);
        cpuTemp.push_back(num1);
      } 
      else if (selectedPC == 2) {
        int num1 = numRandGenCPU(80, 90);
        cpuTemp.push_back(num1);
      } 
      else if (selectedPC == 3) {
        int num1 = numRandGenCPU(70, 80);
        cpuTemp.push_back(num1);
      }
      else if (selectedPC == 4) {
        if (cp.getCores() <= 4 && cp.getThreads() <= 4) {
          int num1 = numRandGenCPU(90, 110);
          cpuTemp.push_back(num1);
      }
        else if (cp.getCores() <= 8 && cp.getThreads() <= 8) {
          int num1 = numRandGenCPU(80, 90);
          cpuTemp.push_back(num1);
        }
        else {
          int num1 = numRandGenCPU(70, 80);
          cpuTemp.push_back(num1);
        }
      }
      break;
    } 
    else {
      cout << "Invalid Choice!" << endl;
      cout << endl;
    } 
    continue;
  }
}

void GPUStressMenu() {
  cout << "Select a Game to Stress Test the GPU!" << endl;
  g1.getGames();
  cout << endl;
  while (true) {
    int gameChoice;
    cout << "Enter your choice: ";
    cin >> gameChoice;
    cout << endl;
    if (gameChoice == 1) {
      cout << "Minecraft Selected" << endl;
      if (selectedPC == 1) {
        int num1 = numRandGenGPU(55, 80);
        gpuTemp.push_back(num1);
      } else if (selectedPC == 2) {
        int num1 = numRandGenGPU(45, 70);
        gpuTemp.push_back(num1);
      } else if (selectedPC == 3) {
        int num1 = numRandGenGPU(40, 60);
        gpuTemp.push_back(num1);
      }
      else if (selectedPC == 4){
        if (cp.getVram() <= 4){
          int num1 = numRandGenGPU(55, 80);
          gpuTemp.push_back(num1);
        }
        else if (cp.getVram() <= 8){
          int num1 = numRandGenGPU(45, 70);
          gpuTemp.push_back(num1);
      }
        else {
        int num1 = numRandGenGPU(40, 60);
        gpuTemp.push_back(num1);
        }
      }
      break;
    } 
    else if (gameChoice == 2) {
      cout << "GTA V Selected" << endl;
      if (selectedPC == 1) {
        int num1 = numRandGenGPU(70, 90);
        gpuTemp.push_back(num1);
      } 
      else if (selectedPC == 2) {
        int num1 = numRandGenGPU(50, 70);
        gpuTemp.push_back(num1);
      } 
      else if (selectedPC == 3) {
        int num1 = numRandGenGPU(40, 60);
        cout << "GPU Temperature: " << num1 << "°C" << endl;
        gpuTemp.push_back(num1);
      }
      else if (selectedPC == 4){
        if (cp.getVram() <= 4) {
          int num1 = numRandGenGPU(70, 90);
          gpuTemp.push_back(num1);
      }
        else if (cp.getVram() <= 8){
          int num1 = numRandGenGPU(50, 70);
          gpuTemp.push_back(num1);
        }
        else {
          int num1 = numRandGenGPU(40, 60);
          gpuTemp.push_back(num1);
        }
      }
      break;
    }

    else if (gameChoice == 3) {
      cout << "Cyberpunk 2077 Selected" << endl;
      if (selectedPC == 1) {
        int num1 = numRandGenGPU(85, 97);
        gpuTemp.push_back(num1);
      } 
      else if (selectedPC == 2) {
        int num1 = numRandGenGPU(70, 85);
        gpuTemp.push_back(num1);
      } 
      else if (selectedPC == 3) {
        int num1 = numRandGenGPU(65, 80);
        gpuTemp.push_back(num1);
      }
      else if (selectedPC == 4){
        if (cp.getVram() <= 4){
          int num1 = numRandGenGPU(85, 97);
          gpuTemp.push_back(num1);
        }
        else if (cp.getVram() <= 8){
          int num1 = numRandGenGPU(70, 85);
          gpuTemp.push_back(num1);
        }
        else {
          int num1 = numRandGenGPU(65, 80);
          gpuTemp.push_back(num1);
        }   
      }
      break;
    } 
    else {
      cout << "Invalid Choice!" << endl;
    }
    continue;
  } 
}
void RAMStressMenu() {
  cout << "Select a Game to Stress Test the RAM!" << endl;
  g1.getGames();
  cout << endl;
  while (true) {
    int gameChoice;
    cout << "Enter your choice: ";
    cin >> gameChoice;
    cout << endl;
    if (gameChoice == 1) {
      cout << "Minecraft Selected" << endl;
      if (selectedPC == 1) {
        int num1 = numRandGenRAM(4, 8);
        if (num1 > 7) {
        cout << "RAM is running out of memory!" << endl;
        }
        ramUsage.push_back(num1);
      } 
      else if (selectedPC == 2) {
        int num1 = numRandGenRAM(4, 8);
        ramUsage.push_back(num1);
      } 
      else if (selectedPC == 3) {
        int num1 = numRandGenRAM(4, 8);
        ramUsage.push_back(num1);
      }
      else if (selectedPC == 4) {
        if (cp.getRam() <= 4) {
          int num1 = numRandGenRAM(4, 8);
        if (num1 > 4) {
        cout << "Minecraft uses all of the RAM!" << endl;
        }
          ramUsage.push_back(num1);
        }
        else if (cp.getRam() <= 8) {
          int num1 = numRandGenRAM(4, 8);
          if (num1 > 5) {
              cout << "Minecraft uses too much RAM!" << endl;
          }
          ramUsage.push_back(num1);
        }
        else {
          int num1 = numRandGenRAM(4, 8);
          ramUsage.push_back(num1);
        }
      }
      break;
    } 
    else if (gameChoice == 2) {
      cout << "GTA V Selected" << endl;
      if (selectedPC == 1) {
        int num1 = numRandGenRAM(6, 8);
        if (num1 > 6) {
            cout << "GTA V uses too much RAM!" << endl;
        }
        ramUsage.push_back(num1);
      } 
      else if (selectedPC == 2) {
        int num1 = numRandGenRAM(6, 8);
        ramUsage.push_back(num1);
      } 
      else if (selectedPC == 3) {
        int num1 = numRandGenRAM(6, 8);
        ramUsage.push_back(num1);
      }
      else if (selectedPC == 4) {
        if (cp.getRam() <= 4) {
          int num1 = numRandGenRAM(6, 8);
          if (num1 > 4) {
              cout << "GTA V uses all of the RAM!" << endl;
          }
          ramUsage.push_back(num1);
        }
        else if (cp.getRam() <= 8) {
          int num1 = numRandGenRAM(6, 8);
          if (num1 > 6) {
              cout << "GTA V uses too much RAM!" << endl;
          }
          ramUsage.push_back(num1);
        }
        else {
          int num1 = numRandGenRAM(6, 8);
          ramUsage.push_back(num1);
        }
      }
      break;
    }

    else if (gameChoice == 3) {
      cout << "Cyberpunk 2077 Selected" << endl;
      if (selectedPC == 1) {
        int num1 = numRandGenRAM(7, 8);
        if (num1 > 7) {
            cout << "Cyberpunk 2077 uses all of the RAM!" << endl;
        }
        else {
            cout << "Cyberpunk 2077 uses too much RAM!" << endl;
        }
        ramUsage.push_back(num1);
      } 
      else if (selectedPC == 2) {
        int num1 = numRandGenRAM(7, 8);
        ramUsage.push_back(num1);
      } 
      else if (selectedPC == 3) {
        int num1 = numRandGenRAM(7, 8);
        ramUsage.push_back(num1);
      }
      else if (selectedPC == 4) {
        if (cp.getRam() <= 4) {
          int num1 = numRandGenRAM(7, 8);
          if (num1 > 4) {
              cout << "Cyberpunk 2077 uses all of the RAM!" <<endl;
          }
          ramUsage.push_back(num1);
        }
        else if (cp.getRam() <= 8) {
          int num1 = numRandGenRAM(7, 8);
          if (num1 > 7) {
              cout << "Cyberpunk 2077 uses all of the RAM!" << endl;
          }
          ramUsage.push_back(num1);
        }
        else {
          int num1 = numRandGenRAM(7, 8);
          ramUsage.push_back(num1);
        }
      }
      break; 
    } else {
      cout << "Invalid Choice!" << endl;
      cout << endl;
    } 
    continue;
  }
}

int sumCPU(
    vector<int> &cpuT,
    int index = 0) {
  if (index == cpuT.size()) {
    return 0;
  } else {
    return cpuT[index] + sumCPU(cpuT, index + 1);
  }
}

int sumGPU(
    vector<int> &gpuT,
    int index = 0) { 
  if (index == gpuT.size()) {
    return 0;
  } else {
    return gpuT[index] + sumGPU(gpuT, index + 1);
  }
}

int sumRAM(
    vector<int> &ramT,
    int index = 0) {
  if (index == ramT.size()) {
    return 0;
  } else {
    return ramT[index] + sumRAM(ramT, index + 1);
  }
}

void CheckTemps() {

  cout << "Select a component to check temps!: " << endl;
  cout << "1. CPU" << "\n2. GPU" << "\n3. RAM" << endl;
  cout << endl;
  cout << "Enter your choice: ";
  cin >> switchChoice;
  cout << endl;
  switch (switchChoice) {
  case 1: {
    sort(cpuTemp.begin(), cpuTemp.end()); 
    cout << "CPU Temperature: ";
    if (cpuTemp.empty()) {
      cout << "No CPU Temps Stored!" << endl;
      break;
    }
    else {
      for (int i = 0; i < cpuTemp.size(); i++) {
        cout << cpuTemp[i] << "°C" << ", ";
      }
      cout << endl;
      double sum = sumCPU(cpuTemp); 
      cout << "Average of CPU Temps: " << sum / cpuTemp.size() << "°C" << endl; 
      break;
    }
    break;
  }
  case 2: {
    sort(gpuTemp.begin(), gpuTemp.end());
    cout << "GPU Temperature: ";
    if (gpuTemp.empty()) {
      cout << "No GPU Temps Stored!" << endl;
      break;
    } 
    else {
      for (int i = 0; i < gpuTemp.size(); i++) {
        cout << gpuTemp[i] << "°C" << ", ";
      }
      cout << endl;
      double sum = sumGPU(gpuTemp); 
      cout << "Average of GPU Temps: " << sum / gpuTemp.size() << "°C" << endl; 
      break;
    }
    break;
  }
  case 3: {
    sort(ramUsage.begin(), ramUsage.end());
    cout << "RAM Usage: ";
    if (ramUsage.empty()) {
      cout << "No RAM Usage Stored!" << endl;
      break;
    } 
    else {
      for (int i = 0; i < ramUsage.size(); i++) {
        cout << ramUsage[i] << "GB" << ", ";
      }
      cout << endl;
      double sum = sumRAM(ramUsage);
      cout << "Average RAM Usage: " << sum / ramUsage.size() << "GB" << endl; 
      break;
    }
    break;
  default:
    cout << "Invalid choice" << endl;
    cout << endl;
  }
  }
}







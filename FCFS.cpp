#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>


class Process {
public:
	int pid;
	int arivalTime;
	int BurstTime;
	int wattingTime;
	int turnaroundTime;

	Process(int id, int arival, int brust)
		: pid(id), arivalTime(arival), BurstTime(brust) {}
};

class FCFS_sheduler {
private:
	std::vector<Process> processes;

public:
	void addProcess(int Pid, int arivalTime, int brustTime) {
		processes.emplace_back(Pid, arivalTime, brustTime);
	}

	void calculateTime() {
		int currentTime = 0;

		for (auto& process : processes) {
			if (currentTime < process.arivalTime) {
				currentTime = process.arivalTime;
			}

			process.wattingTime = currentTime - process.arivalTime;
			process.turnaroundTime = process.wattingTime + process.BurstTime;
			currentTime += process.BurstTime;
		}
	}

	void printStastics() {
		double totalWatingTime = 0;
		double totalTrunAroundTime = 0;

		std::cout << "PID\tArival\tBrust\tWating\tTroundaroudn\n";
		for (const auto& process : processes) {
			std::cout << process.pid << "\t"
				<< process.arivalTime << "\t"
				<< process.BurstTime << "\t"
				<< process.wattingTime << "\t"
				<< process.turnaroundTime << std::endl;

			totalWatingTime += process.wattingTime;
			totalTrunAroundTime += process.turnaroundTime;
		}

		std::cout << std::fixed << std::setprecision(2);
		std::cout << "avrage wating time is " << totalWatingTime / processes.size() << std::endl;
		std::cout << "avrage Trun Around Time is " << totalTrunAroundTime / processes.size() << std::endl;

	}
};


int main()
{
	FCFS_sheduler sheduler;

	sheduler.addProcess(1, 0, 4);
	sheduler.addProcess(2, 1, 3);
	sheduler.addProcess(3, 2, 1);
	sheduler.addProcess(4, 3, 2);

	sheduler.calculateTime();
	sheduler.printStastics();
	return 0;
}
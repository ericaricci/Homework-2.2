#include <iostream>
#include <thread>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
//sourced from chatgpt
class Robot {
public:
    Robot(int id) : id(id), taskCompleted(false) {}

    void assignTools(int tool1, int tool2) {
        this->tool1 = tool1;
        this->tool2 = tool2;
    }

    void startTask() {
        std::cout << "Robot " << id << " is starting task." << std::endl;
        // Simulate reaching and grabbing tools
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Robot " << id << " has grabbed tools " << tool1 << " and " << tool2 << "." << std::endl;
        // Simulate completing task
        std::this_thread::sleep_for(std::chrono::seconds(5));
        std::cout << "Robot " << id << " has completed the task." << std::endl;
        taskCompleted = true;
    }

    bool isTaskCompleted() const {
        return taskCompleted;
    }

private:
    int id;
    int tool1, tool2;
    bool taskCompleted;
};

int main() {
    std::vector<Robot> robots;
    std::vector<int> tools = { 1, 2, 3, 4, 5 };

    // Initialize robots and assign tools
    for (int i = 0; i < 5; ++i) {
        Robot robot(i + 1);
        robot.assignTools(tools[i], tools[(i + 1) % 5]);
        robots.push_back(robot);
    }

    // Simulate robots performing tasks
    while (!std::all_of(robots.begin(), robots.end(), [](const Robot& robot) { return robot.isTaskCompleted(); })) {
        for (Robot& robot : robots) {
            if (!robot.isTaskCompleted()) {
                robot.startTask();
            }
        }
    }

    return 0;
}

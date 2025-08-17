// 5qlz_design_a_intera.cpp

/**
 * Project: Interactive Mobile App Controller
 * Description: This project aims to design a interactive mobile app controller 
 *              that allows users to control mobile apps remotely using a 
 *              custom-designed interface.
 * 
 * Author: Your Name
 * Date: 2023-02-20
 */

#include <iostream>
#include <string>
#include <vector>
#include "MobileApp.h"
#include "Controller.h"

using namespace std;

/**
 * Main function to demonstrate the interactive mobile app controller
 */
int main() {
    // Initialize mobile app objects
    MobileApp instagram("Instagram");
    MobileApp facebook("Facebook");
    MobileApp snapchat("Snapchat");

    // Initialize controller object
    Controller controller;

    // Add mobile apps to controller
    controller.addApp(instagram);
    controller.addApp(facebook);
    controller.addApp(snapchat);

    // Start controller loop
    controller.start();

    return 0;
}

/**
 * MobileApp class: represents a mobile app
 */
class MobileApp {
private:
    string name;

public:
    MobileApp(string name) {
        this->name = name;
    }

    string getName() {
        return name;
    }

    // Function to simulate app interaction (e.g. clicking a button)
    void interact() {
        cout << "Interacting with " << name << "..." << endl;
    }
};

/**
 * Controller class: represents the interactive mobile app controller
 */
class Controller {
private:
    vector<MobileApp> apps;

public:
    void addApp(MobileApp app) {
        apps.push_back(app);
    }

    void start() {
        while (true) {
            cout << "Select an app to control:" << endl;
            for (int i = 0; i < apps.size(); i++) {
                cout << i + 1 << ". " << apps[i].getName() << endl;
            }

            int choice;
            cin >> choice;

            if (choice > 0 && choice <= apps.size()) {
                MobileApp selectedApp = apps[choice - 1];
                selectedApp.interact();
            } else {
                cout << "Invalid choice. Please try again." << endl;
            }
        }
    }
};
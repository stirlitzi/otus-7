#include <climits>
#include <iostream>
#include <deque>
#include <fstream>
#include <chrono>
#include <string>

using namespace std;

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Usage: bulk N.";
        return 0;
    } else {
        int N;
        char *p;
        long conv = strtol(argv[1], &p, 10);
        if (errno != 0 || *p != '\0' || conv > INT_MAX) {
        } else {
            N = conv;
        }
        chrono::system_clock::time_point time;
//        int N = 5;
        string cmd;
        deque<string> cmd_data;
        while (cin) {
            for (size_t i = 0; i < N; i++) {
                getline(cin, cmd);
                if (cmd.empty()) {
                    break;
                }
                if (cmd == "{") {
                    if (!cmd_data.empty()) {
                        time = chrono::system_clock::now();
                        std::ofstream outfile("bulk" + to_string(
                                chrono::time_point_cast<std::chrono::milliseconds>(time).time_since_epoch().count()) +
                                              ".log");
                        cout << "bulk: ";
                        outfile << "bulk: ";
                        bool not_first = false;
                        for (auto &cmd_item:cmd_data) {
                            if (not_first) {
                                cout << ", ";
                                outfile << ", ";
                            }
                            cout << cmd_item;
                            outfile << cmd_item;
                            not_first = true;
                        }
                        cout << endl;
                        outfile << endl;
                        outfile.close();
                        cmd_data.clear();
                    }
                    string temp_cmd;
                    while (temp_cmd != "}") {
                        cin >> temp_cmd;
                        if (temp_cmd == "{") {
                            while (temp_cmd != "}") {
                                cin >> temp_cmd;
                                if (temp_cmd != "}") {
                                    cmd_data.push_back(temp_cmd);
                                }
                            }
                            temp_cmd = "";
                        } else if (temp_cmd != "}") {
                            cmd_data.push_back(temp_cmd);
                        }
                    }
                    if (!cmd_data.empty()) {
                        time = chrono::system_clock::now();
                        std::ofstream outfile("bulk" + to_string(
                                chrono::time_point_cast<std::chrono::milliseconds>(time).time_since_epoch().count()) +
                                              ".log");
                        bool not_first = false;
                        cout << "bulk: ";
                        outfile << "bulk: ";
                        for (auto &cmd_item:cmd_data) {
                            if (not_first) {
                                cout << ", ";
                                outfile << ", ";
                            }
                            cout << cmd_item;
                            outfile << cmd_item;
                            not_first = true;
                        }
                        cout << endl;
                        outfile << endl;
                        outfile.close();
                        cmd_data.clear();
                        break;
                    }
                }
                cmd_data.push_back(cmd);
            }
            if (!cmd_data.empty()) {
                time = chrono::system_clock::now();
                std::ofstream outfile("bulk" + to_string(
                        chrono::time_point_cast<std::chrono::milliseconds>(time).time_since_epoch().count()) +
                                      ".log");
                bool not_first = false;
                cout << "bulk: ";
                outfile << "bulk: ";
                for (auto &cmd_item:cmd_data) {
                    if (not_first) {
                        cout << ", ";
                        outfile << ", ";
                    }
                    cout << cmd_item;
                    outfile << cmd_item;
                    not_first = true;
                }
                cout << endl;
                outfile << endl;
                outfile.close();
                cmd_data.clear();
            }
        }
        return 0;
    }
}

#include <iostream>
#include <cstdint> 


void setAttendance(uint64_t& attendance, int studentNumber) {
   
    attendance |= (1ULL << studentNumber);
}


void clearAttendance(uint64_t& attendance, int studentNumber) {

    attendance &= ~(1ULL << studentNumber);
}


bool checkAttendance(uint64_t attendance, int studentNumber) {
    
    return attendance & (1ULL << studentNumber);
}


void printAbsentStudents(uint64_t attendance) {
    std::cout << "Absent students: ";
    for (int i = 0; i < 64; ++i) {
        if (!checkAttendance(attendance, i)) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
}


void printPresentStudents(uint64_t attendance) {
    std::cout << "Present students: ";
    for (int i = 0; i < 64; ++i) {
        if (checkAttendance(attendance, i)) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
}

int main() {
    uint64_t attendance = 0;
    int option;
    while (1) {
        std::cout << "1. Set attendance" << std::endl;
        std::cout << "2. Clear attendance" << std::endl;
        std::cout << "3. List absent students" << std::endl;
        std::cout << "4. List present students" << std::endl;
        std::cout << "5. Change attendance" << std::endl;
        std::cout << "6. Exit" << std::endl;

        std::cin >> option;

        switch (option) {
            case 1:
                int setStudent;
                std::cout << "Enter student number to set attendance: ";
                std::cin >> setStudent;
                if (setStudent >= 0 && setStudent < 64) {
                    setAttendance(attendance, setStudent);
                } else {
                    std::cerr << "Invalid student number!" << std::endl;
                }
                break;
            case 2:
                int clearStudent;
                std::cout << "Enter student number to clear attendance: ";
                std::cin >> clearStudent;
                if (clearStudent >= 0 && clearStudent < 64) {
                    clearAttendance(attendance, clearStudent);
                } else {
                    std::cerr << "Invalid student number!" << std::endl;
                }
                break;
            case 3:
                printAbsentStudents(attendance);
                break;
            case 4:
                printPresentStudents(attendance);
                break;
            case 5:
                int changeStudent;
                std::cout << "Enter student number to change attendance: ";
                std::cin >> changeStudent;
                if (changeStudent >= 0 && changeStudent < 64) {
                    if (checkAttendance(attendance, changeStudent)) {
                        clearAttendance(attendance, changeStudent);
                    } else {
                        setAttendance(attendance, changeStudent);
                    }
                } else {
                    std::cerr << "Invalid student number!" << std::endl;
                }
                break;
            case 6:
                return 0;
            default:
                std::cerr << "Invalid option!" << std::endl;
        }
    }
    return 0;
}

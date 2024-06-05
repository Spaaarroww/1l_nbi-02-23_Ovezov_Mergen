#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

// Структура Car представляет запись об автомобиле
struct Car {
    std::string id;       // ID автомобиля
    std::string make;     // Марка автомобиля
    std::string model;    // Модель автомобиля
    int year;             // Год выпуска
    double price;         // Цена автомобиля

    // Метод для вывода информации об автомобиле
    void display() const {
        std::cout << "ID: " << id << ", Make: " << make << ", Model: " << model 
                  << ", Year: " << year << ", Price: " << price << std::endl;
    }
};

// Класс CarDatabase представляет базу данных автомобилей
class CarDatabase {
private:
    std::vector<Car> cars;  // Вектор для хранения записей об автомобилях

public:
    // Метод для загрузки данных из файла
    void loadFromFile(const std::string& filename) {
        std::ifstream file(filename);  // Открытие файла для чтения
        if (!file.is_open()) {
            std::cerr << "Error: Unable to open file " << filename << std::endl;
            return;
        }

        cars.clear();  // Очистка текущей базы данных
        std::string line;
        while (std::getline(file, line)) {  // Чтение файла построчно
            std::istringstream iss(line);
            Car car;
            iss >> car.id >> car.make >> car.model >> car.year >> car.price;  // Разбор строки
            cars.push_back(car);  // Добавление записи в вектор
        }

        file.close();  // Закрытие файла
    }

    // Метод для записи данных в файл
    void saveToFile(const std::string& filename) const {
        std::ofstream file(filename);  // Открытие файла для записи
        if (!file.is_open()) {
            std::cerr << "Error: Unable to open file " << filename << std::endl;
            return;
        }

        for (const auto& car : cars) {  // Запись каждой записи в файл
            file << car.id << " " << car.make << " " << car.model << " " 
                 << car.year << " " << car.price << std::endl;
        }

        file.close();  // Закрытие файла
    }

    // Метод для добавления новой записи
    void addCar(const Car& car) {
        cars.push_back(car);  // Добавление новой записи в вектор
    }

    // Метод для редактирования записи
    void editCar(const std::string& id, const Car& newCar) {
        for (auto& car : cars) {
            if (car.id == id) {  // Поиск записи по ID
                car = newCar;  // Обновление записи
                return;
            }
        }
        std::cerr << "Error: Car with ID " << id << " not found." << std::endl;
    }

    // Метод для удаления записи
    void deleteCar(const std::string& id) {
        for (auto it = cars.begin(); it != cars.end(); ++it) {
            if (it->id == id) {  // Поиск записи по ID
                cars.erase(it);  // Удаление записи из вектора
                return;
            }
        }
        std::cerr << "Error: Car with ID " << id << " not found." << std::endl;
    }

    // Метод для поиска записи по ID
    void findCar(const std::string& id) const {
        for (const auto& car : cars) {
            if (car.id == id) {  // Поиск записи по ID
                car.display();  // Вывод информации о найденной записи
                return;
            }
        }
        std::cerr << "Error: Car with ID " << id << " not found." << std::endl;
    }

    // Метод для отображения всех записей
    void displayAll() const {
        for (const auto& car : cars) {
            car.display();  // Вывод информации о каждой записи
        }
    }
};

// Основная функция программы
int main() {
    CarDatabase db;  // Создание объекта базы данных автомобилей
    std::string filename = "cars.txt";  // Имя файла для хранения данных

    while (true) {
        // Вывод меню для пользователя
        std::cout << "Car Database Menu:\n";
        std::cout << "1. Load from file\n";
        std::cout << "2. Save to file\n";
        std::cout << "3. Add car\n";
        std::cout << "4. Edit car\n";
        std::cout << "5. Delete car\n";
        std::cout << "6. Find car\n";
        std::cout << "7. Display all cars\n";
        std::cout << "8. Exit\n";
        std::cout << "Choose an option: ";
        int option;
        std::cin >> option;

        if (option == 1) {
            db.loadFromFile(filename);  // Загрузка данных из файла
        } else if (option == 2) {
            db.saveToFile(filename);  // Сохранение данных в файл
        } else if (option == 3) {
            Car car;
            std::cout << "Enter car details (id make model year price): ";
            std::cin >> car.id >> car.make >> car.model >> car.year >> car.price;  // Ввод новой записи
            db.addCar(car);  // Добавление записи в базу данных
        } else if (option == 4) {
            std::string id;
            std::cout << "Enter car ID to edit: ";
            std::cin >> id;  // Ввод ID редактируемой записи
            Car car;
            std::cout << "Enter new car details (id make model year price): ";
            std::cin >> car.id >> car.make >> car.model >> car.year >> car.price;  // Ввод обновленных данных
            db.editCar(id, car);  // Редактирование записи в базе данных
        } else if (option == 5) {
            std::string id;
            std::cout << "Enter car ID to delete: ";
            std::cin >> id;  // Ввод ID удаляемой записи
            db.deleteCar(id);  // Удаление записи из базы данных
        } else if (option == 6) {
            std::string id;
            std::cout << "Enter car ID to find: ";
            std::cin >> id;  // Ввод ID искомой записи
            db.findCar(id);  // Поиск и вывод записи
        } else if (option == 7) {
            db.displayAll();  // Вывод всех записей из базы данных
        } else if (option == 8) {
            break;  // Выход из программы
        } else {
            std::cout << "Invalid option. Please try again.\n";  // Обработка некорректного ввода
        }
    }

    return 0;
}

#include <iostream>
#include <list>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

class User {
public:
    string username;
    string password;
    list<int> booking_history;

    static unordered_map<string, User> users;

    User(string username, string password) : username(username), password(password) {}

    static string registerUser(string username, string password) {
        if (users.find(username) != users.end()) {
            return "Username already exists.";
        }
        users[username] = User(username, password);
        return "User registered successfully.";
    }

    static string login(string username, string password) {
        if (users.find(username) != users.end() && users[username].password == password) {
            return "Login successful.";
        }
        return "Invalid username or password.";
    }
};

unordered_map<string, User> User::users;

class Flight {
public:
    int flight_id;
    string source;
    string destination;
    string departure_time;
    int seats;

    static list<Flight> flights;

    Flight(int flight_id, string source, string destination, string departure_time, int seats)
        : flight_id(flight_id), source(source), destination(destination), departure_time(departure_time), seats(seats) {}

    static void addFlight(int flight_id, string source, string destination, string departure_time, int seats) {
        flights.emplace_back(flight_id, source, destination, departure_time, seats);
    }

    static list<tuple<int, string, string, string, int>> viewFlights() {
        list<tuple<int, string, string, string, int>> flight_list;
        for (const auto& flight : flights) {
            flight_list.emplace_back(flight.flight_id, flight.source, flight.destination, flight.departure_time, flight.seats);
        }
        return flight_list;
    }
};

list<Flight> Flight::flights;

class Booking {
public:
    string username;
    int flight_id;

    static list<Booking> bookings;

    Booking(string username, int flight_id) : username(username), flight_id(flight_id) {}

    static string bookFlight(string username, int flight_id) {
        if (User::users.find(username) == User::users.end()) {
            return "User not found.";
        }
        auto it = find_if(Flight::flights.begin(), Flight::flights.end(), [flight_id](const Flight& flight) {
            return flight.flight_id == flight_id;
        });
        if (it == Flight::flights.end()) {
            return "Flight not found.";
        }
        if (it->seats <= 0) {
            return "No seats available.";
        }
        it->seats -= 1;
        bookings.emplace_back(username, flight_id);
        User::users[username].booking_history.push_back(flight_id);
        return "Flight booked successfully.";
    }

    static list<int> viewBookingHistory(string username) {
        if (User::users.find(username) == User::users.end()) {
            return {};
        }
        return User::users[username].booking_history;
    }
};

list<Booking> Booking::bookings;

int main() {
    // Adding sample flights
    Flight::addFlight(1, "New York", "Los Angeles", "2024-06-15 08:00", 5);
    Flight::addFlight(2, "Chicago", "Miami", "2024-06-16 09:00", 3);

    // Registering a user
    cout << User::registerUser("john_doe", "password123") << endl;

    // User login
    cout << User::login("john_doe", "password123") << endl;

    // Viewing available flights
    auto flights = Flight::viewFlights();
    for (const auto& flight : flights) {
        cout << get<0>(flight) << " " << get<1>(flight) << " " << get<2>(flight) << " " << get<3>(flight) << " " << get<4>(flight) << endl;
    }

    // Booking a flight
    cout << Booking::bookFlight("john_doe", 1) << endl;

    // Viewing booking history
    auto booking_history = Booking::viewBookingHistory("john_doe");
    for (int flight_id : booking_history) {
        cout << flight_id << " ";
    }
    cout << endl;

    return 0;
}

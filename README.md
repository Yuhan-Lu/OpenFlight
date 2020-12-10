# CS225 Final Project
## TeamNetID: tinghan2-yf9-yuhanlu2-yiruiz2

## Overview
This is the CS225 final project developed by Eric Zhou, Lucas Lu, Joe Ye, and Yucheng Feng. 
Our project goal is to find the shortest path between two airports. In this program, you can
indicate the starting airport and the destination, and we can search for the shortest path for you.

## Problem to solve
In this contemporary society, airflight becomes an important transportation for people in daily life. However, sometimes people are confused about how to go from one location to another unknown location. Here, we have a project to help find the shortest route between two airports. Life becomes convenient!

## Data Source
Our data is from dataset inside OpenFlights. You can open the link [here](https://openflights.org/data.html). This is the general map and locations of our airports. [map here](https://openflights.org/demo/openflights-apdb-2048.png). In specific, we use the following information: Airport ID, Name, City, Country, IATA, ICAO, Latitude, Longitude, Altitude, Timezone.

Example entry here: 507, "London Heathrow Airport", "London", "United Kingdom", "EGLL", 51.4706, -0.461941, 83, 0, "E", "Europe/London", "airport", "OurAirports"

## Installation
No installation needed.

## Test
We include our tests in "tests" file, and there are many tests in different "tests.cpp"
Please run "make test" to see the outcome.
```cpp
make test
```
```cpp
./test
```

You can also design your own airlines in "main.cpp" file. 
Run
```cpp
make test
```
```cpp
./main
```

## Usage
Choose the right data file, and find needed information. ex: airports->name
```cpp
airports.getAirportByID(ID)->name
```
## Contributing
We are using graph file, PNG file, and make file from cs225 class. Thanks to cs225's contribution. Also, we use two algorithms, Dijkstra's Algorithm and Page Rank, to achieve our goal.







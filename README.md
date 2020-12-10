# CS225 Final Project
## TeamNetID: tinghan2-yf9-yuhanlu2-yiruiz2

## Overview
This is the CS225 final project developed by Eric Zhou, Lucas Lu, Joe Ye, and Yucheng Feng. Our project implemented BFS and DFS to traverse all the available airports. Besides, we adopted Dijkstra's algorithm to find the shortest path between two airports. Finally, our project included PageRank, which could display the frequencies of airlines to different airports. For example, a popular airport would have a higher frequency value than a small airport. 

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

## Usage
We include some of our fundamental functions in main.cpp for testing and
displaying results. 
Run
```cpp
make
```
```cpp
./main
```
For more information about a specific function, please refer to the function documentations in each file.

## Contribution
We are using graph files, PNG files, and make files from cs225 class. Thanks for cs225's contribution.

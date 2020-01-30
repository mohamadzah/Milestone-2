# Milestone-2
Milestone 2 is a project that we created as a part of two milestones that we have to do for this semester's course Advanced Programming 1

## Description:

In this project, we created a searching algorithm server that is able to hold a conversation with a client (or multiple clients), in which the client will send to the server a sophisticated problem and the server is expected to return to the client a readable solution, the "problem" we dealt with in this program is graphs that are in the shape of matrices.

Design: 
-
The program opens a server that will allow a client or multiple clients to connect to it, once a connection is made with a client, the client is expected to send to the server the "problem" which is a graph in the shape of a matrix, and the server will find a solution for the client's problem using one of the 4 algorithms implemented:
- A star algorithm.
- Best First Search algorithm
- Breadth First Search algorithm
- Depth First Search algorithm

Once a solution is found after using one of the algorithms, the best path from the starting node and the goal node is sent back to the client.

### How to run

To use this program, you need to compile the code using the following line in your terminal: g++ -std=c++14 *.cpp -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -o a.out -pthread

then you have to run the server using this command: ./a.out 5600
5600 being the port you will connect with.
Then you will connect to the server using the auto_client.py file provided with the code.
You will have to edit the location and the name of the file where you choose to save/name your matrix, 
Open the file auto_client.py file with note pad and you will see the following lines 

DEFAULT_FILE_NAME = 'CHANGE_THIS_TO_MATRIX_NAME'

DEFAULT_TARGET_IP = 'localhost'

DEFAULT_TARGET_PORT = 5600

DEFAULT_MAX_BACKLOG_SIZE = 5

DEFAULT_BUFFER_SIZE = 1024

DEFAULT_SLEEP_TIME = 0.1

You want to change the MATRIX_NAME to the name of the file where the matrix is included, for example: C:\Users\user\Desktop\matrix1.txt

now save and then run the program using the following command: python3 auto_client.py -vv 

Once you are connected, the client will begin sending the matrix line by line, once you are done sending the program will begin solving your "problem" and will send back the solution.

**_Note_**: If no connections were made to the server, it will automatically shutdown after 2 minutes (120 seconds).
**_Note_**: You can find matrices that you can use in the file matrices.txt.

#### Visuals

Here is an example of 3 clients that connected, sent a message and recieved back a solution:

![Clients exmaple](https://github.com/mohamadzah/Milestone-2/blob/master/exampleRun.PNG)

A comparison between the algorithms can be found in a PDF file found with the code files.

##### Support

More on server-client relationship: https://en.wikipedia.org/wiki/Client%E2%80%93server_model

###### Authors

***The author(s) of this code is Mohamad Zahalka***



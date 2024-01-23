# Simple C Socket Chat Application

This is a basic client-server chat application implemented in C using sockets. The application allows communication between a client and a server over a local network.

## Features

- **Bi-directional Communication:** The client and server can send messages to each other in a back-and-forth manner.
- **Exit Command:** Both the client and server understand the "exit" command to gracefully terminate the communication.

## How to Use

### Prerequisites

- Make sure you have a C compiler installed on your system.
- This application is designed for a Linux environment.

### Compilation

1. Compile the server code:

   ```bash
      gcc chatserver.c -o server
   ```
2. Compile the client code:
   ```bash
      gcc chatclient.c -o client
   ```
3. Execute both codes :
   ```bash
     ./server
     ./client
   ```

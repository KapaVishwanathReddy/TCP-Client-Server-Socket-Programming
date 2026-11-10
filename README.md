# TCP Client-Server Communication Using Socket Programming in C

## Project Overview
This project demonstrates TCP client-server communication using socket programming in C on Linux. The server handles multiple clients independently using the `fork()` system call. The server receives messages from clients, converts lowercase characters to uppercase and uppercase characters to lowercase, and sends the modified message back to the respective client.

## Technologies Used
- C Programming
- Linux
- TCP/IP
- Socket Programming
- Process Management (`fork()`)
- Linux System Calls

## Features
- TCP-based client-server communication
- Multiple client handling using separate child processes
- Bidirectional communication between client and server
- Character case conversion at the server side
- Independent communication for each connected client

## Project Structure
```text
TCP-Client-Server-Socket-Programming/
│
├── server.c
├── client.c
├── header.h
└── README.md
```

## How It Works
1. The server creates a TCP socket.
2. The server binds the socket to a port and starts listening.
3. The client connects to the server using its IP address and port number.
4. The server accepts the client connection.
5. The server creates a child process using `fork()` to handle the client.
6. The client sends a message to the server.
7. The server converts lowercase characters to uppercase and uppercase characters to lowercase.
8. The modified message is sent back to the client.
9. Multiple clients can communicate with the server independently.

## Compilation

Compile the server:

```bash
gcc server.c -o server
```

Compile the client:

```bash
gcc client.c -o client
```

## Execution

### Start the Server
```bash
./server 5000 0.0.0.0
```

### Start the Client
```bash
./client 5000 <SERVER_IP_ADDRESS>
```

Example:

```bash
./client 5000 192.168.1.10
```

For testing on the same computer:

```bash
./client 5000 127.0.0.1
```

## Example Output

### Client
```text
Enter data: Hello
Server sent: hELLO
```

### Server
```text
Waiting for client.....
Connected..
Client sent: Hello
```

## Learning Outcomes
- Understanding TCP socket programming
- Working with Linux networking system calls
- Implementing process creation using `fork()`
- Understanding client-server architecture
- Handling multiple client connections

## Author
Vishwanath Reddy

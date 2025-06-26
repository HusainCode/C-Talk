# C-Talk

A simple TCP chat client and server written in C for Linux using POSIX sockets. This project demonstrates basic network programming and socket communication.

## Features
- Connects to a server via IPv4 and TCP
- Sends and receives messages
- Handles basic connection errors

## Files
- `main.c` – Client code
- `server.c` – Server code
- `chat_protocol.c` – Shared chat functions
- `CMakeLists.txt` – Build config

## Build & Run
```bash
mkdir build && cd build
cmake ..
make

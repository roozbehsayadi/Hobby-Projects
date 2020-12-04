
# Packet Sniffing

This program Listens to all the packets that are transmitted or received through your computer, and prints their information; including ethernet header, ip header and header of inner packet (based on the packet's type).

## How does it work

The magic happens in the very first step of the code, in creating the socket. The third argument tells the socket to sniff all ethernet frames, which means that it can sniff all packets. Whether they're incoming or outgoing, or whether they're IP packets or not.

## Operating System

This program runs on Linux. I tested it on Ubuntu but I don't see why it can't be run on the other distributions of Linux. Just install a C compiler (I used gcc), then compile and run the code.

You need root access to run the program, because creating a Raw socket needs root privilege.

## References

A huge thanks to [this amazing article](https://www.binarytides.com/packet-sniffer-code-in-c-using-linux-sockets-bsd-part-2/) which basically took me step-by-step through the process and never left me alone.

I also read a lot of man pages but there are too many pages I can't remember. I assume they don't need my reference either.

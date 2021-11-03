# Packet Tracer Project for SR2I Assessment

This repository contains .pkt files descripting the network required.
It also contains a fucking awesome C program for getting the generating sequence.

## Configuration

We choose RIP configuration here and we'll use RIPv2.
File 'sequence' contains the exact configuration of the project.

We must take into account three special routers :
 - Rd is connected to the Internet identified as 0.0.0.0/0
 - Rs (different from Rd) is connected to another AS (137.194.0.0/16)
 - Ri (different from Rd and Rs) covers an intranet

Each router must be connected to 2 other routers. For routers connected to other sites, they must be connected to at least 2 other sites.

Every router has a default route and a specific route to 137.194.0.0/16 via Ri.

There are at least 3 terminals on 3 different sites in order to illustrate what we want.

## TODO

 - Set devices and connect them within the AS
 - Configure each device
 - Configure RIPv2 within the AS
 - Connect Rd to the Internet
 - Connect Rs to another AS
 - Add a default gateway and a specific route to another AS
 - Add Ri

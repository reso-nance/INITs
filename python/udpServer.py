#!/usr/bin/env python
# -*- coding: utf-8 -*-

import socket

port = 8000
# little trick to get the local ip address.
s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
s.connect(("8.8.8.8", 80))
IP = s.getsockname()[0]

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind((IP, port))
print(" écoute l'UDP entrant à l'addresse %s sur le port %i" %(IP, port))

while True:
  try :
    data, addr = sock.recvfrom(1024)
    print ("paquet UDP reçu : '%s'" % data.decode("utf-8"), "depuis", *addr)
  except KeyboardInterrupt :
    print("\n  bye !")
    raise SystemExit

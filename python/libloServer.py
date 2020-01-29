#!/usr/bin/env python
# -*- coding: utf-8 -*-
import liblo, sys

defaultPort=8000
portNumber = defaultPort
if len(sys.argv) != 2 : print("on utilise le port par défaut "+str(defaultPort))
else :
    try :
        portGiven = int(sys.argv[1])
        if portGiven >= 1025 and portGiven <= 65535 : portNumber = portGiven
    except :
        print("le premier argument doit être le numéro de port (1025~65535)")
        raise SystemExit

try:
    server = liblo.Server(portNumber)
    print("écoute l'OSC entrant sur "+server.url)
except liblo.ServerError as err:
    print(str(err))
    raise SystemExit

def printOSC(path, args, types, src):
    print("reçu le message OSC '%s' de '%s'" % (path, src.url))
    for a, t in zip(args, types):
        print ("  argument de type '%s': %s" % (t, a))
    print("\n")

server.add_method(None, None, printOSC)
# loop and dispatch messages every 100ms
while True:
    try : server.recv(100)
    except KeyboardInterrupt :
       print("\n  bye !")
       raise SystemExit


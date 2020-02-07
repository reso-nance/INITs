#include <ESP8266WiFi.h> // fonctions wifi : connection en station ou point d'accès, addresses IP ...
#include <WiFiUdp.h> // création de paquets UDP et envoi sur le réseau

static char* nomDuReseau = "malinette"; // attention, sensible à la casse
static char* motDePasse = "malinette666"; // idem
static const int portUDP = 8000; // port auquel les paquets seront envoyés, doit être identique à celui du récepteur
static IPAddress IPcible = IPAddress({10,0,0,255});// addresse à laquelle les messages sont envoyés, ici en broadcast
WiFiUDP UDP;

void setup() {
  Serial.begin(115200); // ouverture du port série
  while (true) { // tant que la connection n'est pas établie, on restera coincé ici
    Serial.println("\n\nConnection à " + String(nomDuReseau) + " ...");
    WiFi.mode(WIFI_STA); // mode station : se connecte à un point d'accès existant
    WiFi.begin(nomDuReseau, motDePasse); // tentative de connection
    ESP.wdtFeed(); // évite de rebooter l'ESP si l'opération le bloque trop longtemps
    yield(); // rends la main à l'ESP
    if ( WiFi.waitForConnectResult() == WL_CONNECTED ) {break;} // si la connection est établie, on sort de la boucle infinie
  }
  Serial.print("connecté, addresse IP : ");
  Serial.println(WiFi.localIP()); // addresse IP attribuée à l'ESP par le routeur wifi auquel il se connecte
  UDP.begin(portUDP);
}

void loop() {
  Serial.println("coucou !");
  UDP.beginPacket(IPcible, portUDP);
  UDP.write("coucou !");
  UDP.endPacket();
  yield(); // rends la main à l'ESP
  delay(1000); // le paquet sera envoyé toutes les secondes
}

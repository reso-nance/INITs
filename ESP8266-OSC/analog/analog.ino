static int tolerance = 2; // différence minimale entre la la valeur actuelle et la précédente à partir de laquelle les messages seront envoyés
int valeurPrecedente = 0; // stockera la valeur précédente

void setup() {
  Serial.begin(115200); // ouverture du port série
}

void loop() {
  int valeurActuelle = analogRead(0); // lecture du port analogique
  if (valeurActuelle < valeurPrecedente-tolerance || valeurActuelle > valeurPrecedente+tolerance) { // si la valeur à changée significativement
    Serial.print("valeur changée : ");
    Serial.println(valeurActuelle);
    valeurPrecedente = valeurActuelle; // la tendance d'hier est le vintage d'aujourd'hui
    delay(100);
  }
}

#include <Arduino.h>

// Déclaration des broches pour les moteurs
const int ENA = 10; // PWM pour vitesse moteur A
const int IN1 = 9;  // Direction 1 pour moteur A
const int IN2 = 8;  // Direction 2 pour moteur A

const int ENB = 5;  // PWM pour vitesse moteur B
const int IN3 = 7;  // Direction 1 pour moteur B
const int IN4 = 6;  // Direction 2 pour moteur B

char command; // Variable pour stocker la commande reçue

void setup() {
  // Configuration des broches comme sorties
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Initialisation de la communication série
  Serial.begin(9600);
}

void loop() {
  // Vérification de la disponibilité des données série
  if (Serial.available()) {
    command = Serial.read(); // Lire la commande envoyée via Bluetooth ou série

    // Gestion des commandes reçues
    switch (command) {
      case 'A': // Avancer
        Avancer();
        break;
      case 'R': // Reculer
        Reculer();
        break;
      case 'D': // Tourner à droite
        Droite();
        break;
      case 'G': // Tourner à gauche
        Gauche();
        break;
      case 'P': // Pause (Arrêt des moteurs)
        Pause();
        break;
      default: // Commande invalide
        Pause(); // Par sécurité, arrêter les moteurs
        Serial.println("Commande invalide");
        break;
    }
  }
}

// Fonctions pour le contrôle des moteurs
void Avancer() {
  // Moteur A en marche avant
  digitalWrite(IN1, HIGH); // Avancer
  digitalWrite(IN2, LOW);  // Désactiver la marche arrière
  analogWrite(ENA, 255);   // Vitesse maximale pour moteur A

  // Moteur B en marche avant
  digitalWrite(IN3, HIGH); // Avancer
  digitalWrite(IN4, LOW);  // Désactiver la marche arrière
  analogWrite(ENB, 255);   // Vitesse maximale pour moteur B

  Serial.println("Avancer");
}

void Reculer() {
  // Moteur A en marche arrière
  digitalWrite(IN1, LOW);  // Désactiver la marche avant
  digitalWrite(IN2, HIGH); // Reculer
  analogWrite(ENA, 255);   // Vitesse maximale pour moteur A

  // Moteur B en marche arrière
  digitalWrite(IN3, LOW);  // Désactiver la marche avant
  digitalWrite(IN4, HIGH); // Reculer
  analogWrite(ENB, 255);   // Vitesse maximale pour moteur B

  Serial.println("Reculer");
}

void Droite() {
  // Moteur A en arrière
  digitalWrite(IN1, HIGH);  // Désactiver la marche avant
  digitalWrite(IN2, LOW); // Reculer
  analogWrite(ENA, 150);   // Réduction de vitesse pour rotation

  // Moteur B en avant
  digitalWrite(IN3, LOW); // Avancer
  digitalWrite(IN4, HIGH);  // Désactiver la marche arrière
  analogWrite(ENB, 150);   // Réduction de vitesse pour rotation

  Serial.println("Droite");
}

void Gauche() {
  // Moteur A en avant
  digitalWrite(IN1, LOW); // Avancer
  digitalWrite(IN2, HIGH);  // Désactiver la marche arrière
  analogWrite(ENA, 150);   // Réduction de vitesse pour rotation

  // Moteur B en arrière
  digitalWrite(IN3, HIGH);  // Désactiver la marche avant
  digitalWrite(IN4, LOW); // Reculer
  analogWrite(ENB, 150);   // Réduction de vitesse pour rotation

  Serial.println("Gauche");
}

void Pause() {
  // Arrêt du moteur A
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);

  // Arrêt du moteur B
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 0);

  Serial.println("Pause");
}

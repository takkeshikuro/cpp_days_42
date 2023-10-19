#include "phonebook.hpp"

int main() {
	// Création d'un objet de la classe
	Phonebook monObjet;
	// Utilisation de l'objet
	monObjet.print(); // Affiche "La valeur est : 0"
	monObjet.dbl();
	monObjet.print();
	monObjet.i = 42; // Modification de la variable membre
	monObjet.print(); // Affiche "La valeur est : 42"
	monObjet.dbl(); // Appelle la méthode pour doubler la valeur
	monObjet.print(); // Affiche "La valeur est : 84"

	return 0;
}

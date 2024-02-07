/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 02:36:06 by tmorikaw          #+#    #+#             */
/*   Updated: 2024/01/18 04:06:32 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(Serializer const &cpy) {
	*this = cpy;
}

Serializer & Serializer::operator=(Serializer const &cpy) {
	(void)cpy;
	return *this;
}

Serializer::~Serializer() {}

uintptr_t	Serializer::serialize(Data *ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data *>(raw);	
}

/*					LA SERIALISATION
Avantages :

Persistançe des données : La sérialisation permet de rendre les données 
persistantes, ce qui signifie qu'elles peuvent être sauvegardées dans un 
fichier ou transmises sur un réseau et récupérées ultérieurement. 
Cela peut être utile dans des scénarios tels que la sauvegarde 
'état d'une application.

Transmission à travers un réseau : Lors de la communication entre différents 
systèmes sur un réseau, la sérialisation permet de convertir des objets en 
une forme pouvant être transmise et reconstituée sur l'autre extrémité.

Partage d'état entre des processus : Dans les environnements à plusieurs 
processus, la sérialisation peut être utilisée pour partager l'état entre 
différents processus en convertissant les objets en une forme qui peut être 
passée entre les frontières des processus.

Interopérabilité : La sérialisation peut faciliter l'interopérabilité entre 
des systèmes écrits dans différents langages de programmation, car elle 
permet de convertir des objets en une représentation standard qui peut être 
interprétée de manière cohérente.

Inconvénients et Préoccupations :

Portabilité : La sérialisation basée sur la représentation mémoire des pointeurs 
peut ne pas être portable entre différentes architectures 
ou systèmes d'exploitation. La représentation mémoire des pointeurs peut varier.

Sécurité : L'utilisation de la sérialisation de pointeurs nécessite une 
gestion minutieuse pour éviter les problèmes de sécurité liés à la manipulation 
d'adresses mémoire. Des problèmes tels que la corruption de la mémoire peuvent 
survenir si la sérialisation n'est pas gérée correctement.

Évolution du Code : La sérialisation de pointeurs peut être fragile 
face aux modifications du code, telles que l'ajout ou la suppression 
de membres de classe. Ces changements peuvent entraîner une incompatibilité 
de la sérialisation.*/
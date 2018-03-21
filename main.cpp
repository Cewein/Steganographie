#include <iostream>
#include <bitset>
#include <fstream>
#include <string>
#include <math.h>
#include <vector>

std::string image_visible("image_vacances.ppm");
std::string image_cacher("image_bomb_code_csgo.ppm");

int chiffre(std::ifstream &x, std::vector<int> &y)
{
	std::string fichier;
	int nombre = 0;
	//test si fichier valide
	while (nombre != 255)
	{
		x >> fichier;
		nombre = atoi(fichier.c_str());
	}
	std::cout << "Image validee : Acquisition des donnees" << std::endl;
	//ammasage des données
	for (int i = 0; i != 187500; i++)
	{
		x >> fichier;
		nombre = atoi(fichier.c_str());
		y[i] = nombre;
	}
	std::cout << "Fini !" << std::endl;
	return(0);
}

void steno(std::vector<int> &visible, std::vector<int> &cacher)
{
	int couleur;
	int pixel = 0;
	std::ofstream flux_secret("image_secret.ppm");
	std::cout << "Cryptage de l'image" << std::endl;
	flux_secret << "P3 250 250 255" << std::endl;
	for (int i = 0; i != 187500; i++)
	{
		couleur = 0;
		std::bitset<8>visible_binaire(visible[i]);
		std::bitset<8>cacher_binaire(cacher[i]);
		
		for (int k = 0; k != 4; k++)
		{
			visible_binaire[3 - k] = cacher_binaire[7 - k];
		}
		for (int l = 0; l != 8; l++)
		{
			couleur += visible_binaire[l] * pow(2, l);
		}
		flux_secret << couleur << " ";
		if (pixel == 9)
		{
			pixel = 0;
			flux_secret << std::endl;
		}
		pixel += 1;
	}
	std::cout << "Image crypter" << std::endl;
	return;
}

int main()
{
	// initlialisation des variables 
	std::vector<int> nombre_visible(187500);
	std::vector<int> nombre_cacher(187500);
	std::ifstream flux_visible(image_visible);
	std::ifstream flux_cacher(image_cacher);
	//traitement des images
	chiffre(flux_visible, nombre_visible);
	chiffre(flux_cacher, nombre_cacher);
	steno(nombre_visible, nombre_cacher);
	// fin 
	return(0);
}

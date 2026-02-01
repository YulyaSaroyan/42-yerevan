#include <iostream>
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
	std::cout << "======== Basic Tests ========\n" << std::endl;

	IMateriaSource* src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");
	AMateria* tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << "\n======== Additional Tests ========\n" << std::endl;

	std::cout << "--- Equipping null and extra materias ---" << std::endl;
	me->equip(NULL);

	AMateria* ice2 = src->createMateria("ice");
	AMateria* cure2 = src->createMateria("cure");
	AMateria* ice3 = src->createMateria("ice");

	me->equip(ice2);
	me->equip(cure2);
	me->equip(ice3);

	delete ice3;

	std::cout << "\n--- Using all slots ---" << std::endl;
	for (int i = 0; i < 5; i++)
		me->use(i, *bob);

	std::cout << "\n--- Unequipping ---" << std::endl;
	tmp = ((Character*)me)->getEquipmentByIndex(1);
	me->unequip(1);
	me->unequip(1);

	delete tmp;

	me->unequip(5);

	std::cout << "\n--- Using after unequip ---" << std::endl;
	for (int i = 0; i < 4; i++)
		me->use(i, *bob);

	std::cout << "\n--- Cloning materias ---" << std::endl;
	AMateria* clonedIce = ice2->clone();
	clonedIce->use(*bob);
	delete clonedIce;

	std::cout << "\n--- Character Copy Constructor ---" << std::endl;
	Character copyMe(*(Character*)me);
	copyMe.use(0, *bob);
	copyMe.use(3, *bob);

	std::cout << "\n--- AMateria Copy / Assignment ---" << std::endl;
	Ice iceOriginal;
	Ice iceCopy(iceOriginal);
	Ice iceAssign;

	iceAssign = iceOriginal;
	iceCopy.use(*bob);
	iceAssign.use(*bob);

	delete bob;
	delete me;
	delete src;
}

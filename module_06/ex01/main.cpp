#include "Serializer.hpp"

#include <iostream>
#include <iomanip>
#include <ios>

int main(void)
{
	Data data = {'a', 1, 2.5f};

	Data* ptr = &data;
	std::cout << std::setw(15) << "ptr: "
			  << ptr << '\n';

	std::cout << std::setw(15) << "*ptr: "
			  << data.a << ' ' << data.b << ' ' << data.c << '\n';

	uintptr_t serialized = Serializer::serialize(&data);
	std::cout << std::setw(15) << "serialized: "
			  << std::hex << std::showbase << serialized << '\n';

	Data* deserialized = Serializer::deserialize(serialized);
	std::cout << std::setw(15) << "deserialized: " << deserialized << '\n';

	std::cout << std::setw(15) << "*deserialized: "
			  << deserialized->a
			  << ' ' << std::dec << std::noshowbase << deserialized->b
			  << ' ' << deserialized->c << '\n';

	*deserialized = (Data){'b', 2, 3.5f};
	std::cout << std::setw(15) << "*deserialized: "
			  << deserialized->a
			  << ' ' << std::dec << std::noshowbase << deserialized->b
			  << ' ' << deserialized->c << '\n';
}

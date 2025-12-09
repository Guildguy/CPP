#include "Serializer.hpp"

int	main()
{
	Data	originalData;

	originalData.id = 42;
	originalData.name = "Serialization test";

	std::cout << "--- BEFORE SERIALIZATION ---" << std::endl;
	std::cout << "Address: " << &originalData << std::endl;
	std::cout << "Data: " << originalData.id << " | " << originalData.name << std::endl;

	// 2. Serialize (Pointer -> Integer)
	uintptr_t	raw = Serializer::serialize(&originalData);

	std::cout << "\n--- SERIALIZED (Raw Integer) ---" << std::endl;
	std::cout << "Raw value: " << raw << std::endl;

	// 3. Deserialize (Integer -> Pointer)
	Data*	ptr = Serializer::deserialize(raw);	

	std::cout << "\n--- AFTER DESERIALIZATION ---" << std::endl;
	std::cout << "Address: " << ptr << std::endl;
	std::cout << "Data: " << ptr->id << " | " << ptr->name << std::endl;	

	std::cout << "\n--- VERIFICATION ---" << std::endl;
	if (ptr == &originalData)
	{
	    std::cout << "SUCCESS: Pointers match!" << std::endl;
	    if (ptr->name == originalData.name)
	        std::cout << "Data integrity: OK" << std::endl;
	}
	else
	    std::cout << "FAILURE: Pointers do not match!" << std::endl;

	return (0);
}

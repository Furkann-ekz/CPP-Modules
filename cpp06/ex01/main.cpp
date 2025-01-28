#include "Serializer.hpp"

int main()
{
	Data originalData;
	originalData.number = 42;
	originalData.text = "Hello, Serialization!";

	cout << "Original Data:" << endl;
	cout << "Number: " << originalData.number << ", Text: " << originalData.text << endl;

	uintptr_t raw = Serializer::serialize(&originalData);

	Data* deserializedData = Serializer::deserialize(raw);

	cout << "Deserialized Data:" << endl;
	cout << "Number: " << deserializedData->number << ", Text: " << deserializedData->text << endl;

	if (deserializedData == &originalData)
		cout << "Serialization and Deserialization are consistent!" << endl;
	else
		cout << "Serialization failed!" << endl;

	return 0;
}
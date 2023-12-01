exec: main.o Fabrica.o OrderedDictionaryEntry.o ListNode.o String.o Integer.o ListIterator.o List.o IIterator.o OrderedKey.o OrderedDictionary.o ICollectible.o ICollection.o IDictionary.o IKey.o CTRLHostal.o CTRLUsuario.o Respuesta.o Calificacion.o Habitacion.o Huesped.o Estadia.o Reserva.o Empleado.o Usuario.o Hostal.o
	g++ main.o Fabrica.o OrderedDictionaryEntry.o ListNode.o String.o Integer.o ListIterator.o List.o IIterator.o OrderedKey.o OrderedDictionary.o ICollectible.o ICollection.o IDictionary.o IKey.o CTRLHostal.o CTRLUsuario.o Respuesta.o Calificacion.o Habitacion.o Huesped.o Estadia.o Reserva.o Empleado.o Usuario.o Hostal.o -o exec

main.o: main.cpp
	g++ -c main.cpp

Fabrica.o: Fabrica.cpp
	g++ -c Fabrica.cpp

OrderedDictionaryEntry.o: ICollection/collections/OrderedDictionaryEntry.cpp
	g++ -c ICollection/collections/OrderedDictionaryEntry.cpp

ListNode.o: ICollection/collections/ListNode.cpp
	g++ -c ICollection/collections/ListNode.cpp

ListIterator.o: ICollection/collections/ListIterator.cpp
	g++ -c ICollection/collections/ListIterator.cpp

List.o: ICollection/collections/List.cpp
	g++ -c ICollection/collections/List.cpp

IIterator.o: ICollection/interfaces/IIterator.cpp
	g++ -c ICollection/interfaces/IIterator.cpp

String.o: ICollection/String.cpp
	g++ -c ICollection/String.cpp

Integer.o: ICollection/Integer.cpp
	g++ -c ICollection/Integer.cpp

OrderedDictionary.o: ICollection/collections/OrderedDictionary.cpp
	g++ -c ICollection/collections/OrderedDictionary.cpp

OrderedKey.o: ICollection/interfaces/OrderedKey.cpp
	g++ -c ICollection/interfaces/OrderedKey.cpp

IKey.o: ICollection/interfaces/IKey.cpp
	g++ -c ICollection/interfaces/IKey.cpp

ICollectible.o: ICollection/interfaces/ICollectible.cpp
	g++ -c ICollection/interfaces/ICollectible.cpp

ICollection.o: ICollection/interfaces/ICollection.cpp
	g++ -c ICollection/interfaces/ICollection.cpp

IDictionary.o: ICollection/interfaces/IDictionary.cpp
	g++ -c ICollection/interfaces/IDictionary.cpp

CTRLHostal.o: controladores/CTRLHostal.cpp
	g++ -c controladores/CTRLHostal.cpp

CTRLUsuario.o: controladores/CTRLUsuario.cpp
	g++ -c controladores/CTRLUsuario.cpp

Respuesta.o: clases/estructuras/Respuesta.cpp
	g++ -c clases/estructuras/Respuesta.cpp

Calificacion.o: clases/estructuras/Calificacion.cpp
	g++ -c clases/estructuras/Calificacion.cpp

Habitacion.o: clases/estructuras/Habitacion.cpp
	g++ -c clases/estructuras/Habitacion.cpp

Huesped.o: clases/estructuras/Huesped.cpp
	g++ -c clases/estructuras/Huesped.cpp

Estadia.o: clases/estructuras/Estadia.cpp
	g++ -c clases/estructuras/Estadia.cpp

Reserva.o: clases/estructuras/Reserva.cpp
	g++ -c clases/estructuras/Reserva.cpp

Empleado.o: clases/estructuras/Empleado.cpp
	g++ -c clases/estructuras/Empleado.cpp

Usuario.o: clases/estructuras/Usuario.cpp
	g++ -c clases/estructuras/Usuario.cpp

Hostal.o: clases/estructuras/Hostal.cpp
	g++ -c clases/estructuras/Hostal.cpp
clean:
	rm -f String.o Integer.o main.o Fabrica.o ICollection.o IIterator.o OrderedDictionary.o OrderedDictionaryEntry.o OrderedKey.o List.o ListIterator.o ListNode.o ICollectible.o IColection.o IDictionary.o IKey.o CTRLHostal.o CTRLUsuario.o Respuesta.o Calificacion.o Habitacion.o Huesped.o Estadia.o Reserva.o Empleado.o Usuario.o Hostal.o exec

rebuild:
	make clean
	make
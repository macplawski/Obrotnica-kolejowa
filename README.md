# Obrotnica kolejowa
Wokół dużej obrotnicy kolejowej rozchodzą się promieniście tory kolejowe a na nich stoją wagony do przetoczenia. Na obrotnicę może wjechać maksymalnie 10 wagonów. Można na nią wjechać i zjechać tylko z jednej strony.
Naszym zadaniem jest symulacja przetaczania wagonów.
# Wejście
W pierwszej linii znajduje się liczba t informująca o liczbie torów kolejowych wokół obrotnicy. W kolejnych t liniach znajduje się liczba ni mówiąca o liczbie wagonów na i-tym torze oraz ni liczb - identyfikatorów wagonów. Numery torów podawane są zgodnie z ruchem wskazówek zegara. Wagony wyświetlane są od strony obrotnicy.
W kolejnej linii znajduje się liczba n - instrukcji do wykonania.
W następnych n liniach znajdują się instrukcje:
z liczba - przesuń obrotnicę o liczba torów zgodnie z ruchem wskazówek zegara
o liczba - przesuń obrotnicę o liczba torów odwrotnie do ruchu wskazówek zegara
w liczba - wprowadź liczba wagonów na obrotnicę (wprowadzamy do pojemności obrotnicy i nie więcej niż liczba wagonów na torze)
j liczba - wyjedź liczba wagonami z obrotnicy (nie można wyprowadzić więcej niż liczba wagonów na obrotnicy)
Na początku obrotnica obrócona jest w stronę pierwszego toru.
# Wyjście
W pierwszej linii należy wypisać liczbę wagonów na obrotnicy i wypisać ich identyfikatory od wagonu bliżej wyjazdu z obrotnicy. W następnych t liniach należy wypisać liczbę wagonów oraz identyfikatory wagonów zaczynając od toru wskazywanego przez obrotnicę wypisując tory zgodnie z ruchem wskazówek zegara. Wagony należy wypisywać od strony obrotnicy.
# Przykład
## Wejście
4 
0
2 3 10
3 1 2 4
10 33 10 11 5 9 4 8 13 6 7
19
w 10
z 1
w 10
z 1
w 10
z 1
w 10
o 7
j 5
o 7
j 5
o 7
j 5
o 7
w 1
o 7
w 1
o 7
w 1

## Wyjście
3 3 33 4
4 10 1 2 4
0
4 8 13 6 7
4 10 11 5 9

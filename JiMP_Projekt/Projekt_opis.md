# Opis

Program ma na celu zliczanie cykli sygnału podanego na wejściu. W aktualnej wersji alogrytm jest przystosowany do zliczania cykli sygnału z wodomierza elektronicznego (co za tym idzie ilości płynu który przepłynął).
Sygnał składa się z sygnału z 3 osobnych sensorów, poprzez odpowiednie ich użycie poza liczbą cykli można stwierdzić aktualny kierunek przepływu.
Wynikiem działania programu jest okno dialogowe podające ilość próbek z sygnału oraz wykres wykonany przy pomocy zewnętrzengo oprogramownia gnuplot.
Dane testowe znajdują się w katalogu dane_testowe.

# Wymagania
Do poprawnego działania programu potrzebna jest biblioteka gtk3 oraz program gnuplot, na ubuntu dostępne w repozytorium:<br />
<br />
sudo apt-get install libgtk-3-dev<br />
sudo apt-get install gnuplot<br />

# Sposób użycia
Kod należy skompilować z dodaniem dostępu do biblioteki gtk, na przykład przy pomocy polecenia:<br />
`gcc ProjektJIMP.c `` `pkg-config --cflags --libs gtk+-3.0` `` -Wall -Werror -Wextra -pedantic -lm`<br />
aby zadziałał należy podać 3 argumenty, będące nazwami/ścieżkami do plików z danymi, np:<br />

`./a.out dane_testowe/zestaw_1/0_70st_1.txt dane_testowe/zestaw_1/0_70st_2.txt dane_testowe/zestaw_1/0_70st_3.txt`


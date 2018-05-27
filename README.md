# SO2_PR2

Wymagania funkcjonalne
----------------------

Program ma przy użyciu biblioteki [ncurses](https://en.wikipedia.org/wiki/Ncurses) podzielić okno terminala na 4 części.

W pierwszej z nich, jeden z wątków ma losować oraz przemieszczać w dół swojej ramki klocki (niczym w kultowej grze `tetris`). Gdy w owej pierwszej ramce klocek spadnie na sam dół, powinien zniknąć i jednocześnie trafić do współdzielonej kolekcji (np listy).

Trzy pozostałe wątki odpowiedzialne za trzy pozostałe części ekranu powinny z użyciem zmiennej warunkowej (bez aktywnego czekania) czekać na pojawienie się nowego klocka w kolekcji. W momencie gdy dowolny z wątków dostanie informację o nowym klocku w kolekcji, powinien go z niej wyciągnąć (zapamiętać i usunąć) a następnie narysować ów klocek w losowym miejscu w zakresie swojej ramki.

W efekcie, każdy kolejny klocek spadający z góry na dół w pierwszej części ekranu będzie po dojściu do ramki pojawiać się w losowym miejscu jednej z 3 pozostałych części ekranu (może on tam pozostać nieruchomy). Z czasem, 3 ostatnie ekrany będą się wypełniać klockami aż do zupełnego zamalowania.

Wymagania formalne
------------------

 - użycie `C++ 11` lub `C` oraz [POSIX Threads](https://en.wikipedia.org/wiki/POSIX_Threads)
 - tworzenie i uruchamianie watkow (`std::thread`)
 - poprawne kończenie wątków i zamykanie aplikacji (zamknięcie wszystkich wątków przed zamknięciem wątku glownego)
 - użycie biblioteki [ncurses](https://en.wikipedia.org/wiki/Ncurses)
 - poprawna synchronizacja dostępu wątków do bilbioteki `ncurses` przy użyciu podstawowego mechanizmu synchronizacji w postaci `std::mutex` (plus opcjonalnie wrappery typu `std::lock_guard` itp.)
 - synchronizacja za pomocą `std::condition_variable` bez aktywnego czekania

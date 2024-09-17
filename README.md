# Aho-Corasick algoritam za pretragu u tekstu

Projekat na kursu Konstrukcija i Analiza Algoritama 2, smer Informatika, Matematički fakultet, Univerzitet u Beogradu. 

Ivan Pop-Jovanov, 1066/2022 

Aho-Corasick algoritam pronalazi sva pojavljivanja nekog od konačnog broja unapred zadatih niski unutar teksta. Algoritam konstruiše konačan deterministički automat od zadatih niski u linearnom vremenu, i zatim ga koristi da paralelno traži sve niske u ciljnom tekstu u jednom prolazu kroz tekst. Složenost primene automata na tekst ne zavisi od broja traženih niski i linearna je po dužini teksta koji se pretražuje. 

U ovom projektu je prikazana implementacija algoritma, njegova upotreba, i analiza njegove prostorne i vremenske složenosti. Dokumentacija se nalazi u fajlu Aho_Corasick.pdf

# Pokretanje 

Za pokretanje projekta je potrebna kompilacija korišćenjem komande make. Zatim samo pokrenuti fajl main.out koji rezultate testova upisuje u stats1.csv i stats2.csv fajlove. Ove fajlove je moguće otvoriti i pretvoriti u grafike pomoću Jupyter sveske graph.ipynb

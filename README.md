# RSA

Ten projekt implementuje **prosty generator kluczy RSA** w języku C++.  
Nie korzysta z gotowych bibliotek kryptograficznych – zamiast tego pokazuje, jak RSA działa od środka.

Program:

- generuje wszystkie liczby pierwsze do 65 535 za pomocą Sita Eratostenesa,
- losuje dwie liczby pierwsze `p` i `q`,
- oblicza:
  - moduł `n = p * q`,
  - funkcję Eulera `φ(n) = (p - 1)(q - 1)`,
- wybiera wykładnik stały publiczny `e = 65537`,
- sprawdza, czy `(e, φ(n)) = 1` czyli e musi być względnie pierwsze z φ(n), co realizuje funkcja `euklides(e, phi, x, y)`
- wyznacza klucz prywatny `d` jako modularną odwrotność `e` modulo φ(n),
- wyświetla klucz publiczny i prywatny RSA.

Projekt ma pokazać działanie RSA więc generuje małe 16 bitowe liczby. Prawdziwe bezpieczeństwo mogą dać większe liczby co najmniej 1024 bitowe.

---

